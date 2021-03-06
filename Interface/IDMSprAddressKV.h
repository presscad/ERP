#ifndef UIDMSprAddressKVH
#define UIDMSprAddressKVH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprAddressKV)) IDMSprAddressKV : public IMainInterface
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

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBLargeIntField * TableID_SADR_KV = {read = get_TableID_SADR_KV , write = set_TableID_SADR_KV};
   virtual TFIBLargeIntField * get_TableID_SADR_KV(void)=0;
   virtual void set_TableID_SADR_KV(TFIBLargeIntField * TableID_SADR_KV)=0;

   __property TFIBLargeIntField * TableIDBASE_SADR_KV = {read = get_TableIDBASE_SADR_KV , write = set_TableIDBASE_SADR_KV};
   virtual TFIBLargeIntField * get_TableIDBASE_SADR_KV(void)=0;
   virtual void set_TableIDBASE_SADR_KV(TFIBLargeIntField * TableIDBASE_SADR_KV)=0;

   __property TFIBWideStringField * TableNAME_SADR_KV = {read = get_TableNAME_SADR_KV , write = set_TableNAME_SADR_KV};
   virtual TFIBWideStringField * get_TableNAME_SADR_KV(void)=0;
   virtual void set_TableNAME_SADR_KV(TFIBWideStringField * TableNAME_SADR_KV)=0;

   __property TFIBLargeIntField * TableIDSTROEN_SADR_KV = {read = get_TableIDSTROEN_SADR_KV , write = set_TableIDSTROEN_SADR_KV};
   virtual TFIBLargeIntField * get_TableIDSTROEN_SADR_KV(void)=0;
   virtual void set_TableIDSTROEN_SADR_KV(TFIBLargeIntField * TableIDSTROEN_SADR_KV)=0;

   __property TFIBLargeIntField * ElementID_SADR_KV = {read = get_ElementID_SADR_KV , write = set_ElementID_SADR_KV};
   virtual TFIBLargeIntField * get_ElementID_SADR_KV(void)=0;
   virtual void set_ElementID_SADR_KV(TFIBLargeIntField * ElementID_SADR_KV)=0;

   __property TFIBLargeIntField * ElementIDBASE_SADR_KV = {read = get_ElementIDBASE_SADR_KV , write = set_ElementIDBASE_SADR_KV};
   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_KV(void)=0;
   virtual void set_ElementIDBASE_SADR_KV(TFIBLargeIntField * ElementIDBASE_SADR_KV)=0;

   __property TFIBWideStringField * ElementNAME_SADR_KV = {read = get_ElementNAME_SADR_KV , write = set_ElementNAME_SADR_KV};
   virtual TFIBWideStringField * get_ElementNAME_SADR_KV(void)=0;
   virtual void set_ElementNAME_SADR_KV(TFIBWideStringField * ElementNAME_SADR_KV)=0;

   __property TFIBLargeIntField * ElementIDSTROEN_SADR_KV = {read = get_ElementIDSTROEN_SADR_KV , write = set_ElementIDSTROEN_SADR_KV};
   virtual TFIBLargeIntField * get_ElementIDSTROEN_SADR_KV(void)=0;
   virtual void set_ElementIDSTROEN_SADR_KV(TFIBLargeIntField * ElementIDSTROEN_SADR_KV)=0;

   __property TFIBLargeIntField * ElementID_SADR_STROEN = {read = get_ElementID_SADR_STROEN , write = set_ElementID_SADR_STROEN};
   virtual TFIBLargeIntField * get_ElementID_SADR_STROEN(void)=0;
   virtual void set_ElementID_SADR_STROEN(TFIBLargeIntField * ElementID_SADR_STROEN)=0;

   __property TFIBLargeIntField * ElementIDBASE_SADR_STROEN = {read = get_ElementIDBASE_SADR_STROEN , write = set_ElementIDBASE_SADR_STROEN};
   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_STROEN(void)=0;
   virtual void set_ElementIDBASE_SADR_STROEN(TFIBLargeIntField * ElementIDBASE_SADR_STROEN)=0;

   __property TFIBWideStringField * ElementNAME_SADR_STROEN = {read = get_ElementNAME_SADR_STROEN , write = set_ElementNAME_SADR_STROEN};
   virtual TFIBWideStringField * get_ElementNAME_SADR_STROEN(void)=0;
   virtual void set_ElementNAME_SADR_STROEN(TFIBWideStringField * ElementNAME_SADR_STROEN)=0;

   __property TFIBLargeIntField * ElementIDDOM_SADR_STROEN = {read = get_ElementIDDOM_SADR_STROEN , write = set_ElementIDDOM_SADR_STROEN};
   virtual TFIBLargeIntField * get_ElementIDDOM_SADR_STROEN(void)=0;
   virtual void set_ElementIDDOM_SADR_STROEN(TFIBLargeIntField * ElementIDDOM_SADR_STROEN)=0;

   __property TFIBLargeIntField * ElementID_SADR_DOM = {read = get_ElementID_SADR_DOM , write = set_ElementID_SADR_DOM};
   virtual TFIBLargeIntField * get_ElementID_SADR_DOM(void)=0;
   virtual void set_ElementID_SADR_DOM(TFIBLargeIntField * ElementID_SADR_DOM)=0;

   __property TFIBLargeIntField * ElementIDBASE_SADR_DOM = {read = get_ElementIDBASE_SADR_DOM , write = set_ElementIDBASE_SADR_DOM};
   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_DOM(void)=0;
   virtual void set_ElementIDBASE_SADR_DOM(TFIBLargeIntField * ElementIDBASE_SADR_DOM)=0;

   __property TFIBLargeIntField * ElementIDSTREET_SADR_DOM = {read = get_ElementIDSTREET_SADR_DOM , write = set_ElementIDSTREET_SADR_DOM};
   virtual TFIBLargeIntField * get_ElementIDSTREET_SADR_DOM(void)=0;
   virtual void set_ElementIDSTREET_SADR_DOM(TFIBLargeIntField * ElementIDSTREET_SADR_DOM)=0;

   __property TFIBWideStringField * ElementNAME_SADR_DOM = {read = get_ElementNAME_SADR_DOM , write = set_ElementNAME_SADR_DOM};
   virtual TFIBWideStringField * get_ElementNAME_SADR_DOM(void)=0;
   virtual void set_ElementNAME_SADR_DOM(TFIBWideStringField * ElementNAME_SADR_DOM)=0;

   __property TFIBLargeIntField * ElementID_SADR_STREET = {read = get_ElementID_SADR_STREET , write = set_ElementID_SADR_STREET};
   virtual TFIBLargeIntField * get_ElementID_SADR_STREET(void)=0;
   virtual void set_ElementID_SADR_STREET(TFIBLargeIntField * ElementID_SADR_STREET)=0;

   __property TFIBLargeIntField * ElementIDBASE_SADR_STREET = {read = get_ElementIDBASE_SADR_STREET , write = set_ElementIDBASE_SADR_STREET};
   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_STREET(void)=0;
   virtual void set_ElementIDBASE_SADR_STREET(TFIBLargeIntField * ElementIDBASE_SADR_STREET)=0;

   __property TFIBWideStringField * ElementNAME_SADR_STREET = {read = get_ElementNAME_SADR_STREET , write = set_ElementNAME_SADR_STREET};
   virtual TFIBWideStringField * get_ElementNAME_SADR_STREET(void)=0;
   virtual void set_ElementNAME_SADR_STREET(TFIBWideStringField * ElementNAME_SADR_STREET)=0;

   __property TFIBWideStringField * ElementPOSTCODE_SADR_STREET = {read = get_ElementPOSTCODE_SADR_STREET , write = set_ElementPOSTCODE_SADR_STREET};
   virtual TFIBWideStringField * get_ElementPOSTCODE_SADR_STREET(void)=0;
   virtual void set_ElementPOSTCODE_SADR_STREET(TFIBWideStringField * ElementPOSTCODE_SADR_STREET)=0;

   __property TFIBLargeIntField * ElementIDNASPUNKT_SADR_STREET = {read = get_ElementIDNASPUNKT_SADR_STREET , write = set_ElementIDNASPUNKT_SADR_STREET};
   virtual TFIBLargeIntField * get_ElementIDNASPUNKT_SADR_STREET(void)=0;
   virtual void set_ElementIDNASPUNKT_SADR_STREET(TFIBLargeIntField * ElementIDNASPUNKT_SADR_STREET)=0;

   __property TFIBLargeIntField * ElementID_SADR_NASPUNKT = {read = get_ElementID_SADR_NASPUNKT , write = set_ElementID_SADR_NASPUNKT};
   virtual TFIBLargeIntField * get_ElementID_SADR_NASPUNKT(void)=0;
   virtual void set_ElementID_SADR_NASPUNKT(TFIBLargeIntField * ElementID_SADR_NASPUNKT)=0;

   __property TFIBLargeIntField * ElementIDBASE_SADR_NASPUNKT = {read = get_ElementIDBASE_SADR_NASPUNKT , write = set_ElementIDBASE_SADR_NASPUNKT};
   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_NASPUNKT(void)=0;
   virtual void set_ElementIDBASE_SADR_NASPUNKT(TFIBLargeIntField * ElementIDBASE_SADR_NASPUNKT)=0;

   __property TFIBLargeIntField * ElementIDRAYON_SADR_NASPUNKT = {read = get_ElementIDRAYON_SADR_NASPUNKT , write = set_ElementIDRAYON_SADR_NASPUNKT};
   virtual TFIBLargeIntField * get_ElementIDRAYON_SADR_NASPUNKT(void)=0;
   virtual void set_ElementIDRAYON_SADR_NASPUNKT(TFIBLargeIntField * ElementIDRAYON_SADR_NASPUNKT)=0;

   __property TFIBWideStringField * ElementNAME_SADR_NASPUNKT = {read = get_ElementNAME_SADR_NASPUNKT , write = set_ElementNAME_SADR_NASPUNKT};
   virtual TFIBWideStringField * get_ElementNAME_SADR_NASPUNKT(void)=0;
   virtual void set_ElementNAME_SADR_NASPUNKT(TFIBWideStringField * ElementNAME_SADR_NASPUNKT)=0;

   __property TFIBIntegerField * ElementFL_GOROD_SADR_NASPUNKT = {read = get_ElementFL_GOROD_SADR_NASPUNKT , write = set_ElementFL_GOROD_SADR_NASPUNKT};
   virtual TFIBIntegerField * get_ElementFL_GOROD_SADR_NASPUNKT(void)=0;
   virtual void set_ElementFL_GOROD_SADR_NASPUNKT(TFIBIntegerField * ElementFL_GOROD_SADR_NASPUNKT)=0;

   __property TFIBLargeIntField * ElementID_SADR_RAYON = {read = get_ElementID_SADR_RAYON , write = set_ElementID_SADR_RAYON};
   virtual TFIBLargeIntField * get_ElementID_SADR_RAYON(void)=0;
   virtual void set_ElementID_SADR_RAYON(TFIBLargeIntField * ElementID_SADR_RAYON)=0;

   __property TFIBLargeIntField * ElementIDBASE_SADR_RAYON = {read = get_ElementIDBASE_SADR_RAYON , write = set_ElementIDBASE_SADR_RAYON};
   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_RAYON(void)=0;
   virtual void set_ElementIDBASE_SADR_RAYON(TFIBLargeIntField * ElementIDBASE_SADR_RAYON)=0;

   __property TFIBLargeIntField * ElementIDREGION_SADR_RAYON = {read = get_ElementIDREGION_SADR_RAYON , write = set_ElementIDREGION_SADR_RAYON};
   virtual TFIBLargeIntField * get_ElementIDREGION_SADR_RAYON(void)=0;
   virtual void set_ElementIDREGION_SADR_RAYON(TFIBLargeIntField * ElementIDREGION_SADR_RAYON)=0;

   __property TFIBWideStringField * ElementNAME_SADR_RAYON = {read = get_ElementNAME_SADR_RAYON , write = set_ElementNAME_SADR_RAYON};
   virtual TFIBWideStringField * get_ElementNAME_SADR_RAYON(void)=0;
   virtual void set_ElementNAME_SADR_RAYON(TFIBWideStringField * ElementNAME_SADR_RAYON)=0;

   __property TFIBLargeIntField * ElementID_SADR_REGION = {read = get_ElementID_SADR_REGION , write = set_ElementID_SADR_REGION};
   virtual TFIBLargeIntField * get_ElementID_SADR_REGION(void)=0;
   virtual void set_ElementID_SADR_REGION(TFIBLargeIntField * ElementID_SADR_REGION)=0;

   __property TFIBLargeIntField * ElementIDBASE_SADR_REGION = {read = get_ElementIDBASE_SADR_REGION , write = set_ElementIDBASE_SADR_REGION};
   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_REGION(void)=0;
   virtual void set_ElementIDBASE_SADR_REGION(TFIBLargeIntField * ElementIDBASE_SADR_REGION)=0;

   __property TFIBWideStringField * ElementNAME_SADR_REGION = {read = get_ElementNAME_SADR_REGION , write = set_ElementNAME_SADR_REGION};
   virtual TFIBWideStringField * get_ElementNAME_SADR_REGION(void)=0;
   virtual void set_ElementNAME_SADR_REGION(TFIBWideStringField * ElementNAME_SADR_REGION)=0;

   __property TFIBWideStringField * ElementCODE_SADR_REGION = {read = get_ElementCODE_SADR_REGION , write = set_ElementCODE_SADR_REGION};
   virtual TFIBWideStringField * get_ElementCODE_SADR_REGION(void)=0;
   virtual void set_ElementCODE_SADR_REGION(TFIBWideStringField * ElementCODE_SADR_REGION)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_owner)=0;
   virtual bool NewElement(__int64 id_owner)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IDMSprAddressKV __uuidof(IDMSprAddressKV)
#endif
