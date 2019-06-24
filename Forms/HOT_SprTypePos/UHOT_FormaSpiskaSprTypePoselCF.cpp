#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaSpiskaSprTypePoselCF.h"   
#include "UHOT_FormaSpiskaSprTypePoselImpl.h"  
#include "IHOT_FormaSpiskaSprTypePosel.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaSpiskaSprTypePoselCF::THOT_FormaSpiskaSprTypePoselCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaSpiskaSprTypePoselCF::~THOT_FormaSpiskaSprTypePoselCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaSpiskaSprTypePoselCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaSpiskaSprTypePoselCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaSpiskaSprTypePoselCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaSpiskaSprTypePoselCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaSpiskaSprTypePoselImpl * ob=new THOT_FormaSpiskaSprTypePoselImpl();  
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
