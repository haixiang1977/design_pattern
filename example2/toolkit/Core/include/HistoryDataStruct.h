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

#ifndef __HISTORYDATASTRUCT_H_
#define __HISTORYDATASTRUCT_H_
#if TB5_HISTORY

#include "DataValueStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(HistoryDataStruct::clear, cleanup)
//lint -sem(HistoryDataStruct::clear, initializer)
typedef struct HistoryDataStruct
{
	OTUInt32 dataValues_count;
	DataValueStruct* dataValues;

#ifdef OT_COMPILATION
	HistoryDataStruct();

	EnumStatusCode set(const HistoryDataStruct&);
	EnumStatusCode get(HistoryDataStruct&) const;
	EnumStatusCode set(const OpcUa_HistoryData&, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_HistoryData&, const std::vector<tstring>& preferredLocales) const;

	const HistoryDataStruct& operator=(const HistoryDataStruct& cp);
	bool operator==(const HistoryDataStruct& toCompare) const;
	bool operator!=(const HistoryDataStruct& toCompare) const;
	bool operator<(const HistoryDataStruct& toCompare) const;
	bool operator>(const HistoryDataStruct& toCompare) const;

	int compare(const HistoryDataStruct* pTarget) const;

	void clear(void);
	~HistoryDataStruct(void);

#endif
}HistoryDataStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif
