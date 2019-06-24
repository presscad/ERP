#ifndef UREM_FormaDocRegOtchetPostImplH
#define UREM_FormaDocRegOtchetPostImplH
#include "IREM_FormaDocRegOtchetPost.h"
#include "UREM_FormaDocRegOtchetPost.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaDocRegOtchetPostImpl)) TREM_FormaDocRegOtchetPostImpl : public IREM_FormaDocRegOtchetPost, IkanCallBack
{
public:
   TREM_FormaDocRegOtchetPostImpl();
   ~TREM_FormaDocRegOtchetPostImpl();
   TREM_FormaDocRegOtchetPost * Object;
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

//IREM_FormaDocRegOtchetPost
   virtual IREM_DMDocRegOtchetPost * get_DM(void);
   virtual void set_DM(IREM_DMDocRegOtchetPost * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaDocRegOtchetPostImpl __uuidof(TREM_FormaDocRegOtchetPostImpl)
#endif
