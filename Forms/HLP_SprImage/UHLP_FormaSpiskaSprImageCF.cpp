#include "vcl.h"
#pragma hdrstop  
#include "UHLP_FormaSpiskaSprImageCF.h"   
#include "UHLP_FormaSpiskaSprImageImpl.h"  
#include "IHLP_FormaSpiskaSprImage.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_FormaSpiskaSprImageCF::THLP_FormaSpiskaSprImageCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_FormaSpiskaSprImageCF::~THLP_FormaSpiskaSprImageCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_FormaSpiskaSprImageCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THLP_FormaSpiskaSprImageCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_FormaSpiskaSprImageCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_FormaSpiskaSprImageCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_FormaSpiskaSprImageImpl * ob=new THLP_FormaSpiskaSprImageImpl();  
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
