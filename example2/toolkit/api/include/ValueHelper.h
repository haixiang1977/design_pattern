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

#ifndef VALUEHELPER_H
#define VALUEHELPER_H

#include "QualifiedName.h"
#include "NodeId.h"
#include "DateTime.h"
#include "ByteString.h"
#include "ExpandedNodeId.h"
#include "LocalizedText.h"
#include "DataValue.h"
#include "Guid.h"
#include "ByteString.h"
#include "ReferenceDescription.h"
#include "ApplicationDescription.h"
#include "ServerDiagnosticsSummaryDataType.h"
#include "SubscriptionDiagnosticsDataType.h"
#include "SessionDiagnosticsDataType.h"
#include "SessionSecurityDiagnosticsDataType.h"
#include "ServiceCounterDataType.h"
#include "SemanticChangeStructureDataType.h"
#include "ModelChangeStructureDataType.h"
#include "UserIdentityToken.h"
#include "SignedSoftwareCertificate.h"
#include "BuildInfo.h"
#include "EventFilter.h"
#include "ServerStatusDataType.h"
#include "EnumValueType.h"
#include "Guid.h"
#include "EUInformation.h"
#include "TimeZone.h"
#include "Argument.h"
#include "Range.h"

namespace SoftingOPCToolbox5
{
	class ValueHelper
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// DataValue access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get DataValue function with result code
		static EnumStatusCode getDataValue(const ValueStruct* pValueStruct, DataValue& target);
		// single get DataValue function with direct return
		static DataValue getDataValue(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setDataValue(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setDataValueArray(ValueStruct* pValueStruct, const std::vector<DataValue>& arrayDataValue);
		// array get function with error code
		static EnumStatusCode getDataValueArray(const ValueStruct* pValueStruct, std::vector<DataValue>& arrayDataValue);
		// array get function with value return
		static std::vector<DataValue> getDataValueArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// ExpandedNodeId access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get ExpandedNodeId function with result code
		static EnumStatusCode getExpandedNodeId(const ValueStruct* pValueStruct, ExpandedNodeId& target);
		// single get ExpandedNodeId function with direct return
		static ExpandedNodeId getExpandedNodeId(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setExpandedNodeId(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setExpandedNodeIdArray(ValueStruct* pValueStruct, const std::vector<ExpandedNodeId>& arrayExpandedNodeId);
		// array get function with error code
		static EnumStatusCode getExpandedNodeIdArray(const ValueStruct* pValueStruct, std::vector<ExpandedNodeId>& arrayExpandedNodeId);
		// array get function with value return
		static std::vector<ExpandedNodeId> getExpandedNodeIdArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// LocalizedText access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get LocalizedText function with result code
		static EnumStatusCode getLocalizedText(const ValueStruct* pValueStruct, LocalizedText& target);
		// single get LocalizedText function with direct return
		static LocalizedText getLocalizedText(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setLocalizedText(ValueStruct* pValueStruct, const ILocalizedText* localizedText);
		// array set function
		static EnumStatusCode setLocalizedTextArray(ValueStruct* pValueStruct, const std::vector<LocalizedText>& arrayLocalizedText);
		// array get function with error code
		static EnumStatusCode getLocalizedTextArray(const ValueStruct* pValueStruct, std::vector<LocalizedText>& arrayLocalizedText);
		// array get function with value return
		static std::vector<LocalizedText> getLocalizedTextArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// QualifiedName access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get QualifiedName function with result code
		static EnumStatusCode getQualifiedName(const ValueStruct* pValueStruct, QualifiedName& target);
		// single get QualifiedName function with direct return
		static QualifiedName getQualifiedName(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setQualifiedName(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setQualifiedNameArray(ValueStruct* pValueStruct, const std::vector<QualifiedName>& arrayQualifiedName);
		// array get function with error code
		static EnumStatusCode getQualifiedNameArray(const ValueStruct* pValueStruct, std::vector<QualifiedName>& arrayQualifiedName);
		// array get function with value return
		static std::vector<QualifiedName> getQualifiedNameArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// NodeId access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get NodeId function with result code
		static EnumStatusCode getNodeId(const ValueStruct* pValueStruct, NodeId& target);
		// single get NodeId function with direct return
		static NodeId getNodeId(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setNodeId(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setNodeIdArray(ValueStruct* pValueStruct, const std::vector<NodeId>& arrayNodeId);
		// array get function with error code
		static EnumStatusCode getNodeIdArray(const ValueStruct* pValueStruct, std::vector<NodeId>& arrayNodeId);
		// array get function with value return
		static std::vector<NodeId> getNodeIdArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// EUInformation access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get EUInformation function with result code
		static EnumStatusCode getEUInformation(const ValueStruct* pValueStruct, EUInformation& target);
		// single get EUInformation function with direct return
		static EUInformation getEUInformation(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setEUInformation(ValueStruct* pValueStruct, const IEUInformation* pEUInformation);
		// array set function
		static EnumStatusCode setEUInformationArray(ValueStruct* pValueStruct, const std::vector<EUInformation>& arrayEUInformation);
		// array get function with error code
		static EnumStatusCode getEUInformationArray(const ValueStruct* pValueStruct, std::vector<EUInformation>& arrayEUInformation);
		// array get function with value return
		static std::vector<EUInformation> getEUInformationArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// TimeZone access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get TimeZone function with result code
		static EnumStatusCode getTimeZone(const ValueStruct* pValueStruct, TimeZone& target);
		// single get TimeZone function with direct return
		static TimeZone getTimeZone(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setTimeZone(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setTimeZoneArray(ValueStruct* pValueStruct, const std::vector<TimeZone>& arrayTimeZone);
		// array get function with error code
		static EnumStatusCode getTimeZoneArray(const ValueStruct* pValueStruct, std::vector<TimeZone>& arrayTimeZone);
		// array get function with value return
		static std::vector<TimeZone> getTimeZoneArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// Argument access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get Argument function with result code
		static EnumStatusCode getArgument(const ValueStruct* pValueStruct, Argument& target);
		// single get Argument function with direct return
		static Argument getArgument(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setArgument(ValueStruct* pValueStruct, const IArgument* pArgument);
		// array set function
		static EnumStatusCode setArgumentArray(ValueStruct* pValueStruct, const std::vector<Argument>& arrayArgument);
		// array get function with error code
		static EnumStatusCode getArgumentArray(const ValueStruct* pValueStruct, std::vector<Argument>& arrayArgument);
		// array get function with value return
		static std::vector<Argument> getArgumentArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// Range access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get Range function with result code
		static EnumStatusCode getRange(const ValueStruct* pValueStruct, Range& target);
		// single get Range function with direct return
		static Range getRange(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setRange(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setRangeArray(ValueStruct* pValueStruct, const std::vector<Range>& arrayRange);
		// array get function with error code
		static EnumStatusCode getRangeArray(const ValueStruct* pValueStruct, std::vector<Range>& arrayRange);
		// array get function with value return
		static std::vector<Range> getRangeArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// ReferenceDescription access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get ReferenceDescription function with result code
		static EnumStatusCode getReferenceDescription(const ValueStruct* pValueStruct, ReferenceDescription& target);
		// single get ReferenceDescription function with direct return
		static ReferenceDescription getReferenceDescription(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setReferenceDescription(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setReferenceDescriptionArray(ValueStruct* pValueStruct, const std::vector<ReferenceDescription>& arrayReferenceDescription);
		// array get function with error code
		static EnumStatusCode getReferenceDescriptionArray(const ValueStruct* pValueStruct, std::vector<ReferenceDescription>& arrayReferenceDescription);
		// array get function with value return
		static std::vector<ReferenceDescription> getReferenceDescriptionArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// ApplicationDescription access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get ApplicationDescription function with result code
		static EnumStatusCode getApplicationDescription(const ValueStruct* pValueStruct, ApplicationDescription& target);
		// single get ApplicationDescription function with direct return
		static ApplicationDescription getApplicationDescription(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setApplicationDescription(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setApplicationDescriptionArray(ValueStruct* pValueStruct, const std::vector<ApplicationDescription>& arrayApplicationDescription);
		// array get function with error code
		static EnumStatusCode getApplicationDescriptionArray(const ValueStruct* pValueStruct, std::vector<ApplicationDescription>& arrayApplicationDescription);
		// array get function with value return
		static std::vector<ApplicationDescription> getApplicationDescriptionArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// ServerDiagnosticsSummaryDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get ServerDiagnosticsSummaryDataType function with result code
		static EnumStatusCode getServerDiagnosticsSummaryDataType(const ValueStruct* pValueStruct, ServerDiagnosticsSummaryDataType& target);
		// single get ServerDiagnosticsSummaryDataType function with direct return
		static ServerDiagnosticsSummaryDataType getServerDiagnosticsSummaryDataType(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setServerDiagnosticsSummaryDataType(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setServerDiagnosticsSummaryDataTypeArray(ValueStruct* pValueStruct, const std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType);
		// array get function with error code
		static EnumStatusCode getServerDiagnosticsSummaryDataTypeArray(const ValueStruct* pValueStruct, std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType);
		// array get function with value return
		static std::vector<ServerDiagnosticsSummaryDataType> getServerDiagnosticsSummaryDataTypeArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// SubscriptionDiagnosticsDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get SubscriptionDiagnosticsDataType function with result code
		static EnumStatusCode getSubscriptionDiagnosticsDataType(const ValueStruct* pValueStruct, SubscriptionDiagnosticsDataType& target);
		// single get SubscriptionDiagnosticsDataType function with direct return
		static SubscriptionDiagnosticsDataType getSubscriptionDiagnosticsDataType(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setSubscriptionDiagnosticsDataType(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setSubscriptionDiagnosticsDataTypeArray(ValueStruct* pValueStruct, const std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType);
		// array get function with error code
		static EnumStatusCode getSubscriptionDiagnosticsDataTypeArray(const ValueStruct* pValueStruct, std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType);
		// array get function with value return
		static std::vector<SubscriptionDiagnosticsDataType> getSubscriptionDiagnosticsDataTypeArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// SessionDiagnosticsDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get SessionDiagnosticsDataType function with result code
		static EnumStatusCode getSessionDiagnosticsDataType(const ValueStruct* pValueStruct, SessionDiagnosticsDataType& target);
		// single get SessionDiagnosticsDataType function with direct return
		static SessionDiagnosticsDataType getSessionDiagnosticsDataType(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setSessionDiagnosticsDataType(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setSessionDiagnosticsDataTypeArray(ValueStruct* pValueStruct, const std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType);
		// array get function with error code
		static EnumStatusCode getSessionDiagnosticsDataTypeArray(const ValueStruct* pValueStruct, std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType);
		// array get function with value return
		static std::vector<SessionDiagnosticsDataType> getSessionDiagnosticsDataTypeArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// SessionSecurityDiagnosticsDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get SessionSecurityDiagnosticsDataType function with result code
		static EnumStatusCode getSessionSecurityDiagnosticsDataType(const ValueStruct* pValueStruct, SessionSecurityDiagnosticsDataType& target);
		// single get SessionSecurityDiagnosticsDataType function with direct return
		static SessionSecurityDiagnosticsDataType getSessionSecurityDiagnosticsDataType(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setSessionSecurityDiagnosticsDataType(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray(ValueStruct* pValueStruct, const std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType);
		// array get function with error code
		static EnumStatusCode getSessionSecurityDiagnosticsDataTypeArray(const ValueStruct* pValueStruct, std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType);
		// array get function with value return
		static std::vector<SessionSecurityDiagnosticsDataType> getSessionSecurityDiagnosticsDataTypeArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// ServiceCounterDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get ServiceCounterDataType function with result code
		static EnumStatusCode getServiceCounterDataType(const ValueStruct* pValueStruct, ServiceCounterDataType& target);
		// single get ServiceCounterDataType function with direct return
		static ServiceCounterDataType getServiceCounterDataType(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setServiceCounterDataType(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setServiceCounterDataTypeArray(ValueStruct* pValueStruct, const std::vector<ServiceCounterDataType>& arrayServiceCounterDataType);
		// array get function with error code
		static EnumStatusCode getServiceCounterDataTypeArray(const ValueStruct* pValueStruct, std::vector<ServiceCounterDataType>& arrayServiceCounterDataType);
		// array get function with value return
		static std::vector<ServiceCounterDataType> getServiceCounterDataTypeArray(const ValueStruct* pValueStruct);
#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// SemanticChangeStructureDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get SemanticChangeStructureDataType function with result code
		static EnumStatusCode getSemanticChangeStructureDataType(const ValueStruct* pValueStruct, SemanticChangeStructureDataType& target);
		// single get SemanticChangeStructureDataType function with direct return
		static SemanticChangeStructureDataType getSemanticChangeStructureDataType(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setSemanticChangeStructureDataType(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setSemanticChangeStructureDataTypeArray(ValueStruct* pValueStruct, const std::vector<SemanticChangeStructureDataType>& arraySemanticChangeStructureDataType);
		// array get function with error code
		static EnumStatusCode getSemanticChangeStructureDataTypeArray(const ValueStruct* pValueStruct, std::vector<SemanticChangeStructureDataType>& arraySemanticChangeStructureDataType);
		// array get function with value return
		static std::vector<SemanticChangeStructureDataType> getSemanticChangeStructureDataTypeArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// ModelChangeStructureDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get ModelChangeStructureDataType function with result code
		static EnumStatusCode getModelChangeStructureDataType(const ValueStruct* pValueStruct, ModelChangeStructureDataType& target);
		// single get ModelChangeStructureDataType function with direct return
		static ModelChangeStructureDataType getModelChangeStructureDataType(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setModelChangeStructureDataType(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setModelChangeStructureDataTypeArray(ValueStruct* pValueStruct, const std::vector<ModelChangeStructureDataType>& arrayModelChangeStructureDataType);
		// array get function with error code
		static EnumStatusCode getModelChangeStructureDataTypeArray(const ValueStruct* pValueStruct, std::vector<ModelChangeStructureDataType>& arrayModelChangeStructureDataType);
		// array get function with value return
		static std::vector<ModelChangeStructureDataType> getModelChangeStructureDataTypeArray(const ValueStruct* pValueStruct);
#endif
		////////////////////////////////////////////////////////////////////////////////
		// UserIdentityToken access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get UserIdentityToken function with result code
		static EnumStatusCode getUserIdentityToken(const ValueStruct* pValueStruct, UserIdentityToken& target);
		// single get UserIdentityToken function with direct return
		static UserIdentityToken getUserIdentityToken(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setUserIdentityToken(ValueStruct* pValueStruct, UserIdentityTokenStruct* pIntHandle);
		// array set function
		static EnumStatusCode setUserIdentityTokenArray(ValueStruct* pValueStruct, const std::vector<UserIdentityToken>& arrayUserIdentityToken);
		// array get function with error code
		static EnumStatusCode getUserIdentityTokenArray(const ValueStruct* pValueStruct, std::vector<UserIdentityToken>& arrayUserIdentityToken);
		// array get function with value return
		static std::vector<UserIdentityToken> getUserIdentityTokenArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// AnonymousIdentityToken access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get AnonymousIdentityToken function with result code
		static EnumStatusCode getAnonymousIdentityToken(const ValueStruct* pValueStruct, AnonymousIdentityToken& target);
		// single get AnonymousIdentityToken function with direct return
		static AnonymousIdentityToken getAnonymousIdentityToken(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setAnonymousIdentityToken(ValueStruct* pValueStruct, AnonymousIdentityTokenStruct* pIntHandle);
		// array set function
		static EnumStatusCode setAnonymousIdentityTokenArray(ValueStruct* pValueStruct, const std::vector<AnonymousIdentityToken>& arrayAnonymousIdentityToken);
		// array get function with error code
		static EnumStatusCode getAnonymousIdentityTokenArray(const ValueStruct* pValueStruct, std::vector<AnonymousIdentityToken>& arrayAnonymousIdentityToken);
		// array get function with value return
		static std::vector<AnonymousIdentityToken> getAnonymousIdentityTokenArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// UserNameIdentityToken access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get UserNameIdentityToken function with result code
		static EnumStatusCode getUserNameIdentityToken(const ValueStruct* pValueStruct, UserNameIdentityToken& target);
		// single get UserNameIdentityToken function with direct return
		static UserNameIdentityToken getUserNameIdentityToken(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setUserNameIdentityToken(ValueStruct* pValueStruct, UserNameIdentityTokenStruct* pIntHandle);
		// array set function
		static EnumStatusCode setUserNameIdentityTokenArray(ValueStruct* pValueStruct, const std::vector<UserNameIdentityToken>& arrayUserNameIdentityToken);
		// array get function with error code
		static EnumStatusCode getUserNameIdentityTokenArray(const ValueStruct* pValueStruct, std::vector<UserNameIdentityToken>& arrayUserNameIdentityToken);
		// array get function with value return
		static std::vector<UserNameIdentityToken> getUserNameIdentityTokenArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// X509IdentityToken access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get X509IdentityToken function with result code
		static EnumStatusCode getX509IdentityToken(const ValueStruct* pValueStruct, X509IdentityToken& target);
		// single get X509IdentityToken function with direct return
		static X509IdentityToken getX509IdentityToken(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setX509IdentityToken(ValueStruct* pValueStruct, X509IdentityTokenStruct* pIntHandle);
		// array set function
		static EnumStatusCode setX509IdentityTokenArray(ValueStruct* pValueStruct, const std::vector<X509IdentityToken>& arrayX509IdentityToken);
		// array get function with error code
		static EnumStatusCode getX509IdentityTokenArray(const ValueStruct* pValueStruct, std::vector<X509IdentityToken>& arrayX509IdentityToken);
		// array get function with value return
		static std::vector<X509IdentityToken> getX509IdentityTokenArray(const ValueStruct* pValueStruct);
		////////////////////////////////////////////////////////////////////////////////
		// IssuedIdentityToken access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get IssuedIdentityToken function with result code
		static EnumStatusCode getIssuedIdentityToken(const ValueStruct* pValueStruct, IssuedIdentityToken& target);
		// single get IssuedIdentityToken function with direct return
		static IssuedIdentityToken getIssuedIdentityToken(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setIssuedIdentityToken(ValueStruct* pValueStruct, IssuedIdentityTokenStruct* pIntHandle);
		// array set function
		static EnumStatusCode setIssuedIdentityTokenArray(ValueStruct* pValueStruct, const std::vector<IssuedIdentityToken>& arrayIssuedIdentityToken);
		// array get function with error code
		static EnumStatusCode getIssuedIdentityTokenArray(const ValueStruct* pValueStruct, std::vector<IssuedIdentityToken>& arrayIssuedIdentityToken);
		// array get function with value return
		static std::vector<IssuedIdentityToken> getIssuedIdentityTokenArray(const ValueStruct* pValueStruct);

		////////////////////////////////////////////////////////////////////////////////
		// SignedSoftwareCertificate access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get SignedSoftwareCertificate function with result code
		static EnumStatusCode getSignedSoftwareCertificate(const ValueStruct* pValueStruct, SignedSoftwareCertificate& target);
		// single get SignedSoftwareCertificate function with direct return
		static SignedSoftwareCertificate getSignedSoftwareCertificate(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setSignedSoftwareCertificate(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setSignedSoftwareCertificateArray(ValueStruct* pValueStruct, const std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate);
		static EnumStatusCode setSignedSoftwareCertificateArray(ValueStruct* pValueStruct, const std::vector<const ISignedSoftwareCertificate*>& arraySignedSoftwareCertificate);
		// array get function with error code
		static EnumStatusCode getSignedSoftwareCertificateArray(const ValueStruct* pValueStruct, std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate);
		// array get function with value return
		static std::vector<SignedSoftwareCertificate> getSignedSoftwareCertificateArray(const ValueStruct* pValueStruct);

		////////////////////////////////////////////////////////////////////////////////
		// BuildInfo access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get BuildInfo function with result code
		static EnumStatusCode getBuildInfo(const ValueStruct* pValueStruct, BuildInfo& target);
		// single get BuildInfo function with direct return
		static BuildInfo getBuildInfo(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setBuildInfo(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setBuildInfoArray(ValueStruct* pValueStruct, const std::vector<BuildInfo>& arrayBuildInfo);
		static EnumStatusCode setBuildInfoArray(ValueStruct* pValueStruct, const std::vector<const IBuildInfo*>& arrayBuildInfo);
		// array get function with error code
		static EnumStatusCode getBuildInfoArray(const ValueStruct* pValueStruct, std::vector<BuildInfo>& arrayBuildInfo);
		// array get function with value return
		static std::vector<BuildInfo> getBuildInfoArray(const ValueStruct* pValueStruct);

		////////////////////////////////////////////////////////////////////////////////
		// EventFilter access functions
		////////////////////////////////////////////////////////////////////////////////
#if TB5_ALARMS
		// single get EventFilter function with result code
		static EnumStatusCode getEventFilter(const ValueStruct* pValueStruct, EventFilter& target);
		// single get EventFilter function with direct return
		static EventFilter getEventFilter(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setEventFilter(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setEventFilterArray(ValueStruct* pValueStruct, const std::vector<EventFilter>& arrayEventFilter);
		static EnumStatusCode setEventFilterArray(ValueStruct* pValueStruct, const std::vector<const IEventFilter*>& arrayEventFilter);
		// array get function with error code
		static EnumStatusCode getEventFilterArray(const ValueStruct* pValueStruct, std::vector<EventFilter>& arrayEventFilter);
		// array get function with value return
		static std::vector<EventFilter> getEventFilterArray(const ValueStruct* pValueStruct);
#endif

		////////////////////////////////////////////////////////////////////////////////
		// ServerStatusDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get ServerStatusDataType function with result code
		static EnumStatusCode getServerStatusDataType(const ValueStruct* pValueStruct, ServerStatusDataType& target);
		// single get ServerStatusDataType function with direct return
		static ServerStatusDataType getServerStatusDataType(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setServerStatusDataType(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setServerStatusDataTypeArray(ValueStruct* pValueStruct, const std::vector<ServerStatusDataType>& arrayServerStatusDataType);
		static EnumStatusCode setServerStatusDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IServerStatusDataType*>& arrayServerStatusDataType);
		// array get function with error code
		static EnumStatusCode getServerStatusDataTypeArray(const ValueStruct* pValueStruct, std::vector<ServerStatusDataType>& arrayServerStatusDataType);
		// array get function with value return
		static std::vector<ServerStatusDataType> getServerStatusDataTypeArray(const ValueStruct* pValueStruct);

		////////////////////////////////////////////////////////////////////////////////
		// EnumValueType access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get EnumValueType function with result code
		static EnumStatusCode getEnumValueType(const ValueStruct* pValueStruct, EnumValueType& target);
		// single get EnumValueType function with direct return
		static EnumValueType getEnumValueType(const ValueStruct* pValueStruct);
		// single set function
		static EnumStatusCode setEnumValueType(ValueStruct* pValueStruct, void* pIntHandle);
		// array set function
		static EnumStatusCode setEnumValueTypeArray(ValueStruct* pValueStruct, const std::vector<EnumValueType>& arrayEnumValueType);
		static EnumStatusCode setEnumValueTypeArray(ValueStruct* pValueStruct, const std::vector<const IEnumValueType*>& arrayEnumValueType);
		// array get function with error code
		static EnumStatusCode getEnumValueTypeArray(const ValueStruct* pValueStruct, std::vector<EnumValueType>& arrayEnumValueType);
		// array get function with value return
		static std::vector<EnumValueType> getEnumValueTypeArray(const ValueStruct* pValueStruct);

		//primitives
		static void setBoolean(ValueStruct* pValueStruct, OTBoolean value);
		static void setUInt8(ValueStruct* pValueStruct, OTUInt8 value);
		static void setInt8(ValueStruct* pValueStruct, OTInt8 value);
		static void setUInt16(ValueStruct* pValueStruct, OTUInt16 value);
		static void setInt16(ValueStruct* pValueStruct, OTInt16 value);
		static void setUInt32(ValueStruct* pValueStruct, OTUInt32 value);
		static void setInt32(ValueStruct* pValueStruct, OTInt32 value);
		static void setUInt64(ValueStruct* pValueStruct, OTUInt64 value);
		static void setInt64(ValueStruct* pValueStruct, OTInt64 value);
		static void setFloat(ValueStruct* pValueStruct, OTFloat value);
		static void setDouble(ValueStruct* pValueStruct, OTDouble value);
		//structures
		static void setStatusCode(ValueStruct* pValueStruct, EnumStatusCode statusCode);
		static EnumStatusCode setDateTime(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode setString(ValueStruct* pValueStruct, const tstring& value);
		static EnumStatusCode setByteString(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode setXmlElement(ValueStruct* pValueStruct, const XmlElement& xmlElement);
		static EnumStatusCode setGuid(ValueStruct* pValueStruct, void* pIntHandle);

		//arrays
		static EnumStatusCode setBooleanArray(ValueStruct* pValueStruct, const std::vector<OTBoolean>& arrayBool);
		static EnumStatusCode setUInt8Array(ValueStruct* pValueStruct, const std::vector<OTUInt8>& arrayUInt8);
		static EnumStatusCode setInt8Array(ValueStruct* pValueStruct, const std::vector<OTInt8>& arrayInt8);
		static EnumStatusCode setUInt16Array(ValueStruct* pValueStruct, const std::vector<OTUInt16>& arrayUInt16);
		static EnumStatusCode setInt16Array(ValueStruct* pValueStruct, const std::vector<OTInt16>& arrayInt16);
		static EnumStatusCode setUInt32Array(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayUInt32);
		static EnumStatusCode setInt32Array(ValueStruct* pValueStruct, const std::vector<OTInt32>& arrayInt32);
		static EnumStatusCode setUInt64Array(ValueStruct* pValueStruct, const std::vector<OTUInt64>& arrayUInt64);
		static EnumStatusCode setInt64Array(ValueStruct* pValueStruct, const std::vector<OTInt64>& arrayInt64);
		static EnumStatusCode setFloatArray(ValueStruct* pValueStruct, const std::vector<OTFloat>& arrayFloat);
		static EnumStatusCode setDoubleArray(ValueStruct* pValueStruct, const std::vector<OTDouble>& arrayDouble);
		static EnumStatusCode setStringArray(ValueStruct* pValueStruct, const std::vector<tstring>& arrayString);
		static EnumStatusCode setDateTimeArray(ValueStruct* pValueStruct, const std::vector<DateTime>& arrayDateTime);
		static EnumStatusCode setGuidArray(ValueStruct* pValueStruct, const std::vector<Guid>& arrayGuid);
		static EnumStatusCode setStatusCodeArray(ValueStruct* pValueStruct, const std::vector<EnumStatusCode>& arrayStatusCode);
		static EnumStatusCode setValueArray(ValueStruct* pValueStruct, const std::vector<Value>& arrayValue);
		static EnumStatusCode setByteStringArray(ValueStruct* pValueStruct, const std::vector<ByteString>& arrayByteString);
		static EnumStatusCode setXmlElementArray(ValueStruct* pValueStruct, const std::vector<XmlElement>& arrayXmlElement);

		/* getters. */
		static EnumStatusCode getBoolean(const ValueStruct* pValueStruct, OTBoolean* pTarget);
		static OTBoolean getBoolean(const ValueStruct* pValueStruct);

		static EnumStatusCode getUInt64(const ValueStruct* pValueStruct, OTUInt64* pTarget);
		static OTUInt64 getUInt64(const ValueStruct* pValueStruct);

		static EnumStatusCode getInt64(const ValueStruct* pValueStruct, OTInt64* pTarget);
		static OTInt64 getInt64(const ValueStruct* pValueStruct);

		static EnumStatusCode getUInt32(const ValueStruct* pValueStruct, OTUInt32* pTarget);
		static OTUInt32 getUInt32(const ValueStruct* pValueStruct);

		static EnumStatusCode getInt32(const ValueStruct* pValueStruct, OTInt32* pTarget);
		static OTInt32 getInt32(const ValueStruct* pValueStruct);

		static EnumStatusCode getUInt16(const ValueStruct* pValueStruct, OTUInt16* pTarget);
		static OTUInt16 getUInt16(const ValueStruct* pValueStruct);

		static EnumStatusCode getInt16(const ValueStruct* pValueStruct, OTInt16* pTarget);
		static OTInt16 getInt16(const ValueStruct* pValueStruct);

		static EnumStatusCode getUInt8(const ValueStruct* pValueStruct, OTUInt8* pTarget);
		static OTUInt8 getUInt8(const ValueStruct* pValueStruct);

		static EnumStatusCode getInt8(const ValueStruct* pValueStruct, OTInt8* pTarget);
		static OTInt8 getInt8(const ValueStruct* pValueStruct);

		static EnumStatusCode getFloat(const ValueStruct* pValueStruct, OTFloat* pTarget);
		static OTFloat getFloat(const ValueStruct* pValueStruct);

		static EnumStatusCode getDouble(const ValueStruct* pValueStruct, OTDouble* pTarget);
		static OTDouble getDouble(const ValueStruct* pValueStruct);

		static EnumStatusCode getStatusCode(const ValueStruct* pValueStruct, EnumStatusCode* pTarget);
		static EnumStatusCode getStatusCode(const ValueStruct* pValueStruct);

		static EnumStatusCode getString(const ValueStruct* pValueStruct, tstring& target);
		static tstring getString(const ValueStruct* pValueStruct);

		static DateTime getDateTime(const ValueStruct* pValueStruct);
		static EnumStatusCode getDateTime(const ValueStruct* pValueStruct, DateTime& target);

		static Guid getGuid(const ValueStruct* pValueStruct);
		static EnumStatusCode getGuid(const ValueStruct* pValueStruct, Guid& target);

		static ByteString getByteString(const ValueStruct* pValueStruct);
		static EnumStatusCode getByteString(const ValueStruct* pValueStruct, ByteString& target);

		static XmlElement getXmlElement(const ValueStruct* pValueStruct);
		static EnumStatusCode getXmlElement(const ValueStruct* pValueStruct, XmlElement& target);

		//arrays
		static std::vector<OTBoolean> getBooleanArray(const ValueStruct* pValueStruct);
		static EnumStatusCode getBooleanArray(const ValueStruct* pValueStruct, std::vector<OTBoolean>& target);

		static std::vector<OTUInt8> getUInt8Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getUInt8Array(const ValueStruct* pValueStruct, std::vector<OTUInt8>& target);

		static std::vector<OTInt8> getInt8Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getInt8Array(const ValueStruct* pValueStruct, std::vector<OTInt8>& target);

		static std::vector<OTUInt16> getUInt16Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getUInt16Array(const ValueStruct* pValueStruct, std::vector<OTUInt16>& target);

		static std::vector<OTInt16> getInt16Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getInt16Array(const ValueStruct* pValueStruct, std::vector<OTInt16>& target);

		static std::vector<OTUInt32> getUInt32Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getUInt32Array(const ValueStruct* pValueStruct, std::vector<OTUInt32>& target);

		static std::vector<OTInt32> getInt32Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getInt32Array(const ValueStruct* pValueStruct, std::vector<OTInt32>& target);

		static std::vector<OTUInt64> getUInt64Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getUInt64Array(const ValueStruct* pValueStruct, std::vector<OTUInt64>& target);

		static std::vector<OTInt64> getInt64Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getInt64Array(const ValueStruct* pValueStruct, std::vector<OTInt64>& target);

		static std::vector<OTFloat> getFloatArray(const ValueStruct* pValueStruct);
		static EnumStatusCode getFloatArray(const ValueStruct* pValueStruct, std::vector<OTFloat>& target);

		static std::vector<OTDouble> getDoubleArray(const ValueStruct* pValueStruct);
		static EnumStatusCode getDoubleArray(const ValueStruct* pValueStruct, std::vector<OTDouble>& target);

		static EnumStatusCode getDateTimeArray(const ValueStruct* pValueStruct, std::vector<DateTime>& arrayDateTime);
		static std::vector<DateTime> getDateTimeArray(const ValueStruct* pValueStruct);

		static EnumStatusCode getStatusCodeArray(const ValueStruct* pValueStruct, std::vector<EnumStatusCode>& arrayStatusCode);
		static std::vector<EnumStatusCode> getStatusCodeArray(const ValueStruct* pValueStruct);

		static EnumStatusCode getGuidArray(const ValueStruct* pValueStruct, std::vector<Guid>& arrayGuid);
		static std::vector<Guid> getGuidArray(const ValueStruct* pValueStruct);

		static EnumStatusCode getStringArray(const ValueStruct* pValueStruct, std::vector<tstring>& arrayString);
		static std::vector<tstring> getStringArray(const ValueStruct* pValueStruct);

		static EnumStatusCode getByteStringArray(const ValueStruct* pValueStruct, std::vector<ByteString>& arrayByteString);
		static std::vector<ByteString> getByteStringArray(const ValueStruct* pValueStruct);

		static EnumStatusCode getXmlElementArray(const ValueStruct* pValueStruct, std::vector<XmlElement>& arrayByteString);
		static std::vector<XmlElement> getXmlElementArray(const ValueStruct* pValueStruct);

		static EnumStatusCode getValueArray(const ValueStruct* pValueStruct, std::vector<Value>& arrayValue);
		static std::vector<Value> getValueArray(const ValueStruct* pValueStruct);

		static EnumStatusCode getStructuredValue(const ValueStruct* pValueStruct, StructuredDataTypeDescriptionConstPtr dataTypeDescription, std::vector<Value>& fieldValues);
		static EnumStatusCode setStructuredValue(ValueStruct* pValueStruct, const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<Value>& fieldValues);

		static EnumStatusCode getStructuredValueArray(const ValueStruct* pValueStruct, StructuredDataTypeDescriptionConstPtr dataTypeDescription, std::vector<std::vector<Value> >& fieldValues);
		static EnumStatusCode setStructuredValueArray(ValueStruct* pValueStruct, const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<std::vector<Value> >& fieldValues);

	/*! Utility template method for transforming a vector to an array and calling the OT - C
		* ValueStruct comfort method. */
		template <class T, typename OTFunc>
		static EnumStatusCode setArray(ValueStruct* pValueStruct, const std::vector<T>& arrayT, OTFunc otFunc)
		{
			T* local_array = (T*)OTAllocateMemory(sizeof(T) * arrayT.size());
			if(local_array == NULL)
			{
				return EnumStatusCode_BadInvalidArgument;
			}
			//transform the std::vector to array
			for(unsigned i = 0; i < arrayT.size(); i++)
			{
				local_array[i] = (T)arrayT[i];
			}
			EnumStatusCode result = otFunc(pValueStruct, local_array, (long)arrayT.size());
			OTFreeMemory(local_array);
			return result;
		}

		/*! Copy the primitive array from a ValueStruct to a std::vector.
		*
		*   @param pValueStruct	The source structure, from where the array is copied
		*   @param arrayT		The target array, where the structures will be copied
		*   @param pArray		The array of the ValueStructure, from where the structures are copied
		*   @return an enum code representing the status of the array copy. */
		template <class T, class V>
		static EnumStatusCode getPrimitiveArray(const ValueStruct* pValueStruct, std::vector<T>& arrayT, V pArray[])
		{
			long length = pValueStruct->value.Array.Length;
			arrayT.reserve(length);
			for(int i = 0; i < length; i++)
			{
				arrayT.push_back(pArray[i]);
			}
			return EnumStatusCode_Good;
		}

		/*! Copy the array from a ValueStruct to a std::vector.
		*
		*   @param pValueStruct	The source structure, from where the array is copied
		*   @param arrayT		The target array, where the structures will be copied
		*   @param ofFunc		The exported OT method, which copy the OT structure from source to target
		*   @param pArray		The array of the ValueStructure, from where the structures are copied
		*   @return an enum code representing the status of the array copy. */
		template <class T, class V, typename OTFunc>
		static EnumStatusCode getArray(const ValueStruct* pValueStruct, std::vector<T>& arrayT, OTFunc otFunc, V pArray[])
		{
			OTInt32 length = pValueStruct->value.Array.Length;
			arrayT.reserve(length);
			for(OTInt32 i = 0; i < length; i++)
			{
				arrayT.push_back(T());
				EnumStatusCode result = otFunc((V*)arrayT.back().getInternHandle(), &pArray[i]);
				if(StatusCode::isFAILED(result))
				{
					//rollback the array.
					arrayT.clear();
					return result;
				}
			}
			return EnumStatusCode_Good;
		}

		/*! Similar with getArray, just call OT functions which return void. */
		template <class T, class V, typename OTFunc>
		static EnumStatusCode getArrayV(const ValueStruct* pValueStruct, std::vector<T>& arrayT, OTFunc otFunc, V pArray[])
		{
			long length = pValueStruct->value.Array.Length;
			arrayT.reserve(length);
			for(int i = 0; i < length; i++)
			{
				T t;
				otFunc((V*)t.getInternHandle(), &pArray[i]);
				arrayT.push_back(t);
			}
			return EnumStatusCode_Good;
		}

		template<class T, typename OTClearFunc>
		static void clearStructures(T* pStructArray, size_t idx, OTClearFunc otFunc)
		{
			for(size_t i = 0; i < idx; i++)
			{
				otFunc(&pStructArray[i]);
			}
		}


		static tstring toString(const ValueStruct* pValueStruct);
	};
}

#endif	// VALUEHELPER_H
