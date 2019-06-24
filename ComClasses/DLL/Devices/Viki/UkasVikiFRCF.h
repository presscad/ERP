//---------------------------------------------------------------------------

#ifndef UkasVikiFRCFH
#define UkasVikiFRCFH
//---------------------------------------------------------------------------

#include "GlobalInterface.h"
//---------------------------------------------------------------
class TkasVikiFRCF : public IkanClassFactory
{
public:
   TkasVikiFRCF();
   ~TkasVikiFRCF();
   int NumRefs;
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	  virtual int kanAddRef(void);
	  virtual int kanRelease(void);
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv);
};
//---------------------------------------------------------------


#endif
