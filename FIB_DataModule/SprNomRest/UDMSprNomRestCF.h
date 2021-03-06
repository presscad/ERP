#ifndef UDMSprNomRestCFH                  
#define UDMSprNomRestCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprNomRestCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprNomRestCF();                                                           
   ~TDMSprNomRestCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
