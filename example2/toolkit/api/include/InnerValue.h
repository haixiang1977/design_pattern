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

#ifndef INNERVALUE_H
#define INNERVALUE_H

#include "IValue.h"

namespace SoftingOPCToolbox5
{
	/*! Utility class which stands as the 'Inner' class of the
	* ValueStruct. Implements the IValue interface.
	* Used in DataValue class, as the inner variant member. */
	class TBC_EXPORT InnerValue
		: public IValue
	{
	public:
		InnerValue(void* handle);
		InnerValue(void);

		/*! Destructor */
		virtual ~InnerValue();

		void setBoolean (OTBoolean value);
		void setUInt8   (OTUInt8 value);
		void setInt8    (OTInt8 value);
		void setUInt16  (OTUInt16 value);
		void setInt16   (OTInt16 value);
		void setUInt32  (OTUInt32 value);
		void setInt32   (OTInt32 value);
		void setUInt64  (OTUInt64 value);
		void setInt64   (OTInt64 value);
		void setFloat   (OTFloat value);
		void setDouble  (OTDouble value);
		EnumStatusCode setDateTime(const IDateTime* pdateTime);
		EnumStatusCode setString  (const tstring& value);
		EnumStatusCode setGuid(const IGuid* pGuid);
		EnumStatusCode setNodeId(const INodeId* pNodeId);
		EnumStatusCode setExpandedNodeId(const IExpandedNodeId* pNodeId);
		void setStatusCode(EnumStatusCode statusCode);
		EnumStatusCode setQualifiedName(const IQualifiedName*  pQualifiedName);
		EnumStatusCode setEUInformation (const IEUInformation*  pEUInformation);
		EnumStatusCode setTimeZone (const ITimeZone*  pTimeZone);
		EnumStatusCode setRange (const IRange*  pRange);
		EnumStatusCode setReferenceDescription (const IReferenceDescription* pReferenceDescription);
		EnumStatusCode setApplicationDescription (const IApplicationDescription* pApplicationDescription);
		EnumStatusCode setServerDiagnosticsSummaryDataType (const IServerDiagnosticsSummaryDataType* pServerDiagnosticsSummaryDataType);
		EnumStatusCode setSubscriptionDiagnosticsDataType (const ISubscriptionDiagnosticsDataType* pSubscriptionDiagnosticsDataType);
		EnumStatusCode setSessionDiagnosticsDataType (const ISessionDiagnosticsDataType* pSessionDiagnosticsDataType);
		EnumStatusCode setSessionSecurityDiagnosticsDataType (const ISessionSecurityDiagnosticsDataType* pSessionSecurityDiagnosticsDataType);
		EnumStatusCode setServiceCounterDataType (const IServiceCounterDataType* pServiceCounterDataType);
#if TB5_ALARMS
		EnumStatusCode setSemanticChangeStructureDataType (const ISemanticChangeStructureDataType* pSemanticChangeStructureDataType);
		EnumStatusCode setModelChangeStructureDataType (const IModelChangeStructureDataType* pModelChangeStructureDataType);
#endif
		EnumStatusCode setLocalizedText(const ILocalizedText* pLocalizedText);
		EnumStatusCode setByteString(const unsigned char* pData, unsigned length);
		EnumStatusCode setByteString(const ByteString& pByteString);
		EnumStatusCode setXmlElement(const XmlElement& pXmlElement);
		EnumStatusCode setDataValue(const IDataValue* pDataValue);
		EnumStatusCode setArgument(const IArgument* pArgument);
		EnumStatusCode setUserIdentityToken (const IUserIdentityToken* pUserIdentityToken);
		/* arrays. */
		EnumStatusCode setBooleanArray (const std::vector<OTBoolean>& arrayBool);
		EnumStatusCode setUInt8Array   (const std::vector<OTUInt8>& arrayUInt8);
		EnumStatusCode setInt8Array    (const std::vector<OTInt8>& arrayInt8);
		EnumStatusCode setUInt16Array  (const std::vector<OTUInt16>& arrayUInt16);
		EnumStatusCode setInt16Array   (const std::vector<OTInt16>& arrayInt16);
		EnumStatusCode setUInt32Array  (const std::vector<OTUInt32>& arrayUInt32);
		EnumStatusCode setInt32Array   (const std::vector<OTInt32>& arrayInt32);
		EnumStatusCode setUInt64Array  (const std::vector<OTUInt64>& arrayUInt64);
		EnumStatusCode setInt64Array   (const std::vector<OTInt64>& arrayInt64);
		EnumStatusCode setFloatArray   (const std::vector<OTFloat>& arrayFloat);
		EnumStatusCode setDoubleArray  (const std::vector<OTDouble>& arrayDouble);
		//structure arrays
		EnumStatusCode setDateTimeArray(const std::vector<DateTime>& arrayDateTime);
		EnumStatusCode setStringArray  (const std::vector<tstring>& arrayString);
		EnumStatusCode setGuidArray    (const std::vector<Guid>& arrayGuid);
		EnumStatusCode setNodeIdArray  (const std::vector<NodeId>& arrayNodeId);
		EnumStatusCode setExpandedNodeIdArray (const std::vector<ExpandedNodeId>& arrayExpandedNodeId);
		EnumStatusCode setStatusCodeArray     (const std::vector<EnumStatusCode>& arrayStatusCode);
		EnumStatusCode setQualifiedNameArray  (const std::vector<QualifiedName>& arrayQualifiedName);
		EnumStatusCode setArgumentArray  (const std::vector<Argument>& arrayArgument);
		EnumStatusCode setEUInformationArray  (const std::vector<EUInformation>& arrayEUInformation);
		EnumStatusCode setTimeZoneArray       (const std::vector<TimeZone>& arrayTimeZone);
		EnumStatusCode setRangeArray          (const std::vector<Range>& arrayRange);
		EnumStatusCode setReferenceDescriptionArray (const std::vector<ReferenceDescription>& arrayReferenceDescription);
		EnumStatusCode setApplicationDescriptionArray (const std::vector<ApplicationDescription>& arrayApplicationDescription);
		EnumStatusCode setServerDiagnosticsSummaryDataTypeArray (const std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType);
		EnumStatusCode setSubscriptionDiagnosticsDataTypeArray (const std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType);
		EnumStatusCode setSessionDiagnosticsDataTypeArray (const std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType);
		EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray (const std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType);
		EnumStatusCode setServiceCounterDataTypeArray (const std::vector<ServiceCounterDataType>& arrayServiceCounterDataType);
#if TB5_ALARMS
		EnumStatusCode setSemanticChangeStructureDataTypeArray (const std::vector<SemanticChangeStructureDataType>& arraySemanticChangeStructureDataType);
		EnumStatusCode setModelChangeStructureDataTypeArray (const std::vector<ModelChangeStructureDataType>& arrayModelChangeStructureDataType);
#endif
		EnumStatusCode setLocalizedTextArray  (const std::vector<LocalizedText>& arrayLocalizedText);
		EnumStatusCode setValueArray  (const std::vector<Value>& arrayValue);
		EnumStatusCode setByteStringArray     (const std::vector<ByteString>& arrayByteString);
		EnumStatusCode setXmlElementArray     (const std::vector<XmlElement>& arrayXmlElement);
		EnumStatusCode setDataValueArray      (const std::vector<DataValue>& arrayDataValue);
		EnumStatusCode setUserIdentityTokenArray (const std::vector<UserIdentityToken>& arrayUserIdentityToken);

		// set from interface
		EnumStatusCode set(const IValue* pSrc);
		EnumStatusCode set(const IValue& rValue);

		/* getters */
		OTBoolean getBoolean(void) const;
		EnumStatusCode getBoolean(OTBoolean* target) const;

		OTUInt8 getUInt8(void) const;
		EnumStatusCode getUInt8(OTUInt8* target) const;

		OTInt8 getInt8(void) const;
		EnumStatusCode getInt8(OTInt8* target) const;

		OTUInt16 getUInt16(void) const;
		EnumStatusCode getUInt16(OTUInt16* target) const;

		OTInt16 getInt16(void) const;
		EnumStatusCode getInt16(OTInt16* target) const;

		OTUInt32 getUInt32(void) const;
		EnumStatusCode getUInt32(OTUInt32* target) const;

		OTInt32 getInt32(void) const;
		EnumStatusCode getInt32(OTInt32* target) const;

		OTUInt64 getUInt64(void) const;
		EnumStatusCode getUInt64(OTUInt64* target) const;

		OTInt64 getInt64(void) const;
		EnumStatusCode getInt64(OTInt64* target) const;

		OTFloat getFloat(void) const;
		EnumStatusCode getFloat(OTFloat* target) const;

		OTDouble getDouble(void) const;
		EnumStatusCode getDouble(OTDouble* target) const;

		EnumStatusCode getStatusCode(void) const;
		EnumStatusCode getStatusCode(EnumStatusCode* target) const;

		tstring getString(void) const;
		EnumStatusCode getString(tstring& target) const;

		QualifiedName getQualifiedName(void) const;
		EnumStatusCode getQualifiedName(QualifiedName& target) const;

		EUInformation getEUInformation(void) const;
		EnumStatusCode getEUInformation(EUInformation& target) const;

		TimeZone getTimeZone(void) const;
		EnumStatusCode getTimeZone(TimeZone& target) const;

		Range getRange(void) const;
		EnumStatusCode getRange(Range& target) const;

		ReferenceDescription getReferenceDescription(void) const;
		EnumStatusCode getReferenceDescription(ReferenceDescription& target) const;

		ApplicationDescription getApplicationDescription(void) const;
		EnumStatusCode getApplicationDescription(ApplicationDescription& target) const;

		ServerDiagnosticsSummaryDataType getServerDiagnosticsSummaryDataType(void) const;
		EnumStatusCode getServerDiagnosticsSummaryDataType(ServerDiagnosticsSummaryDataType& target) const;

		SubscriptionDiagnosticsDataType getSubscriptionDiagnosticsDataType(void) const;
		EnumStatusCode getSubscriptionDiagnosticsDataType(SubscriptionDiagnosticsDataType& target) const;

		SessionDiagnosticsDataType getSessionDiagnosticsDataType(void) const;
		EnumStatusCode getSessionDiagnosticsDataType(SessionDiagnosticsDataType& target) const;

		SessionSecurityDiagnosticsDataType getSessionSecurityDiagnosticsDataType(void) const;
		EnumStatusCode getSessionSecurityDiagnosticsDataType(SessionSecurityDiagnosticsDataType& target) const;

		ServiceCounterDataType getServiceCounterDataType(void) const;
		EnumStatusCode getServiceCounterDataType(ServiceCounterDataType& target) const;

#if TB5_ALARMS
		SemanticChangeStructureDataType getSemanticChangeStructureDataType(void) const;
		EnumStatusCode getSemanticChangeStructureDataType(SemanticChangeStructureDataType& target) const;

		ModelChangeStructureDataType getModelChangeStructureDataType(void) const;
		EnumStatusCode getModelChangeStructureDataType(ModelChangeStructureDataType& target) const;
#endif

		DateTime getDateTime(void) const;
		EnumStatusCode getDateTime(DateTime& target) const;

		Guid getGuid(void) const;
		EnumStatusCode getGuid(Guid& target) const;

		ByteString getByteString(void) const;
		EnumStatusCode getByteString(ByteString& target) const;

		XmlElement getXmlElement(void) const;
		EnumStatusCode getXmlElement(XmlElement& target) const;

		NodeId getNodeId(void) const;
		EnumStatusCode getNodeId(NodeId& target) const;

		ExpandedNodeId getExpandedNodeId(void) const;
		EnumStatusCode getExpandedNodeId(ExpandedNodeId& target) const;

		LocalizedText getLocalizedText(void) const;
		EnumStatusCode getLocalizedText(LocalizedText& target) const;

		DataValue getDataValue(void) const;
		EnumStatusCode getDataValue(DataValue& target) const;

		Argument getArgument(void) const;
		EnumStatusCode getArgument(Argument& target) const;

		UserIdentityToken getUserIdentityToken(void) const;
		EnumStatusCode getUserIdentityToken(UserIdentityToken& target) const;

		/* array getters */
		std::vector<OTBoolean> getBooleanArray(void) const;
		EnumStatusCode getBooleanArray(std::vector<OTBoolean>& target) const;

		std::vector<OTUInt8> getUInt8Array(void) const;
		EnumStatusCode getUInt8Array(std::vector<OTUInt8>& target) const;

		std::vector<OTInt8> getInt8Array(void) const;
		EnumStatusCode getInt8Array(std::vector<OTInt8>& target) const;

		std::vector<OTUInt16> getUInt16Array(void) const;
		EnumStatusCode getUInt16Array(std::vector<OTUInt16>& target) const;

		std::vector<OTInt16> getInt16Array(void) const;
		EnumStatusCode getInt16Array(std::vector<OTInt16>& target) const;

		std::vector<OTUInt32> getUInt32Array(void) const;
		EnumStatusCode getUInt32Array(std::vector<OTUInt32>& target) const;

		std::vector<OTInt32> getInt32Array(void) const;
		EnumStatusCode getInt32Array(std::vector<OTInt32>& target) const;

		std::vector<OTUInt64> getUInt64Array(void) const;
		EnumStatusCode getUInt64Array(std::vector<OTUInt64>& target) const;

		std::vector<OTInt64> getInt64Array(void) const;
		EnumStatusCode getInt64Array(std::vector<OTInt64>& target) const;

		std::vector<OTFloat> getFloatArray(void) const;
		EnumStatusCode getFloatArray(std::vector<OTFloat>& target) const;

		std::vector<OTDouble> getDoubleArray(void) const;
		EnumStatusCode getDoubleArray(std::vector<OTDouble>& target) const;

		std::vector<DateTime> getDateTimeArray(void) const;
		EnumStatusCode getDateTimeArray(std::vector<DateTime>& target) const;

		std::vector<EnumStatusCode> getStatusCodeArray(void) const;
		EnumStatusCode getStatusCodeArray(std::vector<EnumStatusCode>& target) const;

		std::vector<Guid> getGuidArray(void) const;
		EnumStatusCode getGuidArray(std::vector<Guid>& target) const;

		std::vector<tstring> getStringArray(void) const;
		EnumStatusCode getStringArray(std::vector<tstring>& target) const;

		std::vector<ByteString> getByteStringArray(void) const;
		EnumStatusCode getByteStringArray(std::vector<ByteString>& target) const;

		std::vector<XmlElement> getXmlElementArray(void) const;
		EnumStatusCode getXmlElementArray(std::vector<XmlElement>& target) const;

		std::vector<NodeId> getNodeIdArray(void) const;
		EnumStatusCode getNodeIdArray(std::vector<NodeId>& target) const;

		std::vector<ExpandedNodeId> getExpandedNodeIdArray(void) const;
		EnumStatusCode getExpandedNodeIdArray(std::vector<ExpandedNodeId>& target) const;

		std::vector<QualifiedName> getQualifiedNameArray(void) const;
		EnumStatusCode getQualifiedNameArray(std::vector<QualifiedName>& target) const;

		std::vector<Argument> getArgumentArray(void) const;
		EnumStatusCode getArgumentArray(std::vector<Argument>& target) const;

		std::vector<EUInformation> getEUInformationArray(void) const;
		EnumStatusCode getEUInformationArray(std::vector<EUInformation>& target) const;

		std::vector<DataValue> getDataValueArray(void) const;
		EnumStatusCode getDataValueArray(std::vector<DataValue>& target) const;

		std::vector<LocalizedText> getLocalizedTextArray(void) const;
		EnumStatusCode getLocalizedTextArray(std::vector<LocalizedText>& target) const;

		std::vector<Value> getValueArray(void) const;
		EnumStatusCode getValueArray(std::vector<Value>& target) const;

		std::vector<Range> getRangeArray(void) const;
		EnumStatusCode getRangeArray(std::vector<Range>& target) const;

		std::vector<TimeZone> getTimeZoneArray(void) const;
		EnumStatusCode getTimeZoneArray(std::vector<TimeZone>&) const;

		std::vector<ReferenceDescription> getReferenceDescriptionArray(void) const;
		EnumStatusCode getReferenceDescriptionArray(std::vector<ReferenceDescription>& target) const;

		std::vector<ApplicationDescription> getApplicationDescriptionArray(void) const;
		EnumStatusCode getApplicationDescriptionArray(std::vector<ApplicationDescription>& target) const;

		std::vector<ServerDiagnosticsSummaryDataType> getServerDiagnosticsSummaryDataTypeArray(void) const;
		EnumStatusCode getServerDiagnosticsSummaryDataTypeArray(std::vector<ServerDiagnosticsSummaryDataType>& target) const;

		std::vector<SubscriptionDiagnosticsDataType> getSubscriptionDiagnosticsDataTypeArray(void) const;
		EnumStatusCode getSubscriptionDiagnosticsDataTypeArray(std::vector<SubscriptionDiagnosticsDataType>& target) const;

		std::vector<SessionDiagnosticsDataType> getSessionDiagnosticsDataTypeArray(void) const;
		EnumStatusCode getSessionDiagnosticsDataTypeArray(std::vector<SessionDiagnosticsDataType>& target) const;

		std::vector<SessionSecurityDiagnosticsDataType> getSessionSecurityDiagnosticsDataTypeArray(void) const;
		EnumStatusCode getSessionSecurityDiagnosticsDataTypeArray(std::vector<SessionSecurityDiagnosticsDataType>& target) const;

		std::vector<ServiceCounterDataType> getServiceCounterDataTypeArray(void) const;
		EnumStatusCode getServiceCounterDataTypeArray(std::vector<ServiceCounterDataType>& target) const;

#if TB5_ALARMS
		std::vector<SemanticChangeStructureDataType> getSemanticChangeStructureDataTypeArray(void) const;
		EnumStatusCode getSemanticChangeStructureDataTypeArray(std::vector<SemanticChangeStructureDataType>& target) const;

		std::vector<ModelChangeStructureDataType> getModelChangeStructureDataTypeArray(void) const;
		EnumStatusCode getModelChangeStructureDataTypeArray(std::vector<ModelChangeStructureDataType>& target) const;

#endif
		std::vector<UserIdentityToken> getUserIdentityTokenArray(void) const;
		EnumStatusCode getUserIdentityTokenArray(std::vector<UserIdentityToken>& target) const;

		// Access functions for SignedSoftwareCertificate
		EnumStatusCode setSignedSoftwareCertificate (const ISignedSoftwareCertificate* pSignedSoftwareCertificate);
		EnumStatusCode setSignedSoftwareCertificateArray (const std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate);
		SignedSoftwareCertificate getSignedSoftwareCertificate(void) const;
		EnumStatusCode getSignedSoftwareCertificate(SignedSoftwareCertificate& target) const;
		std::vector<SignedSoftwareCertificate> getSignedSoftwareCertificateArray(void) const;
		EnumStatusCode getSignedSoftwareCertificateArray(std::vector<SignedSoftwareCertificate>& target) const;

		// Access functions for BuildInfo
		BuildInfo getBuildInfo(void) const;
		EnumStatusCode getBuildInfo(BuildInfo& target) const;
		EnumStatusCode setBuildInfo (const IBuildInfo* pBuildInfo);
		EnumStatusCode setBuildInfoArray (const std::vector<BuildInfo>& arrayBuildInfo);
		std::vector<BuildInfo> getBuildInfoArray(void) const;
		EnumStatusCode getBuildInfoArray(std::vector<BuildInfo>& target) const;

#if TB5_ALARMS
		// Access functions for EventFilter
		EventFilter getEventFilter(void) const;
		EnumStatusCode getEventFilter(EventFilter& target) const;
		EnumStatusCode setEventFilter (const IEventFilter* pEventFilter);
		EnumStatusCode setEventFilterArray (const std::vector<EventFilter>& arrayEventFilter);
		std::vector<EventFilter> getEventFilterArray(void) const;
		EnumStatusCode getEventFilterArray(std::vector<EventFilter>& target) const;
#endif

		// Access functions for ServerStatusDataType
		ServerStatusDataType getServerStatusDataType(void) const;
		EnumStatusCode getServerStatusDataType(ServerStatusDataType& target) const;
		EnumStatusCode setServerStatusDataType (const IServerStatusDataType* pServerStatusDataType);
		EnumStatusCode setServerStatusDataTypeArray (const std::vector<ServerStatusDataType>& arrayServerStatusDataType);
		std::vector<ServerStatusDataType> getServerStatusDataTypeArray(void) const;
		EnumStatusCode getServerStatusDataTypeArray(std::vector<ServerStatusDataType>& target) const;

		// Access functions for EnumValueType
		EnumValueType getEnumValueType(void) const;
		EnumStatusCode getEnumValueType(EnumValueType& target) const;
		EnumStatusCode setEnumValueType (const IEnumValueType* pEnumValueType);
		EnumStatusCode setEnumValueTypeArray (const std::vector<EnumValueType>& arrayEnumValueType);
		std::vector<EnumValueType> getEnumValueTypeArray(void) const;
		EnumStatusCode getEnumValueTypeArray(std::vector<EnumValueType>& target) const;

		// Access functions for AnonymousIdentityToken
		virtual AnonymousIdentityToken getAnonymousIdentityToken() const;
		virtual EnumStatusCode getAnonymousIdentityToken(AnonymousIdentityToken& target) const;
		virtual EnumStatusCode setAnonymousIdentityToken(const IAnonymousIdentityToken* pAnonymousIdentityToken);
		virtual std::vector<AnonymousIdentityToken> getAnonymousIdentityTokenArray() const;
		virtual EnumStatusCode getAnonymousIdentityTokenArray(std::vector<AnonymousIdentityToken>& target) const;
		virtual EnumStatusCode setAnonymousIdentityTokenArray(const std::vector<AnonymousIdentityToken>& arrayAnonymousIdentityToken);

		// Access functions for UserNameIdentityToken
		virtual UserNameIdentityToken getUserNameIdentityToken() const;
		virtual EnumStatusCode getUserNameIdentityToken(UserNameIdentityToken& target) const;
		virtual EnumStatusCode setUserNameIdentityToken(const IUserNameIdentityToken* pUserNameIdentityToken);
		virtual std::vector<UserNameIdentityToken> getUserNameIdentityTokenArray() const;
		virtual EnumStatusCode getUserNameIdentityTokenArray(std::vector<UserNameIdentityToken>& target) const;
		virtual EnumStatusCode setUserNameIdentityTokenArray(const std::vector<UserNameIdentityToken>& arrayUserNameIdentityToken);

		// Access functions for X509IdentityToken
		virtual X509IdentityToken getX509IdentityToken() const;
		virtual EnumStatusCode getX509IdentityToken(X509IdentityToken& target) const;
		virtual EnumStatusCode setX509IdentityToken(const IX509IdentityToken* pX509IdentityToken);
		virtual std::vector<X509IdentityToken> getX509IdentityTokenArray() const;
		virtual EnumStatusCode getX509IdentityTokenArray(std::vector<X509IdentityToken>& target) const;
		virtual EnumStatusCode setX509IdentityTokenArray(const std::vector<X509IdentityToken>& arrayX509IdentityToken);

		// Access functions for IssuedIdentityToken
		virtual IssuedIdentityToken getIssuedIdentityToken() const;
		virtual EnumStatusCode getIssuedIdentityToken(IssuedIdentityToken& target) const;
		virtual EnumStatusCode setIssuedIdentityToken(const IIssuedIdentityToken* pIssuedIdentityToken);
		virtual std::vector<IssuedIdentityToken> getIssuedIdentityTokenArray() const;
		virtual EnumStatusCode getIssuedIdentityTokenArray(std::vector<IssuedIdentityToken>& target) const;
		virtual EnumStatusCode setIssuedIdentityTokenArray(const std::vector<IssuedIdentityToken>& arrayIssuedIdentityToken);

		// Access functions for structured data types
		virtual EnumStatusCode getStructuredValue(StructuredDataTypeDescriptionConstPtr dataTypeDescription, std::vector<Value>& fieldValues) const;
		virtual EnumStatusCode setStructuredValue(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<Value>& fieldValues);
		virtual EnumStatusCode getStructuredValueArray(StructuredDataTypeDescriptionConstPtr dataTypeDescription, std::vector<std::vector<Value> >& fieldValues) const;
		virtual EnumStatusCode setStructuredValueArray(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<std::vector<Value> >& fieldValues);

		virtual EnumStatusCode getComplexValueRaw(NodeId& encodingId, ByteString& body) const;
		virtual EnumStatusCode setComplexValueRaw(const INodeId& encodingId, const IByteString& body);
		virtual EnumStatusCode getComplexValueRawArray(NodeId& encodingId, std::vector<ByteString>& bodies) const;
		virtual EnumStatusCode setComplexValueRawArray(const INodeId& encodingId, const std::vector<ByteString>& bodies);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IValue* other) const;
		/*! @overload */
		virtual int compare(const IValue& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IValue& other);
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IValue& other);

		virtual EnumValueCastType canCastTo(EnumDataTypeId dataType) const;
		virtual EnumStatusCode castTo(EnumDataTypeId dataType, IValue& castedValue) const;

		/*! For internal use only */
		void initInner(void* handle);
		virtual EnumDataTypeId getDataType() const;
		virtual EnumValueArrayType getArrayType() const;
		void* getInternHandle() const{ return m_otbHandle; }
		tstring toString(void) const;
		EnumStatusCode getSubset(IValue& result, const INumericRange* indexRange) const;
		EnumStatusCode setSubset(const IValue& value, const INumericRange* indexRange);
		void clear(void);
	protected:
		// the handle to the related core object
		void* m_otbHandle;
	};
}
#endif	// INNERVALUE_H
