//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprVesNomH
#define UFormaSpiskaSprVesNomH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IDMSprVesNom.h"
#include "IDMSprGrpVesNom.h"
#include "IDMSprScale.h"
#include "IDMSprTypePrice.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaElementaSprGrpVesNom.h"
#include "IDMTableExtPrintForm.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include <DBCtrls.hpp> 
#include <ActnList.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxTreeView.hpp"
#include "cxButtonEdit.hpp"
#include "cxClasses.hpp"
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
#include <DB.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------
class TFormaSpiskaSprVesNom : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNewScale;
        TToolButton *ToolButtonEdiScale;
        TToolButton *ToolButtonDeleteScale;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TLabel *LabelNameGrp;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonAll;
        TToolButton *ToolButtonIsmGrp;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxTreeView *cxTreeView1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_SVESNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1ZNACH_PRICE;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonSave;
	TcxComboBox *NameScalecxComboBox;
	TcxComboBox *NameTypePricecxComboBox;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewScaleClick(TObject *Sender);
        void __fastcall ToolButtonEdiScaleClick(TObject *Sender);
        void __fastcall ToolButtonDeleteScaleClick(TObject *Sender);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ToolButtonIsmGrpClick(TObject *Sender);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxTreeView1KeyPress(TObject *Sender, char &Key);
	void __fastcall NameScalecxComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameTypePricecxComboBoxPropertiesChange(TObject *Sender);

		//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		IDMSprScale *DMScale;
		IDMSprTypePrice * DMSprTypePrice;


 		void UpdateDerevo(void);

		//�������������� �����
		IFormaElementaSprGrpVesNom * FormaGrpElementa;
		void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();
		void __fastcall EndEditGrp(void);

		IFormaSpiskaSprNom *FormaSpiskaSprNom;
		void  OpenFormSpiskaSprNom();

		void DeleteElement();


		enum{NO,ViborScale,ViborElement, ViborGrp, RekvisitPodborNom, ViborNom} ViborRekvisit;
public:		// User declarations
		__fastcall TFormaSpiskaSprVesNom(TComponent* Owner);
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

		IDMSprVesNom* DM;
		IDMSprGrpVesNom* DMGrp;

		__int64 IdScale;
		__int64 IdGrp;  //������� ������
		__int64 IdTypePrice;
        __int64 IdVesNom;
        bool AllElement;//������� �������� ��� �������� ��� ���
		bool Podbor;

		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprVesNom *FormaSpiskaSprVesNom;
//---------------------------------------------------------------------------
#endif
