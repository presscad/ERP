//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprNumTel.h"
#include "IFormaElementaSprNumTel.h"
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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprNumTel::TFormaSpiskaSprNumTel(TComponent* Owner)
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
bool TFormaSpiskaSprNumTel::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNumTel.1",IID_IDMSprNumTel, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
HintLabel->Caption="";


//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprNumTel::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprNumTel::UpdateForm(void)
{
DM->OpenTable(IdKlient); 
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNumTel::FormClose(TObject *Sender,
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

//--------------------------------------------------------------------------
void TFormaSpiskaSprNumTel::OpenFormElement()
{
IFormaElementaSprNumTel * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNumTel.1",IID_IFormaElementaSprNumTel, (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_NUMTEL->AsString));
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprNumTel::OpenFormNewElement()
{
IFormaElementaSprNumTel * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNumTel.1",IID_IFormaElementaSprNumTel, (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement(IdKlient);
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprNumTel::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_NUMTEL->AsString));
DM->OpenTable(IdKlient);
}
//--------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNumTel::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNumTel::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNumTel::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprNumTel::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprNumTel");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNumTel::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		DM->OpenElement(glStrToInt64(DM->TableID_NUMTEL->AsString));
        Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprNumTel::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
		{
		DM->OpenElement(glStrToInt64(DM->TableID_NUMTEL->AsString));
		Close();
		}
else
		{
		OpenFormElement();
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNumTel::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprNumTel::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable(IdKlient);
return -1;
}
//-----------------------------------------------------------------------------
