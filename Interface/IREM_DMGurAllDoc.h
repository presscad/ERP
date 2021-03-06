#ifndef UIREM_DMGurAllDocH
#define UIREM_DMGurAllDocH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMGurAllDoc)) IREM_DMGurAllDoc : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBDataSet * IBQ = {read = get_IBQ , write = set_IBQ};
   virtual TpFIBDataSet * get_IBQ(void)=0;
   virtual void set_IBQ(TpFIBDataSet * IBQ)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_REM_GALLDOC = {read = get_TableID_REM_GALLDOC , write = set_TableID_REM_GALLDOC};
   virtual TFIBLargeIntField * get_TableID_REM_GALLDOC(void)=0;
   virtual void set_TableID_REM_GALLDOC(TFIBLargeIntField * TableID_REM_GALLDOC)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_GALLDOC = {read = get_TableIDBASE_REM_GALLDOC , write = set_TableIDBASE_REM_GALLDOC};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_GALLDOC(void)=0;
   virtual void set_TableIDBASE_REM_GALLDOC(TFIBLargeIntField * TableIDBASE_REM_GALLDOC)=0;

   __property TFIBLargeIntField * TableIDFIRM_REM_GALLDOC = {read = get_TableIDFIRM_REM_GALLDOC , write = set_TableIDFIRM_REM_GALLDOC};
   virtual TFIBLargeIntField * get_TableIDFIRM_REM_GALLDOC(void)=0;
   virtual void set_TableIDFIRM_REM_GALLDOC(TFIBLargeIntField * TableIDFIRM_REM_GALLDOC)=0;

   __property TFIBLargeIntField * TableIDSKLAD_REM_GALLDOC = {read = get_TableIDSKLAD_REM_GALLDOC , write = set_TableIDSKLAD_REM_GALLDOC};
   virtual TFIBLargeIntField * get_TableIDSKLAD_REM_GALLDOC(void)=0;
   virtual void set_TableIDSKLAD_REM_GALLDOC(TFIBLargeIntField * TableIDSKLAD_REM_GALLDOC)=0;

   __property TFIBLargeIntField * TableIDKLIENT_REM_GALLDOC = {read = get_TableIDKLIENT_REM_GALLDOC , write = set_TableIDKLIENT_REM_GALLDOC};
   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_GALLDOC(void)=0;
   virtual void set_TableIDKLIENT_REM_GALLDOC(TFIBLargeIntField * TableIDKLIENT_REM_GALLDOC)=0;

   __property TFIBLargeIntField * TableIDUSER_REM_GALLDOC = {read = get_TableIDUSER_REM_GALLDOC , write = set_TableIDUSER_REM_GALLDOC};
   virtual TFIBLargeIntField * get_TableIDUSER_REM_GALLDOC(void)=0;
   virtual void set_TableIDUSER_REM_GALLDOC(TFIBLargeIntField * TableIDUSER_REM_GALLDOC)=0;

   __property TFIBDateTimeField * TablePOS_REM_GALLDOC = {read = get_TablePOS_REM_GALLDOC , write = set_TablePOS_REM_GALLDOC};
   virtual TFIBDateTimeField * get_TablePOS_REM_GALLDOC(void)=0;
   virtual void set_TablePOS_REM_GALLDOC(TFIBDateTimeField * TablePOS_REM_GALLDOC)=0;

   __property TFIBIntegerField * TableNUM_REM_GALLDOC = {read = get_TableNUM_REM_GALLDOC , write = set_TableNUM_REM_GALLDOC};
   virtual TFIBIntegerField * get_TableNUM_REM_GALLDOC(void)=0;
   virtual void set_TableNUM_REM_GALLDOC(TFIBIntegerField * TableNUM_REM_GALLDOC)=0;

   __property TFIBSmallIntField * TablePR_REM_GALLDOC = {read = get_TablePR_REM_GALLDOC , write = set_TablePR_REM_GALLDOC};
   virtual TFIBSmallIntField * get_TablePR_REM_GALLDOC(void)=0;
   virtual void set_TablePR_REM_GALLDOC(TFIBSmallIntField * TablePR_REM_GALLDOC)=0;

   __property TFIBWideStringField * TableTDOC_REM_GALLDOC = {read = get_TableTDOC_REM_GALLDOC , write = set_TableTDOC_REM_GALLDOC};
   virtual TFIBWideStringField * get_TableTDOC_REM_GALLDOC(void)=0;
   virtual void set_TableTDOC_REM_GALLDOC(TFIBWideStringField * TableTDOC_REM_GALLDOC)=0;

   __property TFIBLargeIntField * TableIDDOCOSN_REM_GALLDOC = {read = get_TableIDDOCOSN_REM_GALLDOC , write = set_TableIDDOCOSN_REM_GALLDOC};
   virtual TFIBLargeIntField * get_TableIDDOCOSN_REM_GALLDOC(void)=0;
   virtual void set_TableIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * TableIDDOCOSN_REM_GALLDOC)=0;

   __property TFIBIntegerField * TableTYPEEXTDOC_REM_GALLDOC = {read = get_TableTYPEEXTDOC_REM_GALLDOC , write = set_TableTYPEEXTDOC_REM_GALLDOC};
   virtual TFIBIntegerField * get_TableTYPEEXTDOC_REM_GALLDOC(void)=0;
   virtual void set_TableTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * TableTYPEEXTDOC_REM_GALLDOC)=0;

   __property TFIBLargeIntField * TableIDEXTDOC_REM_GALLDOC = {read = get_TableIDEXTDOC_REM_GALLDOC , write = set_TableIDEXTDOC_REM_GALLDOC};
   virtual TFIBLargeIntField * get_TableIDEXTDOC_REM_GALLDOC(void)=0;
   virtual void set_TableIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * TableIDEXTDOC_REM_GALLDOC)=0;

   __property TFIBBCDField * TableSUM_REM_GALLDOC = {read = get_TableSUM_REM_GALLDOC , write = set_TableSUM_REM_GALLDOC};
   virtual TFIBBCDField * get_TableSUM_REM_GALLDOC(void)=0;
   virtual void set_TableSUM_REM_GALLDOC(TFIBBCDField * TableSUM_REM_GALLDOC)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TablePREFIKS_NUM_REM_GALLDOC = {read = get_TablePREFIKS_NUM_REM_GALLDOC , write = set_TablePREFIKS_NUM_REM_GALLDOC};
   virtual TFIBWideStringField * get_TablePREFIKS_NUM_REM_GALLDOC(void)=0;
   virtual void set_TablePREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * TablePREFIKS_NUM_REM_GALLDOC)=0;

   __property TFIBWideStringField * TableNAME_SINFBASE_OBMEN = {read = get_TableNAME_SINFBASE_OBMEN , write = set_TableNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)=0;

   __property TFIBLargeIntField * TableIDPROJECT_REM_GALLDOC = {read = get_TableIDPROJECT_REM_GALLDOC , write = set_TableIDPROJECT_REM_GALLDOC};
   virtual TFIBLargeIntField * get_TableIDPROJECT_REM_GALLDOC(void)=0;
   virtual void set_TableIDPROJECT_REM_GALLDOC(TFIBLargeIntField * TableIDPROJECT_REM_GALLDOC)=0;

   __property TFIBLargeIntField * TableIDBUSINOP_REM_GALLDOC = {read = get_TableIDBUSINOP_REM_GALLDOC , write = set_TableIDBUSINOP_REM_GALLDOC};
   virtual TFIBLargeIntField * get_TableIDBUSINOP_REM_GALLDOC(void)=0;
   virtual void set_TableIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * TableIDBUSINOP_REM_GALLDOC)=0;

   __property TFIBLargeIntField * TableID_REM_GUR_PROV = {read = get_TableID_REM_GUR_PROV , write = set_TableID_REM_GUR_PROV};
   virtual TFIBLargeIntField * get_TableID_REM_GUR_PROV(void)=0;
   virtual void set_TableID_REM_GUR_PROV(TFIBLargeIntField * TableID_REM_GUR_PROV)=0;

   __property TFIBIntegerField * TableRES_REM_GUR_PROV = {read = get_TableRES_REM_GUR_PROV , write = set_TableRES_REM_GUR_PROV};
   virtual TFIBIntegerField * get_TableRES_REM_GUR_PROV(void)=0;
   virtual void set_TableRES_REM_GUR_PROV(TFIBIntegerField * TableRES_REM_GUR_PROV)=0;

   __property TFIBLargeIntField * TableIDDOC_REM_GUR_VIGRT = {read = get_TableIDDOC_REM_GUR_VIGRT , write = set_TableIDDOC_REM_GUR_VIGRT};
   virtual TFIBLargeIntField * get_TableIDDOC_REM_GUR_VIGRT(void)=0;
   virtual void set_TableIDDOC_REM_GUR_VIGRT(TFIBLargeIntField * TableIDDOC_REM_GUR_VIGRT)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property UnicodeString StringTypeDoc = {read = get_StringTypeDoc , write = set_StringTypeDoc};
   virtual UnicodeString get_StringTypeDoc(void)=0;
   virtual void set_StringTypeDoc(UnicodeString StringTypeDoc)=0;

   __property bool OtborVkl = {read = get_OtborVkl , write = set_OtborVkl};
   virtual bool get_OtborVkl(void)=0;
   virtual void set_OtborVkl(bool OtborVkl)=0;

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
   virtual bool CancelDvRegDoc(UnicodeString type_doc, __int64 id_doc)=0;
   virtual bool DvRegDoc(UnicodeString type_doc, __int64 id_doc)=0;
   virtual void AllCancelDvRegDoc(void)=0;
   virtual void AllDvRegDoc(void)=0;
   virtual bool OpenTableOnlyHardware(__int64 id_hw)=0;
   virtual bool OpenTableOnlyZayavka(__int64 id_z)=0;
};
#define IID_IREM_DMGurAllDoc __uuidof(IREM_DMGurAllDoc)
#endif
