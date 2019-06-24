#include "vcl.h"
#pragma hdrstop


#include "UFormaSpiskaSprRaschSchetImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaSpiskaSprRaschSchetImpl::TFormaSpiskaSprRaschSchetImpl()           
{                                            
Object=new TFormaSpiskaSprRaschSchet(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaSpiskaSprRaschSchetImpl::~TFormaSpiskaSprRaschSchetImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaSpiskaSprRaschSchetImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaSpiskaSprRaschSchetImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IFormaSpiskaSprRaschSchet)                        
   {                                                                     
   *ppv=static_cast<IFormaSpiskaSprRaschSchet*> (this);                                
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
int TFormaSpiskaSprRaschSchetImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaSpiskaSprRaschSchetImpl::kanRelease(void)                                  
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
int  TFormaSpiskaSprRaschSchetImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprRaschSchetImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaSpiskaSprRaschSchetImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaSpiskaSprRaschSchetImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaSpiskaSprRaschSchetImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaSpiskaSprRaschSchetImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TFormaSpiskaSprRaschSchetImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaSpiskaSprRaschSchetImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IFormaSpiskaSprRaschSchet
IDMSprRaschSchet * TFormaSpiskaSprRaschSchetImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TFormaSpiskaSprRaschSchetImpl::set_DM(IDMSprRaschSchet * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
__int64 TFormaSpiskaSprRaschSchetImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TFormaSpiskaSprRaschSchetImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
bool TFormaSpiskaSprRaschSchetImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprRaschSchetImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaSpiskaSprRaschSchetImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaSpiskaSprRaschSchetImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------

