//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaElementaSprProducerNeispr.h"
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
#pragma link "cxButtonEdit"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprProducerNeispr::TREM_FormaElementaSprProducerNeispr(TComponent* Owner)
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
bool TREM_FormaElementaSprProducerNeispr::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprProducerNeispr,IID_IREM_DMSprProducerNeispr, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);



IdcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNeisprcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameEngcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
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
int TREM_FormaElementaSprProducerNeispr::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprProducerNeispr::UpdateForm(void)
{



}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprProducerNeispr::FormClose(TObject *Sender,
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
void __fastcall TREM_FormaElementaSprProducerNeispr::ActionOpenHelpExecute(
      TObject *Sender)
{
//
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaElementaSprProducerNeispr::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerNeispr::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerNeispr::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		TypeEvent=1;
		Close();
		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprProducerNeispr::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

return -1;
}
//---------------------------------------------------------------------------
