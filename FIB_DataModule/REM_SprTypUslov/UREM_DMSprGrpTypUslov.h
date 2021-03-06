//---------------------------------------------------------------------------

#ifndef UREM_DMSprGrpTypUslovH
#define UREM_DMSprGrpTypUslovH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


//----------------------------------------------------------------------------


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
class TREM_DMSprGrpTypUslov : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *ElementID_REM_STYPUSLOV_GRP;
	TFIBWideStringField *ElementGID_REM_STYPUSLOV_GRP;
	TFIBLargeIntField *ElementIDBASE_REM_STYPUSLOV_GRP;
	TFIBLargeIntField *ElementIDGRP_REM_STYPUSLOV_GRP;
	TFIBWideStringField *ElementNAME_REM_STYPUSLOV_GRP;
	TFIBLargeIntField *TableID_REM_STYPUSLOV_GRP;
	TFIBWideStringField *TableGID_REM_STYPUSLOV_GRP;
	TFIBLargeIntField *TableIDBASE_REM_STYPUSLOV_GRP;
	TFIBLargeIntField *TableIDGRP_REM_STYPUSLOV_GRP;
	TFIBWideStringField *TableNAME_REM_STYPUSLOV_GRP;
	TFIBWideStringField *TableNAME_ENG_REM_STYPUSLOV_GRP;
	TFIBWideStringField *ElementNAME_ENG_REM_STYPUSLOV_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TREM_DMSprGrpTypUslov(TComponent* Owner);

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
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		void DeleteElement(__int64 id);

        int GetIDElement(UnicodeString gid);
        __int64 FindPoName(UnicodeString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprGrpTypUslov *REM_DMSprGrpTypUslov;
//---------------------------------------------------------------------------
#endif
