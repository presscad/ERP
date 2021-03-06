//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMDocRKO.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMDocRKO::TDMDocRKO(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}

//----------------------------------------------------------------------------
void __fastcall TDMDocRKO::DataModuleCreate(TObject *Sender)
{
flGetNumberDoc=true;
}
//---------------------------------------------------------------------------
bool TDMDocRKO::Init(void)
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
//---------------------------------------------------------------------------
int TDMDocRKO::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRKO::DataModuleDestroy(TObject *Sender)
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
void TDMDocRKO::NewDoc(void)
{

flGetNumberDoc=false;

DocAll->Open();
Doc->Open();
DocAll->Insert();
Doc->Insert();

IdDoc=DocAllIDDOC->AsInt64;
DocIDDOCRKO->AsInt64=IdDoc;
DocADDKDRRKO->AsInteger=1;
DocOPERATIONRKO->AsInteger=1;
Doc->Post();

DocAllPOSDOC->AsDateTime=Now();
DocAllTDOC->AsString="RKO";
if(DM_Connection->UserInfoID_USER->AsInt64!=0)
	{
	DocAllIDUSERDOC->AsInt64=DM_Connection->UserInfoID_USER->AsInt64;
	DocAllFNAME_USER->AsString=DM_Connection->UserInfoFNAME_USER->AsString;
	}
if (DM_Connection->UserInfoIDBASE_SUSER->AsInt64!=0)
	{
	DocAllIDBASE_GALLDOC->AsInt64=DM_Connection->UserInfoIDBASE_SUSER->AsInt64;
	DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
	}

DocAll->Post();

flGetNumberDoc=true;
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//----------------------------------------------------------------------------
int TDMDocRKO::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;
//������� ����� ���������
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=DocAllIDBASE_GALLDOC->AsString;
NumDoc->ParamByName("PARAM_IDFIRM")->AsString=DocAllIDFIRMDOC->AsString;
NumDoc->ParamByName("PARAM_IDKASSA")->AsString=DocIDKKMRKO->AsString;

NumDoc->Open();
DocAllPREFIKS_NUM_GALLDOC->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
DocAllNUMDOC->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
NumDoc->Close();
result=DocAllNUMDOC->AsInteger;
return result;
}
//----------------------------------------------------------------------------
void TDMDocRKO::OpenDoc(__int64 Id)
{

DocAll->Active=false;
Doc->Active=false;


DocAll->ParamByName("ID")->AsInt64=Id;
Doc->ParamByName("ID")->AsInt64=Id;

DocAll->Open();
Doc->Open();



IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

DocAllIDBASE_GALLDOC->ReadOnly=true;
IdDoc=DocAllIDDOC->AsInt64;
}

//----------------------------------------------------------------------------
void TDMDocRKO::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
}
//----------------------------------------------------------------------------
bool TDMDocRKO::SaveDoc(void)
{
bool result=false;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();

if (Prosmotr==true)
		{
        TextError="������� ��������� ������ ������� ������� ��������������!";
        return result;
		}

if (DM_Connection->UserInfoID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		TextError="������ ������������� ����� ���������!";
		return result;
		}
	}

try
        {
//        if (CancelDvRegDoc()==true)
//                {
				IdDoc=DocAllIDDOC->AsInt64;
		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();

                OpenDoc(IdDoc);
                result=true;
//                }
        }
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				result=false;
				TextError=exception.Message;
				}
return result;
}
//----------------------------------------------------------------------------
bool TDMDocRKO::DvRegDoc(void)
{
bool result=false;

if (Prosmotr==true)
		{
		TextError="������� ��������� ������ ������� ������� ��������������!";
		return result;
		}

//try
//        {
//		if (CancelDvRegDoc()==true)
//                {
//                if (DocOPERATIONRKO->AsInteger==1)    //� �������������
//						{
//                        //�� �������� �������������
//                        IdDoc=DocAllIDDOC->AsInteger;
//						DMRegVsRasch->IdDoc=IdDoc;
//                        DMRegVsRasch->PosDoc=DocAllPOSDOC->AsDateTime;
//                        DMRegVsRasch->IdFirm=DocAllIDFIRMDOC->AsInteger;
//						DMRegVsRasch->IdKlient=DocAllIDKLDOC->AsInteger;
//                        DMRegVsRasch->Sum=DocAllSUMDOC->AsFloat;
//                        DMRegVsRasch->AddRecordPrihod();
//						}
//                //�� �������� �����
//                DMRegKassa->IdDoc=DocAllIDDOC->AsInteger;
//				DMRegKassa->PosDoc=DocAllPOSDOC->AsDateTime;
//                DMRegKassa->IdFirm=DocAllIDFIRMDOC->AsInteger;
//                DMRegKassa->IdKKM=DocIDKKMRKO->AsInteger;
//				DMRegKassa->Operation =DocOPERATIONRKO->AsInteger;
//				DMRegKassa->Sum=DocAllSUMDOC->AsFloat;
//                DMRegKassa->AddRecordRashod();
//
//				Doc2->Active=false;
//				Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//                Doc2->Active=true;
//                Doc2->Edit();
//				Doc2PRDOC->AsInteger=1;
//				Doc2->Post();
//                IBTrDvReg->Commit();
//
//       TDMSetup * DMSetup=new TDMSetup(Application);
//	   DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//	   delete DMSetup;
//
//                result=true;
//				}
//		}
//
//catch(Exception &exception)
//				{
//				IBTrDvReg->Rollback();
//				result=false;
//				TextError=exception.Message;
//				Error=true;
//				}
//return result;

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
//-----------------------------------------------------------------------------
bool TDMDocRKO::CancelDvRegDoc(void)
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
//
//		DMRegKassa->IdDoc=DocAllIDDOC->AsInteger;
//
//		if (DMRegVsRasch->CancelDvReg()==true &&
//                                        DMRegKassa->CancelDvReg()==true)
//				{
//                Doc2->Active=false;
//				Doc2->ParamByName("ID")->AsInteger=DocAllIDDOC->AsInteger;
//				Doc2->Active=true;
//				Doc2->Edit();
//				Doc2PRDOC->AsInteger=0;
//				Doc2->Post();
//				IBTrDvReg->Commit();
//
//       TDMSetup * DMSetup=new TDMSetup(Application);
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






//---------------------------------------------------------------------------
bool TDMDocRKO::DeleteDoc(__int64 id)
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


void __fastcall TDMDocRKO::DocAllPOSDOCChange(TField *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceOwnerObject);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
DMSetup->kanRelease();
}
//---------------------------------------------------------------------------



void __fastcall TDMDocRKO::DocNewRecord(TDataSet *DataSet)
{
DocIDDOCRKO->AsString=DocAllIDDOC->AsString;
if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	DocIDBASE_DRKO->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRKO::DocAllIDBASE_GALLDOCChange(TField *Sender)
{
if (DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	Doc->Edit();
	DocIDBASE_DRKO->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	Doc->Post();
	}

GetNumberNewDoc();
}
//---------------------------------------------------------------------------


void __fastcall TDMDocRKO::DocIDKKMRKOChange(TField *Sender)
{
DocAll->Edit();
GetNumberNewDoc();
DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRKO::DocAllIDFIRMDOCChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

