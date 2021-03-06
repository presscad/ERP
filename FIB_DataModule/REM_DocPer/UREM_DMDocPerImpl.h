#ifndef UREM_DMDocPerImplH
#define UREM_DMDocPerImplH
#include "IREM_DMDocPer.h"
#include "UREM_DMDocPer.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMDocPerImpl)) TREM_DMDocPerImpl : public IREM_DMDocPer
{
public:
   TREM_DMDocPerImpl();
   ~TREM_DMDocPerImpl();
   TREM_DMDocPer * Object;
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

//IREM_DMDocPer
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void);
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER);

   virtual TpFIBDataSet * get_SpisokTypePrice(void);
   virtual void set_SpisokTypePrice(TpFIBDataSet * SpisokTypePrice);

   virtual TFIBIntegerField * get_SpisokTypePriceID_TPRICE(void);
   virtual void set_SpisokTypePriceID_TPRICE(TFIBIntegerField * SpisokTypePriceID_TPRICE);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TpFIBDataSet * get_DocOsn(void);
   virtual void set_DocOsn(TpFIBDataSet * DocOsn);

   virtual TDataSource * get_DataSourceDocOsn(void);
   virtual void set_DataSourceDocOsn(TDataSource * DataSourceDocOsn);

   virtual TFIBWideStringField * get_SpisokTypePriceNAME_TPRICE(void);
   virtual void set_SpisokTypePriceNAME_TPRICE(TFIBWideStringField * SpisokTypePriceNAME_TPRICE);

   virtual TFIBWideStringField * get_SpisokTypePriceGID_STPRICE(void);
   virtual void set_SpisokTypePriceGID_STPRICE(TFIBWideStringField * SpisokTypePriceGID_STPRICE);

   virtual TFIBLargeIntField * get_DocAllID_REM_GALLDOC(void);
   virtual void set_DocAllID_REM_GALLDOC(TFIBLargeIntField * DocAllID_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBASE_REM_GALLDOC(void);
   virtual void set_DocAllIDBASE_REM_GALLDOC(TFIBLargeIntField * DocAllIDBASE_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDFIRM_REM_GALLDOC(void);
   virtual void set_DocAllIDFIRM_REM_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDSKLAD_REM_GALLDOC(void);
   virtual void set_DocAllIDSKLAD_REM_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDKLIENT_REM_GALLDOC(void);
   virtual void set_DocAllIDKLIENT_REM_GALLDOC(TFIBLargeIntField * DocAllIDKLIENT_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDUSER_REM_GALLDOC(void);
   virtual void set_DocAllIDUSER_REM_GALLDOC(TFIBLargeIntField * DocAllIDUSER_REM_GALLDOC);

   virtual TFIBDateTimeField * get_DocAllPOS_REM_GALLDOC(void);
   virtual void set_DocAllPOS_REM_GALLDOC(TFIBDateTimeField * DocAllPOS_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocAllNUM_REM_GALLDOC(void);
   virtual void set_DocAllNUM_REM_GALLDOC(TFIBIntegerField * DocAllNUM_REM_GALLDOC);

   virtual TFIBSmallIntField * get_DocAllPR_REM_GALLDOC(void);
   virtual void set_DocAllPR_REM_GALLDOC(TFIBSmallIntField * DocAllPR_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllTDOC_REM_GALLDOC(void);
   virtual void set_DocAllTDOC_REM_GALLDOC(TFIBWideStringField * DocAllTDOC_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOCOSN_REM_GALLDOC(void);
   virtual void set_DocAllIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC_REM_GALLDOC(void);
   virtual void set_DocAllTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * DocAllTYPEEXTDOC_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDEXTDOC_REM_GALLDOC(void);
   virtual void set_DocAllIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * DocAllIDEXTDOC_REM_GALLDOC);

   virtual TFIBBCDField * get_DocAllSUM_REM_GALLDOC(void);
   virtual void set_DocAllSUM_REM_GALLDOC(TFIBBCDField * DocAllSUM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDPROJECT_REM_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_REM_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_REM_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_REM_GALLDOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocOsnTDOC_REM_GALLDOC(void);
   virtual void set_DocOsnTDOC_REM_GALLDOC(TFIBWideStringField * DocOsnTDOC_REM_GALLDOC);

   virtual TFIBDateTimeField * get_DocOsnPOS_REM_GALLDOC(void);
   virtual void set_DocOsnPOS_REM_GALLDOC(TFIBDateTimeField * DocOsnPOS_REM_GALLDOC);

   virtual TFIBIntegerField * get_DocOsnNUM_REM_GALLDOC(void);
   virtual void set_DocOsnNUM_REM_GALLDOC(TFIBIntegerField * DocOsnNUM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocID_REM_DPER(void);
   virtual void set_DocID_REM_DPER(TFIBLargeIntField * DocID_REM_DPER);

   virtual TFIBLargeIntField * get_DocIDBASE_REM_DPER(void);
   virtual void set_DocIDBASE_REM_DPER(TFIBLargeIntField * DocIDBASE_REM_DPER);

   virtual TFIBLargeIntField * get_DocIDDOC_REM_DPER(void);
   virtual void set_DocIDDOC_REM_DPER(TFIBLargeIntField * DocIDDOC_REM_DPER);

   virtual TFIBWideStringField * get_DocGID_REM_DPER(void);
   virtual void set_DocGID_REM_DPER(TFIBWideStringField * DocGID_REM_DPER);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_REM_DPER(void);
   virtual void set_DocIDRTPRICE_REM_DPER(TFIBLargeIntField * DocIDRTPRICE_REM_DPER);

   virtual TFIBLargeIntField * get_DocIDSKLPOL_REM_DPER(void);
   virtual void set_DocIDSKLPOL_REM_DPER(TFIBLargeIntField * DocIDSKLPOL_REM_DPER);

   virtual TFIBWideStringField * get_DocPRIM_REM_DPER(void);
   virtual void set_DocPRIM_REM_DPER(TFIBWideStringField * DocPRIM_REM_DPER);

   virtual TFIBLargeIntField * get_DocTID_REM_DPERT(void);
   virtual void set_DocTID_REM_DPERT(TFIBLargeIntField * DocTID_REM_DPERT);

   virtual TFIBLargeIntField * get_DocTIDBASE_REM_DPERT(void);
   virtual void set_DocTIDBASE_REM_DPERT(TFIBLargeIntField * DocTIDBASE_REM_DPERT);

   virtual TFIBLargeIntField * get_DocTIDDOC_REM_DPERT(void);
   virtual void set_DocTIDDOC_REM_DPERT(TFIBLargeIntField * DocTIDDOC_REM_DPERT);

   virtual TFIBWideStringField * get_DocTGID_REM_DPERT(void);
   virtual void set_DocTGID_REM_DPERT(TFIBWideStringField * DocTGID_REM_DPERT);

   virtual TFIBLargeIntField * get_DocTIDNOM_REM_DPERT(void);
   virtual void set_DocTIDNOM_REM_DPERT(TFIBLargeIntField * DocTIDNOM_REM_DPERT);

   virtual TFIBLargeIntField * get_DocTIDED_REM_DPERT(void);
   virtual void set_DocTIDED_REM_DPERT(TFIBLargeIntField * DocTIDED_REM_DPERT);

   virtual TFIBLargeIntField * get_DocTIDHW_REM_DPERT(void);
   virtual void set_DocTIDHW_REM_DPERT(TFIBLargeIntField * DocTIDHW_REM_DPERT);

   virtual TFIBBCDField * get_DocTKOL_REM_DPERT(void);
   virtual void set_DocTKOL_REM_DPERT(TFIBBCDField * DocTKOL_REM_DPERT);

   virtual TFIBBCDField * get_DocTKF_REM_DPERT(void);
   virtual void set_DocTKF_REM_DPERT(TFIBBCDField * DocTKF_REM_DPERT);

   virtual TFIBBCDField * get_DocTRPRICE_REM_DPERT(void);
   virtual void set_DocTRPRICE_REM_DPERT(TFIBBCDField * DocTRPRICE_REM_DPERT);

   virtual TFIBBCDField * get_DocTRSUM_REM_DPERT(void);
   virtual void set_DocTRSUM_REM_DPERT(TFIBBCDField * DocTRSUM_REM_DPERT);

   virtual TFIBBCDField * get_DocTNAC_REM_DPERT(void);
   virtual void set_DocTNAC_REM_DPERT(TFIBBCDField * DocTNAC_REM_DPERT);

   virtual TFIBSmallIntField * get_DocTDVREG_REM_DPERT(void);
   virtual void set_DocTDVREG_REM_DPERT(TFIBSmallIntField * DocTDVREG_REM_DPERT);

   virtual TFIBWideStringField * get_DocTKRNAMENOM(void);
   virtual void set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBSmallIntField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBLargeIntField * get_DocTIDGRPNOM(void);
   virtual void set_DocTIDGRPNOM(TFIBLargeIntField * DocTIDGRPNOM);

   virtual TFIBLargeIntField * get_DocTIDVID_SNOM(void);
   virtual void set_DocTIDVID_SNOM(TFIBLargeIntField * DocTIDVID_SNOM);

   virtual TFIBWideStringField * get_DocTNAMEGN(void);
   virtual void set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN);

   virtual TFIBWideStringField * get_DocTNAME_SVIDNOM(void);
   virtual void set_DocTNAME_SVIDNOM(TFIBWideStringField * DocTNAME_SVIDNOM);

   virtual TFIBWideStringField * get_DocTNAME_REM_SHARDWARE(void);
   virtual void set_DocTNAME_REM_SHARDWARE(TFIBWideStringField * DocTNAME_REM_SHARDWARE);

   virtual TFIBIntegerField * get_DocTCODE_REM_SHARDWARE(void);
   virtual void set_DocTCODE_REM_SHARDWARE(TFIBIntegerField * DocTCODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_DocTSERNUM_REM_SHARDWARE(void);
   virtual void set_DocTSERNUM_REM_SHARDWARE(TFIBWideStringField * DocTSERNUM_REM_SHARDWARE);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBWideStringField * get_DocNAMESKLAD(void);
   virtual void set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD);

   virtual TFIBSmallIntField * get_DocTDVREG_POL_REM_DPERT(void);
   virtual void set_DocTDVREG_POL_REM_DPERT(TFIBSmallIntField * DocTDVREG_POL_REM_DPERT);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_REM_GALLDOC);

   virtual TFIBLargeIntField * get_DocTIDTNOM_REM_DPERT(void);
   virtual void set_DocTIDTNOM_REM_DPERT(TFIBLargeIntField * DocTIDTNOM_REM_DPERT);

   virtual TFIBLargeIntField * get_DocTIDMHRAN_OTPR_REM_DPERT(void);
   virtual void set_DocTIDMHRAN_OTPR_REM_DPERT(TFIBLargeIntField * DocTIDMHRAN_OTPR_REM_DPERT);

   virtual TFIBLargeIntField * get_DocTIDMHRAN_POL_REM_DPERT(void);
   virtual void set_DocTIDMHRAN_POL_REM_DPERT(TFIBLargeIntField * DocTIDMHRAN_POL_REM_DPERT);

   virtual TFIBWideStringField * get_DocTNAME_SMHRAN_POL(void);
   virtual void set_DocTNAME_SMHRAN_POL(TFIBWideStringField * DocTNAME_SMHRAN_POL);

   virtual TFIBWideStringField * get_DocTNAME_STNOM(void);
   virtual void set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM);

   virtual TFIBWideStringField * get_DocTNAME_SMHRAN_OTPR(void);
   virtual void set_DocTNAME_SMHRAN_OTPR(TFIBWideStringField * DocTNAME_SMHRAN_OTPR);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual UnicodeString get_ProsmotrText(void);
   virtual void set_ProsmotrText(UnicodeString ProsmotrText);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AutoRaschet(void);
   virtual void set_AutoRaschet(bool AutoRaschet);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual bool get_SkladRozn(void);
   virtual void set_SkladRozn(bool SkladRozn);

   virtual bool get_NoOtrOstatok(void);
   virtual void set_NoOtrOstatok(bool NoOtrOstatok);

   virtual void NewDoc(void);
   virtual bool OpenDoc(__int64 IdDoc);
   virtual void OpenDocOsn(void);
   virtual bool SaveDoc(void);
   virtual bool BeforeSaveDoc(void);
   virtual bool AfterSaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual void CloseDoc(void);
   virtual void ValidateProsmotr(void);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TREM_DMDocPerImpl __uuidof(TREM_DMDocPerImpl)
#endif
