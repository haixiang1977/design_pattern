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

#ifndef IVALUE_H
#define IVALUE_H

#include "Base.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	class INodeId;
	class IDateTime;
	class IGuid;
	class IExpandedNodeId;
	class ILocalizedText;
	class IQualifiedName;
	class IDataValue;
	class NodeId;
	class ExpandedNodeId;
	class QualifiedName;
	class DateTime;
	class Guid;
	class LocalizedText;
	class DataValue;
	class EUInformation;
	class IEUInformation;
	class TimeZone;
	class ITimeZone;
	class Range;
	class IRange;
	class Argument;
	class Value;
	class IArgument;
	class INumericRange;
	class ReferenceDescription;
	class IReferenceDescription;
	class ApplicationDescription;
	class IApplicationDescription;
	class ServerDiagnosticsSummaryDataType;
	class IServerDiagnosticsSummaryDataType;
	class SubscriptionDiagnosticsDataType;
	class ISubscriptionDiagnosticsDataType;
	class SessionDiagnosticsDataType;
	class ISessionDiagnosticsDataType;
	class SessionSecurityDiagnosticsDataType;
	class ISessionSecurityDiagnosticsDataType;
	class ServiceCounterDataType;
	class IServiceCounterDataType;
	class SemanticChangeStructureDataType;
	class ISemanticChangeStructureDataType;
	class ModelChangeStructureDataType;
	class IModelChangeStructureDataType;
	class UserIdentityToken;
	class IUserIdentityToken;
	class AnonymousIdentityToken;
	class IAnonymousIdentityToken;
	class UserNameIdentityToken;
	class IUserNameIdentityToken;
	class X509IdentityToken;
	class IX509IdentityToken;
	class IssuedIdentityToken;
	class IIssuedIdentityToken;
	class SignedSoftwareCertificate;
	class ISignedSoftwareCertificate;
	class BuildInfo;
	class IBuildInfo;
	class EventFilter;
	class IEventFilter;
	class ServerStatusDataType;
	class IServerStatusDataType;
	class EnumValueType;
	class IEnumValueType;
	class StructuredDataTypeDescription;
	typedef ObjectPointer<const StructuredDataTypeDescription> StructuredDataTypeDescriptionConstPtr;
	class EnumerationDataTypeDescription;
	typedef ObjectPointer<const EnumerationDataTypeDescription> EnumerationDataTypeDescriptionConstPtr;

	/*! The Value data type is a variant that can hold any of the other data types
	* provided by the Toolkit.
	*
	* The Value data type contains the following information:
	* @li	The array type (see IValue::getArrayType()) which indicates whether the variant
	*		holds a scalar, array, or matrix value
	* @li	The data type (see IValue::getDataType()) indicating the data type of the
	*		value stored in the variant
	* @li	The actual value
	*
	* The class provides additional features to simplify handling of index ranges. The methods
	* IValue::getSubset() and IValue::setSubset() enable applications to extract and modify
	* a subset of any array value.
	*
	* The method IValue::castTo() can be used to cast the value stored in the variant between
	* different data types. */
	class TBC_EXPORT IValue
	{
	public:
		/*! Destructor */
		virtual ~IValue() {};

		/*! Returns the data type of the value contained in the variant. */
		virtual EnumDataTypeId getDataType() const = 0;

		/*! Returns the array type of the value contained in the variant.
		*
		* The variant may use one of the following array types:
		* @li EnumValueArrayType_Scalar:	A single value of the specified data type
		* @li EnumValueArrayType_Array:		An array of values of the specified data type
		* @li EnumValueArrayType_Matrix:	A matrix of values of the specified data type. This array type is not yet supported. */
		virtual EnumValueArrayType getArrayType() const = 0;

		/*! Returns a subset of an array, a matrix, a ByteString, or a string value.
		*
		* @param[out]	result		The extracted subset of the array, matrix, ByteString, or string value
		* @param[in]	indexRange	The range that defines the subset to extract */
		virtual EnumStatusCode getSubset(IValue& result, const INumericRange* indexRange) const = 0;
		/*! Replaces a subset of an array, a matrix, a ByteString, or a string value.
		*
		* @param value		The array, matrix, ByteString or string value that shall replace a
		*					certain range of the value stored in the variant
		* @param indexRange	The range that defines the subset of the variant to replace */
		virtual EnumStatusCode setSubset(const IValue& value, const INumericRange* indexRange) = 0;

		/*! Returns whether and how the value in the variant can be converted to another data type.
		*
		* If this method returns EnumValueCastType_NotDefined, then no conversion between the source
		* and the target data type exists. Any other result defines whether explicit (EnumValueCastType_Explicit)
		* or implicit (EnumValueCastType_Implicit) conversion is required or if no conversion is required at all
		* (EnumValueCastType_Identity).
		*
		* @param dataType	The target data type to which the variant's value is to be converted. */
		virtual EnumValueCastType canCastTo(EnumDataTypeId dataType) const = 0;
		/*! Converts the value to the provided data type if such conversion exists.
		*
		* The method IValue::canCastTo() can be used to determine if a conversion between the
		* variant's source data type and the provided target data type exists.
		*
		* @param dataType		The target data type to which the variant's value is to be converted.
		* @param castedValue	The variant containing the casted value. */
		virtual EnumStatusCode castTo(EnumDataTypeId dataType, IValue& castedValue) const = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Boolean content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. If DataType does not match OTBoolean or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getBoolean(OTBoolean* target) const = 0;
		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTBoolean getBoolean() const = 0;
		/*! Sets the value to a scalar of type OTBoolean. */
		virtual void setBoolean(OTBoolean value) = 0;

		/*! Returns the content of the Value. If DataType does not match OTBoolean or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getBooleanArray(std::vector<OTBoolean>& target) const = 0;
		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTBoolean> getBooleanArray() const = 0;
		/*! Sets the value to an array of type OTBoolean. */
		virtual EnumStatusCode setBooleanArray (const std::vector<OTBoolean>& arrayBool) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt8 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTUInt8 getUInt8() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt8 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getUInt8(OTUInt8* target) const = 0;
		/*! Sets the value to a scalar of type OTUInt8. */
		virtual void setUInt8(OTUInt8 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTUInt8> getUInt8Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt8 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getUInt8Array(std::vector<OTUInt8>& target) const = 0;
		/*! Sets the value to an array of type OTUInt8. */
		virtual EnumStatusCode setUInt8Array(const std::vector<OTUInt8>& arrayUInt8) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int8 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTInt8 getInt8() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt8 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getInt8(OTInt8* target) const = 0;
		/*! Sets the value to a scalar of type OTInt8. */
		virtual void setInt8(OTInt8 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTInt8> getInt8Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt8 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getInt8Array(std::vector<OTInt8>& target) const = 0;
		/*! Sets the value to an array of type OTInt8. */
		virtual EnumStatusCode setInt8Array(const std::vector<OTInt8>& arrayInt8) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt16 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTUInt16 getUInt16() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt16 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getUInt16(OTUInt16* target) const = 0;
		/*! Sets the value to a scalar of type OTUInt16. */
		virtual void setUInt16(OTUInt16 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTUInt16> getUInt16Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt16 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getUInt16Array(std::vector<OTUInt16>& target) const = 0;
		/*! Sets the value to an array of type OTUInt16. */
		virtual EnumStatusCode setUInt16Array(const std::vector<OTUInt16>& arrayUInt16) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int16 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTInt16 getInt16() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt16 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getInt16(OTInt16* target) const = 0;
		/*! Sets the value to a scalar of type OTInt16. */
		virtual void setInt16(OTInt16 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTInt16> getInt16Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt16 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getInt16Array(std::vector<OTInt16>& target) const = 0;
		/*! Sets the value to an array of type OTInt16. */
		virtual EnumStatusCode setInt16Array(const std::vector<OTInt16>& arrayInt16) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt32 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTUInt32 getUInt32() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt32 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getUInt32(OTUInt32* target) const = 0;
		/*! Sets the value to a scalar of type OTUInt32. */
		virtual void setUInt32(OTUInt32 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTUInt32> getUInt32Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt32 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getUInt32Array(std::vector<OTUInt32>& target) const = 0;
		/*! Sets the value to an array of type OTUInt32. */
		virtual EnumStatusCode setUInt32Array(const std::vector<OTUInt32>& arrayUInt32) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int32 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTInt32 getInt32() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt32 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getInt32(OTInt32* target) const = 0;
		/*! Sets the value to a scalar of type OTUInt32. */
		virtual void setInt32(OTInt32 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTInt32> getInt32Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt32 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getInt32Array(std::vector<OTInt32>& target) const = 0;
		/*! Sets the value to an array of type OTUInt32. */
		virtual EnumStatusCode setInt32Array(const std::vector<OTInt32>& arrayInt32) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt64 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTUInt64 getUInt64() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt64 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getUInt64(OTUInt64* target) const = 0;
		/*! Sets the value to a scalar of type OTUInt64. */
		virtual void setUInt64(OTUInt64 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTInt64> getInt64Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt64 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getInt64Array(std::vector<OTInt64>& target) const = 0;
		/*! Sets the value to an array of type OTUInt64. */
		virtual EnumStatusCode setUInt64Array(const std::vector<OTUInt64>& arrayUInt64) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int64 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTInt64 getInt64() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt64 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getInt64(OTInt64* target) const = 0;
		/*! Sets the value to a scalar of type OTInt64. */
		virtual void setInt64(OTInt64 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTUInt64> getUInt64Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt64 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getUInt64Array(std::vector<OTUInt64>& target) const = 0;
		/*! Sets the value to an array of type OTInt64. */
		virtual EnumStatusCode setInt64Array(const std::vector<OTInt64>& arrayInt64) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Float content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTFloat getFloat() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTFloat or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getFloat(OTFloat* target) const = 0;
		/*! Sets the value to a scalar of type OTFloat. */
		virtual void setFloat(OTFloat value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTFloat> getFloatArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTFloat or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getFloatArray(std::vector<OTFloat>& target) const = 0;
		/*! Sets the value to an array of type OTFloat. */
		virtual EnumStatusCode setFloatArray(const std::vector<OTFloat>& arrayFloat) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Double content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTDouble getDouble() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTDouble or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getDouble(OTDouble* target) const = 0;
		/*! Sets the value to a scalar of type OTDouble. */
		virtual void setDouble(OTDouble value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTDouble> getDoubleArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTDouble or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getDoubleArray(std::vector<OTDouble>& target) const = 0;
		/*! Sets the value to an array of type OTDouble. */
		virtual EnumStatusCode setDoubleArray(const std::vector<OTDouble>& arrayDouble) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DateTime content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual DateTime getDateTime() const = 0;
		/*! Returns the content of the Value. If DataType does not match DateTime or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getDateTime(DateTime& target) const = 0;
		/*! Sets the value to a scalar of type DateTime. */
		virtual EnumStatusCode setDateTime(const IDateTime* pDateTime) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<DateTime> getDateTimeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match DateTime or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getDateTimeArray(std::vector<DateTime>& target) const = 0;
		/*! Sets the value to an array of type DateTime. */
		virtual EnumStatusCode setDateTimeArray(const std::vector<DateTime>& arrayDateTime) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for String content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual tstring getString() const = 0;
		/*! Returns the content of the Value. If DataType does not match tstring or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getString(tstring& target) const = 0;
		/*! Sets the value to a scalar of type tstring. */
		virtual EnumStatusCode setString(const tstring& value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<tstring> getStringArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match tstring or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getStringArray(std::vector<tstring>& target) const = 0;
		/*! Sets the value to an array of type tstring. */
		virtual EnumStatusCode setStringArray(const std::vector<tstring>& arrayString) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Guid content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual Guid getGuid() const = 0;
		/*! Returns the content of the Value. If DataType does not match Guid or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getGuid(Guid& target) const = 0;
		/*! Sets the value to a scalar of type Guid. */
		virtual EnumStatusCode setGuid(const IGuid* pGuid) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<Guid> getGuidArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match Guid or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getGuidArray(std::vector<Guid>& target) const = 0;
		/*! Sets the value to an array of type Guid. */
		virtual EnumStatusCode setGuidArray(const std::vector<Guid>& arrayGuid) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for NodeId content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual NodeId getNodeId() const = 0;
		/*! Returns the content of the Value. If DataType does not match NodeId or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getNodeId(NodeId& target) const = 0;
		/*! Sets the value to a scalar of type NodeId. */
		virtual EnumStatusCode setNodeId(const INodeId* pNodeId) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<NodeId> getNodeIdArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match NodeId or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getNodeIdArray(std::vector<NodeId>& target) const = 0;
		/*! Sets the value to an array of type NodeId. */
		virtual EnumStatusCode setNodeIdArray(const std::vector<NodeId>& arrayNodeId) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ExpandedNodeId content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ExpandedNodeId getExpandedNodeId() const = 0;
		/*! Returns the content of the Value. If DataType does not match ExpandedNodeId or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getExpandedNodeId(ExpandedNodeId& target) const = 0;
		/*! Sets the value to a scalar of type ExpandedNodeId. */
		virtual EnumStatusCode setExpandedNodeId(const IExpandedNodeId* pNodeId) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ExpandedNodeId> getExpandedNodeIdArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ExpandedNodeId or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getExpandedNodeIdArray(std::vector<ExpandedNodeId>& target) const = 0;
		/*! Sets the value to an array of type ExpandedNodeId. */
		virtual EnumStatusCode setExpandedNodeIdArray(const std::vector<ExpandedNodeId>& arrayExpandedNodeId) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for StatusCode content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. If DataType does not match EnumStatusCode or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getStatusCode() const = 0;
		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual EnumStatusCode getStatusCode(EnumStatusCode* target) const = 0;
		/*! Sets the value to a scalar of type EnumStatusCode. */
		virtual void setStatusCode(EnumStatusCode statusCode) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<EnumStatusCode> getStatusCodeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match EnumStatusCode or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getStatusCodeArray(std::vector<EnumStatusCode>& target) const = 0;
		/*! Sets the value to an array of type EnumStatusCode. */
		virtual EnumStatusCode setStatusCodeArray(const std::vector<EnumStatusCode>& arrayStatusCode) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for QualifiedName content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual QualifiedName getQualifiedName() const = 0;
		/*! Returns the content of the Value. If DataType does not match QualifiedName or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getQualifiedName(QualifiedName& target) const = 0;
		/*! Sets the value to a scalar of type QualifiedName. */
		virtual EnumStatusCode setQualifiedName(const IQualifiedName*  pQualifiedName) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<QualifiedName> getQualifiedNameArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match QualifiedName or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getQualifiedNameArray(std::vector<QualifiedName>& target) const = 0;
		/*! Sets the value to an array of type QualifiedName. */
		virtual EnumStatusCode setQualifiedNameArray(const std::vector<QualifiedName>& arrayQualifiedName) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EUInformation content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual EUInformation getEUInformation() const = 0;
		/*! Returns the content of the Value. If DataType does not match EUInformation or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getEUInformation(EUInformation& target) const = 0;
		/*! Sets the value to a scalar of type EUInformation. */
		virtual EnumStatusCode setEUInformation(const IEUInformation*  pEUInformation) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<EUInformation> getEUInformationArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match EUInformation or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getEUInformationArray(std::vector<EUInformation>& target) const = 0;
		/*! Sets the value to an array of type EUInformation. */
		virtual EnumStatusCode setEUInformationArray(const std::vector<EUInformation>& arrayEUInformation) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for LocalizedText content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual LocalizedText getLocalizedText() const = 0;
		/*! Returns the content of the Value. If DataType does not match LocalizedText or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getLocalizedText(LocalizedText& target) const = 0;
		/*! Sets the value to a scalar of type LocalizedText. */
		virtual EnumStatusCode setLocalizedText(const ILocalizedText* pLocalizedText) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<LocalizedText> getLocalizedTextArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match LocalizedText or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getLocalizedTextArray(std::vector<LocalizedText>& target) const = 0;
		/*! Sets the value to an array of type LocalizedText. */
		virtual EnumStatusCode setLocalizedTextArray(const std::vector<LocalizedText>& arrayLocalizedText) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ByteString content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ByteString getByteString() const = 0;
		/*! Returns the content of the Value. If DataType does not match ByteString or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getByteString(ByteString& target) const = 0;
		/*! Sets the value to a scalar of type ByteString. */
		virtual EnumStatusCode setByteString(const ByteString& pByteString) = 0;
		/*! @overload */
		virtual EnumStatusCode setByteString(const unsigned char* pData, unsigned length) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ByteString> getByteStringArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ByteString or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getByteStringArray(std::vector<ByteString>& target) const = 0;
		/*! Sets the value to an array of type ByteString. */
		virtual EnumStatusCode setByteStringArray(const std::vector<ByteString>& arrayByteString) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for XmlElement content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual XmlElement getXmlElement() const = 0;
		/*! Returns the content of the Value. If DataType does not match XmlElement or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getXmlElement(XmlElement& target) const = 0;
		/*! Sets the value to a scalar of type XmlElement. */
		virtual EnumStatusCode setXmlElement(const XmlElement& pXmlElement) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<XmlElement> getXmlElementArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match XmlElement or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getXmlElementArray(std::vector<XmlElement>& target) const = 0;
		/*! Sets the value to an array of type XmlElement. */
		virtual EnumStatusCode setXmlElementArray(const std::vector<XmlElement>& arrayXmlElement) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DataValue content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual DataValue getDataValue() const = 0;
		/*! Returns the content of the Value. If DataType does not match DataValue or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getDataValue(DataValue& target) const = 0;
		/*! Sets the value to a scalar of type DataValue. */
		virtual EnumStatusCode setDataValue(const IDataValue* pDataValue) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<DataValue> getDataValueArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match DataValue or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getDataValueArray(std::vector<DataValue>& target) const = 0;
		/*! Sets the value to an array of type DataValue. */
		virtual EnumStatusCode setDataValueArray(const std::vector<DataValue>& arrayDataValue) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Argument content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual Argument getArgument() const = 0;
		/*! Returns the content of the Value. If DataType does not match Argument or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getArgument(Argument& target) const = 0;
		/*! Sets the value to a scalar of type Argument. */
		virtual EnumStatusCode setArgument(const IArgument* pArgument) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<Argument> getArgumentArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match Argument or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getArgumentArray(std::vector<Argument>& target) const = 0;
		/*! Sets the value to an array of type Argument. */
		virtual EnumStatusCode setArgumentArray(const std::vector<Argument>& arrayArgument) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for TimeZone content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual TimeZone getTimeZone() const = 0;
		/*! Returns the content of the Value. If DataType does not match TimeZone or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getTimeZone(TimeZone& target) const = 0;
		/*! Sets the value to a scalar of type TimeZone. */
		virtual EnumStatusCode setTimeZone(const ITimeZone* pTimeZone) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<TimeZone> getTimeZoneArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match TimeZone or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getTimeZoneArray(std::vector<TimeZone>&) const = 0;
		/*! Sets the value to an array of type TimeZone. */
		virtual EnumStatusCode setTimeZoneArray(const std::vector<TimeZone>& arrayTimeZone) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Range content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual Range getRange() const = 0;
		/*! Returns the content of the Value. If DataType does not match Range or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getRange(Range& target) const = 0;
		/*! Sets the value to a scalar of type Range. */
		virtual EnumStatusCode setRange(const IRange*  pRange) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<Range> getRangeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match Range or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getRangeArray(std::vector<Range>& target) const = 0;
		/*! Sets the value to an array of type Range. */
		virtual EnumStatusCode setRangeArray(const std::vector<Range>& arrayRange) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ReferenceDescription content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ReferenceDescription getReferenceDescription() const = 0;
		/*! Returns the content of the Value. If DataType does not match ReferenceDescription or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getReferenceDescription(ReferenceDescription& target) const = 0;
		/*! Sets the value to a scalar of type ReferenceDescription. */
		virtual EnumStatusCode setReferenceDescription(const IReferenceDescription* pReferenceDescription) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ReferenceDescription> getReferenceDescriptionArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ReferenceDescription or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getReferenceDescriptionArray(std::vector<ReferenceDescription>& target) const = 0;
		/*! Sets the value to an array of type ReferenceDescription. */
		virtual EnumStatusCode setReferenceDescriptionArray(const std::vector<ReferenceDescription>& arrayReferenceDescription) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ApplicationDescription content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ApplicationDescription getApplicationDescription() const = 0;
		/*! Returns the content of the Value. If DataType does not match ApplicationDescription or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getApplicationDescription(ApplicationDescription& target) const = 0;
		/*! Sets the value to a scalar of type ApplicationDescription. */
		virtual EnumStatusCode setApplicationDescription(const IApplicationDescription* pApplicationDescription) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ApplicationDescription> getApplicationDescriptionArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ApplicationDescription or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getApplicationDescriptionArray(std::vector<ApplicationDescription>& target) const = 0;
		/*! Sets the value to an array of type ApplicationDescription. */
		virtual EnumStatusCode setApplicationDescriptionArray(const std::vector<ApplicationDescription>& arrayApplicationDescription) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServerDiagnosticsSummary content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ServerDiagnosticsSummaryDataType getServerDiagnosticsSummaryDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServerDiagnosticsSummaryDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getServerDiagnosticsSummaryDataType(ServerDiagnosticsSummaryDataType& target) const = 0;
		/*! Sets the value to a scalar of type ServerDiagnosticsSummaryDataType. */
		virtual EnumStatusCode setServerDiagnosticsSummaryDataType(const IServerDiagnosticsSummaryDataType* pServerDiagnosticsSummaryDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ServerDiagnosticsSummaryDataType> getServerDiagnosticsSummaryDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServerDiagnosticsSummaryDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getServerDiagnosticsSummaryDataTypeArray(std::vector<ServerDiagnosticsSummaryDataType>& target) const = 0;
		/*! Sets the value to an array of type ServerDiagnosticsSummaryDataType. */
		virtual EnumStatusCode setServerDiagnosticsSummaryDataTypeArray(const std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SubscriptionDiagnostics content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual SubscriptionDiagnosticsDataType getSubscriptionDiagnosticsDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match SubscriptionDiagnosticsDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getSubscriptionDiagnosticsDataType(SubscriptionDiagnosticsDataType& target) const = 0;
		/*! Sets the value to a scalar of type SubscriptionDiagnosticsDataType. */
		virtual EnumStatusCode setSubscriptionDiagnosticsDataType(const ISubscriptionDiagnosticsDataType* pSubscriptionDiagnosticsDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<SubscriptionDiagnosticsDataType> getSubscriptionDiagnosticsDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match SubscriptionDiagnosticsDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getSubscriptionDiagnosticsDataTypeArray(std::vector<SubscriptionDiagnosticsDataType>& target) const = 0;
		/*! Sets the value to an array of type SubscriptionDiagnosticsDataType. */
		virtual EnumStatusCode setSubscriptionDiagnosticsDataTypeArray(const std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SessionDiagnostics content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual SessionDiagnosticsDataType getSessionDiagnosticsDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match SessionDiagnosticsDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getSessionDiagnosticsDataType(SessionDiagnosticsDataType& target) const = 0;
		/*! Sets the value to a scalar of type SessionDiagnosticsDataType. */
		virtual EnumStatusCode setSessionDiagnosticsDataType(const ISessionDiagnosticsDataType* pSessionDiagnosticsDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<SessionDiagnosticsDataType> getSessionDiagnosticsDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match SessionDiagnosticsDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getSessionDiagnosticsDataTypeArray(std::vector<SessionDiagnosticsDataType>& target) const = 0;
		/*! Sets the value to an array of type SessionDiagnosticsDataType. */
		virtual EnumStatusCode setSessionDiagnosticsDataTypeArray(const std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SessionSecurityDiagnostics content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual SessionSecurityDiagnosticsDataType getSessionSecurityDiagnosticsDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match SessionSecurityDiagnosticsDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataType(SessionSecurityDiagnosticsDataType& target) const = 0;
		/*! Sets the value to a scalar of type SessionSecurityDiagnosticsDataType. */
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataType(const ISessionSecurityDiagnosticsDataType* pSessionSecurityDiagnosticsDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<SessionSecurityDiagnosticsDataType> getSessionSecurityDiagnosticsDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match SessionSecurityDiagnosticsDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataTypeArray(std::vector<SessionSecurityDiagnosticsDataType>& target) const = 0;
		/*! Sets the value to an array of type SessionSecurityDiagnosticsDataType. */
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray(const std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServiceCounter content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ServiceCounterDataType getServiceCounterDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServiceCounterDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getServiceCounterDataType(ServiceCounterDataType& target) const = 0;
		/*! Sets the value to a scalar of type ServiceCounterDataType. */
		virtual EnumStatusCode setServiceCounterDataTypeArray(const std::vector<ServiceCounterDataType>& arrayServiceCounterDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ServiceCounterDataType> getServiceCounterDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServiceCounterDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getServiceCounterDataTypeArray(std::vector<ServiceCounterDataType>& target) const = 0;
		/*! Sets the value to an array of type ServiceCounterDataType. */
		virtual EnumStatusCode setServiceCounterDataType(const IServiceCounterDataType* pServiceCounterDataType) = 0;

#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// Value access for SemanticChangeStructure content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual SemanticChangeStructureDataType getSemanticChangeStructureDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match SemanticChangeStructureDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getSemanticChangeStructureDataType(SemanticChangeStructureDataType& target) const = 0;
		/*! Sets the value to a scalar of type SemanticChangeStructureDataType. */
		virtual EnumStatusCode setSemanticChangeStructureDataType(const ISemanticChangeStructureDataType* pSemanticChangeStructureDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<SemanticChangeStructureDataType> getSemanticChangeStructureDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match SemanticChangeStructureDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getSemanticChangeStructureDataTypeArray(std::vector<SemanticChangeStructureDataType>& target) const = 0;
		/*! Sets the value to an array of type SemanticChangeStructureDataType. */
		virtual EnumStatusCode setSemanticChangeStructureDataTypeArray(const std::vector<SemanticChangeStructureDataType>& arraySemanticChangeStructureDataType) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ModelChangeStructure content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ModelChangeStructureDataType getModelChangeStructureDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match ModelChangeStructureDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getModelChangeStructureDataType(ModelChangeStructureDataType& target) const = 0;
		/*! Sets the value to a scalar of type ModelChangeStructureDataType. */
		virtual EnumStatusCode setModelChangeStructureDataType(const IModelChangeStructureDataType* pModelChangeStructureDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ModelChangeStructureDataType> getModelChangeStructureDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ModelChangeStructureDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getModelChangeStructureDataTypeArray(std::vector<ModelChangeStructureDataType>& target) const = 0;
		/*! Sets the value to an array of type ModelChangeStructureDataType. */
		virtual EnumStatusCode setModelChangeStructureDataTypeArray(const std::vector<ModelChangeStructureDataType>& arrayModelChangeStructureDataType) = 0;
#endif

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UserIdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual UserIdentityToken getUserIdentityToken() const = 0;
		/*! Returns the content of the Value. If DataType does not match UserIdentityToken or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getUserIdentityToken(UserIdentityToken& target) const = 0;
		/*! Sets the value to a scalar of type UserIdentityToken. */
		virtual EnumStatusCode setUserIdentityToken(const IUserIdentityToken* pUserIdentityToken) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<UserIdentityToken> getUserIdentityTokenArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match UserIdentityToken or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getUserIdentityTokenArray(std::vector<UserIdentityToken>& target) const = 0;
		/*! Sets the value to an array of type UserIdentityToken. */
		virtual EnumStatusCode setUserIdentityTokenArray(const std::vector<UserIdentityToken>& arrayUserIdentityToken) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for AnonymousIdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual AnonymousIdentityToken getAnonymousIdentityToken() const = 0;
		/*! Returns the content of the Value. If DataType does not match AnonymousIdentityToken or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getAnonymousIdentityToken(AnonymousIdentityToken& target) const = 0;
		/*! Sets the value to a scalar of type AnonymousIdentityToken. */
		virtual EnumStatusCode setAnonymousIdentityToken(const IAnonymousIdentityToken* pAnonymousIdentityToken) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<AnonymousIdentityToken> getAnonymousIdentityTokenArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match AnonymousIdentityToken or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getAnonymousIdentityTokenArray(std::vector<AnonymousIdentityToken>& target) const = 0;
		/*! Sets the value to an array of type AnonymousIdentityToken. */
		virtual EnumStatusCode setAnonymousIdentityTokenArray(const std::vector<AnonymousIdentityToken>& arrayAnonymousIdentityToken) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UserNameIdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual UserNameIdentityToken getUserNameIdentityToken() const = 0;
		/*! Returns the content of the Value. If DataType does not match UserNameIdentityToken or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getUserNameIdentityToken(UserNameIdentityToken& target) const = 0;
		/*! Sets the value to a scalar of type UserNameIdentityToken. */
		virtual EnumStatusCode setUserNameIdentityToken(const IUserNameIdentityToken* pUserNameIdentityToken) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<UserNameIdentityToken> getUserNameIdentityTokenArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match UserNameIdentityToken or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getUserNameIdentityTokenArray(std::vector<UserNameIdentityToken>& target) const = 0;
		/*! Sets the value to an array of type UserNameIdentityToken. */
		virtual EnumStatusCode setUserNameIdentityTokenArray(const std::vector<UserNameIdentityToken>& arrayUserNameIdentityToken) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for X509IdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual X509IdentityToken getX509IdentityToken() const = 0;
		/*! Returns the content of the Value. If DataType does not match X509IdentityToken or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getX509IdentityToken(X509IdentityToken& target) const = 0;
		/*! Sets the value to a scalar of type X509IdentityToken. */
		virtual EnumStatusCode setX509IdentityToken(const IX509IdentityToken* pX509IdentityToken) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<X509IdentityToken> getX509IdentityTokenArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match X509IdentityToken or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getX509IdentityTokenArray(std::vector<X509IdentityToken>& target) const = 0;
		/*! Sets the value to an array of type X509IdentityToken. */
		virtual EnumStatusCode setX509IdentityTokenArray(const std::vector<X509IdentityToken>& arrayX509IdentityToken) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for IssuedIdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual IssuedIdentityToken getIssuedIdentityToken() const = 0;
		/*! Returns the content of the Value. If DataType does not match IssuedIdentityToken or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getIssuedIdentityToken(IssuedIdentityToken& target) const = 0;
		/*! Sets the value to a scalar of type IssuedIdentityToken. */
		virtual EnumStatusCode setIssuedIdentityToken(const IIssuedIdentityToken* pIssuedIdentityToken) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<IssuedIdentityToken> getIssuedIdentityTokenArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match IssuedIdentityToken or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getIssuedIdentityTokenArray(std::vector<IssuedIdentityToken>& target) const = 0;
		/*! Sets the value to an array of type IssuedIdentityToken. */
		virtual EnumStatusCode setIssuedIdentityTokenArray(const std::vector<IssuedIdentityToken>& arrayIssuedIdentityToken) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SignedSoftwareCertificate content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual SignedSoftwareCertificate getSignedSoftwareCertificate() const = 0;
		/*! Returns the content of the Value. If DataType does not match SignedSoftwareCertificate or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getSignedSoftwareCertificate(SignedSoftwareCertificate& target) const = 0;
		/*! Sets the value to a scalar of type SignedSoftwareCertificate. */
		virtual EnumStatusCode setSignedSoftwareCertificate(const ISignedSoftwareCertificate* pSignedSoftwareCertificate) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<SignedSoftwareCertificate> getSignedSoftwareCertificateArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match SignedSoftwareCertificate or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getSignedSoftwareCertificateArray(std::vector<SignedSoftwareCertificate>& target) const = 0;
		/*! Sets the value to an array of type SignedSoftwareCertificate. */
		virtual EnumStatusCode setSignedSoftwareCertificateArray(const std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for BuildInfo content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual BuildInfo getBuildInfo() const = 0;
		/*! Returns the content of the Value. If DataType does not match BuildInfo or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getBuildInfo(BuildInfo& target) const = 0;
		/*! Sets the value to a scalar of type BuildInfo. */
		virtual EnumStatusCode setBuildInfo(const IBuildInfo* pBuildInfo) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<BuildInfo> getBuildInfoArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match BuildInfo or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getBuildInfoArray(std::vector<BuildInfo>& target) const = 0;
		/*! Sets the value to an array of type BuildInfo. */
		virtual EnumStatusCode setBuildInfoArray(const std::vector<BuildInfo>& arrayBuildInfo) = 0;

#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// Value access for EventFilter content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual EventFilter getEventFilter() const = 0;
		/*! Returns the content of the Value. If DataType does not match EventFilter or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getEventFilter(EventFilter& target) const = 0;
		/*! Sets the value to a scalar of type EventFilter. */
		virtual EnumStatusCode setEventFilter(const IEventFilter* pEventFilter) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<EventFilter> getEventFilterArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match EventFilter or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getEventFilterArray(std::vector<EventFilter>& target) const = 0;
		/*! Sets the value to an array of type EventFilter. */
		virtual EnumStatusCode setEventFilterArray(const std::vector<EventFilter>& arrayEventFilter) = 0;

#endif

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServerStatus content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ServerStatusDataType getServerStatusDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServerStatusDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getServerStatusDataType(ServerStatusDataType& target) const = 0;
		/*! Sets the value to a scalar of type ServerStatusDataType. */
		virtual EnumStatusCode setServerStatusDataType(const IServerStatusDataType* pServerStatusDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ServerStatusDataType> getServerStatusDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServerStatusDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getServerStatusDataTypeArray(std::vector<ServerStatusDataType>& target) const = 0;
		/*! Sets the value to an array of type ServerStatusDataType. */
		virtual EnumStatusCode setServerStatusDataTypeArray(const std::vector<ServerStatusDataType>& arrayServerStatusDataType) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EnumValueType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual EnumValueType getEnumValueType() const = 0;
		/*! Returns the content of the Value. If DataType does not match EnumValueType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getEnumValueType(EnumValueType& target) const = 0;
		/*! Sets the value to a scalar of type EnumValueType. */
		virtual EnumStatusCode setEnumValueType(const IEnumValueType* pEnumValueType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<EnumValueType> getEnumValueTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match EnumValueType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getEnumValueTypeArray(std::vector<EnumValueType>& target) const = 0;
		/*! Sets the value to an array of type EnumValueType. */
		virtual EnumStatusCode setEnumValueTypeArray(const std::vector<EnumValueType>& arrayEnumValueType) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for structured data types
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of a user defined structured value.
		* If DataType is not a user defined data type (simple data type, a well known structured data type or an unknown type)
		* or ArrayType is not EnumValueArryType_Scalar, an error is returned.
		*
		* @param [in]	dataTypeDescription	The description for the current structured data type including the descriptions of the fields
		* @param [out]	fieldValues			Returns the values of the single fields of the structured data type
		*
		* @note	The amount, type and order of @p fieldValues matches to the field descriptions in @p dataTypeDescription.
		*		The field values of nested custom structures are returned as one single value of the type ValueArray.
		*		The field values of arrays of nested structures are returned as one single value of the type ValueArray of ValueArray.
		* @see	StructuredDataTypeDescription::getFields() */
		virtual EnumStatusCode getStructuredValue(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<Value>& fieldValues) const = 0;
		/*! Sets the value to a scalar of a user defined structured value.
		*
		* @param [in]	dataTypeId			The NodeId of the used DataType
		* @param [in]	dataTypeDescription	The description for the current structured data type
		* @param [in]	fieldValues			The values of the single fields of the structured data type
		*
		* @note	The amount, type and order of @p fieldValues have to match to the field descriptions of @p dataTypeDescription.
		*		The field values of nested custom structures have to be set via one single value of the type ValueArray.
		*		The field values of arrays of nested structures have to be set via one single value of the type ValueArray of ValueArray.
		* @see	StructuredDataTypeDescription::getFields() */
		virtual EnumStatusCode setStructuredValue(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<Value>& fieldValues) = 0;

		/*! Returns the content of a user defined structured value.
		* If DataType is not a user defined data type (simple data type, a well known structured data type or an unknown type)
		* or ArrayType is not EnumValueArryType_Array, an error is returned.
		*
		* @param [in]	dataTypeDescription	The description for the current structured data type including the descriptions of the fields
		* @param [out]	fieldValues			Returns the values of the single fields of the structured data type for every array element
		*
		* @note	The amount, type and order of @p fieldValues of every array element matches to the field descriptions in @p dataTypeDescription.
		*		The field values of nested custom structures are returned as one single value of the type ValueArray.
		*		The field values of arrays of nested structures are returned as one single value of the type ValueArray of ValueArray.
		* @see	StructuredDataTypeDescription::getFields() */
		virtual EnumStatusCode getStructuredValueArray(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<std::vector<Value> >& fieldValues) const = 0;
		/*! Sets the value to an array of a user defined structured value.
		*
		* @param [in]	dataTypeId			The NodeId of the used DataType
		* @param [in]	dataTypeDescription	The description for the current structured data type
		* @param [in]	fieldValues			The values of the single fields of the structured data type for every array element
		*
		* @note	The amount, type and order of @p fieldValues for every array element have to match to the field descriptions of @p dataTypeDescription.
		*		The field values of nested custom structures have to be set via value of the type ValueArray.
		*		The field values of arrays of nested structures have to be set via one single value of the type ValueArray of ValueArray.
		* @see	StructuredDataTypeDescription::getFields() */
		virtual EnumStatusCode setStructuredValueArray(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<std::vector<Value> >& fieldValues) = 0;

		/*! Returns the encoded value of a user defined complex value.
		* If DataType is not a user defined complex data type (simple data type or a well known complex data type)
		* or ArrayType is not EnumValueArrayType_Scalar, an error is returned.
		*
		* @param [out]	encodingId		The NodeId to identify the data type encoding
		* @param [out]	body			The encoded body of the complex data type
		*
		* @note	The @p encodingId is the NodeId, which is sent on the wire and it is different to the NodeId of the data type. */
		virtual EnumStatusCode getComplexValueRaw(NodeId& encodingId, ByteString& body) const = 0;
		/*! Sets the encoded value of a user defined complex value.
		*
		* @param [in]	encodingId		The NodeId to identify the data type encoding
		* @param [in]	body			The encoded body of the complex data type
		*
		* @note	There are no checks for the content of @p body, so the application has to take care that this represents a valid decodable value.
		*		The @p encodingId is the NodeId, which is sent on the wire and it is different to the NodeId of the data type. */
		virtual EnumStatusCode setComplexValueRaw(const INodeId& encodingId, const IByteString& body) = 0;

		/*! Returns the contents of a user defined complex value array.
		* If DataType is not a user defined complex data type (simple data type or a well known structured data type)
		* or ArrayType is not EnumValueArrayType_Array, an error is returned.
		*
		* @param [out]	encodingId	The NodeIds to identify the data type encodings of the encoded values
		* @param [out]	bodies		The encoded bodies of all complex data type values
		*
		* @note	There are no checks for the contents of @p bodies, so the application has to take care that they represent a valid decodable value.
		*		The @p encodingId is the NodeId, which is sent on the wire and it is different to the NodeId of the data type. */
		virtual EnumStatusCode getComplexValueRawArray(NodeId& encodingId, std::vector<ByteString>& bodies) const = 0;
		/*! Sets an array of encoded user defined complex values.
		*
		* @param [in]	encodingId	The NodeId to identify the data type encodings of the encoded values
		* @param [in]	bodies		The encoded bodies for all complex data type values
		*
		* @note	There are no checks for the contents of @p bodies, so the application has to take care that they represent a valid decodable value.
		*		The @p encodingId is the NodeId, which is sent on the wire and it is different to the NodeId of the data type. */
		virtual EnumStatusCode setComplexValueRawArray(const INodeId& encodingId, const std::vector<ByteString>& bodies) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for variant content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<Value> getValueArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match BaseDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getValueArray(std::vector<Value>& target) const = 0;
		/*! Sets the value to an array of variants (DataType BaseDataType). */
		virtual EnumStatusCode setValueArray(const std::vector<Value>& arrayValue) = 0;


		/*! Returns a string representation of the value */
		virtual tstring toString() const = 0;

		/*! Clears the contents of this object to enable its re-use. */
		virtual void clear() = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IValue* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IValue& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IValue* other) const = 0;
		/*! @overload */
		virtual int compare(const IValue& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IValue& other) = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IValue& other) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IValue
} // end namespace
#endif	// IVALUE_H
