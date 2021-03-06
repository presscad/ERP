#ifndef UFormaSpiskaSprDiscountCardImplH
#define UFormaSpiskaSprDiscountCardImplH
#include "IFormaSpiskaSprDiscountCard.h"
#include "UFormaSpiskaSprDiscountCard.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprDiscountCardImpl)) TFormaSpiskaSprDiscountCardImpl : public IFormaSpiskaSprDiscountCard, IkanCallBack
{
public:
   TFormaSpiskaSprDiscountCardImpl();
   ~TFormaSpiskaSprDiscountCardImpl();
   TFormaSpiskaSprDiscountCard * Object;
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

//IFormaSpiskaSprDiscountCard
   virtual IDMSprDiscountCard * get_DM(void);
   virtual void set_DM(IDMSprDiscountCard * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual AnsiString get_NameKlient(void);
   virtual void set_NameKlient(AnsiString NameKlient);

   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprDiscountCardImpl __uuidof(TFormaSpiskaSprDiscountCardImpl)
#endif
