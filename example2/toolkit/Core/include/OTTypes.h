/*****************************************************************************
*                                                                            *
*                     SOFTING Industrial Automation GmbH                     *
*                          Richard-Reitzner-Allee 6                          *
*                                D-85540 Haar                                *
*                        Phone: ++49-89-4 56 56-0                            *
*                          Fax: ++49-89-4 56 56-3 99                         *
*                                                                            *
*                            SOFTING CONFIDENTIAL                            *
*                                                                            *
*                     Copyright (C) SOFTING IA GmbH 2016                     *
*                             All Rights Reserved                            *
*                                                                            *
* NOTICE: All information contained herein is, and remains the property of   *
*   SOFTING Industrial Automation GmbH and its suppliers, if any. The intel- *
*   lectual and technical concepts contained herein are proprietary to       *
*   SOFTING Industrial Automation GmbH and its suppliers and may be covered  *
*   by German and Foreign Patents, patents in process, and are protected by  *
*   trade secret or copyright law. Dissemination of this information or      *
*   reproduction of this material is strictly forbidden unless prior         *
*   written permission is obtained from SOFTING Industrial Automation GmbH.  *
******************************************************************************
******************************************************************************
*                                                                            *
* PROJECT_NAME             OPC UA C++ Toolkit                                *
*                                                                            *
* VERSION                  5.52.0                                            *
*                                                                            *
* DATE                     26.09.2016                                        *
*                                                                            *
*****************************************************************************/

#ifndef _OTTYPES_H_
#define _OTTYPES_H_

#include "OSCompat.h"

//////////////////////////////////////////////////////////////////////////
// Legacy types provided for backwards compatibility with Toolkit V5.10
//////////////////////////////////////////////////////////////////////////
#ifdef OT_V510_TYPE_COMPATIBILITY
	typedef OTUInt8				SOCmnUInt8;
	typedef OTInt8				SOCmnInt8;
	typedef OTUInt16			SOCmnUInt16;
	typedef OTInt16				SOCmnInt16;
	typedef OTBoolean			SOCmnBoolean;
	typedef OTUInt32			SOCmnUInt32;
	typedef OTInt32				SOCmnInt32;
	typedef OTUInt64			SOCmnUInt64;
	typedef OTInt64				SOCmnInt64;
	typedef OTUInt32			SOCmnUInt;
	typedef OTInt32				SOCmnInt;
	typedef OTDouble			SOCmnDouble;
	typedef OTFloat				SOCmnFloat;
	typedef char				SOCmnSByte;
	typedef unsigned char		SOCmnByte;
	typedef void				SOCmnVoid;

	static const OTBoolean SOCmnBoolean_False = 0;
	static const OTBoolean SOCmnBoolean_True = !SOCmnBoolean_False;

	typedef unsigned int		uint32;
	typedef int					int32;
	typedef long long			int64;
	typedef unsigned long long	uint64;

	#ifdef SOOS_POSIX
		typedef void          VOID;
		typedef VOID *        LPVOID;

		typedef unsigned char  BYTE;
		typedef unsigned short WORD;
		typedef unsigned long  DWORD;
		typedef unsigned short USHORT;
		typedef unsigned long  ULONG;
		typedef unsigned long long ULONGLONG;
		typedef short int      SHORT;
		typedef long           LONG;
		typedef long long      LONGLONG;
		typedef float          FLOAT;
		typedef double         DOUBLE;
		typedef int            INT;
		typedef unsigned int   UINT;
		typedef int            BOOL;

		#ifndef TRUE
			#define TRUE 1
		#endif
		#ifndef FALSE
			#define FALSE 0
		#endif

		#define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
		#define MAKELONG(a, b)      ((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))
		#define LOWORD(l)           ((WORD)(l))
		#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
		#define LOBYTE(w)           ((BYTE)(w))
		#define HIBYTE(w)           ((BYTE)(((WORD)(w) >> 8) & 0xFF))
	#endif // SOOS_POSIX
#endif // OT_V510_TYPE_COMPATIBILITY

//////////////////////////////////////////////////////////////////////////
// Types used by the Toolkit C API
//////////////////////////////////////////////////////////////////////////
typedef void* TBHandle;
#ifdef SOOS_POSIX
	extern pthread_attr_t *opcua_p_thread_attr;
#endif

#endif
