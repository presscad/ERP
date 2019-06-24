#include "vcl.h"
#pragma hdrstop  
#include "UFormaSpiskaSprPropertiesNaborSostavCF.h"   
#include "UFormaSpiskaSprPropertiesNaborSostavImpl.h"  
#include "IFormaSpiskaSprPropertiesNaborSostav.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaSpiskaSprPropertiesNaborSostavCF::TFormaSpiskaSprPropertiesNaborSostavCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaSpiskaSprPropertiesNaborSostavCF::~TFormaSpiskaSprPropertiesNaborSostavCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaSpiskaSprPropertiesNaborSostavCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaSpiskaSprPropertiesNaborSostavCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaSpiskaSprPropertiesNaborSostavCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaSpiskaSprPropertiesNaborSostavCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaSpiskaSprPropertiesNaborSostavImpl * ob=new TFormaSpiskaSprPropertiesNaborSostavImpl();  
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
