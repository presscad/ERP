//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprGrpNom.h"
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
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprGrpNom::TDMSprGrpNom(TComponent* Owner)
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
bool TDMSprGrpNom::Init(void)
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

Table->Database=DM_Connection->pFIBData;
Element->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprGrpNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprGrpNom::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TDMSprGrpNom::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprGrpNom::NewElement(__int64 IdGrp)
{
Element->Active=false;
Element->Open();
Element->Insert();
if (IdGrp!=0)
        {
		ElementIDGRPGN->AsInt64=IdGrp;
		Element->Post();
        }
}
//---------------------------------------------------------------------------

int TDMSprGrpNom::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprGrpNom::SaveElement()
{
bool result=false;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		result=true;
        }
catch(Exception &exception)
        {
		//		IBTrUpdate->Rollback();
				TextError=exception.Message;
				result=false;
				//ShowMessage(TextError);
		}
return result;
}
//---------------------------------------------------------------------------
bool TDMSprGrpNom::DeleteElement(__int64 Id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
				result=true;
                }
        catch(Exception &exception)
                {
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				result=false;
                }
		}
return result;
}
//-----------------------------------------------------------------
__int64 TDMSprGrpNom::GetIDElement(String gid)
{
__int64 res=0;

if (gid!="" || gid!=" " )
		{
			pFIBQ->Close();
			pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select IDGN from SGRPNOM where GID_SGRPNOM=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
						{
						res=pFIBQ->FieldByName("IDGN")->AsInt64;
						}
				else res=0;
			pFIBQ->Close();
	}
return res;
}
//-----------------------------------------------------------------
AnsiString TDMSprGrpNom::GetGIDElement(__int64 id)
{
AnsiString result="";

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select GID_SGRPNOM  from SGRPNOM where IDGN=:PARAM_ID");
pFIBQ->ParamByName("PARAM_ID")->AsString=id;
pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
						{
						result=pFIBQ->FieldByName("GID_SGRPNOM")->AsString;
						}
				else result="";
pFIBQ->Close();

return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprGrpNom::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
__int64 TDMSprGrpNom::FindPoName(AnsiString name)
{
__int64 result=0;

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select IDGN from SGRPNOM where NAMEGN=:PARAM_NAME");
pFIBQ->ParamByName("PARAM_NAME")->AsString=Trim(name);
pFIBQ->ExecQuery();
result=glStrToInt64(pFIBQ->FieldByName("IDGN")->AsString);
pFIBQ->Close();

return result;
}
//---------------------------------------------------------------------------

