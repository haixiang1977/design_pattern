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

#ifndef INNERNUMERICRANGE_H
#define INNERNUMERICRANGE_H

#include "INumericRange.h"
#include "NumericRangeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! @brief A NumericRange selects a range of elements of
	*        a structure, an array, or a matrix.
	*
	* A NumericRange is a list of integer pairs <k_1, k_2>
	* whereas k_1 describes the lower and k_2 the higher bound
	* of the range. In order to describe a 2x2 matrix within a 4x4 matrix using
	* a NumericRange one would use the pair list (<0, 1>, <0, 1>) for the
	* upper left 2x2 matrix.
	*
	* The OPC Foundation defines the NumericRange type as string adhering to
	* a given BNF. This is also how the NumericRange is transmitted across the wire.
	* Therefore, the string has to be parsed on reception. In order to check whether
	* the received string was parsed correctly, the member getParseResult() is provided. */
	class TBC_EXPORT InnerNumericRange
		: public INumericRange
	{
	public:
		/*! Destructor */
		virtual ~InnerNumericRange();

		/*! Returns true, if the NumericRange contains no ranges. */
		OTUInt32 getDimensions() const;

		/*! Returns the ranges for all dimensions.
		*
		* Each pair denotes the range for one dimension. */
		std::vector<std::pair<OTUInt32, OTUInt32> > getRanges() const;

		/*! @brief Adds a range for a dimension.
		*
		* A range spanning only one element (e.g. 5) is defined
		* by providing the element index both as lower and upper bound
		* (e.g. lower bound = 5, upper bound = 5). If a range is spanning
		* two or more elements, the lower bound must always be less than
		* the upper bound.
		*
		* @param lowerBound The lower bound of the range to add
		* @param upperBound The upper bound of the range to add */
		EnumStatusCode addRange(OTUInt32 lowerBound, OTUInt32 upperBound);

		/*! @brief Adds a range for a dimension.
		*
		* @param range	The range pair whereas the first element denotes the lower
		*				and the second element the upper bound.
		*
		* @see addRange(OTUInt32, OTUInt32) */
		EnumStatusCode addRange(const std::pair<OTUInt32, OTUInt32>& range);

		/*! Returns the size of the allocated storage capacity for (lower bound, upper bound)-pairs.
		* Each range pair requires 8 Byte storage.
		*
		* @return the number of bytes reserved for range pairs */
		OTUInt32 capacity() const;

		/*! @brief Reserves memory for the given number of (lower bound, upper bound)-pairs
		*
		* If the number of required range pairs can be estimated beforehand, reserving storage
		* capacity helps reducing heap fragmentation.
		*
		* @param n the number of range pairs for which memory will be reserved */
		void reserve(OTUInt32 n);

		/*! Returns the NumericRange as string adhering to the BNF specified in OPC UA Spec. Part 4. */
		tstring toString() const;

		/*! Returns whether the NumericRange was parsed successfully if it was constructed from a string. */
		EnumStatusCode getParseResult() const;

		// init from otb handle
		void initInner(NumericRangeStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const INumericRange* other) const;
		/*! @overload */
		virtual int compare(const INumericRange& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const INumericRange& other);
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INumericRange& other);

		EnumStatusCode set(const INumericRange*);
		EnumStatusCode set(const INumericRange&);

		void* getInternHandle() const;

	private:
		NumericRangeStruct* m_content;
	}; // end INumericRange
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// INNERNUMERICRANGE_H
