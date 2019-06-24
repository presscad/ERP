//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UFormaReportGridCF.h"
#include "UFormaReportGridImpl.h"


//---------------------------------------------------------------------------


extern "C" int __declspec (dllexport) kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv);
extern "C" int __declspec (dllexport) kanSendApplication(TApplication * app);
extern "C" int __declspec (dllexport) kanRegisterServer(IkanCom * icom);
extern "C" int __declspec (dllexport) kanUnregisterServer(IkanCom * icom);
extern "C" int __declspec (dllexport) kanCanUnloadNow(void);
extern "C" void __declspec (dllexport) kanInit(void);
extern "C" void __declspec (dllexport) kanDone(void);
//---------------------------------------------------------------------------
int NumObject=0;
TApplication * glApp=0;
TApplication * dllApp=0;




#pragma argsused
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{
if (fwdreason==DLL_PROCESS_DETACH)
	{
	if (dllApp!=0) Application=dllApp;
	}

	return 1;
}

//-----------------------------------------------------------------------------
int kanSendApplication(TApplication * app)
{
int result=0;
if (app!=0)
	{
	glApp=app;
	dllApp=Application;
	Application=glApp;
	}
return result;
}
//-----------------------------------------------------------------------------
void kanInit(void)
{


}
//---------------------------------------------------------------------------
void kanDone(void)
{

if (dllApp!=0) Application=dllApp;
}

//---------------------------------------------------------------------------
int kanCanUnloadNow(void)
{
int result=0;

if (NumObject==0)
	{
	result= -1;
	}

return result;
}
//-----------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
if (id_class==CLSID_TFormaReportGridImpl)
	{
	TFormaReportGridCF * ob=new TFormaReportGridCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else
	{
	result=0;
	*ppv=NULL;
	}


return result;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

int kanRegisterServer(IkanCom * icom)
{
int result=0;

if (icom->kanAddClass(CLSID_TFormaReportGridImpl,"Oberon.FormaReportGrid.1","RepGrid.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaReportGrid.1  !");
	}

return result;
}
//-----------------------------------------------------------------------------
int kanUnregisterServer(IkanCom * icom)
{
int result=0;

return result;
}
//-----------------------------------------------------------------------------

