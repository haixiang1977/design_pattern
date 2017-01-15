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

#ifndef __SIGNATUREDATASTRUCT_H_
#define __SIGNATUREDATASTRUCT_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


/*! Stores the data of a signature. */
//lint -sem(SignatureDataStruct::clear, cleanup)
//lint -sem(SignatureDataStruct::clear, initializer)
typedef struct SignatureDataStruct
{
	/*! The signatures data */
	ByteStringStruct signature;

	/*! The algorithm used to create the siganture. */
	TCHAR* pAlgorithm;


#ifdef OT_COMPILATION
	SignatureDataStruct();
	EnumStatusCode setSignature(unsigned length, const unsigned char* pValue);
	EnumStatusCode getSignature(unsigned* pLength, unsigned char** pValue);
	EnumStatusCode setAlgorithm(const TCHAR* pValue);

	EnumStatusCode set(const SignatureDataStruct&);
	EnumStatusCode get(SignatureDataStruct&) const;
	EnumStatusCode set(const OpcUa_SignatureData&);
	EnumStatusCode get(OpcUa_SignatureData&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;


	const SignatureDataStruct& operator=(const SignatureDataStruct& cp);
	bool operator==(const SignatureDataStruct& toCompare) const;
	bool operator!=(const SignatureDataStruct& toCompare) const;
	bool operator<(const SignatureDataStruct& toCompare) const;
	bool operator>(const SignatureDataStruct& toCompare) const;

	int compare(const SignatureDataStruct* pTarget) const;

	void clear(void);
	~SignatureDataStruct(void);

#endif
}SignatureDataStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
