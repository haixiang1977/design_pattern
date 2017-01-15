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

#ifndef _SemanticChangeStructureDataTypeStruct_H_
#define _SemanticChangeStructureDataTypeStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "NodeIdStruct.h"

//lint -sem(SemanticChangeStructureDataTypeStruct::clear, cleanup)
//lint -sem(SemanticChangeStructureDataTypeStruct::clear, initializer)
typedef struct SemanticChangeStructureDataTypeStruct
{
	/*! NodeId of the Node that owns the Property that has changed. */
	NodeIdStruct affected;

	/*! If the affected Node was an Object or Variable, affectedType contains
	 * the NodeId of the TypeDefinitionNode of the affected Node.
	 * Otherwise it is set to null. */
	NodeIdStruct affectedType;


#ifdef OT_COMPILATION
	SemanticChangeStructureDataTypeStruct();
	SemanticChangeStructureDataTypeStruct(const SemanticChangeStructureDataTypeStruct&);

	EnumStatusCode set(const SemanticChangeStructureDataTypeStruct&);
	EnumStatusCode get(SemanticChangeStructureDataTypeStruct&) const;

	EnumStatusCode set(const OpcUa_SemanticChangeStructureDataType&);
	EnumStatusCode get(OpcUa_SemanticChangeStructureDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;

	const SemanticChangeStructureDataTypeStruct& operator=(const SemanticChangeStructureDataTypeStruct& cp);
	bool operator==(const SemanticChangeStructureDataTypeStruct& toCompare) const;
	bool operator!=(const SemanticChangeStructureDataTypeStruct& toCompare) const;
	bool operator<(const SemanticChangeStructureDataTypeStruct& toCompare) const;
	bool operator>(const SemanticChangeStructureDataTypeStruct& toCompare) const;

	int compare(const SemanticChangeStructureDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~SemanticChangeStructureDataTypeStruct(void);
#endif
} SemanticChangeStructureDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
