#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaDocRemontHWImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaDocRemontHWImpl::TREM_FormaDocRemontHWImpl()           
{                                            
Object=new TREM_FormaDocRemontHW(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaDocRemontHWImpl::~TREM_FormaDocRemontHWImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaDocRemontHWImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaDocRemontHW)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaDocRemontHW*> (this);                                
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
int TREM_FormaDocRemontHWImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaDocRemontHWImpl::kanRelease(void)                                  
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
int  TREM_FormaDocRemontHWImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaDocRemontHWImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaDocRemontHWImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaDocRemontHWImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaDocRemontHWImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaDocRemontHWImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaDocRemontHW
bool TREM_FormaDocRemontHWImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TREM_FormaDocRemontHWImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IREM_DMDocRemontHW * TREM_FormaDocRemontHWImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::set_DM(IREM_DMDocRemontHW * DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool TREM_FormaDocRemontHWImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_FormaDocRemontHWImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_FormaDocRemontHWImpl::get_VibTovarId(void)
{
return Object->VibTovarId;
}
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::set_VibTovarId(__int64 VibTovarId)
{
Object->VibTovarId=VibTovarId;
}
//---------------------------------------------------------------
__int64 TREM_FormaDocRemontHWImpl::get_VibTovarIdGrp(void)
{
return Object->VibTovarIdGrp;
}
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::set_VibTovarIdGrp(__int64 VibTovarIdGrp)
{
Object->VibTovarIdGrp=VibTovarIdGrp;
}
//---------------------------------------------------------------
void TREM_FormaDocRemontHWImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
