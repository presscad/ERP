//---------------------------------------------------------------------------

#ifndef UFormaViborSprKlientH
#define UFormaViborSprKlientH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UDMSprKlient.h"
#include "UDMSprGrpKlient.h"
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include "cxButtons.hpp"
#include "cxClasses.hpp"
#include "cxContainer.hpp"
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
#include "cxLookAndFeelPainters.hpp"
#include "cxStyles.hpp"
#include "cxTreeView.hpp"
#include <DB.hpp>
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaViborSprKlient : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TLabel *LabelNameGrp;
        TLabel *HintLabel;
	TcxButton *cxButtonClose;
	TcxTreeView *cxTreeView1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1INNKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1TELKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonAllElementClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaViborSprKlient(TComponent* Owner);


        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TDMSprKlient* DM;
        TDMSprGrpKlient *DMGrp;

        bool Vibor;
        __int64 IdGrp;    //������� ������
        bool AllElement;//������� �������� ��� �������� ��� ���
        bool OutReady;

        void __fastcall CloseElementSpr(TObject *Sender);
        TNotifyEvent FOnCloseForm;

        void UpdateDerevo(void);
        enum{NO,ViborGrp,ViborElement} ViborRekvisit;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborSprKlient *FormaViborSprKlient;
//---------------------------------------------------------------------------
#endif
