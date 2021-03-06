#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaElementaSprSostCustQueryImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaElementaSprSostCustQueryImpl::TREM_FormaElementaSprSostCustQueryImpl()           
{                                            
Object=new TREM_FormaElementaSprSostCustQuery(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaElementaSprSostCustQueryImpl::~TREM_FormaElementaSprSostCustQueryImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaElementaSprSostCustQueryImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaElementaSprSostCustQueryImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaElementaSprSostCustQuery)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaElementaSprSostCustQuery*> (this);                                
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
int TREM_FormaElementaSprSostCustQueryImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaElementaSprSostCustQueryImpl::kanRelease(void)                                  
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
int  TREM_FormaElementaSprSostCustQueryImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaElementaSprSostCustQueryImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaElementaSprSostCustQueryImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaElementaSprSostCustQueryImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaElementaSprSostCustQueryImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaElementaSprSostCustQueryImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaElementaSprSostCustQueryImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaElementaSprSostCustQueryImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaElementaSprSostCustQuery
bool TREM_FormaElementaSprSostCustQueryImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprSostCustQueryImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_FormaElementaSprSostCustQueryImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprSostCustQueryImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TREM_FormaElementaSprSostCustQueryImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprSostCustQueryImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IREM_DMSprSostCustQuery * TREM_FormaElementaSprSostCustQueryImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprSostCustQueryImpl::set_DM(IREM_DMSprSostCustQuery * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprSostCustQueryImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
