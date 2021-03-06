#ifndef UREM_DMSprProducerConditionGrpImplH
#define UREM_DMSprProducerConditionGrpImplH
#include "IREM_DMSprProducerConditionGrp.h"
#include "UREM_DMSprProducerConditionGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprProducerConditionGrpImpl)) TREM_DMSprProducerConditionGrpImpl : public IREM_DMSprProducerConditionGrp
{
public:
   TREM_DMSprProducerConditionGrpImpl();
   ~TREM_DMSprProducerConditionGrpImpl();
   TREM_DMSprProducerConditionGrp * Object;
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

//IREM_DMSprProducerConditionGrp
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_REM_SPRCOND_GRP(void);
   virtual void set_TableID_REM_SPRCOND_GRP(TFIBLargeIntField * TableID_REM_SPRCOND_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SPRCOND_GRP(void);
   virtual void set_TableIDBASE_REM_SPRCOND_GRP(TFIBLargeIntField * TableIDBASE_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_TableGID_REM_SPRCOND_GRP(void);
   virtual void set_TableGID_REM_SPRCOND_GRP(TFIBWideStringField * TableGID_REM_SPRCOND_GRP);

   virtual TFIBLargeIntField * get_TableIDPR_REM_SPRCOND_GRP(void);
   virtual void set_TableIDPR_REM_SPRCOND_GRP(TFIBLargeIntField * TableIDPR_REM_SPRCOND_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SPRCOND_GRP(void);
   virtual void set_TableIDGRP_REM_SPRCOND_GRP(TFIBLargeIntField * TableIDGRP_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_TableCODE_REM_SPRCOND_GRP(void);
   virtual void set_TableCODE_REM_SPRCOND_GRP(TFIBWideStringField * TableCODE_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_TableNAME_REM_SPRCOND_GRP(void);
   virtual void set_TableNAME_REM_SPRCOND_GRP(TFIBWideStringField * TableNAME_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_TableNAME_ENG_REM_SPRCOND_GRP(void);
   virtual void set_TableNAME_ENG_REM_SPRCOND_GRP(TFIBWideStringField * TableNAME_ENG_REM_SPRCOND_GRP);

   virtual TFIBLargeIntField * get_ElementID_REM_SPRCOND_GRP(void);
   virtual void set_ElementID_REM_SPRCOND_GRP(TFIBLargeIntField * ElementID_REM_SPRCOND_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SPRCOND_GRP(void);
   virtual void set_ElementIDBASE_REM_SPRCOND_GRP(TFIBLargeIntField * ElementIDBASE_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_ElementGID_REM_SPRCOND_GRP(void);
   virtual void set_ElementGID_REM_SPRCOND_GRP(TFIBWideStringField * ElementGID_REM_SPRCOND_GRP);

   virtual TFIBLargeIntField * get_ElementIDPR_REM_SPRCOND_GRP(void);
   virtual void set_ElementIDPR_REM_SPRCOND_GRP(TFIBLargeIntField * ElementIDPR_REM_SPRCOND_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SPRCOND_GRP(void);
   virtual void set_ElementIDGRP_REM_SPRCOND_GRP(TFIBLargeIntField * ElementIDGRP_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_ElementCODE_REM_SPRCOND_GRP(void);
   virtual void set_ElementCODE_REM_SPRCOND_GRP(TFIBWideStringField * ElementCODE_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_ElementNAME_REM_SPRCOND_GRP(void);
   virtual void set_ElementNAME_REM_SPRCOND_GRP(TFIBWideStringField * ElementNAME_REM_SPRCOND_GRP);

   virtual TFIBWideStringField * get_ElementNAME_ENG_REM_SPRCOND_GRP(void);
   virtual void set_ElementNAME_ENG_REM_SPRCOND_GRP(TFIBWideStringField * ElementNAME_ENG_REM_SPRCOND_GRP);

   virtual __int64 get_IdGroupElement(void);
   virtual void set_IdGroupElement(__int64 IdGroupElement);

   virtual void OpenTable(__int64 id_group_element);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_group_element, __int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprProducerConditionGrpImpl __uuidof(TREM_DMSprProducerConditionGrpImpl)
#endif
