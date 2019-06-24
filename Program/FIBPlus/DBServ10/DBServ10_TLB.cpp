// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// $Rev: 5081 $
// File generated on 26.11.2009 11:09:45 from Type Library described below.

// ************************************************************************  //
// Type Lib: K:\Program\FIBPlus\DBServ10\DBServ10.tlb (1)
// LIBID: {3F05B876-7B55-41DD-AB32-DA8BF9369FB4}
// LCID: 0
// Helpfile: 
// HelpString: DBServ10 Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\Windows\system32\stdole2.tlb)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include "DBServ10_TLB.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Dbserv10_tlb
{


// *********************************************************************//
// GUIDS declared in the TypeLibrary                                      
// *********************************************************************//
const GUID LIBID_DBServ10 = {0x3F05B876, 0x7B55, 0x41DD,{ 0xAB, 0x32, 0xDA,0x8B, 0xF9, 0x36,0x9F, 0xB4} };
const GUID IID_IOleDMGurAllDoc = {0xA02C7199, 0xFA6C, 0x428C,{ 0x90, 0x23, 0x6A,0x07, 0xFC, 0x67,0x8F, 0xB3} };
const GUID CLSID_OleDMGurAllDoc = {0x0C7F069C, 0xF727, 0x4C30,{ 0xAF, 0x70, 0x28,0xD5, 0x6B, 0xDA,0x62, 0x32} };
const GUID IID_IOleDM = {0x1A440201, 0x6AC2, 0x4B65,{ 0xA0, 0xE7, 0x10,0x92, 0x67, 0x5C,0x2A, 0x3F} };
const GUID CLSID_OleDM = {0x5ACCEFEF, 0x42EE, 0x4D8B,{ 0x86, 0x51, 0x38,0xA3, 0x6C, 0x64,0x72, 0x63} };
const GUID IID_IOleDMSprSklad = {0x5B2971DD, 0xB19A, 0x4FC3,{ 0xBE, 0xDC, 0x3E,0x05, 0xB1, 0x57,0xFE, 0x9A} };
const GUID CLSID_OleDMSprSklad = {0x9211AAB2, 0xDB04, 0x4B5D,{ 0xA5, 0x8F, 0x2C,0x75, 0x91, 0x4E,0x98, 0xAE} };
const GUID IID_IOleDMSprFirm = {0xC22EF17E, 0xFDD9, 0x48D0,{ 0x9F, 0xE4, 0x59,0xAE, 0x22, 0x54,0x50, 0xD2} };
const GUID CLSID_OleDMSprFirm = {0xF97F36F8, 0x3028, 0x4137,{ 0xBC, 0xFE, 0x3C,0xB6, 0x88, 0x30,0x76, 0x76} };
const GUID IID_IOleDMSprNom = {0xEB727574, 0xCFC8, 0x449E,{ 0xAB, 0x6B, 0xFC,0x50, 0x7E, 0x17,0x38, 0x33} };
const GUID CLSID_OleDMSprNom = {0x33B3A2F9, 0xA013, 0x4EAC,{ 0xA7, 0x89, 0x39,0x22, 0x93, 0xC8,0xBB, 0x02} };
const GUID IID_IOleDMSprEd = {0xA7FF2337, 0xC284, 0x4BDC,{ 0x84, 0xC5, 0x5E,0xB6, 0x2F, 0xD8,0x05, 0x8C} };
const GUID CLSID_OleDMSprEd = {0xFC78D318, 0xC8DD, 0x4958,{ 0x9F, 0x54, 0x5D,0x0C, 0xC9, 0x10,0x4A, 0xAE} };
const GUID IID_IOleDMDocRepKKM = {0x500BC744, 0x0B7A, 0x4DB5,{ 0xAF, 0x7C, 0x6B,0x6B, 0x29, 0x6C,0x3B, 0x8B} };
const GUID CLSID_OleDMDocRepKKM = {0x243D2465, 0x0A38, 0x4386,{ 0xB5, 0x6B, 0x81,0x27, 0x62, 0xA1,0xC8, 0xEA} };
const GUID IID_IOleDMSprGrpNom = {0x122A380E, 0xAADA, 0x46E5,{ 0xAE, 0x13, 0x7B,0xC1, 0xC5, 0x18,0x94, 0x2C} };
const GUID CLSID_OleDMSprGrpNom = {0xB2F95F97, 0x7808, 0x4C5B,{ 0x9C, 0x54, 0xE0,0x54, 0x0E, 0xB1,0x60, 0x7A} };
const GUID IID_IOleDMSprTypePrice = {0x03AE0B1D, 0x6050, 0x471A,{ 0xAF, 0xA2, 0x2F,0x5E, 0x0B, 0x1A,0xDD, 0xED} };
const GUID CLSID_OleDMSprTypePrice = {0x8E0175B5, 0xF301, 0x4761,{ 0xBE, 0xB1, 0xAC,0xE6, 0xDC, 0x55,0x62, 0x28} };
const GUID IID_IOleDMSprPrice = {0x81AAC7FF, 0x6A90, 0x4E54,{ 0xB3, 0xFE, 0xAF,0x26, 0x54, 0x65,0xB0, 0xEB} };
const GUID CLSID_OleDMSprPrice = {0xEF431542, 0xF473, 0x43BC,{ 0x91, 0x4C, 0x73,0xAE, 0xC7, 0x7E,0xB4, 0xB0} };
const GUID IID_IOleDMDocPer = {0x906D0C92, 0xDE95, 0x4FA2,{ 0x9D, 0xE4, 0x4E,0x4D, 0xCA, 0x72,0x42, 0xA1} };
const GUID CLSID_OleDMDocPer = {0xEF156EFE, 0xCA13, 0x415E,{ 0xA4, 0xDC, 0xEF,0x6C, 0x3F, 0xAB,0x8B, 0x59} };
const GUID IID_IOleDMDocPrihNakl = {0x68D9AE11, 0xD691, 0x410E,{ 0x8E, 0x27, 0xAD,0x1C, 0xF6, 0xA3,0xCA, 0x54} };
const GUID CLSID_OleDMDocPrihNakl = {0x3CAEA598, 0x1689, 0x40ED,{ 0x91, 0x02, 0x87,0x4F, 0xB8, 0x9B,0x9F, 0xF3} };
const GUID IID_IOleDMDocReal = {0xA9B32F6B, 0x0BBA, 0x4CFA,{ 0xAE, 0xF1, 0x31,0x2A, 0xA4, 0x88,0xA0, 0x2F} };
const GUID CLSID_OleDMDocReal = {0xC8A9095E, 0x0961, 0x49A2,{ 0x95, 0x58, 0x20,0xDC, 0x25, 0xC8,0x76, 0x75} };
const GUID IID_IOleDMDocSpisNom = {0x8B080649, 0x063C, 0x46B7,{ 0xAB, 0x4B, 0xF1,0x55, 0x56, 0x58,0x55, 0x5E} };
const GUID CLSID_OleDMDocSpisNom = {0x73F7166B, 0x6192, 0x4DCA,{ 0xBF, 0xEF, 0x57,0x77, 0x84, 0x1B,0xD8, 0x70} };
const GUID IID_IOleDMDocOstNom = {0x38DC6630, 0x17D6, 0x42FC,{ 0xB5, 0x28, 0xA2,0xC9, 0xA6, 0x04,0x7C, 0x38} };
const GUID CLSID_OleDMDocOstNom = {0x47808F00, 0x360B, 0x4A0A,{ 0x84, 0x7B, 0x50,0xBA, 0x0A, 0x10,0x6D, 0x2A} };
const GUID IID_IOleDMSprInfBase = {0xD8FD7D0D, 0xA464, 0x40C9,{ 0x85, 0x30, 0x85,0x2F, 0xB7, 0x21,0xE0, 0x35} };
const GUID CLSID_OleDMSprInfBase = {0x261FEA00, 0x60AD, 0x49C2,{ 0x87, 0x85, 0x3A,0xFD, 0x2C, 0x1D,0xF8, 0x45} };

};     // namespace Dbserv10_tlb
