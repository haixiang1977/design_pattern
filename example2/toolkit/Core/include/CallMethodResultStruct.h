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

#ifndef __CALLMETHODRESULTSTRUCT_H_
#define __CALLMETHODRESULTSTRUCT_H_

#include "ValueStruct.h"
#include "DiagnosticInfoStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(CallMethodResultStruct::clear, cleanup)
//lint -sem(CallMethodResultStruct::clear, initializer)
typedef struct CallMethodResultStruct
{
	unsigned pInputArgumentResults_count;
	EnumStatusCode* pInputArgumentResults;

	unsigned pOutputArguments_count;
	ValueStruct* pOutputArguments;

	EnumStatusCode statusCode;

	DiagnosticInfoStruct* pInputArgumentDiagnosticInfos;
	unsigned pInputArgumentDiagnosticInfos_count;

#ifdef OT_COMPILATION
	CallMethodResultStruct();
	EnumStatusCode getInputArgumentResults(unsigned* pCount, EnumStatusCode** ppValues);
	EnumStatusCode setOutputArguments(unsigned OutputArgumentsCount, const ValueStruct* OutputArguments);
	EnumStatusCode addOutputArgument(const ValueStruct* pValue);

	EnumStatusCode set(const CallMethodResultStruct&);
	EnumStatusCode get(CallMethodResultStruct&) const;
	EnumStatusCode set(const OpcUa_CallMethodResult&);
	EnumStatusCode get(OpcUa_CallMethodResult&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;


	const CallMethodResultStruct& operator=(const CallMethodResultStruct& cp);
	bool operator==(const CallMethodResultStruct& toCompare) const;
	bool operator!=(const CallMethodResultStruct& toCompare) const;
	bool operator<(const CallMethodResultStruct& toCompare) const;
	bool operator>(const CallMethodResultStruct& toCompare) const;

	int compare(const CallMethodResultStruct* pTarget) const;

	void clear(void);
	~CallMethodResultStruct(void);

#endif
}CallMethodResultStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
