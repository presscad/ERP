#ifndef UIREM_FormaSpiskaSprModelInfBlockH
#define UIREM_FormaSpiskaSprModelInfBlockH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprModelInfBlock.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprModelInfBlock)) IREM_FormaSpiskaSprModelInfBlock : public IMainInterface
{
public:
   __property IREM_DMSprModelInfBlock * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprModelInfBlock * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprModelInfBlock * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm()=0;
};
#define IID_IREM_FormaSpiskaSprModelInfBlock __uuidof(IREM_FormaSpiskaSprModelInfBlock)
#endif
