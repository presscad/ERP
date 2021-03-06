#ifndef UIFormaImportDocPrihNaklH
#define UIFormaImportDocPrihNaklH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaImportDocPrihNakl)) IFormaImportDocPrihNakl : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdInfBase = {read = get_IdInfBase , write = set_IdInfBase};
   virtual __int64 get_IdInfBase(void)=0;
   virtual void set_IdInfBase(__int64 IdInfBase)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property __int64 IdGrpNom = {read = get_IdGrpNom , write = set_IdGrpNom};
   virtual __int64 get_IdGrpNom(void)=0;
   virtual void set_IdGrpNom(__int64 IdGrpNom)=0;

   __property __int64 IdImportSet = {read = get_IdImportSet , write = set_IdImportSet};
   virtual __int64 get_IdImportSet(void)=0;
   virtual void set_IdImportSet(__int64 IdImportSet)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaImportDocPrihNakl __uuidof(IFormaImportDocPrihNakl)
#endif
