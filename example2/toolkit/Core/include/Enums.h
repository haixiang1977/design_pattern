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

#ifndef ENUMS_H
#define ENUMS_H

#include "OSCompat.h"
#include "OTExports.h"

/*! @file Enums.h */

////////////////////////////////////////////////////////////////////////////////
//! Specifies the possible monitoring states of a monitored item.
typedef enum tagEnumMonitoringMode // Declaration of enum EnumMonitoringMode
{
	//! In this state a MonitoredItem is not collecting change notifications and also does not report anything
	//! to the client.
	//! If the MonitoredItem is "connected" the Item exists on the server.
	//! The Disabled state is foreseen to switch off reporting and sampling of MonitoredItems on a server where
	//! the item is still existing on the server.
	EnumMonitoringMode_Disabled = 0x00,

	//! In this state the MonitoredItem is collecting change notifications but not reporting them to the client.
	//! In addition, each sample is evaluated to determine if a Notification should be generated.
	EnumMonitoringMode_Sampling = 0x01,

	//! In this state the MonitoredItem is collecting change notifications and reporting them to the client.
	EnumMonitoringMode_Reporting = 0x02
}
EnumMonitoringMode; // end EnumMonitoringMode;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumMonitoringModeString(EnumMonitoringMode value);
EnumMonitoringMode OTGetEnumMonitoringModeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumMonitoringModeString(EnumMonitoringMode value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumMonitoringMode getEnumMonitoringModeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Specifies the connection state of an object (Session, Subscription or Monitored item).
typedef enum tagEnumObjectState // Declaration of enum EnumObjectState
{
	//! The state of the object is disconnected.
	EnumObjectState_Disconnected = 0x00,

	//! The state of the object is connected.
	EnumObjectState_Connected = 0x01,

	//! The state of the object is during establishing a connection (only valid for actual state).
	EnumObjectState_Connecting = 0x02,

	//! The state of the object is during closing a connection (only valid for actual state).
	EnumObjectState_Disconnecting = 0x03
}
EnumObjectState; // end EnumObjectState;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumObjectStateString(EnumObjectState value);
EnumObjectState OTGetEnumObjectStateFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumObjectStateString(EnumObjectState value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumObjectState getEnumObjectStateFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Bit coded enumeration (value can be a combination) defining the allowed
//! access level to a value of a Variable node.
typedef OTUInt8 EnumAccessLevel;

//! Empty value for init or clear of values.
static const EnumAccessLevel EnumAccessLevel_None = 0x00;
//! Allows the read of the current value.
static const EnumAccessLevel EnumAccessLevel_CurrentRead = 0x01;
//! Allows the write of the current value.
static const EnumAccessLevel EnumAccessLevel_CurrentWrite = 0x02;
//! Allows a history read on the Variable.
static const EnumAccessLevel EnumAccessLevel_HistoryRead = 0x04;
//! Allows a history write on the Variable.
static const EnumAccessLevel EnumAccessLevel_HistoryWrite = 0x08;
//! Indicates if the Variable used as Property generates SemanticChangeEvents.
static const EnumAccessLevel EnumAccessLevel_SemanticChange = 0x10;
//! Allows to execute the current method.
static const EnumAccessLevel EnumAccessLevel_Executable = 0x80;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumAccessLevelString(EnumAccessLevel value);
EnumAccessLevel OTGetEnumAccessLevelFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumAccessLevelString(EnumAccessLevel value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumAccessLevel getEnumAccessLevelFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Defines the application type of the implemented application (see Application::initialize()). An application
//! can be a Server only, a Client only a Discovery Server or Server and Client.
typedef enum tagEnumApplicationType // Declaration of enum EnumApplicationType
{
	//! The application is acting as Server only.
	EnumApplicationType_Server = 0,

	//! The application is acting as Client only.
	EnumApplicationType_Client = 1,

	//! The application is Server and Client
	EnumApplicationType_Both = 2,

	//! The application is acting as a Discovery Server.
	EnumApplicationType_DiscoveryServer = 3
}
EnumApplicationType; // end EnumApplicationType;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumApplicationTypeString(EnumApplicationType value);
EnumApplicationType OTGetEnumApplicationTypeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumApplicationTypeString(EnumApplicationType value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumApplicationType getEnumApplicationTypeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration used for defining the target of Read / Write calls or the requested Attribute of MonitoredItems.
typedef enum tagEnumAttributeId // Declaration of enum EnumAttributeId
{
	//! Type: NodeId; the NodeId of the node.
	EnumAttributeId_NodeId = 1,

	//! Type: UInt32; the NodeClass of the node.
	EnumAttributeId_NodeClass = 2,

	//! Type: QualifiedName; the BrowseName of the node.
	EnumAttributeId_BrowseName = 3,

	//! Type: LocalizedText; the DisplayName of the node.
	EnumAttributeId_DisplayName = 4,

	//! Type: LocalizedText; the Description of the node.
	EnumAttributeId_Description = 5,

	//! Type: UInt32; the write mask of the node (see also Server::BaseNode).
	EnumAttributeId_WriteMask = 6,

	//! Type: UInt32; the user write mask of the node (see also Server::BaseNode).
	EnumAttributeId_UserWriteMask = 7,

	//! Type: Boolean; the abstract flag (applies only to TypeDefinition nodes).
	EnumAttributeId_IsAbstract = 8,

	//! Type: Boolean; the symmetric flag of the node (applies only to ReferenceType nodes).
	EnumAttributeId_Symmetric = 9,

	//! Type: LocalizedText; the Inverse name of the node (applies only to ReferenceType nodes).
	EnumAttributeId_InverseName = 10,

	//! Type: Boolean; the ContainsNoLoops of the node (applies only to View nodes).
	EnumAttributeId_ContainsNoLoops = 11,

	//! Type: Byte; the EventNotifier of the node (applies only to Object and View nodes).
	EnumAttributeId_EventNotifier = 12,

	//! Type: Value; the Value of the node (applies only to Variable and VariableType nodes).
	EnumAttributeId_Value = 13,

	//! Type: NodeId; DataType of the node (applies only to Variable and VariableType nodes).
	EnumAttributeId_DataType = 14,

	//! Type: Int32; the ValueRank of the node (applies only to Variable and VariableType nodes)
	EnumAttributeId_ValueRank = 15,

	//! Type: Array of UInt32; the array dimensions of the node (applies only to Variable and VariableType nodes).
	EnumAttributeId_ArrayDimensions = 16,

	//! Type: Byte; the access level of the node (applies only to Variable nodes).
	EnumAttributeId_AccessLevel = 17,

	//! Type: Byte; the user access level of the node (applies only to Variable nodes).
	EnumAttributeId_UserAccessLevel = 18,

	//! Type: Double; the minimum sampling interval of the node (applies only to Variable nodes).
	EnumAttributeId_MinimumSamplingInterval = 19,

	//! Type: Boolean; the Historizing flag of the node (applies only to Variable nodes).
	EnumAttributeId_Historizing = 20,

	//! Type: Boolean; the Executable flag of the node (applies only to Method nodes).
	EnumAttributeId_Executable = 21,

	//! Type: Boolean; the user executable flag of the node (applies only to Method nodes).
	EnumAttributeId_UserExecutable = 22
}
EnumAttributeId; // end EnumAttributeId;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumAttributeIdString(EnumAttributeId value);
EnumAttributeId OTGetEnumAttributeIdFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumAttributeIdString(EnumAttributeId value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumAttributeId getEnumAttributeIdFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration type defining the browse direction during a browse call.
//! Browse operations can be performed either following the references in forward direction / backward direction
//! or both.
typedef enum tagEnumBrowseDirection // Declaration of enum EnumBrowseDirection
{
	//! Select only forward references.
	EnumBrowseDirection_Forward = 0,

	//! Select only inverse references.
	EnumBrowseDirection_Inverse = 1,

	//! Select both forward and inverse references.
	EnumBrowseDirection_Both = 2,

	//! Invalid browse direction
	EnumBrowseDirection_Invalid = 3
}
EnumBrowseDirection; // end EnumBrowseDirection;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumBrowseDirectionString(EnumBrowseDirection value);
EnumBrowseDirection OTGetEnumBrowseDirectionFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumBrowseDirectionString(EnumBrowseDirection value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumBrowseDirection getEnumBrowseDirectionFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration defining the different features that can be licensed.
typedef enum tagEnumFeature // Declaration of enum EnumFeature
{
	//! Enumeration value for Server functionality. Use this enum for enabling a server license.
	EnumFeature_Server = 0x01,

	//! Enumeration value for Client functionality. Use this enum for enabling a client license.
	EnumFeature_Client = 0x02,

	//! Enumeration value for NodeSet2 XML import functionality. Use this enum for enabling importing an NodeSet2 XML file to populate the servers address space.
	EnumFeature_XmlImport = 0x03
}
EnumFeature; // end EnumFeature;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumFeatureString(EnumFeature value);
EnumFeature OTGetEnumFeatureFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumFeatureString(EnumFeature value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumFeature getEnumFeatureFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration for the different identifier types of NodeIds
typedef enum tagEnumIdentifierType // Declaration of enum EnumIdentifierType
{
	//! The identifier is a 32bit unsigned integer.
	EnumIdentifierType_Numeric = 0x00,

	//! The identifier is a string.
	EnumIdentifierType_String = 0x01,

	//! The identifier is a GUID (byte field with 16 bytes)
	EnumIdentifierType_Guid = 0x02,

	//! The identifier is a free byte string.
	EnumIdentifierType_Opaque = 0x03,

	//! Use for uninitialized identifier types only.
	EnumIdentifierType_Invalid = 0xFF
}
EnumIdentifierType; // end EnumIdentifierType;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumIdentifierTypeString(EnumIdentifierType value);
EnumIdentifierType OTGetEnumIdentifierTypeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumIdentifierTypeString(EnumIdentifierType value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumIdentifierType getEnumIdentifierTypeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Define the possible message security modes, that can be used for communication.
typedef enum tagEnumMessageSecurityMode // Declaration of enum EnumMessageSecurityMode
{
	//! An invalid value.
	EnumMessageSecurityMode_Invalid = 0,

	//! No security mode. Messages are neither signed nor encrypted.
	EnumMessageSecurityMode_None = 1,

	//! Messages are only signed.
	EnumMessageSecurityMode_Sign = 2,

	//! Messages are signed and encrypted.
	EnumMessageSecurityMode_SignAndEncrypt = 3
}
EnumMessageSecurityMode; // end EnumMessageSecurityMode;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumMessageSecurityModeString(EnumMessageSecurityMode value);
EnumMessageSecurityMode OTGetEnumMessageSecurityModeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumMessageSecurityModeString(EnumMessageSecurityMode value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumMessageSecurityMode getEnumMessageSecurityModeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration for the different node classes (= nodes in the server). Each Node has an attribute which identifies
//! the node type by this enumeration type.
typedef OTUInt32 EnumNodeClass;

//! Base node class. A concrete node can not be of that type.
static const EnumNodeClass EnumNodeClass_Node = 0;
//! Object node class (see Object class definition)
static const EnumNodeClass EnumNodeClass_Object = 1;
//! Variable node class (see Variable class definition).
static const EnumNodeClass EnumNodeClass_Variable = 2;
//! Method node class (see Method class definition).
static const EnumNodeClass EnumNodeClass_Method = 4;
//! ObjectType node class (see ObjectType class definition).
static const EnumNodeClass EnumNodeClass_ObjectType = 8;
//! VariableType node class (see VariableType class definition).
static const EnumNodeClass EnumNodeClass_VariableType = 16;
//! ReferenceType node class (see ReferenceType class definition).
static const EnumNodeClass EnumNodeClass_ReferenceType = 32;
//! DataType node class (see DataType class definition).
static const EnumNodeClass EnumNodeClass_DataType = 64;
//! View node class (see Viewclass definition).
static const EnumNodeClass EnumNodeClass_View = 128;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumNodeClassString(EnumNodeClass value);
EnumNodeClass OTGetEnumNodeClassFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumNodeClassString(EnumNodeClass value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumNodeClass getEnumNodeClassFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration for the different serialization types (e.g. a Session has a defined serialization type).
typedef enum tagEnumSerializerType // Declaration of enum EnumSerializerType
{
	//! Invalid serializer type.
	EnumSerializerType_Invalid = 0x00,
	//! Binary serializer type.
	EnumSerializerType_Binary = 0x01,
	//! Xml serializer type (currently not supported).
	EnumSerializerType_Xml = 0x02
}
EnumSerializerType; // end EnumSerializerType;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumSerializerTypeString(EnumSerializerType value);
EnumSerializerType OTGetEnumSerializerTypeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumSerializerTypeString(EnumSerializerType value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumSerializerType getEnumSerializerTypeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration type used for all returns of method calls and also for status information on values.
typedef enum tagEnumStatusCode // Declaration of enum EnumStatusCode
{
	//! Everything is as expected.
	EnumStatusCode_Good = 0x00000000,

	//! The subscription was transferred to another session.
	EnumStatusCode_GoodSubscriptionTransferred = 0x002D0000,

	//! The processing will complete asynchronously.
	EnumStatusCode_GoodCompletesAsynchronously = 0x002E0000,

	//! Sampling has slowed down due to resource limitations.
	EnumStatusCode_GoodOverload = 0x002F0000,

	//! The value written was accepted but was clamped.
	EnumStatusCode_GoodClamped = 0x00300000,

	//! The value has been overridden.
	EnumStatusCode_GoodLocalOverride = 0x00960000,

	//! The data or event was successfully inserted into the historical database.
	EnumStatusCode_GoodEntryInserted = 0x00A20000,

	//! The data or event field was successfully replaced in the historical database.
	EnumStatusCode_GoodEntryReplaced = 0x00A30000,

	//! No data exists for the requested time range or event filter.
	EnumStatusCode_GoodNoData = 0x00A50000,

	//! The data or event field was successfully replaced in the historical database.
	EnumStatusCode_GoodMoreData = 0x00A60000,

	//! The communication layer has raised an event.
	EnumStatusCode_GoodCommunicationEvent = 0x00A70000,

	//! The system is shutting down.
	EnumStatusCode_GoodShutdownEvent = 0x00A80000,

	//! The operation is not finished and needs to be called again.
	EnumStatusCode_GoodCallAgain = 0x00A90000,

	//! A non-critical timeout occurred.
	EnumStatusCode_GoodNonCriticalTimeout = 0x00AA0000,

	//! The server should have followed a reference to a node in a remote server but did not. The result set may be incomplete.
	EnumStatusCode_GoodResultsMayBeIncomplete = 0x00BA0000,

	//! The request specifies fields which are not valid for the EventType or cannot be saved by the historian.
	EnumStatusCode_GoodDataIgnored = 0x00D90000,

	//! The value does not come from the real source and has been edited by the server.
	EnumStatusCode_GoodEdited = 0x00DC0000,

	//! There was an error in execution of these post-actions.
	EnumStatusCode_GoodPostActionFailed = 0x00DD0000,

	//! A dependent value has been changed but the change has not been applied to the device.
	EnumStatusCode_GoodDependendValueChanged = 0x00DF0000,

	//! Something unexpected occurred but the results still maybe useable.
	EnumStatusCode_Uncertain = 0x40000000,

	//! One of the references to follow in the relative path references to a node in the address space in another server.
	EnumStatusCode_UncertainReferenceOutOfServer = 0x406C0000,

	//! Communication to the data source has failed. The variable value is the last value that had a good quality.
	EnumStatusCode_UncertainNoCommunicationLastUsableValue = 0x408F0000,

	//! Whatever was updating this value has stopped doing so.
	EnumStatusCode_UncertainLastUsableValue = 0x40900000,

	//! The value is an operational value that was manually overwritten.
	EnumStatusCode_UncertainSubstituteValue = 0x40910000,

	//! The value is an initial value for a variable that normally receives its value from another variable.
	EnumStatusCode_UncertainInitialValue = 0x40920000,

	//! The value is at one of the sensor limits.
	EnumStatusCode_UncertainSensorNotAccurate = 0x40930000,

	//! The value is outside of the range of values defined for this parameter.
	EnumStatusCode_UncertainEngineeringUnitsExceeded = 0x40940000,

	//! The value is derived from multiple sources and has less than the required number of Good sources.
	EnumStatusCode_UncertainSubNormal = 0x40950000,

	//! The value is derived from multiple values and has less than the required number of Good values.
	EnumStatusCode_UncertainDataSubNormal = 0x40A40000,

	//! The server was not able to delete all target references.
	EnumStatusCode_UncertainReferenceNotDeleted = 0x40BC0000,

	//! The list of references may not be complete because the underlying system is not available.
	EnumStatusCode_UncertainNotAllNodesAvailable = 0x40C00000,

	//! The related EngineeringUnit has been changed but the Variable Value is still provided based on the previous unit.
	EnumStatusCode_UncertainDominantValueChanged = 0x40DE0000,

	//! An error occurred.
	EnumStatusCode_Bad = 0x80000000,

	//! An unexpected error occurred.
	EnumStatusCode_BadUnexpectedError = 0x80010000,

	//! An internal error occurred as a result of a programming or configuration error.
	EnumStatusCode_BadInternalError = 0x80020000,

	//! Not enough memory to complete the operation.
	EnumStatusCode_BadOutOfMemory = 0x80030000,

	//! An operating system resource is not available.
	EnumStatusCode_BadResourceUnavailable = 0x80040000,

	//! A low level communication error occurred.
	EnumStatusCode_BadCommunicationError = 0x80050000,

	//! Encoding halted because of invalid data in the objects being serialized.
	EnumStatusCode_BadEncodingError = 0x80060000,

	//! Decoding halted because of invalid data in the stream.
	EnumStatusCode_BadDecodingError = 0x80070000,

	//! The message encoding/decoding limits imposed by the stack have been exceeded.
	EnumStatusCode_BadEncodingLimitsExceeded = 0x80080000,

	//! An unrecognized response was received from the server.
	EnumStatusCode_BadUnknownResponse = 0x80090000,

	//! The operation timed out.
	EnumStatusCode_BadTimeout = 0x800A0000,

	//! The server does not support the requested service.
	EnumStatusCode_BadServiceUnsupported = 0x800B0000,

	//! The operation was cancelled because the application is shutting down.
	EnumStatusCode_BadShutdown = 0x800C0000,

	//! The operation could not complete because the client is not connected to the server.
	EnumStatusCode_BadServerNotConnected = 0x800D0000,

	//! The server has stopped and cannot process any requests.
	EnumStatusCode_BadServerHalted = 0x800E0000,

	//! There was nothing to do because the client passed a list of operations with no elements.
	EnumStatusCode_BadNothingToDo = 0x800F0000,

	//! The request could not be processed because it specified too many operations.
	EnumStatusCode_BadTooManyOperations = 0x80100000,

	//! The extension object cannot be (de)serialized because the data type id is not recognized.
	EnumStatusCode_BadDataTypeIdUnknown = 0x80110000,

	//! The certificate provided as a parameter is not valid.
	EnumStatusCode_BadCertificateInvalid = 0x80120000,

	//! An error occurred verifying security.
	EnumStatusCode_BadSecurityChecksFailed = 0x80130000,

	//! The certificate has expired or is not yet valid.
	EnumStatusCode_BadCertificateTimeInvalid = 0x80140000,

	//! An issuer certificate has expired or is not yet valid.
	EnumStatusCode_BadCertificateIssuerTimeInvalid = 0x80150000,

	//! The HostName used to connect to a Server does not match a HostName in the certificate.
	EnumStatusCode_BadCertificateHostNameInvalid = 0x80160000,

	//! The URI specified in the ApplicationDescription does not match the URI in the certificate.
	EnumStatusCode_BadCertificateUriInvalid = 0x80170000,

	//! The certificate may not be used for the requested operation.
	EnumStatusCode_BadCertificateUseNotAllowed = 0x80180000,

	//! The issuer certificate may not be used for the requested operation.
	EnumStatusCode_BadCertificateIssuerUseNotAllowed = 0x80190000,

	//! The certificate is not trusted.
	EnumStatusCode_BadCertificateUntrusted = 0x801A0000,

	//! It was not possible to determine if the certificate has been revoked.
	EnumStatusCode_BadCertificateRevocationUnknown = 0x801B0000,

	//! It was not possible to determine if the issuer certificate has been revoked.
	EnumStatusCode_BadCertificateIssuerRevocationUnknown = 0x801C0000,

	//! The certificate has been revoked.
	EnumStatusCode_BadCertificateRevoked = 0x801D0000,

	//! The issuer certificate has been revoked.
	EnumStatusCode_BadCertificateIssuerRevoked = 0x801E0000,

	//! User does not have permission to perform the requested operation.
	EnumStatusCode_BadUserAccessDenied = 0x801F0000,

	//! The user identity token is not valid.
	EnumStatusCode_BadIdentityTokenInvalid = 0x80200000,

	//! The user identity token is valid but the server has rejected it.
	EnumStatusCode_BadIdentityTokenRejected = 0x80210000,

	//! The specified secure channel is no longer valid.
	EnumStatusCode_BadSecureChannelIdInvalid = 0x80220000,

	//! The timestamp is outside the range allowed by the server.
	EnumStatusCode_BadInvalidTimestamp = 0x80230000,

	//! The nonce does appear to be not a random value or it is not the correct length.
	EnumStatusCode_BadNonceInvalid = 0x80240000,

	//! The session id is not valid.
	EnumStatusCode_BadSessionIdInvalid = 0x80250000,

	//! The session was closed by the client.
	EnumStatusCode_BadSessionClosed = 0x80260000,

	//! The session cannot be used because ActivateSession has not been called.
	EnumStatusCode_BadSessionNotActivated = 0x80270000,

	//! The subscription id is not valid.
	EnumStatusCode_BadSubscriptionIdInvalid = 0x80280000,

	//! The header for the request is missing or invalid.
	EnumStatusCode_BadRequestHeaderInvalid = 0x802A0000,

	//! The timestamps to return parameter is invalid.
	EnumStatusCode_BadTimestampsToReturnInvalid = 0x802B0000,

	//! The request was cancelled by the client.
	EnumStatusCode_BadRequestCancelledByClient = 0x802C0000,

	//! Communication with the data source is defined, but not established, and there is no last known value available.
	EnumStatusCode_BadNoCommunication = 0x80310000,

	//! Waiting for the server to obtain values from the underlying data source.
	EnumStatusCode_BadWaitingForInitialData = 0x80320000,

	//! The syntax of the node id is not valid.
	EnumStatusCode_BadNodeIdInvalid = 0x80330000,

	//! The node id refers to a node that does not exist in the server address space.
	EnumStatusCode_BadNodeIdUnknown = 0x80340000,

	//! The attribute is not supported for the specified Node.
	EnumStatusCode_BadAttributeIdInvalid = 0x80350000,

	//! The syntax of the index range parameter is invalid.
	EnumStatusCode_BadIndexRangeInvalid = 0x80360000,

	//! No data exists within the range of indexes specified.
	EnumStatusCode_BadIndexRangeNoData = 0x80370000,

	//! The data encoding is invalid.
	EnumStatusCode_BadDataEncodingInvalid = 0x80380000,

	//! The server does not support the requested data encoding for the node.
	EnumStatusCode_BadDataEncodingUnsupported = 0x80390000,

	//! The access level does not allow reading or subscribing to the Node.
	EnumStatusCode_BadNotReadable = 0x803A0000,

	//! The access level does not allow writing to the Node.
	EnumStatusCode_BadNotWritable = 0x803B0000,

	//! The value was out of range.
	EnumStatusCode_BadOutOfRange = 0x803C0000,

	//! The requested operation is not supported.
	EnumStatusCode_BadNotSupported = 0x803D0000,

	//! A requested item was not found or a search operation ended without success.
	EnumStatusCode_BadNotFound = 0x803E0000,

	//! The object cannot be used because it has been deleted.
	EnumStatusCode_BadObjectDeleted = 0x803F0000,

	//! Requested operation is not implemented.
	EnumStatusCode_BadNotImplemented = 0x80400000,

	//! The monitoring mode is invalid.
	EnumStatusCode_BadMonitoringModeInvalid = 0x80410000,

	//! The monitoring item id does not refer to a valid monitored item.
	EnumStatusCode_BadMonitoredItemIdInvalid = 0x80420000,

	//! The monitored item filter parameter is not valid.
	EnumStatusCode_BadMonitoredItemFilterInvalid = 0x80430000,

	//! The server does not support the requested monitored item filter.
	EnumStatusCode_BadMonitoredItemFilterUnsupported = 0x80440000,

	//! A monitoring filter cannot be used in combination with the attribute specified.
	EnumStatusCode_BadFilterNotAllowed = 0x80450000,

	//! A mandatory structured parameter was missing or null.
	EnumStatusCode_BadStructureMissing = 0x80460000,

	//! The event filter is not valid.
	EnumStatusCode_BadEventFilterInvalid = 0x80470000,

	//! The content filter is not valid.
	EnumStatusCode_BadContentFilterInvalid = 0x80480000,

	//! The operand used in a content filter is not valid.
	EnumStatusCode_BadFilterOperandInvalid = 0x80490000,

	//! The continuation point provide is longer valid.
	EnumStatusCode_BadContinuationPointInvalid = 0x804A0000,

	//! The operation could not be processed because all continuation points have been allocated.
	EnumStatusCode_BadNoContinuationPoints = 0x804B0000,

	//! The reference type id does not refer to a valid reference type node.
	EnumStatusCode_BadReferenceTypeIdInvalid = 0x804C0000,

	//! The browse direction is not valid.
	EnumStatusCode_BadBrowseDirectionInvalid = 0x804D0000,

	//! The node is not part of the view.
	EnumStatusCode_BadNodeNotInView = 0x804E0000,

	//! The ServerUri is not a valid URI.
	EnumStatusCode_BadServerUriInvalid = 0x804F0000,

	//! No ServerName was specified.
	EnumStatusCode_BadServerNameMissing = 0x80500000,

	//! No DiscoveryUrl was specified.
	EnumStatusCode_BadDiscoveryUrlMissing = 0x80510000,

	//! The semaphore file specified by the client is not valid.
	EnumStatusCode_BadSempahoreFileMissing = 0x80520000,

	//! The security token request type is not valid.
	EnumStatusCode_BadRequestTypeInvalid = 0x80530000,

	//! The security mode does not meet the requirements set by the Server.
	EnumStatusCode_BadSecurityModeRejected = 0x80540000,

	//! The security policy does not meet the requirements set by the Server.
	EnumStatusCode_BadSecurityPolicyRejected = 0x80550000,

	//! The server has reached its maximum number of sessions.
	EnumStatusCode_BadTooManySessions = 0x80560000,

	//! The user token signature is missing or invalid.
	EnumStatusCode_BadUserSignatureInvalid = 0x80570000,

	//! The signature generated with the client certificate is missing or invalid.
	EnumStatusCode_BadApplicationSignatureInvalid = 0x80580000,

	//! The client did not provide at least one software certificate that is valid and meets the profile requirements for the server.
	EnumStatusCode_BadNoValidCertificates = 0x80590000,

	//! The request was cancelled by the client with the Cancel service.
	EnumStatusCode_BadRequestCancelledByRequest = 0x805A0000,

	//! The parent node id does not to refer to a valid node.
	EnumStatusCode_BadParentNodeIdInvalid = 0x805B0000,

	//! The reference could not be created because it violates constraints imposed by the data model.
	EnumStatusCode_BadReferenceNotAllowed = 0x805C0000,

	//! The requested node id was reject because it was either invalid or server does not allow node ids to be specified by the client.
	EnumStatusCode_BadNodeIdRejected = 0x805D0000,

	//! The requested node id is already used by another node.
	EnumStatusCode_BadNodeIdExists = 0x805E0000,

	//! The node class is not valid.
	EnumStatusCode_BadNodeClassInvalid = 0x805F0000,

	//! The browse name is invalid.
	EnumStatusCode_BadBrowseNameInvalid = 0x80600000,

	//! The browse name is not unique among nodes that share the same relationship with the parent.
	EnumStatusCode_BadBrowseNameDuplicated = 0x80610000,

	//! The node attributes are not valid for the node class.
	EnumStatusCode_BadNodeAttributesInvalid = 0x80620000,

	//! The type definition node id does not reference an appropriate type node.
	EnumStatusCode_BadTypeDefinitionInvalid = 0x80630000,

	//! The source node id does not reference a valid node.
	EnumStatusCode_BadSourceNodeIdInvalid = 0x80640000,

	//! The target node id does not reference a valid node.
	EnumStatusCode_BadTargetNodeIdInvalid = 0x80650000,

	//! The reference type between the nodes is already defined.
	EnumStatusCode_BadDuplicateReferenceNotAllowed = 0x80660000,

	//! The server does not allow this type of self reference on this node.
	EnumStatusCode_BadInvalidSelfReference = 0x80670000,

	//! The reference type is not valid for a reference to a remote server.
	EnumStatusCode_BadReferenceLocalOnly = 0x80680000,

	//! The server will not allow the node to be deleted.
	EnumStatusCode_BadNoDeleteRights = 0x80690000,

	//! The server index is not valid.
	EnumStatusCode_BadServerIndexInvalid = 0x806A0000,

	//! The view id does not refer to a valid view node.
	EnumStatusCode_BadViewIdUnknown = 0x806B0000,

	//! The requested operation has too many matches to return.
	EnumStatusCode_BadTooManyMatches = 0x806D0000,

	//! The requested operation requires too many resources in the server.
	EnumStatusCode_BadQueryTooComplex = 0x806E0000,

	//! The requested operation has no match to return.
	EnumStatusCode_BadNoMatch = 0x806F0000,

	//! The max age parameter is invalid.
	EnumStatusCode_BadMaxAgeInvalid = 0x80700000,

	//! The history details parameter is not valid.
	EnumStatusCode_BadHistoryOperationInvalid = 0x80710000,

	//! The server does not support the requested operation.
	EnumStatusCode_BadHistoryOperationUnsupported = 0x80720000,

	//! The server not does support writing the combination of value, status and timestamps provided.
	EnumStatusCode_BadWriteNotSupported = 0x80730000,

	//! The value supplied for the attribute is not of the same type as the attribute's value.
	EnumStatusCode_BadTypeMismatch = 0x80740000,

	//! The method id does not refer to a method for the specified object.
	EnumStatusCode_BadMethodInvalid = 0x80750000,

	//! The client did not specify all of the input arguments for the method.
	EnumStatusCode_BadArgumentsMissing = 0x80760000,

	//! The server has reached its maximum number of subscriptions.
	EnumStatusCode_BadTooManySubscriptions = 0x80770000,

	//! The server has reached the maximum number of queued publish requests.
	EnumStatusCode_BadTooManyPublishRequests = 0x80780000,

	//! There is no subscription available for this session.
	EnumStatusCode_BadNoSubscription = 0x80790000,

	//! The sequence number is unknown to the server.
	EnumStatusCode_BadSequenceNumberUnknown = 0x807A0000,

	//! The requested notification message is no longer available.
	EnumStatusCode_BadMessageNotAvailable = 0x807B0000,

	//! The client of the current session does not support one or more Profiles that are necessary for the subscription.
	EnumStatusCode_BadInsufficientClientProfile = 0x807C0000,

	//! The server cannot process the request because it is too busy.
	EnumStatusCode_BadTcpServerTooBusy = 0x807D0000,

	//! The type of the message specified in the header invalid.
	EnumStatusCode_BadTcpMessageTypeInvalid = 0x807E0000,

	//! The SecureChannelId and/or TokenId are not currently in use.
	EnumStatusCode_BadTcpSecureChannelUnknown = 0x807F0000,

	//! The size of the message specified in the header is too large.
	EnumStatusCode_BadTcpMessageTooLarge = 0x80800000,

	//! There are not enough resources to process the request.
	EnumStatusCode_BadTcpNotEnoughResources = 0x80810000,

	//! An internal error occurred.
	EnumStatusCode_BadTcpInternalError = 0x80820000,

	//! The Server does not recognize the QueryString specified.
	EnumStatusCode_BadTcpEndpointUrlInvalid = 0x80830000,

	//! The request could not be sent because of a network interruption.
	EnumStatusCode_BadRequestInterrupted = 0x80840000,

	//! Timeout occurred while processing the request.
	EnumStatusCode_BadRequestTimeout = 0x80850000,

	//! The secure channel has been closed.
	EnumStatusCode_BadSecureChannelClosed = 0x80860000,

	//! The token has expired or is not recognized.
	EnumStatusCode_BadSecureChannelTokenUnknown = 0x80870000,

	//! The sequence number is not valid.
	EnumStatusCode_BadSequenceNumberInvalid = 0x80880000,

	//! There is a problem with the configuration that affects the usefulness of the value.
	EnumStatusCode_BadConfigurationError = 0x80890000,

	//! The variable should receive its value from another variable, but has never been configured to do so.
	EnumStatusCode_BadNotConnected = 0x808A0000,

	//! There has been a failure in the device/data source that generates the value that has affected the value.
	EnumStatusCode_BadDeviceFailure = 0x808B0000,

	//! There has been a failure in the sensor from which the value is derived by the device/data source.
	EnumStatusCode_BadSensorFailure = 0x808C0000,

	//! The source of the data is not operational.
	EnumStatusCode_BadOutOfService = 0x808D0000,

	//! The deadband filter is not valid.
	EnumStatusCode_BadDeadbandFilterInvalid = 0x808E0000,

	//! This Condition refresh failed, a Condition refresh operation is already in progress.
	EnumStatusCode_BadRefreshInProgress = 0x80970000,

	//! This condition has already been disabled.
	EnumStatusCode_BadConditionAlreadyDisabled = 0x80980000,

	//! Property not available, this condition is disabled.
	EnumStatusCode_BadConditionDisabled = 0x80990000,

	//! The specified event id is not recognized.
	EnumStatusCode_BadEventIdUnknown = 0x809A0000,

	//! No data exists for the requested time range or event filter.
	EnumStatusCode_BadNoData = 0x809B0000,

	//! Data is missing due to collection started/stopped/lost.
	EnumStatusCode_BadDataLost = 0x809D0000,

	//! Expected data is unavailable for the requested time range due to an un-mounted volume, an off-line archive or tape, or similar reason for temporary unavailability.
	EnumStatusCode_BadDataUnavailable = 0x809E0000,

	//! The data or event was not successfully inserted because a matching entry exists.
	EnumStatusCode_BadEntryExists = 0x809F0000,

	//! The data or event was not successfully updated because no matching entry exists.
	EnumStatusCode_BadNoEntryExists = 0x80A00000,

	//! The client requested history using a timestamp format the server does not support (i.e requested ServerTimestamp when server only supports SourceTimestamp).
	EnumStatusCode_BadTimestampNotSupported = 0x80A10000,

	//! One or more arguments are invalid.
	EnumStatusCode_BadInvalidArgument = 0x80AB0000,

	//! Could not establish a network connection to remote server.
	EnumStatusCode_BadConnectionRejected = 0x80AC0000,

	//! The server has disconnected from the client.
	EnumStatusCode_BadDisconnect = 0x80AD0000,

	//! The network connection has been closed.
	EnumStatusCode_BadConnectionClosed = 0x80AE0000,

	//! The operation cannot be completed because the object is closed, uninitialized or in some other invalid state.
	EnumStatusCode_BadInvalidState = 0x80AF0000,

	//! Cannot move beyond end of the stream.
	EnumStatusCode_BadEndOfStream = 0x80B00000,

	//! No data is currently available for reading from a non-blocking stream.
	EnumStatusCode_BadNoDataAvailable = 0x80B10000,

	//! The asynchronous operation is waiting for a response.
	EnumStatusCode_BadWaitingForResponse = 0x80B20000,

	//! The asynchronous operation was abandoned by the caller.
	EnumStatusCode_BadOperationAbandoned = 0x80B30000,

	//! The stream did not return all data requested (possibly because it is a non-blocking stream).
	EnumStatusCode_BadExpectedStreamToBlock = 0x80B40000,

	//! Non blocking behavior is required and the operation would block.
	EnumStatusCode_BadWouldBlock = 0x80B50000,

	//! A value had an invalid syntax.
	EnumStatusCode_BadSyntaxError = 0x80B60000,

	//! The operation could not be finished because all available connections are in use.
	EnumStatusCode_BadMaxConnectionsReached = 0x80B70000,

	//! The request message size exceeds limits set by the server.
	EnumStatusCode_BadRequestTooLarge = 0x80B80000,

	//! The response message size exceeds limits set by the client.
	EnumStatusCode_BadResponseTooLarge = 0x80B90000,

	//! The event cannot be acknowledged.
	EnumStatusCode_BadEventNotAcknowledgeable = 0x80BB0000,

	//! The defined timestamp to return was invalid.
	EnumStatusCode_BadInvalidTimestampArgument = 0x80BD0000,

	//! The applications do not have compatible protocol versions.
	EnumStatusCode_BadProtocolVersionUnsupported = 0x80BE0000,

	//! The sub-state machine is not currently active.
	EnumStatusCode_BadStateNotActive = 0x80BF0000,

	//! An unrecognized operator was provided in a filter.
	EnumStatusCode_BadFilterOperatorInvalid = 0x80C10000,

	//! A valid operator was provided, but the server does not provide support for this filter operator.
	EnumStatusCode_BadFilterOperatorUnsupported = 0x80C20000,

	//! The number of operands provided for the filter operator was less then expected for the operand provided.
	EnumStatusCode_BadFilterOperandCountMismatch = 0x80C30000,

	//! The referenced element is not a valid element in the content filter.
	EnumStatusCode_BadFilterElementInvalid = 0x80C40000,

	//! The referenced literal is not a valid value.
	EnumStatusCode_BadFilterLiteralInvalid = 0x80C50000,

	//! The Server does not support changing the user identity assigned to the session.
	EnumStatusCode_BadIdentityChangeNotSupported = 0x80C60000,

	//! The provided Nodeid was not a type definition nodeid.
	EnumStatusCode_BadNotTypeDefinition = 0x80C80000,

	//! The view timestamp is not available or not supported.
	EnumStatusCode_BadViewTimestampInvalid = 0x80C90000,

	//! The view parameters are not consistent with each other.
	EnumStatusCode_BadViewParameterMismatch = 0x80CA0000,

	//! The view version is not available or not supported.
	EnumStatusCode_BadViewVersionInvalid = 0x80CB0000,

	//! This condition has already been enabled.
	EnumStatusCode_BadConditionAlreadyEnabled = 0x80CC0000,

	//! The dialog condition is not active.
	EnumStatusCode_BadDialogNotActive = 0x80CD0000,

	//! The response is not valid for the dialog.
	EnumStatusCode_BadDialogResponseInvalid = 0x80CE0000,

	//! The condition branch has already been acknowledged.
	EnumStatusCode_BadConditionBranchAlreadyAcked = 0x80CF0000,

	//! The condition branch has already been confirmed.
	EnumStatusCode_BadConditionBranchAlreadyConfirmed = 0x80D00000,

	//! The condition has already been shelved.
	EnumStatusCode_BadConditionAlreadyShelved = 0x80D10000,

	//! The condition is not currently shelved.
	EnumStatusCode_BadConditionNotShelved = 0x80D20000,

	//! The shelving time not within an acceptable range.
	EnumStatusCode_BadShelvingTimeOutOfRange = 0x80D30000,

	//! The requested number of Aggregates does not match the requested number of NodeIds.
	EnumStatusCode_BadAggregateListMismatch = 0x80D40000,

	//! The requested Aggregate is not support by the server.
	EnumStatusCode_BadAggregateNotSupported = 0x80D50000,

	//! The aggregate value could not be derived due to invalid data inputs.
	EnumStatusCode_BadAggregateInvalidInputs = 0x80D60000,

	//! No data found to provide upper or lower bound value.
	EnumStatusCode_BadBoundNotFound = 0x80D70000,

	//! The server cannot retrieve a bound for the variable.
	EnumStatusCode_BadBoundNotSupported = 0x80D80000,

	//! The aggregate configuration is not valid for specified node.
	EnumStatusCode_BadAggregateConfigurationRejected = 0x80DA0000,

	//! The request could not be processed because there are too many monitored items in the subscription.
	EnumStatusCode_BadTooManyMonitoredItems = 0x80DB0000,

	//! The request was rejected by the server because it did not meet the criteria set by the server.
	EnumStatusCode_BadRequestNotAllowed = 0x80E40000,

	//! Too many arguments were provided.
	EnumStatusCode_BadTooManyArguments = 0x80E50000,

	//! The operation is not permitted over the current secure channel.
	EnumStatusCode_BadSecurityModeInsufficient = 0x80E60000,

	//! BadStartOfStackStatusCodes
	EnumStatusCode_BadStartOfStackStatusCodes = 0x81000000,

	//! BadSignatureInvalid
	EnumStatusCode_BadSignatureInvalid = 0x81010000,

	//! BadExtensibleParameterInvalid
	EnumStatusCode_BadExtensibleParameterInvalid = 0x81040000,

	//! BadExtensibleParameterUnsupported
	EnumStatusCode_BadExtensibleParameterUnsupported = 0x81050000,

	//! BadHostUnknown
	EnumStatusCode_BadHostUnknown = 0x81060000,

	//! BadTooManyPosts
	EnumStatusCode_BadTooManyPosts = 0x81070000,

	//! BadSecurityConfig
	EnumStatusCode_BadSecurityConfig = 0x81080000,

	//! BadFileNotFound
	EnumStatusCode_BadFileNotFound = 0x81090000,

	//! BadContinue
	EnumStatusCode_BadContinue = 0x810A0000,

	//! BadHttpMethodNotAllowed
	EnumStatusCode_BadHttpMethodNotAllowed = 0x810B0000,

	//! BadFileExists
	EnumStatusCode_BadFileExists = 0x810C0000,

	//! The certificate chain is incomplete.
	EnumStatusCode_BadCertificateChainIncomplete = 0x810D0000,

	//! The UA Server requires a license to operate in general or to perform a service or operation, but existing license is expired.
	EnumStatusCode_BadLicenseExpired = 0x810E0000,

	//! The UA Server has limits on number of allowed operations / objects, based on installed licenses, and these limits where exceeded.
	EnumStatusCode_BadLicenseLimitsExceeded = 0x810F0000,

	//! The UA Server does not have a license which is required to operate in general or to perform a service or operation.
	EnumStatusCode_BadLicenseNotAvailable = 0x81100000

} EnumStatusCode; // end EnumStatusCode;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumStatusCodeString(EnumStatusCode value);
EnumStatusCode OTGetEnumStatusCodeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumStatusCodeString(EnumStatusCode value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumStatusCode getEnumStatusCodeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration defining the timestamps which have to be returned on different client services.
typedef enum tagEnumTimestampsToReturn // Declaration of enum EnumTimestampsToReturn
{
	//! Return the source timestamp.
	//! If used in HistoryRead ('raw' or 'processed'), the source timestamp is used to determine which historical data values are returned.
	EnumTimestampsToReturn_Source = 0x00,

	//! Return the server timestamp.
	//! If used in HistoryRead ('raw' or 'processed'), the server timestamp is used to determine which historical data values are returned.
	EnumTimestampsToReturn_Server = 0x01,

	//! Return both the source and the server timestamp.
	//! If used in HistoryRead ('raw' or 'processed'), the source timestamp is used to determine which historical data values are returned.
	EnumTimestampsToReturn_Both = 0x02,

	//! This is the default value for monitored items if a variable value is not being accessed. For HistoryRead
	//! service calls this is not a valid setting.
	EnumTimestampsToReturn_Neither = 0x03,

	//! this is not a valid setting.
	EnumTimestampsToReturn_Invalid = 0x04
}
EnumTimestampsToReturn; // end EnumTimestampsToReturn;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumTimestampsToReturnString(EnumTimestampsToReturn value);
EnumTimestampsToReturn OTGetEnumTimestampsToReturnFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumTimestampsToReturnString(EnumTimestampsToReturn value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumTimestampsToReturn getEnumTimestampsToReturnFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Defines the trace groups available in the Toolkit
typedef OTUInt32 EnumTraceGroup;

//! This trace group reports no traces
static const EnumTraceGroup EnumTraceGroup_None = 0x00;
//! This trace group reports traces from the Toolkit's core
static const EnumTraceGroup EnumTraceGroup_Core = 0x01;
//! This trace group reports traces from the Toolkit's C++ API
static const EnumTraceGroup EnumTraceGroup_Api = 0x02;
//! This trace group reports traces from the underlying OPC UA communication stack
static const EnumTraceGroup EnumTraceGroup_Stack = 0x04;
//! This trace group is currently unused
static const EnumTraceGroup EnumTraceGroup_DiagnosticInformation = 0x08;
//! This trace group is currently unused
static const EnumTraceGroup EnumTraceGroup_Statistics = 0x10;
//! This trace group may be used by applications for their own purposes
static const EnumTraceGroup EnumTraceGroup_User1 = 0x100;
//! This trace group may be used by applications for their own purposes
static const EnumTraceGroup EnumTraceGroup_User2 = 0x200;
//! This trace group may be used by applications for their own purposes
static const EnumTraceGroup EnumTraceGroup_User3 = 0x400;
//! This trace group may be used by applications for their own purposes
static const EnumTraceGroup EnumTraceGroup_User4 = 0x800;
//! This trace group reports traces from node set import, node set export and address space manipulation by the model designer
static const EnumTraceGroup EnumTraceGroup_ModelDesigner = 0x1000;
//! This bit mask can be used to select all available trace groups
static const EnumTraceGroup EnumTraceGroup_All = 0xFFFF;
////////////////////////////////////////////////////////////////////////////////

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumTraceGroupString(EnumTraceGroup value);
EnumTraceGroup OTGetEnumTraceGroupFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumTraceGroupString(EnumTraceGroup value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumTraceGroup getEnumTraceGroupFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Bit coded enumeration for tracing adjustments (see single values and related functions).
//! Each trace message has a level assigned to it to allow filtering on different levels.
typedef enum tagEnumTraceLevel // Declaration of enum EnumTraceLevel
{
	//! No trace messages will be dumped.
	EnumTraceLevel_None = 0x00,

	//! If set trace messages with an Debug level will be dumped.
	EnumTraceLevel_Debug = 0x01,

	//! If set trace messages with an Info level will be dumped.
	EnumTraceLevel_Info = 0x02,

	//! If set trace messages with an Warning level will be dumped.
	EnumTraceLevel_Warning = 0x04,

	//! If set trace messages with an Error level will be dumped.
	EnumTraceLevel_Error = 0x08,

	//! If set trace messages with an Fatal level will be dumped.
	EnumTraceLevel_Fatal = 0x10,

	//! If set trace messages with an ErrorAndHigher or a higher level will be dumped.
	EnumTraceLevel_ErrorAndHigher = 0x18,

	//! If set trace messages with an WarningAndHigher or a higher level will be dumped.
	EnumTraceLevel_WarningAndHigher = 0x1C,

	//! If set trace messages with an InfoAndHigher or a higher level will be dumped.
	EnumTraceLevel_InfoAndHigher = 0x1E,

	//! If set any trace message will be dumped to the trace.
	EnumTraceLevel_All = 0x1F
}
EnumTraceLevel; // end EnumTraceLevel;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumTraceLevelString(EnumTraceLevel value);
EnumTraceLevel OTGetEnumTraceLevelFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumTraceLevelString(EnumTraceLevel value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumTraceLevel getEnumTraceLevelFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration of different user authentication types. @see IUserTokenPolicy
typedef enum tagEnumUserTokenType // Declaration of enum EnumUserTokenType
{
	//! No authentication. The user is anonymous.
	EnumUserTokenType_Anonymous = 0,

	//! Authentication via user name and password.
	EnumUserTokenType_UserName = 1,

	//! Authentication via user specific certificates.
	EnumUserTokenType_Certificate = 2,

	//! Authentication via issued token.
	EnumUserTokenType_IssuedToken = 3
}
EnumUserTokenType; // end EnumUserTokenType;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumUserTokenTypeString(EnumUserTokenType value);
EnumUserTokenType OTGetEnumUserTokenTypeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumUserTokenTypeString(EnumUserTokenType value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumUserTokenType getEnumUserTokenTypeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Defines the value rank of a variable (see SoftingOPCToolbox5::Server::Variable::setValueRank).

//! Indicates that the variable contains an array value of one or more dimensions
static const OTInt32 ValueRank_OneOrMoreDimensions = 0;
//! Indicates that the variable contains a scalar value
static const OTInt32 ValueRank_Scalar = -1;
//! Indicates that the variable contains any value, scalar or array of any dimension
static const OTInt32 ValueRank_Any = -2;
//! Indicates that the variable contains a value of scalar or one dimensional array
static const OTInt32 ValueRank_ScalarOrOneDimension = -3;


////////////////////////////////////////////////////////////////////////////////
//! Defines the array type of a value contained in a variant (see SoftingOPCToolbox5::Value).
typedef OTUInt8 EnumValueArrayType;

//! Indicates that the variant contains a scalar value
static const EnumValueArrayType EnumValueArrayType_Scalar = 0x00;
//! Indicates that the variant contains an array value
static const EnumValueArrayType EnumValueArrayType_Array = 0x01;
//! Indicates that the variant contains a matrix value
static const EnumValueArrayType EnumValueArrayType_Matrix = 0x02;

#ifdef OT_V510_TYPE_COMPATIBILITY
//! @deprecated Please use EnumValueArrayType_Scalar instead
static const OTUInt8 OTValueArrayType_Scalar		= EnumValueArrayType_Scalar;
//! @deprecated Please use EnumValueArrayType_Scalar instead
static const OTUInt8 SOCmnValueArrayType_Scalar		= EnumValueArrayType_Scalar;
//! @deprecated Please use EnumValueArrayType_Scalar instead
static const OTUInt8 ValueArrayType_Scalar			= EnumValueArrayType_Scalar;
//! @deprecated Please use EnumValueArrayType_Array instead
static const OTUInt8 OTValueArrayType_Array			= EnumValueArrayType_Array;
//! @deprecated Please use EnumValueArrayType_Array instead
static const OTUInt8 SOCmnValueArrayType_Array		= EnumValueArrayType_Array;
//! @deprecated Please use EnumValueArrayType_Array instead
static const OTUInt8 ValueArrayType_Array			= EnumValueArrayType_Array;
//! @deprecated Please use EnumValueArrayType_Matrix instead
static const OTUInt8 OTValueArrayType_Matrix		= EnumValueArrayType_Matrix;
//! @deprecated Please use EnumValueArrayType_Matrix instead
static const OTUInt8 SOCmnValueArrayType_Matrix		= EnumValueArrayType_Matrix;
//! @deprecated Please use EnumValueArrayType_Matrix instead
static const OTUInt8 ValueArrayType_Matrix			= EnumValueArrayType_Matrix;
#endif

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumValueArrayTypeString(EnumValueArrayType value);
EnumValueArrayType OTGetEnumValueArrayTypeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumValueArrayTypeString(EnumValueArrayType value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumValueArrayType getEnumValueArrayTypeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Defines the Open Files Modes
typedef OTUInt32 EnumOpenFileMode;

//! File mode read
static const EnumOpenFileMode EnumOpenFileMode_Read = 0x01;
//! File mode write
static const EnumOpenFileMode EnumOpenFileMode_Write = 0x02;
//! File mode eraseExisting
static const EnumOpenFileMode EnumOpenFileMode_EraseExisting = 0x04;
//! File mode append
static const EnumOpenFileMode EnumOpenFileMode_Append = 0x08;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumOpenFileModeString(EnumOpenFileMode value);
EnumOpenFileMode OTGetEnumOpenFileModeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumOpenFileModeString(EnumOpenFileMode value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumOpenFileMode getEnumOpenFileModeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Defines the Open Files Modes
typedef OTUInt32 EnumTrustListMasks;

//! Trust list mask none
static const EnumTrustListMasks EnumTrustListMasks_None = 0x00;
//! Trust list mask TrustedCertificates
static const EnumTrustListMasks EnumTrustListMasks_TrustedCertificates = 0x01;
//! Trust list mask TrustedCrls
static const EnumTrustListMasks EnumTrustListMasks_TrustedCrls = 0x02;
//! Trust list mask IssuerCertificates
static const EnumTrustListMasks EnumTrustListMasks_IssuerCertificates = 0x04;
//! Trust list mask IssuerCrls
static const EnumTrustListMasks EnumTrustListMasks_IssuerCrls = 0x08;
//! Trust list mask All
static const EnumTrustListMasks EnumTrustListMasks_All = 0x0F;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumTrustListMasksString(EnumTrustListMasks value);
EnumTrustListMasks OTGetEnumTrustListMasksFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumTrustListMasksString(EnumTrustListMasks value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumTrustListMasks getEnumTrustListMasksFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Defines the Open Files Modes
typedef enum tagEnumAxisScaleEnumeration // Declaration of enum EnumUserTokenType
{
//! Axis Scale Linear
	EnumAxisScaleEnumeration_Linear = 0,
//! Axis Scale Logarithm Base 10
	EnumAxisScaleEnumeration_Log = 1,
//! Axis Scale Logarithm naturalis
	EnumAxisScaleEnumeration_Ln = 2
} EnumAxisScaleEnumeration; // end EnumAxisScaleEnumeration

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumAxisScaleEnumerationString(EnumAxisScaleEnumeration value);
EnumAxisScaleEnumeration OTGetEnumAxisScaleEnumerationFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumAxisScaleEnumerationString(EnumAxisScaleEnumeration value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumAxisScaleEnumeration getEnumAxisScaleEnumerationFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! The OPC standard specifies a number of nodeIds which are for standardized nodes (used all in the reserved
//! namespace 0).
//! These nodeIds are collected in this enumeration, the single members are not listed in the documentation
//! (refer to the UA specification).
typedef enum tagEnumNumericNodeId // Declaration of enum EnumNumericNodeId
{
	//! no valid NodeId.
	EnumNumericNodeId_Null = 0,
	//! NodeId of the data type Boolean.
	EnumNumericNodeId_Boolean = 1,
	//! NodeId of the data type SByte.
	EnumNumericNodeId_SByte = 2,
	//! NodeId of the data type Byte.
	EnumNumericNodeId_Byte = 3,
	//! NodeId of the data type Int16.
	EnumNumericNodeId_Int16 = 4,
	//! NodeId of the data type UInt16.
	EnumNumericNodeId_UInt16 = 5,
	//! NodeId of the data type Int32.
	EnumNumericNodeId_Int32 = 6,
	//! NodeId of the data type UInt32.
	EnumNumericNodeId_UInt32 = 7,
	//! NodeId of the data type Int64.
	EnumNumericNodeId_Int64 = 8,
	//! NodeId of the data type UInt64.
	EnumNumericNodeId_UInt64 = 9,
	//! NodeId of the data type Float.
	EnumNumericNodeId_Float = 10,
	//! NodeId of the data type Double.
	EnumNumericNodeId_Double = 11,
	//! NodeId of the data type String.
	EnumNumericNodeId_String = 12,
	//! NodeId of the data type DateTime.
	EnumNumericNodeId_DateTime = 13,
	//! NodeId of the data type Guid.
	EnumNumericNodeId_Guid = 14,
	//! NodeId of the data type ByteString.
	EnumNumericNodeId_ByteString = 15,
	//! NodeId of the data type XmlElement.
	EnumNumericNodeId_XmlElement = 16,
	//! NodeId of the data type NodeId.
	EnumNumericNodeId_NodeId = 17,
	//! NodeId of the data type ExpandedNodeId.
	EnumNumericNodeId_ExpandedNodeId = 18,
	//! NodeId of the data type StatusCode.
	EnumNumericNodeId_StatusCode = 19,
	//! NodeId of the data type QualifiedName.
	EnumNumericNodeId_QualifiedName = 20,
	//! NodeId of the data type LocalizedText.
	EnumNumericNodeId_LocalizedText = 21,
	//! NodeId of the abstract data type Structure.
	EnumNumericNodeId_Structure = 22,
	//! NodeId of the data type DataValue.
	EnumNumericNodeId_DataValue = 23,
	//! NodeId of the abstract data type BaseDataType.
	EnumNumericNodeId_BaseDataType = 24,
	//! NodeId of the data type DiagnosticInfo.
	EnumNumericNodeId_DiagnosticInfo = 25,
	//! NodeId of the abstract data type Number.
	EnumNumericNodeId_Number = 26,
	//! NodeId of the abstract data type Integer.
	EnumNumericNodeId_Integer = 27,
	//! NodeId of the abstract data type UInteger.
	EnumNumericNodeId_UInteger = 28,
	//! NodeId of the abstract data type Enumeration.
	EnumNumericNodeId_Enumeration = 29,
	//! NodeId of the data type Image.
	EnumNumericNodeId_Image = 30,
	//! NodeId of the abstract reference type References.
	EnumNumericNodeId_References = 31,
	//! NodeId of the abstract reference type NonHierarchicalReferences.
	EnumNumericNodeId_NonHierarchicalReferences = 32,
	//! NodeId of the abstract reference type HierarchicalReferences.
	EnumNumericNodeId_HierarchicalReferences = 33,
	//! NodeId of the reference type HasChild.
	EnumNumericNodeId_HasChild = 34,
	//! NodeId of the reference type Organizes.
	EnumNumericNodeId_Organizes = 35,
	//! NodeId of the reference type HasEventSource.
	EnumNumericNodeId_HasEventSource = 36,
	//! NodeId of the reference type HasModellingRule.
	EnumNumericNodeId_HasModellingRule = 37,
	//! NodeId of the reference type HasEncoding.
	EnumNumericNodeId_HasEncoding = 38,
	//! NodeId of the reference type HasDescription.
	EnumNumericNodeId_HasDescription = 39,
	//! NodeId of the reference type HasTypeDefinition.
	EnumNumericNodeId_HasTypeDefinition = 40,
	//! NodeId of the reference type GeneratesEvent.
	EnumNumericNodeId_GeneratesEvent = 41,
	//! NodeId of the reference type Aggregates.
	EnumNumericNodeId_Aggregates = 44,
	//! NodeId of the reference type HasSubtype.
	EnumNumericNodeId_HasSubtype = 45,
	//! NodeId of the reference type HasProperty.
	EnumNumericNodeId_HasProperty = 46,
	//! NodeId of the reference type HasComponent.
	EnumNumericNodeId_HasComponent = 47,
	//! NodeId of the reference type HasNotifier.
	EnumNumericNodeId_HasNotifier = 48,
	//! NodeId of the reference type HasOrderedComponent.
	EnumNumericNodeId_HasOrderedComponent = 49,
	//! NodeId of the reference type FromState.
	EnumNumericNodeId_FromState = 51,
	//! NodeId of the reference type ToState.
	EnumNumericNodeId_ToState = 52,
	//! NodeId of the reference type HasCause.
	EnumNumericNodeId_HasCause = 53,
	//! NodeId of the reference type HasEffect.
	EnumNumericNodeId_HasEffect = 54,
	//! NodeId of the reference type HasHistoricalConfiguration.
	EnumNumericNodeId_HasHistoricalConfiguration = 56,
	//! NodeId of the object type BaseObjectType.
	EnumNumericNodeId_BaseObjectType = 58,
	//! NodeId of the object type FolderType.
	EnumNumericNodeId_FolderType = 61,
	//! NodeId of the variable type BaseVariableType.
	EnumNumericNodeId_BaseVariableType = 62,
	//! NodeId of the variable type BaseDataVariableType.
	EnumNumericNodeId_BaseDataVariableType = 63,
	//! NodeId of the variable type PropertyType.
	EnumNumericNodeId_PropertyType = 68,
	//! NodeId of the variable type DataTypeDescriptionType.
	EnumNumericNodeId_DataTypeDescriptionType = 69,
	//! NodeId of the variable type DataTypeDictionaryType.
	EnumNumericNodeId_DataTypeDictionaryType = 72,
	//! NodeId of the object type DataTypeSystemType.
	EnumNumericNodeId_DataTypeSystemType = 75,
	//! NodeId of the object type DataTypeEncodingType.
	EnumNumericNodeId_DataTypeEncodingType = 76,
	//! NodeId of the object type ModellingRuleType.
	EnumNumericNodeId_ModellingRuleType = 77,
	//! NodeId of the node ModellingRule/Mandatory.
	EnumNumericNodeId_ModellingRule_Mandatory = 78,
	//! NodeId of the node ModellingRule/MandatoryShared.
	EnumNumericNodeId_ModellingRule_MandatoryShared = 79,
	//! NodeId of the node ModellingRule/Optional.
	EnumNumericNodeId_ModellingRule_Optional = 80,
	//! NodeId of the node ModellingRule/ExposesItsArray.
	EnumNumericNodeId_ModellingRule_ExposesItsArray = 83,
	//! NodeId of the node RootFolder.
	EnumNumericNodeId_RootFolder = 84,
	//! NodeId of the node ObjectsFolder.
	EnumNumericNodeId_ObjectsFolder = 85,
	//! NodeId of the node TypesFolder.
	EnumNumericNodeId_TypesFolder = 86,
	//! NodeId of the node ViewsFolder.
	EnumNumericNodeId_ViewsFolder = 87,
	//! NodeId of the node ObjectTypesFolder.
	EnumNumericNodeId_ObjectTypesFolder = 88,
	//! NodeId of the node VariableTypesFolder.
	EnumNumericNodeId_VariableTypesFolder = 89,
	//! NodeId of the node DataTypesFolder.
	EnumNumericNodeId_DataTypesFolder = 90,
	//! NodeId of the node ReferenceTypesFolder.
	EnumNumericNodeId_ReferenceTypesFolder = 91,
	//! NodeId of the node XmlSchema/TypeSystem.
	EnumNumericNodeId_XmlSchema_TypeSystem = 92,
	//! NodeId of the node OPCBinarySchema/TypeSystem.
	EnumNumericNodeId_OPCBinarySchema_TypeSystem = 93,
	//! NodeId of the node DataTypeDescriptionType/DataTypeVersion.
	EnumNumericNodeId_DataTypeDescriptionType_DataTypeVersion = 104,
	//! NodeId of the node DataTypeDescriptionType/DictionaryFragment.
	EnumNumericNodeId_DataTypeDescriptionType_DictionaryFragment = 105,
	//! NodeId of the node DataTypeDictionaryType/DataTypeVersion.
	EnumNumericNodeId_DataTypeDictionaryType_DataTypeVersion = 106,
	//! NodeId of the node DataTypeDictionaryType/NamespaceUri.
	EnumNumericNodeId_DataTypeDictionaryType_NamespaceUri = 107,
	//! NodeId of the node ModellingRuleType/NamingRule.
	EnumNumericNodeId_ModellingRuleType_NamingRule = 111,
	//! NodeId of the node ModellingRule/Mandatory/NamingRule.
	EnumNumericNodeId_ModellingRule_Mandatory_NamingRule = 112,
	//! NodeId of the node ModellingRule/Optional/NamingRule.
	EnumNumericNodeId_ModellingRule_Optional_NamingRule = 113,
	//! NodeId of the node ModellingRule/ExposesItsArray/NamingRule.
	EnumNumericNodeId_ModellingRule_ExposesItsArray_NamingRule = 114,
	//! NodeId of the node ModellingRule/MandatoryShared/NamingRule.
	EnumNumericNodeId_ModellingRule_MandatoryShared_NamingRule = 116,
	//! NodeId of the reference type HasSubStateMachine.
	EnumNumericNodeId_HasSubStateMachine = 117,
	//! NodeId of the data type NamingRuleType.
	EnumNumericNodeId_NamingRuleType = 120,
	//! NodeId of the data type IdType.
	EnumNumericNodeId_IdType = 256,
	//! NodeId of the data type NodeClass.
	EnumNumericNodeId_NodeClass = 257,
	//! NodeId of the data type Node.
	EnumNumericNodeId_Node = 258,
	//! NodeId of the node Node/Encoding/DefaultXml.
	EnumNumericNodeId_Node_Encoding_DefaultXml = 259,
	//! NodeId of the node Node/Encoding/DefaultBinary.
	EnumNumericNodeId_Node_Encoding_DefaultBinary = 260,
	//! NodeId of the data type ObjectNode.
	EnumNumericNodeId_ObjectNode = 261,
	//! NodeId of the node ObjectNode/Encoding/DefaultXml.
	EnumNumericNodeId_ObjectNode_Encoding_DefaultXml = 262,
	//! NodeId of the node ObjectNode/Encoding/DefaultBinary.
	EnumNumericNodeId_ObjectNode_Encoding_DefaultBinary = 263,
	//! NodeId of the data type ObjectTypeNode.
	EnumNumericNodeId_ObjectTypeNode = 264,
	//! NodeId of the node ObjectTypeNode/Encoding/DefaultXml.
	EnumNumericNodeId_ObjectTypeNode_Encoding_DefaultXml = 265,
	//! NodeId of the node ObjectTypeNode/Encoding/DefaultBinary.
	EnumNumericNodeId_ObjectTypeNode_Encoding_DefaultBinary = 266,
	//! NodeId of the data type VariableNode.
	EnumNumericNodeId_VariableNode = 267,
	//! NodeId of the node VariableNode/Encoding/DefaultXml.
	EnumNumericNodeId_VariableNode_Encoding_DefaultXml = 268,
	//! NodeId of the node VariableNode/Encoding/DefaultBinary.
	EnumNumericNodeId_VariableNode_Encoding_DefaultBinary = 269,
	//! NodeId of the data type VariableTypeNode.
	EnumNumericNodeId_VariableTypeNode = 270,
	//! NodeId of the node VariableTypeNode/Encoding/DefaultXml.
	EnumNumericNodeId_VariableTypeNode_Encoding_DefaultXml = 271,
	//! NodeId of the node VariableTypeNode/Encoding/DefaultBinary.
	EnumNumericNodeId_VariableTypeNode_Encoding_DefaultBinary = 272,
	//! NodeId of the data type ReferenceTypeNode.
	EnumNumericNodeId_ReferenceTypeNode = 273,
	//! NodeId of the node ReferenceTypeNode/Encoding/DefaultXml.
	EnumNumericNodeId_ReferenceTypeNode_Encoding_DefaultXml = 274,
	//! NodeId of the node ReferenceTypeNode/Encoding/DefaultBinary.
	EnumNumericNodeId_ReferenceTypeNode_Encoding_DefaultBinary = 275,
	//! NodeId of the data type MethodNode.
	EnumNumericNodeId_MethodNode = 276,
	//! NodeId of the node MethodNode/Encoding/DefaultXml.
	EnumNumericNodeId_MethodNode_Encoding_DefaultXml = 277,
	//! NodeId of the node MethodNode/Encoding/DefaultBinary.
	EnumNumericNodeId_MethodNode_Encoding_DefaultBinary = 278,
	//! NodeId of the data type ViewNode.
	EnumNumericNodeId_ViewNode = 279,
	//! NodeId of the node ViewNode/Encoding/DefaultXml.
	EnumNumericNodeId_ViewNode_Encoding_DefaultXml = 280,
	//! NodeId of the node ViewNode/Encoding/DefaultBinary.
	EnumNumericNodeId_ViewNode_Encoding_DefaultBinary = 281,
	//! NodeId of the data type DataTypeNode.
	EnumNumericNodeId_DataTypeNode = 282,
	//! NodeId of the node DataTypeNode/Encoding/DefaultXml.
	EnumNumericNodeId_DataTypeNode_Encoding_DefaultXml = 283,
	//! NodeId of the node DataTypeNode/Encoding/DefaultBinary.
	EnumNumericNodeId_DataTypeNode_Encoding_DefaultBinary = 284,
	//! NodeId of the data type ReferenceNode.
	EnumNumericNodeId_ReferenceNode = 285,
	//! NodeId of the node ReferenceNode/Encoding/DefaultXml.
	EnumNumericNodeId_ReferenceNode_Encoding_DefaultXml = 286,
	//! NodeId of the node ReferenceNode/Encoding/DefaultBinary.
	EnumNumericNodeId_ReferenceNode_Encoding_DefaultBinary = 287,
	//! NodeId of the data type IntegerId.
	EnumNumericNodeId_IntegerId = 288,
	//! NodeId of the data type Counter.
	EnumNumericNodeId_Counter = 289,
	//! NodeId of the data type Duration.
	EnumNumericNodeId_Duration = 290,
	//! NodeId of the data type NumericRange.
	EnumNumericNodeId_NumericRange = 291,
	//! NodeId of the data type Time.
	EnumNumericNodeId_Time = 292,
	//! NodeId of the data type Date.
	EnumNumericNodeId_Date = 293,
	//! NodeId of the data type UtcTime.
	EnumNumericNodeId_UtcTime = 294,
	//! NodeId of the data type LocaleId.
	EnumNumericNodeId_LocaleId = 295,
	//! NodeId of the data type Argument.
	EnumNumericNodeId_Argument = 296,
	//! NodeId of the node Argument/Encoding/DefaultXml.
	EnumNumericNodeId_Argument_Encoding_DefaultXml = 297,
	//! NodeId of the node Argument/Encoding/DefaultBinary.
	EnumNumericNodeId_Argument_Encoding_DefaultBinary = 298,
	//! NodeId of the data type StatusResult.
	EnumNumericNodeId_StatusResult = 299,
	//! NodeId of the node StatusResult/Encoding/DefaultXml.
	EnumNumericNodeId_StatusResult_Encoding_DefaultXml = 300,
	//! NodeId of the node StatusResult/Encoding/DefaultBinary.
	EnumNumericNodeId_StatusResult_Encoding_DefaultBinary = 301,
	//! NodeId of the data type MessageSecurityMode.
	EnumNumericNodeId_MessageSecurityMode = 302,
	//! NodeId of the data type UserTokenType.
	EnumNumericNodeId_UserTokenType = 303,
	//! NodeId of the data type UserTokenPolicy.
	EnumNumericNodeId_UserTokenPolicy = 304,
	//! NodeId of the node UserTokenPolicy/Encoding/DefaultXml.
	EnumNumericNodeId_UserTokenPolicy_Encoding_DefaultXml = 305,
	//! NodeId of the node UserTokenPolicy/Encoding/DefaultBinary.
	EnumNumericNodeId_UserTokenPolicy_Encoding_DefaultBinary = 306,
	//! NodeId of the data type ApplicationType.
	EnumNumericNodeId_ApplicationType = 307,
	//! NodeId of the data type ApplicationDescription.
	EnumNumericNodeId_ApplicationDescription = 308,
	//! NodeId of the node ApplicationDescription/Encoding/DefaultXml.
	EnumNumericNodeId_ApplicationDescription_Encoding_DefaultXml = 309,
	//! NodeId of the node ApplicationDescription/Encoding/DefaultBinary.
	EnumNumericNodeId_ApplicationDescription_Encoding_DefaultBinary = 310,
	//! NodeId of the data type ApplicationInstanceCertificate.
	EnumNumericNodeId_ApplicationInstanceCertificate = 311,
	//! NodeId of the data type EndpointDescription.
	EnumNumericNodeId_EndpointDescription = 312,
	//! NodeId of the node EndpointDescription/Encoding/DefaultXml.
	EnumNumericNodeId_EndpointDescription_Encoding_DefaultXml = 313,
	//! NodeId of the node EndpointDescription/Encoding/DefaultBinary.
	EnumNumericNodeId_EndpointDescription_Encoding_DefaultBinary = 314,
	//! NodeId of the data type SecurityTokenRequestType.
	EnumNumericNodeId_SecurityTokenRequestType = 315,
	//! NodeId of the data type UserIdentityToken.
	EnumNumericNodeId_UserIdentityToken = 316,
	//! NodeId of the node UserIdentityToken/Encoding/DefaultXml.
	EnumNumericNodeId_UserIdentityToken_Encoding_DefaultXml = 317,
	//! NodeId of the node UserIdentityToken/Encoding/DefaultBinary.
	EnumNumericNodeId_UserIdentityToken_Encoding_DefaultBinary = 318,
	//! NodeId of the data type AnonymousIdentityToken.
	EnumNumericNodeId_AnonymousIdentityToken = 319,
	//! NodeId of the node AnonymousIdentityToken/Encoding/DefaultXml.
	EnumNumericNodeId_AnonymousIdentityToken_Encoding_DefaultXml = 320,
	//! NodeId of the node AnonymousIdentityToken/Encoding/DefaultBinary.
	EnumNumericNodeId_AnonymousIdentityToken_Encoding_DefaultBinary = 321,
	//! NodeId of the data type UserNameIdentityToken.
	EnumNumericNodeId_UserNameIdentityToken = 322,
	//! NodeId of the node UserNameIdentityToken/Encoding/DefaultXml.
	EnumNumericNodeId_UserNameIdentityToken_Encoding_DefaultXml = 323,
	//! NodeId of the node UserNameIdentityToken/Encoding/DefaultBinary.
	EnumNumericNodeId_UserNameIdentityToken_Encoding_DefaultBinary = 324,
	//! NodeId of the data type X509IdentityToken.
	EnumNumericNodeId_X509IdentityToken = 325,
	//! NodeId of the node X509IdentityToken/Encoding/DefaultXml.
	EnumNumericNodeId_X509IdentityToken_Encoding_DefaultXml = 326,
	//! NodeId of the node X509IdentityToken/Encoding/DefaultBinary.
	EnumNumericNodeId_X509IdentityToken_Encoding_DefaultBinary = 327,
	//! NodeId of the data type EndpointConfiguration.
	EnumNumericNodeId_EndpointConfiguration = 331,
	//! NodeId of the node EndpointConfiguration/Encoding/DefaultXml.
	EnumNumericNodeId_EndpointConfiguration_Encoding_DefaultXml = 332,
	//! NodeId of the node EndpointConfiguration/Encoding/DefaultBinary.
	EnumNumericNodeId_EndpointConfiguration_Encoding_DefaultBinary = 333,
	//! NodeId of the data type ComplianceLevel.
	EnumNumericNodeId_ComplianceLevel = 334,
	//! NodeId of the data type SupportedProfile.
	EnumNumericNodeId_SupportedProfile = 335,
	//! NodeId of the node SupportedProfile/Encoding/DefaultXml.
	EnumNumericNodeId_SupportedProfile_Encoding_DefaultXml = 336,
	//! NodeId of the node SupportedProfile/Encoding/DefaultBinary.
	EnumNumericNodeId_SupportedProfile_Encoding_DefaultBinary = 337,
	//! NodeId of the data type BuildInfo.
	EnumNumericNodeId_BuildInfo = 338,
	//! NodeId of the node BuildInfo/Encoding/DefaultXml.
	EnumNumericNodeId_BuildInfo_Encoding_DefaultXml = 339,
	//! NodeId of the node BuildInfo/Encoding/DefaultBinary.
	EnumNumericNodeId_BuildInfo_Encoding_DefaultBinary = 340,
	//! NodeId of the data type SoftwareCertificate.
	EnumNumericNodeId_SoftwareCertificate = 341,
	//! NodeId of the node SoftwareCertificate/Encoding/DefaultXml.
	EnumNumericNodeId_SoftwareCertificate_Encoding_DefaultXml = 342,
	//! NodeId of the node SoftwareCertificate/Encoding/DefaultBinary.
	EnumNumericNodeId_SoftwareCertificate_Encoding_DefaultBinary = 343,
	//! NodeId of the data type SignedSoftwareCertificate.
	EnumNumericNodeId_SignedSoftwareCertificate = 344,
	//! NodeId of the node SignedSoftwareCertificate/Encoding/DefaultXml.
	EnumNumericNodeId_SignedSoftwareCertificate_Encoding_DefaultXml = 345,
	//! NodeId of the node SignedSoftwareCertificate/Encoding/DefaultBinary.
	EnumNumericNodeId_SignedSoftwareCertificate_Encoding_DefaultBinary = 346,
	//! NodeId of the data type AttributeWriteMask.
	EnumNumericNodeId_AttributeWriteMask = 347,
	//! NodeId of the data type NodeAttributesMask.
	EnumNumericNodeId_NodeAttributesMask = 348,
	//! NodeId of the data type NodeAttributes.
	EnumNumericNodeId_NodeAttributes = 349,
	//! NodeId of the node NodeAttributes/Encoding/DefaultXml.
	EnumNumericNodeId_NodeAttributes_Encoding_DefaultXml = 350,
	//! NodeId of the node NodeAttributes/Encoding/DefaultBinary.
	EnumNumericNodeId_NodeAttributes_Encoding_DefaultBinary = 351,
	//! NodeId of the data type ObjectAttributes.
	EnumNumericNodeId_ObjectAttributes = 352,
	//! NodeId of the node ObjectAttributes/Encoding/DefaultXml.
	EnumNumericNodeId_ObjectAttributes_Encoding_DefaultXml = 353,
	//! NodeId of the node ObjectAttributes/Encoding/DefaultBinary.
	EnumNumericNodeId_ObjectAttributes_Encoding_DefaultBinary = 354,
	//! NodeId of the data type VariableAttributes.
	EnumNumericNodeId_VariableAttributes = 355,
	//! NodeId of the node VariableAttributes/Encoding/DefaultXml.
	EnumNumericNodeId_VariableAttributes_Encoding_DefaultXml = 356,
	//! NodeId of the node VariableAttributes/Encoding/DefaultBinary.
	EnumNumericNodeId_VariableAttributes_Encoding_DefaultBinary = 357,
	//! NodeId of the data type MethodAttributes.
	EnumNumericNodeId_MethodAttributes = 358,
	//! NodeId of the node MethodAttributes/Encoding/DefaultXml.
	EnumNumericNodeId_MethodAttributes_Encoding_DefaultXml = 359,
	//! NodeId of the node MethodAttributes/Encoding/DefaultBinary.
	EnumNumericNodeId_MethodAttributes_Encoding_DefaultBinary = 360,
	//! NodeId of the data type ObjectTypeAttributes.
	EnumNumericNodeId_ObjectTypeAttributes = 361,
	//! NodeId of the node ObjectTypeAttributes/Encoding/DefaultXml.
	EnumNumericNodeId_ObjectTypeAttributes_Encoding_DefaultXml = 362,
	//! NodeId of the node ObjectTypeAttributes/Encoding/DefaultBinary.
	EnumNumericNodeId_ObjectTypeAttributes_Encoding_DefaultBinary = 363,
	//! NodeId of the data type VariableTypeAttributes.
	EnumNumericNodeId_VariableTypeAttributes = 364,
	//! NodeId of the node VariableTypeAttributes/Encoding/DefaultXml.
	EnumNumericNodeId_VariableTypeAttributes_Encoding_DefaultXml = 365,
	//! NodeId of the node VariableTypeAttributes/Encoding/DefaultBinary.
	EnumNumericNodeId_VariableTypeAttributes_Encoding_DefaultBinary = 366,
	//! NodeId of the data type ReferenceTypeAttributes.
	EnumNumericNodeId_ReferenceTypeAttributes = 367,
	//! NodeId of the node ReferenceTypeAttributes/Encoding/DefaultXml.
	EnumNumericNodeId_ReferenceTypeAttributes_Encoding_DefaultXml = 368,
	//! NodeId of the node ReferenceTypeAttributes/Encoding/DefaultBinary.
	EnumNumericNodeId_ReferenceTypeAttributes_Encoding_DefaultBinary = 369,
	//! NodeId of the data type DataTypeAttributes.
	EnumNumericNodeId_DataTypeAttributes = 370,
	//! NodeId of the node DataTypeAttributes/Encoding/DefaultXml.
	EnumNumericNodeId_DataTypeAttributes_Encoding_DefaultXml = 371,
	//! NodeId of the node DataTypeAttributes/Encoding/DefaultBinary.
	EnumNumericNodeId_DataTypeAttributes_Encoding_DefaultBinary = 372,
	//! NodeId of the data type ViewAttributes.
	EnumNumericNodeId_ViewAttributes = 373,
	//! NodeId of the node ViewAttributes/Encoding/DefaultXml.
	EnumNumericNodeId_ViewAttributes_Encoding_DefaultXml = 374,
	//! NodeId of the node ViewAttributes/Encoding/DefaultBinary.
	EnumNumericNodeId_ViewAttributes_Encoding_DefaultBinary = 375,
	//! NodeId of the data type AddNodesItem.
	EnumNumericNodeId_AddNodesItem = 376,
	//! NodeId of the node AddNodesItem/Encoding/DefaultXml.
	EnumNumericNodeId_AddNodesItem_Encoding_DefaultXml = 377,
	//! NodeId of the node AddNodesItem/Encoding/DefaultBinary.
	EnumNumericNodeId_AddNodesItem_Encoding_DefaultBinary = 378,
	//! NodeId of the data type AddReferencesItem.
	EnumNumericNodeId_AddReferencesItem = 379,
	//! NodeId of the node AddReferencesItem/Encoding/DefaultXml.
	EnumNumericNodeId_AddReferencesItem_Encoding_DefaultXml = 380,
	//! NodeId of the node AddReferencesItem/Encoding/DefaultBinary.
	EnumNumericNodeId_AddReferencesItem_Encoding_DefaultBinary = 381,
	//! NodeId of the data type DeleteNodesItem.
	EnumNumericNodeId_DeleteNodesItem = 382,
	//! NodeId of the node DeleteNodesItem/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteNodesItem_Encoding_DefaultXml = 383,
	//! NodeId of the node DeleteNodesItem/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteNodesItem_Encoding_DefaultBinary = 384,
	//! NodeId of the data type DeleteReferencesItem.
	EnumNumericNodeId_DeleteReferencesItem = 385,
	//! NodeId of the node DeleteReferencesItem/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteReferencesItem_Encoding_DefaultXml = 386,
	//! NodeId of the node DeleteReferencesItem/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteReferencesItem_Encoding_DefaultBinary = 387,
	//! NodeId of the data type SessionAuthenticationToken.
	EnumNumericNodeId_SessionAuthenticationToken = 388,
	//! NodeId of the data type RequestHeader.
	EnumNumericNodeId_RequestHeader = 389,
	//! NodeId of the node RequestHeader/Encoding/DefaultXml.
	EnumNumericNodeId_RequestHeader_Encoding_DefaultXml = 390,
	//! NodeId of the node RequestHeader/Encoding/DefaultBinary.
	EnumNumericNodeId_RequestHeader_Encoding_DefaultBinary = 391,
	//! NodeId of the data type ResponseHeader.
	EnumNumericNodeId_ResponseHeader = 392,
	//! NodeId of the node ResponseHeader/Encoding/DefaultXml.
	EnumNumericNodeId_ResponseHeader_Encoding_DefaultXml = 393,
	//! NodeId of the node ResponseHeader/Encoding/DefaultBinary.
	EnumNumericNodeId_ResponseHeader_Encoding_DefaultBinary = 394,
	//! NodeId of the data type ServiceFault.
	EnumNumericNodeId_ServiceFault = 395,
	//! NodeId of the node ServiceFault/Encoding/DefaultXml.
	EnumNumericNodeId_ServiceFault_Encoding_DefaultXml = 396,
	//! NodeId of the node ServiceFault/Encoding/DefaultBinary.
	EnumNumericNodeId_ServiceFault_Encoding_DefaultBinary = 397,
	//! NodeId of the data type EnumeratedTestType.
	EnumNumericNodeId_EnumeratedTestType = 398,
	//! NodeId of the data type ScalarTestType.
	EnumNumericNodeId_ScalarTestType = 399,
	//! NodeId of the node ScalarTestType/Encoding/DefaultXml.
	EnumNumericNodeId_ScalarTestType_Encoding_DefaultXml = 400,
	//! NodeId of the node ScalarTestType/Encoding/DefaultBinary.
	EnumNumericNodeId_ScalarTestType_Encoding_DefaultBinary = 401,
	//! NodeId of the data type ArrayTestType.
	EnumNumericNodeId_ArrayTestType = 402,
	//! NodeId of the node ArrayTestType/Encoding/DefaultXml.
	EnumNumericNodeId_ArrayTestType_Encoding_DefaultXml = 403,
	//! NodeId of the node ArrayTestType/Encoding/DefaultBinary.
	EnumNumericNodeId_ArrayTestType_Encoding_DefaultBinary = 404,
	//! NodeId of the data type CompositeTestType.
	EnumNumericNodeId_CompositeTestType = 405,
	//! NodeId of the node CompositeTestType/Encoding/DefaultXml.
	EnumNumericNodeId_CompositeTestType_Encoding_DefaultXml = 406,
	//! NodeId of the node CompositeTestType/Encoding/DefaultBinary.
	EnumNumericNodeId_CompositeTestType_Encoding_DefaultBinary = 407,
	//! NodeId of the data type TestStackRequest.
	EnumNumericNodeId_TestStackRequest = 408,
	//! NodeId of the node TestStackRequest/Encoding/DefaultXml.
	EnumNumericNodeId_TestStackRequest_Encoding_DefaultXml = 409,
	//! NodeId of the node TestStackRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_TestStackRequest_Encoding_DefaultBinary = 410,
	//! NodeId of the data type TestStackResponse.
	EnumNumericNodeId_TestStackResponse = 411,
	//! NodeId of the node TestStackResponse/Encoding/DefaultXml.
	EnumNumericNodeId_TestStackResponse_Encoding_DefaultXml = 412,
	//! NodeId of the node TestStackResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_TestStackResponse_Encoding_DefaultBinary = 413,
	//! NodeId of the data type TestStackExRequest.
	EnumNumericNodeId_TestStackExRequest = 414,
	//! NodeId of the node TestStackExRequest/Encoding/DefaultXml.
	EnumNumericNodeId_TestStackExRequest_Encoding_DefaultXml = 415,
	//! NodeId of the node TestStackExRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_TestStackExRequest_Encoding_DefaultBinary = 416,
	//! NodeId of the data type TestStackExResponse.
	EnumNumericNodeId_TestStackExResponse = 417,
	//! NodeId of the node TestStackExResponse/Encoding/DefaultXml.
	EnumNumericNodeId_TestStackExResponse_Encoding_DefaultXml = 418,
	//! NodeId of the node TestStackExResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_TestStackExResponse_Encoding_DefaultBinary = 419,
	//! NodeId of the data type FindServersRequest.
	EnumNumericNodeId_FindServersRequest = 420,
	//! NodeId of the node FindServersRequest/Encoding/DefaultXml.
	EnumNumericNodeId_FindServersRequest_Encoding_DefaultXml = 421,
	//! NodeId of the node FindServersRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_FindServersRequest_Encoding_DefaultBinary = 422,
	//! NodeId of the data type FindServersResponse.
	EnumNumericNodeId_FindServersResponse = 423,
	//! NodeId of the node FindServersResponse/Encoding/DefaultXml.
	EnumNumericNodeId_FindServersResponse_Encoding_DefaultXml = 424,
	//! NodeId of the node FindServersResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_FindServersResponse_Encoding_DefaultBinary = 425,
	//! NodeId of the data type GetEndpointsRequest.
	EnumNumericNodeId_GetEndpointsRequest = 426,
	//! NodeId of the node GetEndpointsRequest/Encoding/DefaultXml.
	EnumNumericNodeId_GetEndpointsRequest_Encoding_DefaultXml = 427,
	//! NodeId of the node GetEndpointsRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_GetEndpointsRequest_Encoding_DefaultBinary = 428,
	//! NodeId of the data type GetEndpointsResponse.
	EnumNumericNodeId_GetEndpointsResponse = 429,
	//! NodeId of the node GetEndpointsResponse/Encoding/DefaultXml.
	EnumNumericNodeId_GetEndpointsResponse_Encoding_DefaultXml = 430,
	//! NodeId of the node GetEndpointsResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_GetEndpointsResponse_Encoding_DefaultBinary = 431,
	//! NodeId of the data type RegisteredServer.
	EnumNumericNodeId_RegisteredServer = 432,
	//! NodeId of the node RegisteredServer/Encoding/DefaultXml.
	EnumNumericNodeId_RegisteredServer_Encoding_DefaultXml = 433,
	//! NodeId of the node RegisteredServer/Encoding/DefaultBinary.
	EnumNumericNodeId_RegisteredServer_Encoding_DefaultBinary = 434,
	//! NodeId of the data type RegisterServerRequest.
	EnumNumericNodeId_RegisterServerRequest = 435,
	//! NodeId of the node RegisterServerRequest/Encoding/DefaultXml.
	EnumNumericNodeId_RegisterServerRequest_Encoding_DefaultXml = 436,
	//! NodeId of the node RegisterServerRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_RegisterServerRequest_Encoding_DefaultBinary = 437,
	//! NodeId of the data type RegisterServerResponse.
	EnumNumericNodeId_RegisterServerResponse = 438,
	//! NodeId of the node RegisterServerResponse/Encoding/DefaultXml.
	EnumNumericNodeId_RegisterServerResponse_Encoding_DefaultXml = 439,
	//! NodeId of the node RegisterServerResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_RegisterServerResponse_Encoding_DefaultBinary = 440,
	//! NodeId of the data type ChannelSecurityToken.
	EnumNumericNodeId_ChannelSecurityToken = 441,
	//! NodeId of the node ChannelSecurityToken/Encoding/DefaultXml.
	EnumNumericNodeId_ChannelSecurityToken_Encoding_DefaultXml = 442,
	//! NodeId of the node ChannelSecurityToken/Encoding/DefaultBinary.
	EnumNumericNodeId_ChannelSecurityToken_Encoding_DefaultBinary = 443,
	//! NodeId of the data type OpenSecureChannelRequest.
	EnumNumericNodeId_OpenSecureChannelRequest = 444,
	//! NodeId of the node OpenSecureChannelRequest/Encoding/DefaultXml.
	EnumNumericNodeId_OpenSecureChannelRequest_Encoding_DefaultXml = 445,
	//! NodeId of the node OpenSecureChannelRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_OpenSecureChannelRequest_Encoding_DefaultBinary = 446,
	//! NodeId of the data type OpenSecureChannelResponse.
	EnumNumericNodeId_OpenSecureChannelResponse = 447,
	//! NodeId of the node OpenSecureChannelResponse/Encoding/DefaultXml.
	EnumNumericNodeId_OpenSecureChannelResponse_Encoding_DefaultXml = 448,
	//! NodeId of the node OpenSecureChannelResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_OpenSecureChannelResponse_Encoding_DefaultBinary = 449,
	//! NodeId of the data type CloseSecureChannelRequest.
	EnumNumericNodeId_CloseSecureChannelRequest = 450,
	//! NodeId of the node CloseSecureChannelRequest/Encoding/DefaultXml.
	EnumNumericNodeId_CloseSecureChannelRequest_Encoding_DefaultXml = 451,
	//! NodeId of the node CloseSecureChannelRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_CloseSecureChannelRequest_Encoding_DefaultBinary = 452,
	//! NodeId of the data type CloseSecureChannelResponse.
	EnumNumericNodeId_CloseSecureChannelResponse = 453,
	//! NodeId of the node CloseSecureChannelResponse/Encoding/DefaultXml.
	EnumNumericNodeId_CloseSecureChannelResponse_Encoding_DefaultXml = 454,
	//! NodeId of the node CloseSecureChannelResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_CloseSecureChannelResponse_Encoding_DefaultBinary = 455,
	//! NodeId of the data type SignatureData.
	EnumNumericNodeId_SignatureData = 456,
	//! NodeId of the node SignatureData/Encoding/DefaultXml.
	EnumNumericNodeId_SignatureData_Encoding_DefaultXml = 457,
	//! NodeId of the node SignatureData/Encoding/DefaultBinary.
	EnumNumericNodeId_SignatureData_Encoding_DefaultBinary = 458,
	//! NodeId of the data type CreateSessionRequest.
	EnumNumericNodeId_CreateSessionRequest = 459,
	//! NodeId of the node CreateSessionRequest/Encoding/DefaultXml.
	EnumNumericNodeId_CreateSessionRequest_Encoding_DefaultXml = 460,
	//! NodeId of the node CreateSessionRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_CreateSessionRequest_Encoding_DefaultBinary = 461,
	//! NodeId of the data type CreateSessionResponse.
	EnumNumericNodeId_CreateSessionResponse = 462,
	//! NodeId of the node CreateSessionResponse/Encoding/DefaultXml.
	EnumNumericNodeId_CreateSessionResponse_Encoding_DefaultXml = 463,
	//! NodeId of the node CreateSessionResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_CreateSessionResponse_Encoding_DefaultBinary = 464,
	//! NodeId of the data type ActivateSessionRequest.
	EnumNumericNodeId_ActivateSessionRequest = 465,
	//! NodeId of the node ActivateSessionRequest/Encoding/DefaultXml.
	EnumNumericNodeId_ActivateSessionRequest_Encoding_DefaultXml = 466,
	//! NodeId of the node ActivateSessionRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_ActivateSessionRequest_Encoding_DefaultBinary = 467,
	//! NodeId of the data type ActivateSessionResponse.
	EnumNumericNodeId_ActivateSessionResponse = 468,
	//! NodeId of the node ActivateSessionResponse/Encoding/DefaultXml.
	EnumNumericNodeId_ActivateSessionResponse_Encoding_DefaultXml = 469,
	//! NodeId of the node ActivateSessionResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_ActivateSessionResponse_Encoding_DefaultBinary = 470,
	//! NodeId of the data type CloseSessionRequest.
	EnumNumericNodeId_CloseSessionRequest = 471,
	//! NodeId of the node CloseSessionRequest/Encoding/DefaultXml.
	EnumNumericNodeId_CloseSessionRequest_Encoding_DefaultXml = 472,
	//! NodeId of the node CloseSessionRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_CloseSessionRequest_Encoding_DefaultBinary = 473,
	//! NodeId of the data type CloseSessionResponse.
	EnumNumericNodeId_CloseSessionResponse = 474,
	//! NodeId of the node CloseSessionResponse/Encoding/DefaultXml.
	EnumNumericNodeId_CloseSessionResponse_Encoding_DefaultXml = 475,
	//! NodeId of the node CloseSessionResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_CloseSessionResponse_Encoding_DefaultBinary = 476,
	//! NodeId of the data type CancelRequest.
	EnumNumericNodeId_CancelRequest = 477,
	//! NodeId of the node CancelRequest/Encoding/DefaultXml.
	EnumNumericNodeId_CancelRequest_Encoding_DefaultXml = 478,
	//! NodeId of the node CancelRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_CancelRequest_Encoding_DefaultBinary = 479,
	//! NodeId of the data type CancelResponse.
	EnumNumericNodeId_CancelResponse = 480,
	//! NodeId of the node CancelResponse/Encoding/DefaultXml.
	EnumNumericNodeId_CancelResponse_Encoding_DefaultXml = 481,
	//! NodeId of the node CancelResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_CancelResponse_Encoding_DefaultBinary = 482,
	//! NodeId of the data type AddNodesResult.
	EnumNumericNodeId_AddNodesResult = 483,
	//! NodeId of the node AddNodesResult/Encoding/DefaultXml.
	EnumNumericNodeId_AddNodesResult_Encoding_DefaultXml = 484,
	//! NodeId of the node AddNodesResult/Encoding/DefaultBinary.
	EnumNumericNodeId_AddNodesResult_Encoding_DefaultBinary = 485,
	//! NodeId of the data type AddNodesRequest.
	EnumNumericNodeId_AddNodesRequest = 486,
	//! NodeId of the node AddNodesRequest/Encoding/DefaultXml.
	EnumNumericNodeId_AddNodesRequest_Encoding_DefaultXml = 487,
	//! NodeId of the node AddNodesRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_AddNodesRequest_Encoding_DefaultBinary = 488,
	//! NodeId of the data type AddNodesResponse.
	EnumNumericNodeId_AddNodesResponse = 489,
	//! NodeId of the node AddNodesResponse/Encoding/DefaultXml.
	EnumNumericNodeId_AddNodesResponse_Encoding_DefaultXml = 490,
	//! NodeId of the node AddNodesResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_AddNodesResponse_Encoding_DefaultBinary = 491,
	//! NodeId of the data type AddReferencesRequest.
	EnumNumericNodeId_AddReferencesRequest = 492,
	//! NodeId of the node AddReferencesRequest/Encoding/DefaultXml.
	EnumNumericNodeId_AddReferencesRequest_Encoding_DefaultXml = 493,
	//! NodeId of the node AddReferencesRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_AddReferencesRequest_Encoding_DefaultBinary = 494,
	//! NodeId of the data type AddReferencesResponse.
	EnumNumericNodeId_AddReferencesResponse = 495,
	//! NodeId of the node AddReferencesResponse/Encoding/DefaultXml.
	EnumNumericNodeId_AddReferencesResponse_Encoding_DefaultXml = 496,
	//! NodeId of the node AddReferencesResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_AddReferencesResponse_Encoding_DefaultBinary = 497,
	//! NodeId of the data type DeleteNodesRequest.
	EnumNumericNodeId_DeleteNodesRequest = 498,
	//! NodeId of the node DeleteNodesRequest/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteNodesRequest_Encoding_DefaultXml = 499,
	//! NodeId of the node DeleteNodesRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteNodesRequest_Encoding_DefaultBinary = 500,
	//! NodeId of the data type DeleteNodesResponse.
	EnumNumericNodeId_DeleteNodesResponse = 501,
	//! NodeId of the node DeleteNodesResponse/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteNodesResponse_Encoding_DefaultXml = 502,
	//! NodeId of the node DeleteNodesResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteNodesResponse_Encoding_DefaultBinary = 503,
	//! NodeId of the data type DeleteReferencesRequest.
	EnumNumericNodeId_DeleteReferencesRequest = 504,
	//! NodeId of the node DeleteReferencesRequest/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteReferencesRequest_Encoding_DefaultXml = 505,
	//! NodeId of the node DeleteReferencesRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteReferencesRequest_Encoding_DefaultBinary = 506,
	//! NodeId of the data type DeleteReferencesResponse.
	EnumNumericNodeId_DeleteReferencesResponse = 507,
	//! NodeId of the node DeleteReferencesResponse/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteReferencesResponse_Encoding_DefaultXml = 508,
	//! NodeId of the node DeleteReferencesResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteReferencesResponse_Encoding_DefaultBinary = 509,
	//! NodeId of the data type BrowseDirection.
	EnumNumericNodeId_BrowseDirection = 510,
	//! NodeId of the data type ViewDescription.
	EnumNumericNodeId_ViewDescription = 511,
	//! NodeId of the node ViewDescription/Encoding/DefaultXml.
	EnumNumericNodeId_ViewDescription_Encoding_DefaultXml = 512,
	//! NodeId of the node ViewDescription/Encoding/DefaultBinary.
	EnumNumericNodeId_ViewDescription_Encoding_DefaultBinary = 513,
	//! NodeId of the data type BrowseDescription.
	EnumNumericNodeId_BrowseDescription = 514,
	//! NodeId of the node BrowseDescription/Encoding/DefaultXml.
	EnumNumericNodeId_BrowseDescription_Encoding_DefaultXml = 515,
	//! NodeId of the node BrowseDescription/Encoding/DefaultBinary.
	EnumNumericNodeId_BrowseDescription_Encoding_DefaultBinary = 516,
	//! NodeId of the data type BrowseResultMask.
	EnumNumericNodeId_BrowseResultMask = 517,
	//! NodeId of the data type ReferenceDescription.
	EnumNumericNodeId_ReferenceDescription = 518,
	//! NodeId of the node ReferenceDescription/Encoding/DefaultXml.
	EnumNumericNodeId_ReferenceDescription_Encoding_DefaultXml = 519,
	//! NodeId of the node ReferenceDescription/Encoding/DefaultBinary.
	EnumNumericNodeId_ReferenceDescription_Encoding_DefaultBinary = 520,
	//! NodeId of the data type ContinuationPoint.
	EnumNumericNodeId_ContinuationPoint = 521,
	//! NodeId of the data type BrowseResult.
	EnumNumericNodeId_BrowseResult = 522,
	//! NodeId of the node BrowseResult/Encoding/DefaultXml.
	EnumNumericNodeId_BrowseResult_Encoding_DefaultXml = 523,
	//! NodeId of the node BrowseResult/Encoding/DefaultBinary.
	EnumNumericNodeId_BrowseResult_Encoding_DefaultBinary = 524,
	//! NodeId of the data type BrowseRequest.
	EnumNumericNodeId_BrowseRequest = 525,
	//! NodeId of the node BrowseRequest/Encoding/DefaultXml.
	EnumNumericNodeId_BrowseRequest_Encoding_DefaultXml = 526,
	//! NodeId of the node BrowseRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_BrowseRequest_Encoding_DefaultBinary = 527,
	//! NodeId of the data type BrowseResponse.
	EnumNumericNodeId_BrowseResponse = 528,
	//! NodeId of the node BrowseResponse/Encoding/DefaultXml.
	EnumNumericNodeId_BrowseResponse_Encoding_DefaultXml = 529,
	//! NodeId of the node BrowseResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_BrowseResponse_Encoding_DefaultBinary = 530,
	//! NodeId of the data type BrowseNextRequest.
	EnumNumericNodeId_BrowseNextRequest = 531,
	//! NodeId of the node BrowseNextRequest/Encoding/DefaultXml.
	EnumNumericNodeId_BrowseNextRequest_Encoding_DefaultXml = 532,
	//! NodeId of the node BrowseNextRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_BrowseNextRequest_Encoding_DefaultBinary = 533,
	//! NodeId of the data type BrowseNextResponse.
	EnumNumericNodeId_BrowseNextResponse = 534,
	//! NodeId of the node BrowseNextResponse/Encoding/DefaultXml.
	EnumNumericNodeId_BrowseNextResponse_Encoding_DefaultXml = 535,
	//! NodeId of the node BrowseNextResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_BrowseNextResponse_Encoding_DefaultBinary = 536,
	//! NodeId of the data type RelativePathElement.
	EnumNumericNodeId_RelativePathElement = 537,
	//! NodeId of the node RelativePathElement/Encoding/DefaultXml.
	EnumNumericNodeId_RelativePathElement_Encoding_DefaultXml = 538,
	//! NodeId of the node RelativePathElement/Encoding/DefaultBinary.
	EnumNumericNodeId_RelativePathElement_Encoding_DefaultBinary = 539,
	//! NodeId of the data type RelativePath.
	EnumNumericNodeId_RelativePath = 540,
	//! NodeId of the node RelativePath/Encoding/DefaultXml.
	EnumNumericNodeId_RelativePath_Encoding_DefaultXml = 541,
	//! NodeId of the node RelativePath/Encoding/DefaultBinary.
	EnumNumericNodeId_RelativePath_Encoding_DefaultBinary = 542,
	//! NodeId of the data type BrowsePath.
	EnumNumericNodeId_BrowsePath = 543,
	//! NodeId of the node BrowsePath/Encoding/DefaultXml.
	EnumNumericNodeId_BrowsePath_Encoding_DefaultXml = 544,
	//! NodeId of the node BrowsePath/Encoding/DefaultBinary.
	EnumNumericNodeId_BrowsePath_Encoding_DefaultBinary = 545,
	//! NodeId of the data type BrowsePathTarget.
	EnumNumericNodeId_BrowsePathTarget = 546,
	//! NodeId of the node BrowsePathTarget/Encoding/DefaultXml.
	EnumNumericNodeId_BrowsePathTarget_Encoding_DefaultXml = 547,
	//! NodeId of the node BrowsePathTarget/Encoding/DefaultBinary.
	EnumNumericNodeId_BrowsePathTarget_Encoding_DefaultBinary = 548,
	//! NodeId of the data type BrowsePathResult.
	EnumNumericNodeId_BrowsePathResult = 549,
	//! NodeId of the node BrowsePathResult/Encoding/DefaultXml.
	EnumNumericNodeId_BrowsePathResult_Encoding_DefaultXml = 550,
	//! NodeId of the node BrowsePathResult/Encoding/DefaultBinary.
	EnumNumericNodeId_BrowsePathResult_Encoding_DefaultBinary = 551,
	//! NodeId of the data type TranslateBrowsePathsToNodeIdsRequest.
	EnumNumericNodeId_TranslateBrowsePathsToNodeIdsRequest = 552,
	//! NodeId of the node TranslateBrowsePathsToNodeIdsRequest/Encoding/DefaultXml.
	EnumNumericNodeId_TranslateBrowsePathsToNodeIdsRequest_Encoding_DefaultXml = 553,
	//! NodeId of the node TranslateBrowsePathsToNodeIdsRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_TranslateBrowsePathsToNodeIdsRequest_Encoding_DefaultBinary = 554,
	//! NodeId of the data type TranslateBrowsePathsToNodeIdsResponse.
	EnumNumericNodeId_TranslateBrowsePathsToNodeIdsResponse = 555,
	//! NodeId of the node TranslateBrowsePathsToNodeIdsResponse/Encoding/DefaultXml.
	EnumNumericNodeId_TranslateBrowsePathsToNodeIdsResponse_Encoding_DefaultXml = 556,
	//! NodeId of the node TranslateBrowsePathsToNodeIdsResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_TranslateBrowsePathsToNodeIdsResponse_Encoding_DefaultBinary = 557,
	//! NodeId of the data type RegisterNodesRequest.
	EnumNumericNodeId_RegisterNodesRequest = 558,
	//! NodeId of the node RegisterNodesRequest/Encoding/DefaultXml.
	EnumNumericNodeId_RegisterNodesRequest_Encoding_DefaultXml = 559,
	//! NodeId of the node RegisterNodesRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_RegisterNodesRequest_Encoding_DefaultBinary = 560,
	//! NodeId of the data type RegisterNodesResponse.
	EnumNumericNodeId_RegisterNodesResponse = 561,
	//! NodeId of the node RegisterNodesResponse/Encoding/DefaultXml.
	EnumNumericNodeId_RegisterNodesResponse_Encoding_DefaultXml = 562,
	//! NodeId of the node RegisterNodesResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_RegisterNodesResponse_Encoding_DefaultBinary = 563,
	//! NodeId of the data type UnregisterNodesRequest.
	EnumNumericNodeId_UnregisterNodesRequest = 564,
	//! NodeId of the node UnregisterNodesRequest/Encoding/DefaultXml.
	EnumNumericNodeId_UnregisterNodesRequest_Encoding_DefaultXml = 565,
	//! NodeId of the node UnregisterNodesRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_UnregisterNodesRequest_Encoding_DefaultBinary = 566,
	//! NodeId of the data type UnregisterNodesResponse.
	EnumNumericNodeId_UnregisterNodesResponse = 567,
	//! NodeId of the node UnregisterNodesResponse/Encoding/DefaultXml.
	EnumNumericNodeId_UnregisterNodesResponse_Encoding_DefaultXml = 568,
	//! NodeId of the node UnregisterNodesResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_UnregisterNodesResponse_Encoding_DefaultBinary = 569,
	//! NodeId of the data type QueryDataDescription.
	EnumNumericNodeId_QueryDataDescription = 570,
	//! NodeId of the node QueryDataDescription/Encoding/DefaultXml.
	EnumNumericNodeId_QueryDataDescription_Encoding_DefaultXml = 571,
	//! NodeId of the node QueryDataDescription/Encoding/DefaultBinary.
	EnumNumericNodeId_QueryDataDescription_Encoding_DefaultBinary = 572,
	//! NodeId of the data type NodeTypeDescription.
	EnumNumericNodeId_NodeTypeDescription = 573,
	//! NodeId of the node NodeTypeDescription/Encoding/DefaultXml.
	EnumNumericNodeId_NodeTypeDescription_Encoding_DefaultXml = 574,
	//! NodeId of the node NodeTypeDescription/Encoding/DefaultBinary.
	EnumNumericNodeId_NodeTypeDescription_Encoding_DefaultBinary = 575,
	//! NodeId of the data type FilterOperator.
	EnumNumericNodeId_FilterOperator = 576,
	//! NodeId of the data type QueryDataSet.
	EnumNumericNodeId_QueryDataSet = 577,
	//! NodeId of the node QueryDataSet/Encoding/DefaultXml.
	EnumNumericNodeId_QueryDataSet_Encoding_DefaultXml = 578,
	//! NodeId of the node QueryDataSet/Encoding/DefaultBinary.
	EnumNumericNodeId_QueryDataSet_Encoding_DefaultBinary = 579,
	//! NodeId of the data type NodeReference.
	EnumNumericNodeId_NodeReference = 580,
	//! NodeId of the node NodeReference/Encoding/DefaultXml.
	EnumNumericNodeId_NodeReference_Encoding_DefaultXml = 581,
	//! NodeId of the node NodeReference/Encoding/DefaultBinary.
	EnumNumericNodeId_NodeReference_Encoding_DefaultBinary = 582,
	//! NodeId of the data type ContentFilterElement.
	EnumNumericNodeId_ContentFilterElement = 583,
	//! NodeId of the node ContentFilterElement/Encoding/DefaultXml.
	EnumNumericNodeId_ContentFilterElement_Encoding_DefaultXml = 584,
	//! NodeId of the node ContentFilterElement/Encoding/DefaultBinary.
	EnumNumericNodeId_ContentFilterElement_Encoding_DefaultBinary = 585,
	//! NodeId of the data type ContentFilter.
	EnumNumericNodeId_ContentFilter = 586,
	//! NodeId of the node ContentFilter/Encoding/DefaultXml.
	EnumNumericNodeId_ContentFilter_Encoding_DefaultXml = 587,
	//! NodeId of the node ContentFilter/Encoding/DefaultBinary.
	EnumNumericNodeId_ContentFilter_Encoding_DefaultBinary = 588,
	//! NodeId of the data type FilterOperand.
	EnumNumericNodeId_FilterOperand = 589,
	//! NodeId of the node FilterOperand/Encoding/DefaultXml.
	EnumNumericNodeId_FilterOperand_Encoding_DefaultXml = 590,
	//! NodeId of the node FilterOperand/Encoding/DefaultBinary.
	EnumNumericNodeId_FilterOperand_Encoding_DefaultBinary = 591,
	//! NodeId of the data type ElementOperand.
	EnumNumericNodeId_ElementOperand = 592,
	//! NodeId of the node ElementOperand/Encoding/DefaultXml.
	EnumNumericNodeId_ElementOperand_Encoding_DefaultXml = 593,
	//! NodeId of the node ElementOperand/Encoding/DefaultBinary.
	EnumNumericNodeId_ElementOperand_Encoding_DefaultBinary = 594,
	//! NodeId of the data type LiteralOperand.
	EnumNumericNodeId_LiteralOperand = 595,
	//! NodeId of the node LiteralOperand/Encoding/DefaultXml.
	EnumNumericNodeId_LiteralOperand_Encoding_DefaultXml = 596,
	//! NodeId of the node LiteralOperand/Encoding/DefaultBinary.
	EnumNumericNodeId_LiteralOperand_Encoding_DefaultBinary = 597,
	//! NodeId of the data type AttributeOperand.
	EnumNumericNodeId_AttributeOperand = 598,
	//! NodeId of the node AttributeOperand/Encoding/DefaultXml.
	EnumNumericNodeId_AttributeOperand_Encoding_DefaultXml = 599,
	//! NodeId of the node AttributeOperand/Encoding/DefaultBinary.
	EnumNumericNodeId_AttributeOperand_Encoding_DefaultBinary = 600,
	//! NodeId of the data type SimpleAttributeOperand.
	EnumNumericNodeId_SimpleAttributeOperand = 601,
	//! NodeId of the node SimpleAttributeOperand/Encoding/DefaultXml.
	EnumNumericNodeId_SimpleAttributeOperand_Encoding_DefaultXml = 602,
	//! NodeId of the node SimpleAttributeOperand/Encoding/DefaultBinary.
	EnumNumericNodeId_SimpleAttributeOperand_Encoding_DefaultBinary = 603,
	//! NodeId of the data type ContentFilterElementResult.
	EnumNumericNodeId_ContentFilterElementResult = 604,
	//! NodeId of the node ContentFilterElementResult/Encoding/DefaultXml.
	EnumNumericNodeId_ContentFilterElementResult_Encoding_DefaultXml = 605,
	//! NodeId of the node ContentFilterElementResult/Encoding/DefaultBinary.
	EnumNumericNodeId_ContentFilterElementResult_Encoding_DefaultBinary = 606,
	//! NodeId of the data type ContentFilterResult.
	EnumNumericNodeId_ContentFilterResult = 607,
	//! NodeId of the node ContentFilterResult/Encoding/DefaultXml.
	EnumNumericNodeId_ContentFilterResult_Encoding_DefaultXml = 608,
	//! NodeId of the node ContentFilterResult/Encoding/DefaultBinary.
	EnumNumericNodeId_ContentFilterResult_Encoding_DefaultBinary = 609,
	//! NodeId of the data type ParsingResult.
	EnumNumericNodeId_ParsingResult = 610,
	//! NodeId of the node ParsingResult/Encoding/DefaultXml.
	EnumNumericNodeId_ParsingResult_Encoding_DefaultXml = 611,
	//! NodeId of the node ParsingResult/Encoding/DefaultBinary.
	EnumNumericNodeId_ParsingResult_Encoding_DefaultBinary = 612,
	//! NodeId of the data type QueryFirstRequest.
	EnumNumericNodeId_QueryFirstRequest = 613,
	//! NodeId of the node QueryFirstRequest/Encoding/DefaultXml.
	EnumNumericNodeId_QueryFirstRequest_Encoding_DefaultXml = 614,
	//! NodeId of the node QueryFirstRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_QueryFirstRequest_Encoding_DefaultBinary = 615,
	//! NodeId of the data type QueryFirstResponse.
	EnumNumericNodeId_QueryFirstResponse = 616,
	//! NodeId of the node QueryFirstResponse/Encoding/DefaultXml.
	EnumNumericNodeId_QueryFirstResponse_Encoding_DefaultXml = 617,
	//! NodeId of the node QueryFirstResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_QueryFirstResponse_Encoding_DefaultBinary = 618,
	//! NodeId of the data type QueryNextRequest.
	EnumNumericNodeId_QueryNextRequest = 619,
	//! NodeId of the node QueryNextRequest/Encoding/DefaultXml.
	EnumNumericNodeId_QueryNextRequest_Encoding_DefaultXml = 620,
	//! NodeId of the node QueryNextRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_QueryNextRequest_Encoding_DefaultBinary = 621,
	//! NodeId of the data type QueryNextResponse.
	EnumNumericNodeId_QueryNextResponse = 622,
	//! NodeId of the node QueryNextResponse/Encoding/DefaultXml.
	EnumNumericNodeId_QueryNextResponse_Encoding_DefaultXml = 623,
	//! NodeId of the node QueryNextResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_QueryNextResponse_Encoding_DefaultBinary = 624,
	//! NodeId of the data type TimestampsToReturn.
	EnumNumericNodeId_TimestampsToReturn = 625,
	//! NodeId of the data type ReadValueId.
	EnumNumericNodeId_ReadValueId = 626,
	//! NodeId of the node ReadValueId/Encoding/DefaultXml.
	EnumNumericNodeId_ReadValueId_Encoding_DefaultXml = 627,
	//! NodeId of the node ReadValueId/Encoding/DefaultBinary.
	EnumNumericNodeId_ReadValueId_Encoding_DefaultBinary = 628,
	//! NodeId of the data type ReadRequest.
	EnumNumericNodeId_ReadRequest = 629,
	//! NodeId of the node ReadRequest/Encoding/DefaultXml.
	EnumNumericNodeId_ReadRequest_Encoding_DefaultXml = 630,
	//! NodeId of the node ReadRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_ReadRequest_Encoding_DefaultBinary = 631,
	//! NodeId of the data type ReadResponse.
	EnumNumericNodeId_ReadResponse = 632,
	//! NodeId of the node ReadResponse/Encoding/DefaultXml.
	EnumNumericNodeId_ReadResponse_Encoding_DefaultXml = 633,
	//! NodeId of the node ReadResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_ReadResponse_Encoding_DefaultBinary = 634,
	//! NodeId of the data type HistoryReadValueId.
	EnumNumericNodeId_HistoryReadValueId = 635,
	//! NodeId of the node HistoryReadValueId/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryReadValueId_Encoding_DefaultXml = 636,
	//! NodeId of the node HistoryReadValueId/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryReadValueId_Encoding_DefaultBinary = 637,
	//! NodeId of the data type HistoryReadResult.
	EnumNumericNodeId_HistoryReadResult = 638,
	//! NodeId of the node HistoryReadResult/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryReadResult_Encoding_DefaultXml = 639,
	//! NodeId of the node HistoryReadResult/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryReadResult_Encoding_DefaultBinary = 640,
	//! NodeId of the data type HistoryReadDetails.
	EnumNumericNodeId_HistoryReadDetails = 641,
	//! NodeId of the node HistoryReadDetails/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryReadDetails_Encoding_DefaultXml = 642,
	//! NodeId of the node HistoryReadDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryReadDetails_Encoding_DefaultBinary = 643,
	//! NodeId of the data type ReadEventDetails.
	EnumNumericNodeId_ReadEventDetails = 644,
	//! NodeId of the node ReadEventDetails/Encoding/DefaultXml.
	EnumNumericNodeId_ReadEventDetails_Encoding_DefaultXml = 645,
	//! NodeId of the node ReadEventDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_ReadEventDetails_Encoding_DefaultBinary = 646,
	//! NodeId of the data type ReadRawModifiedDetails.
	EnumNumericNodeId_ReadRawModifiedDetails = 647,
	//! NodeId of the node ReadRawModifiedDetails/Encoding/DefaultXml.
	EnumNumericNodeId_ReadRawModifiedDetails_Encoding_DefaultXml = 648,
	//! NodeId of the node ReadRawModifiedDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_ReadRawModifiedDetails_Encoding_DefaultBinary = 649,
	//! NodeId of the data type ReadProcessedDetails.
	EnumNumericNodeId_ReadProcessedDetails = 650,
	//! NodeId of the node ReadProcessedDetails/Encoding/DefaultXml.
	EnumNumericNodeId_ReadProcessedDetails_Encoding_DefaultXml = 651,
	//! NodeId of the node ReadProcessedDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_ReadProcessedDetails_Encoding_DefaultBinary = 652,
	//! NodeId of the data type ReadAtTimeDetails.
	EnumNumericNodeId_ReadAtTimeDetails = 653,
	//! NodeId of the node ReadAtTimeDetails/Encoding/DefaultXml.
	EnumNumericNodeId_ReadAtTimeDetails_Encoding_DefaultXml = 654,
	//! NodeId of the node ReadAtTimeDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_ReadAtTimeDetails_Encoding_DefaultBinary = 655,
	//! NodeId of the data type HistoryData.
	EnumNumericNodeId_HistoryData = 656,
	//! NodeId of the node HistoryData/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryData_Encoding_DefaultXml = 657,
	//! NodeId of the node HistoryData/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryData_Encoding_DefaultBinary = 658,
	//! NodeId of the data type HistoryEvent.
	EnumNumericNodeId_HistoryEvent = 659,
	//! NodeId of the node HistoryEvent/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryEvent_Encoding_DefaultXml = 660,
	//! NodeId of the node HistoryEvent/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryEvent_Encoding_DefaultBinary = 661,
	//! NodeId of the data type HistoryReadRequest.
	EnumNumericNodeId_HistoryReadRequest = 662,
	//! NodeId of the node HistoryReadRequest/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryReadRequest_Encoding_DefaultXml = 663,
	//! NodeId of the node HistoryReadRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryReadRequest_Encoding_DefaultBinary = 664,
	//! NodeId of the data type HistoryReadResponse.
	EnumNumericNodeId_HistoryReadResponse = 665,
	//! NodeId of the node HistoryReadResponse/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryReadResponse_Encoding_DefaultXml = 666,
	//! NodeId of the node HistoryReadResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryReadResponse_Encoding_DefaultBinary = 667,
	//! NodeId of the data type WriteValue.
	EnumNumericNodeId_WriteValue = 668,
	//! NodeId of the node WriteValue/Encoding/DefaultXml.
	EnumNumericNodeId_WriteValue_Encoding_DefaultXml = 669,
	//! NodeId of the node WriteValue/Encoding/DefaultBinary.
	EnumNumericNodeId_WriteValue_Encoding_DefaultBinary = 670,
	//! NodeId of the data type WriteRequest.
	EnumNumericNodeId_WriteRequest = 671,
	//! NodeId of the node WriteRequest/Encoding/DefaultXml.
	EnumNumericNodeId_WriteRequest_Encoding_DefaultXml = 672,
	//! NodeId of the node WriteRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_WriteRequest_Encoding_DefaultBinary = 673,
	//! NodeId of the data type WriteResponse.
	EnumNumericNodeId_WriteResponse = 674,
	//! NodeId of the node WriteResponse/Encoding/DefaultXml.
	EnumNumericNodeId_WriteResponse_Encoding_DefaultXml = 675,
	//! NodeId of the node WriteResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_WriteResponse_Encoding_DefaultBinary = 676,
	//! NodeId of the data type HistoryUpdateDetails.
	EnumNumericNodeId_HistoryUpdateDetails = 677,
	//! NodeId of the node HistoryUpdateDetails/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryUpdateDetails_Encoding_DefaultXml = 678,
	//! NodeId of the node HistoryUpdateDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryUpdateDetails_Encoding_DefaultBinary = 679,
	//! NodeId of the data type UpdateDataDetails.
	EnumNumericNodeId_UpdateDataDetails = 680,
	//! NodeId of the node UpdateDataDetails/Encoding/DefaultXml.
	EnumNumericNodeId_UpdateDataDetails_Encoding_DefaultXml = 681,
	//! NodeId of the node UpdateDataDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_UpdateDataDetails_Encoding_DefaultBinary = 682,
	//! NodeId of the data type UpdateEventDetails.
	EnumNumericNodeId_UpdateEventDetails = 683,
	//! NodeId of the node UpdateEventDetails/Encoding/DefaultXml.
	EnumNumericNodeId_UpdateEventDetails_Encoding_DefaultXml = 684,
	//! NodeId of the node UpdateEventDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_UpdateEventDetails_Encoding_DefaultBinary = 685,
	//! NodeId of the data type DeleteRawModifiedDetails.
	EnumNumericNodeId_DeleteRawModifiedDetails = 686,
	//! NodeId of the node DeleteRawModifiedDetails/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteRawModifiedDetails_Encoding_DefaultXml = 687,
	//! NodeId of the node DeleteRawModifiedDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteRawModifiedDetails_Encoding_DefaultBinary = 688,
	//! NodeId of the data type DeleteAtTimeDetails.
	EnumNumericNodeId_DeleteAtTimeDetails = 689,
	//! NodeId of the node DeleteAtTimeDetails/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteAtTimeDetails_Encoding_DefaultXml = 690,
	//! NodeId of the node DeleteAtTimeDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteAtTimeDetails_Encoding_DefaultBinary = 691,
	//! NodeId of the data type DeleteEventDetails.
	EnumNumericNodeId_DeleteEventDetails = 692,
	//! NodeId of the node DeleteEventDetails/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteEventDetails_Encoding_DefaultXml = 693,
	//! NodeId of the node DeleteEventDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteEventDetails_Encoding_DefaultBinary = 694,
	//! NodeId of the data type HistoryUpdateResult.
	EnumNumericNodeId_HistoryUpdateResult = 695,
	//! NodeId of the node HistoryUpdateResult/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryUpdateResult_Encoding_DefaultXml = 696,
	//! NodeId of the node HistoryUpdateResult/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryUpdateResult_Encoding_DefaultBinary = 697,
	//! NodeId of the data type HistoryUpdateRequest.
	EnumNumericNodeId_HistoryUpdateRequest = 698,
	//! NodeId of the node HistoryUpdateRequest/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryUpdateRequest_Encoding_DefaultXml = 699,
	//! NodeId of the node HistoryUpdateRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryUpdateRequest_Encoding_DefaultBinary = 700,
	//! NodeId of the data type HistoryUpdateResponse.
	EnumNumericNodeId_HistoryUpdateResponse = 701,
	//! NodeId of the node HistoryUpdateResponse/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryUpdateResponse_Encoding_DefaultXml = 702,
	//! NodeId of the node HistoryUpdateResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryUpdateResponse_Encoding_DefaultBinary = 703,
	//! NodeId of the data type CallMethodRequest.
	EnumNumericNodeId_CallMethodRequest = 704,
	//! NodeId of the node CallMethodRequest/Encoding/DefaultXml.
	EnumNumericNodeId_CallMethodRequest_Encoding_DefaultXml = 705,
	//! NodeId of the node CallMethodRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_CallMethodRequest_Encoding_DefaultBinary = 706,
	//! NodeId of the data type CallMethodResult.
	EnumNumericNodeId_CallMethodResult = 707,
	//! NodeId of the node CallMethodResult/Encoding/DefaultXml.
	EnumNumericNodeId_CallMethodResult_Encoding_DefaultXml = 708,
	//! NodeId of the node CallMethodResult/Encoding/DefaultBinary.
	EnumNumericNodeId_CallMethodResult_Encoding_DefaultBinary = 709,
	//! NodeId of the data type CallRequest.
	EnumNumericNodeId_CallRequest = 710,
	//! NodeId of the node CallRequest/Encoding/DefaultXml.
	EnumNumericNodeId_CallRequest_Encoding_DefaultXml = 711,
	//! NodeId of the node CallRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_CallRequest_Encoding_DefaultBinary = 712,
	//! NodeId of the data type CallResponse.
	EnumNumericNodeId_CallResponse = 713,
	//! NodeId of the node CallResponse/Encoding/DefaultXml.
	EnumNumericNodeId_CallResponse_Encoding_DefaultXml = 714,
	//! NodeId of the node CallResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_CallResponse_Encoding_DefaultBinary = 715,
	//! NodeId of the data type MonitoringMode.
	EnumNumericNodeId_MonitoringMode = 716,
	//! NodeId of the data type DataChangeTrigger.
	EnumNumericNodeId_DataChangeTrigger = 717,
	//! NodeId of the data type DeadbandType.
	EnumNumericNodeId_DeadbandType = 718,
	//! NodeId of the data type MonitoringFilter.
	EnumNumericNodeId_MonitoringFilter = 719,
	//! NodeId of the node MonitoringFilter/Encoding/DefaultXml.
	EnumNumericNodeId_MonitoringFilter_Encoding_DefaultXml = 720,
	//! NodeId of the node MonitoringFilter/Encoding/DefaultBinary.
	EnumNumericNodeId_MonitoringFilter_Encoding_DefaultBinary = 721,
	//! NodeId of the data type DataChangeFilter.
	EnumNumericNodeId_DataChangeFilter = 722,
	//! NodeId of the node DataChangeFilter/Encoding/DefaultXml.
	EnumNumericNodeId_DataChangeFilter_Encoding_DefaultXml = 723,
	//! NodeId of the node DataChangeFilter/Encoding/DefaultBinary.
	EnumNumericNodeId_DataChangeFilter_Encoding_DefaultBinary = 724,
	//! NodeId of the data type EventFilter.
	EnumNumericNodeId_EventFilter = 725,
	//! NodeId of the node EventFilter/Encoding/DefaultXml.
	EnumNumericNodeId_EventFilter_Encoding_DefaultXml = 726,
	//! NodeId of the node EventFilter/Encoding/DefaultBinary.
	EnumNumericNodeId_EventFilter_Encoding_DefaultBinary = 727,
	//! NodeId of the data type AggregateFilter.
	EnumNumericNodeId_AggregateFilter = 728,
	//! NodeId of the node AggregateFilter/Encoding/DefaultXml.
	EnumNumericNodeId_AggregateFilter_Encoding_DefaultXml = 729,
	//! NodeId of the node AggregateFilter/Encoding/DefaultBinary.
	EnumNumericNodeId_AggregateFilter_Encoding_DefaultBinary = 730,
	//! NodeId of the data type MonitoringFilterResult.
	EnumNumericNodeId_MonitoringFilterResult = 731,
	//! NodeId of the node MonitoringFilterResult/Encoding/DefaultXml.
	EnumNumericNodeId_MonitoringFilterResult_Encoding_DefaultXml = 732,
	//! NodeId of the node MonitoringFilterResult/Encoding/DefaultBinary.
	EnumNumericNodeId_MonitoringFilterResult_Encoding_DefaultBinary = 733,
	//! NodeId of the data type EventFilterResult.
	EnumNumericNodeId_EventFilterResult = 734,
	//! NodeId of the node EventFilterResult/Encoding/DefaultXml.
	EnumNumericNodeId_EventFilterResult_Encoding_DefaultXml = 735,
	//! NodeId of the node EventFilterResult/Encoding/DefaultBinary.
	EnumNumericNodeId_EventFilterResult_Encoding_DefaultBinary = 736,
	//! NodeId of the data type AggregateFilterResult.
	EnumNumericNodeId_AggregateFilterResult = 737,
	//! NodeId of the node AggregateFilterResult/Encoding/DefaultXml.
	EnumNumericNodeId_AggregateFilterResult_Encoding_DefaultXml = 738,
	//! NodeId of the node AggregateFilterResult/Encoding/DefaultBinary.
	EnumNumericNodeId_AggregateFilterResult_Encoding_DefaultBinary = 739,
	//! NodeId of the data type MonitoringParameters.
	EnumNumericNodeId_MonitoringParameters = 740,
	//! NodeId of the node MonitoringParameters/Encoding/DefaultXml.
	EnumNumericNodeId_MonitoringParameters_Encoding_DefaultXml = 741,
	//! NodeId of the node MonitoringParameters/Encoding/DefaultBinary.
	EnumNumericNodeId_MonitoringParameters_Encoding_DefaultBinary = 742,
	//! NodeId of the data type MonitoredItemCreateRequest.
	EnumNumericNodeId_MonitoredItemCreateRequest = 743,
	//! NodeId of the node MonitoredItemCreateRequest/Encoding/DefaultXml.
	EnumNumericNodeId_MonitoredItemCreateRequest_Encoding_DefaultXml = 744,
	//! NodeId of the node MonitoredItemCreateRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_MonitoredItemCreateRequest_Encoding_DefaultBinary = 745,
	//! NodeId of the data type MonitoredItemCreateResult.
	EnumNumericNodeId_MonitoredItemCreateResult = 746,
	//! NodeId of the node MonitoredItemCreateResult/Encoding/DefaultXml.
	EnumNumericNodeId_MonitoredItemCreateResult_Encoding_DefaultXml = 747,
	//! NodeId of the node MonitoredItemCreateResult/Encoding/DefaultBinary.
	EnumNumericNodeId_MonitoredItemCreateResult_Encoding_DefaultBinary = 748,
	//! NodeId of the data type CreateMonitoredItemsRequest.
	EnumNumericNodeId_CreateMonitoredItemsRequest = 749,
	//! NodeId of the node CreateMonitoredItemsRequest/Encoding/DefaultXml.
	EnumNumericNodeId_CreateMonitoredItemsRequest_Encoding_DefaultXml = 750,
	//! NodeId of the node CreateMonitoredItemsRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_CreateMonitoredItemsRequest_Encoding_DefaultBinary = 751,
	//! NodeId of the data type CreateMonitoredItemsResponse.
	EnumNumericNodeId_CreateMonitoredItemsResponse = 752,
	//! NodeId of the node CreateMonitoredItemsResponse/Encoding/DefaultXml.
	EnumNumericNodeId_CreateMonitoredItemsResponse_Encoding_DefaultXml = 753,
	//! NodeId of the node CreateMonitoredItemsResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_CreateMonitoredItemsResponse_Encoding_DefaultBinary = 754,
	//! NodeId of the data type MonitoredItemModifyRequest.
	EnumNumericNodeId_MonitoredItemModifyRequest = 755,
	//! NodeId of the node MonitoredItemModifyRequest/Encoding/DefaultXml.
	EnumNumericNodeId_MonitoredItemModifyRequest_Encoding_DefaultXml = 756,
	//! NodeId of the node MonitoredItemModifyRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_MonitoredItemModifyRequest_Encoding_DefaultBinary = 757,
	//! NodeId of the data type MonitoredItemModifyResult.
	EnumNumericNodeId_MonitoredItemModifyResult = 758,
	//! NodeId of the node MonitoredItemModifyResult/Encoding/DefaultXml.
	EnumNumericNodeId_MonitoredItemModifyResult_Encoding_DefaultXml = 759,
	//! NodeId of the node MonitoredItemModifyResult/Encoding/DefaultBinary.
	EnumNumericNodeId_MonitoredItemModifyResult_Encoding_DefaultBinary = 760,
	//! NodeId of the data type ModifyMonitoredItemsRequest.
	EnumNumericNodeId_ModifyMonitoredItemsRequest = 761,
	//! NodeId of the node ModifyMonitoredItemsRequest/Encoding/DefaultXml.
	EnumNumericNodeId_ModifyMonitoredItemsRequest_Encoding_DefaultXml = 762,
	//! NodeId of the node ModifyMonitoredItemsRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_ModifyMonitoredItemsRequest_Encoding_DefaultBinary = 763,
	//! NodeId of the data type ModifyMonitoredItemsResponse.
	EnumNumericNodeId_ModifyMonitoredItemsResponse = 764,
	//! NodeId of the node ModifyMonitoredItemsResponse/Encoding/DefaultXml.
	EnumNumericNodeId_ModifyMonitoredItemsResponse_Encoding_DefaultXml = 765,
	//! NodeId of the node ModifyMonitoredItemsResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_ModifyMonitoredItemsResponse_Encoding_DefaultBinary = 766,
	//! NodeId of the data type SetMonitoringModeRequest.
	EnumNumericNodeId_SetMonitoringModeRequest = 767,
	//! NodeId of the node SetMonitoringModeRequest/Encoding/DefaultXml.
	EnumNumericNodeId_SetMonitoringModeRequest_Encoding_DefaultXml = 768,
	//! NodeId of the node SetMonitoringModeRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_SetMonitoringModeRequest_Encoding_DefaultBinary = 769,
	//! NodeId of the data type SetMonitoringModeResponse.
	EnumNumericNodeId_SetMonitoringModeResponse = 770,
	//! NodeId of the node SetMonitoringModeResponse/Encoding/DefaultXml.
	EnumNumericNodeId_SetMonitoringModeResponse_Encoding_DefaultXml = 771,
	//! NodeId of the node SetMonitoringModeResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_SetMonitoringModeResponse_Encoding_DefaultBinary = 772,
	//! NodeId of the data type SetTriggeringRequest.
	EnumNumericNodeId_SetTriggeringRequest = 773,
	//! NodeId of the node SetTriggeringRequest/Encoding/DefaultXml.
	EnumNumericNodeId_SetTriggeringRequest_Encoding_DefaultXml = 774,
	//! NodeId of the node SetTriggeringRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_SetTriggeringRequest_Encoding_DefaultBinary = 775,
	//! NodeId of the data type SetTriggeringResponse.
	EnumNumericNodeId_SetTriggeringResponse = 776,
	//! NodeId of the node SetTriggeringResponse/Encoding/DefaultXml.
	EnumNumericNodeId_SetTriggeringResponse_Encoding_DefaultXml = 777,
	//! NodeId of the node SetTriggeringResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_SetTriggeringResponse_Encoding_DefaultBinary = 778,
	//! NodeId of the data type DeleteMonitoredItemsRequest.
	EnumNumericNodeId_DeleteMonitoredItemsRequest = 779,
	//! NodeId of the node DeleteMonitoredItemsRequest/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteMonitoredItemsRequest_Encoding_DefaultXml = 780,
	//! NodeId of the node DeleteMonitoredItemsRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteMonitoredItemsRequest_Encoding_DefaultBinary = 781,
	//! NodeId of the data type DeleteMonitoredItemsResponse.
	EnumNumericNodeId_DeleteMonitoredItemsResponse = 782,
	//! NodeId of the node DeleteMonitoredItemsResponse/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteMonitoredItemsResponse_Encoding_DefaultXml = 783,
	//! NodeId of the node DeleteMonitoredItemsResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteMonitoredItemsResponse_Encoding_DefaultBinary = 784,
	//! NodeId of the data type CreateSubscriptionRequest.
	EnumNumericNodeId_CreateSubscriptionRequest = 785,
	//! NodeId of the node CreateSubscriptionRequest/Encoding/DefaultXml.
	EnumNumericNodeId_CreateSubscriptionRequest_Encoding_DefaultXml = 786,
	//! NodeId of the node CreateSubscriptionRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_CreateSubscriptionRequest_Encoding_DefaultBinary = 787,
	//! NodeId of the data type CreateSubscriptionResponse.
	EnumNumericNodeId_CreateSubscriptionResponse = 788,
	//! NodeId of the node CreateSubscriptionResponse/Encoding/DefaultXml.
	EnumNumericNodeId_CreateSubscriptionResponse_Encoding_DefaultXml = 789,
	//! NodeId of the node CreateSubscriptionResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_CreateSubscriptionResponse_Encoding_DefaultBinary = 790,
	//! NodeId of the data type ModifySubscriptionRequest.
	EnumNumericNodeId_ModifySubscriptionRequest = 791,
	//! NodeId of the node ModifySubscriptionRequest/Encoding/DefaultXml.
	EnumNumericNodeId_ModifySubscriptionRequest_Encoding_DefaultXml = 792,
	//! NodeId of the node ModifySubscriptionRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_ModifySubscriptionRequest_Encoding_DefaultBinary = 793,
	//! NodeId of the data type ModifySubscriptionResponse.
	EnumNumericNodeId_ModifySubscriptionResponse = 794,
	//! NodeId of the node ModifySubscriptionResponse/Encoding/DefaultXml.
	EnumNumericNodeId_ModifySubscriptionResponse_Encoding_DefaultXml = 795,
	//! NodeId of the node ModifySubscriptionResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_ModifySubscriptionResponse_Encoding_DefaultBinary = 796,
	//! NodeId of the data type SetPublishingModeRequest.
	EnumNumericNodeId_SetPublishingModeRequest = 797,
	//! NodeId of the node SetPublishingModeRequest/Encoding/DefaultXml.
	EnumNumericNodeId_SetPublishingModeRequest_Encoding_DefaultXml = 798,
	//! NodeId of the node SetPublishingModeRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_SetPublishingModeRequest_Encoding_DefaultBinary = 799,
	//! NodeId of the data type SetPublishingModeResponse.
	EnumNumericNodeId_SetPublishingModeResponse = 800,
	//! NodeId of the node SetPublishingModeResponse/Encoding/DefaultXml.
	EnumNumericNodeId_SetPublishingModeResponse_Encoding_DefaultXml = 801,
	//! NodeId of the node SetPublishingModeResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_SetPublishingModeResponse_Encoding_DefaultBinary = 802,
	//! NodeId of the data type NotificationMessage.
	EnumNumericNodeId_NotificationMessage = 803,
	//! NodeId of the node NotificationMessage/Encoding/DefaultXml.
	EnumNumericNodeId_NotificationMessage_Encoding_DefaultXml = 804,
	//! NodeId of the node NotificationMessage/Encoding/DefaultBinary.
	EnumNumericNodeId_NotificationMessage_Encoding_DefaultBinary = 805,
	//! NodeId of the data type MonitoredItemNotification.
	EnumNumericNodeId_MonitoredItemNotification = 806,
	//! NodeId of the node MonitoredItemNotification/Encoding/DefaultXml.
	EnumNumericNodeId_MonitoredItemNotification_Encoding_DefaultXml = 807,
	//! NodeId of the node MonitoredItemNotification/Encoding/DefaultBinary.
	EnumNumericNodeId_MonitoredItemNotification_Encoding_DefaultBinary = 808,
	//! NodeId of the data type DataChangeNotification.
	EnumNumericNodeId_DataChangeNotification = 809,
	//! NodeId of the node DataChangeNotification/Encoding/DefaultXml.
	EnumNumericNodeId_DataChangeNotification_Encoding_DefaultXml = 810,
	//! NodeId of the node DataChangeNotification/Encoding/DefaultBinary.
	EnumNumericNodeId_DataChangeNotification_Encoding_DefaultBinary = 811,
	//! NodeId of the data type StatusChangeNotification.
	EnumNumericNodeId_StatusChangeNotification = 818,
	//! NodeId of the node StatusChangeNotification/Encoding/DefaultXml.
	EnumNumericNodeId_StatusChangeNotification_Encoding_DefaultXml = 819,
	//! NodeId of the node StatusChangeNotification/Encoding/DefaultBinary.
	EnumNumericNodeId_StatusChangeNotification_Encoding_DefaultBinary = 820,
	//! NodeId of the data type SubscriptionAcknowledgement.
	EnumNumericNodeId_SubscriptionAcknowledgement = 821,
	//! NodeId of the node SubscriptionAcknowledgement/Encoding/DefaultXml.
	EnumNumericNodeId_SubscriptionAcknowledgement_Encoding_DefaultXml = 822,
	//! NodeId of the node SubscriptionAcknowledgement/Encoding/DefaultBinary.
	EnumNumericNodeId_SubscriptionAcknowledgement_Encoding_DefaultBinary = 823,
	//! NodeId of the data type PublishRequest.
	EnumNumericNodeId_PublishRequest = 824,
	//! NodeId of the node PublishRequest/Encoding/DefaultXml.
	EnumNumericNodeId_PublishRequest_Encoding_DefaultXml = 825,
	//! NodeId of the node PublishRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_PublishRequest_Encoding_DefaultBinary = 826,
	//! NodeId of the data type PublishResponse.
	EnumNumericNodeId_PublishResponse = 827,
	//! NodeId of the node PublishResponse/Encoding/DefaultXml.
	EnumNumericNodeId_PublishResponse_Encoding_DefaultXml = 828,
	//! NodeId of the node PublishResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_PublishResponse_Encoding_DefaultBinary = 829,
	//! NodeId of the data type RepublishRequest.
	EnumNumericNodeId_RepublishRequest = 830,
	//! NodeId of the node RepublishRequest/Encoding/DefaultXml.
	EnumNumericNodeId_RepublishRequest_Encoding_DefaultXml = 831,
	//! NodeId of the node RepublishRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_RepublishRequest_Encoding_DefaultBinary = 832,
	//! NodeId of the data type RepublishResponse.
	EnumNumericNodeId_RepublishResponse = 833,
	//! NodeId of the node RepublishResponse/Encoding/DefaultXml.
	EnumNumericNodeId_RepublishResponse_Encoding_DefaultXml = 834,
	//! NodeId of the node RepublishResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_RepublishResponse_Encoding_DefaultBinary = 835,
	//! NodeId of the data type TransferResult.
	EnumNumericNodeId_TransferResult = 836,
	//! NodeId of the node TransferResult/Encoding/DefaultXml.
	EnumNumericNodeId_TransferResult_Encoding_DefaultXml = 837,
	//! NodeId of the node TransferResult/Encoding/DefaultBinary.
	EnumNumericNodeId_TransferResult_Encoding_DefaultBinary = 838,
	//! NodeId of the data type TransferSubscriptionsRequest.
	EnumNumericNodeId_TransferSubscriptionsRequest = 839,
	//! NodeId of the node TransferSubscriptionsRequest/Encoding/DefaultXml.
	EnumNumericNodeId_TransferSubscriptionsRequest_Encoding_DefaultXml = 840,
	//! NodeId of the node TransferSubscriptionsRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_TransferSubscriptionsRequest_Encoding_DefaultBinary = 841,
	//! NodeId of the data type TransferSubscriptionsResponse.
	EnumNumericNodeId_TransferSubscriptionsResponse = 842,
	//! NodeId of the node TransferSubscriptionsResponse/Encoding/DefaultXml.
	EnumNumericNodeId_TransferSubscriptionsResponse_Encoding_DefaultXml = 843,
	//! NodeId of the node TransferSubscriptionsResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_TransferSubscriptionsResponse_Encoding_DefaultBinary = 844,
	//! NodeId of the data type DeleteSubscriptionsRequest.
	EnumNumericNodeId_DeleteSubscriptionsRequest = 845,
	//! NodeId of the node DeleteSubscriptionsRequest/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteSubscriptionsRequest_Encoding_DefaultXml = 846,
	//! NodeId of the node DeleteSubscriptionsRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteSubscriptionsRequest_Encoding_DefaultBinary = 847,
	//! NodeId of the data type DeleteSubscriptionsResponse.
	EnumNumericNodeId_DeleteSubscriptionsResponse = 848,
	//! NodeId of the node DeleteSubscriptionsResponse/Encoding/DefaultXml.
	EnumNumericNodeId_DeleteSubscriptionsResponse_Encoding_DefaultXml = 849,
	//! NodeId of the node DeleteSubscriptionsResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_DeleteSubscriptionsResponse_Encoding_DefaultBinary = 850,
	//! NodeId of the data type RedundancySupport.
	EnumNumericNodeId_RedundancySupport = 851,
	//! NodeId of the data type ServerState.
	EnumNumericNodeId_ServerState = 852,
	//! NodeId of the data type RedundantServerDataType.
	EnumNumericNodeId_RedundantServerDataType = 853,
	//! NodeId of the node RedundantServerDataType/Encoding/DefaultXml.
	EnumNumericNodeId_RedundantServerDataType_Encoding_DefaultXml = 854,
	//! NodeId of the node RedundantServerDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_RedundantServerDataType_Encoding_DefaultBinary = 855,
	//! NodeId of the data type SamplingIntervalDiagnosticsDataType.
	EnumNumericNodeId_SamplingIntervalDiagnosticsDataType = 856,
	//! NodeId of the node SamplingIntervalDiagnosticsDataType/Encoding/DefaultXml.
	EnumNumericNodeId_SamplingIntervalDiagnosticsDataType_Encoding_DefaultXml = 857,
	//! NodeId of the node SamplingIntervalDiagnosticsDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_SamplingIntervalDiagnosticsDataType_Encoding_DefaultBinary = 858,
	//! NodeId of the data type ServerDiagnosticsSummaryDataType.
	EnumNumericNodeId_ServerDiagnosticsSummaryDataType = 859,
	//! NodeId of the node ServerDiagnosticsSummaryDataType/Encoding/DefaultXml.
	EnumNumericNodeId_ServerDiagnosticsSummaryDataType_Encoding_DefaultXml = 860,
	//! NodeId of the node ServerDiagnosticsSummaryDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_ServerDiagnosticsSummaryDataType_Encoding_DefaultBinary = 861,
	//! NodeId of the data type ServerStatusDataType.
	EnumNumericNodeId_ServerStatusDataType = 862,
	//! NodeId of the node ServerStatusDataType/Encoding/DefaultXml.
	EnumNumericNodeId_ServerStatusDataType_Encoding_DefaultXml = 863,
	//! NodeId of the node ServerStatusDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_ServerStatusDataType_Encoding_DefaultBinary = 864,
	//! NodeId of the data type SessionDiagnosticsDataType.
	EnumNumericNodeId_SessionDiagnosticsDataType = 865,
	//! NodeId of the node SessionDiagnosticsDataType/Encoding/DefaultXml.
	EnumNumericNodeId_SessionDiagnosticsDataType_Encoding_DefaultXml = 866,
	//! NodeId of the node SessionDiagnosticsDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_SessionDiagnosticsDataType_Encoding_DefaultBinary = 867,
	//! NodeId of the data type SessionSecurityDiagnosticsDataType.
	EnumNumericNodeId_SessionSecurityDiagnosticsDataType = 868,
	//! NodeId of the node SessionSecurityDiagnosticsDataType/Encoding/DefaultXml.
	EnumNumericNodeId_SessionSecurityDiagnosticsDataType_Encoding_DefaultXml = 869,
	//! NodeId of the node SessionSecurityDiagnosticsDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_SessionSecurityDiagnosticsDataType_Encoding_DefaultBinary = 870,
	//! NodeId of the data type ServiceCounterDataType.
	EnumNumericNodeId_ServiceCounterDataType = 871,
	//! NodeId of the node ServiceCounterDataType/Encoding/DefaultXml.
	EnumNumericNodeId_ServiceCounterDataType_Encoding_DefaultXml = 872,
	//! NodeId of the node ServiceCounterDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_ServiceCounterDataType_Encoding_DefaultBinary = 873,
	//! NodeId of the data type SubscriptionDiagnosticsDataType.
	EnumNumericNodeId_SubscriptionDiagnosticsDataType = 874,
	//! NodeId of the node SubscriptionDiagnosticsDataType/Encoding/DefaultXml.
	EnumNumericNodeId_SubscriptionDiagnosticsDataType_Encoding_DefaultXml = 875,
	//! NodeId of the node SubscriptionDiagnosticsDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_SubscriptionDiagnosticsDataType_Encoding_DefaultBinary = 876,
	//! NodeId of the data type ModelChangeStructureDataType.
	EnumNumericNodeId_ModelChangeStructureDataType = 877,
	//! NodeId of the node ModelChangeStructureDataType/Encoding/DefaultXml.
	EnumNumericNodeId_ModelChangeStructureDataType_Encoding_DefaultXml = 878,
	//! NodeId of the node ModelChangeStructureDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_ModelChangeStructureDataType_Encoding_DefaultBinary = 879,
	//! NodeId of the data type Range.
	EnumNumericNodeId_Range = 884,
	//! NodeId of the node Range/Encoding/DefaultXml.
	EnumNumericNodeId_Range_Encoding_DefaultXml = 885,
	//! NodeId of the node Range/Encoding/DefaultBinary.
	EnumNumericNodeId_Range_Encoding_DefaultBinary = 886,
	//! NodeId of the data type EUInformation.
	EnumNumericNodeId_EUInformation = 887,
	//! NodeId of the node EUInformation/Encoding/DefaultXml.
	EnumNumericNodeId_EUInformation_Encoding_DefaultXml = 888,
	//! NodeId of the node EUInformation/Encoding/DefaultBinary.
	EnumNumericNodeId_EUInformation_Encoding_DefaultBinary = 889,
	//! NodeId of the data type ExceptionDeviationFormat.
	EnumNumericNodeId_ExceptionDeviationFormat = 890,
	//! NodeId of the data type Annotation.
	EnumNumericNodeId_Annotation = 891,
	//! NodeId of the node Annotation/Encoding/DefaultXml.
	EnumNumericNodeId_Annotation_Encoding_DefaultXml = 892,
	//! NodeId of the node Annotation/Encoding/DefaultBinary.
	EnumNumericNodeId_Annotation_Encoding_DefaultBinary = 893,
	//! NodeId of the data type ProgramDiagnosticDataType.
	EnumNumericNodeId_ProgramDiagnosticDataType = 894,
	//! NodeId of the node ProgramDiagnosticDataType/Encoding/DefaultXml.
	EnumNumericNodeId_ProgramDiagnosticDataType_Encoding_DefaultXml = 895,
	//! NodeId of the node ProgramDiagnosticDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_ProgramDiagnosticDataType_Encoding_DefaultBinary = 896,
	//! NodeId of the data type SemanticChangeStructureDataType.
	EnumNumericNodeId_SemanticChangeStructureDataType = 897,
	//! NodeId of the node SemanticChangeStructureDataType/Encoding/DefaultXml.
	EnumNumericNodeId_SemanticChangeStructureDataType_Encoding_DefaultXml = 898,
	//! NodeId of the node SemanticChangeStructureDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_SemanticChangeStructureDataType_Encoding_DefaultBinary = 899,
	//! NodeId of the data type EventNotificationList.
	EnumNumericNodeId_EventNotificationList = 914,
	//! NodeId of the node EventNotificationList/Encoding/DefaultXml.
	EnumNumericNodeId_EventNotificationList_Encoding_DefaultXml = 915,
	//! NodeId of the node EventNotificationList/Encoding/DefaultBinary.
	EnumNumericNodeId_EventNotificationList_Encoding_DefaultBinary = 916,
	//! NodeId of the data type EventFieldList.
	EnumNumericNodeId_EventFieldList = 917,
	//! NodeId of the node EventFieldList/Encoding/DefaultXml.
	EnumNumericNodeId_EventFieldList_Encoding_DefaultXml = 918,
	//! NodeId of the node EventFieldList/Encoding/DefaultBinary.
	EnumNumericNodeId_EventFieldList_Encoding_DefaultBinary = 919,
	//! NodeId of the data type HistoryEventFieldList.
	EnumNumericNodeId_HistoryEventFieldList = 920,
	//! NodeId of the node HistoryEventFieldList/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryEventFieldList_Encoding_DefaultXml = 921,
	//! NodeId of the node HistoryEventFieldList/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryEventFieldList_Encoding_DefaultBinary = 922,
	//! NodeId of the data type IssuedIdentityToken.
	EnumNumericNodeId_IssuedIdentityToken = 938,
	//! NodeId of the node IssuedIdentityToken/Encoding/DefaultXml.
	EnumNumericNodeId_IssuedIdentityToken_Encoding_DefaultXml = 939,
	//! NodeId of the node IssuedIdentityToken/Encoding/DefaultBinary.
	EnumNumericNodeId_IssuedIdentityToken_Encoding_DefaultBinary = 940,
	//! NodeId of the data type NotificationData.
	EnumNumericNodeId_NotificationData = 945,
	//! NodeId of the node NotificationData/Encoding/DefaultXml.
	EnumNumericNodeId_NotificationData_Encoding_DefaultXml = 946,
	//! NodeId of the node NotificationData/Encoding/DefaultBinary.
	EnumNumericNodeId_NotificationData_Encoding_DefaultBinary = 947,
	//! NodeId of the data type AggregateConfiguration.
	EnumNumericNodeId_AggregateConfiguration = 948,
	//! NodeId of the node AggregateConfiguration/Encoding/DefaultXml.
	EnumNumericNodeId_AggregateConfiguration_Encoding_DefaultXml = 949,
	//! NodeId of the node AggregateConfiguration/Encoding/DefaultBinary.
	EnumNumericNodeId_AggregateConfiguration_Encoding_DefaultBinary = 950,
	//! NodeId of the data type ImageBMP.
	EnumNumericNodeId_ImageBMP = 2000,
	//! NodeId of the data type ImageGIF.
	EnumNumericNodeId_ImageGIF = 2001,
	//! NodeId of the data type ImageJPG.
	EnumNumericNodeId_ImageJPG = 2002,
	//! NodeId of the data type ImagePNG.
	EnumNumericNodeId_ImagePNG = 2003,
	//! NodeId of the object type ServerType.
	EnumNumericNodeId_ServerType = 2004,
	//! NodeId of the node ServerType/ServerArray.
	EnumNumericNodeId_ServerType_ServerArray = 2005,
	//! NodeId of the node ServerType/NamespaceArray.
	EnumNumericNodeId_ServerType_NamespaceArray = 2006,
	//! NodeId of the node ServerType/ServerStatus.
	EnumNumericNodeId_ServerType_ServerStatus = 2007,
	//! NodeId of the node ServerType/ServiceLevel.
	EnumNumericNodeId_ServerType_ServiceLevel = 2008,
	//! NodeId of the node ServerType/ServerCapabilities.
	EnumNumericNodeId_ServerType_ServerCapabilities = 2009,
	//! NodeId of the node ServerType/ServerDiagnostics.
	EnumNumericNodeId_ServerType_ServerDiagnostics = 2010,
	//! NodeId of the node ServerType/VendorServerInfo.
	EnumNumericNodeId_ServerType_VendorServerInfo = 2011,
	//! NodeId of the node ServerType/ServerRedundancy.
	EnumNumericNodeId_ServerType_ServerRedundancy = 2012,
	//! NodeId of the object type ServerCapabilitiesType.
	EnumNumericNodeId_ServerCapabilitiesType = 2013,
	//! NodeId of the node ServerCapabilitiesType/ServerProfileArray.
	EnumNumericNodeId_ServerCapabilitiesType_ServerProfileArray = 2014,
	//! NodeId of the node ServerCapabilitiesType/LocaleIdArray.
	EnumNumericNodeId_ServerCapabilitiesType_LocaleIdArray = 2016,
	//! NodeId of the node ServerCapabilitiesType/MinSupportedSampleRate.
	EnumNumericNodeId_ServerCapabilitiesType_MinSupportedSampleRate = 2017,
	//! NodeId of the node ServerCapabilitiesType/ModellingRules.
	EnumNumericNodeId_ServerCapabilitiesType_ModellingRules = 2019,
	//! NodeId of the object type ServerDiagnosticsType.
	EnumNumericNodeId_ServerDiagnosticsType = 2020,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary = 2021,
	//! NodeId of the node ServerDiagnosticsType/SamplingIntervalDiagnosticsArray.
	EnumNumericNodeId_ServerDiagnosticsType_SamplingIntervalDiagnosticsArray = 2022,
	//! NodeId of the node ServerDiagnosticsType/SubscriptionDiagnosticsArray.
	EnumNumericNodeId_ServerDiagnosticsType_SubscriptionDiagnosticsArray = 2023,
	//! NodeId of the node ServerDiagnosticsType/EnabledFlag.
	EnumNumericNodeId_ServerDiagnosticsType_EnabledFlag = 2025,
	//! NodeId of the object type SessionsDiagnosticsSummaryType.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType = 2026,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionDiagnosticsArray.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionDiagnosticsArray = 2027,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionSecurityDiagnosticsArray.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionSecurityDiagnosticsArray = 2028,
	//! NodeId of the object type SessionDiagnosticsObjectType.
	EnumNumericNodeId_SessionDiagnosticsObjectType = 2029,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics = 2030,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionSecurityDiagnostics.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionSecurityDiagnostics = 2031,
	//! NodeId of the node SessionDiagnosticsObjectType/SubscriptionDiagnosticsArray.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SubscriptionDiagnosticsArray = 2032,
	//! NodeId of the object type VendorServerInfoType.
	EnumNumericNodeId_VendorServerInfoType = 2033,
	//! NodeId of the object type ServerRedundancyType.
	EnumNumericNodeId_ServerRedundancyType = 2034,
	//! NodeId of the node ServerRedundancyType/RedundancySupport.
	EnumNumericNodeId_ServerRedundancyType_RedundancySupport = 2035,
	//! NodeId of the object type TransparentRedundancyType.
	EnumNumericNodeId_TransparentRedundancyType = 2036,
	//! NodeId of the node TransparentRedundancyType/CurrentServerId.
	EnumNumericNodeId_TransparentRedundancyType_CurrentServerId = 2037,
	//! NodeId of the node TransparentRedundancyType/RedundantServerArray.
	EnumNumericNodeId_TransparentRedundancyType_RedundantServerArray = 2038,
	//! NodeId of the object type NonTransparentRedundancyType.
	EnumNumericNodeId_NonTransparentRedundancyType = 2039,
	//! NodeId of the node NonTransparentRedundancyType/ServerUriArray.
	EnumNumericNodeId_NonTransparentRedundancyType_ServerUriArray = 2040,
	//! NodeId of the abstract object type BaseEventType.
	EnumNumericNodeId_BaseEventType = 2041,
	//! NodeId of the node BaseEventType/EventId.
	EnumNumericNodeId_BaseEventType_EventId = 2042,
	//! NodeId of the node BaseEventType/EventType.
	EnumNumericNodeId_BaseEventType_EventType = 2043,
	//! NodeId of the node BaseEventType/SourceNode.
	EnumNumericNodeId_BaseEventType_SourceNode = 2044,
	//! NodeId of the node BaseEventType/SourceName.
	EnumNumericNodeId_BaseEventType_SourceName = 2045,
	//! NodeId of the node BaseEventType/Time.
	EnumNumericNodeId_BaseEventType_Time = 2046,
	//! NodeId of the node BaseEventType/ReceiveTime.
	EnumNumericNodeId_BaseEventType_ReceiveTime = 2047,
	//! NodeId of the node BaseEventType/Message.
	EnumNumericNodeId_BaseEventType_Message = 2050,
	//! NodeId of the node BaseEventType/Severity.
	EnumNumericNodeId_BaseEventType_Severity = 2051,
	//! NodeId of the abstract object type AuditEventType.
	EnumNumericNodeId_AuditEventType = 2052,
	//! NodeId of the node AuditEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditEventType_ActionTimeStamp = 2053,
	//! NodeId of the node AuditEventType/Status.
	EnumNumericNodeId_AuditEventType_Status = 2054,
	//! NodeId of the node AuditEventType/ServerId.
	EnumNumericNodeId_AuditEventType_ServerId = 2055,
	//! NodeId of the node AuditEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditEventType_ClientAuditEntryId = 2056,
	//! NodeId of the node AuditEventType/ClientUserId.
	EnumNumericNodeId_AuditEventType_ClientUserId = 2057,
	//! NodeId of the abstract object type AuditSecurityEventType.
	EnumNumericNodeId_AuditSecurityEventType = 2058,
	//! NodeId of the abstract object type AuditChannelEventType.
	EnumNumericNodeId_AuditChannelEventType = 2059,
	//! NodeId of the abstract object type AuditOpenSecureChannelEventType.
	EnumNumericNodeId_AuditOpenSecureChannelEventType = 2060,
	//! NodeId of the node AuditOpenSecureChannelEventType/ClientCertificate.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_ClientCertificate = 2061,
	//! NodeId of the node AuditOpenSecureChannelEventType/RequestType.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_RequestType = 2062,
	//! NodeId of the node AuditOpenSecureChannelEventType/SecurityPolicyUri.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_SecurityPolicyUri = 2063,
	//! NodeId of the node AuditOpenSecureChannelEventType/SecurityMode.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_SecurityMode = 2065,
	//! NodeId of the node AuditOpenSecureChannelEventType/RequestedLifetime.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_RequestedLifetime = 2066,
	//! NodeId of the abstract object type AuditSessionEventType.
	EnumNumericNodeId_AuditSessionEventType = 2069,
	//! NodeId of the node AuditSessionEventType/SessionId.
	EnumNumericNodeId_AuditSessionEventType_SessionId = 2070,
	//! NodeId of the abstract object type AuditCreateSessionEventType.
	EnumNumericNodeId_AuditCreateSessionEventType = 2071,
	//! NodeId of the node AuditCreateSessionEventType/SecureChannelId.
	EnumNumericNodeId_AuditCreateSessionEventType_SecureChannelId = 2072,
	//! NodeId of the node AuditCreateSessionEventType/ClientCertificate.
	EnumNumericNodeId_AuditCreateSessionEventType_ClientCertificate = 2073,
	//! NodeId of the node AuditCreateSessionEventType/RevisedSessionTimeout.
	EnumNumericNodeId_AuditCreateSessionEventType_RevisedSessionTimeout = 2074,
	//! NodeId of the abstract object type AuditActivateSessionEventType.
	EnumNumericNodeId_AuditActivateSessionEventType = 2075,
	//! NodeId of the node AuditActivateSessionEventType/ClientSoftwareCertificates.
	EnumNumericNodeId_AuditActivateSessionEventType_ClientSoftwareCertificates = 2076,
	//! NodeId of the node AuditActivateSessionEventType/UserIdentityToken.
	EnumNumericNodeId_AuditActivateSessionEventType_UserIdentityToken = 2077,
	//! NodeId of the abstract object type AuditCancelEventType.
	EnumNumericNodeId_AuditCancelEventType = 2078,
	//! NodeId of the node AuditCancelEventType/RequestHandle.
	EnumNumericNodeId_AuditCancelEventType_RequestHandle = 2079,
	//! NodeId of the abstract object type AuditCertificateEventType.
	EnumNumericNodeId_AuditCertificateEventType = 2080,
	//! NodeId of the node AuditCertificateEventType/Certificate.
	EnumNumericNodeId_AuditCertificateEventType_Certificate = 2081,
	//! NodeId of the abstract object type AuditCertificateDataMismatchEventType.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType = 2082,
	//! NodeId of the node AuditCertificateDataMismatchEventType/InvalidHostname.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_InvalidHostname = 2083,
	//! NodeId of the node AuditCertificateDataMismatchEventType/InvalidUri.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_InvalidUri = 2084,
	//! NodeId of the abstract object type AuditCertificateExpiredEventType.
	EnumNumericNodeId_AuditCertificateExpiredEventType = 2085,
	//! NodeId of the abstract object type AuditCertificateInvalidEventType.
	EnumNumericNodeId_AuditCertificateInvalidEventType = 2086,
	//! NodeId of the abstract object type AuditCertificateUntrustedEventType.
	EnumNumericNodeId_AuditCertificateUntrustedEventType = 2087,
	//! NodeId of the abstract object type AuditCertificateRevokedEventType.
	EnumNumericNodeId_AuditCertificateRevokedEventType = 2088,
	//! NodeId of the abstract object type AuditCertificateMismatchEventType.
	EnumNumericNodeId_AuditCertificateMismatchEventType = 2089,
	//! NodeId of the abstract object type AuditNodeManagementEventType.
	EnumNumericNodeId_AuditNodeManagementEventType = 2090,
	//! NodeId of the abstract object type AuditAddNodesEventType.
	EnumNumericNodeId_AuditAddNodesEventType = 2091,
	//! NodeId of the node AuditAddNodesEventType/NodesToAdd.
	EnumNumericNodeId_AuditAddNodesEventType_NodesToAdd = 2092,
	//! NodeId of the abstract object type AuditDeleteNodesEventType.
	EnumNumericNodeId_AuditDeleteNodesEventType = 2093,
	//! NodeId of the node AuditDeleteNodesEventType/NodesToDelete.
	EnumNumericNodeId_AuditDeleteNodesEventType_NodesToDelete = 2094,
	//! NodeId of the abstract object type AuditAddReferencesEventType.
	EnumNumericNodeId_AuditAddReferencesEventType = 2095,
	//! NodeId of the node AuditAddReferencesEventType/ReferencesToAdd.
	EnumNumericNodeId_AuditAddReferencesEventType_ReferencesToAdd = 2096,
	//! NodeId of the abstract object type AuditDeleteReferencesEventType.
	EnumNumericNodeId_AuditDeleteReferencesEventType = 2097,
	//! NodeId of the node AuditDeleteReferencesEventType/ReferencesToDelete.
	EnumNumericNodeId_AuditDeleteReferencesEventType_ReferencesToDelete = 2098,
	//! NodeId of the abstract object type AuditUpdateEventType.
	EnumNumericNodeId_AuditUpdateEventType = 2099,
	//! NodeId of the abstract object type AuditWriteUpdateEventType.
	EnumNumericNodeId_AuditWriteUpdateEventType = 2100,
	//! NodeId of the node AuditWriteUpdateEventType/IndexRange.
	EnumNumericNodeId_AuditWriteUpdateEventType_IndexRange = 2101,
	//! NodeId of the node AuditWriteUpdateEventType/OldValue.
	EnumNumericNodeId_AuditWriteUpdateEventType_OldValue = 2102,
	//! NodeId of the node AuditWriteUpdateEventType/NewValue.
	EnumNumericNodeId_AuditWriteUpdateEventType_NewValue = 2103,
	//! NodeId of the abstract object type AuditHistoryUpdateEventType.
	EnumNumericNodeId_AuditHistoryUpdateEventType = 2104,
	//! NodeId of the abstract object type AuditUpdateMethodEventType.
	EnumNumericNodeId_AuditUpdateMethodEventType = 2127,
	//! NodeId of the node AuditUpdateMethodEventType/MethodId.
	EnumNumericNodeId_AuditUpdateMethodEventType_MethodId = 2128,
	//! NodeId of the node AuditUpdateMethodEventType/InputArguments.
	EnumNumericNodeId_AuditUpdateMethodEventType_InputArguments = 2129,
	//! NodeId of the abstract object type SystemEventType.
	EnumNumericNodeId_SystemEventType = 2130,
	//! NodeId of the abstract object type DeviceFailureEventType.
	EnumNumericNodeId_DeviceFailureEventType = 2131,
	//! NodeId of the abstract object type BaseModelChangeEventType.
	EnumNumericNodeId_BaseModelChangeEventType = 2132,
	//! NodeId of the abstract object type GeneralModelChangeEventType.
	EnumNumericNodeId_GeneralModelChangeEventType = 2133,
	//! NodeId of the node GeneralModelChangeEventType/Changes.
	EnumNumericNodeId_GeneralModelChangeEventType_Changes = 2134,
	//! NodeId of the variable type ServerVendorCapabilityType.
	EnumNumericNodeId_ServerVendorCapabilityType = 2137,
	//! NodeId of the variable type ServerStatusType.
	EnumNumericNodeId_ServerStatusType = 2138,
	//! NodeId of the node ServerStatusType/StartTime.
	EnumNumericNodeId_ServerStatusType_StartTime = 2139,
	//! NodeId of the node ServerStatusType/CurrentTime.
	EnumNumericNodeId_ServerStatusType_CurrentTime = 2140,
	//! NodeId of the node ServerStatusType/State.
	EnumNumericNodeId_ServerStatusType_State = 2141,
	//! NodeId of the node ServerStatusType/BuildInfo.
	EnumNumericNodeId_ServerStatusType_BuildInfo = 2142,
	//! NodeId of the variable type ServerDiagnosticsSummaryType.
	EnumNumericNodeId_ServerDiagnosticsSummaryType = 2150,
	//! NodeId of the node ServerDiagnosticsSummaryType/ServerViewCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_ServerViewCount = 2151,
	//! NodeId of the node ServerDiagnosticsSummaryType/CurrentSessionCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_CurrentSessionCount = 2152,
	//! NodeId of the node ServerDiagnosticsSummaryType/CumulatedSessionCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_CumulatedSessionCount = 2153,
	//! NodeId of the node ServerDiagnosticsSummaryType/SecurityRejectedSessionCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_SecurityRejectedSessionCount = 2154,
	//! NodeId of the node ServerDiagnosticsSummaryType/RejectedSessionCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_RejectedSessionCount = 2155,
	//! NodeId of the node ServerDiagnosticsSummaryType/SessionTimeoutCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_SessionTimeoutCount = 2156,
	//! NodeId of the node ServerDiagnosticsSummaryType/SessionAbortCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_SessionAbortCount = 2157,
	//! NodeId of the node ServerDiagnosticsSummaryType/PublishingIntervalCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_PublishingIntervalCount = 2159,
	//! NodeId of the node ServerDiagnosticsSummaryType/CurrentSubscriptionCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_CurrentSubscriptionCount = 2160,
	//! NodeId of the node ServerDiagnosticsSummaryType/CumulatedSubscriptionCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_CumulatedSubscriptionCount = 2161,
	//! NodeId of the node ServerDiagnosticsSummaryType/SecurityRejectedRequestsCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_SecurityRejectedRequestsCount = 2162,
	//! NodeId of the node ServerDiagnosticsSummaryType/RejectedRequestsCount.
	EnumNumericNodeId_ServerDiagnosticsSummaryType_RejectedRequestsCount = 2163,
	//! NodeId of the variable type SamplingIntervalDiagnosticsArrayType.
	EnumNumericNodeId_SamplingIntervalDiagnosticsArrayType = 2164,
	//! NodeId of the variable type SamplingIntervalDiagnosticsType.
	EnumNumericNodeId_SamplingIntervalDiagnosticsType = 2165,
	//! NodeId of the node SamplingIntervalDiagnosticsType/SamplingInterval.
	EnumNumericNodeId_SamplingIntervalDiagnosticsType_SamplingInterval = 2166,
	//! NodeId of the variable type SubscriptionDiagnosticsArrayType.
	EnumNumericNodeId_SubscriptionDiagnosticsArrayType = 2171,
	//! NodeId of the variable type SubscriptionDiagnosticsType.
	EnumNumericNodeId_SubscriptionDiagnosticsType = 2172,
	//! NodeId of the node SubscriptionDiagnosticsType/SessionId.
	EnumNumericNodeId_SubscriptionDiagnosticsType_SessionId = 2173,
	//! NodeId of the node SubscriptionDiagnosticsType/SubscriptionId.
	EnumNumericNodeId_SubscriptionDiagnosticsType_SubscriptionId = 2174,
	//! NodeId of the node SubscriptionDiagnosticsType/Priority.
	EnumNumericNodeId_SubscriptionDiagnosticsType_Priority = 2175,
	//! NodeId of the node SubscriptionDiagnosticsType/PublishingInterval.
	EnumNumericNodeId_SubscriptionDiagnosticsType_PublishingInterval = 2176,
	//! NodeId of the node SubscriptionDiagnosticsType/MaxKeepAliveCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_MaxKeepAliveCount = 2177,
	//! NodeId of the node SubscriptionDiagnosticsType/MaxNotificationsPerPublish.
	EnumNumericNodeId_SubscriptionDiagnosticsType_MaxNotificationsPerPublish = 2179,
	//! NodeId of the node SubscriptionDiagnosticsType/PublishingEnabled.
	EnumNumericNodeId_SubscriptionDiagnosticsType_PublishingEnabled = 2180,
	//! NodeId of the node SubscriptionDiagnosticsType/ModifyCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_ModifyCount = 2181,
	//! NodeId of the node SubscriptionDiagnosticsType/EnableCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_EnableCount = 2182,
	//! NodeId of the node SubscriptionDiagnosticsType/DisableCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_DisableCount = 2183,
	//! NodeId of the node SubscriptionDiagnosticsType/RepublishRequestCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_RepublishRequestCount = 2184,
	//! NodeId of the node SubscriptionDiagnosticsType/RepublishMessageRequestCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_RepublishMessageRequestCount = 2185,
	//! NodeId of the node SubscriptionDiagnosticsType/RepublishMessageCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_RepublishMessageCount = 2186,
	//! NodeId of the node SubscriptionDiagnosticsType/TransferRequestCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_TransferRequestCount = 2187,
	//! NodeId of the node SubscriptionDiagnosticsType/TransferredToAltClientCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_TransferredToAltClientCount = 2188,
	//! NodeId of the node SubscriptionDiagnosticsType/TransferredToSameClientCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_TransferredToSameClientCount = 2189,
	//! NodeId of the node SubscriptionDiagnosticsType/PublishRequestCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_PublishRequestCount = 2190,
	//! NodeId of the node SubscriptionDiagnosticsType/DataChangeNotificationsCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_DataChangeNotificationsCount = 2191,
	//! NodeId of the node SubscriptionDiagnosticsType/NotificationsCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_NotificationsCount = 2193,
	//! NodeId of the variable type SessionDiagnosticsArrayType.
	EnumNumericNodeId_SessionDiagnosticsArrayType = 2196,
	//! NodeId of the variable type SessionDiagnosticsVariableType.
	EnumNumericNodeId_SessionDiagnosticsVariableType = 2197,
	//! NodeId of the node SessionDiagnosticsVariableType/SessionId.
	EnumNumericNodeId_SessionDiagnosticsVariableType_SessionId = 2198,
	//! NodeId of the node SessionDiagnosticsVariableType/SessionName.
	EnumNumericNodeId_SessionDiagnosticsVariableType_SessionName = 2199,
	//! NodeId of the node SessionDiagnosticsVariableType/ClientDescription.
	EnumNumericNodeId_SessionDiagnosticsVariableType_ClientDescription = 2200,
	//! NodeId of the node SessionDiagnosticsVariableType/ServerUri.
	EnumNumericNodeId_SessionDiagnosticsVariableType_ServerUri = 2201,
	//! NodeId of the node SessionDiagnosticsVariableType/EndpointUrl.
	EnumNumericNodeId_SessionDiagnosticsVariableType_EndpointUrl = 2202,
	//! NodeId of the node SessionDiagnosticsVariableType/LocaleIds.
	EnumNumericNodeId_SessionDiagnosticsVariableType_LocaleIds = 2203,
	//! NodeId of the node SessionDiagnosticsVariableType/ActualSessionTimeout.
	EnumNumericNodeId_SessionDiagnosticsVariableType_ActualSessionTimeout = 2204,
	//! NodeId of the node SessionDiagnosticsVariableType/ClientConnectionTime.
	EnumNumericNodeId_SessionDiagnosticsVariableType_ClientConnectionTime = 2205,
	//! NodeId of the node SessionDiagnosticsVariableType/ClientLastContactTime.
	EnumNumericNodeId_SessionDiagnosticsVariableType_ClientLastContactTime = 2206,
	//! NodeId of the node SessionDiagnosticsVariableType/CurrentSubscriptionsCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_CurrentSubscriptionsCount = 2207,
	//! NodeId of the node SessionDiagnosticsVariableType/CurrentMonitoredItemsCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_CurrentMonitoredItemsCount = 2208,
	//! NodeId of the node SessionDiagnosticsVariableType/CurrentPublishRequestsInQueue.
	EnumNumericNodeId_SessionDiagnosticsVariableType_CurrentPublishRequestsInQueue = 2209,
	//! NodeId of the node SessionDiagnosticsVariableType/ReadCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_ReadCount = 2217,
	//! NodeId of the node SessionDiagnosticsVariableType/HistoryReadCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_HistoryReadCount = 2218,
	//! NodeId of the node SessionDiagnosticsVariableType/WriteCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_WriteCount = 2219,
	//! NodeId of the node SessionDiagnosticsVariableType/HistoryUpdateCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_HistoryUpdateCount = 2220,
	//! NodeId of the node SessionDiagnosticsVariableType/CallCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_CallCount = 2221,
	//! NodeId of the node SessionDiagnosticsVariableType/CreateMonitoredItemsCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_CreateMonitoredItemsCount = 2222,
	//! NodeId of the node SessionDiagnosticsVariableType/ModifyMonitoredItemsCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_ModifyMonitoredItemsCount = 2223,
	//! NodeId of the node SessionDiagnosticsVariableType/SetMonitoringModeCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_SetMonitoringModeCount = 2224,
	//! NodeId of the node SessionDiagnosticsVariableType/SetTriggeringCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_SetTriggeringCount = 2225,
	//! NodeId of the node SessionDiagnosticsVariableType/DeleteMonitoredItemsCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_DeleteMonitoredItemsCount = 2226,
	//! NodeId of the node SessionDiagnosticsVariableType/CreateSubscriptionCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_CreateSubscriptionCount = 2227,
	//! NodeId of the node SessionDiagnosticsVariableType/ModifySubscriptionCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_ModifySubscriptionCount = 2228,
	//! NodeId of the node SessionDiagnosticsVariableType/SetPublishingModeCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_SetPublishingModeCount = 2229,
	//! NodeId of the node SessionDiagnosticsVariableType/PublishCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_PublishCount = 2230,
	//! NodeId of the node SessionDiagnosticsVariableType/RepublishCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_RepublishCount = 2231,
	//! NodeId of the node SessionDiagnosticsVariableType/TransferSubscriptionsCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_TransferSubscriptionsCount = 2232,
	//! NodeId of the node SessionDiagnosticsVariableType/DeleteSubscriptionsCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_DeleteSubscriptionsCount = 2233,
	//! NodeId of the node SessionDiagnosticsVariableType/AddNodesCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_AddNodesCount = 2234,
	//! NodeId of the node SessionDiagnosticsVariableType/AddReferencesCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_AddReferencesCount = 2235,
	//! NodeId of the node SessionDiagnosticsVariableType/DeleteNodesCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_DeleteNodesCount = 2236,
	//! NodeId of the node SessionDiagnosticsVariableType/DeleteReferencesCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_DeleteReferencesCount = 2237,
	//! NodeId of the node SessionDiagnosticsVariableType/BrowseCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_BrowseCount = 2238,
	//! NodeId of the node SessionDiagnosticsVariableType/BrowseNextCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_BrowseNextCount = 2239,
	//! NodeId of the node SessionDiagnosticsVariableType/TranslateBrowsePathsToNodeIdsCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_TranslateBrowsePathsToNodeIdsCount = 2240,
	//! NodeId of the node SessionDiagnosticsVariableType/QueryFirstCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_QueryFirstCount = 2241,
	//! NodeId of the node SessionDiagnosticsVariableType/QueryNextCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_QueryNextCount = 2242,
	//! NodeId of the variable type SessionSecurityDiagnosticsArrayType.
	EnumNumericNodeId_SessionSecurityDiagnosticsArrayType = 2243,
	//! NodeId of the variable type SessionSecurityDiagnosticsType.
	EnumNumericNodeId_SessionSecurityDiagnosticsType = 2244,
	//! NodeId of the node SessionSecurityDiagnosticsType/SessionId.
	EnumNumericNodeId_SessionSecurityDiagnosticsType_SessionId = 2245,
	//! NodeId of the node SessionSecurityDiagnosticsType/ClientUserIdOfSession.
	EnumNumericNodeId_SessionSecurityDiagnosticsType_ClientUserIdOfSession = 2246,
	//! NodeId of the node SessionSecurityDiagnosticsType/ClientUserIdHistory.
	EnumNumericNodeId_SessionSecurityDiagnosticsType_ClientUserIdHistory = 2247,
	//! NodeId of the node SessionSecurityDiagnosticsType/AuthenticationMechanism.
	EnumNumericNodeId_SessionSecurityDiagnosticsType_AuthenticationMechanism = 2248,
	//! NodeId of the node SessionSecurityDiagnosticsType/Encoding.
	EnumNumericNodeId_SessionSecurityDiagnosticsType_Encoding = 2249,
	//! NodeId of the node SessionSecurityDiagnosticsType/TransportProtocol.
	EnumNumericNodeId_SessionSecurityDiagnosticsType_TransportProtocol = 2250,
	//! NodeId of the node SessionSecurityDiagnosticsType/SecurityMode.
	EnumNumericNodeId_SessionSecurityDiagnosticsType_SecurityMode = 2251,
	//! NodeId of the node SessionSecurityDiagnosticsType/SecurityPolicyUri.
	EnumNumericNodeId_SessionSecurityDiagnosticsType_SecurityPolicyUri = 2252,
	//! NodeId of the node Server.
	EnumNumericNodeId_Server = 2253,
	//! NodeId of the node Server/ServerArray.
	EnumNumericNodeId_Server_ServerArray = 2254,
	//! NodeId of the node Server/NamespaceArray.
	EnumNumericNodeId_Server_NamespaceArray = 2255,
	//! NodeId of the node Server/ServerStatus.
	EnumNumericNodeId_Server_ServerStatus = 2256,
	//! NodeId of the node Server/ServerStatus/StartTime.
	EnumNumericNodeId_Server_ServerStatus_StartTime = 2257,
	//! NodeId of the node Server/ServerStatus/CurrentTime.
	EnumNumericNodeId_Server_ServerStatus_CurrentTime = 2258,
	//! NodeId of the node Server/ServerStatus/State.
	EnumNumericNodeId_Server_ServerStatus_State = 2259,
	//! NodeId of the node Server/ServerStatus/BuildInfo.
	EnumNumericNodeId_Server_ServerStatus_BuildInfo = 2260,
	//! NodeId of the node Server/ServerStatus/BuildInfo/ProductName.
	EnumNumericNodeId_Server_ServerStatus_BuildInfo_ProductName = 2261,
	//! NodeId of the node Server/ServerStatus/BuildInfo/ProductUri.
	EnumNumericNodeId_Server_ServerStatus_BuildInfo_ProductUri = 2262,
	//! NodeId of the node Server/ServerStatus/BuildInfo/ManufacturerName.
	EnumNumericNodeId_Server_ServerStatus_BuildInfo_ManufacturerName = 2263,
	//! NodeId of the node Server/ServerStatus/BuildInfo/SoftwareVersion.
	EnumNumericNodeId_Server_ServerStatus_BuildInfo_SoftwareVersion = 2264,
	//! NodeId of the node Server/ServerStatus/BuildInfo/BuildNumber.
	EnumNumericNodeId_Server_ServerStatus_BuildInfo_BuildNumber = 2265,
	//! NodeId of the node Server/ServerStatus/BuildInfo/BuildDate.
	EnumNumericNodeId_Server_ServerStatus_BuildInfo_BuildDate = 2266,
	//! NodeId of the node Server/ServiceLevel.
	EnumNumericNodeId_Server_ServiceLevel = 2267,
	//! NodeId of the node Server/ServerCapabilities.
	EnumNumericNodeId_Server_ServerCapabilities = 2268,
	//! NodeId of the node Server/ServerCapabilities/ServerProfileArray.
	EnumNumericNodeId_Server_ServerCapabilities_ServerProfileArray = 2269,
	//! NodeId of the node Server/ServerCapabilities/LocaleIdArray.
	EnumNumericNodeId_Server_ServerCapabilities_LocaleIdArray = 2271,
	//! NodeId of the node Server/ServerCapabilities/MinSupportedSampleRate.
	EnumNumericNodeId_Server_ServerCapabilities_MinSupportedSampleRate = 2272,
	//! NodeId of the node Server/ServerDiagnostics.
	EnumNumericNodeId_Server_ServerDiagnostics = 2274,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary = 2275,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/ServerViewCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_ServerViewCount = 2276,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/CurrentSessionCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount = 2277,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/CumulatedSessionCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount = 2278,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/SecurityRejectedSessionCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount = 2279,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/SessionTimeoutCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount = 2281,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/SessionAbortCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_SessionAbortCount = 2282,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/PublishingIntervalCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount = 2284,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/CurrentSubscriptionCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount = 2285,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/CumulatedSubscriptionCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount = 2286,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/SecurityRejectedRequestsCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount = 2287,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/RejectedRequestsCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount = 2288,
	//! NodeId of the node Server/ServerDiagnostics/SamplingIntervalDiagnosticsArray.
	EnumNumericNodeId_Server_ServerDiagnostics_SamplingIntervalDiagnosticsArray = 2289,
	//! NodeId of the node Server/ServerDiagnostics/SubscriptionDiagnosticsArray.
	EnumNumericNodeId_Server_ServerDiagnostics_SubscriptionDiagnosticsArray = 2290,
	//! NodeId of the node Server/ServerDiagnostics/EnabledFlag.
	EnumNumericNodeId_Server_ServerDiagnostics_EnabledFlag = 2294,
	//! NodeId of the node Server/VendorServerInfo.
	EnumNumericNodeId_Server_VendorServerInfo = 2295,
	//! NodeId of the node Server/ServerRedundancy.
	EnumNumericNodeId_Server_ServerRedundancy = 2296,
	//! NodeId of the object type StateMachineType.
	EnumNumericNodeId_StateMachineType = 2299,
	//! NodeId of the object type StateType.
	EnumNumericNodeId_StateType = 2307,
	//! NodeId of the node StateType/StateNumber.
	EnumNumericNodeId_StateType_StateNumber = 2308,
	//! NodeId of the object type InitialStateType.
	EnumNumericNodeId_InitialStateType = 2309,
	//! NodeId of the object type TransitionType.
	EnumNumericNodeId_TransitionType = 2310,
	//! NodeId of the object type TransitionEventType.
	EnumNumericNodeId_TransitionEventType = 2311,
	//! NodeId of the node TransitionType/TransitionNumber.
	EnumNumericNodeId_TransitionType_TransitionNumber = 2312,
	//! NodeId of the abstract object type AuditUpdateStateEventType.
	EnumNumericNodeId_AuditUpdateStateEventType = 2315,
	//! NodeId of the object type HistoricalDataConfigurationType.
	EnumNumericNodeId_HistoricalDataConfigurationType = 2318,
	//! NodeId of the node HistoricalDataConfigurationType/Stepped.
	EnumNumericNodeId_HistoricalDataConfigurationType_Stepped = 2323,
	//! NodeId of the node HistoricalDataConfigurationType/Definition.
	EnumNumericNodeId_HistoricalDataConfigurationType_Definition = 2324,
	//! NodeId of the node HistoricalDataConfigurationType/MaxTimeInterval.
	EnumNumericNodeId_HistoricalDataConfigurationType_MaxTimeInterval = 2325,
	//! NodeId of the node HistoricalDataConfigurationType/MinTimeInterval.
	EnumNumericNodeId_HistoricalDataConfigurationType_MinTimeInterval = 2326,
	//! NodeId of the node HistoricalDataConfigurationType/ExceptionDeviation.
	EnumNumericNodeId_HistoricalDataConfigurationType_ExceptionDeviation = 2327,
	//! NodeId of the node HistoricalDataConfigurationType/ExceptionDeviationFormat.
	EnumNumericNodeId_HistoricalDataConfigurationType_ExceptionDeviationFormat = 2328,
	//! NodeId of the object type HistoryServerCapabilitiesType.
	EnumNumericNodeId_HistoryServerCapabilitiesType = 2330,
	//! NodeId of the node HistoryServerCapabilitiesType/AccessHistoryDataCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_AccessHistoryDataCapability = 2331,
	//! NodeId of the node HistoryServerCapabilitiesType/AccessHistoryEventsCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_AccessHistoryEventsCapability = 2332,
	//! NodeId of the node HistoryServerCapabilitiesType/InsertDataCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_InsertDataCapability = 2334,
	//! NodeId of the node HistoryServerCapabilitiesType/ReplaceDataCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_ReplaceDataCapability = 2335,
	//! NodeId of the node HistoryServerCapabilitiesType/UpdateDataCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_UpdateDataCapability = 2336,
	//! NodeId of the node HistoryServerCapabilitiesType/DeleteRawCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_DeleteRawCapability = 2337,
	//! NodeId of the node HistoryServerCapabilitiesType/DeleteAtTimeCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_DeleteAtTimeCapability = 2338,
	//! NodeId of the object type AggregateFunctionType.
	EnumNumericNodeId_AggregateFunctionType = 2340,
	//! NodeId of the node AggregateFunction/Interpolative.
	EnumNumericNodeId_AggregateFunction_Interpolative = 2341,
	//! NodeId of the node AggregateFunction/Average.
	EnumNumericNodeId_AggregateFunction_Average = 2342,
	//! NodeId of the node AggregateFunction/TimeAverage.
	EnumNumericNodeId_AggregateFunction_TimeAverage = 2343,
	//! NodeId of the node AggregateFunction/Total.
	EnumNumericNodeId_AggregateFunction_Total = 2344,
	//! NodeId of the node AggregateFunction/Minimum.
	EnumNumericNodeId_AggregateFunction_Minimum = 2346,
	//! NodeId of the node AggregateFunction/Maximum.
	EnumNumericNodeId_AggregateFunction_Maximum = 2347,
	//! NodeId of the node AggregateFunction/MinimumActualTime.
	EnumNumericNodeId_AggregateFunction_MinimumActualTime = 2348,
	//! NodeId of the node AggregateFunction/MaximumActualTime.
	EnumNumericNodeId_AggregateFunction_MaximumActualTime = 2349,
	//! NodeId of the node AggregateFunction/Range.
	EnumNumericNodeId_AggregateFunction_Range = 2350,
	//! NodeId of the node AggregateFunction/AnnotationCount.
	EnumNumericNodeId_AggregateFunction_AnnotationCount = 2351,
	//! NodeId of the node AggregateFunction/Count.
	EnumNumericNodeId_AggregateFunction_Count = 2352,
	//! NodeId of the node AggregateFunction/NumberOfTransitions.
	EnumNumericNodeId_AggregateFunction_NumberOfTransitions = 2355,
	//! NodeId of the node AggregateFunction/Start.
	EnumNumericNodeId_AggregateFunction_Start = 2357,
	//! NodeId of the node AggregateFunction/End.
	EnumNumericNodeId_AggregateFunction_End = 2358,
	//! NodeId of the node AggregateFunction/Delta.
	EnumNumericNodeId_AggregateFunction_Delta = 2359,
	//! NodeId of the node AggregateFunction/DurationGood.
	EnumNumericNodeId_AggregateFunction_DurationGood = 2360,
	//! NodeId of the node AggregateFunction/DurationBad.
	EnumNumericNodeId_AggregateFunction_DurationBad = 2361,
	//! NodeId of the node AggregateFunction/PercentGood.
	EnumNumericNodeId_AggregateFunction_PercentGood = 2362,
	//! NodeId of the node AggregateFunction/PercentBad.
	EnumNumericNodeId_AggregateFunction_PercentBad = 2363,
	//! NodeId of the node AggregateFunction/WorstQuality.
	EnumNumericNodeId_AggregateFunction_WorstQuality = 2364,
	//! NodeId of the variable type DataItemType.
	EnumNumericNodeId_DataItemType = 2365,
	//! NodeId of the node DataItemType/Definition.
	EnumNumericNodeId_DataItemType_Definition = 2366,
	//! NodeId of the node DataItemType/ValuePrecision.
	EnumNumericNodeId_DataItemType_ValuePrecision = 2367,
	//! NodeId of the variable type AnalogItemType.
	EnumNumericNodeId_AnalogItemType = 2368,
	//! NodeId of the node AnalogItemType/EURange.
	EnumNumericNodeId_AnalogItemType_EURange = 2369,
	//! NodeId of the node AnalogItemType/InstrumentRange.
	EnumNumericNodeId_AnalogItemType_InstrumentRange = 2370,
	//! NodeId of the node AnalogItemType/EngineeringUnits.
	EnumNumericNodeId_AnalogItemType_EngineeringUnits = 2371,
	//! NodeId of the variable type DiscreteItemType.
	EnumNumericNodeId_DiscreteItemType = 2372,
	//! NodeId of the variable type TwoStateDiscreteType.
	EnumNumericNodeId_TwoStateDiscreteType = 2373,
	//! NodeId of the node TwoStateDiscreteType/FalseState.
	EnumNumericNodeId_TwoStateDiscreteType_FalseState = 2374,
	//! NodeId of the node TwoStateDiscreteType/TrueState.
	EnumNumericNodeId_TwoStateDiscreteType_TrueState = 2375,
	//! NodeId of the variable type MultiStateDiscreteType.
	EnumNumericNodeId_MultiStateDiscreteType = 2376,
	//! NodeId of the node MultiStateDiscreteType/EnumStrings.
	EnumNumericNodeId_MultiStateDiscreteType_EnumStrings = 2377,
	//! NodeId of the object type ProgramTransitionEventType.
	EnumNumericNodeId_ProgramTransitionEventType = 2378,
	//! NodeId of the node ProgramTransitionEventType/IntermediateResult.
	EnumNumericNodeId_ProgramTransitionEventType_IntermediateResult = 2379,
	//! NodeId of the variable type ProgramDiagnosticType.
	EnumNumericNodeId_ProgramDiagnosticType = 2380,
	//! NodeId of the node ProgramDiagnosticType/CreateSessionId.
	EnumNumericNodeId_ProgramDiagnosticType_CreateSessionId = 2381,
	//! NodeId of the node ProgramDiagnosticType/CreateClientName.
	EnumNumericNodeId_ProgramDiagnosticType_CreateClientName = 2382,
	//! NodeId of the node ProgramDiagnosticType/InvocationCreationTime.
	EnumNumericNodeId_ProgramDiagnosticType_InvocationCreationTime = 2383,
	//! NodeId of the node ProgramDiagnosticType/LastTransitionTime.
	EnumNumericNodeId_ProgramDiagnosticType_LastTransitionTime = 2384,
	//! NodeId of the node ProgramDiagnosticType/LastMethodCall.
	EnumNumericNodeId_ProgramDiagnosticType_LastMethodCall = 2385,
	//! NodeId of the node ProgramDiagnosticType/LastMethodSessionId.
	EnumNumericNodeId_ProgramDiagnosticType_LastMethodSessionId = 2386,
	//! NodeId of the node ProgramDiagnosticType/LastMethodInputArguments.
	EnumNumericNodeId_ProgramDiagnosticType_LastMethodInputArguments = 2387,
	//! NodeId of the node ProgramDiagnosticType/LastMethodOutputArguments.
	EnumNumericNodeId_ProgramDiagnosticType_LastMethodOutputArguments = 2388,
	//! NodeId of the node ProgramDiagnosticType/LastMethodCallTime.
	EnumNumericNodeId_ProgramDiagnosticType_LastMethodCallTime = 2389,
	//! NodeId of the node ProgramDiagnosticType/LastMethodReturnStatus.
	EnumNumericNodeId_ProgramDiagnosticType_LastMethodReturnStatus = 2390,
	//! NodeId of the object type ProgramStateMachineType.
	EnumNumericNodeId_ProgramStateMachineType = 2391,
	//! NodeId of the node ProgramStateMachineType/Creatable.
	EnumNumericNodeId_ProgramStateMachineType_Creatable = 2392,
	//! NodeId of the node ProgramStateMachineType/Deletable.
	EnumNumericNodeId_ProgramStateMachineType_Deletable = 2393,
	//! NodeId of the node ProgramStateMachineType/AutoDelete.
	EnumNumericNodeId_ProgramStateMachineType_AutoDelete = 2394,
	//! NodeId of the node ProgramStateMachineType/RecycleCount.
	EnumNumericNodeId_ProgramStateMachineType_RecycleCount = 2395,
	//! NodeId of the node ProgramStateMachineType/InstanceCount.
	EnumNumericNodeId_ProgramStateMachineType_InstanceCount = 2396,
	//! NodeId of the node ProgramStateMachineType/MaxInstanceCount.
	EnumNumericNodeId_ProgramStateMachineType_MaxInstanceCount = 2397,
	//! NodeId of the node ProgramStateMachineType/MaxRecycleCount.
	EnumNumericNodeId_ProgramStateMachineType_MaxRecycleCount = 2398,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics = 2399,
	//! NodeId of the node ProgramStateMachineType/Ready.
	EnumNumericNodeId_ProgramStateMachineType_Ready = 2400,
	//! NodeId of the node ProgramStateMachineType/Ready/StateNumber.
	EnumNumericNodeId_ProgramStateMachineType_Ready_StateNumber = 2401,
	//! NodeId of the node ProgramStateMachineType/Running.
	EnumNumericNodeId_ProgramStateMachineType_Running = 2402,
	//! NodeId of the node ProgramStateMachineType/Running/StateNumber.
	EnumNumericNodeId_ProgramStateMachineType_Running_StateNumber = 2403,
	//! NodeId of the node ProgramStateMachineType/Suspended.
	EnumNumericNodeId_ProgramStateMachineType_Suspended = 2404,
	//! NodeId of the node ProgramStateMachineType/Suspended/StateNumber.
	EnumNumericNodeId_ProgramStateMachineType_Suspended_StateNumber = 2405,
	//! NodeId of the node ProgramStateMachineType/Halted.
	EnumNumericNodeId_ProgramStateMachineType_Halted = 2406,
	//! NodeId of the node ProgramStateMachineType/Halted/StateNumber.
	EnumNumericNodeId_ProgramStateMachineType_Halted_StateNumber = 2407,
	//! NodeId of the node ProgramStateMachineType/HaltedToReady.
	EnumNumericNodeId_ProgramStateMachineType_HaltedToReady = 2408,
	//! NodeId of the node ProgramStateMachineType/HaltedToReady/TransitionNumber.
	EnumNumericNodeId_ProgramStateMachineType_HaltedToReady_TransitionNumber = 2409,
	//! NodeId of the node ProgramStateMachineType/ReadyToRunning.
	EnumNumericNodeId_ProgramStateMachineType_ReadyToRunning = 2410,
	//! NodeId of the node ProgramStateMachineType/ReadyToRunning/TransitionNumber.
	EnumNumericNodeId_ProgramStateMachineType_ReadyToRunning_TransitionNumber = 2411,
	//! NodeId of the node ProgramStateMachineType/RunningToHalted.
	EnumNumericNodeId_ProgramStateMachineType_RunningToHalted = 2412,
	//! NodeId of the node ProgramStateMachineType/RunningToHalted/TransitionNumber.
	EnumNumericNodeId_ProgramStateMachineType_RunningToHalted_TransitionNumber = 2413,
	//! NodeId of the node ProgramStateMachineType/RunningToReady.
	EnumNumericNodeId_ProgramStateMachineType_RunningToReady = 2414,
	//! NodeId of the node ProgramStateMachineType/RunningToReady/TransitionNumber.
	EnumNumericNodeId_ProgramStateMachineType_RunningToReady_TransitionNumber = 2415,
	//! NodeId of the node ProgramStateMachineType/RunningToSuspended.
	EnumNumericNodeId_ProgramStateMachineType_RunningToSuspended = 2416,
	//! NodeId of the node ProgramStateMachineType/RunningToSuspended/TransitionNumber.
	EnumNumericNodeId_ProgramStateMachineType_RunningToSuspended_TransitionNumber = 2417,
	//! NodeId of the node ProgramStateMachineType/SuspendedToRunning.
	EnumNumericNodeId_ProgramStateMachineType_SuspendedToRunning = 2418,
	//! NodeId of the node ProgramStateMachineType/SuspendedToRunning/TransitionNumber.
	EnumNumericNodeId_ProgramStateMachineType_SuspendedToRunning_TransitionNumber = 2419,
	//! NodeId of the node ProgramStateMachineType/SuspendedToHalted.
	EnumNumericNodeId_ProgramStateMachineType_SuspendedToHalted = 2420,
	//! NodeId of the node ProgramStateMachineType/SuspendedToHalted/TransitionNumber.
	EnumNumericNodeId_ProgramStateMachineType_SuspendedToHalted_TransitionNumber = 2421,
	//! NodeId of the node ProgramStateMachineType/SuspendedToReady.
	EnumNumericNodeId_ProgramStateMachineType_SuspendedToReady = 2422,
	//! NodeId of the node ProgramStateMachineType/SuspendedToReady/TransitionNumber.
	EnumNumericNodeId_ProgramStateMachineType_SuspendedToReady_TransitionNumber = 2423,
	//! NodeId of the node ProgramStateMachineType/ReadyToHalted.
	EnumNumericNodeId_ProgramStateMachineType_ReadyToHalted = 2424,
	//! NodeId of the node ProgramStateMachineType/ReadyToHalted/TransitionNumber.
	EnumNumericNodeId_ProgramStateMachineType_ReadyToHalted_TransitionNumber = 2425,
	//! NodeId of the node ProgramStateMachineType/Start.
	EnumNumericNodeId_ProgramStateMachineType_Start = 2426,
	//! NodeId of the node ProgramStateMachineType/Suspend.
	EnumNumericNodeId_ProgramStateMachineType_Suspend = 2427,
	//! NodeId of the node ProgramStateMachineType/Resume.
	EnumNumericNodeId_ProgramStateMachineType_Resume = 2428,
	//! NodeId of the node ProgramStateMachineType/Halt.
	EnumNumericNodeId_ProgramStateMachineType_Halt = 2429,
	//! NodeId of the node ProgramStateMachineType/Reset.
	EnumNumericNodeId_ProgramStateMachineType_Reset = 2430,
	//! NodeId of the node SessionDiagnosticsVariableType/RegisterNodesCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_RegisterNodesCount = 2730,
	//! NodeId of the node SessionDiagnosticsVariableType/UnregisterNodesCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_UnregisterNodesCount = 2731,
	//! NodeId of the node ServerCapabilitiesType/MaxBrowseContinuationPoints.
	EnumNumericNodeId_ServerCapabilitiesType_MaxBrowseContinuationPoints = 2732,
	//! NodeId of the node ServerCapabilitiesType/MaxQueryContinuationPoints.
	EnumNumericNodeId_ServerCapabilitiesType_MaxQueryContinuationPoints = 2733,
	//! NodeId of the node ServerCapabilitiesType/MaxHistoryContinuationPoints.
	EnumNumericNodeId_ServerCapabilitiesType_MaxHistoryContinuationPoints = 2734,
	//! NodeId of the node Server/ServerCapabilities/MaxBrowseContinuationPoints.
	EnumNumericNodeId_Server_ServerCapabilities_MaxBrowseContinuationPoints = 2735,
	//! NodeId of the node Server/ServerCapabilities/MaxQueryContinuationPoints.
	EnumNumericNodeId_Server_ServerCapabilities_MaxQueryContinuationPoints = 2736,
	//! NodeId of the node Server/ServerCapabilities/MaxHistoryContinuationPoints.
	EnumNumericNodeId_Server_ServerCapabilities_MaxHistoryContinuationPoints = 2737,
	//! NodeId of the abstract object type SemanticChangeEventType.
	EnumNumericNodeId_SemanticChangeEventType = 2738,
	//! NodeId of the node SemanticChangeEventType/Changes.
	EnumNumericNodeId_SemanticChangeEventType_Changes = 2739,
	//! NodeId of the node ServerType/Auditing.
	EnumNumericNodeId_ServerType_Auditing = 2742,
	//! NodeId of the node ServerDiagnosticsType/SessionsDiagnosticsSummary.
	EnumNumericNodeId_ServerDiagnosticsType_SessionsDiagnosticsSummary = 2744,
	//! NodeId of the node AuditChannelEventType/SecureChannelId.
	EnumNumericNodeId_AuditChannelEventType_SecureChannelId = 2745,
	//! NodeId of the node AuditOpenSecureChannelEventType/ClientCertificateThumbprint.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_ClientCertificateThumbprint = 2746,
	//! NodeId of the node AuditCreateSessionEventType/ClientCertificateThumbprint.
	EnumNumericNodeId_AuditCreateSessionEventType_ClientCertificateThumbprint = 2747,
	//! NodeId of the abstract object type AuditUrlMismatchEventType.
	EnumNumericNodeId_AuditUrlMismatchEventType = 2748,
	//! NodeId of the node AuditUrlMismatchEventType/EndpointUrl.
	EnumNumericNodeId_AuditUrlMismatchEventType_EndpointUrl = 2749,
	//! NodeId of the node AuditWriteUpdateEventType/AttributeId.
	EnumNumericNodeId_AuditWriteUpdateEventType_AttributeId = 2750,
	//! NodeId of the node AuditHistoryUpdateEventType/ParameterDataTypeId.
	EnumNumericNodeId_AuditHistoryUpdateEventType_ParameterDataTypeId = 2751,
	//! NodeId of the node ServerStatusType/SecondsTillShutdown.
	EnumNumericNodeId_ServerStatusType_SecondsTillShutdown = 2752,
	//! NodeId of the node ServerStatusType/ShutdownReason.
	EnumNumericNodeId_ServerStatusType_ShutdownReason = 2753,
	//! NodeId of the node ServerCapabilitiesType/AggregateFunctions.
	EnumNumericNodeId_ServerCapabilitiesType_AggregateFunctions = 2754,
	//! NodeId of the variable type StateVariableType.
	EnumNumericNodeId_StateVariableType = 2755,
	//! NodeId of the node StateVariableType/Id.
	EnumNumericNodeId_StateVariableType_Id = 2756,
	//! NodeId of the node StateVariableType/Name.
	EnumNumericNodeId_StateVariableType_Name = 2757,
	//! NodeId of the node StateVariableType/Number.
	EnumNumericNodeId_StateVariableType_Number = 2758,
	//! NodeId of the node StateVariableType/EffectiveDisplayName.
	EnumNumericNodeId_StateVariableType_EffectiveDisplayName = 2759,
	//! NodeId of the variable type FiniteStateVariableType.
	EnumNumericNodeId_FiniteStateVariableType = 2760,
	//! NodeId of the node FiniteStateVariableType/Id.
	EnumNumericNodeId_FiniteStateVariableType_Id = 2761,
	//! NodeId of the variable type TransitionVariableType.
	EnumNumericNodeId_TransitionVariableType = 2762,
	//! NodeId of the node TransitionVariableType/Id.
	EnumNumericNodeId_TransitionVariableType_Id = 2763,
	//! NodeId of the node TransitionVariableType/Name.
	EnumNumericNodeId_TransitionVariableType_Name = 2764,
	//! NodeId of the node TransitionVariableType/Number.
	EnumNumericNodeId_TransitionVariableType_Number = 2765,
	//! NodeId of the node TransitionVariableType/TransitionTime.
	EnumNumericNodeId_TransitionVariableType_TransitionTime = 2766,
	//! NodeId of the variable type FiniteTransitionVariableType.
	EnumNumericNodeId_FiniteTransitionVariableType = 2767,
	//! NodeId of the node FiniteTransitionVariableType/Id.
	EnumNumericNodeId_FiniteTransitionVariableType_Id = 2768,
	//! NodeId of the node StateMachineType/CurrentState.
	EnumNumericNodeId_StateMachineType_CurrentState = 2769,
	//! NodeId of the node StateMachineType/LastTransition.
	EnumNumericNodeId_StateMachineType_LastTransition = 2770,
	//! NodeId of the object type FiniteStateMachineType.
	EnumNumericNodeId_FiniteStateMachineType = 2771,
	//! NodeId of the node FiniteStateMachineType/CurrentState.
	EnumNumericNodeId_FiniteStateMachineType_CurrentState = 2772,
	//! NodeId of the node FiniteStateMachineType/LastTransition.
	EnumNumericNodeId_FiniteStateMachineType_LastTransition = 2773,
	//! NodeId of the node TransitionEventType/Transition.
	EnumNumericNodeId_TransitionEventType_Transition = 2774,
	//! NodeId of the node TransitionEventType/FromState.
	EnumNumericNodeId_TransitionEventType_FromState = 2775,
	//! NodeId of the node TransitionEventType/ToState.
	EnumNumericNodeId_TransitionEventType_ToState = 2776,
	//! NodeId of the node AuditUpdateStateEventType/OldStateId.
	EnumNumericNodeId_AuditUpdateStateEventType_OldStateId = 2777,
	//! NodeId of the node AuditUpdateStateEventType/NewStateId.
	EnumNumericNodeId_AuditUpdateStateEventType_NewStateId = 2778,
	//! NodeId of the abstract object type ConditionType.
	EnumNumericNodeId_ConditionType = 2782,
	//! NodeId of the object type RefreshStartEventType.
	EnumNumericNodeId_RefreshStartEventType = 2787,
	//! NodeId of the object type RefreshEndEventType.
	EnumNumericNodeId_RefreshEndEventType = 2788,
	//! NodeId of the object type RefreshRequiredEventType.
	EnumNumericNodeId_RefreshRequiredEventType = 2789,
	//! NodeId of the object type AuditConditionEventType.
	EnumNumericNodeId_AuditConditionEventType = 2790,
	//! NodeId of the object type AuditConditionEnableEventType.
	EnumNumericNodeId_AuditConditionEnableEventType = 2803,
	//! NodeId of the object type AuditConditionCommentEventType.
	EnumNumericNodeId_AuditConditionCommentEventType = 2829,
	//! NodeId of the object type DialogConditionType.
	EnumNumericNodeId_DialogConditionType = 2830,
	//! NodeId of the node DialogConditionType/Prompt.
	EnumNumericNodeId_DialogConditionType_Prompt = 2831,
	//! NodeId of the object type AcknowledgeableConditionType.
	EnumNumericNodeId_AcknowledgeableConditionType = 2881,
	//! NodeId of the object type AlarmConditionType.
	EnumNumericNodeId_AlarmConditionType = 2915,
	//! NodeId of the object type ShelvedStateMachineType.
	EnumNumericNodeId_ShelvedStateMachineType = 2929,
	//! NodeId of the node ShelvedStateMachineType/Unshelved.
	EnumNumericNodeId_ShelvedStateMachineType_Unshelved = 2930,
	//! NodeId of the node ShelvedStateMachineType/TimedShelved.
	EnumNumericNodeId_ShelvedStateMachineType_TimedShelved = 2932,
	//! NodeId of the node ShelvedStateMachineType/OneShotShelved.
	EnumNumericNodeId_ShelvedStateMachineType_OneShotShelved = 2933,
	//! NodeId of the node ShelvedStateMachineType/UnshelvedToTimedShelved.
	EnumNumericNodeId_ShelvedStateMachineType_UnshelvedToTimedShelved = 2935,
	//! NodeId of the node ShelvedStateMachineType/UnshelvedToOneShotShelved.
	EnumNumericNodeId_ShelvedStateMachineType_UnshelvedToOneShotShelved = 2936,
	//! NodeId of the node ShelvedStateMachineType/TimedShelvedToUnshelved.
	EnumNumericNodeId_ShelvedStateMachineType_TimedShelvedToUnshelved = 2940,
	//! NodeId of the node ShelvedStateMachineType/TimedShelvedToOneShotShelved.
	EnumNumericNodeId_ShelvedStateMachineType_TimedShelvedToOneShotShelved = 2942,
	//! NodeId of the node ShelvedStateMachineType/OneShotShelvedToUnshelved.
	EnumNumericNodeId_ShelvedStateMachineType_OneShotShelvedToUnshelved = 2943,
	//! NodeId of the node ShelvedStateMachineType/OneShotShelvedToTimedShelved.
	EnumNumericNodeId_ShelvedStateMachineType_OneShotShelvedToTimedShelved = 2945,
	//! NodeId of the node ShelvedStateMachineType/Unshelve.
	EnumNumericNodeId_ShelvedStateMachineType_Unshelve = 2947,
	//! NodeId of the node ShelvedStateMachineType/OneShotShelve.
	EnumNumericNodeId_ShelvedStateMachineType_OneShotShelve = 2948,
	//! NodeId of the node ShelvedStateMachineType/TimedShelve.
	EnumNumericNodeId_ShelvedStateMachineType_TimedShelve = 2949,
	//! NodeId of the object type LimitAlarmType.
	EnumNumericNodeId_LimitAlarmType = 2955,
	//! NodeId of the node ShelvedStateMachineType/TimedShelve/InputArguments.
	EnumNumericNodeId_ShelvedStateMachineType_TimedShelve_InputArguments = 2991,
	//! NodeId of the node Server/ServerStatus/SecondsTillShutdown.
	EnumNumericNodeId_Server_ServerStatus_SecondsTillShutdown = 2992,
	//! NodeId of the node Server/ServerStatus/ShutdownReason.
	EnumNumericNodeId_Server_ServerStatus_ShutdownReason = 2993,
	//! NodeId of the node Server/Auditing.
	EnumNumericNodeId_Server_Auditing = 2994,
	//! NodeId of the node Server/ServerCapabilities/ModellingRules.
	EnumNumericNodeId_Server_ServerCapabilities_ModellingRules = 2996,
	//! NodeId of the node Server/ServerCapabilities/AggregateFunctions.
	EnumNumericNodeId_Server_ServerCapabilities_AggregateFunctions = 2997,
	//! NodeId of the node SubscriptionDiagnosticsType/EventNotificationsCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_EventNotificationsCount = 2998,
	//! NodeId of the abstract object type AuditHistoryEventUpdateEventType.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType = 2999,
	//! NodeId of the node AuditHistoryEventUpdateEventType/Filter.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_Filter = 3003,
	//! NodeId of the abstract object type AuditHistoryValueUpdateEventType.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType = 3006,
	//! NodeId of the abstract object type AuditHistoryDeleteEventType.
	EnumNumericNodeId_AuditHistoryDeleteEventType = 3012,
	//! NodeId of the abstract object type AuditHistoryRawModifyDeleteEventType.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType = 3014,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/IsDeleteModified.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_IsDeleteModified = 3015,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/StartTime.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_StartTime = 3016,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/EndTime.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_EndTime = 3017,
	//! NodeId of the abstract object type AuditHistoryAtTimeDeleteEventType.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType = 3019,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/ReqTimes.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_ReqTimes = 3020,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/OldValues.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_OldValues = 3021,
	//! NodeId of the abstract object type AuditHistoryEventDeleteEventType.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType = 3022,
	//! NodeId of the node AuditHistoryEventDeleteEventType/EventIds.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_EventIds = 3023,
	//! NodeId of the node AuditHistoryEventDeleteEventType/OldValues.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_OldValues = 3024,
	//! NodeId of the node AuditHistoryEventUpdateEventType/UpdatedNode.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_UpdatedNode = 3025,
	//! NodeId of the node AuditHistoryValueUpdateEventType/UpdatedNode.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_UpdatedNode = 3026,
	//! NodeId of the node AuditHistoryDeleteEventType/UpdatedNode.
	EnumNumericNodeId_AuditHistoryDeleteEventType_UpdatedNode = 3027,
	//! NodeId of the node AuditHistoryEventUpdateEventType/PerformInsertReplace.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_PerformInsertReplace = 3028,
	//! NodeId of the node AuditHistoryEventUpdateEventType/NewValues.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_NewValues = 3029,
	//! NodeId of the node AuditHistoryEventUpdateEventType/OldValues.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_OldValues = 3030,
	//! NodeId of the node AuditHistoryValueUpdateEventType/PerformInsertReplace.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_PerformInsertReplace = 3031,
	//! NodeId of the node AuditHistoryValueUpdateEventType/NewValues.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_NewValues = 3032,
	//! NodeId of the node AuditHistoryValueUpdateEventType/OldValues.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_OldValues = 3033,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/OldValues.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_OldValues = 3034,
	//! NodeId of the abstract object type EventQueueOverflowEventType.
	EnumNumericNodeId_EventQueueOverflowEventType = 3035,
	//! NodeId of the node EventTypesFolder.
	EnumNumericNodeId_EventTypesFolder = 3048,
	//! NodeId of the node ServerCapabilitiesType/SoftwareCertificates.
	EnumNumericNodeId_ServerCapabilitiesType_SoftwareCertificates = 3049,
	//! NodeId of the node SessionDiagnosticsVariableType/MaxResponseMessageSize.
	EnumNumericNodeId_SessionDiagnosticsVariableType_MaxResponseMessageSize = 3050,
	//! NodeId of the variable type BuildInfoType.
	EnumNumericNodeId_BuildInfoType = 3051,
	//! NodeId of the node BuildInfoType/ProductUri.
	EnumNumericNodeId_BuildInfoType_ProductUri = 3052,
	//! NodeId of the node BuildInfoType/ManufacturerName.
	EnumNumericNodeId_BuildInfoType_ManufacturerName = 3053,
	//! NodeId of the node BuildInfoType/ProductName.
	EnumNumericNodeId_BuildInfoType_ProductName = 3054,
	//! NodeId of the node BuildInfoType/SoftwareVersion.
	EnumNumericNodeId_BuildInfoType_SoftwareVersion = 3055,
	//! NodeId of the node BuildInfoType/BuildNumber.
	EnumNumericNodeId_BuildInfoType_BuildNumber = 3056,
	//! NodeId of the node BuildInfoType/BuildDate.
	EnumNumericNodeId_BuildInfoType_BuildDate = 3057,
	//! NodeId of the node SessionSecurityDiagnosticsType/ClientCertificate.
	EnumNumericNodeId_SessionSecurityDiagnosticsType_ClientCertificate = 3058,
	//! NodeId of the node HistoricalDataConfigurationType/AggregateConfiguration.
	EnumNumericNodeId_HistoricalDataConfigurationType_AggregateConfiguration = 3059,
	//! NodeId of the node DefaultBinary.
	EnumNumericNodeId_DefaultBinary = 3062,
	//! NodeId of the node DefaultXml.
	EnumNumericNodeId_DefaultXml = 3063,
	//! NodeId of the reference type AlwaysGeneratesEvent.
	EnumNumericNodeId_AlwaysGeneratesEvent = 3065,
	//! NodeId of the node Icon.
	EnumNumericNodeId_Icon = 3067,
	//! NodeId of the node NodeVersion.
	EnumNumericNodeId_NodeVersion = 3068,
	//! NodeId of the node LocalTime.
	EnumNumericNodeId_LocalTime = 3069,
	//! NodeId of the node AllowNulls.
	EnumNumericNodeId_AllowNulls = 3070,
	//! NodeId of the node EnumValues.
	EnumNumericNodeId_EnumValues = 3071,
	//! NodeId of the node InputArguments.
	EnumNumericNodeId_InputArguments = 3072,
	//! NodeId of the node OutputArguments.
	EnumNumericNodeId_OutputArguments = 3073,
	//! NodeId of the node ServerType/ServerStatus/StartTime.
	EnumNumericNodeId_ServerType_ServerStatus_StartTime = 3074,
	//! NodeId of the node ServerType/ServerStatus/CurrentTime.
	EnumNumericNodeId_ServerType_ServerStatus_CurrentTime = 3075,
	//! NodeId of the node ServerType/ServerStatus/State.
	EnumNumericNodeId_ServerType_ServerStatus_State = 3076,
	//! NodeId of the node ServerType/ServerStatus/BuildInfo.
	EnumNumericNodeId_ServerType_ServerStatus_BuildInfo = 3077,
	//! NodeId of the node ServerType/ServerStatus/BuildInfo/ProductUri.
	EnumNumericNodeId_ServerType_ServerStatus_BuildInfo_ProductUri = 3078,
	//! NodeId of the node ServerType/ServerStatus/BuildInfo/ManufacturerName.
	EnumNumericNodeId_ServerType_ServerStatus_BuildInfo_ManufacturerName = 3079,
	//! NodeId of the node ServerType/ServerStatus/BuildInfo/ProductName.
	EnumNumericNodeId_ServerType_ServerStatus_BuildInfo_ProductName = 3080,
	//! NodeId of the node ServerType/ServerStatus/BuildInfo/SoftwareVersion.
	EnumNumericNodeId_ServerType_ServerStatus_BuildInfo_SoftwareVersion = 3081,
	//! NodeId of the node ServerType/ServerStatus/BuildInfo/BuildNumber.
	EnumNumericNodeId_ServerType_ServerStatus_BuildInfo_BuildNumber = 3082,
	//! NodeId of the node ServerType/ServerStatus/BuildInfo/BuildDate.
	EnumNumericNodeId_ServerType_ServerStatus_BuildInfo_BuildDate = 3083,
	//! NodeId of the node ServerType/ServerStatus/SecondsTillShutdown.
	EnumNumericNodeId_ServerType_ServerStatus_SecondsTillShutdown = 3084,
	//! NodeId of the node ServerType/ServerStatus/ShutdownReason.
	EnumNumericNodeId_ServerType_ServerStatus_ShutdownReason = 3085,
	//! NodeId of the node ServerType/ServerCapabilities/ServerProfileArray.
	EnumNumericNodeId_ServerType_ServerCapabilities_ServerProfileArray = 3086,
	//! NodeId of the node ServerType/ServerCapabilities/LocaleIdArray.
	EnumNumericNodeId_ServerType_ServerCapabilities_LocaleIdArray = 3087,
	//! NodeId of the node ServerType/ServerCapabilities/MinSupportedSampleRate.
	EnumNumericNodeId_ServerType_ServerCapabilities_MinSupportedSampleRate = 3088,
	//! NodeId of the node ServerType/ServerCapabilities/MaxBrowseContinuationPoints.
	EnumNumericNodeId_ServerType_ServerCapabilities_MaxBrowseContinuationPoints = 3089,
	//! NodeId of the node ServerType/ServerCapabilities/MaxQueryContinuationPoints.
	EnumNumericNodeId_ServerType_ServerCapabilities_MaxQueryContinuationPoints = 3090,
	//! NodeId of the node ServerType/ServerCapabilities/MaxHistoryContinuationPoints.
	EnumNumericNodeId_ServerType_ServerCapabilities_MaxHistoryContinuationPoints = 3091,
	//! NodeId of the node ServerType/ServerCapabilities/SoftwareCertificates.
	EnumNumericNodeId_ServerType_ServerCapabilities_SoftwareCertificates = 3092,
	//! NodeId of the node ServerType/ServerCapabilities/ModellingRules.
	EnumNumericNodeId_ServerType_ServerCapabilities_ModellingRules = 3093,
	//! NodeId of the node ServerType/ServerCapabilities/AggregateFunctions.
	EnumNumericNodeId_ServerType_ServerCapabilities_AggregateFunctions = 3094,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary = 3095,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/ServerViewCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_ServerViewCount = 3096,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/CurrentSessionCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount = 3097,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/CumulatedSessionCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount = 3098,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/SecurityRejectedSessionCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount = 3099,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/RejectedSessionCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount = 3100,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/SessionTimeoutCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount = 3101,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/SessionAbortCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_SessionAbortCount = 3102,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/PublishingIntervalCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount = 3104,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/CurrentSubscriptionCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount = 3105,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/CumulatedSubscriptionCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount = 3106,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/SecurityRejectedRequestsCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount = 3107,
	//! NodeId of the node ServerType/ServerDiagnostics/ServerDiagnosticsSummary/RejectedRequestsCount.
	EnumNumericNodeId_ServerType_ServerDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount = 3108,
	//! NodeId of the node ServerType/ServerDiagnostics/SamplingIntervalDiagnosticsArray.
	EnumNumericNodeId_ServerType_ServerDiagnostics_SamplingIntervalDiagnosticsArray = 3109,
	//! NodeId of the node ServerType/ServerDiagnostics/SubscriptionDiagnosticsArray.
	EnumNumericNodeId_ServerType_ServerDiagnostics_SubscriptionDiagnosticsArray = 3110,
	//! NodeId of the node ServerType/ServerDiagnostics/SessionsDiagnosticsSummary.
	EnumNumericNodeId_ServerType_ServerDiagnostics_SessionsDiagnosticsSummary = 3111,
	//! NodeId of the node ServerType/ServerDiagnostics/SessionsDiagnosticsSummary/SessionDiagnosticsArray.
	EnumNumericNodeId_ServerType_ServerDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray = 3112,
	//! NodeId of the node ServerType/ServerDiagnostics/SessionsDiagnosticsSummary/SessionSecurityDiagnosticsArray.
	EnumNumericNodeId_ServerType_ServerDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray = 3113,
	//! NodeId of the node ServerType/ServerDiagnostics/EnabledFlag.
	EnumNumericNodeId_ServerType_ServerDiagnostics_EnabledFlag = 3114,
	//! NodeId of the node ServerType/ServerRedundancy/RedundancySupport.
	EnumNumericNodeId_ServerType_ServerRedundancy_RedundancySupport = 3115,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/ServerViewCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_ServerViewCount = 3116,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/CurrentSessionCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_CurrentSessionCount = 3117,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/CumulatedSessionCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_CumulatedSessionCount = 3118,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/SecurityRejectedSessionCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_SecurityRejectedSessionCount = 3119,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/RejectedSessionCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_RejectedSessionCount = 3120,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/SessionTimeoutCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_SessionTimeoutCount = 3121,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/SessionAbortCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_SessionAbortCount = 3122,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/PublishingIntervalCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_PublishingIntervalCount = 3124,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/CurrentSubscriptionCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_CurrentSubscriptionCount = 3125,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/CumulatedSubscriptionCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_CumulatedSubscriptionCount = 3126,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/SecurityRejectedRequestsCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_SecurityRejectedRequestsCount = 3127,
	//! NodeId of the node ServerDiagnosticsType/ServerDiagnosticsSummary/RejectedRequestsCount.
	EnumNumericNodeId_ServerDiagnosticsType_ServerDiagnosticsSummary_RejectedRequestsCount = 3128,
	//! NodeId of the node ServerDiagnosticsType/SessionsDiagnosticsSummary/SessionDiagnosticsArray.
	EnumNumericNodeId_ServerDiagnosticsType_SessionsDiagnosticsSummary_SessionDiagnosticsArray = 3129,
	//! NodeId of the node ServerDiagnosticsType/SessionsDiagnosticsSummary/SessionSecurityDiagnosticsArray.
	EnumNumericNodeId_ServerDiagnosticsType_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray = 3130,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/SessionId.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_SessionId = 3131,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/SessionName.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_SessionName = 3132,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/ClientDescription.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_ClientDescription = 3133,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/ServerUri.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_ServerUri = 3134,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/EndpointUrl.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_EndpointUrl = 3135,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/LocaleIds.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_LocaleIds = 3136,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/ActualSessionTimeout.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_ActualSessionTimeout = 3137,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/MaxResponseMessageSize.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_MaxResponseMessageSize = 3138,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/ClientConnectionTime.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_ClientConnectionTime = 3139,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/ClientLastContactTime.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_ClientLastContactTime = 3140,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/CurrentSubscriptionsCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_CurrentSubscriptionsCount = 3141,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/CurrentMonitoredItemsCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_CurrentMonitoredItemsCount = 3142,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/CurrentPublishRequestsInQueue.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_CurrentPublishRequestsInQueue = 3143,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/ReadCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_ReadCount = 3151,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/HistoryReadCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_HistoryReadCount = 3152,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/WriteCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_WriteCount = 3153,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/HistoryUpdateCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_HistoryUpdateCount = 3154,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/CallCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_CallCount = 3155,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/CreateMonitoredItemsCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_CreateMonitoredItemsCount = 3156,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/ModifyMonitoredItemsCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_ModifyMonitoredItemsCount = 3157,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/SetMonitoringModeCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_SetMonitoringModeCount = 3158,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/SetTriggeringCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_SetTriggeringCount = 3159,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/DeleteMonitoredItemsCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_DeleteMonitoredItemsCount = 3160,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/CreateSubscriptionCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_CreateSubscriptionCount = 3161,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/ModifySubscriptionCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_ModifySubscriptionCount = 3162,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/SetPublishingModeCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_SetPublishingModeCount = 3163,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/PublishCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_PublishCount = 3164,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/RepublishCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_RepublishCount = 3165,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/TransferSubscriptionsCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_TransferSubscriptionsCount = 3166,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/DeleteSubscriptionsCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_DeleteSubscriptionsCount = 3167,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/AddNodesCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_AddNodesCount = 3168,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/AddReferencesCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_AddReferencesCount = 3169,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/DeleteNodesCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_DeleteNodesCount = 3170,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/DeleteReferencesCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_DeleteReferencesCount = 3171,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/BrowseCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_BrowseCount = 3172,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/BrowseNextCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_BrowseNextCount = 3173,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/TranslateBrowsePathsToNodeIdsCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_TranslateBrowsePathsToNodeIdsCount = 3174,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/QueryFirstCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_QueryFirstCount = 3175,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/QueryNextCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_QueryNextCount = 3176,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/RegisterNodesCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_RegisterNodesCount = 3177,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/UnregisterNodesCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_UnregisterNodesCount = 3178,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionSecurityDiagnostics/SessionId.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionSecurityDiagnostics_SessionId = 3179,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionSecurityDiagnostics/ClientUserIdOfSession.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionSecurityDiagnostics_ClientUserIdOfSession = 3180,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionSecurityDiagnostics/ClientUserIdHistory.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionSecurityDiagnostics_ClientUserIdHistory = 3181,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionSecurityDiagnostics/AuthenticationMechanism.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionSecurityDiagnostics_AuthenticationMechanism = 3182,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionSecurityDiagnostics/Encoding.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionSecurityDiagnostics_Encoding = 3183,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionSecurityDiagnostics/TransportProtocol.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionSecurityDiagnostics_TransportProtocol = 3184,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionSecurityDiagnostics/SecurityMode.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionSecurityDiagnostics_SecurityMode = 3185,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionSecurityDiagnostics/SecurityPolicyUri.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionSecurityDiagnostics_SecurityPolicyUri = 3186,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionSecurityDiagnostics/ClientCertificate.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionSecurityDiagnostics_ClientCertificate = 3187,
	//! NodeId of the node TransparentRedundancyType/RedundancySupport.
	EnumNumericNodeId_TransparentRedundancyType_RedundancySupport = 3188,
	//! NodeId of the node NonTransparentRedundancyType/RedundancySupport.
	EnumNumericNodeId_NonTransparentRedundancyType_RedundancySupport = 3189,
	//! NodeId of the node BaseEventType/LocalTime.
	EnumNumericNodeId_BaseEventType_LocalTime = 3190,
	//! NodeId of the node EventQueueOverflowEventType/EventId.
	EnumNumericNodeId_EventQueueOverflowEventType_EventId = 3191,
	//! NodeId of the node EventQueueOverflowEventType/EventType.
	EnumNumericNodeId_EventQueueOverflowEventType_EventType = 3192,
	//! NodeId of the node EventQueueOverflowEventType/SourceNode.
	EnumNumericNodeId_EventQueueOverflowEventType_SourceNode = 3193,
	//! NodeId of the node EventQueueOverflowEventType/SourceName.
	EnumNumericNodeId_EventQueueOverflowEventType_SourceName = 3194,
	//! NodeId of the node EventQueueOverflowEventType/Time.
	EnumNumericNodeId_EventQueueOverflowEventType_Time = 3195,
	//! NodeId of the node EventQueueOverflowEventType/ReceiveTime.
	EnumNumericNodeId_EventQueueOverflowEventType_ReceiveTime = 3196,
	//! NodeId of the node EventQueueOverflowEventType/LocalTime.
	EnumNumericNodeId_EventQueueOverflowEventType_LocalTime = 3197,
	//! NodeId of the node EventQueueOverflowEventType/Message.
	EnumNumericNodeId_EventQueueOverflowEventType_Message = 3198,
	//! NodeId of the node EventQueueOverflowEventType/Severity.
	EnumNumericNodeId_EventQueueOverflowEventType_Severity = 3199,
	//! NodeId of the node AuditEventType/EventId.
	EnumNumericNodeId_AuditEventType_EventId = 3200,
	//! NodeId of the node AuditEventType/EventType.
	EnumNumericNodeId_AuditEventType_EventType = 3201,
	//! NodeId of the node AuditEventType/SourceNode.
	EnumNumericNodeId_AuditEventType_SourceNode = 3202,
	//! NodeId of the node AuditEventType/SourceName.
	EnumNumericNodeId_AuditEventType_SourceName = 3203,
	//! NodeId of the node AuditEventType/Time.
	EnumNumericNodeId_AuditEventType_Time = 3204,
	//! NodeId of the node AuditEventType/ReceiveTime.
	EnumNumericNodeId_AuditEventType_ReceiveTime = 3205,
	//! NodeId of the node AuditEventType/LocalTime.
	EnumNumericNodeId_AuditEventType_LocalTime = 3206,
	//! NodeId of the node AuditEventType/Message.
	EnumNumericNodeId_AuditEventType_Message = 3207,
	//! NodeId of the node AuditEventType/Severity.
	EnumNumericNodeId_AuditEventType_Severity = 3208,
	//! NodeId of the node AuditSecurityEventType/EventId.
	EnumNumericNodeId_AuditSecurityEventType_EventId = 3209,
	//! NodeId of the node AuditSecurityEventType/EventType.
	EnumNumericNodeId_AuditSecurityEventType_EventType = 3210,
	//! NodeId of the node AuditSecurityEventType/SourceNode.
	EnumNumericNodeId_AuditSecurityEventType_SourceNode = 3211,
	//! NodeId of the node AuditSecurityEventType/SourceName.
	EnumNumericNodeId_AuditSecurityEventType_SourceName = 3212,
	//! NodeId of the node AuditSecurityEventType/Time.
	EnumNumericNodeId_AuditSecurityEventType_Time = 3213,
	//! NodeId of the node AuditSecurityEventType/ReceiveTime.
	EnumNumericNodeId_AuditSecurityEventType_ReceiveTime = 3214,
	//! NodeId of the node AuditSecurityEventType/LocalTime.
	EnumNumericNodeId_AuditSecurityEventType_LocalTime = 3215,
	//! NodeId of the node AuditSecurityEventType/Message.
	EnumNumericNodeId_AuditSecurityEventType_Message = 3216,
	//! NodeId of the node AuditSecurityEventType/Severity.
	EnumNumericNodeId_AuditSecurityEventType_Severity = 3217,
	//! NodeId of the node AuditSecurityEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditSecurityEventType_ActionTimeStamp = 3218,
	//! NodeId of the node AuditSecurityEventType/Status.
	EnumNumericNodeId_AuditSecurityEventType_Status = 3219,
	//! NodeId of the node AuditSecurityEventType/ServerId.
	EnumNumericNodeId_AuditSecurityEventType_ServerId = 3220,
	//! NodeId of the node AuditSecurityEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditSecurityEventType_ClientAuditEntryId = 3221,
	//! NodeId of the node AuditSecurityEventType/ClientUserId.
	EnumNumericNodeId_AuditSecurityEventType_ClientUserId = 3222,
	//! NodeId of the node AuditChannelEventType/EventId.
	EnumNumericNodeId_AuditChannelEventType_EventId = 3223,
	//! NodeId of the node AuditChannelEventType/EventType.
	EnumNumericNodeId_AuditChannelEventType_EventType = 3224,
	//! NodeId of the node AuditChannelEventType/SourceNode.
	EnumNumericNodeId_AuditChannelEventType_SourceNode = 3225,
	//! NodeId of the node AuditChannelEventType/SourceName.
	EnumNumericNodeId_AuditChannelEventType_SourceName = 3226,
	//! NodeId of the node AuditChannelEventType/Time.
	EnumNumericNodeId_AuditChannelEventType_Time = 3227,
	//! NodeId of the node AuditChannelEventType/ReceiveTime.
	EnumNumericNodeId_AuditChannelEventType_ReceiveTime = 3228,
	//! NodeId of the node AuditChannelEventType/LocalTime.
	EnumNumericNodeId_AuditChannelEventType_LocalTime = 3229,
	//! NodeId of the node AuditChannelEventType/Message.
	EnumNumericNodeId_AuditChannelEventType_Message = 3230,
	//! NodeId of the node AuditChannelEventType/Severity.
	EnumNumericNodeId_AuditChannelEventType_Severity = 3231,
	//! NodeId of the node AuditChannelEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditChannelEventType_ActionTimeStamp = 3232,
	//! NodeId of the node AuditChannelEventType/Status.
	EnumNumericNodeId_AuditChannelEventType_Status = 3233,
	//! NodeId of the node AuditChannelEventType/ServerId.
	EnumNumericNodeId_AuditChannelEventType_ServerId = 3234,
	//! NodeId of the node AuditChannelEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditChannelEventType_ClientAuditEntryId = 3235,
	//! NodeId of the node AuditChannelEventType/ClientUserId.
	EnumNumericNodeId_AuditChannelEventType_ClientUserId = 3236,
	//! NodeId of the node AuditOpenSecureChannelEventType/EventId.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_EventId = 3237,
	//! NodeId of the node AuditOpenSecureChannelEventType/EventType.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_EventType = 3238,
	//! NodeId of the node AuditOpenSecureChannelEventType/SourceNode.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_SourceNode = 3239,
	//! NodeId of the node AuditOpenSecureChannelEventType/SourceName.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_SourceName = 3240,
	//! NodeId of the node AuditOpenSecureChannelEventType/Time.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_Time = 3241,
	//! NodeId of the node AuditOpenSecureChannelEventType/ReceiveTime.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_ReceiveTime = 3242,
	//! NodeId of the node AuditOpenSecureChannelEventType/LocalTime.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_LocalTime = 3243,
	//! NodeId of the node AuditOpenSecureChannelEventType/Message.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_Message = 3244,
	//! NodeId of the node AuditOpenSecureChannelEventType/Severity.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_Severity = 3245,
	//! NodeId of the node AuditOpenSecureChannelEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_ActionTimeStamp = 3246,
	//! NodeId of the node AuditOpenSecureChannelEventType/Status.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_Status = 3247,
	//! NodeId of the node AuditOpenSecureChannelEventType/ServerId.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_ServerId = 3248,
	//! NodeId of the node AuditOpenSecureChannelEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_ClientAuditEntryId = 3249,
	//! NodeId of the node AuditOpenSecureChannelEventType/ClientUserId.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_ClientUserId = 3250,
	//! NodeId of the node AuditOpenSecureChannelEventType/SecureChannelId.
	EnumNumericNodeId_AuditOpenSecureChannelEventType_SecureChannelId = 3251,
	//! NodeId of the node AuditSessionEventType/EventId.
	EnumNumericNodeId_AuditSessionEventType_EventId = 3252,
	//! NodeId of the node AuditSessionEventType/EventType.
	EnumNumericNodeId_AuditSessionEventType_EventType = 3253,
	//! NodeId of the node AuditSessionEventType/SourceNode.
	EnumNumericNodeId_AuditSessionEventType_SourceNode = 3254,
	//! NodeId of the node AuditSessionEventType/SourceName.
	EnumNumericNodeId_AuditSessionEventType_SourceName = 3255,
	//! NodeId of the node AuditSessionEventType/Time.
	EnumNumericNodeId_AuditSessionEventType_Time = 3256,
	//! NodeId of the node AuditSessionEventType/ReceiveTime.
	EnumNumericNodeId_AuditSessionEventType_ReceiveTime = 3257,
	//! NodeId of the node AuditSessionEventType/LocalTime.
	EnumNumericNodeId_AuditSessionEventType_LocalTime = 3258,
	//! NodeId of the node AuditSessionEventType/Message.
	EnumNumericNodeId_AuditSessionEventType_Message = 3259,
	//! NodeId of the node AuditSessionEventType/Severity.
	EnumNumericNodeId_AuditSessionEventType_Severity = 3260,
	//! NodeId of the node AuditSessionEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditSessionEventType_ActionTimeStamp = 3261,
	//! NodeId of the node AuditSessionEventType/Status.
	EnumNumericNodeId_AuditSessionEventType_Status = 3262,
	//! NodeId of the node AuditSessionEventType/ServerId.
	EnumNumericNodeId_AuditSessionEventType_ServerId = 3263,
	//! NodeId of the node AuditSessionEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditSessionEventType_ClientAuditEntryId = 3264,
	//! NodeId of the node AuditSessionEventType/ClientUserId.
	EnumNumericNodeId_AuditSessionEventType_ClientUserId = 3265,
	//! NodeId of the node AuditCreateSessionEventType/EventId.
	EnumNumericNodeId_AuditCreateSessionEventType_EventId = 3266,
	//! NodeId of the node AuditCreateSessionEventType/EventType.
	EnumNumericNodeId_AuditCreateSessionEventType_EventType = 3267,
	//! NodeId of the node AuditCreateSessionEventType/SourceNode.
	EnumNumericNodeId_AuditCreateSessionEventType_SourceNode = 3268,
	//! NodeId of the node AuditCreateSessionEventType/SourceName.
	EnumNumericNodeId_AuditCreateSessionEventType_SourceName = 3269,
	//! NodeId of the node AuditCreateSessionEventType/Time.
	EnumNumericNodeId_AuditCreateSessionEventType_Time = 3270,
	//! NodeId of the node AuditCreateSessionEventType/ReceiveTime.
	EnumNumericNodeId_AuditCreateSessionEventType_ReceiveTime = 3271,
	//! NodeId of the node AuditCreateSessionEventType/LocalTime.
	EnumNumericNodeId_AuditCreateSessionEventType_LocalTime = 3272,
	//! NodeId of the node AuditCreateSessionEventType/Message.
	EnumNumericNodeId_AuditCreateSessionEventType_Message = 3273,
	//! NodeId of the node AuditCreateSessionEventType/Severity.
	EnumNumericNodeId_AuditCreateSessionEventType_Severity = 3274,
	//! NodeId of the node AuditCreateSessionEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditCreateSessionEventType_ActionTimeStamp = 3275,
	//! NodeId of the node AuditCreateSessionEventType/Status.
	EnumNumericNodeId_AuditCreateSessionEventType_Status = 3276,
	//! NodeId of the node AuditCreateSessionEventType/ServerId.
	EnumNumericNodeId_AuditCreateSessionEventType_ServerId = 3277,
	//! NodeId of the node AuditCreateSessionEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditCreateSessionEventType_ClientAuditEntryId = 3278,
	//! NodeId of the node AuditCreateSessionEventType/ClientUserId.
	EnumNumericNodeId_AuditCreateSessionEventType_ClientUserId = 3279,
	//! NodeId of the node AuditCreateSessionEventType/SessionId.
	EnumNumericNodeId_AuditCreateSessionEventType_SessionId = 3280,
	//! NodeId of the node AuditUrlMismatchEventType/EventId.
	EnumNumericNodeId_AuditUrlMismatchEventType_EventId = 3281,
	//! NodeId of the node AuditUrlMismatchEventType/EventType.
	EnumNumericNodeId_AuditUrlMismatchEventType_EventType = 3282,
	//! NodeId of the node AuditUrlMismatchEventType/SourceNode.
	EnumNumericNodeId_AuditUrlMismatchEventType_SourceNode = 3283,
	//! NodeId of the node AuditUrlMismatchEventType/SourceName.
	EnumNumericNodeId_AuditUrlMismatchEventType_SourceName = 3284,
	//! NodeId of the node AuditUrlMismatchEventType/Time.
	EnumNumericNodeId_AuditUrlMismatchEventType_Time = 3285,
	//! NodeId of the node AuditUrlMismatchEventType/ReceiveTime.
	EnumNumericNodeId_AuditUrlMismatchEventType_ReceiveTime = 3286,
	//! NodeId of the node AuditUrlMismatchEventType/LocalTime.
	EnumNumericNodeId_AuditUrlMismatchEventType_LocalTime = 3287,
	//! NodeId of the node AuditUrlMismatchEventType/Message.
	EnumNumericNodeId_AuditUrlMismatchEventType_Message = 3288,
	//! NodeId of the node AuditUrlMismatchEventType/Severity.
	EnumNumericNodeId_AuditUrlMismatchEventType_Severity = 3289,
	//! NodeId of the node AuditUrlMismatchEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditUrlMismatchEventType_ActionTimeStamp = 3290,
	//! NodeId of the node AuditUrlMismatchEventType/Status.
	EnumNumericNodeId_AuditUrlMismatchEventType_Status = 3291,
	//! NodeId of the node AuditUrlMismatchEventType/ServerId.
	EnumNumericNodeId_AuditUrlMismatchEventType_ServerId = 3292,
	//! NodeId of the node AuditUrlMismatchEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditUrlMismatchEventType_ClientAuditEntryId = 3293,
	//! NodeId of the node AuditUrlMismatchEventType/ClientUserId.
	EnumNumericNodeId_AuditUrlMismatchEventType_ClientUserId = 3294,
	//! NodeId of the node AuditUrlMismatchEventType/SessionId.
	EnumNumericNodeId_AuditUrlMismatchEventType_SessionId = 3295,
	//! NodeId of the node AuditUrlMismatchEventType/SecureChannelId.
	EnumNumericNodeId_AuditUrlMismatchEventType_SecureChannelId = 3296,
	//! NodeId of the node AuditUrlMismatchEventType/ClientCertificate.
	EnumNumericNodeId_AuditUrlMismatchEventType_ClientCertificate = 3297,
	//! NodeId of the node AuditUrlMismatchEventType/ClientCertificateThumbprint.
	EnumNumericNodeId_AuditUrlMismatchEventType_ClientCertificateThumbprint = 3298,
	//! NodeId of the node AuditUrlMismatchEventType/RevisedSessionTimeout.
	EnumNumericNodeId_AuditUrlMismatchEventType_RevisedSessionTimeout = 3299,
	//! NodeId of the node AuditActivateSessionEventType/EventId.
	EnumNumericNodeId_AuditActivateSessionEventType_EventId = 3300,
	//! NodeId of the node AuditActivateSessionEventType/EventType.
	EnumNumericNodeId_AuditActivateSessionEventType_EventType = 3301,
	//! NodeId of the node AuditActivateSessionEventType/SourceNode.
	EnumNumericNodeId_AuditActivateSessionEventType_SourceNode = 3302,
	//! NodeId of the node AuditActivateSessionEventType/SourceName.
	EnumNumericNodeId_AuditActivateSessionEventType_SourceName = 3303,
	//! NodeId of the node AuditActivateSessionEventType/Time.
	EnumNumericNodeId_AuditActivateSessionEventType_Time = 3304,
	//! NodeId of the node AuditActivateSessionEventType/ReceiveTime.
	EnumNumericNodeId_AuditActivateSessionEventType_ReceiveTime = 3305,
	//! NodeId of the node AuditActivateSessionEventType/LocalTime.
	EnumNumericNodeId_AuditActivateSessionEventType_LocalTime = 3306,
	//! NodeId of the node AuditActivateSessionEventType/Message.
	EnumNumericNodeId_AuditActivateSessionEventType_Message = 3307,
	//! NodeId of the node AuditActivateSessionEventType/Severity.
	EnumNumericNodeId_AuditActivateSessionEventType_Severity = 3308,
	//! NodeId of the node AuditActivateSessionEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditActivateSessionEventType_ActionTimeStamp = 3309,
	//! NodeId of the node AuditActivateSessionEventType/Status.
	EnumNumericNodeId_AuditActivateSessionEventType_Status = 3310,
	//! NodeId of the node AuditActivateSessionEventType/ServerId.
	EnumNumericNodeId_AuditActivateSessionEventType_ServerId = 3311,
	//! NodeId of the node AuditActivateSessionEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditActivateSessionEventType_ClientAuditEntryId = 3312,
	//! NodeId of the node AuditActivateSessionEventType/ClientUserId.
	EnumNumericNodeId_AuditActivateSessionEventType_ClientUserId = 3313,
	//! NodeId of the node AuditActivateSessionEventType/SessionId.
	EnumNumericNodeId_AuditActivateSessionEventType_SessionId = 3314,
	//! NodeId of the node AuditCancelEventType/EventId.
	EnumNumericNodeId_AuditCancelEventType_EventId = 3315,
	//! NodeId of the node AuditCancelEventType/EventType.
	EnumNumericNodeId_AuditCancelEventType_EventType = 3316,
	//! NodeId of the node AuditCancelEventType/SourceNode.
	EnumNumericNodeId_AuditCancelEventType_SourceNode = 3317,
	//! NodeId of the node AuditCancelEventType/SourceName.
	EnumNumericNodeId_AuditCancelEventType_SourceName = 3318,
	//! NodeId of the node AuditCancelEventType/Time.
	EnumNumericNodeId_AuditCancelEventType_Time = 3319,
	//! NodeId of the node AuditCancelEventType/ReceiveTime.
	EnumNumericNodeId_AuditCancelEventType_ReceiveTime = 3320,
	//! NodeId of the node AuditCancelEventType/LocalTime.
	EnumNumericNodeId_AuditCancelEventType_LocalTime = 3321,
	//! NodeId of the node AuditCancelEventType/Message.
	EnumNumericNodeId_AuditCancelEventType_Message = 3322,
	//! NodeId of the node AuditCancelEventType/Severity.
	EnumNumericNodeId_AuditCancelEventType_Severity = 3323,
	//! NodeId of the node AuditCancelEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditCancelEventType_ActionTimeStamp = 3324,
	//! NodeId of the node AuditCancelEventType/Status.
	EnumNumericNodeId_AuditCancelEventType_Status = 3325,
	//! NodeId of the node AuditCancelEventType/ServerId.
	EnumNumericNodeId_AuditCancelEventType_ServerId = 3326,
	//! NodeId of the node AuditCancelEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditCancelEventType_ClientAuditEntryId = 3327,
	//! NodeId of the node AuditCancelEventType/ClientUserId.
	EnumNumericNodeId_AuditCancelEventType_ClientUserId = 3328,
	//! NodeId of the node AuditCancelEventType/SessionId.
	EnumNumericNodeId_AuditCancelEventType_SessionId = 3329,
	//! NodeId of the node AuditCertificateEventType/EventId.
	EnumNumericNodeId_AuditCertificateEventType_EventId = 3330,
	//! NodeId of the node AuditCertificateEventType/EventType.
	EnumNumericNodeId_AuditCertificateEventType_EventType = 3331,
	//! NodeId of the node AuditCertificateEventType/SourceNode.
	EnumNumericNodeId_AuditCertificateEventType_SourceNode = 3332,
	//! NodeId of the node AuditCertificateEventType/SourceName.
	EnumNumericNodeId_AuditCertificateEventType_SourceName = 3333,
	//! NodeId of the node AuditCertificateEventType/Time.
	EnumNumericNodeId_AuditCertificateEventType_Time = 3334,
	//! NodeId of the node AuditCertificateEventType/ReceiveTime.
	EnumNumericNodeId_AuditCertificateEventType_ReceiveTime = 3335,
	//! NodeId of the node AuditCertificateEventType/LocalTime.
	EnumNumericNodeId_AuditCertificateEventType_LocalTime = 3336,
	//! NodeId of the node AuditCertificateEventType/Message.
	EnumNumericNodeId_AuditCertificateEventType_Message = 3337,
	//! NodeId of the node AuditCertificateEventType/Severity.
	EnumNumericNodeId_AuditCertificateEventType_Severity = 3338,
	//! NodeId of the node AuditCertificateEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditCertificateEventType_ActionTimeStamp = 3339,
	//! NodeId of the node AuditCertificateEventType/Status.
	EnumNumericNodeId_AuditCertificateEventType_Status = 3340,
	//! NodeId of the node AuditCertificateEventType/ServerId.
	EnumNumericNodeId_AuditCertificateEventType_ServerId = 3341,
	//! NodeId of the node AuditCertificateEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditCertificateEventType_ClientAuditEntryId = 3342,
	//! NodeId of the node AuditCertificateEventType/ClientUserId.
	EnumNumericNodeId_AuditCertificateEventType_ClientUserId = 3343,
	//! NodeId of the node AuditCertificateDataMismatchEventType/EventId.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_EventId = 3344,
	//! NodeId of the node AuditCertificateDataMismatchEventType/EventType.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_EventType = 3345,
	//! NodeId of the node AuditCertificateDataMismatchEventType/SourceNode.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_SourceNode = 3346,
	//! NodeId of the node AuditCertificateDataMismatchEventType/SourceName.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_SourceName = 3347,
	//! NodeId of the node AuditCertificateDataMismatchEventType/Time.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_Time = 3348,
	//! NodeId of the node AuditCertificateDataMismatchEventType/ReceiveTime.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_ReceiveTime = 3349,
	//! NodeId of the node AuditCertificateDataMismatchEventType/LocalTime.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_LocalTime = 3350,
	//! NodeId of the node AuditCertificateDataMismatchEventType/Message.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_Message = 3351,
	//! NodeId of the node AuditCertificateDataMismatchEventType/Severity.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_Severity = 3352,
	//! NodeId of the node AuditCertificateDataMismatchEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_ActionTimeStamp = 3353,
	//! NodeId of the node AuditCertificateDataMismatchEventType/Status.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_Status = 3354,
	//! NodeId of the node AuditCertificateDataMismatchEventType/ServerId.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_ServerId = 3355,
	//! NodeId of the node AuditCertificateDataMismatchEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_ClientAuditEntryId = 3356,
	//! NodeId of the node AuditCertificateDataMismatchEventType/ClientUserId.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_ClientUserId = 3357,
	//! NodeId of the node AuditCertificateDataMismatchEventType/Certificate.
	EnumNumericNodeId_AuditCertificateDataMismatchEventType_Certificate = 3358,
	//! NodeId of the node AuditCertificateExpiredEventType/EventId.
	EnumNumericNodeId_AuditCertificateExpiredEventType_EventId = 3359,
	//! NodeId of the node AuditCertificateExpiredEventType/EventType.
	EnumNumericNodeId_AuditCertificateExpiredEventType_EventType = 3360,
	//! NodeId of the node AuditCertificateExpiredEventType/SourceNode.
	EnumNumericNodeId_AuditCertificateExpiredEventType_SourceNode = 3361,
	//! NodeId of the node AuditCertificateExpiredEventType/SourceName.
	EnumNumericNodeId_AuditCertificateExpiredEventType_SourceName = 3362,
	//! NodeId of the node AuditCertificateExpiredEventType/Time.
	EnumNumericNodeId_AuditCertificateExpiredEventType_Time = 3363,
	//! NodeId of the node AuditCertificateExpiredEventType/ReceiveTime.
	EnumNumericNodeId_AuditCertificateExpiredEventType_ReceiveTime = 3364,
	//! NodeId of the node AuditCertificateExpiredEventType/LocalTime.
	EnumNumericNodeId_AuditCertificateExpiredEventType_LocalTime = 3365,
	//! NodeId of the node AuditCertificateExpiredEventType/Message.
	EnumNumericNodeId_AuditCertificateExpiredEventType_Message = 3366,
	//! NodeId of the node AuditCertificateExpiredEventType/Severity.
	EnumNumericNodeId_AuditCertificateExpiredEventType_Severity = 3367,
	//! NodeId of the node AuditCertificateExpiredEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditCertificateExpiredEventType_ActionTimeStamp = 3368,
	//! NodeId of the node AuditCertificateExpiredEventType/Status.
	EnumNumericNodeId_AuditCertificateExpiredEventType_Status = 3369,
	//! NodeId of the node AuditCertificateExpiredEventType/ServerId.
	EnumNumericNodeId_AuditCertificateExpiredEventType_ServerId = 3370,
	//! NodeId of the node AuditCertificateExpiredEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditCertificateExpiredEventType_ClientAuditEntryId = 3371,
	//! NodeId of the node AuditCertificateExpiredEventType/ClientUserId.
	EnumNumericNodeId_AuditCertificateExpiredEventType_ClientUserId = 3372,
	//! NodeId of the node AuditCertificateExpiredEventType/Certificate.
	EnumNumericNodeId_AuditCertificateExpiredEventType_Certificate = 3373,
	//! NodeId of the node AuditCertificateInvalidEventType/EventId.
	EnumNumericNodeId_AuditCertificateInvalidEventType_EventId = 3374,
	//! NodeId of the node AuditCertificateInvalidEventType/EventType.
	EnumNumericNodeId_AuditCertificateInvalidEventType_EventType = 3375,
	//! NodeId of the node AuditCertificateInvalidEventType/SourceNode.
	EnumNumericNodeId_AuditCertificateInvalidEventType_SourceNode = 3376,
	//! NodeId of the node AuditCertificateInvalidEventType/SourceName.
	EnumNumericNodeId_AuditCertificateInvalidEventType_SourceName = 3377,
	//! NodeId of the node AuditCertificateInvalidEventType/Time.
	EnumNumericNodeId_AuditCertificateInvalidEventType_Time = 3378,
	//! NodeId of the node AuditCertificateInvalidEventType/ReceiveTime.
	EnumNumericNodeId_AuditCertificateInvalidEventType_ReceiveTime = 3379,
	//! NodeId of the node AuditCertificateInvalidEventType/LocalTime.
	EnumNumericNodeId_AuditCertificateInvalidEventType_LocalTime = 3380,
	//! NodeId of the node AuditCertificateInvalidEventType/Message.
	EnumNumericNodeId_AuditCertificateInvalidEventType_Message = 3381,
	//! NodeId of the node AuditCertificateInvalidEventType/Severity.
	EnumNumericNodeId_AuditCertificateInvalidEventType_Severity = 3382,
	//! NodeId of the node AuditCertificateInvalidEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditCertificateInvalidEventType_ActionTimeStamp = 3383,
	//! NodeId of the node AuditCertificateInvalidEventType/Status.
	EnumNumericNodeId_AuditCertificateInvalidEventType_Status = 3384,
	//! NodeId of the node AuditCertificateInvalidEventType/ServerId.
	EnumNumericNodeId_AuditCertificateInvalidEventType_ServerId = 3385,
	//! NodeId of the node AuditCertificateInvalidEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditCertificateInvalidEventType_ClientAuditEntryId = 3386,
	//! NodeId of the node AuditCertificateInvalidEventType/ClientUserId.
	EnumNumericNodeId_AuditCertificateInvalidEventType_ClientUserId = 3387,
	//! NodeId of the node AuditCertificateInvalidEventType/Certificate.
	EnumNumericNodeId_AuditCertificateInvalidEventType_Certificate = 3388,
	//! NodeId of the node AuditCertificateUntrustedEventType/EventId.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_EventId = 3389,
	//! NodeId of the node AuditCertificateUntrustedEventType/EventType.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_EventType = 3390,
	//! NodeId of the node AuditCertificateUntrustedEventType/SourceNode.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_SourceNode = 3391,
	//! NodeId of the node AuditCertificateUntrustedEventType/SourceName.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_SourceName = 3392,
	//! NodeId of the node AuditCertificateUntrustedEventType/Time.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_Time = 3393,
	//! NodeId of the node AuditCertificateUntrustedEventType/ReceiveTime.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_ReceiveTime = 3394,
	//! NodeId of the node AuditCertificateUntrustedEventType/LocalTime.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_LocalTime = 3395,
	//! NodeId of the node AuditCertificateUntrustedEventType/Message.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_Message = 3396,
	//! NodeId of the node AuditCertificateUntrustedEventType/Severity.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_Severity = 3397,
	//! NodeId of the node AuditCertificateUntrustedEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_ActionTimeStamp = 3398,
	//! NodeId of the node AuditCertificateUntrustedEventType/Status.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_Status = 3399,
	//! NodeId of the node AuditCertificateUntrustedEventType/ServerId.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_ServerId = 3400,
	//! NodeId of the node AuditCertificateUntrustedEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_ClientAuditEntryId = 3401,
	//! NodeId of the node AuditCertificateUntrustedEventType/ClientUserId.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_ClientUserId = 3402,
	//! NodeId of the node AuditCertificateUntrustedEventType/Certificate.
	EnumNumericNodeId_AuditCertificateUntrustedEventType_Certificate = 3403,
	//! NodeId of the node AuditCertificateRevokedEventType/EventId.
	EnumNumericNodeId_AuditCertificateRevokedEventType_EventId = 3404,
	//! NodeId of the node AuditCertificateRevokedEventType/EventType.
	EnumNumericNodeId_AuditCertificateRevokedEventType_EventType = 3405,
	//! NodeId of the node AuditCertificateRevokedEventType/SourceNode.
	EnumNumericNodeId_AuditCertificateRevokedEventType_SourceNode = 3406,
	//! NodeId of the node AuditCertificateRevokedEventType/SourceName.
	EnumNumericNodeId_AuditCertificateRevokedEventType_SourceName = 3407,
	//! NodeId of the node AuditCertificateRevokedEventType/Time.
	EnumNumericNodeId_AuditCertificateRevokedEventType_Time = 3408,
	//! NodeId of the node AuditCertificateRevokedEventType/ReceiveTime.
	EnumNumericNodeId_AuditCertificateRevokedEventType_ReceiveTime = 3409,
	//! NodeId of the node AuditCertificateRevokedEventType/LocalTime.
	EnumNumericNodeId_AuditCertificateRevokedEventType_LocalTime = 3410,
	//! NodeId of the node AuditCertificateRevokedEventType/Message.
	EnumNumericNodeId_AuditCertificateRevokedEventType_Message = 3411,
	//! NodeId of the node AuditCertificateRevokedEventType/Severity.
	EnumNumericNodeId_AuditCertificateRevokedEventType_Severity = 3412,
	//! NodeId of the node AuditCertificateRevokedEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditCertificateRevokedEventType_ActionTimeStamp = 3413,
	//! NodeId of the node AuditCertificateRevokedEventType/Status.
	EnumNumericNodeId_AuditCertificateRevokedEventType_Status = 3414,
	//! NodeId of the node AuditCertificateRevokedEventType/ServerId.
	EnumNumericNodeId_AuditCertificateRevokedEventType_ServerId = 3415,
	//! NodeId of the node AuditCertificateRevokedEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditCertificateRevokedEventType_ClientAuditEntryId = 3416,
	//! NodeId of the node AuditCertificateRevokedEventType/ClientUserId.
	EnumNumericNodeId_AuditCertificateRevokedEventType_ClientUserId = 3417,
	//! NodeId of the node AuditCertificateRevokedEventType/Certificate.
	EnumNumericNodeId_AuditCertificateRevokedEventType_Certificate = 3418,
	//! NodeId of the node AuditCertificateMismatchEventType/EventId.
	EnumNumericNodeId_AuditCertificateMismatchEventType_EventId = 3419,
	//! NodeId of the node AuditCertificateMismatchEventType/EventType.
	EnumNumericNodeId_AuditCertificateMismatchEventType_EventType = 3420,
	//! NodeId of the node AuditCertificateMismatchEventType/SourceNode.
	EnumNumericNodeId_AuditCertificateMismatchEventType_SourceNode = 3421,
	//! NodeId of the node AuditCertificateMismatchEventType/SourceName.
	EnumNumericNodeId_AuditCertificateMismatchEventType_SourceName = 3422,
	//! NodeId of the node AuditCertificateMismatchEventType/Time.
	EnumNumericNodeId_AuditCertificateMismatchEventType_Time = 3423,
	//! NodeId of the node AuditCertificateMismatchEventType/ReceiveTime.
	EnumNumericNodeId_AuditCertificateMismatchEventType_ReceiveTime = 3424,
	//! NodeId of the node AuditCertificateMismatchEventType/LocalTime.
	EnumNumericNodeId_AuditCertificateMismatchEventType_LocalTime = 3425,
	//! NodeId of the node AuditCertificateMismatchEventType/Message.
	EnumNumericNodeId_AuditCertificateMismatchEventType_Message = 3426,
	//! NodeId of the node AuditCertificateMismatchEventType/Severity.
	EnumNumericNodeId_AuditCertificateMismatchEventType_Severity = 3427,
	//! NodeId of the node AuditCertificateMismatchEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditCertificateMismatchEventType_ActionTimeStamp = 3428,
	//! NodeId of the node AuditCertificateMismatchEventType/Status.
	EnumNumericNodeId_AuditCertificateMismatchEventType_Status = 3429,
	//! NodeId of the node AuditCertificateMismatchEventType/ServerId.
	EnumNumericNodeId_AuditCertificateMismatchEventType_ServerId = 3430,
	//! NodeId of the node AuditCertificateMismatchEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditCertificateMismatchEventType_ClientAuditEntryId = 3431,
	//! NodeId of the node AuditCertificateMismatchEventType/ClientUserId.
	EnumNumericNodeId_AuditCertificateMismatchEventType_ClientUserId = 3432,
	//! NodeId of the node AuditCertificateMismatchEventType/Certificate.
	EnumNumericNodeId_AuditCertificateMismatchEventType_Certificate = 3433,
	//! NodeId of the node AuditNodeManagementEventType/EventId.
	EnumNumericNodeId_AuditNodeManagementEventType_EventId = 3434,
	//! NodeId of the node AuditNodeManagementEventType/EventType.
	EnumNumericNodeId_AuditNodeManagementEventType_EventType = 3435,
	//! NodeId of the node AuditNodeManagementEventType/SourceNode.
	EnumNumericNodeId_AuditNodeManagementEventType_SourceNode = 3436,
	//! NodeId of the node AuditNodeManagementEventType/SourceName.
	EnumNumericNodeId_AuditNodeManagementEventType_SourceName = 3437,
	//! NodeId of the node AuditNodeManagementEventType/Time.
	EnumNumericNodeId_AuditNodeManagementEventType_Time = 3438,
	//! NodeId of the node AuditNodeManagementEventType/ReceiveTime.
	EnumNumericNodeId_AuditNodeManagementEventType_ReceiveTime = 3439,
	//! NodeId of the node AuditNodeManagementEventType/LocalTime.
	EnumNumericNodeId_AuditNodeManagementEventType_LocalTime = 3440,
	//! NodeId of the node AuditNodeManagementEventType/Message.
	EnumNumericNodeId_AuditNodeManagementEventType_Message = 3441,
	//! NodeId of the node AuditNodeManagementEventType/Severity.
	EnumNumericNodeId_AuditNodeManagementEventType_Severity = 3442,
	//! NodeId of the node AuditNodeManagementEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditNodeManagementEventType_ActionTimeStamp = 3443,
	//! NodeId of the node AuditNodeManagementEventType/Status.
	EnumNumericNodeId_AuditNodeManagementEventType_Status = 3444,
	//! NodeId of the node AuditNodeManagementEventType/ServerId.
	EnumNumericNodeId_AuditNodeManagementEventType_ServerId = 3445,
	//! NodeId of the node AuditNodeManagementEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditNodeManagementEventType_ClientAuditEntryId = 3446,
	//! NodeId of the node AuditNodeManagementEventType/ClientUserId.
	EnumNumericNodeId_AuditNodeManagementEventType_ClientUserId = 3447,
	//! NodeId of the node AuditAddNodesEventType/EventId.
	EnumNumericNodeId_AuditAddNodesEventType_EventId = 3448,
	//! NodeId of the node AuditAddNodesEventType/EventType.
	EnumNumericNodeId_AuditAddNodesEventType_EventType = 3449,
	//! NodeId of the node AuditAddNodesEventType/SourceNode.
	EnumNumericNodeId_AuditAddNodesEventType_SourceNode = 3450,
	//! NodeId of the node AuditAddNodesEventType/SourceName.
	EnumNumericNodeId_AuditAddNodesEventType_SourceName = 3451,
	//! NodeId of the node AuditAddNodesEventType/Time.
	EnumNumericNodeId_AuditAddNodesEventType_Time = 3452,
	//! NodeId of the node AuditAddNodesEventType/ReceiveTime.
	EnumNumericNodeId_AuditAddNodesEventType_ReceiveTime = 3453,
	//! NodeId of the node AuditAddNodesEventType/LocalTime.
	EnumNumericNodeId_AuditAddNodesEventType_LocalTime = 3454,
	//! NodeId of the node AuditAddNodesEventType/Message.
	EnumNumericNodeId_AuditAddNodesEventType_Message = 3455,
	//! NodeId of the node AuditAddNodesEventType/Severity.
	EnumNumericNodeId_AuditAddNodesEventType_Severity = 3456,
	//! NodeId of the node AuditAddNodesEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditAddNodesEventType_ActionTimeStamp = 3457,
	//! NodeId of the node AuditAddNodesEventType/Status.
	EnumNumericNodeId_AuditAddNodesEventType_Status = 3458,
	//! NodeId of the node AuditAddNodesEventType/ServerId.
	EnumNumericNodeId_AuditAddNodesEventType_ServerId = 3459,
	//! NodeId of the node AuditAddNodesEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditAddNodesEventType_ClientAuditEntryId = 3460,
	//! NodeId of the node AuditAddNodesEventType/ClientUserId.
	EnumNumericNodeId_AuditAddNodesEventType_ClientUserId = 3461,
	//! NodeId of the node AuditDeleteNodesEventType/EventId.
	EnumNumericNodeId_AuditDeleteNodesEventType_EventId = 3462,
	//! NodeId of the node AuditDeleteNodesEventType/EventType.
	EnumNumericNodeId_AuditDeleteNodesEventType_EventType = 3463,
	//! NodeId of the node AuditDeleteNodesEventType/SourceNode.
	EnumNumericNodeId_AuditDeleteNodesEventType_SourceNode = 3464,
	//! NodeId of the node AuditDeleteNodesEventType/SourceName.
	EnumNumericNodeId_AuditDeleteNodesEventType_SourceName = 3465,
	//! NodeId of the node AuditDeleteNodesEventType/Time.
	EnumNumericNodeId_AuditDeleteNodesEventType_Time = 3466,
	//! NodeId of the node AuditDeleteNodesEventType/ReceiveTime.
	EnumNumericNodeId_AuditDeleteNodesEventType_ReceiveTime = 3467,
	//! NodeId of the node AuditDeleteNodesEventType/LocalTime.
	EnumNumericNodeId_AuditDeleteNodesEventType_LocalTime = 3468,
	//! NodeId of the node AuditDeleteNodesEventType/Message.
	EnumNumericNodeId_AuditDeleteNodesEventType_Message = 3469,
	//! NodeId of the node AuditDeleteNodesEventType/Severity.
	EnumNumericNodeId_AuditDeleteNodesEventType_Severity = 3470,
	//! NodeId of the node AuditDeleteNodesEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditDeleteNodesEventType_ActionTimeStamp = 3471,
	//! NodeId of the node AuditDeleteNodesEventType/Status.
	EnumNumericNodeId_AuditDeleteNodesEventType_Status = 3472,
	//! NodeId of the node AuditDeleteNodesEventType/ServerId.
	EnumNumericNodeId_AuditDeleteNodesEventType_ServerId = 3473,
	//! NodeId of the node AuditDeleteNodesEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditDeleteNodesEventType_ClientAuditEntryId = 3474,
	//! NodeId of the node AuditDeleteNodesEventType/ClientUserId.
	EnumNumericNodeId_AuditDeleteNodesEventType_ClientUserId = 3475,
	//! NodeId of the node AuditAddReferencesEventType/EventId.
	EnumNumericNodeId_AuditAddReferencesEventType_EventId = 3476,
	//! NodeId of the node AuditAddReferencesEventType/EventType.
	EnumNumericNodeId_AuditAddReferencesEventType_EventType = 3477,
	//! NodeId of the node AuditAddReferencesEventType/SourceNode.
	EnumNumericNodeId_AuditAddReferencesEventType_SourceNode = 3478,
	//! NodeId of the node AuditAddReferencesEventType/SourceName.
	EnumNumericNodeId_AuditAddReferencesEventType_SourceName = 3479,
	//! NodeId of the node AuditAddReferencesEventType/Time.
	EnumNumericNodeId_AuditAddReferencesEventType_Time = 3480,
	//! NodeId of the node AuditAddReferencesEventType/ReceiveTime.
	EnumNumericNodeId_AuditAddReferencesEventType_ReceiveTime = 3481,
	//! NodeId of the node AuditAddReferencesEventType/LocalTime.
	EnumNumericNodeId_AuditAddReferencesEventType_LocalTime = 3482,
	//! NodeId of the node AuditAddReferencesEventType/Message.
	EnumNumericNodeId_AuditAddReferencesEventType_Message = 3483,
	//! NodeId of the node AuditAddReferencesEventType/Severity.
	EnumNumericNodeId_AuditAddReferencesEventType_Severity = 3484,
	//! NodeId of the node AuditAddReferencesEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditAddReferencesEventType_ActionTimeStamp = 3485,
	//! NodeId of the node AuditAddReferencesEventType/Status.
	EnumNumericNodeId_AuditAddReferencesEventType_Status = 3486,
	//! NodeId of the node AuditAddReferencesEventType/ServerId.
	EnumNumericNodeId_AuditAddReferencesEventType_ServerId = 3487,
	//! NodeId of the node AuditAddReferencesEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditAddReferencesEventType_ClientAuditEntryId = 3488,
	//! NodeId of the node AuditAddReferencesEventType/ClientUserId.
	EnumNumericNodeId_AuditAddReferencesEventType_ClientUserId = 3489,
	//! NodeId of the node AuditDeleteReferencesEventType/EventId.
	EnumNumericNodeId_AuditDeleteReferencesEventType_EventId = 3490,
	//! NodeId of the node AuditDeleteReferencesEventType/EventType.
	EnumNumericNodeId_AuditDeleteReferencesEventType_EventType = 3491,
	//! NodeId of the node AuditDeleteReferencesEventType/SourceNode.
	EnumNumericNodeId_AuditDeleteReferencesEventType_SourceNode = 3492,
	//! NodeId of the node AuditDeleteReferencesEventType/SourceName.
	EnumNumericNodeId_AuditDeleteReferencesEventType_SourceName = 3493,
	//! NodeId of the node AuditDeleteReferencesEventType/Time.
	EnumNumericNodeId_AuditDeleteReferencesEventType_Time = 3494,
	//! NodeId of the node AuditDeleteReferencesEventType/ReceiveTime.
	EnumNumericNodeId_AuditDeleteReferencesEventType_ReceiveTime = 3495,
	//! NodeId of the node AuditDeleteReferencesEventType/LocalTime.
	EnumNumericNodeId_AuditDeleteReferencesEventType_LocalTime = 3496,
	//! NodeId of the node AuditDeleteReferencesEventType/Message.
	EnumNumericNodeId_AuditDeleteReferencesEventType_Message = 3497,
	//! NodeId of the node AuditDeleteReferencesEventType/Severity.
	EnumNumericNodeId_AuditDeleteReferencesEventType_Severity = 3498,
	//! NodeId of the node AuditDeleteReferencesEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditDeleteReferencesEventType_ActionTimeStamp = 3499,
	//! NodeId of the node AuditDeleteReferencesEventType/Status.
	EnumNumericNodeId_AuditDeleteReferencesEventType_Status = 3500,
	//! NodeId of the node AuditDeleteReferencesEventType/ServerId.
	EnumNumericNodeId_AuditDeleteReferencesEventType_ServerId = 3501,
	//! NodeId of the node AuditDeleteReferencesEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditDeleteReferencesEventType_ClientAuditEntryId = 3502,
	//! NodeId of the node AuditDeleteReferencesEventType/ClientUserId.
	EnumNumericNodeId_AuditDeleteReferencesEventType_ClientUserId = 3503,
	//! NodeId of the node AuditUpdateEventType/EventId.
	EnumNumericNodeId_AuditUpdateEventType_EventId = 3504,
	//! NodeId of the node AuditUpdateEventType/EventType.
	EnumNumericNodeId_AuditUpdateEventType_EventType = 3505,
	//! NodeId of the node AuditUpdateEventType/SourceNode.
	EnumNumericNodeId_AuditUpdateEventType_SourceNode = 3506,
	//! NodeId of the node AuditUpdateEventType/SourceName.
	EnumNumericNodeId_AuditUpdateEventType_SourceName = 3507,
	//! NodeId of the node AuditUpdateEventType/Time.
	EnumNumericNodeId_AuditUpdateEventType_Time = 3508,
	//! NodeId of the node AuditUpdateEventType/ReceiveTime.
	EnumNumericNodeId_AuditUpdateEventType_ReceiveTime = 3509,
	//! NodeId of the node AuditUpdateEventType/LocalTime.
	EnumNumericNodeId_AuditUpdateEventType_LocalTime = 3510,
	//! NodeId of the node AuditUpdateEventType/Message.
	EnumNumericNodeId_AuditUpdateEventType_Message = 3511,
	//! NodeId of the node AuditUpdateEventType/Severity.
	EnumNumericNodeId_AuditUpdateEventType_Severity = 3512,
	//! NodeId of the node AuditUpdateEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditUpdateEventType_ActionTimeStamp = 3513,
	//! NodeId of the node AuditUpdateEventType/Status.
	EnumNumericNodeId_AuditUpdateEventType_Status = 3514,
	//! NodeId of the node AuditUpdateEventType/ServerId.
	EnumNumericNodeId_AuditUpdateEventType_ServerId = 3515,
	//! NodeId of the node AuditUpdateEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditUpdateEventType_ClientAuditEntryId = 3516,
	//! NodeId of the node AuditUpdateEventType/ClientUserId.
	EnumNumericNodeId_AuditUpdateEventType_ClientUserId = 3517,
	//! NodeId of the node AuditWriteUpdateEventType/EventId.
	EnumNumericNodeId_AuditWriteUpdateEventType_EventId = 3518,
	//! NodeId of the node AuditWriteUpdateEventType/EventType.
	EnumNumericNodeId_AuditWriteUpdateEventType_EventType = 3519,
	//! NodeId of the node AuditWriteUpdateEventType/SourceNode.
	EnumNumericNodeId_AuditWriteUpdateEventType_SourceNode = 3520,
	//! NodeId of the node AuditWriteUpdateEventType/SourceName.
	EnumNumericNodeId_AuditWriteUpdateEventType_SourceName = 3521,
	//! NodeId of the node AuditWriteUpdateEventType/Time.
	EnumNumericNodeId_AuditWriteUpdateEventType_Time = 3522,
	//! NodeId of the node AuditWriteUpdateEventType/ReceiveTime.
	EnumNumericNodeId_AuditWriteUpdateEventType_ReceiveTime = 3523,
	//! NodeId of the node AuditWriteUpdateEventType/LocalTime.
	EnumNumericNodeId_AuditWriteUpdateEventType_LocalTime = 3524,
	//! NodeId of the node AuditWriteUpdateEventType/Message.
	EnumNumericNodeId_AuditWriteUpdateEventType_Message = 3525,
	//! NodeId of the node AuditWriteUpdateEventType/Severity.
	EnumNumericNodeId_AuditWriteUpdateEventType_Severity = 3526,
	//! NodeId of the node AuditWriteUpdateEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditWriteUpdateEventType_ActionTimeStamp = 3527,
	//! NodeId of the node AuditWriteUpdateEventType/Status.
	EnumNumericNodeId_AuditWriteUpdateEventType_Status = 3528,
	//! NodeId of the node AuditWriteUpdateEventType/ServerId.
	EnumNumericNodeId_AuditWriteUpdateEventType_ServerId = 3529,
	//! NodeId of the node AuditWriteUpdateEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditWriteUpdateEventType_ClientAuditEntryId = 3530,
	//! NodeId of the node AuditWriteUpdateEventType/ClientUserId.
	EnumNumericNodeId_AuditWriteUpdateEventType_ClientUserId = 3531,
	//! NodeId of the node AuditHistoryUpdateEventType/EventId.
	EnumNumericNodeId_AuditHistoryUpdateEventType_EventId = 3532,
	//! NodeId of the node AuditHistoryUpdateEventType/EventType.
	EnumNumericNodeId_AuditHistoryUpdateEventType_EventType = 3533,
	//! NodeId of the node AuditHistoryUpdateEventType/SourceNode.
	EnumNumericNodeId_AuditHistoryUpdateEventType_SourceNode = 3534,
	//! NodeId of the node AuditHistoryUpdateEventType/SourceName.
	EnumNumericNodeId_AuditHistoryUpdateEventType_SourceName = 3535,
	//! NodeId of the node AuditHistoryUpdateEventType/Time.
	EnumNumericNodeId_AuditHistoryUpdateEventType_Time = 3536,
	//! NodeId of the node AuditHistoryUpdateEventType/ReceiveTime.
	EnumNumericNodeId_AuditHistoryUpdateEventType_ReceiveTime = 3537,
	//! NodeId of the node AuditHistoryUpdateEventType/LocalTime.
	EnumNumericNodeId_AuditHistoryUpdateEventType_LocalTime = 3538,
	//! NodeId of the node AuditHistoryUpdateEventType/Message.
	EnumNumericNodeId_AuditHistoryUpdateEventType_Message = 3539,
	//! NodeId of the node AuditHistoryUpdateEventType/Severity.
	EnumNumericNodeId_AuditHistoryUpdateEventType_Severity = 3540,
	//! NodeId of the node AuditHistoryUpdateEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditHistoryUpdateEventType_ActionTimeStamp = 3541,
	//! NodeId of the node AuditHistoryUpdateEventType/Status.
	EnumNumericNodeId_AuditHistoryUpdateEventType_Status = 3542,
	//! NodeId of the node AuditHistoryUpdateEventType/ServerId.
	EnumNumericNodeId_AuditHistoryUpdateEventType_ServerId = 3543,
	//! NodeId of the node AuditHistoryUpdateEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditHistoryUpdateEventType_ClientAuditEntryId = 3544,
	//! NodeId of the node AuditHistoryUpdateEventType/ClientUserId.
	EnumNumericNodeId_AuditHistoryUpdateEventType_ClientUserId = 3545,
	//! NodeId of the node AuditHistoryEventUpdateEventType/EventId.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_EventId = 3546,
	//! NodeId of the node AuditHistoryEventUpdateEventType/EventType.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_EventType = 3547,
	//! NodeId of the node AuditHistoryEventUpdateEventType/SourceNode.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_SourceNode = 3548,
	//! NodeId of the node AuditHistoryEventUpdateEventType/SourceName.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_SourceName = 3549,
	//! NodeId of the node AuditHistoryEventUpdateEventType/Time.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_Time = 3550,
	//! NodeId of the node AuditHistoryEventUpdateEventType/ReceiveTime.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_ReceiveTime = 3551,
	//! NodeId of the node AuditHistoryEventUpdateEventType/LocalTime.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_LocalTime = 3552,
	//! NodeId of the node AuditHistoryEventUpdateEventType/Message.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_Message = 3553,
	//! NodeId of the node AuditHistoryEventUpdateEventType/Severity.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_Severity = 3554,
	//! NodeId of the node AuditHistoryEventUpdateEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_ActionTimeStamp = 3555,
	//! NodeId of the node AuditHistoryEventUpdateEventType/Status.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_Status = 3556,
	//! NodeId of the node AuditHistoryEventUpdateEventType/ServerId.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_ServerId = 3557,
	//! NodeId of the node AuditHistoryEventUpdateEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_ClientAuditEntryId = 3558,
	//! NodeId of the node AuditHistoryEventUpdateEventType/ClientUserId.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_ClientUserId = 3559,
	//! NodeId of the node AuditHistoryEventUpdateEventType/ParameterDataTypeId.
	EnumNumericNodeId_AuditHistoryEventUpdateEventType_ParameterDataTypeId = 3560,
	//! NodeId of the node AuditHistoryValueUpdateEventType/EventId.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_EventId = 3561,
	//! NodeId of the node AuditHistoryValueUpdateEventType/EventType.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_EventType = 3562,
	//! NodeId of the node AuditHistoryValueUpdateEventType/SourceNode.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_SourceNode = 3563,
	//! NodeId of the node AuditHistoryValueUpdateEventType/SourceName.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_SourceName = 3564,
	//! NodeId of the node AuditHistoryValueUpdateEventType/Time.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_Time = 3565,
	//! NodeId of the node AuditHistoryValueUpdateEventType/ReceiveTime.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_ReceiveTime = 3566,
	//! NodeId of the node AuditHistoryValueUpdateEventType/LocalTime.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_LocalTime = 3567,
	//! NodeId of the node AuditHistoryValueUpdateEventType/Message.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_Message = 3568,
	//! NodeId of the node AuditHistoryValueUpdateEventType/Severity.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_Severity = 3569,
	//! NodeId of the node AuditHistoryValueUpdateEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_ActionTimeStamp = 3570,
	//! NodeId of the node AuditHistoryValueUpdateEventType/Status.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_Status = 3571,
	//! NodeId of the node AuditHistoryValueUpdateEventType/ServerId.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_ServerId = 3572,
	//! NodeId of the node AuditHistoryValueUpdateEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_ClientAuditEntryId = 3573,
	//! NodeId of the node AuditHistoryValueUpdateEventType/ClientUserId.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_ClientUserId = 3574,
	//! NodeId of the node AuditHistoryValueUpdateEventType/ParameterDataTypeId.
	EnumNumericNodeId_AuditHistoryValueUpdateEventType_ParameterDataTypeId = 3575,
	//! NodeId of the node AuditHistoryDeleteEventType/EventId.
	EnumNumericNodeId_AuditHistoryDeleteEventType_EventId = 3576,
	//! NodeId of the node AuditHistoryDeleteEventType/EventType.
	EnumNumericNodeId_AuditHistoryDeleteEventType_EventType = 3577,
	//! NodeId of the node AuditHistoryDeleteEventType/SourceNode.
	EnumNumericNodeId_AuditHistoryDeleteEventType_SourceNode = 3578,
	//! NodeId of the node AuditHistoryDeleteEventType/SourceName.
	EnumNumericNodeId_AuditHistoryDeleteEventType_SourceName = 3579,
	//! NodeId of the node AuditHistoryDeleteEventType/Time.
	EnumNumericNodeId_AuditHistoryDeleteEventType_Time = 3580,
	//! NodeId of the node AuditHistoryDeleteEventType/ReceiveTime.
	EnumNumericNodeId_AuditHistoryDeleteEventType_ReceiveTime = 3581,
	//! NodeId of the node AuditHistoryDeleteEventType/LocalTime.
	EnumNumericNodeId_AuditHistoryDeleteEventType_LocalTime = 3582,
	//! NodeId of the node AuditHistoryDeleteEventType/Message.
	EnumNumericNodeId_AuditHistoryDeleteEventType_Message = 3583,
	//! NodeId of the node AuditHistoryDeleteEventType/Severity.
	EnumNumericNodeId_AuditHistoryDeleteEventType_Severity = 3584,
	//! NodeId of the node AuditHistoryDeleteEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditHistoryDeleteEventType_ActionTimeStamp = 3585,
	//! NodeId of the node AuditHistoryDeleteEventType/Status.
	EnumNumericNodeId_AuditHistoryDeleteEventType_Status = 3586,
	//! NodeId of the node AuditHistoryDeleteEventType/ServerId.
	EnumNumericNodeId_AuditHistoryDeleteEventType_ServerId = 3587,
	//! NodeId of the node AuditHistoryDeleteEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditHistoryDeleteEventType_ClientAuditEntryId = 3588,
	//! NodeId of the node AuditHistoryDeleteEventType/ClientUserId.
	EnumNumericNodeId_AuditHistoryDeleteEventType_ClientUserId = 3589,
	//! NodeId of the node AuditHistoryDeleteEventType/ParameterDataTypeId.
	EnumNumericNodeId_AuditHistoryDeleteEventType_ParameterDataTypeId = 3590,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/EventId.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_EventId = 3591,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/EventType.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_EventType = 3592,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/SourceNode.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_SourceNode = 3593,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/SourceName.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_SourceName = 3594,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/Time.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_Time = 3595,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/ReceiveTime.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_ReceiveTime = 3596,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/LocalTime.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_LocalTime = 3597,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/Message.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_Message = 3598,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/Severity.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_Severity = 3599,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_ActionTimeStamp = 3600,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/Status.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_Status = 3601,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/ServerId.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_ServerId = 3602,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_ClientAuditEntryId = 3603,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/ClientUserId.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_ClientUserId = 3604,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/ParameterDataTypeId.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_ParameterDataTypeId = 3605,
	//! NodeId of the node AuditHistoryRawModifyDeleteEventType/UpdatedNode.
	EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType_UpdatedNode = 3606,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/EventId.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_EventId = 3607,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/EventType.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_EventType = 3608,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/SourceNode.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_SourceNode = 3609,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/SourceName.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_SourceName = 3610,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/Time.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_Time = 3611,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/ReceiveTime.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_ReceiveTime = 3612,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/LocalTime.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_LocalTime = 3613,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/Message.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_Message = 3614,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/Severity.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_Severity = 3615,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_ActionTimeStamp = 3616,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/Status.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_Status = 3617,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/ServerId.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_ServerId = 3618,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_ClientAuditEntryId = 3619,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/ClientUserId.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_ClientUserId = 3620,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/ParameterDataTypeId.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_ParameterDataTypeId = 3621,
	//! NodeId of the node AuditHistoryAtTimeDeleteEventType/UpdatedNode.
	EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType_UpdatedNode = 3622,
	//! NodeId of the node AuditHistoryEventDeleteEventType/EventId.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_EventId = 3623,
	//! NodeId of the node AuditHistoryEventDeleteEventType/EventType.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_EventType = 3624,
	//! NodeId of the node AuditHistoryEventDeleteEventType/SourceNode.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_SourceNode = 3625,
	//! NodeId of the node AuditHistoryEventDeleteEventType/SourceName.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_SourceName = 3626,
	//! NodeId of the node AuditHistoryEventDeleteEventType/Time.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_Time = 3627,
	//! NodeId of the node AuditHistoryEventDeleteEventType/ReceiveTime.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_ReceiveTime = 3628,
	//! NodeId of the node AuditHistoryEventDeleteEventType/LocalTime.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_LocalTime = 3629,
	//! NodeId of the node AuditHistoryEventDeleteEventType/Message.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_Message = 3630,
	//! NodeId of the node AuditHistoryEventDeleteEventType/Severity.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_Severity = 3631,
	//! NodeId of the node AuditHistoryEventDeleteEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_ActionTimeStamp = 3632,
	//! NodeId of the node AuditHistoryEventDeleteEventType/Status.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_Status = 3633,
	//! NodeId of the node AuditHistoryEventDeleteEventType/ServerId.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_ServerId = 3634,
	//! NodeId of the node AuditHistoryEventDeleteEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_ClientAuditEntryId = 3635,
	//! NodeId of the node AuditHistoryEventDeleteEventType/ClientUserId.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_ClientUserId = 3636,
	//! NodeId of the node AuditHistoryEventDeleteEventType/ParameterDataTypeId.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_ParameterDataTypeId = 3637,
	//! NodeId of the node AuditHistoryEventDeleteEventType/UpdatedNode.
	EnumNumericNodeId_AuditHistoryEventDeleteEventType_UpdatedNode = 3638,
	//! NodeId of the node AuditUpdateMethodEventType/EventId.
	EnumNumericNodeId_AuditUpdateMethodEventType_EventId = 3639,
	//! NodeId of the node AuditUpdateMethodEventType/EventType.
	EnumNumericNodeId_AuditUpdateMethodEventType_EventType = 3640,
	//! NodeId of the node AuditUpdateMethodEventType/SourceNode.
	EnumNumericNodeId_AuditUpdateMethodEventType_SourceNode = 3641,
	//! NodeId of the node AuditUpdateMethodEventType/SourceName.
	EnumNumericNodeId_AuditUpdateMethodEventType_SourceName = 3642,
	//! NodeId of the node AuditUpdateMethodEventType/Time.
	EnumNumericNodeId_AuditUpdateMethodEventType_Time = 3643,
	//! NodeId of the node AuditUpdateMethodEventType/ReceiveTime.
	EnumNumericNodeId_AuditUpdateMethodEventType_ReceiveTime = 3644,
	//! NodeId of the node AuditUpdateMethodEventType/LocalTime.
	EnumNumericNodeId_AuditUpdateMethodEventType_LocalTime = 3645,
	//! NodeId of the node AuditUpdateMethodEventType/Message.
	EnumNumericNodeId_AuditUpdateMethodEventType_Message = 3646,
	//! NodeId of the node AuditUpdateMethodEventType/Severity.
	EnumNumericNodeId_AuditUpdateMethodEventType_Severity = 3647,
	//! NodeId of the node AuditUpdateMethodEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditUpdateMethodEventType_ActionTimeStamp = 3648,
	//! NodeId of the node AuditUpdateMethodEventType/Status.
	EnumNumericNodeId_AuditUpdateMethodEventType_Status = 3649,
	//! NodeId of the node AuditUpdateMethodEventType/ServerId.
	EnumNumericNodeId_AuditUpdateMethodEventType_ServerId = 3650,
	//! NodeId of the node AuditUpdateMethodEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditUpdateMethodEventType_ClientAuditEntryId = 3651,
	//! NodeId of the node AuditUpdateMethodEventType/ClientUserId.
	EnumNumericNodeId_AuditUpdateMethodEventType_ClientUserId = 3652,
	//! NodeId of the node SystemEventType/EventId.
	EnumNumericNodeId_SystemEventType_EventId = 3653,
	//! NodeId of the node SystemEventType/EventType.
	EnumNumericNodeId_SystemEventType_EventType = 3654,
	//! NodeId of the node SystemEventType/SourceNode.
	EnumNumericNodeId_SystemEventType_SourceNode = 3655,
	//! NodeId of the node SystemEventType/SourceName.
	EnumNumericNodeId_SystemEventType_SourceName = 3656,
	//! NodeId of the node SystemEventType/Time.
	EnumNumericNodeId_SystemEventType_Time = 3657,
	//! NodeId of the node SystemEventType/ReceiveTime.
	EnumNumericNodeId_SystemEventType_ReceiveTime = 3658,
	//! NodeId of the node SystemEventType/LocalTime.
	EnumNumericNodeId_SystemEventType_LocalTime = 3659,
	//! NodeId of the node SystemEventType/Message.
	EnumNumericNodeId_SystemEventType_Message = 3660,
	//! NodeId of the node SystemEventType/Severity.
	EnumNumericNodeId_SystemEventType_Severity = 3661,
	//! NodeId of the node DeviceFailureEventType/EventId.
	EnumNumericNodeId_DeviceFailureEventType_EventId = 3662,
	//! NodeId of the node DeviceFailureEventType/EventType.
	EnumNumericNodeId_DeviceFailureEventType_EventType = 3663,
	//! NodeId of the node DeviceFailureEventType/SourceNode.
	EnumNumericNodeId_DeviceFailureEventType_SourceNode = 3664,
	//! NodeId of the node DeviceFailureEventType/SourceName.
	EnumNumericNodeId_DeviceFailureEventType_SourceName = 3665,
	//! NodeId of the node DeviceFailureEventType/Time.
	EnumNumericNodeId_DeviceFailureEventType_Time = 3666,
	//! NodeId of the node DeviceFailureEventType/ReceiveTime.
	EnumNumericNodeId_DeviceFailureEventType_ReceiveTime = 3667,
	//! NodeId of the node DeviceFailureEventType/LocalTime.
	EnumNumericNodeId_DeviceFailureEventType_LocalTime = 3668,
	//! NodeId of the node DeviceFailureEventType/Message.
	EnumNumericNodeId_DeviceFailureEventType_Message = 3669,
	//! NodeId of the node DeviceFailureEventType/Severity.
	EnumNumericNodeId_DeviceFailureEventType_Severity = 3670,
	//! NodeId of the node BaseModelChangeEventType/EventId.
	EnumNumericNodeId_BaseModelChangeEventType_EventId = 3671,
	//! NodeId of the node BaseModelChangeEventType/EventType.
	EnumNumericNodeId_BaseModelChangeEventType_EventType = 3672,
	//! NodeId of the node BaseModelChangeEventType/SourceNode.
	EnumNumericNodeId_BaseModelChangeEventType_SourceNode = 3673,
	//! NodeId of the node BaseModelChangeEventType/SourceName.
	EnumNumericNodeId_BaseModelChangeEventType_SourceName = 3674,
	//! NodeId of the node BaseModelChangeEventType/Time.
	EnumNumericNodeId_BaseModelChangeEventType_Time = 3675,
	//! NodeId of the node BaseModelChangeEventType/ReceiveTime.
	EnumNumericNodeId_BaseModelChangeEventType_ReceiveTime = 3676,
	//! NodeId of the node BaseModelChangeEventType/LocalTime.
	EnumNumericNodeId_BaseModelChangeEventType_LocalTime = 3677,
	//! NodeId of the node BaseModelChangeEventType/Message.
	EnumNumericNodeId_BaseModelChangeEventType_Message = 3678,
	//! NodeId of the node BaseModelChangeEventType/Severity.
	EnumNumericNodeId_BaseModelChangeEventType_Severity = 3679,
	//! NodeId of the node GeneralModelChangeEventType/EventId.
	EnumNumericNodeId_GeneralModelChangeEventType_EventId = 3680,
	//! NodeId of the node GeneralModelChangeEventType/EventType.
	EnumNumericNodeId_GeneralModelChangeEventType_EventType = 3681,
	//! NodeId of the node GeneralModelChangeEventType/SourceNode.
	EnumNumericNodeId_GeneralModelChangeEventType_SourceNode = 3682,
	//! NodeId of the node GeneralModelChangeEventType/SourceName.
	EnumNumericNodeId_GeneralModelChangeEventType_SourceName = 3683,
	//! NodeId of the node GeneralModelChangeEventType/Time.
	EnumNumericNodeId_GeneralModelChangeEventType_Time = 3684,
	//! NodeId of the node GeneralModelChangeEventType/ReceiveTime.
	EnumNumericNodeId_GeneralModelChangeEventType_ReceiveTime = 3685,
	//! NodeId of the node GeneralModelChangeEventType/LocalTime.
	EnumNumericNodeId_GeneralModelChangeEventType_LocalTime = 3686,
	//! NodeId of the node GeneralModelChangeEventType/Message.
	EnumNumericNodeId_GeneralModelChangeEventType_Message = 3687,
	//! NodeId of the node GeneralModelChangeEventType/Severity.
	EnumNumericNodeId_GeneralModelChangeEventType_Severity = 3688,
	//! NodeId of the node SemanticChangeEventType/EventId.
	EnumNumericNodeId_SemanticChangeEventType_EventId = 3689,
	//! NodeId of the node SemanticChangeEventType/EventType.
	EnumNumericNodeId_SemanticChangeEventType_EventType = 3690,
	//! NodeId of the node SemanticChangeEventType/SourceNode.
	EnumNumericNodeId_SemanticChangeEventType_SourceNode = 3691,
	//! NodeId of the node SemanticChangeEventType/SourceName.
	EnumNumericNodeId_SemanticChangeEventType_SourceName = 3692,
	//! NodeId of the node SemanticChangeEventType/Time.
	EnumNumericNodeId_SemanticChangeEventType_Time = 3693,
	//! NodeId of the node SemanticChangeEventType/ReceiveTime.
	EnumNumericNodeId_SemanticChangeEventType_ReceiveTime = 3694,
	//! NodeId of the node SemanticChangeEventType/LocalTime.
	EnumNumericNodeId_SemanticChangeEventType_LocalTime = 3695,
	//! NodeId of the node SemanticChangeEventType/Message.
	EnumNumericNodeId_SemanticChangeEventType_Message = 3696,
	//! NodeId of the node SemanticChangeEventType/Severity.
	EnumNumericNodeId_SemanticChangeEventType_Severity = 3697,
	//! NodeId of the node ServerStatusType/BuildInfo/ProductUri.
	EnumNumericNodeId_ServerStatusType_BuildInfo_ProductUri = 3698,
	//! NodeId of the node ServerStatusType/BuildInfo/ManufacturerName.
	EnumNumericNodeId_ServerStatusType_BuildInfo_ManufacturerName = 3699,
	//! NodeId of the node ServerStatusType/BuildInfo/ProductName.
	EnumNumericNodeId_ServerStatusType_BuildInfo_ProductName = 3700,
	//! NodeId of the node ServerStatusType/BuildInfo/SoftwareVersion.
	EnumNumericNodeId_ServerStatusType_BuildInfo_SoftwareVersion = 3701,
	//! NodeId of the node ServerStatusType/BuildInfo/BuildNumber.
	EnumNumericNodeId_ServerStatusType_BuildInfo_BuildNumber = 3702,
	//! NodeId of the node ServerStatusType/BuildInfo/BuildDate.
	EnumNumericNodeId_ServerStatusType_BuildInfo_BuildDate = 3703,
	//! NodeId of the node Server/ServerCapabilities/SoftwareCertificates.
	EnumNumericNodeId_Server_ServerCapabilities_SoftwareCertificates = 3704,
	//! NodeId of the node Server/ServerDiagnostics/ServerDiagnosticsSummary/RejectedSessionCount.
	EnumNumericNodeId_Server_ServerDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount = 3705,
	//! NodeId of the node Server/ServerDiagnostics/SessionsDiagnosticsSummary.
	EnumNumericNodeId_Server_ServerDiagnostics_SessionsDiagnosticsSummary = 3706,
	//! NodeId of the node Server/ServerDiagnostics/SessionsDiagnosticsSummary/SessionDiagnosticsArray.
	EnumNumericNodeId_Server_ServerDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray = 3707,
	//! NodeId of the node Server/ServerDiagnostics/SessionsDiagnosticsSummary/SessionSecurityDiagnosticsArray.
	EnumNumericNodeId_Server_ServerDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray = 3708,
	//! NodeId of the node Server/ServerRedundancy/RedundancySupport.
	EnumNumericNodeId_Server_ServerRedundancy_RedundancySupport = 3709,
	//! NodeId of the node FiniteStateVariableType/Name.
	EnumNumericNodeId_FiniteStateVariableType_Name = 3714,
	//! NodeId of the node FiniteStateVariableType/Number.
	EnumNumericNodeId_FiniteStateVariableType_Number = 3715,
	//! NodeId of the node FiniteStateVariableType/EffectiveDisplayName.
	EnumNumericNodeId_FiniteStateVariableType_EffectiveDisplayName = 3716,
	//! NodeId of the node FiniteTransitionVariableType/Name.
	EnumNumericNodeId_FiniteTransitionVariableType_Name = 3717,
	//! NodeId of the node FiniteTransitionVariableType/Number.
	EnumNumericNodeId_FiniteTransitionVariableType_Number = 3718,
	//! NodeId of the node FiniteTransitionVariableType/TransitionTime.
	EnumNumericNodeId_FiniteTransitionVariableType_TransitionTime = 3719,
	//! NodeId of the node StateMachineType/CurrentState/Id.
	EnumNumericNodeId_StateMachineType_CurrentState_Id = 3720,
	//! NodeId of the node StateMachineType/CurrentState/Name.
	EnumNumericNodeId_StateMachineType_CurrentState_Name = 3721,
	//! NodeId of the node StateMachineType/CurrentState/Number.
	EnumNumericNodeId_StateMachineType_CurrentState_Number = 3722,
	//! NodeId of the node StateMachineType/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_StateMachineType_CurrentState_EffectiveDisplayName = 3723,
	//! NodeId of the node StateMachineType/LastTransition/Id.
	EnumNumericNodeId_StateMachineType_LastTransition_Id = 3724,
	//! NodeId of the node StateMachineType/LastTransition/Name.
	EnumNumericNodeId_StateMachineType_LastTransition_Name = 3725,
	//! NodeId of the node StateMachineType/LastTransition/Number.
	EnumNumericNodeId_StateMachineType_LastTransition_Number = 3726,
	//! NodeId of the node StateMachineType/LastTransition/TransitionTime.
	EnumNumericNodeId_StateMachineType_LastTransition_TransitionTime = 3727,
	//! NodeId of the node FiniteStateMachineType/CurrentState/Id.
	EnumNumericNodeId_FiniteStateMachineType_CurrentState_Id = 3728,
	//! NodeId of the node FiniteStateMachineType/CurrentState/Name.
	EnumNumericNodeId_FiniteStateMachineType_CurrentState_Name = 3729,
	//! NodeId of the node FiniteStateMachineType/CurrentState/Number.
	EnumNumericNodeId_FiniteStateMachineType_CurrentState_Number = 3730,
	//! NodeId of the node FiniteStateMachineType/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_FiniteStateMachineType_CurrentState_EffectiveDisplayName = 3731,
	//! NodeId of the node FiniteStateMachineType/LastTransition/Id.
	EnumNumericNodeId_FiniteStateMachineType_LastTransition_Id = 3732,
	//! NodeId of the node FiniteStateMachineType/LastTransition/Name.
	EnumNumericNodeId_FiniteStateMachineType_LastTransition_Name = 3733,
	//! NodeId of the node FiniteStateMachineType/LastTransition/Number.
	EnumNumericNodeId_FiniteStateMachineType_LastTransition_Number = 3734,
	//! NodeId of the node FiniteStateMachineType/LastTransition/TransitionTime.
	EnumNumericNodeId_FiniteStateMachineType_LastTransition_TransitionTime = 3735,
	//! NodeId of the node InitialStateType/StateNumber.
	EnumNumericNodeId_InitialStateType_StateNumber = 3736,
	//! NodeId of the node TransitionEventType/EventId.
	EnumNumericNodeId_TransitionEventType_EventId = 3737,
	//! NodeId of the node TransitionEventType/EventType.
	EnumNumericNodeId_TransitionEventType_EventType = 3738,
	//! NodeId of the node TransitionEventType/SourceNode.
	EnumNumericNodeId_TransitionEventType_SourceNode = 3739,
	//! NodeId of the node TransitionEventType/SourceName.
	EnumNumericNodeId_TransitionEventType_SourceName = 3740,
	//! NodeId of the node TransitionEventType/Time.
	EnumNumericNodeId_TransitionEventType_Time = 3741,
	//! NodeId of the node TransitionEventType/ReceiveTime.
	EnumNumericNodeId_TransitionEventType_ReceiveTime = 3742,
	//! NodeId of the node TransitionEventType/LocalTime.
	EnumNumericNodeId_TransitionEventType_LocalTime = 3743,
	//! NodeId of the node TransitionEventType/Message.
	EnumNumericNodeId_TransitionEventType_Message = 3744,
	//! NodeId of the node TransitionEventType/Severity.
	EnumNumericNodeId_TransitionEventType_Severity = 3745,
	//! NodeId of the node TransitionEventType/FromState/Id.
	EnumNumericNodeId_TransitionEventType_FromState_Id = 3746,
	//! NodeId of the node TransitionEventType/FromState/Name.
	EnumNumericNodeId_TransitionEventType_FromState_Name = 3747,
	//! NodeId of the node TransitionEventType/FromState/Number.
	EnumNumericNodeId_TransitionEventType_FromState_Number = 3748,
	//! NodeId of the node TransitionEventType/FromState/EffectiveDisplayName.
	EnumNumericNodeId_TransitionEventType_FromState_EffectiveDisplayName = 3749,
	//! NodeId of the node TransitionEventType/ToState/Id.
	EnumNumericNodeId_TransitionEventType_ToState_Id = 3750,
	//! NodeId of the node TransitionEventType/ToState/Name.
	EnumNumericNodeId_TransitionEventType_ToState_Name = 3751,
	//! NodeId of the node TransitionEventType/ToState/Number.
	EnumNumericNodeId_TransitionEventType_ToState_Number = 3752,
	//! NodeId of the node TransitionEventType/ToState/EffectiveDisplayName.
	EnumNumericNodeId_TransitionEventType_ToState_EffectiveDisplayName = 3753,
	//! NodeId of the node TransitionEventType/Transition/Id.
	EnumNumericNodeId_TransitionEventType_Transition_Id = 3754,
	//! NodeId of the node TransitionEventType/Transition/Name.
	EnumNumericNodeId_TransitionEventType_Transition_Name = 3755,
	//! NodeId of the node TransitionEventType/Transition/Number.
	EnumNumericNodeId_TransitionEventType_Transition_Number = 3756,
	//! NodeId of the node TransitionEventType/Transition/TransitionTime.
	EnumNumericNodeId_TransitionEventType_Transition_TransitionTime = 3757,
	//! NodeId of the node AuditUpdateStateEventType/EventId.
	EnumNumericNodeId_AuditUpdateStateEventType_EventId = 3758,
	//! NodeId of the node AuditUpdateStateEventType/EventType.
	EnumNumericNodeId_AuditUpdateStateEventType_EventType = 3759,
	//! NodeId of the node AuditUpdateStateEventType/SourceNode.
	EnumNumericNodeId_AuditUpdateStateEventType_SourceNode = 3760,
	//! NodeId of the node AuditUpdateStateEventType/SourceName.
	EnumNumericNodeId_AuditUpdateStateEventType_SourceName = 3761,
	//! NodeId of the node AuditUpdateStateEventType/Time.
	EnumNumericNodeId_AuditUpdateStateEventType_Time = 3762,
	//! NodeId of the node AuditUpdateStateEventType/ReceiveTime.
	EnumNumericNodeId_AuditUpdateStateEventType_ReceiveTime = 3763,
	//! NodeId of the node AuditUpdateStateEventType/LocalTime.
	EnumNumericNodeId_AuditUpdateStateEventType_LocalTime = 3764,
	//! NodeId of the node AuditUpdateStateEventType/Message.
	EnumNumericNodeId_AuditUpdateStateEventType_Message = 3765,
	//! NodeId of the node AuditUpdateStateEventType/Severity.
	EnumNumericNodeId_AuditUpdateStateEventType_Severity = 3766,
	//! NodeId of the node AuditUpdateStateEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditUpdateStateEventType_ActionTimeStamp = 3767,
	//! NodeId of the node AuditUpdateStateEventType/Status.
	EnumNumericNodeId_AuditUpdateStateEventType_Status = 3768,
	//! NodeId of the node AuditUpdateStateEventType/ServerId.
	EnumNumericNodeId_AuditUpdateStateEventType_ServerId = 3769,
	//! NodeId of the node AuditUpdateStateEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditUpdateStateEventType_ClientAuditEntryId = 3770,
	//! NodeId of the node AuditUpdateStateEventType/ClientUserId.
	EnumNumericNodeId_AuditUpdateStateEventType_ClientUserId = 3771,
	//! NodeId of the node AuditUpdateStateEventType/MethodId.
	EnumNumericNodeId_AuditUpdateStateEventType_MethodId = 3772,
	//! NodeId of the node AuditUpdateStateEventType/InputArguments.
	EnumNumericNodeId_AuditUpdateStateEventType_InputArguments = 3773,
	//! NodeId of the node AnalogItemType/Definition.
	EnumNumericNodeId_AnalogItemType_Definition = 3774,
	//! NodeId of the node AnalogItemType/ValuePrecision.
	EnumNumericNodeId_AnalogItemType_ValuePrecision = 3775,
	//! NodeId of the node DiscreteItemType/Definition.
	EnumNumericNodeId_DiscreteItemType_Definition = 3776,
	//! NodeId of the node DiscreteItemType/ValuePrecision.
	EnumNumericNodeId_DiscreteItemType_ValuePrecision = 3777,
	//! NodeId of the node TwoStateDiscreteType/Definition.
	EnumNumericNodeId_TwoStateDiscreteType_Definition = 3778,
	//! NodeId of the node TwoStateDiscreteType/ValuePrecision.
	EnumNumericNodeId_TwoStateDiscreteType_ValuePrecision = 3779,
	//! NodeId of the node MultiStateDiscreteType/Definition.
	EnumNumericNodeId_MultiStateDiscreteType_Definition = 3780,
	//! NodeId of the node MultiStateDiscreteType/ValuePrecision.
	EnumNumericNodeId_MultiStateDiscreteType_ValuePrecision = 3781,
	//! NodeId of the node ProgramTransitionEventType/EventId.
	EnumNumericNodeId_ProgramTransitionEventType_EventId = 3782,
	//! NodeId of the node ProgramTransitionEventType/EventType.
	EnumNumericNodeId_ProgramTransitionEventType_EventType = 3783,
	//! NodeId of the node ProgramTransitionEventType/SourceNode.
	EnumNumericNodeId_ProgramTransitionEventType_SourceNode = 3784,
	//! NodeId of the node ProgramTransitionEventType/SourceName.
	EnumNumericNodeId_ProgramTransitionEventType_SourceName = 3785,
	//! NodeId of the node ProgramTransitionEventType/Time.
	EnumNumericNodeId_ProgramTransitionEventType_Time = 3786,
	//! NodeId of the node ProgramTransitionEventType/ReceiveTime.
	EnumNumericNodeId_ProgramTransitionEventType_ReceiveTime = 3787,
	//! NodeId of the node ProgramTransitionEventType/LocalTime.
	EnumNumericNodeId_ProgramTransitionEventType_LocalTime = 3788,
	//! NodeId of the node ProgramTransitionEventType/Message.
	EnumNumericNodeId_ProgramTransitionEventType_Message = 3789,
	//! NodeId of the node ProgramTransitionEventType/Severity.
	EnumNumericNodeId_ProgramTransitionEventType_Severity = 3790,
	//! NodeId of the node ProgramTransitionEventType/FromState.
	EnumNumericNodeId_ProgramTransitionEventType_FromState = 3791,
	//! NodeId of the node ProgramTransitionEventType/FromState/Id.
	EnumNumericNodeId_ProgramTransitionEventType_FromState_Id = 3792,
	//! NodeId of the node ProgramTransitionEventType/FromState/Name.
	EnumNumericNodeId_ProgramTransitionEventType_FromState_Name = 3793,
	//! NodeId of the node ProgramTransitionEventType/FromState/Number.
	EnumNumericNodeId_ProgramTransitionEventType_FromState_Number = 3794,
	//! NodeId of the node ProgramTransitionEventType/FromState/EffectiveDisplayName.
	EnumNumericNodeId_ProgramTransitionEventType_FromState_EffectiveDisplayName = 3795,
	//! NodeId of the node ProgramTransitionEventType/ToState.
	EnumNumericNodeId_ProgramTransitionEventType_ToState = 3796,
	//! NodeId of the node ProgramTransitionEventType/ToState/Id.
	EnumNumericNodeId_ProgramTransitionEventType_ToState_Id = 3797,
	//! NodeId of the node ProgramTransitionEventType/ToState/Name.
	EnumNumericNodeId_ProgramTransitionEventType_ToState_Name = 3798,
	//! NodeId of the node ProgramTransitionEventType/ToState/Number.
	EnumNumericNodeId_ProgramTransitionEventType_ToState_Number = 3799,
	//! NodeId of the node ProgramTransitionEventType/ToState/EffectiveDisplayName.
	EnumNumericNodeId_ProgramTransitionEventType_ToState_EffectiveDisplayName = 3800,
	//! NodeId of the node ProgramTransitionEventType/Transition.
	EnumNumericNodeId_ProgramTransitionEventType_Transition = 3801,
	//! NodeId of the node ProgramTransitionEventType/Transition/Id.
	EnumNumericNodeId_ProgramTransitionEventType_Transition_Id = 3802,
	//! NodeId of the node ProgramTransitionEventType/Transition/Name.
	EnumNumericNodeId_ProgramTransitionEventType_Transition_Name = 3803,
	//! NodeId of the node ProgramTransitionEventType/Transition/Number.
	EnumNumericNodeId_ProgramTransitionEventType_Transition_Number = 3804,
	//! NodeId of the node ProgramTransitionEventType/Transition/TransitionTime.
	EnumNumericNodeId_ProgramTransitionEventType_Transition_TransitionTime = 3805,
	//! NodeId of the object type ProgramTransitionAuditEventType.
	EnumNumericNodeId_ProgramTransitionAuditEventType = 3806,
	//! NodeId of the node ProgramTransitionAuditEventType/EventId.
	EnumNumericNodeId_ProgramTransitionAuditEventType_EventId = 3807,
	//! NodeId of the node ProgramTransitionAuditEventType/EventType.
	EnumNumericNodeId_ProgramTransitionAuditEventType_EventType = 3808,
	//! NodeId of the node ProgramTransitionAuditEventType/SourceNode.
	EnumNumericNodeId_ProgramTransitionAuditEventType_SourceNode = 3809,
	//! NodeId of the node ProgramTransitionAuditEventType/SourceName.
	EnumNumericNodeId_ProgramTransitionAuditEventType_SourceName = 3810,
	//! NodeId of the node ProgramTransitionAuditEventType/Time.
	EnumNumericNodeId_ProgramTransitionAuditEventType_Time = 3811,
	//! NodeId of the node ProgramTransitionAuditEventType/ReceiveTime.
	EnumNumericNodeId_ProgramTransitionAuditEventType_ReceiveTime = 3812,
	//! NodeId of the node ProgramTransitionAuditEventType/LocalTime.
	EnumNumericNodeId_ProgramTransitionAuditEventType_LocalTime = 3813,
	//! NodeId of the node ProgramTransitionAuditEventType/Message.
	EnumNumericNodeId_ProgramTransitionAuditEventType_Message = 3814,
	//! NodeId of the node ProgramTransitionAuditEventType/Severity.
	EnumNumericNodeId_ProgramTransitionAuditEventType_Severity = 3815,
	//! NodeId of the node ProgramTransitionAuditEventType/ActionTimeStamp.
	EnumNumericNodeId_ProgramTransitionAuditEventType_ActionTimeStamp = 3816,
	//! NodeId of the node ProgramTransitionAuditEventType/Status.
	EnumNumericNodeId_ProgramTransitionAuditEventType_Status = 3817,
	//! NodeId of the node ProgramTransitionAuditEventType/ServerId.
	EnumNumericNodeId_ProgramTransitionAuditEventType_ServerId = 3818,
	//! NodeId of the node ProgramTransitionAuditEventType/ClientAuditEntryId.
	EnumNumericNodeId_ProgramTransitionAuditEventType_ClientAuditEntryId = 3819,
	//! NodeId of the node ProgramTransitionAuditEventType/ClientUserId.
	EnumNumericNodeId_ProgramTransitionAuditEventType_ClientUserId = 3820,
	//! NodeId of the node ProgramTransitionAuditEventType/MethodId.
	EnumNumericNodeId_ProgramTransitionAuditEventType_MethodId = 3821,
	//! NodeId of the node ProgramTransitionAuditEventType/InputArguments.
	EnumNumericNodeId_ProgramTransitionAuditEventType_InputArguments = 3822,
	//! NodeId of the node ProgramTransitionAuditEventType/OldStateId.
	EnumNumericNodeId_ProgramTransitionAuditEventType_OldStateId = 3823,
	//! NodeId of the node ProgramTransitionAuditEventType/NewStateId.
	EnumNumericNodeId_ProgramTransitionAuditEventType_NewStateId = 3824,
	//! NodeId of the node ProgramTransitionAuditEventType/Transition.
	EnumNumericNodeId_ProgramTransitionAuditEventType_Transition = 3825,
	//! NodeId of the node ProgramTransitionAuditEventType/Transition/Id.
	EnumNumericNodeId_ProgramTransitionAuditEventType_Transition_Id = 3826,
	//! NodeId of the node ProgramTransitionAuditEventType/Transition/Name.
	EnumNumericNodeId_ProgramTransitionAuditEventType_Transition_Name = 3827,
	//! NodeId of the node ProgramTransitionAuditEventType/Transition/Number.
	EnumNumericNodeId_ProgramTransitionAuditEventType_Transition_Number = 3828,
	//! NodeId of the node ProgramTransitionAuditEventType/Transition/TransitionTime.
	EnumNumericNodeId_ProgramTransitionAuditEventType_Transition_TransitionTime = 3829,
	//! NodeId of the node ProgramStateMachineType/CurrentState.
	EnumNumericNodeId_ProgramStateMachineType_CurrentState = 3830,
	//! NodeId of the node ProgramStateMachineType/CurrentState/Id.
	EnumNumericNodeId_ProgramStateMachineType_CurrentState_Id = 3831,
	//! NodeId of the node ProgramStateMachineType/CurrentState/Name.
	EnumNumericNodeId_ProgramStateMachineType_CurrentState_Name = 3832,
	//! NodeId of the node ProgramStateMachineType/CurrentState/Number.
	EnumNumericNodeId_ProgramStateMachineType_CurrentState_Number = 3833,
	//! NodeId of the node ProgramStateMachineType/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ProgramStateMachineType_CurrentState_EffectiveDisplayName = 3834,
	//! NodeId of the node ProgramStateMachineType/LastTransition.
	EnumNumericNodeId_ProgramStateMachineType_LastTransition = 3835,
	//! NodeId of the node ProgramStateMachineType/LastTransition/Id.
	EnumNumericNodeId_ProgramStateMachineType_LastTransition_Id = 3836,
	//! NodeId of the node ProgramStateMachineType/LastTransition/Name.
	EnumNumericNodeId_ProgramStateMachineType_LastTransition_Name = 3837,
	//! NodeId of the node ProgramStateMachineType/LastTransition/Number.
	EnumNumericNodeId_ProgramStateMachineType_LastTransition_Number = 3838,
	//! NodeId of the node ProgramStateMachineType/LastTransition/TransitionTime.
	EnumNumericNodeId_ProgramStateMachineType_LastTransition_TransitionTime = 3839,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics/CreateSessionId.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics_CreateSessionId = 3840,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics/CreateClientName.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics_CreateClientName = 3841,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics/InvocationCreationTime.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics_InvocationCreationTime = 3842,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics/LastTransitionTime.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics_LastTransitionTime = 3843,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics/LastMethodCall.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics_LastMethodCall = 3844,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics/LastMethodSessionId.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics_LastMethodSessionId = 3845,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics/LastMethodInputArguments.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics_LastMethodInputArguments = 3846,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics/LastMethodOutputArguments.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics_LastMethodOutputArguments = 3847,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics/LastMethodCallTime.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics_LastMethodCallTime = 3848,
	//! NodeId of the node ProgramStateMachineType/ProgramDiagnostics/LastMethodReturnStatus.
	EnumNumericNodeId_ProgramStateMachineType_ProgramDiagnostics_LastMethodReturnStatus = 3849,
	//! NodeId of the node ProgramStateMachineType/FinalResultData.
	EnumNumericNodeId_ProgramStateMachineType_FinalResultData = 3850,
	//! NodeId of the node ConditionType/EventId.
	EnumNumericNodeId_ConditionType_EventId = 3865,
	//! NodeId of the node ConditionType/EventType.
	EnumNumericNodeId_ConditionType_EventType = 3866,
	//! NodeId of the node ConditionType/SourceNode.
	EnumNumericNodeId_ConditionType_SourceNode = 3867,
	//! NodeId of the node ConditionType/SourceName.
	EnumNumericNodeId_ConditionType_SourceName = 3868,
	//! NodeId of the node ConditionType/Time.
	EnumNumericNodeId_ConditionType_Time = 3869,
	//! NodeId of the node ConditionType/ReceiveTime.
	EnumNumericNodeId_ConditionType_ReceiveTime = 3870,
	//! NodeId of the node ConditionType/LocalTime.
	EnumNumericNodeId_ConditionType_LocalTime = 3871,
	//! NodeId of the node ConditionType/Message.
	EnumNumericNodeId_ConditionType_Message = 3872,
	//! NodeId of the node ConditionType/Severity.
	EnumNumericNodeId_ConditionType_Severity = 3873,
	//! NodeId of the node ConditionType/Retain.
	EnumNumericNodeId_ConditionType_Retain = 3874,
	//! NodeId of the node ConditionType/ConditionRefresh.
	EnumNumericNodeId_ConditionType_ConditionRefresh = 3875,
	//! NodeId of the node ConditionType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_ConditionType_ConditionRefresh_InputArguments = 3876,
	//! NodeId of the node RefreshStartEventType/EventId.
	EnumNumericNodeId_RefreshStartEventType_EventId = 3969,
	//! NodeId of the node RefreshStartEventType/EventType.
	EnumNumericNodeId_RefreshStartEventType_EventType = 3970,
	//! NodeId of the node RefreshStartEventType/SourceNode.
	EnumNumericNodeId_RefreshStartEventType_SourceNode = 3971,
	//! NodeId of the node RefreshStartEventType/SourceName.
	EnumNumericNodeId_RefreshStartEventType_SourceName = 3972,
	//! NodeId of the node RefreshStartEventType/Time.
	EnumNumericNodeId_RefreshStartEventType_Time = 3973,
	//! NodeId of the node RefreshStartEventType/ReceiveTime.
	EnumNumericNodeId_RefreshStartEventType_ReceiveTime = 3974,
	//! NodeId of the node RefreshStartEventType/LocalTime.
	EnumNumericNodeId_RefreshStartEventType_LocalTime = 3975,
	//! NodeId of the node RefreshStartEventType/Message.
	EnumNumericNodeId_RefreshStartEventType_Message = 3976,
	//! NodeId of the node RefreshStartEventType/Severity.
	EnumNumericNodeId_RefreshStartEventType_Severity = 3977,
	//! NodeId of the node RefreshEndEventType/EventId.
	EnumNumericNodeId_RefreshEndEventType_EventId = 3978,
	//! NodeId of the node RefreshEndEventType/EventType.
	EnumNumericNodeId_RefreshEndEventType_EventType = 3979,
	//! NodeId of the node RefreshEndEventType/SourceNode.
	EnumNumericNodeId_RefreshEndEventType_SourceNode = 3980,
	//! NodeId of the node RefreshEndEventType/SourceName.
	EnumNumericNodeId_RefreshEndEventType_SourceName = 3981,
	//! NodeId of the node RefreshEndEventType/Time.
	EnumNumericNodeId_RefreshEndEventType_Time = 3982,
	//! NodeId of the node RefreshEndEventType/ReceiveTime.
	EnumNumericNodeId_RefreshEndEventType_ReceiveTime = 3983,
	//! NodeId of the node RefreshEndEventType/LocalTime.
	EnumNumericNodeId_RefreshEndEventType_LocalTime = 3984,
	//! NodeId of the node RefreshEndEventType/Message.
	EnumNumericNodeId_RefreshEndEventType_Message = 3985,
	//! NodeId of the node RefreshEndEventType/Severity.
	EnumNumericNodeId_RefreshEndEventType_Severity = 3986,
	//! NodeId of the node RefreshRequiredEventType/EventId.
	EnumNumericNodeId_RefreshRequiredEventType_EventId = 3987,
	//! NodeId of the node RefreshRequiredEventType/EventType.
	EnumNumericNodeId_RefreshRequiredEventType_EventType = 3988,
	//! NodeId of the node RefreshRequiredEventType/SourceNode.
	EnumNumericNodeId_RefreshRequiredEventType_SourceNode = 3989,
	//! NodeId of the node RefreshRequiredEventType/SourceName.
	EnumNumericNodeId_RefreshRequiredEventType_SourceName = 3990,
	//! NodeId of the node RefreshRequiredEventType/Time.
	EnumNumericNodeId_RefreshRequiredEventType_Time = 3991,
	//! NodeId of the node RefreshRequiredEventType/ReceiveTime.
	EnumNumericNodeId_RefreshRequiredEventType_ReceiveTime = 3992,
	//! NodeId of the node RefreshRequiredEventType/LocalTime.
	EnumNumericNodeId_RefreshRequiredEventType_LocalTime = 3993,
	//! NodeId of the node RefreshRequiredEventType/Message.
	EnumNumericNodeId_RefreshRequiredEventType_Message = 3994,
	//! NodeId of the node RefreshRequiredEventType/Severity.
	EnumNumericNodeId_RefreshRequiredEventType_Severity = 3995,
	//! NodeId of the node AuditConditionEventType/EventId.
	EnumNumericNodeId_AuditConditionEventType_EventId = 3996,
	//! NodeId of the node AuditConditionEventType/EventType.
	EnumNumericNodeId_AuditConditionEventType_EventType = 3997,
	//! NodeId of the node AuditConditionEventType/SourceNode.
	EnumNumericNodeId_AuditConditionEventType_SourceNode = 3998,
	//! NodeId of the node AuditConditionEventType/SourceName.
	EnumNumericNodeId_AuditConditionEventType_SourceName = 3999,
	//! NodeId of the node AuditConditionEventType/Time.
	EnumNumericNodeId_AuditConditionEventType_Time = 4000,
	//! NodeId of the node AuditConditionEventType/ReceiveTime.
	EnumNumericNodeId_AuditConditionEventType_ReceiveTime = 4001,
	//! NodeId of the node AuditConditionEventType/LocalTime.
	EnumNumericNodeId_AuditConditionEventType_LocalTime = 4002,
	//! NodeId of the node AuditConditionEventType/Message.
	EnumNumericNodeId_AuditConditionEventType_Message = 4003,
	//! NodeId of the node AuditConditionEventType/Severity.
	EnumNumericNodeId_AuditConditionEventType_Severity = 4004,
	//! NodeId of the node AuditConditionEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditConditionEventType_ActionTimeStamp = 4005,
	//! NodeId of the node AuditConditionEventType/Status.
	EnumNumericNodeId_AuditConditionEventType_Status = 4006,
	//! NodeId of the node AuditConditionEventType/ServerId.
	EnumNumericNodeId_AuditConditionEventType_ServerId = 4007,
	//! NodeId of the node AuditConditionEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditConditionEventType_ClientAuditEntryId = 4008,
	//! NodeId of the node AuditConditionEventType/ClientUserId.
	EnumNumericNodeId_AuditConditionEventType_ClientUserId = 4009,
	//! NodeId of the node AuditConditionEventType/MethodId.
	EnumNumericNodeId_AuditConditionEventType_MethodId = 4010,
	//! NodeId of the node AuditConditionEventType/InputArguments.
	EnumNumericNodeId_AuditConditionEventType_InputArguments = 4011,
	//! NodeId of the node AuditConditionEnableEventType/EventId.
	EnumNumericNodeId_AuditConditionEnableEventType_EventId = 4106,
	//! NodeId of the node AuditConditionEnableEventType/EventType.
	EnumNumericNodeId_AuditConditionEnableEventType_EventType = 4107,
	//! NodeId of the node AuditConditionEnableEventType/SourceNode.
	EnumNumericNodeId_AuditConditionEnableEventType_SourceNode = 4108,
	//! NodeId of the node AuditConditionEnableEventType/SourceName.
	EnumNumericNodeId_AuditConditionEnableEventType_SourceName = 4109,
	//! NodeId of the node AuditConditionEnableEventType/Time.
	EnumNumericNodeId_AuditConditionEnableEventType_Time = 4110,
	//! NodeId of the node AuditConditionEnableEventType/ReceiveTime.
	EnumNumericNodeId_AuditConditionEnableEventType_ReceiveTime = 4111,
	//! NodeId of the node AuditConditionEnableEventType/LocalTime.
	EnumNumericNodeId_AuditConditionEnableEventType_LocalTime = 4112,
	//! NodeId of the node AuditConditionEnableEventType/Message.
	EnumNumericNodeId_AuditConditionEnableEventType_Message = 4113,
	//! NodeId of the node AuditConditionEnableEventType/Severity.
	EnumNumericNodeId_AuditConditionEnableEventType_Severity = 4114,
	//! NodeId of the node AuditConditionEnableEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditConditionEnableEventType_ActionTimeStamp = 4115,
	//! NodeId of the node AuditConditionEnableEventType/Status.
	EnumNumericNodeId_AuditConditionEnableEventType_Status = 4116,
	//! NodeId of the node AuditConditionEnableEventType/ServerId.
	EnumNumericNodeId_AuditConditionEnableEventType_ServerId = 4117,
	//! NodeId of the node AuditConditionEnableEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditConditionEnableEventType_ClientAuditEntryId = 4118,
	//! NodeId of the node AuditConditionEnableEventType/ClientUserId.
	EnumNumericNodeId_AuditConditionEnableEventType_ClientUserId = 4119,
	//! NodeId of the node AuditConditionEnableEventType/MethodId.
	EnumNumericNodeId_AuditConditionEnableEventType_MethodId = 4120,
	//! NodeId of the node AuditConditionEnableEventType/InputArguments.
	EnumNumericNodeId_AuditConditionEnableEventType_InputArguments = 4121,
	//! NodeId of the node AuditConditionCommentEventType/EventId.
	EnumNumericNodeId_AuditConditionCommentEventType_EventId = 4170,
	//! NodeId of the node AuditConditionCommentEventType/EventType.
	EnumNumericNodeId_AuditConditionCommentEventType_EventType = 4171,
	//! NodeId of the node AuditConditionCommentEventType/SourceNode.
	EnumNumericNodeId_AuditConditionCommentEventType_SourceNode = 4172,
	//! NodeId of the node AuditConditionCommentEventType/SourceName.
	EnumNumericNodeId_AuditConditionCommentEventType_SourceName = 4173,
	//! NodeId of the node AuditConditionCommentEventType/Time.
	EnumNumericNodeId_AuditConditionCommentEventType_Time = 4174,
	//! NodeId of the node AuditConditionCommentEventType/ReceiveTime.
	EnumNumericNodeId_AuditConditionCommentEventType_ReceiveTime = 4175,
	//! NodeId of the node AuditConditionCommentEventType/LocalTime.
	EnumNumericNodeId_AuditConditionCommentEventType_LocalTime = 4176,
	//! NodeId of the node AuditConditionCommentEventType/Message.
	EnumNumericNodeId_AuditConditionCommentEventType_Message = 4177,
	//! NodeId of the node AuditConditionCommentEventType/Severity.
	EnumNumericNodeId_AuditConditionCommentEventType_Severity = 4178,
	//! NodeId of the node AuditConditionCommentEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditConditionCommentEventType_ActionTimeStamp = 4179,
	//! NodeId of the node AuditConditionCommentEventType/Status.
	EnumNumericNodeId_AuditConditionCommentEventType_Status = 4180,
	//! NodeId of the node AuditConditionCommentEventType/ServerId.
	EnumNumericNodeId_AuditConditionCommentEventType_ServerId = 4181,
	//! NodeId of the node AuditConditionCommentEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditConditionCommentEventType_ClientAuditEntryId = 4182,
	//! NodeId of the node AuditConditionCommentEventType/ClientUserId.
	EnumNumericNodeId_AuditConditionCommentEventType_ClientUserId = 4183,
	//! NodeId of the node AuditConditionCommentEventType/MethodId.
	EnumNumericNodeId_AuditConditionCommentEventType_MethodId = 4184,
	//! NodeId of the node AuditConditionCommentEventType/InputArguments.
	EnumNumericNodeId_AuditConditionCommentEventType_InputArguments = 4185,
	//! NodeId of the node DialogConditionType/EventId.
	EnumNumericNodeId_DialogConditionType_EventId = 4188,
	//! NodeId of the node DialogConditionType/EventType.
	EnumNumericNodeId_DialogConditionType_EventType = 4189,
	//! NodeId of the node DialogConditionType/SourceNode.
	EnumNumericNodeId_DialogConditionType_SourceNode = 4190,
	//! NodeId of the node DialogConditionType/SourceName.
	EnumNumericNodeId_DialogConditionType_SourceName = 4191,
	//! NodeId of the node DialogConditionType/Time.
	EnumNumericNodeId_DialogConditionType_Time = 4192,
	//! NodeId of the node DialogConditionType/ReceiveTime.
	EnumNumericNodeId_DialogConditionType_ReceiveTime = 4193,
	//! NodeId of the node DialogConditionType/LocalTime.
	EnumNumericNodeId_DialogConditionType_LocalTime = 4194,
	//! NodeId of the node DialogConditionType/Message.
	EnumNumericNodeId_DialogConditionType_Message = 4195,
	//! NodeId of the node DialogConditionType/Severity.
	EnumNumericNodeId_DialogConditionType_Severity = 4196,
	//! NodeId of the node DialogConditionType/Retain.
	EnumNumericNodeId_DialogConditionType_Retain = 4197,
	//! NodeId of the node DialogConditionType/ConditionRefresh.
	EnumNumericNodeId_DialogConditionType_ConditionRefresh = 4198,
	//! NodeId of the node DialogConditionType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_DialogConditionType_ConditionRefresh_InputArguments = 4199,
	//! NodeId of the node AcknowledgeableConditionType/EventId.
	EnumNumericNodeId_AcknowledgeableConditionType_EventId = 5113,
	//! NodeId of the node AcknowledgeableConditionType/EventType.
	EnumNumericNodeId_AcknowledgeableConditionType_EventType = 5114,
	//! NodeId of the node AcknowledgeableConditionType/SourceNode.
	EnumNumericNodeId_AcknowledgeableConditionType_SourceNode = 5115,
	//! NodeId of the node AcknowledgeableConditionType/SourceName.
	EnumNumericNodeId_AcknowledgeableConditionType_SourceName = 5116,
	//! NodeId of the node AcknowledgeableConditionType/Time.
	EnumNumericNodeId_AcknowledgeableConditionType_Time = 5117,
	//! NodeId of the node AcknowledgeableConditionType/ReceiveTime.
	EnumNumericNodeId_AcknowledgeableConditionType_ReceiveTime = 5118,
	//! NodeId of the node AcknowledgeableConditionType/LocalTime.
	EnumNumericNodeId_AcknowledgeableConditionType_LocalTime = 5119,
	//! NodeId of the node AcknowledgeableConditionType/Message.
	EnumNumericNodeId_AcknowledgeableConditionType_Message = 5120,
	//! NodeId of the node AcknowledgeableConditionType/Severity.
	EnumNumericNodeId_AcknowledgeableConditionType_Severity = 5121,
	//! NodeId of the node AcknowledgeableConditionType/Retain.
	EnumNumericNodeId_AcknowledgeableConditionType_Retain = 5122,
	//! NodeId of the node AcknowledgeableConditionType/ConditionRefresh.
	EnumNumericNodeId_AcknowledgeableConditionType_ConditionRefresh = 5123,
	//! NodeId of the node AcknowledgeableConditionType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_AcknowledgeableConditionType_ConditionRefresh_InputArguments = 5124,
	//! NodeId of the node AlarmConditionType/EventId.
	EnumNumericNodeId_AlarmConditionType_EventId = 5540,
	//! NodeId of the node AlarmConditionType/EventType.
	EnumNumericNodeId_AlarmConditionType_EventType = 5541,
	//! NodeId of the node AlarmConditionType/SourceNode.
	EnumNumericNodeId_AlarmConditionType_SourceNode = 5542,
	//! NodeId of the node AlarmConditionType/SourceName.
	EnumNumericNodeId_AlarmConditionType_SourceName = 5543,
	//! NodeId of the node AlarmConditionType/Time.
	EnumNumericNodeId_AlarmConditionType_Time = 5544,
	//! NodeId of the node AlarmConditionType/ReceiveTime.
	EnumNumericNodeId_AlarmConditionType_ReceiveTime = 5545,
	//! NodeId of the node AlarmConditionType/LocalTime.
	EnumNumericNodeId_AlarmConditionType_LocalTime = 5546,
	//! NodeId of the node AlarmConditionType/Message.
	EnumNumericNodeId_AlarmConditionType_Message = 5547,
	//! NodeId of the node AlarmConditionType/Severity.
	EnumNumericNodeId_AlarmConditionType_Severity = 5548,
	//! NodeId of the node AlarmConditionType/Retain.
	EnumNumericNodeId_AlarmConditionType_Retain = 5549,
	//! NodeId of the node AlarmConditionType/ConditionRefresh.
	EnumNumericNodeId_AlarmConditionType_ConditionRefresh = 5550,
	//! NodeId of the node AlarmConditionType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_AlarmConditionType_ConditionRefresh_InputArguments = 5551,
	//! NodeId of the node ShelvedStateMachineType/CurrentState.
	EnumNumericNodeId_ShelvedStateMachineType_CurrentState = 6088,
	//! NodeId of the node ShelvedStateMachineType/CurrentState/Id.
	EnumNumericNodeId_ShelvedStateMachineType_CurrentState_Id = 6089,
	//! NodeId of the node ShelvedStateMachineType/CurrentState/Name.
	EnumNumericNodeId_ShelvedStateMachineType_CurrentState_Name = 6090,
	//! NodeId of the node ShelvedStateMachineType/CurrentState/Number.
	EnumNumericNodeId_ShelvedStateMachineType_CurrentState_Number = 6091,
	//! NodeId of the node ShelvedStateMachineType/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ShelvedStateMachineType_CurrentState_EffectiveDisplayName = 6092,
	//! NodeId of the node ShelvedStateMachineType/LastTransition.
	EnumNumericNodeId_ShelvedStateMachineType_LastTransition = 6093,
	//! NodeId of the node ShelvedStateMachineType/LastTransition/Id.
	EnumNumericNodeId_ShelvedStateMachineType_LastTransition_Id = 6094,
	//! NodeId of the node ShelvedStateMachineType/LastTransition/Name.
	EnumNumericNodeId_ShelvedStateMachineType_LastTransition_Name = 6095,
	//! NodeId of the node ShelvedStateMachineType/LastTransition/Number.
	EnumNumericNodeId_ShelvedStateMachineType_LastTransition_Number = 6096,
	//! NodeId of the node ShelvedStateMachineType/LastTransition/TransitionTime.
	EnumNumericNodeId_ShelvedStateMachineType_LastTransition_TransitionTime = 6097,
	//! NodeId of the node ShelvedStateMachineType/Unshelved/StateNumber.
	EnumNumericNodeId_ShelvedStateMachineType_Unshelved_StateNumber = 6098,
	//! NodeId of the node ShelvedStateMachineType/TimedShelved/StateNumber.
	EnumNumericNodeId_ShelvedStateMachineType_TimedShelved_StateNumber = 6100,
	//! NodeId of the node ShelvedStateMachineType/OneShotShelved/StateNumber.
	EnumNumericNodeId_ShelvedStateMachineType_OneShotShelved_StateNumber = 6101,
	//! NodeId of the node LimitAlarmType/EventId.
	EnumNumericNodeId_LimitAlarmType_EventId = 6116,
	//! NodeId of the node LimitAlarmType/EventType.
	EnumNumericNodeId_LimitAlarmType_EventType = 6117,
	//! NodeId of the node LimitAlarmType/SourceNode.
	EnumNumericNodeId_LimitAlarmType_SourceNode = 6118,
	//! NodeId of the node LimitAlarmType/SourceName.
	EnumNumericNodeId_LimitAlarmType_SourceName = 6119,
	//! NodeId of the node LimitAlarmType/Time.
	EnumNumericNodeId_LimitAlarmType_Time = 6120,
	//! NodeId of the node LimitAlarmType/ReceiveTime.
	EnumNumericNodeId_LimitAlarmType_ReceiveTime = 6121,
	//! NodeId of the node LimitAlarmType/LocalTime.
	EnumNumericNodeId_LimitAlarmType_LocalTime = 6122,
	//! NodeId of the node LimitAlarmType/Message.
	EnumNumericNodeId_LimitAlarmType_Message = 6123,
	//! NodeId of the node LimitAlarmType/Severity.
	EnumNumericNodeId_LimitAlarmType_Severity = 6124,
	//! NodeId of the node LimitAlarmType/Retain.
	EnumNumericNodeId_LimitAlarmType_Retain = 6125,
	//! NodeId of the node LimitAlarmType/ConditionRefresh.
	EnumNumericNodeId_LimitAlarmType_ConditionRefresh = 6126,
	//! NodeId of the node LimitAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_LimitAlarmType_ConditionRefresh_InputArguments = 6127,
	//! NodeId of the node IdType/EnumStrings.
	EnumNumericNodeId_IdType_EnumStrings = 7591,
	//! NodeId of the data type EnumValueType.
	EnumNumericNodeId_EnumValueType = 7594,
	//! NodeId of the node MessageSecurityMode/EnumStrings.
	EnumNumericNodeId_MessageSecurityMode_EnumStrings = 7595,
	//! NodeId of the node UserTokenType/EnumStrings.
	EnumNumericNodeId_UserTokenType_EnumStrings = 7596,
	//! NodeId of the node ApplicationType/EnumStrings.
	EnumNumericNodeId_ApplicationType_EnumStrings = 7597,
	//! NodeId of the node SecurityTokenRequestType/EnumStrings.
	EnumNumericNodeId_SecurityTokenRequestType_EnumStrings = 7598,
	//! NodeId of the node ComplianceLevel/EnumStrings.
	EnumNumericNodeId_ComplianceLevel_EnumStrings = 7599,
	//! NodeId of the node BrowseDirection/EnumStrings.
	EnumNumericNodeId_BrowseDirection_EnumStrings = 7603,
	//! NodeId of the node FilterOperator/EnumStrings.
	EnumNumericNodeId_FilterOperator_EnumStrings = 7605,
	//! NodeId of the node TimestampsToReturn/EnumStrings.
	EnumNumericNodeId_TimestampsToReturn_EnumStrings = 7606,
	//! NodeId of the node MonitoringMode/EnumStrings.
	EnumNumericNodeId_MonitoringMode_EnumStrings = 7608,
	//! NodeId of the node DataChangeTrigger/EnumStrings.
	EnumNumericNodeId_DataChangeTrigger_EnumStrings = 7609,
	//! NodeId of the node DeadbandType/EnumStrings.
	EnumNumericNodeId_DeadbandType_EnumStrings = 7610,
	//! NodeId of the node RedundancySupport/EnumStrings.
	EnumNumericNodeId_RedundancySupport_EnumStrings = 7611,
	//! NodeId of the node ServerState/EnumStrings.
	EnumNumericNodeId_ServerState_EnumStrings = 7612,
	//! NodeId of the node ExceptionDeviationFormat/EnumStrings.
	EnumNumericNodeId_ExceptionDeviationFormat_EnumStrings = 7614,
	//! NodeId of the node EnumValueType/Encoding/DefaultXml.
	EnumNumericNodeId_EnumValueType_Encoding_DefaultXml = 7616,
	//! NodeId of the node OpcUa/BinarySchema.
	EnumNumericNodeId_OpcUa_BinarySchema = 7617,
	//! NodeId of the node OpcUa/BinarySchema/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_DataTypeVersion = 7618,
	//! NodeId of the node OpcUa/BinarySchema/NamespaceUri.
	EnumNumericNodeId_OpcUa_BinarySchema_NamespaceUri = 7619,
	//! NodeId of the node OpcUa/BinarySchema/Argument.
	EnumNumericNodeId_OpcUa_BinarySchema_Argument = 7650,
	//! NodeId of the node OpcUa/BinarySchema/Argument/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_Argument_DataTypeVersion = 7651,
	//! NodeId of the node OpcUa/BinarySchema/Argument/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_Argument_DictionaryFragment = 7652,
	//! NodeId of the node OpcUa/BinarySchema/EnumValueType.
	EnumNumericNodeId_OpcUa_BinarySchema_EnumValueType = 7656,
	//! NodeId of the node OpcUa/BinarySchema/EnumValueType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_EnumValueType_DataTypeVersion = 7657,
	//! NodeId of the node OpcUa/BinarySchema/EnumValueType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_EnumValueType_DictionaryFragment = 7658,
	//! NodeId of the node OpcUa/BinarySchema/StatusResult.
	EnumNumericNodeId_OpcUa_BinarySchema_StatusResult = 7659,
	//! NodeId of the node OpcUa/BinarySchema/StatusResult/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_StatusResult_DataTypeVersion = 7660,
	//! NodeId of the node OpcUa/BinarySchema/StatusResult/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_StatusResult_DictionaryFragment = 7661,
	//! NodeId of the node OpcUa/BinarySchema/UserTokenPolicy.
	EnumNumericNodeId_OpcUa_BinarySchema_UserTokenPolicy = 7662,
	//! NodeId of the node OpcUa/BinarySchema/UserTokenPolicy/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_UserTokenPolicy_DataTypeVersion = 7663,
	//! NodeId of the node OpcUa/BinarySchema/UserTokenPolicy/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_UserTokenPolicy_DictionaryFragment = 7664,
	//! NodeId of the node OpcUa/BinarySchema/ApplicationDescription.
	EnumNumericNodeId_OpcUa_BinarySchema_ApplicationDescription = 7665,
	//! NodeId of the node OpcUa/BinarySchema/ApplicationDescription/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ApplicationDescription_DataTypeVersion = 7666,
	//! NodeId of the node OpcUa/BinarySchema/ApplicationDescription/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ApplicationDescription_DictionaryFragment = 7667,
	//! NodeId of the node OpcUa/BinarySchema/EndpointDescription.
	EnumNumericNodeId_OpcUa_BinarySchema_EndpointDescription = 7668,
	//! NodeId of the node OpcUa/BinarySchema/EndpointDescription/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_EndpointDescription_DataTypeVersion = 7669,
	//! NodeId of the node OpcUa/BinarySchema/EndpointDescription/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_EndpointDescription_DictionaryFragment = 7670,
	//! NodeId of the node OpcUa/BinarySchema/UserIdentityToken.
	EnumNumericNodeId_OpcUa_BinarySchema_UserIdentityToken = 7671,
	//! NodeId of the node OpcUa/BinarySchema/UserIdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_UserIdentityToken_DataTypeVersion = 7672,
	//! NodeId of the node OpcUa/BinarySchema/UserIdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_UserIdentityToken_DictionaryFragment = 7673,
	//! NodeId of the node OpcUa/BinarySchema/AnonymousIdentityToken.
	EnumNumericNodeId_OpcUa_BinarySchema_AnonymousIdentityToken = 7674,
	//! NodeId of the node OpcUa/BinarySchema/AnonymousIdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_AnonymousIdentityToken_DataTypeVersion = 7675,
	//! NodeId of the node OpcUa/BinarySchema/AnonymousIdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_AnonymousIdentityToken_DictionaryFragment = 7676,
	//! NodeId of the node OpcUa/BinarySchema/UserNameIdentityToken.
	EnumNumericNodeId_OpcUa_BinarySchema_UserNameIdentityToken = 7677,
	//! NodeId of the node OpcUa/BinarySchema/UserNameIdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_UserNameIdentityToken_DataTypeVersion = 7678,
	//! NodeId of the node OpcUa/BinarySchema/UserNameIdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_UserNameIdentityToken_DictionaryFragment = 7679,
	//! NodeId of the node OpcUa/BinarySchema/X509IdentityToken.
	EnumNumericNodeId_OpcUa_BinarySchema_X509IdentityToken = 7680,
	//! NodeId of the node OpcUa/BinarySchema/X509IdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_X509IdentityToken_DataTypeVersion = 7681,
	//! NodeId of the node OpcUa/BinarySchema/X509IdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_X509IdentityToken_DictionaryFragment = 7682,
	//! NodeId of the node OpcUa/BinarySchema/IssuedIdentityToken.
	EnumNumericNodeId_OpcUa_BinarySchema_IssuedIdentityToken = 7683,
	//! NodeId of the node OpcUa/BinarySchema/IssuedIdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_IssuedIdentityToken_DataTypeVersion = 7684,
	//! NodeId of the node OpcUa/BinarySchema/IssuedIdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_IssuedIdentityToken_DictionaryFragment = 7685,
	//! NodeId of the node OpcUa/BinarySchema/EndpointConfiguration.
	EnumNumericNodeId_OpcUa_BinarySchema_EndpointConfiguration = 7686,
	//! NodeId of the node OpcUa/BinarySchema/EndpointConfiguration/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_EndpointConfiguration_DataTypeVersion = 7687,
	//! NodeId of the node OpcUa/BinarySchema/EndpointConfiguration/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_EndpointConfiguration_DictionaryFragment = 7688,
	//! NodeId of the node OpcUa/BinarySchema/SupportedProfile.
	EnumNumericNodeId_OpcUa_BinarySchema_SupportedProfile = 7689,
	//! NodeId of the node OpcUa/BinarySchema/SupportedProfile/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_SupportedProfile_DataTypeVersion = 7690,
	//! NodeId of the node OpcUa/BinarySchema/SupportedProfile/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_SupportedProfile_DictionaryFragment = 7691,
	//! NodeId of the node OpcUa/BinarySchema/BuildInfo.
	EnumNumericNodeId_OpcUa_BinarySchema_BuildInfo = 7692,
	//! NodeId of the node OpcUa/BinarySchema/BuildInfo/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_BuildInfo_DataTypeVersion = 7693,
	//! NodeId of the node OpcUa/BinarySchema/BuildInfo/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_BuildInfo_DictionaryFragment = 7694,
	//! NodeId of the node OpcUa/BinarySchema/SoftwareCertificate.
	EnumNumericNodeId_OpcUa_BinarySchema_SoftwareCertificate = 7695,
	//! NodeId of the node OpcUa/BinarySchema/SoftwareCertificate/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_SoftwareCertificate_DataTypeVersion = 7696,
	//! NodeId of the node OpcUa/BinarySchema/SoftwareCertificate/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_SoftwareCertificate_DictionaryFragment = 7697,
	//! NodeId of the node OpcUa/BinarySchema/SignedSoftwareCertificate.
	EnumNumericNodeId_OpcUa_BinarySchema_SignedSoftwareCertificate = 7698,
	//! NodeId of the node OpcUa/BinarySchema/SignedSoftwareCertificate/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_SignedSoftwareCertificate_DataTypeVersion = 7699,
	//! NodeId of the node OpcUa/BinarySchema/SignedSoftwareCertificate/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_SignedSoftwareCertificate_DictionaryFragment = 7700,
	//! NodeId of the node OpcUa/BinarySchema/AddNodesItem.
	EnumNumericNodeId_OpcUa_BinarySchema_AddNodesItem = 7728,
	//! NodeId of the node OpcUa/BinarySchema/AddNodesItem/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_AddNodesItem_DataTypeVersion = 7729,
	//! NodeId of the node OpcUa/BinarySchema/AddNodesItem/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_AddNodesItem_DictionaryFragment = 7730,
	//! NodeId of the node OpcUa/BinarySchema/AddReferencesItem.
	EnumNumericNodeId_OpcUa_BinarySchema_AddReferencesItem = 7731,
	//! NodeId of the node OpcUa/BinarySchema/AddReferencesItem/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_AddReferencesItem_DataTypeVersion = 7732,
	//! NodeId of the node OpcUa/BinarySchema/AddReferencesItem/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_AddReferencesItem_DictionaryFragment = 7733,
	//! NodeId of the node OpcUa/BinarySchema/DeleteNodesItem.
	EnumNumericNodeId_OpcUa_BinarySchema_DeleteNodesItem = 7734,
	//! NodeId of the node OpcUa/BinarySchema/DeleteNodesItem/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_DeleteNodesItem_DataTypeVersion = 7735,
	//! NodeId of the node OpcUa/BinarySchema/DeleteNodesItem/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_DeleteNodesItem_DictionaryFragment = 7736,
	//! NodeId of the node OpcUa/BinarySchema/DeleteReferencesItem.
	EnumNumericNodeId_OpcUa_BinarySchema_DeleteReferencesItem = 7737,
	//! NodeId of the node OpcUa/BinarySchema/DeleteReferencesItem/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_DeleteReferencesItem_DataTypeVersion = 7738,
	//! NodeId of the node OpcUa/BinarySchema/DeleteReferencesItem/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_DeleteReferencesItem_DictionaryFragment = 7739,
	//! NodeId of the node OpcUa/BinarySchema/ScalarTestType.
	EnumNumericNodeId_OpcUa_BinarySchema_ScalarTestType = 7749,
	//! NodeId of the node OpcUa/BinarySchema/ScalarTestType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ScalarTestType_DataTypeVersion = 7750,
	//! NodeId of the node OpcUa/BinarySchema/ScalarTestType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ScalarTestType_DictionaryFragment = 7751,
	//! NodeId of the node OpcUa/BinarySchema/ArrayTestType.
	EnumNumericNodeId_OpcUa_BinarySchema_ArrayTestType = 7752,
	//! NodeId of the node OpcUa/BinarySchema/ArrayTestType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ArrayTestType_DataTypeVersion = 7753,
	//! NodeId of the node OpcUa/BinarySchema/ArrayTestType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ArrayTestType_DictionaryFragment = 7754,
	//! NodeId of the node OpcUa/BinarySchema/CompositeTestType.
	EnumNumericNodeId_OpcUa_BinarySchema_CompositeTestType = 7755,
	//! NodeId of the node OpcUa/BinarySchema/CompositeTestType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_CompositeTestType_DataTypeVersion = 7756,
	//! NodeId of the node OpcUa/BinarySchema/CompositeTestType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_CompositeTestType_DictionaryFragment = 7757,
	//! NodeId of the node OpcUa/BinarySchema/RegisteredServer.
	EnumNumericNodeId_OpcUa_BinarySchema_RegisteredServer = 7782,
	//! NodeId of the node OpcUa/BinarySchema/RegisteredServer/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_RegisteredServer_DataTypeVersion = 7783,
	//! NodeId of the node OpcUa/BinarySchema/RegisteredServer/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_RegisteredServer_DictionaryFragment = 7784,
	//! NodeId of the node OpcUa/BinarySchema/ContentFilterElement.
	EnumNumericNodeId_OpcUa_BinarySchema_ContentFilterElement = 7929,
	//! NodeId of the node OpcUa/BinarySchema/ContentFilterElement/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ContentFilterElement_DataTypeVersion = 7930,
	//! NodeId of the node OpcUa/BinarySchema/ContentFilterElement/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ContentFilterElement_DictionaryFragment = 7931,
	//! NodeId of the node OpcUa/BinarySchema/ContentFilter.
	EnumNumericNodeId_OpcUa_BinarySchema_ContentFilter = 7932,
	//! NodeId of the node OpcUa/BinarySchema/ContentFilter/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ContentFilter_DataTypeVersion = 7933,
	//! NodeId of the node OpcUa/BinarySchema/ContentFilter/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ContentFilter_DictionaryFragment = 7934,
	//! NodeId of the node OpcUa/BinarySchema/FilterOperand.
	EnumNumericNodeId_OpcUa_BinarySchema_FilterOperand = 7935,
	//! NodeId of the node OpcUa/BinarySchema/FilterOperand/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_FilterOperand_DataTypeVersion = 7936,
	//! NodeId of the node OpcUa/BinarySchema/FilterOperand/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_FilterOperand_DictionaryFragment = 7937,
	//! NodeId of the node OpcUa/BinarySchema/ElementOperand.
	EnumNumericNodeId_OpcUa_BinarySchema_ElementOperand = 7938,
	//! NodeId of the node OpcUa/BinarySchema/ElementOperand/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ElementOperand_DataTypeVersion = 7939,
	//! NodeId of the node OpcUa/BinarySchema/ElementOperand/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ElementOperand_DictionaryFragment = 7940,
	//! NodeId of the node OpcUa/BinarySchema/LiteralOperand.
	EnumNumericNodeId_OpcUa_BinarySchema_LiteralOperand = 7941,
	//! NodeId of the node OpcUa/BinarySchema/LiteralOperand/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_LiteralOperand_DataTypeVersion = 7942,
	//! NodeId of the node OpcUa/BinarySchema/LiteralOperand/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_LiteralOperand_DictionaryFragment = 7943,
	//! NodeId of the node OpcUa/BinarySchema/AttributeOperand.
	EnumNumericNodeId_OpcUa_BinarySchema_AttributeOperand = 7944,
	//! NodeId of the node OpcUa/BinarySchema/AttributeOperand/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_AttributeOperand_DataTypeVersion = 7945,
	//! NodeId of the node OpcUa/BinarySchema/AttributeOperand/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_AttributeOperand_DictionaryFragment = 7946,
	//! NodeId of the node OpcUa/BinarySchema/SimpleAttributeOperand.
	EnumNumericNodeId_OpcUa_BinarySchema_SimpleAttributeOperand = 7947,
	//! NodeId of the node OpcUa/BinarySchema/SimpleAttributeOperand/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_SimpleAttributeOperand_DataTypeVersion = 7948,
	//! NodeId of the node OpcUa/BinarySchema/SimpleAttributeOperand/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_SimpleAttributeOperand_DictionaryFragment = 7949,
	//! NodeId of the node OpcUa/BinarySchema/HistoryEvent.
	EnumNumericNodeId_OpcUa_BinarySchema_HistoryEvent = 8004,
	//! NodeId of the node OpcUa/BinarySchema/HistoryEvent/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_HistoryEvent_DataTypeVersion = 8005,
	//! NodeId of the node OpcUa/BinarySchema/HistoryEvent/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_HistoryEvent_DictionaryFragment = 8006,
	//! NodeId of the node OpcUa/BinarySchema/MonitoringFilter.
	EnumNumericNodeId_OpcUa_BinarySchema_MonitoringFilter = 8067,
	//! NodeId of the node OpcUa/BinarySchema/MonitoringFilter/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_MonitoringFilter_DataTypeVersion = 8068,
	//! NodeId of the node OpcUa/BinarySchema/MonitoringFilter/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_MonitoringFilter_DictionaryFragment = 8069,
	//! NodeId of the node OpcUa/BinarySchema/EventFilter.
	EnumNumericNodeId_OpcUa_BinarySchema_EventFilter = 8073,
	//! NodeId of the node OpcUa/BinarySchema/EventFilter/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_EventFilter_DataTypeVersion = 8074,
	//! NodeId of the node OpcUa/BinarySchema/EventFilter/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_EventFilter_DictionaryFragment = 8075,
	//! NodeId of the node OpcUa/BinarySchema/AggregateConfiguration.
	EnumNumericNodeId_OpcUa_BinarySchema_AggregateConfiguration = 8076,
	//! NodeId of the node OpcUa/BinarySchema/AggregateConfiguration/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_AggregateConfiguration_DataTypeVersion = 8077,
	//! NodeId of the node OpcUa/BinarySchema/AggregateConfiguration/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_AggregateConfiguration_DictionaryFragment = 8078,
	//! NodeId of the node OpcUa/BinarySchema/HistoryEventFieldList.
	EnumNumericNodeId_OpcUa_BinarySchema_HistoryEventFieldList = 8172,
	//! NodeId of the node OpcUa/BinarySchema/HistoryEventFieldList/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_HistoryEventFieldList_DataTypeVersion = 8173,
	//! NodeId of the node OpcUa/BinarySchema/HistoryEventFieldList/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_HistoryEventFieldList_DictionaryFragment = 8174,
	//! NodeId of the node OpcUa/BinarySchema/RedundantServerDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_RedundantServerDataType = 8208,
	//! NodeId of the node OpcUa/BinarySchema/RedundantServerDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_RedundantServerDataType_DataTypeVersion = 8209,
	//! NodeId of the node OpcUa/BinarySchema/RedundantServerDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_RedundantServerDataType_DictionaryFragment = 8210,
	//! NodeId of the node OpcUa/BinarySchema/SamplingIntervalDiagnosticsDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_SamplingIntervalDiagnosticsDataType = 8211,
	//! NodeId of the node OpcUa/BinarySchema/SamplingIntervalDiagnosticsDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_SamplingIntervalDiagnosticsDataType_DataTypeVersion = 8212,
	//! NodeId of the node OpcUa/BinarySchema/SamplingIntervalDiagnosticsDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_SamplingIntervalDiagnosticsDataType_DictionaryFragment = 8213,
	//! NodeId of the node OpcUa/BinarySchema/ServerDiagnosticsSummaryDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_ServerDiagnosticsSummaryDataType = 8214,
	//! NodeId of the node OpcUa/BinarySchema/ServerDiagnosticsSummaryDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ServerDiagnosticsSummaryDataType_DataTypeVersion = 8215,
	//! NodeId of the node OpcUa/BinarySchema/ServerDiagnosticsSummaryDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ServerDiagnosticsSummaryDataType_DictionaryFragment = 8216,
	//! NodeId of the node OpcUa/BinarySchema/ServerStatusDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_ServerStatusDataType = 8217,
	//! NodeId of the node OpcUa/BinarySchema/ServerStatusDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ServerStatusDataType_DataTypeVersion = 8218,
	//! NodeId of the node OpcUa/BinarySchema/ServerStatusDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ServerStatusDataType_DictionaryFragment = 8219,
	//! NodeId of the node OpcUa/BinarySchema/SessionDiagnosticsDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_SessionDiagnosticsDataType = 8220,
	//! NodeId of the node OpcUa/BinarySchema/SessionDiagnosticsDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_SessionDiagnosticsDataType_DataTypeVersion = 8221,
	//! NodeId of the node OpcUa/BinarySchema/SessionDiagnosticsDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_SessionDiagnosticsDataType_DictionaryFragment = 8222,
	//! NodeId of the node OpcUa/BinarySchema/SessionSecurityDiagnosticsDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_SessionSecurityDiagnosticsDataType = 8223,
	//! NodeId of the node OpcUa/BinarySchema/SessionSecurityDiagnosticsDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_SessionSecurityDiagnosticsDataType_DataTypeVersion = 8224,
	//! NodeId of the node OpcUa/BinarySchema/SessionSecurityDiagnosticsDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_SessionSecurityDiagnosticsDataType_DictionaryFragment = 8225,
	//! NodeId of the node OpcUa/BinarySchema/ServiceCounterDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_ServiceCounterDataType = 8226,
	//! NodeId of the node OpcUa/BinarySchema/ServiceCounterDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ServiceCounterDataType_DataTypeVersion = 8227,
	//! NodeId of the node OpcUa/BinarySchema/ServiceCounterDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ServiceCounterDataType_DictionaryFragment = 8228,
	//! NodeId of the node OpcUa/BinarySchema/SubscriptionDiagnosticsDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_SubscriptionDiagnosticsDataType = 8229,
	//! NodeId of the node OpcUa/BinarySchema/SubscriptionDiagnosticsDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_SubscriptionDiagnosticsDataType_DataTypeVersion = 8230,
	//! NodeId of the node OpcUa/BinarySchema/SubscriptionDiagnosticsDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_SubscriptionDiagnosticsDataType_DictionaryFragment = 8231,
	//! NodeId of the node OpcUa/BinarySchema/ModelChangeStructureDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_ModelChangeStructureDataType = 8232,
	//! NodeId of the node OpcUa/BinarySchema/ModelChangeStructureDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ModelChangeStructureDataType_DataTypeVersion = 8233,
	//! NodeId of the node OpcUa/BinarySchema/ModelChangeStructureDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ModelChangeStructureDataType_DictionaryFragment = 8234,
	//! NodeId of the node OpcUa/BinarySchema/SemanticChangeStructureDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_SemanticChangeStructureDataType = 8235,
	//! NodeId of the node OpcUa/BinarySchema/SemanticChangeStructureDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_SemanticChangeStructureDataType_DataTypeVersion = 8236,
	//! NodeId of the node OpcUa/BinarySchema/SemanticChangeStructureDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_SemanticChangeStructureDataType_DictionaryFragment = 8237,
	//! NodeId of the node OpcUa/BinarySchema/Range.
	EnumNumericNodeId_OpcUa_BinarySchema_Range = 8238,
	//! NodeId of the node OpcUa/BinarySchema/Range/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_Range_DataTypeVersion = 8239,
	//! NodeId of the node OpcUa/BinarySchema/Range/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_Range_DictionaryFragment = 8240,
	//! NodeId of the node OpcUa/BinarySchema/EUInformation.
	EnumNumericNodeId_OpcUa_BinarySchema_EUInformation = 8241,
	//! NodeId of the node OpcUa/BinarySchema/EUInformation/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_EUInformation_DataTypeVersion = 8242,
	//! NodeId of the node OpcUa/BinarySchema/EUInformation/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_EUInformation_DictionaryFragment = 8243,
	//! NodeId of the node OpcUa/BinarySchema/Annotation.
	EnumNumericNodeId_OpcUa_BinarySchema_Annotation = 8244,
	//! NodeId of the node OpcUa/BinarySchema/Annotation/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_Annotation_DataTypeVersion = 8245,
	//! NodeId of the node OpcUa/BinarySchema/Annotation/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_Annotation_DictionaryFragment = 8246,
	//! NodeId of the node OpcUa/BinarySchema/ProgramDiagnosticDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_ProgramDiagnosticDataType = 8247,
	//! NodeId of the node OpcUa/BinarySchema/ProgramDiagnosticDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ProgramDiagnosticDataType_DataTypeVersion = 8248,
	//! NodeId of the node OpcUa/BinarySchema/ProgramDiagnosticDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ProgramDiagnosticDataType_DictionaryFragment = 8249,
	//! NodeId of the node EnumValueType/Encoding/DefaultBinary.
	EnumNumericNodeId_EnumValueType_Encoding_DefaultBinary = 8251,
	//! NodeId of the node OpcUa/XmlSchema.
	EnumNumericNodeId_OpcUa_XmlSchema = 8252,
	//! NodeId of the node OpcUa/XmlSchema/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_DataTypeVersion = 8253,
	//! NodeId of the node OpcUa/XmlSchema/NamespaceUri.
	EnumNumericNodeId_OpcUa_XmlSchema_NamespaceUri = 8254,
	//! NodeId of the node OpcUa/XmlSchema/Argument.
	EnumNumericNodeId_OpcUa_XmlSchema_Argument = 8285,
	//! NodeId of the node OpcUa/XmlSchema/Argument/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_Argument_DataTypeVersion = 8286,
	//! NodeId of the node OpcUa/XmlSchema/Argument/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_Argument_DictionaryFragment = 8287,
	//! NodeId of the node OpcUa/XmlSchema/EnumValueType.
	EnumNumericNodeId_OpcUa_XmlSchema_EnumValueType = 8291,
	//! NodeId of the node OpcUa/XmlSchema/EnumValueType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_EnumValueType_DataTypeVersion = 8292,
	//! NodeId of the node OpcUa/XmlSchema/EnumValueType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_EnumValueType_DictionaryFragment = 8293,
	//! NodeId of the node OpcUa/XmlSchema/StatusResult.
	EnumNumericNodeId_OpcUa_XmlSchema_StatusResult = 8294,
	//! NodeId of the node OpcUa/XmlSchema/StatusResult/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_StatusResult_DataTypeVersion = 8295,
	//! NodeId of the node OpcUa/XmlSchema/StatusResult/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_StatusResult_DictionaryFragment = 8296,
	//! NodeId of the node OpcUa/XmlSchema/UserTokenPolicy.
	EnumNumericNodeId_OpcUa_XmlSchema_UserTokenPolicy = 8297,
	//! NodeId of the node OpcUa/XmlSchema/UserTokenPolicy/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_UserTokenPolicy_DataTypeVersion = 8298,
	//! NodeId of the node OpcUa/XmlSchema/UserTokenPolicy/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_UserTokenPolicy_DictionaryFragment = 8299,
	//! NodeId of the node OpcUa/XmlSchema/ApplicationDescription.
	EnumNumericNodeId_OpcUa_XmlSchema_ApplicationDescription = 8300,
	//! NodeId of the node OpcUa/XmlSchema/ApplicationDescription/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ApplicationDescription_DataTypeVersion = 8301,
	//! NodeId of the node OpcUa/XmlSchema/ApplicationDescription/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ApplicationDescription_DictionaryFragment = 8302,
	//! NodeId of the node OpcUa/XmlSchema/EndpointDescription.
	EnumNumericNodeId_OpcUa_XmlSchema_EndpointDescription = 8303,
	//! NodeId of the node OpcUa/XmlSchema/EndpointDescription/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_EndpointDescription_DataTypeVersion = 8304,
	//! NodeId of the node OpcUa/XmlSchema/EndpointDescription/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_EndpointDescription_DictionaryFragment = 8305,
	//! NodeId of the node OpcUa/XmlSchema/UserIdentityToken.
	EnumNumericNodeId_OpcUa_XmlSchema_UserIdentityToken = 8306,
	//! NodeId of the node OpcUa/XmlSchema/UserIdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_UserIdentityToken_DataTypeVersion = 8307,
	//! NodeId of the node OpcUa/XmlSchema/UserIdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_UserIdentityToken_DictionaryFragment = 8308,
	//! NodeId of the node OpcUa/XmlSchema/AnonymousIdentityToken.
	EnumNumericNodeId_OpcUa_XmlSchema_AnonymousIdentityToken = 8309,
	//! NodeId of the node OpcUa/XmlSchema/AnonymousIdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_AnonymousIdentityToken_DataTypeVersion = 8310,
	//! NodeId of the node OpcUa/XmlSchema/AnonymousIdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_AnonymousIdentityToken_DictionaryFragment = 8311,
	//! NodeId of the node OpcUa/XmlSchema/UserNameIdentityToken.
	EnumNumericNodeId_OpcUa_XmlSchema_UserNameIdentityToken = 8312,
	//! NodeId of the node OpcUa/XmlSchema/UserNameIdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_UserNameIdentityToken_DataTypeVersion = 8313,
	//! NodeId of the node OpcUa/XmlSchema/UserNameIdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_UserNameIdentityToken_DictionaryFragment = 8314,
	//! NodeId of the node OpcUa/XmlSchema/X509IdentityToken.
	EnumNumericNodeId_OpcUa_XmlSchema_X509IdentityToken = 8315,
	//! NodeId of the node OpcUa/XmlSchema/X509IdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_X509IdentityToken_DataTypeVersion = 8316,
	//! NodeId of the node OpcUa/XmlSchema/X509IdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_X509IdentityToken_DictionaryFragment = 8317,
	//! NodeId of the node OpcUa/XmlSchema/IssuedIdentityToken.
	EnumNumericNodeId_OpcUa_XmlSchema_IssuedIdentityToken = 8318,
	//! NodeId of the node OpcUa/XmlSchema/IssuedIdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_IssuedIdentityToken_DataTypeVersion = 8319,
	//! NodeId of the node OpcUa/XmlSchema/IssuedIdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_IssuedIdentityToken_DictionaryFragment = 8320,
	//! NodeId of the node OpcUa/XmlSchema/EndpointConfiguration.
	EnumNumericNodeId_OpcUa_XmlSchema_EndpointConfiguration = 8321,
	//! NodeId of the node OpcUa/XmlSchema/EndpointConfiguration/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_EndpointConfiguration_DataTypeVersion = 8322,
	//! NodeId of the node OpcUa/XmlSchema/EndpointConfiguration/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_EndpointConfiguration_DictionaryFragment = 8323,
	//! NodeId of the node OpcUa/XmlSchema/SupportedProfile.
	EnumNumericNodeId_OpcUa_XmlSchema_SupportedProfile = 8324,
	//! NodeId of the node OpcUa/XmlSchema/SupportedProfile/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_SupportedProfile_DataTypeVersion = 8325,
	//! NodeId of the node OpcUa/XmlSchema/SupportedProfile/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_SupportedProfile_DictionaryFragment = 8326,
	//! NodeId of the node OpcUa/XmlSchema/BuildInfo.
	EnumNumericNodeId_OpcUa_XmlSchema_BuildInfo = 8327,
	//! NodeId of the node OpcUa/XmlSchema/BuildInfo/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_BuildInfo_DataTypeVersion = 8328,
	//! NodeId of the node OpcUa/XmlSchema/BuildInfo/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_BuildInfo_DictionaryFragment = 8329,
	//! NodeId of the node OpcUa/XmlSchema/SoftwareCertificate.
	EnumNumericNodeId_OpcUa_XmlSchema_SoftwareCertificate = 8330,
	//! NodeId of the node OpcUa/XmlSchema/SoftwareCertificate/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_SoftwareCertificate_DataTypeVersion = 8331,
	//! NodeId of the node OpcUa/XmlSchema/SoftwareCertificate/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_SoftwareCertificate_DictionaryFragment = 8332,
	//! NodeId of the node OpcUa/XmlSchema/SignedSoftwareCertificate.
	EnumNumericNodeId_OpcUa_XmlSchema_SignedSoftwareCertificate = 8333,
	//! NodeId of the node OpcUa/XmlSchema/SignedSoftwareCertificate/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_SignedSoftwareCertificate_DataTypeVersion = 8334,
	//! NodeId of the node OpcUa/XmlSchema/SignedSoftwareCertificate/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_SignedSoftwareCertificate_DictionaryFragment = 8335,
	//! NodeId of the node OpcUa/XmlSchema/AddNodesItem.
	EnumNumericNodeId_OpcUa_XmlSchema_AddNodesItem = 8363,
	//! NodeId of the node OpcUa/XmlSchema/AddNodesItem/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_AddNodesItem_DataTypeVersion = 8364,
	//! NodeId of the node OpcUa/XmlSchema/AddNodesItem/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_AddNodesItem_DictionaryFragment = 8365,
	//! NodeId of the node OpcUa/XmlSchema/AddReferencesItem.
	EnumNumericNodeId_OpcUa_XmlSchema_AddReferencesItem = 8366,
	//! NodeId of the node OpcUa/XmlSchema/AddReferencesItem/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_AddReferencesItem_DataTypeVersion = 8367,
	//! NodeId of the node OpcUa/XmlSchema/AddReferencesItem/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_AddReferencesItem_DictionaryFragment = 8368,
	//! NodeId of the node OpcUa/XmlSchema/DeleteNodesItem.
	EnumNumericNodeId_OpcUa_XmlSchema_DeleteNodesItem = 8369,
	//! NodeId of the node OpcUa/XmlSchema/DeleteNodesItem/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_DeleteNodesItem_DataTypeVersion = 8370,
	//! NodeId of the node OpcUa/XmlSchema/DeleteNodesItem/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_DeleteNodesItem_DictionaryFragment = 8371,
	//! NodeId of the node OpcUa/XmlSchema/DeleteReferencesItem.
	EnumNumericNodeId_OpcUa_XmlSchema_DeleteReferencesItem = 8372,
	//! NodeId of the node OpcUa/XmlSchema/DeleteReferencesItem/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_DeleteReferencesItem_DataTypeVersion = 8373,
	//! NodeId of the node OpcUa/XmlSchema/DeleteReferencesItem/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_DeleteReferencesItem_DictionaryFragment = 8374,
	//! NodeId of the node OpcUa/XmlSchema/ScalarTestType.
	EnumNumericNodeId_OpcUa_XmlSchema_ScalarTestType = 8384,
	//! NodeId of the node OpcUa/XmlSchema/ScalarTestType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ScalarTestType_DataTypeVersion = 8385,
	//! NodeId of the node OpcUa/XmlSchema/ScalarTestType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ScalarTestType_DictionaryFragment = 8386,
	//! NodeId of the node OpcUa/XmlSchema/ArrayTestType.
	EnumNumericNodeId_OpcUa_XmlSchema_ArrayTestType = 8387,
	//! NodeId of the node OpcUa/XmlSchema/ArrayTestType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ArrayTestType_DataTypeVersion = 8388,
	//! NodeId of the node OpcUa/XmlSchema/ArrayTestType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ArrayTestType_DictionaryFragment = 8389,
	//! NodeId of the node OpcUa/XmlSchema/CompositeTestType.
	EnumNumericNodeId_OpcUa_XmlSchema_CompositeTestType = 8390,
	//! NodeId of the node OpcUa/XmlSchema/CompositeTestType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_CompositeTestType_DataTypeVersion = 8391,
	//! NodeId of the node OpcUa/XmlSchema/CompositeTestType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_CompositeTestType_DictionaryFragment = 8392,
	//! NodeId of the node OpcUa/XmlSchema/RegisteredServer.
	EnumNumericNodeId_OpcUa_XmlSchema_RegisteredServer = 8417,
	//! NodeId of the node OpcUa/XmlSchema/RegisteredServer/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_RegisteredServer_DataTypeVersion = 8418,
	//! NodeId of the node OpcUa/XmlSchema/RegisteredServer/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_RegisteredServer_DictionaryFragment = 8419,
	//! NodeId of the node OpcUa/XmlSchema/ContentFilterElement.
	EnumNumericNodeId_OpcUa_XmlSchema_ContentFilterElement = 8564,
	//! NodeId of the node OpcUa/XmlSchema/ContentFilterElement/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ContentFilterElement_DataTypeVersion = 8565,
	//! NodeId of the node OpcUa/XmlSchema/ContentFilterElement/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ContentFilterElement_DictionaryFragment = 8566,
	//! NodeId of the node OpcUa/XmlSchema/ContentFilter.
	EnumNumericNodeId_OpcUa_XmlSchema_ContentFilter = 8567,
	//! NodeId of the node OpcUa/XmlSchema/ContentFilter/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ContentFilter_DataTypeVersion = 8568,
	//! NodeId of the node OpcUa/XmlSchema/ContentFilter/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ContentFilter_DictionaryFragment = 8569,
	//! NodeId of the node OpcUa/XmlSchema/FilterOperand.
	EnumNumericNodeId_OpcUa_XmlSchema_FilterOperand = 8570,
	//! NodeId of the node OpcUa/XmlSchema/FilterOperand/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_FilterOperand_DataTypeVersion = 8571,
	//! NodeId of the node OpcUa/XmlSchema/FilterOperand/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_FilterOperand_DictionaryFragment = 8572,
	//! NodeId of the node OpcUa/XmlSchema/ElementOperand.
	EnumNumericNodeId_OpcUa_XmlSchema_ElementOperand = 8573,
	//! NodeId of the node OpcUa/XmlSchema/ElementOperand/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ElementOperand_DataTypeVersion = 8574,
	//! NodeId of the node OpcUa/XmlSchema/ElementOperand/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ElementOperand_DictionaryFragment = 8575,
	//! NodeId of the node OpcUa/XmlSchema/LiteralOperand.
	EnumNumericNodeId_OpcUa_XmlSchema_LiteralOperand = 8576,
	//! NodeId of the node OpcUa/XmlSchema/LiteralOperand/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_LiteralOperand_DataTypeVersion = 8577,
	//! NodeId of the node OpcUa/XmlSchema/LiteralOperand/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_LiteralOperand_DictionaryFragment = 8578,
	//! NodeId of the node OpcUa/XmlSchema/AttributeOperand.
	EnumNumericNodeId_OpcUa_XmlSchema_AttributeOperand = 8579,
	//! NodeId of the node OpcUa/XmlSchema/AttributeOperand/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_AttributeOperand_DataTypeVersion = 8580,
	//! NodeId of the node OpcUa/XmlSchema/AttributeOperand/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_AttributeOperand_DictionaryFragment = 8581,
	//! NodeId of the node OpcUa/XmlSchema/SimpleAttributeOperand.
	EnumNumericNodeId_OpcUa_XmlSchema_SimpleAttributeOperand = 8582,
	//! NodeId of the node OpcUa/XmlSchema/SimpleAttributeOperand/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_SimpleAttributeOperand_DataTypeVersion = 8583,
	//! NodeId of the node OpcUa/XmlSchema/SimpleAttributeOperand/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_SimpleAttributeOperand_DictionaryFragment = 8584,
	//! NodeId of the node OpcUa/XmlSchema/HistoryEvent.
	EnumNumericNodeId_OpcUa_XmlSchema_HistoryEvent = 8639,
	//! NodeId of the node OpcUa/XmlSchema/HistoryEvent/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_HistoryEvent_DataTypeVersion = 8640,
	//! NodeId of the node OpcUa/XmlSchema/HistoryEvent/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_HistoryEvent_DictionaryFragment = 8641,
	//! NodeId of the node OpcUa/XmlSchema/MonitoringFilter.
	EnumNumericNodeId_OpcUa_XmlSchema_MonitoringFilter = 8702,
	//! NodeId of the node OpcUa/XmlSchema/MonitoringFilter/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_MonitoringFilter_DataTypeVersion = 8703,
	//! NodeId of the node OpcUa/XmlSchema/MonitoringFilter/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_MonitoringFilter_DictionaryFragment = 8704,
	//! NodeId of the node OpcUa/XmlSchema/EventFilter.
	EnumNumericNodeId_OpcUa_XmlSchema_EventFilter = 8708,
	//! NodeId of the node OpcUa/XmlSchema/EventFilter/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_EventFilter_DataTypeVersion = 8709,
	//! NodeId of the node OpcUa/XmlSchema/EventFilter/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_EventFilter_DictionaryFragment = 8710,
	//! NodeId of the node OpcUa/XmlSchema/AggregateConfiguration.
	EnumNumericNodeId_OpcUa_XmlSchema_AggregateConfiguration = 8711,
	//! NodeId of the node OpcUa/XmlSchema/AggregateConfiguration/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_AggregateConfiguration_DataTypeVersion = 8712,
	//! NodeId of the node OpcUa/XmlSchema/AggregateConfiguration/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_AggregateConfiguration_DictionaryFragment = 8713,
	//! NodeId of the node OpcUa/XmlSchema/HistoryEventFieldList.
	EnumNumericNodeId_OpcUa_XmlSchema_HistoryEventFieldList = 8807,
	//! NodeId of the node OpcUa/XmlSchema/HistoryEventFieldList/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_HistoryEventFieldList_DataTypeVersion = 8808,
	//! NodeId of the node OpcUa/XmlSchema/HistoryEventFieldList/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_HistoryEventFieldList_DictionaryFragment = 8809,
	//! NodeId of the node OpcUa/XmlSchema/RedundantServerDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_RedundantServerDataType = 8843,
	//! NodeId of the node OpcUa/XmlSchema/RedundantServerDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_RedundantServerDataType_DataTypeVersion = 8844,
	//! NodeId of the node OpcUa/XmlSchema/RedundantServerDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_RedundantServerDataType_DictionaryFragment = 8845,
	//! NodeId of the node OpcUa/XmlSchema/SamplingIntervalDiagnosticsDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_SamplingIntervalDiagnosticsDataType = 8846,
	//! NodeId of the node OpcUa/XmlSchema/SamplingIntervalDiagnosticsDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_SamplingIntervalDiagnosticsDataType_DataTypeVersion = 8847,
	//! NodeId of the node OpcUa/XmlSchema/SamplingIntervalDiagnosticsDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_SamplingIntervalDiagnosticsDataType_DictionaryFragment = 8848,
	//! NodeId of the node OpcUa/XmlSchema/ServerDiagnosticsSummaryDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_ServerDiagnosticsSummaryDataType = 8849,
	//! NodeId of the node OpcUa/XmlSchema/ServerDiagnosticsSummaryDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ServerDiagnosticsSummaryDataType_DataTypeVersion = 8850,
	//! NodeId of the node OpcUa/XmlSchema/ServerDiagnosticsSummaryDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ServerDiagnosticsSummaryDataType_DictionaryFragment = 8851,
	//! NodeId of the node OpcUa/XmlSchema/ServerStatusDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_ServerStatusDataType = 8852,
	//! NodeId of the node OpcUa/XmlSchema/ServerStatusDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ServerStatusDataType_DataTypeVersion = 8853,
	//! NodeId of the node OpcUa/XmlSchema/ServerStatusDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ServerStatusDataType_DictionaryFragment = 8854,
	//! NodeId of the node OpcUa/XmlSchema/SessionDiagnosticsDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_SessionDiagnosticsDataType = 8855,
	//! NodeId of the node OpcUa/XmlSchema/SessionDiagnosticsDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_SessionDiagnosticsDataType_DataTypeVersion = 8856,
	//! NodeId of the node OpcUa/XmlSchema/SessionDiagnosticsDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_SessionDiagnosticsDataType_DictionaryFragment = 8857,
	//! NodeId of the node OpcUa/XmlSchema/SessionSecurityDiagnosticsDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_SessionSecurityDiagnosticsDataType = 8858,
	//! NodeId of the node OpcUa/XmlSchema/SessionSecurityDiagnosticsDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_SessionSecurityDiagnosticsDataType_DataTypeVersion = 8859,
	//! NodeId of the node OpcUa/XmlSchema/SessionSecurityDiagnosticsDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_SessionSecurityDiagnosticsDataType_DictionaryFragment = 8860,
	//! NodeId of the node OpcUa/XmlSchema/ServiceCounterDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_ServiceCounterDataType = 8861,
	//! NodeId of the node OpcUa/XmlSchema/ServiceCounterDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ServiceCounterDataType_DataTypeVersion = 8862,
	//! NodeId of the node OpcUa/XmlSchema/ServiceCounterDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ServiceCounterDataType_DictionaryFragment = 8863,
	//! NodeId of the node OpcUa/XmlSchema/SubscriptionDiagnosticsDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_SubscriptionDiagnosticsDataType = 8864,
	//! NodeId of the node OpcUa/XmlSchema/SubscriptionDiagnosticsDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_SubscriptionDiagnosticsDataType_DataTypeVersion = 8865,
	//! NodeId of the node OpcUa/XmlSchema/SubscriptionDiagnosticsDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_SubscriptionDiagnosticsDataType_DictionaryFragment = 8866,
	//! NodeId of the node OpcUa/XmlSchema/ModelChangeStructureDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_ModelChangeStructureDataType = 8867,
	//! NodeId of the node OpcUa/XmlSchema/ModelChangeStructureDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ModelChangeStructureDataType_DataTypeVersion = 8868,
	//! NodeId of the node OpcUa/XmlSchema/ModelChangeStructureDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ModelChangeStructureDataType_DictionaryFragment = 8869,
	//! NodeId of the node OpcUa/XmlSchema/SemanticChangeStructureDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_SemanticChangeStructureDataType = 8870,
	//! NodeId of the node OpcUa/XmlSchema/SemanticChangeStructureDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_SemanticChangeStructureDataType_DataTypeVersion = 8871,
	//! NodeId of the node OpcUa/XmlSchema/SemanticChangeStructureDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_SemanticChangeStructureDataType_DictionaryFragment = 8872,
	//! NodeId of the node OpcUa/XmlSchema/Range.
	EnumNumericNodeId_OpcUa_XmlSchema_Range = 8873,
	//! NodeId of the node OpcUa/XmlSchema/Range/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_Range_DataTypeVersion = 8874,
	//! NodeId of the node OpcUa/XmlSchema/Range/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_Range_DictionaryFragment = 8875,
	//! NodeId of the node OpcUa/XmlSchema/EUInformation.
	EnumNumericNodeId_OpcUa_XmlSchema_EUInformation = 8876,
	//! NodeId of the node OpcUa/XmlSchema/EUInformation/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_EUInformation_DataTypeVersion = 8877,
	//! NodeId of the node OpcUa/XmlSchema/EUInformation/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_EUInformation_DictionaryFragment = 8878,
	//! NodeId of the node OpcUa/XmlSchema/Annotation.
	EnumNumericNodeId_OpcUa_XmlSchema_Annotation = 8879,
	//! NodeId of the node OpcUa/XmlSchema/Annotation/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_Annotation_DataTypeVersion = 8880,
	//! NodeId of the node OpcUa/XmlSchema/Annotation/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_Annotation_DictionaryFragment = 8881,
	//! NodeId of the node OpcUa/XmlSchema/ProgramDiagnosticDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_ProgramDiagnosticDataType = 8882,
	//! NodeId of the node OpcUa/XmlSchema/ProgramDiagnosticDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ProgramDiagnosticDataType_DataTypeVersion = 8883,
	//! NodeId of the node OpcUa/XmlSchema/ProgramDiagnosticDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ProgramDiagnosticDataType_DictionaryFragment = 8884,
	//! NodeId of the node SubscriptionDiagnosticsType/MaxLifetimeCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_MaxLifetimeCount = 8888,
	//! NodeId of the node SubscriptionDiagnosticsType/LatePublishRequestCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_LatePublishRequestCount = 8889,
	//! NodeId of the node SubscriptionDiagnosticsType/CurrentKeepAliveCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_CurrentKeepAliveCount = 8890,
	//! NodeId of the node SubscriptionDiagnosticsType/CurrentLifetimeCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_CurrentLifetimeCount = 8891,
	//! NodeId of the node SubscriptionDiagnosticsType/UnacknowledgedMessageCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_UnacknowledgedMessageCount = 8892,
	//! NodeId of the node SubscriptionDiagnosticsType/DiscardedMessageCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_DiscardedMessageCount = 8893,
	//! NodeId of the node SubscriptionDiagnosticsType/MonitoredItemCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_MonitoredItemCount = 8894,
	//! NodeId of the node SubscriptionDiagnosticsType/DisabledMonitoredItemCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_DisabledMonitoredItemCount = 8895,
	//! NodeId of the node SubscriptionDiagnosticsType/MonitoringQueueOverflowCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_MonitoringQueueOverflowCount = 8896,
	//! NodeId of the node SubscriptionDiagnosticsType/NextSequenceNumber.
	EnumNumericNodeId_SubscriptionDiagnosticsType_NextSequenceNumber = 8897,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/TotalRequestCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_TotalRequestCount = 8898,
	//! NodeId of the node SessionDiagnosticsVariableType/TotalRequestCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_TotalRequestCount = 8900,
	//! NodeId of the node SubscriptionDiagnosticsType/EventQueueOverFlowCount.
	EnumNumericNodeId_SubscriptionDiagnosticsType_EventQueueOverFlowCount = 8902,
	//! NodeId of the data type TimeZoneDataType.
	EnumNumericNodeId_TimeZoneDataType = 8912,
	//! NodeId of the node TimeZoneDataType/Encoding/DefaultXml.
	EnumNumericNodeId_TimeZoneDataType_Encoding_DefaultXml = 8913,
	//! NodeId of the node OpcUa/BinarySchema/TimeZoneDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_TimeZoneDataType = 8914,
	//! NodeId of the node OpcUa/BinarySchema/TimeZoneDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_TimeZoneDataType_DataTypeVersion = 8915,
	//! NodeId of the node OpcUa/BinarySchema/TimeZoneDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_TimeZoneDataType_DictionaryFragment = 8916,
	//! NodeId of the node TimeZoneDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_TimeZoneDataType_Encoding_DefaultBinary = 8917,
	//! NodeId of the node OpcUa/XmlSchema/TimeZoneDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_TimeZoneDataType = 8918,
	//! NodeId of the node OpcUa/XmlSchema/TimeZoneDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_TimeZoneDataType_DataTypeVersion = 8919,
	//! NodeId of the node OpcUa/XmlSchema/TimeZoneDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_TimeZoneDataType_DictionaryFragment = 8920,
	//! NodeId of the object type LockType.
	EnumNumericNodeId_LockType = 8921,
	//! NodeId of the node LockType/Lock.
	EnumNumericNodeId_LockType_Lock = 8922,
	//! NodeId of the node LockType/Unlock.
	EnumNumericNodeId_LockType_Unlock = 8923,
	//! NodeId of the node ServerLock.
	EnumNumericNodeId_ServerLock = 8924,
	//! NodeId of the node ServerLock/Lock.
	EnumNumericNodeId_ServerLock_Lock = 8925,
	//! NodeId of the node ServerLock/Unlock.
	EnumNumericNodeId_ServerLock_Unlock = 8926,
	//! NodeId of the object type AuditConditionRespondEventType.
	EnumNumericNodeId_AuditConditionRespondEventType = 8927,
	//! NodeId of the node AuditConditionRespondEventType/EventId.
	EnumNumericNodeId_AuditConditionRespondEventType_EventId = 8928,
	//! NodeId of the node AuditConditionRespondEventType/EventType.
	EnumNumericNodeId_AuditConditionRespondEventType_EventType = 8929,
	//! NodeId of the node AuditConditionRespondEventType/SourceNode.
	EnumNumericNodeId_AuditConditionRespondEventType_SourceNode = 8930,
	//! NodeId of the node AuditConditionRespondEventType/SourceName.
	EnumNumericNodeId_AuditConditionRespondEventType_SourceName = 8931,
	//! NodeId of the node AuditConditionRespondEventType/Time.
	EnumNumericNodeId_AuditConditionRespondEventType_Time = 8932,
	//! NodeId of the node AuditConditionRespondEventType/ReceiveTime.
	EnumNumericNodeId_AuditConditionRespondEventType_ReceiveTime = 8933,
	//! NodeId of the node AuditConditionRespondEventType/LocalTime.
	EnumNumericNodeId_AuditConditionRespondEventType_LocalTime = 8934,
	//! NodeId of the node AuditConditionRespondEventType/Message.
	EnumNumericNodeId_AuditConditionRespondEventType_Message = 8935,
	//! NodeId of the node AuditConditionRespondEventType/Severity.
	EnumNumericNodeId_AuditConditionRespondEventType_Severity = 8936,
	//! NodeId of the node AuditConditionRespondEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditConditionRespondEventType_ActionTimeStamp = 8937,
	//! NodeId of the node AuditConditionRespondEventType/Status.
	EnumNumericNodeId_AuditConditionRespondEventType_Status = 8938,
	//! NodeId of the node AuditConditionRespondEventType/ServerId.
	EnumNumericNodeId_AuditConditionRespondEventType_ServerId = 8939,
	//! NodeId of the node AuditConditionRespondEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditConditionRespondEventType_ClientAuditEntryId = 8940,
	//! NodeId of the node AuditConditionRespondEventType/ClientUserId.
	EnumNumericNodeId_AuditConditionRespondEventType_ClientUserId = 8941,
	//! NodeId of the node AuditConditionRespondEventType/MethodId.
	EnumNumericNodeId_AuditConditionRespondEventType_MethodId = 8942,
	//! NodeId of the node AuditConditionRespondEventType/InputArguments.
	EnumNumericNodeId_AuditConditionRespondEventType_InputArguments = 8943,
	//! NodeId of the object type AuditConditionAcknowledgeEventType.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType = 8944,
	//! NodeId of the node AuditConditionAcknowledgeEventType/EventId.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_EventId = 8945,
	//! NodeId of the node AuditConditionAcknowledgeEventType/EventType.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_EventType = 8946,
	//! NodeId of the node AuditConditionAcknowledgeEventType/SourceNode.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_SourceNode = 8947,
	//! NodeId of the node AuditConditionAcknowledgeEventType/SourceName.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_SourceName = 8948,
	//! NodeId of the node AuditConditionAcknowledgeEventType/Time.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_Time = 8949,
	//! NodeId of the node AuditConditionAcknowledgeEventType/ReceiveTime.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_ReceiveTime = 8950,
	//! NodeId of the node AuditConditionAcknowledgeEventType/LocalTime.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_LocalTime = 8951,
	//! NodeId of the node AuditConditionAcknowledgeEventType/Message.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_Message = 8952,
	//! NodeId of the node AuditConditionAcknowledgeEventType/Severity.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_Severity = 8953,
	//! NodeId of the node AuditConditionAcknowledgeEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_ActionTimeStamp = 8954,
	//! NodeId of the node AuditConditionAcknowledgeEventType/Status.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_Status = 8955,
	//! NodeId of the node AuditConditionAcknowledgeEventType/ServerId.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_ServerId = 8956,
	//! NodeId of the node AuditConditionAcknowledgeEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_ClientAuditEntryId = 8957,
	//! NodeId of the node AuditConditionAcknowledgeEventType/ClientUserId.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_ClientUserId = 8958,
	//! NodeId of the node AuditConditionAcknowledgeEventType/MethodId.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_MethodId = 8959,
	//! NodeId of the node AuditConditionAcknowledgeEventType/InputArguments.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_InputArguments = 8960,
	//! NodeId of the object type AuditConditionConfirmEventType.
	EnumNumericNodeId_AuditConditionConfirmEventType = 8961,
	//! NodeId of the node AuditConditionConfirmEventType/EventId.
	EnumNumericNodeId_AuditConditionConfirmEventType_EventId = 8962,
	//! NodeId of the node AuditConditionConfirmEventType/EventType.
	EnumNumericNodeId_AuditConditionConfirmEventType_EventType = 8963,
	//! NodeId of the node AuditConditionConfirmEventType/SourceNode.
	EnumNumericNodeId_AuditConditionConfirmEventType_SourceNode = 8964,
	//! NodeId of the node AuditConditionConfirmEventType/SourceName.
	EnumNumericNodeId_AuditConditionConfirmEventType_SourceName = 8965,
	//! NodeId of the node AuditConditionConfirmEventType/Time.
	EnumNumericNodeId_AuditConditionConfirmEventType_Time = 8966,
	//! NodeId of the node AuditConditionConfirmEventType/ReceiveTime.
	EnumNumericNodeId_AuditConditionConfirmEventType_ReceiveTime = 8967,
	//! NodeId of the node AuditConditionConfirmEventType/LocalTime.
	EnumNumericNodeId_AuditConditionConfirmEventType_LocalTime = 8968,
	//! NodeId of the node AuditConditionConfirmEventType/Message.
	EnumNumericNodeId_AuditConditionConfirmEventType_Message = 8969,
	//! NodeId of the node AuditConditionConfirmEventType/Severity.
	EnumNumericNodeId_AuditConditionConfirmEventType_Severity = 8970,
	//! NodeId of the node AuditConditionConfirmEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditConditionConfirmEventType_ActionTimeStamp = 8971,
	//! NodeId of the node AuditConditionConfirmEventType/Status.
	EnumNumericNodeId_AuditConditionConfirmEventType_Status = 8972,
	//! NodeId of the node AuditConditionConfirmEventType/ServerId.
	EnumNumericNodeId_AuditConditionConfirmEventType_ServerId = 8973,
	//! NodeId of the node AuditConditionConfirmEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditConditionConfirmEventType_ClientAuditEntryId = 8974,
	//! NodeId of the node AuditConditionConfirmEventType/ClientUserId.
	EnumNumericNodeId_AuditConditionConfirmEventType_ClientUserId = 8975,
	//! NodeId of the node AuditConditionConfirmEventType/MethodId.
	EnumNumericNodeId_AuditConditionConfirmEventType_MethodId = 8976,
	//! NodeId of the node AuditConditionConfirmEventType/InputArguments.
	EnumNumericNodeId_AuditConditionConfirmEventType_InputArguments = 8977,
	//! NodeId of the variable type TwoStateVariableType.
	EnumNumericNodeId_TwoStateVariableType = 8995,
	//! NodeId of the node TwoStateVariableType/Id.
	EnumNumericNodeId_TwoStateVariableType_Id = 8996,
	//! NodeId of the node TwoStateVariableType/Name.
	EnumNumericNodeId_TwoStateVariableType_Name = 8997,
	//! NodeId of the node TwoStateVariableType/Number.
	EnumNumericNodeId_TwoStateVariableType_Number = 8998,
	//! NodeId of the node TwoStateVariableType/EffectiveDisplayName.
	EnumNumericNodeId_TwoStateVariableType_EffectiveDisplayName = 8999,
	//! NodeId of the node TwoStateVariableType/TransitionTime.
	EnumNumericNodeId_TwoStateVariableType_TransitionTime = 9000,
	//! NodeId of the node TwoStateVariableType/EffectiveTransitionTime.
	EnumNumericNodeId_TwoStateVariableType_EffectiveTransitionTime = 9001,
	//! NodeId of the variable type ConditionVariableType.
	EnumNumericNodeId_ConditionVariableType = 9002,
	//! NodeId of the node ConditionVariableType/SourceTimestamp.
	EnumNumericNodeId_ConditionVariableType_SourceTimestamp = 9003,
	//! NodeId of the reference type HasTrueSubState.
	EnumNumericNodeId_HasTrueSubState = 9004,
	//! NodeId of the reference type HasFalseSubState.
	EnumNumericNodeId_HasFalseSubState = 9005,
	//! NodeId of the reference type HasCondition.
	EnumNumericNodeId_HasCondition = 9006,
	//! NodeId of the node ConditionType/ConditionName.
	EnumNumericNodeId_ConditionType_ConditionName = 9009,
	//! NodeId of the node ConditionType/BranchId.
	EnumNumericNodeId_ConditionType_BranchId = 9010,
	//! NodeId of the node ConditionType/EnabledState.
	EnumNumericNodeId_ConditionType_EnabledState = 9011,
	//! NodeId of the node ConditionType/EnabledState/Id.
	EnumNumericNodeId_ConditionType_EnabledState_Id = 9012,
	//! NodeId of the node ConditionType/EnabledState/Name.
	EnumNumericNodeId_ConditionType_EnabledState_Name = 9013,
	//! NodeId of the node ConditionType/EnabledState/Number.
	EnumNumericNodeId_ConditionType_EnabledState_Number = 9014,
	//! NodeId of the node ConditionType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_ConditionType_EnabledState_EffectiveDisplayName = 9015,
	//! NodeId of the node ConditionType/EnabledState/TransitionTime.
	EnumNumericNodeId_ConditionType_EnabledState_TransitionTime = 9016,
	//! NodeId of the node ConditionType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_ConditionType_EnabledState_EffectiveTransitionTime = 9017,
	//! NodeId of the node ConditionType/EnabledState/TrueState.
	EnumNumericNodeId_ConditionType_EnabledState_TrueState = 9018,
	//! NodeId of the node ConditionType/EnabledState/FalseState.
	EnumNumericNodeId_ConditionType_EnabledState_FalseState = 9019,
	//! NodeId of the node ConditionType/Quality.
	EnumNumericNodeId_ConditionType_Quality = 9020,
	//! NodeId of the node ConditionType/Quality/SourceTimestamp.
	EnumNumericNodeId_ConditionType_Quality_SourceTimestamp = 9021,
	//! NodeId of the node ConditionType/LastSeverity.
	EnumNumericNodeId_ConditionType_LastSeverity = 9022,
	//! NodeId of the node ConditionType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_ConditionType_LastSeverity_SourceTimestamp = 9023,
	//! NodeId of the node ConditionType/Comment.
	EnumNumericNodeId_ConditionType_Comment = 9024,
	//! NodeId of the node ConditionType/Comment/SourceTimestamp.
	EnumNumericNodeId_ConditionType_Comment_SourceTimestamp = 9025,
	//! NodeId of the node ConditionType/ClientUserId.
	EnumNumericNodeId_ConditionType_ClientUserId = 9026,
	//! NodeId of the node ConditionType/Enable.
	EnumNumericNodeId_ConditionType_Enable = 9027,
	//! NodeId of the node ConditionType/Disable.
	EnumNumericNodeId_ConditionType_Disable = 9028,
	//! NodeId of the node ConditionType/AddComment.
	EnumNumericNodeId_ConditionType_AddComment = 9029,
	//! NodeId of the node ConditionType/AddComment/InputArguments.
	EnumNumericNodeId_ConditionType_AddComment_InputArguments = 9030,
	//! NodeId of the node DialogConditionType/ConditionName.
	EnumNumericNodeId_DialogConditionType_ConditionName = 9033,
	//! NodeId of the node DialogConditionType/BranchId.
	EnumNumericNodeId_DialogConditionType_BranchId = 9034,
	//! NodeId of the node DialogConditionType/EnabledState.
	EnumNumericNodeId_DialogConditionType_EnabledState = 9035,
	//! NodeId of the node DialogConditionType/EnabledState/Id.
	EnumNumericNodeId_DialogConditionType_EnabledState_Id = 9036,
	//! NodeId of the node DialogConditionType/EnabledState/Name.
	EnumNumericNodeId_DialogConditionType_EnabledState_Name = 9037,
	//! NodeId of the node DialogConditionType/EnabledState/Number.
	EnumNumericNodeId_DialogConditionType_EnabledState_Number = 9038,
	//! NodeId of the node DialogConditionType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_DialogConditionType_EnabledState_EffectiveDisplayName = 9039,
	//! NodeId of the node DialogConditionType/EnabledState/TransitionTime.
	EnumNumericNodeId_DialogConditionType_EnabledState_TransitionTime = 9040,
	//! NodeId of the node DialogConditionType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_DialogConditionType_EnabledState_EffectiveTransitionTime = 9041,
	//! NodeId of the node DialogConditionType/EnabledState/TrueState.
	EnumNumericNodeId_DialogConditionType_EnabledState_TrueState = 9042,
	//! NodeId of the node DialogConditionType/EnabledState/FalseState.
	EnumNumericNodeId_DialogConditionType_EnabledState_FalseState = 9043,
	//! NodeId of the node DialogConditionType/Quality.
	EnumNumericNodeId_DialogConditionType_Quality = 9044,
	//! NodeId of the node DialogConditionType/Quality/SourceTimestamp.
	EnumNumericNodeId_DialogConditionType_Quality_SourceTimestamp = 9045,
	//! NodeId of the node DialogConditionType/LastSeverity.
	EnumNumericNodeId_DialogConditionType_LastSeverity = 9046,
	//! NodeId of the node DialogConditionType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_DialogConditionType_LastSeverity_SourceTimestamp = 9047,
	//! NodeId of the node DialogConditionType/Comment.
	EnumNumericNodeId_DialogConditionType_Comment = 9048,
	//! NodeId of the node DialogConditionType/Comment/SourceTimestamp.
	EnumNumericNodeId_DialogConditionType_Comment_SourceTimestamp = 9049,
	//! NodeId of the node DialogConditionType/ClientUserId.
	EnumNumericNodeId_DialogConditionType_ClientUserId = 9050,
	//! NodeId of the node DialogConditionType/Enable.
	EnumNumericNodeId_DialogConditionType_Enable = 9051,
	//! NodeId of the node DialogConditionType/Disable.
	EnumNumericNodeId_DialogConditionType_Disable = 9052,
	//! NodeId of the node DialogConditionType/AddComment.
	EnumNumericNodeId_DialogConditionType_AddComment = 9053,
	//! NodeId of the node DialogConditionType/AddComment/InputArguments.
	EnumNumericNodeId_DialogConditionType_AddComment_InputArguments = 9054,
	//! NodeId of the node DialogConditionType/DialogState.
	EnumNumericNodeId_DialogConditionType_DialogState = 9055,
	//! NodeId of the node DialogConditionType/DialogState/Id.
	EnumNumericNodeId_DialogConditionType_DialogState_Id = 9056,
	//! NodeId of the node DialogConditionType/DialogState/Name.
	EnumNumericNodeId_DialogConditionType_DialogState_Name = 9057,
	//! NodeId of the node DialogConditionType/DialogState/Number.
	EnumNumericNodeId_DialogConditionType_DialogState_Number = 9058,
	//! NodeId of the node DialogConditionType/DialogState/EffectiveDisplayName.
	EnumNumericNodeId_DialogConditionType_DialogState_EffectiveDisplayName = 9059,
	//! NodeId of the node DialogConditionType/DialogState/TransitionTime.
	EnumNumericNodeId_DialogConditionType_DialogState_TransitionTime = 9060,
	//! NodeId of the node DialogConditionType/DialogState/EffectiveTransitionTime.
	EnumNumericNodeId_DialogConditionType_DialogState_EffectiveTransitionTime = 9061,
	//! NodeId of the node DialogConditionType/DialogState/TrueState.
	EnumNumericNodeId_DialogConditionType_DialogState_TrueState = 9062,
	//! NodeId of the node DialogConditionType/DialogState/FalseState.
	EnumNumericNodeId_DialogConditionType_DialogState_FalseState = 9063,
	//! NodeId of the node DialogConditionType/ResponseOptionSet.
	EnumNumericNodeId_DialogConditionType_ResponseOptionSet = 9064,
	//! NodeId of the node DialogConditionType/DefaultResponse.
	EnumNumericNodeId_DialogConditionType_DefaultResponse = 9065,
	//! NodeId of the node DialogConditionType/OkResponse.
	EnumNumericNodeId_DialogConditionType_OkResponse = 9066,
	//! NodeId of the node DialogConditionType/CancelResponse.
	EnumNumericNodeId_DialogConditionType_CancelResponse = 9067,
	//! NodeId of the node DialogConditionType/LastResponse.
	EnumNumericNodeId_DialogConditionType_LastResponse = 9068,
	//! NodeId of the node DialogConditionType/Respond.
	EnumNumericNodeId_DialogConditionType_Respond = 9069,
	//! NodeId of the node DialogConditionType/Respond/InputArguments.
	EnumNumericNodeId_DialogConditionType_Respond_InputArguments = 9070,
	//! NodeId of the node AcknowledgeableConditionType/ConditionName.
	EnumNumericNodeId_AcknowledgeableConditionType_ConditionName = 9071,
	//! NodeId of the node AcknowledgeableConditionType/BranchId.
	EnumNumericNodeId_AcknowledgeableConditionType_BranchId = 9072,
	//! NodeId of the node AcknowledgeableConditionType/EnabledState.
	EnumNumericNodeId_AcknowledgeableConditionType_EnabledState = 9073,
	//! NodeId of the node AcknowledgeableConditionType/EnabledState/Id.
	EnumNumericNodeId_AcknowledgeableConditionType_EnabledState_Id = 9074,
	//! NodeId of the node AcknowledgeableConditionType/EnabledState/Name.
	EnumNumericNodeId_AcknowledgeableConditionType_EnabledState_Name = 9075,
	//! NodeId of the node AcknowledgeableConditionType/EnabledState/Number.
	EnumNumericNodeId_AcknowledgeableConditionType_EnabledState_Number = 9076,
	//! NodeId of the node AcknowledgeableConditionType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_AcknowledgeableConditionType_EnabledState_EffectiveDisplayName = 9077,
	//! NodeId of the node AcknowledgeableConditionType/EnabledState/TransitionTime.
	EnumNumericNodeId_AcknowledgeableConditionType_EnabledState_TransitionTime = 9078,
	//! NodeId of the node AcknowledgeableConditionType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_AcknowledgeableConditionType_EnabledState_EffectiveTransitionTime = 9079,
	//! NodeId of the node AcknowledgeableConditionType/EnabledState/TrueState.
	EnumNumericNodeId_AcknowledgeableConditionType_EnabledState_TrueState = 9080,
	//! NodeId of the node AcknowledgeableConditionType/EnabledState/FalseState.
	EnumNumericNodeId_AcknowledgeableConditionType_EnabledState_FalseState = 9081,
	//! NodeId of the node AcknowledgeableConditionType/Quality.
	EnumNumericNodeId_AcknowledgeableConditionType_Quality = 9082,
	//! NodeId of the node AcknowledgeableConditionType/Quality/SourceTimestamp.
	EnumNumericNodeId_AcknowledgeableConditionType_Quality_SourceTimestamp = 9083,
	//! NodeId of the node AcknowledgeableConditionType/LastSeverity.
	EnumNumericNodeId_AcknowledgeableConditionType_LastSeverity = 9084,
	//! NodeId of the node AcknowledgeableConditionType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_AcknowledgeableConditionType_LastSeverity_SourceTimestamp = 9085,
	//! NodeId of the node AcknowledgeableConditionType/Comment.
	EnumNumericNodeId_AcknowledgeableConditionType_Comment = 9086,
	//! NodeId of the node AcknowledgeableConditionType/Comment/SourceTimestamp.
	EnumNumericNodeId_AcknowledgeableConditionType_Comment_SourceTimestamp = 9087,
	//! NodeId of the node AcknowledgeableConditionType/ClientUserId.
	EnumNumericNodeId_AcknowledgeableConditionType_ClientUserId = 9088,
	//! NodeId of the node AcknowledgeableConditionType/Enable.
	EnumNumericNodeId_AcknowledgeableConditionType_Enable = 9089,
	//! NodeId of the node AcknowledgeableConditionType/Disable.
	EnumNumericNodeId_AcknowledgeableConditionType_Disable = 9090,
	//! NodeId of the node AcknowledgeableConditionType/AddComment.
	EnumNumericNodeId_AcknowledgeableConditionType_AddComment = 9091,
	//! NodeId of the node AcknowledgeableConditionType/AddComment/InputArguments.
	EnumNumericNodeId_AcknowledgeableConditionType_AddComment_InputArguments = 9092,
	//! NodeId of the node AcknowledgeableConditionType/AckedState.
	EnumNumericNodeId_AcknowledgeableConditionType_AckedState = 9093,
	//! NodeId of the node AcknowledgeableConditionType/AckedState/Id.
	EnumNumericNodeId_AcknowledgeableConditionType_AckedState_Id = 9094,
	//! NodeId of the node AcknowledgeableConditionType/AckedState/Name.
	EnumNumericNodeId_AcknowledgeableConditionType_AckedState_Name = 9095,
	//! NodeId of the node AcknowledgeableConditionType/AckedState/Number.
	EnumNumericNodeId_AcknowledgeableConditionType_AckedState_Number = 9096,
	//! NodeId of the node AcknowledgeableConditionType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_AcknowledgeableConditionType_AckedState_EffectiveDisplayName = 9097,
	//! NodeId of the node AcknowledgeableConditionType/AckedState/TransitionTime.
	EnumNumericNodeId_AcknowledgeableConditionType_AckedState_TransitionTime = 9098,
	//! NodeId of the node AcknowledgeableConditionType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_AcknowledgeableConditionType_AckedState_EffectiveTransitionTime = 9099,
	//! NodeId of the node AcknowledgeableConditionType/AckedState/TrueState.
	EnumNumericNodeId_AcknowledgeableConditionType_AckedState_TrueState = 9100,
	//! NodeId of the node AcknowledgeableConditionType/AckedState/FalseState.
	EnumNumericNodeId_AcknowledgeableConditionType_AckedState_FalseState = 9101,
	//! NodeId of the node AcknowledgeableConditionType/ConfirmedState.
	EnumNumericNodeId_AcknowledgeableConditionType_ConfirmedState = 9102,
	//! NodeId of the node AcknowledgeableConditionType/ConfirmedState/Id.
	EnumNumericNodeId_AcknowledgeableConditionType_ConfirmedState_Id = 9103,
	//! NodeId of the node AcknowledgeableConditionType/ConfirmedState/Name.
	EnumNumericNodeId_AcknowledgeableConditionType_ConfirmedState_Name = 9104,
	//! NodeId of the node AcknowledgeableConditionType/ConfirmedState/Number.
	EnumNumericNodeId_AcknowledgeableConditionType_ConfirmedState_Number = 9105,
	//! NodeId of the node AcknowledgeableConditionType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_AcknowledgeableConditionType_ConfirmedState_EffectiveDisplayName = 9106,
	//! NodeId of the node AcknowledgeableConditionType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_AcknowledgeableConditionType_ConfirmedState_TransitionTime = 9107,
	//! NodeId of the node AcknowledgeableConditionType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_AcknowledgeableConditionType_ConfirmedState_EffectiveTransitionTime = 9108,
	//! NodeId of the node AcknowledgeableConditionType/ConfirmedState/TrueState.
	EnumNumericNodeId_AcknowledgeableConditionType_ConfirmedState_TrueState = 9109,
	//! NodeId of the node AcknowledgeableConditionType/ConfirmedState/FalseState.
	EnumNumericNodeId_AcknowledgeableConditionType_ConfirmedState_FalseState = 9110,
	//! NodeId of the node AcknowledgeableConditionType/Acknowledge.
	EnumNumericNodeId_AcknowledgeableConditionType_Acknowledge = 9111,
	//! NodeId of the node AcknowledgeableConditionType/Acknowledge/InputArguments.
	EnumNumericNodeId_AcknowledgeableConditionType_Acknowledge_InputArguments = 9112,
	//! NodeId of the node AcknowledgeableConditionType/Confirm.
	EnumNumericNodeId_AcknowledgeableConditionType_Confirm = 9113,
	//! NodeId of the node AcknowledgeableConditionType/Confirm/InputArguments.
	EnumNumericNodeId_AcknowledgeableConditionType_Confirm_InputArguments = 9114,
	//! NodeId of the node ShelvedStateMachineType/UnshelveTime.
	EnumNumericNodeId_ShelvedStateMachineType_UnshelveTime = 9115,
	//! NodeId of the node AlarmConditionType/ConditionName.
	EnumNumericNodeId_AlarmConditionType_ConditionName = 9116,
	//! NodeId of the node AlarmConditionType/BranchId.
	EnumNumericNodeId_AlarmConditionType_BranchId = 9117,
	//! NodeId of the node AlarmConditionType/EnabledState.
	EnumNumericNodeId_AlarmConditionType_EnabledState = 9118,
	//! NodeId of the node AlarmConditionType/EnabledState/Id.
	EnumNumericNodeId_AlarmConditionType_EnabledState_Id = 9119,
	//! NodeId of the node AlarmConditionType/EnabledState/Name.
	EnumNumericNodeId_AlarmConditionType_EnabledState_Name = 9120,
	//! NodeId of the node AlarmConditionType/EnabledState/Number.
	EnumNumericNodeId_AlarmConditionType_EnabledState_Number = 9121,
	//! NodeId of the node AlarmConditionType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_AlarmConditionType_EnabledState_EffectiveDisplayName = 9122,
	//! NodeId of the node AlarmConditionType/EnabledState/TransitionTime.
	EnumNumericNodeId_AlarmConditionType_EnabledState_TransitionTime = 9123,
	//! NodeId of the node AlarmConditionType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_AlarmConditionType_EnabledState_EffectiveTransitionTime = 9124,
	//! NodeId of the node AlarmConditionType/EnabledState/TrueState.
	EnumNumericNodeId_AlarmConditionType_EnabledState_TrueState = 9125,
	//! NodeId of the node AlarmConditionType/EnabledState/FalseState.
	EnumNumericNodeId_AlarmConditionType_EnabledState_FalseState = 9126,
	//! NodeId of the node AlarmConditionType/Quality.
	EnumNumericNodeId_AlarmConditionType_Quality = 9127,
	//! NodeId of the node AlarmConditionType/Quality/SourceTimestamp.
	EnumNumericNodeId_AlarmConditionType_Quality_SourceTimestamp = 9128,
	//! NodeId of the node AlarmConditionType/LastSeverity.
	EnumNumericNodeId_AlarmConditionType_LastSeverity = 9129,
	//! NodeId of the node AlarmConditionType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_AlarmConditionType_LastSeverity_SourceTimestamp = 9130,
	//! NodeId of the node AlarmConditionType/Comment.
	EnumNumericNodeId_AlarmConditionType_Comment = 9131,
	//! NodeId of the node AlarmConditionType/Comment/SourceTimestamp.
	EnumNumericNodeId_AlarmConditionType_Comment_SourceTimestamp = 9132,
	//! NodeId of the node AlarmConditionType/ClientUserId.
	EnumNumericNodeId_AlarmConditionType_ClientUserId = 9133,
	//! NodeId of the node AlarmConditionType/Enable.
	EnumNumericNodeId_AlarmConditionType_Enable = 9134,
	//! NodeId of the node AlarmConditionType/Disable.
	EnumNumericNodeId_AlarmConditionType_Disable = 9135,
	//! NodeId of the node AlarmConditionType/AddComment.
	EnumNumericNodeId_AlarmConditionType_AddComment = 9136,
	//! NodeId of the node AlarmConditionType/AddComment/InputArguments.
	EnumNumericNodeId_AlarmConditionType_AddComment_InputArguments = 9137,
	//! NodeId of the node AlarmConditionType/AckedState.
	EnumNumericNodeId_AlarmConditionType_AckedState = 9138,
	//! NodeId of the node AlarmConditionType/AckedState/Id.
	EnumNumericNodeId_AlarmConditionType_AckedState_Id = 9139,
	//! NodeId of the node AlarmConditionType/AckedState/Name.
	EnumNumericNodeId_AlarmConditionType_AckedState_Name = 9140,
	//! NodeId of the node AlarmConditionType/AckedState/Number.
	EnumNumericNodeId_AlarmConditionType_AckedState_Number = 9141,
	//! NodeId of the node AlarmConditionType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_AlarmConditionType_AckedState_EffectiveDisplayName = 9142,
	//! NodeId of the node AlarmConditionType/AckedState/TransitionTime.
	EnumNumericNodeId_AlarmConditionType_AckedState_TransitionTime = 9143,
	//! NodeId of the node AlarmConditionType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_AlarmConditionType_AckedState_EffectiveTransitionTime = 9144,
	//! NodeId of the node AlarmConditionType/AckedState/TrueState.
	EnumNumericNodeId_AlarmConditionType_AckedState_TrueState = 9145,
	//! NodeId of the node AlarmConditionType/AckedState/FalseState.
	EnumNumericNodeId_AlarmConditionType_AckedState_FalseState = 9146,
	//! NodeId of the node AlarmConditionType/ConfirmedState.
	EnumNumericNodeId_AlarmConditionType_ConfirmedState = 9147,
	//! NodeId of the node AlarmConditionType/ConfirmedState/Id.
	EnumNumericNodeId_AlarmConditionType_ConfirmedState_Id = 9148,
	//! NodeId of the node AlarmConditionType/ConfirmedState/Name.
	EnumNumericNodeId_AlarmConditionType_ConfirmedState_Name = 9149,
	//! NodeId of the node AlarmConditionType/ConfirmedState/Number.
	EnumNumericNodeId_AlarmConditionType_ConfirmedState_Number = 9150,
	//! NodeId of the node AlarmConditionType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_AlarmConditionType_ConfirmedState_EffectiveDisplayName = 9151,
	//! NodeId of the node AlarmConditionType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_AlarmConditionType_ConfirmedState_TransitionTime = 9152,
	//! NodeId of the node AlarmConditionType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_AlarmConditionType_ConfirmedState_EffectiveTransitionTime = 9153,
	//! NodeId of the node AlarmConditionType/ConfirmedState/TrueState.
	EnumNumericNodeId_AlarmConditionType_ConfirmedState_TrueState = 9154,
	//! NodeId of the node AlarmConditionType/ConfirmedState/FalseState.
	EnumNumericNodeId_AlarmConditionType_ConfirmedState_FalseState = 9155,
	//! NodeId of the node AlarmConditionType/Acknowledge.
	EnumNumericNodeId_AlarmConditionType_Acknowledge = 9156,
	//! NodeId of the node AlarmConditionType/Acknowledge/InputArguments.
	EnumNumericNodeId_AlarmConditionType_Acknowledge_InputArguments = 9157,
	//! NodeId of the node AlarmConditionType/Confirm.
	EnumNumericNodeId_AlarmConditionType_Confirm = 9158,
	//! NodeId of the node AlarmConditionType/Confirm/InputArguments.
	EnumNumericNodeId_AlarmConditionType_Confirm_InputArguments = 9159,
	//! NodeId of the node AlarmConditionType/ActiveState.
	EnumNumericNodeId_AlarmConditionType_ActiveState = 9160,
	//! NodeId of the node AlarmConditionType/ActiveState/Id.
	EnumNumericNodeId_AlarmConditionType_ActiveState_Id = 9161,
	//! NodeId of the node AlarmConditionType/ActiveState/Name.
	EnumNumericNodeId_AlarmConditionType_ActiveState_Name = 9162,
	//! NodeId of the node AlarmConditionType/ActiveState/Number.
	EnumNumericNodeId_AlarmConditionType_ActiveState_Number = 9163,
	//! NodeId of the node AlarmConditionType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_AlarmConditionType_ActiveState_EffectiveDisplayName = 9164,
	//! NodeId of the node AlarmConditionType/ActiveState/TransitionTime.
	EnumNumericNodeId_AlarmConditionType_ActiveState_TransitionTime = 9165,
	//! NodeId of the node AlarmConditionType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_AlarmConditionType_ActiveState_EffectiveTransitionTime = 9166,
	//! NodeId of the node AlarmConditionType/ActiveState/TrueState.
	EnumNumericNodeId_AlarmConditionType_ActiveState_TrueState = 9167,
	//! NodeId of the node AlarmConditionType/ActiveState/FalseState.
	EnumNumericNodeId_AlarmConditionType_ActiveState_FalseState = 9168,
	//! NodeId of the node AlarmConditionType/SuppressedState.
	EnumNumericNodeId_AlarmConditionType_SuppressedState = 9169,
	//! NodeId of the node AlarmConditionType/SuppressedState/Id.
	EnumNumericNodeId_AlarmConditionType_SuppressedState_Id = 9170,
	//! NodeId of the node AlarmConditionType/SuppressedState/Name.
	EnumNumericNodeId_AlarmConditionType_SuppressedState_Name = 9171,
	//! NodeId of the node AlarmConditionType/SuppressedState/Number.
	EnumNumericNodeId_AlarmConditionType_SuppressedState_Number = 9172,
	//! NodeId of the node AlarmConditionType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_AlarmConditionType_SuppressedState_EffectiveDisplayName = 9173,
	//! NodeId of the node AlarmConditionType/SuppressedState/TransitionTime.
	EnumNumericNodeId_AlarmConditionType_SuppressedState_TransitionTime = 9174,
	//! NodeId of the node AlarmConditionType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_AlarmConditionType_SuppressedState_EffectiveTransitionTime = 9175,
	//! NodeId of the node AlarmConditionType/SuppressedState/TrueState.
	EnumNumericNodeId_AlarmConditionType_SuppressedState_TrueState = 9176,
	//! NodeId of the node AlarmConditionType/SuppressedState/FalseState.
	EnumNumericNodeId_AlarmConditionType_SuppressedState_FalseState = 9177,
	//! NodeId of the node AlarmConditionType/ShelvingState.
	EnumNumericNodeId_AlarmConditionType_ShelvingState = 9178,
	//! NodeId of the node AlarmConditionType/ShelvingState/CurrentState.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_CurrentState = 9179,
	//! NodeId of the node AlarmConditionType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_CurrentState_Id = 9180,
	//! NodeId of the node AlarmConditionType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_CurrentState_Name = 9181,
	//! NodeId of the node AlarmConditionType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_CurrentState_Number = 9182,
	//! NodeId of the node AlarmConditionType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_CurrentState_EffectiveDisplayName = 9183,
	//! NodeId of the node AlarmConditionType/ShelvingState/LastTransition.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_LastTransition = 9184,
	//! NodeId of the node AlarmConditionType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_LastTransition_Id = 9185,
	//! NodeId of the node AlarmConditionType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_LastTransition_Name = 9186,
	//! NodeId of the node AlarmConditionType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_LastTransition_Number = 9187,
	//! NodeId of the node AlarmConditionType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_LastTransition_TransitionTime = 9188,
	//! NodeId of the node AlarmConditionType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_UnshelveTime = 9189,
	//! NodeId of the node AlarmConditionType/ShelvingState/Unshelve.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_Unshelve = 9211,
	//! NodeId of the node AlarmConditionType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_OneShotShelve = 9212,
	//! NodeId of the node AlarmConditionType/ShelvingState/TimedShelve.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_TimedShelve = 9213,
	//! NodeId of the node AlarmConditionType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_TimedShelve_InputArguments = 9214,
	//! NodeId of the node AlarmConditionType/SuppressedOrShelved.
	EnumNumericNodeId_AlarmConditionType_SuppressedOrShelved = 9215,
	//! NodeId of the node AlarmConditionType/MaxTimeShelved.
	EnumNumericNodeId_AlarmConditionType_MaxTimeShelved = 9216,
	//! NodeId of the node LimitAlarmType/ConditionName.
	EnumNumericNodeId_LimitAlarmType_ConditionName = 9217,
	//! NodeId of the node LimitAlarmType/BranchId.
	EnumNumericNodeId_LimitAlarmType_BranchId = 9218,
	//! NodeId of the node LimitAlarmType/EnabledState.
	EnumNumericNodeId_LimitAlarmType_EnabledState = 9219,
	//! NodeId of the node LimitAlarmType/EnabledState/Id.
	EnumNumericNodeId_LimitAlarmType_EnabledState_Id = 9220,
	//! NodeId of the node LimitAlarmType/EnabledState/Name.
	EnumNumericNodeId_LimitAlarmType_EnabledState_Name = 9221,
	//! NodeId of the node LimitAlarmType/EnabledState/Number.
	EnumNumericNodeId_LimitAlarmType_EnabledState_Number = 9222,
	//! NodeId of the node LimitAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_LimitAlarmType_EnabledState_EffectiveDisplayName = 9223,
	//! NodeId of the node LimitAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_LimitAlarmType_EnabledState_TransitionTime = 9224,
	//! NodeId of the node LimitAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_LimitAlarmType_EnabledState_EffectiveTransitionTime = 9225,
	//! NodeId of the node LimitAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_LimitAlarmType_EnabledState_TrueState = 9226,
	//! NodeId of the node LimitAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_LimitAlarmType_EnabledState_FalseState = 9227,
	//! NodeId of the node LimitAlarmType/Quality.
	EnumNumericNodeId_LimitAlarmType_Quality = 9228,
	//! NodeId of the node LimitAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_LimitAlarmType_Quality_SourceTimestamp = 9229,
	//! NodeId of the node LimitAlarmType/LastSeverity.
	EnumNumericNodeId_LimitAlarmType_LastSeverity = 9230,
	//! NodeId of the node LimitAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_LimitAlarmType_LastSeverity_SourceTimestamp = 9231,
	//! NodeId of the node LimitAlarmType/Comment.
	EnumNumericNodeId_LimitAlarmType_Comment = 9232,
	//! NodeId of the node LimitAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_LimitAlarmType_Comment_SourceTimestamp = 9233,
	//! NodeId of the node LimitAlarmType/ClientUserId.
	EnumNumericNodeId_LimitAlarmType_ClientUserId = 9234,
	//! NodeId of the node LimitAlarmType/Enable.
	EnumNumericNodeId_LimitAlarmType_Enable = 9235,
	//! NodeId of the node LimitAlarmType/Disable.
	EnumNumericNodeId_LimitAlarmType_Disable = 9236,
	//! NodeId of the node LimitAlarmType/AddComment.
	EnumNumericNodeId_LimitAlarmType_AddComment = 9237,
	//! NodeId of the node LimitAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_LimitAlarmType_AddComment_InputArguments = 9238,
	//! NodeId of the node LimitAlarmType/AckedState.
	EnumNumericNodeId_LimitAlarmType_AckedState = 9239,
	//! NodeId of the node LimitAlarmType/AckedState/Id.
	EnumNumericNodeId_LimitAlarmType_AckedState_Id = 9240,
	//! NodeId of the node LimitAlarmType/AckedState/Name.
	EnumNumericNodeId_LimitAlarmType_AckedState_Name = 9241,
	//! NodeId of the node LimitAlarmType/AckedState/Number.
	EnumNumericNodeId_LimitAlarmType_AckedState_Number = 9242,
	//! NodeId of the node LimitAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_LimitAlarmType_AckedState_EffectiveDisplayName = 9243,
	//! NodeId of the node LimitAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_LimitAlarmType_AckedState_TransitionTime = 9244,
	//! NodeId of the node LimitAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_LimitAlarmType_AckedState_EffectiveTransitionTime = 9245,
	//! NodeId of the node LimitAlarmType/AckedState/TrueState.
	EnumNumericNodeId_LimitAlarmType_AckedState_TrueState = 9246,
	//! NodeId of the node LimitAlarmType/AckedState/FalseState.
	EnumNumericNodeId_LimitAlarmType_AckedState_FalseState = 9247,
	//! NodeId of the node LimitAlarmType/ConfirmedState.
	EnumNumericNodeId_LimitAlarmType_ConfirmedState = 9248,
	//! NodeId of the node LimitAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_LimitAlarmType_ConfirmedState_Id = 9249,
	//! NodeId of the node LimitAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_LimitAlarmType_ConfirmedState_Name = 9250,
	//! NodeId of the node LimitAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_LimitAlarmType_ConfirmedState_Number = 9251,
	//! NodeId of the node LimitAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_LimitAlarmType_ConfirmedState_EffectiveDisplayName = 9252,
	//! NodeId of the node LimitAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_LimitAlarmType_ConfirmedState_TransitionTime = 9253,
	//! NodeId of the node LimitAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_LimitAlarmType_ConfirmedState_EffectiveTransitionTime = 9254,
	//! NodeId of the node LimitAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_LimitAlarmType_ConfirmedState_TrueState = 9255,
	//! NodeId of the node LimitAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_LimitAlarmType_ConfirmedState_FalseState = 9256,
	//! NodeId of the node LimitAlarmType/Acknowledge.
	EnumNumericNodeId_LimitAlarmType_Acknowledge = 9257,
	//! NodeId of the node LimitAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_LimitAlarmType_Acknowledge_InputArguments = 9258,
	//! NodeId of the node LimitAlarmType/Confirm.
	EnumNumericNodeId_LimitAlarmType_Confirm = 9259,
	//! NodeId of the node LimitAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_LimitAlarmType_Confirm_InputArguments = 9260,
	//! NodeId of the node LimitAlarmType/ActiveState.
	EnumNumericNodeId_LimitAlarmType_ActiveState = 9261,
	//! NodeId of the node LimitAlarmType/ActiveState/Id.
	EnumNumericNodeId_LimitAlarmType_ActiveState_Id = 9262,
	//! NodeId of the node LimitAlarmType/ActiveState/Name.
	EnumNumericNodeId_LimitAlarmType_ActiveState_Name = 9263,
	//! NodeId of the node LimitAlarmType/ActiveState/Number.
	EnumNumericNodeId_LimitAlarmType_ActiveState_Number = 9264,
	//! NodeId of the node LimitAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_LimitAlarmType_ActiveState_EffectiveDisplayName = 9265,
	//! NodeId of the node LimitAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_LimitAlarmType_ActiveState_TransitionTime = 9266,
	//! NodeId of the node LimitAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_LimitAlarmType_ActiveState_EffectiveTransitionTime = 9267,
	//! NodeId of the node LimitAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_LimitAlarmType_ActiveState_TrueState = 9268,
	//! NodeId of the node LimitAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_LimitAlarmType_ActiveState_FalseState = 9269,
	//! NodeId of the node LimitAlarmType/SuppressedState.
	EnumNumericNodeId_LimitAlarmType_SuppressedState = 9270,
	//! NodeId of the node LimitAlarmType/SuppressedState/Id.
	EnumNumericNodeId_LimitAlarmType_SuppressedState_Id = 9271,
	//! NodeId of the node LimitAlarmType/SuppressedState/Name.
	EnumNumericNodeId_LimitAlarmType_SuppressedState_Name = 9272,
	//! NodeId of the node LimitAlarmType/SuppressedState/Number.
	EnumNumericNodeId_LimitAlarmType_SuppressedState_Number = 9273,
	//! NodeId of the node LimitAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_LimitAlarmType_SuppressedState_EffectiveDisplayName = 9274,
	//! NodeId of the node LimitAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_LimitAlarmType_SuppressedState_TransitionTime = 9275,
	//! NodeId of the node LimitAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_LimitAlarmType_SuppressedState_EffectiveTransitionTime = 9276,
	//! NodeId of the node LimitAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_LimitAlarmType_SuppressedState_TrueState = 9277,
	//! NodeId of the node LimitAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_LimitAlarmType_SuppressedState_FalseState = 9278,
	//! NodeId of the node LimitAlarmType/ShelvingState.
	EnumNumericNodeId_LimitAlarmType_ShelvingState = 9279,
	//! NodeId of the node LimitAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_CurrentState = 9280,
	//! NodeId of the node LimitAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_CurrentState_Id = 9281,
	//! NodeId of the node LimitAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_CurrentState_Name = 9282,
	//! NodeId of the node LimitAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_CurrentState_Number = 9283,
	//! NodeId of the node LimitAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 9284,
	//! NodeId of the node LimitAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_LastTransition = 9285,
	//! NodeId of the node LimitAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_LastTransition_Id = 9286,
	//! NodeId of the node LimitAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_LastTransition_Name = 9287,
	//! NodeId of the node LimitAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_LastTransition_Number = 9288,
	//! NodeId of the node LimitAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_LastTransition_TransitionTime = 9289,
	//! NodeId of the node LimitAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_UnshelveTime = 9290,
	//! NodeId of the node LimitAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_Unshelve = 9312,
	//! NodeId of the node LimitAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_OneShotShelve = 9313,
	//! NodeId of the node LimitAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_TimedShelve = 9314,
	//! NodeId of the node LimitAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_TimedShelve_InputArguments = 9315,
	//! NodeId of the node LimitAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_LimitAlarmType_SuppressedOrShelved = 9316,
	//! NodeId of the node LimitAlarmType/MaxTimeShelved.
	EnumNumericNodeId_LimitAlarmType_MaxTimeShelved = 9317,
	//! NodeId of the object type ExclusiveLimitStateMachineType.
	EnumNumericNodeId_ExclusiveLimitStateMachineType = 9318,
	//! NodeId of the node ExclusiveLimitStateMachineType/CurrentState.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_CurrentState = 9319,
	//! NodeId of the node ExclusiveLimitStateMachineType/CurrentState/Id.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_CurrentState_Id = 9320,
	//! NodeId of the node ExclusiveLimitStateMachineType/CurrentState/Name.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_CurrentState_Name = 9321,
	//! NodeId of the node ExclusiveLimitStateMachineType/CurrentState/Number.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_CurrentState_Number = 9322,
	//! NodeId of the node ExclusiveLimitStateMachineType/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_CurrentState_EffectiveDisplayName = 9323,
	//! NodeId of the node ExclusiveLimitStateMachineType/LastTransition.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LastTransition = 9324,
	//! NodeId of the node ExclusiveLimitStateMachineType/LastTransition/Id.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LastTransition_Id = 9325,
	//! NodeId of the node ExclusiveLimitStateMachineType/LastTransition/Name.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LastTransition_Name = 9326,
	//! NodeId of the node ExclusiveLimitStateMachineType/LastTransition/Number.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LastTransition_Number = 9327,
	//! NodeId of the node ExclusiveLimitStateMachineType/LastTransition/TransitionTime.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LastTransition_TransitionTime = 9328,
	//! NodeId of the node ExclusiveLimitStateMachineType/HighHigh.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_HighHigh = 9329,
	//! NodeId of the node ExclusiveLimitStateMachineType/HighHigh/StateNumber.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_HighHigh_StateNumber = 9330,
	//! NodeId of the node ExclusiveLimitStateMachineType/High.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_High = 9331,
	//! NodeId of the node ExclusiveLimitStateMachineType/High/StateNumber.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_High_StateNumber = 9332,
	//! NodeId of the node ExclusiveLimitStateMachineType/Low.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_Low = 9333,
	//! NodeId of the node ExclusiveLimitStateMachineType/Low/StateNumber.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_Low_StateNumber = 9334,
	//! NodeId of the node ExclusiveLimitStateMachineType/LowLow.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LowLow = 9335,
	//! NodeId of the node ExclusiveLimitStateMachineType/LowLow/StateNumber.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LowLow_StateNumber = 9336,
	//! NodeId of the node ExclusiveLimitStateMachineType/LowLowToLow.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LowLowToLow = 9337,
	//! NodeId of the node ExclusiveLimitStateMachineType/LowToLowLow.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LowToLowLow = 9338,
	//! NodeId of the node ExclusiveLimitStateMachineType/HighHighToHigh.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_HighHighToHigh = 9339,
	//! NodeId of the node ExclusiveLimitStateMachineType/HighToHighHigh.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_HighToHighHigh = 9340,
	//! NodeId of the object type ExclusiveLimitAlarmType.
	EnumNumericNodeId_ExclusiveLimitAlarmType = 9341,
	//! NodeId of the node ExclusiveLimitAlarmType/EventId.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EventId = 9342,
	//! NodeId of the node ExclusiveLimitAlarmType/EventType.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EventType = 9343,
	//! NodeId of the node ExclusiveLimitAlarmType/SourceNode.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SourceNode = 9344,
	//! NodeId of the node ExclusiveLimitAlarmType/SourceName.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SourceName = 9345,
	//! NodeId of the node ExclusiveLimitAlarmType/Time.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Time = 9346,
	//! NodeId of the node ExclusiveLimitAlarmType/ReceiveTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ReceiveTime = 9347,
	//! NodeId of the node ExclusiveLimitAlarmType/LocalTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LocalTime = 9348,
	//! NodeId of the node ExclusiveLimitAlarmType/Message.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Message = 9349,
	//! NodeId of the node ExclusiveLimitAlarmType/Severity.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Severity = 9350,
	//! NodeId of the node ExclusiveLimitAlarmType/ConditionName.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConditionName = 9351,
	//! NodeId of the node ExclusiveLimitAlarmType/BranchId.
	EnumNumericNodeId_ExclusiveLimitAlarmType_BranchId = 9352,
	//! NodeId of the node ExclusiveLimitAlarmType/Retain.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Retain = 9353,
	//! NodeId of the node ExclusiveLimitAlarmType/EnabledState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EnabledState = 9354,
	//! NodeId of the node ExclusiveLimitAlarmType/EnabledState/Id.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EnabledState_Id = 9355,
	//! NodeId of the node ExclusiveLimitAlarmType/EnabledState/Name.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EnabledState_Name = 9356,
	//! NodeId of the node ExclusiveLimitAlarmType/EnabledState/Number.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EnabledState_Number = 9357,
	//! NodeId of the node ExclusiveLimitAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EnabledState_EffectiveDisplayName = 9358,
	//! NodeId of the node ExclusiveLimitAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EnabledState_TransitionTime = 9359,
	//! NodeId of the node ExclusiveLimitAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EnabledState_EffectiveTransitionTime = 9360,
	//! NodeId of the node ExclusiveLimitAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EnabledState_TrueState = 9361,
	//! NodeId of the node ExclusiveLimitAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_EnabledState_FalseState = 9362,
	//! NodeId of the node ExclusiveLimitAlarmType/Quality.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Quality = 9363,
	//! NodeId of the node ExclusiveLimitAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Quality_SourceTimestamp = 9364,
	//! NodeId of the node ExclusiveLimitAlarmType/LastSeverity.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LastSeverity = 9365,
	//! NodeId of the node ExclusiveLimitAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LastSeverity_SourceTimestamp = 9366,
	//! NodeId of the node ExclusiveLimitAlarmType/Comment.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Comment = 9367,
	//! NodeId of the node ExclusiveLimitAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Comment_SourceTimestamp = 9368,
	//! NodeId of the node ExclusiveLimitAlarmType/ClientUserId.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ClientUserId = 9369,
	//! NodeId of the node ExclusiveLimitAlarmType/Enable.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Enable = 9370,
	//! NodeId of the node ExclusiveLimitAlarmType/Disable.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Disable = 9371,
	//! NodeId of the node ExclusiveLimitAlarmType/AddComment.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AddComment = 9372,
	//! NodeId of the node ExclusiveLimitAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AddComment_InputArguments = 9373,
	//! NodeId of the node ExclusiveLimitAlarmType/ConditionRefresh.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConditionRefresh = 9374,
	//! NodeId of the node ExclusiveLimitAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConditionRefresh_InputArguments = 9375,
	//! NodeId of the node ExclusiveLimitAlarmType/AckedState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AckedState = 9376,
	//! NodeId of the node ExclusiveLimitAlarmType/AckedState/Id.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AckedState_Id = 9377,
	//! NodeId of the node ExclusiveLimitAlarmType/AckedState/Name.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AckedState_Name = 9378,
	//! NodeId of the node ExclusiveLimitAlarmType/AckedState/Number.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AckedState_Number = 9379,
	//! NodeId of the node ExclusiveLimitAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AckedState_EffectiveDisplayName = 9380,
	//! NodeId of the node ExclusiveLimitAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AckedState_TransitionTime = 9381,
	//! NodeId of the node ExclusiveLimitAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AckedState_EffectiveTransitionTime = 9382,
	//! NodeId of the node ExclusiveLimitAlarmType/AckedState/TrueState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AckedState_TrueState = 9383,
	//! NodeId of the node ExclusiveLimitAlarmType/AckedState/FalseState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_AckedState_FalseState = 9384,
	//! NodeId of the node ExclusiveLimitAlarmType/ConfirmedState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConfirmedState = 9385,
	//! NodeId of the node ExclusiveLimitAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConfirmedState_Id = 9386,
	//! NodeId of the node ExclusiveLimitAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConfirmedState_Name = 9387,
	//! NodeId of the node ExclusiveLimitAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConfirmedState_Number = 9388,
	//! NodeId of the node ExclusiveLimitAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConfirmedState_EffectiveDisplayName = 9389,
	//! NodeId of the node ExclusiveLimitAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConfirmedState_TransitionTime = 9390,
	//! NodeId of the node ExclusiveLimitAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConfirmedState_EffectiveTransitionTime = 9391,
	//! NodeId of the node ExclusiveLimitAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConfirmedState_TrueState = 9392,
	//! NodeId of the node ExclusiveLimitAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConfirmedState_FalseState = 9393,
	//! NodeId of the node ExclusiveLimitAlarmType/Acknowledge.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Acknowledge = 9394,
	//! NodeId of the node ExclusiveLimitAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Acknowledge_InputArguments = 9395,
	//! NodeId of the node ExclusiveLimitAlarmType/Confirm.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Confirm = 9396,
	//! NodeId of the node ExclusiveLimitAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_ExclusiveLimitAlarmType_Confirm_InputArguments = 9397,
	//! NodeId of the node ExclusiveLimitAlarmType/ActiveState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ActiveState = 9398,
	//! NodeId of the node ExclusiveLimitAlarmType/ActiveState/Id.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ActiveState_Id = 9399,
	//! NodeId of the node ExclusiveLimitAlarmType/ActiveState/Name.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ActiveState_Name = 9400,
	//! NodeId of the node ExclusiveLimitAlarmType/ActiveState/Number.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ActiveState_Number = 9401,
	//! NodeId of the node ExclusiveLimitAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ActiveState_EffectiveDisplayName = 9402,
	//! NodeId of the node ExclusiveLimitAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ActiveState_TransitionTime = 9403,
	//! NodeId of the node ExclusiveLimitAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ActiveState_EffectiveTransitionTime = 9404,
	//! NodeId of the node ExclusiveLimitAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ActiveState_TrueState = 9405,
	//! NodeId of the node ExclusiveLimitAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ActiveState_FalseState = 9406,
	//! NodeId of the node ExclusiveLimitAlarmType/SuppressedState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SuppressedState = 9407,
	//! NodeId of the node ExclusiveLimitAlarmType/SuppressedState/Id.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SuppressedState_Id = 9408,
	//! NodeId of the node ExclusiveLimitAlarmType/SuppressedState/Name.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SuppressedState_Name = 9409,
	//! NodeId of the node ExclusiveLimitAlarmType/SuppressedState/Number.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SuppressedState_Number = 9410,
	//! NodeId of the node ExclusiveLimitAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SuppressedState_EffectiveDisplayName = 9411,
	//! NodeId of the node ExclusiveLimitAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SuppressedState_TransitionTime = 9412,
	//! NodeId of the node ExclusiveLimitAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SuppressedState_EffectiveTransitionTime = 9413,
	//! NodeId of the node ExclusiveLimitAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SuppressedState_TrueState = 9414,
	//! NodeId of the node ExclusiveLimitAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SuppressedState_FalseState = 9415,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState = 9416,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_CurrentState = 9417,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_CurrentState_Id = 9418,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_CurrentState_Name = 9419,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_CurrentState_Number = 9420,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 9421,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_LastTransition = 9422,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_LastTransition_Id = 9423,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_LastTransition_Name = 9424,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_LastTransition_Number = 9425,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_LastTransition_TransitionTime = 9426,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_UnshelveTime = 9427,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_Unshelve = 9449,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_OneShotShelve = 9450,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_TimedShelve = 9451,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_TimedShelve_InputArguments = 9452,
	//! NodeId of the node ExclusiveLimitAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_ExclusiveLimitAlarmType_SuppressedOrShelved = 9453,
	//! NodeId of the node ExclusiveLimitAlarmType/MaxTimeShelved.
	EnumNumericNodeId_ExclusiveLimitAlarmType_MaxTimeShelved = 9454,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState = 9455,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/CurrentState.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_CurrentState = 9456,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/CurrentState/Id.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_CurrentState_Id = 9457,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/CurrentState/Name.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_CurrentState_Name = 9458,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/CurrentState/Number.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_CurrentState_Number = 9459,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_CurrentState_EffectiveDisplayName = 9460,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/LastTransition.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_LastTransition = 9461,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/LastTransition/Id.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_LastTransition_Id = 9462,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/LastTransition/Name.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_LastTransition_Name = 9463,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/LastTransition/Number.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_LastTransition_Number = 9464,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/LastTransition/TransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_LastTransition_TransitionTime = 9465,
	//! NodeId of the node ExclusiveLimitAlarmType/HighHighLimit.
	EnumNumericNodeId_ExclusiveLimitAlarmType_HighHighLimit = 9478,
	//! NodeId of the node ExclusiveLimitAlarmType/HighLimit.
	EnumNumericNodeId_ExclusiveLimitAlarmType_HighLimit = 9479,
	//! NodeId of the node ExclusiveLimitAlarmType/LowLimit.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LowLimit = 9480,
	//! NodeId of the node ExclusiveLimitAlarmType/LowLowLimit.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LowLowLimit = 9481,
	//! NodeId of the object type ExclusiveLevelAlarmType.
	EnumNumericNodeId_ExclusiveLevelAlarmType = 9482,
	//! NodeId of the node ExclusiveLevelAlarmType/EventId.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EventId = 9483,
	//! NodeId of the node ExclusiveLevelAlarmType/EventType.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EventType = 9484,
	//! NodeId of the node ExclusiveLevelAlarmType/SourceNode.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SourceNode = 9485,
	//! NodeId of the node ExclusiveLevelAlarmType/SourceName.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SourceName = 9486,
	//! NodeId of the node ExclusiveLevelAlarmType/Time.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Time = 9487,
	//! NodeId of the node ExclusiveLevelAlarmType/ReceiveTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ReceiveTime = 9488,
	//! NodeId of the node ExclusiveLevelAlarmType/LocalTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LocalTime = 9489,
	//! NodeId of the node ExclusiveLevelAlarmType/Message.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Message = 9490,
	//! NodeId of the node ExclusiveLevelAlarmType/Severity.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Severity = 9491,
	//! NodeId of the node ExclusiveLevelAlarmType/ConditionName.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConditionName = 9492,
	//! NodeId of the node ExclusiveLevelAlarmType/BranchId.
	EnumNumericNodeId_ExclusiveLevelAlarmType_BranchId = 9493,
	//! NodeId of the node ExclusiveLevelAlarmType/Retain.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Retain = 9494,
	//! NodeId of the node ExclusiveLevelAlarmType/EnabledState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EnabledState = 9495,
	//! NodeId of the node ExclusiveLevelAlarmType/EnabledState/Id.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EnabledState_Id = 9496,
	//! NodeId of the node ExclusiveLevelAlarmType/EnabledState/Name.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EnabledState_Name = 9497,
	//! NodeId of the node ExclusiveLevelAlarmType/EnabledState/Number.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EnabledState_Number = 9498,
	//! NodeId of the node ExclusiveLevelAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EnabledState_EffectiveDisplayName = 9499,
	//! NodeId of the node ExclusiveLevelAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EnabledState_TransitionTime = 9500,
	//! NodeId of the node ExclusiveLevelAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EnabledState_EffectiveTransitionTime = 9501,
	//! NodeId of the node ExclusiveLevelAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EnabledState_TrueState = 9502,
	//! NodeId of the node ExclusiveLevelAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_EnabledState_FalseState = 9503,
	//! NodeId of the node ExclusiveLevelAlarmType/Quality.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Quality = 9504,
	//! NodeId of the node ExclusiveLevelAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Quality_SourceTimestamp = 9505,
	//! NodeId of the node ExclusiveLevelAlarmType/LastSeverity.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LastSeverity = 9506,
	//! NodeId of the node ExclusiveLevelAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LastSeverity_SourceTimestamp = 9507,
	//! NodeId of the node ExclusiveLevelAlarmType/Comment.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Comment = 9508,
	//! NodeId of the node ExclusiveLevelAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Comment_SourceTimestamp = 9509,
	//! NodeId of the node ExclusiveLevelAlarmType/ClientUserId.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ClientUserId = 9510,
	//! NodeId of the node ExclusiveLevelAlarmType/Enable.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Enable = 9511,
	//! NodeId of the node ExclusiveLevelAlarmType/Disable.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Disable = 9512,
	//! NodeId of the node ExclusiveLevelAlarmType/AddComment.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AddComment = 9513,
	//! NodeId of the node ExclusiveLevelAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AddComment_InputArguments = 9514,
	//! NodeId of the node ExclusiveLevelAlarmType/ConditionRefresh.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConditionRefresh = 9515,
	//! NodeId of the node ExclusiveLevelAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConditionRefresh_InputArguments = 9516,
	//! NodeId of the node ExclusiveLevelAlarmType/AckedState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AckedState = 9517,
	//! NodeId of the node ExclusiveLevelAlarmType/AckedState/Id.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AckedState_Id = 9518,
	//! NodeId of the node ExclusiveLevelAlarmType/AckedState/Name.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AckedState_Name = 9519,
	//! NodeId of the node ExclusiveLevelAlarmType/AckedState/Number.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AckedState_Number = 9520,
	//! NodeId of the node ExclusiveLevelAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AckedState_EffectiveDisplayName = 9521,
	//! NodeId of the node ExclusiveLevelAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AckedState_TransitionTime = 9522,
	//! NodeId of the node ExclusiveLevelAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AckedState_EffectiveTransitionTime = 9523,
	//! NodeId of the node ExclusiveLevelAlarmType/AckedState/TrueState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AckedState_TrueState = 9524,
	//! NodeId of the node ExclusiveLevelAlarmType/AckedState/FalseState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_AckedState_FalseState = 9525,
	//! NodeId of the node ExclusiveLevelAlarmType/ConfirmedState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConfirmedState = 9526,
	//! NodeId of the node ExclusiveLevelAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConfirmedState_Id = 9527,
	//! NodeId of the node ExclusiveLevelAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConfirmedState_Name = 9528,
	//! NodeId of the node ExclusiveLevelAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConfirmedState_Number = 9529,
	//! NodeId of the node ExclusiveLevelAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConfirmedState_EffectiveDisplayName = 9530,
	//! NodeId of the node ExclusiveLevelAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConfirmedState_TransitionTime = 9531,
	//! NodeId of the node ExclusiveLevelAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConfirmedState_EffectiveTransitionTime = 9532,
	//! NodeId of the node ExclusiveLevelAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConfirmedState_TrueState = 9533,
	//! NodeId of the node ExclusiveLevelAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConfirmedState_FalseState = 9534,
	//! NodeId of the node ExclusiveLevelAlarmType/Acknowledge.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Acknowledge = 9535,
	//! NodeId of the node ExclusiveLevelAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Acknowledge_InputArguments = 9536,
	//! NodeId of the node ExclusiveLevelAlarmType/Confirm.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Confirm = 9537,
	//! NodeId of the node ExclusiveLevelAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_ExclusiveLevelAlarmType_Confirm_InputArguments = 9538,
	//! NodeId of the node ExclusiveLevelAlarmType/ActiveState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ActiveState = 9539,
	//! NodeId of the node ExclusiveLevelAlarmType/ActiveState/Id.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ActiveState_Id = 9540,
	//! NodeId of the node ExclusiveLevelAlarmType/ActiveState/Name.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ActiveState_Name = 9541,
	//! NodeId of the node ExclusiveLevelAlarmType/ActiveState/Number.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ActiveState_Number = 9542,
	//! NodeId of the node ExclusiveLevelAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ActiveState_EffectiveDisplayName = 9543,
	//! NodeId of the node ExclusiveLevelAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ActiveState_TransitionTime = 9544,
	//! NodeId of the node ExclusiveLevelAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ActiveState_EffectiveTransitionTime = 9545,
	//! NodeId of the node ExclusiveLevelAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ActiveState_TrueState = 9546,
	//! NodeId of the node ExclusiveLevelAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ActiveState_FalseState = 9547,
	//! NodeId of the node ExclusiveLevelAlarmType/SuppressedState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SuppressedState = 9548,
	//! NodeId of the node ExclusiveLevelAlarmType/SuppressedState/Id.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SuppressedState_Id = 9549,
	//! NodeId of the node ExclusiveLevelAlarmType/SuppressedState/Name.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SuppressedState_Name = 9550,
	//! NodeId of the node ExclusiveLevelAlarmType/SuppressedState/Number.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SuppressedState_Number = 9551,
	//! NodeId of the node ExclusiveLevelAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SuppressedState_EffectiveDisplayName = 9552,
	//! NodeId of the node ExclusiveLevelAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SuppressedState_TransitionTime = 9553,
	//! NodeId of the node ExclusiveLevelAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SuppressedState_EffectiveTransitionTime = 9554,
	//! NodeId of the node ExclusiveLevelAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SuppressedState_TrueState = 9555,
	//! NodeId of the node ExclusiveLevelAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SuppressedState_FalseState = 9556,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState = 9557,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_CurrentState = 9558,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_CurrentState_Id = 9559,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_CurrentState_Name = 9560,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_CurrentState_Number = 9561,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 9562,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_LastTransition = 9563,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_LastTransition_Id = 9564,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_LastTransition_Name = 9565,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_LastTransition_Number = 9566,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_LastTransition_TransitionTime = 9567,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_UnshelveTime = 9568,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_Unshelve = 9590,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_OneShotShelve = 9591,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_TimedShelve = 9592,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_TimedShelve_InputArguments = 9593,
	//! NodeId of the node ExclusiveLevelAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_ExclusiveLevelAlarmType_SuppressedOrShelved = 9594,
	//! NodeId of the node ExclusiveLevelAlarmType/MaxTimeShelved.
	EnumNumericNodeId_ExclusiveLevelAlarmType_MaxTimeShelved = 9595,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState = 9596,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/CurrentState.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_CurrentState = 9597,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/CurrentState/Id.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_CurrentState_Id = 9598,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/CurrentState/Name.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_CurrentState_Name = 9599,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/CurrentState/Number.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_CurrentState_Number = 9600,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_CurrentState_EffectiveDisplayName = 9601,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/LastTransition.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_LastTransition = 9602,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/LastTransition/Id.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_LastTransition_Id = 9603,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/LastTransition/Name.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_LastTransition_Name = 9604,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/LastTransition/Number.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_LastTransition_Number = 9605,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/LastTransition/TransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_LastTransition_TransitionTime = 9606,
	//! NodeId of the node ExclusiveLevelAlarmType/HighHighLimit.
	EnumNumericNodeId_ExclusiveLevelAlarmType_HighHighLimit = 9619,
	//! NodeId of the node ExclusiveLevelAlarmType/HighLimit.
	EnumNumericNodeId_ExclusiveLevelAlarmType_HighLimit = 9620,
	//! NodeId of the node ExclusiveLevelAlarmType/LowLimit.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LowLimit = 9621,
	//! NodeId of the node ExclusiveLevelAlarmType/LowLowLimit.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LowLowLimit = 9622,
	//! NodeId of the object type ExclusiveRateOfChangeAlarmType.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType = 9623,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EventId.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EventId = 9624,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EventType.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EventType = 9625,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SourceNode.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SourceNode = 9626,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SourceName.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SourceName = 9627,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Time.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Time = 9628,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ReceiveTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ReceiveTime = 9629,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LocalTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LocalTime = 9630,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Message.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Message = 9631,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Severity.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Severity = 9632,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConditionName.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConditionName = 9633,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/BranchId.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_BranchId = 9634,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Retain.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Retain = 9635,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EnabledState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EnabledState = 9636,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EnabledState/Id.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EnabledState_Id = 9637,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EnabledState/Name.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EnabledState_Name = 9638,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EnabledState/Number.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EnabledState_Number = 9639,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EnabledState_EffectiveDisplayName = 9640,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EnabledState_TransitionTime = 9641,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EnabledState_EffectiveTransitionTime = 9642,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EnabledState_TrueState = 9643,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_EnabledState_FalseState = 9644,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Quality.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Quality = 9645,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Quality_SourceTimestamp = 9646,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LastSeverity.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LastSeverity = 9647,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LastSeverity_SourceTimestamp = 9648,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Comment.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Comment = 9649,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Comment_SourceTimestamp = 9650,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ClientUserId.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ClientUserId = 9651,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Enable.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Enable = 9652,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Disable.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Disable = 9653,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AddComment.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AddComment = 9654,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AddComment_InputArguments = 9655,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConditionRefresh.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConditionRefresh = 9656,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConditionRefresh_InputArguments = 9657,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AckedState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AckedState = 9658,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AckedState/Id.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AckedState_Id = 9659,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AckedState/Name.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AckedState_Name = 9660,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AckedState/Number.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AckedState_Number = 9661,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AckedState_EffectiveDisplayName = 9662,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AckedState_TransitionTime = 9663,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AckedState_EffectiveTransitionTime = 9664,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AckedState/TrueState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AckedState_TrueState = 9665,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/AckedState/FalseState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_AckedState_FalseState = 9666,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConfirmedState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConfirmedState = 9667,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConfirmedState_Id = 9668,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConfirmedState_Name = 9669,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConfirmedState_Number = 9670,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConfirmedState_EffectiveDisplayName = 9671,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConfirmedState_TransitionTime = 9672,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConfirmedState_EffectiveTransitionTime = 9673,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConfirmedState_TrueState = 9674,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConfirmedState_FalseState = 9675,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Acknowledge.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Acknowledge = 9676,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Acknowledge_InputArguments = 9677,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Confirm.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Confirm = 9678,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_Confirm_InputArguments = 9679,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ActiveState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ActiveState = 9680,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ActiveState/Id.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ActiveState_Id = 9681,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ActiveState/Name.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ActiveState_Name = 9682,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ActiveState/Number.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ActiveState_Number = 9683,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ActiveState_EffectiveDisplayName = 9684,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ActiveState_TransitionTime = 9685,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ActiveState_EffectiveTransitionTime = 9686,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ActiveState_TrueState = 9687,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ActiveState_FalseState = 9688,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SuppressedState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SuppressedState = 9689,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SuppressedState/Id.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SuppressedState_Id = 9690,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SuppressedState/Name.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SuppressedState_Name = 9691,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SuppressedState/Number.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SuppressedState_Number = 9692,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SuppressedState_EffectiveDisplayName = 9693,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SuppressedState_TransitionTime = 9694,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SuppressedState_EffectiveTransitionTime = 9695,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SuppressedState_TrueState = 9696,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SuppressedState_FalseState = 9697,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState = 9698,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_CurrentState = 9699,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_CurrentState_Id = 9700,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_CurrentState_Name = 9701,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_CurrentState_Number = 9702,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 9703,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition = 9704,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition_Id = 9705,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition_Name = 9706,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition_Number = 9707,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition_TransitionTime = 9708,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_UnshelveTime = 9709,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_Unshelve = 9731,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_OneShotShelve = 9732,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_TimedShelve = 9733,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_TimedShelve_InputArguments = 9734,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_SuppressedOrShelved = 9735,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/MaxTimeShelved.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_MaxTimeShelved = 9736,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState = 9737,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/CurrentState.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_CurrentState = 9738,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/CurrentState/Id.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_CurrentState_Id = 9739,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/CurrentState/Name.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_CurrentState_Name = 9740,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/CurrentState/Number.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_CurrentState_Number = 9741,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_CurrentState_EffectiveDisplayName = 9742,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/LastTransition.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_LastTransition = 9743,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/LastTransition/Id.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_LastTransition_Id = 9744,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/LastTransition/Name.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_LastTransition_Name = 9745,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/LastTransition/Number.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_LastTransition_Number = 9746,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/LastTransition/TransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_LastTransition_TransitionTime = 9747,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/HighHighLimit.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_HighHighLimit = 9760,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/HighLimit.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_HighLimit = 9761,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LowLimit.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LowLimit = 9762,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LowLowLimit.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LowLowLimit = 9763,
	//! NodeId of the object type ExclusiveDeviationAlarmType.
	EnumNumericNodeId_ExclusiveDeviationAlarmType = 9764,
	//! NodeId of the node ExclusiveDeviationAlarmType/EventId.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EventId = 9765,
	//! NodeId of the node ExclusiveDeviationAlarmType/EventType.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EventType = 9766,
	//! NodeId of the node ExclusiveDeviationAlarmType/SourceNode.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SourceNode = 9767,
	//! NodeId of the node ExclusiveDeviationAlarmType/SourceName.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SourceName = 9768,
	//! NodeId of the node ExclusiveDeviationAlarmType/Time.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Time = 9769,
	//! NodeId of the node ExclusiveDeviationAlarmType/ReceiveTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ReceiveTime = 9770,
	//! NodeId of the node ExclusiveDeviationAlarmType/LocalTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LocalTime = 9771,
	//! NodeId of the node ExclusiveDeviationAlarmType/Message.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Message = 9772,
	//! NodeId of the node ExclusiveDeviationAlarmType/Severity.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Severity = 9773,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConditionName.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConditionName = 9774,
	//! NodeId of the node ExclusiveDeviationAlarmType/BranchId.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_BranchId = 9775,
	//! NodeId of the node ExclusiveDeviationAlarmType/Retain.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Retain = 9776,
	//! NodeId of the node ExclusiveDeviationAlarmType/EnabledState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EnabledState = 9777,
	//! NodeId of the node ExclusiveDeviationAlarmType/EnabledState/Id.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EnabledState_Id = 9778,
	//! NodeId of the node ExclusiveDeviationAlarmType/EnabledState/Name.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EnabledState_Name = 9779,
	//! NodeId of the node ExclusiveDeviationAlarmType/EnabledState/Number.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EnabledState_Number = 9780,
	//! NodeId of the node ExclusiveDeviationAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EnabledState_EffectiveDisplayName = 9781,
	//! NodeId of the node ExclusiveDeviationAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EnabledState_TransitionTime = 9782,
	//! NodeId of the node ExclusiveDeviationAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EnabledState_EffectiveTransitionTime = 9783,
	//! NodeId of the node ExclusiveDeviationAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EnabledState_TrueState = 9784,
	//! NodeId of the node ExclusiveDeviationAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_EnabledState_FalseState = 9785,
	//! NodeId of the node ExclusiveDeviationAlarmType/Quality.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Quality = 9786,
	//! NodeId of the node ExclusiveDeviationAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Quality_SourceTimestamp = 9787,
	//! NodeId of the node ExclusiveDeviationAlarmType/LastSeverity.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LastSeverity = 9788,
	//! NodeId of the node ExclusiveDeviationAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LastSeverity_SourceTimestamp = 9789,
	//! NodeId of the node ExclusiveDeviationAlarmType/Comment.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Comment = 9790,
	//! NodeId of the node ExclusiveDeviationAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Comment_SourceTimestamp = 9791,
	//! NodeId of the node ExclusiveDeviationAlarmType/ClientUserId.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ClientUserId = 9792,
	//! NodeId of the node ExclusiveDeviationAlarmType/Enable.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Enable = 9793,
	//! NodeId of the node ExclusiveDeviationAlarmType/Disable.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Disable = 9794,
	//! NodeId of the node ExclusiveDeviationAlarmType/AddComment.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AddComment = 9795,
	//! NodeId of the node ExclusiveDeviationAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AddComment_InputArguments = 9796,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConditionRefresh.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConditionRefresh = 9797,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConditionRefresh_InputArguments = 9798,
	//! NodeId of the node ExclusiveDeviationAlarmType/AckedState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AckedState = 9799,
	//! NodeId of the node ExclusiveDeviationAlarmType/AckedState/Id.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AckedState_Id = 9800,
	//! NodeId of the node ExclusiveDeviationAlarmType/AckedState/Name.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AckedState_Name = 9801,
	//! NodeId of the node ExclusiveDeviationAlarmType/AckedState/Number.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AckedState_Number = 9802,
	//! NodeId of the node ExclusiveDeviationAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AckedState_EffectiveDisplayName = 9803,
	//! NodeId of the node ExclusiveDeviationAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AckedState_TransitionTime = 9804,
	//! NodeId of the node ExclusiveDeviationAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AckedState_EffectiveTransitionTime = 9805,
	//! NodeId of the node ExclusiveDeviationAlarmType/AckedState/TrueState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AckedState_TrueState = 9806,
	//! NodeId of the node ExclusiveDeviationAlarmType/AckedState/FalseState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_AckedState_FalseState = 9807,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConfirmedState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConfirmedState = 9808,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConfirmedState_Id = 9809,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConfirmedState_Name = 9810,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConfirmedState_Number = 9811,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConfirmedState_EffectiveDisplayName = 9812,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConfirmedState_TransitionTime = 9813,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConfirmedState_EffectiveTransitionTime = 9814,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConfirmedState_TrueState = 9815,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConfirmedState_FalseState = 9816,
	//! NodeId of the node ExclusiveDeviationAlarmType/Acknowledge.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Acknowledge = 9817,
	//! NodeId of the node ExclusiveDeviationAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Acknowledge_InputArguments = 9818,
	//! NodeId of the node ExclusiveDeviationAlarmType/Confirm.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Confirm = 9819,
	//! NodeId of the node ExclusiveDeviationAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_Confirm_InputArguments = 9820,
	//! NodeId of the node ExclusiveDeviationAlarmType/ActiveState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ActiveState = 9821,
	//! NodeId of the node ExclusiveDeviationAlarmType/ActiveState/Id.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ActiveState_Id = 9822,
	//! NodeId of the node ExclusiveDeviationAlarmType/ActiveState/Name.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ActiveState_Name = 9823,
	//! NodeId of the node ExclusiveDeviationAlarmType/ActiveState/Number.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ActiveState_Number = 9824,
	//! NodeId of the node ExclusiveDeviationAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ActiveState_EffectiveDisplayName = 9825,
	//! NodeId of the node ExclusiveDeviationAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ActiveState_TransitionTime = 9826,
	//! NodeId of the node ExclusiveDeviationAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ActiveState_EffectiveTransitionTime = 9827,
	//! NodeId of the node ExclusiveDeviationAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ActiveState_TrueState = 9828,
	//! NodeId of the node ExclusiveDeviationAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ActiveState_FalseState = 9829,
	//! NodeId of the node ExclusiveDeviationAlarmType/SuppressedState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SuppressedState = 9830,
	//! NodeId of the node ExclusiveDeviationAlarmType/SuppressedState/Id.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SuppressedState_Id = 9831,
	//! NodeId of the node ExclusiveDeviationAlarmType/SuppressedState/Name.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SuppressedState_Name = 9832,
	//! NodeId of the node ExclusiveDeviationAlarmType/SuppressedState/Number.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SuppressedState_Number = 9833,
	//! NodeId of the node ExclusiveDeviationAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SuppressedState_EffectiveDisplayName = 9834,
	//! NodeId of the node ExclusiveDeviationAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SuppressedState_TransitionTime = 9835,
	//! NodeId of the node ExclusiveDeviationAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SuppressedState_EffectiveTransitionTime = 9836,
	//! NodeId of the node ExclusiveDeviationAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SuppressedState_TrueState = 9837,
	//! NodeId of the node ExclusiveDeviationAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SuppressedState_FalseState = 9838,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState = 9839,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_CurrentState = 9840,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_CurrentState_Id = 9841,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_CurrentState_Name = 9842,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_CurrentState_Number = 9843,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 9844,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_LastTransition = 9845,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_LastTransition_Id = 9846,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_LastTransition_Name = 9847,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_LastTransition_Number = 9848,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_LastTransition_TransitionTime = 9849,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_UnshelveTime = 9850,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_Unshelve = 9872,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_OneShotShelve = 9873,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_TimedShelve = 9874,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_TimedShelve_InputArguments = 9875,
	//! NodeId of the node ExclusiveDeviationAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SuppressedOrShelved = 9876,
	//! NodeId of the node ExclusiveDeviationAlarmType/MaxTimeShelved.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_MaxTimeShelved = 9877,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState = 9878,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/CurrentState.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_CurrentState = 9879,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/CurrentState/Id.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_CurrentState_Id = 9880,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/CurrentState/Name.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_CurrentState_Name = 9881,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/CurrentState/Number.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_CurrentState_Number = 9882,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_CurrentState_EffectiveDisplayName = 9883,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/LastTransition.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_LastTransition = 9884,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/LastTransition/Id.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_LastTransition_Id = 9885,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/LastTransition/Name.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_LastTransition_Name = 9886,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/LastTransition/Number.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_LastTransition_Number = 9887,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/LastTransition/TransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_LastTransition_TransitionTime = 9888,
	//! NodeId of the node ExclusiveDeviationAlarmType/HighHighLimit.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_HighHighLimit = 9901,
	//! NodeId of the node ExclusiveDeviationAlarmType/HighLimit.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_HighLimit = 9902,
	//! NodeId of the node ExclusiveDeviationAlarmType/LowLimit.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LowLimit = 9903,
	//! NodeId of the node ExclusiveDeviationAlarmType/LowLowLimit.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LowLowLimit = 9904,
	//! NodeId of the node ExclusiveDeviationAlarmType/SetpointNode.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_SetpointNode = 9905,
	//! NodeId of the object type NonExclusiveLimitAlarmType.
	EnumNumericNodeId_NonExclusiveLimitAlarmType = 9906,
	//! NodeId of the node NonExclusiveLimitAlarmType/EventId.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EventId = 9907,
	//! NodeId of the node NonExclusiveLimitAlarmType/EventType.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EventType = 9908,
	//! NodeId of the node NonExclusiveLimitAlarmType/SourceNode.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SourceNode = 9909,
	//! NodeId of the node NonExclusiveLimitAlarmType/SourceName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SourceName = 9910,
	//! NodeId of the node NonExclusiveLimitAlarmType/Time.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Time = 9911,
	//! NodeId of the node NonExclusiveLimitAlarmType/ReceiveTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ReceiveTime = 9912,
	//! NodeId of the node NonExclusiveLimitAlarmType/LocalTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LocalTime = 9913,
	//! NodeId of the node NonExclusiveLimitAlarmType/Message.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Message = 9914,
	//! NodeId of the node NonExclusiveLimitAlarmType/Severity.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Severity = 9915,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConditionName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConditionName = 9916,
	//! NodeId of the node NonExclusiveLimitAlarmType/BranchId.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_BranchId = 9917,
	//! NodeId of the node NonExclusiveLimitAlarmType/Retain.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Retain = 9918,
	//! NodeId of the node NonExclusiveLimitAlarmType/EnabledState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EnabledState = 9919,
	//! NodeId of the node NonExclusiveLimitAlarmType/EnabledState/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EnabledState_Id = 9920,
	//! NodeId of the node NonExclusiveLimitAlarmType/EnabledState/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EnabledState_Name = 9921,
	//! NodeId of the node NonExclusiveLimitAlarmType/EnabledState/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EnabledState_Number = 9922,
	//! NodeId of the node NonExclusiveLimitAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EnabledState_EffectiveDisplayName = 9923,
	//! NodeId of the node NonExclusiveLimitAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EnabledState_TransitionTime = 9924,
	//! NodeId of the node NonExclusiveLimitAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EnabledState_EffectiveTransitionTime = 9925,
	//! NodeId of the node NonExclusiveLimitAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EnabledState_TrueState = 9926,
	//! NodeId of the node NonExclusiveLimitAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_EnabledState_FalseState = 9927,
	//! NodeId of the node NonExclusiveLimitAlarmType/Quality.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Quality = 9928,
	//! NodeId of the node NonExclusiveLimitAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Quality_SourceTimestamp = 9929,
	//! NodeId of the node NonExclusiveLimitAlarmType/LastSeverity.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LastSeverity = 9930,
	//! NodeId of the node NonExclusiveLimitAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LastSeverity_SourceTimestamp = 9931,
	//! NodeId of the node NonExclusiveLimitAlarmType/Comment.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Comment = 9932,
	//! NodeId of the node NonExclusiveLimitAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Comment_SourceTimestamp = 9933,
	//! NodeId of the node NonExclusiveLimitAlarmType/ClientUserId.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ClientUserId = 9934,
	//! NodeId of the node NonExclusiveLimitAlarmType/Enable.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Enable = 9935,
	//! NodeId of the node NonExclusiveLimitAlarmType/Disable.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Disable = 9936,
	//! NodeId of the node NonExclusiveLimitAlarmType/AddComment.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AddComment = 9937,
	//! NodeId of the node NonExclusiveLimitAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AddComment_InputArguments = 9938,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConditionRefresh.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConditionRefresh = 9939,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConditionRefresh_InputArguments = 9940,
	//! NodeId of the node NonExclusiveLimitAlarmType/AckedState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AckedState = 9941,
	//! NodeId of the node NonExclusiveLimitAlarmType/AckedState/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AckedState_Id = 9942,
	//! NodeId of the node NonExclusiveLimitAlarmType/AckedState/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AckedState_Name = 9943,
	//! NodeId of the node NonExclusiveLimitAlarmType/AckedState/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AckedState_Number = 9944,
	//! NodeId of the node NonExclusiveLimitAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AckedState_EffectiveDisplayName = 9945,
	//! NodeId of the node NonExclusiveLimitAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AckedState_TransitionTime = 9946,
	//! NodeId of the node NonExclusiveLimitAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AckedState_EffectiveTransitionTime = 9947,
	//! NodeId of the node NonExclusiveLimitAlarmType/AckedState/TrueState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AckedState_TrueState = 9948,
	//! NodeId of the node NonExclusiveLimitAlarmType/AckedState/FalseState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_AckedState_FalseState = 9949,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConfirmedState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConfirmedState = 9950,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConfirmedState_Id = 9951,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConfirmedState_Name = 9952,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConfirmedState_Number = 9953,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConfirmedState_EffectiveDisplayName = 9954,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConfirmedState_TransitionTime = 9955,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConfirmedState_EffectiveTransitionTime = 9956,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConfirmedState_TrueState = 9957,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConfirmedState_FalseState = 9958,
	//! NodeId of the node NonExclusiveLimitAlarmType/Acknowledge.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Acknowledge = 9959,
	//! NodeId of the node NonExclusiveLimitAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Acknowledge_InputArguments = 9960,
	//! NodeId of the node NonExclusiveLimitAlarmType/Confirm.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Confirm = 9961,
	//! NodeId of the node NonExclusiveLimitAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_Confirm_InputArguments = 9962,
	//! NodeId of the node NonExclusiveLimitAlarmType/ActiveState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ActiveState = 9963,
	//! NodeId of the node NonExclusiveLimitAlarmType/ActiveState/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ActiveState_Id = 9964,
	//! NodeId of the node NonExclusiveLimitAlarmType/ActiveState/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ActiveState_Name = 9965,
	//! NodeId of the node NonExclusiveLimitAlarmType/ActiveState/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ActiveState_Number = 9966,
	//! NodeId of the node NonExclusiveLimitAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ActiveState_EffectiveDisplayName = 9967,
	//! NodeId of the node NonExclusiveLimitAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ActiveState_TransitionTime = 9968,
	//! NodeId of the node NonExclusiveLimitAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ActiveState_EffectiveTransitionTime = 9969,
	//! NodeId of the node NonExclusiveLimitAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ActiveState_TrueState = 9970,
	//! NodeId of the node NonExclusiveLimitAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ActiveState_FalseState = 9971,
	//! NodeId of the node NonExclusiveLimitAlarmType/SuppressedState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SuppressedState = 9972,
	//! NodeId of the node NonExclusiveLimitAlarmType/SuppressedState/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SuppressedState_Id = 9973,
	//! NodeId of the node NonExclusiveLimitAlarmType/SuppressedState/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SuppressedState_Name = 9974,
	//! NodeId of the node NonExclusiveLimitAlarmType/SuppressedState/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SuppressedState_Number = 9975,
	//! NodeId of the node NonExclusiveLimitAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SuppressedState_EffectiveDisplayName = 9976,
	//! NodeId of the node NonExclusiveLimitAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SuppressedState_TransitionTime = 9977,
	//! NodeId of the node NonExclusiveLimitAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SuppressedState_EffectiveTransitionTime = 9978,
	//! NodeId of the node NonExclusiveLimitAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SuppressedState_TrueState = 9979,
	//! NodeId of the node NonExclusiveLimitAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SuppressedState_FalseState = 9980,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState = 9981,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_CurrentState = 9982,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_CurrentState_Id = 9983,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_CurrentState_Name = 9984,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_CurrentState_Number = 9985,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 9986,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_LastTransition = 9987,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_LastTransition_Id = 9988,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_LastTransition_Name = 9989,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_LastTransition_Number = 9990,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_LastTransition_TransitionTime = 9991,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_UnshelveTime = 9992,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_Unshelve = 10014,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_OneShotShelve = 10015,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_TimedShelve = 10016,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_TimedShelve_InputArguments = 10017,
	//! NodeId of the node NonExclusiveLimitAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_SuppressedOrShelved = 10018,
	//! NodeId of the node NonExclusiveLimitAlarmType/MaxTimeShelved.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_MaxTimeShelved = 10019,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighHighState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighHighState = 10020,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighHighState/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighHighState_Id = 10021,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighHighState/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighHighState_Name = 10022,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighHighState/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighHighState_Number = 10023,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighHighState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighHighState_EffectiveDisplayName = 10024,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighHighState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighHighState_TransitionTime = 10025,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighHighState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighHighState_EffectiveTransitionTime = 10026,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighHighState/TrueState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighHighState_TrueState = 10027,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighHighState/FalseState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighHighState_FalseState = 10028,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighState = 10029,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighState/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighState_Id = 10030,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighState/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighState_Name = 10031,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighState/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighState_Number = 10032,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighState_EffectiveDisplayName = 10033,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighState_TransitionTime = 10034,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighState_EffectiveTransitionTime = 10035,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighState/TrueState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighState_TrueState = 10036,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighState/FalseState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighState_FalseState = 10037,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowState = 10038,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowState/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowState_Id = 10039,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowState/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowState_Name = 10040,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowState/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowState_Number = 10041,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowState_EffectiveDisplayName = 10042,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowState_TransitionTime = 10043,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowState_EffectiveTransitionTime = 10044,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowState/TrueState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowState_TrueState = 10045,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowState/FalseState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowState_FalseState = 10046,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLowState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLowState = 10047,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLowState/Id.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLowState_Id = 10048,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLowState/Name.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLowState_Name = 10049,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLowState/Number.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLowState_Number = 10050,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLowState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLowState_EffectiveDisplayName = 10051,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLowState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLowState_TransitionTime = 10052,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLowState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLowState_EffectiveTransitionTime = 10053,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLowState/TrueState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLowState_TrueState = 10054,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLowState/FalseState.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLowState_FalseState = 10055,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighHighLimit.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighHighLimit = 10056,
	//! NodeId of the node NonExclusiveLimitAlarmType/HighLimit.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_HighLimit = 10057,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLimit.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLimit = 10058,
	//! NodeId of the node NonExclusiveLimitAlarmType/LowLowLimit.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_LowLowLimit = 10059,
	//! NodeId of the object type NonExclusiveLevelAlarmType.
	EnumNumericNodeId_NonExclusiveLevelAlarmType = 10060,
	//! NodeId of the node NonExclusiveLevelAlarmType/EventId.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EventId = 10061,
	//! NodeId of the node NonExclusiveLevelAlarmType/EventType.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EventType = 10062,
	//! NodeId of the node NonExclusiveLevelAlarmType/SourceNode.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SourceNode = 10063,
	//! NodeId of the node NonExclusiveLevelAlarmType/SourceName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SourceName = 10064,
	//! NodeId of the node NonExclusiveLevelAlarmType/Time.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Time = 10065,
	//! NodeId of the node NonExclusiveLevelAlarmType/ReceiveTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ReceiveTime = 10066,
	//! NodeId of the node NonExclusiveLevelAlarmType/LocalTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LocalTime = 10067,
	//! NodeId of the node NonExclusiveLevelAlarmType/Message.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Message = 10068,
	//! NodeId of the node NonExclusiveLevelAlarmType/Severity.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Severity = 10069,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConditionName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConditionName = 10070,
	//! NodeId of the node NonExclusiveLevelAlarmType/BranchId.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_BranchId = 10071,
	//! NodeId of the node NonExclusiveLevelAlarmType/Retain.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Retain = 10072,
	//! NodeId of the node NonExclusiveLevelAlarmType/EnabledState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EnabledState = 10073,
	//! NodeId of the node NonExclusiveLevelAlarmType/EnabledState/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EnabledState_Id = 10074,
	//! NodeId of the node NonExclusiveLevelAlarmType/EnabledState/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EnabledState_Name = 10075,
	//! NodeId of the node NonExclusiveLevelAlarmType/EnabledState/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EnabledState_Number = 10076,
	//! NodeId of the node NonExclusiveLevelAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EnabledState_EffectiveDisplayName = 10077,
	//! NodeId of the node NonExclusiveLevelAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EnabledState_TransitionTime = 10078,
	//! NodeId of the node NonExclusiveLevelAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EnabledState_EffectiveTransitionTime = 10079,
	//! NodeId of the node NonExclusiveLevelAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EnabledState_TrueState = 10080,
	//! NodeId of the node NonExclusiveLevelAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_EnabledState_FalseState = 10081,
	//! NodeId of the node NonExclusiveLevelAlarmType/Quality.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Quality = 10082,
	//! NodeId of the node NonExclusiveLevelAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Quality_SourceTimestamp = 10083,
	//! NodeId of the node NonExclusiveLevelAlarmType/LastSeverity.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LastSeverity = 10084,
	//! NodeId of the node NonExclusiveLevelAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LastSeverity_SourceTimestamp = 10085,
	//! NodeId of the node NonExclusiveLevelAlarmType/Comment.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Comment = 10086,
	//! NodeId of the node NonExclusiveLevelAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Comment_SourceTimestamp = 10087,
	//! NodeId of the node NonExclusiveLevelAlarmType/ClientUserId.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ClientUserId = 10088,
	//! NodeId of the node NonExclusiveLevelAlarmType/Enable.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Enable = 10089,
	//! NodeId of the node NonExclusiveLevelAlarmType/Disable.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Disable = 10090,
	//! NodeId of the node NonExclusiveLevelAlarmType/AddComment.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AddComment = 10091,
	//! NodeId of the node NonExclusiveLevelAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AddComment_InputArguments = 10092,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConditionRefresh.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConditionRefresh = 10093,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConditionRefresh_InputArguments = 10094,
	//! NodeId of the node NonExclusiveLevelAlarmType/AckedState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AckedState = 10095,
	//! NodeId of the node NonExclusiveLevelAlarmType/AckedState/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AckedState_Id = 10096,
	//! NodeId of the node NonExclusiveLevelAlarmType/AckedState/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AckedState_Name = 10097,
	//! NodeId of the node NonExclusiveLevelAlarmType/AckedState/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AckedState_Number = 10098,
	//! NodeId of the node NonExclusiveLevelAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AckedState_EffectiveDisplayName = 10099,
	//! NodeId of the node NonExclusiveLevelAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AckedState_TransitionTime = 10100,
	//! NodeId of the node NonExclusiveLevelAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AckedState_EffectiveTransitionTime = 10101,
	//! NodeId of the node NonExclusiveLevelAlarmType/AckedState/TrueState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AckedState_TrueState = 10102,
	//! NodeId of the node NonExclusiveLevelAlarmType/AckedState/FalseState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_AckedState_FalseState = 10103,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConfirmedState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConfirmedState = 10104,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConfirmedState_Id = 10105,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConfirmedState_Name = 10106,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConfirmedState_Number = 10107,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConfirmedState_EffectiveDisplayName = 10108,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConfirmedState_TransitionTime = 10109,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConfirmedState_EffectiveTransitionTime = 10110,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConfirmedState_TrueState = 10111,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConfirmedState_FalseState = 10112,
	//! NodeId of the node NonExclusiveLevelAlarmType/Acknowledge.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Acknowledge = 10113,
	//! NodeId of the node NonExclusiveLevelAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Acknowledge_InputArguments = 10114,
	//! NodeId of the node NonExclusiveLevelAlarmType/Confirm.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Confirm = 10115,
	//! NodeId of the node NonExclusiveLevelAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_Confirm_InputArguments = 10116,
	//! NodeId of the node NonExclusiveLevelAlarmType/ActiveState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ActiveState = 10117,
	//! NodeId of the node NonExclusiveLevelAlarmType/ActiveState/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ActiveState_Id = 10118,
	//! NodeId of the node NonExclusiveLevelAlarmType/ActiveState/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ActiveState_Name = 10119,
	//! NodeId of the node NonExclusiveLevelAlarmType/ActiveState/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ActiveState_Number = 10120,
	//! NodeId of the node NonExclusiveLevelAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ActiveState_EffectiveDisplayName = 10121,
	//! NodeId of the node NonExclusiveLevelAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ActiveState_TransitionTime = 10122,
	//! NodeId of the node NonExclusiveLevelAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ActiveState_EffectiveTransitionTime = 10123,
	//! NodeId of the node NonExclusiveLevelAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ActiveState_TrueState = 10124,
	//! NodeId of the node NonExclusiveLevelAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ActiveState_FalseState = 10125,
	//! NodeId of the node NonExclusiveLevelAlarmType/SuppressedState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SuppressedState = 10126,
	//! NodeId of the node NonExclusiveLevelAlarmType/SuppressedState/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SuppressedState_Id = 10127,
	//! NodeId of the node NonExclusiveLevelAlarmType/SuppressedState/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SuppressedState_Name = 10128,
	//! NodeId of the node NonExclusiveLevelAlarmType/SuppressedState/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SuppressedState_Number = 10129,
	//! NodeId of the node NonExclusiveLevelAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SuppressedState_EffectiveDisplayName = 10130,
	//! NodeId of the node NonExclusiveLevelAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SuppressedState_TransitionTime = 10131,
	//! NodeId of the node NonExclusiveLevelAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SuppressedState_EffectiveTransitionTime = 10132,
	//! NodeId of the node NonExclusiveLevelAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SuppressedState_TrueState = 10133,
	//! NodeId of the node NonExclusiveLevelAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SuppressedState_FalseState = 10134,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState = 10135,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_CurrentState = 10136,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_CurrentState_Id = 10137,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_CurrentState_Name = 10138,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_CurrentState_Number = 10139,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 10140,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_LastTransition = 10141,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_LastTransition_Id = 10142,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_LastTransition_Name = 10143,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_LastTransition_Number = 10144,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_LastTransition_TransitionTime = 10145,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_UnshelveTime = 10146,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_Unshelve = 10168,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_OneShotShelve = 10169,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_TimedShelve = 10170,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_TimedShelve_InputArguments = 10171,
	//! NodeId of the node NonExclusiveLevelAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_SuppressedOrShelved = 10172,
	//! NodeId of the node NonExclusiveLevelAlarmType/MaxTimeShelved.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_MaxTimeShelved = 10173,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighHighState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighHighState = 10174,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighHighState/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighHighState_Id = 10175,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighHighState/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighHighState_Name = 10176,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighHighState/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighHighState_Number = 10177,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighHighState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighHighState_EffectiveDisplayName = 10178,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighHighState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighHighState_TransitionTime = 10179,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighHighState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighHighState_EffectiveTransitionTime = 10180,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighHighState/TrueState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighHighState_TrueState = 10181,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighHighState/FalseState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighHighState_FalseState = 10182,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighState = 10183,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighState/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighState_Id = 10184,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighState/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighState_Name = 10185,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighState/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighState_Number = 10186,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighState_EffectiveDisplayName = 10187,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighState_TransitionTime = 10188,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighState_EffectiveTransitionTime = 10189,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighState/TrueState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighState_TrueState = 10190,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighState/FalseState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighState_FalseState = 10191,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowState = 10192,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowState/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowState_Id = 10193,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowState/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowState_Name = 10194,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowState/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowState_Number = 10195,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowState_EffectiveDisplayName = 10196,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowState_TransitionTime = 10197,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowState_EffectiveTransitionTime = 10198,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowState/TrueState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowState_TrueState = 10199,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowState/FalseState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowState_FalseState = 10200,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLowState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLowState = 10201,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLowState/Id.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLowState_Id = 10202,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLowState/Name.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLowState_Name = 10203,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLowState/Number.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLowState_Number = 10204,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLowState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLowState_EffectiveDisplayName = 10205,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLowState/TransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLowState_TransitionTime = 10206,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLowState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLowState_EffectiveTransitionTime = 10207,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLowState/TrueState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLowState_TrueState = 10208,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLowState/FalseState.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLowState_FalseState = 10209,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighHighLimit.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighHighLimit = 10210,
	//! NodeId of the node NonExclusiveLevelAlarmType/HighLimit.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_HighLimit = 10211,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLimit.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLimit = 10212,
	//! NodeId of the node NonExclusiveLevelAlarmType/LowLowLimit.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_LowLowLimit = 10213,
	//! NodeId of the object type NonExclusiveRateOfChangeAlarmType.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType = 10214,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EventId.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EventId = 10215,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EventType.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EventType = 10216,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SourceNode.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SourceNode = 10217,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SourceName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SourceName = 10218,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Time.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Time = 10219,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ReceiveTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ReceiveTime = 10220,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LocalTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LocalTime = 10221,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Message.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Message = 10222,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Severity.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Severity = 10223,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConditionName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConditionName = 10224,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/BranchId.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_BranchId = 10225,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Retain.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Retain = 10226,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EnabledState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EnabledState = 10227,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EnabledState/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EnabledState_Id = 10228,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EnabledState/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EnabledState_Name = 10229,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EnabledState/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EnabledState_Number = 10230,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EnabledState_EffectiveDisplayName = 10231,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EnabledState_TransitionTime = 10232,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EnabledState_EffectiveTransitionTime = 10233,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EnabledState_TrueState = 10234,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_EnabledState_FalseState = 10235,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Quality.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Quality = 10236,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Quality_SourceTimestamp = 10237,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LastSeverity.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LastSeverity = 10238,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LastSeverity_SourceTimestamp = 10239,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Comment.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Comment = 10240,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Comment_SourceTimestamp = 10241,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ClientUserId.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ClientUserId = 10242,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Enable.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Enable = 10243,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Disable.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Disable = 10244,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AddComment.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AddComment = 10245,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AddComment_InputArguments = 10246,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConditionRefresh.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConditionRefresh = 10247,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConditionRefresh_InputArguments = 10248,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AckedState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AckedState = 10249,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AckedState/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AckedState_Id = 10250,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AckedState/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AckedState_Name = 10251,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AckedState/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AckedState_Number = 10252,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AckedState_EffectiveDisplayName = 10253,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AckedState_TransitionTime = 10254,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AckedState_EffectiveTransitionTime = 10255,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AckedState/TrueState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AckedState_TrueState = 10256,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/AckedState/FalseState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_AckedState_FalseState = 10257,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConfirmedState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConfirmedState = 10258,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConfirmedState_Id = 10259,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConfirmedState_Name = 10260,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConfirmedState_Number = 10261,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConfirmedState_EffectiveDisplayName = 10262,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConfirmedState_TransitionTime = 10263,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConfirmedState_EffectiveTransitionTime = 10264,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConfirmedState_TrueState = 10265,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConfirmedState_FalseState = 10266,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Acknowledge.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Acknowledge = 10267,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Acknowledge_InputArguments = 10268,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Confirm.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Confirm = 10269,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_Confirm_InputArguments = 10270,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ActiveState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ActiveState = 10271,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ActiveState/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ActiveState_Id = 10272,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ActiveState/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ActiveState_Name = 10273,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ActiveState/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ActiveState_Number = 10274,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ActiveState_EffectiveDisplayName = 10275,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ActiveState_TransitionTime = 10276,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ActiveState_EffectiveTransitionTime = 10277,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ActiveState_TrueState = 10278,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ActiveState_FalseState = 10279,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SuppressedState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SuppressedState = 10280,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SuppressedState/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SuppressedState_Id = 10281,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SuppressedState/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SuppressedState_Name = 10282,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SuppressedState/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SuppressedState_Number = 10283,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SuppressedState_EffectiveDisplayName = 10284,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SuppressedState_TransitionTime = 10285,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SuppressedState_EffectiveTransitionTime = 10286,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SuppressedState_TrueState = 10287,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SuppressedState_FalseState = 10288,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState = 10289,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_CurrentState = 10290,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_CurrentState_Id = 10291,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_CurrentState_Name = 10292,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_CurrentState_Number = 10293,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 10294,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition = 10295,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition_Id = 10296,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition_Name = 10297,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition_Number = 10298,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition_TransitionTime = 10299,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_UnshelveTime = 10300,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_Unshelve = 10322,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_OneShotShelve = 10323,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_TimedShelve = 10324,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_TimedShelve_InputArguments = 10325,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_SuppressedOrShelved = 10326,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/MaxTimeShelved.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_MaxTimeShelved = 10327,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighHighState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighHighState = 10328,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighHighState/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighHighState_Id = 10329,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighHighState/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighHighState_Name = 10330,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighHighState/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighHighState_Number = 10331,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighHighState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighHighState_EffectiveDisplayName = 10332,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighHighState/TransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighHighState_TransitionTime = 10333,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighHighState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighHighState_EffectiveTransitionTime = 10334,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighHighState/TrueState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighHighState_TrueState = 10335,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighHighState/FalseState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighHighState_FalseState = 10336,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighState = 10337,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighState/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighState_Id = 10338,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighState/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighState_Name = 10339,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighState/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighState_Number = 10340,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighState_EffectiveDisplayName = 10341,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighState/TransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighState_TransitionTime = 10342,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighState_EffectiveTransitionTime = 10343,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighState/TrueState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighState_TrueState = 10344,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighState/FalseState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighState_FalseState = 10345,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowState = 10346,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowState/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowState_Id = 10347,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowState/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowState_Name = 10348,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowState/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowState_Number = 10349,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowState_EffectiveDisplayName = 10350,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowState/TransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowState_TransitionTime = 10351,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowState_EffectiveTransitionTime = 10352,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowState/TrueState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowState_TrueState = 10353,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowState/FalseState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowState_FalseState = 10354,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLowState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLowState = 10355,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLowState/Id.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLowState_Id = 10356,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLowState/Name.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLowState_Name = 10357,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLowState/Number.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLowState_Number = 10358,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLowState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLowState_EffectiveDisplayName = 10359,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLowState/TransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLowState_TransitionTime = 10360,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLowState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLowState_EffectiveTransitionTime = 10361,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLowState/TrueState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLowState_TrueState = 10362,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLowState/FalseState.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLowState_FalseState = 10363,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighHighLimit.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighHighLimit = 10364,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/HighLimit.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_HighLimit = 10365,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLimit.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLimit = 10366,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/LowLowLimit.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_LowLowLimit = 10367,
	//! NodeId of the object type NonExclusiveDeviationAlarmType.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType = 10368,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EventId.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EventId = 10369,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EventType.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EventType = 10370,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SourceNode.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SourceNode = 10371,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SourceName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SourceName = 10372,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Time.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Time = 10373,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ReceiveTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ReceiveTime = 10374,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LocalTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LocalTime = 10375,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Message.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Message = 10376,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Severity.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Severity = 10377,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConditionName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConditionName = 10378,
	//! NodeId of the node NonExclusiveDeviationAlarmType/BranchId.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_BranchId = 10379,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Retain.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Retain = 10380,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EnabledState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EnabledState = 10381,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EnabledState/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EnabledState_Id = 10382,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EnabledState/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EnabledState_Name = 10383,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EnabledState/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EnabledState_Number = 10384,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EnabledState_EffectiveDisplayName = 10385,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EnabledState_TransitionTime = 10386,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EnabledState_EffectiveTransitionTime = 10387,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EnabledState_TrueState = 10388,
	//! NodeId of the node NonExclusiveDeviationAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_EnabledState_FalseState = 10389,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Quality.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Quality = 10390,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Quality_SourceTimestamp = 10391,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LastSeverity.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LastSeverity = 10392,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LastSeverity_SourceTimestamp = 10393,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Comment.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Comment = 10394,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Comment_SourceTimestamp = 10395,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ClientUserId.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ClientUserId = 10396,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Enable.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Enable = 10397,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Disable.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Disable = 10398,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AddComment.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AddComment = 10399,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AddComment_InputArguments = 10400,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConditionRefresh.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConditionRefresh = 10401,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConditionRefresh_InputArguments = 10402,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AckedState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AckedState = 10403,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AckedState/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AckedState_Id = 10404,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AckedState/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AckedState_Name = 10405,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AckedState/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AckedState_Number = 10406,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AckedState_EffectiveDisplayName = 10407,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AckedState_TransitionTime = 10408,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AckedState_EffectiveTransitionTime = 10409,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AckedState/TrueState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AckedState_TrueState = 10410,
	//! NodeId of the node NonExclusiveDeviationAlarmType/AckedState/FalseState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_AckedState_FalseState = 10411,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConfirmedState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConfirmedState = 10412,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConfirmedState_Id = 10413,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConfirmedState_Name = 10414,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConfirmedState_Number = 10415,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConfirmedState_EffectiveDisplayName = 10416,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConfirmedState_TransitionTime = 10417,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConfirmedState_EffectiveTransitionTime = 10418,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConfirmedState_TrueState = 10419,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConfirmedState_FalseState = 10420,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Acknowledge.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Acknowledge = 10421,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Acknowledge_InputArguments = 10422,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Confirm.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Confirm = 10423,
	//! NodeId of the node NonExclusiveDeviationAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_Confirm_InputArguments = 10424,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ActiveState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ActiveState = 10425,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ActiveState/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ActiveState_Id = 10426,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ActiveState/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ActiveState_Name = 10427,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ActiveState/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ActiveState_Number = 10428,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ActiveState_EffectiveDisplayName = 10429,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ActiveState_TransitionTime = 10430,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ActiveState_EffectiveTransitionTime = 10431,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ActiveState_TrueState = 10432,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ActiveState_FalseState = 10433,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SuppressedState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SuppressedState = 10434,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SuppressedState/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SuppressedState_Id = 10435,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SuppressedState/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SuppressedState_Name = 10436,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SuppressedState/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SuppressedState_Number = 10437,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SuppressedState_EffectiveDisplayName = 10438,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SuppressedState_TransitionTime = 10439,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SuppressedState_EffectiveTransitionTime = 10440,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SuppressedState_TrueState = 10441,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SuppressedState_FalseState = 10442,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState = 10443,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_CurrentState = 10444,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_CurrentState_Id = 10445,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_CurrentState_Name = 10446,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_CurrentState_Number = 10447,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 10448,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_LastTransition = 10449,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_LastTransition_Id = 10450,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_LastTransition_Name = 10451,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_LastTransition_Number = 10452,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_LastTransition_TransitionTime = 10453,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_UnshelveTime = 10454,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_Unshelve = 10476,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_OneShotShelve = 10477,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_TimedShelve = 10478,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_TimedShelve_InputArguments = 10479,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SuppressedOrShelved = 10480,
	//! NodeId of the node NonExclusiveDeviationAlarmType/MaxTimeShelved.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_MaxTimeShelved = 10481,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighHighState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighHighState = 10482,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighHighState/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighHighState_Id = 10483,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighHighState/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighHighState_Name = 10484,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighHighState/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighHighState_Number = 10485,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighHighState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighHighState_EffectiveDisplayName = 10486,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighHighState/TransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighHighState_TransitionTime = 10487,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighHighState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighHighState_EffectiveTransitionTime = 10488,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighHighState/TrueState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighHighState_TrueState = 10489,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighHighState/FalseState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighHighState_FalseState = 10490,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighState = 10491,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighState/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighState_Id = 10492,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighState/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighState_Name = 10493,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighState/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighState_Number = 10494,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighState_EffectiveDisplayName = 10495,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighState/TransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighState_TransitionTime = 10496,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighState_EffectiveTransitionTime = 10497,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighState/TrueState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighState_TrueState = 10498,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighState/FalseState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighState_FalseState = 10499,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowState = 10500,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowState/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowState_Id = 10501,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowState/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowState_Name = 10502,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowState/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowState_Number = 10503,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowState_EffectiveDisplayName = 10504,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowState/TransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowState_TransitionTime = 10505,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowState_EffectiveTransitionTime = 10506,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowState/TrueState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowState_TrueState = 10507,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowState/FalseState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowState_FalseState = 10508,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLowState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLowState = 10509,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLowState/Id.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLowState_Id = 10510,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLowState/Name.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLowState_Name = 10511,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLowState/Number.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLowState_Number = 10512,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLowState/EffectiveDisplayName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLowState_EffectiveDisplayName = 10513,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLowState/TransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLowState_TransitionTime = 10514,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLowState/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLowState_EffectiveTransitionTime = 10515,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLowState/TrueState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLowState_TrueState = 10516,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLowState/FalseState.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLowState_FalseState = 10517,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighHighLimit.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighHighLimit = 10518,
	//! NodeId of the node NonExclusiveDeviationAlarmType/HighLimit.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_HighLimit = 10519,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLimit.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLimit = 10520,
	//! NodeId of the node NonExclusiveDeviationAlarmType/LowLowLimit.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_LowLowLimit = 10521,
	//! NodeId of the node NonExclusiveDeviationAlarmType/SetpointNode.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_SetpointNode = 10522,
	//! NodeId of the object type DiscreteAlarmType.
	EnumNumericNodeId_DiscreteAlarmType = 10523,
	//! NodeId of the node DiscreteAlarmType/EventId.
	EnumNumericNodeId_DiscreteAlarmType_EventId = 10524,
	//! NodeId of the node DiscreteAlarmType/EventType.
	EnumNumericNodeId_DiscreteAlarmType_EventType = 10525,
	//! NodeId of the node DiscreteAlarmType/SourceNode.
	EnumNumericNodeId_DiscreteAlarmType_SourceNode = 10526,
	//! NodeId of the node DiscreteAlarmType/SourceName.
	EnumNumericNodeId_DiscreteAlarmType_SourceName = 10527,
	//! NodeId of the node DiscreteAlarmType/Time.
	EnumNumericNodeId_DiscreteAlarmType_Time = 10528,
	//! NodeId of the node DiscreteAlarmType/ReceiveTime.
	EnumNumericNodeId_DiscreteAlarmType_ReceiveTime = 10529,
	//! NodeId of the node DiscreteAlarmType/LocalTime.
	EnumNumericNodeId_DiscreteAlarmType_LocalTime = 10530,
	//! NodeId of the node DiscreteAlarmType/Message.
	EnumNumericNodeId_DiscreteAlarmType_Message = 10531,
	//! NodeId of the node DiscreteAlarmType/Severity.
	EnumNumericNodeId_DiscreteAlarmType_Severity = 10532,
	//! NodeId of the node DiscreteAlarmType/ConditionName.
	EnumNumericNodeId_DiscreteAlarmType_ConditionName = 10533,
	//! NodeId of the node DiscreteAlarmType/BranchId.
	EnumNumericNodeId_DiscreteAlarmType_BranchId = 10534,
	//! NodeId of the node DiscreteAlarmType/Retain.
	EnumNumericNodeId_DiscreteAlarmType_Retain = 10535,
	//! NodeId of the node DiscreteAlarmType/EnabledState.
	EnumNumericNodeId_DiscreteAlarmType_EnabledState = 10536,
	//! NodeId of the node DiscreteAlarmType/EnabledState/Id.
	EnumNumericNodeId_DiscreteAlarmType_EnabledState_Id = 10537,
	//! NodeId of the node DiscreteAlarmType/EnabledState/Name.
	EnumNumericNodeId_DiscreteAlarmType_EnabledState_Name = 10538,
	//! NodeId of the node DiscreteAlarmType/EnabledState/Number.
	EnumNumericNodeId_DiscreteAlarmType_EnabledState_Number = 10539,
	//! NodeId of the node DiscreteAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_DiscreteAlarmType_EnabledState_EffectiveDisplayName = 10540,
	//! NodeId of the node DiscreteAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_EnabledState_TransitionTime = 10541,
	//! NodeId of the node DiscreteAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_EnabledState_EffectiveTransitionTime = 10542,
	//! NodeId of the node DiscreteAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_DiscreteAlarmType_EnabledState_TrueState = 10543,
	//! NodeId of the node DiscreteAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_DiscreteAlarmType_EnabledState_FalseState = 10544,
	//! NodeId of the node DiscreteAlarmType/Quality.
	EnumNumericNodeId_DiscreteAlarmType_Quality = 10545,
	//! NodeId of the node DiscreteAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_DiscreteAlarmType_Quality_SourceTimestamp = 10546,
	//! NodeId of the node DiscreteAlarmType/LastSeverity.
	EnumNumericNodeId_DiscreteAlarmType_LastSeverity = 10547,
	//! NodeId of the node DiscreteAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_DiscreteAlarmType_LastSeverity_SourceTimestamp = 10548,
	//! NodeId of the node DiscreteAlarmType/Comment.
	EnumNumericNodeId_DiscreteAlarmType_Comment = 10549,
	//! NodeId of the node DiscreteAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_DiscreteAlarmType_Comment_SourceTimestamp = 10550,
	//! NodeId of the node DiscreteAlarmType/ClientUserId.
	EnumNumericNodeId_DiscreteAlarmType_ClientUserId = 10551,
	//! NodeId of the node DiscreteAlarmType/Enable.
	EnumNumericNodeId_DiscreteAlarmType_Enable = 10552,
	//! NodeId of the node DiscreteAlarmType/Disable.
	EnumNumericNodeId_DiscreteAlarmType_Disable = 10553,
	//! NodeId of the node DiscreteAlarmType/AddComment.
	EnumNumericNodeId_DiscreteAlarmType_AddComment = 10554,
	//! NodeId of the node DiscreteAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_DiscreteAlarmType_AddComment_InputArguments = 10555,
	//! NodeId of the node DiscreteAlarmType/ConditionRefresh.
	EnumNumericNodeId_DiscreteAlarmType_ConditionRefresh = 10556,
	//! NodeId of the node DiscreteAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_DiscreteAlarmType_ConditionRefresh_InputArguments = 10557,
	//! NodeId of the node DiscreteAlarmType/AckedState.
	EnumNumericNodeId_DiscreteAlarmType_AckedState = 10558,
	//! NodeId of the node DiscreteAlarmType/AckedState/Id.
	EnumNumericNodeId_DiscreteAlarmType_AckedState_Id = 10559,
	//! NodeId of the node DiscreteAlarmType/AckedState/Name.
	EnumNumericNodeId_DiscreteAlarmType_AckedState_Name = 10560,
	//! NodeId of the node DiscreteAlarmType/AckedState/Number.
	EnumNumericNodeId_DiscreteAlarmType_AckedState_Number = 10561,
	//! NodeId of the node DiscreteAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_DiscreteAlarmType_AckedState_EffectiveDisplayName = 10562,
	//! NodeId of the node DiscreteAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_AckedState_TransitionTime = 10563,
	//! NodeId of the node DiscreteAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_AckedState_EffectiveTransitionTime = 10564,
	//! NodeId of the node DiscreteAlarmType/AckedState/TrueState.
	EnumNumericNodeId_DiscreteAlarmType_AckedState_TrueState = 10565,
	//! NodeId of the node DiscreteAlarmType/AckedState/FalseState.
	EnumNumericNodeId_DiscreteAlarmType_AckedState_FalseState = 10566,
	//! NodeId of the node DiscreteAlarmType/ConfirmedState.
	EnumNumericNodeId_DiscreteAlarmType_ConfirmedState = 10567,
	//! NodeId of the node DiscreteAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_DiscreteAlarmType_ConfirmedState_Id = 10568,
	//! NodeId of the node DiscreteAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_DiscreteAlarmType_ConfirmedState_Name = 10569,
	//! NodeId of the node DiscreteAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_DiscreteAlarmType_ConfirmedState_Number = 10570,
	//! NodeId of the node DiscreteAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_DiscreteAlarmType_ConfirmedState_EffectiveDisplayName = 10571,
	//! NodeId of the node DiscreteAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_ConfirmedState_TransitionTime = 10572,
	//! NodeId of the node DiscreteAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_ConfirmedState_EffectiveTransitionTime = 10573,
	//! NodeId of the node DiscreteAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_DiscreteAlarmType_ConfirmedState_TrueState = 10574,
	//! NodeId of the node DiscreteAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_DiscreteAlarmType_ConfirmedState_FalseState = 10575,
	//! NodeId of the node DiscreteAlarmType/Acknowledge.
	EnumNumericNodeId_DiscreteAlarmType_Acknowledge = 10576,
	//! NodeId of the node DiscreteAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_DiscreteAlarmType_Acknowledge_InputArguments = 10577,
	//! NodeId of the node DiscreteAlarmType/Confirm.
	EnumNumericNodeId_DiscreteAlarmType_Confirm = 10578,
	//! NodeId of the node DiscreteAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_DiscreteAlarmType_Confirm_InputArguments = 10579,
	//! NodeId of the node DiscreteAlarmType/ActiveState.
	EnumNumericNodeId_DiscreteAlarmType_ActiveState = 10580,
	//! NodeId of the node DiscreteAlarmType/ActiveState/Id.
	EnumNumericNodeId_DiscreteAlarmType_ActiveState_Id = 10581,
	//! NodeId of the node DiscreteAlarmType/ActiveState/Name.
	EnumNumericNodeId_DiscreteAlarmType_ActiveState_Name = 10582,
	//! NodeId of the node DiscreteAlarmType/ActiveState/Number.
	EnumNumericNodeId_DiscreteAlarmType_ActiveState_Number = 10583,
	//! NodeId of the node DiscreteAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_DiscreteAlarmType_ActiveState_EffectiveDisplayName = 10584,
	//! NodeId of the node DiscreteAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_ActiveState_TransitionTime = 10585,
	//! NodeId of the node DiscreteAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_ActiveState_EffectiveTransitionTime = 10586,
	//! NodeId of the node DiscreteAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_DiscreteAlarmType_ActiveState_TrueState = 10587,
	//! NodeId of the node DiscreteAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_DiscreteAlarmType_ActiveState_FalseState = 10588,
	//! NodeId of the node DiscreteAlarmType/SuppressedState.
	EnumNumericNodeId_DiscreteAlarmType_SuppressedState = 10589,
	//! NodeId of the node DiscreteAlarmType/SuppressedState/Id.
	EnumNumericNodeId_DiscreteAlarmType_SuppressedState_Id = 10590,
	//! NodeId of the node DiscreteAlarmType/SuppressedState/Name.
	EnumNumericNodeId_DiscreteAlarmType_SuppressedState_Name = 10591,
	//! NodeId of the node DiscreteAlarmType/SuppressedState/Number.
	EnumNumericNodeId_DiscreteAlarmType_SuppressedState_Number = 10592,
	//! NodeId of the node DiscreteAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_DiscreteAlarmType_SuppressedState_EffectiveDisplayName = 10593,
	//! NodeId of the node DiscreteAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_SuppressedState_TransitionTime = 10594,
	//! NodeId of the node DiscreteAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_SuppressedState_EffectiveTransitionTime = 10595,
	//! NodeId of the node DiscreteAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_DiscreteAlarmType_SuppressedState_TrueState = 10596,
	//! NodeId of the node DiscreteAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_DiscreteAlarmType_SuppressedState_FalseState = 10597,
	//! NodeId of the node DiscreteAlarmType/ShelvingState.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState = 10598,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_CurrentState = 10599,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_CurrentState_Id = 10600,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_CurrentState_Name = 10601,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_CurrentState_Number = 10602,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 10603,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_LastTransition = 10604,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_LastTransition_Id = 10605,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_LastTransition_Name = 10606,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_LastTransition_Number = 10607,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_LastTransition_TransitionTime = 10608,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_UnshelveTime = 10609,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_Unshelve = 10631,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_OneShotShelve = 10632,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_TimedShelve = 10633,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_TimedShelve_InputArguments = 10634,
	//! NodeId of the node DiscreteAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_DiscreteAlarmType_SuppressedOrShelved = 10635,
	//! NodeId of the node DiscreteAlarmType/MaxTimeShelved.
	EnumNumericNodeId_DiscreteAlarmType_MaxTimeShelved = 10636,
	//! NodeId of the object type OffNormalAlarmType.
	EnumNumericNodeId_OffNormalAlarmType = 10637,
	//! NodeId of the node OffNormalAlarmType/EventId.
	EnumNumericNodeId_OffNormalAlarmType_EventId = 10638,
	//! NodeId of the node OffNormalAlarmType/EventType.
	EnumNumericNodeId_OffNormalAlarmType_EventType = 10639,
	//! NodeId of the node OffNormalAlarmType/SourceNode.
	EnumNumericNodeId_OffNormalAlarmType_SourceNode = 10640,
	//! NodeId of the node OffNormalAlarmType/SourceName.
	EnumNumericNodeId_OffNormalAlarmType_SourceName = 10641,
	//! NodeId of the node OffNormalAlarmType/Time.
	EnumNumericNodeId_OffNormalAlarmType_Time = 10642,
	//! NodeId of the node OffNormalAlarmType/ReceiveTime.
	EnumNumericNodeId_OffNormalAlarmType_ReceiveTime = 10643,
	//! NodeId of the node OffNormalAlarmType/LocalTime.
	EnumNumericNodeId_OffNormalAlarmType_LocalTime = 10644,
	//! NodeId of the node OffNormalAlarmType/Message.
	EnumNumericNodeId_OffNormalAlarmType_Message = 10645,
	//! NodeId of the node OffNormalAlarmType/Severity.
	EnumNumericNodeId_OffNormalAlarmType_Severity = 10646,
	//! NodeId of the node OffNormalAlarmType/ConditionName.
	EnumNumericNodeId_OffNormalAlarmType_ConditionName = 10647,
	//! NodeId of the node OffNormalAlarmType/BranchId.
	EnumNumericNodeId_OffNormalAlarmType_BranchId = 10648,
	//! NodeId of the node OffNormalAlarmType/Retain.
	EnumNumericNodeId_OffNormalAlarmType_Retain = 10649,
	//! NodeId of the node OffNormalAlarmType/EnabledState.
	EnumNumericNodeId_OffNormalAlarmType_EnabledState = 10650,
	//! NodeId of the node OffNormalAlarmType/EnabledState/Id.
	EnumNumericNodeId_OffNormalAlarmType_EnabledState_Id = 10651,
	//! NodeId of the node OffNormalAlarmType/EnabledState/Name.
	EnumNumericNodeId_OffNormalAlarmType_EnabledState_Name = 10652,
	//! NodeId of the node OffNormalAlarmType/EnabledState/Number.
	EnumNumericNodeId_OffNormalAlarmType_EnabledState_Number = 10653,
	//! NodeId of the node OffNormalAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_OffNormalAlarmType_EnabledState_EffectiveDisplayName = 10654,
	//! NodeId of the node OffNormalAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_EnabledState_TransitionTime = 10655,
	//! NodeId of the node OffNormalAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_EnabledState_EffectiveTransitionTime = 10656,
	//! NodeId of the node OffNormalAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_OffNormalAlarmType_EnabledState_TrueState = 10657,
	//! NodeId of the node OffNormalAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_OffNormalAlarmType_EnabledState_FalseState = 10658,
	//! NodeId of the node OffNormalAlarmType/Quality.
	EnumNumericNodeId_OffNormalAlarmType_Quality = 10659,
	//! NodeId of the node OffNormalAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_OffNormalAlarmType_Quality_SourceTimestamp = 10660,
	//! NodeId of the node OffNormalAlarmType/LastSeverity.
	EnumNumericNodeId_OffNormalAlarmType_LastSeverity = 10661,
	//! NodeId of the node OffNormalAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_OffNormalAlarmType_LastSeverity_SourceTimestamp = 10662,
	//! NodeId of the node OffNormalAlarmType/Comment.
	EnumNumericNodeId_OffNormalAlarmType_Comment = 10663,
	//! NodeId of the node OffNormalAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_OffNormalAlarmType_Comment_SourceTimestamp = 10664,
	//! NodeId of the node OffNormalAlarmType/ClientUserId.
	EnumNumericNodeId_OffNormalAlarmType_ClientUserId = 10665,
	//! NodeId of the node OffNormalAlarmType/Enable.
	EnumNumericNodeId_OffNormalAlarmType_Enable = 10666,
	//! NodeId of the node OffNormalAlarmType/Disable.
	EnumNumericNodeId_OffNormalAlarmType_Disable = 10667,
	//! NodeId of the node OffNormalAlarmType/AddComment.
	EnumNumericNodeId_OffNormalAlarmType_AddComment = 10668,
	//! NodeId of the node OffNormalAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_OffNormalAlarmType_AddComment_InputArguments = 10669,
	//! NodeId of the node OffNormalAlarmType/ConditionRefresh.
	EnumNumericNodeId_OffNormalAlarmType_ConditionRefresh = 10670,
	//! NodeId of the node OffNormalAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_OffNormalAlarmType_ConditionRefresh_InputArguments = 10671,
	//! NodeId of the node OffNormalAlarmType/AckedState.
	EnumNumericNodeId_OffNormalAlarmType_AckedState = 10672,
	//! NodeId of the node OffNormalAlarmType/AckedState/Id.
	EnumNumericNodeId_OffNormalAlarmType_AckedState_Id = 10673,
	//! NodeId of the node OffNormalAlarmType/AckedState/Name.
	EnumNumericNodeId_OffNormalAlarmType_AckedState_Name = 10674,
	//! NodeId of the node OffNormalAlarmType/AckedState/Number.
	EnumNumericNodeId_OffNormalAlarmType_AckedState_Number = 10675,
	//! NodeId of the node OffNormalAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_OffNormalAlarmType_AckedState_EffectiveDisplayName = 10676,
	//! NodeId of the node OffNormalAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_AckedState_TransitionTime = 10677,
	//! NodeId of the node OffNormalAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_AckedState_EffectiveTransitionTime = 10678,
	//! NodeId of the node OffNormalAlarmType/AckedState/TrueState.
	EnumNumericNodeId_OffNormalAlarmType_AckedState_TrueState = 10679,
	//! NodeId of the node OffNormalAlarmType/AckedState/FalseState.
	EnumNumericNodeId_OffNormalAlarmType_AckedState_FalseState = 10680,
	//! NodeId of the node OffNormalAlarmType/ConfirmedState.
	EnumNumericNodeId_OffNormalAlarmType_ConfirmedState = 10681,
	//! NodeId of the node OffNormalAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_OffNormalAlarmType_ConfirmedState_Id = 10682,
	//! NodeId of the node OffNormalAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_OffNormalAlarmType_ConfirmedState_Name = 10683,
	//! NodeId of the node OffNormalAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_OffNormalAlarmType_ConfirmedState_Number = 10684,
	//! NodeId of the node OffNormalAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_OffNormalAlarmType_ConfirmedState_EffectiveDisplayName = 10685,
	//! NodeId of the node OffNormalAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_ConfirmedState_TransitionTime = 10686,
	//! NodeId of the node OffNormalAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_ConfirmedState_EffectiveTransitionTime = 10687,
	//! NodeId of the node OffNormalAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_OffNormalAlarmType_ConfirmedState_TrueState = 10688,
	//! NodeId of the node OffNormalAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_OffNormalAlarmType_ConfirmedState_FalseState = 10689,
	//! NodeId of the node OffNormalAlarmType/Acknowledge.
	EnumNumericNodeId_OffNormalAlarmType_Acknowledge = 10690,
	//! NodeId of the node OffNormalAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_OffNormalAlarmType_Acknowledge_InputArguments = 10691,
	//! NodeId of the node OffNormalAlarmType/Confirm.
	EnumNumericNodeId_OffNormalAlarmType_Confirm = 10692,
	//! NodeId of the node OffNormalAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_OffNormalAlarmType_Confirm_InputArguments = 10693,
	//! NodeId of the node OffNormalAlarmType/ActiveState.
	EnumNumericNodeId_OffNormalAlarmType_ActiveState = 10694,
	//! NodeId of the node OffNormalAlarmType/ActiveState/Id.
	EnumNumericNodeId_OffNormalAlarmType_ActiveState_Id = 10695,
	//! NodeId of the node OffNormalAlarmType/ActiveState/Name.
	EnumNumericNodeId_OffNormalAlarmType_ActiveState_Name = 10696,
	//! NodeId of the node OffNormalAlarmType/ActiveState/Number.
	EnumNumericNodeId_OffNormalAlarmType_ActiveState_Number = 10697,
	//! NodeId of the node OffNormalAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_OffNormalAlarmType_ActiveState_EffectiveDisplayName = 10698,
	//! NodeId of the node OffNormalAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_ActiveState_TransitionTime = 10699,
	//! NodeId of the node OffNormalAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_ActiveState_EffectiveTransitionTime = 10700,
	//! NodeId of the node OffNormalAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_OffNormalAlarmType_ActiveState_TrueState = 10701,
	//! NodeId of the node OffNormalAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_OffNormalAlarmType_ActiveState_FalseState = 10702,
	//! NodeId of the node OffNormalAlarmType/SuppressedState.
	EnumNumericNodeId_OffNormalAlarmType_SuppressedState = 10703,
	//! NodeId of the node OffNormalAlarmType/SuppressedState/Id.
	EnumNumericNodeId_OffNormalAlarmType_SuppressedState_Id = 10704,
	//! NodeId of the node OffNormalAlarmType/SuppressedState/Name.
	EnumNumericNodeId_OffNormalAlarmType_SuppressedState_Name = 10705,
	//! NodeId of the node OffNormalAlarmType/SuppressedState/Number.
	EnumNumericNodeId_OffNormalAlarmType_SuppressedState_Number = 10706,
	//! NodeId of the node OffNormalAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_OffNormalAlarmType_SuppressedState_EffectiveDisplayName = 10707,
	//! NodeId of the node OffNormalAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_SuppressedState_TransitionTime = 10708,
	//! NodeId of the node OffNormalAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_SuppressedState_EffectiveTransitionTime = 10709,
	//! NodeId of the node OffNormalAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_OffNormalAlarmType_SuppressedState_TrueState = 10710,
	//! NodeId of the node OffNormalAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_OffNormalAlarmType_SuppressedState_FalseState = 10711,
	//! NodeId of the node OffNormalAlarmType/ShelvingState.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState = 10712,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_CurrentState = 10713,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_CurrentState_Id = 10714,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_CurrentState_Name = 10715,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_CurrentState_Number = 10716,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 10717,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_LastTransition = 10718,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_LastTransition_Id = 10719,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_LastTransition_Name = 10720,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_LastTransition_Number = 10721,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_LastTransition_TransitionTime = 10722,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_UnshelveTime = 10723,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_Unshelve = 10745,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_OneShotShelve = 10746,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_TimedShelve = 10747,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_TimedShelve_InputArguments = 10748,
	//! NodeId of the node OffNormalAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_OffNormalAlarmType_SuppressedOrShelved = 10749,
	//! NodeId of the node OffNormalAlarmType/MaxTimeShelved.
	EnumNumericNodeId_OffNormalAlarmType_MaxTimeShelved = 10750,
	//! NodeId of the object type TripAlarmType.
	EnumNumericNodeId_TripAlarmType = 10751,
	//! NodeId of the node TripAlarmType/EventId.
	EnumNumericNodeId_TripAlarmType_EventId = 10752,
	//! NodeId of the node TripAlarmType/EventType.
	EnumNumericNodeId_TripAlarmType_EventType = 10753,
	//! NodeId of the node TripAlarmType/SourceNode.
	EnumNumericNodeId_TripAlarmType_SourceNode = 10754,
	//! NodeId of the node TripAlarmType/SourceName.
	EnumNumericNodeId_TripAlarmType_SourceName = 10755,
	//! NodeId of the node TripAlarmType/Time.
	EnumNumericNodeId_TripAlarmType_Time = 10756,
	//! NodeId of the node TripAlarmType/ReceiveTime.
	EnumNumericNodeId_TripAlarmType_ReceiveTime = 10757,
	//! NodeId of the node TripAlarmType/LocalTime.
	EnumNumericNodeId_TripAlarmType_LocalTime = 10758,
	//! NodeId of the node TripAlarmType/Message.
	EnumNumericNodeId_TripAlarmType_Message = 10759,
	//! NodeId of the node TripAlarmType/Severity.
	EnumNumericNodeId_TripAlarmType_Severity = 10760,
	//! NodeId of the node TripAlarmType/ConditionName.
	EnumNumericNodeId_TripAlarmType_ConditionName = 10761,
	//! NodeId of the node TripAlarmType/BranchId.
	EnumNumericNodeId_TripAlarmType_BranchId = 10762,
	//! NodeId of the node TripAlarmType/Retain.
	EnumNumericNodeId_TripAlarmType_Retain = 10763,
	//! NodeId of the node TripAlarmType/EnabledState.
	EnumNumericNodeId_TripAlarmType_EnabledState = 10764,
	//! NodeId of the node TripAlarmType/EnabledState/Id.
	EnumNumericNodeId_TripAlarmType_EnabledState_Id = 10765,
	//! NodeId of the node TripAlarmType/EnabledState/Name.
	EnumNumericNodeId_TripAlarmType_EnabledState_Name = 10766,
	//! NodeId of the node TripAlarmType/EnabledState/Number.
	EnumNumericNodeId_TripAlarmType_EnabledState_Number = 10767,
	//! NodeId of the node TripAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_TripAlarmType_EnabledState_EffectiveDisplayName = 10768,
	//! NodeId of the node TripAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_TripAlarmType_EnabledState_TransitionTime = 10769,
	//! NodeId of the node TripAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_TripAlarmType_EnabledState_EffectiveTransitionTime = 10770,
	//! NodeId of the node TripAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_TripAlarmType_EnabledState_TrueState = 10771,
	//! NodeId of the node TripAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_TripAlarmType_EnabledState_FalseState = 10772,
	//! NodeId of the node TripAlarmType/Quality.
	EnumNumericNodeId_TripAlarmType_Quality = 10773,
	//! NodeId of the node TripAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_TripAlarmType_Quality_SourceTimestamp = 10774,
	//! NodeId of the node TripAlarmType/LastSeverity.
	EnumNumericNodeId_TripAlarmType_LastSeverity = 10775,
	//! NodeId of the node TripAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_TripAlarmType_LastSeverity_SourceTimestamp = 10776,
	//! NodeId of the node TripAlarmType/Comment.
	EnumNumericNodeId_TripAlarmType_Comment = 10777,
	//! NodeId of the node TripAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_TripAlarmType_Comment_SourceTimestamp = 10778,
	//! NodeId of the node TripAlarmType/ClientUserId.
	EnumNumericNodeId_TripAlarmType_ClientUserId = 10779,
	//! NodeId of the node TripAlarmType/Enable.
	EnumNumericNodeId_TripAlarmType_Enable = 10780,
	//! NodeId of the node TripAlarmType/Disable.
	EnumNumericNodeId_TripAlarmType_Disable = 10781,
	//! NodeId of the node TripAlarmType/AddComment.
	EnumNumericNodeId_TripAlarmType_AddComment = 10782,
	//! NodeId of the node TripAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_TripAlarmType_AddComment_InputArguments = 10783,
	//! NodeId of the node TripAlarmType/ConditionRefresh.
	EnumNumericNodeId_TripAlarmType_ConditionRefresh = 10784,
	//! NodeId of the node TripAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_TripAlarmType_ConditionRefresh_InputArguments = 10785,
	//! NodeId of the node TripAlarmType/AckedState.
	EnumNumericNodeId_TripAlarmType_AckedState = 10786,
	//! NodeId of the node TripAlarmType/AckedState/Id.
	EnumNumericNodeId_TripAlarmType_AckedState_Id = 10787,
	//! NodeId of the node TripAlarmType/AckedState/Name.
	EnumNumericNodeId_TripAlarmType_AckedState_Name = 10788,
	//! NodeId of the node TripAlarmType/AckedState/Number.
	EnumNumericNodeId_TripAlarmType_AckedState_Number = 10789,
	//! NodeId of the node TripAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_TripAlarmType_AckedState_EffectiveDisplayName = 10790,
	//! NodeId of the node TripAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_TripAlarmType_AckedState_TransitionTime = 10791,
	//! NodeId of the node TripAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_TripAlarmType_AckedState_EffectiveTransitionTime = 10792,
	//! NodeId of the node TripAlarmType/AckedState/TrueState.
	EnumNumericNodeId_TripAlarmType_AckedState_TrueState = 10793,
	//! NodeId of the node TripAlarmType/AckedState/FalseState.
	EnumNumericNodeId_TripAlarmType_AckedState_FalseState = 10794,
	//! NodeId of the node TripAlarmType/ConfirmedState.
	EnumNumericNodeId_TripAlarmType_ConfirmedState = 10795,
	//! NodeId of the node TripAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_TripAlarmType_ConfirmedState_Id = 10796,
	//! NodeId of the node TripAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_TripAlarmType_ConfirmedState_Name = 10797,
	//! NodeId of the node TripAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_TripAlarmType_ConfirmedState_Number = 10798,
	//! NodeId of the node TripAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_TripAlarmType_ConfirmedState_EffectiveDisplayName = 10799,
	//! NodeId of the node TripAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_TripAlarmType_ConfirmedState_TransitionTime = 10800,
	//! NodeId of the node TripAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_TripAlarmType_ConfirmedState_EffectiveTransitionTime = 10801,
	//! NodeId of the node TripAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_TripAlarmType_ConfirmedState_TrueState = 10802,
	//! NodeId of the node TripAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_TripAlarmType_ConfirmedState_FalseState = 10803,
	//! NodeId of the node TripAlarmType/Acknowledge.
	EnumNumericNodeId_TripAlarmType_Acknowledge = 10804,
	//! NodeId of the node TripAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_TripAlarmType_Acknowledge_InputArguments = 10805,
	//! NodeId of the node TripAlarmType/Confirm.
	EnumNumericNodeId_TripAlarmType_Confirm = 10806,
	//! NodeId of the node TripAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_TripAlarmType_Confirm_InputArguments = 10807,
	//! NodeId of the node TripAlarmType/ActiveState.
	EnumNumericNodeId_TripAlarmType_ActiveState = 10808,
	//! NodeId of the node TripAlarmType/ActiveState/Id.
	EnumNumericNodeId_TripAlarmType_ActiveState_Id = 10809,
	//! NodeId of the node TripAlarmType/ActiveState/Name.
	EnumNumericNodeId_TripAlarmType_ActiveState_Name = 10810,
	//! NodeId of the node TripAlarmType/ActiveState/Number.
	EnumNumericNodeId_TripAlarmType_ActiveState_Number = 10811,
	//! NodeId of the node TripAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_TripAlarmType_ActiveState_EffectiveDisplayName = 10812,
	//! NodeId of the node TripAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_TripAlarmType_ActiveState_TransitionTime = 10813,
	//! NodeId of the node TripAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_TripAlarmType_ActiveState_EffectiveTransitionTime = 10814,
	//! NodeId of the node TripAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_TripAlarmType_ActiveState_TrueState = 10815,
	//! NodeId of the node TripAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_TripAlarmType_ActiveState_FalseState = 10816,
	//! NodeId of the node TripAlarmType/SuppressedState.
	EnumNumericNodeId_TripAlarmType_SuppressedState = 10817,
	//! NodeId of the node TripAlarmType/SuppressedState/Id.
	EnumNumericNodeId_TripAlarmType_SuppressedState_Id = 10818,
	//! NodeId of the node TripAlarmType/SuppressedState/Name.
	EnumNumericNodeId_TripAlarmType_SuppressedState_Name = 10819,
	//! NodeId of the node TripAlarmType/SuppressedState/Number.
	EnumNumericNodeId_TripAlarmType_SuppressedState_Number = 10820,
	//! NodeId of the node TripAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_TripAlarmType_SuppressedState_EffectiveDisplayName = 10821,
	//! NodeId of the node TripAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_TripAlarmType_SuppressedState_TransitionTime = 10822,
	//! NodeId of the node TripAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_TripAlarmType_SuppressedState_EffectiveTransitionTime = 10823,
	//! NodeId of the node TripAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_TripAlarmType_SuppressedState_TrueState = 10824,
	//! NodeId of the node TripAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_TripAlarmType_SuppressedState_FalseState = 10825,
	//! NodeId of the node TripAlarmType/ShelvingState.
	EnumNumericNodeId_TripAlarmType_ShelvingState = 10826,
	//! NodeId of the node TripAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_TripAlarmType_ShelvingState_CurrentState = 10827,
	//! NodeId of the node TripAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_TripAlarmType_ShelvingState_CurrentState_Id = 10828,
	//! NodeId of the node TripAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_TripAlarmType_ShelvingState_CurrentState_Name = 10829,
	//! NodeId of the node TripAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_TripAlarmType_ShelvingState_CurrentState_Number = 10830,
	//! NodeId of the node TripAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_TripAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 10831,
	//! NodeId of the node TripAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_TripAlarmType_ShelvingState_LastTransition = 10832,
	//! NodeId of the node TripAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_TripAlarmType_ShelvingState_LastTransition_Id = 10833,
	//! NodeId of the node TripAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_TripAlarmType_ShelvingState_LastTransition_Name = 10834,
	//! NodeId of the node TripAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_TripAlarmType_ShelvingState_LastTransition_Number = 10835,
	//! NodeId of the node TripAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_TripAlarmType_ShelvingState_LastTransition_TransitionTime = 10836,
	//! NodeId of the node TripAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_TripAlarmType_ShelvingState_UnshelveTime = 10837,
	//! NodeId of the node TripAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_TripAlarmType_ShelvingState_Unshelve = 10859,
	//! NodeId of the node TripAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_TripAlarmType_ShelvingState_OneShotShelve = 10860,
	//! NodeId of the node TripAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_TripAlarmType_ShelvingState_TimedShelve = 10861,
	//! NodeId of the node TripAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_TripAlarmType_ShelvingState_TimedShelve_InputArguments = 10862,
	//! NodeId of the node TripAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_TripAlarmType_SuppressedOrShelved = 10863,
	//! NodeId of the node TripAlarmType/MaxTimeShelved.
	EnumNumericNodeId_TripAlarmType_MaxTimeShelved = 10864,
	//! NodeId of the object type AuditConditionShelvingEventType.
	EnumNumericNodeId_AuditConditionShelvingEventType = 11093,
	//! NodeId of the node AuditConditionShelvingEventType/EventId.
	EnumNumericNodeId_AuditConditionShelvingEventType_EventId = 11094,
	//! NodeId of the node AuditConditionShelvingEventType/EventType.
	EnumNumericNodeId_AuditConditionShelvingEventType_EventType = 11095,
	//! NodeId of the node AuditConditionShelvingEventType/SourceNode.
	EnumNumericNodeId_AuditConditionShelvingEventType_SourceNode = 11096,
	//! NodeId of the node AuditConditionShelvingEventType/SourceName.
	EnumNumericNodeId_AuditConditionShelvingEventType_SourceName = 11097,
	//! NodeId of the node AuditConditionShelvingEventType/Time.
	EnumNumericNodeId_AuditConditionShelvingEventType_Time = 11098,
	//! NodeId of the node AuditConditionShelvingEventType/ReceiveTime.
	EnumNumericNodeId_AuditConditionShelvingEventType_ReceiveTime = 11099,
	//! NodeId of the node AuditConditionShelvingEventType/LocalTime.
	EnumNumericNodeId_AuditConditionShelvingEventType_LocalTime = 11100,
	//! NodeId of the node AuditConditionShelvingEventType/Message.
	EnumNumericNodeId_AuditConditionShelvingEventType_Message = 11101,
	//! NodeId of the node AuditConditionShelvingEventType/Severity.
	EnumNumericNodeId_AuditConditionShelvingEventType_Severity = 11102,
	//! NodeId of the node AuditConditionShelvingEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditConditionShelvingEventType_ActionTimeStamp = 11103,
	//! NodeId of the node AuditConditionShelvingEventType/Status.
	EnumNumericNodeId_AuditConditionShelvingEventType_Status = 11104,
	//! NodeId of the node AuditConditionShelvingEventType/ServerId.
	EnumNumericNodeId_AuditConditionShelvingEventType_ServerId = 11105,
	//! NodeId of the node AuditConditionShelvingEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditConditionShelvingEventType_ClientAuditEntryId = 11106,
	//! NodeId of the node AuditConditionShelvingEventType/ClientUserId.
	EnumNumericNodeId_AuditConditionShelvingEventType_ClientUserId = 11107,
	//! NodeId of the node AuditConditionShelvingEventType/MethodId.
	EnumNumericNodeId_AuditConditionShelvingEventType_MethodId = 11108,
	//! NodeId of the node AuditConditionShelvingEventType/InputArguments.
	EnumNumericNodeId_AuditConditionShelvingEventType_InputArguments = 11109,
	//! NodeId of the node TwoStateVariableType/TrueState.
	EnumNumericNodeId_TwoStateVariableType_TrueState = 11110,
	//! NodeId of the node TwoStateVariableType/FalseState.
	EnumNumericNodeId_TwoStateVariableType_FalseState = 11111,
	//! NodeId of the node ConditionType/ConditionClassId.
	EnumNumericNodeId_ConditionType_ConditionClassId = 11112,
	//! NodeId of the node ConditionType/ConditionClassName.
	EnumNumericNodeId_ConditionType_ConditionClassName = 11113,
	//! NodeId of the node DialogConditionType/ConditionClassId.
	EnumNumericNodeId_DialogConditionType_ConditionClassId = 11114,
	//! NodeId of the node DialogConditionType/ConditionClassName.
	EnumNumericNodeId_DialogConditionType_ConditionClassName = 11115,
	//! NodeId of the node AcknowledgeableConditionType/ConditionClassId.
	EnumNumericNodeId_AcknowledgeableConditionType_ConditionClassId = 11116,
	//! NodeId of the node AcknowledgeableConditionType/ConditionClassName.
	EnumNumericNodeId_AcknowledgeableConditionType_ConditionClassName = 11117,
	//! NodeId of the node AlarmConditionType/ConditionClassId.
	EnumNumericNodeId_AlarmConditionType_ConditionClassId = 11118,
	//! NodeId of the node AlarmConditionType/ConditionClassName.
	EnumNumericNodeId_AlarmConditionType_ConditionClassName = 11119,
	//! NodeId of the node AlarmConditionType/InputNode.
	EnumNumericNodeId_AlarmConditionType_InputNode = 11120,
	//! NodeId of the node LimitAlarmType/ConditionClassId.
	EnumNumericNodeId_LimitAlarmType_ConditionClassId = 11121,
	//! NodeId of the node LimitAlarmType/ConditionClassName.
	EnumNumericNodeId_LimitAlarmType_ConditionClassName = 11122,
	//! NodeId of the node LimitAlarmType/InputNode.
	EnumNumericNodeId_LimitAlarmType_InputNode = 11123,
	//! NodeId of the node LimitAlarmType/HighHighLimit.
	EnumNumericNodeId_LimitAlarmType_HighHighLimit = 11124,
	//! NodeId of the node LimitAlarmType/HighLimit.
	EnumNumericNodeId_LimitAlarmType_HighLimit = 11125,
	//! NodeId of the node LimitAlarmType/LowLimit.
	EnumNumericNodeId_LimitAlarmType_LowLimit = 11126,
	//! NodeId of the node LimitAlarmType/LowLowLimit.
	EnumNumericNodeId_LimitAlarmType_LowLowLimit = 11127,
	//! NodeId of the node ExclusiveLimitAlarmType/ConditionClassId.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConditionClassId = 11128,
	//! NodeId of the node ExclusiveLimitAlarmType/ConditionClassName.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ConditionClassName = 11129,
	//! NodeId of the node ExclusiveLimitAlarmType/InputNode.
	EnumNumericNodeId_ExclusiveLimitAlarmType_InputNode = 11130,
	//! NodeId of the node ExclusiveLevelAlarmType/ConditionClassId.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConditionClassId = 11131,
	//! NodeId of the node ExclusiveLevelAlarmType/ConditionClassName.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ConditionClassName = 11132,
	//! NodeId of the node ExclusiveLevelAlarmType/InputNode.
	EnumNumericNodeId_ExclusiveLevelAlarmType_InputNode = 11133,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConditionClassId.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConditionClassId = 11134,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ConditionClassName.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ConditionClassName = 11135,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/InputNode.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_InputNode = 11136,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConditionClassId.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConditionClassId = 11137,
	//! NodeId of the node ExclusiveDeviationAlarmType/ConditionClassName.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ConditionClassName = 11138,
	//! NodeId of the node ExclusiveDeviationAlarmType/InputNode.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_InputNode = 11139,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConditionClassId.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConditionClassId = 11140,
	//! NodeId of the node NonExclusiveLimitAlarmType/ConditionClassName.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ConditionClassName = 11141,
	//! NodeId of the node NonExclusiveLimitAlarmType/InputNode.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_InputNode = 11142,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConditionClassId.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConditionClassId = 11143,
	//! NodeId of the node NonExclusiveLevelAlarmType/ConditionClassName.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ConditionClassName = 11144,
	//! NodeId of the node NonExclusiveLevelAlarmType/InputNode.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_InputNode = 11145,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConditionClassId.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConditionClassId = 11146,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ConditionClassName.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ConditionClassName = 11147,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/InputNode.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_InputNode = 11148,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConditionClassId.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConditionClassId = 11149,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ConditionClassName.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ConditionClassName = 11150,
	//! NodeId of the node NonExclusiveDeviationAlarmType/InputNode.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_InputNode = 11151,
	//! NodeId of the node DiscreteAlarmType/ConditionClassId.
	EnumNumericNodeId_DiscreteAlarmType_ConditionClassId = 11152,
	//! NodeId of the node DiscreteAlarmType/ConditionClassName.
	EnumNumericNodeId_DiscreteAlarmType_ConditionClassName = 11153,
	//! NodeId of the node DiscreteAlarmType/InputNode.
	EnumNumericNodeId_DiscreteAlarmType_InputNode = 11154,
	//! NodeId of the node OffNormalAlarmType/ConditionClassId.
	EnumNumericNodeId_OffNormalAlarmType_ConditionClassId = 11155,
	//! NodeId of the node OffNormalAlarmType/ConditionClassName.
	EnumNumericNodeId_OffNormalAlarmType_ConditionClassName = 11156,
	//! NodeId of the node OffNormalAlarmType/InputNode.
	EnumNumericNodeId_OffNormalAlarmType_InputNode = 11157,
	//! NodeId of the node OffNormalAlarmType/NormalState.
	EnumNumericNodeId_OffNormalAlarmType_NormalState = 11158,
	//! NodeId of the node TripAlarmType/ConditionClassId.
	EnumNumericNodeId_TripAlarmType_ConditionClassId = 11159,
	//! NodeId of the node TripAlarmType/ConditionClassName.
	EnumNumericNodeId_TripAlarmType_ConditionClassName = 11160,
	//! NodeId of the node TripAlarmType/InputNode.
	EnumNumericNodeId_TripAlarmType_InputNode = 11161,
	//! NodeId of the node TripAlarmType/NormalState.
	EnumNumericNodeId_TripAlarmType_NormalState = 11162,
	//! NodeId of the object type BaseConditionClassType.
	EnumNumericNodeId_BaseConditionClassType = 11163,
	//! NodeId of the object type ProcessConditionClassType.
	EnumNumericNodeId_ProcessConditionClassType = 11164,
	//! NodeId of the object type MaintenanceConditionClassType.
	EnumNumericNodeId_MaintenanceConditionClassType = 11165,
	//! NodeId of the object type SystemConditionClassType.
	EnumNumericNodeId_SystemConditionClassType = 11166,
	//! NodeId of the node HistoricalDataConfigurationType/AggregateConfiguration/TreatUncertainAsBad.
	EnumNumericNodeId_HistoricalDataConfigurationType_AggregateConfiguration_TreatUncertainAsBad = 11168,
	//! NodeId of the node HistoricalDataConfigurationType/AggregateConfiguration/PercentDataBad.
	EnumNumericNodeId_HistoricalDataConfigurationType_AggregateConfiguration_PercentDataBad = 11169,
	//! NodeId of the node HistoricalDataConfigurationType/AggregateConfiguration/PercentDataGood.
	EnumNumericNodeId_HistoricalDataConfigurationType_AggregateConfiguration_PercentDataGood = 11170,
	//! NodeId of the node HistoricalDataConfigurationType/AggregateConfiguration/UseSlopedExtrapolation.
	EnumNumericNodeId_HistoricalDataConfigurationType_AggregateConfiguration_UseSlopedExtrapolation = 11171,
	//! NodeId of the node HistoryServerCapabilitiesType/AggregateFunctions.
	EnumNumericNodeId_HistoryServerCapabilitiesType_AggregateFunctions = 11172,
	//! NodeId of the object type AggregateConfigurationType.
	EnumNumericNodeId_AggregateConfigurationType = 11187,
	//! NodeId of the node AggregateConfigurationType/TreatUncertainAsBad.
	EnumNumericNodeId_AggregateConfigurationType_TreatUncertainAsBad = 11188,
	//! NodeId of the node AggregateConfigurationType/PercentDataBad.
	EnumNumericNodeId_AggregateConfigurationType_PercentDataBad = 11189,
	//! NodeId of the node AggregateConfigurationType/PercentDataGood.
	EnumNumericNodeId_AggregateConfigurationType_PercentDataGood = 11190,
	//! NodeId of the node AggregateConfigurationType/UseSlopedExtrapolation.
	EnumNumericNodeId_AggregateConfigurationType_UseSlopedExtrapolation = 11191,
	//! NodeId of the node HistoryServerCapabilities.
	EnumNumericNodeId_HistoryServerCapabilities = 11192,
	//! NodeId of the node HistoryServerCapabilities/AccessHistoryDataCapability.
	EnumNumericNodeId_HistoryServerCapabilities_AccessHistoryDataCapability = 11193,
	//! NodeId of the node HistoryServerCapabilities/InsertDataCapability.
	EnumNumericNodeId_HistoryServerCapabilities_InsertDataCapability = 11196,
	//! NodeId of the node HistoryServerCapabilities/ReplaceDataCapability.
	EnumNumericNodeId_HistoryServerCapabilities_ReplaceDataCapability = 11197,
	//! NodeId of the node HistoryServerCapabilities/UpdateDataCapability.
	EnumNumericNodeId_HistoryServerCapabilities_UpdateDataCapability = 11198,
	//! NodeId of the node HistoryServerCapabilities/DeleteRawCapability.
	EnumNumericNodeId_HistoryServerCapabilities_DeleteRawCapability = 11199,
	//! NodeId of the node HistoryServerCapabilities/DeleteAtTimeCapability.
	EnumNumericNodeId_HistoryServerCapabilities_DeleteAtTimeCapability = 11200,
	//! NodeId of the node HistoryServerCapabilities/AggregateFunctions.
	EnumNumericNodeId_HistoryServerCapabilities_AggregateFunctions = 11201,
	//! NodeId of the node HAConfiguration.
	EnumNumericNodeId_HAConfiguration = 11202,
	//! NodeId of the node HAConfiguration/AggregateConfiguration.
	EnumNumericNodeId_HAConfiguration_AggregateConfiguration = 11203,
	//! NodeId of the node HAConfiguration/AggregateConfiguration/TreatUncertainAsBad.
	EnumNumericNodeId_HAConfiguration_AggregateConfiguration_TreatUncertainAsBad = 11204,
	//! NodeId of the node HAConfiguration/AggregateConfiguration/PercentDataBad.
	EnumNumericNodeId_HAConfiguration_AggregateConfiguration_PercentDataBad = 11205,
	//! NodeId of the node HAConfiguration/AggregateConfiguration/PercentDataGood.
	EnumNumericNodeId_HAConfiguration_AggregateConfiguration_PercentDataGood = 11206,
	//! NodeId of the node HAConfiguration/AggregateConfiguration/UseSlopedExtrapolation.
	EnumNumericNodeId_HAConfiguration_AggregateConfiguration_UseSlopedExtrapolation = 11207,
	//! NodeId of the node HAConfiguration/Stepped.
	EnumNumericNodeId_HAConfiguration_Stepped = 11208,
	//! NodeId of the node HAConfiguration/Definition.
	EnumNumericNodeId_HAConfiguration_Definition = 11209,
	//! NodeId of the node HAConfiguration/MaxTimeInterval.
	EnumNumericNodeId_HAConfiguration_MaxTimeInterval = 11210,
	//! NodeId of the node HAConfiguration/MinTimeInterval.
	EnumNumericNodeId_HAConfiguration_MinTimeInterval = 11211,
	//! NodeId of the node HAConfiguration/ExceptionDeviation.
	EnumNumericNodeId_HAConfiguration_ExceptionDeviation = 11212,
	//! NodeId of the node HAConfiguration/ExceptionDeviationFormat.
	EnumNumericNodeId_HAConfiguration_ExceptionDeviationFormat = 11213,
	//! NodeId of the node Annotations.
	EnumNumericNodeId_Annotations = 11214,
	//! NodeId of the node HistoricalEventFilter.
	EnumNumericNodeId_HistoricalEventFilter = 11215,
	//! NodeId of the data type ModificationInfo.
	EnumNumericNodeId_ModificationInfo = 11216,
	//! NodeId of the data type HistoryModifiedData.
	EnumNumericNodeId_HistoryModifiedData = 11217,
	//! NodeId of the node ModificationInfo/Encoding/DefaultXml.
	EnumNumericNodeId_ModificationInfo_Encoding_DefaultXml = 11218,
	//! NodeId of the node HistoryModifiedData/Encoding/DefaultXml.
	EnumNumericNodeId_HistoryModifiedData_Encoding_DefaultXml = 11219,
	//! NodeId of the node ModificationInfo/Encoding/DefaultBinary.
	EnumNumericNodeId_ModificationInfo_Encoding_DefaultBinary = 11226,
	//! NodeId of the node HistoryModifiedData/Encoding/DefaultBinary.
	EnumNumericNodeId_HistoryModifiedData_Encoding_DefaultBinary = 11227,
	//! NodeId of the data type HistoryUpdateType.
	EnumNumericNodeId_HistoryUpdateType = 11234,
	//! NodeId of the variable type MultiStateValueDiscreteType.
	EnumNumericNodeId_MultiStateValueDiscreteType = 11238,
	//! NodeId of the node MultiStateValueDiscreteType/Definition.
	EnumNumericNodeId_MultiStateValueDiscreteType_Definition = 11239,
	//! NodeId of the node MultiStateValueDiscreteType/ValuePrecision.
	EnumNumericNodeId_MultiStateValueDiscreteType_ValuePrecision = 11240,
	//! NodeId of the node MultiStateValueDiscreteType/EnumValues.
	EnumNumericNodeId_MultiStateValueDiscreteType_EnumValues = 11241,
	//! NodeId of the node HistoryServerCapabilities/AccessHistoryEventsCapability.
	EnumNumericNodeId_HistoryServerCapabilities_AccessHistoryEventsCapability = 11242,
	//! NodeId of the node HistoryServerCapabilitiesType/MaxReturnDataValues.
	EnumNumericNodeId_HistoryServerCapabilitiesType_MaxReturnDataValues = 11268,
	//! NodeId of the node HistoryServerCapabilitiesType/MaxReturnEventValues.
	EnumNumericNodeId_HistoryServerCapabilitiesType_MaxReturnEventValues = 11269,
	//! NodeId of the node HistoryServerCapabilitiesType/InsertAnnotationCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_InsertAnnotationCapability = 11270,
	//! NodeId of the node HistoryServerCapabilities/MaxReturnDataValues.
	EnumNumericNodeId_HistoryServerCapabilities_MaxReturnDataValues = 11273,
	//! NodeId of the node HistoryServerCapabilities/MaxReturnEventValues.
	EnumNumericNodeId_HistoryServerCapabilities_MaxReturnEventValues = 11274,
	//! NodeId of the node HistoryServerCapabilities/InsertAnnotationCapability.
	EnumNumericNodeId_HistoryServerCapabilities_InsertAnnotationCapability = 11275,
	//! NodeId of the node HistoryServerCapabilitiesType/InsertEventCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_InsertEventCapability = 11278,
	//! NodeId of the node HistoryServerCapabilitiesType/ReplaceEventCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_ReplaceEventCapability = 11279,
	//! NodeId of the node HistoryServerCapabilitiesType/UpdateEventCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_UpdateEventCapability = 11280,
	//! NodeId of the node HistoryServerCapabilities/InsertEventCapability.
	EnumNumericNodeId_HistoryServerCapabilities_InsertEventCapability = 11281,
	//! NodeId of the node HistoryServerCapabilities/ReplaceEventCapability.
	EnumNumericNodeId_HistoryServerCapabilities_ReplaceEventCapability = 11282,
	//! NodeId of the node HistoryServerCapabilities/UpdateEventCapability.
	EnumNumericNodeId_HistoryServerCapabilities_UpdateEventCapability = 11283,
	//! NodeId of the node AggregateFunction/TimeAverage2.
	EnumNumericNodeId_AggregateFunction_TimeAverage2 = 11285,
	//! NodeId of the node AggregateFunction/Minimum2.
	EnumNumericNodeId_AggregateFunction_Minimum2 = 11286,
	//! NodeId of the node AggregateFunction/Maximum2.
	EnumNumericNodeId_AggregateFunction_Maximum2 = 11287,
	//! NodeId of the node AggregateFunction/Range2.
	EnumNumericNodeId_AggregateFunction_Range2 = 11288,
	//! NodeId of the node AggregateFunction/WorstQuality2.
	EnumNumericNodeId_AggregateFunction_WorstQuality2 = 11292,
	//! NodeId of the data type PerformUpdateType.
	EnumNumericNodeId_PerformUpdateType = 11293,
	//! NodeId of the data type UpdateStructureDataDetails.
	EnumNumericNodeId_UpdateStructureDataDetails = 11295,
	//! NodeId of the node UpdateStructureDataDetails/Encoding/DefaultXml.
	EnumNumericNodeId_UpdateStructureDataDetails_Encoding_DefaultXml = 11296,
	//! NodeId of the node UpdateStructureDataDetails/Encoding/DefaultBinary.
	EnumNumericNodeId_UpdateStructureDataDetails_Encoding_DefaultBinary = 11300,
	//! NodeId of the node AggregateFunction/Total2.
	EnumNumericNodeId_AggregateFunction_Total2 = 11304,
	//! NodeId of the node AggregateFunction/MinimumActualTime2.
	EnumNumericNodeId_AggregateFunction_MinimumActualTime2 = 11305,
	//! NodeId of the node AggregateFunction/MaximumActualTime2.
	EnumNumericNodeId_AggregateFunction_MaximumActualTime2 = 11306,
	//! NodeId of the node AggregateFunction/DurationInStateZero.
	EnumNumericNodeId_AggregateFunction_DurationInStateZero = 11307,
	//! NodeId of the node AggregateFunction/DurationInStateNonZero.
	EnumNumericNodeId_AggregateFunction_DurationInStateNonZero = 11308,
	//! NodeId of the node Server/ServerRedundancy/CurrentServerId.
	EnumNumericNodeId_Server_ServerRedundancy_CurrentServerId = 11312,
	//! NodeId of the node Server/ServerRedundancy/RedundantServerArray.
	EnumNumericNodeId_Server_ServerRedundancy_RedundantServerArray = 11313,
	//! NodeId of the node Server/ServerRedundancy/ServerUriArray.
	EnumNumericNodeId_Server_ServerRedundancy_ServerUriArray = 11314,
	//! NodeId of the node ShelvedStateMachineType/UnshelvedToTimedShelved/TransitionNumber.
	EnumNumericNodeId_ShelvedStateMachineType_UnshelvedToTimedShelved_TransitionNumber = 11322,
	//! NodeId of the node ShelvedStateMachineType/UnshelvedToOneShotShelved/TransitionNumber.
	EnumNumericNodeId_ShelvedStateMachineType_UnshelvedToOneShotShelved_TransitionNumber = 11323,
	//! NodeId of the node ShelvedStateMachineType/TimedShelvedToUnshelved/TransitionNumber.
	EnumNumericNodeId_ShelvedStateMachineType_TimedShelvedToUnshelved_TransitionNumber = 11324,
	//! NodeId of the node ShelvedStateMachineType/TimedShelvedToOneShotShelved/TransitionNumber.
	EnumNumericNodeId_ShelvedStateMachineType_TimedShelvedToOneShotShelved_TransitionNumber = 11325,
	//! NodeId of the node ShelvedStateMachineType/OneShotShelvedToUnshelved/TransitionNumber.
	EnumNumericNodeId_ShelvedStateMachineType_OneShotShelvedToUnshelved_TransitionNumber = 11326,
	//! NodeId of the node ShelvedStateMachineType/OneShotShelvedToTimedShelved/TransitionNumber.
	EnumNumericNodeId_ShelvedStateMachineType_OneShotShelvedToTimedShelved_TransitionNumber = 11327,
	//! NodeId of the node ExclusiveLimitStateMachineType/LowLowToLow/TransitionNumber.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LowLowToLow_TransitionNumber = 11340,
	//! NodeId of the node ExclusiveLimitStateMachineType/LowToLowLow/TransitionNumber.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LowToLowLow_TransitionNumber = 11341,
	//! NodeId of the node ExclusiveLimitStateMachineType/HighHighToHigh/TransitionNumber.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_HighHighToHigh_TransitionNumber = 11342,
	//! NodeId of the node ExclusiveLimitStateMachineType/HighToHighHigh/TransitionNumber.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_HighToHighHigh_TransitionNumber = 11343,
	//! NodeId of the node AggregateFunction/StandardDeviationSample.
	EnumNumericNodeId_AggregateFunction_StandardDeviationSample = 11426,
	//! NodeId of the node AggregateFunction/StandardDeviationPopulation.
	EnumNumericNodeId_AggregateFunction_StandardDeviationPopulation = 11427,
	//! NodeId of the node AggregateFunction/VarianceSample.
	EnumNumericNodeId_AggregateFunction_VarianceSample = 11428,
	//! NodeId of the node AggregateFunction/VariancePopulation.
	EnumNumericNodeId_AggregateFunction_VariancePopulation = 11429,
	//! NodeId of the node EnumStrings.
	EnumNumericNodeId_EnumStrings = 11432,
	//! NodeId of the node ValueAsText.
	EnumNumericNodeId_ValueAsText = 11433,
	//! NodeId of the abstract object type ProgressEventType.
	EnumNumericNodeId_ProgressEventType = 11436,
	//! NodeId of the node ProgressEventType/EventId.
	EnumNumericNodeId_ProgressEventType_EventId = 11437,
	//! NodeId of the node ProgressEventType/EventType.
	EnumNumericNodeId_ProgressEventType_EventType = 11438,
	//! NodeId of the node ProgressEventType/SourceNode.
	EnumNumericNodeId_ProgressEventType_SourceNode = 11439,
	//! NodeId of the node ProgressEventType/SourceName.
	EnumNumericNodeId_ProgressEventType_SourceName = 11440,
	//! NodeId of the node ProgressEventType/Time.
	EnumNumericNodeId_ProgressEventType_Time = 11441,
	//! NodeId of the node ProgressEventType/ReceiveTime.
	EnumNumericNodeId_ProgressEventType_ReceiveTime = 11442,
	//! NodeId of the node ProgressEventType/LocalTime.
	EnumNumericNodeId_ProgressEventType_LocalTime = 11443,
	//! NodeId of the node ProgressEventType/Message.
	EnumNumericNodeId_ProgressEventType_Message = 11444,
	//! NodeId of the node ProgressEventType/Severity.
	EnumNumericNodeId_ProgressEventType_Severity = 11445,
	//! NodeId of the abstract object type SystemStatusChangeEventType.
	EnumNumericNodeId_SystemStatusChangeEventType = 11446,
	//! NodeId of the node SystemStatusChangeEventType/EventId.
	EnumNumericNodeId_SystemStatusChangeEventType_EventId = 11447,
	//! NodeId of the node SystemStatusChangeEventType/EventType.
	EnumNumericNodeId_SystemStatusChangeEventType_EventType = 11448,
	//! NodeId of the node SystemStatusChangeEventType/SourceNode.
	EnumNumericNodeId_SystemStatusChangeEventType_SourceNode = 11449,
	//! NodeId of the node SystemStatusChangeEventType/SourceName.
	EnumNumericNodeId_SystemStatusChangeEventType_SourceName = 11450,
	//! NodeId of the node SystemStatusChangeEventType/Time.
	EnumNumericNodeId_SystemStatusChangeEventType_Time = 11451,
	//! NodeId of the node SystemStatusChangeEventType/ReceiveTime.
	EnumNumericNodeId_SystemStatusChangeEventType_ReceiveTime = 11452,
	//! NodeId of the node SystemStatusChangeEventType/LocalTime.
	EnumNumericNodeId_SystemStatusChangeEventType_LocalTime = 11453,
	//! NodeId of the node SystemStatusChangeEventType/Message.
	EnumNumericNodeId_SystemStatusChangeEventType_Message = 11454,
	//! NodeId of the node SystemStatusChangeEventType/Severity.
	EnumNumericNodeId_SystemStatusChangeEventType_Severity = 11455,
	//! NodeId of the node TransitionVariableType/EffectiveTransitionTime.
	EnumNumericNodeId_TransitionVariableType_EffectiveTransitionTime = 11456,
	//! NodeId of the node FiniteTransitionVariableType/EffectiveTransitionTime.
	EnumNumericNodeId_FiniteTransitionVariableType_EffectiveTransitionTime = 11457,
	//! NodeId of the node StateMachineType/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_StateMachineType_LastTransition_EffectiveTransitionTime = 11458,
	//! NodeId of the node FiniteStateMachineType/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_FiniteStateMachineType_LastTransition_EffectiveTransitionTime = 11459,
	//! NodeId of the node TransitionEventType/Transition/EffectiveTransitionTime.
	EnumNumericNodeId_TransitionEventType_Transition_EffectiveTransitionTime = 11460,
	//! NodeId of the node MultiStateValueDiscreteType/ValueAsText.
	EnumNumericNodeId_MultiStateValueDiscreteType_ValueAsText = 11461,
	//! NodeId of the node ProgramTransitionEventType/Transition/EffectiveTransitionTime.
	EnumNumericNodeId_ProgramTransitionEventType_Transition_EffectiveTransitionTime = 11462,
	//! NodeId of the node ProgramTransitionAuditEventType/Transition/EffectiveTransitionTime.
	EnumNumericNodeId_ProgramTransitionAuditEventType_Transition_EffectiveTransitionTime = 11463,
	//! NodeId of the node ProgramStateMachineType/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ProgramStateMachineType_LastTransition_EffectiveTransitionTime = 11464,
	//! NodeId of the node ShelvedStateMachineType/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ShelvedStateMachineType_LastTransition_EffectiveTransitionTime = 11465,
	//! NodeId of the node AlarmConditionType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_AlarmConditionType_ShelvingState_LastTransition_EffectiveTransitionTime = 11466,
	//! NodeId of the node LimitAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_LimitAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11467,
	//! NodeId of the node ExclusiveLimitStateMachineType/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLimitStateMachineType_LastTransition_EffectiveTransitionTime = 11468,
	//! NodeId of the node ExclusiveLimitAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11469,
	//! NodeId of the node ExclusiveLimitAlarmType/LimitState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLimitAlarmType_LimitState_LastTransition_EffectiveTransitionTime = 11470,
	//! NodeId of the node ExclusiveLevelAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11471,
	//! NodeId of the node ExclusiveLevelAlarmType/LimitState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveLevelAlarmType_LimitState_LastTransition_EffectiveTransitionTime = 11472,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11473,
	//! NodeId of the node ExclusiveRateOfChangeAlarmType/LimitState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveRateOfChangeAlarmType_LimitState_LastTransition_EffectiveTransitionTime = 11474,
	//! NodeId of the node ExclusiveDeviationAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11475,
	//! NodeId of the node ExclusiveDeviationAlarmType/LimitState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_ExclusiveDeviationAlarmType_LimitState_LastTransition_EffectiveTransitionTime = 11476,
	//! NodeId of the node NonExclusiveLimitAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLimitAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11477,
	//! NodeId of the node NonExclusiveLevelAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveLevelAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11478,
	//! NodeId of the node NonExclusiveRateOfChangeAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11479,
	//! NodeId of the node NonExclusiveDeviationAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_NonExclusiveDeviationAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11480,
	//! NodeId of the node DiscreteAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_DiscreteAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11481,
	//! NodeId of the node OffNormalAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_OffNormalAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11482,
	//! NodeId of the node TripAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_TripAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11483,
	//! NodeId of the node AuditActivateSessionEventType/SecureChannelId.
	EnumNumericNodeId_AuditActivateSessionEventType_SecureChannelId = 11485,
	//! NodeId of the variable type OptionSetType.
	EnumNumericNodeId_OptionSetType = 11487,
	//! NodeId of the node OptionSetType/OptionSetValues.
	EnumNumericNodeId_OptionSetType_OptionSetValues = 11488,
	//! NodeId of the node ServerType/GetMonitoredItems.
	EnumNumericNodeId_ServerType_GetMonitoredItems = 11489,
	//! NodeId of the node ServerType/GetMonitoredItems/InputArguments.
	EnumNumericNodeId_ServerType_GetMonitoredItems_InputArguments = 11490,
	//! NodeId of the node ServerType/GetMonitoredItems/OutputArguments.
	EnumNumericNodeId_ServerType_GetMonitoredItems_OutputArguments = 11491,
	//! NodeId of the node Server/GetMonitoredItems.
	EnumNumericNodeId_Server_GetMonitoredItems = 11492,
	//! NodeId of the node Server/GetMonitoredItems/InputArguments.
	EnumNumericNodeId_Server_GetMonitoredItems_InputArguments = 11493,
	//! NodeId of the node Server/GetMonitoredItems/OutputArguments.
	EnumNumericNodeId_Server_GetMonitoredItems_OutputArguments = 11494,
	//! NodeId of the node MaxStringLength.
	EnumNumericNodeId_MaxStringLength = 11498,
	//! NodeId of the node HistoricalDataConfigurationType/StartOfArchive.
	EnumNumericNodeId_HistoricalDataConfigurationType_StartOfArchive = 11499,
	//! NodeId of the node HistoricalDataConfigurationType/StartOfOnlineArchive.
	EnumNumericNodeId_HistoricalDataConfigurationType_StartOfOnlineArchive = 11500,
	//! NodeId of the node HistoryServerCapabilitiesType/DeleteEventCapability.
	EnumNumericNodeId_HistoryServerCapabilitiesType_DeleteEventCapability = 11501,
	//! NodeId of the node HistoryServerCapabilities/DeleteEventCapability.
	EnumNumericNodeId_HistoryServerCapabilities_DeleteEventCapability = 11502,
	//! NodeId of the node HAConfiguration/StartOfArchive.
	EnumNumericNodeId_HAConfiguration_StartOfArchive = 11503,
	//! NodeId of the node HAConfiguration/StartOfOnlineArchive.
	EnumNumericNodeId_HAConfiguration_StartOfOnlineArchive = 11504,
	//! NodeId of the node AggregateFunction/StartBound.
	EnumNumericNodeId_AggregateFunction_StartBound = 11505,
	//! NodeId of the node AggregateFunction/EndBound.
	EnumNumericNodeId_AggregateFunction_EndBound = 11506,
	//! NodeId of the node AggregateFunction/DeltaBounds.
	EnumNumericNodeId_AggregateFunction_DeltaBounds = 11507,
	//! NodeId of the node ModellingRule/OptionalPlaceholder.
	EnumNumericNodeId_ModellingRule_OptionalPlaceholder = 11508,
	//! NodeId of the node ModellingRule/OptionalPlaceholder/NamingRule.
	EnumNumericNodeId_ModellingRule_OptionalPlaceholder_NamingRule = 11509,
	//! NodeId of the node ModellingRule/MandatoryPlaceholder.
	EnumNumericNodeId_ModellingRule_MandatoryPlaceholder = 11510,
	//! NodeId of the node ModellingRule/MandatoryPlaceholder/NamingRule.
	EnumNumericNodeId_ModellingRule_MandatoryPlaceholder_NamingRule = 11511,
	//! NodeId of the node MaxArrayLength.
	EnumNumericNodeId_MaxArrayLength = 11512,
	//! NodeId of the node EngineeringUnits.
	EnumNumericNodeId_EngineeringUnits = 11513,
	//! NodeId of the node ServerType/ServerCapabilities/MaxArrayLength.
	EnumNumericNodeId_ServerType_ServerCapabilities_MaxArrayLength = 11514,
	//! NodeId of the node ServerType/ServerCapabilities/MaxStringLength.
	EnumNumericNodeId_ServerType_ServerCapabilities_MaxStringLength = 11515,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits = 11516,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerRead.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerRead = 11517,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerWrite.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerWrite = 11519,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerMethodCall.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerMethodCall = 11521,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerBrowse.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerBrowse = 11522,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerRegisterNodes.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerRegisterNodes = 11523,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerTranslateBrowsePathsToNodeIds.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerTranslateBrowsePathsToNodeIds = 11524,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerNodeManagement.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerNodeManagement = 11525,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxMonitoredItemsPerCall.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxMonitoredItemsPerCall = 11526,
	//! NodeId of the node ServerType/Namespaces.
	EnumNumericNodeId_ServerType_Namespaces = 11527,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile = 11528,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Size.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Size = 11529,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/OpenCount.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_OpenCount = 11532,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Open.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Open = 11533,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Open/InputArguments.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Open_InputArguments = 11534,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Open/OutputArguments.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Open_OutputArguments = 11535,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Close.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Close = 11536,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Close/InputArguments.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Close_InputArguments = 11537,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Read.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Read = 11538,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Read/InputArguments.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Read_InputArguments = 11539,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Read/OutputArguments.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Read_OutputArguments = 11540,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Write.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Write = 11541,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Write/InputArguments.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Write_InputArguments = 11542,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/GetPosition.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_GetPosition = 11543,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/GetPosition/InputArguments.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_GetPosition_InputArguments = 11544,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/GetPosition/OutputArguments.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_GetPosition_OutputArguments = 11545,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/SetPosition.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_SetPosition = 11546,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/SetPosition/InputArguments.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_SetPosition_InputArguments = 11547,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/ExportNamespace.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_ExportNamespace = 11548,
	//! NodeId of the node ServerCapabilitiesType/MaxArrayLength.
	EnumNumericNodeId_ServerCapabilitiesType_MaxArrayLength = 11549,
	//! NodeId of the node ServerCapabilitiesType/MaxStringLength.
	EnumNumericNodeId_ServerCapabilitiesType_MaxStringLength = 11550,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits = 11551,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerRead.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerRead = 11552,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerWrite.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerWrite = 11554,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerMethodCall.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerMethodCall = 11556,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerBrowse.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerBrowse = 11557,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerRegisterNodes.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerRegisterNodes = 11558,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerTranslateBrowsePathsToNodeIds.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerTranslateBrowsePathsToNodeIds = 11559,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerNodeManagement.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerNodeManagement = 11560,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxMonitoredItemsPerCall.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxMonitoredItemsPerCall = 11561,
	//! NodeId of the node ServerCapabilitiesType/VendorCapability.
	EnumNumericNodeId_ServerCapabilitiesType_VendorCapability = 11562,
	//! NodeId of the object type OperationLimitsType.
	EnumNumericNodeId_OperationLimitsType = 11564,
	//! NodeId of the node OperationLimitsType/MaxNodesPerRead.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerRead = 11565,
	//! NodeId of the node OperationLimitsType/MaxNodesPerWrite.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerWrite = 11567,
	//! NodeId of the node OperationLimitsType/MaxNodesPerMethodCall.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerMethodCall = 11569,
	//! NodeId of the node OperationLimitsType/MaxNodesPerBrowse.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerBrowse = 11570,
	//! NodeId of the node OperationLimitsType/MaxNodesPerRegisterNodes.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerRegisterNodes = 11571,
	//! NodeId of the node OperationLimitsType/MaxNodesPerTranslateBrowsePathsToNodeIds.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerTranslateBrowsePathsToNodeIds = 11572,
	//! NodeId of the node OperationLimitsType/MaxNodesPerNodeManagement.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerNodeManagement = 11573,
	//! NodeId of the node OperationLimitsType/MaxMonitoredItemsPerCall.
	EnumNumericNodeId_OperationLimitsType_MaxMonitoredItemsPerCall = 11574,
	//! NodeId of the object type FileType.
	EnumNumericNodeId_FileType = 11575,
	//! NodeId of the node FileType/Size.
	EnumNumericNodeId_FileType_Size = 11576,
	//! NodeId of the node FileType/OpenCount.
	EnumNumericNodeId_FileType_OpenCount = 11579,
	//! NodeId of the node FileType/Open.
	EnumNumericNodeId_FileType_Open = 11580,
	//! NodeId of the node FileType/Open/InputArguments.
	EnumNumericNodeId_FileType_Open_InputArguments = 11581,
	//! NodeId of the node FileType/Open/OutputArguments.
	EnumNumericNodeId_FileType_Open_OutputArguments = 11582,
	//! NodeId of the node FileType/Close.
	EnumNumericNodeId_FileType_Close = 11583,
	//! NodeId of the node FileType/Close/InputArguments.
	EnumNumericNodeId_FileType_Close_InputArguments = 11584,
	//! NodeId of the node FileType/Read.
	EnumNumericNodeId_FileType_Read = 11585,
	//! NodeId of the node FileType/Read/InputArguments.
	EnumNumericNodeId_FileType_Read_InputArguments = 11586,
	//! NodeId of the node FileType/Read/OutputArguments.
	EnumNumericNodeId_FileType_Read_OutputArguments = 11587,
	//! NodeId of the node FileType/Write.
	EnumNumericNodeId_FileType_Write = 11588,
	//! NodeId of the node FileType/Write/InputArguments.
	EnumNumericNodeId_FileType_Write_InputArguments = 11589,
	//! NodeId of the node FileType/GetPosition.
	EnumNumericNodeId_FileType_GetPosition = 11590,
	//! NodeId of the node FileType/GetPosition/InputArguments.
	EnumNumericNodeId_FileType_GetPosition_InputArguments = 11591,
	//! NodeId of the node FileType/GetPosition/OutputArguments.
	EnumNumericNodeId_FileType_GetPosition_OutputArguments = 11592,
	//! NodeId of the node FileType/SetPosition.
	EnumNumericNodeId_FileType_SetPosition = 11593,
	//! NodeId of the node FileType/SetPosition/InputArguments.
	EnumNumericNodeId_FileType_SetPosition_InputArguments = 11594,
	//! NodeId of the object type AddressSpaceFileType.
	EnumNumericNodeId_AddressSpaceFileType = 11595,
	//! NodeId of the node AddressSpaceFileType/Size.
	EnumNumericNodeId_AddressSpaceFileType_Size = 11596,
	//! NodeId of the node AddressSpaceFileType/OpenCount.
	EnumNumericNodeId_AddressSpaceFileType_OpenCount = 11599,
	//! NodeId of the node AddressSpaceFileType/Open.
	EnumNumericNodeId_AddressSpaceFileType_Open = 11600,
	//! NodeId of the node AddressSpaceFileType/Open/InputArguments.
	EnumNumericNodeId_AddressSpaceFileType_Open_InputArguments = 11601,
	//! NodeId of the node AddressSpaceFileType/Open/OutputArguments.
	EnumNumericNodeId_AddressSpaceFileType_Open_OutputArguments = 11602,
	//! NodeId of the node AddressSpaceFileType/Close.
	EnumNumericNodeId_AddressSpaceFileType_Close = 11603,
	//! NodeId of the node AddressSpaceFileType/Close/InputArguments.
	EnumNumericNodeId_AddressSpaceFileType_Close_InputArguments = 11604,
	//! NodeId of the node AddressSpaceFileType/Read.
	EnumNumericNodeId_AddressSpaceFileType_Read = 11605,
	//! NodeId of the node AddressSpaceFileType/Read/InputArguments.
	EnumNumericNodeId_AddressSpaceFileType_Read_InputArguments = 11606,
	//! NodeId of the node AddressSpaceFileType/Read/OutputArguments.
	EnumNumericNodeId_AddressSpaceFileType_Read_OutputArguments = 11607,
	//! NodeId of the node AddressSpaceFileType/Write.
	EnumNumericNodeId_AddressSpaceFileType_Write = 11608,
	//! NodeId of the node AddressSpaceFileType/Write/InputArguments.
	EnumNumericNodeId_AddressSpaceFileType_Write_InputArguments = 11609,
	//! NodeId of the node AddressSpaceFileType/GetPosition.
	EnumNumericNodeId_AddressSpaceFileType_GetPosition = 11610,
	//! NodeId of the node AddressSpaceFileType/GetPosition/InputArguments.
	EnumNumericNodeId_AddressSpaceFileType_GetPosition_InputArguments = 11611,
	//! NodeId of the node AddressSpaceFileType/GetPosition/OutputArguments.
	EnumNumericNodeId_AddressSpaceFileType_GetPosition_OutputArguments = 11612,
	//! NodeId of the node AddressSpaceFileType/SetPosition.
	EnumNumericNodeId_AddressSpaceFileType_SetPosition = 11613,
	//! NodeId of the node AddressSpaceFileType/SetPosition/InputArguments.
	EnumNumericNodeId_AddressSpaceFileType_SetPosition_InputArguments = 11614,
	//! NodeId of the node AddressSpaceFileType/ExportNamespace.
	EnumNumericNodeId_AddressSpaceFileType_ExportNamespace = 11615,
	//! NodeId of the object type NamespaceMetadataType.
	EnumNumericNodeId_NamespaceMetadataType = 11616,
	//! NodeId of the node NamespaceMetadataType/NamespaceUri.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceUri = 11617,
	//! NodeId of the node NamespaceMetadataType/NamespaceVersion.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceVersion = 11618,
	//! NodeId of the node NamespaceMetadataType/NamespacePublicationDate.
	EnumNumericNodeId_NamespaceMetadataType_NamespacePublicationDate = 11619,
	//! NodeId of the node NamespaceMetadataType/IsNamespaceSubset.
	EnumNumericNodeId_NamespaceMetadataType_IsNamespaceSubset = 11620,
	//! NodeId of the node NamespaceMetadataType/StaticNodeIdIdentifierTypes.
	EnumNumericNodeId_NamespaceMetadataType_StaticNodeIdIdentifierTypes = 11621,
	//! NodeId of the node NamespaceMetadataType/StaticNumericNodeIdRange.
	EnumNumericNodeId_NamespaceMetadataType_StaticNumericNodeIdRange = 11622,
	//! NodeId of the node NamespaceMetadataType/StaticStringNodeIdPattern.
	EnumNumericNodeId_NamespaceMetadataType_StaticStringNodeIdPattern = 11623,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile = 11624,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Size.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Size = 11625,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/OpenCount.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_OpenCount = 11628,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Open.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Open = 11629,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Open/InputArguments.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Open_InputArguments = 11630,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Open/OutputArguments.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Open_OutputArguments = 11631,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Close.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Close = 11632,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Close/InputArguments.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Close_InputArguments = 11633,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Read.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Read = 11634,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Read/InputArguments.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Read_InputArguments = 11635,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Read/OutputArguments.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Read_OutputArguments = 11636,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Write.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Write = 11637,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Write/InputArguments.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Write_InputArguments = 11638,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/GetPosition.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_GetPosition = 11639,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/GetPosition/InputArguments.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_GetPosition_InputArguments = 11640,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/GetPosition/OutputArguments.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_GetPosition_OutputArguments = 11641,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/SetPosition.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_SetPosition = 11642,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/SetPosition/InputArguments.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_SetPosition_InputArguments = 11643,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/ExportNamespace.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_ExportNamespace = 11644,
	//! NodeId of the object type NamespacesType.
	EnumNumericNodeId_NamespacesType = 11645,
	//! NodeId of the node NamespacesType/NamespaceIdentifier.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier = 11646,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceUri.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceUri = 11647,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceVersion.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceVersion = 11648,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespacePublicationDate.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespacePublicationDate = 11649,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/IsNamespaceSubset.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_IsNamespaceSubset = 11650,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/StaticNodeIdIdentifierTypes.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_StaticNodeIdIdentifierTypes = 11651,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/StaticNumericNodeIdRange.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_StaticNumericNodeIdRange = 11652,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/StaticStringNodeIdPattern.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_StaticStringNodeIdPattern = 11653,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile = 11654,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Size.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Size = 11655,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/OpenCount.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_OpenCount = 11658,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Open.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Open = 11659,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Open/InputArguments.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Open_InputArguments = 11660,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Open/OutputArguments.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Open_OutputArguments = 11661,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Close.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Close = 11662,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Close/InputArguments.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Close_InputArguments = 11663,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Read.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Read = 11664,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Read/InputArguments.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Read_InputArguments = 11665,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Read/OutputArguments.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Read_OutputArguments = 11666,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Write.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Write = 11667,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Write/InputArguments.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Write_InputArguments = 11668,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/GetPosition.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_GetPosition = 11669,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/GetPosition/InputArguments.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_GetPosition_InputArguments = 11670,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/GetPosition/OutputArguments.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_GetPosition_OutputArguments = 11671,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/SetPosition.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_SetPosition = 11672,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/SetPosition/InputArguments.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_SetPosition_InputArguments = 11673,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/ExportNamespace.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_ExportNamespace = 11674,
	//! NodeId of the node NamespacesType/AddressSpaceFile.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile = 11675,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Size.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Size = 11676,
	//! NodeId of the node NamespacesType/AddressSpaceFile/OpenCount.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_OpenCount = 11679,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Open.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Open = 11680,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Open/InputArguments.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Open_InputArguments = 11681,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Open/OutputArguments.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Open_OutputArguments = 11682,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Close.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Close = 11683,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Close/InputArguments.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Close_InputArguments = 11684,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Read.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Read = 11685,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Read/InputArguments.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Read_InputArguments = 11686,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Read/OutputArguments.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Read_OutputArguments = 11687,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Write.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Write = 11688,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Write/InputArguments.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Write_InputArguments = 11689,
	//! NodeId of the node NamespacesType/AddressSpaceFile/GetPosition.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_GetPosition = 11690,
	//! NodeId of the node NamespacesType/AddressSpaceFile/GetPosition/InputArguments.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_GetPosition_InputArguments = 11691,
	//! NodeId of the node NamespacesType/AddressSpaceFile/GetPosition/OutputArguments.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_GetPosition_OutputArguments = 11692,
	//! NodeId of the node NamespacesType/AddressSpaceFile/SetPosition.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_SetPosition = 11693,
	//! NodeId of the node NamespacesType/AddressSpaceFile/SetPosition/InputArguments.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_SetPosition_InputArguments = 11694,
	//! NodeId of the node NamespacesType/AddressSpaceFile/ExportNamespace.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_ExportNamespace = 11695,
	//! NodeId of the node SystemStatusChangeEventType/SystemState.
	EnumNumericNodeId_SystemStatusChangeEventType_SystemState = 11696,
	//! NodeId of the node SamplingIntervalDiagnosticsType/SampledMonitoredItemsCount.
	EnumNumericNodeId_SamplingIntervalDiagnosticsType_SampledMonitoredItemsCount = 11697,
	//! NodeId of the node SamplingIntervalDiagnosticsType/MaxSampledMonitoredItemsCount.
	EnumNumericNodeId_SamplingIntervalDiagnosticsType_MaxSampledMonitoredItemsCount = 11698,
	//! NodeId of the node SamplingIntervalDiagnosticsType/DisabledMonitoredItemsSamplingCount.
	EnumNumericNodeId_SamplingIntervalDiagnosticsType_DisabledMonitoredItemsSamplingCount = 11699,
	//! NodeId of the node OptionSetType/BitMask.
	EnumNumericNodeId_OptionSetType_BitMask = 11701,
	//! NodeId of the node Server/ServerCapabilities/MaxArrayLength.
	EnumNumericNodeId_Server_ServerCapabilities_MaxArrayLength = 11702,
	//! NodeId of the node Server/ServerCapabilities/MaxStringLength.
	EnumNumericNodeId_Server_ServerCapabilities_MaxStringLength = 11703,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits = 11704,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerRead.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerRead = 11705,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerWrite.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerWrite = 11707,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerMethodCall.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerMethodCall = 11709,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerBrowse.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerBrowse = 11710,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerRegisterNodes.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerRegisterNodes = 11711,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerTranslateBrowsePathsToNodeIds.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerTranslateBrowsePathsToNodeIds = 11712,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerNodeManagement.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerNodeManagement = 11713,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxMonitoredItemsPerCall.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxMonitoredItemsPerCall = 11714,
	//! NodeId of the node Server/Namespaces.
	EnumNumericNodeId_Server_Namespaces = 11715,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile = 11716,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Size.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Size = 11717,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/OpenCount.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_OpenCount = 11720,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Open.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Open = 11721,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Open/InputArguments.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Open_InputArguments = 11722,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Open/OutputArguments.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Open_OutputArguments = 11723,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Close.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Close = 11724,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Close/InputArguments.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Close_InputArguments = 11725,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Read.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Read = 11726,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Read/InputArguments.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Read_InputArguments = 11727,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Read/OutputArguments.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Read_OutputArguments = 11728,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Write.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Write = 11729,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Write/InputArguments.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Write_InputArguments = 11730,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/GetPosition.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_GetPosition = 11731,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/GetPosition/InputArguments.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_GetPosition_InputArguments = 11732,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/GetPosition/OutputArguments.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_GetPosition_OutputArguments = 11733,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/SetPosition.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_SetPosition = 11734,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/SetPosition/InputArguments.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_SetPosition_InputArguments = 11735,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/ExportNamespace.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_ExportNamespace = 11736,
	//! NodeId of the data type BitFieldMaskDataType.
	EnumNumericNodeId_BitFieldMaskDataType = 11737,
	//! NodeId of the object type SystemOffNormalAlarmType.
	EnumNumericNodeId_SystemOffNormalAlarmType = 11753,
	//! NodeId of the node SystemOffNormalAlarmType/EventId.
	EnumNumericNodeId_SystemOffNormalAlarmType_EventId = 11754,
	//! NodeId of the node SystemOffNormalAlarmType/EventType.
	EnumNumericNodeId_SystemOffNormalAlarmType_EventType = 11755,
	//! NodeId of the node SystemOffNormalAlarmType/SourceNode.
	EnumNumericNodeId_SystemOffNormalAlarmType_SourceNode = 11756,
	//! NodeId of the node SystemOffNormalAlarmType/SourceName.
	EnumNumericNodeId_SystemOffNormalAlarmType_SourceName = 11757,
	//! NodeId of the node SystemOffNormalAlarmType/Time.
	EnumNumericNodeId_SystemOffNormalAlarmType_Time = 11758,
	//! NodeId of the node SystemOffNormalAlarmType/ReceiveTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_ReceiveTime = 11759,
	//! NodeId of the node SystemOffNormalAlarmType/LocalTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_LocalTime = 11760,
	//! NodeId of the node SystemOffNormalAlarmType/Message.
	EnumNumericNodeId_SystemOffNormalAlarmType_Message = 11761,
	//! NodeId of the node SystemOffNormalAlarmType/Severity.
	EnumNumericNodeId_SystemOffNormalAlarmType_Severity = 11762,
	//! NodeId of the node SystemOffNormalAlarmType/ConditionClassId.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConditionClassId = 11763,
	//! NodeId of the node SystemOffNormalAlarmType/ConditionClassName.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConditionClassName = 11764,
	//! NodeId of the node SystemOffNormalAlarmType/ConditionName.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConditionName = 11765,
	//! NodeId of the node SystemOffNormalAlarmType/BranchId.
	EnumNumericNodeId_SystemOffNormalAlarmType_BranchId = 11766,
	//! NodeId of the node SystemOffNormalAlarmType/Retain.
	EnumNumericNodeId_SystemOffNormalAlarmType_Retain = 11767,
	//! NodeId of the node SystemOffNormalAlarmType/EnabledState.
	EnumNumericNodeId_SystemOffNormalAlarmType_EnabledState = 11768,
	//! NodeId of the node SystemOffNormalAlarmType/EnabledState/Id.
	EnumNumericNodeId_SystemOffNormalAlarmType_EnabledState_Id = 11769,
	//! NodeId of the node SystemOffNormalAlarmType/EnabledState/Name.
	EnumNumericNodeId_SystemOffNormalAlarmType_EnabledState_Name = 11770,
	//! NodeId of the node SystemOffNormalAlarmType/EnabledState/Number.
	EnumNumericNodeId_SystemOffNormalAlarmType_EnabledState_Number = 11771,
	//! NodeId of the node SystemOffNormalAlarmType/EnabledState/EffectiveDisplayName.
	EnumNumericNodeId_SystemOffNormalAlarmType_EnabledState_EffectiveDisplayName = 11772,
	//! NodeId of the node SystemOffNormalAlarmType/EnabledState/TransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_EnabledState_TransitionTime = 11773,
	//! NodeId of the node SystemOffNormalAlarmType/EnabledState/EffectiveTransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_EnabledState_EffectiveTransitionTime = 11774,
	//! NodeId of the node SystemOffNormalAlarmType/EnabledState/TrueState.
	EnumNumericNodeId_SystemOffNormalAlarmType_EnabledState_TrueState = 11775,
	//! NodeId of the node SystemOffNormalAlarmType/EnabledState/FalseState.
	EnumNumericNodeId_SystemOffNormalAlarmType_EnabledState_FalseState = 11776,
	//! NodeId of the node SystemOffNormalAlarmType/Quality.
	EnumNumericNodeId_SystemOffNormalAlarmType_Quality = 11777,
	//! NodeId of the node SystemOffNormalAlarmType/Quality/SourceTimestamp.
	EnumNumericNodeId_SystemOffNormalAlarmType_Quality_SourceTimestamp = 11778,
	//! NodeId of the node SystemOffNormalAlarmType/LastSeverity.
	EnumNumericNodeId_SystemOffNormalAlarmType_LastSeverity = 11779,
	//! NodeId of the node SystemOffNormalAlarmType/LastSeverity/SourceTimestamp.
	EnumNumericNodeId_SystemOffNormalAlarmType_LastSeverity_SourceTimestamp = 11780,
	//! NodeId of the node SystemOffNormalAlarmType/Comment.
	EnumNumericNodeId_SystemOffNormalAlarmType_Comment = 11781,
	//! NodeId of the node SystemOffNormalAlarmType/Comment/SourceTimestamp.
	EnumNumericNodeId_SystemOffNormalAlarmType_Comment_SourceTimestamp = 11782,
	//! NodeId of the node SystemOffNormalAlarmType/ClientUserId.
	EnumNumericNodeId_SystemOffNormalAlarmType_ClientUserId = 11783,
	//! NodeId of the node SystemOffNormalAlarmType/Disable.
	EnumNumericNodeId_SystemOffNormalAlarmType_Disable = 11784,
	//! NodeId of the node SystemOffNormalAlarmType/Enable.
	EnumNumericNodeId_SystemOffNormalAlarmType_Enable = 11785,
	//! NodeId of the node SystemOffNormalAlarmType/AddComment.
	EnumNumericNodeId_SystemOffNormalAlarmType_AddComment = 11786,
	//! NodeId of the node SystemOffNormalAlarmType/AddComment/InputArguments.
	EnumNumericNodeId_SystemOffNormalAlarmType_AddComment_InputArguments = 11787,
	//! NodeId of the node SystemOffNormalAlarmType/ConditionRefresh.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConditionRefresh = 11788,
	//! NodeId of the node SystemOffNormalAlarmType/ConditionRefresh/InputArguments.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConditionRefresh_InputArguments = 11789,
	//! NodeId of the node SystemOffNormalAlarmType/AckedState.
	EnumNumericNodeId_SystemOffNormalAlarmType_AckedState = 11790,
	//! NodeId of the node SystemOffNormalAlarmType/AckedState/Id.
	EnumNumericNodeId_SystemOffNormalAlarmType_AckedState_Id = 11791,
	//! NodeId of the node SystemOffNormalAlarmType/AckedState/Name.
	EnumNumericNodeId_SystemOffNormalAlarmType_AckedState_Name = 11792,
	//! NodeId of the node SystemOffNormalAlarmType/AckedState/Number.
	EnumNumericNodeId_SystemOffNormalAlarmType_AckedState_Number = 11793,
	//! NodeId of the node SystemOffNormalAlarmType/AckedState/EffectiveDisplayName.
	EnumNumericNodeId_SystemOffNormalAlarmType_AckedState_EffectiveDisplayName = 11794,
	//! NodeId of the node SystemOffNormalAlarmType/AckedState/TransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_AckedState_TransitionTime = 11795,
	//! NodeId of the node SystemOffNormalAlarmType/AckedState/EffectiveTransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_AckedState_EffectiveTransitionTime = 11796,
	//! NodeId of the node SystemOffNormalAlarmType/AckedState/TrueState.
	EnumNumericNodeId_SystemOffNormalAlarmType_AckedState_TrueState = 11797,
	//! NodeId of the node SystemOffNormalAlarmType/AckedState/FalseState.
	EnumNumericNodeId_SystemOffNormalAlarmType_AckedState_FalseState = 11798,
	//! NodeId of the node SystemOffNormalAlarmType/ConfirmedState.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConfirmedState = 11799,
	//! NodeId of the node SystemOffNormalAlarmType/ConfirmedState/Id.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConfirmedState_Id = 11800,
	//! NodeId of the node SystemOffNormalAlarmType/ConfirmedState/Name.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConfirmedState_Name = 11801,
	//! NodeId of the node SystemOffNormalAlarmType/ConfirmedState/Number.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConfirmedState_Number = 11802,
	//! NodeId of the node SystemOffNormalAlarmType/ConfirmedState/EffectiveDisplayName.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConfirmedState_EffectiveDisplayName = 11803,
	//! NodeId of the node SystemOffNormalAlarmType/ConfirmedState/TransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConfirmedState_TransitionTime = 11804,
	//! NodeId of the node SystemOffNormalAlarmType/ConfirmedState/EffectiveTransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConfirmedState_EffectiveTransitionTime = 11805,
	//! NodeId of the node SystemOffNormalAlarmType/ConfirmedState/TrueState.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConfirmedState_TrueState = 11806,
	//! NodeId of the node SystemOffNormalAlarmType/ConfirmedState/FalseState.
	EnumNumericNodeId_SystemOffNormalAlarmType_ConfirmedState_FalseState = 11807,
	//! NodeId of the node SystemOffNormalAlarmType/Acknowledge.
	EnumNumericNodeId_SystemOffNormalAlarmType_Acknowledge = 11808,
	//! NodeId of the node SystemOffNormalAlarmType/Acknowledge/InputArguments.
	EnumNumericNodeId_SystemOffNormalAlarmType_Acknowledge_InputArguments = 11809,
	//! NodeId of the node SystemOffNormalAlarmType/Confirm.
	EnumNumericNodeId_SystemOffNormalAlarmType_Confirm = 11810,
	//! NodeId of the node SystemOffNormalAlarmType/Confirm/InputArguments.
	EnumNumericNodeId_SystemOffNormalAlarmType_Confirm_InputArguments = 11811,
	//! NodeId of the node SystemOffNormalAlarmType/ActiveState.
	EnumNumericNodeId_SystemOffNormalAlarmType_ActiveState = 11812,
	//! NodeId of the node SystemOffNormalAlarmType/ActiveState/Id.
	EnumNumericNodeId_SystemOffNormalAlarmType_ActiveState_Id = 11813,
	//! NodeId of the node SystemOffNormalAlarmType/ActiveState/Name.
	EnumNumericNodeId_SystemOffNormalAlarmType_ActiveState_Name = 11814,
	//! NodeId of the node SystemOffNormalAlarmType/ActiveState/Number.
	EnumNumericNodeId_SystemOffNormalAlarmType_ActiveState_Number = 11815,
	//! NodeId of the node SystemOffNormalAlarmType/ActiveState/EffectiveDisplayName.
	EnumNumericNodeId_SystemOffNormalAlarmType_ActiveState_EffectiveDisplayName = 11816,
	//! NodeId of the node SystemOffNormalAlarmType/ActiveState/TransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_ActiveState_TransitionTime = 11817,
	//! NodeId of the node SystemOffNormalAlarmType/ActiveState/EffectiveTransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_ActiveState_EffectiveTransitionTime = 11818,
	//! NodeId of the node SystemOffNormalAlarmType/ActiveState/TrueState.
	EnumNumericNodeId_SystemOffNormalAlarmType_ActiveState_TrueState = 11819,
	//! NodeId of the node SystemOffNormalAlarmType/ActiveState/FalseState.
	EnumNumericNodeId_SystemOffNormalAlarmType_ActiveState_FalseState = 11820,
	//! NodeId of the node SystemOffNormalAlarmType/InputNode.
	EnumNumericNodeId_SystemOffNormalAlarmType_InputNode = 11821,
	//! NodeId of the node SystemOffNormalAlarmType/SuppressedState.
	EnumNumericNodeId_SystemOffNormalAlarmType_SuppressedState = 11822,
	//! NodeId of the node SystemOffNormalAlarmType/SuppressedState/Id.
	EnumNumericNodeId_SystemOffNormalAlarmType_SuppressedState_Id = 11823,
	//! NodeId of the node SystemOffNormalAlarmType/SuppressedState/Name.
	EnumNumericNodeId_SystemOffNormalAlarmType_SuppressedState_Name = 11824,
	//! NodeId of the node SystemOffNormalAlarmType/SuppressedState/Number.
	EnumNumericNodeId_SystemOffNormalAlarmType_SuppressedState_Number = 11825,
	//! NodeId of the node SystemOffNormalAlarmType/SuppressedState/EffectiveDisplayName.
	EnumNumericNodeId_SystemOffNormalAlarmType_SuppressedState_EffectiveDisplayName = 11826,
	//! NodeId of the node SystemOffNormalAlarmType/SuppressedState/TransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_SuppressedState_TransitionTime = 11827,
	//! NodeId of the node SystemOffNormalAlarmType/SuppressedState/EffectiveTransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_SuppressedState_EffectiveTransitionTime = 11828,
	//! NodeId of the node SystemOffNormalAlarmType/SuppressedState/TrueState.
	EnumNumericNodeId_SystemOffNormalAlarmType_SuppressedState_TrueState = 11829,
	//! NodeId of the node SystemOffNormalAlarmType/SuppressedState/FalseState.
	EnumNumericNodeId_SystemOffNormalAlarmType_SuppressedState_FalseState = 11830,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState = 11831,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/CurrentState.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_CurrentState = 11832,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/CurrentState/Id.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_CurrentState_Id = 11833,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/CurrentState/Name.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_CurrentState_Name = 11834,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/CurrentState/Number.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_CurrentState_Number = 11835,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/CurrentState/EffectiveDisplayName.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_CurrentState_EffectiveDisplayName = 11836,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/LastTransition.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_LastTransition = 11837,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/LastTransition/Id.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_LastTransition_Id = 11838,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/LastTransition/Name.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_LastTransition_Name = 11839,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/LastTransition/Number.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_LastTransition_Number = 11840,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/LastTransition/TransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_LastTransition_TransitionTime = 11841,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/LastTransition/EffectiveTransitionTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_LastTransition_EffectiveTransitionTime = 11842,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/UnshelveTime.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_UnshelveTime = 11843,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/Unshelve.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_Unshelve = 11844,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/OneShotShelve.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_OneShotShelve = 11845,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/TimedShelve.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_TimedShelve = 11846,
	//! NodeId of the node SystemOffNormalAlarmType/ShelvingState/TimedShelve/InputArguments.
	EnumNumericNodeId_SystemOffNormalAlarmType_ShelvingState_TimedShelve_InputArguments = 11847,
	//! NodeId of the node SystemOffNormalAlarmType/SuppressedOrShelved.
	EnumNumericNodeId_SystemOffNormalAlarmType_SuppressedOrShelved = 11848,
	//! NodeId of the node SystemOffNormalAlarmType/MaxTimeShelved.
	EnumNumericNodeId_SystemOffNormalAlarmType_MaxTimeShelved = 11849,
	//! NodeId of the node SystemOffNormalAlarmType/NormalState.
	EnumNumericNodeId_SystemOffNormalAlarmType_NormalState = 11850,
	//! NodeId of the node AuditConditionCommentEventType/Comment.
	EnumNumericNodeId_AuditConditionCommentEventType_Comment = 11851,
	//! NodeId of the node AuditConditionRespondEventType/SelectedResponse.
	EnumNumericNodeId_AuditConditionRespondEventType_SelectedResponse = 11852,
	//! NodeId of the node AuditConditionAcknowledgeEventType/Comment.
	EnumNumericNodeId_AuditConditionAcknowledgeEventType_Comment = 11853,
	//! NodeId of the node AuditConditionConfirmEventType/Comment.
	EnumNumericNodeId_AuditConditionConfirmEventType_Comment = 11854,
	//! NodeId of the node AuditConditionShelvingEventType/ShelvingTime.
	EnumNumericNodeId_AuditConditionShelvingEventType_ShelvingTime = 11855,
	//! NodeId of the object type AuditProgramTransitionEventType.
	EnumNumericNodeId_AuditProgramTransitionEventType = 11856,
	//! NodeId of the node AuditProgramTransitionEventType/EventId.
	EnumNumericNodeId_AuditProgramTransitionEventType_EventId = 11857,
	//! NodeId of the node AuditProgramTransitionEventType/EventType.
	EnumNumericNodeId_AuditProgramTransitionEventType_EventType = 11858,
	//! NodeId of the node AuditProgramTransitionEventType/SourceNode.
	EnumNumericNodeId_AuditProgramTransitionEventType_SourceNode = 11859,
	//! NodeId of the node AuditProgramTransitionEventType/SourceName.
	EnumNumericNodeId_AuditProgramTransitionEventType_SourceName = 11860,
	//! NodeId of the node AuditProgramTransitionEventType/Time.
	EnumNumericNodeId_AuditProgramTransitionEventType_Time = 11861,
	//! NodeId of the node AuditProgramTransitionEventType/ReceiveTime.
	EnumNumericNodeId_AuditProgramTransitionEventType_ReceiveTime = 11862,
	//! NodeId of the node AuditProgramTransitionEventType/LocalTime.
	EnumNumericNodeId_AuditProgramTransitionEventType_LocalTime = 11863,
	//! NodeId of the node AuditProgramTransitionEventType/Message.
	EnumNumericNodeId_AuditProgramTransitionEventType_Message = 11864,
	//! NodeId of the node AuditProgramTransitionEventType/Severity.
	EnumNumericNodeId_AuditProgramTransitionEventType_Severity = 11865,
	//! NodeId of the node AuditProgramTransitionEventType/ActionTimeStamp.
	EnumNumericNodeId_AuditProgramTransitionEventType_ActionTimeStamp = 11866,
	//! NodeId of the node AuditProgramTransitionEventType/Status.
	EnumNumericNodeId_AuditProgramTransitionEventType_Status = 11867,
	//! NodeId of the node AuditProgramTransitionEventType/ServerId.
	EnumNumericNodeId_AuditProgramTransitionEventType_ServerId = 11868,
	//! NodeId of the node AuditProgramTransitionEventType/ClientAuditEntryId.
	EnumNumericNodeId_AuditProgramTransitionEventType_ClientAuditEntryId = 11869,
	//! NodeId of the node AuditProgramTransitionEventType/ClientUserId.
	EnumNumericNodeId_AuditProgramTransitionEventType_ClientUserId = 11870,
	//! NodeId of the node AuditProgramTransitionEventType/MethodId.
	EnumNumericNodeId_AuditProgramTransitionEventType_MethodId = 11871,
	//! NodeId of the node AuditProgramTransitionEventType/InputArguments.
	EnumNumericNodeId_AuditProgramTransitionEventType_InputArguments = 11872,
	//! NodeId of the node AuditProgramTransitionEventType/OldStateId.
	EnumNumericNodeId_AuditProgramTransitionEventType_OldStateId = 11873,
	//! NodeId of the node AuditProgramTransitionEventType/NewStateId.
	EnumNumericNodeId_AuditProgramTransitionEventType_NewStateId = 11874,
	//! NodeId of the node AuditProgramTransitionEventType/TransitionNumber.
	EnumNumericNodeId_AuditProgramTransitionEventType_TransitionNumber = 11875,
	//! NodeId of the node HistoricalDataConfigurationType/AggregateFunctions.
	EnumNumericNodeId_HistoricalDataConfigurationType_AggregateFunctions = 11876,
	//! NodeId of the node HAConfiguration/AggregateFunctions.
	EnumNumericNodeId_HAConfiguration_AggregateFunctions = 11877,
	//! NodeId of the node NodeClass/EnumValues.
	EnumNumericNodeId_NodeClass_EnumValues = 11878,
	//! NodeId of the data type InstanceNode.
	EnumNumericNodeId_InstanceNode = 11879,
	//! NodeId of the data type TypeNode.
	EnumNumericNodeId_TypeNode = 11880,
	//! NodeId of the node NodeAttributesMask/EnumValues.
	EnumNumericNodeId_NodeAttributesMask_EnumValues = 11881,
	//! NodeId of the node AttributeWriteMask/EnumValues.
	EnumNumericNodeId_AttributeWriteMask_EnumValues = 11882,
	//! NodeId of the node BrowseResultMask/EnumValues.
	EnumNumericNodeId_BrowseResultMask_EnumValues = 11883,
	//! NodeId of the node HistoryUpdateType/EnumValues.
	EnumNumericNodeId_HistoryUpdateType_EnumValues = 11884,
	//! NodeId of the node PerformUpdateType/EnumValues.
	EnumNumericNodeId_PerformUpdateType_EnumValues = 11885,
	//! NodeId of the node EnumeratedTestType/EnumValues.
	EnumNumericNodeId_EnumeratedTestType_EnumValues = 11886,
	//! NodeId of the node InstanceNode/Encoding/DefaultXml.
	EnumNumericNodeId_InstanceNode_Encoding_DefaultXml = 11887,
	//! NodeId of the node TypeNode/Encoding/DefaultXml.
	EnumNumericNodeId_TypeNode_Encoding_DefaultXml = 11888,
	//! NodeId of the node InstanceNode/Encoding/DefaultBinary.
	EnumNumericNodeId_InstanceNode_Encoding_DefaultBinary = 11889,
	//! NodeId of the node TypeNode/Encoding/DefaultBinary.
	EnumNumericNodeId_TypeNode_Encoding_DefaultBinary = 11890,
	//! NodeId of the node SessionDiagnosticsObjectType/SessionDiagnostics/UnauthorizedRequestCount.
	EnumNumericNodeId_SessionDiagnosticsObjectType_SessionDiagnostics_UnauthorizedRequestCount = 11891,
	//! NodeId of the node SessionDiagnosticsVariableType/UnauthorizedRequestCount.
	EnumNumericNodeId_SessionDiagnosticsVariableType_UnauthorizedRequestCount = 11892,
	//! NodeId of the data type OpenFileMode.
	EnumNumericNodeId_OpenFileMode = 11939,
	//! NodeId of the node OpenFileMode/EnumValues.
	EnumNumericNodeId_OpenFileMode_EnumValues = 11940,
	//! NodeId of the data type ModelChangeStructureVerbMask.
	EnumNumericNodeId_ModelChangeStructureVerbMask = 11941,
	//! NodeId of the node ModelChangeStructureVerbMask/EnumValues.
	EnumNumericNodeId_ModelChangeStructureVerbMask_EnumValues = 11942,
	//! NodeId of the data type EndpointUrlListDataType.
	EnumNumericNodeId_EndpointUrlListDataType = 11943,
	//! NodeId of the data type NetworkGroupDataType.
	EnumNumericNodeId_NetworkGroupDataType = 11944,
	//! NodeId of the object type NonTransparentNetworkRedundancyType.
	EnumNumericNodeId_NonTransparentNetworkRedundancyType = 11945,
	//! NodeId of the node NonTransparentNetworkRedundancyType/RedundancySupport.
	EnumNumericNodeId_NonTransparentNetworkRedundancyType_RedundancySupport = 11946,
	//! NodeId of the node NonTransparentNetworkRedundancyType/ServerUriArray.
	EnumNumericNodeId_NonTransparentNetworkRedundancyType_ServerUriArray = 11947,
	//! NodeId of the node NonTransparentNetworkRedundancyType/ServerNetworkGroups.
	EnumNumericNodeId_NonTransparentNetworkRedundancyType_ServerNetworkGroups = 11948,
	//! NodeId of the node EndpointUrlListDataType/Encoding/DefaultXml.
	EnumNumericNodeId_EndpointUrlListDataType_Encoding_DefaultXml = 11949,
	//! NodeId of the node NetworkGroupDataType/Encoding/DefaultXml.
	EnumNumericNodeId_NetworkGroupDataType_Encoding_DefaultXml = 11950,
	//! NodeId of the node OpcUa/XmlSchema/EndpointUrlListDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_EndpointUrlListDataType = 11951,
	//! NodeId of the node OpcUa/XmlSchema/EndpointUrlListDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_EndpointUrlListDataType_DataTypeVersion = 11952,
	//! NodeId of the node OpcUa/XmlSchema/EndpointUrlListDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_EndpointUrlListDataType_DictionaryFragment = 11953,
	//! NodeId of the node OpcUa/XmlSchema/NetworkGroupDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_NetworkGroupDataType = 11954,
	//! NodeId of the node OpcUa/XmlSchema/NetworkGroupDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_NetworkGroupDataType_DataTypeVersion = 11955,
	//! NodeId of the node OpcUa/XmlSchema/NetworkGroupDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_NetworkGroupDataType_DictionaryFragment = 11956,
	//! NodeId of the node EndpointUrlListDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_EndpointUrlListDataType_Encoding_DefaultBinary = 11957,
	//! NodeId of the node NetworkGroupDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_NetworkGroupDataType_Encoding_DefaultBinary = 11958,
	//! NodeId of the node OpcUa/BinarySchema/EndpointUrlListDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_EndpointUrlListDataType = 11959,
	//! NodeId of the node OpcUa/BinarySchema/EndpointUrlListDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_EndpointUrlListDataType_DataTypeVersion = 11960,
	//! NodeId of the node OpcUa/BinarySchema/EndpointUrlListDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_EndpointUrlListDataType_DictionaryFragment = 11961,
	//! NodeId of the node OpcUa/BinarySchema/NetworkGroupDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_NetworkGroupDataType = 11962,
	//! NodeId of the node OpcUa/BinarySchema/NetworkGroupDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_NetworkGroupDataType_DataTypeVersion = 11963,
	//! NodeId of the node OpcUa/BinarySchema/NetworkGroupDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_NetworkGroupDataType_DictionaryFragment = 11964,
	//! NodeId of the variable type ArrayItemType.
	EnumNumericNodeId_ArrayItemType = 12021,
	//! NodeId of the node ArrayItemType/Definition.
	EnumNumericNodeId_ArrayItemType_Definition = 12022,
	//! NodeId of the node ArrayItemType/ValuePrecision.
	EnumNumericNodeId_ArrayItemType_ValuePrecision = 12023,
	//! NodeId of the node ArrayItemType/InstrumentRange.
	EnumNumericNodeId_ArrayItemType_InstrumentRange = 12024,
	//! NodeId of the node ArrayItemType/EURange.
	EnumNumericNodeId_ArrayItemType_EURange = 12025,
	//! NodeId of the node ArrayItemType/EngineeringUnits.
	EnumNumericNodeId_ArrayItemType_EngineeringUnits = 12026,
	//! NodeId of the node ArrayItemType/Title.
	EnumNumericNodeId_ArrayItemType_Title = 12027,
	//! NodeId of the node ArrayItemType/AxisScaleType.
	EnumNumericNodeId_ArrayItemType_AxisScaleType = 12028,
	//! NodeId of the variable type YArrayItemType.
	EnumNumericNodeId_YArrayItemType = 12029,
	//! NodeId of the node YArrayItemType/Definition.
	EnumNumericNodeId_YArrayItemType_Definition = 12030,
	//! NodeId of the node YArrayItemType/ValuePrecision.
	EnumNumericNodeId_YArrayItemType_ValuePrecision = 12031,
	//! NodeId of the node YArrayItemType/InstrumentRange.
	EnumNumericNodeId_YArrayItemType_InstrumentRange = 12032,
	//! NodeId of the node YArrayItemType/EURange.
	EnumNumericNodeId_YArrayItemType_EURange = 12033,
	//! NodeId of the node YArrayItemType/EngineeringUnits.
	EnumNumericNodeId_YArrayItemType_EngineeringUnits = 12034,
	//! NodeId of the node YArrayItemType/Title.
	EnumNumericNodeId_YArrayItemType_Title = 12035,
	//! NodeId of the node YArrayItemType/AxisScaleType.
	EnumNumericNodeId_YArrayItemType_AxisScaleType = 12036,
	//! NodeId of the node YArrayItemType/XAxisDefinition.
	EnumNumericNodeId_YArrayItemType_XAxisDefinition = 12037,
	//! NodeId of the variable type XYArrayItemType.
	EnumNumericNodeId_XYArrayItemType = 12038,
	//! NodeId of the node XYArrayItemType/Definition.
	EnumNumericNodeId_XYArrayItemType_Definition = 12039,
	//! NodeId of the node XYArrayItemType/ValuePrecision.
	EnumNumericNodeId_XYArrayItemType_ValuePrecision = 12040,
	//! NodeId of the node XYArrayItemType/InstrumentRange.
	EnumNumericNodeId_XYArrayItemType_InstrumentRange = 12041,
	//! NodeId of the node XYArrayItemType/EURange.
	EnumNumericNodeId_XYArrayItemType_EURange = 12042,
	//! NodeId of the node XYArrayItemType/EngineeringUnits.
	EnumNumericNodeId_XYArrayItemType_EngineeringUnits = 12043,
	//! NodeId of the node XYArrayItemType/Title.
	EnumNumericNodeId_XYArrayItemType_Title = 12044,
	//! NodeId of the node XYArrayItemType/AxisScaleType.
	EnumNumericNodeId_XYArrayItemType_AxisScaleType = 12045,
	//! NodeId of the node XYArrayItemType/XAxisDefinition.
	EnumNumericNodeId_XYArrayItemType_XAxisDefinition = 12046,
	//! NodeId of the variable type ImageItemType.
	EnumNumericNodeId_ImageItemType = 12047,
	//! NodeId of the node ImageItemType/Definition.
	EnumNumericNodeId_ImageItemType_Definition = 12048,
	//! NodeId of the node ImageItemType/ValuePrecision.
	EnumNumericNodeId_ImageItemType_ValuePrecision = 12049,
	//! NodeId of the node ImageItemType/InstrumentRange.
	EnumNumericNodeId_ImageItemType_InstrumentRange = 12050,
	//! NodeId of the node ImageItemType/EURange.
	EnumNumericNodeId_ImageItemType_EURange = 12051,
	//! NodeId of the node ImageItemType/EngineeringUnits.
	EnumNumericNodeId_ImageItemType_EngineeringUnits = 12052,
	//! NodeId of the node ImageItemType/Title.
	EnumNumericNodeId_ImageItemType_Title = 12053,
	//! NodeId of the node ImageItemType/AxisScaleType.
	EnumNumericNodeId_ImageItemType_AxisScaleType = 12054,
	//! NodeId of the node ImageItemType/XAxisDefinition.
	EnumNumericNodeId_ImageItemType_XAxisDefinition = 12055,
	//! NodeId of the node ImageItemType/YAxisDefinition.
	EnumNumericNodeId_ImageItemType_YAxisDefinition = 12056,
	//! NodeId of the variable type CubeItemType.
	EnumNumericNodeId_CubeItemType = 12057,
	//! NodeId of the node CubeItemType/Definition.
	EnumNumericNodeId_CubeItemType_Definition = 12058,
	//! NodeId of the node CubeItemType/ValuePrecision.
	EnumNumericNodeId_CubeItemType_ValuePrecision = 12059,
	//! NodeId of the node CubeItemType/InstrumentRange.
	EnumNumericNodeId_CubeItemType_InstrumentRange = 12060,
	//! NodeId of the node CubeItemType/EURange.
	EnumNumericNodeId_CubeItemType_EURange = 12061,
	//! NodeId of the node CubeItemType/EngineeringUnits.
	EnumNumericNodeId_CubeItemType_EngineeringUnits = 12062,
	//! NodeId of the node CubeItemType/Title.
	EnumNumericNodeId_CubeItemType_Title = 12063,
	//! NodeId of the node CubeItemType/AxisScaleType.
	EnumNumericNodeId_CubeItemType_AxisScaleType = 12064,
	//! NodeId of the node CubeItemType/XAxisDefinition.
	EnumNumericNodeId_CubeItemType_XAxisDefinition = 12065,
	//! NodeId of the node CubeItemType/YAxisDefinition.
	EnumNumericNodeId_CubeItemType_YAxisDefinition = 12066,
	//! NodeId of the node CubeItemType/ZAxisDefinition.
	EnumNumericNodeId_CubeItemType_ZAxisDefinition = 12067,
	//! NodeId of the variable type NDimensionArrayItemType.
	EnumNumericNodeId_NDimensionArrayItemType = 12068,
	//! NodeId of the node NDimensionArrayItemType/Definition.
	EnumNumericNodeId_NDimensionArrayItemType_Definition = 12069,
	//! NodeId of the node NDimensionArrayItemType/ValuePrecision.
	EnumNumericNodeId_NDimensionArrayItemType_ValuePrecision = 12070,
	//! NodeId of the node NDimensionArrayItemType/InstrumentRange.
	EnumNumericNodeId_NDimensionArrayItemType_InstrumentRange = 12071,
	//! NodeId of the node NDimensionArrayItemType/EURange.
	EnumNumericNodeId_NDimensionArrayItemType_EURange = 12072,
	//! NodeId of the node NDimensionArrayItemType/EngineeringUnits.
	EnumNumericNodeId_NDimensionArrayItemType_EngineeringUnits = 12073,
	//! NodeId of the node NDimensionArrayItemType/Title.
	EnumNumericNodeId_NDimensionArrayItemType_Title = 12074,
	//! NodeId of the node NDimensionArrayItemType/AxisScaleType.
	EnumNumericNodeId_NDimensionArrayItemType_AxisScaleType = 12075,
	//! NodeId of the node NDimensionArrayItemType/AxisDefinition.
	EnumNumericNodeId_NDimensionArrayItemType_AxisDefinition = 12076,
	//! NodeId of the data type AxisScaleEnumeration.
	EnumNumericNodeId_AxisScaleEnumeration = 12077,
	//! NodeId of the node AxisScaleEnumeration/EnumStrings.
	EnumNumericNodeId_AxisScaleEnumeration_EnumStrings = 12078,
	//! NodeId of the data type AxisInformation.
	EnumNumericNodeId_AxisInformation = 12079,
	//! NodeId of the data type XVType.
	EnumNumericNodeId_XVType = 12080,
	//! NodeId of the node AxisInformation/Encoding/DefaultXml.
	EnumNumericNodeId_AxisInformation_Encoding_DefaultXml = 12081,
	//! NodeId of the node XVType/Encoding/DefaultXml.
	EnumNumericNodeId_XVType_Encoding_DefaultXml = 12082,
	//! NodeId of the node OpcUa/XmlSchema/AxisInformation.
	EnumNumericNodeId_OpcUa_XmlSchema_AxisInformation = 12083,
	//! NodeId of the node OpcUa/XmlSchema/AxisInformation/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_AxisInformation_DataTypeVersion = 12084,
	//! NodeId of the node OpcUa/XmlSchema/AxisInformation/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_AxisInformation_DictionaryFragment = 12085,
	//! NodeId of the node OpcUa/XmlSchema/XVType.
	EnumNumericNodeId_OpcUa_XmlSchema_XVType = 12086,
	//! NodeId of the node OpcUa/XmlSchema/XVType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_XVType_DataTypeVersion = 12087,
	//! NodeId of the node OpcUa/XmlSchema/XVType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_XVType_DictionaryFragment = 12088,
	//! NodeId of the node AxisInformation/Encoding/DefaultBinary.
	EnumNumericNodeId_AxisInformation_Encoding_DefaultBinary = 12089,
	//! NodeId of the node XVType/Encoding/DefaultBinary.
	EnumNumericNodeId_XVType_Encoding_DefaultBinary = 12090,
	//! NodeId of the node OpcUa/BinarySchema/AxisInformation.
	EnumNumericNodeId_OpcUa_BinarySchema_AxisInformation = 12091,
	//! NodeId of the node OpcUa/BinarySchema/AxisInformation/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_AxisInformation_DataTypeVersion = 12092,
	//! NodeId of the node OpcUa/BinarySchema/AxisInformation/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_AxisInformation_DictionaryFragment = 12093,
	//! NodeId of the node OpcUa/BinarySchema/XVType.
	EnumNumericNodeId_OpcUa_BinarySchema_XVType = 12094,
	//! NodeId of the node OpcUa/BinarySchema/XVType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_XVType_DataTypeVersion = 12095,
	//! NodeId of the node OpcUa/BinarySchema/XVType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_XVType_DictionaryFragment = 12096,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder = 12097,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics = 12098,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/SessionId.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_SessionId = 12099,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/SessionName.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_SessionName = 12100,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/ClientDescription.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_ClientDescription = 12101,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/ServerUri.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_ServerUri = 12102,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/EndpointUrl.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_EndpointUrl = 12103,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/LocaleIds.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_LocaleIds = 12104,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/ActualSessionTimeout.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_ActualSessionTimeout = 12105,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/MaxResponseMessageSize.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_MaxResponseMessageSize = 12106,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/ClientConnectionTime.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_ClientConnectionTime = 12107,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/ClientLastContactTime.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_ClientLastContactTime = 12108,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/CurrentSubscriptionsCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_CurrentSubscriptionsCount = 12109,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/CurrentMonitoredItemsCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_CurrentMonitoredItemsCount = 12110,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/CurrentPublishRequestsInQueue.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_CurrentPublishRequestsInQueue = 12111,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/TotalRequestCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_TotalRequestCount = 12112,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/UnauthorizedRequestCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_UnauthorizedRequestCount = 12113,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/ReadCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_ReadCount = 12114,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/HistoryReadCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_HistoryReadCount = 12115,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/WriteCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_WriteCount = 12116,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/HistoryUpdateCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_HistoryUpdateCount = 12117,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/CallCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_CallCount = 12118,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/CreateMonitoredItemsCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_CreateMonitoredItemsCount = 12119,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/ModifyMonitoredItemsCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_ModifyMonitoredItemsCount = 12120,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/SetMonitoringModeCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_SetMonitoringModeCount = 12121,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/SetTriggeringCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_SetTriggeringCount = 12122,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/DeleteMonitoredItemsCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_DeleteMonitoredItemsCount = 12123,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/CreateSubscriptionCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_CreateSubscriptionCount = 12124,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/ModifySubscriptionCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_ModifySubscriptionCount = 12125,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/SetPublishingModeCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_SetPublishingModeCount = 12126,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/PublishCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_PublishCount = 12127,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/RepublishCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_RepublishCount = 12128,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/TransferSubscriptionsCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_TransferSubscriptionsCount = 12129,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/DeleteSubscriptionsCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_DeleteSubscriptionsCount = 12130,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/AddNodesCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_AddNodesCount = 12131,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/AddReferencesCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_AddReferencesCount = 12132,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/DeleteNodesCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_DeleteNodesCount = 12133,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/DeleteReferencesCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_DeleteReferencesCount = 12134,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/BrowseCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_BrowseCount = 12135,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/BrowseNextCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_BrowseNextCount = 12136,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/TranslateBrowsePathsToNodeIdsCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_TranslateBrowsePathsToNodeIdsCount = 12137,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/QueryFirstCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_QueryFirstCount = 12138,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/QueryNextCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_QueryNextCount = 12139,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/RegisterNodesCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_RegisterNodesCount = 12140,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionDiagnostics/UnregisterNodesCount.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionDiagnostics_UnregisterNodesCount = 12141,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionSecurityDiagnostics.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionSecurityDiagnostics = 12142,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionSecurityDiagnostics/SessionId.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionSecurityDiagnostics_SessionId = 12143,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionSecurityDiagnostics/ClientUserIdOfSession.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionSecurityDiagnostics_ClientUserIdOfSession = 12144,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionSecurityDiagnostics/ClientUserIdHistory.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionSecurityDiagnostics_ClientUserIdHistory = 12145,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionSecurityDiagnostics/AuthenticationMechanism.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionSecurityDiagnostics_AuthenticationMechanism = 12146,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionSecurityDiagnostics/Encoding.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionSecurityDiagnostics_Encoding = 12147,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionSecurityDiagnostics/TransportProtocol.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionSecurityDiagnostics_TransportProtocol = 12148,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionSecurityDiagnostics/SecurityMode.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionSecurityDiagnostics_SecurityMode = 12149,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionSecurityDiagnostics/SecurityPolicyUri.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionSecurityDiagnostics_SecurityPolicyUri = 12150,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SessionSecurityDiagnostics/ClientCertificate.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SessionSecurityDiagnostics_ClientCertificate = 12151,
	//! NodeId of the node SessionsDiagnosticsSummaryType/SessionPlaceholder/SubscriptionDiagnosticsArray.
	EnumNumericNodeId_SessionsDiagnosticsSummaryType_SessionPlaceholder_SubscriptionDiagnosticsArray = 12152,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerHistoryReadData.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerHistoryReadData = 12153,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerHistoryReadEvents.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerHistoryReadEvents = 12154,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerHistoryUpdateData.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerHistoryUpdateData = 12155,
	//! NodeId of the node ServerType/ServerCapabilities/OperationLimits/MaxNodesPerHistoryUpdateEvents.
	EnumNumericNodeId_ServerType_ServerCapabilities_OperationLimits_MaxNodesPerHistoryUpdateEvents = 12156,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerHistoryReadData.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerHistoryReadData = 12157,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerHistoryReadEvents.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerHistoryReadEvents = 12158,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerHistoryUpdateData.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerHistoryUpdateData = 12159,
	//! NodeId of the node ServerCapabilitiesType/OperationLimits/MaxNodesPerHistoryUpdateEvents.
	EnumNumericNodeId_ServerCapabilitiesType_OperationLimits_MaxNodesPerHistoryUpdateEvents = 12160,
	//! NodeId of the node OperationLimitsType/MaxNodesPerHistoryReadData.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerHistoryReadData = 12161,
	//! NodeId of the node OperationLimitsType/MaxNodesPerHistoryReadEvents.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerHistoryReadEvents = 12162,
	//! NodeId of the node OperationLimitsType/MaxNodesPerHistoryUpdateData.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerHistoryUpdateData = 12163,
	//! NodeId of the node OperationLimitsType/MaxNodesPerHistoryUpdateEvents.
	EnumNumericNodeId_OperationLimitsType_MaxNodesPerHistoryUpdateEvents = 12164,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerHistoryReadData.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerHistoryReadData = 12165,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerHistoryReadEvents.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerHistoryReadEvents = 12166,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerHistoryUpdateData.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerHistoryUpdateData = 12167,
	//! NodeId of the node Server/ServerCapabilities/OperationLimits/MaxNodesPerHistoryUpdateEvents.
	EnumNumericNodeId_Server_ServerCapabilities_OperationLimits_MaxNodesPerHistoryUpdateEvents = 12168,
	//! NodeId of the node NamingRuleType/EnumValues.
	EnumNumericNodeId_NamingRuleType_EnumValues = 12169,
	//! NodeId of the node ViewVersion.
	EnumNumericNodeId_ViewVersion = 12170,
	//! NodeId of the data type ComplexNumberType.
	EnumNumericNodeId_ComplexNumberType = 12171,
	//! NodeId of the data type DoubleComplexNumberType.
	EnumNumericNodeId_DoubleComplexNumberType = 12172,
	//! NodeId of the node ComplexNumberType/Encoding/DefaultXml.
	EnumNumericNodeId_ComplexNumberType_Encoding_DefaultXml = 12173,
	//! NodeId of the node DoubleComplexNumberType/Encoding/DefaultXml.
	EnumNumericNodeId_DoubleComplexNumberType_Encoding_DefaultXml = 12174,
	//! NodeId of the node OpcUa/XmlSchema/ComplexNumberType.
	EnumNumericNodeId_OpcUa_XmlSchema_ComplexNumberType = 12175,
	//! NodeId of the node OpcUa/XmlSchema/ComplexNumberType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ComplexNumberType_DataTypeVersion = 12176,
	//! NodeId of the node OpcUa/XmlSchema/ComplexNumberType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ComplexNumberType_DictionaryFragment = 12177,
	//! NodeId of the node OpcUa/XmlSchema/DoubleComplexNumberType.
	EnumNumericNodeId_OpcUa_XmlSchema_DoubleComplexNumberType = 12178,
	//! NodeId of the node OpcUa/XmlSchema/DoubleComplexNumberType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_DoubleComplexNumberType_DataTypeVersion = 12179,
	//! NodeId of the node OpcUa/XmlSchema/DoubleComplexNumberType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_DoubleComplexNumberType_DictionaryFragment = 12180,
	//! NodeId of the node ComplexNumberType/Encoding/DefaultBinary.
	EnumNumericNodeId_ComplexNumberType_Encoding_DefaultBinary = 12181,
	//! NodeId of the node DoubleComplexNumberType/Encoding/DefaultBinary.
	EnumNumericNodeId_DoubleComplexNumberType_Encoding_DefaultBinary = 12182,
	//! NodeId of the node OpcUa/BinarySchema/ComplexNumberType.
	EnumNumericNodeId_OpcUa_BinarySchema_ComplexNumberType = 12183,
	//! NodeId of the node OpcUa/BinarySchema/ComplexNumberType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ComplexNumberType_DataTypeVersion = 12184,
	//! NodeId of the node OpcUa/BinarySchema/ComplexNumberType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ComplexNumberType_DictionaryFragment = 12185,
	//! NodeId of the node OpcUa/BinarySchema/DoubleComplexNumberType.
	EnumNumericNodeId_OpcUa_BinarySchema_DoubleComplexNumberType = 12186,
	//! NodeId of the node OpcUa/BinarySchema/DoubleComplexNumberType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_DoubleComplexNumberType_DataTypeVersion = 12187,
	//! NodeId of the node OpcUa/BinarySchema/DoubleComplexNumberType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_DoubleComplexNumberType_DictionaryFragment = 12188,
	//! NodeId of the data type ServerOnNetwork.
	EnumNumericNodeId_ServerOnNetwork = 12189,
	//! NodeId of the data type FindServersOnNetworkRequest.
	EnumNumericNodeId_FindServersOnNetworkRequest = 12190,
	//! NodeId of the data type FindServersOnNetworkResponse.
	EnumNumericNodeId_FindServersOnNetworkResponse = 12191,
	//! NodeId of the data type RegisteredServer2.
	EnumNumericNodeId_RegisteredServer2 = 12192,
	//! NodeId of the data type RegisterServer2Request.
	EnumNumericNodeId_RegisterServer2Request = 12193,
	//! NodeId of the data type RegisterServer2Response.
	EnumNumericNodeId_RegisterServer2Response = 12194,
	//! NodeId of the node ServerOnNetwork/Encoding/DefaultXml.
	EnumNumericNodeId_ServerOnNetwork_Encoding_DefaultXml = 12195,
	//! NodeId of the node FindServersOnNetworkRequest/Encoding/DefaultXml.
	EnumNumericNodeId_FindServersOnNetworkRequest_Encoding_DefaultXml = 12196,
	//! NodeId of the node FindServersOnNetworkResponse/Encoding/DefaultXml.
	EnumNumericNodeId_FindServersOnNetworkResponse_Encoding_DefaultXml = 12197,
	//! NodeId of the node RegisteredServer2/Encoding/DefaultXml.
	EnumNumericNodeId_RegisteredServer2_Encoding_DefaultXml = 12198,
	//! NodeId of the node RegisterServer2Request/Encoding/DefaultXml.
	EnumNumericNodeId_RegisterServer2Request_Encoding_DefaultXml = 12199,
	//! NodeId of the node RegisterServer2Response/Encoding/DefaultXml.
	EnumNumericNodeId_RegisterServer2Response_Encoding_DefaultXml = 12200,
	//! NodeId of the node OpcUa/XmlSchema/ServerOnNetwork.
	EnumNumericNodeId_OpcUa_XmlSchema_ServerOnNetwork = 12201,
	//! NodeId of the node OpcUa/XmlSchema/ServerOnNetwork/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_ServerOnNetwork_DataTypeVersion = 12202,
	//! NodeId of the node OpcUa/XmlSchema/ServerOnNetwork/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_ServerOnNetwork_DictionaryFragment = 12203,
	//! NodeId of the node OpcUa/XmlSchema/RegisteredServer2.
	EnumNumericNodeId_OpcUa_XmlSchema_RegisteredServer2 = 12204,
	//! NodeId of the node OpcUa/XmlSchema/RegisteredServer2/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_RegisteredServer2_DataTypeVersion = 12205,
	//! NodeId of the node OpcUa/XmlSchema/RegisteredServer2/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_RegisteredServer2_DictionaryFragment = 12206,
	//! NodeId of the node ServerOnNetwork/Encoding/DefaultBinary.
	EnumNumericNodeId_ServerOnNetwork_Encoding_DefaultBinary = 12207,
	//! NodeId of the node FindServersOnNetworkRequest/Encoding/DefaultBinary.
	EnumNumericNodeId_FindServersOnNetworkRequest_Encoding_DefaultBinary = 12208,
	//! NodeId of the node FindServersOnNetworkResponse/Encoding/DefaultBinary.
	EnumNumericNodeId_FindServersOnNetworkResponse_Encoding_DefaultBinary = 12209,
	//! NodeId of the node RegisteredServer2/Encoding/DefaultBinary.
	EnumNumericNodeId_RegisteredServer2_Encoding_DefaultBinary = 12210,
	//! NodeId of the node RegisterServer2Request/Encoding/DefaultBinary.
	EnumNumericNodeId_RegisterServer2Request_Encoding_DefaultBinary = 12211,
	//! NodeId of the node RegisterServer2Response/Encoding/DefaultBinary.
	EnumNumericNodeId_RegisterServer2Response_Encoding_DefaultBinary = 12212,
	//! NodeId of the node OpcUa/BinarySchema/ServerOnNetwork.
	EnumNumericNodeId_OpcUa_BinarySchema_ServerOnNetwork = 12213,
	//! NodeId of the node OpcUa/BinarySchema/ServerOnNetwork/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_ServerOnNetwork_DataTypeVersion = 12214,
	//! NodeId of the node OpcUa/BinarySchema/ServerOnNetwork/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_ServerOnNetwork_DictionaryFragment = 12215,
	//! NodeId of the node OpcUa/BinarySchema/RegisteredServer2.
	EnumNumericNodeId_OpcUa_BinarySchema_RegisteredServer2 = 12216,
	//! NodeId of the node OpcUa/BinarySchema/RegisteredServer2/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_RegisteredServer2_DataTypeVersion = 12217,
	//! NodeId of the node OpcUa/BinarySchema/RegisteredServer2/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_RegisteredServer2_DictionaryFragment = 12218,
	//! NodeId of the node ProgressEventType/Context.
	EnumNumericNodeId_ProgressEventType_Context = 12502,
	//! NodeId of the node ProgressEventType/Progress.
	EnumNumericNodeId_ProgressEventType_Progress = 12503,
	//! NodeId of the data type KerberosIdentityToken.
	EnumNumericNodeId_KerberosIdentityToken = 12504,
	//! NodeId of the node KerberosIdentityToken/Encoding/DefaultXml.
	EnumNumericNodeId_KerberosIdentityToken_Encoding_DefaultXml = 12505,
	//! NodeId of the node OpcUa/XmlSchema/KerberosIdentityToken.
	EnumNumericNodeId_OpcUa_XmlSchema_KerberosIdentityToken = 12506,
	//! NodeId of the node OpcUa/XmlSchema/KerberosIdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_KerberosIdentityToken_DataTypeVersion = 12507,
	//! NodeId of the node OpcUa/XmlSchema/KerberosIdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_KerberosIdentityToken_DictionaryFragment = 12508,
	//! NodeId of the node KerberosIdentityToken/Encoding/DefaultBinary.
	EnumNumericNodeId_KerberosIdentityToken_Encoding_DefaultBinary = 12509,
	//! NodeId of the node OpcUa/BinarySchema/KerberosIdentityToken.
	EnumNumericNodeId_OpcUa_BinarySchema_KerberosIdentityToken = 12510,
	//! NodeId of the node OpcUa/BinarySchema/KerberosIdentityToken/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_KerberosIdentityToken_DataTypeVersion = 12511,
	//! NodeId of the node OpcUa/BinarySchema/KerberosIdentityToken/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_KerberosIdentityToken_DictionaryFragment = 12512,
	//! NodeId of the object type TrustListType.
	EnumNumericNodeId_TrustListType = 12522,
	//! NodeId of the node TrustListType/Size.
	EnumNumericNodeId_TrustListType_Size = 12523,
	//! NodeId of the node TrustListType/OpenCount.
	EnumNumericNodeId_TrustListType_OpenCount = 12526,
	//! NodeId of the node TrustListType/Open.
	EnumNumericNodeId_TrustListType_Open = 12527,
	//! NodeId of the node TrustListType/Open/InputArguments.
	EnumNumericNodeId_TrustListType_Open_InputArguments = 12528,
	//! NodeId of the node TrustListType/Open/OutputArguments.
	EnumNumericNodeId_TrustListType_Open_OutputArguments = 12529,
	//! NodeId of the node TrustListType/Close.
	EnumNumericNodeId_TrustListType_Close = 12530,
	//! NodeId of the node TrustListType/Close/InputArguments.
	EnumNumericNodeId_TrustListType_Close_InputArguments = 12531,
	//! NodeId of the node TrustListType/Read.
	EnumNumericNodeId_TrustListType_Read = 12532,
	//! NodeId of the node TrustListType/Read/InputArguments.
	EnumNumericNodeId_TrustListType_Read_InputArguments = 12533,
	//! NodeId of the node TrustListType/Read/OutputArguments.
	EnumNumericNodeId_TrustListType_Read_OutputArguments = 12534,
	//! NodeId of the node TrustListType/Write.
	EnumNumericNodeId_TrustListType_Write = 12535,
	//! NodeId of the node TrustListType/Write/InputArguments.
	EnumNumericNodeId_TrustListType_Write_InputArguments = 12536,
	//! NodeId of the node TrustListType/GetPosition.
	EnumNumericNodeId_TrustListType_GetPosition = 12537,
	//! NodeId of the node TrustListType/GetPosition/InputArguments.
	EnumNumericNodeId_TrustListType_GetPosition_InputArguments = 12538,
	//! NodeId of the node TrustListType/GetPosition/OutputArguments.
	EnumNumericNodeId_TrustListType_GetPosition_OutputArguments = 12539,
	//! NodeId of the node TrustListType/SetPosition.
	EnumNumericNodeId_TrustListType_SetPosition = 12540,
	//! NodeId of the node TrustListType/SetPosition/InputArguments.
	EnumNumericNodeId_TrustListType_SetPosition_InputArguments = 12541,
	//! NodeId of the node TrustListType/LastUpdateTime.
	EnumNumericNodeId_TrustListType_LastUpdateTime = 12542,
	//! NodeId of the node TrustListType/OpenWithMasks.
	EnumNumericNodeId_TrustListType_OpenWithMasks = 12543,
	//! NodeId of the node TrustListType/OpenWithMasks/InputArguments.
	EnumNumericNodeId_TrustListType_OpenWithMasks_InputArguments = 12544,
	//! NodeId of the node TrustListType/OpenWithMasks/OutputArguments.
	EnumNumericNodeId_TrustListType_OpenWithMasks_OutputArguments = 12545,
	//! NodeId of the node TrustListType/CloseAndUpdate.
	EnumNumericNodeId_TrustListType_CloseAndUpdate = 12546,
	//! NodeId of the node TrustListType/CloseAndUpdate/OutputArguments.
	EnumNumericNodeId_TrustListType_CloseAndUpdate_OutputArguments = 12547,
	//! NodeId of the node TrustListType/AddCertificate.
	EnumNumericNodeId_TrustListType_AddCertificate = 12548,
	//! NodeId of the node TrustListType/AddCertificate/InputArguments.
	EnumNumericNodeId_TrustListType_AddCertificate_InputArguments = 12549,
	//! NodeId of the node TrustListType/RemoveCertificate.
	EnumNumericNodeId_TrustListType_RemoveCertificate = 12550,
	//! NodeId of the node TrustListType/RemoveCertificate/InputArguments.
	EnumNumericNodeId_TrustListType_RemoveCertificate_InputArguments = 12551,
	//! NodeId of the data type TrustListMasks.
	EnumNumericNodeId_TrustListMasks = 12552,
	//! NodeId of the node TrustListMasks/EnumValues.
	EnumNumericNodeId_TrustListMasks_EnumValues = 12553,
	//! NodeId of the data type TrustListDataType.
	EnumNumericNodeId_TrustListDataType = 12554,
	//! NodeId of the object type AuthorityType.
	EnumNumericNodeId_AuthorityType = 12555,
	//! NodeId of the abstract object type CertificateType.
	EnumNumericNodeId_CertificateType = 12556,
	//! NodeId of the abstract object type ApplicationCertificateType.
	EnumNumericNodeId_ApplicationCertificateType = 12557,
	//! NodeId of the object type HttpsCertificateType.
	EnumNumericNodeId_HttpsCertificateType = 12558,
	//! NodeId of the object type RsaBasicApplicationCertificateType.
	EnumNumericNodeId_RsaBasicApplicationCertificateType = 12559,
	//! NodeId of the object type Rsa2084ApplicationCertificateType.
	EnumNumericNodeId_Rsa2084ApplicationCertificateType = 12560,
	//! NodeId of the abstract object type TrustListUpdatedAuditEventType.
	EnumNumericNodeId_TrustListUpdatedAuditEventType = 12561,
	//! NodeId of the node TrustListUpdatedAuditEventType/EventId.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_EventId = 12562,
	//! NodeId of the node TrustListUpdatedAuditEventType/EventType.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_EventType = 12563,
	//! NodeId of the node TrustListUpdatedAuditEventType/SourceNode.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_SourceNode = 12564,
	//! NodeId of the node TrustListUpdatedAuditEventType/SourceName.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_SourceName = 12565,
	//! NodeId of the node TrustListUpdatedAuditEventType/Time.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_Time = 12566,
	//! NodeId of the node TrustListUpdatedAuditEventType/ReceiveTime.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_ReceiveTime = 12567,
	//! NodeId of the node TrustListUpdatedAuditEventType/LocalTime.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_LocalTime = 12568,
	//! NodeId of the node TrustListUpdatedAuditEventType/Message.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_Message = 12569,
	//! NodeId of the node TrustListUpdatedAuditEventType/Severity.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_Severity = 12570,
	//! NodeId of the node TrustListUpdatedAuditEventType/ActionTimeStamp.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_ActionTimeStamp = 12571,
	//! NodeId of the node TrustListUpdatedAuditEventType/Status.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_Status = 12572,
	//! NodeId of the node TrustListUpdatedAuditEventType/ServerId.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_ServerId = 12573,
	//! NodeId of the node TrustListUpdatedAuditEventType/ClientAuditEntryId.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_ClientAuditEntryId = 12574,
	//! NodeId of the node TrustListUpdatedAuditEventType/ClientUserId.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_ClientUserId = 12575,
	//! NodeId of the node TrustListUpdatedAuditEventType/MethodId.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_MethodId = 12576,
	//! NodeId of the node TrustListUpdatedAuditEventType/InputArguments.
	EnumNumericNodeId_TrustListUpdatedAuditEventType_InputArguments = 12577,
	//! NodeId of the object type ServerConfigurationType.
	EnumNumericNodeId_ServerConfigurationType = 12581,
	//! NodeId of the node ServerConfigurationType/SupportedPrivateKeyFormats.
	EnumNumericNodeId_ServerConfigurationType_SupportedPrivateKeyFormats = 12583,
	//! NodeId of the node ServerConfigurationType/MaxTrustListSize.
	EnumNumericNodeId_ServerConfigurationType_MaxTrustListSize = 12584,
	//! NodeId of the node ServerConfigurationType/MulticastDnsEnabled.
	EnumNumericNodeId_ServerConfigurationType_MulticastDnsEnabled = 12585,
	//! NodeId of the node ServerConfigurationType/TrustList.
	EnumNumericNodeId_ServerConfigurationType_TrustList = 12586,
	//! NodeId of the node ServerConfigurationType/TrustList/Size.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Size = 12587,
	//! NodeId of the node ServerConfigurationType/TrustList/OpenCount.
	EnumNumericNodeId_ServerConfigurationType_TrustList_OpenCount = 12590,
	//! NodeId of the node ServerConfigurationType/TrustList/Open.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Open = 12591,
	//! NodeId of the node ServerConfigurationType/TrustList/Open/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Open_InputArguments = 12592,
	//! NodeId of the node ServerConfigurationType/TrustList/Open/OutputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Open_OutputArguments = 12593,
	//! NodeId of the node ServerConfigurationType/TrustList/Close.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Close = 12594,
	//! NodeId of the node ServerConfigurationType/TrustList/Close/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Close_InputArguments = 12595,
	//! NodeId of the node ServerConfigurationType/TrustList/Read.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Read = 12596,
	//! NodeId of the node ServerConfigurationType/TrustList/Read/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Read_InputArguments = 12597,
	//! NodeId of the node ServerConfigurationType/TrustList/Read/OutputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Read_OutputArguments = 12598,
	//! NodeId of the node ServerConfigurationType/TrustList/Write.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Write = 12599,
	//! NodeId of the node ServerConfigurationType/TrustList/Write/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Write_InputArguments = 12600,
	//! NodeId of the node ServerConfigurationType/TrustList/GetPosition.
	EnumNumericNodeId_ServerConfigurationType_TrustList_GetPosition = 12601,
	//! NodeId of the node ServerConfigurationType/TrustList/GetPosition/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_GetPosition_InputArguments = 12602,
	//! NodeId of the node ServerConfigurationType/TrustList/GetPosition/OutputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_GetPosition_OutputArguments = 12603,
	//! NodeId of the node ServerConfigurationType/TrustList/SetPosition.
	EnumNumericNodeId_ServerConfigurationType_TrustList_SetPosition = 12604,
	//! NodeId of the node ServerConfigurationType/TrustList/SetPosition/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_SetPosition_InputArguments = 12605,
	//! NodeId of the node ServerConfigurationType/TrustList/LastUpdateTime.
	EnumNumericNodeId_ServerConfigurationType_TrustList_LastUpdateTime = 12606,
	//! NodeId of the node ServerConfigurationType/TrustList/OpenWithMasks.
	EnumNumericNodeId_ServerConfigurationType_TrustList_OpenWithMasks = 12607,
	//! NodeId of the node ServerConfigurationType/TrustList/OpenWithMasks/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_OpenWithMasks_InputArguments = 12608,
	//! NodeId of the node ServerConfigurationType/TrustList/OpenWithMasks/OutputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_OpenWithMasks_OutputArguments = 12609,
	//! NodeId of the node ServerConfigurationType/TrustList/CloseAndUpdate.
	EnumNumericNodeId_ServerConfigurationType_TrustList_CloseAndUpdate = 12610,
	//! NodeId of the node ServerConfigurationType/TrustList/CloseAndUpdate/OutputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_CloseAndUpdate_OutputArguments = 12611,
	//! NodeId of the node ServerConfigurationType/TrustList/AddCertificate.
	EnumNumericNodeId_ServerConfigurationType_TrustList_AddCertificate = 12612,
	//! NodeId of the node ServerConfigurationType/TrustList/AddCertificate/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_AddCertificate_InputArguments = 12613,
	//! NodeId of the node ServerConfigurationType/TrustList/RemoveCertificate.
	EnumNumericNodeId_ServerConfigurationType_TrustList_RemoveCertificate = 12614,
	//! NodeId of the node ServerConfigurationType/TrustList/RemoveCertificate/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_RemoveCertificate_InputArguments = 12615,
	//! NodeId of the node ServerConfigurationType/UpdateCertificate.
	EnumNumericNodeId_ServerConfigurationType_UpdateCertificate = 12616,
	//! NodeId of the node ServerConfigurationType/UpdateCertificate/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_UpdateCertificate_InputArguments = 12617,
	//! NodeId of the node ServerConfigurationType/UpdateCertificate/OutputArguments.
	EnumNumericNodeId_ServerConfigurationType_UpdateCertificate_OutputArguments = 12618,
	//! NodeId of the node ServerConfigurationType/Restart.
	EnumNumericNodeId_ServerConfigurationType_Restart = 12619,
	//! NodeId of the abstract object type CertificateUpdatedAuditEventType.
	EnumNumericNodeId_CertificateUpdatedAuditEventType = 12620,
	//! NodeId of the node CertificateUpdatedAuditEventType/EventId.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_EventId = 12621,
	//! NodeId of the node CertificateUpdatedAuditEventType/EventType.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_EventType = 12622,
	//! NodeId of the node CertificateUpdatedAuditEventType/SourceNode.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_SourceNode = 12623,
	//! NodeId of the node CertificateUpdatedAuditEventType/SourceName.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_SourceName = 12624,
	//! NodeId of the node CertificateUpdatedAuditEventType/Time.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_Time = 12625,
	//! NodeId of the node CertificateUpdatedAuditEventType/ReceiveTime.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_ReceiveTime = 12626,
	//! NodeId of the node CertificateUpdatedAuditEventType/LocalTime.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_LocalTime = 12627,
	//! NodeId of the node CertificateUpdatedAuditEventType/Message.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_Message = 12628,
	//! NodeId of the node CertificateUpdatedAuditEventType/Severity.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_Severity = 12629,
	//! NodeId of the node CertificateUpdatedAuditEventType/ActionTimeStamp.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_ActionTimeStamp = 12630,
	//! NodeId of the node CertificateUpdatedAuditEventType/Status.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_Status = 12631,
	//! NodeId of the node CertificateUpdatedAuditEventType/ServerId.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_ServerId = 12632,
	//! NodeId of the node CertificateUpdatedAuditEventType/ClientAuditEntryId.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_ClientAuditEntryId = 12633,
	//! NodeId of the node CertificateUpdatedAuditEventType/ClientUserId.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_ClientUserId = 12634,
	//! NodeId of the node CertificateUpdatedAuditEventType/MethodId.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_MethodId = 12635,
	//! NodeId of the node CertificateUpdatedAuditEventType/InputArguments.
	EnumNumericNodeId_CertificateUpdatedAuditEventType_InputArguments = 12636,
	//! NodeId of the node ServerConfiguration.
	EnumNumericNodeId_ServerConfiguration = 12637,
	//! NodeId of the node ServerConfiguration/SupportedPrivateKeyFormats.
	EnumNumericNodeId_ServerConfiguration_SupportedPrivateKeyFormats = 12639,
	//! NodeId of the node ServerConfiguration/MaxTrustListSize.
	EnumNumericNodeId_ServerConfiguration_MaxTrustListSize = 12640,
	//! NodeId of the node ServerConfiguration/MulticastDnsEnabled.
	EnumNumericNodeId_ServerConfiguration_MulticastDnsEnabled = 12641,
	//! NodeId of the node ServerConfiguration/TrustList.
	EnumNumericNodeId_ServerConfiguration_TrustList = 12642,
	//! NodeId of the node ServerConfiguration/TrustList/Size.
	EnumNumericNodeId_ServerConfiguration_TrustList_Size = 12643,
	//! NodeId of the node ServerConfiguration/TrustList/OpenCount.
	EnumNumericNodeId_ServerConfiguration_TrustList_OpenCount = 12646,
	//! NodeId of the node ServerConfiguration/TrustList/Open.
	EnumNumericNodeId_ServerConfiguration_TrustList_Open = 12647,
	//! NodeId of the node ServerConfiguration/TrustList/Open/InputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_Open_InputArguments = 12648,
	//! NodeId of the node ServerConfiguration/TrustList/Open/OutputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_Open_OutputArguments = 12649,
	//! NodeId of the node ServerConfiguration/TrustList/Close.
	EnumNumericNodeId_ServerConfiguration_TrustList_Close = 12650,
	//! NodeId of the node ServerConfiguration/TrustList/Close/InputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_Close_InputArguments = 12651,
	//! NodeId of the node ServerConfiguration/TrustList/Read.
	EnumNumericNodeId_ServerConfiguration_TrustList_Read = 12652,
	//! NodeId of the node ServerConfiguration/TrustList/Read/InputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_Read_InputArguments = 12653,
	//! NodeId of the node ServerConfiguration/TrustList/Read/OutputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_Read_OutputArguments = 12654,
	//! NodeId of the node ServerConfiguration/TrustList/Write.
	EnumNumericNodeId_ServerConfiguration_TrustList_Write = 12655,
	//! NodeId of the node ServerConfiguration/TrustList/Write/InputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_Write_InputArguments = 12656,
	//! NodeId of the node ServerConfiguration/TrustList/GetPosition.
	EnumNumericNodeId_ServerConfiguration_TrustList_GetPosition = 12657,
	//! NodeId of the node ServerConfiguration/TrustList/GetPosition/InputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_GetPosition_InputArguments = 12658,
	//! NodeId of the node ServerConfiguration/TrustList/GetPosition/OutputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_GetPosition_OutputArguments = 12659,
	//! NodeId of the node ServerConfiguration/TrustList/SetPosition.
	EnumNumericNodeId_ServerConfiguration_TrustList_SetPosition = 12660,
	//! NodeId of the node ServerConfiguration/TrustList/SetPosition/InputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_SetPosition_InputArguments = 12661,
	//! NodeId of the node ServerConfiguration/TrustList/LastUpdateTime.
	EnumNumericNodeId_ServerConfiguration_TrustList_LastUpdateTime = 12662,
	//! NodeId of the node ServerConfiguration/TrustList/OpenWithMasks.
	EnumNumericNodeId_ServerConfiguration_TrustList_OpenWithMasks = 12663,
	//! NodeId of the node ServerConfiguration/TrustList/OpenWithMasks/InputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_OpenWithMasks_InputArguments = 12664,
	//! NodeId of the node ServerConfiguration/TrustList/OpenWithMasks/OutputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_OpenWithMasks_OutputArguments = 12665,
	//! NodeId of the node ServerConfiguration/TrustList/CloseAndUpdate.
	EnumNumericNodeId_ServerConfiguration_TrustList_CloseAndUpdate = 12666,
	//! NodeId of the node ServerConfiguration/TrustList/CloseAndUpdate/OutputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_CloseAndUpdate_OutputArguments = 12667,
	//! NodeId of the node ServerConfiguration/TrustList/AddCertificate.
	EnumNumericNodeId_ServerConfiguration_TrustList_AddCertificate = 12668,
	//! NodeId of the node ServerConfiguration/TrustList/AddCertificate/InputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_AddCertificate_InputArguments = 12669,
	//! NodeId of the node ServerConfiguration/TrustList/RemoveCertificate.
	EnumNumericNodeId_ServerConfiguration_TrustList_RemoveCertificate = 12670,
	//! NodeId of the node ServerConfiguration/TrustList/RemoveCertificate/InputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_RemoveCertificate_InputArguments = 12671,
	//! NodeId of the node ServerConfiguration/UpdateCertificate.
	EnumNumericNodeId_ServerConfiguration_UpdateCertificate = 12672,
	//! NodeId of the node ServerConfiguration/UpdateCertificate/InputArguments.
	EnumNumericNodeId_ServerConfiguration_UpdateCertificate_InputArguments = 12673,
	//! NodeId of the node ServerConfiguration/UpdateCertificate/OutputArguments.
	EnumNumericNodeId_ServerConfiguration_UpdateCertificate_OutputArguments = 12674,
	//! NodeId of the node ServerConfiguration/Restart.
	EnumNumericNodeId_ServerConfiguration_Restart = 12675,
	//! NodeId of the node TrustListDataType/Encoding/DefaultXml.
	EnumNumericNodeId_TrustListDataType_Encoding_DefaultXml = 12676,
	//! NodeId of the node OpcUa/XmlSchema/TrustListDataType.
	EnumNumericNodeId_OpcUa_XmlSchema_TrustListDataType = 12677,
	//! NodeId of the node OpcUa/XmlSchema/TrustListDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_TrustListDataType_DataTypeVersion = 12678,
	//! NodeId of the node OpcUa/XmlSchema/TrustListDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_TrustListDataType_DictionaryFragment = 12679,
	//! NodeId of the node TrustListDataType/Encoding/DefaultBinary.
	EnumNumericNodeId_TrustListDataType_Encoding_DefaultBinary = 12680,
	//! NodeId of the node OpcUa/BinarySchema/TrustListDataType.
	EnumNumericNodeId_OpcUa_BinarySchema_TrustListDataType = 12681,
	//! NodeId of the node OpcUa/BinarySchema/TrustListDataType/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_TrustListDataType_DataTypeVersion = 12682,
	//! NodeId of the node OpcUa/BinarySchema/TrustListDataType/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_TrustListDataType_DictionaryFragment = 12683,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/Writable.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_Writable = 12684,
	//! NodeId of the node ServerType/Namespaces/AddressSpaceFile/UserWritable.
	EnumNumericNodeId_ServerType_Namespaces_AddressSpaceFile_UserWritable = 12685,
	//! NodeId of the node FileType/Writable.
	EnumNumericNodeId_FileType_Writable = 12686,
	//! NodeId of the node FileType/UserWritable.
	EnumNumericNodeId_FileType_UserWritable = 12687,
	//! NodeId of the node AddressSpaceFileType/Writable.
	EnumNumericNodeId_AddressSpaceFileType_Writable = 12688,
	//! NodeId of the node AddressSpaceFileType/UserWritable.
	EnumNumericNodeId_AddressSpaceFileType_UserWritable = 12689,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/Writable.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_Writable = 12690,
	//! NodeId of the node NamespaceMetadataType/NamespaceFile/UserWritable.
	EnumNumericNodeId_NamespaceMetadataType_NamespaceFile_UserWritable = 12691,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/Writable.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_Writable = 12692,
	//! NodeId of the node NamespacesType/NamespaceIdentifier/NamespaceFile/UserWritable.
	EnumNumericNodeId_NamespacesType_NamespaceIdentifier_NamespaceFile_UserWritable = 12693,
	//! NodeId of the node NamespacesType/AddressSpaceFile/Writable.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_Writable = 12694,
	//! NodeId of the node NamespacesType/AddressSpaceFile/UserWritable.
	EnumNumericNodeId_NamespacesType_AddressSpaceFile_UserWritable = 12695,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/Writable.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_Writable = 12696,
	//! NodeId of the node Server/Namespaces/AddressSpaceFile/UserWritable.
	EnumNumericNodeId_Server_Namespaces_AddressSpaceFile_UserWritable = 12697,
	//! NodeId of the node TrustListType/Writable.
	EnumNumericNodeId_TrustListType_Writable = 12698,
	//! NodeId of the node TrustListType/UserWritable.
	EnumNumericNodeId_TrustListType_UserWritable = 12699,
	//! NodeId of the node ServerConfigurationType/TrustList/Writable.
	EnumNumericNodeId_ServerConfigurationType_TrustList_Writable = 12700,
	//! NodeId of the node ServerConfigurationType/TrustList/UserWritable.
	EnumNumericNodeId_ServerConfigurationType_TrustList_UserWritable = 12701,
	//! NodeId of the node ServerConfiguration/TrustList/Writable.
	EnumNumericNodeId_ServerConfiguration_TrustList_Writable = 12702,
	//! NodeId of the node ServerConfiguration/TrustList/UserWritable.
	EnumNumericNodeId_ServerConfiguration_TrustList_UserWritable = 12703,
	//! NodeId of the node TrustListType/CloseAndUpdate/InputArguments.
	EnumNumericNodeId_TrustListType_CloseAndUpdate_InputArguments = 12705,
	//! NodeId of the node ServerConfigurationType/TrustList/CloseAndUpdate/InputArguments.
	EnumNumericNodeId_ServerConfigurationType_TrustList_CloseAndUpdate_InputArguments = 12706,
	//! NodeId of the node ServerConfiguration/TrustList/CloseAndUpdate/InputArguments.
	EnumNumericNodeId_ServerConfiguration_TrustList_CloseAndUpdate_InputArguments = 12707,
	//! NodeId of the node ServerConfigurationType/ServerCapabilities.
	EnumNumericNodeId_ServerConfigurationType_ServerCapabilities = 12708,
	//! NodeId of the node ServerConfigurationType/SupportedCertificateTypes.
	EnumNumericNodeId_ServerConfigurationType_SupportedCertificateTypes = 12709,
	//! NodeId of the node ServerConfiguration/ServerCapabilities.
	EnumNumericNodeId_ServerConfiguration_ServerCapabilities = 12710,
	//! NodeId of the node ServerConfiguration/SupportedCertificateTypes.
	EnumNumericNodeId_ServerConfiguration_SupportedCertificateTypes = 12711,
	//! NodeId of the node OpcUa/XmlSchema/RelativePathElement.
	EnumNumericNodeId_OpcUa_XmlSchema_RelativePathElement = 12712,
	//! NodeId of the node OpcUa/XmlSchema/RelativePathElement/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_RelativePathElement_DataTypeVersion = 12713,
	//! NodeId of the node OpcUa/XmlSchema/RelativePathElement/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_RelativePathElement_DictionaryFragment = 12714,
	//! NodeId of the node OpcUa/XmlSchema/RelativePath.
	EnumNumericNodeId_OpcUa_XmlSchema_RelativePath = 12715,
	//! NodeId of the node OpcUa/XmlSchema/RelativePath/DataTypeVersion.
	EnumNumericNodeId_OpcUa_XmlSchema_RelativePath_DataTypeVersion = 12716,
	//! NodeId of the node OpcUa/XmlSchema/RelativePath/DictionaryFragment.
	EnumNumericNodeId_OpcUa_XmlSchema_RelativePath_DictionaryFragment = 12717,
	//! NodeId of the node OpcUa/BinarySchema/RelativePathElement.
	EnumNumericNodeId_OpcUa_BinarySchema_RelativePathElement = 12718,
	//! NodeId of the node OpcUa/BinarySchema/RelativePathElement/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_RelativePathElement_DataTypeVersion = 12719,
	//! NodeId of the node OpcUa/BinarySchema/RelativePathElement/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_RelativePathElement_DictionaryFragment = 12720,
	//! NodeId of the node OpcUa/BinarySchema/RelativePath.
	EnumNumericNodeId_OpcUa_BinarySchema_RelativePath = 12721,
	//! NodeId of the node OpcUa/BinarySchema/RelativePath/DataTypeVersion.
	EnumNumericNodeId_OpcUa_BinarySchema_RelativePath_DataTypeVersion = 12722,
	//! NodeId of the node OpcUa/BinarySchema/RelativePath/DictionaryFragment.
	EnumNumericNodeId_OpcUa_BinarySchema_RelativePath_DictionaryFragment = 12723

} EnumNumericNodeId; // end EnumNumericNodeId;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumNumericNodeIdString(EnumNumericNodeId value);
EnumNumericNodeId OTGetEnumNumericNodeIdFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumNumericNodeIdString(EnumNumericNodeId value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumNumericNodeId getEnumNumericNodeIdFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Enumeration containing the basic predefined OPC-DataTypes. Abstract types can be used for definitions
//! of variables containing a value of any subtype.
typedef enum tagEnumDataTypeId // Declaration of enum EnumDataTypeId
{
	//! Undefined DataType
	EnumDataTypeId_Null = EnumNumericNodeId_Null, // 0
	//! Describes a value that is either TRUE or FALSE.
	EnumDataTypeId_Boolean = EnumNumericNodeId_Boolean,
	//! Describes a value that is an integer between -128 and 127.
	EnumDataTypeId_SByte = EnumNumericNodeId_SByte,
	//! Describes a value that is an integer between 0 and 255.
	EnumDataTypeId_Byte = EnumNumericNodeId_Byte,
	//! Describes a value that is an integer between -32,768 and 32,767.
	EnumDataTypeId_Int16 = EnumNumericNodeId_Int16,
	//! Describes a value that is an integer between 0 and 65535.
	EnumDataTypeId_UInt16 = EnumNumericNodeId_UInt16,
	//! Describes a value that is an integer between -2,147,483,648  and 2,147,483,647.
	EnumDataTypeId_Int32 = EnumNumericNodeId_Int32,
	//! Describes a value that is an integer between 0 and 4,294,967,295.
	EnumDataTypeId_UInt32 = EnumNumericNodeId_UInt32,
	//! Describes a value that is an integer between -9,223,372,036,854,775,808 and 9,223,372,036,854,775,807.
	EnumDataTypeId_Int64 = EnumNumericNodeId_Int64,
	//! Describes a value that is an integer between 0 and 18,446,744,073,709,551,615.
	EnumDataTypeId_UInt64 = EnumNumericNodeId_UInt64,
	//! Describes a value that is an IEEE 754-1985 single precision floating point number.
	EnumDataTypeId_Float = EnumNumericNodeId_Float,
	//! Describes a value that is an IEEE 754-1985 double precision floating point number.
	EnumDataTypeId_Double = EnumNumericNodeId_Double,
	//! Describes a value that is a sequence of printable Unicode characters.
	EnumDataTypeId_String = EnumNumericNodeId_String,
	//! Describes a value that is a Gregorian calender date and time.
	EnumDataTypeId_DateTime = EnumNumericNodeId_DateTime,
	//! Describes a value that is a 128-bit globally unique identifier.
	EnumDataTypeId_Guid = EnumNumericNodeId_Guid,
	//! Describes a value that is a sequence of bytes.
	EnumDataTypeId_ByteString = EnumNumericNodeId_ByteString,
	//! Describes a value that is an XML element.
	EnumDataTypeId_XmlElement = EnumNumericNodeId_XmlElement,
	//! Describes a value that is an identifier for a node within a Server address space.
	EnumDataTypeId_NodeId = EnumNumericNodeId_NodeId,
	//! Describes a value that is an absolute identifier for a node.
	EnumDataTypeId_ExpandedNodeId = EnumNumericNodeId_ExpandedNodeId,
	//! Describes a value that is a code representing the outcome of an operation by a Server.
	EnumDataTypeId_StatusCode = EnumNumericNodeId_StatusCode,
	//! Describes a value that is a name qualified by a namespace.
	EnumDataTypeId_QualifiedName = EnumNumericNodeId_QualifiedName,
	//! Describes a value that is human readable Unicode text with a locale identifier.
	EnumDataTypeId_LocalizedText = EnumNumericNodeId_LocalizedText,
	//! Describes a value that is any type of structure that can be described with a data encoding.
	EnumDataTypeId_Structure = EnumNumericNodeId_Structure,
	//! Describes a value that is a structure containing a value, a status code and timestamps.
	EnumDataTypeId_DataValue = EnumNumericNodeId_DataValue,
	//! Describes a value that can have any valid DataType.
	EnumDataTypeId_BaseDataType = EnumNumericNodeId_BaseDataType,
	//! Describes a value that can have any numeric DataType.
	EnumDataTypeId_Number = EnumNumericNodeId_Number,
	//! Describes a value that can have any integer DataType.
	EnumDataTypeId_Integer = EnumNumericNodeId_Integer,
	//! Describes a value that can have any unsigned integer DataType.
	EnumDataTypeId_UInteger = EnumNumericNodeId_UInteger,
	//! Describes a value that is an enumerated DataType.
	EnumDataTypeId_Enumeration = EnumNumericNodeId_Enumeration,
	//! Describes a value that is an image encoded as a string of bytes.
	EnumDataTypeId_Image = EnumNumericNodeId_Image,
	//! Describes a value that specifies the significance of the BrowseName for an instance declaration.
	EnumDataTypeId_NamingRuleType = EnumNumericNodeId_NamingRuleType,
	//! A period of time measured in seconds.
	EnumDataTypeId_Duration = EnumNumericNodeId_Duration,
	//! Specifies a range of array indexes.
	EnumDataTypeId_NumericRange = EnumNumericNodeId_NumericRange,
	//! A date/time value specified in Universal Coordinated Time (UTC).
	EnumDataTypeId_UtcTime = EnumNumericNodeId_UtcTime,
	//! An identifier for a user locale.
	EnumDataTypeId_LocaleId = EnumNumericNodeId_LocaleId,
	//! An argument for a method.
	EnumDataTypeId_Argument = EnumNumericNodeId_Argument,
	//! Describes an application and how to find it.
	EnumDataTypeId_ApplicationDescription = EnumNumericNodeId_ApplicationDescription,
	//! A base type for a user identity token.
	EnumDataTypeId_UserIdentityToken = EnumNumericNodeId_UserIdentityToken,
	//! A token representing an anonymous user.
	EnumDataTypeId_AnonymousIdentityToken = EnumNumericNodeId_AnonymousIdentityToken,
	//! A token representing a user identified by a user name and password.
	EnumDataTypeId_UserNameIdentityToken = EnumNumericNodeId_UserNameIdentityToken,
	//! A token representing a user identified by an X509 certificate.
	EnumDataTypeId_X509IdentityToken = EnumNumericNodeId_X509IdentityToken,
	//! A description for the BuildInfo DataType.
	EnumDataTypeId_BuildInfo = EnumNumericNodeId_BuildInfo,
	//! A software certificate with a digital signature.
	EnumDataTypeId_SignedSoftwareCertificate = EnumNumericNodeId_SignedSoftwareCertificate,
	//! The description of a reference.
	EnumDataTypeId_ReferenceDescription = EnumNumericNodeId_ReferenceDescription,
	//! A description for the EventFilter DataType.
	EnumDataTypeId_EventFilter = EnumNumericNodeId_EventFilter,
	//! A description for the ServerDiagnosticsSummaryDataType DataType.
	EnumDataTypeId_ServerDiagnosticsSummaryDataType = EnumNumericNodeId_ServerDiagnosticsSummaryDataType,
	//! A description for the ServerStatusDataType DataType.
	EnumDataTypeId_ServerStatusDataType = EnumNumericNodeId_ServerStatusDataType,
	//! A description for the SessionDiagnosticsDataType DataType.
	EnumDataTypeId_SessionDiagnosticsDataType = EnumNumericNodeId_SessionDiagnosticsDataType,
	//! A description for the SessionSecurityDiagnosticsDataType DataType.
	EnumDataTypeId_SessionSecurityDiagnosticsDataType = EnumNumericNodeId_SessionSecurityDiagnosticsDataType,
	//! A description for the ServiceCounterDataType DataType.
	EnumDataTypeId_ServiceCounterDataType = EnumNumericNodeId_ServiceCounterDataType,
	//! A description for the SubscriptionDiagnosticsDataType DataType.
	EnumDataTypeId_SubscriptionDiagnosticsDataType = EnumNumericNodeId_SubscriptionDiagnosticsDataType,
	//! A description for the ModelChangeStructureDataType DataType.
	EnumDataTypeId_ModelChangeStructureDataType = EnumNumericNodeId_ModelChangeStructureDataType,
	//! A description for the Range DataType.
	EnumDataTypeId_Range = EnumNumericNodeId_Range,
	//! A description for the EUInformation DataType.
	EnumDataTypeId_EUInformation = EnumNumericNodeId_EUInformation,
	//! A description for the SemanticChangeStructureDataType DataType.
	EnumDataTypeId_SemanticChangeStructureDataType = EnumNumericNodeId_SemanticChangeStructureDataType,
	//! A token representing a user identified by a WS-Security XML token.
	EnumDataTypeId_IssuedIdentityToken = EnumNumericNodeId_IssuedIdentityToken,
	//! An image encoded in BMP format.
	EnumDataTypeId_ImageBMP = EnumNumericNodeId_ImageBMP,
	//! An image encoded in GIF format.
	EnumDataTypeId_ImageGIF = EnumNumericNodeId_ImageGIF,
	//! An image encoded in JPEG format.
	EnumDataTypeId_ImageJPG = EnumNumericNodeId_ImageJPG,
	//! An image encoded in PNG format.
	EnumDataTypeId_ImagePNG = EnumNumericNodeId_ImagePNG,
	//! A mapping between a value of an enumerated type and a name and description.
	EnumDataTypeId_EnumValueType = EnumNumericNodeId_EnumValueType,
	//! A description for the TimeZoneDataType DataType.
	EnumDataTypeId_TimeZoneDataType = EnumNumericNodeId_TimeZoneDataType

} EnumDataTypeId; // end EnumDataTypeId;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumDataTypeIdString(EnumDataTypeId value);
EnumDataTypeId OTGetEnumDataTypeIdFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumDataTypeIdString(EnumDataTypeId value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumDataTypeId getEnumDataTypeIdFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration for predefined object types (object type definitions). The single values are not documented
//! here, you have to refer to the UA specifications.
typedef enum tagEnumObjectTypeId // Declaration of enum EnumObjectTypeId
{
	//! The base type for all object nodes.
	EnumObjectTypeId_BaseObjectType = EnumNumericNodeId_BaseObjectType,
	//! The type for objects that organize other nodes.
	EnumObjectTypeId_FolderType = EnumNumericNodeId_FolderType,
	//! A description for the DataTypeSystemType ObjectType.
	EnumObjectTypeId_DataTypeSystemType = EnumNumericNodeId_DataTypeSystemType,
	//! A description for the DataTypeEncodingType ObjectType.
	EnumObjectTypeId_DataTypeEncodingType = EnumNumericNodeId_DataTypeEncodingType,
	//! The type for an object that describes how an instance declaration is used when a type is instantiated.
	EnumObjectTypeId_ModellingRuleType = EnumNumericNodeId_ModellingRuleType,
	//! Specifies the current status and capabilities of the server.
	EnumObjectTypeId_ServerType = EnumNumericNodeId_ServerType,
	//! Describes the capabilities supported by the server.
	EnumObjectTypeId_ServerCapabilitiesType = EnumNumericNodeId_ServerCapabilitiesType,
	//! The diagnostics information for a server.
	EnumObjectTypeId_ServerDiagnosticsType = EnumNumericNodeId_ServerDiagnosticsType,
	//! Provides a summary of session level diagnostics.
	EnumObjectTypeId_SessionsDiagnosticsSummaryType = EnumNumericNodeId_SessionsDiagnosticsSummaryType,
	//! A container for session level diagnostics information.
	EnumObjectTypeId_SessionDiagnosticsObjectType = EnumNumericNodeId_SessionDiagnosticsObjectType,
	//! A base type for vendor specific server information.
	EnumObjectTypeId_VendorServerInfoType = EnumNumericNodeId_VendorServerInfoType,
	//! A base type for an object that describe how a server supports redundancy.
	EnumObjectTypeId_ServerRedundancyType = EnumNumericNodeId_ServerRedundancyType,
	//! Identifies the capabilties of server that supports transparent redundancy.
	EnumObjectTypeId_TransparentRedundancyType = EnumNumericNodeId_TransparentRedundancyType,
	//! Identifies the capabilties of server that supports non-transparent redundancy.
	EnumObjectTypeId_NonTransparentRedundancyType = EnumNumericNodeId_NonTransparentRedundancyType,
	//! The base type for all events.
	EnumObjectTypeId_BaseEventType = EnumNumericNodeId_BaseEventType,
	//! A base type for events used to track client initiated changes to the server state.
	EnumObjectTypeId_AuditEventType = EnumNumericNodeId_AuditEventType,
	//! A base type for events used to track security related changes.
	EnumObjectTypeId_AuditSecurityEventType = EnumNumericNodeId_AuditSecurityEventType,
	//! A base type for events used to track related changes to a secure channel.
	EnumObjectTypeId_AuditChannelEventType = EnumNumericNodeId_AuditChannelEventType,
	//! An event that is raised when a secure channel is opened.
	EnumObjectTypeId_AuditOpenSecureChannelEventType = EnumNumericNodeId_AuditOpenSecureChannelEventType,
	//! A base type for events used to track related changes to a session.
	EnumObjectTypeId_AuditSessionEventType = EnumNumericNodeId_AuditSessionEventType,
	//! An event that is raised when a session is created.
	EnumObjectTypeId_AuditCreateSessionEventType = EnumNumericNodeId_AuditCreateSessionEventType,
	//! A description for the AuditActivateSessionEventType ObjectType.
	EnumObjectTypeId_AuditActivateSessionEventType = EnumNumericNodeId_AuditActivateSessionEventType,
	//! A description for the AuditCancelEventType ObjectType.
	EnumObjectTypeId_AuditCancelEventType = EnumNumericNodeId_AuditCancelEventType,
	//! A description for the AuditCertificateEventType ObjectType.
	EnumObjectTypeId_AuditCertificateEventType = EnumNumericNodeId_AuditCertificateEventType,
	//! A description for the AuditCertificateDataMismatchEventType ObjectType.
	EnumObjectTypeId_AuditCertificateDataMismatchEventType = EnumNumericNodeId_AuditCertificateDataMismatchEventType,
	//! A description for the AuditCertificateExpiredEventType ObjectType.
	EnumObjectTypeId_AuditCertificateExpiredEventType = EnumNumericNodeId_AuditCertificateExpiredEventType,
	//! A description for the AuditCertificateInvalidEventType ObjectType.
	EnumObjectTypeId_AuditCertificateInvalidEventType = EnumNumericNodeId_AuditCertificateInvalidEventType,
	//! A description for the AuditCertificateUntrustedEventType ObjectType.
	EnumObjectTypeId_AuditCertificateUntrustedEventType = EnumNumericNodeId_AuditCertificateUntrustedEventType,
	//! A description for the AuditCertificateRevokedEventType ObjectType.
	EnumObjectTypeId_AuditCertificateRevokedEventType = EnumNumericNodeId_AuditCertificateRevokedEventType,
	//! A description for the AuditCertificateMismatchEventType ObjectType.
	EnumObjectTypeId_AuditCertificateMismatchEventType = EnumNumericNodeId_AuditCertificateMismatchEventType,
	//! A description for the AuditNodeManagementEventType ObjectType.
	EnumObjectTypeId_AuditNodeManagementEventType = EnumNumericNodeId_AuditNodeManagementEventType,
	//! A description for the AuditAddNodesEventType ObjectType.
	EnumObjectTypeId_AuditAddNodesEventType = EnumNumericNodeId_AuditAddNodesEventType,
	//! A description for the AuditDeleteNodesEventType ObjectType.
	EnumObjectTypeId_AuditDeleteNodesEventType = EnumNumericNodeId_AuditDeleteNodesEventType,
	//! A description for the AuditAddReferencesEventType ObjectType.
	EnumObjectTypeId_AuditAddReferencesEventType = EnumNumericNodeId_AuditAddReferencesEventType,
	//! A description for the AuditDeleteReferencesEventType ObjectType.
	EnumObjectTypeId_AuditDeleteReferencesEventType = EnumNumericNodeId_AuditDeleteReferencesEventType,
	//! A description for the AuditUpdateEventType ObjectType.
	EnumObjectTypeId_AuditUpdateEventType = EnumNumericNodeId_AuditUpdateEventType,
	//! A description for the AuditWriteUpdateEventType ObjectType.
	EnumObjectTypeId_AuditWriteUpdateEventType = EnumNumericNodeId_AuditWriteUpdateEventType,
	//! A description for the AuditHistoryUpdateEventType ObjectType.
	EnumObjectTypeId_AuditHistoryUpdateEventType = EnumNumericNodeId_AuditHistoryUpdateEventType,
	//! A description for the AuditUpdateMethodEventType ObjectType.
	EnumObjectTypeId_AuditUpdateMethodEventType = EnumNumericNodeId_AuditUpdateMethodEventType,
	//! A description for the SystemEventType ObjectType.
	EnumObjectTypeId_SystemEventType = EnumNumericNodeId_SystemEventType,
	//! A description for the DeviceFailureEventType ObjectType.
	EnumObjectTypeId_DeviceFailureEventType = EnumNumericNodeId_DeviceFailureEventType,
	//! A description for the BaseModelChangeEventType ObjectType.
	EnumObjectTypeId_BaseModelChangeEventType = EnumNumericNodeId_BaseModelChangeEventType,
	//! A description for the GeneralModelChangeEventType ObjectType.
	EnumObjectTypeId_GeneralModelChangeEventType = EnumNumericNodeId_GeneralModelChangeEventType,
	//! A description for the StateMachineType ObjectType.
	EnumObjectTypeId_StateMachineType = EnumNumericNodeId_StateMachineType,
	//! A description for the StateType ObjectType.
	EnumObjectTypeId_StateType = EnumNumericNodeId_StateType,
	//! A description for the InitialStateType ObjectType.
	EnumObjectTypeId_InitialStateType = EnumNumericNodeId_InitialStateType,
	//! A description for the TransitionType ObjectType.
	EnumObjectTypeId_TransitionType = EnumNumericNodeId_TransitionType,
	//! A description for the TransitionEventType ObjectType.
	EnumObjectTypeId_TransitionEventType = EnumNumericNodeId_TransitionEventType,
	//! A description for the AuditUpdateStateEventType ObjectType.
	EnumObjectTypeId_AuditUpdateStateEventType = EnumNumericNodeId_AuditUpdateStateEventType,
	//! A description for the HistoricalDataConfigurationType ObjectType.
	EnumObjectTypeId_HistoricalDataConfigurationType = EnumNumericNodeId_HistoricalDataConfigurationType,
	//! A description for the HistoryServerCapabilitiesType ObjectType.
	EnumObjectTypeId_HistoryServerCapabilitiesType = EnumNumericNodeId_HistoryServerCapabilitiesType,
	//! A description for the AggregateFunctionType ObjectType.
	EnumObjectTypeId_AggregateFunctionType = EnumNumericNodeId_AggregateFunctionType,
	//! A description for the ProgramTransitionEventType ObjectType.
	EnumObjectTypeId_ProgramTransitionEventType = EnumNumericNodeId_ProgramTransitionEventType,
	//! A state machine for a program.
	EnumObjectTypeId_ProgramStateMachineType = EnumNumericNodeId_ProgramStateMachineType,
	//! A description for the SemanticChangeEventType ObjectType.
	EnumObjectTypeId_SemanticChangeEventType = EnumNumericNodeId_SemanticChangeEventType,
	//! A description for the AuditUrlMismatchEventType ObjectType.
	EnumObjectTypeId_AuditUrlMismatchEventType = EnumNumericNodeId_AuditUrlMismatchEventType,
	//! A description for the FiniteStateMachineType ObjectType.
	EnumObjectTypeId_FiniteStateMachineType = EnumNumericNodeId_FiniteStateMachineType,
	//! A description for the ConditionType ObjectType.
	EnumObjectTypeId_ConditionType = EnumNumericNodeId_ConditionType,
	//! A description for the RefreshStartEventType ObjectType.
	EnumObjectTypeId_RefreshStartEventType = EnumNumericNodeId_RefreshStartEventType,
	//! A description for the RefreshEndEventType ObjectType.
	EnumObjectTypeId_RefreshEndEventType = EnumNumericNodeId_RefreshEndEventType,
	//! A description for the RefreshRequiredEventType ObjectType.
	EnumObjectTypeId_RefreshRequiredEventType = EnumNumericNodeId_RefreshRequiredEventType,
	//! A description for the AuditConditionEventType ObjectType.
	EnumObjectTypeId_AuditConditionEventType = EnumNumericNodeId_AuditConditionEventType,
	//! A description for the AuditConditionEnableEventType ObjectType.
	EnumObjectTypeId_AuditConditionEnableEventType = EnumNumericNodeId_AuditConditionEnableEventType,
	//! A description for the AuditConditionCommentEventType ObjectType.
	EnumObjectTypeId_AuditConditionCommentEventType = EnumNumericNodeId_AuditConditionCommentEventType,
	//! A description for the DialogConditionType ObjectType.
	EnumObjectTypeId_DialogConditionType = EnumNumericNodeId_DialogConditionType,
	//! A description for the AcknowledgeableConditionType ObjectType.
	EnumObjectTypeId_AcknowledgeableConditionType = EnumNumericNodeId_AcknowledgeableConditionType,
	//! A description for the AlarmConditionType ObjectType.
	EnumObjectTypeId_AlarmConditionType = EnumNumericNodeId_AlarmConditionType,
	//! A description for the ShelvedStateMachineType ObjectType.
	EnumObjectTypeId_ShelvedStateMachineType = EnumNumericNodeId_ShelvedStateMachineType,
	//! A description for the LimitAlarmType ObjectType.
	EnumObjectTypeId_LimitAlarmType = EnumNumericNodeId_LimitAlarmType,
	//! A description for the AuditHistoryEventUpdateEventType ObjectType.
	EnumObjectTypeId_AuditHistoryEventUpdateEventType = EnumNumericNodeId_AuditHistoryEventUpdateEventType,
	//! A description for the AuditHistoryValueUpdateEventType ObjectType.
	EnumObjectTypeId_AuditHistoryValueUpdateEventType = EnumNumericNodeId_AuditHistoryValueUpdateEventType,
	//! A description for the AuditHistoryDeleteEventType ObjectType.
	EnumObjectTypeId_AuditHistoryDeleteEventType = EnumNumericNodeId_AuditHistoryDeleteEventType,
	//! A description for the AuditHistoryRawModifyDeleteEventType ObjectType.
	EnumObjectTypeId_AuditHistoryRawModifyDeleteEventType = EnumNumericNodeId_AuditHistoryRawModifyDeleteEventType,
	//! A description for the AuditHistoryAtTimeDeleteEventType ObjectType.
	EnumObjectTypeId_AuditHistoryAtTimeDeleteEventType = EnumNumericNodeId_AuditHistoryAtTimeDeleteEventType,
	//! A description for the AuditHistoryEventDeleteEventType ObjectType.
	EnumObjectTypeId_AuditHistoryEventDeleteEventType = EnumNumericNodeId_AuditHistoryEventDeleteEventType,
	//! A description for the EventQueueOverflowEventType ObjectType.
	EnumObjectTypeId_EventQueueOverflowEventType = EnumNumericNodeId_EventQueueOverflowEventType,
	//! A description for the ProgramTransitionAuditEventType ObjectType.
	EnumObjectTypeId_ProgramTransitionAuditEventType = EnumNumericNodeId_ProgramTransitionAuditEventType,
	//! A description for the LockType ObjectType.
	EnumObjectTypeId_LockType = EnumNumericNodeId_LockType,
	//! A description for the AuditConditionRespondEventType ObjectType.
	EnumObjectTypeId_AuditConditionRespondEventType = EnumNumericNodeId_AuditConditionRespondEventType,
	//! A description for the AuditConditionAcknowledgeEventType ObjectType.
	EnumObjectTypeId_AuditConditionAcknowledgeEventType = EnumNumericNodeId_AuditConditionAcknowledgeEventType,
	//! A description for the AuditConditionConfirmEventType ObjectType.
	EnumObjectTypeId_AuditConditionConfirmEventType = EnumNumericNodeId_AuditConditionConfirmEventType,
	//! A description for the ExclusiveLimitStateMachineType ObjectType.
	EnumObjectTypeId_ExclusiveLimitStateMachineType = EnumNumericNodeId_ExclusiveLimitStateMachineType,
	//! A description for the ExclusiveLimitAlarmType ObjectType.
	EnumObjectTypeId_ExclusiveLimitAlarmType = EnumNumericNodeId_ExclusiveLimitAlarmType,
	//! A description for the ExclusiveLevelAlarmType ObjectType.
	EnumObjectTypeId_ExclusiveLevelAlarmType = EnumNumericNodeId_ExclusiveLevelAlarmType,
	//! A description for the ExclusiveRateOfChangeAlarmType ObjectType.
	EnumObjectTypeId_ExclusiveRateOfChangeAlarmType = EnumNumericNodeId_ExclusiveRateOfChangeAlarmType,
	//! A description for the ExclusiveDeviationAlarmType ObjectType.
	EnumObjectTypeId_ExclusiveDeviationAlarmType = EnumNumericNodeId_ExclusiveDeviationAlarmType,
	//! A description for the NonExclusiveLimitAlarmType ObjectType.
	EnumObjectTypeId_NonExclusiveLimitAlarmType = EnumNumericNodeId_NonExclusiveLimitAlarmType,
	//! A description for the NonExclusiveLevelAlarmType ObjectType.
	EnumObjectTypeId_NonExclusiveLevelAlarmType = EnumNumericNodeId_NonExclusiveLevelAlarmType,
	//! A description for the NonExclusiveRateOfChangeAlarmType ObjectType.
	EnumObjectTypeId_NonExclusiveRateOfChangeAlarmType = EnumNumericNodeId_NonExclusiveRateOfChangeAlarmType,
	//! A description for the NonExclusiveDeviationAlarmType ObjectType.
	EnumObjectTypeId_NonExclusiveDeviationAlarmType = EnumNumericNodeId_NonExclusiveDeviationAlarmType,
	//! A description for the DiscreteAlarmType ObjectType.
	EnumObjectTypeId_DiscreteAlarmType = EnumNumericNodeId_DiscreteAlarmType,
	//! A description for the OffNormalAlarmType ObjectType.
	EnumObjectTypeId_OffNormalAlarmType = EnumNumericNodeId_OffNormalAlarmType,
	//! A description for the TripAlarmType ObjectType.
	EnumObjectTypeId_TripAlarmType = EnumNumericNodeId_TripAlarmType,
	//! A description for the AuditConditionShelvingEventType ObjectType.
	EnumObjectTypeId_AuditConditionShelvingEventType = EnumNumericNodeId_AuditConditionShelvingEventType,
	//! A description for the BaseConditionClassType ObjectType.
	EnumObjectTypeId_BaseConditionClassType = EnumNumericNodeId_BaseConditionClassType,
	//! A description for the ProcessConditionClassType ObjectType.
	EnumObjectTypeId_ProcessConditionClassType = EnumNumericNodeId_ProcessConditionClassType,
	//! A description for the MaintenanceConditionClassType ObjectType.
	EnumObjectTypeId_MaintenanceConditionClassType = EnumNumericNodeId_MaintenanceConditionClassType,
	//! A description for the SystemConditionClassType ObjectType.
	EnumObjectTypeId_SystemConditionClassType = EnumNumericNodeId_SystemConditionClassType,
	//! A description for the AggregateConfigurationType ObjectType.
	EnumObjectTypeId_AggregateConfigurationType = EnumNumericNodeId_AggregateConfigurationType,
	//! A description for the ProgressEventType ObjectType.
	EnumObjectTypeId_ProgressEventType = EnumNumericNodeId_ProgressEventType,
	//! A description for the SystemStatusChangeEventType ObjectType.
	EnumObjectTypeId_SystemStatusChangeEventType = EnumNumericNodeId_SystemStatusChangeEventType,
	//! Identifies the operation limits imposed by the server.
	EnumObjectTypeId_OperationLimitsType = EnumNumericNodeId_OperationLimitsType,
	//! An object that represents a file that can be accessed via the server.
	EnumObjectTypeId_FileType = EnumNumericNodeId_FileType,
	//! A file used to store a namespace exported from the server.
	EnumObjectTypeId_AddressSpaceFileType = EnumNumericNodeId_AddressSpaceFileType,
	//! Provides the metadata for a namespace used by the server.
	EnumObjectTypeId_NamespaceMetadataType = EnumNumericNodeId_NamespaceMetadataType,
	//! A container for the namespace metadata provided by the server.
	EnumObjectTypeId_NamespacesType = EnumNumericNodeId_NamespacesType,
	//! A description for the SystemOffNormalAlarmType ObjectType.
	EnumObjectTypeId_SystemOffNormalAlarmType = EnumNumericNodeId_SystemOffNormalAlarmType,
	//! A description for the AuditProgramTransitionEventType ObjectType.
	EnumObjectTypeId_AuditProgramTransitionEventType = EnumNumericNodeId_AuditProgramTransitionEventType,
	//! A description for the NonTransparentNetworkRedundancyType ObjectType.
	EnumObjectTypeId_NonTransparentNetworkRedundancyType = EnumNumericNodeId_NonTransparentNetworkRedundancyType,
	//! A description for the TrustListType ObjectType.
	EnumObjectTypeId_TrustListType = EnumNumericNodeId_TrustListType,
	//! A description for the AuthorityType ObjectType.
	EnumObjectTypeId_AuthorityType = EnumNumericNodeId_AuthorityType,
	//! A description for the CertificateType ObjectType.
	EnumObjectTypeId_CertificateType = EnumNumericNodeId_CertificateType,
	//! A description for the ApplicationCertificateType ObjectType.
	EnumObjectTypeId_ApplicationCertificateType = EnumNumericNodeId_ApplicationCertificateType,
	//! A description for the HttpsCertificateType ObjectType.
	EnumObjectTypeId_HttpsCertificateType = EnumNumericNodeId_HttpsCertificateType,
	//! A description for the RsaBasicApplicationCertificateType ObjectType.
	EnumObjectTypeId_RsaBasicApplicationCertificateType = EnumNumericNodeId_RsaBasicApplicationCertificateType,
	//! A description for the Rsa2084ApplicationCertificateType ObjectType.
	EnumObjectTypeId_Rsa2084ApplicationCertificateType = EnumNumericNodeId_Rsa2084ApplicationCertificateType,
	//! A description for the TrustListUpdatedAuditEventType ObjectType.
	EnumObjectTypeId_TrustListUpdatedAuditEventType = EnumNumericNodeId_TrustListUpdatedAuditEventType,
	//! A description for the ServerConfigurationType ObjectType.
	EnumObjectTypeId_ServerConfigurationType = EnumNumericNodeId_ServerConfigurationType,
	//! A description for the CertificateUpdatedAuditEventType ObjectType.
	EnumObjectTypeId_CertificateUpdatedAuditEventType = EnumNumericNodeId_CertificateUpdatedAuditEventType

} EnumObjectTypeId; // end EnumObjectTypeId;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumObjectTypeIdString(EnumObjectTypeId value);
EnumObjectTypeId OTGetEnumObjectTypeIdFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumObjectTypeIdString(EnumObjectTypeId value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumObjectTypeId getEnumObjectTypeIdFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! The predefined UA reference types as enumeration type.
typedef enum tagEnumReferenceTypeId // Declaration of enum EnumReferenceTypeId
{
	//! The abstract base type for all references.
	EnumReferenceTypeId_References = EnumNumericNodeId_References,
	//! The abstract base type for all non-hierarchical references.
	EnumReferenceTypeId_NonHierarchicalReferences = EnumNumericNodeId_NonHierarchicalReferences,
	//! The abstract base type for all hierarchical references.
	EnumReferenceTypeId_HierarchicalReferences = EnumNumericNodeId_HierarchicalReferences,
	//! The abstract base type for all non-looping hierarchical references.
	EnumReferenceTypeId_HasChild = EnumNumericNodeId_HasChild,
	//! The type for hierarchical references that are used to organize nodes.
	EnumReferenceTypeId_Organizes = EnumNumericNodeId_Organizes,
	//! The type for non-looping hierarchical references that are used to organize event sources.
	EnumReferenceTypeId_HasEventSource = EnumNumericNodeId_HasEventSource,
	//! The type for references from instance declarations to modelling rule nodes.
	EnumReferenceTypeId_HasModellingRule = EnumNumericNodeId_HasModellingRule,
	//! The type for references from data type nodes to to data type encoding nodes.
	EnumReferenceTypeId_HasEncoding = EnumNumericNodeId_HasEncoding,
	//! The type for references from data type encoding nodes to data type description nodes.
	EnumReferenceTypeId_HasDescription = EnumNumericNodeId_HasDescription,
	//! The type for references from a instance node its type defintion node.
	EnumReferenceTypeId_HasTypeDefinition = EnumNumericNodeId_HasTypeDefinition,
	//! The type for references from a node to an event type that is raised by node.
	EnumReferenceTypeId_GeneratesEvent = EnumNumericNodeId_GeneratesEvent,
	//! The type for non-looping hierarchical references that are used to aggregate nodes into complex types.
	EnumReferenceTypeId_Aggregates = EnumNumericNodeId_Aggregates,
	//! The type for non-looping hierarchical references that are used to define sub types.
	EnumReferenceTypeId_HasSubtype = EnumNumericNodeId_HasSubtype,
	//! The type for non-looping hierarchical reference from a node to its property.
	EnumReferenceTypeId_HasProperty = EnumNumericNodeId_HasProperty,
	//! The type for non-looping hierarchical reference from a node to its component.
	EnumReferenceTypeId_HasComponent = EnumNumericNodeId_HasComponent,
	//! The type for non-looping hierarchical references that are used to indicate how events propagate from node to node.
	EnumReferenceTypeId_HasNotifier = EnumNumericNodeId_HasNotifier,
	//! The type for non-looping hierarchical reference from a node to its component when the order of references matters.
	EnumReferenceTypeId_HasOrderedComponent = EnumNumericNodeId_HasOrderedComponent,
	//! The type for a reference to the state before a transition.
	EnumReferenceTypeId_FromState = EnumNumericNodeId_FromState,
	//! The type for a reference to the state after a transition.
	EnumReferenceTypeId_ToState = EnumNumericNodeId_ToState,
	//! The type for a reference to a method that can cause a transition to occur.
	EnumReferenceTypeId_HasCause = EnumNumericNodeId_HasCause,
	//! The type for a reference to an event that may be raised when a transition occurs.
	EnumReferenceTypeId_HasEffect = EnumNumericNodeId_HasEffect,
	//! The type for a reference to the historical configuration for a data variable.
	EnumReferenceTypeId_HasHistoricalConfiguration = EnumNumericNodeId_HasHistoricalConfiguration,
	//! The type for a reference to a substate for a state.
	EnumReferenceTypeId_HasSubStateMachine = EnumNumericNodeId_HasSubStateMachine,
	//! The type for references from a node to an event type that is always raised by node.
	EnumReferenceTypeId_AlwaysGeneratesEvent = EnumNumericNodeId_AlwaysGeneratesEvent,
	//! A description for the HasTrueSubState ReferenceType.
	EnumReferenceTypeId_HasTrueSubState = EnumNumericNodeId_HasTrueSubState,
	//! A description for the HasFalseSubState ReferenceType.
	EnumReferenceTypeId_HasFalseSubState = EnumNumericNodeId_HasFalseSubState,
	//! A description for the HasCondition ReferenceType.
	EnumReferenceTypeId_HasCondition = EnumNumericNodeId_HasCondition

} EnumReferenceTypeId; // end EnumReferenceTypeId;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumReferenceTypeIdString(EnumReferenceTypeId value);
EnumReferenceTypeId OTGetEnumReferenceTypeIdFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumReferenceTypeIdString(EnumReferenceTypeId value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumReferenceTypeId getEnumReferenceTypeIdFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration of node IDs representing various variable type nodes.
typedef enum tagEnumVariableTypeId // Declaration of enum EnumVariableTypeId
{
	//! The abstract base type for all variable nodes.
	EnumVariableTypeId_BaseVariableType = EnumNumericNodeId_BaseVariableType,
	//! The type for variable that represents a process value.
	EnumVariableTypeId_BaseDataVariableType = EnumNumericNodeId_BaseDataVariableType,
	//! The type for variable that represents a property of another node.
	EnumVariableTypeId_PropertyType = EnumNumericNodeId_PropertyType,
	//! The type for variable that represents the description of a data type encoding.
	EnumVariableTypeId_DataTypeDescriptionType = EnumNumericNodeId_DataTypeDescriptionType,
	//! The type for variable that represents the collection of data type decriptions.
	EnumVariableTypeId_DataTypeDictionaryType = EnumNumericNodeId_DataTypeDictionaryType,
	//! A description for the ServerVendorCapabilityType VariableType.
	EnumVariableTypeId_ServerVendorCapabilityType = EnumNumericNodeId_ServerVendorCapabilityType,
	//! A description for the ServerStatusType VariableType.
	EnumVariableTypeId_ServerStatusType = EnumNumericNodeId_ServerStatusType,
	//! A description for the ServerDiagnosticsSummaryType VariableType.
	EnumVariableTypeId_ServerDiagnosticsSummaryType = EnumNumericNodeId_ServerDiagnosticsSummaryType,
	//! A description for the SamplingIntervalDiagnosticsArrayType VariableType.
	EnumVariableTypeId_SamplingIntervalDiagnosticsArrayType = EnumNumericNodeId_SamplingIntervalDiagnosticsArrayType,
	//! A description for the SamplingIntervalDiagnosticsType VariableType.
	EnumVariableTypeId_SamplingIntervalDiagnosticsType = EnumNumericNodeId_SamplingIntervalDiagnosticsType,
	//! A description for the SubscriptionDiagnosticsArrayType VariableType.
	EnumVariableTypeId_SubscriptionDiagnosticsArrayType = EnumNumericNodeId_SubscriptionDiagnosticsArrayType,
	//! A description for the SubscriptionDiagnosticsType VariableType.
	EnumVariableTypeId_SubscriptionDiagnosticsType = EnumNumericNodeId_SubscriptionDiagnosticsType,
	//! A description for the SessionDiagnosticsArrayType VariableType.
	EnumVariableTypeId_SessionDiagnosticsArrayType = EnumNumericNodeId_SessionDiagnosticsArrayType,
	//! A description for the SessionDiagnosticsVariableType VariableType.
	EnumVariableTypeId_SessionDiagnosticsVariableType = EnumNumericNodeId_SessionDiagnosticsVariableType,
	//! A description for the SessionSecurityDiagnosticsArrayType VariableType.
	EnumVariableTypeId_SessionSecurityDiagnosticsArrayType = EnumNumericNodeId_SessionSecurityDiagnosticsArrayType,
	//! A description for the SessionSecurityDiagnosticsType VariableType.
	EnumVariableTypeId_SessionSecurityDiagnosticsType = EnumNumericNodeId_SessionSecurityDiagnosticsType,
	//! A variable that contains live automation data.
	EnumVariableTypeId_DataItemType = EnumNumericNodeId_DataItemType,
	//! A description for the AnalogItemType VariableType.
	EnumVariableTypeId_AnalogItemType = EnumNumericNodeId_AnalogItemType,
	//! A description for the DiscreteItemType VariableType.
	EnumVariableTypeId_DiscreteItemType = EnumNumericNodeId_DiscreteItemType,
	//! A description for the TwoStateDiscreteType VariableType.
	EnumVariableTypeId_TwoStateDiscreteType = EnumNumericNodeId_TwoStateDiscreteType,
	//! A description for the MultiStateDiscreteType VariableType.
	EnumVariableTypeId_MultiStateDiscreteType = EnumNumericNodeId_MultiStateDiscreteType,
	//! A description for the ProgramDiagnosticType VariableType.
	EnumVariableTypeId_ProgramDiagnosticType = EnumNumericNodeId_ProgramDiagnosticType,
	//! A description for the StateVariableType VariableType.
	EnumVariableTypeId_StateVariableType = EnumNumericNodeId_StateVariableType,
	//! A description for the FiniteStateVariableType VariableType.
	EnumVariableTypeId_FiniteStateVariableType = EnumNumericNodeId_FiniteStateVariableType,
	//! A description for the TransitionVariableType VariableType.
	EnumVariableTypeId_TransitionVariableType = EnumNumericNodeId_TransitionVariableType,
	//! A description for the FiniteTransitionVariableType VariableType.
	EnumVariableTypeId_FiniteTransitionVariableType = EnumNumericNodeId_FiniteTransitionVariableType,
	//! A description for the BuildInfoType VariableType.
	EnumVariableTypeId_BuildInfoType = EnumNumericNodeId_BuildInfoType,
	//! A description for the TwoStateVariableType VariableType.
	EnumVariableTypeId_TwoStateVariableType = EnumNumericNodeId_TwoStateVariableType,
	//! A description for the ConditionVariableType VariableType.
	EnumVariableTypeId_ConditionVariableType = EnumNumericNodeId_ConditionVariableType,
	//! A description for the MultiStateValueDiscreteType VariableType.
	EnumVariableTypeId_MultiStateValueDiscreteType = EnumNumericNodeId_MultiStateValueDiscreteType,
	//! A description for the OptionSetType VariableType.
	EnumVariableTypeId_OptionSetType = EnumNumericNodeId_OptionSetType,
	//! A description for the ArrayItemType VariableType.
	EnumVariableTypeId_ArrayItemType = EnumNumericNodeId_ArrayItemType,
	//! A description for the YArrayItemType VariableType.
	EnumVariableTypeId_YArrayItemType = EnumNumericNodeId_YArrayItemType,
	//! A description for the XYArrayItemType VariableType.
	EnumVariableTypeId_XYArrayItemType = EnumNumericNodeId_XYArrayItemType,
	//! A description for the ImageItemType VariableType.
	EnumVariableTypeId_ImageItemType = EnumNumericNodeId_ImageItemType,
	//! A description for the CubeItemType VariableType.
	EnumVariableTypeId_CubeItemType = EnumNumericNodeId_CubeItemType,
	//! A description for the NDimensionArrayItemType VariableType.
	EnumVariableTypeId_NDimensionArrayItemType = EnumNumericNodeId_NDimensionArrayItemType

} EnumVariableTypeId; // end EnumVariableTypeId;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumVariableTypeIdString(EnumVariableTypeId value);
EnumVariableTypeId OTGetEnumVariableTypeIdFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumVariableTypeIdString(EnumVariableTypeId value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumVariableTypeId getEnumVariableTypeIdFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Bit coded enumeration Defining additional results to be returned from a browse call.
//! A browse call defines with a combination of the single values the results to be returned.
typedef OTUInt32 EnumResultMask;

//! None of the possible additional results is contained in the browse result (means the result contains only
//! the NodeId of the target node).
static const EnumResultMask EnumResultMask_None = 0;
//! If set the reference type of the used reference leading to the node will be returned.
//! E.g. if the found node is bound by a "HasComponent" reference to the source node that type will be returned.
static const EnumResultMask EnumResultMask_ReferenceType = 1;
//! If set the returned result contains a "true" for forward references and a false for backward references.
//!
//! The flag is only useful if browseDirection both is used in the browse call.
static const EnumResultMask EnumResultMask_IsForward = 2;
//! If set the node class of the result node is returned.
static const EnumResultMask EnumResultMask_NodeClass = 4;
//! If set the BrowseName of the result node is returned in the browse result.
static const EnumResultMask EnumResultMask_BrowseName = 8;
//! If set the DisplayName of the result node is returned in the browse result.
static const EnumResultMask EnumResultMask_DisplayName = 16;
//! If set the TypeDefinition NodeId of the found node is contained in the browse result.
static const EnumResultMask EnumResultMask_TypeDefinition = 32;
//! All possible values are contained in the browse result.
static const EnumResultMask EnumResultMask_All = 63;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumResultMaskString(EnumResultMask value);
EnumResultMask OTGetEnumResultMaskFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumResultMaskString(EnumResultMask value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumResultMask getEnumResultMaskFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Bit coded enumeration (value can be a combination) defining the allowed access level to a Node.
typedef OTUInt32 EnumWriteMask;

//! Indicates if the AccessLevel Attribute is writable.
static const EnumWriteMask EnumWriteMask_AccessLevel = 1;
//! Indicates if the ArrayDimensions Attribute is writable.
static const EnumWriteMask EnumWriteMask_ArrayDimensions = 0x2;
//! Indicates if the BrowseName Attribute is writable.
static const EnumWriteMask EnumWriteMask_BrowseName = 0x4;
//! Indicates if the ContainsNoLoops Attribute is writable.
static const EnumWriteMask EnumWriteMask_ContainsNoLoops = 0x8;
//! Indicates if the DataType Attribute is writable.
static const EnumWriteMask EnumWriteMask_DataType = 0x10;
//! Indicates if the Description Attribute is writable.
static const EnumWriteMask EnumWriteMask_Description = 0x20;
//! Indicates if the DisplayName Attribute is writable.
static const EnumWriteMask EnumWriteMask_DisplayName = 0x40;
//! Indicates if the EventNotifier Attribute is writable.
static const EnumWriteMask EnumWriteMask_EventNotifier = 0x80;
//! Indicates if the Executable Attribute is writable.
static const EnumWriteMask EnumWriteMask_Executable = 0x100;
//! Indicates if the Historizing Attribute is writable.
static const EnumWriteMask EnumWriteMask_Historizing = 0x200;
//! Indicates if the InverseName Attribute is writable.
static const EnumWriteMask EnumWriteMask_InverseName = 0x400;
//! Indicates if the IsAbstract Attribute is writable
static const EnumWriteMask EnumWriteMask_IsAbstract = 0x800;
//! Indicates if the MinimumSamplingInterval Attribute is writable.
static const EnumWriteMask EnumWriteMask_MinimumSamplingInterval = 0x1000;
//! Indicates if the NodeClass Attribute is writable.
static const EnumWriteMask EnumWriteMask_NodeClass = 0x2000;
//! Indicates if the NodeId Attribute is writable
static const EnumWriteMask EnumWriteMask_NodeId = 0x4000;
//! Indicates if the Symmetric Attribute is writable
static const EnumWriteMask EnumWriteMask_Symmetric = 0x8000;
//! Indicates if the UserAccessLevel Attribute is writable.
static const EnumWriteMask EnumWriteMask_UserAccessLevel = 0x10000;
//! Indicates if the UserExecutable Attribute is writable.
static const EnumWriteMask EnumWriteMask_UserExecutable = 0x20000;
//! Indicates if the UserWriteMask Attribute is writable.
static const EnumWriteMask EnumWriteMask_UserWriteMask = 0x40000;
//! Indicates if the ValueRank Attribute is writable.
static const EnumWriteMask EnumWriteMask_ValueRank = 0x80000;
//! Indicates if the WriteMask Attribute is writable.
static const EnumWriteMask EnumWriteMask_WriteMask = 0x100000;
//! Indicates if the Value Attribute is writable for a VariableType. It does not apply for
//! Variables since this is handled by the AccessLevel and UserAccessLevel
//! Attributes for the Variable. For Variables this bit shall be set to 0.
static const EnumWriteMask EnumWriteMask_ValueForVariableType = 0x200000;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumWriteMaskString(EnumWriteMask value);
EnumWriteMask OTGetEnumWriteMaskFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumWriteMaskString(EnumWriteMask value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumWriteMask getEnumWriteMaskFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Specifies the conditions under which a data change notification should be reported.
typedef enum tagEnumDataChangeTrigger // Declaration of enum EnumDataChangeTrigger
{
	//! Report a notification ONLY if the StatusCode associated with the value changes.
	EnumDataChangeTrigger_Status = 0,

	//! Report a notification if either the StatusCode or the value change.
	//! The Deadband filter can be used in addition for filtering value changes.
	//! This is the default setting if no filter is set.
	EnumDataChangeTrigger_StatusValue = 1,

	//! Report a notification if either StatusCode, value or the SourceTimestamp change.
	//! The Deadband filter can be used in addition for filtering value changes.
	EnumDataChangeTrigger_StatusValueTimestamp = 2
}
EnumDataChangeTrigger; // end EnumDataChangeTrigger;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumDataChangeTriggerString(EnumDataChangeTrigger value);
EnumDataChangeTrigger OTGetEnumDataChangeTriggerFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumDataChangeTriggerString(EnumDataChangeTrigger value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumDataChangeTrigger getEnumDataChangeTriggerFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Defines the Deadband type and behavior.
typedef enum tagEnumDeadbandType // Declaration of enum EnumDeadbandType
{
	//! No Deadband calculation should be applied.
	EnumDeadbandType_None = 0,

	//! For this type the deadbandValue contains the absolute change in a data value that will cause a Notification
	//! to be generated.
	//! This parameter applies only to Variables with any number data type.
	EnumDeadbandType_Absolute = 1,

	//! For this type of deadband the deadbandValue is defined as the percentage of the EURange.
	//! That is, it applies only to AnalogItems with an EURange Property that defines the typical value range
	//! for the item.
	//! This range will be multiplied with the deadbandValue to generate an exception limit. An exception is determined
	//! as follows:
	//! Exception if (absolute value of (last cached value - current value) > (deadbandValue/100.0) * ((high-low)
	//! of EURange)))
	//! If the item is an array of values and any array element exceeds the deadbandValue, the entire monitored
	//! array is returned.
	EnumDeadbandType_Percent = 2
}
EnumDeadbandType; // end EnumDeadbandType;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumDeadbandTypeString(EnumDeadbandType value);
EnumDeadbandType OTGetEnumDeadbandTypeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumDeadbandTypeString(EnumDeadbandType value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumDeadbandType getEnumDeadbandTypeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Bit coded enumeration exposing the capabilities of a node for event notifications.
//! The Enumeration value applies only to nodes of type Object or View.
//! Only 3 of possible 8 bits are used in the notifier -- the other bits are unused and reserved.
typedef OTUInt8 EnumEventNotifier;

	//! Empty value for init or clear of values.
static const EnumEventNotifier 	EnumEventNotifier_None = 0x00;
	//! Bit 0: Indicates if it can be used to subscribe to Events (0 means cannot be used to subscribe to Events,
	//! 1 means can be used to subscribe to Events).
static const EnumEventNotifier 	EnumEventNotifier_SubscribeToEvents = 0x01;
	//! Bit 2: Indicates if the history of the Events is readable (0 means not readable, 1 means readable).
static const EnumEventNotifier 	EnumEventNotifier_HistoryRead = 0x04;
	//! Bit 3: Indicates if the history of the Events is writeable (0 means not writeable, 1 means writeable).
static const EnumEventNotifier 	EnumEventNotifier_HistoryWrite = 0x08;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumEventNotifierString(EnumEventNotifier value);
EnumEventNotifier OTGetEnumEventNotifierFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumEventNotifierString(EnumEventNotifier value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumEventNotifier getEnumEventNotifierFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! All filter operator types.
typedef enum tagEnumFilterOperator // Declaration of enum EnumFilterOperator
{
	//! TRUE if operand[0] is equal to operand[1].
	//! If the operands have different types then it is tried to convert them implicit to a
	//! common type. If this fails then FALSE is returned.
	EnumFilterOperator_Equals = 0,

	//! TRUE if operand[0] is a null value.
	EnumFilterOperator_IsNull = 1,

	//! TRUE if operand[0] is greater than operand[1].
	//! The following restrictions apply to the operands:
	//! @li [0]: Any operand that resolves to an ordered value.
	//! @li [1]: Any operand that resolves to an ordered value.
	//! The same conversion rules as defined for Equals apply.
	EnumFilterOperator_GreaterThan = 2,

	//! TRUE if operand[0] is less than operand[1].
	//! The same conversion rules and restrictions as defined for GreaterThan apply.
	EnumFilterOperator_LessThan = 3,

	//! TRUE if operand[0] is greater than or equal to operand[1].
	//! The same conversion rules and restrictions as defined for GreaterThan apply.
	EnumFilterOperator_GreaterthanOrEqual = 4,

	//! TRUE if operand[0] is less than or equal to operand[1].
	//! The same conversion rules and restrictions as defined for GreaterThan apply.
	EnumFilterOperator_LessThanOrEqual = 5,

	//! String pattern matching.
	//!
	//! This operator can be used to perform wildcard comparisons. Several special characters can be
	//! included in the second operand of the Like operator. The valid characters:
	//!
	//! @li '%':	Match any string of zero or more characters (i.e. 'main%' would match any string that
	//!				starts with 'main', '%en%' would match any string
	//!				that contains the letters 'en' such as 'entail', 'green' and 'content'.) If a '%' sign is intend in a
	//!				string the list operand can be used (i.e. 5[%] would match '5%').
	//!	@li '_':	Match any single character (i.e. '_ould' would match 'would', 'could'). If the '_' is
	//!				intended in a string then the list operand can be used (i.e. 5[_] would match '5_').
	//! @li '\':	Escape character allows literal interpretation (i.e. \\ is \, \% is %, \_ is _)
	//! @li '[]':	Match any single character in a list
	//!				(i.e. 'abc[13-68] would match 'abc1','abc3','abc4','abc5','abc6', and 'abc8'. 'xyz[c-f]' would match 'xyzc',
	//!				'xyzd', 'xyze', 'xyzf').
	//!	@li '[^]':	Not Matching any single character in a list. The ^ shall be the first character inside on the []
	//!				(i.e. 'ABC[^13-5]' would NOT match 'ABC1', 'ABC3', 'ABC4', and 'ABC5'. xyz[^dgh] would NOT
	//!				match 'xyzd', 'xyzg', 'xyzh'.)
	EnumFilterOperator_Like = 6,

	//! TRUE if operand[0] is FALSE.
	//! The following restrictions apply to the operands:
	//! @li [0]: Any operand that resolves to a Boolean.
	//! If the operand can not be resolved to a Boolean, the result is a NULL.
	EnumFilterOperator_Not = 7,

	//! TRUE if operand[0] is greater or equal to operand[1] and less than or equal to
	//! operand[2].
	//! The following restrictions apply to the operands:
	//! @li [0]: Any operand that resolves to an ordered value.
	//! @li [1]: Any operand that resolves to an ordered value.
	//! @li [2]: Any operand that resolves to an ordered value.
	//!
	//! If the operands are of different types, it is tried to convert them implicit
	//! to a common type. If this fails then FALSE is returned.
	EnumFilterOperator_Between = 8,

	//! TRUE if operand[0] is equal to one or more of the remaining operands.
	//! The Equals Operator is evaluated for operand[0] and each remaining operand in the
	//! list. If any Equals evaluation is TRUE, InList returns TRUE.
	EnumFilterOperator_InList = 9,

	//! TRUE if operand[0] and operand[1] are TRUE.
	//! The following restrictions apply to the operands:
	//! @li [0]: Any operand that resolves to a Boolean.
	//! @li [1]: Any operand that resolves to a Boolean.
	//!
	//! If any operand can not be resolved to a Boolean it is considered a NULL.
	EnumFilterOperator_And = 10,

	//! TRUE if operand[0] or operand[1] are TRUE.
	//! The following restrictions apply to the operands:
	//! @li [0]: Any operand that resolves to a Boolean.
	//! @li [1]: Any operand that resolves to a Boolean.
	//!
	//! If any operand can not be resolved to a Boolean it is considered a NULL.
	EnumFilterOperator_Or = 11,

	//! Converts operand[0] to a value with a data type with a NodeId identified by
	//! operand[1].
	//! The following restrictions apply to the operands:
	//! @li [0]: Any operand.
	//! @li [1]: Any operand that resolves to a NodeId or ExpandedNodeId where the Node
	//! is of the NodeClass DataType.
	//!
	//! If there is any error in conversion or in any of the parameters then the Cast
	//! Operation evaluates to a NULL.
	EnumFilterOperator_Cast = 12,

	//! TRUE if the target Node is contained in the View defined by operand[0].
	//! The following restrictions apply to the operands:
	//! @li [0]: Any operand that resolves to a NodeId that identifies a View Node.
	//!
	//! If operand[0] does not resolve to a NodeId that identifies a View Node, this operation
	//! returns FALSE.
	EnumFilterOperator_InView = 13,

	//! TRUE if the target Node is of type operand[0] or of a subtype of operand[0].
	//! The following restrictions apply to the operands:
	//! @li [0]: Any operand that resolves to a NodeId that identifies an ObjectType or
	//! VariableType Node.
	//!
	//! If operand[0] does not resolve to a NodeId that identifies an ObjectType or
	//! VariableType Node, this operation returns FALSE.
	EnumFilterOperator_OfType = 14,

	//! TRUE if the target Node is of type operand[0] and is related to a NodeId of the type
	//! defined in operand[1] by the Reference type defined in operand[2].
	//! Operand[0] or operand[1] can also point to an element Reference where the referred
	//! to element is another RelatedTo operator. This allows chaining of relationships (e.g.
	//! A is related to B is related to C). In this case, the referred to element returns a list of
	//! NodeIds instead of TRUE or FALSE. In this case if any errors occur or any of the
	//! operands can not be resolved to an appropriate value, the result of the chained
	//! relationship is an empty list of nodes.
	//! Operand[3] defines the number of hops the relationship should be followed. If
	//! operand[3] is 1, then objects shall be directly related. If a hop is greater than 1, then
	//! a NodeId of the type described in operand[1] is checked for at the depth specified by
	//! the hop. In this case, the type of the intermediate Node is undefined, and only the
	//! Reference type used to reach the end Node is defined. If the requested number of
	//! hops cannot be followed, then the result is FALSE, i.e., an empty Node list. If
	//! operand[3] is 0, the relationship is followed to its logical end in a forward direction
	//! and each Node is checked to be of the type specified in operand[1]. If any Node
	//! satisfies this criteria, then the result is TRUE, i.e., the NodeId is included in the sublist.
	//! Operand[4] defines if operand[0] and operand[1] should include support for subtypes of
	//! the types defined by these operands. A TRUE indicates support for subtypes.
	//! Operand[5] defines if operand[2] should include support for subtypes of the
	//! reference type. A TRUE indicates support for subtypes.
	//!
	//! The following restrictions apply to the operands:
	//! @li [0]:	Any operand that resolves to a NodeId or ExpandedNodeId that identifies an
	//!				ObjectType or VariableType Node or a reference to another element which is a
	//!				RelatedTo operator.
	//! @li [1]:	Any operand that resolves to a NodeId or ExpandedNodeId that identifies an
	//!				ObjectType or VariableType Node or a reference to another element which is a
	//!				RelatedTo operator.
	//! @li [2]:	Any operand that resolves to a NodeId that identifies a ReferenceType Node.
	//! @li [3]:	Any operand that resolves to a value implicitly convertible to Int32.
	//! @li [4]:	Any operand that resolves to a value implicitly convertible to a boolean; if this
	//!				operand does not resolve to a Boolean, then a value of FALSE is used.
	//! @li [5]:	Any operand that resolves to a value implicitly convertible to a boolean; if this
	//!				operand does not resolve to a Boolean, then a value of FALSE is used.
	//!
	//! If any of the operands [0],[1],[2],[3] do not resolve to an appropriate value then the
	//! result of this operation is FALSE (or an Empty set in the case of a nested
	//! relatedTo operand).
	EnumFilterOperator_RelatedTo = 15,

	//! The result is an integer which matches the size of the largest operand and contains a
	//! bitwise And operation of the two operands where both have been converted to the
	//! same size (largest of the two operands)
	//! The following restrictions apply to the operands:
	//! @li [0]: Any operand that resolves to an Integer.
	//! @li [1]: Any operand that resolves to an Integer.
	//!
	//! If any operand can not be resolved to an integer it is considered a NULL.
	EnumFilterOperator_BitwiseAnd = 16,

	//! The result is an integer which matches the size of the largest operand and contains a
	//! bitwise Or operation of the two operands where both have been converted to the
	//! same size (largest of the two operands)
	//! The following restrictions apply to the operands:
	//! @li [0]: Any operand that resolves to an Integer.
	//! @li [1]: Any operand that resolves to an Integer.
	//!
	//! If any operand can not be resolved to an Integer it is considered a NULL.
	EnumFilterOperator_BitwiseOr = 17
}
EnumFilterOperator; // end EnumFilterOperator;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumFilterOperatorString(EnumFilterOperator value);
EnumFilterOperator OTGetEnumFilterOperatorFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumFilterOperatorString(EnumFilterOperator value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumFilterOperator getEnumFilterOperatorFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration for the state of a request (server only). The initial state is "Initialized" and the final
//! state "Completed".
//! The two other states can be used by the user but are not evaluated internally.
typedef enum tagEnumRequestState // Declaration of enum EnumRequestState
{
	//! The request has been started. This is the state in which the request is when the callback on server side
	//! is performed.
	EnumRequestState_Started = 1,

	//! This flag indicates that a request (Read / Write Request or method call), is still in a pending state.
	EnumRequestState_Pending = 2,

	//! The request has been completed. If all requests of a transaction are in a completed state the Transaction's
	//! result is sent to the connected client.
	EnumRequestState_Completed = 3
}
EnumRequestState; // end EnumRequestState;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumRequestStateString(EnumRequestState value);
EnumRequestState OTGetEnumRequestStateFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumRequestStateString(EnumRequestState value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumRequestState getEnumRequestStateFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Specifies the monitoring states of a node in the address space.
typedef enum tagEnumMonitoringState // Declaration of enum EnumMonitoringState
{
	//! The related node is not monitored (no related MonitoredItem exists).
	EnumMonitoringState_NotMonitored = 0x00,

	//! The related Node is monitored but currently disabled (the monitored Item is deactivated).
	EnumMonitoringState_Disabled = 0x01,

	//! The related Node is currently monitored (means a reporting MonitoredItem is connected).
	EnumMonitoringState_Active = 0x02
}
EnumMonitoringState; // end EnumMonitoringState;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumMonitoringStateString(EnumMonitoringState value);
EnumMonitoringState OTGetEnumMonitoringStateFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumMonitoringStateString(EnumMonitoringState value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumMonitoringState getEnumMonitoringStateFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Specifies the redundancy support of the server.
typedef enum tagEnumRedundancySupport // Declaration of enum EnumRedundancySupport
{
	//! None means that there is no redundancy support
	EnumRedundancySupport_None = 0,

	//! Cold means that the redundant servers are operational, but do not have any subscriptions defined and do
	//! not accept requests to create one.
	EnumRedundancySupport_Cold = 1,

	//! Warm means that the redundant servers have redundant subscriptions, but with sampling disabled.
	EnumRedundancySupport_Warm = 2,

	//! Hot means that the redundant servers have redundant subscriptions with sampling enabled,
	//! but not reporting.
	EnumRedundancySupport_Hot = 3,

	//!  Transparent means that the server supports transparent redundancy.
	EnumRedundancySupport_Transparent = 4,

	//!  HotAndMirrored means that the server supports redundant subscriptions with sampling enabled.
	EnumRedundancySupport_HotAndMirrored = 5
}
EnumRedundancySupport; // end EnumRedundancySupport;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumRedundancySupportString(EnumRedundancySupport value);
EnumRedundancySupport OTGetEnumRedundancySupportFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumRedundancySupportString(EnumRedundancySupport value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumRedundancySupport getEnumRedundancySupportFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Specifies the source that the server uses for providing initial values
//! for subscriptions
typedef enum tagEnumInitialValueProvider
{
	//! The initial value for the monitored item is retrieved from
	//! the current attribute value of the monitored node
	EnumInitialValueProvider_CurrentAttributeValue = 0x00,

	//! The initial value is provided by an underlying system
	EnumInitialValueProvider_UnderlyingSystem = 0x01
}
EnumInitialValueProvider;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumInitialValueProviderString(EnumInitialValueProvider value);
EnumInitialValueProvider OTGetEnumInitialValueProviderFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumInitialValueProviderString(EnumInitialValueProvider value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumInitialValueProvider getEnumInitialValueProviderFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Service groups which can be enabled and disabled in a server application
typedef enum tagEnumServiceGroup
{
	//! Invalid enumeration value
	EnumServiceGroup_Invalid = 0x00,

	//! Browse, BrowseNext and TranslateBrowsePathsToNodeIds services
	EnumServiceGroup_View = 0x01,

	//! QueryFirst and QueryNext service
	EnumServiceGroup_Query = 0x02,

	//! Read and Write service
	EnumServiceGroup_DataAccess = 0x04,

	//! HistoryRead service
	EnumServiceGroup_HistoricalAccess = 0x08,

	//! Call service
	EnumServiceGroup_Methods = 0x20,

	//! CreateMonitoredItems, ModifyMonitoredItems, SetMonitoringMode,
	//! SetTriggering, DeleteMonitoredItems, CreateSubscription,
	//! ModifySubscription, SetPublishingMode, Publish, Republish,
	//! TransferSubscriptions and DeleteSubscriptions services
	EnumServiceGroup_SubscriptionAndMonitoredItem = 0x40
} EnumServiceGroup;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumServiceGroupString(EnumServiceGroup value);
EnumServiceGroup OTGetEnumServiceGroupFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumServiceGroupString(EnumServiceGroup value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumServiceGroup getEnumServiceGroupFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Timeout groups which can be used to specify different timeouts for each group in a client application
typedef enum tagEnumTimeoutGroup
{
	//! Invalid enumeration value
	EnumTimeoutGroup_Invalid = 0x00,

	//! API methods using this timeout:
	//! Client::Session::browse, Client::Session::browseNode, Client::Session::browseNext,
	//! Client::Session::translateBrowsePathToNodeIds
	//! Default: 5000 ms
	EnumTimeoutGroup_View = 0x01,

	//! API methods using this timeout:
	//! Client::Session::queryFirst, Client::Session::queryFirstAsync,
	//! Client::Session::queryNext, Client::Session::queryNextAsync
	//! Default: 20000 ms
	EnumTimeoutGroup_Query = 0x02,

	//! API methods using this timeout:
	//! Client::Session::read, Client::Session::readAsync,
	//! Client::Session::write, Client::Session::writeAsync
	//! Default: 5000 ms
	EnumTimeoutGroup_DataAccess = 0x04,

	//! API methods using this timeout:
	//! Client::Session::historyReadRaw, Client::Session::historyReadRawAsync,
	//! Client::Session::historyReadProcessed, Client::Session::historyReadProcessedAsync,
	//! Client::Session::historyReadEvent, Client::Session::historyReadEventAsync
	//! Default: 10000 ms
	EnumTimeoutGroup_HistoricalAccess = 0x08,

	//! API methods using this timeout:
	//! Client::Session::callMethods, Client::Session::callMethod, Client::Session::callMethodsAsync
	//! Default: 10000 ms
	EnumTimeoutGroup_Methods = 0x20,

	//! API methods using this timeout:
	//! Client::Subscription::connect, Client::Subscription::disconnect,
	//! Client::Subscription::enablePublishing, Client::Subscription::disablePublishing,
	//! Client::Subscription::update, Client::Subscription::updateMonitoredItems, Client::Subscription::updateChangedMonitoredItems,
	//! Client::Subscription::addMonitoredItem, Client::Subscription::addMonitoredItems,
	//! Client::Subscription::removeMonitoredItem, Client::Subscription::removeMonitoredItems, Client::Subscription::removeAllMonitoredItems,
	//! Client::Subscription::setAllMonitoredItemsMonitoringMode, Client::Subscription::setMonitoredItemsMonitoringMode,
	//! Client::Subscription::conditionRefresh,
	//! Client::MonitoredItem::connect, Client::MonitoredItem::disconnect,
	//! Client::MonitoredItem::addItemsToReport, Client::MonitoredItem::removeItemsToReport,
	//! Client::MonitoredItem::setMonitoringMode
	//! Default: 5000 ms
	EnumTimeoutGroup_SubscriptionAndMonitoredItem = 0x40,

	//! Timeout for publish requests.
	//! Publish requests are sent Toolkit internally to the server. Responses are notified to the client using
	//! Client::Subscription::onDataChange and Client::Subscription::onEventsReceived
	//!
	//! Since publish requests are enqueued at server until new notifications are sent it is recommended to set a long timeout.
	//! Especially do not set this timeout smaller than the maximal used publish interval of a subscription.
	//! 
	//! Default: 60000 ms
	EnumTimeoutGroup_Publish = 0x80,

	//! API methods using this timeout:
	//! Client::Session::connect, Client::Session::disconnect,
	//! Client::Session::addSubscription, Client::Session::removeSubscription,
	//! Client::Session::impersonateDifferentUser, Client::Session::updateNamespaceTable,
	//! Client::Session::cancelTransaction,
	//! Client::Session::registerNodes, Client::Session::unregisterNodes,
	//! Application::getEndpointsFromServer, Application::findServers
	//! Default: 5000 ms
	EnumTimeoutGroup_Session = 0x100
} EnumTimeoutGroup;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumTimeoutGroupString(EnumTimeoutGroup value);
EnumTimeoutGroup OTGetEnumTimeoutGroupFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumTimeoutGroupString(EnumTimeoutGroup value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumTimeoutGroup getEnumTimeoutGroupFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Defines bit masks what errors shall be ignored during validating the certificate
typedef OTUInt32 EnumCertificateCheck;

//! No validation errors are ignored, i.e. every validation error causes the certificate to be rejected.
static const EnumCertificateCheck EnumCertificateCheck_All	= 0x0000;
//! The certificate is not rejected if the current time is not within the period specified in the certificate
static const EnumCertificateCheck EnumCertificateCheck_SuppressCertificateValidityPeriodCheck	= 0x0040;
//! The certificate is not rejected if the current time is not within the period specified in the revocation list
static const EnumCertificateCheck EnumCertificateCheck_SuppressCrlValidityPeriodCheck = 0x0080;
//! The certificate is not rejected if a CRL is not found
static const EnumCertificateCheck EnumCertificateCheck_SuppressCrlNotFoundError = 0x0100;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumCertificateCheckString(EnumCertificateCheck value);
EnumCertificateCheck OTGetEnumCertificateCheckFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumCertificateCheckString(EnumCertificateCheck value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumCertificateCheck getEnumCertificateCheckFromString(const TCHAR* str);
#endif

////////////////////////////////////////////////////////////////////////////////
//! Defines how the CRL check shall be executed
typedef enum tagEnumCrlCheckOption // Declaration of EnumCrlCheckOption
{
	//! Validation of revocation list is omitted
	EnumCrlCheckOption_None = 0,

	//! Only the leaf certificate in the certificate chain is validated in the CRL of its issuer.
	//! This includes self-signed certificates which are validated in their own CRL (i.e. the CRL needs to exist)
	EnumCrlCheckOption_OnlyLeaf = 0x0200,

	//! Every certificate in the certificate chain is validated in the CRL of its issuer.
	//! Self-signed certificated are omitted from. This includes root certificates
	EnumCrlCheckOption_AllExceptSelfSigned = 0x0400,

	//! All certificates in the certificate chain are validated in the CRL of its issuer, including self-signed certificates
	EnumCrlCheckOption_All = 0x0600
}
EnumCrlCheckOption; // end EnumCrlCheckOption;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumCrlCheckOptionString(EnumCrlCheckOption value);
EnumCrlCheckOption OTGetEnumCrlCheckOptionFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumCrlCheckOptionString(EnumCrlCheckOption value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumCrlCheckOption getEnumCrlCheckOptionFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Enumeration describing the concrete subclasses of a DataTypeDescription
typedef enum tagEnumDataTypeDescriptionType // Declaration of enum EnumDataTypeDescriptionType
{
	//! This is the default value, which is invalid for instances of DataTypeDescriptions
	EnumDataTypeDescriptionType_None = 0,
	//! Describes that the DataTypeDescription is an instance of a StructuredDataTypeDesciption
	EnumDataTypeDescriptionType_Structure = 1,
	//! Describes that the DataTypeDescription is an instance of an EnumerationDataTypeDescription
	EnumDataTypeDescriptionType_Enumeration
}
EnumDataTypeDescriptionType; // end EnumDataTypeDescriptionType;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumDataTypeDescriptionType(EnumDataTypeDescriptionType value);
EnumDataTypeDescriptionType OTGetEnumDataTypeDescriptionType(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumDataTypeDescriptionType(EnumDataTypeDescriptionType value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumDataTypeDescriptionType getEnumDataTypeDescriptionType(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! All OPC UA Services defined in the OPC UA Specification Part 4.
//! For internal use only
typedef enum tagEnumServiceType
{
	//! Denotes a OpenSecureChannel request
	EnumServiceType_OpenSecureChannel,
	//! Denotes a CloseSecureChannel request
	EnumServiceType_CloseSecureChannel,
	//! Denotes a FindServers Service
	EnumServiceType_FindServers,
	//! Denotes a RegisterServer Service
	EnumServiceType_RegisterServer,
	//! Denotes a GetEndpoints Service
	EnumServiceType_GetEndpoints,
	//! Denotes a CreateSession Service
	EnumServiceType_CreateSession,
	//! Denotes an ActivateSession Service
	EnumServiceType_ActivateSession,
	//! Denotes a CloseSession Service
	EnumServiceType_CloseSession,
	//! Denotes a Read Service
	EnumServiceType_Read,
	//! Denotes a HistoryRead Service
	EnumServiceType_HistoryRead,
	//! Denotes a Write Service
	EnumServiceType_Write,
	//! Denotes a HistoryUpdate Service
	EnumServiceType_HistoryUpdate,
	//! Denotes a Call Service
	EnumServiceType_Call,
	//! Denotes a CreateMonitoredItems Service
	EnumServiceType_CreateMonitoredItems,
	//! Denotes a ModifyMonitoredItems Service
	EnumServiceType_ModifyMonitoredItems,
	//! Denotes a SetMonitoringMode Service
	EnumServiceType_SetMonitoringMode,
	//! Denotes a SetTriggering Service
	EnumServiceType_SetTriggering,
	//! Denotes a DeleteMonitoredItems Service
	EnumServiceType_DeleteMonitoredItems,
	//! Denotes a CreateSubscription Service
	EnumServiceType_CreateSubscription,
	//! Denotes a ModifySubscription Service
	EnumServiceType_ModifySubscription,
	//! Denotes a SetPublishingMode Service
	EnumServiceType_SetPublishingMode,
	//! Denotes a Publish Service
	EnumServiceType_Publish,
	//! Denotes a Republish Service
	EnumServiceType_Republish,
	//! Denotes a TransferSubscriptions Service
	EnumServiceType_TransferSubscriptions,
	//! Denotes a DeleteSubscriptions Service
	EnumServiceType_DeleteSubscriptions,
	//! Denotes an AddNodes Service
	EnumServiceType_AddNodes,
	//! Denotes an AddReferences Service
	EnumServiceType_AddReferences,
	//! Denotes a DeleteNodes Service
	EnumServiceType_DeleteNodes,
	//! Denotes a DeleteReferences Service
	EnumServiceType_DeleteReferences,
	//! Denotes a Browse Service
	EnumServiceType_Browse,
	//! Denotes a BrowseNext Service
	EnumServiceType_BrowseNext,
	//! Denotes a TranslateBrowsePathsToNodeIds Service
	EnumServiceType_TranslateBrowsePathsToNodeIds,
	//! Denotes a QueryFirst Service
	EnumServiceType_QueryFirst,
	//! Denotes a QueryNext Service
	EnumServiceType_QueryNext,
	//! Denotes a RegisterNodes Service
	EnumServiceType_RegisterNodes,
	//! Denotes an UnregisterNodes Service
	EnumServiceType_UnregisterNodes,
	//! Denotes a Cancel Service
	EnumServiceType_Cancel
}
EnumServiceType;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumServiceTypeString(EnumServiceType value);
EnumServiceType OTGetEnumServiceTypeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumServiceTypeString(EnumServiceType value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumServiceType getEnumServiceTypeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Possible types for converting two Values.
//! A value of this type is returned by the Value::canCastTo() function
typedef enum tagEnumValueCastType
{
	//! Undefined enumeration value.
	EnumValueCastType_NotDefined = 0,
	//! The requested data type needs an implicit conversion.
	EnumValueCastType_Implicit = 1,
	//! The requested data type needs an explicit conversion, possibly loosing information.
	EnumValueCastType_Explicit = 2,
	//! The requested data type does not need any conversion.
	EnumValueCastType_Identity = 3
} EnumValueCastType;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumValueCastTypeString(EnumValueCastType value);
EnumValueCastType OTGetEnumValueCastTypeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumValueCastTypeString(EnumValueCastType value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumValueCastType getEnumValueCastTypeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Continuation point types
typedef enum tagEnumContinuationPointType
{
	//! Denotes a Browse continuation point
	EnumContinuationPointType_Browse,
	//! Denotes a HistoryReadRaw continuation point
	EnumContinuationPointType_HistoryReadRaw,
	//! Denotes a Query continuation point
	EnumContinuationPointType_Query,
	//! Denotes a HistoryReadProcessed continuation point
	EnumContinuationPointType_HistoryReadProcessed,
	//! Denotes a HistoryReadEvent continuation point
	EnumContinuationPointType_HistoryReadEvent
} EnumContinuationPointType;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumContinuationPointTypeString(EnumContinuationPointType value);
EnumContinuationPointType OTGetEnumContinuationPointTypeFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumContinuationPointTypeString(EnumContinuationPointType value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumContinuationPointType getEnumContinuationPointTypeFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Defines allowed bits in the verb field of the ModelChangeStructureDataType.
//! @see ModelChangeStructureDataType::getVerb()
typedef enum tagEnumModelChangeStructureVerbMask
{
	//! Indicates that the affected node has been added
	EnumModelChangeStructureVerbMask_NodeAdded        = 1,

	//! Indicates that the affected node has been deleted
	EnumModelChangeStructureVerbMask_NodeDeleted      = 2,

	//! Indicates that a reference has been added. The affected node
	//! may be either the source or target of a reference. Note that an added
	//! bidirectional reference is reflected by two ModelChangeStructure entries.
	EnumModelChangeStructureVerbMask_ReferenceAdded   = 4,

	//! Indicates that a reference has been removed. The affected node
	//! may be either the source or target of a reference. Note that an added
	//! bidirectional reference is reflected by two ModelChangeStructure entries.
	EnumModelChangeStructureVerbMask_ReferenceDeleted = 8,

	//! Indicates that the DataType attribute of a Variable or VariableType has changed.
	EnumModelChangeStructureVerbMask_DataTypeChanged  = 16
} EnumModelChangeStructureVerbMask;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumModelChangeStructureVerbMaskString(EnumModelChangeStructureVerbMask value);
EnumModelChangeStructureVerbMask OTGetEnumModelChangeStructureVerbMaskFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumModelChangeStructureVerbMaskString(EnumModelChangeStructureVerbMask value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumModelChangeStructureVerbMask getEnumModelChangeStructureVerbMaskFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! The ExceptionDeviation specifies the minimum amount that the data for the HistoricalDataNode
//! must change in order for the change to be reported to the history database. The
//! The ExceptionDeviationFormat specifies how the ExceptionDeviation is determined.
//! @see Server::HistoricalDataConfiguration
typedef enum tagEnumExceptionDeviationFormat
{
	//! ExceptionDeviation is an absolute Value.
	EnumExceptionDeviationFormat_AbsoluteValue		= 0,

	//! ExceptionDeviation is a percent of Value.
	EnumExceptionDeviationFormat_PercentOfValue		= 1,

	//! ExceptionDeviation is a percent of InstrumentRange.
	EnumExceptionDeviationFormat_PercentOfRange		= 2,

	//! ExceptionDeviation is a percent of EURange.
	EnumExceptionDeviationFormat_PercentOfEuRange	= 3,

	//! ExceptionDeviation type is unknown or not specified.
	EnumExceptionDeviationFormat_Unknown			= 4
} EnumExceptionDeviationFormat;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumExceptionDeviationFormatString(EnumExceptionDeviationFormat value);
EnumExceptionDeviationFormat OTGetEnumExceptionDeviationFormatFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumExceptionDeviationFormatString(EnumExceptionDeviationFormat value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumExceptionDeviationFormat getEnumExceptionDeviationFormatFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! The pre-defined index for the "Anonymous" user group.
//! @see Server::Endpoint::onAuthenticateUser()
static const OTUInt32 ANONYMOUS_USER_INDEX = 0xFFFFFFFF;
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Defines bit masks that are used to request diagnostic information for service invocations
typedef OTUInt32 EnumDiagnosticsToReturn;

//! Return a namespace-qualified, symbolic identifier for an error or condition. The maximum
//! length of this identifier is 32 characters.
//! The diagnostic info shall be related to a transaction (also known as service).
static const EnumDiagnosticsToReturn EnumDiagnosticsToReturn_ServiceLevel_SymbolicId			= 0x001;
//! Return up to 256 bytes of localized text that describes the symbolic id.
//! The diagnostic info shall be related to a transaction (also known as service).
static const EnumDiagnosticsToReturn EnumDiagnosticsToReturn_ServiceLevel_LocalizedText			= 0x002;
//! Return a byte string that contains additional diagnostic information, such as a memory image.
//! The format of this byte string is vendor-specific, and may depend on the type of error or
//! condition encountered.
//! The diagnostic info shall be related to a transaction (also known as service).
static const EnumDiagnosticsToReturn EnumDiagnosticsToReturn_ServiceLevel_AdditionalInfo		= 0x004;
//! Return the inner StatusCode associated with the transaction (also known as service).
static const EnumDiagnosticsToReturn EnumDiagnosticsToReturn_ServiceLevel_InnerStatusCode		= 0x008;
//! Return the inner diagnostic info associated with the transaction (also known as service).
//! The contents of the inner diagnostic info structure are determined by other bits in the mask.
//! Note that setting this bit could cause multiple levels of nested diagnostic info structures
//! to be returned.
static const EnumDiagnosticsToReturn EnumDiagnosticsToReturn_ServiceLevel_InnerDiagnostics		= 0x010;
//! Return a namespace-qualified, symbolic identifier for an error or condition. The maximum
//! length of this identifier is 32 characters.
//! The diagnostic info shall be related to a request (also known as operation).
static const EnumDiagnosticsToReturn EnumDiagnosticsToReturn_OperationLevel_SymbolicId			= 0x020;
//! Return up to 256 bytes of localized text that describes the symbolic id.
//! The diagnostic info shall be related to a request (also known as operation).
static const EnumDiagnosticsToReturn EnumDiagnosticsToReturn_OperationLevel_LocalizedText		= 0x040;
//! Return a byte string that contains additional diagnostic information, such as a memory image.
//! The format of this byte string is vendor-specific, and may depend on the type of error or
//! condition encountered.
//! The diagnostic info shall be related to a request (also known as operation).
static const EnumDiagnosticsToReturn EnumDiagnosticsToReturn_OperationLevel_AdditionalInfo		= 0x080;
//! Return the inner StatusCode associated with the request (also known as operation).
static const EnumDiagnosticsToReturn EnumDiagnosticsToReturn_OperationLevel_InnerStatusCode		= 0x100;
//! Return the inner diagnostic info associated with the request (also known as operation).
//! The contents of the inner diagnostic info structure are determined by other bits in the mask.
//! Note that setting this bit could cause multiple levels of nested diagnostic info structures
//! to be returned.
static const EnumDiagnosticsToReturn EnumDiagnosticsToReturn_OperationLevel_InnerDiagnostics	= 0x200;
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Specifies the type of request while creating a secure channel
typedef enum tagEnumOpenRequest
{
	//! A new Secure UA Session was created. See: OpcUa_SecurityTokenRequestType_Issue.
	EnumOpenRequest_Open,
	//! A previously existing Secure UA Session was re-opened. Note: this is currently not implemented. See: OpcUa_SecurityTokenRequestType_Renew.
	EnumOpenRequest_Renew
} EnumOpenRequest;
#ifdef OT_COMPILATION
const TCHAR* OTGetEnumOpenRequestString(EnumOpenRequest value);
EnumOpenRequest OTGetEnumOpenRequestFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumOpenRequestString(EnumOpenRequest value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumOpenRequest getEnumOpenRequestFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration for the possible states of a UA server
typedef enum tagEnumServerState // Declaration of enum EnumMonitoringMode
{
	//! The server is running normally. This is the usual state for a server.
	EnumServerState_Running = 0x00,

	//! A vendor-specific fatal error has occurred within the server. The server is no longer functioning.
	//! The recovery procedure from this situation is vendor-specific. Most Service requests should be
	//! expected to fail.
	EnumServerState_Failed = 0x01,

	//! The server is running but has no configuration information loaded and therefore does not transfer data.
	EnumServerState_NoConfiguration = 0x02,

	//! The server has been temporarily suspended by some vendor-specific method and is not receiving
	//! or sending data.
	EnumServerState_Suspended = 0x03,

	//! The server has shut down or is in the process of shutting down. Depending on the implementation,
	//! this might or might not be visible to clients.
	EnumServerState_Shutdown = 0x04,

	//! The server is in Test Mode. The outputs are disconnected from the real hardware, but the server
	//! will otherwise behave normally. Inputs may be real or may be simulated depending on the vendor
	//! implementation. StatusCode will generally be returned normally.
	EnumServerState_Test = 0x05,

	//! The server is running properly, but is having difficulty accessing data from its data sources. This
	//! may be due to communication problems or some other problem preventing the underlying device,
	//! control system, etc. from returning valid data. It may be a complete failure, meaning that no data is
	//! available, or a partial failure, meaning that some data is still available. It is expected that items
	//! affected by the fault will individually return with a BAD FAILURE status code indication for the
	//! items.
	EnumServerState_CommunicationFault = 0x06,

	//! This state is used only to indicate that the OPC UA server does not know the state of underlying servers.
	EnumServerState_Unknown = 0x07
}
EnumServerState; // end EnumServerState;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumServerStateString(EnumServerState value);
EnumServerState OTGetEnumServerStateFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumServerStateString(EnumServerState value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumServerState getEnumServerStateFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration for the available operands in a ContentFilter
typedef enum tagEnumFilterOperand // Declaration of enum EnumFilterOperand
{
	//! Denotes an invalid filter operand type
	EnumFilterOperand_Invalid = 0,

	//! Denotes a Literal operand
	EnumFilterOperand_Literal,

	//! Denotes an Element operand
	EnumFilterOperand_Element,

	//! Denotes an Attribute operand
	EnumFilterOperand_Attribute,

	//! Denotes a SimpleAttribute operand
	EnumFilterOperand_SimpleAttribute
}
EnumFilterOperand; // end EnumFilterOperand;

#ifdef OT_COMPILATION
const TCHAR* OTGetEnumFilterOperandString(EnumFilterOperand value);
EnumFilterOperand OTGetEnumFilterOperandFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumFilterOperandString(EnumFilterOperand value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumFilterOperand getEnumFilterOperandFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Specifies options defining whether to create an API object after creating new nodes
//! or only on demand when accessing a certain node.
typedef enum tagEnumApiObjectCreation
{
	//! Create an API object for all created nodes.
	EnumApiObjectCreation_All,
	//! Create an API object for all created nodes except for nodes in the default namespace "http://opcfoundation.org/UA/" (namespace index 0).
	EnumApiObjectCreation_AllExceptDefaultNodes,
	//! API objects will only be created on demand.
	EnumApiObjectCreation_None
} EnumApiObjectCreation;
#ifdef OT_COMPILATION
const TCHAR* OTGetEnumApiObjectCreationString(EnumApiObjectCreation value);
EnumApiObjectCreation OTGetEnumApiObjectCreationFromString(const TCHAR* str);
#else
/*! Returns the enumeration value as string */
TBC_EXPORT const TCHAR* getEnumApiObjectCreationString(EnumApiObjectCreation value);
/*! Returns an enumeration value corresponding to the provided string */
TBC_EXPORT EnumApiObjectCreation getEnumApiObjectCreationFromString(const TCHAR* str);
#endif
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//! Enumeration for different object classes.
typedef enum tagEnumApiClassType
{
	//! Denotes classes that don't have a representation class in the API.
	EnumApiClassType_None,
	//! Denotes the Client::MonitoredItem object class.
	EnumApiClassType_ClientMonitoredItem,
	//! Denotes the Client::RedundantMonitoredItem object class.
	EnumApiClassType_ClientRedundantMonitoredItem,
	//! Denotes the Client::Session object class.
	EnumApiClassType_ClientSession,
	//! Denotes the Client::RedundantSession object class.
	EnumApiClassType_ClientRedundantSession,
	//! Denotes the Client::Subscription object class.
	EnumApiClassType_ClientSubscription,
	//! Denotes the Client::RedundantSubscription object class.
	EnumApiClassType_ClientRedundantSubscription,
	//! Denotes the Trace object class.
	EnumApiClassType_Trace,
	//! Denotes the Application object class.
	EnumApiClassType_Application,
	//! Denotes the Server::Diagnostics object class.
	EnumApiClassType_ServerDiagnostics,
	//! Denotes the Server::AddressSpaceRoot object class.
	EnumApiClassType_ServerAddressSpaceRoot,
	//! Denotes the Server::Variable object class.
	EnumApiClassType_ServerVariable,
	//! Denotes the Server::Object object class.
	EnumApiClassType_ServerObject,
	//! Denotes the Server::Method object class.
	EnumApiClassType_ServerMethod,
	//! Denotes the Server::ObjectType object class.
	EnumApiClassType_ServerObjectType,
	//! Denotes the Server::ReferenceType object class.
	EnumApiClassType_ServerReferenceType,
	//! Denotes the Server::DataType object class.
	EnumApiClassType_ServerDataType,
	//! Denotes the Server::View object class.
	EnumApiClassType_ServerView,
	//! Denotes the Server::VariableType object class.
	EnumApiClassType_ServerVariableType,
	//! Denotes the Server::Endpoint object class.
	EnumApiClassType_ServerEndpoint,
	//! Denotes the Server::MonitoredItem object class.
	EnumApiClassType_ServerMonitoredItem,
	//! Denotes the Server::ServerSubscription object class.
	EnumApiClassType_ServerSubscription,
	//! Denotes the Server::ReadRequest object class.
	EnumApiClassType_ServerReadRequest,
	//! Denotes the Server::WriteRequest object class.
	EnumApiClassType_ServerWriteRequest,
	//! Denotes the Server::HistoryReadRequest object class.
	EnumApiClassType_ServerHistoryReadRequest,
	//! Denotes the Server::HistoryReadRawRequest object class.
	EnumApiClassType_ServerHistoryReadRawRequest,
	//! Denotes the Server::HistoryReadProcessedRequest object class.
	EnumApiClassType_ServerHistoryReadProcessedRequest,
	//! Denotes the Server::BrowseRequest object class.
	EnumApiClassType_ServerBrowseRequest,
	//! Denotes the Server::BrowseNextRequest object class.
	EnumApiClassType_ServerBrowseNextRequest,
	//! Denotes the Server::TranslateBrowsePathsToNodeIdsRequest object class.
	EnumApiClassType_ServerTranslateBrowsePathsToNodeIdsRequest,
	//! Denotes the Server::ReadTransaction object class.
	EnumApiClassType_ServerReadTransaction,
	//! Denotes the Server::WriteTransaction object class.
	EnumApiClassType_ServerWriteTransaction,
	//! Denotes the Server::HistoryReadTransaction object class.
	EnumApiClassType_ServerHistoryReadTransaction,
	//! Denotes the Server::HistoryReadRawTransaction object class.
	EnumApiClassType_ServerHistoryReadRawTransaction,
	//! Denotes the Server::HistoryReadProcessedTransaction object class.
	EnumApiClassType_ServerHistoryReadProcessedTransaction,
	//! Denotes the Server::BrowseTransaction object class.
	EnumApiClassType_ServerBrowseTransaction,
	//! Denotes the Server::BrowseNextTransaction object class.
	EnumApiClassType_ServerBrowseNextTransaction,
	//! Denotes the Server::TranslateBrowsePathsToNodeIdsTransaction object class.
	EnumApiClassType_ServerTranslateBrowsePathsToNodeIdsTransaction,
	//! Denotes the Server::Session object class.
	EnumApiClassType_ServerSession,
	//! Denotes the Server::ReferenceIterator object class.
	EnumApiClassType_ServerReferenceIterator,
	//! Denotes the Server::MethodCallRequest object class.
	EnumApiClassType_ServerMethodCallRequest,
	//! Denotes the Server::MethodCallTransaction object class.
	EnumApiClassType_ServerMethodCallTransaction,
	//! Denotes the Server::BaseEvent object class.
	EnumApiClassType_ServerBaseEvent,
	//! Denotes the Server::Condition object class.
	EnumApiClassType_ServerCondition,
	//! Denotes the Server::StateMachine object class.
	EnumApiClassType_ServerStateMachine,
	//! Denotes the Server::StateVariable object class.
	EnumApiClassType_ServerStateVariable,
	//! Denotes the Server::TransitionVariable object class.
	EnumApiClassType_ServerTransitionVariable,
	//! Denotes the Server::FiniteStateMachine object class.
	EnumApiClassType_ServerFiniteStateMachine,
	//! Denotes the Server::FiniteStateVariable object class.
	EnumApiClassType_ServerFiniteStateVariable,
	//! Denotes the Server::FiniteTransitionVariable object class.
	EnumApiClassType_ServerFiniteTransitionVariable,
	//! Denotes the Server::ConditionVariable object class.
	EnumApiClassType_ServerConditionVariable,
	//! Denotes the Server::TwoStateVariable object class.
	EnumApiClassType_ServerTwoStateVariable,
	//! Denotes the Server::AcknowledgeableCondition object class.
	EnumApiClassType_ServerAcknowledgeableCondition,
	//! Denotes the Server::AlarmCondition object class.
	EnumApiClassType_ServerAlarmCondition,
	//! Denotes the Server::ShelvedStateMachine object class.
	EnumApiClassType_ServerShelvedStateMachine,
	//! Denotes the Server::ConditionEnable object class.
	EnumApiClassType_ServerConditionEnable,
	//! Denotes the Server::ConditionDisable object class.
	EnumApiClassType_ServerConditionDisable,
	//! Denotes the Server::State object class.
	EnumApiClassType_ServerState,
	//! Denotes the Server::Transition object class.
	EnumApiClassType_ServerTransition,
	//! Denotes the Server::LimitAlarm object class.
	EnumApiClassType_ServerLimitAlarm,
	//! Denotes the Server::ShelvedStateMachineTimedShelve object class.
	EnumApiClassType_ServerShelvedStateMachineTimedShelve,
	//! Denotes the Server::ShelvedStateMachineOneShotShelve object class.
	EnumApiClassType_ServerShelvedStateMachineOneShotShelve,
	//! Denotes the Server::ShelvedStateMachineUnshelve object class.
	EnumApiClassType_ServerShelvedStateMachineUnshelve,
	//! Denotes the Server::ConditionAddComment object class.
	EnumApiClassType_ServerConditionAddComment,
	//! Denotes the Server::AcknowledgeableConditionAcknowledge object class.
	EnumApiClassType_ServerAcknowledgeableConditionAcknowledge,
	//! Denotes the Server::ServerAcknowledgeableConditionConfirm object class.
	EnumApiClassType_ServerAcknowledgeableConditionConfirm,
	//! Denotes the Server::ConditionRefresh object class.
	EnumApiClassType_ServerConditionRefresh,
	//! Denotes the Server::ExclusiveLimitAlarm object class.
	EnumApiClassType_ServerExclusiveLimitAlarm,
	//! Denotes the Server::ExclusiveLimitStateMachine object class.
	EnumApiClassType_ServerExclusiveLimitStateMachine,
	//! Denotes the Server::ExclusiveLevelAlarm object class.
	EnumApiClassType_ServerExclusiveLevelAlarm,
	//! Denotes the Server::ExclusiveDeviationAlarm object class.
	EnumApiClassType_ServerExclusiveDeviationAlarm,
	//! Denotes the Server::ExclusiveRateOfChangeAlarm object class.
	EnumApiClassType_ServerExclusiveRateOfChangeAlarm,
	//! Denotes the Server::DiscreteAlarm object class.
	EnumApiClassType_ServerDiscreteAlarm,
	//! Denotes the Server::OffNormalAlarm object class.
	EnumApiClassType_ServerOffNormalAlarm,
	//! Denotes the Server::TripAlarm object class.
	EnumApiClassType_ServerTripAlarm,
	//! Denotes the Server::NonExclusiveLimitAlarm object class.
	EnumApiClassType_ServerNonExclusiveLimitAlarm,
	//! Denotes the Server::NonExclusiveLevelAlarm object class.
	EnumApiClassType_ServerNonExclusiveLevelAlarm,
	//! Denotes the Server::NonExclusiveDeviationAlarm object class.
	EnumApiClassType_ServerNonExclusiveDeviationAlarm,
	//! Denotes the Server::NonExclusiveRateOfChangeAlarm object class.
	EnumApiClassType_ServerNonExclusiveRateOfChangeAlarm,
	//! Denotes the Server::RefreshStartEvent object class.
	EnumApiClassType_ServerRefreshStartEvent,
	//! Denotes the Server::RefreshEndEvent object class.
	EnumApiClassType_ServerRefreshEndEvent,
	//! Denotes the Server::AuditOpenSecureChannelEvent object class.
	EnumApiClassType_ServerAuditOpenSecureChannelEvent,
	//! Denotes the Server::AuditCreateSessionEvent object class.
	EnumApiClassType_ServerAuditCreateSessionEvent,
	//! Denotes the Server::AuditUrlMismatchEvent object class.
	EnumApiClassType_ServerAuditUrlMismatchEvent,
	//! Denotes the Server::AuditActivateSessionEvent object class.
	EnumApiClassType_ServerAuditActivateSessionEvent,
	//! Denotes the Server::AuditCancelEvent object class.
	EnumApiClassType_ServerAuditCancelEvent,
	//! Denotes the Server::AuditCertificateDataMismatchEvent object class.
	EnumApiClassType_ServerAuditCertificateDataMismatchEvent,
	//! Denotes the Server::AuditCertificateExpiredEvent object class.
	EnumApiClassType_ServerAuditCertificateExpiredEvent,
	//! Denotes the Server::AuditCertificateInvalidEvent object class.
	EnumApiClassType_ServerAuditCertificateInvalidEvent,
	//! Denotes the Server::AuditCertificateUntrustedEvent object class.
	EnumApiClassType_ServerAuditCertificateUntrustedEvent,
	//! Denotes the Server::AuditCertificateMismatchEvent object class.
	EnumApiClassType_ServerAuditCertificateMismatchEvent,
	//! Denotes the Server::AuditWriteUpdateEvent object class.
	EnumApiClassType_ServerAuditWriteUpdateEvent,
	//! Denotes the Server::AuditConditionEnableEvent object class.
	EnumApiClassType_ServerAuditConditionEnableEvent,
	//! Denotes the Server::AuditConditionCommentEvent object class.
	EnumApiClassType_ServerAuditConditionCommentEvent,
	//! Denotes the Server::AuditConditionRespondEvent object class.
	EnumApiClassType_ServerAuditConditionRespondEvent,
	//! Denotes the Server::AuditConditionAcknowledgeEvent object class.
	EnumApiClassType_ServerAuditConditionAcknowledgeEvent,
	//! Denotes the Server::AuditConditionConfirmEvent object class.
	EnumApiClassType_ServerAuditConditionConfirmEvent,
	//! Denotes the Server::AuditConditionShelvingEvent object class.
	EnumApiClassType_ServerAuditConditionShelvingEvent,
	//! Denotes the Server::BrowseContinuationPoint object class.
	EnumApiClassType_ServerBrowseContinuationPoint,
	//! Denotes the Server::HistoryReadRawContinuationPoint object class.
	EnumApiClassType_ServerHistoryReadRawContinuationPoint,
	//! Denotes the Server::HistoryReadProcessedContinuationPoint object class.
	EnumApiClassType_ServerHistoryReadProcessedContinuationPoint,
	//! Denotes the Server::QueryTransaction object class.
	EnumApiClassType_ServerQueryTransaction,
	//! Denotes the Server::QueryContinuationPoint object class.
	EnumApiClassType_ServerQueryContinuationPoint,
	//! Denotes the Server::BaseEventNotification object class.
	EnumApiClassType_ServerBaseEventNotification,
	//! Denotes the Server::SemanticChangeEvent object class.
	EnumApiClassType_ServerSemanticChangeEvent,
	//! Denotes the Server::BaseModelChangeEvent object class.
	EnumApiClassType_ServerBaseModelChangeEvent,
	//! Denotes the Server::GeneralModelChangeEvent object class.
	EnumApiClassType_ServerGeneralModelChangeEvent,
	//! Denotes the Server::HistoricalDataConfiguration object class.
	EnumApiClassType_ServerHistoricalDataConfiguration,
	//! Denotes the Server::AggregateConfiguration object class.
	EnumApiClassType_ServerAggregateConfiguration,
	//! Denotes the Server::RefreshRequiredEvent object class.
	EnumApiClassType_ServerRefreshRequiredEvent,
	//! Denotes the Server::AggregateFunction object class.
	EnumApiClassType_ServerAggregateFunction,
	//! Denotes the StringTable object class.
	EnumApiClassType_StringTable,
	//! Denotes the Server::HistoryReadEventTransaction object class.
	EnumApiClassType_ServerHistoryReadEventTransaction,
	//! Denotes the Server::HistoryReadEventRequest object class.
	EnumApiClassType_ServerHistoryReadEventRequest,
	//! Denotes the Server::HistoryReadEventContinuationPoint object class.
	EnumApiClassType_ServerHistoryReadEventContinuationPoint,
	//! Denotes the Server::CreateMonitoredItemRequest object class.
	EnumApiClassType_ServerCreateMonitoredItemRequest,
	//! Denotes the Server::ModifyMonitoredItemRequest object class.
	EnumApiClassType_ServerModifyMonitoredItemRequest,
	//! Denotes the Server::DeleteMonitoredItemRequest object class.
	EnumApiClassType_ServerDeleteMonitoredItemRequest,
	//! Denotes the FieldDescription object class
	EnumApiClassType_FieldDescription,
	//! Denotes the EnumeratedValueDescription object class
	EnumApiClassType_EnumeratedValueDescription,
	//! Denotes the ServerDictionaryVariable object class
	EnumApiClassType_ServerDictionaryVariable,
	//! Denotes the StructuredDataTypeDescription object class
	EnumApiClassType_StructuredDataTypeDescription,
	//! Denotes the EnumerationDataTypeDescription object class
	EnumApiClassType_EnumerationDataTypeDescription,
	//! Denotes the Server::GetMonitoredItems object class
	EnumApiClassType_ServerGetMonitoredItems,
	//! Denotes the Server::DeleteSubscriptionRequest object class
	EnumApiClassType_ServerDeleteSubscriptionRequest,
	//! Denotes the Server::DeleteSessionRequest object class.
	EnumApiClassType_ServerDeleteSessionRequest,
	//! Denotes the Server::DataItem object class.
	EnumApiClassType_ServerDataItem,
	//! Denotes the abstract Server::DiscreteItem object class.
	EnumApiClassType_ServerDiscreteItem,
	//! Denotes the Server::TwoStateItem object class.
	EnumApiClassType_ServerTwoStateItem,
	//! Denotes the Server::MultiStateItem object class.
	EnumApiClassType_ServerMultiStateItem,
	//! Denotes the Server::MultiStateValueItem object class.
	EnumApiClassType_ServerMultiStateValueItem,
	//! Denotes the Server::AnalogItem object class.
	EnumApiClassType_ServerAnalogItem
} EnumApiClassType;

////////////////////////////////////////////////////////////////////////////////
//! This class provides convenience methods for dealing with status codes
class StatusCode
{
public:
	//! Mask to indicate that the EnumStatusCode means an error status code
	static const OTUInt32 ERROR_MASK = 0x80000000;
	//! Mask to indicate that the EnumStatusCode means an uncertain value
	static const OTUInt32 UNCERTAIN_MASK = 0x40000000;
	//! Mask to indicate that the EnumStatusCode means an good status code
	static const OTUInt32 SUCCESS_MASK = 0x00000000;
	//! Value for EnumStatusCode_Good
	static const OTUInt32 GOOD = 0x00000000;
	//! Mask to get the pure status code without any status bits
	static const OTUInt32 STATUS_MASK = 0xFFFF0000;
	//! Mask to get the pure status bits without any status code
	static const OTUInt32 BIT_MASK = 0x0000FFFF;

	/*! This bit may be only set when reading historical data and indicates a raw data value. */
	static const OTUInt32 HISTORIAN_BITS_RAW = 0x0;

	/*! This bit may be only set when reading historical data and indicates a calculated data value. */
	static const OTUInt32 HISTORIAN_BITS_CALCULATED = 0x1;

	/*! This bit may be only set when reading historical data and indicates an interpolated data value. */
	static const OTUInt32 HISTORIAN_BITS_INTERPOLATED = 0x2;

	/*! This bit may be only set when reading historical data and indicates a data value which
	* was calculated with an incomplete interval. */
	static const OTUInt32 HISTORIAN_BITS_PARTIAL= 0x4;

	/*! This bit may be only set when reading historical data and indicates a raw data value
	* which hides other data at the same timestamp. */
	static const OTUInt32 HISTORIAN_BITS_EXTRA_DATA= 0x8;

	/*! This bit may be only set when reading historical data and indicates that multiple values match the
	* aggregate criteria (i.e. multiple minimum values at different timestamps within the same interval). */
	static const OTUInt32 HISTORIAN_BITS_MULTI_VALUE= 0x10;

	/*! Indicates that the semantics of the associated data value have changed.
	 * Clients should not process the data value until they re-read the metadata associated with the Variable. */
	static const OTUInt32 SEMANTICS_CHANGED = 0x4000;

	/*! Indicates that the status code is associated with a data value and additional info bits are available. */
	static const OTUInt32 INFO_BITS_DATAVALUE = 0x400;

	/*! Indicates that not every detected data change for a node has been reported
	* by a MonitoredItem due to an overflow in the data change notification queue.
	* @note This info bit is only relevant if INFO_BITS_DATAVALUE is set. */
	static const OTUInt32 OVERFLOW_INFO_BIT_DATAVALUE = 0x80;

	/*! Returns whether the given status code has the severity 'Good'.
	*
	* @param res The status code to test. */
	static bool isGood(OTUInt32 res)
	{
		return ((res & (ERROR_MASK | UNCERTAIN_MASK)) == SUCCESS_MASK);
	}
	/*! Returns whether the given status code has the severity 'Good'.
	*
	* @param res The status code to test. */
	static bool isGood(EnumStatusCode res)
	{
		return (((OTUInt32)res & (ERROR_MASK | UNCERTAIN_MASK)) == SUCCESS_MASK);
	}

	/*! Returns whether the given status code has the severity 'Uncertain'.
	*
	* @param res The status code to test. */
	static bool isUncertain(OTUInt32 res)
	{
		return ((res & UNCERTAIN_MASK) == UNCERTAIN_MASK);
	}
	/*! Returns whether the given status code has the severity 'Uncertain'.
	*
	* @param res The status code to test. */
	static bool isUncertain(EnumStatusCode res)
	{
		return ((((OTUInt32)res) & UNCERTAIN_MASK) == UNCERTAIN_MASK);
	}

	/*! Returns whether the given status code has the severity 'Bad'.
	*
	* @param res The status code to test. */
	static bool isBad(OTUInt32 res)
	{
		return ((res & ERROR_MASK) == ERROR_MASK);
	}
	/*! Returns whether the given status code has the severity 'Bad'.
	*
	* @param res The status code to test. */
	static bool isBad(EnumStatusCode res)
	{
		return ((((OTUInt32)res) & ERROR_MASK) == ERROR_MASK);
	}

	/*! Returns whether the given status code has the severity 'Good' or 'Uncertain'.
	*
	* @param res The status code to test. */
	static bool isSUCCEEDED(OTUInt32 res)
	{
		return ((res & ERROR_MASK) == SUCCESS_MASK);
	}
	/*! Returns whether the given status code has the severity 'Good' or 'Uncertain'.
	*
	* @param res The status code to test. */
	static bool isSUCCEEDED(EnumStatusCode res)
	{
		return ((((OTUInt32)res) & ERROR_MASK) == SUCCESS_MASK);
	}

	/*! Returns whether the given status code has the severity 'Bad'.
	*
	* @param res The status code to test.
	* @note		This method does the same as isBad() and is provided
	*			for backward compatibility. */
	static bool isFAILED(OTUInt32 res)
	{
		return isBad(res);
	}
	/*! Returns whether the given status code has the severity 'Bad'.
	*
	* @param res The status code to test.
	* @note		This method does the same as isBad() and is provided
	*			for backward compatibility. */
	static bool isFAILED(EnumStatusCode res)
	{
		return isBad(res);
	}

	/*! Returns whether the SemanticsChanged bit is set
	*
	* @param statusCode The status code to test. */
	static bool isSemanticsChangedBitSet(EnumStatusCode statusCode)
	{
		return (statusCode & SEMANTICS_CHANGED) == SEMANTICS_CHANGED;
	}
	/*! Sets the SemanticsChanged bit on the status code.
	*
	* @param statusCode The status code on which to set the bit. */
	static void setSemanticsChangedBit(EnumStatusCode& statusCode)
	{
		statusCode = (EnumStatusCode)((OTUInt32)statusCode | SEMANTICS_CHANGED);
	}

	/*! Returns whether the 'Raw' bit in the 'Historian' bit field is set
	*
	* @param statusCode The status code to test. */
	static bool isRawHistorianBitSet(EnumStatusCode statusCode)
	{
		return ((OTUInt32)statusCode & (HISTORIAN_BITS_CALCULATED | HISTORIAN_BITS_INTERPOLATED)) == HISTORIAN_BITS_RAW;
	}
	/*! Sets the 'Raw' bit in the 'Historian' bit field.
	*
	* @param statusCode The status code on which to set the bit. */
	static void setRawHistorianBit(EnumStatusCode& statusCode)
	{
		statusCode = (EnumStatusCode)((OTUInt32)statusCode & ~(HISTORIAN_BITS_CALCULATED | HISTORIAN_BITS_INTERPOLATED));
	}

	/*! Returns whether the 'Calculated' bit in the 'Historian' bit field is set
	*
	* @param statusCode The status code to test. */
	static bool isCalculatedHistorianBitSet(EnumStatusCode statusCode)
	{
		return ((OTUInt32)statusCode & HISTORIAN_BITS_CALCULATED) == HISTORIAN_BITS_CALCULATED;
	}
	/*! Sets the 'Calculated' bit in the 'Historian' bit field.
	*
	* @param statusCode The status code on which to set the bit. */
	static void setCalculatedHistorianBit(EnumStatusCode& statusCode)
	{
		statusCode = (EnumStatusCode)((OTUInt32)statusCode | HISTORIAN_BITS_CALCULATED);
	}

	/*! Returns whether the 'Interpolated' bit in the 'Historian' bit field is set
	*
	* @param statusCode The status code to test. */
	static bool isInterpolatedHistorianBitSet(EnumStatusCode statusCode)
	{
		return ((OTUInt32)statusCode & HISTORIAN_BITS_INTERPOLATED) == HISTORIAN_BITS_INTERPOLATED;
	}
	/*! Sets the 'Interpolated' bit in the 'Historian' bit field.
	*
	* @param statusCode The status code on which to set the bit. */
	static void setInterpolatedHistorianBit(EnumStatusCode& statusCode)
	{
		statusCode = (EnumStatusCode)((OTUInt32)statusCode | HISTORIAN_BITS_INTERPOLATED);
	}

	/*! Returns whether the 'Partial' bit in the 'Historian' bit field is set
	*
	* @param statusCode The status code to test. */
	static bool isPartialHistorianBitSet(EnumStatusCode statusCode)
	{
		return ((OTUInt32)statusCode & HISTORIAN_BITS_PARTIAL) == HISTORIAN_BITS_PARTIAL;
	}
	/*! Sets the 'Partial' bit in the 'Historian' bit field.
	*
	* @param statusCode The status code on which to set the bit. */
	static void setPartialHistorianBit(EnumStatusCode& statusCode)
	{
		statusCode = (EnumStatusCode)((OTUInt32)statusCode | HISTORIAN_BITS_PARTIAL);
	}

	/*! Returns whether the 'Extra Data' bit in the 'Historian' bit field is set
	*
	* @param statusCode The status code to test. */
	static bool isExtraDataHistorianBitSet(EnumStatusCode statusCode)
	{
		return ((OTUInt32)statusCode & HISTORIAN_BITS_EXTRA_DATA) == HISTORIAN_BITS_EXTRA_DATA;
	}
	/*! Sets the 'Extra Data' bit in the 'Historian' bit field.
	*
	* @param statusCode The status code on which to set the bit. */
	static void setExtraDataHistorianBit(EnumStatusCode& statusCode)
	{
		statusCode = (EnumStatusCode)((OTUInt32)statusCode | HISTORIAN_BITS_EXTRA_DATA);
	}

	/*! Returns whether the 'Multi Value' bit in the 'Historian' bit field is set
	*
	* @param statusCode The status code to test. */
	static bool isMultiValueHistorianBitSet(EnumStatusCode statusCode)
	{
		return ((OTUInt32)statusCode & HISTORIAN_BITS_MULTI_VALUE) == HISTORIAN_BITS_MULTI_VALUE;
	}
	/*! Sets the 'Multi Value' bit in the 'Historian' bit field.
	*
	* @param statusCode The status code on which to set the bit. */
	static void setMultiValueHistorianBit(EnumStatusCode& statusCode)
	{
		statusCode = (EnumStatusCode)((OTUInt32)statusCode | HISTORIAN_BITS_MULTI_VALUE);
	}
};	// end class StatusCode


//! The EnumGroup enumeration refers to the different enumeration types in "Enums.h".
//! For internal use only
typedef enum tagEnumGroup
{
	//! Refers to the EnumMonitoringMode enumeration.
	EnumMonitoringModeGroup = 0,
	//! Refers to the EnumObjectState enumeration.
	EnumObjectStateGroup = 1,
	//! Refers to the EnumAccessLevel enumeration.
	EnumAccessLevelGroup = 2,
	//! Refers to the EnumApplicationType enumeration.
	EnumApplicationTypeGroup = 3,
	//! Refers to the EnumAttributeId enumeration.
	EnumAttributeIdGroup = 4,
	//! Refers to the EnumBrowseDirection enumeration.
	EnumBrowseDirectionGroup = 5,
	//! Refers to the EnumFeature enumeration.
	EnumFeatureGroup = 6,
	//! Refers to the EnumIdentifierType enumeration.
	EnumIdentifierTypeGroup = 7,
	//! Refers to the EnumMessageSecurityMode enumeration.
	EnumMessageSecurityModeGroup = 8,
	//! Refers to the EnumNodeClass enumeration.
	EnumNodeClassGroup = 9,
	//! Refers to the EnumSerializerType enumeration.
	EnumSerializerTypeGroup = 10,
	//! Refers to the EnumStatusCode enumeration.
	EnumStatusCodeGroup = 11,
	//! Refers to the EnumTimestampsToReturn enumeration.
	EnumTimestampsToReturnGroup = 12,
	//! Refers to the EnumTraceGroup enumeration.
	EnumTraceGroupGroup = 13,
	//! Refers to the EnumTraceLevel enumeration.
	EnumTraceLevelGroup = 14,
	//! Refers to the EnumUserTokenType enumeration.
	EnumUserTokenTypeGroup = 15,
	//! Refers to the EnumValueArrayType enumeration.
	EnumValueArrayTypeGroup = 16,
	//! Refers to the EnumNumericNodeId enumeration.
	EnumNumericNodeIdGroup = 17,
	//! Refers to the EnumDataTypeId enumeration.
	EnumDataTypeIdGroup = 18,
	//! Refers to the EnumObjectTypeId enumeration.
	EnumObjectTypeIdGroup = 19,
	//! Refers to the EnumReferenceTypeId enumeration.
	EnumReferenceTypeIdGroup = 20,
	//! Refers to the EnumVariableTypeId enumeration.
	EnumVariableTypeIdGroup = 21,
	//! Refers to the EnumResultMask enumeration.
	EnumResultMaskGroup = 22,
	//! Refers to the EnumWriteMask enumeration.
	EnumWriteMaskGroup = 23,
	//! Refers to the EnumDataChangeTrigger enumeration.
	EnumDataChangeTriggerGroup = 24,
	//! Refers to the EnumDeadbandType enumeration.
	EnumDeadbandTypeGroup = 25,
	//! Refers to the EnumEventNotifier enumeration.
	EnumEventNotifierGroup = 26,
	//! Refers to the EnumFilterOperator enumeration.
	EnumFilterOperatorGroup = 27,
	//! Refers to the EnumRequestState enumeration.
	EnumRequestStateGroup = 28,
	//! Refers to the EnumMonitoringState enumeration.
	EnumMonitoringStateGroup = 29,
	//! Refers to the EnumRedundancySupport enumeration.
	EnumRedundancySupportGroup = 30,
	//! Refers to the EnumInitialValueProvider enumeration.
	EnumInitialValueProviderGroup = 31,
	//! Refers to the EnumServiceGroup enumeration.
	EnumServiceGroupGroup = 32,
	//! Refers to the EnumServiceType enumeration.
	EnumServiceTypeGroup = 33,
	//! Refers to the EnumValueCastType enumeration.
	EnumValueCastTypeGroup = 34,
	//! Refers to the EnumContinuationPointType enumeration.
	EnumContinuationPointTypeGroup = 35,
	//! Refers to the EnumModelChangeStructureVerbMask enumeration.
	EnumModelChangeStructureVerbMaskGroup = 36,
	//! Refers to the EnumExceptionDeviationFormat enumeration.
	EnumExceptionDeviationFormatGroup = 37,
	//! Refers to the EnumOpenRequestType enumeration.
	EnumOpenRequestTypeGroup = 38,
	//! Refers to the EnumServerStateType enumeration.
	EnumServerStateTypeGroup = 39,
	//! Refers to the EnumFilterOperand enumeration.
	EnumFilterOperandGroup = 40,
	//! Refers to the EnumTimeoutGroup enumeration.
	EnumTimeoutGroupGroup = 41,
	//! Refers to the EnumCertificateCheck enumeration.
	EnumCertificateCheckGroup = 42,
	//! Refers to the EnumCrlCheckOption enumeration.
	EnumCrlCheckOptionGroup = 43,
	//! Refers to the EnumDataTypeDescriptionType enumeration
	EnumDataTypeDescriptionTypeGroup = 44,
	//! Refers to the EnumAPIObjectCreation enumeration.
	EnumApiObjectCreationGroup = 45,
	//! Refers to the EnumOpenFileMode enumeration.
	EnumOpenFileModeGroup = 46,
	//! Refers to the EnumTrustListMasks enumeration.
	EnumTrustListMasksGroup = 47,
	//! Refers to the EnumAxisScaleEnumeration enumeration.
	EnumAxisScaleEnumerationGroup = 48,
	//! Invalid enumeration type.
	EnumGroup_Max = 49
} EnumGroup;


#ifdef COMPILE_FOR_UNITTESTS
OTUInt32 getNumberOfEnumStrings();
OTUInt32 getNumberOfEnumValues();
OTUInt32 getEnumStrings(OTUInt32 enumNumber, const TCHAR *** enumStringArray);
OTUInt32 getEnumValues(OTUInt32 enumNumber, int **enumValueArray);
#endif

#endif	// ENUMS_H
