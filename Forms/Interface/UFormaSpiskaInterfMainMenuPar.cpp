//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaInterfMainMenuPar.h"
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
__fastcall TFormaSpiskaInterfMainMenuPar::TFormaSpiskaInterfMainMenuPar(TComponent* Owner)
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
bool TFormaSpiskaInterfMainMenuPar::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_DMInterfMainMenuPar,IID_IDMInterfMainMenuPar, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
//DM->OpenTable(IdNom);
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
int TFormaSpiskaInterfMainMenuPar::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenuPar::FormClose(TObject *Sender,
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
void TFormaSpiskaInterfMainMenuPar::UpdateForm(void)
{

LabelHeader->Caption=TextHeader;
DM->OpenTable(IdOwner);

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenuPar::ToolButtonNewClick(TObject *Sender)
{
DM->TableAppend(IdOwner);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfMainMenuPar::ToolButtonDeleteClick(TObject *Sender)
{
DM->TableDelete();
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaInterfMainMenuPar::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
        Close();
        }
else
        {
		}
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaInterfMainMenuPar::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
        Close();
        }
else
        {
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfMainMenuPar::ActionCloseExecute(TObject *Sender)
{
DM->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfMainMenuPar::ActionOKExecute(TObject *Sender)
{
DM->SaveIsmen();
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaInterfMainMenuPar::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

return -1;
}
//-----------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenuPar::DeleteElement()
{


}
//------------------------------------------------------------------------------
