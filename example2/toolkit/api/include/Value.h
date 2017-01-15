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

#ifndef VALUE_H
#define VALUE_H

#include "ValueStruct.h"
#include "IValue.h"
#include "Enums.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	// Forward declarations
	class NodeId;
	class ExpandedNodeId;
	class LocalizedText;
	class DataValue;
	class IDataValue;
	class IDateTime;
	class IApplicationDescription;
	class IServerDiagnosticsSummaryDataType;
	class ISubscriptionDiagnosticsDataType;
	class ISessionDiagnosticsDataType;
	class ISessionSecurityDiagnosticsDataType;
	class IServiceCounterDataType;
	class ISemanticChangeStructureDataType;
	class IModelChangeStructureDataType;
	class DateTime;
	class IGuid;
	class ByteString;
	class Guid;
	class QualifiedName;
	class IQualifiedName;
	class INodeId;
	class ILocalizedtext;
	class IExpandedNodeId;
	class ILocalizedText;
	class IArgument;
	class IReferenceDescription;
	class AnonymousIdentityToken;
	class IAnonymousIdentityToken;
	class UserNameIdentityToken;
	class IUserNameIdentityToken;
	class X509IdentityToken;
	class IX509IdentityToken;
	class IssuedIdentityToken;
	class IIssuedIdentityToken;
	class EnumerationDataTypeDescription;

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
	class TBC_EXPORT Value
		: public IValue
	{
	public:
		/*! Default constructor which initializes the value to null.
		* The array type is set to EnumValueArrayType_Scalar, the data type is
		* set to EnumDataTypeId_Null. */
		Value();
		/*! Constructs a copy of the given instance */
		Value(const Value& cp);
		/*! @overload */
		Value(const IValue*);
		/*! Constructor that initializes the variant with the given value. */
		Value(const std::vector<Value>& arrayValue);
		/*! @overload */
		Value(OTBoolean value);
		/*! @overload */
		Value(const std::vector<OTBoolean>& arrayBool);
		/*! @overload */
		Value(OTUInt8 value);
		/*! @overload */
		Value(const std::vector<OTUInt8>& arrayUInt8);
		/*! @overload */
		Value(OTInt8 value);
		/*! @overload */
		Value(const std::vector<OTInt8>& arrayInt8);
		/*! @overload */
		Value(OTUInt16 value);
		/*! @overload */
		Value(const std::vector<OTUInt16>& arrayUInt16);
		/*! @overload */
		Value(OTInt16 value);
		/*! @overload */
		Value(const std::vector<OTInt16>& arrayInt16);
		/*! @overload */
		Value(OTUInt32 value);
		/*! @overload */
		Value(const std::vector<OTUInt32>& arrayUInt32);
		/*! @overload */
		Value(OTInt32 value);
		/*! @overload */
		Value(const std::vector<OTInt32>& arrayInt32);
		/*! @overload */
		Value(OTUInt64 value);
		/*! @overload */
		Value(const std::vector<OTUInt64>& arrayUInt64);
		/*! @overload */
		Value(OTInt64 value);
		/*! @overload */
		Value(const std::vector<OTInt64>& arrayInt64);
		/*! @overload */
		Value(OTFloat value);
		/*! @overload */
		Value(const std::vector<OTFloat>& arrayFloat);
		/*! @overload */
		Value(OTDouble value);
		/*! @overload */
		Value(const std::vector<OTDouble>& arrayDouble);
		/*! @overload */
		Value(const TCHAR* value);
		/*! @overload */
		Value(const tstring& value);
		/*! @overload */
		Value(const std::vector<tstring>& arrayString);
		/*! @overload */
		Value(const IDateTime* value);
		/*! @overload */
		Value(const std::vector<DateTime>& arrayDateTime);
		/*! @overload */
		Value(const unsigned char* pData, unsigned length);
		/*! @overload */
		Value(const IByteString* pByteString);
		/*! @overload */
		Value(const std::vector<ByteString>& arrayByteString);
		/*! @overload */
		Value(const IGuid* pGuid);
		/*! @overload */
		Value(const std::vector<Guid>& arrayGuid);
		/*! @overload */
		Value(const INodeId* pNodeId);
		/*! @overload */
		Value(const std::vector<NodeId>& arrayNodeId);
		/*! @overload */
		Value(const IExpandedNodeId* pNodeId);
		/*! @overload */
		Value(const std::vector<ExpandedNodeId>& arrayExpandedNodeId);
		/*! @overload */
		Value(EnumStatusCode statusCode);
		/*! @overload */
		Value(const std::vector<EnumStatusCode>& arrayStatusCode);
		/*! @overload */
		Value(const IQualifiedName*  pQualifiedName);
		/*! @overload */
		Value(const std::vector<QualifiedName>& arrayQualifiedName);
		/*! @overload */
		Value(const ILocalizedText* pLocalizedText);
		/*! @overload */
		Value(const std::vector<LocalizedText>& arrayLocalizedText);
		/*! @overload */
		Value(const IDataValue*	pDataValue);
		/*! @overload */
		Value(const std::vector<DataValue>& arrayDataValue);
		/*! @overload */
		Value(const IArgument* pArgument);
		/*! @overload */
		Value(const std::vector<Argument>& arrayArgument);
		/*! @overload */
		Value(const IRange*	pRange);
		/*! @overload */
		Value(const std::vector<Range>& arrayRange);
		/*! @overload */
		Value(const IReferenceDescription* pReferenceDescription);
		/*! @overload */
		Value(const std::vector<ReferenceDescription>& arrayReferenceDescription);
		/*! @overload */
		Value(const IApplicationDescription* pApplicationDescription);
		/*! @overload */
		Value(const std::vector<ApplicationDescription>& arrayApplicationDescription);
		/*! @overload */
		Value(const IServerDiagnosticsSummaryDataType* pServerDiagnosticsSummaryDataType);
		/*! @overload */
		Value(const std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType);
		/*! @overload */
		Value(const ISubscriptionDiagnosticsDataType* pSubscriptionDiagnosticsDataType);
		/*! @overload */
		Value(const std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType);
		/*! @overload */
		Value(const ISessionDiagnosticsDataType* pSessionDiagnosticsDataType);
		/*! @overload */
		Value(const std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType);
		/*! @overload */
		Value(const ISessionSecurityDiagnosticsDataType* pSessionSecurityDiagnosticsDataType);
		/*! @overload */
		Value(const std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType);
		/*! @overload */
		Value(const IServiceCounterDataType* pServiceCounterDataType);
		/*! @overload */
		Value(const std::vector<ServiceCounterDataType>& arrayServiceCounterDataType);
		/*! @overload */
		Value(const IEUInformation* pEUInformation);
		/*! @overload */
		Value(const std::vector<EUInformation>& arrayEUInformation);
		/*! @overload */
		Value(const ITimeZone* pTimeZone);
		/*! @overload */
		Value(const std::vector<TimeZone>& arrayTimeZone);
		/*! @overload */
		Value(const IUserIdentityToken* pUserIdentityToken);
		/*! @overload */
		Value(const std::vector<UserIdentityToken>& arrayUserIdentityToken);
		/*! @overload */
		Value(const IAnonymousIdentityToken* pAnonymousIdentityToken);
		/*! @overload */
		Value(const std::vector<AnonymousIdentityToken>& arrayAnonymousIdentityToken);
		/*! @overload */
		Value(const IUserNameIdentityToken* pUserNameIdentityToken);
		/*! @overload */
		Value(const std::vector<UserNameIdentityToken>& arrayUserNameIdentityToken);
		/*! @overload */
		Value(const IX509IdentityToken* pCertificateIdentityToken);
		/*! @overload */
		Value(const std::vector<X509IdentityToken>& arrayCertificateIdentityToken);
		/*! @overload */
		Value(const IIssuedIdentityToken* pIssuedIdentityToken);
		/*! @overload */
		Value(const std::vector<IssuedIdentityToken>& arrayIssuedIdentityToken);
		/*! @overload */
		Value(const std::vector<const ISignedSoftwareCertificate*>& arraySignedSoftwareCertificate);
		/*! @overload */
		Value(const ISignedSoftwareCertificate* pSignedSoftwareCertificate);
		/*! @overload */
		Value(const std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate);
		/*! @overload */
		Value(const IBuildInfo* pBuildInfo);
		/*! @overload */
		Value(const std::vector<BuildInfo>& arrayBuildInfo);
		/*! @overload */
		Value(const IEventFilter* pEventFilter);
		/*! @overload */
		Value(const std::vector<EventFilter>& arrayEventFilter);
		/*! @overload */
		Value(const IServerStatusDataType* pServerStatusDataType);
		/*! @overload */
		Value(const std::vector<ServerStatusDataType>& arrayServerStatusDataType);
		/*! @overload */
		Value(const IEnumValueType* pEnumValueType);
		/*! @overload */
		Value(const std::vector<EnumValueType>& arrayEnumValueType);

		/*! Destructor */
		virtual ~Value();

		/*! Assigns the contents of @p cp to this instance */
		Value& operator=(const IValue* cp);
		/*! @overload */
		Value& operator=(const IValue& cp);
		/*! @overload */
		Value& operator=(const Value& cp);

		/* see IValue::set */
		virtual EnumStatusCode set(const IValue* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IValue& pSrc);

		/* see IValue::compare */
		virtual int compare(const IValue* other) const;
		/*! @overload */
		virtual int compare(const IValue& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IValue& other);
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IValue& other);

		/*! Returns whether two Value instances are equal.
		*
		* If this method is applied to two instances @p value1 and @p value2, the result
		* is equivalent to value1.compare(value2) == 0. */
		static bool areEqual(const Value& value1, const Value& value2);

		/* see IValue::getDataType */
		virtual EnumDataTypeId getDataType() const;

		/* see IValue::getArrayType */
		virtual EnumValueArrayType getArrayType() const;

		/* see IValue::getSubset */
		virtual EnumStatusCode getSubset(IValue& result, const INumericRange* indexRange) const;
		/* see IValue::setSubset */
		virtual EnumStatusCode setSubset(const IValue& value, const INumericRange* indexRange);

		/* see IValue::canCastTo */
		virtual EnumValueCastType canCastTo(EnumDataTypeId dataType) const;
		/* see IValue::castTo */
		virtual EnumStatusCode castTo(EnumDataTypeId dataType, IValue& castedValue) const;

		/* see IValue::toString */
		virtual tstring toString() const;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Boolean content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getBoolean */
		virtual EnumStatusCode getBoolean(OTBoolean* target) const;
		/*! @overload */
		virtual OTBoolean getBoolean() const;
		/* see IValue::setBoolean */
		virtual void setBoolean(OTBoolean value);

		/* see IValue::getBooleanArray */
		virtual std::vector<OTBoolean> getBooleanArray() const;
		/*! @overload */
		virtual EnumStatusCode getBooleanArray(std::vector<OTBoolean>& target) const;
		/* see IValue::setBooleanArray */
		virtual EnumStatusCode setBooleanArray(const std::vector<OTBoolean>& arrayBool);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt8 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUInt8 */
		virtual EnumStatusCode getUInt8(OTUInt8* target) const;
		/*! @overload */
		virtual OTUInt8 getUInt8() const;
		/* see IValue::setUInt8 */
		virtual void setUInt8(OTUInt8 value);

		/* see IValue::getUInt8Array */
		virtual EnumStatusCode getUInt8Array(std::vector<OTUInt8>& target) const;
		/*! @overload */
		virtual std::vector<OTUInt8> getUInt8Array() const;
		/* see IValue::setUInt8Array */
		virtual EnumStatusCode setUInt8Array(const std::vector<OTUInt8>& arrayUInt8);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int8 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getInt8 */
		virtual EnumStatusCode getInt8(OTInt8* target) const;
		/*! @overload */
		virtual OTInt8 getInt8() const;
		/* see IValue::setInt8 */
		virtual void setInt8(OTInt8 value);

		/* see IValue::getInt8Array */
		virtual EnumStatusCode getInt8Array(std::vector<OTInt8>& target) const;
		/*! @overload */
		virtual std::vector<OTInt8> getInt8Array() const;
		/* see IValue::setInt8Array */
		virtual EnumStatusCode setInt8Array(const std::vector<OTInt8>& arrayInt8);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt16 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUInt16 */
		virtual EnumStatusCode getUInt16(OTUInt16* target) const;
		/*! @overload */
		virtual OTUInt16 getUInt16() const;
		/* see IValue::setUInt16 */
		virtual void setUInt16(OTUInt16 value);

		/* see IValue::getUInt16Array */
		virtual EnumStatusCode getUInt16Array(std::vector<OTUInt16>& target) const;
		/*! @overload */
		virtual std::vector<OTUInt16> getUInt16Array() const;
		/* see IValue::setUInt16Array */
		virtual EnumStatusCode setUInt16Array(const std::vector<OTUInt16>& arrayUInt16);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int16 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getInt16 */
		virtual EnumStatusCode getInt16(OTInt16* target) const;
		/*! @overload */
		virtual OTInt16 getInt16() const;
		/* see IValue::setInt16 */
		virtual void setInt16(OTInt16 value);

		/* see IValue::getInt16Array */
		virtual EnumStatusCode getInt16Array(std::vector<OTInt16>& target) const;
		/*! @overload */
		virtual std::vector<OTInt16> getInt16Array() const;
		/* see IValue::setInt16Array */
		virtual EnumStatusCode setInt16Array(const std::vector<OTInt16>& arrayInt16);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt32 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUInt32 */
		virtual EnumStatusCode getUInt32(OTUInt32* target) const;
		/*! @overload */
		virtual OTUInt32 getUInt32() const;
		/* see IValue::setUInt32 */
		virtual void setUInt32(OTUInt32 value);

		/* see IValue::getInt32Array */
		virtual EnumStatusCode getInt32Array(std::vector<OTInt32>& target) const;
		/*! @overload */
		virtual std::vector<OTInt32> getInt32Array() const;
		/* see IValue::setInt32Array */
		virtual EnumStatusCode setUInt32Array(const std::vector<OTUInt32>& arrayUInt32);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int32 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getInt32 */
		virtual EnumStatusCode getInt32(OTInt32* target) const;
		/*! @overload */
		virtual OTInt32 getInt32() const;
		/* see IValue::setInt32 */
		virtual void setInt32(OTInt32 value);

		/* see IValue::getUInt32Array */
		virtual EnumStatusCode getUInt32Array(std::vector<OTUInt32>& target) const;
		/*! @overload */
		virtual std::vector<OTUInt32> getUInt32Array() const;
		/* see IValue::setUInt32Array */
		virtual EnumStatusCode setInt32Array(const std::vector<OTInt32>& arrayInt32);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt64 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUInt64 */
		virtual EnumStatusCode getUInt64(OTUInt64* target) const;
		/*! @overload */
		virtual OTUInt64 getUInt64() const;
		/* see IValue::setUInt64 */
		virtual void setUInt64(OTUInt64 value);

		/* see IValue::getUInt64Array */
		virtual EnumStatusCode getUInt64Array(std::vector<OTUInt64>& target) const;
		/*! @overload */
		virtual std::vector<OTUInt64> getUInt64Array() const;
		/* see IValue::setUInt64Array */
		virtual EnumStatusCode setUInt64Array(const std::vector<OTUInt64>& arrayUInt64);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int64 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getInt64 */
		virtual EnumStatusCode getInt64(OTInt64* target) const;
		/*! @overload */
		virtual OTInt64 getInt64() const;
		/* see IValue::setInt64 */
		virtual void setInt64(OTInt64 value);

		/* see IValue::getInt64Array */
		virtual EnumStatusCode getInt64Array(std::vector<OTInt64>& target) const;
		/*! @overload */
		virtual std::vector<OTInt64> getInt64Array() const;
		/* see IValue::setInt64Array */
		virtual EnumStatusCode setInt64Array(const std::vector<OTInt64>& arrayInt64);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Float content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getFloat */
		virtual EnumStatusCode getFloat(OTFloat* target) const;
		/*! @overload */
		virtual OTFloat getFloat() const;
		/* see IValue::setFloat */
		virtual void setFloat(OTFloat value);

		/* see IValue::getFloatArray */
		virtual EnumStatusCode getFloatArray(std::vector<OTFloat>& target) const;
		/*! @overload */
		virtual std::vector<OTFloat> getFloatArray() const;
		/* see IValue::setFloatArray */
		virtual EnumStatusCode setFloatArray(const std::vector<OTFloat>& arrayFloat);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Double content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getDouble */
		virtual EnumStatusCode getDouble(OTDouble* target) const;
		/*! @overload */
		virtual OTDouble getDouble() const;
		/* see IValue::setDouble */
		virtual void setDouble(OTDouble value);

		/* see IValue::getDoubleArray */
		virtual EnumStatusCode getDoubleArray(std::vector<OTDouble>& target) const;
		/*! @overload */
		virtual std::vector<OTDouble> getDoubleArray() const;
		/* see IValue::setDoubleArray */
		virtual EnumStatusCode setDoubleArray(const std::vector<OTDouble>& arrayDouble);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DateTime content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getDateTime */
		virtual EnumStatusCode getDateTime(DateTime& target) const;
		/*! @overload */
		virtual DateTime getDateTime() const;
		/* see IValue::setDateTime */
		virtual EnumStatusCode setDateTime(const IDateTime* dateTime);

		/* see IValue::getDateTimeArray */
		virtual EnumStatusCode getDateTimeArray(std::vector<DateTime>& target) const;
		/*! @overload */
		virtual std::vector<DateTime> getDateTimeArray() const;
		/* see IValue::setDateTimeArray */
		virtual EnumStatusCode setDateTimeArray(const std::vector<DateTime>& arrayDateTime);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for String content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getString */
		virtual EnumStatusCode getString(tstring& target) const;
		/*! @overload */
		virtual tstring getString() const;
		/* see IValue::setString */
		virtual EnumStatusCode setString(const tstring& value);

		/* see IValue::getStringArray */
		virtual EnumStatusCode getStringArray(std::vector<tstring>& target) const;
		/*! @overload */
		virtual std::vector<tstring> getStringArray() const;
		/* see IValue::setStringArray */
		virtual EnumStatusCode setStringArray(const std::vector<tstring>& arrayString);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Guid content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getGuid */
		virtual EnumStatusCode getGuid(Guid& target) const;
		/*! @overload */
		virtual Guid getGuid() const;
		/* see IValue::setGuid */
		virtual EnumStatusCode setGuid(const IGuid* guid);

		/* see IValue::getGuidArray */
		virtual EnumStatusCode getGuidArray(std::vector<Guid>& target) const;
		/*! @overload */
		virtual std::vector<Guid> getGuidArray() const;
		/* see IValue::setGuidArray */
		virtual EnumStatusCode setGuidArray(const std::vector<Guid>& arrayGuid);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EnumStatusCode content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getStatusCode */
		virtual EnumStatusCode getStatusCode(EnumStatusCode* target) const;
		/*! @overload */
		virtual EnumStatusCode getStatusCode() const;
		/* see IValue::setStatusCode */
		virtual void setStatusCode(EnumStatusCode statusCode);

		/* see IValue::getStatusCodeArray */
		virtual EnumStatusCode getStatusCodeArray(std::vector<EnumStatusCode>& target) const;
		/*! @overload */
		virtual std::vector<EnumStatusCode> getStatusCodeArray() const;
		/* see IValue::setStatusCodeArray */
		virtual EnumStatusCode setStatusCodeArray(const std::vector<EnumStatusCode>& arrayStatusCode);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ByteString content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getByteString */
		virtual EnumStatusCode getByteString(ByteString& target) const;
		/*! @overload */
		virtual ByteString getByteString() const;
		/* see IValue::setByteString */
		virtual EnumStatusCode setByteString(const unsigned char* pData, unsigned length);
		/*! @overload */
		virtual EnumStatusCode setByteString(const ByteString& byteString);
		/*! @overload */
		virtual EnumStatusCode setByteString(const IByteString* byteString);

		/* see IValue::getByteStringArray */
		virtual EnumStatusCode getByteStringArray(std::vector<ByteString>& target) const;
		/*! @overload */
		virtual std::vector<ByteString> getByteStringArray() const;
		/* see IValue::setByteStringArray */
		virtual EnumStatusCode setByteStringArray(const std::vector<ByteString>& arrayByteString);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for XmlElement content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getXmlElement */
		virtual EnumStatusCode getXmlElement(XmlElement& target) const;
		/*! @overload */
		virtual XmlElement getXmlElement() const;
		/* see IValue::setXmlElement */
		virtual EnumStatusCode setXmlElement(const XmlElement& xmlElement);

		/* see IValue::getXmlElementArray */
		virtual EnumStatusCode getXmlElementArray(std::vector<XmlElement>& target) const;
		/*! @overload */
		virtual std::vector<XmlElement> getXmlElementArray() const;
		/* see IValue::setXmlElementArray */
		virtual EnumStatusCode setXmlElementArray(const std::vector<XmlElement>& arrayXmlElement);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Value content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getValueArray */
		virtual EnumStatusCode getValueArray(std::vector<Value>& target) const;
		/*! @overload */
		virtual std::vector<Value> getValueArray() const;
		/* see IValue::setValueArray */
		virtual EnumStatusCode setValueArray(const std::vector<Value>& arrayValue);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DataValue content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getDataValue */
		virtual EnumStatusCode getDataValue(DataValue& target) const;
		/*! @overload */
		virtual DataValue getDataValue() const;
		/* see IValue::setDataValue */
		virtual EnumStatusCode setDataValue(const IDataValue* pDataValue);

		/* see IValue::getDataValueArray */
		virtual std::vector<DataValue> getDataValueArray() const;
		/*! @overload */
		virtual EnumStatusCode getDataValueArray(std::vector<DataValue>&) const;
		/* see IValue::setDataValueArray */
		virtual EnumStatusCode setDataValueArray(const std::vector<DataValue>& arrayDataValue);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ExpandedNodeId content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getExpandedNodeId */
		virtual EnumStatusCode getExpandedNodeId(ExpandedNodeId& target) const;
		/*! @overload */
		virtual ExpandedNodeId getExpandedNodeId() const;
		/* see IValue::setExpandedNodeId */
		virtual EnumStatusCode setExpandedNodeId(const IExpandedNodeId* pExpandedNodeId);

		/*! @overload */
		virtual EnumStatusCode getExpandedNodeIdArray(std::vector<ExpandedNodeId>&) const;
		/* see IValue::getExpandedNodeIdArray */
		virtual std::vector<ExpandedNodeId> getExpandedNodeIdArray() const;
		/* see IValue::setExpandedNodeIdArray */
		virtual EnumStatusCode setExpandedNodeIdArray(const std::vector<ExpandedNodeId>& arrayExpandedNodeId);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for LocalizedText content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getLocalizedText */
		virtual EnumStatusCode getLocalizedText(LocalizedText& target) const;
		/*! @overload */
		virtual LocalizedText getLocalizedText() const;
		/* see IValue::setLocalizedText */
		virtual EnumStatusCode setLocalizedText(const ILocalizedText* pLocalizedText);

		/* see IValue::getLocalizedTextArray */
		virtual std::vector<LocalizedText> getLocalizedTextArray() const;
		/*! @overload */
		virtual EnumStatusCode getLocalizedTextArray(std::vector<LocalizedText>&) const;
		/* see IValue::setLocalizedTextArray */
		virtual EnumStatusCode setLocalizedTextArray(const std::vector<LocalizedText>& arrayLocalizedText);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for QualifiedName content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getQualifiedName */
		virtual EnumStatusCode getQualifiedName(QualifiedName& target) const;
		/*! @overload */
		virtual QualifiedName getQualifiedName() const;
		/* see IValue::setQualifiedName */
		virtual EnumStatusCode setQualifiedName(const IQualifiedName* pQualifiedName);

		/* see IValue::getQualifiedNameArray */
		virtual std::vector<QualifiedName> getQualifiedNameArray() const;
		/*! @overload */
		virtual EnumStatusCode getQualifiedNameArray(std::vector<QualifiedName>&) const;
		/* see IValue::setQualifiedNameArray */
		virtual EnumStatusCode setQualifiedNameArray(const std::vector<QualifiedName>& arrayQualifiedName);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for NodeId content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getNodeId */
		virtual EnumStatusCode getNodeId(NodeId& target) const;
		/*! @overload */
		virtual NodeId getNodeId() const;
		/* see IValue::setNodeId */
		virtual EnumStatusCode setNodeId(const INodeId* pNodeId);

		/* see IValue::getNodeIdArray */
		virtual std::vector<NodeId> getNodeIdArray() const;
		/*! @overload */
		virtual EnumStatusCode getNodeIdArray(std::vector<NodeId>&) const;
		/* see IValue::setNodeIdArray */
		virtual EnumStatusCode setNodeIdArray(const std::vector<NodeId>& arrayNodeId);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EUInformation content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getEUInformation */
		virtual EnumStatusCode getEUInformation(EUInformation& target) const;
		/*! @overload */
		virtual EUInformation getEUInformation() const;
		/* see IValue::setEUInformation */
		virtual EnumStatusCode setEUInformation(const IEUInformation* pEUInformation);

		/* see IValue::getEUInformationArray */
		virtual std::vector<EUInformation> getEUInformationArray() const;
		/*! @overload */
		virtual EnumStatusCode getEUInformationArray(std::vector<EUInformation>&) const;
		/* see IValue::setEUInformationArray */
		virtual EnumStatusCode setEUInformationArray(const std::vector<EUInformation>& arrayEUInformation);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for TimeZone content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getTimeZone */
		virtual EnumStatusCode getTimeZone(TimeZone& target) const;
		/*! @overload */
		virtual TimeZone getTimeZone() const;
		/* see IValue::setTimeZone */
		virtual EnumStatusCode setTimeZone(const ITimeZone* pTimeZone);

		/* see IValue::getTimeZoneArray */
		virtual std::vector<TimeZone> getTimeZoneArray() const;
		/*! @overload */
		virtual EnumStatusCode getTimeZoneArray(std::vector<TimeZone>&) const;
		/* see IValue::setTimeZoneArray */
		virtual EnumStatusCode setTimeZoneArray(const std::vector<TimeZone>& arrayTimeZone);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Argument content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getArgument */
		virtual EnumStatusCode getArgument(Argument& target) const;
		/*! @overload */
		virtual Argument getArgument() const;
		/* see IValue::setArgument */
		virtual EnumStatusCode setArgument(const IArgument* pArgument);

		/* see IValue::getArgumentArray */
		virtual std::vector<Argument> getArgumentArray() const;
		/*! @overload */
		virtual EnumStatusCode getArgumentArray(std::vector<Argument>&) const;
		/* see IValue::setArgumentArray */
		virtual EnumStatusCode setArgumentArray(const std::vector<Argument>& arrayArgument);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Range content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getRange */
		virtual EnumStatusCode getRange(Range& target) const;
		/*! @overload */
		virtual Range getRange() const;
		/* see IValue::setRange */
		virtual EnumStatusCode setRange(const IRange* pRange);

		/* see IValue::getRangeArray */
		virtual std::vector<Range> getRangeArray() const;
		/*! @overload */
		virtual EnumStatusCode getRangeArray(std::vector<Range>&) const;
		/* see IValue::setRangeArray */
		virtual EnumStatusCode setRangeArray(const std::vector<Range>& arrayRange);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ReferenceDescription content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getReferenceDescription */
		virtual EnumStatusCode getReferenceDescription(ReferenceDescription& target) const;
		/*! @overload */
		virtual ReferenceDescription getReferenceDescription() const;
		/* see IValue::setReferenceDescription */
		virtual EnumStatusCode setReferenceDescription(const IReferenceDescription* pReferenceDescription);

		/* see IValue::getReferenceDescriptionArray */
		virtual std::vector<ReferenceDescription> getReferenceDescriptionArray() const;
		/*! @overload */
		virtual EnumStatusCode getReferenceDescriptionArray(std::vector<ReferenceDescription>&) const;
		/* see IValue::setReferenceDescriptionArray */
		virtual EnumStatusCode setReferenceDescriptionArray(const std::vector<ReferenceDescription>& arrayReferenceDescription);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ApplicationDescription content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getApplicationDescription */
		virtual EnumStatusCode getApplicationDescription(ApplicationDescription& target) const;
		/*! @overload */
		virtual ApplicationDescription getApplicationDescription() const;
		/* see IValue::setApplicationDescription */
		virtual EnumStatusCode setApplicationDescription(const IApplicationDescription* pApplicationDescription);

		/* see IValue::getApplicationDescriptionArray */
		virtual std::vector<ApplicationDescription> getApplicationDescriptionArray() const;
		/*! @overload */
		virtual EnumStatusCode getApplicationDescriptionArray(std::vector<ApplicationDescription>&) const;
		/* see IValue::setApplicationDescriptionArray */
		virtual EnumStatusCode setApplicationDescriptionArray(const std::vector<ApplicationDescription>& arrayApplicationDescription);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServerDiagnosticsSummaryDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getServerDiagnosticsSummaryDataType */
		virtual EnumStatusCode getServerDiagnosticsSummaryDataType(ServerDiagnosticsSummaryDataType& target) const;
		/*! @overload */
		virtual ServerDiagnosticsSummaryDataType getServerDiagnosticsSummaryDataType() const;
		/* see IValue::setServerDiagnosticsSummaryDataType */
		virtual EnumStatusCode setServerDiagnosticsSummaryDataType(const IServerDiagnosticsSummaryDataType* pServerDiagnosticsSummaryDataType);

		/* see IValue::getServerDiagnosticsSummaryDataTypeArray */
		virtual std::vector<ServerDiagnosticsSummaryDataType> getServerDiagnosticsSummaryDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getServerDiagnosticsSummaryDataTypeArray(std::vector<ServerDiagnosticsSummaryDataType>&) const;
		/* see IValue::setServerDiagnosticsSummaryDataTypeArray */
		virtual EnumStatusCode setServerDiagnosticsSummaryDataTypeArray(const std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SubscriptionDiagnosticsDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getSubscriptionDiagnosticsDataType */
		virtual EnumStatusCode getSubscriptionDiagnosticsDataType(SubscriptionDiagnosticsDataType& target) const;
		/*! @overload */
		virtual SubscriptionDiagnosticsDataType getSubscriptionDiagnosticsDataType() const;
		/* see IValue::setSubscriptionDiagnosticsDataType */
		virtual EnumStatusCode setSubscriptionDiagnosticsDataType(const ISubscriptionDiagnosticsDataType* pSubscriptionDiagnosticsDataType);

		/* see IValue::getSubscriptionDiagnosticsDataTypeArray */
		virtual std::vector<SubscriptionDiagnosticsDataType> getSubscriptionDiagnosticsDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getSubscriptionDiagnosticsDataTypeArray(std::vector<SubscriptionDiagnosticsDataType>&) const;
		/* see IValue::setSubscriptionDiagnosticsDataTypeArray */
		virtual EnumStatusCode setSubscriptionDiagnosticsDataTypeArray(const std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SessionDiagnosticsDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getSessionDiagnosticsDataType */
		virtual EnumStatusCode getSessionDiagnosticsDataType(SessionDiagnosticsDataType& target) const;
		/*! @overload */
		virtual SessionDiagnosticsDataType getSessionDiagnosticsDataType() const;
		/* see IValue::setSessionDiagnosticsDataType */
		virtual EnumStatusCode setSessionDiagnosticsDataType(const ISessionDiagnosticsDataType* pSessionDiagnosticsDataType);

		/* see IValue::getSessionDiagnosticsDataTypeArray */
		virtual std::vector<SessionDiagnosticsDataType> getSessionDiagnosticsDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getSessionDiagnosticsDataTypeArray(std::vector<SessionDiagnosticsDataType>&) const;
		/* see IValue::setSessionDiagnosticsDataTypeArray */
		virtual EnumStatusCode setSessionDiagnosticsDataTypeArray(const std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SessionSecurityDiagnosticsDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getSessionSecurityDiagnosticsDataType */
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataType(SessionSecurityDiagnosticsDataType& target) const;
		/*! @overload */
		virtual SessionSecurityDiagnosticsDataType getSessionSecurityDiagnosticsDataType() const;
		/* see IValue::setSessionSecurityDiagnosticsDataType */
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataType(const ISessionSecurityDiagnosticsDataType* pSessionSecurityDiagnosticsDataType);

		/* see IValue::getSessionSecurityDiagnosticsDataTypeArray */
		virtual std::vector<SessionSecurityDiagnosticsDataType> getSessionSecurityDiagnosticsDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataTypeArray(std::vector<SessionSecurityDiagnosticsDataType>&) const;
		/* see IValue::setSessionSecurityDiagnosticsDataTypeArray */
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray(const std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServiceCounterDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getServiceCounterDataType */
		virtual EnumStatusCode getServiceCounterDataType(ServiceCounterDataType& target) const;
		/*! @overload */
		virtual ServiceCounterDataType getServiceCounterDataType() const;
		/* see IValue::setServiceCounterDataType */
		virtual EnumStatusCode setServiceCounterDataType(const IServiceCounterDataType* pServiceCounterDataType);

		/* see IValue::getServiceCounterDataTypeArray */
		virtual std::vector<ServiceCounterDataType> getServiceCounterDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getServiceCounterDataTypeArray(std::vector<ServiceCounterDataType>&) const;
		/* see IValue::setServiceCounterDataTypeArray */
		virtual EnumStatusCode setServiceCounterDataTypeArray(const std::vector<ServiceCounterDataType>& arrayServiceCounterDataType);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UserIdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUserIdentityToken */
		virtual EnumStatusCode getUserIdentityToken(UserIdentityToken& target) const;
		/*! @overload */
		virtual UserIdentityToken getUserIdentityToken() const;
		/* see IValue::setUserIdentityToken */
		virtual EnumStatusCode setUserIdentityToken(const IUserIdentityToken* pUserIdentityToken);

		/* see IValue::getUserIdentityTokenArray */
		virtual std::vector<UserIdentityToken> getUserIdentityTokenArray() const;
		/*! @overload */
		virtual EnumStatusCode getUserIdentityTokenArray(std::vector<UserIdentityToken>&) const;
		/* see IValue::setUserIdentityTokenArray */
		virtual EnumStatusCode setUserIdentityTokenArray(const std::vector<UserIdentityToken>& arrayUserIdentityToken);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for AnonymousIdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getAnonymousIdentityToken */
		virtual AnonymousIdentityToken getAnonymousIdentityToken() const;
		/*! @overload */
		virtual EnumStatusCode getAnonymousIdentityToken(AnonymousIdentityToken& target) const;
		/* see IValue::setAnonymousIdentityToken */
		virtual EnumStatusCode setAnonymousIdentityToken(const IAnonymousIdentityToken* pAnonymousIdentityToken);

		/* see IValue::getAnonymousIdentityTokenArray */
		virtual std::vector<AnonymousIdentityToken> getAnonymousIdentityTokenArray() const;
		/*! @overload */
		virtual EnumStatusCode getAnonymousIdentityTokenArray(std::vector<AnonymousIdentityToken>& target) const;
		/* see IValue::setAnonymousIdentityTokenArray */
		virtual EnumStatusCode setAnonymousIdentityTokenArray(const std::vector<AnonymousIdentityToken>& arrayAnonymousIdentityToken);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UserNameIdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUserNameIdentityToken */
		virtual UserNameIdentityToken getUserNameIdentityToken() const;
		/*! @overload */
		virtual EnumStatusCode getUserNameIdentityToken(UserNameIdentityToken& target) const;
		/* see IValue::setUserNameIdentityToken */
		virtual EnumStatusCode setUserNameIdentityToken(const IUserNameIdentityToken* pUserNameIdentityToken);

		/* see IValue::getUserNameIdentityTokenArray */
		virtual std::vector<UserNameIdentityToken> getUserNameIdentityTokenArray() const;
		/*! @overload */
		virtual EnumStatusCode getUserNameIdentityTokenArray(std::vector<UserNameIdentityToken>& target) const;
		/* see IValue::setUserNameIdentityTokenArray */
		virtual EnumStatusCode setUserNameIdentityTokenArray(const std::vector<UserNameIdentityToken>& arrayUserNameIdentityToken);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for X509IdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getX509IdentityToken */
		virtual X509IdentityToken getX509IdentityToken() const;
		/*! @overload */
		virtual EnumStatusCode getX509IdentityToken(X509IdentityToken& target) const;
		/* see IValue::setX509IdentityToken */
		virtual EnumStatusCode setX509IdentityToken(const IX509IdentityToken* pX509IdentityToken);

		/* see IValue::getX509IdentityTokenArray */
		virtual std::vector<X509IdentityToken> getX509IdentityTokenArray() const;
		/*! @overload */
		virtual EnumStatusCode getX509IdentityTokenArray(std::vector<X509IdentityToken>& target) const;
		/* see IValue::setX509IdentityTokenArray */
		virtual EnumStatusCode setX509IdentityTokenArray(const std::vector<X509IdentityToken>& arrayX509IdentityToken);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for IssuedIdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getIssuedIdentityToken */
		virtual IssuedIdentityToken getIssuedIdentityToken() const;
		/*! @overload */
		virtual EnumStatusCode getIssuedIdentityToken(IssuedIdentityToken& target) const;
		/* see IValue::setIssuedIdentityToken */
		virtual EnumStatusCode setIssuedIdentityToken(const IIssuedIdentityToken* pIssuedIdentityToken);

		/* see IValue::getIssuedIdentityTokenArray */
		virtual std::vector<IssuedIdentityToken> getIssuedIdentityTokenArray() const;
		/*! @overload */
		virtual EnumStatusCode getIssuedIdentityTokenArray(std::vector<IssuedIdentityToken>& target) const;
		/* see IValue::setIssuedIdentityTokenArray */
		virtual EnumStatusCode setIssuedIdentityTokenArray(const std::vector<IssuedIdentityToken>& arrayIssuedIdentityToken);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SignedSoftwareCertificate content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getSignedSoftwareCertificate */
		virtual EnumStatusCode getSignedSoftwareCertificate(SignedSoftwareCertificate& target) const;
		/*! @overload */
		virtual SignedSoftwareCertificate getSignedSoftwareCertificate() const;
		/* see IValue::setSignedSoftwareCertificate */
		virtual EnumStatusCode setSignedSoftwareCertificate(const ISignedSoftwareCertificate* pSignedSoftwareCertificate);

		/* see IValue::getSignedSoftwareCertificateArray */
		virtual std::vector<SignedSoftwareCertificate> getSignedSoftwareCertificateArray() const;
		/*! @overload */
		virtual EnumStatusCode getSignedSoftwareCertificateArray(std::vector<SignedSoftwareCertificate>&) const;
		/* see IValue::setSignedSoftwareCertificateArray */
		virtual EnumStatusCode setSignedSoftwareCertificateArray(const std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate);
		/*! @overload */
		virtual EnumStatusCode setSignedSoftwareCertificateArray(const std::vector<const ISignedSoftwareCertificate*>& arraySignedSoftwareCertificate);

#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// Value access for SemanticChangeStructureDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getSemanticChangeStructureDataType */
		virtual EnumStatusCode getSemanticChangeStructureDataType(SemanticChangeStructureDataType& target) const;
		/*! @overload */
		virtual SemanticChangeStructureDataType getSemanticChangeStructureDataType() const;
		/* see IValue::setSemanticChangeStructureDataType */
		virtual EnumStatusCode setSemanticChangeStructureDataType(const ISemanticChangeStructureDataType* pSemanticChangeStructureDataType);

		/* see IValue::getSemanticChangeStructureDataTypeArray */
		virtual std::vector<SemanticChangeStructureDataType> getSemanticChangeStructureDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getSemanticChangeStructureDataTypeArray(std::vector<SemanticChangeStructureDataType>&) const;
		/* see IValue::setSemanticChangeStructureDataTypeArray */
		virtual EnumStatusCode setSemanticChangeStructureDataTypeArray(const std::vector<SemanticChangeStructureDataType>& arraySemanticChangeStructureDataType);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ModelChangeStructureDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getModelChangeStructureDataType */
		virtual EnumStatusCode getModelChangeStructureDataType(ModelChangeStructureDataType& target) const;
		/*! @overload */
		virtual ModelChangeStructureDataType getModelChangeStructureDataType() const;
		/* see IValue::setModelChangeStructureDataType */
		virtual EnumStatusCode setModelChangeStructureDataType(const IModelChangeStructureDataType* pModelChangeStructureDataType);

		/* see IValue::getModelChangeStructureDataTypeArray */
		virtual std::vector<ModelChangeStructureDataType> getModelChangeStructureDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getModelChangeStructureDataTypeArray(std::vector<ModelChangeStructureDataType>&) const;
		/* see IValue::setModelChangeStructureDataTypeArray */
		virtual EnumStatusCode setModelChangeStructureDataTypeArray(const std::vector<ModelChangeStructureDataType>& arrayModelChangeStructureDataType);
#endif

		////////////////////////////////////////////////////////////////////////////////
		// Value access for BuildInfo content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getBuildInfo */
		virtual EnumStatusCode getBuildInfo(BuildInfo& target) const;
		/*! @overload */
		virtual BuildInfo getBuildInfo() const;
		/* see IValue::setBuildInfo */
		virtual EnumStatusCode setBuildInfo(const IBuildInfo* pBuildInfo);

		/* see IValue::getBuildInfoArray */
		virtual std::vector<BuildInfo> getBuildInfoArray() const;
		/*! @overload */
		virtual EnumStatusCode getBuildInfoArray(std::vector<BuildInfo>&) const;
		/* see IValue::setBuildInfoArray */
		virtual EnumStatusCode setBuildInfoArray(const std::vector<BuildInfo>& arrayBuildInfo);
		/*! @overload */
		virtual EnumStatusCode setBuildInfoArray(const std::vector<const IBuildInfo*>& arrayBuildInfo);

#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// Value access for EventFilter content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getEventFilter */
		virtual EnumStatusCode getEventFilter(EventFilter& target) const;
		/*! @overload */
		virtual EventFilter getEventFilter() const;
		/* see IValue::setEventFilter */
		virtual EnumStatusCode setEventFilter(const IEventFilter* pEventFilter);

		/* see IValue::getEventFilterArray */
		virtual std::vector<EventFilter> getEventFilterArray() const;
		/*! @overload */
		virtual EnumStatusCode getEventFilterArray(std::vector<EventFilter>&) const;
		/* see IValue::setEventFilterArray */
		virtual EnumStatusCode setEventFilterArray(const std::vector<EventFilter>& arrayEventFilter);
		/*! @overload */
		virtual EnumStatusCode setEventFilterArray(const std::vector<const IEventFilter*>& arrayEventFilter);

#endif
		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServerStatusDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getServerStatusDataType */
		virtual EnumStatusCode getServerStatusDataType(ServerStatusDataType& target) const;
		/*! @overload */
		virtual ServerStatusDataType getServerStatusDataType() const;
		/* see IValue::setServerStatusDataType */
		virtual EnumStatusCode setServerStatusDataType(const IServerStatusDataType* pServerStatusDataType);

		/* see IValue::getServerStatusDataTypeArray */
		virtual std::vector<ServerStatusDataType> getServerStatusDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getServerStatusDataTypeArray(std::vector<ServerStatusDataType>&) const;
		/* see IValue::setServerStatusDataTypeArray */
		virtual EnumStatusCode setServerStatusDataTypeArray(const std::vector<ServerStatusDataType>& arrayServerStatusDataType);
		/*! @overload */
		virtual EnumStatusCode setServerStatusDataTypeArray(const std::vector<const IServerStatusDataType*>& arrayServerStatusDataType);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EnumValueType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getEnumValueType */
		virtual EnumStatusCode getEnumValueType(EnumValueType& target) const;
		/*! @overload */
		virtual EnumValueType getEnumValueType() const;
		/* see IValue::setEnumValueType */
		virtual EnumStatusCode setEnumValueType(const IEnumValueType* pEnumValueType);

		/* see IValue::getEnumValueTypeArray */
		virtual std::vector<EnumValueType> getEnumValueTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getEnumValueTypeArray(std::vector<EnumValueType>&) const;
		/* see IValue::setEnumValueTypeArray */
		virtual EnumStatusCode setEnumValueTypeArray(const std::vector<EnumValueType>& arrayEnumValueType);
		/*! @overload */
		virtual EnumStatusCode setEnumValueTypeArray(const std::vector<const IEnumValueType*>& arrayEnumValueType);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for structured data types
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getStructuredValue */
		virtual EnumStatusCode getStructuredValue(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<Value>& fieldValues) const;
		/* see IValue::setStructuredValue */
		virtual EnumStatusCode setStructuredValue(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<Value>& fieldValues);

		/* see IValue::setStructuredValue */
		virtual EnumStatusCode getStructuredValueArray(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<std::vector<Value> >& fieldValues) const;
		/* see IValue::setStructuredValueArray */
		virtual EnumStatusCode setStructuredValueArray(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<std::vector<Value> >& fieldValues);

		/* see IValue::getComplexValueRaw */
		virtual EnumStatusCode getComplexValueRaw(NodeId& encodingId, ByteString& body) const;
		/* see IValue::setComplexValueRaw */
		virtual EnumStatusCode setComplexValueRaw(const INodeId& encodingId, const IByteString& body);

		/* see IValue::getComplexValueRawArray */
		virtual EnumStatusCode getComplexValueRawArray(NodeId& encodingId, std::vector<ByteString>& bodies) const;
		/* see IValue::setComplexValueRawArray */
		virtual EnumStatusCode setComplexValueRawArray(const INodeId& encodingId, const std::vector<ByteString>& bodies);

		/* see IValue::clear */
		virtual void clear();

		/* see IValue::getInternHandle */
		void* getInternHandle() const;

	private:
		ValueStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// VALUE_H
