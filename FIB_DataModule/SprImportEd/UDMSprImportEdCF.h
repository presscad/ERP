#ifndef UDMSprImportEdCFH                  
#define UDMSprImportEdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprImportEdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprImportEdCF();                                                           
   ~TDMSprImportEdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
