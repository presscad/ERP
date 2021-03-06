#ifndef UIFormaDocPKOH
#define UIFormaDocPKOH
#include "IMainInterface.h"
#include "IDMDocPKO.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaDocPKO)) IFormaDocPKO : public IMainInterface
{
public:
   __property IDMDocPKO * DM = {read = get_DM , write = set_DM};
   virtual IDMDocPKO * get_DM(void)=0;
   virtual void set_DM(IDMDocPKO * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaDocPKO __uuidof(IFormaDocPKO)
#endif
