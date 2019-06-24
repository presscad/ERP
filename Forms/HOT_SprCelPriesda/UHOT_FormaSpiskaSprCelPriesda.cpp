//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaSpiskaSprCelPriesda.h"
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
__fastcall THOT_FormaSpiskaSprCelPriesda::THOT_FormaSpiskaSprCelPriesda(TComponent* Owner)
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


bool THOT_FormaSpiskaSprCelPriesda::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMSprCelPriesda.1",IID_IHOT_DMSprCelPriesda,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;
TypeEvent=0;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaSpiskaSprCelPriesda::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaSpiskaSprCelPriesda::FormClose(TObject *Sender,
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
//-----------------------------------------------------------------------------
int THOT_FormaSpiskaSprCelPriesda::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

return -1;
}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaSprCelPriesda::UpdateForm(void)
{
DM->OpenTable();
if (Vibor==true)
	{
	cxGrid1DBTableView1->OptionsData->Editing=false;
	ToolButtonEdit->Down=false;
	}
else
	{
	cxGrid1DBTableView1->OptionsData->Editing=true;
	ToolButtonEdit->Down=true;
	}
}

////---------------------------------------------------------------------------
//void __fastcall THOT_FormaSpiskaSprCelPriesda::CloseElementSpr(TObject *Sender)
//{
//DM->OpenTable();
//}
////--------------------------------------------------------------------------
//void THOT_FormaSpiskaSprCelPriesda::OpenFormElement()
//{
//THOT_FormaElementaSprCatNom * f=new THOT_FormaElementaSprCatNom(Application);
//if (!f) return;
//f->DM->OpenElement(DM->TableID_HOT_SCATNOM->AsInteger);
//f->UpdateForm();
//f->Show();
//f->FOnCloseForm=CloseElementSpr;
//}
////--------------------------------------------------------------------------
//void THOT_FormaSpiskaSprCelPriesda::OpenFormNewElement()
//{
//THOT_FormaElementaSprCatNom * f=new THOT_FormaElementaSprCatNom(Application);
//if (!f) return;
//f->DM->NewElement();
//f->UpdateForm();
//f->Show();
//f->FOnCloseForm=CloseElementSpr;
//}
////--------------------------------------------------------------------------
//void THOT_FormaSpiskaSprCelPriesda::DeleteElement()
//{
//DM->DeleteElement(DM->TableID_HOT_SCATNOM->AsInteger);
//DM->OpenTable();
//}
////---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprCelPriesda::ToolButtonNewClick(TObject *Sender)
{
DM->Table->Append();
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaSpiskaSprCelPriesda::ToolButtonDeleteClick(
      TObject *Sender)
{
DM->Table->Delete();
}
//---------------------------------------------------------------------------



void __fastcall THOT_FormaSpiskaSprCelPriesda::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Spr/SprCelPriesda");
}
//---------------------------------------------------------------------------





void __fastcall THOT_FormaSpiskaSprCelPriesda::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
	{
	TypeEvent=1;
	Close();
	}

}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprCelPriesda::ToolButtonEditClick(
      TObject *Sender)
{

if (ToolButtonEdit->Down==true)  //������
		{
		cxGrid1DBTableView1->OptionsData->Editing=true;
		}
else
		{
		cxGrid1DBTableView1->OptionsData->Editing=false;
		}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprCelPriesda::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
if (Vibor==true)
	{
	TypeEvent=1;
	Close();
	}
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprCelPriesda::ActionCloseExecute(TObject *Sender)

{
DM->CancelIsmen();
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprCelPriesda::ActionOKExecute(TObject *Sender)
{
if (DM->SaveIsmen()==true)
		{
		Close();
		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprCelPriesda::ActionSaveExecute(TObject *Sender)

{
if (DM->SaveIsmen()==true)
		{
		DM->OpenTable();
		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

