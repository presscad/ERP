#ifndef UFormaGurLogCFH                  
#define UFormaGurLogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaGurLogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaGurLogCF();                                                           
   ~TFormaGurLogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
