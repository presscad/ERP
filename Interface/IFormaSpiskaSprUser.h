#ifndef UIFormaSpiskaSprUserH
#define UIFormaSpiskaSprUserH
#include "IMainInterface.h"
#include "IDMSprUser.h"
#include "IDMSprGrpUser.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprUser)) IFormaSpiskaSprUser : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprUser * DM = {read = get_DM , write = set_DM};
   virtual IDMSprUser * get_DM(void)=0;
   virtual void set_DM(IDMSprUser * DM)=0;

   __property IDMSprGrpUser * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpUser * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpUser * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdUser = {read = get_IdUser , write = set_IdUser};
   virtual __int64 get_IdUser(void)=0;
   virtual void set_IdUser(__int64 IdUser)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprUser __uuidof(IFormaSpiskaSprUser)
#endif
