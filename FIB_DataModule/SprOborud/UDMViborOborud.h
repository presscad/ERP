//---------------------------------------------------------------------------

#ifndef UDMViborOborudH
#define UDMViborOborudH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//#include <DB.hpp>
//#include <IBCustomDataSet.hpp>
//#include <IBDatabase.hpp>
//#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDMViborOborud : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TFIBBCDField *TableID_OBORUD;
	TFIBBCDField *TableIDARM_SOBORUD;
	TFIBSmallIntField *TableON_START_SOBORUD;
	TFIBWideStringField *TableNAME_OBORUD;
	TFIBWideStringField *TableCOMPNAME_OBORUD;
	TFIBWideStringField *TableCOMNAME_OBORUD;
	TFIBWideStringField *TableBAUDRATE_OBORUD;
	TFIBWideStringField *TableTYPE_OBORUD;
	TFIBWideStringField *TableMODEL_OBORUD;
	TFIBWideStringField *TableGID_SOBORUD;
	TFIBWideStringField *TableSTRPAR_SOBORUD;
	TFIBWideStringField *TableMODUL_SOBORUD;
	TFIBBCDField *TableIDBASE_SOBORUD;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMViborOborud(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //��������� ������ ����������
	GUID ClsIdImpl;				 //GUID ������ ����������
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		bool Init(void);
		int Done(void);


		void OpenTable(__int64 id_arm, AnsiString type_oborud);

		bool Error;
		String TextError;

		int IdArm;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMViborOborud *DMViborOborud;
//---------------------------------------------------------------------------
#endif
