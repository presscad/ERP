#ifndef UIREM_FormaZayavkaH
#define UIREM_FormaZayavkaH
#include "IMainInterface.h"
#include "IREM_DMZayavka.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IREM_FormaZayavka)) IREM_FormaZayavka : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMZayavka * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMZayavka * get_DM(void)=0;
   virtual void set_DM(IREM_DMZayavka * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdZ = {read = get_IdZ , write = set_IdZ};
   virtual __int64 get_IdZ(void)=0;
   virtual void set_IdZ(__int64 IdZ)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaZayavka __uuidof(IREM_FormaZayavka)
#endif
