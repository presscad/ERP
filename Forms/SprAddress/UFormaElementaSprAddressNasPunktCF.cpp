#include "vcl.h"
#pragma hdrstop  
#include "UFormaElementaSprAddressNasPunktCF.h"   
#include "UFormaElementaSprAddressNasPunktImpl.h"  
#include "IFormaElementaSprAddressNasPunkt.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaElementaSprAddressNasPunktCF::TFormaElementaSprAddressNasPunktCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaElementaSprAddressNasPunktCF::~TFormaElementaSprAddressNasPunktCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaElementaSprAddressNasPunktCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaElementaSprAddressNasPunktCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaElementaSprAddressNasPunktCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaElementaSprAddressNasPunktCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaElementaSprAddressNasPunktImpl * ob=new TFormaElementaSprAddressNasPunktImpl();  
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
