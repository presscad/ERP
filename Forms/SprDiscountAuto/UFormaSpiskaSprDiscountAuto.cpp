//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprDiscountAuto.h"
#include "IFormaElementaSprDiscountAuto.h"
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
#pragma link "cxCheckBox"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprDiscountAuto::TFormaSpiskaSprDiscountAuto(TComponent* Owner)
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

bool TFormaSpiskaSprDiscountAuto::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountAuto.1",IID_IDMSprDiscountAuto, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;
TypeEvent=0;

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
int TFormaSpiskaSprDiscountAuto::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprDiscountAuto::FormClose(TObject *Sender,
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
void TFormaSpiskaSprDiscountAuto::UpdateForm(void)
{
DM->OpenTable();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprDiscountAuto::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable();
return -1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountAuto::OpenFormElement()
{
IFormaElementaSprDiscountAuto * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprDiscountAuto.1",
														IID_IFormaElementaSprDiscountAuto,
													(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_SDISCOUNT_AUTO->AsString));
FormaElementa->UpdateForm();

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountAuto::OpenFormNewElement()
{
IFormaElementaSprDiscountAuto * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprDiscountAuto.1",
														IID_IFormaElementaSprDiscountAuto,
													(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement();
FormaElementa->UpdateForm();
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountAuto::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_SDISCOUNT_AUTO->AsString));
DM->OpenTable();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountAuto::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountAuto::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountAuto::ToolButtonDeleteClick(
      TObject *Sender)
{
DeleteElement();        
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprDiscountAuto::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprDiscountAuto");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountAuto::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
        DM->OpenElement(glStrToInt64(DM->TableID_SDISCOUNT_AUTO->AsString));
        Close();
        }
else
        {
        OpenFormElement();
        }	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprDiscountAuto::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

