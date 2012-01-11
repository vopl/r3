

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Jan 12 12:03:46 2012
 */
/* Compiler settings for .\DecoratorLib.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IMgaMetaRegNode,0x83BA323D,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x02,0x38,0x75,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaConstraint,0x83BA3241,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaProject,0x83BA3243,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaBase,0xDB1E0FB7,0xC9CB,0x11D3,0x9A,0xD2,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaFolder,0x83BA3245,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaFCO,0x83BA3247,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaModel,0x83BA3249,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaAspect,0x83BA324B,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaRole,0x83BA324D,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaPart,0xA70CAB45,0xDD94,0x11D3,0x93,0x08,0x44,0x45,0x53,0x54,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaAtom,0x83BA324F,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaAttribute,0x83BA3259,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaEnumItem,0x83254259,0xB758,0x21D3,0x7B,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaReference,0x83BA3251,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaSet,0x83BA3253,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaConnection,0x83BA3255,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaConnJoint,0x83BA3257,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaPointerSpec,0x83BA325B,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaPointerItem,0x83518A5B,0xB758,0x11D3,0xAB,0xAE,0x00,0x69,0x28,0x36,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaAspects,0xc61352b0,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaRoles,0xc851e130,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaFCOs,0xc66a6c60,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaAttributes,0xc6922740,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaFolders,0xc6b85af0,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaPointerSpecs,0xc761f8c0,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaRegNodes,0xc795ed20,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x27);


MIDL_DEFINE_GUID(IID, IID_IMgaConstraints,0xc8ec3720,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaParts,0xc8ec3720,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x27);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaModels,0xc8ec3723,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x27);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaConnJoints,0xc8432623,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x27);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaPointerItems,0xc8124623,0xc51d,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x27);


MIDL_DEFINE_GUID(IID, IID_IMgaMetaEnumItems,0xc8124623,0xc51d,0x1ad3,0x9a,0xd2,0x11,0xaa,0x01,0x76,0xfe,0x27);


MIDL_DEFINE_GUID(IID, IID_IMgaProject,0x270B4F92,0xB17C,0x11D3,0x9A,0xD1,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaEventSink,0x32D1F3A5,0xD276,0x11D3,0x9A,0xD5,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaAddOn,0x80A6D661,0xD411,0x11D3,0x9A,0xD5,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaComponent,0x11BB02D9,0x2E2C,0x11D3,0xB3,0x6D,0x00,0x60,0x08,0x2D,0xF8,0x84);


MIDL_DEFINE_GUID(IID, IID_IMgaComponentEx,0x11BB44D9,0x2E2C,0x11D3,0xB3,0x6D,0x00,0x60,0x08,0x2D,0xF8,0x84);


MIDL_DEFINE_GUID(IID, IID_IMgaClient,0xF07EE1A2,0x2D53,0x449b,0xA2,0xDA,0x45,0xA1,0xA9,0x11,0x0E,0x53);


MIDL_DEFINE_GUID(IID, DIID_IMgaComponentDispatch,0x52871786,0x9C85,0x408f,0xA7,0xD1,0xAE,0x50,0x79,0x05,0xA5,0x40);


MIDL_DEFINE_GUID(IID, IID_IMgaTerritory,0x32D1F3A3,0xD276,0x11D3,0x9A,0xD5,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaObject,0x32D1F3A7,0xD276,0x11D3,0x9A,0xD5,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaFCO,0x270B4F98,0xB17C,0x11D3,0x9A,0xD1,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaFolder,0x270B4F96,0xB17C,0x11D3,0x9A,0xD1,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaModel,0x270B4F9A,0xB17C,0x11D3,0x9A,0xD1,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaAtom,0x270B4F9C,0xB17C,0x11D3,0x9A,0xD1,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaPart,0x270B4F9E,0xB17C,0x11D3,0x9A,0xD1,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaReference,0x83BA3233,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaSet,0x83BA3235,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaConnection,0x270B4FA0,0xB17C,0x11D3,0x9A,0xD1,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaSimpleConnection,0x83BA3237,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaConnPoint,0xcb8fa000,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaRegNode,0x83BA323D,0xB758,0x11D3,0xAB,0xAE,0x00,0x00,0x00,0x00,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IMgaFilter,0xc8f6e970,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaAttribute,0xCBF20084,0xBD43,0x11D3,0x9A,0xD2,0x00,0xAA,0x00,0xB6,0xFE,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaFolders,0xc59c2210,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaFCOs,0xc5f4c2f0,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaAttributes,0xc6f3f340,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaParts,0xc71a26f0,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaConnPoints,0xc7f19c60,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaRegNodes,0xc79f1840,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaAddOns,0xc8a5ec80,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaTerritories,0xc87caa70,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaComponents,0xc8cda760,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaClients,0xc9d8df93,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaObjects,0xc5aac2f0,0xc1fd,0x11d3,0x9a,0xd2,0x00,0xaa,0x00,0xb6,0xfe,0x26);


MIDL_DEFINE_GUID(IID, IID_IMgaO,0xC356B135,0x961D,0x4B6C,0x8B,0x1F,0x25,0x7E,0x19,0x11,0x7C,0xC1);


MIDL_DEFINE_GUID(IID, IID_IMgaDataSource,0x9FF8F4E0,0xE0C9,0x11d3,0xB3,0x76,0x00,0x50,0x04,0xD3,0x85,0x90);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEApp,0x81191A44,0xB898,0x4143,0xBF,0x8B,0xCA,0x75,0x01,0xFE,0xC1,0x9A);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEIt,0xF2181278,0x749F,0x459d,0x87,0x00,0x92,0xF0,0x88,0xB8,0x0D,0x72);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEModel,0x399A16A0,0xD209,0x4d00,0x9B,0xDF,0x85,0x8D,0x87,0xEC,0x46,0x41);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEAspect,0xEDEEB1F8,0xBC44,0x40d2,0xBE,0x91,0x83,0xE8,0xCC,0xD5,0x98,0x45);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEPanel,0xC047FAEB,0x7AE7,0x40fb,0x8C,0x5C,0x90,0xC7,0x3D,0xAD,0x4B,0xC6);


MIDL_DEFINE_GUID(IID, IID_IGMEOLEColl,0x36C7B797,0x6BDE,0x46d0,0x88,0x70,0x70,0x18,0x90,0x00,0xED,0xF9);


MIDL_DEFINE_GUID(IID, IID_IMgaVersionInfo,0x9A228010,0x020B,0x11d2,0xBB,0xB3,0x00,0x40,0x05,0x1F,0x71,0x17);


MIDL_DEFINE_GUID(IID, IID_IMgaDecorator,0x1E13054E,0x5AD1,0x41EB,0x8F,0xF1,0xC3,0x90,0x1D,0x99,0xFD,0xCC);


MIDL_DEFINE_GUID(IID, IID_IMgaCommonDecoratorEvents,0xD25188F5,0x3ECF,0x433e,0x85,0xC5,0x8B,0x95,0x74,0xCA,0x26,0x4C);


MIDL_DEFINE_GUID(IID, IID_IMgaDecoratorCommon,0x91004115,0x2D1F,0x44a8,0xB6,0xA0,0x09,0xA2,0x75,0x0B,0xF2,0x78);


MIDL_DEFINE_GUID(IID, IID_IMgaElementDecoratorEvents,0x1D63D045,0x28C9,0x4902,0x8E,0x5F,0x46,0xF4,0xAC,0x1F,0x8C,0x5B);


MIDL_DEFINE_GUID(IID, IID_IMgaElementDecorator,0x2BEAD76C,0x126E,0x405D,0xAA,0xC6,0xB9,0xCA,0x39,0x06,0x70,0x06);


MIDL_DEFINE_GUID(IID, IID_IMgaResolver,0x461F30B0,0x3BF0,0x11D4,0xB3,0xF0,0x00,0x50,0x04,0xD3,0x85,0x90);


MIDL_DEFINE_GUID(IID, IID_IMgaRegistrar,0xF1D6BB05,0x42EE,0x11D4,0xB3,0xF4,0x00,0x50,0x04,0xD3,0x85,0x90);


MIDL_DEFINE_GUID(IID, IID_IMgaLauncher,0xD03EC326,0x447B,0x11D4,0xB3,0xF6,0x00,0x50,0x04,0xD3,0x85,0x90);


MIDL_DEFINE_GUID(IID, IID_IMgaProgressDlg,0xD0317326,0x447B,0x12D4,0xB3,0xF6,0x00,0x50,0x04,0xD3,0x85,0x90);


MIDL_DEFINE_GUID(IID, IID_IMgaComponentProxy,0xFF01497A,0x36EB,0x4EA7,0xBE,0x44,0x2F,0xA9,0x8B,0xD7,0x03,0xDB);


MIDL_DEFINE_GUID(IID, IID_IMgaClosure,0x74348E5A,0xC76D,0x4c2e,0x88,0xD5,0xD9,0x68,0xC0,0x1C,0xE4,0x32);


MIDL_DEFINE_GUID(IID, IID_IMgaEventLogger,0x9D46C230,0x31A5,0x4248,0xB6,0x1E,0x42,0x23,0xFA,0x6A,0x7F,0x7A);


MIDL_DEFINE_GUID(IID, IID_IMetaParser,0x70C41B24,0xE3CE,0x11D3,0xB3,0x7A,0x00,0x50,0x04,0xD3,0x85,0x90);


MIDL_DEFINE_GUID(IID, IID_IMgaDumper,0xA5D0DAE6,0x16EE,0x11D4,0xB3,0xC2,0x00,0x50,0x04,0xD3,0x85,0x90);


MIDL_DEFINE_GUID(IID, IID_IMgaParser,0x94D6FB53,0x1F7C,0x11D4,0xB3,0xD0,0x00,0x50,0x04,0xD3,0x85,0x90);


MIDL_DEFINE_GUID(IID, LIBID_DecoratorLib,0xCAB05A05,0xF6A5,0x4f89,0x91,0xF5,0x81,0x82,0x6E,0x95,0x8A,0x5C);


MIDL_DEFINE_GUID(CLSID, CLSID_Decorator,0xC8054B76,0x4760,0x4a4d,0x8B,0x03,0x59,0x90,0xDF,0x0B,0x88,0x62);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



