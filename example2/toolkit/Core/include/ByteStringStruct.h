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

#ifndef BYTESTRINGSTRUCT_H
#define BYTESTRINGSTRUCT_H

#include "OTMemory.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(ByteStringStruct::clear, cleanup)
//lint -sem(ByteStringStruct::clear, initializer)
typedef struct ByteStringStruct
{
	OTUInt32          length;
	unsigned char*    pData;

#ifdef OT_COMPILATION
	ByteStringStruct(void);
	ByteStringStruct(const ByteStringStruct&);
	ByteStringStruct(const OTUInt32 size, const unsigned char* src);

	~ByteStringStruct(void);

	EnumStatusCode set(const ByteStringStruct& cp);
	EnumStatusCode get(ByteStringStruct& target) const;
	EnumStatusCode get(OTUInt32* len, unsigned char** ppData) const;

	EnumStatusCode init(const OTUInt32 size, const unsigned char* src);
	void clear();

	OTUInt32 getLength(void) const;
	const unsigned char* getData(void) const;

	EnumStatusCode alloc(OTUInt32 size);

	EnumStatusCode set(const OpcUa_ByteString& target);
	EnumStatusCode get(OpcUa_ByteString& target) const;

	bool operator==(const ByteStringStruct& bs) const;
	bool operator!=(const ByteStringStruct& bs) const;

	int compare(const ByteStringStruct& bs) const;
	int compare(const ByteStringStruct* bs) const;

	EnumStatusCode getStringFromUtf8_API(OTChar*& pTargetString) const;
	EnumStatusCode getStringFromUtf8(tstring& targetString) const;
	EnumStatusCode setUtf8FromString(const OTChar* pString);

	tstring toString(void) const;

	ByteStringStruct& operator=(const ByteStringStruct& src);

private:
	ByteStringStruct& operator=(const OpcUa_ByteString& src);

#endif
} ByteStringStruct;

typedef ByteStringStruct XmlElementStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// BYTESTRINGSTRUCT_H
