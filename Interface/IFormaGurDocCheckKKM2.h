#ifndef UIFormaGurDocCheckKKM2H
#define UIFormaGurDocCheckKKM2H
#include "IMainInterface.h"
#include "IDMGurDocCheckKKM2.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaGurCheckKKM2)) IFormaGurDocCheckKKM2 : public IMainInterface
{
public:
   __property IDMGurDocCheckKKM2 * DM = {read = get_DM , write = set_DM};
   virtual IDMGurDocCheckKKM2 * get_DM(void)=0;
   virtual void set_DM(IDMGurDocCheckKKM2 * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdKKM = {read = get_IdKKM , write = set_IdKKM};
   virtual __int64 get_IdKKM(void)=0;
   virtual void set_IdKKM(__int64 IdKKM)=0;

   __property bool Otbor = {read = get_Otbor , write = set_Otbor};
   virtual bool get_Otbor(void)=0;
   virtual void set_Otbor(bool Otbor)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaGurDocCheckKKM2 __uuidof(IFormaGurDocCheckKKM2)
#endif
