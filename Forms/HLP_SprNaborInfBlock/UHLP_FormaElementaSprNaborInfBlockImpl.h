#ifndef UHLP_FormaElementaSprNaborInfBlockImplH
#define UHLP_FormaElementaSprNaborInfBlockImplH
#include "IHLP_FormaElementaSprNaborInfBlock.h"
#include "UHLP_FormaElementaSprNaborInfBlock.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THLP_FormaElementaSprNaborInfBlockImpl)) THLP_FormaElementaSprNaborInfBlockImpl : public IHLP_FormaElementaSprNaborInfBlock, IkanCallBack
{
public:
   THLP_FormaElementaSprNaborInfBlockImpl();
   ~THLP_FormaElementaSprNaborInfBlockImpl();
   THLP_FormaElementaSprNaborInfBlock * Object;
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

//IHLP_FormaElementaSprNaborInfBlock
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IHLP_DMSprNaborInfBlock * get_DM(void);
   virtual void set_DM(IHLP_DMSprNaborInfBlock * DM);

   virtual bool get_SaveElement(void);
   virtual void set_SaveElement(bool SaveElement);

   virtual void UpdateForm(void);
};
#define CLSID_THLP_FormaElementaSprNaborInfBlockImpl __uuidof(THLP_FormaElementaSprNaborInfBlockImpl)
#endif