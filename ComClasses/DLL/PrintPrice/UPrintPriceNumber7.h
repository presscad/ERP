//---------------------------------------------------------------------------

#ifndef UPrintPriceNumber7H
#define UPrintPriceNumber7H
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "USheetEditor.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"


class TPrintPriceNumber7
{
private:
        void PrintPriceNumber_OutputGrp(void);
        void PrintPriceNumber_OutputZagolovok(void);
        void PrintPriceNumber_OutputElement(AnsiString name,
                                                AnsiString code,
                                                AnsiString price,
                                                AnsiString name_ed);

public:
		TPrintPriceNumber7();
		~TPrintPriceNumber7();

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		void CreatePrice(void);
        TList * List;

        TElementSpiskaPrintPrice * ElementSpiska;

        TSheetEditor * SE;
        int x, y;
        int KolNaString;
		int KolNaPage;
		__int64 IdTypePrice;
		AnsiString NameFirm;
		int NumberPage;
};
#endif
