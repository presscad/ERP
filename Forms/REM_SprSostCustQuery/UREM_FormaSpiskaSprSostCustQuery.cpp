//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaSpiskaSprSostCustQuery.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IREM_FormaElementaSprSostCustQuery.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaSpiskaSprSostCustQuery::TREM_FormaSpiskaSprSostCustQuery(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------

bool TREM_FormaSpiskaSprSostCustQuery::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprSostCustQuery,IID_IREM_DMSprSostCustQuery,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;



DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprSostCustQuery::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprSostCustQuery::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//������� ICallBack ��� �������� ������� � ���������� �����
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		}
	i_callback->kanRelease();
	}

DM->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprSostCustQuery::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable();

return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprSostCustQuery::OpenFormElement()
{
IREM_FormaElementaSprSostCustQuery * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprSostCustQuery,IID_IREM_FormaElementaSprSostCustQuery,
												 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);

if (!FormaElementa) return;
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_REM_SSOST_CQUERY->AsString));
FormaElementa->UpdateForm();

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprSostCustQuery::OpenFormNewElement()
{
IREM_FormaElementaSprSostCustQuery * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprSostCustQuery,IID_IREM_FormaElementaSprSostCustQuery,
												 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
if (!FormaElementa) return;
FormaElementa->DM->NewElement();
FormaElementa->UpdateForm();
}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprSostCustQuery::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_REM_SSOST_CQUERY->AsString));
DM->OpenTable();
}
//--------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprSostCustQuery::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprSostCustQuery::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();        
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprSostCustQuery::ToolButtonDeleteClick(
      TObject *Sender)
{
DeleteElement();        
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaSpiskaSprSostCustQuery::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprSklad");	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprSostCustQuery::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		DM->OpenElement(glStrToInt64(DM->TableID_REM_SSOST_CQUERY->AsString));
		TypeEvent=1;
        Close();
        }
else
        {
        OpenFormElement();
        }	
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaSpiskaSprSostCustQuery::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

