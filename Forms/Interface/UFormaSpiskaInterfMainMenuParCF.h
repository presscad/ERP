#ifndef UFormaSpiskaInterfMainMenuParCFH                  
#define UFormaSpiskaInterfMainMenuParCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaInterfMainMenuParCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaInterfMainMenuParCF();                                                           
   ~TFormaSpiskaInterfMainMenuParCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
