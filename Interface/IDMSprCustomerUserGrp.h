#ifndef UIDMSprCustomerUserGrpH
#define UIDMSprCustomerUserGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprCustomerUserGrp)) IDMSprCustomerUserGrp : public IMainInterface
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

   __property TFIBLargeIntField * TableID_CUST_USER_GRP = {read = get_TableID_CUST_USER_GRP , write = set_TableID_CUST_USER_GRP};
   virtual TFIBLargeIntField * get_TableID_CUST_USER_GRP(void)=0;
   virtual void set_TableID_CUST_USER_GRP(TFIBLargeIntField * TableID_CUST_USER_GRP)=0;

   __property TFIBLargeIntField * TableIDBASE_CUST_USER_GRP = {read = get_TableIDBASE_CUST_USER_GRP , write = set_TableIDBASE_CUST_USER_GRP};
   virtual TFIBLargeIntField * get_TableIDBASE_CUST_USER_GRP(void)=0;
   virtual void set_TableIDBASE_CUST_USER_GRP(TFIBLargeIntField * TableIDBASE_CUST_USER_GRP)=0;

   __property TFIBWideStringField * TableGID_CUST_USER_GRP = {read = get_TableGID_CUST_USER_GRP , write = set_TableGID_CUST_USER_GRP};
   virtual TFIBWideStringField * get_TableGID_CUST_USER_GRP(void)=0;
   virtual void set_TableGID_CUST_USER_GRP(TFIBWideStringField * TableGID_CUST_USER_GRP)=0;

   __property TFIBLargeIntField * TableIDGRP_CUST_USER_GRP = {read = get_TableIDGRP_CUST_USER_GRP , write = set_TableIDGRP_CUST_USER_GRP};
   virtual TFIBLargeIntField * get_TableIDGRP_CUST_USER_GRP(void)=0;
   virtual void set_TableIDGRP_CUST_USER_GRP(TFIBLargeIntField * TableIDGRP_CUST_USER_GRP)=0;

   __property TFIBLargeIntField * TableIDACCOUNT_CUST_USER_GRP = {read = get_TableIDACCOUNT_CUST_USER_GRP , write = set_TableIDACCOUNT_CUST_USER_GRP};
   virtual TFIBLargeIntField * get_TableIDACCOUNT_CUST_USER_GRP(void)=0;
   virtual void set_TableIDACCOUNT_CUST_USER_GRP(TFIBLargeIntField * TableIDACCOUNT_CUST_USER_GRP)=0;

   __property TFIBWideStringField * TableNAME_CUST_USER_GRP = {read = get_TableNAME_CUST_USER_GRP , write = set_TableNAME_CUST_USER_GRP};
   virtual TFIBWideStringField * get_TableNAME_CUST_USER_GRP(void)=0;
   virtual void set_TableNAME_CUST_USER_GRP(TFIBWideStringField * TableNAME_CUST_USER_GRP)=0;

   __property TFIBLargeIntField * ElementID_CUST_USER_GRP = {read = get_ElementID_CUST_USER_GRP , write = set_ElementID_CUST_USER_GRP};
   virtual TFIBLargeIntField * get_ElementID_CUST_USER_GRP(void)=0;
   virtual void set_ElementID_CUST_USER_GRP(TFIBLargeIntField * ElementID_CUST_USER_GRP)=0;

   __property TFIBLargeIntField * ElementIDBASE_CUST_USER_GRP = {read = get_ElementIDBASE_CUST_USER_GRP , write = set_ElementIDBASE_CUST_USER_GRP};
   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_USER_GRP(void)=0;
   virtual void set_ElementIDBASE_CUST_USER_GRP(TFIBLargeIntField * ElementIDBASE_CUST_USER_GRP)=0;

   __property TFIBWideStringField * ElementGID_CUST_USER_GRP = {read = get_ElementGID_CUST_USER_GRP , write = set_ElementGID_CUST_USER_GRP};
   virtual TFIBWideStringField * get_ElementGID_CUST_USER_GRP(void)=0;
   virtual void set_ElementGID_CUST_USER_GRP(TFIBWideStringField * ElementGID_CUST_USER_GRP)=0;

   __property TFIBLargeIntField * ElementIDGRP_CUST_USER_GRP = {read = get_ElementIDGRP_CUST_USER_GRP , write = set_ElementIDGRP_CUST_USER_GRP};
   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_USER_GRP(void)=0;
   virtual void set_ElementIDGRP_CUST_USER_GRP(TFIBLargeIntField * ElementIDGRP_CUST_USER_GRP)=0;

   __property TFIBLargeIntField * ElementIDACCOUNT_CUST_USER_GRP = {read = get_ElementIDACCOUNT_CUST_USER_GRP , write = set_ElementIDACCOUNT_CUST_USER_GRP};
   virtual TFIBLargeIntField * get_ElementIDACCOUNT_CUST_USER_GRP(void)=0;
   virtual void set_ElementIDACCOUNT_CUST_USER_GRP(TFIBLargeIntField * ElementIDACCOUNT_CUST_USER_GRP)=0;

   __property TFIBWideStringField * ElementNAME_CUST_USER_GRP = {read = get_ElementNAME_CUST_USER_GRP , write = set_ElementNAME_CUST_USER_GRP};
   virtual TFIBWideStringField * get_ElementNAME_CUST_USER_GRP(void)=0;
   virtual void set_ElementNAME_CUST_USER_GRP(TFIBWideStringField * ElementNAME_CUST_USER_GRP)=0;

   __property __int64 IdAccount = {read = get_IdAccount , write = set_IdAccount};
   virtual __int64 get_IdAccount(void)=0;
   virtual void set_IdAccount(__int64 IdAccount)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_account)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_account, __int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
};
#define IID_IDMSprCustomerUserGrp __uuidof(IDMSprCustomerUserGrp)
#endif
