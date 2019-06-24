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
// File generated on 04.03.2008 11:03:53 from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\WINDOWS\system32\MercFPrtX.ocx (1)
// LIBID: {AB1C5DBF-F491-489B-9B88-0F7B9CF0D904}
// LCID: 0
// Helpfile: 
// HelpString: ��������: ���������� ������������ "��������"
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINDOWS\system32\stdole2.tlb)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include "MercFPrtX_TLB.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Mercfprtx_tlb
{


// *********************************************************************//
// GUIDS declared in the TypeLibrary                                      
// *********************************************************************//
const GUID LIBID_MercFPrtX = {0xAB1C5DBF, 0xF491, 0x489B,{ 0x9B, 0x88, 0x0F,0x7B, 0x9C, 0xF0,0xD9, 0x04} };
const GUID IID_IMercuryFPrt = {0x525FE0EA, 0x4EA5, 0x45DD,{ 0xAB, 0x9E, 0xEB,0x75, 0xAD, 0xAF,0x25, 0x57} };
const GUID DIID_IMercuryFPrtEvents = {0x2E1B3242, 0x7861, 0x424F,{ 0xB9, 0x25, 0xE2,0x30, 0xD9, 0x66,0xDD, 0xAE} };
const GUID IID_IMercuryFPrtX = {0x6976823E, 0xB5E5, 0x4748,{ 0xBD, 0x90, 0x65,0x16, 0xD2, 0x2B,0x69, 0x4E} };
const GUID IID__IMercuryFPrtEventsDirect = {0xDF60ED81, 0xA028, 0x4863,{ 0x8C, 0x69, 0x66,0x2E, 0x5F, 0x28,0x51, 0x2B} };
const GUID IID_IMercuryFPrt2 = {0x081E43FF, 0x4768, 0x4C9A,{ 0x95, 0x7F, 0xBF,0x11, 0x7C, 0xFD,0xD1, 0x5B} };
const GUID IID_IMercuryFPrt3 = {0x761CED73, 0x985A, 0x4FCF,{ 0x95, 0xE7, 0x21,0xD0, 0x3E, 0x48,0x93, 0x05} };
const GUID IID_IMercuryFPrtX2 = {0x15273680, 0x3D9A, 0x4D78,{ 0x9F, 0xEC, 0xB9,0x2F, 0xFC, 0xD8,0x84, 0x41} };
const GUID IID_IMercuryFPrtX3 = {0x7F2562A6, 0x46FE, 0x41FD,{ 0xA7, 0x5F, 0x85,0x53, 0x54, 0x72,0x96, 0x9F} };
const GUID IID_IMercuryFPrt4 = {0x01D442F5, 0x56A5, 0x4F04,{ 0x8C, 0x61, 0xFB,0x65, 0x11, 0x72,0xC6, 0xF0} };
const GUID IID_IMercuryFPrtX4 = {0x38FC4258, 0xEFAC, 0x49CE,{ 0x82, 0x15, 0xB3,0xED, 0x20, 0x4C,0x5E, 0x7A} };
const GUID IID_IMercuryFPrt5 = {0x66636E2A, 0x5015, 0x4156,{ 0x9D, 0x06, 0xFC,0x6F, 0x63, 0x19,0x42, 0x54} };
const GUID IID_IMercuryFPrtX5 = {0xD3FA84FF, 0x677F, 0x4244,{ 0xAE, 0xFB, 0xE8,0x34, 0x3E, 0xF7,0xC7, 0x06} };
const GUID IID_IMercuryFPrt6 = {0xFDC67547, 0x0246, 0x4854,{ 0x9F, 0x84, 0xC7,0xEE, 0x4E, 0x93,0xFB, 0x9B} };
const GUID IID_IMercuryFPrtX6 = {0x44595440, 0x34C5, 0x4FCA,{ 0xA3, 0xBE, 0x15,0x4B, 0xD9, 0x80,0xC7, 0xBA} };
const GUID IID_IMercuryFPrt7 = {0x9549BA81, 0x6015, 0x4DA1,{ 0x99, 0x6E, 0x53,0x34, 0x7C, 0xD5,0x7A, 0xBE} };
const GUID IID_IMercuryFPrtX7 = {0x3D5A10AD, 0x307C, 0x49D4,{ 0xA5, 0x9B, 0x70,0xFF, 0xEE, 0x15,0x9C, 0xB2} };
const GUID IID_IMercuryFPrt8 = {0x9397BB3C, 0x769E, 0x47E2,{ 0x8C, 0x0D, 0x02,0x8A, 0x38, 0xB5,0xD4, 0x8F} };
const GUID IID_IMercuryFPrtX8 = {0x116A8129, 0x4171, 0x4B1D,{ 0x8A, 0x49, 0x67,0x24, 0xA8, 0xE9,0x75, 0xDD} };
const GUID IID_IMercuryFPrt9 = {0xB9F07D55, 0x3587, 0x4FFE,{ 0xBF, 0xA8, 0x0F,0x1B, 0xFE, 0x05,0x55, 0x4F} };
const GUID IID_IMercuryFPrtX9 = {0x47D80BD0, 0x5B41, 0x4BFE,{ 0x98, 0xAA, 0x9E,0x76, 0xBA, 0x94,0xF3, 0x7E} };
const GUID IID_IMercuryFPrt10 = {0xC389388E, 0xBCC0, 0x4580,{ 0x86, 0x73, 0x47,0x19, 0x34, 0x31,0xC2, 0xC3} };
const GUID IID_IMercuryFPrtX10 = {0x10ECF5F7, 0x72AB, 0x4B70,{ 0x8B, 0xB9, 0x42,0x97, 0xAC, 0x4B,0x8E, 0xC3} };
const GUID CLSID_MercuryFPrtCOM = {0x140A3451, 0xBB71, 0x4DE3,{ 0x87, 0xE5, 0xE1,0x35, 0x77, 0xDE,0xFC, 0xD1} };
const GUID CLSID_MercuryFPrtX = {0xED0257F0, 0x3434, 0x4934,{ 0xB6, 0xA9, 0xD3,0x7E, 0x14, 0xC5,0x59, 0x86} };

};     // namespace Mercfprtx_tlb
