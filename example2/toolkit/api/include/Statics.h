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

#ifndef TOOLBOX_STATICS_H
#define TOOLBOX_STATICS_H

namespace SoftingOPCToolbox5
{
	class NodeId;
	namespace Statics
	{
		////////////////////////////////////////////////////////////////////////////////
		// Static NodeId declaration for DataType NodeIds
		extern TBC_EXPORT NodeId* DataTypeId_Boolean;
		extern TBC_EXPORT NodeId* DataTypeId_SByte;
		extern TBC_EXPORT NodeId* DataTypeId_Byte;
		extern TBC_EXPORT NodeId* DataTypeId_Int16;
		extern TBC_EXPORT NodeId* DataTypeId_UInt16;
		extern TBC_EXPORT NodeId* DataTypeId_Int32;
		extern TBC_EXPORT NodeId* DataTypeId_UInt32;
		extern TBC_EXPORT NodeId* DataTypeId_Int64;
		extern TBC_EXPORT NodeId* DataTypeId_UInt64;
		extern TBC_EXPORT NodeId* DataTypeId_Float;
		extern TBC_EXPORT NodeId* DataTypeId_Double;
		extern TBC_EXPORT NodeId* DataTypeId_String;
		extern TBC_EXPORT NodeId* DataTypeId_DateTime;
		extern TBC_EXPORT NodeId* DataTypeId_Guid;
		extern TBC_EXPORT NodeId* DataTypeId_ByteString;
		extern TBC_EXPORT NodeId* DataTypeId_XmlElement;
		extern TBC_EXPORT NodeId* DataTypeId_NodeId;
		extern TBC_EXPORT NodeId* DataTypeId_ExpandedNodeId;
		extern TBC_EXPORT NodeId* DataTypeId_StatusCode;
		extern TBC_EXPORT NodeId* DataTypeId_QualifiedName;
		extern TBC_EXPORT NodeId* DataTypeId_LocalizedText;
		extern TBC_EXPORT NodeId* DataTypeId_DataValue;
		extern TBC_EXPORT NodeId* DataTypeId_BaseDataType;
		extern TBC_EXPORT NodeId* DataTypeId_Number;
		extern TBC_EXPORT NodeId* DataTypeId_Integer;
		extern TBC_EXPORT NodeId* DataTypeId_UInteger;
		extern TBC_EXPORT NodeId* DataTypeId_Enumeration;
		extern TBC_EXPORT NodeId* DataTypeId_Image;
		extern TBC_EXPORT NodeId* DataTypeId_NamingRuleType;
		extern TBC_EXPORT NodeId* DataTypeId_Duration;
		extern TBC_EXPORT NodeId* DataTypeId_NumericRange;
		extern TBC_EXPORT NodeId* DataTypeId_UtcTime;
		extern TBC_EXPORT NodeId* DataTypeId_LocaleId;
		extern TBC_EXPORT NodeId* DataTypeId_Argument;
		extern TBC_EXPORT NodeId* DataTypeId_ApplicationDescription;
		extern TBC_EXPORT NodeId* DataTypeId_UserIdentityToken;
		extern TBC_EXPORT NodeId* DataTypeId_BuildInfo;
		extern TBC_EXPORT NodeId* DataTypeId_SignedSoftwareCertificate;
		extern TBC_EXPORT NodeId* DataTypeId_ReferenceDescription;
		extern TBC_EXPORT NodeId* DataTypeId_EventFilter;
		extern TBC_EXPORT NodeId* DataTypeId_ServerDiagnosticsSummaryDataType;
		extern TBC_EXPORT NodeId* DataTypeId_ServerStatusDataType;
		extern TBC_EXPORT NodeId* DataTypeId_SessionDiagnosticsDataType;
		extern TBC_EXPORT NodeId* DataTypeId_SessionSecurityDiagnosticsDataType;
		extern TBC_EXPORT NodeId* DataTypeId_ServiceCounterDataType;
		extern TBC_EXPORT NodeId* DataTypeId_SubscriptionDiagnosticsDataType;
		extern TBC_EXPORT NodeId* DataTypeId_ModelChangeStructureDataType;
		extern TBC_EXPORT NodeId* DataTypeId_Range;
		extern TBC_EXPORT NodeId* DataTypeId_EUInformation;
		extern TBC_EXPORT NodeId* DataTypeId_SemanticChangeStructureDataType;
		extern TBC_EXPORT NodeId* DataTypeId_ImageBMP;
		extern TBC_EXPORT NodeId* DataTypeId_ImageGIF;
		extern TBC_EXPORT NodeId* DataTypeId_ImageJPG;
		extern TBC_EXPORT NodeId* DataTypeId_ImagePNG;
		extern TBC_EXPORT NodeId* DataTypeId_TimeZoneDataType;

		////////////////////////////////////////////////////////////////////////////////
		// Static NodeId declaration for Method NodeIds
		extern TBC_EXPORT NodeId* MethodNodeId_ConditionRefreshMethod;

		////////////////////////////////////////////////////////////////////////////////
		// Static NodeId declaration for ObjectType NodeIds
		extern TBC_EXPORT NodeId* ObjectTypeId_BaseObjectType;
		extern TBC_EXPORT NodeId* ObjectTypeId_FolderType;
		extern TBC_EXPORT NodeId* ObjectTypeId_DataTypeSystemType;
		extern TBC_EXPORT NodeId* ObjectTypeId_DataTypeEncodingType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ModellingRuleType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ServerType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ServerCapabilitiesType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ServerDiagnosticsType;
		extern TBC_EXPORT NodeId* ObjectTypeId_SessionsDiagnosticsSummaryType;
		extern TBC_EXPORT NodeId* ObjectTypeId_SessionDiagnosticsObjectType;
		extern TBC_EXPORT NodeId* ObjectTypeId_VendorServerInfoType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ServerRedundancyType;
		extern TBC_EXPORT NodeId* ObjectTypeId_TransparentRedundancyType;
		extern TBC_EXPORT NodeId* ObjectTypeId_NonTransparentRedundancyType;
		extern TBC_EXPORT NodeId* ObjectTypeId_BaseEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditSecurityEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditChannelEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditOpenSecureChannelEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditSessionEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditCreateSessionEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditActivateSessionEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditCancelEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditCertificateEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditCertificateDataMismatchEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditCertificateExpiredEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditCertificateInvalidEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditCertificateUntrustedEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditCertificateRevokedEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditCertificateMismatchEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditNodeManagementEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditAddNodesEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditDeleteNodesEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditAddReferencesEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditDeleteReferencesEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditUpdateEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditWriteUpdateEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditHistoryUpdateEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditUpdateMethodEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_SystemEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_DeviceFailureEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_BaseModelChangeEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_GeneralModelChangeEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_StateMachineType;
		extern TBC_EXPORT NodeId* ObjectTypeId_StateType;
		extern TBC_EXPORT NodeId* ObjectTypeId_InitialStateType;
		extern TBC_EXPORT NodeId* ObjectTypeId_TransitionType;
		extern TBC_EXPORT NodeId* ObjectTypeId_TransitionEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditUpdateStateEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_HistoricalDataConfigurationType;
		extern TBC_EXPORT NodeId* ObjectTypeId_HistoryServerCapabilitiesType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AggregateFunctionType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ProgramTransitionEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ProgramStateMachineType;
		extern TBC_EXPORT NodeId* ObjectTypeId_SemanticChangeEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditUrlMismatchEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_FiniteStateMachineType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ConditionType;
		extern TBC_EXPORT NodeId* ObjectTypeId_RefreshStartEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_RefreshEndEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_RefreshRequiredEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditConditionEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditConditionEnableEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditConditionCommentEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_DialogConditionType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AcknowledgeableConditionType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AlarmConditionType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ShelvedStateMachineType;
		extern TBC_EXPORT NodeId* ObjectTypeId_LimitAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditHistoryEventUpdateEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditHistoryValueUpdateEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditHistoryDeleteEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditHistoryRawModifyDeleteEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditHistoryAtTimeDeleteEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditHistoryEventDeleteEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_EventQueueOverflowEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ProgramTransitionAuditEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_LockType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditConditionRespondEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditConditionAcknowledgeEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditConditionConfirmEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ExclusiveLimitStateMachineType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ExclusiveLimitAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ExclusiveLevelAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ExclusiveRateOfChangeAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ExclusiveDeviationAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_NonExclusiveLimitAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_NonExclusiveLevelAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_NonExclusiveRateOfChangeAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_NonExclusiveDeviationAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_DiscreteAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_OffNormalAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_TripAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditConditionShelvingEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_BaseConditionClassType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ProcessConditionClassType;
		extern TBC_EXPORT NodeId* ObjectTypeId_MaintenanceConditionClassType;
		extern TBC_EXPORT NodeId* ObjectTypeId_SystemConditionClassType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AggregateConfigurationType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ProgressEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_SystemStatusChangeEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_OperationLimitsType;
		extern TBC_EXPORT NodeId* ObjectTypeId_FileType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AddressSpaceFileType;
		extern TBC_EXPORT NodeId* ObjectTypeId_NamespaceMetadataType;
		extern TBC_EXPORT NodeId* ObjectTypeId_NamespacesType;
		extern TBC_EXPORT NodeId* ObjectTypeId_SystemOffNormalAlarmType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuditProgramTransitionEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_NonTransparentNetworkRedundancyType;
		extern TBC_EXPORT NodeId* ObjectTypeId_TrustListType;
		extern TBC_EXPORT NodeId* ObjectTypeId_AuthorityType;
		extern TBC_EXPORT NodeId* ObjectTypeId_CertificateType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ApplicationCertificateType;
		extern TBC_EXPORT NodeId* ObjectTypeId_HttpsCertificateType;
		extern TBC_EXPORT NodeId* ObjectTypeId_RsaBasicApplicationCertificateType;
		extern TBC_EXPORT NodeId* ObjectTypeId_Rsa2084ApplicationCertificateType;
		extern TBC_EXPORT NodeId* ObjectTypeId_TrustListUpdatedAuditEventType;
		extern TBC_EXPORT NodeId* ObjectTypeId_ServerConfigurationType;
		extern TBC_EXPORT NodeId* ObjectTypeId_CertificateUpdatedAuditEventType;

		////////////////////////////////////////////////////////////////////////////////
		// Static NodeId declaration for ReferenceType NodeIds
		extern TBC_EXPORT NodeId* ReferenceTypeId_References;
		extern TBC_EXPORT NodeId* ReferenceTypeId_NonHierarchicalReferences;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HierarchicalReferences;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasChild;
		extern TBC_EXPORT NodeId* ReferenceTypeId_Organizes;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasEventSource;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasModellingRule;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasEncoding;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasDescription;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasTypeDefinition;
		extern TBC_EXPORT NodeId* ReferenceTypeId_GeneratesEvent;
		extern TBC_EXPORT NodeId* ReferenceTypeId_Aggregates;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasSubtype;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasProperty;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasComponent;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasNotifier;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasOrderedComponent;
		extern TBC_EXPORT NodeId* ReferenceTypeId_FromState;
		extern TBC_EXPORT NodeId* ReferenceTypeId_ToState;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasCause;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasEffect;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasHistoricalConfiguration;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasSubStateMachine;
		extern TBC_EXPORT NodeId* ReferenceTypeId_AlwaysGeneratesEvent;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasTrueSubState;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasFalseSubState;
		extern TBC_EXPORT NodeId* ReferenceTypeId_HasCondition;

		////////////////////////////////////////////////////////////////////////////////
		// Static NodeId declaration for VariableType NodeIds
		extern TBC_EXPORT NodeId* VariableTypeId_BaseVariableType;
		extern TBC_EXPORT NodeId* VariableTypeId_BaseDataVariableType;
		extern TBC_EXPORT NodeId* VariableTypeId_PropertyType;
		extern TBC_EXPORT NodeId* VariableTypeId_DataTypeDescriptionType;
		extern TBC_EXPORT NodeId* VariableTypeId_DataTypeDictionaryType;
		extern TBC_EXPORT NodeId* VariableTypeId_ServerVendorCapabilityType;
		extern TBC_EXPORT NodeId* VariableTypeId_ServerStatusType;
		extern TBC_EXPORT NodeId* VariableTypeId_ServerDiagnosticsSummaryType;
		extern TBC_EXPORT NodeId* VariableTypeId_SamplingIntervalDiagnosticsArrayType;
		extern TBC_EXPORT NodeId* VariableTypeId_SamplingIntervalDiagnosticsType;
		extern TBC_EXPORT NodeId* VariableTypeId_SubscriptionDiagnosticsArrayType;
		extern TBC_EXPORT NodeId* VariableTypeId_SubscriptionDiagnosticsType;
		extern TBC_EXPORT NodeId* VariableTypeId_SessionDiagnosticsArrayType;
		extern TBC_EXPORT NodeId* VariableTypeId_SessionDiagnosticsVariableType;
		extern TBC_EXPORT NodeId* VariableTypeId_SessionSecurityDiagnosticsArrayType;
		extern TBC_EXPORT NodeId* VariableTypeId_SessionSecurityDiagnosticsType;
		extern TBC_EXPORT NodeId* VariableTypeId_DataItemType;
		extern TBC_EXPORT NodeId* VariableTypeId_AnalogItemType;
		extern TBC_EXPORT NodeId* VariableTypeId_DiscreteItemType;
		extern TBC_EXPORT NodeId* VariableTypeId_TwoStateDiscreteType;
		extern TBC_EXPORT NodeId* VariableTypeId_MultiStateDiscreteType;
		extern TBC_EXPORT NodeId* VariableTypeId_ProgramDiagnosticType;
		extern TBC_EXPORT NodeId* VariableTypeId_StateVariableType;
		extern TBC_EXPORT NodeId* VariableTypeId_FiniteStateVariableType;
		extern TBC_EXPORT NodeId* VariableTypeId_TransitionVariableType;
		extern TBC_EXPORT NodeId* VariableTypeId_FiniteTransitionVariableType;
		extern TBC_EXPORT NodeId* VariableTypeId_BuildInfoType;
		extern TBC_EXPORT NodeId* VariableTypeId_TwoStateVariableType;
		extern TBC_EXPORT NodeId* VariableTypeId_ConditionVariableType;
		extern TBC_EXPORT NodeId* VariableTypeId_MultiStateValueDiscreteType;
		extern TBC_EXPORT NodeId* VariableTypeId_OptionSetType;
		extern TBC_EXPORT NodeId* VariableTypeId_ArrayItemType;
		extern TBC_EXPORT NodeId* VariableTypeId_YArrayItemType;
		extern TBC_EXPORT NodeId* VariableTypeId_XYArrayItemType;
		extern TBC_EXPORT NodeId* VariableTypeId_ImageItemType;
		extern TBC_EXPORT NodeId* VariableTypeId_CubeItemType;
		extern TBC_EXPORT NodeId* VariableTypeId_NDimensionArrayItemType;


	}

	/*! For internal use only.
	*
	* Members of the Statics class are made available during initialization of
	* the Application (see Application::initialize()). */
	void initStaticNodes();

	/*! For internal use only.
	*
	* Members of the Statics class are freed during Application::uninitialize(). */
	void deleteStaticNodes();
}

#endif // TOOLBOX_STATICS_H
