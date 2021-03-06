#ifndef UFormaSpiskaSprProducerCFH                  
#define UFormaSpiskaSprProducerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprProducerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprProducerCF();                                                           
   ~TFormaSpiskaSprProducerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
