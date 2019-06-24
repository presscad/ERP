#include "vcl.h"
#pragma hdrstop  
#include "UFormaElementaSprProducerNomGrpCF.h"   
#include "UFormaElementaSprProducerNomGrpImpl.h"  
#include "IFormaElementaSprProducerNomGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaElementaSprProducerNomGrpCF::TFormaElementaSprProducerNomGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaElementaSprProducerNomGrpCF::~TFormaElementaSprProducerNomGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaElementaSprProducerNomGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaElementaSprProducerNomGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaElementaSprProducerNomGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaElementaSprProducerNomGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaElementaSprProducerNomGrpImpl * ob=new TFormaElementaSprProducerNomGrpImpl();  
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
