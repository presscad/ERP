#include "vcl.h"
#pragma hdrstop


#include "UFormaElementaSprKlientDopFisLImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaElementaSprKlientDopFisLImpl::TFormaElementaSprKlientDopFisLImpl()           
{                                            
Object=new TFormaElementaSprKlientDopFisL(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaElementaSprKlientDopFisLImpl::~TFormaElementaSprKlientDopFisLImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaElementaSprKlientDopFisLImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaElementaSprKlientDopFisLImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaElementaSprKlientDopFisL)                        
   {                                                                     
   *ppv=static_cast<IFormaElementaSprKlientDopFisL*> (this);                                
   result=-1;                                                            
   }                                                                     
else                                                                     
   {                                                                     
   *ppv=NULL;                                                            
   result=1;                                                             
   return result;                                                        
   }                                                                     
kanAddRef();;
return result;                                                           
}                                                                       
//---------------------------------------------------------------
int TFormaElementaSprKlientDopFisLImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaElementaSprKlientDopFisLImpl::kanRelease(void)                                  
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

//---------------------------------------------------------------
int  TFormaElementaSprKlientDopFisLImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaElementaSprKlientDopFisLImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaElementaSprKlientDopFisLImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaElementaSprKlientDopFisLImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaElementaSprKlientDopFisLImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaElementaSprKlientDopFisLImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TFormaElementaSprKlientDopFisLImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaElementaSprKlientDopFisLImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IFormaElementaSprKlientDopFisL
IDMSprKlientDopFisL * TFormaElementaSprKlientDopFisLImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaElementaSprKlientDopFisLImpl::set_DM(IDMSprKlientDopFisL * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
UnicodeString TFormaElementaSprKlientDopFisLImpl::get_NameKlient(void)
{
return Object->NameKlient;
}
//---------------------------------------------------------------
void TFormaElementaSprKlientDopFisLImpl::set_NameKlient(UnicodeString NameKlient)
{
Object->NameKlient=NameKlient;
}
//---------------------------------------------------------------
bool TFormaElementaSprKlientDopFisLImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaElementaSprKlientDopFisLImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaElementaSprKlientDopFisLImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaElementaSprKlientDopFisLImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}

//---------------------------------------------------------------
void TFormaElementaSprKlientDopFisLImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
