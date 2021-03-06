

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Fri Jul 23 23:54:58 2010
 */
/* Compiler settings for .\tmailx.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
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

MIDL_DEFINE_GUID(IID, IID_IMessageHeader,0x4D9B8FE2,0xE781,0x4B07,0x90,0xA4,0xF5,0xA1,0x18,0xDA,0xCF,0x55);


MIDL_DEFINE_GUID(IID, IID_IHeaders,0x883A711E,0x6C77,0x4ACF,0x80,0x4F,0x76,0x7C,0xFC,0x0D,0xC5,0x0A);


MIDL_DEFINE_GUID(IID, IID_IContent,0x798F3451,0x59A0,0x4F09,0x92,0x68,0xC7,0x30,0x33,0x4C,0x38,0x4C);


MIDL_DEFINE_GUID(IID, IID_IContents,0x3716A914,0x91E2,0x4034,0x84,0xE6,0x2D,0xEB,0x11,0x4F,0xC5,0x54);


MIDL_DEFINE_GUID(IID, IID_IMail,0xC19ED2A0,0x7414,0x474C,0xBB,0x5E,0x07,0x3A,0x9D,0x0F,0x2F,0xEA);


MIDL_DEFINE_GUID(IID, IID_IOptions,0x3278D320,0x60C2,0x43B4,0xAB,0x95,0xFE,0xAA,0x8A,0x17,0xD6,0x70);


MIDL_DEFINE_GUID(IID, IID_ISmtp,0x44A1A6DF,0xEC33,0x430C,0x99,0xF3,0x5A,0x68,0x57,0xE2,0x04,0x8E);


MIDL_DEFINE_GUID(IID, IID_IPop3,0x7DA5678A,0x76A1,0x4278,0xB2,0x89,0xD4,0xBD,0x95,0xF3,0x86,0x0B);


MIDL_DEFINE_GUID(IID, LIBID_TMail,0xFB454128,0x13C3,0x483E,0x83,0xE7,0x5B,0x74,0xB5,0xD9,0xB3,0x36);


MIDL_DEFINE_GUID(CLSID, CLSID_Content,0x2757F0DB,0xAC05,0x4096,0xB9,0xD4,0xDB,0x7D,0x27,0x6A,0xD6,0xE1);


MIDL_DEFINE_GUID(CLSID, CLSID_MessageHeader,0xB7AF3F6D,0xC7B7,0x4314,0xB5,0x84,0x22,0xB6,0x38,0xB4,0x1C,0x85);


MIDL_DEFINE_GUID(CLSID, CLSID_Headers,0x7559924E,0x8109,0x4D49,0x86,0x2C,0xD2,0x01,0x3C,0x37,0xCA,0x21);


MIDL_DEFINE_GUID(CLSID, CLSID_Contents,0x19D91141,0x36EC,0x4DAC,0xB3,0x17,0xB9,0x18,0x80,0xC6,0xDB,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_Mail,0x09D7A000,0x1E25,0x4F02,0xA9,0xC2,0x46,0xF1,0x39,0xC9,0x1A,0xC6);


MIDL_DEFINE_GUID(IID, DIID__IClientEvents,0x0E41DE9B,0x7DDB,0x4C8B,0xB5,0x7D,0xC9,0x0C,0xCD,0x16,0xD9,0x78);


MIDL_DEFINE_GUID(CLSID, CLSID_Options,0x819F3AA3,0x3045,0x47F3,0x9A,0x22,0x69,0x80,0x6E,0xE4,0xDC,0x62);


MIDL_DEFINE_GUID(CLSID, CLSID_Smtp,0xEB4CB7F1,0x7770,0x44D4,0x91,0x67,0xEF,0xDB,0x48,0xFF,0xE1,0xC5);


MIDL_DEFINE_GUID(CLSID, CLSID_Pop3,0xA967542B,0x6A74,0x4F6C,0x8E,0x72,0xFC,0x91,0x55,0xF4,0xD7,0x7A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



