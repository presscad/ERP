#include "vcl.h"
#pragma hdrstop  
#include "UFormaSpiskaSprKlientCF.h"   
#include "UFormaSpiskaSprKlientImpl.h"  
#include "IFormaSpiskaSprKlient.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaSpiskaSprKlientCF::TFormaSpiskaSprKlientCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaSpiskaSprKlientCF::~TFormaSpiskaSprKlientCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaSpiskaSprKlientCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaSpiskaSprKlientCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaSpiskaSprKlientCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaSpiskaSprKlientCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaSpiskaSprKlientImpl * ob=new TFormaSpiskaSprKlientImpl();  
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
