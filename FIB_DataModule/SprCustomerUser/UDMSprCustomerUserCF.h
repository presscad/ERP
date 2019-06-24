#ifndef UDMSprCustomerUserCFH                  
#define UDMSprCustomerUserCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprCustomerUserCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprCustomerUserCF();                                                           
   ~TDMSprCustomerUserCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 