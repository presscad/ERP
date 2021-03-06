#ifndef UFormaSpiskaSprDiscountAutoImplH
#define UFormaSpiskaSprDiscountAutoImplH
#include "IFormaSpiskaSprDiscountAuto.h"
#include "UFormaSpiskaSprDiscountAuto.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprDiscountAutoImpl)) TFormaSpiskaSprDiscountAutoImpl : public IFormaSpiskaSprDiscountAuto, IkanCallBack
{
public:
   TFormaSpiskaSprDiscountAutoImpl();
   ~TFormaSpiskaSprDiscountAutoImpl();
   TFormaSpiskaSprDiscountAuto * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

   //IkanCallBack  
   virtual int kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end);

//IFormaSpiskaSprDiscountAuto
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprDiscountAuto * get_DM(void);
   virtual void set_DM(IDMSprDiscountAuto * DM);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprDiscountAutoImpl __uuidof(TFormaSpiskaSprDiscountAutoImpl)
#endif
