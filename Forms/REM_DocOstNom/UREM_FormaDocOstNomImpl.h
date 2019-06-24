#ifndef UREM_FormaDocOstNomImplH
#define UREM_FormaDocOstNomImplH
#include "IREM_FormaDocOstNom.h"
#include "UREM_FormaDocOstNom.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaDocOstNomImpl)) TREM_FormaDocOstNomImpl : public IREM_FormaDocOstNom, IkanCallBack
{
public:
   TREM_FormaDocOstNomImpl();
   ~TREM_FormaDocOstNomImpl();
   TREM_FormaDocOstNom * Object;
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

//IREM_FormaDocOstNom
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMDocOstNom * get_DM(void);
   virtual void set_DM(IREM_DMDocOstNom * DM);

   virtual bool get_ObjectSave(void);
   virtual void set_ObjectSave(bool ObjectSave);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

   virtual __int64 get_VibTovarId(void);
   virtual void set_VibTovarId(__int64 VibTovarId);

   virtual __int64 get_VibTovarIdGrp(void);
   virtual void set_VibTovarIdGrp(__int64 VibTovarIdGrp);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaDocOstNomImpl __uuidof(TREM_FormaDocOstNomImpl)
#endif
