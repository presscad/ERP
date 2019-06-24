#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaDocKM2CF.h"   
#include "UREM_FormaDocKM2Impl.h"  
#include "IREM_FormaDocKM2.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaDocKM2CF::TREM_FormaDocKM2CF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaDocKM2CF::~TREM_FormaDocKM2CF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaDocKM2CF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaDocKM2CF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaDocKM2CF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaDocKM2CF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaDocKM2Impl * ob=new TREM_FormaDocKM2Impl();  
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
