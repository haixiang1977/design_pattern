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

#ifndef __READRAWMODIFIEDDETAILSSTRUCT_H_
#define __READRAWMODIFIEDDETAILSSTRUCT_H_

#include "DateTimeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure that defines a relative path from one node to another. */
//lint -sem(ReadRawModifiedDetailsStruct::clear, cleanup)
//lint -sem(ReadRawModifiedDetailsStruct::clear, initializer)
typedef struct ReadRawModifiedDetailsStruct
{
	/*! TRUE for Read Modified functionality, FALSE for Read Raw functionality */
	bool isReadModified;

	/*! Beginning of period to read. Set to default value of DateTime.MinValue if no specific start time is specified. */
	DateTimeStruct startTime;

	/*! End of period to read. Set to default value of DateTime.MinValue if no specific end time is specified. */
	DateTimeStruct endTime;

	/*! The maximum number of values returned for any Node over the time */
	OTUInt32 maxNumberOfValuesPerNode;

	/*! If true, bounding values should be returned */
	bool returnBounds;

#ifdef OT_COMPILATION
	ReadRawModifiedDetailsStruct();

	EnumStatusCode set(const ReadRawModifiedDetailsStruct&);
	EnumStatusCode get(ReadRawModifiedDetailsStruct&) const;
	EnumStatusCode set(const OpcUa_ReadRawModifiedDetails&);
	EnumStatusCode get(OpcUa_ReadRawModifiedDetails&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;

	const ReadRawModifiedDetailsStruct& operator=(const ReadRawModifiedDetailsStruct& cp);
	bool operator==(const ReadRawModifiedDetailsStruct& toCompare) const;
	bool operator!=(const ReadRawModifiedDetailsStruct& toCompare) const;
	bool operator<(const ReadRawModifiedDetailsStruct& toCompare) const;
	bool operator>(const ReadRawModifiedDetailsStruct& toCompare) const;

	int compare(const ReadRawModifiedDetailsStruct* pTarget) const;

	void clear(void);
	~ReadRawModifiedDetailsStruct(void);

#endif
}ReadRawModifiedDetailsStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
