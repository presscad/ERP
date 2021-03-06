#ifndef UIREM_FormaSpiskaSprNeisprModelH
#define UIREM_FormaSpiskaSprNeisprModelH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprNeisprModel.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprNeisprModel)) IREM_FormaSpiskaSprNeisprModel : public IMainInterface
{
public:
   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMSprNeisprModel * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprNeisprModel * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprNeisprModel * DM)=0;

   __property __int64 IdModel = {read = get_IdModel , write = set_IdModel};
   virtual __int64 get_IdModel(void)=0;
   virtual void set_IdModel(__int64 IdModel)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   virtual void UpdateForm()=0;
};
#define IID_IREM_FormaSpiskaSprNeisprModel __uuidof(IREM_FormaSpiskaSprNeisprModel)
#endif
