#ifndef UREM_FormaSpiskaSprHardwareIspImplH
#define UREM_FormaSpiskaSprHardwareIspImplH
#include "IREM_FormaSpiskaSprHardwareIsp.h"
#include "UREM_FormaSpiskaSprHardwareIsp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprHardwareIspImpl)) TREM_FormaSpiskaSprHardwareIspImpl : public IREM_FormaSpiskaSprHardwareIsp, IkanCallBack
{
public:
   TREM_FormaSpiskaSprHardwareIspImpl();
   ~TREM_FormaSpiskaSprHardwareIspImpl();
   TREM_FormaSpiskaSprHardwareIsp * Object;
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

//IREM_FormaSpiskaSprHardwareIsp
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprHardwareIsp * get_DM(void);
   virtual void set_DM(IREM_DMSprHardwareIsp * DM);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm();
};
#define CLSID_TREM_FormaSpiskaSprHardwareIspImpl __uuidof(TREM_FormaSpiskaSprHardwareIspImpl)
#endif
