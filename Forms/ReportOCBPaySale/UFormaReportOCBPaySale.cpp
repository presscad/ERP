//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaReportOCBPaySale.h"
#include "math.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportOCBPaySale::TFormaReportOCBPaySale(TComponent* Owner)
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
void __fastcall TFormaReportOCBPaySale::FormCreate(TObject *Sender)
{
//
}

//-----------------------------------------------------------------------
bool TFormaReportOCBPaySale::Init(void)
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

IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBQ->Database=DM_Connection->pFIBData;


DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameGrpKlientEdit->Text="";
NameKlientEdit->Text="";
NameDogovorEdit->Text="";
NameBusinessOpercxButtonEdit->Text="";
NameProjectcxButtonEdit->Text="";

//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaReportOCBPaySaleImpl),false);
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
void __fastcall TFormaReportOCBPaySale::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokGrpKlient)SpisokGrpKlient->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
if(FormaSpiskaSprDogovor) FormaSpiskaSprDogovor->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int  TFormaReportOCBPaySale::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
int TFormaReportOCBPaySale::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

if (number_procedure_end==ViborFirm)
        {
		if (type_event==1)
                {
				IdFirm=SpisokFirm->DM->TableIDFIRM->AsInt64;
                NameFirmEdit->Text=SpisokFirm->DM->TableNAMEFIRM->AsString;
                }
        SpisokFirm=0;
        }

if (number_procedure_end==ViborGrpKlient)
        {
		if (type_event==1)
                {
				IdGrpKlient=SpisokGrpKlient->DM->ElementIDGRPKL->AsInt64;
                NameGrpKlientEdit->Text=SpisokGrpKlient->DM->ElementNAMEGRPKL->AsString;
                }
        SpisokGrpKlient=0;
        }

if (number_procedure_end==ViborKlient)
        {
		if (type_event==1)
				{
				IdKlient=SpisokKlient->DM->ElementIDKLIENT->AsInt64;
                NameKlientEdit->Text=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
                IdGrpKlient=0;
                NameGrpKlientEdit->Text="";
                }
        SpisokKlient=0;
        }


if (number_procedure_end==ViborDogovor)
        {
        if(type_event==1)
                {
				IdDogovor=FormaSpiskaSprDogovor->DM->TableID_SDOG->AsInt64;
                NameDogovorEdit->Text=FormaSpiskaSprDogovor->DM->TableNAME_SDOG->AsString;

                }
        FormaSpiskaSprDogovor=0;
		 }

if (number_procedure_end==ER_ViborProject)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_ViborBusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------
void TFormaReportOCBPaySale::CreateReportPaySale( TSheetEditor *prForm)
{
porNumKlient=1;

                IBQ->Active=false;
				IBQ->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
                IBQ->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
				IBQ->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
				IBQ->ParamByName("PARAM_IDGRPKLIENT")->AsInt64=IdGrpKlient;
				IBQ->ParamByName("PARAM_IDKLIENT")->AsInt64=IdKlient;
				IBQ->ParamByName("PARAM_IDDOGOVOR")->AsInt64=IdDogovor;

                IBQ->Active=true;
                porNumStr=1;
                IBQ->First();

IdTecFirm=IBQIDFIRM_PROC->AsInt64;
num_row_firm=numRow;
OutputStringFirm(prForm);


IdTecGrpKlient=IBQIDGRP_PROC->AsInt64;
num_row_grp_klient=numRow;
OutputStringGrpKlient(prForm);


IdTecKlient=IBQIDKLIENT_PROC->AsInt64;
num_row_klient=numRow;
OutputStringKlient(prForm);


IdTecDogovor=IBQIDDOGOVOR_PROC->AsInt64;
num_row_dogovor=numRow;
OutputStringDogovor(prForm);


IdTecDoc=IBQIDDOC_PROC->AsInt64;
num_row_doc=numRow;
OutputStringDoc(prForm);


AllNachOst=0;
AllPrihod=0;
AllRashod=0;
AllConOst=0;

sum_nach_ost_firm=0;
sum_prihod_firm=0;
sum_rashod_firm=0;
sum_con_ost_firm=0;

sum_nach_ost_grp=0;
sum_prihod_grp=0;
sum_rashod_grp=0;
sum_con_ost_grp=0;

sum_nach_ost_klient=0;
sum_prihod_klient=0;
sum_rashod_klient=0;
sum_con_ost_klient=0;

sum_nach_ost_dogovor=0;
sum_prihod_dogovor=0;
sum_rashod_dogovor=0;
sum_con_ost_dogovor=0;

sum_nach_ost_doc=0;
sum_prihod_doc=0;
sum_rashod_doc=0;
sum_con_ost_doc=0;



                while(!IBQ->Eof)
                        {
                        //�����
						if (IBQIDFIRM_PROC->AsInt64==IdTecFirm)
                                {   //��� �� �����
                                sum_nach_ost_firm=sum_nach_ost_firm+IBQNACHOST_PROC->AsFloat;
                                sum_prihod_firm=sum_prihod_firm+IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_firm=sum_rashod_firm+IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_firm=sum_con_ost_firm+IBQCONOST_PROC->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiFirm(prForm);
                                num_row_firm=numRow;
                                OutputStringFirm(prForm);
                                IdTecFirm=IBQIDFIRM_PROC->AsInteger;

                                sum_nach_ost_firm=IBQNACHOST_PROC->AsFloat;
                                sum_prihod_firm=IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_firm=IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_firm=IBQCONOST_PROC->AsFloat;

                                }

                        //������ ��������
						if (IBQIDGRP_PROC->AsInt64==IdTecGrpKlient)
                                {   //��� �� ������
                                sum_nach_ost_grp=sum_nach_ost_grp+IBQNACHOST_PROC->AsFloat;
                                sum_prihod_grp=sum_prihod_grp+IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_grp=sum_rashod_grp+IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_grp=sum_con_ost_grp+IBQCONOST_PROC->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiGrpKlient(prForm);
                                num_row_grp_klient=numRow;
                                OutputStringGrpKlient(prForm);
								IdTecGrpKlient=IBQIDGRP_PROC->AsInt64;

                                sum_nach_ost_grp=IBQNACHOST_PROC->AsFloat;
                                sum_prihod_grp=IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_grp=IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_grp=IBQCONOST_PROC->AsFloat;
                                porNumKlient=1;
                                }

                        //������
						if (IBQIDKLIENT_PROC->AsInt64==IdTecKlient)
                                {   //���� �� ������
                                sum_nach_ost_klient=sum_nach_ost_klient+IBQNACHOST_PROC->AsFloat;
                                sum_prihod_klient=sum_prihod_klient+IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_klient=sum_rashod_klient+IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_klient=sum_con_ost_klient+IBQCONOST_PROC->AsFloat;
                                }
                        else
                                {

                                OutputStringItogiKlient(prForm);
                                num_row_klient=numRow;
								OutputStringKlient(prForm);
								IdTecKlient=IBQIDKLIENT_PROC->AsInt64;
                                porNumKlient++;
                                sum_nach_ost_klient=IBQNACHOST_PROC->AsFloat;
                                sum_prihod_klient=IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_klient=IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_klient=IBQCONOST_PROC->AsFloat;
                                }

                        //�������
						if (IBQIDDOGOVOR_PROC->AsInt64==IdTecDogovor)
                                {   //���� �� �������

                                sum_nach_ost_dogovor=sum_nach_ost_dogovor+IBQNACHOST_PROC->AsFloat;
                                sum_prihod_dogovor=sum_prihod_dogovor+IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_dogovor=sum_rashod_dogovor+IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_dogovor=sum_con_ost_dogovor+IBQCONOST_PROC->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiDogovor(prForm);
                                num_row_dogovor=numRow;
                                OutputStringDogovor(prForm);
                                IdTecDogovor=IBQIDDOGOVOR_PROC->AsInt64;

                                sum_nach_ost_dogovor=IBQNACHOST_PROC->AsFloat;
                                sum_prihod_dogovor=IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_dogovor=IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_dogovor=IBQCONOST_PROC->AsFloat;
                                }

                        //��������
                        if (IBQIDDOC_PROC->AsInt64==IdTecDoc)
                                {   //���� �� ��������
                                sum_nach_ost_doc=sum_nach_ost_doc+IBQNACHOST_PROC->AsFloat;
                                sum_prihod_doc=sum_prihod_doc+IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_doc=sum_rashod_doc+IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_doc=sum_con_ost_doc+IBQCONOST_PROC->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiDoc(prForm);
                                num_row_doc=numRow;
                                OutputStringDoc(prForm);
                                IdTecDoc=IBQIDDOC_PROC->AsInt64;

                                sum_nach_ost_doc=IBQNACHOST_PROC->AsFloat;
                                sum_prihod_doc=IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_doc=IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_doc=IBQCONOST_PROC->AsFloat;
                                }


                        OutputStringDate(prForm);


                        AllNachOst=AllNachOst+IBQNACHOST_PROC->AsFloat;
                        AllPrihod=AllPrihod+IBQPRIHOD_PROC->AsFloat;
                        AllRashod=AllRashod+IBQRASHOD_PROC->AsFloat;
                        AllConOst=AllConOst+IBQCONOST_PROC->AsFloat;

                        porNumStrGrp++;
                        porNumStr++;
                        IBQ->Next();
                        }

OutputStringItogiFirm(prForm);
OutputStringItogiGrpKlient(prForm);
OutputStringItogiKlient(prForm);
OutputStringItogiDogovor(prForm);
OutputStringItogiDoc(prForm);

}
//---------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputZagolovokReport(TSheetEditor *prForm)
{
        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 50;
        cHeader->Size[2] = 300;
        cHeader->Size[3] = 100;
        cHeader->Size[4] = 100;
        cHeader->Size[5] = 100;
        cHeader->Size[6] = 100;


numRow=2;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "����� �� �������� "+DateToStr(DateNach->Date)
                        +" �� "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
numRow++;

if (IdFirm>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        cell->Text = "�����: "+NameFirmEdit->Text;
        cell->Style->Font->Size = 12;
        delete cell;
        numRow++;
        }

if (IdGrpKlient>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        cell->Text = "������: "+NameGrpKlientEdit->Text;
        cell->Style->Font->Size = 12;
        delete cell;
        numRow++;
        }

if (IdKlient>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        cell->Text = "����������: "+NameKlientEdit->Text;
        cell->Style->Font->Size = 12;
        delete cell;
        numRow++;
        }

if (IdDogovor>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        cell->Text = "�������: "+NameDogovorEdit->Text;
        cell->Style->Font->Size = 12;
        delete cell;
        numRow++;
        }

numRow++;
numCol=1;
//���������� ����� ������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "�";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//������������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Text = "����� / ���������� / ������� / �������� ����.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//��� �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "���. �������";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "�����������";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "��������";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//���. �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "���. �������";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}

//----------------------------------------------------------------------------
//***************   �����     *********
//----------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringFirm(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//���������� ����� ������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;

//�����
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEFIRM_PROC->AsString;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//��� �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//���. �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
numRow++;
}
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringItogiFirm(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
if(sum_nach_ost_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_firm);
        cell->Text = FloatToStrF(sum_nach_ost_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 16;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_prihod_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_firm);
        cell->Text = FloatToStrF(sum_prihod_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 16;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_rashod_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_firm);
        cell->Text = FloatToStrF(sum_rashod_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 16;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_con_ost_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_firm);
        cell->Text = FloatToStrF(sum_con_ost_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 16;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_firm] = 30;
//sum_nach_ost_grp=IBQNACHOSTSUM->AsFloat;
//sum_prihod_grp=IBQPRIHODSUM->AsFloat;
//sum_rashod_grp=IBQRASHODSUM->AsFloat;
//sum_con_ost_grp=IBQCONOSTSUM->AsFloat;



}
//----------------------------------------------------------------------------
// ������ ��������
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringGrpKlient(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//���������� ����� ������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//������ ���.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEGRP_PROC->AsString;
cell->Style->Font->Size = 14;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//��� �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//���. �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
numRow++;
}
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringItogiGrpKlient(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
if(sum_nach_ost_grp!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_grp_klient);
        cell->Text = FloatToStrF(sum_nach_ost_grp,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 14;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_prihod_grp!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_grp_klient);
        cell->Text = FloatToStrF(sum_prihod_grp,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 14;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_rashod_grp!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_grp_klient);
        cell->Text = FloatToStrF(sum_rashod_grp,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 14;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_con_ost_grp!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_grp_klient);
        cell->Text = FloatToStrF(sum_con_ost_grp,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 14;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_grp_klient] = 30;
//sum_nach_ost_grp=IBQNACHOSTSUM->AsFloat;
//sum_prihod_grp=IBQPRIHODSUM->AsFloat;
//sum_rashod_grp=IBQRASHODSUM->AsFloat;
//sum_con_ost_grp=IBQCONOSTSUM->AsFloat;



}
//-----------------------------------------------------------------------------
//  �������
//-----------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringKlient(TSheetEditor *prForm)
{

TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumKlient);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//�����������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEKLIENT_PROC->AsString;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//��� �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//���. �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
numCol++;
numRow++;
}
//---------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringItogiKlient(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
if(sum_nach_ost_klient!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_klient);
        cell->Text = FloatToStrF(sum_nach_ost_klient,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_prihod_klient!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_klient);
        cell->Text = FloatToStrF(sum_prihod_klient,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }



if(sum_rashod_klient!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_klient);
        cell->Text = FloatToStrF(sum_rashod_klient,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }



if(sum_con_ost_klient!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_klient);
        cell->Text = FloatToStrF(sum_con_ost_klient,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }



//kol_nach_ost_nom=IBQNACHOSTKOL->AsFloat;
//sum_nach_ost_nom=IBQNACHOSTSUM->AsFloat;
//kol_prihod_nom=IBQPRIHODKOL->AsFloat;
//sum_prihod_nom=IBQPRIHODSUM->AsFloat;
//kol_rashod_nom=IBQRASHODKOL->AsFloat;
//sum_rashod_nom=IBQRASHODSUM->AsFloat;
//kol_con_ost_nom=IBQCONOSTKOL->AsFloat;
//sum_con_ost_nom=IBQCONOSTSUM->AsFloat;

}

//-----------------------------------------------------------------------------
//------------------------------------------------------------------------------
// ��������
//------------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringDogovor(TSheetEditor *prForm)
{

TcxSSCellObject *cell;
numCol=1;
//���������� ����� ������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = IntToStr(porNumStrGrp);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;



//�����������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEDOGOVOR_PROC->AsString;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//��� �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//���. �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
}
//---------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringItogiDogovor(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
if(sum_nach_ost_dogovor!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(3,num_row_dogovor);
        cell->Text = FloatToStrF(sum_nach_ost_dogovor,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        delete cell;
        }

if(sum_prihod_dogovor!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4,num_row_dogovor);
        cell->Text = FloatToStrF(sum_prihod_dogovor,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        delete cell;
        }

if(sum_rashod_dogovor!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5,num_row_dogovor);
        cell->Text = FloatToStrF(sum_rashod_dogovor,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        delete cell;
        }

if(sum_con_ost_dogovor!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6,num_row_dogovor);
        cell->Text = FloatToStrF(sum_con_ost_dogovor,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        delete cell;
        }



//kol_nach_ost_nom=IBQNACHOSTKOL->AsFloat;
//sum_nach_ost_nom=IBQNACHOSTSUM->AsFloat;
//kol_prihod_nom=IBQPRIHODKOL->AsFloat;
//sum_prihod_nom=IBQPRIHODSUM->AsFloat;
//kol_rashod_nom=IBQRASHODKOL->AsFloat;
//sum_rashod_nom=IBQRASHODSUM->AsFloat;
//kol_con_ost_nom=IBQCONOSTKOL->AsFloat;
//sum_con_ost_nom=IBQCONOSTSUM->AsFloat;

}
//------------------------------------------------------------------------------
//���������
//-----------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringDoc(TSheetEditor *prForm)
{

TcxSSCellObject *cell;
numCol=1;
//���������� ����� ������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//�����������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = glGetNameDoc(IBQTDOC_PROC->AsString)+" �"+IBQNUMDOC_PROC->AsString+" �� "+IBQPOSDOC_PROC->AsString;
        cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//��� �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//���. �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
}
//---------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringItogiDoc(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
if(sum_nach_ost_doc!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(3,num_row_doc);
        cell->Text = FloatToStrF(sum_nach_ost_doc,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        delete cell;
        }

if(sum_prihod_doc!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4,num_row_doc);
        cell->Text = FloatToStrF(sum_prihod_doc,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        delete cell;
        }

if(sum_rashod_doc!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5,num_row_doc);
        cell->Text = FloatToStrF(sum_rashod_doc,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        delete cell;
        }

if(sum_con_ost_doc!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6,num_row_doc);
        cell->Text = FloatToStrF(sum_con_ost_doc,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        delete cell;
        }


//kol_nach_ost_nom=IBQNACHOSTKOL->AsFloat;
//sum_nach_ost_nom=IBQNACHOSTSUM->AsFloat;
//kol_prihod_nom=IBQPRIHODKOL->AsFloat;
//sum_prihod_nom=IBQPRIHODSUM->AsFloat;
//kol_rashod_nom=IBQRASHODKOL->AsFloat;
//sum_rashod_nom=IBQRASHODSUM->AsFloat;
//kol_con_ost_nom=IBQCONOSTKOL->AsFloat;
//sum_con_ost_nom=IBQCONOSTSUM->AsFloat;

}
//-----------------------------------------------------------------------------




//------------------------------------------------------------------------------
void TFormaReportOCBPaySale::OutputStringDate(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//�����������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQDATE_PROC->AsDateTime!=StrToDate("30.12.1899"))
        {
        cell->Text = IBQDATE_PROC->AsString;
        }
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
if (IBQDATE_PROC->AsDateTime<=DateCon->Date &&
            IBQCONOST_PROC->AsFloat>0 && IBQDATE_PROC->AsDateTime!=StrToDate("30.12.1899"))
        {
        cell->Style->Font->FontColor=2;
        }
else
        {
        cell->Style->Font->FontColor=10;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//��� �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQNACHOST_PROC->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQNACHOST_PROC->AsFloat,ffFixed,10,2);
        }
if (IBQDATE_PROC->AsDateTime<=DateCon->Date &&
            IBQCONOST_PROC->AsFloat>0 && IBQDATE_PROC->AsDateTime!=StrToDate("30.12.1899"))
        {
        cell->Style->Font->FontColor=2;
        }
else
        {
        cell->Style->Font->FontColor=10;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQPRIHOD_PROC->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQPRIHOD_PROC->AsFloat,ffFixed,10,2);
        }
if (IBQDATE_PROC->AsDateTime<=DateCon->Date &&
			IBQCONOST_PROC->AsFloat>0 && IBQDATE_PROC->AsDateTime!=StrToDate("30.12.1899"))
        {
        cell->Style->Font->FontColor=2;
        }
else
        {
        cell->Style->Font->FontColor=10;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQRASHOD_PROC->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQRASHOD_PROC->AsFloat,ffFixed,10,2);
        }
if (IBQDATE_PROC->AsDateTime<=DateCon->Date &&
            IBQCONOST_PROC->AsFloat>0 && IBQDATE_PROC->AsDateTime!=StrToDate("30.12.1899"))
        {
        cell->Style->Font->FontColor=2;
        }
else
        {
        cell->Style->Font->FontColor=10;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//���. �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQCONOST_PROC->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQCONOST_PROC->AsFloat,ffFixed,10,2);
        }

if (IBQDATE_PROC->AsDateTime<=DateCon->Date &&
            IBQCONOST_PROC->AsFloat>0  && IBQDATE_PROC->AsDateTime!=StrToDate("30.12.1899"))
        {
        cell->Style->Font->FontColor=2;
        }
else
        {
        cell->Style->Font->FontColor=10;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;
}

//--------------------------------------------------------------------------


void TFormaReportOCBPaySale::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//���������� ����� ������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;

//�����������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;

//��� �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(AllNachOst, ffFixed,15,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(AllPrihod, ffFixed,15,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(AllRashod, ffFixed,15,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//���. �������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(AllConOst, ffFixed,15,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
}
//-----------------------------------------------------------------------------



void TFormaReportOCBPaySale::OpenFormSpiskaSprFirm(void)
{
if (SpisokFirm==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=ViborFirm;
		}
}
//---------------------------------------------------------------------------


void TFormaReportOCBPaySale::OpenFormSpiskaSprGrpKlient(void)
{
if (SpisokGrpKlient==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpKlient.1",IID_IFormaSpiskaSprGrpKlient,
													(void**)&SpisokGrpKlient);
		SpisokGrpKlient->Init(InterfaceMainObject,InterfaceImpl);
        SpisokGrpKlient->Vibor=true;
		SpisokGrpKlient->NumberProcVibor=ViborGrpKlient;
        }

}
//--------------------------------------------------------------------------

void TFormaReportOCBPaySale::OpenFormSpiskaSprKlient(void)
{
if (SpisokKlient==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
        SpisokKlient->Vibor=true;
		SpisokKlient->NumberProcVibor=ViborKlient;
		SpisokKlient->UpdateForm();
		}
}
//--------------------------------------------------------------------------
void TFormaReportOCBPaySale::OpenFormSpiskaSprDogovor(void)
{
if (IdDogovor==0)
        {
        ShowMessage("�������� �����������!");
        return;
        }

if (FormaSpiskaSprDogovor==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDogovor.1",IID_IFormaSpiskaSprDogovor,
													(void**)&FormaSpiskaSprDogovor);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
        FormaSpiskaSprDogovor->IdKlient=IdKlient;
        FormaSpiskaSprDogovor->Vibor=true;
        FormaSpiskaSprDogovor->DM->OpenTable(IdKlient);
		//FormaSpiskaSprDogovor->LabelKlient->Caption="����������: "+NameKlientEdit->Text;
		FormaSpiskaSprDogovor->NumberProcVibor=ViborDogovor;
        }
}
//-----------------------------------------------------------------------------




void __fastcall TFormaReportOCBPaySale::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Report/RepPaySale");	
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportOCBPaySale::cxButtonCreateClick(TObject *Sender)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;

porNumStrGrp=1;

AllNachOst=0;
AllPrihod=0;
AllRashod=0;
AllConOst=0;

PrintForm->SS->BeginUpdate();

//�����
OutputZagolovokReport(PrintForm);

//�������

CreateReportPaySale( PrintForm);


OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBPaySale::NameDogovorEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprDogovor();
		}break;
	case 1:
		{
		IdDogovor=0;
		NameDogovorEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBPaySale::NameKlientEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprKlient();
		}break;
	case 1:
		{
		IdKlient=0;
		NameKlientEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBPaySale::NameGrpKlientEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprGrpKlient();
		}break;
	case 1:
		{
		IdGrpKlient=0;
		NameGrpKlientEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBPaySale::NameFirmEditPropertiesButtonClick(
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
//������� ������
void __fastcall TFormaReportOCBPaySale::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaReportOCBPaySale::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdGrpKlient", IdGrpKlient);
	module->SetInt64Variables("glIdKlient", IdKlient);
	module->SetInt64Variables("glIdDogovor", IdDogovor);
	module->SetInt64Variables("glIdBusinessOper", IdBusinessOper);
	module->SetInt64Variables("glIdProject", IdProject);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);

	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportOCBPaySale::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TFormaReportOCBPaySale::OpenFormSpiskaSprProject(void)
{

if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=ER_ViborProject;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void  TFormaReportOCBPaySale::EndViborProject(void)
{


		IdProject=glStrToInt64(SpisokProject->DM->TableID_SPROJECT->AsString);
		NameProjectcxButtonEdit->Text=SpisokProject->DM->TableNAME_SPROJECT->AsString;


}
//----------------------------------------------------------------------------
void TFormaReportOCBPaySale::OpenFormSpiskaSprBusinessOper(void)
{

if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=ER_ViborBusinessOper;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TFormaReportOCBPaySale::EndViborBusinessOper(void)
{


		IdBusinessOper=glStrToInt64(SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString);
		NameBusinessOpercxButtonEdit->Text=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;


}
//----------------------------------------------------------------------------
void __fastcall TFormaReportOCBPaySale::NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
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
		IdBusinessOper=0;
		NameBusinessOpercxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBPaySale::NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender,
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
		IdProject=0;
		NameProjectcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

