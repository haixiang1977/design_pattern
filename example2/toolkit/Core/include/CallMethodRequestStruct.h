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

#ifndef __CALLMETHODREQUESTSTRUCT_H_
#define __CALLMETHODREQUESTSTRUCT_H_

#include "NodeIdStruct.h"
#include "ValueStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(CallMethodRequestStruct::clear, cleanup)
//lint -sem(CallMethodRequestStruct::clear, initializer)
typedef struct CallMethodRequestStruct
{
	NodeIdStruct objectId;

	NodeIdStruct methodId;

	unsigned inputArguments_count;
	ValueStruct* inputArguments;


#ifdef OT_COMPILATION
	CallMethodRequestStruct();
	EnumStatusCode addInputArgument(const ValueStruct* pValue);

	EnumStatusCode set(const CallMethodRequestStruct&);
	EnumStatusCode get(CallMethodRequestStruct&) const;
	EnumStatusCode set(const OpcUa_CallMethodRequest&);
	EnumStatusCode get(OpcUa_CallMethodRequest&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;


	const CallMethodRequestStruct& operator=(const CallMethodRequestStruct& cp);
	bool operator==(const CallMethodRequestStruct& toCompare) const;
	bool operator!=(const CallMethodRequestStruct& toCompare) const;
	bool operator<(const CallMethodRequestStruct& toCompare) const;
	bool operator>(const CallMethodRequestStruct& toCompare) const;

	int compare(const CallMethodRequestStruct* pTarget) const;

	void clear(void);
	~CallMethodRequestStruct(void);

#endif
}CallMethodRequestStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
