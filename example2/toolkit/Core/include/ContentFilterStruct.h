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

#ifndef __CONTENTFILTERSTRUCT_H_
#define __CONTENTFILTERSTRUCT_H_
#if TB5_FILTER

#include "ContentFilterElementStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Stores a content filter for a filter (the where clauses). */
//lint -sem(ContentFilterStruct::clear, cleanup)
//lint -sem(ContentFilterStruct::clear, initializer)
typedef struct ContentFilterStruct
{
	unsigned elements_count;
	ContentFilterElementStruct* elements;


#ifdef OT_COMPILATION
	ContentFilterStruct();
	EnumStatusCode setElements(unsigned ElementsCount, const ContentFilterElementStruct* Elements);
	EnumStatusCode addElement(const ContentFilterElementStruct* pContentFilterElement);

	EnumStatusCode set(const ContentFilterStruct&);
	EnumStatusCode get(ContentFilterStruct&) const;
	EnumStatusCode set(const OpcUa_ContentFilter&);
	EnumStatusCode get(OpcUa_ContentFilter&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;


	const ContentFilterStruct& operator=(const ContentFilterStruct& cp);
	bool operator==(const ContentFilterStruct& toCompare) const;
	bool operator!=(const ContentFilterStruct& toCompare) const;
	bool operator<(const ContentFilterStruct& toCompare) const;
	bool operator>(const ContentFilterStruct& toCompare) const;

	int compare(const ContentFilterStruct* pTarget) const;

	void clear(void);
	~ContentFilterStruct(void);

#endif
}ContentFilterStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
