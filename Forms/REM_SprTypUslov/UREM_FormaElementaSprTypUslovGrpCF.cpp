#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaElementaSprTypUslovGrpCF.h"   
#include "UREM_FormaElementaSprTypUslovGrpImpl.h"  
#include "IREM_FormaElementaSprTypUslovGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaElementaSprTypUslovGrpCF::TREM_FormaElementaSprTypUslovGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaElementaSprTypUslovGrpCF::~TREM_FormaElementaSprTypUslovGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaElementaSprTypUslovGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaElementaSprTypUslovGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaElementaSprTypUslovGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaElementaSprTypUslovGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaElementaSprTypUslovGrpImpl * ob=new TREM_FormaElementaSprTypUslovGrpImpl();  
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
