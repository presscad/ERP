//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocPlP.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"

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
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TDMDocPLP::TDMDocPLP(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//-----------------------------------------------------------------
void __fastcall TDMDocPLP::DataModuleCreate(TObject *Sender)
{
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------

bool TDMDocPLP::Init(void)
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
NumDoc->Database=DM_Connection->pFIBData;

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
//----------------------------------------------------------------------------
int TDMDocPLP::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMDocPLP::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
NumDoc->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TDMDocPLP::NewDoc(void)
{
flGetNumberDoc=false;

DocAll->Open();
Doc->Open();
DocAll->Append();
Doc->Append();


DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="PLP";
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0)
	{
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	DocAllIDUSERDOC->AsString=DM_Connection->UserInfoID_USER->AsString;
	}
if(glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
	{
	DocAllIDBASE_GALLDOC->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
	}
DocAll->Post();

IdDoc=glStrToInt64(DocAllIDDOC->AsString);
Doc->Edit();
DocIDDOCPLP->AsString=IdDoc;
DocOCHPLP->AsInteger=5;
DocVIDPLP->AsInteger=0;
DocSROKPLP->AsVariant=Date();
DocADDKDRPLP->AsInteger=1;
DocOPERATIONPLP->AsInteger=1;
DocNALOG_DATE_PLP->AsDateTime=Now();
Doc->Post();

flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//----------------------------------------------------------------------------
int TDMDocPLP::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;
//������� ����� ���������
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_GALLDOC->AsString;
NumDoc->ParamByName("PARAM_IDFIRM")->AsString=DocAllIDFIRMDOC->AsString;
NumDoc->ParamByName("PARAM_IDBSCHET")->AsString=DocIDBSCHPLP->AsString;

NumDoc->Open();
DocAllPREFIKS_NUM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
DocAllNUMDOC->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
NumDoc->Close();
result=DocAllNUMDOC->AsInteger;
return result;
}
//----------------------------------------------------------------------------
void TDMDocPLP::OpenDoc(__int64 id)
{

DocAll->Close();
Doc->Close();
NumDoc->Close();


DocAll->ParamByName("ID")->AsInt64=id;
Doc->ParamByName("ID")->AsInt64=id;

DocAll->Open();
Doc->Open();


IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_GALLDOC->ReadOnly=true;
IdDoc=glStrToInt64(DocAllIDDOC->AsString);
}

//----------------------------------------------------------------------------
void TDMDocPLP::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
}
//----------------------------------------------------------------------------
bool TDMDocPLP::SaveDoc(void)
{

bool Res=false;
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
		{
        TextError="������� ��������� ������ ������� ������� ��������������!";
        return Res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="������ ������������� ����� ���������!";
		return Res;
		}
	}

try
        {
		IdDoc=glStrToInt64(DocAllIDDOC->AsString);
		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();

        OpenDoc(IdDoc);
        Res=true;
        }
catch(Exception &exception)
				{
			   	IBTrUpdate->Rollback();
				Res=false;
				TextError=exception.Message;
				}
return Res;
}
//----------------------------------------------------------------------------
bool TDMDocPLP::DvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
		TextError="������� ��������� ������ ������� ������� ��������������!";
		return result;
		}
//
//try
//        {
//        if (CancelDvRegDoc()==true)
//                {
//				if(DocOPERATIONPLP->AsInteger==1)
//                        {
//                        //�� �������� �������������
//						IdDoc=DocAllIDDOC->AsInteger;
//						DMRegVsRasch->IdDoc=IdDoc;
//                        DMRegVsRasch->PosDoc=DocAllPOSDOC->AsDateTime;
//                        DMRegVsRasch->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                        DMRegVsRasch->IdKlient=DocAllIDKLDOC->AsInteger;
//						DMRegVsRasch->Sum=DocAllSUMDOC->AsFloat;
//                        DMRegVsRasch->AddRecordPrihod();
//                        }
//                //�� �������� ����
//				DMRegBank->IdDoc=DocAllIDDOC->AsInteger;
//                DMRegBank->PosDoc=DocAllPOSDOC->AsDateTime;
//                DMRegBank->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                DMRegBank->IdBSchet=DocIDBSCHPLP->AsInteger;
//				DMRegBank->Operation =DocOPERATIONPLP->AsInteger;
//                DMRegBank->Sum=DocAllSUMDOC->AsFloat;
//                DMRegBank->AddRecordRashod();
//
//				Doc2->Active=false;
//                Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//                Doc2->Active=true;
//				Doc2->Edit();
//				Doc2PRDOC->AsInteger=1;
//				Doc2->Post();
//
//				IBTrDvReg->Commit();
//
//	   TDMSetup * DMSetup=new TDMSetup(Application);
//	   DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//	   delete DMSetup;
//
//                Res=true;
//				}
//		}
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				Res=false;
//				TextError=exception.Message;
//				Error=true;
//				}
//return Res;


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
bool TDMDocPLP::CancelDvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
		TextError="������� ��������� ������ ������� ������� ��������������!";
		return result;
		}

//try
//        {
//		DMRegVsRasch->IdDoc=DocAllIDDOC->AsInteger;
//		DMRegBank->IdDoc=DocAllIDDOC->AsInteger;
//        if (DMRegVsRasch->CancelDvReg()==true &&
//										DMRegBank->CancelDvReg()==true)
//                {
//                Doc2->Active=false;
//				Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//				Doc2->Active=true;
//				Doc2->Edit();
//				Doc2PRDOC->AsInteger=0;
//				Doc2->Post();
//				IBTrDvReg->Commit();
//
//	   TDMSetup * DMSetup=new TDMSetup(Application);
//	   DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//	   delete DMSetup;
//
//                result=true;
//				}
//		}
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				result=false;
//				TextError=exception.Message;
//				Error=true;
//				}
//
//return result;

try
		{
				QueryCancelDvReg->Close();
				QueryCancelDvReg->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
				QueryCancelDvReg->ExecProc();
				IBTrDvReg->Commit();

//				TDMSetup * DMSetup=new TDMSetup(Application);
//				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//				delete DMSetup;

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
bool TDMDocPLP::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);

if (Prosmotr==true)
        {

        TextError="������� ��������� ������ ������� ������� ��������������!";
        return res;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
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


        Doc->Delete();
        DocAll->Delete();

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
//-----------------------------------------------------------------------------






void __fastcall TDMDocPLP::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocPLP::DocAllSUMDOCChange(TField *Sender)
{
Doc->Edit();
DocSUMUSNPLP->AsFloat=DocAllSUMDOC->AsFloat;
Doc->Post();      	
}
//---------------------------------------------------------------------------


void __fastcall TDMDocPLP::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCPLP->AsString=DocAllIDDOC->AsString;
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	DocIDBASE_DPLP->AsString=DocAllIDBASE_GALLDOC->AsString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPLP::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (glStrToInt64(DocAllIDBASE_GALLDOC->AsString)!=0)
	{
	Doc->Edit();
	DocIDBASE_DPLP->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc->Post();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPLP::DocIDBSCHPLPChange(TField *Sender)
{
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocPLP::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

