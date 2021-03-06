#ifndef UFormaElementaSprInetCatalogCFH                  
#define UFormaElementaSprInetCatalogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprInetCatalogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprInetCatalogCF();                                                           
   ~TFormaElementaSprInetCatalogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
