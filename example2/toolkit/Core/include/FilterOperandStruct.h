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

#ifndef __FILTEROPERANDSTRUCT_H_
#define __FILTEROPERANDSTRUCT_H_
#if TB5_FILTER
#include "LiteralOperandStruct.h"
#include "ElementOperandStruct.h"
#include "AttributeOperandStruct.h"
#include "SimpleAttributeOperandStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Stores an operand used in the filters where clauses (contaent filter). */
//lint -sem(FilterOperandStruct::clear, cleanup)
//lint -sem(FilterOperandStruct::clear, initializer)
typedef struct FilterOperandStruct
{
	union
	{
		LiteralOperandStruct* lit;
		ElementOperandStruct* element;
		AttributeOperandStruct* attribute;
		SimpleAttributeOperandStruct* simpleAttribute;
	}
	operand;
	EnumFilterOperand type;

#ifdef OT_COMPILATION
	FilterOperandStruct();

	EnumStatusCode set(const FilterOperandStruct&);
	EnumStatusCode get(FilterOperandStruct&) const;

	EnumStatusCode set(const OpcUa_ExtensionObject& src);
	EnumStatusCode get(OpcUa_ExtensionObject& target, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode setLiteralOperand_API(const LiteralOperandStruct* value);
	EnumStatusCode setElementOperand_API(const ElementOperandStruct* value);
	EnumStatusCode setAttributeOperand_API(const AttributeOperandStruct* value);
	EnumStatusCode setSimpleAttributeOperand_API(const SimpleAttributeOperandStruct* value);


	const FilterOperandStruct& operator=(const FilterOperandStruct& cp);
	bool operator==(const FilterOperandStruct& toCompare) const;
	bool operator!=(const FilterOperandStruct& toCompare) const;
	bool operator<(const FilterOperandStruct& toCompare) const;
	bool operator>(const FilterOperandStruct& toCompare) const;

	int compare(const FilterOperandStruct* pTarget) const;

	void clear(void);
	~FilterOperandStruct(void);

#endif
}FilterOperandStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
