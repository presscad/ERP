#ifndef UFormaReportDiscountDocCheckForCashierImplH
#define UFormaReportDiscountDocCheckForCashierImplH
#include "IMainInterface.h"
#include "UFormaReportDiscountDocCheckForCashier.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaReportDiscountForCashiersImpl))TFormaReportDiscountDocCheckForCashierImpl
			: public IMainInterface, IkanCallBack
{
public:
   TFormaReportDiscountDocCheckForCashierImpl();
   ~TFormaReportDiscountDocCheckForCashierImpl();
   TFormaReportDiscountDocCheckForCashier * Object;
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

//IFormaReportDiscountDocCheckForCashier
};
#define CLSID_TFormaReportDiscountDocCheckForCashierImpl __uuidof(TFormaReportDiscountDocCheckForCashierImpl)
#endif
