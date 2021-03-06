//---------------------------------------------------------------------------

#ifndef UDMSprProgramModuleH
#define UDMSprProgramModuleH
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
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMSprProgramModule : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_PROGRAM_MODULE;
	TFIBWideStringField *TableNAME_PROGRAM_MODULE;
	TFIBWideStringField *TablePROGID_PROGRAM_MODULE;
	TFIBWideStringField *TableMODULE_PROGRAM_MODULE;
	TFIBWideStringField *TableDESCR_PROGRAM_MODULE;
	TFIBWideStringField *TablePATCH_PROGRAM_MODULE;
	TFIBLargeIntField *TableIDBASE_PROGRAM_MODULE;
	TFIBLargeIntField *ElementID_PROGRAM_MODULE;
	TFIBWideStringField *ElementNAME_PROGRAM_MODULE;
	TFIBWideStringField *ElementPROGID_PROGRAM_MODULE;
	TFIBWideStringField *ElementMODULE_PROGRAM_MODULE;
	TFIBWideStringField *ElementDESCR_PROGRAM_MODULE;
	TFIBWideStringField *ElementPATCH_PROGRAM_MODULE;
	TFIBLargeIntField *ElementIDBASE_PROGRAM_MODULE;
	TIntegerField *TableRECNO;
	TpFIBQuery *Query;
	TFIBWideStringField *TableGUID_PROGRAM_MODULE;
	TFIBWideStringField *ElementGUID_PROGRAM_MODULE;
	TFIBIntegerField *TableTYPEMOD_PROGRAM_MODULE;
	TFIBIntegerField *ElementTYPEMOD_PROGRAM_MODULE;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall Table1CalcFields(TDataSet *DataSet);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprProgramModule(TComponent* Owner);


	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //��������� ������ ����������
	GUID ClsIdImpl;				 //GUID ������ ����������
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;

		bool Init(void);
		int Done(void);
		bool Error;
		UnicodeString TextError;
        int CodeError;


        void OpenTable(void);
		int OpenElement(__int64 id);
        void NewElement(void);
        bool SaveElement(void);
		void DeleteElement(__int64 id);

        __int64 GetIDElement(UnicodeString gid);


	   //�������� GUID �� ProgId
	   GUID GetCLSIDFromProgID(UnicodeString prog_id);
	   //�������� ProgId �� GUID
	   UnicodeString GetProgIDFromCLSID (GUID guid);
	   //�������� ������ �� GUID
	   UnicodeString GetNameModuleFromCLSID(GUID guid);
	   //�������� ���� �� GUID
	   UnicodeString GetFullPatchFromCLSID(GUID guid);

	   __int64 GetIdModuleFromGUID(GUID guid);
	   __int64 GetIdModuleFromProgId(UnicodeString prog_id);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprProgramModule *DMSprProgramModule;
//---------------------------------------------------------------------------
#endif
