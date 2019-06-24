#include "vcl.h"
#pragma hdrstop  
#include "UFormaReportSostProdCF.h"   
#include "UFormaReportSostProdImpl.h"  
#include "IFormaReportSostProd.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaReportSostProdCF::TFormaReportSostProdCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaReportSostProdCF::~TFormaReportSostProdCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaReportSostProdCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaReportSostProdCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaReportSostProdCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaReportSostProdCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaReportSostProdImpl * ob=new TFormaReportSostProdImpl();  
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
