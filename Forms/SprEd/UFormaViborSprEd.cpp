//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaViborSprEd.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDM.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxStyles"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxStyles"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaViborSprEd::TFormaViborSprEd(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TFormaViborSprEd::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
												 (void**)&DM);
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
int TFormaViborSprEd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaViborSprEd::UpdateForm(void)
{
DM->OpenTable(IdNom);
cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprEd::FormClose(TObject *Sender,
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
int TFormaViborSprEd::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable(IdNom);
return -1;
}

//------------------------------------------------------------------------





void __fastcall TFormaViborSprEd::cxButtonCloseClick(TObject *Sender)
{
TypeEvent=0;
Close(); 	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprEd::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{
		TypeEvent=1;
		DM->OpenElement(glStrToInt64(DM->TableIDED->AsString));
		Close();
		}
else
		{

		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprEd::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{
				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableIDED->AsString));
				Close();
				}
		else
				{

				}
		}

if (Key==VK_ESCAPE)
		{
		TypeEvent=0;
		Close();
		}	
}
//---------------------------------------------------------------------------

