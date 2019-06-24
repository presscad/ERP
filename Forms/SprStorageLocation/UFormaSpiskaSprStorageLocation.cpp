//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprStorageLocation.h"
#include "IFormaElementaSprStorageLocation.h"
#include "IFormaElementaSprStorageLocationGrp.h"
#include "IDMUserSetup.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IObjectBarCode.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxTreeView"
#pragma link "cxClasses"
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
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"



//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprStorageLocation::TFormaSpiskaSprStorageLocation(TComponent* Owner)
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
bool TFormaSpiskaSprStorageLocation::Init(void)
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

	//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������
	if(InterfaceMainObject)
		{
		IAsyncExternalEvent * interf=0;
		InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
		if (interf)
			{
			interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
			interf->kanRelease();
			}
		}
	}
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprStorageLocation,IID_IDMSprStorageLocation, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprStorageLocationGrp,IID_IDMSprStorageLocationGrp, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdGrp=0;
AllElement=false;
Vibor=false;


InterfaceGlobalCom->kanCreateObject(ProgId_DMSprSklad,IID_IDMSprSklad, (void**)&DMGroupElement);
DMGroupElement->Init(InterfaceMainObject,InterfaceImpl);



LabelNameGrp->Caption="����� ��������\\...";
HintLabel->Caption="";

//�������� ������
DMGroupElement->OpenTable();
NameGroupElementcxComboBox->Properties->Items->Clear();
NameGroupElementcxComboBox->Properties->Items->Add("�� �����");
DMGroupElement->Table->First();
while (!DMGroupElement->Table->Eof)
		{
		NameGroupElementcxComboBox->Properties->Items->Add(DMGroupElement->TableNAMESKLAD->AsString);
		DMGroupElement->Table->Next();
		}
NameGroupElementcxComboBox->ItemIndex=0;


//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm, (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaSprStorageLocationImpl),false);

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
NoUpdateForm=false;
LoadFormSetup();

InputStrcxTextEdit->Text="";

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
int TFormaSpiskaSprStorageLocation::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::UpdateForm(void)
{
if(Vibor==true)
	{
	cxButtonVibor->Visible=true;
	}
else
	{
	cxButtonVibor->Visible=false;
	}


DM->DataSourceTable->Enabled=false;

DM->OpenTable(IdGroupElement,IdGrp,AllElement);
DMGrp->OpenTable(IdGroupElement);

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_SMHRAN",IdElement,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::UpdateDerevo()
{

//������� ������ �� ����������� ������
if (cxTreeView1->Items->Count>0)
        {
		for (__int64 i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable(IdGroupElement);
cxTreeView1->Items->Clear();
__int64 * lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"����� ��������",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DMGrp->TableIDGRP_SMHRAN_GRP->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_SMHRAN_GRP->AsString);
                         // ShowMessage(" ������� ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_SMHRAN_GRP->AsString, lpIDGrp);
                         break;
                       }

                }
        DMGrp->Table->Next();
        }
cxTreeView1->AlphaSort(true);


for (int i=0;i<cxTreeView1->Items->Count;i++)
        {
		__int64 IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                if (IdGrp==IDData)
                        {
						cxTreeView1->Selected=cxTreeView1->Items->Item[i];
                        if(AllElement!=true)
                                {
								LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
                                }
                        break;
                        }
		}

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStorageLocation::FormClose(TObject *Sender,
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
DMGrp->kanRelease();
DMTableExtPrintForm->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//-------------------------------------------------------------------------------
int TFormaSpiskaSprStorageLocation::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==ER_GrpForm)//ViborGrp)
		{
        UpdateDerevo();
		}

if(number_procedure_end==ER_ElementForm)//ViborElement)
		{
		cxGrid1->SetFocus();
		}



if (DM_Connection->UserInfoREOPEN_SPR_SUSER->AsInteger==1)
	{
	UpdateForm();
	}
return -1;
}

//--------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::OpenFormElement()
{

		IFormaElementaSprStorageLocation * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprStorageLocation,IID_IFormaElementaSprStorageLocation,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_SMHRAN->AsString));
		FormaElementa->NumberProcVibor=ER_ElementForm;
		//FormaElementa->IdGrp=IdGrp;
		//FormaElementa->NameGrpNom=LabelNameGrp->Caption;
		//FormaElementa->UpdateForm();
		IdElement=glStrToInt64(DM->TableID_SMHRAN->AsString);
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::OpenFormNewElement()
{

		IFormaElementaSprStorageLocation * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprStorageLocation,IID_IFormaElementaSprStorageLocation,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (FormaElementa->DM->NewElement(IdGroupElement,IdGrp)==true)
				{
				//FormaElementa->IdProducerTypePrice=IdTypePrice;
				//FormaElementa->IdGrpNom=IdGrp;
				//FormaElementa->NameGrpNom=LabelNameGrp->Caption;
				//FormaElementa->UpdateForm();
				FormaElementa->NumberProcVibor=ER_ElementForm;
				IdElement=glStrToInt64(FormaElementa->DM->ElementID_SMHRAN->AsString);
				}
		else
				{
				FormaElementa->kanRelease();
				ShowMessage(FormaElementa->DM->TextError);
				}
}
//-------------------------------------------------------------------------

void TFormaSpiskaSprStorageLocation::DeleteElement()
{
		UnicodeString V="�� ������������� ������ ������� "	+DM->TableNAME_SMHRAN->AsString+"?";
		UnicodeString Z="������������� �������� ��������";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

if(DM->DeleteElement(glStrToInt64(DM->TableID_SMHRAN->AsString))!=true)
	{
	ShowMessage("�� ������� ������� ������� �����������!  ������: "+DM->TextError );
	}


DM->OpenTable(IdGroupElement,IdGrp,AllElement);
}

//---------------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::OpenFormGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				IFormaElementaSprStorageLocationGrp * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprStorageLocationGrp,IID_IFormaElementaSprStorageLocationGrp,
										 (void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->NumberProcVibor=ER_GrpForm;
				}
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::OpenFormNewGrpElement()
{

		IFormaElementaSprStorageLocationGrp * FormaGrpElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprStorageLocationGrp,IID_IFormaElementaSprStorageLocationGrp,
										 (void**)&FormaGrpElementa);
		FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);

		if (cxTreeView1->Selected!=NULL)
				{
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaGrpElementa->DM->NewElement(IdGroupElement,IdGrp);
				}
		else
				{
				FormaGrpElementa->DM->NewElement(IdGroupElement,0);
				}
		FormaGrpElementa->NumberProcVibor=ER_GrpForm;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::DeleteGrpElement()
{

        if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdElement=glStrToInt64(DM->TableID_SMHRAN->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_SMHRAN->AsString);
        }
else
        {
        AllElement=true ;
		LabelNameGrp->Caption="��� ��������...";
		IdElement=glStrToInt64(DM->TableID_SMHRAN->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_SMHRAN->AsString);
        }
UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{  //������������� �������
		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				__int64 id=AViewData->Records[i]->Values[cxGrid1DBTableView1ID_SMHRAN->Index];
				DM->ChangeGrp(*(__int64*)cxTreeView1->Selected->Data,id);
				}
			}
		}
DM->OpenTable(IdGroupElement,IdGrp,AllElement);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprStorageLocation::FormActivate(TObject *Sender)
{

//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprStorageLocation::FormDeactivate(TObject *Sender)
{
//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������

if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(0);
		interf->kanRelease();
		}
	}
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::ReadShtrihCodEvent(int number, UnicodeString sh)
{

AnsiString s=sh;

//IObjectBarCode * ob_bar;
//InterfaceGlobalCom->kanCreateObject("Oberon.ObjectBarCode.1",IID_IObjectBarCode,
//													(void**)&ob_bar);
//ob_bar->Init(InterfaceMainObject,InterfaceImpl);
//
//IDMSprNom * dm_nom;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
//													(void**)&dm_nom);
//dm_nom->Init(InterfaceMainObject,InterfaceImpl);
//
//IDMSprEd * dm_ed;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
//													(void**)&dm_ed);
//dm_ed->Init(InterfaceMainObject,InterfaceImpl);
//
//ob_bar->SprNom=dm_nom;
//ob_bar->SprEd=dm_ed;
//ob_bar->IdTypePrice=0;
//ob_bar->ObrabotatShtrihCod(sh);
//
//if (ob_bar->OutReady==true)
//	{
//	IdNom=glStrToInt64(dm_nom->ElementIDNOM->AsString);
//	UpdateForm();
//	cxGrid1->SetFocus();
//	}
//else
//	{
//	 ShowMessage(ob_bar->TextError);
//	}
//ob_bar->kanRelease();
//dm_nom->kanRelease();
//dm_ed->kanRelease();


}
//---------------------------------------------------------------

//-----------------------------------------------------------------------------








void __fastcall TFormaSpiskaSprStorageLocation::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGroupElement,IdGrp,AllElement);
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprStorageLocation::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{

				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableID_SMHRAN->AsString));
				Close();

		}
else
		{
		IdElement=glStrToInt64(DM->TableID_SMHRAN->AsString);
		OpenFormElement();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprStorageLocation::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{

						TypeEvent=1;
						DM->OpenElement(glStrToInt64(DM->TableID_SMHRAN->AsString));
						Close();
				}
		else
				{
				OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprStorageLocation::cxTreeView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGroupElement,IdGrp,AllElement);
		}
		}
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprStorageLocation::ToolButton6Click(TObject *Sender)
{
IdElement=glStrToInt64(DM->TableID_SMHRAN->AsString);
UpdateForm();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//������� ������
void __fastcall TFormaSpiskaSprStorageLocation::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::RunExternalModule(__int64 id_module, int type_module)
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

if (type_module==3)
	{  //���� �������� ���������� ������, ��� �������  IDDOC
	module->SetInt64Variables("glIdElement", glStrToInt64(DM->TableID_SMHRAN->AsString));
	module->SetInt64Variables("glIdGroupElement", IdGroupElement);
	module->SetInt64Variables("glIdGrp", IdGrp);
    module->SetStringVariables("glStrPoisk", Trim(InputStrcxTextEdit->Text));
	}
	
module->ExecuteModule();


if (type_module==1 || type_module==2)
	{
//	delete scr_doc;
//	delete module;
	}


}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::OpenFormNewCopyElement()
{

//		IFormaElementaSprProducerNom * FormaElementa;
//		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprProducerNom,IID_IFormaElementaSprProducerNom,
//													(void**)&FormaElementa);
//
//		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
//		if (FormaElementa->DM->NewElement(IdGroupElement,IdGrp)==true)
//				{
//				FormaElementa->NumberProcVibor=2;
//
//				IDMSprProducerNom * n;
//				InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducerNom,IID_IDMSprProducerNom,
//													(void**)&n);
//				n->Init(InterfaceMainObject,InterfaceImpl);
//				n->OpenElement(glStrToInt64(DM->TableID_SPRNOM->AsString));
//				FormaElementa->DM->Element->Edit();
//				FormaElementa->DM->ElementTYPE_SPRNOM->AsString=
//												n->ElementTYPE_SPRNOM->AsString;
//				FormaElementa->DM->ElementART_SPRNOM->AsString=
//												n->ElementART_SPRNOM->AsString;
//				FormaElementa->DM->ElementNAME_SPRNOM->AsString=
//												n->ElementNAME_SPRNOM->AsString;
//				FormaElementa->DM->ElementFNAME_SPRNOM->AsString=
//												n->ElementFNAME_SPRNOM->AsString;
//				FormaElementa->DM->ElementKRNAME_SPRNOM->AsString=
//												n->ElementKRNAME_SPRNOM->AsString;
//
//				n->kanRelease();
//
//				FormaElementa->DM->Element->Post();
//				FormaElementa->IdProducerTypePrice=IdTypePrice;
//				FormaElementa->UpdateForm();
//				}
//		else
//				{
//				FormaElementa->kanRelease();
//				ShowMessage(FormaElementa->DM->TextError);
//				}

}
//--------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonCopyRecordClick(TObject *Sender)
{
//OpenFormNewCopyElement();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::SaveFormSetup(void)
{
IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);

dm->Init(InterfaceMainObject,InterfaceImpl);

dm->SaveSetupBool("FormaSpiskaSprStorageLocation","AllElement",AllElement);

dm->kanRelease();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprStorageLocation::LoadFormSetup(void)
{
NoUpdateForm=true;

//IDMUserSetup * dm;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
//													(void**)&dm);
//dm->Init(InterfaceMainObject,InterfaceImpl);
//
//SpisokTypePrice->ItemIndex=dm->LoadSetupInt("FormaSpiskaSprProducerNom","IndexTypePrice");
//
//
//DM->SpTPrice->First();
//DM->SpTPrice->MoveBy(SpisokTypePrice->ItemIndex);
//DM->IdProducerTypePrice=glStrToInt64(DM->SpTPriceID_SPRTYPE_PRICE->AsString);
//IdTypePrice=glStrToInt64(DM->SpTPriceID_SPRTYPE_PRICE->AsString);
//
//AllElement=dm->LoadSetupBool("FormaSpiskaSprProducerNom","AllElement");
//ToolButtonAll->Down=AllElement;
//dm->kanRelease();

NoUpdateForm=false;
}
//----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStorageLocation::ToolButton7Click(TObject *Sender)
{
SaveFormSetup();	
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprStorageLocation::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprStorageLocation::cxButtonViborClick(TObject *Sender)
{
//if(InterfaceOwnerObject)
//	{
//	IkanCallBack * i_callback=0;
//	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
//	if (i_callback)
//		{
//		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
//		for(int i=0;i<AViewData->RowCount;i++)
//			{
//			if (AViewData->Records[i]->Selected==true)
//				{
//				__int64 id=AViewData->Records[i]->Values[cxGrid1DBTableView1ID_SMHRAN->Index];
//				IdElement=id;
//				TypeEvent=2;
//				i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
//				}
//			}
//
//		}
//	i_callback->kanRelease();
//	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprStorageLocation::NameGroupElementcxComboBoxPropertiesChange(TObject *Sender)

{
IdGroupElement=0;
if (NameGroupElementcxComboBox->ItemIndex!=0)
		{
		DMGroupElement->Table->First();
		DMGroupElement->Table->MoveBy(NameGroupElementcxComboBox->ItemIndex-1);
		IdGroupElement=glStrToInt64(DMGroupElement->TableIDSKLAD->AsString);
		}

	   //	LabelObnovleno->Caption="����. ����������: "+DMGroupElement->TablePOSZAGRNOM_SPRODUCER->AsString;

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprStorageLocation::cxButtonPoiskClick(TObject *Sender)
{

DM->OpenTable(IdGroupElement,IdGrp,AllElement);

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonPoiskPoModelClick(TObject *Sender)

{
DM->OpenTable(IdGroupElement,IdGrp,AllElement);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprStorageLocation::ToolButtonSetDostupno0Click(TObject *Sender)

{

//		UnicodeString V="������� ���� �������� � ��������� ������������? ";
//		UnicodeString Z="�������������";
//		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
//				{
//				return;
//				}
//
//if (IdGroupElement!=0)
//	{
//	IDMSprProducerNom* el;
//	InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducerNom,IID_IDMSprProducerNom, (void**)&el);
//	el->Init(InterfaceMainObject,InterfaceImpl);
//
//	DM->Table->First();
//	while(!DM->Table->Eof)
//		{
//		 el->OpenElement(glStrToInt64(DM->TableID_SPRNOM->AsString));
//		 el->Element->Edit();
//		 el->ElementFL_DOSTUPNO_SPRNOM->AsInteger=0 ;
//		 el->Element->Post();
//		 el->SaveElement();
//		 DM->Table->Next();
//		}
//	el->kanRelease();
//	}


}
//---------------------------------------------------------------------------

