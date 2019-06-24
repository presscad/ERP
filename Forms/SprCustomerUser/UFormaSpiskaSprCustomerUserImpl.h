#ifndef UFormaSpiskaSprCustomerUserImplH
#define UFormaSpiskaSprCustomerUserImplH
#include "IFormaSpiskaSprCustomerUser.h"
#include "UFormaSpiskaSprCustomerUser.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprCustomerUserImpl)) TFormaSpiskaSprCustomerUserImpl : public IFormaSpiskaSprCustomerUser, IkanCallBack
{
public:
   TFormaSpiskaSprCustomerUserImpl();
   ~TFormaSpiskaSprCustomerUserImpl();
   TFormaSpiskaSprCustomerUser * Object;
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

//IFormaSpiskaSprCustomerUser
   virtual IDMSprCustomerUser* get_DM(void);
   virtual void set_DM(IDMSprCustomerUser* DM);

   virtual IDMSprCustomerUserGrp * get_DMGrp(void);
   virtual void set_DMGrp(IDMSprCustomerUserGrp * DMGrp);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrpElement(void);
   virtual void set_IdGrpElement(__int64 IdGrpElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdAccount(void);
   virtual void set_IdAccount(__int64 IdAccount);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprCustomerUserImpl __uuidof(TFormaSpiskaSprCustomerUserImpl)
#endif
