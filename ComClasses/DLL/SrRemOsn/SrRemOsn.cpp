//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"
#include "USR_FormaOstatkiTovarovCF.h"
#include "USR_FormaOstatkiTovarovImpl.h"

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



TDM *DM=0;

#pragma argsused
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{

	return 1;
}
//---------------------------------------------------------------------------
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

DM=new TDM(Application);
}
//---------------------------------------------------------------------------
void kanDone(void)
{
if (DM!=0) delete DM;
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


if (id_class==CLSID_TSR_FormaOstatkiTovarovImpl)
	{
	TSR_FormaOstatkiTovarovCF * ob=new TSR_FormaOstatkiTovarovCF();
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


int kanRegisterServer(IkanCom * icom)
{
int result=0;

if (icom->kanAddClass(CLSID_TSR_FormaOstatkiTovarovImpl,ProgId_SR_FormaOstatkiTovarov,"SrRemOsn.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_SR_FormaOstatkiTovarov)+"  !");
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
