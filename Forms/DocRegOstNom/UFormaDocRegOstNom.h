//---------------------------------------------------------------------------

#ifndef UFormaDocRegOstNomH
#define UFormaDocRegOstNomH
//---------------------------------------------------------------------------
#include "USheetEditor.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprPart.h"
#include "IDMDocRegOstNom.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <IBDatabase.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalc.hpp"
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxDBLabel.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocRegOstNom : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1TDV_DRG_OSTNOMT;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_DRG_OSTNOMT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_DRG_OSTNOMT;
	TcxGridDBColumn *cxGrid1DBTableView1OPER_DRG_OSTNOMT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEFIRM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMESKLAD;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1DOCPART;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
 //       void __fastcall AddNewStringClick(TObject *Sender);
 //       void __fastcall DeleteStringClick(TObject *Sender);
        void __fastcall NumberDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FDateDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall PrimKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionAddStringExecute(TObject *Sender);
	void __fastcall ActionDeleteStringExecute(TObject *Sender);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall cxGrid1DBTableView1NAMEFIRMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMESKLADPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1DOCPARTPropertiesButtonClick(
		  TObject *Sender, int AButtonIndex);

		  			//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
	//������� ����� � �������
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);
	
		//����� �������������� ����
		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void ViborInfBase(void);
		void __fastcall EndViborInfBase(void);

		//����� �����
		IFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		void ViborFirm(void);
		void __fastcall EndViborFirm(void);

		//����� ������
		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		void ViborSklad(void);
		void __fastcall EndViborSklad(void);

		//����� ������������
		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		void ViborNom(void);
		void __fastcall EndViborNom(void);

		//����� ������
		IFormaSpiskaSprPart * FormaSpiskaSprPart;
		void ViborPart(void);
		void __fastcall EndViborPart(void);

		 enum  {aoNO,aoAddNewString} ActionOperation;

        
		 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;

        void OpenPrintForm(void);
		void OutputString(TSheetEditor *prForm);
		void OutputZagolovokReport(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;

		void BeforeSaveDoc(void);

	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);

		enum  {ER_NoRekv,ER_InfBase, ER_Firm, ER_BankSchet, ER_Sklad, ER_Klient, ER_Dogovor, ER_Kassa,
					 ER_BusinessOper, ER_Project, ER_Nom,
					  ER_Ed,ER_Part,ER_NO} EditRekvisit;
public:		// User declarations
		__fastcall TFormaDocRegOstNom(TComponent* Owner);

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
		IDMDocRegOstNom * DM;


		bool Prosmotr;    //������ ��������

		__int64 IdDoc;           //������������� ������� ������


		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


		void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocRegOstNom *FormaDocRegOstNom;
//---------------------------------------------------------------------------
#endif
