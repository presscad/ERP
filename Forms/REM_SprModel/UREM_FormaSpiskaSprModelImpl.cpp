#include "vcl.h"
#pragma hdrstop


#include "UREM_FormaSpiskaSprModelImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_FormaSpiskaSprModelImpl::TREM_FormaSpiskaSprModelImpl()           
{                                            
Object=new TREM_FormaSpiskaSprModel(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_FormaSpiskaSprModelImpl::~TREM_FormaSpiskaSprModelImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_FormaSpiskaSprModelImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_FormaSpiskaSprModel)                        
   {                                                                     
   *ppv=static_cast<IREM_FormaSpiskaSprModel*> (this);                                
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
int TREM_FormaSpiskaSprModelImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_FormaSpiskaSprModelImpl::kanRelease(void)                                  
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
int  TREM_FormaSpiskaSprModelImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_FormaSpiskaSprModelImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprModelImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_FormaSpiskaSprModelImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_FormaSpiskaSprModelImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TREM_FormaSpiskaSprModelImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //��������� �� �������� ������ 
									id_object,      //��� ��������� �������  
									type_event,     //��� ������� � �������� ������� 
									number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������ 
									); 
}   
//---------------------------------------------------------------

//IREM_FormaSpiskaSprModel
bool TREM_FormaSpiskaSprModelImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprModelImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TREM_FormaSpiskaSprModelImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
IREM_DMSprModel* TREM_FormaSpiskaSprModelImpl::get_DM(void)
{
return Object->DM;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_DM(IREM_DMSprModel* DM)
{
Object->DM=DM;
}
//---------------------------------------------------------------
IREM_DMSprGrpModel * TREM_FormaSpiskaSprModelImpl::get_DMGrp(void)
{
return Object->DMGrp;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_DMGrp(IREM_DMSprGrpModel * DMGrp)
{
Object->DMGrp=DMGrp;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprModelImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TREM_FormaSpiskaSprModelImpl::get_IdModel(void)
{
return Object->IdModel;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_IdModel(__int64 IdModel)
{
Object->IdModel=IdModel;
}
//---------------------------------------------------------------
bool TREM_FormaSpiskaSprModelImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
UnicodeString TREM_FormaSpiskaSprModelImpl::get_TextMessage(void)
{
return Object->TextMessage;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::set_TextMessage(UnicodeString TextMessage)
{
Object->TextMessage=TextMessage;
}
//---------------------------------------------------------------
void TREM_FormaSpiskaSprModelImpl::UpdateForm(void)
{
return Object->UpdateForm();
}
//---------------------------------------------------------------
