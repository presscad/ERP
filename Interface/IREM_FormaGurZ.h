#ifndef UIREM_FormaGurZH
#define UIREM_FormaGurZH
#include "IMainInterface.h"
#include "IREM_DMGurZ.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IREM_FormaGurZ)) IREM_FormaGurZ : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMGurZ * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMGurZ * get_DM(void)=0;
   virtual void set_DM(IREM_DMGurZ * DM)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

};
#define IID_IREM_FormaGurZ __uuidof(IREM_FormaGurZ)
#endif
