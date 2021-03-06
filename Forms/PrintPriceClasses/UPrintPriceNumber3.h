//---------------------------------------------------------------------------

#ifndef UPrintPriceNumber3H
#define UPrintPriceNumber3H
#include "IDMFibConnection.h"
#include "USheetEditor.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
class TPrintPriceNumber3
{
private:
        void PrintPriceNumber_OutputGrp(void);
        void PrintPriceNumber_OutputZagolovok(void);
        void PrintPriceNumber_OutputElement(AnsiString name,
                                                AnsiString code,
                                                AnsiString price,
                                                AnsiString name_ed);

public:
        TPrintPriceNumber3();
		~TPrintPriceNumber3();

	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        void CreatePrice(void);
        TList * List;

        TElementSpiskaPrintPrice * ElementSpiska;

        TSheetEditor * SE;
        int x, y;
        int KolNaString;
		int KolNaPage;
		__int64 IdTypePrice ;
		AnsiString NameFirm;

		int NumberPage;
};
#endif


