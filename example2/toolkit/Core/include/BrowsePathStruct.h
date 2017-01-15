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

#ifndef __BROWSEPATHSTRUCT_H_
#define __BROWSEPATHSTRUCT_H_

#include "NodeIdStruct.h"
#include "RelativePathStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure that defines a relative path from one node to another. */
//lint -sem(BrowsePathStruct::clear, cleanup)
//lint -sem(BrowsePathStruct::clear, initializer)
typedef struct BrowsePathStruct
{
	/*! NodeId of the starting Node for the browse path. */
	NodeIdStruct startingNode;

	/*! The path to follow from the startingNode. */
	RelativePathStruct relativePath;


#ifdef OT_COMPILATION
	BrowsePathStruct();

	EnumStatusCode set(const BrowsePathStruct&);
	EnumStatusCode get(BrowsePathStruct&) const;
	EnumStatusCode set(const OpcUa_BrowsePath&);
	EnumStatusCode get(OpcUa_BrowsePath&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;


	const BrowsePathStruct& operator=(const BrowsePathStruct& cp);
	bool operator==(const BrowsePathStruct& toCompare) const;
	bool operator!=(const BrowsePathStruct& toCompare) const;
	bool operator<(const BrowsePathStruct& toCompare) const;
	bool operator>(const BrowsePathStruct& toCompare) const;

	int compare(const BrowsePathStruct* pTarget) const;

	void clear(void);
	~BrowsePathStruct(void);

#endif
}BrowsePathStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
