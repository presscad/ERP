#ifndef UREM_FormaSpiskaSprKKTDvCFH                  
#define UREM_FormaSpiskaSprKKTDvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaSpiskaSprKKTDvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaSpiskaSprKKTDvCF();                                                           
   ~TREM_FormaSpiskaSprKKTDvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
