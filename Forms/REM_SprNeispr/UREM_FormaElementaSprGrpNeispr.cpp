//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaElementaSprGrpNeispr.h" 
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprGrpNeispr::TREM_FormaElementaSprGrpNeispr(TComponent* Owner)
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
bool TREM_FormaElementaSprGrpNeispr::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprGrpNeispr,IID_IREM_DMSprGrpNeispr,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
IdGnDBText->DataSource=DM->DataSourceElement;
NameEngcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprGrpNeispr::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprGrpNeispr::FormClose(TObject *Sender,
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
int TREM_FormaElementaSprGrpNeispr::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprGrpNeispr::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprNom");	
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaElementaSprGrpNeispr::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprGrpNeispr::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		Close();
		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

