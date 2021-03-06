#ifndef UFormaReportTouchForFRImplH
#define UFormaReportTouchForFRImplH
#include "IMainInterface.h"
#include "UFormaReportTouchForFR.h"
//---------------------------------------------------------------
class __declspec(uuid("{D2361E6D-BFFA-4590-ADD5-F6259F27896A}")) TFormaReportTouchForFRImpl : public IMainInterface
{
public:
   TFormaReportTouchForFRImpl();
   ~TFormaReportTouchForFRImpl();
   TFormaReportTouchForFR * Object;
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

//IFormaReportTouchForFR
};
#define CLSID_TFormaReportTouchForFRImpl __uuidof(TFormaReportTouchForFRImpl)
#endif
