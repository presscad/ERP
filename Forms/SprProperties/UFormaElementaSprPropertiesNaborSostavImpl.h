#ifndef UFormaElementaSprPropertiesNaborSostavImplH
#define UFormaElementaSprPropertiesNaborSostavImplH
#include "IFormaElementaSprPropertiesNaborSostav.h"
#include "UFormaElementaSprPropertiesNaborSostav.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaElementaSprPropertiesNaborSostavImpl)) TFormaElementaSprPropertiesNaborSostavImpl : public IFormaElementaSprPropertiesNaborSostav, IkanCallBack
{
public:
   TFormaElementaSprPropertiesNaborSostavImpl();
   ~TFormaElementaSprPropertiesNaborSostavImpl();
   TFormaElementaSprPropertiesNaborSostav * Object;
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

//IFormaElementaSprPropertiesNaborSostav
   virtual IDMSprPropertiesNaborSostav * get_DM(void);
   virtual void set_DM(IDMSprPropertiesNaborSostav * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprPropertiesNaborSostavImpl __uuidof(TFormaElementaSprPropertiesNaborSostavImpl)
#endif