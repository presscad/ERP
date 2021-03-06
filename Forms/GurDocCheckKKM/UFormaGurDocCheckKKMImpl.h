#ifndef UFormaGurDocCheckKKMImplH
#define UFormaGurDocCheckKKMImplH
#include "IFormaGurDocCheckKKM.h"
#include "UFormaGurDocCheckKKM.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaGurDocCheckKKMImpl)) TFormaGurDocCheckKKMImpl
: public IFormaGurDocCheckKKM, IkanCallBack
{
public:
   TFormaGurDocCheckKKMImpl();
   ~TFormaGurDocCheckKKMImpl();
   TFormaGurDocCheckKKM * Object;
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

//IFormaGurDocCheckKKM
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMGurDocCheckKKM * get_DM(void);
   virtual void set_DM(IDMGurDocCheckKKM * DM);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdKKM(void);
   virtual void set_IdKKM(__int64 IdKKM);

   virtual bool get_Otbor(void);
   virtual void set_Otbor(bool Otbor);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

};
#define CLSID_TFormaGurDocCheckKKMImpl __uuidof(TFormaGurDocCheckKKMImpl)
#endif
