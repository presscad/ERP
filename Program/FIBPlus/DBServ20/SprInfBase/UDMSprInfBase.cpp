//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprInfBase.h"
#include "UDM.h"
//#include "UDMXTableIsm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
//---------------------------------------------------------------------------
__fastcall TDMSprInfBase::TDMSprInfBase(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprInfBase::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
BaseForObmen->Active=false;        
}
//---------------------------------------------------------------------------
void  TDMSprInfBase::OpenTable(void)
{

Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprInfBase::NewElement(void)
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMSprInfBase::OpenElement(__int64 id)
{
Id=id;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

//BaseForObmen->Active=false;
//BaseForObmen->ParamByName("PARAM_IDBASE")->AsInt64=id;
//BaseForObmen->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprInfBase::SaveElement()
{
bool result=false;
Id=ElementID_SINFBASE_OBMEN->AsInt64;
try
        {
		Element->ApplyUpdates();
//		BaseForObmen->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(Id);
		result=true;
        }
catch(Exception &exception)
        {
        Error=true;
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
void TDMSprInfBase::DeleteElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
                }
		catch(Exception &exception)
                {

                IBTr->Rollback();
				Error=true;
				TextError=exception.Message;
                }
        }
}
//---------------------------------------------------------------------------
__int64 TDMSprInfBase::GetIdPoPrefiks(AnsiString prefiks)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select ID_SINFBASE_OBMEN from SINFBASE_OBMEN ");
		pFIBQ->SQL->Add(" where PREFIKS_SINFBASE_OBMEN='"+Trim(prefiks)+"'");
		pFIBQ->ExecQuery();
		result=pFIBQ->FieldByName("ID_SINFBASE_OBMEN")->AsInt64;
pFIBQ->Close();
return result;
}
//----------------------------------------------------------------------------

void __fastcall TDMSprInfBase::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprInfBase::ElementNewRecord(TDataSet *DataSet)
{

//TDMXTableIsm * DMXTableIsm=new TDMXTableIsm(Application);
//ElementIDTIZM_SINFBASE_OBMEN->AsInteger=DMXTableIsm->GetMaxID();
//delete DMXTableIsm;
	
}
//---------------------------------------------------------------------------
__int64 TDMSprInfBase::GetIdPoName(AnsiString name)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ID_SINFBASE_OBMEN from SINFBASE_OBMEN ");
pFIBQ->SQL->Add(" where NAME_SINFBASE_OBMEN='"+Trim(name)+"'");
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("ID_SINFBASE_OBMEN")->AsInt64;
pFIBQ->Close();
return result;
}
//----------------------------------------------------------------------------
