#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaSpiskaSprHardwareIspImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaSpiskaSprHardwareIspImpl::TREM_FormaSpiskaSprHardwareIspImpl()           
{                                            
Object=new TREM_FormaSpiskaSprHardwareIsp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaSpiskaSprHardwareIspImpl::~TREM_FormaSpiskaSprHardwareIspImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareIspImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareIspImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaSpiskaSprHardwareIsp)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaSpiskaSprHardwareIsp*> (this);                                
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
int TREM_FormaSpiskaSprHardwareIspImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareIspImpl::kanRelease(void)                                  
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
int  TREM_FormaSpiskaSprHardwareIspImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareIspImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaSpiskaSprHardwareIspImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareIspImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareIspImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaSpiskaSprHardwareIspImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareIspImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaSpiskaSprHardwareIspImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaSpiskaSprHardwareIsp
bool TREM_FormaSpiskaSprHardwareIspImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareIspImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprHardwareIspImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareIspImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareIspImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareIspImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IREM_DMSprHardwareIsp * TREM_FormaSpiskaSprHardwareIspImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareIspImpl::set_DM(IREM_DMSprHardwareIsp * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprHardwareIspImpl::get_IdOwner(void)
{
return Object->IdOwner;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareIspImpl::set_IdOwner(__int64 IdOwner)
{
Object->IdOwner=IdOwner;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaSpiskaSprHardwareIspImpl::get_TextMessage(void)
{
return Object->TextMessage;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareIspImpl::set_TextMessage(UnicodeString TextMessage)
{
Object->TextMessage=TextMessage;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareIspImpl::UpdateForm()
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
