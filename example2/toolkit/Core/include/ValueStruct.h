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

#ifndef _VALUESTRUCT_H_
#define _VALUESTRUCT_H_

#include "ByteStringStruct.h"
#include "ValueUnion.h"
#include "GuidStruct.h"
#include "NodeIdStruct.h"
#include "ExpandedNodeIdStruct.h"
#include "QualifiedNameStruct.h"
#include "LocalizedTextStruct.h"
#include "EUInformationStruct.h"
#include "TimeZoneStruct.h"
#include "MatrixValueStruct.h"
#include "NumericRangeStruct.h"
#include "SignedSoftwareCertificateStruct.h"
#include "ReferenceDescriptionStruct.h"
#include "ApplicationDescriptionStruct.h"
#include "ServerDiagnosticsSummaryDataTypeStruct.h"
#include "SubscriptionDiagnosticsDataTypeStruct.h"
#include "SessionDiagnosticsDataTypeStruct.h"
#include "SessionSecurityDiagnosticsDataTypeStruct.h"
#include "ServiceCounterDataTypeStruct.h"
#include "SemanticChangeStructureDataTypeStruct.h"
#include "ModelChangeStructureDataTypeStruct.h"
#include "UserIdentityTokenStruct.h"
#include "BuildInfoStruct.h"
#include "ServerStatusDataTypeStruct.h"
#include "EnumValueTypeStruct.h"
#include <limits>

#ifdef OT_COMPILATION
typedef std::vector<std::pair<OTUInt32, OTUInt32> > IndexRangeVector;
#endif

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

struct DataValueStruct;
class OTStructuredDataTypeDescription;

/*! @brief Correspond to OpcUa_Variant.
*
*   @see OPC UA Part 6 par. 5.1.5 for specs.
*
*   @par Few observations on data types:
*   <ul>
*   <li>Instead of SByte the Int8 should be used.
*   <li>Instead of Byte the UInt8 should be used.
*   <li>XmlElement is in fact a ByteString.
*   <li>Instead of UInt8 array the ByteString should be used.
*   <li>Variants can contain arrays of Variants but they cannot
*       directly contain another Variant.
*   <li>Variants can be empty.
*   </ul> */
//lint -sem(ValueStruct::clear, cleanup)
//lint -sem(ValueStruct::clear, initializer)
//lint -sem(ValueStruct::init, initializer)
typedef struct ValueStruct
{
	/* @brief the array type can be scalar/array/matrix */
	unsigned char arrayType;

	/* @brief the data type currently set. */
	unsigned short dataType;

	/* @brief Correspond to the OpcUa_VariantUnion */
	ValueStructUnion value;

#ifdef OT_COMPILATION
	ValueStruct(void);
	ValueStruct(const ValueStruct& copy);

	EnumStatusCode set(const ValueStruct& cp, bool targetIsMemberOfNode = false);
	EnumStatusCode get(ValueStruct& target) const;
	EnumStatusCode set(const OpcUa_Variant& cp, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_Variant& target, const std::vector<tstring>& preferredLocales) const;

	const ValueStruct& operator=(const ValueStruct& cp);
	const ValueStruct& operator=(const OpcUa_Variant& cp);

	bool operator==(const ValueStruct &toCompare) const;
	bool operator!=(const ValueStruct &toCompare) const;

	static bool supportsDataType(OTUInt16 dataTypeId);

	OTUInt32* getArrayDimensions(void) const;
	OTInt32 getValueRank(void) const;

	tstring toString(void) const;

	void clear(void);
	void init(void);

	/*! @brief Initializes this structure with default values
	 *
	 * @param dataType the data type
	 * @param arrayType the arrayType (EnumValueArrayType_Scalar, EnumValueArrayType_Array
	 *        or EnumValueArrayType_Matrix) */
	EnumStatusCode init(unsigned short dataType, OTUInt8 arrayType);
	void swap(ValueStruct & other);
	~ValueStruct(void);

	// encoding / decoding the value to /from a stream (works for embedded values in a structure only since only contents of embedded structures are encoded / decoded).
	EnumStatusCode encode(struct _OpcUa_Encoder *pEncoder, const std::vector<tstring>& preferredLocales, OTUInt32 arrayLength = std::numeric_limits<OTUInt32>::max()) const ;
	EnumStatusCode decode(struct _OpcUa_Decoder *pDecoder, EnumDataTypeId encodedDataType, EnumValueArrayType encodedArrayType, OTUInt32 arrayLength = std::numeric_limits<OTUInt32>::max());

	/*! Recursive helper method to test against array dimensions of variables and variable types */
	EnumStatusCode checkArrayDimensions(OTUInt32 arrayDimensionsCount, const OTUInt32 *pArrayDimensions) const;

	/*! Recursive helper method to test against value rank of variables and variable types */
	EnumStatusCode checkValueRank(OTInt32 valueRank) const;

	/*! Helper method to check whether ValueRank and ArrayDimensions fit together */
	static bool valueRankMatchToArrayDimensions(OTInt32 valueRank, OTUInt32 arrayDimensionsCount);

	//////////////////////////////////////////////////////////////////////////
	// Methods for setting values
	//////////////////////////////////////////////////////////////////////////

	// Null
	void setNull();

	// Boolean
	void setBoolean(OTBoolean value);
	EnumStatusCode setBooleanArray(const OTBoolean* arrayBoolean, OTInt32 length);
	EnumStatusCode setBooleanArray(const OTBoolean* arrayBoolean, OTInt32 length, OTInt32 index);

	// UInt8 (Byte)
	void setUInt8(OTUInt8 value);
	EnumStatusCode setUInt8Array(const OTUInt8* arrayUInt8, OTInt32 length);
	EnumStatusCode setUInt8Array(const OTUInt8* arrayUInt8, OTInt32 length, OTInt32 index);

	// Int8 (SByte)
	void setInt8(OTInt8 value);
	EnumStatusCode setInt8Array(const OTInt8* arrayInt8, OTInt32 length);
	EnumStatusCode setInt8Array(const OTInt8* arrayInt8, OTInt32 length, OTInt32 index);

	// UInt16
	void setUInt16(OTUInt16 value);
	EnumStatusCode setUInt16Array(const OTUInt16* arrayUInt16, OTInt32 length);
	EnumStatusCode setUInt16Array(const OTUInt16* arrayUInt16, OTInt32 length, OTInt32 index);

	// Int16
	void setInt16(OTInt16 value);
	EnumStatusCode setInt16Array(const OTInt16* arrayInt16, OTInt32 length);
	EnumStatusCode setInt16Array(const OTInt16* arrayInt16, OTInt32 length, OTInt32 index);

	// UInt32
	void setUInt32(OTUInt32 value);
	EnumStatusCode setUInt32Array(const OTUInt32* arrayUInt32, OTInt32 length);
	EnumStatusCode setUInt32Array(const OTUInt32* arrayUInt32, OTInt32 length, OTInt32 index);

	// Int32
	void setInt32(OTInt32 value);
	EnumStatusCode setInt32Array(const OTInt32* arrayInt32, OTInt32 length);
	EnumStatusCode setInt32Array(const OTInt32* arrayInt32, OTInt32 length, EnumDataTypeId dataTypeId);
	EnumStatusCode setInt32Array(const OTInt32* arrayInt32, OTInt32 length, OTInt32 index);

	// UInt64
	void setUInt64(OTUInt64 value);
	EnumStatusCode setUInt64Array(const OTUInt64* arrayUInt64, OTInt32 length);
	EnumStatusCode setUInt64Array(const OTUInt64* arrayUInt64, OTInt32 length, OTInt32 index);

	// Int64
	void setInt64(OTInt64 value);
	EnumStatusCode setInt64Array(const OTInt64* arrayInt64, OTInt32 length);
	EnumStatusCode setInt64Array(const OTInt64* arrayInt64, OTInt32 length, OTInt32 index);

	// Float
	void setFloat(OTFloat value);
	EnumStatusCode setFloatArray(const OTFloat* arrayFloat, OTInt32 length);
	EnumStatusCode setFloatArray(const OTFloat* arrayFloat, OTInt32 length, OTInt32 index);

	// Double
	void setDouble(OTDouble value);
	EnumStatusCode setDoubleArray(const OTDouble* arrayDouble, OTInt32 length);
	EnumStatusCode setDoubleArray(const OTDouble* arrayDouble, OTInt32 length, OTInt32 index);

	// DateTime
	EnumStatusCode setDateTime(const DateTimeStruct& value);
	EnumStatusCode setDateTimeArray(const DateTimeStruct* arrayDateTime, OTInt32 length);
	EnumStatusCode setDateTimeArray(const DateTimeStruct* arrayDateTime, OTInt32 length, OTInt32 index);

	// String
	EnumStatusCode setString(const OTChar* value);
	EnumStatusCode setStringArray(const std::vector<tstring>& arrayString);
	EnumStatusCode setStringArray(const LPCTSTR* arrayString, OTInt32 length);
	EnumStatusCode setStringArray(const LPCTSTR* arrayString, OTInt32 length, OTInt32 index);

	// Guid
	EnumStatusCode setGuid(const GuidStruct& value);
	EnumStatusCode setGuidArray(const GuidStruct* arrayGuid, OTInt32 length);
	EnumStatusCode setGuidArray(const GuidStruct* arrayGuid, OTInt32 length, OTInt32 index);

	// ByteString
	EnumStatusCode setByteString(const ByteStringStruct& value);
	EnumStatusCode setByteString(unsigned size, const unsigned char* data);
	EnumStatusCode setByteStringArray(const ByteStringStruct* arrayByteString, OTInt32 length);
	EnumStatusCode setByteStringArray(const ByteStringStruct* arrayByteString, OTInt32 length, OTInt32 index);

	// XmlElement
	EnumStatusCode setXmlElement(const XmlElementStruct& value);
	EnumStatusCode setXmlElementArray(const XmlElementStruct* arrayXmlElement, OTInt32 length);
	EnumStatusCode setXmlElementArray(const XmlElementStruct* arrayXmlElement, OTInt32 length, OTInt32 index);

	// StatusCode
	void setStatusCode(const EnumStatusCode value);
	EnumStatusCode setStatusCodeArray(const EnumStatusCode* arrayStatusCode, OTInt32 length);
	EnumStatusCode setStatusCodeArray(const EnumStatusCode* arrayStatusCode, OTInt32 length, OTInt32 index);

	// Value
	EnumStatusCode setValueArray(const ValueStruct* arrayDataValue, OTInt32 length);
	EnumStatusCode setValueArray(const ValueStruct* arrayDataValue, OTInt32 length, OTInt32 index);
	EnumStatusCode attachToValueArray(const ValueStruct* pValue, OTInt32 length);

	// DataValue
	EnumStatusCode setDataValue(const DataValueStruct& value);
	EnumStatusCode setDataValueArray(const DataValueStruct* arrayDataValue, OTInt32 length);
	EnumStatusCode setDataValueArray(const DataValueStruct* arrayDataValue, OTInt32 length, OTInt32 index);

	// ExpandedNodeId
	EnumStatusCode setExpandedNodeId(const ExpandedNodeIdStruct& value);
	EnumStatusCode setExpandedNodeIdArray(const ExpandedNodeIdStruct* arrayExpandedNodeId, OTInt32 length);
	EnumStatusCode setExpandedNodeIdArray(const ExpandedNodeIdStruct* arrayExpandedNodeId, OTInt32 length, OTInt32 index);

	// LocalizedText
	EnumStatusCode setLocalizedText(const LocalizedTextStruct& value, bool targetIsMemberOfNode = false);
	EnumStatusCode setLocalizedTextArray(const LocalizedTextStruct* arrayLocalizedText, OTInt32 length, bool targetIsMemberOfNode = false);
	EnumStatusCode setLocalizedTextArray(const LocalizedTextStruct* arrayLocalizedText, OTInt32 length, OTInt32 index, bool targetIsMemberOfNode = false);

	// QualifiedName
	EnumStatusCode setQualifiedName(const QualifiedNameStruct& value);
	EnumStatusCode setQualifiedNameArray(const QualifiedNameStruct* arrayQualifiedName, OTInt32 length);
	EnumStatusCode setQualifiedNameArray(const QualifiedNameStruct* arrayQualifiedName, OTInt32 length, OTInt32 index);

	// NodeId
	EnumStatusCode setNodeId(const NodeIdStruct& value);
	EnumStatusCode setNodeIdArray(const NodeIdStruct* arrayNodeId, OTInt32 length);
	EnumStatusCode setNodeIdArray(const NodeIdStruct* arrayNodeId, OTInt32 length, OTInt32 index);

	// EUInformation
	EnumStatusCode setEUInformation(const EUInformationStruct& value, bool targetIsMemberOfNode = false);
	EnumStatusCode setEUInformationArray(const EUInformationStruct* arrayEUInformation, OTInt32 length, bool targetIsMemberOfNode = false);
	EnumStatusCode setEUInformationArray(const EUInformationStruct* arrayEUInformation, OTInt32 length, OTInt32 index, bool targetIsMemberOfNode = false);

	// TimeZone
	EnumStatusCode setTimeZone(const TimeZoneStruct& value);
	EnumStatusCode setTimeZoneArray(const TimeZoneStruct* arrayTimeZone, OTInt32 length);
	EnumStatusCode setTimeZoneArray(const TimeZoneStruct* arrayTimeZone, OTInt32 length, OTInt32 index);

	// Argument
	EnumStatusCode setArgument(const ArgumentStruct& value, bool targetIsMemberOfNode = false);
	EnumStatusCode setArgumentArray(const ArgumentStruct* arrayArgument, OTInt32 length, bool targetIsMemberOfNode = false);
	EnumStatusCode setArgumentArray(const ArgumentStruct* arrayArgument, OTInt32 length, OTInt32 index, bool targetIsMemberOfNode = false);

	// Range
	EnumStatusCode setRange(const RangeStruct& value);
	EnumStatusCode setRangeArray(const RangeStruct* arrayRange, OTInt32 length);
	EnumStatusCode setRangeArray(const RangeStruct* arrayRange, OTInt32 length, OTInt32 index);

	// SignedSoftwareCertificate
	EnumStatusCode setSignedSoftwareCertificate(const SignedSoftwareCertificateStruct& value);
	EnumStatusCode setSignedSoftwareCertificateArray(const SignedSoftwareCertificateStruct* arrayRange, OTInt32 length);
	EnumStatusCode setSignedSoftwareCertificateArray(const SignedSoftwareCertificateStruct* arrayRange, OTInt32 length, OTInt32 index);

	// ReferenceDescription
	EnumStatusCode setReferenceDescription(const ReferenceDescriptionStruct& value);
	EnumStatusCode setReferenceDescriptionArray(const ReferenceDescriptionStruct* arrayReferenceDescription, OTInt32 length);
	EnumStatusCode setReferenceDescriptionArray(const ReferenceDescriptionStruct* arrayReferenceDescription, OTInt32 length, OTInt32 index);

	// ApplicationDescription
	EnumStatusCode setApplicationDescription(const ApplicationDescriptionStruct& value);
	EnumStatusCode setApplicationDescriptionArray(const ApplicationDescriptionStruct* arrayApplicationDescription, OTInt32 length);
	EnumStatusCode setApplicationDescriptionArray(const ApplicationDescriptionStruct* arrayApplicationDescription, OTInt32 length, OTInt32 index);

	// ServerDiagnosticsSummaryDataType
	EnumStatusCode setServerDiagnosticsSummaryDataType(const ServerDiagnosticsSummaryDataTypeStruct& value);
	EnumStatusCode setServerDiagnosticsSummaryDataTypeArray(const ServerDiagnosticsSummaryDataTypeStruct* arrayServerDiagnosticsSummaryDataType, OTInt32 length);
	EnumStatusCode setServerDiagnosticsSummaryDataTypeArray(const ServerDiagnosticsSummaryDataTypeStruct* arrayServerDiagnosticsSummaryDataType, OTInt32 length, OTInt32 index);

	// SubscriptionDiagnosticsDataType
	EnumStatusCode setSubscriptionDiagnosticsDataType(const SubscriptionDiagnosticsDataTypeStruct& value);
	EnumStatusCode setSubscriptionDiagnosticsDataTypeArray(const SubscriptionDiagnosticsDataTypeStruct* arraySubscriptionDiagnosticsDataType, OTInt32 length);
	EnumStatusCode setSubscriptionDiagnosticsDataTypeArray(const SubscriptionDiagnosticsDataTypeStruct* arraySubscriptionDiagnosticsDataType, OTInt32 length, OTInt32 index);

	// SessionDiagnosticsDataType
	EnumStatusCode setSessionDiagnosticsDataType(const SessionDiagnosticsDataTypeStruct& value);
	EnumStatusCode setSessionDiagnosticsDataTypeArray(const SessionDiagnosticsDataTypeStruct* arraySessionDiagnosticsDataType, OTInt32 length);
	EnumStatusCode setSessionDiagnosticsDataTypeArray(const SessionDiagnosticsDataTypeStruct* arraySessionDiagnosticsDataType, OTInt32 length, OTInt32 index);

	// SessionSecurityDiagnosticsDataType
	EnumStatusCode setSessionSecurityDiagnosticsDataType(const SessionSecurityDiagnosticsDataTypeStruct& value);
	EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray(const SessionSecurityDiagnosticsDataTypeStruct* arraySessionSecurityDiagnosticsDataType, OTInt32 length);
	EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray(const SessionSecurityDiagnosticsDataTypeStruct* arraySessionSecurityDiagnosticsDataType, OTInt32 length, OTInt32 index);

	// ServiceCounterDataType
	EnumStatusCode setServiceCounterDataType(const ServiceCounterDataTypeStruct& value);
	EnumStatusCode setServiceCounterDataTypeArray(const ServiceCounterDataTypeStruct* arrayServiceCounterDataType, OTInt32 length);
	EnumStatusCode setServiceCounterDataTypeArray(const ServiceCounterDataTypeStruct* arrayServiceCounterDataType, OTInt32 length, OTInt32 index);

#if TB5_ALARMS
	// SemanticChangeStructureDataType
	EnumStatusCode setSemanticChangeStructureDataType(const SemanticChangeStructureDataTypeStruct& value);
	EnumStatusCode setSemanticChangeStructureDataTypeArray(const SemanticChangeStructureDataTypeStruct* arraySemanticChangeStructureDataType, OTInt32 length);
	EnumStatusCode setSemanticChangeStructureDataTypeArray(const SemanticChangeStructureDataTypeStruct* arraySemanticChangeStructureDataType, OTInt32 length, OTInt32 index);

	// SemanticChangeStructureDataType
	EnumStatusCode setModelChangeStructureDataType(const ModelChangeStructureDataTypeStruct& value);
	EnumStatusCode setModelChangeStructureDataTypeArray(const ModelChangeStructureDataTypeStruct* arrayModelChangeStructureDataType, OTInt32 length);
	EnumStatusCode setModelChangeStructureDataTypeArray(const ModelChangeStructureDataTypeStruct* arrayModelChangeStructureDataType, OTInt32 length, OTInt32 index);
#endif

	// UserIdentityToken
	EnumStatusCode setUserIdentityToken(const UserIdentityTokenStruct& value);
	EnumStatusCode setUserIdentityTokenArray(const UserIdentityTokenStruct* arrayUserIdentityToken, OTInt32 length);
	EnumStatusCode setUserIdentityTokenArray(const UserIdentityTokenStruct* arrayUserIdentityToken, OTInt32 length, OTInt32 index);

	// BuildInfo
	EnumStatusCode setBuildInfo(const BuildInfoStruct& value);
	EnumStatusCode setBuildInfoArray(const BuildInfoStruct* arrayBuildInfo, OTInt32 length);
	EnumStatusCode setBuildInfoArray(const BuildInfoStruct* arrayBuildInfo, OTInt32 length, OTInt32 index);

#if TB5_ALARMS
	// EventFilter
	EnumStatusCode setEventFilter(const EventFilterStruct& valueArg);
	EnumStatusCode setEventFilterArray(const EventFilterStruct* arrayEventFilter, OTInt32 length);
	EnumStatusCode setEventFilterArray(const EventFilterStruct* arrayEventFilter, OTInt32 length, OTInt32 index);
#endif

	// ServerStatusDataType
	EnumStatusCode setServerStatusDataType(const ServerStatusDataTypeStruct& valueArg);
	EnumStatusCode setServerStatusDataTypeArray(const ServerStatusDataTypeStruct* arrayServerStatusDataType, OTInt32 length);
	EnumStatusCode setServerStatusDataTypeArray(const ServerStatusDataTypeStruct* arrayServerStatusDataType, OTInt32 length, OTInt32 index);

	// EnumValueType
	EnumStatusCode setEnumValueType(const EnumValueTypeStruct& valueArg, bool targetIsMemberOfNode = false);
	EnumStatusCode setEnumValueTypeArray(const EnumValueTypeStruct* arrayEnumValueType, OTInt32 length, bool targetIsMemberOfNode = false);
	EnumStatusCode setEnumValueTypeArray(const EnumValueTypeStruct* arrayEnumValueType, OTInt32 length, OTInt32 index, bool targetIsMemberOfNode = false);

	// StructureType
	EnumStatusCode setExtensionObject(const OTExtensionObject& value, bool targetIsMemberOfNode = false);
	EnumStatusCode setExtensionObjectArray(const OTExtensionObject* arrayStructureType, OTInt32 length, bool targetIsMemberOfNode = false);
	EnumStatusCode setExtensionObjectArray(const OTExtensionObject* arrayStructureType, OTInt32 length, OTInt32 index, bool targetIsMemberOfNode = false);

	EnumStatusCode getComplexRaw(NodeIdStruct* encodingId, ByteStringStruct* rawData) const;
	EnumStatusCode setComplexRaw(const NodeIdStruct* encodingId, const ByteStringStruct* rawData);

	EnumStatusCode getComplexRawArray(NodeIdStruct* encodingId, size_t* pCount, ByteStringStruct** pRawData) const;
	EnumStatusCode setComplexRawArray(const NodeIdStruct* encodingId, const std::vector<ByteStringStruct*>& rawData);

	/*! Returns the fields of a custom structured data type
	* @note The caller has to free the returned fieldValues */
	EnumStatusCode getStructureFields(SOCmnPointer<const OTStructuredDataTypeDescription> dataTypeDesc, std::vector<ValueStruct*>& values) const;
	EnumStatusCode setStructureFields(const NodeIdStruct* dataTypeId, SOCmnPointer<const OTStructuredDataTypeDescription> dataTypeDesc, const std::vector<const ValueStruct*>& values);

	/*! Returns the fields of a custom structured data type array
	* @note The caller has to free the returned fieldValues */
	EnumStatusCode getStructureFieldsArray(SOCmnPointer<const OTStructuredDataTypeDescription> dataTypeDesc, std::vector<std::vector<ValueStruct*> >& values) const ;
	EnumStatusCode setStructureFieldsArray(const NodeIdStruct* dataTypeId, SOCmnPointer<const OTStructuredDataTypeDescription> dataTypeDesc, const std::vector< std::vector<const ValueStruct*> >& values);

	//////////////////////////////////////////////////////////////////////////
	// Array-related methods
	//////////////////////////////////////////////////////////////////////////

	/*! @brief Constructs an array from this value.
	 *
	 * This method is useful if you want to convert a scalar value
	 * to an array.
	 *
	 * @warning @p valueArray must be different from the object you are calling this method
	 *
	 * @param[out] target the array that is constructed from the scalar value
	 *             that is stored in this object
	 * @param      true, if the target is a member (C++-wise) of a node object */
	EnumStatusCode toArray(ValueStruct& target, bool targetIsMemberOfNode);
	EnumStatusCode toArray(std::vector<ValueStruct*> nestedValues, bool clearSourceValues);

	/*! @brief Attaches a scalar or array value to an array of values
	 *
	 * @param scalarValue the scalar or array value to attach */

	EnumStatusCode getSubset(ValueStruct* pDst, const NumericRangeStruct* indexRange) const;
	EnumStatusCode getSubset(ValueStruct* pDst, const IndexRangeVector& ranges) const;
	EnumStatusCode setSubset(const ValueStruct* pSrc, const NumericRangeStruct* indexRange);

	//////////////////////////////////////////////////////////////////////////

	int compare(const ValueStruct* pWith) const;
	int compareScalar(const ValueStruct & with) const;
	int compareArray(const ValueStruct & with) const;
	int compareMatrix(const ValueStruct & with) const;

	//////////////////////////////////////////////////////////////////////////
	// Internal helper methods
	//////////////////////////////////////////////////////////////////////////

	EnumStatusCode copyStringArrayRange(const ValueStruct& src, const IndexRangeVector& ranges);
	EnumStatusCode copyByteStringArrayRange(const ValueStruct& src, const IndexRangeVector& ranges);
	EnumStatusCode copyArraySubset(const ValueStruct& src, OTUInt32 first, OTUInt32 count);
	EnumStatusCode replaceArraySubset(const ValueStruct& src, OTUInt32 first, OTUInt32 count);

	EnumStatusCode replaceStringArrayRange(const ValueStruct& src, IndexRangeVector ranges);
	EnumStatusCode replaceByteStringArrayRange(const ValueStruct& src, IndexRangeVector ranges);
	EnumStatusCode replaceStringRange(const ValueStruct& src, OTUInt32 first, OTUInt32 length);
	EnumStatusCode replaceByteStringRange(const ValueStruct& src, OTUInt32 first, OTUInt32 length);

	/*! @brief helper function that copies array values that are to be encoded as extension object to
	 * the Variant OPC UA structure */
	EnumStatusCode setExtensionArray(OpcUa_Variant& target, const std::vector<tstring>& preferredLocales) const;

	/*! @brief helper function attaching extension objects into an allocated field of variants */
	EnumStatusCode attachExtensionArray(OpcUa_ExtensionObject* pWhere, const std::vector<tstring>& preferredLocales) const;
#endif
}ValueStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif // _VALUESTRUCT_H_
