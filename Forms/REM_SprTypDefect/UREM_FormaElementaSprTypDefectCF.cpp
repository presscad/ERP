#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaElementaSprTypDefectCF.h"   
#include "UREM_FormaElementaSprTypDefectImpl.h"  
#include "IREM_FormaElementaSprTypDefect.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaElementaSprTypDefectCF::TREM_FormaElementaSprTypDefectCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaElementaSprTypDefectCF::~TREM_FormaElementaSprTypDefectCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaElementaSprTypDefectCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaElementaSprTypDefectCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaElementaSprTypDefectCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaElementaSprTypDefectCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaElementaSprTypDefectImpl * ob=new TREM_FormaElementaSprTypDefectImpl();  
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
