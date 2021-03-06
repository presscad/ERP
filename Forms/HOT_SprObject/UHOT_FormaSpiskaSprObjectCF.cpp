#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaSpiskaSprObjectCF.h"   
#include "UHOT_FormaSpiskaSprObjectImpl.h"  
#include "IHOT_FormaSpiskaSprObject.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaSpiskaSprObjectCF::THOT_FormaSpiskaSprObjectCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaSpiskaSprObjectCF::~THOT_FormaSpiskaSprObjectCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaSpiskaSprObjectCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaSpiskaSprObjectCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaSpiskaSprObjectCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaSpiskaSprObjectCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaSpiskaSprObjectImpl * ob=new THOT_FormaSpiskaSprObjectImpl();  
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
