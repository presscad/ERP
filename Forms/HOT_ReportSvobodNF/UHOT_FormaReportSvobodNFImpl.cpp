#include "vcl.h"
#pragma hdrstop


#include "UHOT_FormaReportSvobodNFImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_FormaReportSvobodNFImpl::THOT_FormaReportSvobodNFImpl()           
{                                            
Object=new THOT_FormaReportSvobodNF(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_FormaReportSvobodNFImpl::~THOT_FormaReportSvobodNFImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_FormaReportSvobodNFImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_FormaReportSvobodNFImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (static_cast<IMainInterface*>(this)); 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IMainInterface)                        
   {                                                                     
   *ppv=static_cast<IMainInterface*> (this);                                
   result=-1;                                                            
   }  
else if (id_interface==IID_IkanCallBack) 
   {                                        
   *ppv=static_cast<IkanCallBack*> (this);  
   result=-1;                               
   }

else                                                                     
   {                                                                     
   *ppv=NULL;                                                            
   result=1;                                                             
   return result;                                                        
   }                                                                     
kanAddRef();
return result;                                                           
}                                                                       
//---------------------------------------------------------------
int THOT_FormaReportSvobodNFImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_FormaReportSvobodNFImpl::kanRelease(void)                                  
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;                                                       
   return 0;                                                       
   }                                                                  
return NumRefs;                                                       
}                                                                     
//---------------------------------------------------------------

//IMainInterface 
int  THOT_FormaReportSvobodNFImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_FormaReportSvobodNFImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_FormaReportSvobodNFImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_FormaReportSvobodNFImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_FormaReportSvobodNFImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_FormaReportSvobodNFImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_FormaReportSvobodNFImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int THOT_FormaReportSvobodNFImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IHOT_FormaReportSvobodNF
