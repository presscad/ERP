#include "vcl.h"
#pragma hdrstop  
#include "UFormaElementaSprBankCF.h"   
#include "UFormaElementaSprBankImpl.h"  
#include "IFormaElementaSprBank.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaElementaSprBankCF::TFormaElementaSprBankCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaElementaSprBankCF::~TFormaElementaSprBankCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaElementaSprBankCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaElementaSprBankCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaElementaSprBankCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaElementaSprBankCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaElementaSprBankImpl * ob=new TFormaElementaSprBankImpl();  
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
