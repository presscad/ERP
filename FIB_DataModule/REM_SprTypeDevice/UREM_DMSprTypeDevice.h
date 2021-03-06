//---------------------------------------------------------------------------

#ifndef UREM_DMSprTypeDeviceH
#define UREM_DMSprTypeDeviceH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


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
//---------------------------------------------------------------------------
class TREM_DMSprTypeDevice : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_REM_STYPEDEVICE;
	TFIBWideStringField *TableGID_REM_STYPEDEVICE;
	TFIBLargeIntField *TableIDBASE_REM_STYPEDEVICE;
	TFIBWideStringField *TableNAME_REM_STYPEDEVICE;
	TFIBLargeIntField *ElementID_REM_STYPEDEVICE;
	TFIBWideStringField *ElementGID_REM_STYPEDEVICE;
	TFIBLargeIntField *ElementIDBASE_REM_STYPEDEVICE;
	TFIBWideStringField *ElementNAME_REM_STYPEDEVICE;
		void __fastcall DataModuleDestroy(TObject *Sender);
		void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TREM_DMSprTypeDevice(TComponent* Owner);

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
		void OpenTable(void);
		int OpenElement(__int64 id);  //���������� ���������� ���������
		bool NewElement(void);
		bool SaveElement(void);
		bool DeleteElement(__int64 id);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprTypeDevice *REM_DMSprTypeDevice;
//---------------------------------------------------------------------------
#endif
