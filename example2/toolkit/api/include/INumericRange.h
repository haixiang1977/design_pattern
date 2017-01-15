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

#ifndef INUMERICRANGE_H
#define INUMERICRANGE_H

#include <vector>

namespace SoftingOPCToolbox5
{
	/*! The NumericRange data type is used to define a range of elements in
	* an array, a matrix, a ByteString, or a string.
	*
	* A NumericRange is a list of integer pairs <k_1, k_2>
	* whereas k_1 describes the lower and k_2 the higher bound
	* of the range. In order to describe a 2x2 matrix within a 4x4 matrix using
	* a NumericRange one would use the pair list (<0, 1>, <0, 1>) for the
	* upper left 2x2 matrix.
	*
	* @note		The NumericRange data type is actually transmitted as string across the wire.
	*			Therefore, the getParseResult() method must be used to verify that any NumericRange
	*			received by a client or server has been successfully parsed. */
	class TBC_EXPORT INumericRange
	{
	public:
		/*! Destructor */
		virtual ~INumericRange(){};

		/*! Returns whether the NumericRange was parsed successfully from string.
		*
		* The NumericRange data type is actually transmitted as string across the wire.
		* Therefore, the getParseResult() method must be used to verify that any NumericRange
		* received by a client or server has been successfully parsed. */
		virtual EnumStatusCode getParseResult() const = 0;

		/*! Returns the number of ranges (i.e. the number of dimensions). This method
		* is provided for convenience and returns the same result as getRange().size().
		*
		* @see getRanges() */
		virtual OTUInt32 getDimensions() const = 0;

		/*! Returns the range pairs for all dimensions. Each returned pair denotes the
		* range defined for one dimension. */
		virtual std::vector<std::pair<OTUInt32, OTUInt32> > getRanges() const = 0;
		/*! Adds a range pair for one dimension.
		*
		* A range spanning only one element (e.g. 5) is defined
		* by providing the element index both as lower and upper bound
		* (e.g. lower bound = 5, upper bound = 5). If a range is spanning
		* two or more elements, the lower bound must always be less than
		* the upper bound.
		*
		* @param lowerBound		The lower bound of the range to add
		* @param upperBound		The upper bound of the range to add */
		virtual EnumStatusCode addRange(OTUInt32 lowerBound, OTUInt32 upperBound) = 0;
		/*! @brief Adds a range pair for one dimension.
		*
		* @param range	The range pair whereas the first element denotes the lower
		*				and the second element the upper bound.
		*
		* @see addRange(OTUInt32, OTUInt32) */
		virtual EnumStatusCode addRange(const std::pair<OTUInt32, OTUInt32>& range) = 0;

		/*! Returns the size in bytes of the allocated storage capacity for (lower bound, upper bound)-pairs.
		* Each range pair requires 8 byte storage. */
		virtual OTUInt32 capacity() const = 0;
		/*! Reserves memory for the given number of (lower bound, upper bound)-pairs
		*
		* If the number of required range pairs can be estimated beforehand, reserving storage
		* capacity helps reducing heap fragmentation.
		*
		* @param n The number of range pairs for which memory will be reserved */
		virtual void reserve(OTUInt32 n) = 0;

		/*! Returns a string representation of the NumericRange. The string representation
		* conforms to the representation of the NumericRange that is found on the wire. */
		virtual tstring toString() const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const INumericRange* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const INumericRange& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const INumericRange* other) const = 0;
		/*! @overload */
		virtual int compare(const INumericRange& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const INumericRange& other) = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INumericRange& other) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end INumericRange
} // end namespace
#endif	// INUMERICRANGE_H
