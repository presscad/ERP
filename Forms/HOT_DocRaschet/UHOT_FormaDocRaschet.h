//---------------------------------------------------------------------------

#ifndef UHOT_FormaDocRaschetH
#define UHOT_FormaDocRaschetH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDM.h"
#include "IHOT_DMDocRaschet.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprSklad.h"
#include "IHOT_FormaSpiskaSprNF.h"
#include "IHOT_FormaSpiskaSprTypePosel.h"
#include "IHOT_FormaSpiskaSprCatNom.h"
#include "IFormaSpiskaSprBankSchet.h"
#include "IDMTableExtPrintForm.h"
#include "IDMSprTypePrice.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <DBGrids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
#include <ActnList.hpp>
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
#include "cxButtonEdit.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxDBLookupComboBox.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxLabel.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class THOT_FormaDocRaschet : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TLabel *FSummaCheck;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label7;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TDBText *SumDocDBText;
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonPrintNakl;
        TToolButton *ToolButtonPrintAkt;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1TUSL_HOT_DREALT;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_HOT_DREALT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_HOT_DREALT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_HOT_DREALT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_HOT_DREALT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBTextEdit *NumberDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxGridDBColumn *cxGrid1DBTableView1VIBORTYPEPRICE;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TLabel *Label4;
	TcxGridDBBandedTableView *cxGrid1DBBandedTableView1;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1KOL_HOT_DRASCHETT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1KF_HOT_DRASCHETT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1PRICE_HOT_DRASCHETT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMENOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMEED;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_TPRICE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_HOT_SNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_HOT_SCATNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_HOT_STYPEPOS;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMEKLIENT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RECNO;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1SUM_HOT_DRASCHETT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1POSNACH_HOT_DRASCHETT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1POSCON_HOT_DRASCHETT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1TUSL_HOT_DRASCHETT;
	TcxDBButtonEdit *NameBSchetcxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxButton *cxButtonCreateDocReal;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxDBLookupComboBox *TypePricecxDBLookupComboBox;
	TcxLabel *cxLabel2;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonPrintNaklClick(TObject *Sender);
        void __fastcall ToolButtonPrintAktClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAMEEDPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_HOT_SNFPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_HOT_SCATNOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAMEKLIENTPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_HOT_STYPEPOSPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall NameBSchetcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCreateDocRealClick(TObject *Sender);
	void __fastcall ActionAddStringExecute(TObject *Sender);
	void __fastcall ActionDeleteStringExecute(TObject *Sender);
	void __fastcall NumberDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);

		//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);


private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

	   IDMTableExtPrintForm * DMTableExtPrintForm;
	   void RunExternalModule(__int64 id_module, int type_module);

	   
		enum  { aoNO,aoAddNewString} ActionOperation;


		//����� �����
		IFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		void ViborFirm(void);
		void __fastcall EndViborFirm(void);

		//����� �������������� ����
		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void ViborInfBase(void);
		void __fastcall EndViborInfBase(void);

		//����� ������
		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		void ViborSklad(void);
		void __fastcall EndViborSklad(void);


		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;

		//����� �����������
		void ViborPlat(void);
		void __fastcall EndViborPlat(void);
		//����� �����
		void ViborGuest(void);
		void __fastcall EndViborGuest(void);

		//����� ������������
		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		void ViborNom(void);
		void __fastcall EndViborNom(void);

		//����� ������� ���������
		IFormaSpiskaSprEd * FormaSpiskaSprEd;
		void ViborEd(void);
		void __fastcall EndViborEd(void);

		//����� ������
		IHOT_FormaSpiskaSprNF * HOT_FormaSpiskaSprNF;
		void ViborNomer(void);
		void __fastcall EndViborNomer(void);

		//����� ���� ���������
		IHOT_FormaSpiskaSprTypePosel * HOT_FormaSpiskaSprTypePosel;
		void ViborTypePosel(void);
		void __fastcall EndViborTypePosel(void);

		//����� ���������
		IHOT_FormaSpiskaSprCatNom * HOT_FormaSpiskaSprCatNom;
		void ViborCatNom(void);
		void __fastcall EndViborCatNom(void);

		//����� ����������� �����
		IFormaSpiskaSprBankSchet * FormaSpiskaSprBSchet;
		void ViborBSchet(void);
		void __fastcall EndViborBSchet(void);

		enum {ER_NoRekv,ER_Firm,ER_InfBase,ER_Sklad, ER_Plat,ER_Guest,
		ER_Nom,ER_Ed,ER_Nomer,ER_Cat,ER_TypePos, ER_BankSchet} EditRekvisit;

		void OpenPrintFormSchet(void);
		void OpenPrintFormSchetPoGuest(void);

		void OutputStringSchet(TSheetEditor *prForm,
													AnsiString por_number,
													AnsiString pos_nach,
													AnsiString pos_con,
													AnsiString tarif,
													AnsiString nomer,
													AnsiString guest,
													AnsiString name_nom,
													AnsiString kol,
													AnsiString name_ed,
													AnsiString kf_ed,
													AnsiString price,
													AnsiString summa) ;



		void OutputZagolovokReportSchet(TSheetEditor *prForm);
		void OutputPodavalReportSchet(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;

		int NumStrOsnUslugi;
		double KolOsnUslug;
		double SummaOsnUslug;
		bool OutputDopUslug;
		int KolStrokDopUslug;


		void OpenPrintFormAkt(void);
		void OutputStringAkt(TSheetEditor *prForm);
		void OutputZagolovokReportAkt(TSheetEditor *prForm);
		void OutputZagolovokReportAktKompl(TSheetEditor *prForm);
		void OutputPodavalReportAkt(TSheetEditor *prForm);

		int NumPage;

		void CreateDocRealNaOsnRaschet(void);

	   IDMSprTypePrice * DMSprTypePrice;
public:		// User declarations
		__fastcall THOT_FormaDocRaschet(TComponent* Owner);

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


		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


		//������� ���������
		IHOT_DMDocRaschet *DM;

		bool Prosmotr;    //������ ��������
		bool NoEdit;
		__int64 IdDoc;           //������������� ������� ������
		void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE THOT_FormaDocRaschet *HOT_FormaDocRaschet;
//---------------------------------------------------------------------------
#endif
