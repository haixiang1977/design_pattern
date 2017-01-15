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

#ifndef _ReadProcessedDetailsStruct_H_
#define _ReadProcessedDetailsStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "DateTimeStruct.h"
#include "NodeIdStruct.h"
#include "AggregateConfigurationStruct.h"

/*! Specifies the details used to perform a 'processed' history read */
//lint -sem(ReadProcessedDetailsStruct::clear, cleanup)
//lint -sem(ReadProcessedDetailsStruct::clear, initializer)
typedef struct ReadProcessedDetailsStruct
{
	/*! Beginning of period to read */
	DateTimeStruct startTime;

	/*! End of period to read */
	DateTimeStruct endTime;

	/*! Interval between returned Aggregate values. The value 0 indicates that there
	 * is no ProcessingInterval defined. */
	OTDouble processingInterval;

	/*! The NodeId of the HistoryAggregate object that indicates the list of Aggregates to
	 *  be used when retrieving processed history. See [UA Part 13] for details. */
	NodeIdStruct* pAggregateType;
	unsigned pAggregateType_count;

	/*! Aggregate configuration structure */
	AggregateConfigurationStruct aggregateConfiguration;

#ifdef OT_COMPILATION
	ReadProcessedDetailsStruct();
	ReadProcessedDetailsStruct(const ReadProcessedDetailsStruct&);

	EnumStatusCode set(const ReadProcessedDetailsStruct&);
	EnumStatusCode get(ReadProcessedDetailsStruct&) const;

	EnumStatusCode set(const OpcUa_ReadProcessedDetails&);
	EnumStatusCode get(OpcUa_ReadProcessedDetails&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;

	const ReadProcessedDetailsStruct& operator=(const ReadProcessedDetailsStruct& cp);
	bool operator==(const ReadProcessedDetailsStruct& toCompare) const;
	bool operator!=(const ReadProcessedDetailsStruct& toCompare) const;
	bool operator<(const ReadProcessedDetailsStruct& toCompare) const;
	bool operator>(const ReadProcessedDetailsStruct& toCompare) const;

	int compare(const ReadProcessedDetailsStruct* pTarget) const;

	void clear(void);
	~ReadProcessedDetailsStruct(void);
#endif
} ReadProcessedDetailsStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
