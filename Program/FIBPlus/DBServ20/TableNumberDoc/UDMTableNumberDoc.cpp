//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMTableNumberDoc.h"
#include "UDM.h"
#include "DateUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
extern AnsiString glStringFullTypeDoc;
//---------------------------------------------------------------------------
__fastcall TDMTableNumberDoc::TDMTableNumberDoc(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMTableNumberDoc::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
}

//---------------------------------------------------------------------------

void  TDMTableNumberDoc::OpenTable(void)
{

Table->Active=false;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMTableNumberDoc::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenTable();
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------

void  TDMTableNumberDoc::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
		//IBTrUpdate->Commit();
        OpenTable();
        }
		catch(Exception &exception)
				{
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------

void  TDMTableNumberDoc::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMTableNumberDoc::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;
int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

void  TDMTableNumberDoc::SaveElement()
{
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        }
catch(...)
        {
        Error=true;
        TextError="�� ������� �������� �������!";
        }
}
//---------------------------------------------------------------------------
void TDMTableNumberDoc::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
                }
        catch(...)
                {
                Error=true;
                TextError="�� ������� ������� �������!";
                }
        }
}
//---------------------------------------------------------------------------



void __fastcall TDMTableNumberDoc::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMTableNumberDoc::TableTYPE_TNUM_DOCGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
if (TableTYPE_TNUM_DOC->AsInteger==0)
		{
		Text="�� �����";
		}
if (TableTYPE_TNUM_DOC->AsInteger==1)
		{
		Text="� ������ ����";
		}
if (TableTYPE_TNUM_DOC->AsInteger==2)
		{
		Text="� ������ ��������";
		}
if (TableTYPE_TNUM_DOC->AsInteger==3)
		{
		Text="� ������ ������";
		}
if (TableTYPE_TNUM_DOC->AsInteger==4)
		{
		Text="� ������ ���";
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMTableNumberDoc::TableTYPE_TNUM_DOCSetText(TField *Sender,
      const AnsiString Text)
{
if(Text=="�� �����")
		{
		TableTYPE_TNUM_DOC->AsInteger=0;
		}
if(Text=="� ������ ����")
		{
		TableTYPE_TNUM_DOC->AsInteger=1;
		}
if(Text=="� ������ ��������")
		{
		TableTYPE_TNUM_DOC->AsInteger=2;
		}
if(Text=="� ������ ������")
		{
		TableTYPE_TNUM_DOC->AsInteger=3;
		}
if(Text=="� ������ ���")
		{
		TableTYPE_TNUM_DOC->AsInteger=4;
		}
}
//----------------------------------------------------------------------------
TDateTime TDMTableNumberDoc::GetPosNachNumDoc(AnsiString type_doc)
{
TDateTime result=0;
int type_num=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select TYPE_TNUM_DOC from TNUM_DOC where DOC_TNUM_DOC='"+type_doc+"'");
Query->ExecQuery();
type_num=Query->FieldByName("TYPE_TNUM_DOC")->AsInteger;
Query->Close();


switch (type_num)
	{
	case 0:  //�� �����
		{
		result=0;
		}break;
	case 1:  //������ ����
		{
		result=EncodeDate(YearOf(Date()),1,1);
		}break;
	case 2:   //������ ��������
		{
		if (EncodeDate(YearOf(Date()),1,1)< Date() && Date()< EncodeDate(YearOf(Date()),4,1))
			{
			result=EncodeDate(YearOf(Date()),1,1);
			}
		if (EncodeDate(YearOf(Date()),4,1)< Date() && Date()< EncodeDate(YearOf(Date()),7,1))
			{
			result=EncodeDate(YearOf(Date()),4,1);
			}
		if (EncodeDate(YearOf(Date()),7,1)< Date() && Date()< EncodeDate(YearOf(Date()),10,1))
			{
			result=EncodeDate(YearOf(Date()),7,1);
			}
		if (EncodeDate(YearOf(Date()),10,1)< Date() && Date()< EncodeDate(YearOf(Date())+1,1,1))
			{
			result=EncodeDate(YearOf(Date()),7,1);
			}

		}break;
	case 3:   //������ ������
		{
        result=Date()-DayOf(Date())+1;
		}break;
	case 4:  //������ ���
		{
        result=Date();
		}break;
	}

return result;



}
//----------------------------------------------------------------------------
