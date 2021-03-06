//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_DMDocPrihNakl.h"
#include "IDMDocPrihNakl.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
//#include "UDMXTableIsm.h"
#include "IDMSprNacenka.h"
#include "IDMSprNom.h"
#include "IDMTableNumberDoc.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_DMDocPrihNakl::TREM_DMDocPrihNakl(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
IsmPrice=false;
IsmSum=true;
Prosmotr=false;
SkladRozn=false;
}
//---------------------------------------------------------------------------

bool TREM_DMDocPrihNakl::Init(void)
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
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;
IBTrDvReg->DefaultDatabase=DM_Connection->pFIBData;

DocAll->Database=DM_Connection->pFIBData;
Doc->Database=DM_Connection->pFIBData;
DocT->Database=DM_Connection->pFIBData;
NumDoc->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;
QueryCancelDvReg->Database=DM_Connection->pFIBData;
QueryDvReg->Database=DM_Connection->pFIBData;

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
int TREM_DMDocPrihNakl::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMDocPrihNakl::DataModuleDestroy(TObject *Sender)
{


DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;
NumDoc->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TREM_DMDocPrihNakl::NewDoc(void)
{
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->Active=true;
Doc->Active=true;
DocT->Active=true;

DocAll->Append();
Doc->Append();

IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);

//������� ����� ���������
NumDoc->Active=false;
IDMTableNumberDoc * dm_num;
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableNumberDoc.1",IID_IDMTableNumberDoc,
													(void**)&dm_num);
dm_num->Init(InterfaceMainObject,0);
NumDoc->ParamByName("PARAM_POS")->AsDateTime=dm_num->GetPosNachNumDoc("REMPRN");
NumDoc->Open();
DocAllNUM_REM_GALLDOC->AsInteger=
				NumDoc->FieldByName("MAXNUMBER")->AsInteger+1;
dm_num->kanRelease();
NumDoc->Active=false;

DocAllPOS_REM_GALLDOC->AsDateTime=Now();
DocAllTDOC_REM_GALLDOC->AsString="REMPRN";
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllIDUSER_REM_GALLDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
	{
	DocAllIDFIRM_REM_GALLDOC->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
	DocAllNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
	{
	DocAllIDSKLAD_REM_GALLDOC->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
	DocAllNAMESKLAD->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
	}
if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsInt64)!=0)
	{
	DocAllIDBASE_REM_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
	}
DocAll->Post();

Doc->Edit();
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
DMSetup->OpenElement(30);
if (Trim(DMSetup->ElementVALUE_SETUP->AsString)!="")
		{
		if (glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString)!=0)
			{
			DocIDTPRICE_REM_DPRN->AsString=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
			}
		}
else
		{
		if (glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
			{
			DocIDTPRICE_REM_DPRN->AsString=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
			}
		}

DMSetup->OpenElement(31);
if (Trim(DMSetup->ElementVALUE_SETUP->AsString)!="")
		{
		if (glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString)!=0)
			{
			DocIDRTPRICE_REM_DPRN->AsString=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
			}
		}
else
		{
		if( glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString)!=0)
			{
			DocIDRTPRICE_REM_DPRN->AsString=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
			}
		}
DMSetup->kanRelease();

Doc->Post();

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocAllIDSKLAD_REM_GALLDOC->AsString)));
pFIBQ->ExecQuery();
if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladRozn=true;
	}
else
	{
	SkladRozn=false;
	}
}
//---------------------------------------------------------------------------
void TREM_DMDocPrihNakl::CopyDoc(__int64 id_doc)
{
//IDMDocPrihNakl * doc;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl,
//													(void**)&doc);
//doc->Init(InterfaceMainObject,0);
//doc->OpenDoc(id_doc);
//NewDoc();
//DocAll->Edit();
//DocAllIDBASE_GALLDOC->AsString=doc->DocAllIDBASE_GALLDOC->AsString;
//DocAllNAME_SINFBASE_OBMEN->AsString=doc->DocAllNAME_SINFBASE_OBMEN->AsString;
//DocAllIDFIRMDOC->AsString=doc->DocAllIDFIRMDOC->AsString;
//DocAllNAMEFIRM->AsString=doc->DocAllNAMEFIRM->AsString;
//DocAllIDSKLDOC->AsString=doc->DocAllIDSKLDOC->AsString;
//DocAllNAMESKLAD->AsString=doc->DocAllNAMESKLAD->AsString;
//DocAllIDKLDOC->AsString=doc->DocAllIDKLDOC->AsString;
//DocAllNAMEKLIENT->AsString=doc->DocAllNAMEKLIENT->AsString;
//DocAll->Post();
//
//Doc->Edit();
//DocIDRTPRICE_DPRN->AsString=doc->DocIDRTPRICE_DPRN->AsString;
//DocIDTPRICE->AsString=doc->DocIDTPRICE->AsString;
//Doc->Post();
//
//doc->DocT->First();
//while (!doc->DocT->Eof)
//	{
//	DocT->Append();
//	DocT->Edit();
//	DocTIDNOMPRNT->AsString=doc->DocTIDNOMPRNT->AsString;
//	DocTNAMENOM->AsString=doc->DocTNAMENOM->AsString;
//	DocTIDEDPRNT->AsString=doc->DocTIDEDPRNT->AsString;
//	DocTNAMEED->AsString=doc->DocTNAMEED->AsString;
//	DocTKFPRNT->AsFloat=doc->DocTKFPRNT->AsFloat;
//	DocTKOLPRNT->AsFloat=doc->DocTKOLPRNT->AsFloat;
//	DocTNAC_DPRNT->AsFloat=doc->DocTNAC_DPRNT->AsFloat;
//	DocTPRICEPRNT->AsFloat=doc->DocTPRICEPRNT->AsFloat;
//	DocTRPRICE_DPRNT->AsFloat=doc->DocTRPRICE_DPRNT->AsFloat;
//    DocTTNOM->AsInteger=doc->DocTTNOM->AsInteger;
//	DocT->Post();
//	doc->DocT->Next();
//    }
//doc->kanRelease();
}
//---------------------------------------------------------------------------
void TREM_DMDocPrihNakl::OpenDoc(__int64 id)
{
IdDoc=id;
DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

DocAll->ParamByName("PARAM_ID")->AsInt64=IdDoc;
Doc->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
DocAll->Active=true;
Doc->Active=true;


DocT->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
//DocT->ParamByName("PARAM_ID_TYPE_PRICE")->AsInt64=DocIDTPRICE->AsInt64;
DocT->Active=true;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_REM_GALLDOC->ReadOnly=true;


pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocAllIDSKLAD_REM_GALLDOC->AsString)));
pFIBQ->ExecQuery();
if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladRozn=true;
	}
else
	{
	SkladRozn=false;
	}


}
//-----------------------------------------------------------------------------
void TREM_DMDocPrihNakl::AddDocNewString()
{
DocT->Append();
//DocT->FieldByName("IDDOCPRNT")->AsInteger=DocAll->FieldByName("IDDOC")->AsInteger;
//DocT->Post();

//DocIDTPRICE->ReadOnly=true;
}
//---------------------------------------------------------------------------
void TREM_DMDocPrihNakl::DeleteStringDoc(void)
{
DocT->Delete();
//if (DocT->RecordCount==0)
//        {
//        DocIDTPRICE->ReadOnly=false;
//        }
}
//---------------------------------------------------------------------------
bool TREM_DMDocPrihNakl::SaveDoc(void)
{
bool Res=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
        {
        TextError="������� ��������� ������ ������� ������� ��������������!";
        return Res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GALLDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="������ ������������� ����� ���������!";
		return Res;
		}
	}

Summa();
DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=SummaDoc;
DocAll->Post();

//���������� ��������� ��������
try
        {
		IdDoc=glStrToInt64(DocAllID_REM_GALLDOC->AsString);
		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		DocT->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();
		DocT->CommitUpdToCach();
        Res=true;
        OpenDoc(IdDoc);
        }
catch(Exception &exception)
				{
			  	IBTrUpdate->Rollback();
				Res=false;
				TextError=exception.Message;
				}

return Res;
}


//---------------------------------------------------------------------------
bool TREM_DMDocPrihNakl::DvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
		TextError="������� ��������� ������ ������� ������� ��������������!";
		return result;
		}


try
        {
        if (CancelDvRegDoc()==true)
                {
				QueryDvReg->Close();
				QueryDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
				QueryDvReg->ExecProc();
				IBTrDvReg->Commit();

                result=true;
                }
        }
catch(Exception &exception)
				{
				IBTrDvReg->Rollback();
				result=false;
				TextError=exception.Message;
				}


QueryDvReg->Close();
return result;
}

//---------------------------------------------------------------------------
bool TREM_DMDocPrihNakl::CancelDvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
		{
		TextError="������� ��������� ������ ������� ������� ��������������!";
		return result;
		}
try
		{
				QueryCancelDvReg->Close();
				QueryCancelDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
				QueryCancelDvReg->ExecProc();
				IBTrDvReg->Commit();

				result=true;

		}
catch(Exception &exception)
				{
				IBTrDvReg->Rollback();
				result=false;
				TextError=exception.Message;
				}
				
QueryCancelDvReg->Close();
return result;
}
//---------------------------------------------------------------------------
double TREM_DMDocPrihNakl::Summa()
{
DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;
double SumRozn=0;
BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
		{
		SummaDoc=SummaDoc+DocTSUM_REM_DPRNT->AsFloat;
		SumRozn=SumRozn+DocTRSUM_REM_DPRNT->AsFloat;
		DocT->Next();
		}
DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

Doc->Edit();
DocRSUM_REM_DPRN->AsFloat=SumRozn;
Doc->Post();

return SummaDoc;
}


//---------------------------------------------------------------------------


bool TREM_DMDocPrihNakl::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);

if (Prosmotr==true)
		{
        TextError="������� ��������� ������ ������� ������� ��������������!";
        return res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSER_REM_GALLDOC->AsString)
	{
	if (DM_Connection->UserInfoDEL_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="������ ������� ����� ���������!";
		return res;
		}
	}

try
        {
        if (CancelDvRegDoc()!=true)
                {
                res=false;
                return res;
                }

        DocT->First();
        while(!DocT->Eof)
                {
                //ShowMessage(IntToStr(DocT->RecNo));
                DocT->Delete();
                }

        Doc->Delete();
        DocAll->Delete();

        DocT->ApplyUpdates();
        Doc->ApplyUpdates();
        DocAll->ApplyUpdates();
		IBTrUpdate->Commit();
        res=true;
        }
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				res=false;
				TextError=exception.Message;
				}
return res;

}
//---------------------------------------------------------------------------

__int64 TREM_DMDocPrihNakl::GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)
{
__int64 res=0;


return res;
}
//---------------------------------------------------------------------------




void __fastcall TREM_DMDocPrihNakl::DocTAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;
NewRSummaStr=0;

DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

Doc->Edit();
DocRSUM_REM_DPRN->AsFloat=DocRSUM_REM_DPRN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPrihNakl::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_REM_DPRNT->AsFloat;
OldRSummaStr=DocTRSUM_REM_DPRNT->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPrihNakl::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_REM_DPRNT->AsString=DocAllID_REM_GALLDOC->AsString;

	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		DocTIDBASE_REM_DPRNT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		}

}
//---------------------------------------------------------------------------


void __fastcall TREM_DMDocPrihNakl::DocTCalcFields(TDataSet *DataSet)
{
DocTRECNO->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------


void __fastcall TREM_DMDocPrihNakl::DocNewRecord(TDataSet *DataSet)
{
DocIDDOC_REM_DPRN->AsString=DocAllID_REM_GALLDOC->AsString;
if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
	{
	DocIDBASE_REM_DPRN->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
	} 
}
//---------------------------------------------------------------------------




void __fastcall TREM_DMDocPrihNakl::DocAllPOS_REM_GALLDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
Prosmotr=DMSetup->ProveritPosZapretaRedRemont(DocAllPOS_REM_GALLDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPrihNakl::DocTKOL_REM_DPRNTChange(TField *Sender)
{
if (IsmSum==true)
		{
OldSummaStr=DocTSUM_REM_DPRNT->AsFloat;

DocTSUM_REM_DPRNT->AsFloat=NewSummaStr=DocTKOL_REM_DPRNT->AsFloat*DocTPRICE_REM_DPRNT->AsFloat;
DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();

		}

OldRSummaStr=DocTRSUM_REM_DPRNT->AsFloat;

DocTRSUM_REM_DPRNT->AsFloat=NewRSummaStr=DocTKOL_REM_DPRNT->AsFloat*DocTRPRICE_REM_DPRNT->AsFloat;
Doc->Edit();
DocRSUM_REM_DPRN->AsFloat=DocRSUM_REM_DPRN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPrihNakl::DocTPRICE_REM_DPRNTChange(TField *Sender)
{
if (IsmSum==true)
		{
OldSummaStr=DocTSUM_REM_DPRNT->AsFloat;

DocTSUM_REM_DPRNT->AsFloat=NewSummaStr=DocTKOL_REM_DPRNT->AsFloat*DocTPRICE_REM_DPRNT->AsFloat;
DocAll->Edit();
DocAllSUM_REM_GALLDOC->AsFloat=DocAllSUM_REM_GALLDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPrihNakl::DocAllIDSKLAD_REM_GALLDOCChange(TField *Sender)

{
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(DocAllIDSKLAD_REM_GALLDOC->AsString)));
pFIBQ->ExecQuery();
if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladRozn=true;
	}
else
	{
	SkladRozn=false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPrihNakl::DocTRPRICE_REM_DPRNTChange(TField *Sender)
{
OldRSummaStr=DocTRSUM_REM_DPRNT->AsFloat;

DocTRSUM_REM_DPRNT->AsFloat=NewRSummaStr=DocTKOL_REM_DPRNT->AsFloat*DocTRPRICE_REM_DPRNT->AsFloat;
Doc->Edit();
DocRSUM_REM_DPRN->AsFloat=DocRSUM_REM_DPRN->AsFloat-OldRSummaStr+NewRSummaStr;
Doc->Post();
}
//---------------------------------------------------------------------------



void __fastcall TREM_DMDocPrihNakl::DocAllIDBASE_REM_GALLDOCChange(TField *Sender)

{
 	if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
		{
		Doc->Edit();
		DocIDBASE_REM_DPRN->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
		Doc->Post();
		}


	DocT->First();
	while (!DocT->Eof)
		{
		if (glStrToInt64(DocAllIDBASE_REM_GALLDOC->AsString)!=0)
			{
			DocT->Edit();
			DocTIDBASE_REM_DPRNT->AsString=DocAllIDBASE_REM_GALLDOC->AsString;
			DocT->Post();
			}
		DocT->Next();
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPrihNakl::DocTNAME_REM_CQUERYGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
Text=DocTNUM_REM_CQUERY->AsString+" �� "+DocTPOS_REM_CQUERY->AsString+
	" "+DocTKLIENT_NAME_REM_CQUERY->AsString+
	" "+DocTNAME_MODEL_REM_CQUERY->AsString+
	" "+DocTNUM_STR_ZAK_POST_REM_CQUERY->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMDocPrihNakl::DocTNAME_REM_ZGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
Text=DocTPREFIKS_NUM_REM_Z->AsString+DocTNUM_REM_Z->AsString+
			" �� "+DocTPOS_REM_Z->AsString+
			" "+DocTMODEL_REM_Z->AsString+
			" �"+DocTSERNUM_REM_Z->AsString+
			" 2�"+DocTSERNUM2_REM_Z->AsString+
			" SO "+DocTSTR_CODE_VIGR_REM_Z_1->AsString;
}
//---------------------------------------------------------------------------

