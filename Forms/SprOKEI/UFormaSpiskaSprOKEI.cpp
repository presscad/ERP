//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprOKEI.h"
#include "IFormaElementaSprOKEI.h"
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
__fastcall TFormaSpiskaSprOKEI::TFormaSpiskaSprOKEI(TComponent* Owner)
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
bool TFormaSpiskaSprOKEI::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOKEI.1",IID_IDMSprOKEI, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;


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
int TFormaSpiskaSprOKEI::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprOKEI::FormClose(TObject *Sender,
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
void TFormaSpiskaSprOKEI::OpenFormElement()
{
IFormaElementaSprOKEI * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprOKEI.1",IID_IFormaElementaSprOKEI, (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(DM->TableIDOKEI->AsInt64);
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprOKEI::OpenFormNewElement()
{
IFormaElementaSprOKEI * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprOKEI.1",IID_IFormaElementaSprOKEI, (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement();
FormaElementa->DM->OpenElement(DM->TableIDOKEI->AsInt64);
FormaElementa->NumberProcVibor=1;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprOKEI::DeleteElement()
{
DM->DeleteElement(DM->TableIDOKEI->AsInt64);
DM->OpenTable();
}

//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprOKEI::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprOKEI::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprOKEI::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOKEI::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprOKEI");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOKEI::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
		DM->OpenElement(DM->TableIDOKEI->AsInt64);
		TypeEvent=1;
		Close();
		}
else
		{
		OpenFormElement();
		}
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprOKEI::cxGrid1DBTableView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
		{
		DM->OpenElement(DM->TableIDOKEI->AsInteger);
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

void __fastcall TFormaSpiskaSprOKEI::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprOKEI::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable();
return -1;
}
//-----------------------------------------------------------------------------
