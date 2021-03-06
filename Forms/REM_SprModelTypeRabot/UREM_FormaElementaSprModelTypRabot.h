//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprModelTypRabotH
#define UREM_FormaElementaSprModelTypRabotH
//---------------------------------------------------------------------------
#include "IREM_FormaSpiskaSprTypRabot.h"
#include "IREM_DMSprModelTypRabot.h"
#include "UDM.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxImageComboBox.hpp"
#include "cxLookAndFeels.hpp"
#include "cxDBRichEdit.hpp"
#include "cxMemo.hpp"
#include "cxRichEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxCheckBox.hpp"
//---------------------------------------------------------------------------
class TREM_FormaElementaSprModelTypRabot : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBButtonEdit *cxDBButtonEditNAME_REM_STYPRABOT;
	TLabel *Label1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall cxDBButtonEditNAME_REM_STYPRABOTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

	IREM_FormaSpiskaSprTypRabot * REM_FormaSpiskaSprTypRabot;

	void OpenFormaSpiskaSprTypRabot(void);
	void  EndViborTypRabot(void);



	enum  {ER_NoRekv, ER_ViborTypRabot} ER_Rekvisit;


public:		// User declarations
		__fastcall TREM_FormaElementaSprModelTypRabot(TComponent* Owner);

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
		IREM_DMSprModelTypRabot * DM;
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

	   void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprModelTypRabot *REM_FormaElementaSprModelTypRabot;
//---------------------------------------------------------------------------
#endif
