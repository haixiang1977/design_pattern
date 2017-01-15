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

#ifndef _HistoryEventFieldListStruct_H_
#define _HistoryEventFieldListStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "ValueStruct.h"

//lint -sem(HistoryEventFieldListStruct::clear, cleanup)
//lint -sem(HistoryEventFieldListStruct::clear, initializer)
typedef struct HistoryEventFieldListStruct
{
	/* The list of event fields */
	ValueStruct* pEventFields;
	unsigned pEventFields_count;


#ifdef OT_COMPILATION
	HistoryEventFieldListStruct();
	HistoryEventFieldListStruct(const HistoryEventFieldListStruct&);

	EnumStatusCode set(const HistoryEventFieldListStruct&);
	EnumStatusCode get(HistoryEventFieldListStruct&) const;

	EnumStatusCode set(const OpcUa_HistoryEventFieldList&, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_HistoryEventFieldList&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;

	const HistoryEventFieldListStruct& operator=(const HistoryEventFieldListStruct& cp);
	bool operator==(const HistoryEventFieldListStruct& toCompare) const;
	bool operator!=(const HistoryEventFieldListStruct& toCompare) const;
	bool operator<(const HistoryEventFieldListStruct& toCompare) const;
	bool operator>(const HistoryEventFieldListStruct& toCompare) const;

	int compare(const HistoryEventFieldListStruct* pTarget) const;

	void clear(void);
	~HistoryEventFieldListStruct(void);
#endif
} HistoryEventFieldListStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
