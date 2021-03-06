#include "vcl.h"
#pragma hdrstop  
#include "UFormaImportSprProducerRabotaCF.h"   
#include "UFormaImportSprProducerRabotaImpl.h"  
#include "IFormaImportSprProducerRabota.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaImportSprProducerRabotaCF::TFormaImportSprProducerRabotaCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaImportSprProducerRabotaCF::~TFormaImportSprProducerRabotaCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaImportSprProducerRabotaCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();  
return result;  
}   
//---------------------------------------------------------------
int TFormaImportSprProducerRabotaCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaImportSprProducerRabotaCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaImportSprProducerRabotaCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaImportSprProducerRabotaImpl * ob=new TFormaImportSprProducerRabotaImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
