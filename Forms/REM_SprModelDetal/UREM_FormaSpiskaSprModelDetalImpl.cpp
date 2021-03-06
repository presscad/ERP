#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaSpiskaSprModelDetalImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaSpiskaSprModelDetalImpl::TREM_FormaSpiskaSprModelDetalImpl()           
{                                            
Object=new TREM_FormaSpiskaSprModelDetal(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaSpiskaSprModelDetalImpl::~TREM_FormaSpiskaSprModelDetalImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelDetalImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaSpiskaSprModelDetalImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaSpiskaSprModelDetal)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaSpiskaSprModelDetal*> (this);                                
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
int TREM_FormaSpiskaSprModelDetalImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaSpiskaSprModelDetalImpl::kanRelease(void)                                  
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
int  TREM_FormaSpiskaSprModelDetalImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelDetalImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaSpiskaSprModelDetalImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelDetalImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprModelDetalImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaSpiskaSprModelDetalImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprModelDetalImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaSpiskaSprModelDetalImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaSpiskaSprModelDetal
bool TREM_FormaSpiskaSprModelDetalImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelDetalImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprModelDetalImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelDetalImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TREM_FormaSpiskaSprModelDetalImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelDetalImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IREM_DMSprModelDetal * TREM_FormaSpiskaSprModelDetalImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelDetalImpl::set_DM(IREM_DMSprModelDetal * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprModelDetalImpl::get_IdModel(void)
{
return Object->IdModel;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelDetalImpl::set_IdModel(__int64 IdModel)
{
Object->IdModel=IdModel;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaSpiskaSprModelDetalImpl::get_TextMessage(void)
{
return Object->TextMessage;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelDetalImpl::set_TextMessage(UnicodeString TextMessage)
{
Object->TextMessage=TextMessage;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelDetalImpl::UpdateForm()
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
