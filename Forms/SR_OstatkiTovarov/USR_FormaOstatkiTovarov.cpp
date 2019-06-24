//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "USR_FormaOstatkiTovarov.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IREM_FormaReportKartTovara.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxCheckBox"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TSR_FormaOstatkiTovarov::TSR_FormaOstatkiTovarov(TComponent* Owner)
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
void __fastcall TSR_FormaOstatkiTovarov::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TSR_FormaOstatkiTovarov::Init(void)
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

pFIBDataSet->Database=DM_Connection->pFIBData;
pFIBTransaction->DefaultDatabase=DM_Connection->pFIBData;

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameSkladEdit->Text="";
NameGrpNomEdit->Text="";
NameNomEdit->Text="";


//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TSR_FormaOstatkiTovarovImpl),false);
DMTableExtPrintForm->Table->First();
while (!DMTableExtPrintForm->Table->Eof)
		{
		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = PopupMenuExtModuleClick;
		PopupMenuExtModule->Items->Add(menu);
		//static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
		DMTableExtPrintForm->Table->Next();
		}



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
int  TSR_FormaOstatkiTovarov::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TSR_FormaOstatkiTovarov::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad) SpisokSklad->kanRelease();
if(SpisokFirm) SpisokFirm->kanRelease();
if(SpisokGrpNom) SpisokGrpNom->kanRelease();
if(SpisokNom) SpisokNom->kanRelease();


Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//----------------------------------------------------------------------------
void TSR_FormaOstatkiTovarov::OpenFormSpiskaSprNom(void)
{
if (SpisokNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->Vibor=true;
		SpisokNom->NumberProcVibor=ViborNom;
        SpisokNom->IdNom=IdNom;
        SpisokNom->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TSR_FormaOstatkiTovarov::OpenFormSpiskaSprFirm(void)
{
if (SpisokFirm==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
	SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
	SpisokFirm->Vibor=true;
	SpisokFirm->NumberProcVibor=ViborFirm;
	}
}
//---------------------------------------------------------------------------
void TSR_FormaOstatkiTovarov::OpenFormSpiskaSprGrpNom(void)
{
if (SpisokGrpNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&SpisokGrpNom);
		SpisokGrpNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokGrpNom->Vibor=true;
		SpisokGrpNom->NumberProcVibor=ViborGrpNom;
        SpisokGrpNom->UpdateForm();
		}
}
//---------------------------------------------------------------------------
int TSR_FormaOstatkiTovarov::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==ViborSklad)
		{
		if (type_event==1)
				{
				IdSkl=glStrToInt64(SpisokSklad->DM->ElementIDSKLAD->AsString);
                NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                }
        SpisokSklad=0;
        }

if (number_procedure_end==ViborFirm)
        {
		if (type_event==1)
                {
				IdFirm=SpisokFirm->DM->TableIDFIRM->AsInt64;
                NameFirmEdit->Text=SpisokFirm->DM->TableNAMEFIRM->AsString;
                }
        SpisokFirm=0;
        }

if (number_procedure_end==ViborGrpNom)
        {
		if (type_event==1)
				{
				IdGrpNom=SpisokGrpNom->DMGrp->ElementIDGN->AsInt64;
				NameGrpNomEdit->Text=SpisokGrpNom->DMGrp->ElementNAMEGN->AsString;
				IdNom=0;
				NameNomEdit->Text="";
				}
		SpisokGrpNom=0;
        }


if (number_procedure_end==ViborNom)
        {
		if (type_event==1)
				{
				IdNom=glStrToInt64(SpisokNom->DM->TableIDNOM->AsString);
				NameNomEdit->Text=SpisokNom->DM->TableNAMENOM->AsString;
				IdGrpNom=0;
				NameGrpNomEdit->Text="";
				}
		SpisokNom=0;
		}


EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------
void TSR_FormaOstatkiTovarov::OpenFormSpiskaSprSklad(void)
{
if (SpisokSklad==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->Vibor=true;
		SpisokSklad->NumberProcVibor=ViborSklad;
		}

}
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------






void __fastcall TSR_FormaOstatkiTovarov::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------


void __fastcall TSR_FormaOstatkiTovarov::NameNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprNom();
		}break;
	case 1:
		{
		IdNom=0;
		NameNomEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TSR_FormaOstatkiTovarov::NameGrpNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprGrpNom();
		}break;
	case 1:
		{
		IdGrpNom=0;
		NameGrpNomEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TSR_FormaOstatkiTovarov::NameSkladEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprSklad();
		}break;
	case 1:
		{
		IdSkl=0;
		NameSkladEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TSR_FormaOstatkiTovarov::NameFirmEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprFirm();  
		}break;
	case 1:
		{
		IdFirm=0;
		NameFirmEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//������� ������
void __fastcall TSR_FormaOstatkiTovarov::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TSR_FormaOstatkiTovarov::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();


//��������� ������� ������
//TScriptDMDocRealRozn * scr_doc;
if (type_module==1 || type_module==2)
	{
//	//���� �������� ����� TScriptDMDocRealRozn
//	//������ ��� ������ � ����������
//	module->AddClassesInScript_DMDocRealRozn();
//	module->ScriptDMDocRealRozn->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",module->ScriptDMDocRealRozn);
	}


	module->SetInt64Variables("glIdFirm", IdFirm);
	module->SetInt64Variables("glIdSklad", IdSkl);
	module->SetInt64Variables("glIdGrpNom", IdGrpNom);
	module->SetInt64Variables("glIdNom", IdNom);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);

	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall TSR_FormaOstatkiTovarov::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TSR_FormaOstatkiTovarov::cxButtonUpdateClick(TObject *Sender)
{
pFIBDataSet->Active=false;

UnicodeString zapros=" select snom.artnom, \
						snom.codenom,                       \
						sed.shed,                           \
						snom. namenom,                        \
						rggoods.kol_rggoods,                  \
						rem_rggoods.kol_rem_rggoods,        \
						rem_firm.namefirm as rem_firm_name,  \
						osn_firm.namefirm as osn_firm_name, \
						rem_sklad.namesklad as osn_sklad_name,          \
						osn_sklad.namesklad as rem_sklad_name,         \
						snom.idnom          \
																		\
from snom                                                               \
left outer join sed on sed.ided=snom.idbasednom                         \
left outer join rggoods on rggoods.idnom_rggoods=snom.idnom             \
left outer join rem_rggoods on rem_rggoods.idnom_rem_rggoods=snom.idnom                       \
left outer join sfirm as osn_firm on osn_firm.idfirm=rggoods.idfirm_rggoods                   \
left outer join sfirm as rem_firm on rem_firm.idfirm=rem_rggoods.idfirm_rem_rggoods           \
left outer join ssklad as osn_sklad on osn_sklad.idsklad=rggoods.idsklad_rggoods              \
left outer join ssklad as rem_sklad on rem_sklad.idsklad=rem_rggoods.idsklad_rem_rggoods      \
where rggoods.kol_rggoods != rem_rggoods.kol_rem_rggoods   ";

if (IdFirm !=0)
	{
	zapros=zapros+" and (rggoods.idfirm_rggoods=:PARAM_IDFIRM or rem_rggoods.idfirm_rem_rggoods=:PARAM_IDFIRM) ";
	}

if (IdSkl !=0)
	{
	zapros=zapros+" and (rggoods.idsklad_rggoods=:PARAM_IDSKLAD or rem_rggoods.idsklad_rem_rggoods=:PARAM_IDSKLAD)";
	}

pFIBDataSet->SelectSQL->Clear();
pFIBDataSet->SelectSQL->Add(zapros);

if (IdFirm !=0)
	{
	pFIBDataSet->ParamByName("PARAM_IDFIRM")->AsString = IdFirm;
	}

if (IdSkl !=0)
	{
	pFIBDataSet->ParamByName("PARAM_IDSKLAD")->AsString = IdSkl;
	}

pFIBDataSet->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TSR_FormaOstatkiTovarov::cxButtonKartTovaraClick(TObject *Sender)

{
IREM_FormaReportKartTovara * form;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaReportKartTovara,IID_IREM_FormaReportKartTovara,
									 (void**)&form);
form->Init(InterfaceMainObject,InterfaceImpl);

form->IdNom=glStrToInt64(pFIBDataSetIDNOM->AsString);
form->NameNom=pFIBDataSetNAMENOM->AsString;

form->IdFirm=IdFirm;
form->NameFirm=NameFirmEdit->Text;

form->IdSkl=IdSkl;
form->NameSklad=NameSkladEdit->Text;

form->UpdateForm();
}
//---------------------------------------------------------------------------

