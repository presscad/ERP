//---------------------------------------------------------------------------

#ifndef UFormaElementaSprAddressRegionH
#define UFormaElementaSprAddressRegionH
//---------------------------------------------------------------------------
#include "IDMSprAddressRegion.h"
#include "UDM.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprAddressRegion : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TDBText *DBTextID_SADR_REGION;
	TLabel *Label3;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *cxDBTextEditNAME_SADR_REGION;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBTextEdit *cxDBTextEditCODE_SADR_REGION;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DatecxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall cxDBTextEditNAME_SADR_REGIONKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
public:		// User declarations
		__fastcall TFormaElementaSprAddressRegion(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������

		//�� ���� ����� ������� ������ ��� ������
		//��������� ������� ������ � ������ ����� (������� ���� ������� �� ���� ��� ������ ����-��)
		int ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������ (����� � ������� ������������ �����)
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									);


		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//������� ���������
		IDMSprAddressRegion * DM;
		void UpdateForm(void);
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprAddressRegion *FormaElementaSprAddressRegion;
//---------------------------------------------------------------------------
#endif
