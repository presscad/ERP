//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprLossFactor.h"
#include "IFormaElementaSprLossFactor.h"
#include "IFormaElementaSprGrpLossFactor.h"

#include "IDMUserSetup.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

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
#pragma resource "*.dfm"



//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprLossFactor::TFormaSpiskaSprLossFactor(TComponent* Owner)
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
bool TFormaSpiskaSprLossFactor::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprLossFactor,IID_IDMSprLossFactor, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprGrpLossFactor,IID_IDMSprGrpLossFactor, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdGrp=0;
AllElement=false;
Vibor=false;


LabelNameGrp->Caption="�������� (����������)\\...";
HintLabel->Caption="";


//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm, (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaSprProduceImpl),false);
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


//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

UpdateForm();

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprLossFactor::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprLossFactor::UpdateForm(void)
{


if (IdElement>0)
        {
		IdGrp=DM->GetIdGrp(IdElement);
		}


DM->DataSourceTable->Enabled=false;

DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_SLOSS_FACTOR",IdElement,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void TFormaSpiskaSprLossFactor::UpdateDerevo()
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
DMGrp->OpenTable();
cxTreeView1->Items->Clear();
__int64 * lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"�������� (����������)",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DMGrp->TableIDGRP_SLOSS_FACTOR_GRP->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_SLOSS_FACTOR_GRP->AsString);
                         // ShowMessage(" ������� ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_SLOSS_FACTOR_GRP->AsString, lpIDGrp);
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
void __fastcall TFormaSpiskaSprLossFactor::FormClose(TObject *Sender,
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
int TFormaSpiskaSprLossFactor::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

if (DM_Connection->UserInfoREOPEN_SPR_SUSER->AsInteger==1)
	{
	UpdateForm();
	}
return -1;
}

//--------------------------------------------------------------------------
void TFormaSpiskaSprLossFactor::OpenFormElement()
{

		IFormaElementaSprLossFactor * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprLossFactor,IID_IFormaElementaSprLossFactor,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString));
		FormaElementa->NumberProcVibor=2;
		FormaElementa->IdGrp=IdGrp;
		FormaElementa->NameGrp=LabelNameGrp->Caption;
		FormaElementa->UpdateForm();
		IdElement=glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString);
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprLossFactor::OpenFormNewElement()
{

		IFormaElementaSprLossFactor * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprLossFactor,IID_IFormaElementaSprLossFactor,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (FormaElementa->DM->NewElement(IdGrp)==true)
				{
				FormaElementa->IdGrp=IdGrp;
				FormaElementa->NameGrp=LabelNameGrp->Caption;
				FormaElementa->UpdateForm();
				FormaElementa->NumberProcVibor=2;
				IdElement=glStrToInt64(FormaElementa->DM->ElementID_SLOSS_FACTOR->AsString);
				}
		else
				{
				FormaElementa->kanRelease();
				ShowMessage(FormaElementa->DM->TextError);
				}
}
//-------------------------------------------------------------------------

void TFormaSpiskaSprLossFactor::DeleteElement()
{
		UnicodeString V="�� ������������� ������ ������� "
		+DM->TableNAME_SLOSS_FACTOR->AsString+"?";
		UnicodeString Z="������������� �������� ��������";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

if(DM->DeleteElement(glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString))!=true)
	{
	ShowMessage("�� ������� ������� ������� �����������!  ������: "+DM->TextError );
	}


DM->OpenTable(IdGrp,AllElement);
}

//---------------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprLossFactor::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprLossFactor::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprLossFactor::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprLossFactor::OpenFormGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				IFormaElementaSprGrpLossFactor * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprGrpLossFactor,IID_IFormaElementaSprGrpLossFactor,
										 (void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->NumberProcVibor=1;
				}
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprLossFactor::OpenFormNewGrpElement()
{

		IFormaElementaSprGrpLossFactor * FormaGrpElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprGrpLossFactor,IID_IFormaElementaSprGrpLossFactor,
										 (void**)&FormaGrpElementa);
		FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);

		if (cxTreeView1->Selected!=NULL)
				{
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaGrpElementa->DM->NewElement(IdGrp);
				}
		else
				{
				FormaGrpElementa->DM->NewElement(0);
				}
		FormaGrpElementa->NumberProcVibor=1;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprLossFactor::DeleteGrpElement()
{

        if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprLossFactor::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprLossFactor::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprLossFactor::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprLossFactor::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdElement=glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_SLOSS_FACTOR->AsString);
        }
else
        {
        AllElement=true ;
		LabelNameGrp->Caption="��� ��������...";
		IdElement=glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_SLOSS_FACTOR->AsString);
        }
UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprLossFactor::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{  //������������� �������
		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				__int64 id=AViewData->Records[i]->Values[cxGrid1DBTableView1ID_SLOSS_FACTOR->Index];
				DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data,id);
				}
			}
		}
DM->OpenTable(IdGrp,AllElement);
}
//-----------------------------------------------------------------------------








void __fastcall TFormaSpiskaSprLossFactor::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGrp,AllElement);
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprLossFactor::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{

				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString));
				Close();

		}
else
		{
		IdElement=glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString);
		OpenFormElement();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprLossFactor::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{

						TypeEvent=1;
						DM->OpenElement(glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString));
						Close();
				}
		else
				{
				OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprLossFactor::cxTreeView1KeyDown(TObject *Sender,
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
		DM->OpenTable(IdGrp,AllElement);
		}
		}
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprLossFactor::ToolButton6Click(TObject *Sender)
{
IdElement=glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString);
UpdateForm();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//������� ������
void __fastcall TFormaSpiskaSprLossFactor::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprLossFactor::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdElement", glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString));
	module->SetInt64Variables("glIdGrp", IdGrp);
	}
	
module->ExecuteModule();


if (type_module==1 || type_module==2)
	{
//	delete scr_doc;
//	delete module;
	}


}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprLossFactor::OpenFormNewCopyElement()
{

		IFormaElementaSprLossFactor * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprLossFactor,IID_IFormaElementaSprLossFactor,
													(void**)&FormaElementa);

		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (FormaElementa->DM->NewElement(IdGrp)==true)
				{
				FormaElementa->NumberProcVibor=2;

				IDMSprLossFactor * n;
				InterfaceGlobalCom->kanCreateObject(ProgId_DMSprLossFactor,IID_IDMSprLossFactor,
													(void**)&n);
				n->Init(InterfaceMainObject,InterfaceImpl);
				n->OpenElement(glStrToInt64(DM->TableID_SLOSS_FACTOR->AsString));
				FormaElementa->DM->Element->Edit();
				FormaElementa->DM->ElementNAME_SLOSS_FACTOR->AsString=
												n->ElementNAME_SLOSS_FACTOR->AsString;

				n->kanRelease();

				FormaElementa->DM->Element->Post();
				FormaElementa->UpdateForm();
				}
		else
				{
				FormaElementa->kanRelease();
				ShowMessage(FormaElementa->DM->TextError);
				}

}
//--------------------------------------------------------------------------

void TFormaSpiskaSprLossFactor::SaveFormSetup(void)
{
//IDMUserSetup * dm;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
//													(void**)&dm);
//
//dm->Init(InterfaceMainObject,InterfaceImpl);
//
//dm->SaveSetupInt("FormaSpiskaSprNom","IndexTypePrice", SpisokTypePrice->ItemIndex);
//dm->SaveSetupInt64("FormaSpiskaSprNom","IdFirm",IdFirm);
//dm->SaveSetup("FormaSpiskaSprNom","NameFirm",NameFirm);
//dm->SaveSetupInt64("FormaSpiskaSprNom","IdSklad",IdSklad);
//dm->SaveSetup("FormaSpiskaSprNom","NameSklad",NameSklad);
//dm->SaveSetupBool("FormaSpiskaSprNom","FlagOstatok",FlagOstatok);
//dm->SaveSetupBool("FormaSpiskaSprNom","OnlyChange",OnlyChange);
//dm->SaveSetupBool("FormaSpiskaSprNom","OnlyOstatok",OnlyOstatok);
//dm->SaveSetupBool("FormaSpiskaSprNom","PriceSklad",PriceSklad);
//
//dm->SaveSetupBool("FormaSpiskaSprNom","AllElement",AllElement);
//
//dm->kanRelease();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprLossFactor::LoadFormSetup(void)
{
//NoUpdateForm=true;
//
//IDMUserSetup * dm;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
//													(void**)&dm);
//dm->Init(InterfaceMainObject,InterfaceImpl);
//
//SpisokTypePrice->ItemIndex=dm->LoadSetupInt("FormaSpiskaSprNom","IndexTypePrice");
//
//
//DM->SpTPrice->First();
//DM->SpTPrice->MoveBy(SpisokTypePrice->ItemIndex);
//DM->IdTypePrice=DM->SpTPriceID_TPRICE->AsInt64;
//IdTypePrice=DM->SpTPriceID_TPRICE->AsInt64;
//
//IdFirm=dm->LoadSetupInt64("FormaSpiskaSprNom","IdFirm");
//NameFirm=dm->LoadSetup("FormaSpiskaSprNom","NameFirm");
//IdSklad=dm->LoadSetupInt64("FormaSpiskaSprNom","IdSklad");
//NameSklad=dm->LoadSetup("FormaSpiskaSprNom","NameSklad");
//
//
//
//FlagOstatok=dm->LoadSetupBool("FormaSpiskaSprNom","FlagOstatok");
//ToolButtonOst->Down=FlagOstatok;
//
//OnlyChange=dm->LoadSetupBool("FormaSpiskaSprNom","OnlyChange");
//ToolButtonCheckOnlyChange->Down=OnlyChange;
//
//OnlyOstatok=dm->LoadSetupBool("FormaSpiskaSprNom","OnlyOstatok");
//ToolButtonOnlyOstatok->Down=OnlyOstatok;
//
//PriceSklad=dm->LoadSetupBool("FormaSpiskaSprNom","PriceSklad");
//ToolButtonPriceSklad->Down=PriceSklad;
//
//AllElement=dm->LoadSetupBool("FormaSpiskaSprNom","AllElement");
//ToolButtonAll->Down=AllElement;
//dm->kanRelease();
//
//NoUpdateForm=false;
}
//----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprLossFactor::ToolButton7Click(TObject *Sender)
{
SaveFormSetup();	
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprLossFactor::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprLossFactor::ToolButtonNewCopyElementClick(TObject *Sender)

{
OpenFormNewCopyElement();
}
//---------------------------------------------------------------------------

