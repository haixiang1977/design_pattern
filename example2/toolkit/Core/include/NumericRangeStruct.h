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

#ifndef _NUMERICRANGESTRUCT_H_
#define _NUMERICRANGESTRUCT_H_

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

/*!
 * @brief A NumericRange selects a range of elements of
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
 * the received string was parsed correctly, the member @ref parseResult is provided.
 */
//lint -sem(NumericRangeStruct::clear, cleanup)
//lint -sem(NumericRangeStruct::clear, initializer)
//lint -sem(NumericRangeStruct::parse,initializer)
typedef struct NumericRangeStruct
{
	OTUInt32 pairCount;
	OTUInt32* pairElement;

	/*!
	 * @brief If the NumericRange was parsed from string representation, this member
	 *        holds the parse result.
	 */
	EnumStatusCode parseResult;

	/*!
	 * FOR INTERNAL USE ONLY
	 *
	 * Holds the number of bytes assigned to the @p pairElement member
	 */
	OTUInt32 pairElementCapacity;

#ifdef OT_COMPILATION
	NumericRangeStruct(void);
	NumericRangeStruct(const NumericRangeStruct& cp);
	NumericRangeStruct(const tstring& numericRange);

	EnumStatusCode set(const NumericRangeStruct& source);
	EnumStatusCode get(NumericRangeStruct& target) const;

	EnumStatusCode set(const OpcUa_String& cp);
	EnumStatusCode get(OpcUa_String& target) const;

	const NumericRangeStruct& operator=(const NumericRangeStruct& cp);
	bool operator==(const NumericRangeStruct& cp) const;
	bool operator!=(const NumericRangeStruct& cp) const;

	int compare(const NumericRangeStruct* with) const;

	/*!
	 * @brief Returns the size of the allocated storage capacity
	 *        for range pairs
	 *
	 * Each range pair requires 8 Byte storage.
	 *
	 * @return the number of bytes reserved for range pairs
	 */
	OTUInt32 capacity() const;

	/*!
	 * @brief Reserves the given amount of bytes for storing range pairs
	 *
	 * If you know in advance how many range pairs you will add, reserving
	 * storage capacity will help reducing heap fragmentation.
	 *
	 * @param n the number of bytes that will be reserved for range pairs
	 */
	void reserve(OTUInt32 n);

	/*!
	 * @brief Adds a range pair
	 *
	 * @param lowerBound the lower bound of the range
	 * @param upperBound the upper bound of the range
	 *
	 * Precondition: lowerBound <= upperBound
	 */
	EnumStatusCode addRange(OTUInt32 lowerBound, OTUInt32 upperBound);

	/*!
	 * @brief Returns the ranges for all dimensions
	 */
	std::vector<std::pair<OTUInt32, OTUInt32 > > getRanges() const;

	/*!
	 * @brief Parses a NumericRange provided as string adhering to the
	 *        BNF specified in OPC UA Spec. Part 4
	 *
	 * @param numericRange the NumericRange to parse
	 */
	void parse(const std::string& numericRange);
#ifdef _UNICODE
	void parse(const std::wstring& numericRange);
#endif

	/*!
	 * @brief Returns the NumericRange as string adhering to the BNF
	 *        specified in OPC UA Spec. Part 4
	 */
	tstring toString() const;

	void clear(void);
	~NumericRangeStruct(void);

#endif
}NumericRangeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif // _NUMERICRANGESTRUCT_H_


