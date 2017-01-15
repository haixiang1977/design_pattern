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

#ifndef __MONITORINGCHANGESTRUCT_H_
#define __MONITORINGCHANGESTRUCT_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


/*! This class is meant to describe the monitoring state of a node in the address space. */
//lint -sem(MonitoringChangeStruct::clear, cleanup)
//lint -sem(MonitoringChangeStruct::clear, initializer)
typedef struct MonitoringChangeStruct
{
	/*! The minimum sampling interval that is used by all monitored items monitoring a specific node. */
	double minimumSamplingInterval;

	/*! The monitoring state of the node before the last change. */
	EnumMonitoringState previousState;

	/*! The current monitoring state for the monitored item. */
	EnumMonitoringState currentState;

	/*! The attribute of the node that is monitored. */
	EnumAttributeId monitoredAttribute;

#ifdef OT_COMPILATION
	MonitoringChangeStruct();
	MonitoringChangeStruct(const MonitoringChangeStruct&);

	EnumStatusCode set(const MonitoringChangeStruct&);
	EnumStatusCode get(MonitoringChangeStruct&) const;


	const MonitoringChangeStruct& operator=(const MonitoringChangeStruct& cp);
	bool operator==(const MonitoringChangeStruct& toCompare) const;
	bool operator!=(const MonitoringChangeStruct& toCompare) const;
	bool operator<(const MonitoringChangeStruct& toCompare) const;
	bool operator>(const MonitoringChangeStruct& toCompare) const;

	int compare(const MonitoringChangeStruct* pTarget) const;

	void clear(void);
	~MonitoringChangeStruct(void);

#endif
}MonitoringChangeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
