//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprAddressKV.h"
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
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprAddressKV::TFormaElementaSprAddressKV(TComponent* Owner)
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
bool TFormaElementaSprAddressKV::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressKV,IID_IDMSprAddressKV, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);



DBTextID_SADR_REGION->DataSource=DM->DataSourceElement;
DBTextCODE_SADR_REGION->DataSource=DM->DataSourceElement;
DBTextNAME_SADR_REGION->DataSource=DM->DataSourceElement;
DBTextNAME_SADR_RAYON->DataSource=DM->DataSourceElement;
DBTextNAME_SADR_NASPUNKT->DataSource=DM->DataSourceElement;
DBTextPOSTCODE_SADR_STREET->DataSource=DM->DataSourceElement;
DBTextNAME_SADR_STREET->DataSource=DM->DataSourceElement;
DBTextNAME_SADR_DOM->DataSource=DM->DataSourceElement;
DBTextNAME_SADR_STROEN->DataSource=DM->DataSourceElement;


cxDBTextEditNAME_SADR_KV->DataBinding->DataSource=DM->DataSourceElement;


//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//--------------------------------------------------------------------------
int TFormaElementaSprAddressKV::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprAddressKV::UpdateForm(void)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprAddressKV::FormClose(TObject *Sender,
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






void __fastcall TFormaElementaSprAddressKV::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressKV::ActionOKExecute(TObject *Sender)
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
int TFormaElementaSprAddressKV::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

return -1;
}
//-----------------------------------------------------------------------------
