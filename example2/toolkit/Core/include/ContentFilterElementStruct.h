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

#ifndef __CONTENTFILTERELEMENTSTRUCT_H_
#define __CONTENTFILTERELEMENTSTRUCT_H_
#if TB5_FILTER

#include "FilterOperandStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Stroes an element from a ContentFilter. */
//lint -sem(ContentFilterElementStruct::clear, cleanup)
//lint -sem(ContentFilterElementStruct::clear, initializer)
typedef struct ContentFilterElementStruct
{
	EnumFilterOperator filterOperator;

	OTUInt32 filterOperands_count;
	FilterOperandStruct* filterOperands;


#ifdef OT_COMPILATION
	ContentFilterElementStruct();
	EnumStatusCode setFilterOperands(unsigned FilterOperandsCount, const FilterOperandStruct* FilterOperands);
	EnumStatusCode addFilterOperand(const FilterOperandStruct* pFilterOperand);

	EnumStatusCode set(const ContentFilterElementStruct&);
	EnumStatusCode get(ContentFilterElementStruct&) const;
	EnumStatusCode set(const OpcUa_ContentFilterElement&);
	EnumStatusCode get(OpcUa_ContentFilterElement&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;


	const ContentFilterElementStruct& operator=(const ContentFilterElementStruct& cp);
	bool operator==(const ContentFilterElementStruct& toCompare) const;
	bool operator!=(const ContentFilterElementStruct& toCompare) const;
	bool operator<(const ContentFilterElementStruct& toCompare) const;
	bool operator>(const ContentFilterElementStruct& toCompare) const;

	int compare(const ContentFilterElementStruct* pTarget) const;

	void clear(void);
	~ContentFilterElementStruct(void);

#endif
}ContentFilterElementStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
