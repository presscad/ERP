#ifndef UREM_FormaDocRemontHWCFH                  
#define UREM_FormaDocRemontHWCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocRemontHWCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocRemontHWCF();                                                           
   ~TREM_FormaDocRemontHWCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
