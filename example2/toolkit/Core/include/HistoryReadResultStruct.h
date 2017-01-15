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

#ifndef __HISTORYREADRESULTSTRUCT_H_
#define __HISTORYREADRESULTSTRUCT_H_
#if TB5_HISTORY

#include "Enums.h"
#include "HistoryDataExtensionObjectStruct.h"
#include "ByteStringStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(HistoryReadResultStruct::clear, cleanup)
//lint -sem(HistoryReadResultStruct::clear, initializer)
typedef struct HistoryReadResultStruct
{
	/*! StatusCode for the requested node */
	EnumStatusCode statusCode;

	/*!
	 * This parameter is used only if the number of values to be returned is too large to be returned in a single response.
	 * When this parameter is not used, its value is null.
	 */
	ByteStringStruct continuationPoint;

	/*! The history data returned for the Node */
	HistoryDataExtensionObjectStruct data;

#ifdef OT_COMPILATION
	HistoryReadResultStruct();

	EnumStatusCode set(const HistoryReadResultStruct&);
	EnumStatusCode get(HistoryReadResultStruct&) const;
	EnumStatusCode set(const OpcUa_HistoryReadResult&, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_HistoryReadResult&, const std::vector<tstring>& preferredLocales) const;

	const HistoryReadResultStruct& operator=(const HistoryReadResultStruct& cp);
	bool operator==(const HistoryReadResultStruct& toCompare) const;
	bool operator!=(const HistoryReadResultStruct& toCompare) const;
	bool operator<(const HistoryReadResultStruct& toCompare) const;
	bool operator>(const HistoryReadResultStruct& toCompare) const;

	int compare(const HistoryReadResultStruct* pTarget) const;

	void clear(void);
	~HistoryReadResultStruct(void);

#endif
}HistoryReadResultStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif
