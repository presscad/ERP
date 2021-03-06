#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaElementaSprProducerSectionImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaElementaSprProducerSectionImpl::TREM_FormaElementaSprProducerSectionImpl()           
{                                            
Object=new TREM_FormaElementaSprProducerSection(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaElementaSprProducerSectionImpl::~TREM_FormaElementaSprProducerSectionImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaElementaSprProducerSectionImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaElementaSprProducerSection)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaElementaSprProducerSection*> (this);                                
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
int TREM_FormaElementaSprProducerSectionImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaElementaSprProducerSectionImpl::kanRelease(void)                                  
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
int  TREM_FormaElementaSprProducerSectionImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaElementaSprProducerSectionImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaElementaSprProducerSectionImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaElementaSprProducerSectionImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaElementaSprProducerSectionImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaElementaSprProducerSectionImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaElementaSprProducerSection
IREM_DMSprProducerSection* TREM_FormaElementaSprProducerSectionImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::set_DM(IREM_DMSprProducerSection* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
bool TREM_FormaElementaSprProducerSectionImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TREM_FormaElementaSprProducerSectionImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaElementaSprProducerSectionImpl::get_NameGroupElement(void)
{
return Object->NameGroupElement;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::set_NameGroupElement(UnicodeString NameGroupElement)
{
Object->NameGroupElement=NameGroupElement;
}
//---------------------------------------------------------------
__int64 TREM_FormaElementaSprProducerSectionImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaElementaSprProducerSectionImpl::get_NameGroup(void)
{
return Object->NameGroup;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::set_NameGroup(UnicodeString NameGroup)
{
Object->NameGroup=NameGroup;
}
//---------------------------------------------------------------
__int64 TREM_FormaElementaSprProducerSectionImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
void TREM_FormaElementaSprProducerSectionImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
