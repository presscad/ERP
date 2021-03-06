//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaSpiskaTableSostNF.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_FormaSpiskaTableSostNF::THOT_FormaSpiskaTableSostNF(TComponent* Owner)
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

bool THOT_FormaSpiskaTableSostNF::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMTableSostNF.1",IID_IHOT_DMTableSostNF,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

Vibor=false;
TypeEvent=1;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaSpiskaTableSostNF::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaTableSostNF::FormClose(TObject *Sender,
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
void THOT_FormaSpiskaTableSostNF::UpdateForm(void)
{
DM->OpenTable();
}
//----------------------------------------------------------------------------
int THOT_FormaSpiskaTableSostNF::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
HOT_FormaElementaTableSostNF=0;
DM->OpenTable();
return -1;
}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaTableSostNF::OpenFormElement()
{
if (HOT_FormaElementaTableSostNF==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaElTableSostNF.1",IID_IHOT_FormaElementaTableSostNF,
												 (void**)&HOT_FormaElementaTableSostNF);
	HOT_FormaElementaTableSostNF->Init(InterfaceMainObject,InterfaceImpl);
	HOT_FormaElementaTableSostNF->DM->OpenElement(DM->TableID_HOT_SOSTNF->AsInt64);
	HOT_FormaElementaTableSostNF->UpdateForm();
	}

}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaTableSostNF::OpenFormNewElement()
{
if (HOT_FormaElementaTableSostNF==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaElTableSostNF.1",IID_IHOT_FormaElementaTableSostNF,
												 (void**)&HOT_FormaElementaTableSostNF);
	HOT_FormaElementaTableSostNF->Init(InterfaceMainObject,InterfaceImpl);
	HOT_FormaElementaTableSostNF->DM->NewElement();
	HOT_FormaElementaTableSostNF->UpdateForm();
	}

}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaTableSostNF::DeleteElement()
{
DM->DeleteElement(DM->TableID_HOT_SOSTNF->AsInt64);
DM->OpenTable();
}
//----------------------------------------------------------------------------


void __fastcall THOT_FormaSpiskaTableSostNF::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Spr/TableSostNF");
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaTableSostNF::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
        {
        DM->OpenElement(DM->TableID_HOT_SOSTNF->AsInt64);
		TypeEvent=1;
        Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaSpiskaTableSostNF::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaTableSostNF::ToolButtonEditClick(
      TObject *Sender)
{
void OpenFormElement();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaTableSostNF::ToolButtonDeleteClick(
      TObject *Sender)
{
DeleteElement();	
}
//---------------------------------------------------------------------------



void __fastcall THOT_FormaSpiskaTableSostNF::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
if (Vibor==true)
        {
        DM->OpenElement(DM->TableID_HOT_SOSTNF->AsInteger);
		TypeEvent=1;
        Close();
        }
else
        {
        OpenFormElement();
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaTableSostNF::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

