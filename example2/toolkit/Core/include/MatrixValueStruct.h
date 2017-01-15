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

#ifndef _MATRIXVALUESTRUCT_H_
#define _MATRIXVALUESTRUCT_H_

#include "OTTypes.h"
#include "ValueUnion.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

/*!
*	@brief Correspond to OpcUa_VariantMatrixValue.
*	BAL 20.01.2009 actually it is implemented just for Int32.
*/
//lint -sem(MatrixValueStruct::clear, cleanup)
//lint -sem(MatrixValueStruct::clear, initializer)
typedef struct MatrixValueStruct
{
public:
	OTInt32  noOfDimensions;
	OTInt32* pDimensions;
	OTUInt16 datatype;
	/* The limit of the elements number. Actually limit the allocation
	 * to around 100Mb. If not limited, a few GBs can be easily reached
	 * with the multidimensional array.
	*/
	static const OTUInt32 MAX_ELEMENT_COUNT = 1024*1024*100;
	/* The data stored in the array.
	 *
	 * The higher rank dimensions appear in the array first.
	 * e.g. an array with dimensions [2,2,2] is written in this order:
	 * [0,0,0], [0,0,1], [0,1,0], [0,1,1], [1,0,0], [1,0,1], [1,1,0], [1,1,1]

	 * Using [3] to access the pointer stored in this field would return element [0,1,1] */
	ValueArrayUnion value;

#ifdef OT_COMPILATION

	MatrixValueStruct(void);
	/*!
		@brief Constructor with dimensions. Do not initialize the data, just fields related
		to dimension.
	*/
	EnumStatusCode set(OTInt32 NoOfDimensions,OTInt32* Dimensions);

	EnumStatusCode set(const MatrixValueStruct& cp);
	EnumStatusCode get(MatrixValueStruct& target) const;

	EnumStatusCode set(const OpcUa_VariantMatrixValue& cp);
	EnumStatusCode get(OpcUa_VariantMatrixValue& target) const;

	EnumStatusCode set(OTInt32 NoOfDimensions,OTInt32* Dimensions,OTInt32* Int32Array);

	OTUInt32 size(void);
	OTUInt32 max_size();
	/* Returns the actual number of elements */
	static OTUInt32 size(OTInt32 NoOfDimensions,OTInt32* Dimensions);

	OTInt32 insert(OTInt32* Dimensions,OTInt32* Int32Array,OTInt32 length);
	OTInt32 at(OTUInt32 idx);
	OTInt32 at(OTInt32* Dimensions);
	OTInt32 operator[](OTInt32 idx);

	bool empty(void);

	static bool areEqual(const MatrixValueStruct& mda1,const MatrixValueStruct& mda2);
	bool operator !=(const MatrixValueStruct& nodeId) const;
	bool operator ==(const MatrixValueStruct& nodeId) const;

	const MatrixValueStruct& operator=(const MatrixValueStruct& cp);

	OTInt32* getInt32Buffer();

	void clear(void);
	bool inRange(OTUInt32 idx);

	~MatrixValueStruct();
#endif

}MatrixValueStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif // _MATRIXVALUESTRUCT_H_
