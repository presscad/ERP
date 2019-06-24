//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------
#include "UFormaDocRKORozn.h"
//#include "UPrintFormDocRKO.h"
#include "USheetEditor.h"
#include "IDMSprFirm.h"
#include "IDMSprKlient.h"
#include "IFiskReg.h"
#include "IDMSprOborud.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxPC"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxGraphics"
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocRKORozn::TFormaDocRKORozn(TComponent* Owner)
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
bool TFormaDocRKORozn::Init(void)
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

EditRekvisit=NO;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRKORozn.1",IID_IDMDocRKORozn, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //������ ��������
Vibor=false;       //��� ������
IdDoc=0;           //������������� ������� ������

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameDogovorcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
SumDoccxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

VidatcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
OsncxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameKassacxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
OpercxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;

ModelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SavNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
RegNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NKLcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NCheckcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameCardcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

DBTextFNameUser->DataSource=DM->DataSourceDocAll;

flObrabatChangeOperation=false;

//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocRKORoznImpl),false);
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
DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaDocRKORozn::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocRKORozn::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
		}

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRKORozn::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
if(SpisokKKM)SpisokKKM->kanRelease();
if(FormaSpiskaSprDogovor)FormaSpiskaSprDogovor->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprDiscountCard)FormaSpiskaSprDiscountCard->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

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

DMTableExtPrintForm->kanRelease();
DM->kanRelease();
Action=caFree;
}
//---------------------------------------------------------------------------
int TFormaDocRKORozn::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

if (number_procedure_end==ViborFirm)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRMDOC->AsString=SpisokFirm->DM->ElementIDFIRM->AsString;
                DM->DocAllNAMEFIRM->AsString=SpisokFirm->DM->ElementNAMEFIRM->AsString;
                DM->DocAll->Post();
                }
		SpisokFirm=0;
        }

if (number_procedure_end==ViborKlient)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDKLDOC->AsString=SpisokKlient->DM->ElementIDKLIENT->AsString;
                DM->DocAllNAMEKLIENT->AsString=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
                DM->DocAll->Post();
                DM->Doc->Edit();
                DM->DocVIDAT_DRKOROZN->AsString=SpisokKlient->DM->ElementFNAME->AsString;
                DM->Doc->Post();
                }
        SpisokKlient=0;
        }

if (number_procedure_end==ViborKKM)
        {
		if (type_event==1)
                {
                DM->Doc->Edit();
				DM->DocIDKKM_DRKOROZN->AsString=SpisokKKM->DM->ElementIDKKM->AsString;
                DM->DocNAMEKKM->AsString=SpisokKKM->DM->ElementNAMEKKM->AsString;
                DM->Doc->Post();
                }
        SpisokKKM=0;
        }

if (number_procedure_end==ViborInfBase)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDBASE_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
                }
        FormaSpiskaSprInfBase=0;
        }
        
if (number_procedure_end==ViborDogovor)
		{
		if(type_event==1)
				{
				DM->DocAll->Edit();
				DM->DocAllIDDOGDOC->AsString=FormaSpiskaSprDogovor->DM->TableID_SDOG->AsString;
				DM->DocAllNAME_SDOG->AsString=FormaSpiskaSprDogovor->DM->TableNAME_SDOG->AsString;
                DM->DocAll->Post();
				}
		FormaSpiskaSprDogovor=0;
		 }


if (number_procedure_end==ViborCard_Rekvisit)
		{
		if(type_event==1)
				{
                EndViborCard();
				}
		FormaSpiskaSprDiscountCard=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_Project)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		}

if (number_procedure_end==ER_BusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		}

EditRekvisit=NO;

return -1;
}

//---------------------------------------------------------------------------



void TFormaDocRKORozn::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (SpisokFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=ViborFirm;
        }

}
//--------------------------------------------------------------------------
void TFormaDocRKORozn::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;
if (SpisokKlient==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->Vibor=true;
		SpisokKlient->NumberProcVibor=ViborKlient;
		SpisokKlient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		SpisokKlient->UpdateForm();
	 }
}
//--------------------------------------------------------------------------
void TFormaDocRKORozn::OpenFormSpiskaSprKKM(void)
{
if (Prosmotr==true) return;
if (SpisokKKM==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKKM.1",IID_IFormaSpiskaSprKKM,
													(void**)&SpisokKKM);
		SpisokKKM->Init(InterfaceMainObject,InterfaceImpl);
        SpisokKKM->Vibor=true;
		SpisokKKM->NumberProcVibor=ViborKKM;
    }

}
//--------------------------------------------------------------------------




void TFormaDocRKORozn::PrintDoc(void)
{
TSheetEditor  *prForm=new TSheetEditor(Application);
TcxSSCellObject *cell;

if (!prForm) return;

prForm->SS->BeginUpdate();


prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 40;
        cHeader->Size[3] = 100;
        cHeader->Size[4] = 100;
        cHeader->Size[5] = 100;
        cHeader->Size[6] = 10;
        cHeader->Size[7] = 80;
        cHeader->Size[8] = 50;
        cHeader->Size[9] = 10;
        cHeader->Size[10] =50;
        cHeader->Size[11] = 100;
        cHeader->Size[12] = 30;



numCol=12;
numRow=0;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="��������������� ����� � ��-2";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
delete cell;
numRow++;

        TRect rect;
        rect.Left = 4;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Text="���������� �������������� ����������� ������ �� 18.08.98 �. � 88";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
delete cell;
numRow++;

numCol=11;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="����";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

numRow++;
//***********
numCol=10;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="����� �� ����";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;

numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="0310002";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
//************************
numCol=2;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+6;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

IDMSprFirm * DMSFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSFirm);
DMSFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSFirm->ElementFNAMEFIRM->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�� ����";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;

numCol++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
//*********************************
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;numCol++;

numCol++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numRow++;
//*********************************************
prForm->SS->ActiveSheet->Rows->Size[numRow]=10;
numRow++;
//*********************************

numCol=8;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Text="����� ���������";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Text="���� �����������";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numRow++;
//******************

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Text="��������� �������� �����  ";
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Font->Size = 12;
delete cell;

numCol=8;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text=DM->DocAllNUMDOC->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Text=DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numRow++;
//****************
prForm->SS->ActiveSheet->Rows->Size[numRow]=10;
numRow++;

//******************
numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+3;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="��� ������������ �������������";
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="��������������- ��� ����, �������";
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="��� �������- ������� �����";
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Text="������";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Text="�����, ���. ���.";
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+2, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow+1);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+2, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol++;numCol++;numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Text="��� �������� ����������";
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;numRow++;
//***********************
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;


        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text=FloatToStrF(DM->DocAllSUMDOC->AsFloat, ffFixed,14,2);
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;

numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=10;
numRow++;

numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+10;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="������ "+DM->DocVIDAT_DRKOROZN->AsString;
cell->Style->WordBreak = true;
delete cell;

numRow++;
numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+10;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="���������: "+DM->DocOSN_DRKOROZN->AsString;
cell->Style->WordBreak = true;
delete cell;

numRow++;
numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+10;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�����: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
cell->Style->WordBreak = true;
delete cell;

numRow++;
numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+10;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="����������: "+DM->DocPRIM_DRKOROZN->AsString;
cell->Style->WordBreak = true;
delete cell;

numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=10;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="������������";
//cell->Style->Font->Size = 10;
//cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numCol++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DMSFirm->ElementDIRFIRM->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numRow++;
numCol=4;
prForm->SS->ActiveSheet->Rows->Size[numRow]=10;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="���������";
cell->Style->Font->Size = 6;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
numCol++;
numCol++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�������";
cell->Style->Font->Size = 6;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
numCol++;numCol++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="����������� �������";
cell->Style->Font->Size = 6;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;


numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="������� ���������";
//cell->Style->Font->Size = 10;
//cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numCol++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DMSFirm->ElementBUHFIRM->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numRow++;
numCol=4;
prForm->SS->ActiveSheet->Rows->Size[numRow]=10;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="���������";
cell->Style->Font->Size = 6;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
numCol++;
numCol++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�������";
cell->Style->Font->Size = 6;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
numCol++;numCol++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="����������� �������";
cell->Style->Font->Size = 6;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;

numRow++;
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�������";
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;
//*********************
prForm->SS->ActiveSheet->Rows->Size[numRow]=10;
cell = prForm->SS->ActiveSheet->GetCellObject(6,numRow);
cell->Text="����� ��������";
cell->Style->Font->Size = 6;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numRow++;
///***************************
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(9,numRow);
cell->Text="���.";
delete cell;
numCol++;numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(12,numRow);
cell->Text="���.";
delete cell;

numRow++;
//*************************
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="\"____\" _______________ 200__  �.";
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(7,numRow);
cell->Text="�������___________________________________";
delete cell;
numRow++;
//****************************************
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(2,numRow);
cell->Text="��";
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=10;
cell = prForm->SS->ActiveSheet->GetCellObject(6,numRow);
cell->Text="������������, �����, ���� � ����� ������ ���������, ��������������� ��������";
cell->Style->Font->Size = 6;
cell->Style->HorzTextAlign = haCENTER;
delete cell;


numRow++;
//***********************
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="����� ������";
//cell->Style->Font->Size = 8;
//cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text=DMSFirm->ElementKASFIRM->AsString;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numRow++;
//**********************
numCol=4;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="�������";
cell->Style->Font->Size = 6;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;numCol++;numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+3;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="����������� �������";
cell->Style->Font->Size = 6;
cell->Style->HorzTextAlign = haCENTER;
delete cell;



DMSFirm->kanRelease();
//PrintForm->F1->ShowGridLines=false;

prForm->SS->EndUpdate();
prForm->Show();

}
//---------------------------------------------------------------------------

void TFormaDocRKORozn::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
        FormaSpiskaSprInfBase->Vibor=true;
        FormaSpiskaSprInfBase->NumberProcVibor=ViborInfBase;
		FormaSpiskaSprInfBase->DM->OpenTable();
        }
}
//---------------------------------------------------------------------


//---------------------------------------------------------------------------
void TFormaDocRKORozn::OpenFormSpiskaSprDogovor(void)
{
if (DM->DocAllIDKLDOC->AsInteger==0)
        {
        ShowMessage("�������� �����������!");
        return;
        }

if (FormaSpiskaSprDogovor==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDogovor.1",IID_IFormaSpiskaSprDogovor,
													(void**)&FormaSpiskaSprDogovor);
		FormaSpiskaSprDogovor->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprDogovor->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
        FormaSpiskaSprDogovor->Vibor=true;
		FormaSpiskaSprDogovor->DM->OpenTable(glStrToInt64(DM->DocAllIDKLDOC->AsString));
        //FormaSpiskaSprDogovor->LabelKlient->Caption="����������: "+DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDogovor->NumberProcVibor=ViborDogovor;
        }
}
//-----------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocRKORozn");
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaDocRKORozn::PrintCheckFR(void)
{
if (Prosmotr==true) return;
if (FormaViborFR==NULL)
        {
		FormaViborFR=new TFormaViborFR(Application);
		FormaViborFR->DM_Connection=DM_Connection;
		FormaViborFR->Init();
		if (!FormaViborFR) return;
		FormaViborFR->IdArm=glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString);
		FormaViborFR->Vibor=true;
		FormaViborFR->UpdateForm();
		FormaViborFR->FOnCloseForm=EndViborFR;
		if (FormaViborFR->DM->Table->RecordCount<=1)
			{
			FormaViborFR->OutReady=true;
			FormaViborFR->Close();
			}
		else
			{
			FormaViborFR->ShowModal();
			}
		} 
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRKORozn::EndViborFR(TObject *Sender)
{

if (FormaViborFR->OutReady==true)
	{
	FormaViborFR->Visible=false;
	IDMSprOborud *DMSprOborud;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
													(void**)&DMSprOborud);
		DMSprOborud->Init(InterfaceMainObject,InterfaceImpl);
	DMSprOborud->OpenElement(FormaViborFR->DM->TableID_OBORUD->AsInt64);
	if (DMSprOborud->ElementID_OBORUD->AsInteger>0)
		{
		IFiskReg *fr;
		InterfaceGlobalCom->kanCreateObject("Oberon.FiskReg.1",IID_IFiskReg,
													(void**)&fr);
		fr->Init(InterfaceMainObject,InterfaceImpl);
		fr->Modul=DMSprOborud->ElementMODUL_SOBORUD->AsString;
		fr->Number=1;
		fr->InitDevice();
		int number_port=0;
		if (DMSprOborud->ElementCOMNAME_OBORUD->AsString!="")
			{
			number_port=StrToFloat(DMSprOborud->ElementCOMNAME_OBORUD->AsString);
			}
		AnsiString baud_rate=DMSprOborud->ElementBAUDRATE_OBORUD->AsString;

		AnsiString password=DMSprOborud->GetParameter("password");
		if(fr->Connect(number_port, baud_rate, password)==true)
			{}
		else
			{
			ShowMessage("������ ��� ����������� ����������� ������������: "+fr->TextError);
			FormaViborFR=0;
			return;
			}

		try
			{
				if(fr->ProvVosmPrintCheck()==false)
					{
					throw Exception("��� ����������� ���������� ���! "+fr->TextError);
					}

				fr->OpenNoFiscalCheck();


				if (DMSprOborud->GetParameter("STR_ZAG_1")!="")
							{
							fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_1"),1,0,0,true,false, false);
							}

				if (DMSprOborud->GetParameter("STR_ZAG_2")!="")
							{
							fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_2"),1,0,0,true,false, false);
							}

				if (DMSprOborud->GetParameter("STR_ZAG_3")!="")
							{
							fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_3"),1,0,0,true,false, false);
							}

				fr->PrintString(" ",1,0,0,true,false, false);


				fr->PrintLine();//("------------------------------------",1,0,0,true,false);
				fr->PrintString(DM->DocOSN_DRKOROZN->AsString,1,0,1,true,false, true);

				fr->PrintLine();//("------------------------------------",1,0,0,true,false);
				fr->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false);

				fr->CloseNoFiscalCheck();

				if (DMSprOborud->GetParameter("UCH")=="YES")
					{
							//0 ������� 1 �������
							if(fr->PrintNoFiscalCheck(DM->DocAllSUMDOC->AsFloat,  //����� �������
													1,                            //�����
													DM->DocAllSUMDOC->AsFloat,       //��������
													0,     //���������� �����
													0,     //��������� �����
													0,	   //������
													1)==true)
								{}
							else {}

					}
				else
					{
							//0 ������� 1 �������
							if(fr->PrintFiscalCheck(DM->DocAllSUMDOC->AsFloat,  //����� �������
													1,                            //�����
													DM->DocAllSUMDOC->AsFloat,       //��������
													0,     //���������� �����
													0,     //��������� �����
													0,	   //������
													1)==true)
								{}
							else {}

					}
			//������� ����� ����
			fr->GetSostKKM();
			DM->Doc->Edit();
			DM->DocNKL_DRKOROZN->AsInteger=fr->NumberKL;
			DM->DocNCHECK_DRKOROZN->AsInteger=fr->NumberCheck;
			DM->DocREGNUM_DRKOROZN->AsString=fr->RegNumberKKM;
			DM->DocSAVNUM_DRKOROZN->AsString=fr->SerialNumberKKM;
			DM->DocMODEL_DRKOROZN->AsString=fr->ModelKKM;
			DM->Doc->Post();
			}
		catch(Exception &exception)
			{
			ShowMessage("������! "+exception.Message);
			}
		fr->Disconnect();
		fr->kanRelease();
		}
	else
		{
		ShowMessage("�� ������ ������� ����� ��� ������������ ���������� �������������! ");
		}
	DMSprOborud->kanRelease();
	}
FormaViborFR=0;
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRKORozn::cxButtonprintCheckNaFRClick(TObject *Sender)
{
if (DM->DocNCHECK_DRKOROZN->AsInteger>0)
	{
	String V="�������� ��� ��� ������! ������� ��� ����?";
	String Z="��������!";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				PrintCheckFR();
				}
	}
else
	{
	PrintCheckFR();
	}
}
//---------------------------------------------------------------------------









void __fastcall TFormaDocRKORozn::NameDogovorcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprDogovor();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::PosDoccxDBDateEditPropertiesChange(
      TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::NameKassacxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKKM();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRKORozn::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();  	
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocRKORozn::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::VidatcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::OsncxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRKORozn::SumDoccxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void TFormaDocRKORozn::ViborCard(void)
{ 
if (Prosmotr==true) return;
if (FormaSpiskaSprDiscountCard==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDiscountCard.1",IID_IFormaSpiskaSprDiscountCard,
													(void**)&FormaSpiskaSprDiscountCard);
		FormaSpiskaSprDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprDiscountCard->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		FormaSpiskaSprDiscountCard->DM->OpenTable(DM->DocAllIDKLDOC->AsInteger);
		//FormaSpiskaSprDiscountCard->LabelKlient->Caption="����������: "+DM->DocAllNAMEKLIENT->AsString;
		//FormaSpiskaSprDiscountCard->NameKlient=DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDiscountCard->Vibor=true;
		FormaSpiskaSprDiscountCard->NumberProcVibor=ViborCard_Rekvisit;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRKORozn::EndViborCard(void)
{

	DM->Doc->Edit();
	DM->DocIDCARD_DRKOROZN->AsString=FormaSpiskaSprDiscountCard->DM->TableID_SDISCOUNT_CARD->AsString;
	DM->DocNAME_SDISCOUNT_CARD->AsString=FormaSpiskaSprDiscountCard->DM->TableNAME_SDISCOUNT_CARD->AsString;
    DM->Doc->Post();



}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRKORozn::NameCardcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCard();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//������� ������
void __fastcall TFormaDocRKORozn::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocRKORozn::RunExternalModule(__int64 id_module, int type_module)
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
//
//	//���� �������� ����� TScriptDMDocRealRozn
//	//������ ��� ������ � ����������
//	scr_doc=new TScriptDMDocRealRozn();
//	scr_doc->AddClassesInScript(module);
//	//���� �������� ������� DM
//	scr_doc->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",scr_doc);
	}


//���� �������� ���������� ������, ��� �������  IDDOC
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllIDDOC->AsString));
	
module->ExecuteModule();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRKORozn::ActionDvRegExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{

				}
		else
			{
			ShowMessage("������ ��� ���������� ���������: "+DM->TextError);
			}
		UpdateForm();
		}
else
	{
	ShowMessage("������ ��� ������ ���������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::ActionOKExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				Close();
				}
		else
			{
			ShowMessage("������ ��� ���������� ���������: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("������ ��� ������ ���������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		UpdateForm();
		}
else
	{
	ShowMessage("������ ��� ������ ���������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::ActionPrintExecute(TObject *Sender)
{
PrintDoc();
}
//---------------------------------------------------------------------------
void TFormaDocRKORozn::OpenFormSpiskaSprProject(void)
{
if (Prosmotr==true) return;
if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=ER_Project;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRKORozn::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocRKORozn::OpenFormSpiskaSprBusinessOper(void)
{
if (Prosmotr==true) return;
if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=ER_BusinessOper;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRKORozn::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRKORozn::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprBusinessOper();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDBUSINOP_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRKORozn::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprProject();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDPROJECT_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

