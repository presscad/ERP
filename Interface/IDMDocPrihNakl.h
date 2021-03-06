#ifndef UIDMDocPrihNaklH
#define UIDMDocPrihNaklH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocPrihNakl)) IDMDocPrihNakl : public IMainInterface
{
public:
   __property TDataSource * DataSourceDoc = {read = get_DataSourceDoc , write = set_DataSourceDoc};
   virtual TDataSource * get_DataSourceDoc(void)=0;
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc)=0;

   __property TDataSource * DataSourceDocT = {read = get_DataSourceDocT , write = set_DataSourceDocT};
   virtual TDataSource * get_DataSourceDocT(void)=0;
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT)=0;

   __property TDataSource * DataSourceDocAll = {read = get_DataSourceDocAll , write = set_DataSourceDocAll};
   virtual TDataSource * get_DataSourceDocAll(void)=0;
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll)=0;

   __property TpFIBDataSet * DocAll = {read = get_DocAll , write = set_DocAll};
   virtual TpFIBDataSet * get_DocAll(void)=0;
   virtual void set_DocAll(TpFIBDataSet * DocAll)=0;

   __property TpFIBDataSet * Doc = {read = get_Doc , write = set_Doc};
   virtual TpFIBDataSet * get_Doc(void)=0;
   virtual void set_Doc(TpFIBDataSet * Doc)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBDateTimeField * DocAllPOSDOC = {read = get_DocAllPOSDOC , write = set_DocAllPOSDOC};
   virtual TFIBDateTimeField * get_DocAllPOSDOC(void)=0;
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)=0;

   __property TFIBSmallIntField * DocAllPRDOC = {read = get_DocAllPRDOC , write = set_DocAllPRDOC};
   virtual TFIBSmallIntField * get_DocAllPRDOC(void)=0;
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)=0;

   __property TFIBIntegerField * DocAllNUMDOC = {read = get_DocAllNUMDOC , write = set_DocAllNUMDOC};
   virtual TFIBIntegerField * get_DocAllNUMDOC(void)=0;
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)=0;

   __property TFIBBCDField * DocAllSUMDOC = {read = get_DocAllSUMDOC , write = set_DocAllSUMDOC};
   virtual TFIBBCDField * get_DocAllSUMDOC(void)=0;
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)=0;

   __property TFIBBCDField * DocTKOLPRNT = {read = get_DocTKOLPRNT , write = set_DocTKOLPRNT};
   virtual TFIBBCDField * get_DocTKOLPRNT(void)=0;
   virtual void set_DocTKOLPRNT(TFIBBCDField * DocTKOLPRNT)=0;

   __property TFIBBCDField * DocTKFPRNT = {read = get_DocTKFPRNT , write = set_DocTKFPRNT};
   virtual TFIBBCDField * get_DocTKFPRNT(void)=0;
   virtual void set_DocTKFPRNT(TFIBBCDField * DocTKFPRNT)=0;

   __property TFIBBCDField * DocTPRICEPRNT = {read = get_DocTPRICEPRNT , write = set_DocTPRICEPRNT};
   virtual TFIBBCDField * get_DocTPRICEPRNT(void)=0;
   virtual void set_DocTPRICEPRNT(TFIBBCDField * DocTPRICEPRNT)=0;

   __property TFIBBCDField * DocTSUMPRNT = {read = get_DocTSUMPRNT , write = set_DocTSUMPRNT};
   virtual TFIBBCDField * get_DocTSUMPRNT(void)=0;
   virtual void set_DocTSUMPRNT(TFIBBCDField * DocTSUMPRNT)=0;

   __property TFIBIntegerField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBIntegerField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TFIBBCDField * DocTNAC_DPRNT = {read = get_DocTNAC_DPRNT , write = set_DocTNAC_DPRNT};
   virtual TFIBBCDField * get_DocTNAC_DPRNT(void)=0;
   virtual void set_DocTNAC_DPRNT(TFIBBCDField * DocTNAC_DPRNT)=0;

   __property TFIBBCDField * DocTRPRICE_DPRNT = {read = get_DocTRPRICE_DPRNT , write = set_DocTRPRICE_DPRNT};
   virtual TFIBBCDField * get_DocTRPRICE_DPRNT(void)=0;
   virtual void set_DocTRPRICE_DPRNT(TFIBBCDField * DocTRPRICE_DPRNT)=0;

   __property TFIBBCDField * DocTRSUM_DPRNT = {read = get_DocTRSUM_DPRNT , write = set_DocTRSUM_DPRNT};
   virtual TFIBBCDField * get_DocTRSUM_DPRNT(void)=0;
   virtual void set_DocTRSUM_DPRNT(TFIBBCDField * DocTRSUM_DPRNT)=0;

   __property TFIBBCDField * DocRSUM_DPRN = {read = get_DocRSUM_DPRN , write = set_DocRSUM_DPRN};
   virtual TFIBBCDField * get_DocRSUM_DPRN(void)=0;
   virtual void set_DocRSUM_DPRN(TFIBBCDField * DocRSUM_DPRN)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBDateTimeField * DocPOSDOCPOST_DPRN = {read = get_DocPOSDOCPOST_DPRN , write = set_DocPOSDOCPOST_DPRN};
   virtual TFIBDateTimeField * get_DocPOSDOCPOST_DPRN(void)=0;
   virtual void set_DocPOSDOCPOST_DPRN(TFIBDateTimeField * DocPOSDOCPOST_DPRN)=0;

   __property TFIBLargeIntField * DocAllIDDOC = {read = get_DocAllIDDOC , write = set_DocAllIDDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOC(void)=0;
   virtual void set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

   __property TFIBLargeIntField * DocAllIDFIRMDOC = {read = get_DocAllIDFIRMDOC , write = set_DocAllIDFIRMDOC};
   virtual TFIBLargeIntField * get_DocAllIDFIRMDOC(void)=0;
   virtual void set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)=0;

   __property TFIBLargeIntField * DocAllIDSKLDOC = {read = get_DocAllIDSKLDOC , write = set_DocAllIDSKLDOC};
   virtual TFIBLargeIntField * get_DocAllIDSKLDOC(void)=0;
   virtual void set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)=0;

   __property TFIBLargeIntField * DocAllIDKLDOC = {read = get_DocAllIDKLDOC , write = set_DocAllIDKLDOC};
   virtual TFIBLargeIntField * get_DocAllIDKLDOC(void)=0;
   virtual void set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)=0;

   __property TFIBLargeIntField * DocAllIDDOGDOC = {read = get_DocAllIDDOGDOC , write = set_DocAllIDDOGDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOGDOC(void)=0;
   virtual void set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)=0;

   __property TFIBLargeIntField * DocAllIDUSERDOC = {read = get_DocAllIDUSERDOC , write = set_DocAllIDUSERDOC};
   virtual TFIBLargeIntField * get_DocAllIDUSERDOC(void)=0;
   virtual void set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)=0;

   __property TFIBWideStringField * DocAllGID_DOC = {read = get_DocAllGID_DOC , write = set_DocAllGID_DOC};
   virtual TFIBWideStringField * get_DocAllGID_DOC(void)=0;
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)=0;

   __property TFIBWideStringField * DocAllPREFIKSDOC = {read = get_DocAllPREFIKSDOC , write = set_DocAllPREFIKSDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKSDOC(void)=0;
   virtual void set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)=0;

   __property TFIBLargeIntField * DocAllIDDOCOSNDOC = {read = get_DocAllIDDOCOSNDOC , write = set_DocAllIDDOCOSNDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOCOSNDOC(void)=0;
   virtual void set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)=0;

   __property TFIBLargeIntField * DocAllIDEXTDOC = {read = get_DocAllIDEXTDOC , write = set_DocAllIDEXTDOC};
   virtual TFIBLargeIntField * get_DocAllIDEXTDOC(void)=0;
   virtual void set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)=0;

   __property TFIBIntegerField * DocAllTYPEEXTDOC = {read = get_DocAllTYPEEXTDOC , write = set_DocAllTYPEEXTDOC};
   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void)=0;
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)=0;

   __property TFIBLargeIntField * DocAllIDBASE_GALLDOC = {read = get_DocAllIDBASE_GALLDOC , write = set_DocAllIDBASE_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBASE_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDPROJECT_GALLDOC = {read = get_DocAllIDPROJECT_GALLDOC , write = set_DocAllIDPROJECT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDPROJECT_GALLDOC(void)=0;
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)=0;

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

   __property TFIBLargeIntField * DocIDPRN = {read = get_DocIDPRN , write = set_DocIDPRN};
   virtual TFIBLargeIntField * get_DocIDPRN(void)=0;
   virtual void set_DocIDPRN(TFIBLargeIntField * DocIDPRN)=0;

   __property TFIBLargeIntField * DocIDDOCPRN = {read = get_DocIDDOCPRN , write = set_DocIDDOCPRN};
   virtual TFIBLargeIntField * get_DocIDDOCPRN(void)=0;
   virtual void set_DocIDDOCPRN(TFIBLargeIntField * DocIDDOCPRN)=0;

   __property TFIBWideStringField * DocPRIMDOC = {read = get_DocPRIMDOC , write = set_DocPRIMDOC};
   virtual TFIBWideStringField * get_DocPRIMDOC(void)=0;
   virtual void set_DocPRIMDOC(TFIBWideStringField * DocPRIMDOC)=0;

   __property TFIBLargeIntField * DocIDTPRICE = {read = get_DocIDTPRICE , write = set_DocIDTPRICE};
   virtual TFIBLargeIntField * get_DocIDTPRICE(void)=0;
   virtual void set_DocIDTPRICE(TFIBLargeIntField * DocIDTPRICE)=0;

   __property TFIBWideStringField * DocGID_DPRN = {read = get_DocGID_DPRN , write = set_DocGID_DPRN};
   virtual TFIBWideStringField * get_DocGID_DPRN(void)=0;
   virtual void set_DocGID_DPRN(TFIBWideStringField * DocGID_DPRN)=0;

   __property TFIBLargeIntField * DocIDRTPRICE_DPRN = {read = get_DocIDRTPRICE_DPRN , write = set_DocIDRTPRICE_DPRN};
   virtual TFIBLargeIntField * get_DocIDRTPRICE_DPRN(void)=0;
   virtual void set_DocIDRTPRICE_DPRN(TFIBLargeIntField * DocIDRTPRICE_DPRN)=0;

   __property TFIBLargeIntField * DocIDBASE_DPRN = {read = get_DocIDBASE_DPRN , write = set_DocIDBASE_DPRN};
   virtual TFIBLargeIntField * get_DocIDBASE_DPRN(void)=0;
   virtual void set_DocIDBASE_DPRN(TFIBLargeIntField * DocIDBASE_DPRN)=0;

   __property TFIBLargeIntField * DocTIDPRNT = {read = get_DocTIDPRNT , write = set_DocTIDPRNT};
   virtual TFIBLargeIntField * get_DocTIDPRNT(void)=0;
   virtual void set_DocTIDPRNT(TFIBLargeIntField * DocTIDPRNT)=0;

   __property TFIBLargeIntField * DocTIDDOCPRNT = {read = get_DocTIDDOCPRNT , write = set_DocTIDDOCPRNT};
   virtual TFIBLargeIntField * get_DocTIDDOCPRNT(void)=0;
   virtual void set_DocTIDDOCPRNT(TFIBLargeIntField * DocTIDDOCPRNT)=0;

   __property TFIBLargeIntField * DocTIDNOMPRNT = {read = get_DocTIDNOMPRNT , write = set_DocTIDNOMPRNT};
   virtual TFIBLargeIntField * get_DocTIDNOMPRNT(void)=0;
   virtual void set_DocTIDNOMPRNT(TFIBLargeIntField * DocTIDNOMPRNT)=0;

   __property TFIBLargeIntField * DocTIDEDPRNT = {read = get_DocTIDEDPRNT , write = set_DocTIDEDPRNT};
   virtual TFIBLargeIntField * get_DocTIDEDPRNT(void)=0;
   virtual void set_DocTIDEDPRNT(TFIBLargeIntField * DocTIDEDPRNT)=0;

   __property TFIBLargeIntField * DocTIDPARTPRNT = {read = get_DocTIDPARTPRNT , write = set_DocTIDPARTPRNT};
   virtual TFIBLargeIntField * get_DocTIDPARTPRNT(void)=0;
   virtual void set_DocTIDPARTPRNT(TFIBLargeIntField * DocTIDPARTPRNT)=0;

   __property TFIBWideStringField * DocTGID_DPRNT = {read = get_DocTGID_DPRNT , write = set_DocTGID_DPRNT};
   virtual TFIBWideStringField * get_DocTGID_DPRNT(void)=0;
   virtual void set_DocTGID_DPRNT(TFIBWideStringField * DocTGID_DPRNT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DPRNT = {read = get_DocTIDBASE_DPRNT , write = set_DocTIDBASE_DPRNT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DPRNT(void)=0;
   virtual void set_DocTIDBASE_DPRNT(TFIBLargeIntField * DocTIDBASE_DPRNT)=0;

   __property TFIBIntegerField * DocTNDS_DPRNT = {read = get_DocTNDS_DPRNT , write = set_DocTNDS_DPRNT};
   virtual TFIBIntegerField * get_DocTNDS_DPRNT(void)=0;
   virtual void set_DocTNDS_DPRNT(TFIBIntegerField * DocTNDS_DPRNT)=0;

   __property TFIBBCDField * DocTSUMNDS_DPRNT = {read = get_DocTSUMNDS_DPRNT , write = set_DocTSUMNDS_DPRNT};
   virtual TFIBBCDField * get_DocTSUMNDS_DPRNT(void)=0;
   virtual void set_DocTSUMNDS_DPRNT(TFIBBCDField * DocTSUMNDS_DPRNT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocTGTDPART = {read = get_DocTGTDPART , write = set_DocTGTDPART};
   virtual TFIBWideStringField * get_DocTGTDPART(void)=0;
   virtual void set_DocTGTDPART(TFIBWideStringField * DocTGTDPART)=0;

   __property TFIBWideStringField * DocTSERTPART = {read = get_DocTSERTPART , write = set_DocTSERTPART};
   virtual TFIBWideStringField * get_DocTSERTPART(void)=0;
   virtual void set_DocTSERTPART(TFIBWideStringField * DocTSERTPART)=0;

   __property TFIBDateTimeField * DocTSRGODNPART = {read = get_DocTSRGODNPART , write = set_DocTSRGODNPART};
   virtual TFIBDateTimeField * get_DocTSRGODNPART(void)=0;
   virtual void set_DocTSRGODNPART(TFIBDateTimeField * DocTSRGODNPART)=0;

   __property TFIBWideStringField * DocNUMDOCPOST_DPRN = {read = get_DocNUMDOCPOST_DPRN , write = set_DocNUMDOCPOST_DPRN};
   virtual TFIBWideStringField * get_DocNUMDOCPOST_DPRN(void)=0;
   virtual void set_DocNUMDOCPOST_DPRN(TFIBWideStringField * DocNUMDOCPOST_DPRN)=0;

   __property TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC = {read = get_DocAllIDBUSINOP_GALLDOC , write = set_DocAllIDBUSINOP_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC = {read = get_DocAllPREFIKS_NUM_GALLDOC , write = set_DocAllPREFIKS_NUM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)=0;

   __property TFIBBCDField * DocTNAC_SUM_ED = {read = get_DocTNAC_SUM_ED , write = set_DocTNAC_SUM_ED};
   virtual TFIBBCDField * get_DocTNAC_SUM_ED(void)=0;
   virtual void set_DocTNAC_SUM_ED(TFIBBCDField * DocTNAC_SUM_ED)=0;

   __property TFIBBCDField * DocTNAC_SUM = {read = get_DocTNAC_SUM , write = set_DocTNAC_SUM};
   virtual TFIBBCDField * get_DocTNAC_SUM(void)=0;
   virtual void set_DocTNAC_SUM(TFIBBCDField * DocTNAC_SUM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElementaMaster = {read = get_IdElementaMaster , write = set_IdElementaMaster};
   virtual __int64 get_IdElementaMaster(void)=0;
   virtual void set_IdElementaMaster(__int64 IdElementaMaster)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property bool IsmPrice = {read = get_IsmPrice , write = set_IsmPrice};
   virtual bool get_IsmPrice(void)=0;
   virtual void set_IsmPrice(bool IsmPrice)=0;

   __property bool IsmSum = {read = get_IsmSum , write = set_IsmSum};
   virtual bool get_IsmSum(void)=0;
   virtual void set_IsmSum(bool IsmSum)=0;

   __property bool SkladRozn = {read = get_SkladRozn , write = set_SkladRozn};
   virtual bool get_SkladRozn(void)=0;
   virtual void set_SkladRozn(bool SkladRozn)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual void NewDoc(void)=0;
   virtual void CopyDoc(__int64 id_doc)=0;
   virtual void OpenDoc(__int64 id)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual double Summa(void)=0;
   virtual void CreateNewPart(void)=0;
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)=0;
   virtual bool UpdatePrice(void)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocPrihNakl __uuidof(IDMDocPrihNakl)
#endif
