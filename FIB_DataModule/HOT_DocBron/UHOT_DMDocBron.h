//---------------------------------------------------------------------------

#ifndef UHOT_DMDocBronH
#define UHOT_DMDocBronH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class THOT_DMDocBron : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TFIBIntegerField *NumDocMAXNUMBER;
	TFIBDateTimeField *DocAllPOS_HOT_GALLDOC;
	TFIBSmallIntField *DocAllPR_HOT_GALLDOC;
	TFIBBCDField *DocAllSUM_HOT_GALLDOC;
	TFIBIntegerField *DocAllNUMBER_HOT_GALLDOC;
	TpFIBQuery *QueryDvReg;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBDataSet *DocT;
	TFIBIntegerField *DocTKOLM_HOT_SOSTNF;
	TFIBDateTimeField *DocTPOSNACH_HOT_SOSTNF;
	TFIBDateTimeField *DocTPOSCON_HOT_SOSTNF;
	TDataSource *DataSourceDocT;
	TFIBWideStringField *DocAllTDOC_HOT_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocTNAME_HOT_SNF;
	TFIBWideStringField *DocTNAME_HOT_SCATNOM;
	TFIBWideStringField *DocTNAME_HOT_STYPEPOS;
	TFIBWideStringField *DocTNAMEKLIENT;
	TFIBWideStringField *DocTNAME_HOT_SSOSTNOM;
	TFIBLargeIntField *DocAllID_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDFIRM_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDKL_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDUSER_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDDOCOSN_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDBASE_HOT_GALLDOC;
	TFIBLargeIntField *DocID_HOT_DBRON;
	TFIBLargeIntField *DocIDDOCH_HOT_DBRON;
	TFIBWideStringField *DocDESCR_HOT_DBRON;
	TFIBLargeIntField *DocIDBASE_HOT_DBRON;
	TFIBLargeIntField *DocIDTPRICE_HOT_DBRON;
	TFIBLargeIntField *DocTID_HOT_DBRONT;
	TFIBLargeIntField *DocTIDDOCH_HOT_DBRONT;
	TFIBLargeIntField *DocTIDSOST_HOT_DBRONT;
	TFIBLargeIntField *DocTIDBASE_HOT_DBRONT;
	TFIBLargeIntField *DocTID_HOT_SOSTNF;
	TFIBLargeIntField *DocTIDNOMER_HOT_SOSTNF;
	TFIBLargeIntField *DocTIDPLAT_HOT_SOSTNF;
	TFIBLargeIntField *DocTIDGUEST_HOT_SOSTNF;
	TFIBLargeIntField *DocTIDSOST_HOT_SOSTNF;
	TFIBLargeIntField *DocTIDTPOS_HOT_SOSTNF;
	TFIBLargeIntField *DocTIDCAT_HOT_SOSTNF;
	TFIBLargeIntField *DocTIDDOCH_HOT_SOSTNF;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_HOT_GALLDOCChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	double Summa(void);
	__int64 IdDocH;           //������������� ������� ������
public:		// User declarations
        __fastcall THOT_DMDocBron(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������

		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		//������� ���������

        void NewDoc(void);
		void OpenDoc(__int64 IdDoc);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void CloseDoc(void);
        bool DeleteDoc(__int64 id);


		void AddString(void);
		void DeleteString(void);


        bool Prosmotr;    //������ ��������
        bool Vibor;       //��� ������




		
};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMDocBron *HOT_DMDocBron;
//---------------------------------------------------------------------------
#endif
