//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaSpiskaSprDefectModelNeispr.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IREM_FormaElementaSprDefectModelNeispr.h"
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
__fastcall TREM_FormaSpiskaSprDefectModelNeispr::TREM_FormaSpiskaSprDefectModelNeispr(TComponent* Owner)
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
bool TREM_FormaSpiskaSprDefectModelNeispr::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprDefectModelNeispr,IID_IREM_DMSprDefectModelNeispr,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
HintLabel->Caption="";

DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprDefectModelNeispr::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprDefectModelNeispr::UpdateForm(void)
{
DM->OpenTable(IdModelNeispr);

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprDefectModelNeispr::FormClose(TObject *Sender,
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
int TREM_FormaSpiskaSprDefectModelNeispr::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable(IdModelNeispr);
return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprDefectModelNeispr::OpenFormElement()
{
IREM_FormaElementaSprDefectModelNeispr * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprDefectModelNeispr,IID_IREM_FormaElementaSprDefectModelNeispr,
												 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
if (!FormaElementa) return;
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_REM_SDEFECT_MODNE->AsString));
FormaElementa->UpdateForm();

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprDefectModelNeispr::OpenFormNewElement()
{
IREM_FormaElementaSprDefectModelNeispr * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprDefectModelNeispr,IID_IREM_FormaElementaSprDefectModelNeispr,
												 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
if (!FormaElementa) return;
FormaElementa->DM->NewElement(IdModelNeispr);
FormaElementa->UpdateForm();


}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprDefectModelNeispr::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_REM_SDEFECT_MODNE->AsString));
DM->OpenTable(IdModelNeispr);
}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprDefectModelNeispr::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprDefectModelNeispr::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprDefectModelNeispr::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaSpiskaSprDefectModelNeispr::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprEd");
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprDefectModelNeispr::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		DM->OpenElement(glStrToInt64(DM->TableID_REM_SDEFECT_MODNE->AsString));
		TypeEvent=1;
        Close();
        }
else
        {
        OpenFormElement();
        }	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprDefectModelNeispr::ActionCloseExecute(TObject *Sender)

{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

