#ifndef UIREM_DMSprGrpModelH
#define UIREM_DMSprGrpModelH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprGrpModel)) IREM_DMSprGrpModel : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * TableID_REM_SGRPMODEL = {read = get_TableID_REM_SGRPMODEL , write = set_TableID_REM_SGRPMODEL};
   virtual TFIBLargeIntField * get_TableID_REM_SGRPMODEL(void)=0;
   virtual void set_TableID_REM_SGRPMODEL(TFIBLargeIntField * TableID_REM_SGRPMODEL)=0;

   __property TFIBWideStringField * TableGID_REM_SGRPMODEL = {read = get_TableGID_REM_SGRPMODEL , write = set_TableGID_REM_SGRPMODEL};
   virtual TFIBWideStringField * get_TableGID_REM_SGRPMODEL(void)=0;
   virtual void set_TableGID_REM_SGRPMODEL(TFIBWideStringField * TableGID_REM_SGRPMODEL)=0;

   __property TFIBLargeIntField * TableIDGRP_REM_SGRPMODEL = {read = get_TableIDGRP_REM_SGRPMODEL , write = set_TableIDGRP_REM_SGRPMODEL};
   virtual TFIBLargeIntField * get_TableIDGRP_REM_SGRPMODEL(void)=0;
   virtual void set_TableIDGRP_REM_SGRPMODEL(TFIBLargeIntField * TableIDGRP_REM_SGRPMODEL)=0;

   __property TFIBWideStringField * TableNAME_REM_SGRPMODEL = {read = get_TableNAME_REM_SGRPMODEL , write = set_TableNAME_REM_SGRPMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SGRPMODEL(void)=0;
   virtual void set_TableNAME_REM_SGRPMODEL(TFIBWideStringField * TableNAME_REM_SGRPMODEL)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SGRPMODEL = {read = get_TableIDBASE_REM_SGRPMODEL , write = set_TableIDBASE_REM_SGRPMODEL};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SGRPMODEL(void)=0;
   virtual void set_TableIDBASE_REM_SGRPMODEL(TFIBLargeIntField * TableIDBASE_REM_SGRPMODEL)=0;

   __property TFIBLargeIntField * ElementID_REM_SGRPMODEL = {read = get_ElementID_REM_SGRPMODEL , write = set_ElementID_REM_SGRPMODEL};
   virtual TFIBLargeIntField * get_ElementID_REM_SGRPMODEL(void)=0;
   virtual void set_ElementID_REM_SGRPMODEL(TFIBLargeIntField * ElementID_REM_SGRPMODEL)=0;

   __property TFIBWideStringField * ElementGID_REM_SGRPMODEL = {read = get_ElementGID_REM_SGRPMODEL , write = set_ElementGID_REM_SGRPMODEL};
   virtual TFIBWideStringField * get_ElementGID_REM_SGRPMODEL(void)=0;
   virtual void set_ElementGID_REM_SGRPMODEL(TFIBWideStringField * ElementGID_REM_SGRPMODEL)=0;

   __property TFIBLargeIntField * ElementIDGRP_REM_SGRPMODEL = {read = get_ElementIDGRP_REM_SGRPMODEL , write = set_ElementIDGRP_REM_SGRPMODEL};
   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SGRPMODEL(void)=0;
   virtual void set_ElementIDGRP_REM_SGRPMODEL(TFIBLargeIntField * ElementIDGRP_REM_SGRPMODEL)=0;

   __property TFIBWideStringField * ElementNAME_REM_SGRPMODEL = {read = get_ElementNAME_REM_SGRPMODEL , write = set_ElementNAME_REM_SGRPMODEL};
   virtual TFIBWideStringField * get_ElementNAME_REM_SGRPMODEL(void)=0;
   virtual void set_ElementNAME_REM_SGRPMODEL(TFIBWideStringField * ElementNAME_REM_SGRPMODEL)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SGRPMODEL = {read = get_ElementIDBASE_REM_SGRPMODEL , write = set_ElementIDBASE_REM_SGRPMODEL};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SGRPMODEL(void)=0;
   virtual void set_ElementIDBASE_REM_SGRPMODEL(TFIBLargeIntField * ElementIDBASE_REM_SGRPMODEL)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual int GetIDElement(UnicodeString gid)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
};
#define IID_IREM_DMSprGrpModel __uuidof(IREM_DMSprGrpModel)
#endif
