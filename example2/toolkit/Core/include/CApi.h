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

#ifndef _C_API_H_
#define _C_API_H_

#include "OTExports.h"
#include "OSCompat.h"
#include "OTTypes.h"
#include "Callbacks.h"

// Forward declarations
struct AccessPatternStruct;
struct AggregateConfigurationStruct;
struct AnonymousIdentityTokenStruct;
struct ApplicationDescriptionStruct;
struct ArgumentStruct;
struct AttributeOperandStruct;
struct BrowseDescriptionStruct;
struct BrowsePathResultStruct;
struct BrowsePathStruct;
struct BrowsePathTargetStruct;
struct BrowseResultStruct;
struct BuildInfoStruct;
struct ByteStringStruct;
struct CallMethodRequestStruct;
struct CallMethodResultStruct;
struct ContentFilterElementResultStruct;
struct ContentFilterElementStruct;
struct ContentFilterResultStruct;
struct ContentFilterStruct;
struct DataChangeFilterStruct;
struct DataValueStruct;
struct DateTimeStruct;
struct DiagnosticInfoStruct;
struct EUInformationStruct;
struct ElementOperandStruct;
struct EndpointDescriptionStruct;
struct EventFieldListStruct;
struct EventFilterStruct;
struct ExpandedNodeIdStruct;
struct FilterOperandStruct;
struct GuidStruct;
#if TB5_HISTORY
struct HistoryDataExtensionObjectStruct;
struct HistoryDataStruct;
struct HistoryEventFieldListStruct;
struct HistoryEventStruct;
struct HistoryReadDetailsStruct;
struct HistoryReadResultStruct;
struct HistoryReadValueIdStruct;
#endif
struct IssuedIdentityTokenStruct;
struct LiteralOperandStruct;
#include "LocalizedTextStruct.h" // C API requires definition of OTTextId
struct MatrixValueStruct;
struct ModelChangeStructureDataTypeStruct;
struct MonitoringChangeStruct;
struct NodeIdStruct;
struct NodeTypeDescriptionStruct;
struct NumericRangeStruct;
struct ParsingResultStruct;
struct PkiStoreConfigurationStruct;
struct QualifiedNameStruct;
#if TB5_QUERY
struct QueryDataDescriptionStruct;
struct QueryDataSetStruct;
#endif
struct RangeStruct;
struct ReadEventDetailsStruct;
struct ReadProcessedDetailsStruct;
struct ReadRawModifiedDetailsStruct;
struct ReadValueIdStruct;
struct ReferenceDescriptionStruct;
struct RelativePathElementStruct;
struct RelativePathStruct;
struct SemanticChangeStructureDataTypeStruct;
struct ServerDiagnosticsSummaryDataTypeStruct;
struct ServerStatusDataTypeStruct;
struct ServiceCounterDataTypeStruct;
struct SessionDiagnosticsDataTypeStruct;
struct SessionSecurityDiagnosticsDataTypeStruct;
struct SignatureDataStruct;
struct SignedSoftwareCertificateStruct;
struct SimpleAttributeOperandStruct;
struct SubscriptionDiagnosticsDataTypeStruct;
struct TimeZoneStruct;
struct UserAuthenticationTokenStruct;
struct UserIdentityTokenStruct;
struct UserNameIdentityTokenStruct;
struct UserTokenPolicyStruct;
struct ValueStruct;
struct ViewDescriptionStruct;
struct WriteValueStruct;
struct X509IdentityTokenStruct;
struct EnumValueTypeStruct;

#ifdef __cplusplus
extern "C"
{
#endif
	TBCORE_IF void OTAPI_CALL OTRegisterApiObject(TBHandle otbHandle, void* ApiObject);
	TBCORE_IF void OTAPI_CALL OTUnregisterApiObject(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTProtectApiObject(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReleaseApiRef(TBHandle otbHandle, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCommonAdvise(IN OTCommonCallbackFunctions* pCallbacks);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerAdvise(IN OTServerCallbackFunctions* pCallbacks);
#if TB5_CLIENT
	TBCORE_IF EnumStatusCode OTAPI_CALL OTClientAdvise(IN OTClientSessionCallbackFunctions* pSessionCallbacks,
		IN OTClientSubscriptionCallbackFunctions* pSubscriptionCallbacks, IN OTClientMonitoredItemCallbackFunctions* pMonitoredItemCallbacks,
		IN OTClientRedundantSessionCallbackFunctions* pRedundantSessionCallbacks, IN OTClientRedundantSubscriptionCallbackFunctions* pRedundantSubscriptionCallbacks,
		IN OTClientRedundantMonitoredItemCallbackFunctions* pRedundantMonitoredItemCallbacks);
#endif

	TBCORE_IF const TCHAR* OTAPI_CALL OTGetErrorText(EnumStatusCode code);

	////////////////////////////////////////////////////////////////////////////////
	// Few missing exported methods
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDateTimeSet(void* pTarget, const void* pSource);
	TBCORE_IF int OTAPI_CALL OTDateTimeCompare(const void* pSource, const void* pTarget);
#ifdef SOOS_WINDOWS
	TBCORE_IF void OTAPI_CALL OTDateTimeSetFileTime(void* pTarget, const FILETIME& fileTime);
	TBCORE_IF void OTAPI_CALL OTDateTimeGetFileTime(const void* pTarget, FILETIME& fileTimefileTime);
#endif
	TBCORE_IF TCHAR* OTAPI_CALL OTDateToString(const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDateFromString(const void* pTarget, const TCHAR* dateStr);
	TBCORE_IF void OTAPI_CALL OTDateTimeNow(void* pTarget);
	TBCORE_IF void OTAPI_CALL OTDateTimeUtcNow(void* pTarget);
	TBCORE_IF OTUInt32 OTAPI_CALL OTDateTimeMilliSecond(const void* pTarget);
	TBCORE_IF OTUInt32 OTAPI_CALL OTDateTimeMilliSecondGMT(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeSecond(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeSecondGMT(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeMinute(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeMinuteGMT(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeHour(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeHourGMT(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeDay(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeDayGMT(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeMonth(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeMonthGMT(const void* pTarget);
	TBCORE_IF OTUInt32 OTAPI_CALL OTDateTimeYear(const void* pTarget);
	TBCORE_IF OTUInt32 OTAPI_CALL OTDateTimeYearGMT(const void* pTarget);
	TBCORE_IF OTUInt64 OTAPI_CALL OTDateTimeDurationMilliseconds(const void* pFrom, const void* pTo);
	TBCORE_IF void OTAPI_CALL OTDateTimeAddMilliseconds(void* pTarget, OTUInt64 milliseconds);
	TBCORE_IF void OTAPI_CALL OTDateTimeSubtractMilliseconds(void* pTarget, OTUInt64 milliseconds);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDateTimeIsNull(void* pTarget, bool* pIsNull);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDateTimeClear(DateTimeStruct* pTarget);
	TBCORE_IF int OTGetEnumerationValue(LPCTSTR str, EnumGroup group, bool inclusiveUnknown);
	TBCORE_IF LPCTSTR OTGetEnumerationString(unsigned enumValue, EnumGroup group, bool inclusiveUnknown);
	TBCORE_IF void OTAPI_CALL OTGuidSet(GuidStruct* pTarget, const GuidStruct* pSource);
	TBCORE_IF int OTAPI_CALL OTGuidCompare(const GuidStruct* pSource, const GuidStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTGuidGenerate(GuidStruct* pTarget);
	TBCORE_IF TCHAR* OTAPI_CALL OTGuidToString(const GuidStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTGuidFromString(const TCHAR* guidString, GuidStruct* pGuid);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTGuidClear(GuidStruct* pGuid);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTInit(OT_Memory_Alloc_Func pAlloc, OT_Memory_ReAlloc_Func pRealloc, OT_Memory_Free_Func pFree);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTExit();
	TBCORE_IF void OTAPI_CALL OTThreadCleanup();
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSeedPrngState(const ByteStringStruct* pEntropy);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSetNumeric(NodeIdStruct* pTarget, unsigned short namespaceIndex, OTUInt32 numeric);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSetString(NodeIdStruct* pTarget, unsigned short namespaceIndex, const TCHAR* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSetGuid(NodeIdStruct* pTarget, unsigned short namespaceIndex, const GuidStruct* guid);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSetOpaque(NodeIdStruct* pTarget, unsigned short namespaceIndex, const ByteStringStruct* byteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSetNull(NodeIdStruct* pTarget);
	TBCORE_IF bool OTAPI_CALL OTNodeIdIsNull(const NodeIdStruct* pTarget);
	TBCORE_IF TCHAR* OTAPI_CALL OTNodeIdToString(const NodeIdStruct* pTarget);
	TBCORE_IF bool OTAPI_CALL OTNodeIdAreEqual(const NodeIdStruct* pNodeId1, const NodeIdStruct* pNodeId2);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdParse(const TCHAR* pString, NodeIdStruct* pNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCreateNodeId(NodeIdStruct* pTargetNodeId, EnumIdentifierType identifierType, unsigned short namespaceIndex);

	TBCORE_IF TCHAR* OTAPI_CALL OTExpandedNodeIdToString(const void* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ValueStruct
	////////////////////////////////////////////////////////////////////////////////
	/*! @brief stands for copy constructor. */
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSet(ValueStruct* pTarget, const ValueStruct* pValue);
	TBCORE_IF void OTAPI_CALL OTValueClear(ValueStruct* pTarget);
	TBCORE_IF bool OTAPI_CALL OTValueAreEqual(ValueStruct* pVal1, ValueStruct* pVal2);
	TBCORE_IF TCHAR* OTAPI_CALL OTValueToString(const ValueStruct* pTarget);
	TBCORE_IF int OTAPI_CALL OTValueCompare(const ValueStruct* pSource, const ValueStruct* pTarget);

	TBCORE_IF void OTAPI_CALL OTValueSetBoolean(ValueStruct* pTarget, OTBoolean value);
	TBCORE_IF void OTAPI_CALL OTValueSetUInt8(ValueStruct* pTarget, OTUInt8 value);
	TBCORE_IF void OTAPI_CALL OTValueSetInt8(ValueStruct* pTarget, OTInt8 value);
	TBCORE_IF void OTAPI_CALL OTValueSetUInt16(ValueStruct* pTarget, OTUInt16 value);
	TBCORE_IF void OTAPI_CALL OTValueSetInt16(ValueStruct* pTarget, OTInt16 value);
	TBCORE_IF void OTAPI_CALL OTValueSetUInt32(ValueStruct* pTarget, OTUInt32 value);
	TBCORE_IF void OTAPI_CALL OTValueSetInt32(ValueStruct* pTarget, OTInt32 value);
	TBCORE_IF void OTAPI_CALL OTValueSetUInt64(ValueStruct* pTarget, OTUInt64 value);
	TBCORE_IF void OTAPI_CALL OTValueSetInt64(ValueStruct* pTarget, OTInt64 value);
	TBCORE_IF void OTAPI_CALL OTValueSetFloat(ValueStruct* pTarget, OTFloat value);
	TBCORE_IF void OTAPI_CALL OTValueSetDouble(ValueStruct* pTarget, OTDouble value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetString(ValueStruct* pTarget, const TCHAR* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetByteString(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetXmlElement(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDateTime(void* pTarget, const void* pValue);
	TBCORE_IF void OTAPI_CALL OTValueSetStatusCode(ValueStruct* pTarget, EnumStatusCode statusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetGuid(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetExpandedNodeId(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetQualifiedName(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEUInformation(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetTimeZone(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetRange(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetReferenceDescription(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetApplicationDescription(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServerDiagnosticsSummaryDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSubscriptionDiagnosticsDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSessionDiagnosticsDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSessionSecurityDiagnosticsDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServiceCounterDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSemanticChangeStructureDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetModelChangeStructureDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetArgument(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetLocalizedText(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDataValue(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetNodeId(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUserIdentityToken(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSignedSoftwareCertificate(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetBuildInfo(void* pTarget, const void* pValue);
#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEventFilter(void* pTarget, const void* pValue);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServerStatusDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEnumValueType(void* pTarget, const void* pValue);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueGetComplexRaw(const ValueStruct* pTarget, NodeIdStruct* encodingNodeId, ByteStringStruct* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetComplexRaw(ValueStruct* pTarget, const NodeIdStruct* encodingNodeId, const ByteStringStruct* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueGetComplexRawArray(const ValueStruct* pTarget, NodeIdStruct* encodingId, size_t* pValueCount, ByteStringStruct** ppValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetComplexRawArray(ValueStruct* pTarget, const NodeIdStruct* encodingId, size_t valueCount, ByteStringStruct** ppValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueGetStructureFields(const ValueStruct* pTarget, TBHandle typeDescHandle, size_t *pFieldCount, ValueStruct*** pppArray);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetStructureFields(ValueStruct* pTarget, const NodeIdStruct* pTypeNodeId,  TBHandle typeDescHandle, size_t fieldCount, const ValueStruct* const* pArray);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueGetStructureFieldsArray(const ValueStruct* pTarget, TBHandle typeDescHandle, size_t* pCounterSize, size_t** ppCounterArray, ValueStruct**** ppppFieldArrays);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetStructureFieldsArray(ValueStruct* pTarget, const NodeIdStruct* pTypeNodeId, TBHandle typeDescHandle, size_t counterSize, size_t* pCounterArray, ValueStruct*** pppFieldArrays);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetBooleanArray(ValueStruct* pTarget, const OTBoolean* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt8Array(ValueStruct* pTarget, const OTUInt8* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt8Array(ValueStruct* pTarget, const OTInt8* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt16Array(ValueStruct* pTarget, const OTUInt16* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt16Array(ValueStruct* pTarget, const OTInt16* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt32Array(ValueStruct* pTarget, const OTUInt32* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt32Array(ValueStruct* pTarget, const OTInt32* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt64Array(ValueStruct* pTarget, const OTUInt64* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt64Array(ValueStruct* pTarget, const OTInt64* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetFloatArray(ValueStruct* pTarget, const OTFloat* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDoubleArray(ValueStruct* pTarget, const OTDouble* pArray, long length);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetStatusCodeArray(ValueStruct* pTarget, const EnumStatusCode* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDateTimeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetStringArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetGuidArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetNodeIdArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetExpandedNodeIdArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetLocalizedTextArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetValueArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetQualifiedNameArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEUInformationArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetTimeZoneArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetRangeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetReferenceDescriptionArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetApplicationDescriptionArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServerDiagnosticsSummaryDataTypeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSubscriptionDiagnosticsDataTypeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSessionDiagnosticsDataTypeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSessionSecurityDiagnosticsDataTypeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServiceCounterDataTypeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSemanticChangeStructureDataTypeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetModelChangeStructureDataTypeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetArgumentArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDataValueArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetByteStringArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetXmlElementArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUserIdentityTokenArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSignedSoftwareCertificateArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetBuildInfoArray(void* pTarget, const void* pArray, long length);
#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEventFilterArray(void* pTarget, const void* pArray, long length);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServerStatusDataTypeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEnumValueTypeArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueGetSubset(const void* pTarget, void* pDst, const void* indexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSubset(void* pTarget, const void* pSrc, const void* indexRange);

	TBCORE_IF EnumValueCastType OTAPI_CALL OTValueCastHelperCanCast(EnumDataTypeId targetDataType, EnumDataTypeId sourceDataType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueCastHelperCast(EnumDataTypeId targetDataType, void* pTargetValue, const void* pSourceValue);

	TBCORE_IF EnumApiClassType OTAPI_CALL OTBGetObjectType(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTGetApiHandle(TBHandle otbHandle, bool releaseCore);
	TBCORE_IF TBHandle OTAPI_CALL OTGetApiHandleExtended(TBHandle otbHandle, bool releaseCore, const XmlElementStruct *pXmlTag);

	TBCORE_IF void OTAPI_CALL OTEnterUsage(TBHandle otbHandle);
	TBCORE_IF void OTAPI_CALL OTLeaveUsage(TBHandle otbHandle);
	TBCORE_IF long OTAPI_CALL OTBAddRef(TBHandle otbHandle);
	TBCORE_IF long OTAPI_CALL OTBRelease(TBHandle otbHandle);
	TBCORE_IF void OTAPI_CALL OTLockLifetimeSemaphore();
	TBCORE_IF void OTAPI_CALL OTUnlockLifetimeSemaphore();
	TBCORE_IF void OTAPI_CALL OTLockStructSemaphore();
	TBCORE_IF void OTAPI_CALL OTUnlockStructSemaphore();

	TBCORE_IF EnumStatusCode OTAPI_CALL OTApplicationDescriptionClear(ApplicationDescriptionStruct* pApplicationDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTApplicationDescriptionSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTApplicationDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTApplicationDescriptionCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataValueClear(DataValueStruct* pDataValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataValueSet(DataValueStruct* pTarget, const DataValueStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataValueCopy(const DataValueStruct* pSource, DataValueStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataValueCompare(const DataValueStruct* pSource, const DataValueStruct* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTExpandedNodeIdClear(ExpandedNodeIdStruct* pExpandedNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTExpandedNodeIdSet(ExpandedNodeIdStruct* pTarget, const ExpandedNodeIdStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTExpandedNodeIdSetNodeId(ExpandedNodeIdStruct* pTarget, const NodeIdStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTExpandedNodeIdCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTExpandedNodeIdCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextAddReference(LocalizedTextStruct* pLocalizedText);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextReleaseReference(LocalizedTextStruct* pLocalizedText);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextClear(LocalizedTextStruct* pLocalizedText);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextSet(LocalizedTextStruct* pTarget, const LocalizedTextStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextCopy(const LocalizedTextStruct* pSource, LocalizedTextStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTLocalizedTextCompare(const LocalizedTextStruct* pSource, const LocalizedTextStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextGetTranslation(LocalizedTextStruct* pTarget, unsigned preferredLocalesCount, const TCHAR** pPreferredLocales, TCHAR** pTranslation, TCHAR** pLocale);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextGetAllTranslations(LocalizedTextStruct* pLocalizedText, TCHAR*** pppAllTexts, size_t* pTextCount, TCHAR*** pppAllLocales, size_t* pLocaleCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextDefineTranslation(LocalizedTextStruct* pTarget, const TCHAR* pTranslation, const TCHAR* pLocale);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextRemoveTranslation(LocalizedTextStruct* pTarget, const TCHAR* pLocale);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTQualifiedNameClear(QualifiedNameStruct* pQualifiedName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQualifiedNameSet(QualifiedNameStruct* pTarget, const QualifiedNameStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQualifiedNameCopy(const QualifiedNameStruct* pSource, QualifiedNameStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTQualifiedNameCompare(const QualifiedNameStruct* pSource, const QualifiedNameStruct* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTReferenceDescriptionClear(ReferenceDescriptionStruct* pReferenceDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReferenceDescriptionSet(ReferenceDescriptionStruct* pTarget, const ReferenceDescriptionStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReferenceDescriptionCopy(const ReferenceDescriptionStruct* pSource, ReferenceDescriptionStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTReferenceDescriptionCompare(const ReferenceDescriptionStruct* pSource, const ReferenceDescriptionStruct* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTViewDescriptionClear(ViewDescriptionStruct* pViewDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTViewDescriptionSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTViewDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTViewDescriptionCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdClear(NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSet(NodeIdStruct* pTarget, const NodeIdStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdCopy(const NodeIdStruct* pSource, NodeIdStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTNodeIdCompare(const NodeIdStruct* pSource, const NodeIdStruct* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseDescriptionClear(BrowseDescriptionStruct* pBrowseDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseDescriptionSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBrowseDescriptionCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserAuthenticationTokenClear(UserAuthenticationTokenStruct* pUserAuthenticationToken);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserAuthenticationTokenSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserAuthenticationTokenCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTUserAuthenticationTokenCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyClear(UserTokenPolicyStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTUserTokenPolicyCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyGetPolicyId(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySetPolicyId(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyGetTokenType(TBHandle otbHandle, EnumUserTokenType* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySetTokenType(TBHandle otbHandle, EnumUserTokenType value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyGetIssuedTokenType(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySetIssuedTokenType(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyGetIssuerEndpointUrl(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySetIssuerEndpointUrl(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyGetSecurityPolicyUri(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySetSecurityPolicyUri(TBHandle otbHandle, const TCHAR* value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTEndpointDescriptionClear(EndpointDescriptionStruct* pEndpointDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEndpointDescriptionSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEndpointDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTEndpointDescriptionCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadValueIdClear(ReadValueIdStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadValueIdSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadValueIdCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTReadValueIdCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriteValueClear(WriteValueStruct* pWriteValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriteValueSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriteValueCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTWriteValueCompare(const void* pSource, const void* pTarget);

#if TB5_HISTORY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadRawModifiedDetailsClear(ReadRawModifiedDetailsStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadRawModifiedDetailsSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadRawModifiedDetailsCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTReadRawModifiedDetailsCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadEventDetailsClear(ReadEventDetailsStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadEventDetailsSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadEventDetailsCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTReadEventDetailsCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadValueIdClear(HistoryReadValueIdStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadValueIdSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadValueIdCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryReadValueIdCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataClear(HistoryDataStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryDataCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataExtensionObjectClear(HistoryDataExtensionObjectStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataExtensionObjectSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataExtensionObjectCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryDataExtensionObjectCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadResultClear(HistoryReadResultStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryReadResultCompare(const void* pSource, const void* pTarget);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseResultClear(BrowseResultStruct* pBrowseResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBrowseResultCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTAccessPatternClear(AccessPatternStruct* pAccessPattern);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAccessPatternSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAccessPatternCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTAccessPatternCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTPkiStoreConfigurationInitialize(PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPkiStoreConfigurationClear(PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPkiStoreConfigurationSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPkiStoreConfigurationCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTPkiStoreConfigurationCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathClear(RelativePathStruct* pRelativePath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTRelativePathCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathElementClear(RelativePathElementStruct* pRelativePathElement);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathElementSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathElementCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTRelativePathElementCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathClear(BrowsePathStruct* pBrowsePath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBrowsePathCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathTargetClear(BrowsePathTargetStruct* pBrowsePathTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathTargetSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathTargetCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBrowsePathTargetCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathResultClear(BrowsePathResultStruct* pBrowsePathResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBrowsePathResultCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataChangeFilterClear(DataChangeFilterStruct* pDataChangeFilter);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataChangeFilterSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataChangeFilterCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataChangeFilterCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTEUInformationClear(EUInformationStruct* pEUInformation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEUInformationSet(void* pTarget, const void* pSource);
	TBCORE_IF int OTAPI_CALL OTEUInformationCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTTimeZoneClear(TimeZoneStruct* pTimeZone);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTTimeZoneSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTTimeZoneCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTTimeZoneCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTArgumentClear(ArgumentStruct* pArgument);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTArgumentSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTArgumentCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTArgumentCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTArgumentSetValueRank(ArgumentStruct* pArgument, OTInt32 valueRank);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTArgumentSetArrayDimensions(ArgumentStruct* pArgument, OTUInt32 dimensionsCount, const OTUInt32* pArrayDimensions);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTRangeClear(RangeStruct* pRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRangeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRangeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTRangeCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodRequestClear(CallMethodRequestStruct* pCallMethodRequest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodRequestSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodRequestCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTCallMethodRequestCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodResultClear(CallMethodResultStruct* pCallMethodResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTCallMethodResultCompare(const void* pSource, const void* pTarget);

#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFilterClear(EventFilterStruct* pEventFilter);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFilterSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFilterCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTEventFilterCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleAttributeOperandClear(SimpleAttributeOperandStruct* pSimpleAttributeOperand);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleAttributeOperandSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleAttributeOperandCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSimpleAttributeOperandCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFieldListClear(EventFieldListStruct* pEventFieldList);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFieldListSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFieldListCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTEventFieldListCompare(const void* pSource, const void* pTarget);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignatureDataClear(SignatureDataStruct* pSignatureData);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignatureDataSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignatureDataCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSignatureDataCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterClear(ContentFilterStruct* pContentFilter);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTContentFilterCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementClear(ContentFilterElementStruct* pContentFilterElement);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTContentFilterElementCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTFilterOperandClear(FilterOperandStruct* pFilterOperand);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFilterOperandSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFilterOperandCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTFilterOperandCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTElementOperandClear(ElementOperandStruct* pElementOperand);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTElementOperandSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTElementOperandCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTElementOperandCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTLiteralOperandClear(LiteralOperandStruct* pLiteralOperand);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLiteralOperandSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLiteralOperandCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTLiteralOperandCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTAttributeOperandClear(AttributeOperandStruct* pAttributeOperand);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAttributeOperandSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAttributeOperandCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTAttributeOperandCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTMonitoringChangeClear(MonitoringChangeStruct* pMonitoringChange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTMonitoringChangeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTMonitoringChangeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTMonitoringChangeCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeTypeDescriptionClear(NodeTypeDescriptionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeTypeDescriptionSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeTypeDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTNodeTypeDescriptionCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeTypeDescriptionGetIncludeSubTypes(TBHandle otbHandle, bool* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeTypeDescriptionSetIncludeSubTypes(TBHandle otbHandle, bool value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTParsingResultClear(ParsingResultStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTParsingResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTParsingResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTParsingResultCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTParsingResultGetStatusCode(TBHandle otbHandle, EnumStatusCode* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTParsingResultSetStatusCode(TBHandle otbHandle, EnumStatusCode value);

#if TB5_QUERY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataDescriptionClear(QueryDataDescriptionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataDescriptionSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTQueryDataDescriptionCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataDescriptionGetAttributeId(TBHandle otbHandle, EnumAttributeId* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataDescriptionSetAttributeId(TBHandle otbHandle, EnumAttributeId value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataSetClear(QueryDataSetStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataSetSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataSetCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTQueryDataSetCompare(const void* pSource, const void* pTarget);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringClear(ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringSet(ByteStringStruct* pTarget, const ByteStringStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringInit(ByteStringStruct* pTarget, OTUInt32 length, const unsigned char* pData);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringSetUtf8FromString(void* pTarget, const TCHAR* pString);
	TBCORE_IF TCHAR* OTAPI_CALL OTByteStringGetStringFromUtf8(const void* pTarget);
	TBCORE_IF int OTAPI_CALL OTByteStringCompare(const void* pSource, const void* pTarget);
	TBCORE_IF TCHAR* OTAPI_CALL OTByteStringToString(const ByteStringStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringGetLength(const ByteStringStruct* pTarget, unsigned* pLength);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringGetData(const ByteStringStruct* pTarget, unsigned char** pData);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTNumericRangeClear(NumericRangeStruct* pNumericRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNumericRangeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNumericRangeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTNumericRangeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF OTUInt32 OTAPI_CALL OTNumericRangeCapacity(const NumericRangeStruct* pNumericRange);
	TBCORE_IF void OTAPI_CALL OTNumericRangeReserve(NumericRangeStruct* pNumericRange, OTUInt32 n);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNumericRangeAddRange(NumericRangeStruct* pNumericRange, unsigned lowerBound, unsigned upperBound);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNumericRangeParse(NumericRangeStruct* pNumericRange, const TCHAR* numericRange);
	TBCORE_IF TCHAR* OTAPI_CALL OTNumericRangeToString(const NumericRangeStruct* pNumericRange);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetApplicationUri(TBHandle otbHandle, TCHAR** pApplicationUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetApplicationUri(TBHandle otbHandle, const TCHAR* _ApplicationUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetProductUri(TBHandle otbHandle, TCHAR** pProductUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetProductUri(TBHandle otbHandle, const TCHAR* _ProductUri);
	TBCORE_IF TBHandle OTAPI_CALL OTBApplicationDescriptionGetApplicationNameHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetApplicationType(TBHandle otbHandle, EnumApplicationType* pApplicationType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetApplicationType(TBHandle otbHandle, EnumApplicationType _ApplicationType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetGatewayServerUri(TBHandle otbHandle, TCHAR** pGatewayServerUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetGatewayServerUri(TBHandle otbHandle, const TCHAR* _GatewayServerUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetDiscoveryProfileUri(TBHandle otbHandle, TCHAR** pDiscoveryProfileUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetDiscoveryProfileUri(TBHandle otbHandle, const TCHAR* _DiscoveryProfileUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetDiscoveryUrls(TBHandle otbHandle, unsigned* discoveryUrlsCount, TCHAR*** pDiscoveryUrls);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetDiscoveryUrls(TBHandle otbHandle, unsigned discoveryUrlsCount, const TCHAR** _DiscoveryUrls);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueSetStatusCode(TBHandle otbHandle, EnumStatusCode _StatusCode);
	TBCORE_IF TBHandle OTAPI_CALL OTBDataValueGetSourceTimestampHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBDataValueGetServerTimestampHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueGetSourcePicoseconds(TBHandle otbHandle, unsigned short* pSourcePicoseconds);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueSetSourcePicoseconds(TBHandle otbHandle, unsigned short _SourcePicoseconds);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueGetServerPicoseconds(TBHandle otbHandle, unsigned short* pServerPicoseconds);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueSetServerPicoseconds(TBHandle otbHandle, unsigned short _ServerPicoseconds);
	TBCORE_IF TBHandle OTAPI_CALL OTBDataValueGetValueHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBExpandedNodeIdGetNamespaceUri(TBHandle otbHandle, TCHAR** pNamespaceUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBExpandedNodeIdSetNamespaceUri(TBHandle otbHandle, const TCHAR* _NamespaceUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBExpandedNodeIdGetServerIndex(TBHandle otbHandle, OTUInt32* pServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBExpandedNodeIdSetServerIndex(TBHandle otbHandle, OTUInt32 _ServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBQualifiedNameGetName(TBHandle otbHandle, TCHAR** pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBQualifiedNameSetName(TBHandle otbHandle, const TCHAR* _Name);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBQualifiedNameGetNamespaceIndex(TBHandle otbHandle, unsigned short* pNamespaceIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBQualifiedNameSetNamespaceIndex(TBHandle otbHandle, unsigned short _NamespaceIndex);

	TBCORE_IF TBHandle OTAPI_CALL OTBReferenceDescriptionGetReferenceTypeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReferenceDescriptionGetIsForward(TBHandle otbHandle, bool* pIsForward);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReferenceDescriptionSetIsForward(TBHandle otbHandle, bool _IsForward);
	TBCORE_IF TBHandle OTAPI_CALL OTBReferenceDescriptionGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBReferenceDescriptionGetBrowseNameHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBReferenceDescriptionGetDisplayNameHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReferenceDescriptionGetNodeClass(TBHandle otbHandle, EnumNodeClass* pNodeClass);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReferenceDescriptionSetNodeClass(TBHandle otbHandle, EnumNodeClass _NodeClass);
	TBCORE_IF TBHandle OTAPI_CALL OTBReferenceDescriptionGetTypeDefinitionHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceGetFileName(TBHandle otbHandle, TCHAR** pFileName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceGetFileMaxSize(TBHandle otbHandle, OTUInt32* pFileMaxSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceGetMaximumBackups(TBHandle otbHandle, OTUInt32* pMaximumBackups);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceGetSocketPort(TBHandle otbHandle, OTUInt32* pSocketPort);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceSetSocketPort(TBHandle otbHandle, OTUInt32 _SocketPort);
	TBCORE_IF TBHandle OTAPI_CALL OTBViewDescriptionGetViewIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBViewDescriptionGetTimestampHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBViewDescriptionGetViewVersion(TBHandle otbHandle, OTUInt32* pViewVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBViewDescriptionSetViewVersion(TBHandle otbHandle, OTUInt32 _ViewVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBNodeIdGetNamespaceIndex(TBHandle otbHandle, unsigned short* pNamespaceIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBNodeIdSetNamespaceIndex(TBHandle otbHandle, unsigned short _NamespaceIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBNodeIdGetIdentifierType(TBHandle otbHandle, EnumIdentifierType* pIdentifierType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBNodeIdSetIdentifierType(TBHandle otbHandle, EnumIdentifierType _IdentifierType);
	TBCORE_IF TBHandle OTAPI_CALL OTBApplicationGetDescriptionHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetManufacturerName(TBHandle otbHandle, TCHAR** ppManufacturerName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetManufacturerName(TBHandle otbHandle, const TCHAR* pManufacturerName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMajorVersion(TBHandle otbHandle, unsigned short* pMajorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMajorVersion(TBHandle otbHandle, unsigned short _MajorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMinorVersion(TBHandle otbHandle, unsigned short* pMinorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMinorVersion(TBHandle otbHandle, unsigned short _MinorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetPatchVersion(TBHandle otbHandle, unsigned short* pPatchVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetPatchVersion(TBHandle otbHandle, unsigned short _PatchVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetBuildNumber(TBHandle otbHandle, OTUInt32* pBuildNumber);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetBuildNumber(TBHandle otbHandle, OTUInt32 _BuildNumber);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetBuildDate(TBHandle otbHandle, DateTimeStruct* pBuildDate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetBuildDate(TBHandle otbHandle, const DateTimeStruct* pBuildDate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetToolboxMajorVersion(TBHandle otbHandle, unsigned short* pToolboxMajorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetToolboxMinorVersion(TBHandle otbHandle, unsigned short* pToolboxMinorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetToolboxBuildNumber(TBHandle otbHandle, OTUInt32* pToolboxBuildNumber);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetToolboxPatchVersion(TBHandle otbHandle, unsigned short* pToolboxPatchVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetPreferredLocales(TBHandle otbHandle, OTUInt32 preferredLocaleCount, const TCHAR** preferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetPreferredLocales(TBHandle otbHandle, OTUInt32 *pPreferredLocaleCount, TCHAR*** pppPreferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 timeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 *pTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetDefaultDataChangeMonitoringQueueSize(TBHandle otbHandle, OTUInt32* pDefaultMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetDefaultDataChangeMonitoringQueueSize(TBHandle otbHandle, OTUInt32 _DefaultMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxDataChangeMonitoringQueueSize(TBHandle otbHandle, OTUInt32* pMaxMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxDataChangeMonitoringQueueSize(TBHandle otbHandle, OTUInt32 _MaxMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxEventMonitoringQueueSize(TBHandle otbHandle, OTUInt32* pMaxMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxEventMonitoringQueueSize(TBHandle otbHandle, OTUInt32 _MaxMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMinSessionTimeout(TBHandle otbHandle, OTUInt32* pMinSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMinSessionTimeout(TBHandle otbHandle, OTUInt32 _MinSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxSessionTimeout(TBHandle otbHandle, OTUInt32* pMaxSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxSessionTimeout(TBHandle otbHandle, OTUInt32 _MaxSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxPipedPublishRequests(TBHandle otbHandle, OTUInt32* pMaxPipedPublishRequests);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxPipedPublishRequests(TBHandle otbHandle, OTUInt32 _MaxPipedPublishRequests);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxMonitoredItemsPerService(TBHandle otbHandle, OTUInt32* pMaxMonitoredItemsPerService);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxMonitoredItemsPerService(TBHandle otbHandle, OTUInt32 _MaxMonitoredItemsPerService);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetDefaultNetworkTimeout(TBHandle otbHandle, OTUInt32* pDefaultNetworkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetDefaultNetworkTimeout(TBHandle otbHandle, OTUInt32 _DefaultNetworkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCApplicationGetDefaultAutoReconnectInterval(TBHandle otbHandle, OTUInt32* pDefaultAutoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCApplicationSetDefaultAutoReconnectInterval(TBHandle otbHandle, OTUInt32 _DefaultAutoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCApplicationGetDefaultConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32* pDefaultConnectionMonitoringInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCApplicationSetDefaultConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32 _DefaultConnectionMonitoringInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxDataSetsToReturn(TBHandle otbHandle, OTUInt32* pMaxDataSetsToReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxDataSetsToReturn(TBHandle otbHandle, OTUInt32 _MaxDataSetsToReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxReferencesToReturn(TBHandle otbHandle, OTUInt32* pMaxReferencesToReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxReferencesToReturn(TBHandle otbHandle, OTUInt32 _MaxReferencesToReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxNodesToAnalyzePerQueryRequest(TBHandle otbHandle, OTUInt32* pMaxNodesToAnalyzePerQueryRequest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxNodesToAnalyzePerQueryRequest(TBHandle otbHandle, OTUInt32 _MaxNodesToAnalyzePerQueryRequest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxBrowseContinuationPoints(TBHandle otbHandle, OTUInt16* pMaxBrowseContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxBrowseContinuationPoints(TBHandle otbHandle, OTUInt16 _MaxBrowseContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxHistoryContinuationPoints(TBHandle otbHandle, OTUInt16* pMaxHistoryContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxHistoryContinuationPoints(TBHandle otbHandle, OTUInt16 _MaxHistoryContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxQueryContinuationPoints(TBHandle otbHandle, OTUInt16* pMaxQueryContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxQueryContinuationPoints(TBHandle otbHandle, OTUInt16 _MaxQueryContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetMinDiagnosticsUpdateInterval(TBHandle otbHandle, OTUInt32* pMinDiagnosticsUpdateInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetMinDiagnosticsUpdateInterval(TBHandle otbHandle, OTUInt32 _MinDiagnosticsUpdateInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetMaxDiagnosticsUpdateInterval(TBHandle otbHandle, OTUInt32* pMaxDiagnosticsUpdateInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetMaxDiagnosticsUpdateInterval(TBHandle otbHandle, OTUInt32 _MaxDiagnosticsUpdateInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCApplicationGetDemoTime(TBHandle otbHandle, OTUInt32* pDemoTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetDemoTime(TBHandle otbHandle, OTUInt32 _DemoTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMinPublishingInterval(TBHandle otbHandle, double* pMinPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMinPublishingInterval(TBHandle otbHandle, double _MinPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxPublishingInterval(TBHandle otbHandle, double* pMaxPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxPublishingInterval(TBHandle otbHandle, double _MaxPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMinSamplingInterval(TBHandle otbHandle, double* pMinSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMinSamplingInterval(TBHandle otbHandle, double _MinSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxSamplingInterval(TBHandle otbHandle, double* pMaxSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxSamplingInterval(TBHandle otbHandle, double _MaxSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetEnableAuditEvents(TBHandle otbHandle, bool* pEnableAuditEvents);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetEnableAuditEvents(TBHandle otbHandle, bool _EnableAuditEvents);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetChannelSharing(TBHandle otbHandle, bool* pEnableSharing);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetChannelSharing(TBHandle otbHandle, bool enableSharing);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationIsServiceGroupEnabled(TBHandle otbHandle, EnumServiceGroup serviceGroup, bool* pEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetEnableServiceGroup(TBHandle otbHandle, EnumServiceGroup serviceGroup, bool _Enable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetServerRedundancyMode(TBHandle otbHandle, EnumRedundancySupport* pRedundancyMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetServerRedundancyMode(TBHandle otbHandle, EnumRedundancySupport redundancyMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetRedundantServerArray(TBHandle otbHandle, OTUInt32* pRedundantServerDescriptionsCount, ApplicationDescriptionStruct** ppRedundantServerDescriptions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetRedundantServerArray(TBHandle otbHandle, OTUInt32 redundantServerDescriptionsCount, const ApplicationDescriptionStruct** pRedundantServerDescriptions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetPkiStoreConfiguration(TBHandle otbHandle, PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetPkiStoreConfiguration(TBHandle otbHandle, const PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetDhParamFileLocation(TBHandle otbHandle, const TCHAR* _DhParamFileLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationValidateCertificate(TBHandle otbHandle, const PkiStoreConfigurationStruct* pPkiStoreConfiguration, const ByteStringStruct *pX509Certificate, const TCHAR* pAppUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetSuppressAddresspaceCreation(TBHandle otbHandle, bool* pSuppress);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetSuppressAddresspaceCreation(TBHandle otbHandle, bool suppress);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStatisticsGetSubscriptionCount(TBHandle otbHandle, OTUInt32* pSubscriptionCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStatisticsGetDataChangeEventCount(TBHandle otbHandle, OTUInt32* pDataChangeEventCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStatisticsGetNetworkFailureCount(TBHandle otbHandle, OTUInt32* pNetworkFailureCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStatisticsGetMonitoredItemCount(TBHandle otbHandle, OTUInt32* pMonitoredItemCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenGetPolicyId(TBHandle otbHandle, TCHAR** pPolicyId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenSetPolicyId(TBHandle otbHandle, const TCHAR* _PolicyId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenGetSecurityPolicyUri(TBHandle otbHandle, TCHAR** pSecurityPolicyUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenSetSecurityPolicyUri(TBHandle otbHandle, const TCHAR* _SecurityPolicyUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenGetType(TBHandle otbHandle, EnumUserTokenType* pType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenGetIssuedTokenType(TBHandle otbHandle, TCHAR** pIssuedTokenType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenSetIssuedTokenType(TBHandle otbHandle, const TCHAR* _IssuedTokenType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenGetIssuerEndpointUrl(TBHandle otbHandle, TCHAR** pIssuerEndpointUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenSetIssuerEndpointUrl(TBHandle otbHandle, const TCHAR* _IssuerEndpointUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicyGetPolicyId(TBHandle otbHandle, TCHAR** pPolicyId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicySetPolicyId(TBHandle otbHandle, const TCHAR* _PolicyId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicyGetTokenType(TBHandle otbHandle, EnumUserTokenType* pTokenType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicySetTokenType(TBHandle otbHandle, EnumUserTokenType _TokenType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicyGetIssuerEndpointUrl(TBHandle otbHandle, TCHAR** pIssuerEndpointUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicySetIssuerEndpointUrl(TBHandle otbHandle, const TCHAR* _IssuerEndpointUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicyGetSecurityPolicyUri(TBHandle otbHandle, TCHAR** pSecurityPolicyUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicySetSecurityPolicyUri(TBHandle otbHandle, const TCHAR* _SecurityPolicyUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicyGetIssuedTokenType(TBHandle otbHandle, TCHAR** pIssuedTokenType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicySetIssuedTokenType(TBHandle otbHandle, const TCHAR* _IssuedTokenType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetEndpointUrl(TBHandle otbHandle, TCHAR** pEndpointUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetEndpointUrl(TBHandle otbHandle, const TCHAR* _EndpointUrl);
	TBCORE_IF TBHandle OTAPI_CALL OTBEndpointDescriptionGetServerHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetServerCertificate(TBHandle otbHandle, unsigned* serverCertificateCount, unsigned char** pServerCertificate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetServerCertificate(TBHandle otbHandle, unsigned serverCertificateCount, const unsigned char* _ServerCertificate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* pMessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode _MessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetSecurityPolicy(TBHandle otbHandle, TCHAR** pSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetSecurityPolicy(TBHandle otbHandle, const TCHAR* _SecurityPolicy);
	TBCORE_IF TBHandle OTAPI_CALL OTBEndpointDescriptionGetUserIdentityTokensHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetTransportProfile(TBHandle otbHandle, TCHAR** pTransportProfile);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetTransportProfile(TBHandle otbHandle, const TCHAR* _TransportProfile);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetSecurityLevel(TBHandle otbHandle, unsigned char* pSecurityLevel);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetSecurityLevel(TBHandle otbHandle, unsigned char _SecurityLevel);
	TBCORE_IF TBHandle OTAPI_CALL OTBReadValueIdGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReadValueIdGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReadValueIdSetAttributeId(TBHandle otbHandle, EnumAttributeId _AttributeId);
	TBCORE_IF TBHandle OTAPI_CALL OTBReadValueIdGetDataEncodingHandle(TBHandle otbHandle);
#if TB5_HISTORY
	TBCORE_IF TBHandle OTAPI_CALL OTBHistoryReadValueIdGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBHistoryReadValueIdGetDataEncodingHandle(TBHandle otbHandle);
#endif
	TBCORE_IF TBHandle OTAPI_CALL OTBWriteValueGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBWriteValueGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBWriteValueSetAttributeId(TBHandle otbHandle, EnumAttributeId _AttributeId);
	TBCORE_IF TBHandle OTAPI_CALL OTBWriteValueGetValueHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternGetAccessField(TBHandle otbHandle, unsigned* accessFieldCount, unsigned char** pAccessField);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternSetAccessField(TBHandle otbHandle, unsigned accessFieldCount, const unsigned char* _AccessField);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternGetKey(TBHandle otbHandle, OTUInt32* pKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternSetKey(TBHandle otbHandle, OTUInt32 _Key);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternGetName(TBHandle otbHandle, TCHAR** pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternSetName(TBHandle otbHandle, const TCHAR* _Name);
	TBCORE_IF TBHandle OTAPI_CALL OTBRelativePathGetElementsHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBRelativePathElementGetReferenceTypeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRelativePathElementGetIsInverse(TBHandle otbHandle, bool* pIsInverse);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRelativePathElementSetIsInverse(TBHandle otbHandle, bool _IsInverse);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRelativePathElementGetIncludeSubtypes(TBHandle otbHandle, bool* pIncludeSubtypes);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRelativePathElementSetIncludeSubtypes(TBHandle otbHandle, bool _IncludeSubtypes);
	TBCORE_IF TBHandle OTAPI_CALL OTBRelativePathElementGetTargetNameHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBBrowsePathTargetGetTargetIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBBrowsePathTargetGetRemainingPathIndex(TBHandle otbHandle, OTUInt32* pRemainingPathIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBBrowsePathTargetSetRemainingPathIndex(TBHandle otbHandle, OTUInt32 _RemainingPathIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterGetTrigger(TBHandle otbHandle, EnumDataChangeTrigger* pTrigger);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterSetTrigger(TBHandle otbHandle, EnumDataChangeTrigger _Trigger);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterGetDeadbandType(TBHandle otbHandle, EnumDeadbandType* pDeadbandType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterSetDeadbandType(TBHandle otbHandle, EnumDeadbandType _DeadbandType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterGetDeadbandValue(TBHandle otbHandle, double* pDeadbandValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterSetDeadbandValue(TBHandle otbHandle, double _DeadbandValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTimeZoneGetOffset(TBHandle otbHandle, OTInt16* pOffet);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTimeZoneSetOffset(TBHandle otbHandle, OTInt16 _Offset);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTimeZoneGetDaylightSavingInOffset(TBHandle otbHandle, bool* pDSTInOffsetOffet);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTimeZoneSetDaylightSavingInOffset(TBHandle otbHandle, bool _DSTInOffsetOffet);
	TBCORE_IF TBHandle OTAPI_CALL OTBArgumentGetDescriptionHandle(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTAnonymousIdentityTokenClear(AnonymousIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAnonymousIdentityTokenSet(AnonymousIdentityTokenStruct* pTarget, const AnonymousIdentityTokenStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAnonymousIdentityTokenCopy(const AnonymousIdentityTokenStruct* pSource, AnonymousIdentityTokenStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTAnonymousIdentityTokenCompare(const AnonymousIdentityTokenStruct* pSource, const AnonymousIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAnonymousIdentityTokenGetPolicyId(AnonymousIdentityTokenStruct* otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAnonymousIdentityTokenSetPolicyId(AnonymousIdentityTokenStruct* otbHandle, const TCHAR* value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenClear(UserNameIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenSet(UserNameIdentityTokenStruct* pTarget, const UserNameIdentityTokenStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenCopy(const UserNameIdentityTokenStruct* pSource, UserNameIdentityTokenStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTUserNameIdentityTokenCompare(const UserNameIdentityTokenStruct* pSource, const UserNameIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenGetUserName(UserNameIdentityTokenStruct* otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenSetUserName(UserNameIdentityTokenStruct* otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenGetEncryptionAlgorithm(UserNameIdentityTokenStruct* otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenSetEncryptionAlgorithm(UserNameIdentityTokenStruct* otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenGetPolicyId(UserNameIdentityTokenStruct* otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenSetPolicyId(UserNameIdentityTokenStruct* otbHandle, const TCHAR* value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenClear(X509IdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenSet(X509IdentityTokenStruct* pTarget, const X509IdentityTokenStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenCopy(const X509IdentityTokenStruct* pSource, X509IdentityTokenStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTX509IdentityTokenCompare(const X509IdentityTokenStruct* pSource, const X509IdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenGetPolicyId(X509IdentityTokenStruct* otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenSetPolicyId(X509IdentityTokenStruct* otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenLoadPrivateKey(X509IdentityTokenStruct* pTarget,
		const TCHAR* filePath,
		const TCHAR* password, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenClear(IssuedIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenSet(IssuedIdentityTokenStruct* pTarget, const IssuedIdentityTokenStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenCopy(const IssuedIdentityTokenStruct* pSource, IssuedIdentityTokenStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTIssuedIdentityTokenCompare(const IssuedIdentityTokenStruct* pSource, const IssuedIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenGetEncryptionAlgorithm(IssuedIdentityTokenStruct* otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenSetEncryptionAlgorithm(IssuedIdentityTokenStruct* otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenGetPolicyId(IssuedIdentityTokenStruct* otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenSetPolicyId(IssuedIdentityTokenStruct* otbHandle, const TCHAR* value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenClear(UserIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenSet(UserIdentityTokenStruct* pTarget, const UserIdentityTokenStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenCopy(const UserIdentityTokenStruct* pSource, UserIdentityTokenStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTUserIdentityTokenCompare(const UserIdentityTokenStruct* pSource, const UserIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenSetAnonymousIdentityToken(UserIdentityTokenStruct* otbHandle, AnonymousIdentityTokenStruct* pToken);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenSetUserNameIdentityToken(UserIdentityTokenStruct* otbHandle, UserNameIdentityTokenStruct* pToken);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenSetX509IdentityToken(UserIdentityTokenStruct* otbHandle, X509IdentityTokenStruct* pX509Token);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenSetIssuedIdentityToken(UserIdentityTokenStruct* otbHandle, IssuedIdentityTokenStruct* pIssuedToken);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRangeGetLow(TBHandle otbHandle, double* pLow);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRangeSetLow(TBHandle otbHandle, double _Low);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRangeGetHigh(TBHandle otbHandle, double* pHigh);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRangeSetHigh(TBHandle otbHandle, double _High);
	TBCORE_IF TBHandle OTAPI_CALL OTBCallMethodRequestGetObjectIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBCallMethodRequestGetMethodIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBCallMethodRequestGetInputArgumentsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBCallMethodResultGetInputArgumentResults(TBHandle otbHandle, unsigned* inputArgumentResultsCount, EnumStatusCode** pInputArgumentResults);
	TBCORE_IF TBHandle OTAPI_CALL OTBCallMethodResultGetOutputArgumentsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBCallMethodResultGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
#if TB5_ALARMS
	TBCORE_IF TBHandle OTAPI_CALL OTBEventFilterGetSelectClausesHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBEventFilterGetWhereClauseHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBSimpleAttributeOperandGetTypeDefinitionIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBSimpleAttributeOperandGetBrowsePathHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBSimpleAttributeOperandIndexRangeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSimpleAttributeOperandGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSimpleAttributeOperandSetAttributeId(TBHandle otbHandle, EnumAttributeId _AttributeId);
	TBCORE_IF TBHandle OTAPI_CALL OTBEventFieldListGetEventFieldsHandle(TBHandle otbHandle);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSignatureDataGetSignature(TBHandle otbHandle, unsigned* signatureCount, unsigned char** pSignature);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSignatureDataSetSignature(TBHandle otbHandle, unsigned signatureCount, const unsigned char* _Signature);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSignatureDataGetAlgorithm(TBHandle otbHandle, TCHAR** pAlgorithm);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSignatureDataSetAlgorithm(TBHandle otbHandle, const TCHAR* _Algorithm);
	TBCORE_IF TBHandle OTAPI_CALL OTBContentFilterGetElementsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBContentFilterElementGetFilterOperator(TBHandle otbHandle, EnumFilterOperator* pFilterOperator);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBContentFilterElementSetFilterOperator(TBHandle otbHandle, EnumFilterOperator _FilterOperator);
	TBCORE_IF TBHandle OTAPI_CALL OTBContentFilterElementGetFilterOperandsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBElementOperandGetIndex(TBHandle otbHandle, OTUInt32* pIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBElementOperandSetIndex(TBHandle otbHandle, OTUInt32 _Index);
	TBCORE_IF TBHandle OTAPI_CALL OTBLiteralOperandGetValueHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBAttributeOperandGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBAttributeOperandGetIndexRangeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAttributeOperandGetAlias(TBHandle otbHandle, TCHAR** pAlias);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAttributeOperandSetAlias(TBHandle otbHandle, const TCHAR* _Alias);
	TBCORE_IF TBHandle OTAPI_CALL OTBAttributeOperandGetBrowsePathHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAttributeOperandGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAttributeOperandSetAttributeId(TBHandle otbHandle, EnumAttributeId _AttributeId);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class QualifiedName
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBQualifiedNameSetNameAndIndex(TBHandle otbHandle,
			const TCHAR* name,
			unsigned short namespaceIndex);


	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Trace
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceWriteLine(TBHandle otbHandle,
			EnumTraceLevel enum_level,
			EnumTraceGroup enum_group,
			const TCHAR* message,
			const TCHAR* objectID);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceStop(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableFileLogging(TBHandle otbHandle,
			const TCHAR* file,
			OTUInt32 maxFileSize,
			OTUInt32 maxBackups,
			OTUInt32 bufferSize, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableFileLogging(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableTcpLogging(TBHandle otbHandle,
			const TCHAR* host,
			unsigned short port,
			OTUInt32 maxQueueSize, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableTcpLogging(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceWriteSourceLine(TBHandle otbHandle,
			EnumTraceLevel enum_level,
			EnumTraceGroup enum_group,
			const TCHAR* message,
			const TCHAR* file,
			OTUInt32 line);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableTraceLevel(TBHandle otbHandle,
			EnumTraceGroup enum_groups,
			EnumTraceLevel enum_level);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableTraceLevel(TBHandle otbHandle,
			EnumTraceGroup groups,
			EnumTraceLevel enum_level);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableStdOutLogging(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableStdErrLogging(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableStdOutLogging(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableStdErrLogging(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableCallbackLogging(TBHandle otbHandle, CB_OnLogMessageCore pApiCallback, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableCallbackLogging(TBHandle otbHandle);

	TBCORE_IF void* OTAPI_CALL OTBTraceGetHandle(bool addRef);
	TBCORE_IF void OTAPI_CALL OTBTraceReleaseHandle(TBHandle otbHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Application
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationStart(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationStop(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationAddSession(TBHandle otbHandle,
			TBHandle session, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetSessions(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationRemoveSession(TBHandle otbHandle,
			TBHandle session, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationAddRedundantSession(TBHandle otbHandle,
		TBHandle redundantSession, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetRedundantSessions(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationRemoveRedundantSession(TBHandle otbHandle,
		TBHandle redundantSession, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationActivateLicense(TBHandle otbHandle,
			EnumFeature enum_product,
			const TCHAR* licenseKey, EnumStatusCode* __pReturn);

	TBCORE_IF OTUInt32 OTAPI_CALL OTSImportNode(const NodeIdStruct *pnodeId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationInitialize(TBHandle otbHandle,
			ApplicationDescriptionStruct* pDescription, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationUninitialize(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationAddEndpoint(TBHandle otbHandle,
			TBHandle endPoint, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetEndpoints(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationRemoveEndpoint(TBHandle otbHandle,
			TBHandle endPoint, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationLoadCertificate(TBHandle otbHandle,
			const TCHAR* applicationInstanceCertificate, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationLoadPrivateKey(TBHandle otbHandle,
			const TCHAR* privateKeyFile,
			const TCHAR* password, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetEndpointsFromServer(TBHandle otbHandle,
			const TCHAR* serverUrl,
			OTUInt32 transportProfilesCount, const TCHAR** transportProfiles,
			OTUInt32* endpointDescriptionsCount, EndpointDescriptionStruct** pEndpointDescriptions, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationLoadDiscoveryServerCertificate(TBHandle otbHandle,
			const TCHAR* discoveryServerCertificate, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetAccessGroup(TBHandle otbHandle,
			AccessPatternStruct* pGroup, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetAccessGroups(TBHandle otbHandle,
			unsigned* groupsCount, AccessPatternStruct** pGroups, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationFindServers(TBHandle otbHandle,
			const TCHAR* discoveryServerUrl,
			const TCHAR* securityPolicy,
			EnumMessageSecurityMode enum_messageSecurityMode,
			unsigned serverURIsCount, const TCHAR** serverURIs,
			unsigned* applicationDescriptionsCount, ApplicationDescriptionStruct** pApplicationDescriptions, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetUserAccessLevel(TBHandle otbHandle,
			unsigned short accessGroupKey,
			OTUInt32 userGroupIdx,
			unsigned char* userAccessLevel, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationEnableServerRegistration(TBHandle otbHandle,
			const TCHAR* discoveryServerUrl,
			const TCHAR* discoveryServerSecurityProfile,
			EnumMessageSecurityMode enum_discoveryServerMessageSecurityMode,
			OTUInt32 refreshPeriod, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDisableServerRegistration(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTBApplicationGetHandle(bool addRef);
	TBCORE_IF void OTAPI_CALL OTBApplicationReleaseHandle(TBHandle otbHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Statistics
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSDiagnosticsGetHandle(bool addRef);
	TBCORE_IF void OTAPI_CALL OTSDiagnosticsReleaseHandle(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDiagnosticsIsEnabled(TBHandle otbHandle, bool* pEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDiagnosticsSetEnabled(TBHandle otbHandle, bool enable, EnumStatusCode* pReturnValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDiagnosticsGetUpdateInterval(TBHandle otbHandle, OTUInt32* pUpdateInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDiagnosticsSetUpdateInterval(TBHandle otbHandle, OTUInt32 updateInterval, EnumStatusCode* pReturnValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDiagnosticsSetUpdateIntervalWritable(TBHandle otbHandle, bool writable);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class UserAuthenticationToken
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenSetUsernameToken(TBHandle otbHandle,
			UserNameIdentityTokenStruct* pUsernameToken, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenGetUsernameToken(TBHandle otbHandle, UserNameIdentityTokenStruct* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenGetIssuedToken(TBHandle otbHandle, IssuedIdentityTokenStruct* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenSetIssuedToken(TBHandle otbHandle,
			IssuedIdentityTokenStruct* pIssuedToken, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenGetX509Token(TBHandle otbHandle, X509IdentityTokenStruct* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenSetX509Token(TBHandle otbHandle,
			X509IdentityTokenStruct* pX509Token, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserAuthenticationTokenSetAnonymousToken(TBHandle otbHandle, EnumStatusCode* __pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class FilterOperand
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBFilterOperandSetLiteralOperand(TBHandle otbHandle,
			LiteralOperandStruct* pOperand, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBFilterOperandSetElementOperand(TBHandle otbHandle,
			ElementOperandStruct* pOperand, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBFilterOperandSetAttributeOperand(TBHandle otbHandle,
			AttributeOperandStruct* pOperand, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBFilterOperandSetSimpleAttributeOperand(TBHandle otbHandle,
			SimpleAttributeOperandStruct* pOperand, EnumStatusCode* __pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class LiteralOperand
	////////////////////////////////////////////////////////////////////////////////

	void* OTAPI_CALL OTBLiteralOperand_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AttributeOperand
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTEndpointDescription_AddUserIdentityToken(TBHandle handle, const UserTokenPolicyStruct* pUserIdentityToken);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseResult_AddReference(TBHandle handle, const ReferenceDescriptionStruct* pReference);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePath_AddElement(TBHandle handle, const RelativePathElementStruct* pElement);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathResult_AddTarget(TBHandle handle, const BrowsePathTargetStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodRequest_AddInputArgument(TBHandle handle, const ValueStruct* pInputArgument);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodResult_AddOutputArgument(TBHandle handle, const ValueStruct* pOutputArgument);
#if TB5_FILTER
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleAttributeOperand_AddBrowsePath(TBHandle handle, const QualifiedNameStruct* pBrowsePath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilter_AddElement(TBHandle handle, const ContentFilterElementStruct* pElement);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElement_AddFilterOperand(TBHandle handle, const FilterOperandStruct* pFilterOperand);
#endif
#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFilter_AddSelectClause(TBHandle handle, const SimpleAttributeOperandStruct* pSelectClause);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFieldList_AddEventField(TBHandle handle, const ValueStruct* pEventField);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetEventIdVar(TBHandle otbHandle, TBHandle* pEventIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetEventId(TBHandle otbHandle, OTUInt32* eventIdSize, unsigned char** eventIdValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetEventTypeVar(TBHandle otbHandle, TBHandle* pEventTypeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetEventType(TBHandle otbHandle, NodeIdStruct* eventType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSourceNodeVar(TBHandle otbHandle, TBHandle* pSourceNodeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSourceNode(TBHandle otbHandle, NodeIdStruct* sourceNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSourceNameVar(TBHandle otbHandle, TBHandle* pSourceNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSourceName(TBHandle otbHandle, TCHAR** sourceName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetTimeVar(TBHandle otbHandle, TBHandle* pTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetTime(TBHandle otbHandle, DateTimeStruct* time);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetReceiveTimeVar(TBHandle otbHandle, TBHandle* pReceiveTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetReceiveTime(TBHandle otbHandle, DateTimeStruct* receiveTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetLocalTimeVar(TBHandle otbHandle, TBHandle* pLocalTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetLocalTime(TBHandle otbHandle, TimeZoneStruct* localTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetMessageVar(TBHandle otbHandle, TBHandle* pMessageHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetMessage(TBHandle otbHandle, LocalizedTextStruct* message);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSeverityVar(TBHandle otbHandle, TBHandle* pSeverityHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSeverity(TBHandle otbHandle, unsigned short* severity);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetEnabledStateVar(TBHandle otbHandle, TBHandle* pEnabledStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetEnabledState(TBHandle otbHandle, LocalizedTextStruct* enabledState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetBranchIdVar(TBHandle otbHandle, TBHandle* pBranchIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetBranchId(TBHandle otbHandle, NodeIdStruct* branchId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetRetainVar(TBHandle otbHandle, TBHandle* pRetainHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetRetain(TBHandle otbHandle, bool* retain);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetQualityVar(TBHandle otbHandle, TBHandle* pQualityHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetQuality(TBHandle otbHandle, EnumStatusCode* quality);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetLastSeverityVar(TBHandle otbHandle, TBHandle* pLastSeverityHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetLastSeverity(TBHandle otbHandle, unsigned short* lastSeverity);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetCommentVar(TBHandle otbHandle, TBHandle* pCommentHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetComment(TBHandle otbHandle, LocalizedTextStruct* comment);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetClientUserIdVar(TBHandle otbHandle, TBHandle* pClientUserIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetClientUserId(TBHandle otbHandle, TCHAR** clientUserId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetEnable(TBHandle otbHandle, TBHandle* pEnableHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetDisable(TBHandle otbHandle, TBHandle* pDisableHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetConditionRefresh(TBHandle otbHandle, TBHandle* pConditionRefreshHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetAddComment(TBHandle otbHandle, TBHandle* pAddCommentHandle);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineGetCurrentStateVar(TBHandle otbHandle, TBHandle* pCurrentStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineGetCurrentState(TBHandle otbHandle, LocalizedTextStruct* currentState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineGetLastTransitionVar(TBHandle otbHandle, TBHandle* pLastTransitionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineGetLastTransition(TBHandle otbHandle, LocalizedTextStruct* lastTransition);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetIdVar(TBHandle otbHandle, TBHandle* pIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetId(TBHandle otbHandle, ValueStruct* id);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetNameVar(TBHandle otbHandle, TBHandle* pNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetName(TBHandle otbHandle, QualifiedNameStruct* name);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetNumberVar(TBHandle otbHandle, TBHandle* pNumberHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetNumber(TBHandle otbHandle, OTUInt32* number);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetEffectiveDisplayNameVar(TBHandle otbHandle, TBHandle* pEffectiveDisplayNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetEffectiveDisplayName(TBHandle otbHandle, LocalizedTextStruct* effectiveDisplayName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetIdVar(TBHandle otbHandle, TBHandle* pIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetId(TBHandle otbHandle, ValueStruct* id);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetNameVar(TBHandle otbHandle, TBHandle* pNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetName(TBHandle otbHandle, QualifiedNameStruct* name);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetNumberVar(TBHandle otbHandle, TBHandle* pNumberHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetNumber(TBHandle otbHandle, OTUInt32* number);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetTransitionTimeVar(TBHandle otbHandle, TBHandle* pTransitionTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetTransitionTime(TBHandle otbHandle, DateTimeStruct* transitionTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateMachineGetCurrentStateVar(TBHandle otbHandle, TBHandle* pCurrentStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateMachineGetCurrentState(TBHandle otbHandle, LocalizedTextStruct* currentState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateMachineGetLastTransitionVar(TBHandle otbHandle, TBHandle* pLastTransitionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateMachineGetLastTransition(TBHandle otbHandle, LocalizedTextStruct* lastTransition);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateVariableGetIdVar(TBHandle otbHandle, TBHandle* pIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateVariableGetId(TBHandle otbHandle, NodeIdStruct* id);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteTransitionVariableGetIdVar(TBHandle otbHandle, TBHandle* pIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteTransitionVariableGetId(TBHandle otbHandle, NodeIdStruct* id);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionVariableGetSourceTimestampVar(TBHandle otbHandle, TBHandle* pSourceTimestampHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionVariableGetSourceTimestamp(TBHandle otbHandle, DateTimeStruct* sourceTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetIdVar(TBHandle otbHandle, TBHandle* pIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetId(TBHandle otbHandle, bool* id);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetTransitionTimeVar(TBHandle otbHandle, TBHandle* pTransitionTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetTransitionTime(TBHandle otbHandle, DateTimeStruct* transitionTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetEffectiveTransitionTimeVar(TBHandle otbHandle, TBHandle* pEffectiveTransitionTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetEffectiveTransitionTime(TBHandle otbHandle, DateTimeStruct* effectiveTransitionTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetTrueStateVar(TBHandle otbHandle, TBHandle* pTrueStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetTrueState(TBHandle otbHandle, LocalizedTextStruct* trueState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetFalseStateVar(TBHandle otbHandle, TBHandle* pFalseStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetFalseState(TBHandle otbHandle, LocalizedTextStruct* falseState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetAckedStateVar(TBHandle otbHandle, TBHandle* pAckedStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetAckedState(TBHandle otbHandle, LocalizedTextStruct* ackedState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetConfirmedStateVar(TBHandle otbHandle, TBHandle* pConfirmedStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetConfirmedState(TBHandle otbHandle, LocalizedTextStruct* confirmedState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetAcknowledge(TBHandle otbHandle, TBHandle* pAcknowledgeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetConfirm(TBHandle otbHandle, TBHandle* pConfirmHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetActiveStateVar(TBHandle otbHandle, TBHandle* pActiveStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetActiveState(TBHandle otbHandle, LocalizedTextStruct* activeState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetSuppressedOrShelvedVar(TBHandle otbHandle, TBHandle* pSuppressedOrShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetSuppressedOrShelved(TBHandle otbHandle, bool* suppressedOrShelved);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetSuppressedStateVar(TBHandle otbHandle, TBHandle* pSuppressedStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetSuppressedState(TBHandle otbHandle, LocalizedTextStruct* suppressedState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetMaxTimeShelvedVar(TBHandle otbHandle, TBHandle* pMaxTimeShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetMaxTimeShelved(TBHandle otbHandle, double* maxTimeShelved);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetShelvingState(TBHandle otbHandle, TBHandle* pShelvingStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetInputNodeVar(TBHandle otbHandle, TBHandle* pInputNodeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetInputNode(TBHandle otbHandle, NodeIdStruct* inputNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetAlarmCondition(TBHandle otbHandle, TBHandle* pAlarmCondition);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelveTimeVar(TBHandle otbHandle, TBHandle* pUnshelveTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelveTime(TBHandle otbHandle, double* unshelveTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelved(TBHandle otbHandle, TBHandle* pUnshelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetTimedShelved(TBHandle otbHandle, TBHandle* pTimedShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetOneShotShelved(TBHandle otbHandle, TBHandle* pOneShotShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelvedToTimedShelved(TBHandle otbHandle, TBHandle* pUnshelvedToTimedShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetTimedShelvedToUnshelved(TBHandle otbHandle, TBHandle* pTimedShelvedToUnshelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelvedToOneShotShelved(TBHandle otbHandle, TBHandle* pUnshelvedToOneShotShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetOneShotShelvedToUnshelved(TBHandle otbHandle, TBHandle* pOneShotShelvedToUnshelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetOneShotShelvedToTimedShelved(TBHandle otbHandle, TBHandle* pOneShotShelvedToTimedShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetTimedShelve(TBHandle otbHandle, TBHandle* pTimedShelveHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetOneShotShelve(TBHandle otbHandle, TBHandle* pOneShotShelveHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelve(TBHandle otbHandle, TBHandle* pUnshelveHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetTimedShelvedToOneShotShelved(TBHandle otbHandle, TBHandle* pTimedShelvedToOneShotShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateGetStateNumberVar(TBHandle otbHandle, TBHandle* pStateNumberHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateGetStateNumber(TBHandle otbHandle, OTUInt32* stateNumber);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionGetTransitionNumberVar(TBHandle otbHandle, TBHandle* pTransitionNumberHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionGetTransitionNumber(TBHandle otbHandle, OTUInt32* transitionNumber);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetHighHighLimitVar(TBHandle otbHandle, TBHandle* pHighHighLimitHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetHighHighLimit(TBHandle otbHandle, double* highHighLimit);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetHighLimitVar(TBHandle otbHandle, TBHandle* pHighLimitHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetHighLimit(TBHandle otbHandle, double* highLimit);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetLowLowLimitVar(TBHandle otbHandle, TBHandle* pLowLowLimitHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetLowLowLimit(TBHandle otbHandle, double* lowLowLimit);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetLowLimitVar(TBHandle otbHandle, TBHandle* pLowLimitHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetLowLimit(TBHandle otbHandle, double* lowLimit);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitAlarmGetLimitState(TBHandle otbHandle, TBHandle* pLimitStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetHighHigh(TBHandle otbHandle, TBHandle* pHighHighHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetHigh(TBHandle otbHandle, TBHandle* pHighHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetLow(TBHandle otbHandle, TBHandle* pLowHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetLowLow(TBHandle otbHandle, TBHandle* pLowLowHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetLowLowToLow(TBHandle otbHandle, TBHandle* pLowLowToLowHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetLowToLowLow(TBHandle otbHandle, TBHandle* pLowToLowLowHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetHighHighToHigh(TBHandle otbHandle, TBHandle* pHighHighToHighHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetHighToHighHigh(TBHandle otbHandle, TBHandle* pHighToHighHighHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSOffNormalAlarmGetNormalStateVar(TBHandle otbHandle, TBHandle* pNormalStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSOffNormalAlarmGetNormalState(TBHandle otbHandle, NodeIdStruct* normalState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetHighHighStateVar(TBHandle otbHandle, TBHandle* pHighHighStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetHighHighState(TBHandle otbHandle, LocalizedTextStruct* highHighState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetHighStateVar(TBHandle otbHandle, TBHandle* pHighStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetHighState(TBHandle otbHandle, LocalizedTextStruct* highState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetLowStateVar(TBHandle otbHandle, TBHandle* pLowStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetLowState(TBHandle otbHandle, LocalizedTextStruct* lowState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetLowLowStateVar(TBHandle otbHandle, TBHandle* pLowLowStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetLowLowState(TBHandle otbHandle, LocalizedTextStruct* lowLowState);

#if TB5_CLIENT
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetSubscription(TBHandle otbHandle, TBHandle* pSubscriptionHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTCMonitoredItemGetIndexRangeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetIndexRange(TBHandle otbHandle, const void* _IndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetAttributeId(TBHandle otbHandle, EnumAttributeId _AttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetMonitoringMode(TBHandle otbHandle, EnumMonitoringMode* pMonitoringMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetMonitoringMode(TBHandle otbHandle, EnumMonitoringMode _MonitoringMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetSamplingInterval(TBHandle otbHandle, double* pSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetSamplingInterval(TBHandle otbHandle, double _SamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetRevisedSamplingInterval(TBHandle otbHandle, double* pRevisedSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetQueueSize(TBHandle otbHandle, OTUInt32* pQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetQueueSize(TBHandle otbHandle, OTUInt32 _QueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetRevisedQueueSize(TBHandle otbHandle, OTUInt32* pRevisedQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetDiscardOldest(TBHandle otbHandle, bool* pDiscardOldest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetDiscardOldest(TBHandle otbHandle, bool _DiscardOldest);
	TBCORE_IF TBHandle OTAPI_CALL OTCMonitoredItemGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetNodeId(TBHandle otbHandle, void* nodeIdHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTCMonitoredItemGetFilterHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetFilter(TBHandle otbHandle, void* filterHandle);
#if TB5_ALARMS
	TBCORE_IF TBHandle OTAPI_CALL OTCMonitoredItemGetEventFilterHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetEventFilter(TBHandle otbHandle, void* eventFilterHandle);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetId(TBHandle otbHandle, OTUInt32* pMonitoredItemId);


	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetSubscriptions(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetUrl(TBHandle otbHandle, TCHAR** pUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetUrl(TBHandle otbHandle, const TCHAR* _Url);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetSessionTimeout(TBHandle otbHandle, double* pSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetSessionTimeout(TBHandle otbHandle, double _SessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetRevisedSessionTimeout(TBHandle otbHandle, double* pRevisedSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* pMessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode _MessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetSecurityPolicy(TBHandle otbHandle, TCHAR** pSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetSecurityPolicy(TBHandle otbHandle, const TCHAR* _SecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetUserAuthenticationInfo(TBHandle otbHandle, void* userAuthenticationInfo);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetUserIdentityToken(TBHandle otbHandle, UserIdentityTokenStruct* pUserIdentityToken);
	TBCORE_IF TBHandle OTAPI_CALL OTCSessionGetUserIdentityTokenHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetUserSecurityPolicy(TBHandle otbHandle, TCHAR** pSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetUserSecurityPolicy(TBHandle otbHandle, const TCHAR* _SecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionImpersonateDifferentUser(TBHandle otbHandle, UserIdentityTokenStruct* userIdentityHandle, const TCHAR* securityPolicy, OTUInt32 preferredLocaleCount, const TCHAR** preferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetName(TBHandle otbHandle, TCHAR** pName);
	TBCORE_IF NodeIdStruct* OTAPI_CALL OTCSessionGetSessionIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetName(TBHandle otbHandle, const TCHAR* _Name);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetServerCertificate(TBHandle otbHandle, OTUInt32* serverCertificateCount, unsigned char** pServerCertificate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetServerCertificate(TBHandle otbHandle, OTUInt32 ServerCertificateCount, const unsigned char* _ServerCertificate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetNetworkTimeout(TBHandle otbHandle, OTUInt32* pNetworkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetNetworkTimeout(TBHandle otbHandle, OTUInt32 _NetworkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetAutoReconnectInterval(TBHandle otbHandle, OTUInt32* pAutoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetAutoReconnectInterval(TBHandle otbHandle, OTUInt32 _AutoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32* pConnectionMonitoringInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32 _ConnectionMonitoringInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetPreferredLocales(TBHandle otbHandle, OTUInt32 preferredLocaleCount, const TCHAR** preferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetPreferredLocales(TBHandle otbHandle, OTUInt32 *pPreferredLocaleCount, TCHAR*** pppPreferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetNamespaceTable(TBHandle otbHandle, TBHandle* namespaceTableHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionUpdateNamespaceTable(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetDataTypeNodeIds(TBHandle otbHandle, size_t *pCount, NodeIdStruct** ppDataTypeIds);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetDataTypeDescription(TBHandle otbHandle, const NodeIdStruct* pDataTypeId, TBHandle* descriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 timeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 *pTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionCancel(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		OTUInt32 requestId,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pNoOfCancelledRequests,
		EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionRegisterNodes(TBHandle otbHandle,
		OTUInt32 diagnosticToReturn,
		OTUInt32 noOfNodeIds, const NodeIdStruct *pNodeIds,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		NodeIdStruct **ppNewNodeIds,
		EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionUnregisterNodes(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		OTUInt32 noOfNodeIds, const NodeIdStruct *pNodeIds,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetDiagnosticInfo(TBHandle otbHandle, OTUInt32* pConnectCount);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetSession(TBHandle otbHandle, TBHandle* pSessionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetPublishingInterval(TBHandle otbHandle, double* pPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetPublishingInterval(TBHandle otbHandle, double _PublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetRevisedPublishingInterval(TBHandle otbHandle, double* pRevisedPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetLifeTimeCount(TBHandle otbHandle, OTUInt32* pLifeTimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetLifeTimeCount(TBHandle otbHandle, OTUInt32 _LifeTimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetRevisedLifeTimeCount(TBHandle otbHandle, OTUInt32* pRevisedLifeTimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* pMaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32 _MaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetRevisedMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* pRevisedMaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32* pMaxNotificationsPerPublish);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32 _MaxNotificationsPerPublish);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetPublishingEnabled(TBHandle otbHandle, bool* pPublishingEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetPublishingEnabled(TBHandle otbHandle, bool _PublishingEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetPriority(TBHandle otbHandle, unsigned char* pPriority);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetPriority(TBHandle otbHandle, unsigned char _Priority);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetId(TBHandle otbHandle, OTUInt32* pId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetDiagnosticInformation(TBHandle otbHandle, OTUInt32* pNumberOfMonitoredItems, OTUInt32* pReceivedNotifications, OTUInt32* pReceviedDataChanges, OTUInt32* pReceivedEvents);


	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class MonitoredItem
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemConnect(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemDisconnect(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemIsConnected(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemAddItemsToReport(TBHandle otbHandle,
			OTUInt32 itemsToReportCount, TBHandle* itemsToReport, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemRemoveItemsToReport(TBHandle otbHandle,
			OTUInt32 itemsToReportCount, TBHandle* itemsToReport, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTCMonitoredItem_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Session
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionWrite(TBHandle otbHandle,
			OTUInt32 diagnosticsToReturn, unsigned writeValuesCount, WriteValueStruct* pWriteValues,
			TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics, unsigned* resultsCount, EnumStatusCode** enum_results, unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
			EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionWriteAsync(TBHandle otbHandle, void* requestHandle, unsigned writeValuesCount, WriteValueStruct* pWriteValues, EnumStatusCode* __pReturn, OTUInt32 requestId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionRead(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn, EnumTimestampsToReturn enum_returnTimestamps, unsigned nodesToReadCount, ReadValueIdStruct* pNodesToRead, double maxAge,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics, unsigned* valuesCount, DataValueStruct** pValues, unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionReadAsync(TBHandle otbHandle, void* requestHandle, EnumTimestampsToReturn enum_returnTimestamps, unsigned nodesToReadCount, ReadValueIdStruct* pNodesToRead, double maxAge, EnumStatusCode* __pReturn, OTUInt32 requestId);

#if TB5_HISTORY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadRaw(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enum_returnTimestamps,
		bool releaseContinuationPoints,
		ReadRawModifiedDetailsStruct *pHistoryReadRawModifiedDetails,
		unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* valuesCount, HistoryReadResultStruct** pValues,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadRawAsync(TBHandle otbHandle,
			void* requestHandle,
			EnumTimestampsToReturn enum_returnTimestamps,
			bool releaseContinuationPoints,
			ReadRawModifiedDetailsStruct *pHistoryReadRawModifiedDetails,
			unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
			EnumStatusCode* __pReturn,
			OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadProcessed(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enum_returnTimestamps, bool releaseContinuationPoints,
		ReadProcessedDetailsStruct *pHistoryReadProcessedDetails,
		unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* valuesCount, HistoryReadResultStruct** pValues,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadProcessedAsync(TBHandle otbHandle,
		void* requestHandle,
		EnumTimestampsToReturn enum_returnTimestamps,
		bool releaseContinuationPoints,
		ReadProcessedDetailsStruct *pHistoryReadProcessedDetails,
		unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		EnumStatusCode* __pReturn,
		OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadEvent(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enum_returnTimestamps,
		bool releaseContinuationPoints,
		const ReadEventDetailsStruct *pHistoryReadEventDetails,
		unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* valuesCount, HistoryReadResultStruct** pValues,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadEventAsync(TBHandle otbHandle,
		void* requestHandle,
		EnumTimestampsToReturn enum_returnTimestamps,
		bool releaseContinuationPoints,
		const ReadEventDetailsStruct *pHistoryReadEventDetails,
		unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		EnumStatusCode* __pReturn,
		OTUInt32 requestId);
#endif

#if TB5_QUERY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionQueryFirst(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		ViewDescriptionStruct* pView,
		OTUInt32 nodeTypesCount,
		NodeTypeDescriptionStruct* pNodeTypes,
		ContentFilterStruct* pFilter,
		OTUInt32 maxDataSetsToReturn,
		OTUInt32 maxReferencesToReturn,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pQueryDataSetsCount, QueryDataSetStruct** ppQueryDataSets,
		ByteStringStruct* pContinuationPoint,
		OTUInt32* pParsingResultsCount, ParsingResultStruct** ppParsingResults,
		ContentFilterResultStruct* pFilterResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionQueryFirstAsync(TBHandle otbHandle,
		void* requestHandle,
		ViewDescriptionStruct* pView,
		unsigned nodeTypesCount,
		NodeTypeDescriptionStruct* pNodeTypes,
		ContentFilterStruct* pFilter,
		unsigned maxDataSetsToReturn,
		unsigned maxReferencesToReturn,
		EnumStatusCode* __pReturn,
		OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionQueryNext(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		bool releaseContinuationPoint,
		ByteStringStruct* pContinuationPoint,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* pQueryDataSetsCount, QueryDataSetStruct** ppQueryDataSets,
		ByteStringStruct* pRevisedContinuationPoint,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionQueryNextAsync(TBHandle otbHandle,
		void* requestHandle,
		bool releaseContinuationPoint,
		ByteStringStruct* pContinuationPoint,
		EnumStatusCode* __pReturn,
		OTUInt32 requestId);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionAddSubscription(TBHandle otbHandle,
			TBHandle subscription, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionRemoveSubscription(TBHandle otbHandle,
			TBHandle subscription, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionBrowse(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		ViewDescriptionStruct* pViewDescription,
		unsigned browseDescriptionsCount, BrowseDescriptionStruct* pBrowseDescriptions,
		OTUInt32 maxReferencesPerNode,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* resultsCount, BrowseResultStruct** pResults,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionBrowseAsync(TBHandle otbHandle, void* requestHandle,
		ViewDescriptionStruct* pViewDescription,
		unsigned browseDescriptionsCount, BrowseDescriptionStruct* pBrowseDescriptions,
		OTUInt32 maxReferencesPerNode,
		OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetSecurityConfiguration(TBHandle otbHandle,
			EnumMessageSecurityMode enum_messageSecurityMode,
			const TCHAR* securityPolicy, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionBrowseNext(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		unsigned continuationPointsCount, const ByteStringStruct* continuationPoints,
		bool releaseContinuationPoints,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* resultsCount, BrowseResultStruct** pResults,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionBrowseNextAsync(TBHandle otbHandle, void* requestHandle,
		unsigned continuationPointsCount, const ByteStringStruct* continuationPoints,
		bool releaseContinuationPoints,
		OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionConnect(TBHandle otbHandle,
			bool deep, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionDisconnect(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionBrowseNode(TBHandle otbHandle,
		ViewDescriptionStruct* pViewDescription,
		BrowseDescriptionStruct* pBrowseDescription,
		unsigned* resultsCount, ReferenceDescriptionStruct** pResults,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionIsConnected(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionTranslateBrowsePathToNodeIds(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		unsigned browsePathCount, const TCHAR** browsePath,
		unsigned startingNodeCount, const TCHAR** startingNode,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* browsePathResultCount, BrowsePathResultStruct** pBrowsePathResult,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionTranslateBrowsePathToNodeIds2(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		OTUInt32 browsePathCount, const BrowsePathStruct** ppBrowsePath,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pBrowsePathResultCount, BrowsePathResultStruct** ppBrowsePathResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionCallMethods(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		unsigned methodCallRequestCount, CallMethodRequestStruct* pMethodCallRequest,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* methodCallResultCount, CallMethodResultStruct** pMethodCallResult,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionCallMethodsAsync(TBHandle otbHandle, void* requestHandle,
			OTUInt32 methodCallRequestCount, CallMethodRequestStruct* pMethodCallRequest,
			EnumStatusCode* __pReturn,
			OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionCallMethod(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		NodeIdStruct* pObjectId,
		NodeIdStruct* pMethodId,
		unsigned inputArgsCount, ValueStruct* pInputArgs,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* outputArgsCount, ValueStruct** pOutputArgs,
		unsigned* inputArgStatusCodesCount, EnumStatusCode** enum_inputArgStatusCodes,
		unsigned* inputArgDiagnosticInfosCount, DiagnosticInfoStruct** ppInputArgDiagnosticInfos,
		DiagnosticInfoStruct* pDiagnosticInfo,
		EnumStatusCode* enum_callResult, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTCSession_Internal_Construct(TBHandle apiHandle, bool addRef);


	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Client::RedundantSession
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTCRedundantSession_Internal_Construct(TBHandle apiHandle, bool addRef);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetUrls(TBHandle otbHandle, OTUInt32* pUrlCount, TCHAR*** ppSessionUrls);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetServerCertificates(TBHandle otbHandle, OTUInt32* pSize, ByteStringStruct** ppServerCertificates);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetServerInformation(TBHandle otbHandle, OTUInt32 serverCount, const TCHAR** pUrls, OTUInt32 serverCertificatesCount, const ByteStringStruct** pServerCertificates, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetSessionTimeout(TBHandle otbHandle, double* pSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetSessionTimeout(TBHandle otbHandle, double sessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetRevisedSessionTimeout(TBHandle otbHandle, double* pRevisedSessionTimeout, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* pMessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetSecurityPolicy(TBHandle otbHandle, TCHAR** pSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetSecurityConfiguration(TBHandle otbHandle, EnumMessageSecurityMode messageSecurityMode, const TCHAR* securityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetUserSecurityPolicy(TBHandle otbHandle, TCHAR** pUserSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetUserSecurityPolicy(TBHandle otbHandle, const TCHAR* securityPolicy);
	TBCORE_IF const UserIdentityTokenStruct* OTAPI_CALL OTCRedundantSessionGetUserIdentityTokenHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetUserIdentityToken(TBHandle otbHandle, const UserIdentityTokenStruct* pUserIdentityToken);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetSessionId(TBHandle otbHandle, NodeIdStruct* sessionIdHandle, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetName(TBHandle otbHandle, const TCHAR** pSessionName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetName(TBHandle otbHandle, const TCHAR* name);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetNetworkTimeout(TBHandle otbHandle, OTUInt32* pNetworkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetNetworkTimeout(TBHandle otbHandle, OTUInt32 networkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetAutoReconnectInterval(TBHandle otbHandle, OTUInt32* pAutoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetAutoReconnectInterval(TBHandle otbHandle, OTUInt32 autoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32* pConnectionMonitorInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32 connectionMonitoringInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetPreferredLocales(TBHandle otbHandle, OTUInt32 *pPreferredLocaleCount, TCHAR*** ppPreferredLocaleStrings);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetPreferredLocales(TBHandle otbHandle, OTUInt32 preferredLocaleCount, const TCHAR** pPreferredLocaleStrings);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 timeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 *pTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetPrimaryIndex(TBHandle otbHandle, OTUInt32* pPrimaryIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetRedundancyMode(TBHandle otbHandle, EnumRedundancySupport* pRedundancyMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetRedundancyMode(TBHandle otbHandle, EnumRedundancySupport redundancyMode);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionConnect(TBHandle otbHandle, bool deep, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionDisconnect(TBHandle otbHandle, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionIsConnected(TBHandle otbHandle, bool* pConnected, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionImpersonateDifferentUser(TBHandle otbHandle, const UserIdentityTokenStruct* pUserAuthenticationToken,
		const TCHAR* userSecurityPolicy, OTUInt32 preferredLocaleCount, const TCHAR **preferredLocaleStrings, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetSubscriptions(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** ppSubscriptions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionAddSubscription(TBHandle otbHandle, TBHandle pSubscription, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionRemoveSubscription(TBHandle otbHandle, TBHandle pSubscription, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetNamespaceTable(TBHandle otbHandle, TBHandle* pNamespaceTable, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionUpdateNamespaceTable(TBHandle otbHandle, OTUInt32 redundantServerIndex, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetDataTypeDescription(TBHandle otbHandle, const NodeIdStruct* pDataTypeId, TBHandle* pDescriptionHandle, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSwitchover(TBHandle otbHandle, void* requestHandle, OTUInt32 primaryIndex, EnumStatusCode* pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionWrite(
		TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 nodesToWriteCount, WriteValueStruct* pNodesToWrite,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pResultsCount, EnumStatusCode** ppEnumResults,
		OTUInt32* pDiagnosticInfoCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionWriteAsync(
		TBHandle otbHandle, void* requestHandle, OTUInt32 writeValuesCount,
		WriteValueStruct* pWriteValues,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionRead(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enumReturnTimestamps,
		OTUInt32 nodesToReadCount, ReadValueIdStruct* pNodesToRead,
		double maxAge,
		void* pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pValuesCount, DataValueStruct** ppValues,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionReadAsync(TBHandle otbHandle, void* requestHandle, EnumTimestampsToReturn enumReturnTimestamps,
		OTUInt32 nodesToReadCount, ReadValueIdStruct* pNodesToRead,
		double maxAge, OTUInt32 requestId, OTUInt32 redundantServerIndex, EnumStatusCode* pReturn);
#if TB5_HISTORY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadRaw(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		ReadRawModifiedDetailsStruct *pHistoryReadRawModifiedDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		void* pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pValuesCount, HistoryReadResultStruct** ppValues,
		OTUInt32* pDiagnisticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadRawAsync(TBHandle otbHandle, void* requestHandle,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		ReadRawModifiedDetailsStruct *pHistoryReadRawModifiedDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadProcessed(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		ReadProcessedDetailsStruct *pHistoryReadProcessedDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pValuesCount, HistoryReadResultStruct** ppValues,
		OTUInt32* pDiagnisticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadProcessedAsync(TBHandle otbHandle, void* requestHandle,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		ReadProcessedDetailsStruct *pHistoryReadProcessedDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadEvent(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		const ReadEventDetailsStruct *pHistoryReadEventDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pValuesCount, HistoryReadResultStruct** ppValues,
		OTUInt32* pDiagnisticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadEventAsync(TBHandle otbHandle, void* requestHandle,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		const ReadEventDetailsStruct *pHistoryReadEventDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
#endif

#if TB5_QUERY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionQueryFirst(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		ViewDescriptionStruct* pView,
		OTUInt32 nodeTypesCount,
		NodeTypeDescriptionStruct* pNodeTypes,
		ContentFilterStruct* pFilter,
		OTUInt32 maxDataSetsToReturn,
		OTUInt32 maxReferencesToReturn,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pQueryDataSetsCount, QueryDataSetStruct** ppQueryDataSets,
		ByteStringStruct* pContinuationPoint,
		OTUInt32* pParsingResultsCount, ParsingResultStruct** ppParsingResults,
		ContentFilterResultStruct* pFilterResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionQueryFirstAsync(TBHandle otbHandle, void* requestHandle,
		ViewDescriptionStruct* pView,
		OTUInt32 nodeTypesCount,
		NodeTypeDescriptionStruct* pNodeTypes,
		ContentFilterStruct* pFilter,
		OTUInt32 maxDataSetsToReturn,
		OTUInt32 maxReferencesToReturn,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionQueryNext(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		bool releaseContinuationPoint,
		ByteStringStruct* pContinuationPoint,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pQueryDataSetsCount,
		QueryDataSetStruct** ppQueryDataSets,
		ByteStringStruct* pRevisedContinuationPoint,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionQueryNextAsync(TBHandle otbHandle, void* requestHandle,
		bool releaseContinuationPoint,
		ByteStringStruct* pContinuationPoint,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionBrowse(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		ViewDescriptionStruct* pViewDescription,
		OTUInt32 browseDescriptionsCount, BrowseDescriptionStruct* pBrowseDescriptions,
		OTUInt32 maxReferencesPerNode,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pResultsCount, BrowseResultStruct** ppResults,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionBrowseAsync(TBHandle otbHandle, void* requestHandle,
		ViewDescriptionStruct* pViewDescription,
		unsigned browseDescriptionsCount, BrowseDescriptionStruct* pBrowseDescriptions,
		OTUInt32 maxReferencesPerNode,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionBrowseNextAsync(TBHandle otbHandle, void* requestHandle,
		unsigned continuationPointsCount, const ByteStringStruct* continuationPoints,
		bool releaseContinuationPoints,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionBrowseNext(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 continuationPointCount, const ByteStringStruct* pContinuationPoint,
		bool releaseContinuationPoints,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pResultsCount, BrowseResultStruct** ppResults,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionBrowseNode(TBHandle otbHandle, ViewDescriptionStruct* pViewDescription,
		BrowseDescriptionStruct* pBrowseDescription,
		OTUInt32* pResultsCount, ReferenceDescriptionStruct** ppResults,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionTranslateBrowsePathToNodeIds(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 browsePathCount, const TCHAR** pBrowsePath,
		OTUInt32 startingNodeCount, const TCHAR** pStartingNodes,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pBrowsePathResultCount, BrowsePathResultStruct** ppBrowsePathResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionTranslateBrowsePathToNodeIds2(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		OTUInt32 browsePathCount, const BrowsePathStruct** ppBrowsePaths,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pBrowsePathResultCount, BrowsePathResultStruct** ppBrowsePathResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionCallMethods(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 methodCallRequestCount,
		CallMethodRequestStruct* pMethodCallRequest,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pMethodCallResultCount,
		CallMethodResultStruct** ppMethodCallResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionCallMethodsAsync(TBHandle otbHandle, void* requestHandle, OTUInt32 methodCallRequestCount, CallMethodRequestStruct* pMethodCallRequest,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionCallMethod(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		NodeIdStruct* pObjectId,
		NodeIdStruct* pMethodId,
		OTUInt32 inputArgsCount, ValueStruct* pInputArgs,
		OPTIONAL IN OUT TBHandle pStringTableHandle,
		OPTIONAL OUT DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pOutputArgsCount, ValueStruct** ppOutputArgs,
		OTUInt32* pInputArgStatusCodesCount, EnumStatusCode** ppEnumInputArgStatusCodes,
		OTUInt32* pInputArgumentDiagnosticInfosCount, OPTIONAL OUT DiagnosticInfoStruct** ppInputArgumentDiagnosticInfos,
		OPTIONAL OUT DiagnosticInfoStruct* pDiagnosticInfo,
		EnumStatusCode* pEnumCallResult,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionCancel(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 requestId,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pNoOfCancelledRequests,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionRegisterNodes(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 noOfNodeIds, const NodeIdStruct *pNodeIds,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		NodeIdStruct **ppNewNodeIds,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionUnregisterNodes(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 noOfNodeIds, const NodeIdStruct *pNodeIds,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Subscription
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetMonitoredItems(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionRemoveAllMonitoredItems(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionConnectMonitoredItems(TBHandle otbHandle, OTUInt32 itemsToConnectCount, TBHandle* itemsToConnect, EnumStatusCode** ppMIConnectResults);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionConnect(TBHandle otbHandle,
			bool deep, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionDisconnect(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionAddMonitoredItems(TBHandle otbHandle,
			unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionRemoveMonitoredItems(TBHandle otbHandle,
			unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionUpdateMonitoredItems(TBHandle otbHandle,
			unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionUpdateChangedMonitoredItems(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionEnablePublishing(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionDisablePublishing(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionUpdate(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionIsConnected(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetAllMonitoredItemsMonitoringMode(TBHandle otbHandle,
			EnumMonitoringMode enum_eMonitoringMode, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetMonitoredItemsMonitoringMode(TBHandle otbHandle,
			unsigned monitoredItemsCount, TBHandle* monitoredItems,
			EnumMonitoringMode enum_eMonitoringMode, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionEnableRepublish(TBHandle otbHandle, bool bEnable);

	TBCORE_IF void* OTAPI_CALL OTCSubscription_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class RedundantSubscription
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetMonitoredItems(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionRemoveAllMonitoredItems(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionConnectMonitoredItems(TBHandle otbHandle, 
		OTUInt32 itemsToConnectCount, TBHandle* itemsToConnect, EnumStatusCode** ppMIConnectResults);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionConnect(TBHandle otbHandle,
		bool deep, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionDisconnect(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionAddMonitoredItems(TBHandle otbHandle,
		unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionRemoveMonitoredItems(TBHandle otbHandle,
		unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionUpdateMonitoredItems(TBHandle otbHandle,
		unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionUpdateChangedMonitoredItems(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionEnablePublishing(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionDisablePublishing(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionUpdate(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionIsConnected(TBHandle otbHandle, bool* pIsConnected, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetAllMonitoredItemsMonitoringMode(TBHandle otbHandle,
		EnumMonitoringMode enum_eMonitoringMode, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetMonitoredItemsMonitoringMode(TBHandle otbHandle,
		unsigned monitoredItemsCount, TBHandle* monitoredItems,
		EnumMonitoringMode enum_eMonitoringMode, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionEnableRepublish(TBHandle otbHandle, bool bEnable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetSession(TBHandle otbHandle, TBHandle* pSessionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetPublishingInterval(TBHandle otbHandle, double* pPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetPublishingInterval(TBHandle otbHandle, double _PublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetRevisedPublishingInterval(TBHandle otbHandle, double* pRevisedPublishingInterval, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetLifeTimeCount(TBHandle otbHandle, OTUInt32* pLifeTimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetLifeTimeCount(TBHandle otbHandle, OTUInt32 _LifeTimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetRevisedLifeTimeCount(TBHandle otbHandle, OTUInt32* pRevisedLifeTimeCount, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* pMaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32 _MaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetRevisedMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* pRevisedMaxKeepAliveCount, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32* pMaxNotificationsPerPublish);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32 _MaxNotificationsPerPublish);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetPublishingEnabled(TBHandle otbHandle, bool* pPublishingEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetPublishingEnabled(TBHandle otbHandle, bool _PublishingEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetPriority(TBHandle otbHandle, unsigned char* pPriority);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetPriority(TBHandle otbHandle, unsigned char _Priority);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetId(TBHandle otbHandle, OTUInt32* pId, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetPrimaryServerIndex(TBHandle otbHandle, OTUInt32* primaryServerIndex);
	TBCORE_IF void* OTAPI_CALL OTCRedundantSubscription_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class RedundantMonitoredItem
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTCRedundantMonitoredItem_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemConnect(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemDisconnect(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemIsConnected(TBHandle otbHandle, bool* pIsConnected, OTUInt32 serverIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemAddItemsToReport(TBHandle otbHandle, OTUInt32 itemsToReportCount, TBHandle* itemsToReport);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemRemoveItemsToReport(TBHandle otbHandle, OTUInt32 itemsToReportCount, TBHandle* itemsToReport);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetSubscription(TBHandle otbHandle, TBHandle* pSubscriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetPrimaryServerIndex(TBHandle otbHandle, OTUInt32* primaryServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetId(TBHandle otbHandle, OTUInt32* pMonitoredItemId, OTUInt32 serverIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetNodeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetNodeId(TBHandle otbHandle, const NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetAttributeId(TBHandle otbHandle, EnumAttributeId attributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetIndexRange(TBHandle otbHandle, NumericRangeStruct* pIndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetIndexRange(TBHandle otbHandle, const NumericRangeStruct* pIndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetMonitoringMode(TBHandle otbHandle, EnumMonitoringMode* pMonitoringMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetMonitoringMode(TBHandle otbHandle, EnumMonitoringMode monitoringMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetSamplingInterval(TBHandle otbHandle, OTDouble* pSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetSamplingInterval(TBHandle otbHandle, OTDouble samplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetRevisedSamplingInterval(TBHandle otbHandle, OTDouble* pRevisedSamplingInterval, OTUInt32 serverIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetQueueSize(TBHandle otbHandle, OTUInt32* pQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetQueueSize(TBHandle otbHandle, OTUInt32 queueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetRevisedQueueSize(TBHandle otbHandle, OTUInt32* pRevisedQueueSize, OTUInt32 serverIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetDiscardOldest(TBHandle otbHandle, bool* pDiscardOldest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetDiscardOldest(TBHandle otbHandle, bool discardOldest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetFilter(TBHandle otbHandle, DataChangeFilterStruct* pFilter);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetFilter(TBHandle otbHandle, const DataChangeFilterStruct* pFilter);
#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetEventFilter(TBHandle otbHandle, EventFilterStruct* pFilter);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetEventFilter(TBHandle otbHandle, const EventFilterStruct* pFilter);
#endif
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BaseNode
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetUserData(TBHandle otbHandle, void** pUserData);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetUserData(TBHandle otbHandle, void* _UserData);
	TBCORE_IF TBHandle OTAPI_CALL OTSBaseNodeGetBrowseNameHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetBrowseName(TBHandle otbHandle, const QualifiedNameStruct* browseNameHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSBaseNodeGetDisplayNameHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetDisplayName(TBHandle otbHandle, const LocalizedTextStruct* displayNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetNodeClass(TBHandle otbHandle, EnumNodeClass* pNodeClass);
	TBCORE_IF TBHandle OTAPI_CALL OTSBaseNodeGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetNodeId(TBHandle otbHandle, const NodeIdStruct* nodeIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetWriteMask(TBHandle otbHandle, OTUInt32* pWriteMask);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetWriteMask(TBHandle otbHandle, OTUInt32 _WriteMask);
	TBCORE_IF TBHandle OTAPI_CALL OTSBaseNodeGetDescriptionHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetDescription(TBHandle otbHandle, const LocalizedTextStruct* descriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetRoot(TBHandle otbHandle, TBHandle* pObjectHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetObjectsFolder(TBHandle otbHandle, TBHandle* pObjectHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetServerObject(TBHandle otbHandle, TBHandle* pObjectHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootValidate(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataRequestGetRequestState(TBHandle otbHandle, EnumRequestState* pRequestState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataRequestSetRequestState(TBHandle otbHandle, EnumRequestState _RequestState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataRequestGetUserGroupIndex(TBHandle otbHandle, OTUInt32* pUserGroupIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataRequestIsCancelled(TBHandle otbHandle, OTBoolean *result);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetSession(TBHandle otbHandle, TBHandle* pSessionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetClientRequestHandle(TBHandle otbHandle, OTUInt32* pClientHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetUserGroupIndex(TBHandle otbHandle, OTUInt32* pUserGroupIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetAuditEntryId(TBHandle otbHandle, TCHAR** pAuditEntryId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionIsCancelled(TBHandle otbHandle, OTBoolean *result);
	TBCORE_IF TBHandle OTAPI_CALL OTSVariableGetDataTypeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetDataType(TBHandle otbHandle, const NodeIdStruct* dataTypeHandle, bool validateDataTypeNode);
	TBCORE_IF TBHandle OTAPI_CALL OTSVariableGetVariableTypeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetVariableType(TBHandle otbHandle, void* variableTypeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetAccessLevel(TBHandle otbHandle, EnumAccessLevel* pAccessLevel);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetAccessLevel(TBHandle otbHandle, EnumAccessLevel _AccessLevel);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetIsHistorizing(TBHandle otbHandle, bool* pIsHistorizing);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetIsHistorizing(TBHandle otbHandle, bool _IsHistorizing);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetMinimumSamplingInterval(TBHandle otbHandle, double* pMinimumSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetMinimumSamplingInterval(TBHandle otbHandle, double minimumSamplingInterval);
	TBCORE_IF TBHandle OTAPI_CALL OTSVariableGetDataValueHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetDataValue(TBHandle otbHandle, const DataValueStruct* dataValueHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetDataValueWithChangedSemantics(TBHandle otbHandle, void* dataValueHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetValueRank(TBHandle otbHandle, OTInt32* pValueRank);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetValueRank(TBHandle otbHandle, OTInt32 _ValueRank);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetAccessGroupKey(TBHandle otbHandle, OTUInt32* pAccessGroupKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetAccessGroupKey(TBHandle otbHandle, OTUInt32 _AccessGroupKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetArrayDimensions(TBHandle otbHandle, unsigned* arrayDimensionsCount, OTUInt32** pArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetArrayDimensions(TBHandle otbHandle, unsigned ArrayDimensionsCount, OTUInt32* _ArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetDataValueChangeCallbackEnabled(TBHandle otbHandle, bool enabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSObjectGetEventNotifier(TBHandle otbHandle, EnumEventNotifier* pEventNotifier);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSObjectSetEventNotifier(TBHandle otbHandle, EnumEventNotifier _EventNotifier);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodGetExecutable(TBHandle otbHandle, bool* pExecutable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodSetExecutable(TBHandle otbHandle, bool _Executable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodGetAccessGroupKey(TBHandle otbHandle, OTUInt32* pAccessGroupKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodSetAccessGroupKey(TBHandle otbHandle, OTUInt32 _AccessGroupKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSObjectTypeGetIsAbstract(TBHandle otbHandle, bool* pIsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSObjectTypeSetIsAbstract(TBHandle otbHandle, bool _IsAbstract);
	TBCORE_IF TBHandle OTAPI_CALL OTSReferenceTypeGetInverseNameHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceTypeSetInverseName(TBHandle otbHandle, const LocalizedTextStruct* inverseNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceTypeGetIsAbstract(TBHandle otbHandle, bool* pIsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceTypeSetIsAbstract(TBHandle otbHandle, bool _IsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceTypeGetIsSymmetric(TBHandle otbHandle, bool* pIsSymmetric);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceTypeSetIsSymmetric(TBHandle otbHandle, bool _IsSymmetric);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTypeGetIsAbstract(TBHandle otbHandle, bool* pIsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTypeSetIsAbstract(TBHandle otbHandle, bool _IsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeGetIsAbstract(TBHandle otbHandle, bool* pIsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeSetIsAbstract(TBHandle otbHandle, bool _IsAbstract);
	TBCORE_IF TBHandle OTAPI_CALL OTSVariableTypeGetDataValueHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeSetDataValue(TBHandle otbHandle, const DataValueStruct* dataValueHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeGetValueRank(TBHandle otbHandle, OTInt32* pValueRank);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeSetValueRank(TBHandle otbHandle, OTInt32 _ValueRank);
	TBCORE_IF TBHandle OTAPI_CALL OTSVariableTypeGetDataTypeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeSetDataType(TBHandle otbHandle, const NodeIdStruct* dataTypeHandle, bool validateDataTypeNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeGetArrayDimensions(TBHandle otbHandle, unsigned* arrayDimensionsCount, OTUInt32** pArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeSetArrayDimensions(TBHandle otbHandle, unsigned ArrayDimensionsCount, OTUInt32* _ArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSViewGetEventNotifier(TBHandle otbHandle, EnumEventNotifier* pEventNotifier);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSViewSetEventNotifier(TBHandle otbHandle, EnumEventNotifier _EventNotifier);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSViewGetContainsNoLoops(TBHandle otbHandle, OTBoolean* pContainsNoLoops);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSViewSetContainsNoLoops(TBHandle otbHandle, OTBoolean _ContainsNoLoops);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetUrl(TBHandle otbHandle, TCHAR** pUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetUrl(TBHandle otbHandle, const TCHAR* _Url);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetIsOpen(TBHandle otbHandle, bool* pIsOpen);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetUserCertificateRevocationListLocation(TBHandle otbHandle, TCHAR** pUserCertificateRevocationListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetUserCertificateRevocationListLocation(TBHandle otbHandle, const TCHAR* _UserCertificateRevocationListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetUserCertificateTrustListLocation(TBHandle otbHandle, TCHAR** pUserCertificateTrustListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetUserCertificateTrustListLocation(TBHandle otbHandle, const TCHAR* _UserCertificateTrustListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetUserCertificateIssuerListLocation(TBHandle otbHandle, TCHAR** pUserCertificateIssuerListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetUserCertificateIssuerListLocation(TBHandle otbHandle, const TCHAR* _UserCertificateIssuerListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetNode(TBHandle otbHandle, TBHandle* pBaseNodeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetSubscription(TBHandle otbHandle, TBHandle* pSubscriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pTimestampsToReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetMonitoringMode(TBHandle otbHandle, EnumMonitoringMode* pMonitoringMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetSamplingInterval(TBHandle otbHandle, double* pSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemSetSamplingInterval(TBHandle otbHandle, double _SamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetDiscardOldest(TBHandle otbHandle, bool* pDiscardOldest);
#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemReportEventByBaseEvent(TBHandle otbHandle, TBHandle eventHandle, bool evaluateWhereClause);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemReportEventByBaseEventNotification(TBHandle otbHandle, TBHandle eventHandle, bool evaluateWhereClause);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemReportEventByFields(TBHandle otbHandle, TBHandle eventFieldsHandle);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemReportDataChange(TBHandle otbHandle, const DataValueStruct* pValue, bool evaluateFilters);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetQueueSize(TBHandle otbHandle, OTUInt32* pQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemSetQueueSize(TBHandle otbHandle, OTUInt32 _QueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetId(TBHandle otbHandle, OTUInt32* pMonitoredItemId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetTriggeredMonitoredItems(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF TBHandle OTAPI_CALL OTSMonitoredItemGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSMonitoredItemGetFilterHandle(TBHandle otbHandle);
#if TB5_ALARMS
	TBCORE_IF TBHandle OTAPI_CALL OTSMonitoredItemGetEventFilterHandle(TBHandle otbHandle);
#endif
	TBCORE_IF TBHandle OTAPI_CALL OTSMonitoredItemGetIndexRangeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetPublishingInterval(TBHandle otbHandle, double* pPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionSetPublishingInterval(TBHandle otbHandle, double _PublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetLifetimeCount(TBHandle otbHandle, OTUInt32* pLifetimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionSetLifetimeCount(TBHandle otbHandle, OTUInt32 _LifetimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* pMaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionSetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32 _MaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32* pMaxNotificationsPerPublish);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetPublishingEnabled(TBHandle otbHandle, bool* pPublishingEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetPriority(TBHandle otbHandle, unsigned char* pPriority);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetId(TBHandle otbHandle, OTUInt32* pId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetSession(TBHandle otbHandle, TBHandle* pSessionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetMonitoredItems(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetDiagnosticInformation(TBHandle otbHandle, OTUInt32* pNumberOfMonitoredItems);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionEnableClientHandleValidation(TBHandle otbHandle, bool enableCheck);

	TBCORE_IF TBHandle OTAPI_CALL OTSReadRequestGetValueIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSReadRequestGetDataValueHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSReadRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadRequestSetDataValue(TBHandle otbHandle, void* dataValueHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadRequestGetNode(TBHandle otbHandle, TBHandle* pBaseNodeHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSWriteRequestGetWriteValueHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSWriteRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSWriteRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSWriteRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSWriteRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode _StatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSWriteRequestGetNode(TBHandle otbHandle, TBHandle* pBaseNodeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadTransactionGetMaxAge(TBHandle otbHandle, double* pMaxAge);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadTransactionGetTimestampToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pTimestampToReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseTransactionGetRequests(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseTransactionGetViewDescription(TBHandle otbHandle, ViewDescriptionStruct* pViewDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseTransactionGetRequestedMaxReferencesPerNode(TBHandle otbHandle, OTUInt32* maxReferencesPerNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetNodeIdToBrowse(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetNodeToBrowse(TBHandle otbHandle, TBHandle* pNodeToBrowse);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetBrowseDirection(TBHandle otbHandle, EnumBrowseDirection* direction);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetReferenceTypeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetIncludeSubtypes(TBHandle otbHandle, bool* includeSubtypes);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetNodeClassMask(TBHandle otbHandle, EnumNodeClass* pNodeClassMask);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetResultMask(TBHandle otbHandle, EnumResultMask* pResultMask);

	TBCORE_IF void* OTAPI_CALL OTSReadTransaction_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetSubscriptions(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetUserGroupIndex(TBHandle otbHandle, OTUInt32* pUserGroupIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* pMessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetSecurityPolicy(TBHandle otbHandle, TCHAR** pSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetPreferredLocales(TBHandle otbHandle, OTUInt32 *pPreferredLocaleCount, TCHAR*** pppPreferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionUserClientId(TBHandle otbHandle, TCHAR** pUserClientId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetName(TBHandle otbHandle, TCHAR** pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetClientPeerInfo(TBHandle otbHandle, TCHAR** pPeerInfo);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetId(TBHandle otbHandle, NodeIdStruct* pId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetTimeout(TBHandle otbHandle, double *pTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionSetTimeout(TBHandle otbHandle, double timeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoringChangeGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoringChangeGetMinimumSamplingInterval(TBHandle otbHandle, double* pMinimumSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoringChangeGetPreviousState(TBHandle otbHandle, EnumMonitoringState* pPreviousState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoringChangeGetCurrentState(TBHandle otbHandle, EnumMonitoringState* pCurrentState);
	TBCORE_IF TBHandle OTAPI_CALL OTSReferenceIteratorGetReferenceDescriptionHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSMethodCallRequestGetObjectIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSMethodCallRequestGetMethodIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSMethodCallRequestGetInputArgumentsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestSetOutputArguments(TBHandle otbHandle, OTUInt32 argumentCount, void* outputArgumentsHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode _StatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestSetInputReturns(TBHandle otbHandle, unsigned InputReturnsCount, EnumStatusCode* _InputReturns);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestSetInputArgumentDiagnosticInfos(TBHandle otbHandle, OTUInt32 diagnosticInfosCount, void* diagnosticInfosHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSMethodCallRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BaseNode
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeCreateVariableInstance(const NodeIdStruct* pNodeId, const NodeIdStruct* pTypeDefinitionId,
		TBHandle* hCreatedNode, bool allowNullTypeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeCreateObjectInstance(const NodeIdStruct* pTypeDefinitionId,
		TBHandle* hCreatedNode, bool allowNullTypeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeCreateMethodInstance(const NodeIdStruct* pNodeId,
		TBHandle* hCreatedNode);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeAddReference(TBHandle otbHandle,
			NodeIdStruct* pReferenceId,
			TBHandle TargetNode, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeAddReferenceEx(TBHandle otbHandle,
		NodeIdStruct* pReferenceId,
		TBHandle TargetNode,
		bool suppressErrorOnDuplicateReference, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeRemoveReferenceTo(TBHandle otbHandle,
			TBHandle TargetNode,
			NodeIdStruct* pReferenceId, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeInsert(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeRemove(TBHandle otbHandle,
			bool includeReferences, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeInsertTree(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeCopyTree(TBHandle otbHandle,
			TBHandle* copiedTreeHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeCopyAttributeValues(TBHandle otbHandle,
			TBHandle targetNodeHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeRemoveReferencesTo(TBHandle otbHandle,
			TBHandle TargetNode, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetReferenceIterator(TBHandle otbHandle,
			EnumBrowseDirection enum_browseDir,
			NodeIdStruct* pPReferenceId,
			bool includeSubtypes,
			EnumNodeClass nodeClassMask,
			EnumResultMask resultMask, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeFindNode(TBHandle otbHandle,
		EnumBrowseDirection browseDirection,
		const NodeIdStruct* pReferenceId,
		bool includeSubtypes,
		const QualifiedNameStruct* pBrowseName , TBHandle** ppNodes, size_t* pNodeCount);

#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeReportEvent(TBHandle otbHandle,
			TBHandle notification, EnumStatusCode* __pReturn);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetAttribute(TBHandle otbHandle,
			EnumAttributeId enum_attributeId,
			DataValueStruct* pAttributeValue, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeHasAttribute(TBHandle otbHandle,
			EnumAttributeId enum_attributeId, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetAttribute(TBHandle otbHandle,
			EnumAttributeId enum_attributeId,
			DataValueStruct* pAttributeValue,
			bool bypassWriteMask, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeInit(TBHandle otbHandle,
			NodeIdStruct* pTypeId, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeClear(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetMethod(TBHandle otbHandle,
			const TCHAR* propertyName, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetMethodByBrowsePath(TBHandle otbHandle,
			const QualifiedNameStruct** browsePathElements, OTUInt32 browsePathElementsCount, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetVariable(TBHandle otbHandle,
			const TCHAR* propertyName, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetVariableByBrowsePath(TBHandle otbHandle,
			const QualifiedNameStruct** browsePathElements, OTUInt32 browsePathElementsCount, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetQualifiedVariable(TBHandle otbHandle,
			const QualifiedNameStruct * pPropertyName, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetPropertyValue(TBHandle otbHandle,
			const TCHAR* propertyName,
			DataValueStruct* pValue, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetPropertyValueByQualifiedName(TBHandle otbHandle,
		const QualifiedNameStruct* pBrowseName, DataValueStruct* pValue, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetObject(TBHandle otbHandle,
			const TCHAR* objectName, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetObjectByBrowsePath(TBHandle otbHandle,
			const QualifiedNameStruct** browsePathElements, OTUInt32 browsePathElementsCount, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeIsOfUaType(TBHandle otbHandle,
			NodeIdStruct* pTypeId,
			bool includeSubtypes, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeIsInstanceOfUaType(TBHandle otbHandle,
			NodeIdStruct* pTypeId,
			bool includeSubtypes, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetTypeNode(TBHandle otbHandle,
			NodeIdStruct* pTypeId, EnumStatusCode* __pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AddressSpaceRoot
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetNamespaces(TBHandle otbHandle, TBHandle* namespaceStringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootAddNamespace(TBHandle otbHandle,
			const TCHAR* Url,
			unsigned short* index, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootModifyNamespace(TBHandle otbHandle,
		OTUInt16 index, 
		const TCHAR* Url,EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootUpdateNamespacesArrayNode(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetServerUris(TBHandle otbHandle, TBHandle* serverUriStringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootAddServerUri(TBHandle otbHandle, const TCHAR* serverUri, OTUInt16* pIndex, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootUpdateServerArrayNode(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetNode(TBHandle otbHandle,
		const NodeIdStruct* pNodeId, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetNodesFromNamespaces(TBHandle otbHandle,
		const TCHAR** pNamespaceUris, size_t namespaceUriCount, TBHandle** ppNodes, size_t* pNodeCount);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootCreateObject(TBHandle otbHandle,
			TBHandle typeNode, TBHandle* __pReturn);

#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetEvent(TBHandle otbHandle,
			const ByteStringStruct* eventId, TBHandle* __pReturn);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootBeginSemanticsChange(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootEndSemanticsChange(TBHandle otbHandle, const LocalizedTextStruct* pMessage, OTUInt16 severity);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootBeginModelChange(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootEndModelChange(TBHandle otbHandle, const LocalizedTextStruct* pMessage, OTUInt16 severity);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceSetVariableDataValues(TBHandle otbHandle, OTUInt32 nodeIdCount, void** nodeIdHandles, const DataValueStruct** dataValues, EnumStatusCode** ppsetVariableDataValuesResults);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceSetVariableDataValuesByVar(TBHandle otbHandle, OTUInt32 nodeIdCount, void** variables, const DataValueStruct** dataValues, EnumStatusCode** ppsetVariableDataValuesResults);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootSetStandardObjectValues(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetToolkitNamespaceIndex(TBHandle otbHandle, OTUInt16* pNamespaceId);

	TBCORE_IF void* OTAPI_CALL OTSAddressSpaceRootGetHandle(bool addRef);
	TBCORE_IF void OTAPI_CALL OTSAddressSpaceRootReleaseHandle(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootRemoveNodesWithoutChecking(TBHandle otbHandle, OTUInt32 nodeCount, TBHandle* pNodes);

	// Use these functions for testing purposes only
	TBCORE_IF void OTAPI_CALL OTSAddressSpaceRootCreate();
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootDestroy();

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DataRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataRequestComplete(TBHandle otbHandle, EnumStatusCode* __pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DataTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionComplete(TBHandle otbHandle,
			EnumStatusCode enum_requestStatus, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetStringTable(TBHandle otbHandle,
		TBHandle* stringTableHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionSetStringTable(TBHandle otbHandle,
		TBHandle stringTableHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetDiagnosticsToReturn(TBHandle otbHandle,
		OTUInt32* pDiagnosticsToReturn);
	TBCORE_IF TBHandle OTAPI_CALL OTSDataTransactionGetServiceDiagnosticsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionSetServiceDiagnostics(TBHandle otbHandle, void* serviceDiagnosticsHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Variable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetUserAccessLevel(TBHandle otbHandle,
			OTUInt32 userGroupIndex, EnumAccessLevel* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSVariable_Internal_Construct(TBHandle apiHandle, bool addRef, EnumApiClassType apiClass);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Object
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSObject_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Method
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodGetUserExecutable(TBHandle otbHandle,
			OTUInt32 userGroupIndex, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodExecuteRequest(TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSMethod_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ObjectType
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSObjectTypeGetBaseType(TBHandle otbHandle, TBHandle* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSObjectType_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ReferenceType
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSReferenceType_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DataType
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSDataType_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTypeGetDataTypeDescription(TBHandle otbHandle, TBHandle* dataTypeDescriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTypeSetDataTypeDescription(TBHandle otbHandle, TBHandle dataTypeDescriptionHandle, const NodeIdStruct* pDescriptionId, const NodeIdStruct* pEncodingId, const NodeIdStruct* pDictionaryId, const NodeIdStruct* pEnumValuesId, EnumStatusCode* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTypeRemoveDataTypeDescription(TBHandle otbHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class View
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSView_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class VariableType
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeGetBaseType(TBHandle otbHandle, TBHandle* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSVariableType_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Endpoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetSessions(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointOpen(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointClose(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointAddSecurityConfiguration(TBHandle otbHandle,
			EnumMessageSecurityMode enum_messageSecurityMode,
			const TCHAR* securityPolicy, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointAddUserTokenPolicy(TBHandle otbHandle,
			UserTokenPolicyStruct* pPolicy, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointIsRestrictedToSingleInterface(TBHandle otbHandle, bool* pIsRestricted);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetRestrictToSingleInterface(TBHandle otbHandle, bool restrictToSingleInterface, EnumStatusCode* pResult);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointValidateUserCertificate(TBHandle otbHandle, const ByteStringStruct* x509Certificate, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSEndpoint_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Subscription
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSSubscription_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ReadRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSReadRequest_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class WriteRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSWriteRequest_Internal_Construct(TBHandle apiHandle, bool addRef);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadRawRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestHasContinuationPoint(TBHandle otbHandle, bool* pHasContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestGetContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestCreateContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestSetContinuationPoint(TBHandle otbHandle, TBHandle pContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestDeleteContinuationPoint(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestGetNodeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestGetVariable(TBHandle otbHandle, TBHandle* ppVariable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestGetIndexRange(TBHandle otbHandle, NumericRangeStruct* pIndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestSetDataValues(TBHandle otbHandle, OTUInt32 dataValueCount, const DataValueStruct** ppDataValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);
	TBCORE_IF TBHandle OTAPI_CALL OTSHistoryReadRawRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadProcessedRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestHasContinuationPoint(TBHandle otbHandle, bool* pHasContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestCreateContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestSetContinuationPoint(TBHandle otbHandle, TBHandle pContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestDeleteContinuationPoint(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetNodeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetVariable(TBHandle otbHandle, TBHandle* ppVariable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetAggregateType(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetIndexRange(TBHandle otbHandle, NumericRangeStruct* pIndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestSetDataValues(TBHandle otbHandle, OTUInt32 dataValueCount, const DataValueStruct** ppDataValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);
	TBCORE_IF TBHandle OTAPI_CALL OTSHistoryReadProcessedRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BrowseBaseRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestSetReferences(TBHandle otbHandle, OTUInt32 referencesCount, const ReferenceDescriptionStruct** ppReferences);
	TBCORE_IF TBHandle OTAPI_CALL OTSBrowseBaseRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestHasContinuationPoint(TBHandle otbHandle, bool* pHasContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestGetContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestCreateContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestSetContinuationPoint(TBHandle otbHandle, TBHandle pContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestDeleteContinuationPoint(TBHandle otbHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class TranslateBrowsePathsToNodeIdsRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestGetStartingNodeId(TBHandle otbHandle, NodeIdStruct* pStartingNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestGetStartingNode(TBHandle otbHandle, TBHandle* pStartingNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestGetRelativePath(TBHandle otbHandle, RelativePathStruct* pRelativePath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestSetTargets(TBHandle otbHandle, OTUInt32 targetCount, const BrowsePathTargetStruct** ppTargets);
	TBCORE_IF TBHandle OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadEventRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestHasContinuationPoint(TBHandle otbHandle, bool* pHasContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestGetContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestCreateContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestSetContinuationPoint(TBHandle otbHandle, TBHandle pContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestDeleteContinuationPoint(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestGetNodeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestGetIndexRange(TBHandle otbHandle, NumericRangeStruct* pIndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestSetEvents(TBHandle otbHandle, OTUInt32 eventsCount, const HistoryEventFieldListStruct** ppEvents);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);
	TBCORE_IF TBHandle OTAPI_CALL OTSHistoryReadEventRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);
#endif
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ReadTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadTransactionGetRequests(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadTransactionUpdateTimeStamps(TBHandle otbHandle,
			DataValueStruct* pLocalValue,
			EnumAttributeId enum_attributeId, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSReadTransaction_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class WriteTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSWriteTransactionGetRequests(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSWriteTransaction_Internal_Construct(TBHandle apiHandle, bool addRef);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadRawTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionGetStartTime(TBHandle otbHandle, DateTimeStruct* pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionGetEndTime(TBHandle otbHandle, DateTimeStruct* pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionGetMaxNumberOfValuesPerNode(TBHandle otbHandle, OTUInt32* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionReturnBoundingValues(TBHandle otbHandle, bool* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadProcessedTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetStartTime(TBHandle otbHandle, DateTimeStruct* pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetEndTime(TBHandle otbHandle, DateTimeStruct* pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetProcessingInterval(TBHandle otbHandle, double* pProcessingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetAggregateConfiguration(TBHandle otbHandle, AggregateConfigurationStruct* pAggregateConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class CreateMonitoredItemRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemRequestGetMonitoredItem(TBHandle otbHandle, TBHandle* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode *pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class CreateMonitoredItemsTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemsTransactionGetSubscription(TBHandle otbHandle, TBHandle* pSubscriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemsTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemsTransactionSetServiceResult(TBHandle otbHandle, EnumStatusCode statusCode);


	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ModifyMonitoredItemRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSModifyMonitoredItemRequestGetMonitoredItem(TBHandle otbHandle, TBHandle* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSModifyMonitoredItemRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode *pStatusCode);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ModifyMonitoredItemsTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSModifyMonitoredItemsTransactionGetSubscription(TBHandle otbHandle, TBHandle* pSubscriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSModifyMonitoredItemsTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DeleteMonitoredItemRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDeleteMonitoredItemRequestGetMonitoredItem(TBHandle otbHandle, TBHandle* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDeleteMonitoredItemRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode *pStatusCode);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DeleteSubscriptionRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDeleteSubscriptionRequestGetSubscription(TBHandle otbHandle, TBHandle* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDeleteSubscriptionRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode *pStatusCode);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DeleteSessionRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDeleteSessionRequestGetSession(TBHandle otbHandle, TBHandle* pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BrowseNextTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseNextTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class TranslateBrowsePathsToNodeIdsTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadEventTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetStartTime(TBHandle otbHandle, DateTimeStruct* pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetEndTime(TBHandle otbHandle, DateTimeStruct* pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetMaxNumberOfValuesPerNode(TBHandle otbHandle, OTUInt32* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetFilter(TBHandle otbHandle, EventFilterStruct* pEventFilter, EnumStatusCode* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Session
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSSession_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class MonitoringChange
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSMonitoringChange_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ReferenceIterator
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceIteratorMoveNext(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceIteratorIsEnd(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSReferenceIterator_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class MethodCallRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSMethodCallRequest_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class MethodCallTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallTransactionGetRequests(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSMethodCallTransaction_Internal_Construct(TBHandle apiHandle, bool addRef);

#if TB5_ALARMS
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BaseEvent
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSBaseEvent_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Condition
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionEnable(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionDisable(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionAddBranch(TBHandle otbHandle,
		TBHandle branchHandle, NodeIdStruct* pBranchId, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetBranch(TBHandle otbHandle,
		const NodeIdStruct* pBranchId, TBHandle* pConditionBranchHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionDeleteBranch(TBHandle otbHandle,
		const NodeIdStruct* pBranchId, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetBranches(TBHandle otbHandle,
		OTUInt32* pBranchesCount, NodeIdStruct** ppBranchIds, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetTrunk(TBHandle otbHandle,
		TBHandle* pTrunkHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSCondition_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BaseEventNotification
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSBaseEventNotification_Internal_Construct(TBHandle apiHandle, bool addRef);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventNotificationInit(TBHandle otbHandle,
			const NodeIdStruct* pEventType, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventNotificationRemoveProperty(TBHandle otbHandle,
			const QualifiedNameStruct* pPropertyName, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventNotificationSetProperty(TBHandle otbHandle,
			const QualifiedNameStruct* pPropertyName,
			const ValueStruct* pProperty, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventNotificationGetProperty(TBHandle otbHandle,
			const QualifiedNameStruct* pPropertyName, ValueStruct* pValue, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSIBaseEventReport(TBHandle otbHandle, NodeIdStruct *reportingNode, EnumStatusCode* __pReturn);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class StateMachine
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineIsActive(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineDeactivate(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineActivate(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSStateMachine_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class StateVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableReset(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSStateVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class TransitionVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableReset(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSTransitionVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class FiniteStateMachine
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateMachineChangeState(TBHandle otbHandle,
			TBHandle target, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSFiniteStateMachine_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class FiniteStateVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSFiniteStateVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class FiniteTransitionVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSFiniteTransitionVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ConditionVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSConditionVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class TwoStateVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableSetCurrentState(TBHandle otbHandle,
			bool newState, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableActivate(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableDeactivate(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableIsActive(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSTwoStateVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

#if TB5_ALARMS
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AcknowledgeableCondition
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSAcknowledgeableCondition_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AlarmCondition
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionSuppress(TBHandle otbHandle,
			bool suppressed, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSAlarmCondition_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ShelvedStateMachine
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineShelve(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineTimeShelve(TBHandle otbHandle,
			double duration, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineUnshelve(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSShelvedStateMachine_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ConditionEnable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSConditionEnable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ConditionDisable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSConditionDisable_Internal_Construct(TBHandle apiHandle, bool addRef);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class State
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSState_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Transition
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSTransition_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class LimitAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSLimitAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ShelvedStateMachineTimedShelve
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSShelvedStateMachineTimedShelve_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ShelvedStateMachineOneShotShelve
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSShelvedStateMachineOneShotShelve_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ShelvedStateMachineUnshelve
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSShelvedStateMachineUnshelve_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ConditionAddComment
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSConditionAddComment_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AcknowledgeableConditionAcknowledge
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSAcknowledgeableConditionAcknowledge_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AcknowledgeableConditionConfirm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSAcknowledgeableConditionConfirm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ConditionRefresh
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSConditionRefresh_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ExclusiveLimitAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSExclusiveLimitAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ExclusiveLimitStateMachine
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSExclusiveLimitStateMachine_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ExclusiveLevelAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSExclusiveLevelAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ExclusiveDeviationAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveDeviationAlarmSetSetpointVar(TBHandle otbHandle,
			TBHandle setpoint, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveDeviationAlarmGetSetpointVar(TBHandle otbHandle, TBHandle* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSExclusiveDeviationAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ExclusiveRateOfChangeAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSExclusiveRateOfChangeAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DiscreteAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSDiscreteAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class OffNormalAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSOffNormalAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class TripAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSTripAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class NonExclusiveLimitAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSNonExclusiveLimitAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class NonExclusiveLevelAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSNonExclusiveLevelAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class NonExclusiveDeviationAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveDeviationAlarmSetSetpointVar(TBHandle otbHandle,
			TBHandle setpoint, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveDeviationAlarmGetSetpointVar(TBHandle otbHandle, TBHandle* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSNonExclusiveDeviationAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class NonExclusiveRateOfChangeAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSNonExclusiveRateOfChangeAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerContinuationPoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerContinuationPointGetType(TBHandle otbHandle, EnumContinuationPointType* pContinuationPointType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerContinuationPointSetContext(TBHandle otbHandle, const void* pContext, OTUInt32 contextLength, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerContinuationPointGetContext(TBHandle otbHandle, void** ppContext, OTUInt32* pContextLength);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerDictionaryVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSDictionaryVariable_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDictionaryVariableRegisterDictionary(TBHandle otbHandle, EnumStatusCode* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDictionaryVariableIsRegistered(TBHandle otbHandle, bool* pResult);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class GetMonitoredItems
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSGetMonitoredItems_Internal_Construct(TBHandle apiHandle, bool addRef);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerHistoryReadRawContinuationPoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetContextAsTimestamp(TBHandle otbHandle, DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointSetContextFromTimestamp(TBHandle otbHandle, const DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetContextAsByteString(TBHandle otbHandle, ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointSetContextFromByteString(TBHandle otbHandle, const ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetStartTimeHandle(TBHandle otbHandle, DateTimeStruct** pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetEndTimeHandle(TBHandle otbHandle, DateTimeStruct** pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetMaxNumberOfValuesPerNode(TBHandle otbHandle, OTUInt32* pMaxNumberOfValuesPerNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointReturnBoundingValues(TBHandle otbHandle, bool* pBoundingValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pTimestampsToReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerHistoryReadProcessedContinuationPoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetContextAsTimestamp(TBHandle otbHandle, DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointSetContextFromTimestamp(TBHandle otbHandle, const DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetContextAsByteString(TBHandle otbHandle, ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointSetContextFromByteString(TBHandle otbHandle, const ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetStartTimeHandle(TBHandle otbHandle, DateTimeStruct** pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetEndTimeHandle(TBHandle otbHandle, DateTimeStruct** pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetProcessingInterval(TBHandle otbHandle, double* pProcessingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetAggregateConfigurationHandle(TBHandle otbHandle, AggregateConfigurationStruct** ppAggregateConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetAggregateTypeHandle(TBHandle otbHandle, NodeIdStruct** ppAggregateType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pTimestampsToReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerHistoryReadEventContinuationPoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetContextAsTimestamp(TBHandle otbHandle, DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointSetContextFromTimestamp(TBHandle otbHandle, const DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetContextAsByteString(TBHandle otbHandle, ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointSetContextFromByteString(TBHandle otbHandle, const ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetStartTimeHandle(TBHandle otbHandle, DateTimeStruct** pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetEndTimeHandle(TBHandle otbHandle, DateTimeStruct** pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetMaxNumberOfValuesPerNode(TBHandle otbHandle, OTUInt32* pMaxNumberOfValuesPerNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetFilter(TBHandle otbHandle, EventFilterStruct* pEventFilter, EnumStatusCode* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pTimestampsToReturn);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerBrowseContinuationPoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointGetContextAsByteString(TBHandle otbHandle, ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointSetContextFromByteString(TBHandle otbHandle, const ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointGetView(TBHandle otbHandle, ViewDescriptionStruct* pView);
	TBCORE_IF OTUInt32 OTAPI_CALL OTSServerBrowseContinuationPointGetRequestedMaxReferencesPerNode(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointGetNodeIdToBrowse(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointGetNodeToBrowse(TBHandle otbHandle, TBHandle* pNodeHandle);
	TBCORE_IF EnumBrowseDirection OTAPI_CALL OTSServerBrowseContinuationPointGetBrowseDirection(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointGetReferenceTypeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF bool OTAPI_CALL OTSServerBrowseContinuationPointGetIncludeSubtypes(TBHandle otbHandle);
	TBCORE_IF EnumNodeClass OTAPI_CALL OTSServerBrowseContinuationPointGetNodeClassMask(TBHandle otbHandle);
	TBCORE_IF EnumResultMask OTAPI_CALL OTSServerBrowseContinuationPointGetResultMask(TBHandle otbHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ContentFilterResult
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterResultClear(ContentFilterResultStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTContentFilterResultCompare(const void* pSource, const void* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ContentFilterElementResult
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementResultClear(ContentFilterElementResultStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTContentFilterElementResultCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementResultGetStatusCode(TBHandle otbHandle, EnumStatusCode* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementResultSetStatusCode(TBHandle otbHandle, EnumStatusCode value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ServerDiagnosticsSummaryDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeClear(ServerDiagnosticsSummaryDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTServerDiagnosticsSummaryDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetServerViewCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetServerViewCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetCurrentSessionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetCurrentSessionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetCumulatedSessionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetCumulatedSessionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetSecurityRejectedSessionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetSecurityRejectedSessionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetRejectedSessionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetRejectedSessionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetSessionTimeoutCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetSessionTimeoutCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetSessionAbortCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetSessionAbortCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetCurrentSubscriptionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetCurrentSubscriptionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetCumulatedSubscriptionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetCumulatedSubscriptionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetPublishingIntervalCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetPublishingIntervalCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetSecurityRejectedRequestsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetSecurityRejectedRequestsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetRejectedRequestsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetRejectedRequestsCount(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SubscriptionDiagnosticsDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeClear(SubscriptionDiagnosticsDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSubscriptionDiagnosticsDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetSubscriptionId(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetSubscriptionId(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetPriority(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetPriority(TBHandle otbHandle, OTUInt8 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetPublishingInterval(TBHandle otbHandle, double* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetPublishingInterval(TBHandle otbHandle, double value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetMaxLifetimeCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetMaxLifetimeCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetPublishingEnabled(TBHandle otbHandle, bool* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetPublishingEnabled(TBHandle otbHandle, bool value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetModifyCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetModifyCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetEnableCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetEnableCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetDisableCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetDisableCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetRepublishRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetRepublishRequestCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetRepublishMessageRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetRepublishMessageRequestCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetRepublishMessageCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetRepublishMessageCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetTransferRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetTransferRequestCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetTransferredToAltClientCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetTransferredToAltClientCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetTransferredToSameClientCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetTransferredToSameClientCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetPublishRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetPublishRequestCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetDataChangeNotificationsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetDataChangeNotificationsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetEventNotificationsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetEventNotificationsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetNotificationsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetNotificationsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetLatePublishRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetLatePublishRequestCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetCurrentKeepAliveCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetCurrentKeepAliveCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetCurrentLifetimeCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetCurrentLifetimeCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetUnacknowledgedMessageCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetUnacknowledgedMessageCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetDiscardedMessageCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetDiscardedMessageCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetMonitoredItemCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetMonitoredItemCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetDisabledMonitoredItemCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetDisabledMonitoredItemCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetMonitoringQueueOverflowCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetMonitoringQueueOverflowCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetNextSequenceNumber(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetNextSequenceNumber(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetEventQueueOverFlowCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetEventQueueOverFlowCount(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SessionDiagnosticsDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeClear(SessionDiagnosticsDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSessionDiagnosticsDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetSessionName(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetSessionName(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetServerUri(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetServerUri(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetEndpointUrl(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetEndpointUrl(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetActualSessionTimeout(TBHandle otbHandle, double* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetActualSessionTimeout(TBHandle otbHandle, double value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetMaxResponseMessageSize(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetMaxResponseMessageSize(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetCurrentSubscriptionsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetCurrentSubscriptionsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetCurrentMonitoredItemsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetCurrentMonitoredItemsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetCurrentPublishRequestsInQueue(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetCurrentPublishRequestsInQueue(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetUnauthorizedRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetUnauthorizedRequestCount(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SessionSecurityDiagnosticsDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeClear(SessionSecurityDiagnosticsDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetClientUserIdOfSession(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetClientUserIdOfSession(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetAuthenticationMechanism(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetAuthenticationMechanism(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetEncoding(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetEncoding(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetTransportProtocol(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetTransportProtocol(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetSecurityPolicyUri(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetSecurityPolicyUri(TBHandle otbHandle, const TCHAR* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ServiceCounterDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeClear(ServiceCounterDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTServiceCounterDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeGetTotalCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeSetTotalCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeGetErrorCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeSetErrorCount(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SemanticChangeStructureDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSemanticChangeStructureDataTypeClear(SemanticChangeStructureDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSemanticChangeStructureDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSemanticChangeStructureDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSemanticChangeStructureDataTypeCompare(const void* pSource, const void* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ModelChangeStructureDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTModelChangeStructureDataTypeClear(ModelChangeStructureDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTModelChangeStructureDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTModelChangeStructureDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTModelChangeStructureDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTModelChangeStructureDataTypeGetVerb(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTModelChangeStructureDataTypeSetVerb(TBHandle otbHandle, OTUInt8 value);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct AggregateConfiguration (DataType)
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationClear(AggregateConfigurationStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTAggregateConfigurationCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationGetUseServerCapabilitiesDefaults(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSetUseServerCapabilitiesDefaults(TBHandle otbHandle, OTBoolean value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationGetTreatUncertainAsBad(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSetTreatUncertainAsBad(TBHandle otbHandle, OTBoolean value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationGetPercentDataBad(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSetPercentDataBad(TBHandle otbHandle, OTUInt8 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationGetPercentDataGood(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSetPercentDataGood(TBHandle otbHandle, OTUInt8 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationGetUseSlopedExtrapolation(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSetUseSlopedExtrapolation(TBHandle otbHandle, OTBoolean value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct AggregateConfiguration (ObjectType)
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTSAggregateConfiguration_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct HistoricalDataConfiguration
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTSHistoricalDataConfiguration_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoricalDataConfigurationGetAggregateConfiguration(TBHandle otbHandle, TBHandle* pAggregateConfigurationHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ReadProcessedDetails
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadProcessedDetailsClear(ReadProcessedDetailsStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadProcessedDetailsSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadProcessedDetailsCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTReadProcessedDetailsCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadProcessedDetailsGetProcessingInterval(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadProcessedDetailsSetProcessingInterval(TBHandle otbHandle, OTDouble value);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SignedSoftwareCertificate
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignedSoftwareCertificateClear(SignedSoftwareCertificateStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignedSoftwareCertificateSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignedSoftwareCertificateCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSignedSoftwareCertificateCompare(const void* pSource, const void* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct BuildInfo
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoClear(BuildInfoStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBuildInfoCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoGetProductUri(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSetProductUri(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoGetManufacturerName(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSetManufacturerName(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoGetProductName(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSetProductName(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoGetSoftwareVersion(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSetSoftwareVersion(TBHandle otbHandle, const TCHAR* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoGetBuildNumber(TBHandle otbHandle, TCHAR** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSetBuildNumber(TBHandle otbHandle, const TCHAR* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ServerStatusDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeClear(ServerStatusDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTServerStatusDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeGetState(TBHandle otbHandle, EnumServerState* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeSetState(TBHandle otbHandle, EnumServerState value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeGetSecondsTillShutdown(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeSetSecondsTillShutdown(TBHandle otbHandle, OTUInt32 value);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct AggregateFunction
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTSAggregateFunction_Internal_Construct(TBHandle apiHandle, bool addRef);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class StringTable
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTBStringTable_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableAppendEntry(TBHandle otbHandle, const TCHAR* pEntry, OTInt32* pIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableGetEntry(TBHandle otbHandle, OTInt32 index, TCHAR** ppEntry);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableGetIndex(TBHandle otbHandle, const TCHAR* pEntry, OTInt32* pIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableRemoveLastEntry(TBHandle otbHandle, OTInt32 lastEntryIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableGetSize(TBHandle otbHandle, OTUInt32* pSize);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DiagnosticInfo (DataType)
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoInitialize(DiagnosticInfoStruct* pDiagnosticInfo);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoClear(DiagnosticInfoStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTDiagnosticInfoCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoGetNamespaceUri(const DiagnosticInfoStruct* pDiagnosticInfo, TBHandle stringTable, TCHAR** ppNamespaceUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSetNamespaceUri(DiagnosticInfoStruct* pDiagnosticInfo, const TCHAR* pNamespaceUri, TBHandle stringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoGetSymbolicId(const DiagnosticInfoStruct* pDiagnosticInfo, TBHandle stringTable, TCHAR** ppSymbolicId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSetSymbolicId(DiagnosticInfoStruct* pDiagnosticInfo, const TCHAR* pSymbolicId, TBHandle stringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoGetLocale(const DiagnosticInfoStruct* pDiagnosticInfo, TBHandle stringTable, TCHAR** ppLocale);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSetLocale(DiagnosticInfoStruct* pDiagnosticInfo, const TCHAR* pLocale, TBHandle stringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoGetLocalizedText(const DiagnosticInfoStruct* pDiagnosticInfo, TBHandle stringTable, TCHAR** ppLocalizedText);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSetLocalizedText(DiagnosticInfoStruct* pDiagnosticInfo, const TCHAR* pLocalizedText, TBHandle stringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSetInnerDiagnosticInfo(DiagnosticInfoStruct* pDiagnosticInfo, const DiagnosticInfoStruct* pInnerDiagnosticInfo);
	TBCORE_IF TCHAR* OTAPI_CALL OTDiagnosticInfoToString(const void* pTarget, TBHandle stringTable);

#if TB5_ALARMS
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class OTContentFilterEvaluator
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEventFilterEvaluatorEvaluate(const ContentFilterStruct* pContentFilter, void* pApiContentFilterTargetHandle, bool* pFilterAccepted);
#endif


#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryEventFieldList
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventFieldListClear(HistoryEventFieldListStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventFieldListSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventFieldListCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryEventFieldListCompare(const void* pSource, const void* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryEvent
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventClear(HistoryEventStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryEventCompare(const void* pSource, const void* pTarget);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class EnumValueType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumValueTypeClear(EnumValueTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumValueTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumValueTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTEnumValueTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumValueTypeGetValue(TBHandle otbHandle, OTInt64* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumValueTypeSetValue(TBHandle otbHandle, OTInt64 value);

	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class DataTypeDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetDescriptionType(TBHandle otbHandle, EnumDataTypeDescriptionType* pDescriptionType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetName(TBHandle otbHandle, TCHAR** pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSetName(TBHandle otbHandle, const TCHAR* pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetDocumentation(TBHandle otbHandle, TCHAR** ppDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSetDocumentation(TBHandle otbHandle, const TCHAR* pDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetDocumentationAttributes(TBHandle otbHandle, OTUInt32 *pAttributeNamesCount, TCHAR*** pAttributeNames, OTUInt32 *pAttributeValuesCount, TCHAR*** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSetDocumentationAttributes(TBHandle otbHandle, OTUInt32 attributeNamesCount, const TCHAR** pAttributeNames, OTUInt32 attributeValuesCount, const TCHAR** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetCustomAttributes(TBHandle otbHandle, OTUInt32 *pAttributeNamesCount, TCHAR*** pAttributeNames, OTUInt32 *pAttributeValuesCount, TCHAR*** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSetCustomAttributes(TBHandle otbHandle, OTUInt32 attributeNamesCount, const TCHAR** pAttributeNames, OTUInt32 attributeValuesCount, const TCHAR** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetVersion(TBHandle otbHandle, TCHAR** pVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSetVersion(TBHandle otbHandle, const TCHAR* pVersion);

	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class StructuredDataTypeDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTStructuredDataTypeDescription_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructuredDataTypeDescriptionGetFields(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructuredDataTypeDescriptionSetFields(TBHandle otbHandle, OTUInt32 fieldCount, TBHandle* pFields);

	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class EnumerationDataTypeDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTEnumerationDataTypeDescription_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumerationDataTypeDescriptionGetEnumeratedValues(TBHandle otbHandle, OTUInt32* pValueCount, TBHandle** ppEnumeratedValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumerationDataTypeDescriptionSetEnumeratedValues(TBHandle otbHandle, OTUInt32 valueCount, TBHandle* pEnumeratedValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumerationDataTypeDescriptionIsEnumValue(TBHandle otbHandle, OTInt32 integerRepresentation, bool* pIsEnumValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumerationDataTypeDescriptionGetEnumeratedValue(TBHandle otbHandle, OTInt32 integerRepresentation, TBHandle* pEnumeratedValueDescriptionHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class FieldDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTFieldDescription_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetName(TBHandle otbHandle, TCHAR** ppName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetName(TBHandle otbHandle, const TCHAR* pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetLength(TBHandle otbHandle, OTUInt32* pLength);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetLength(TBHandle otbHandle, OTUInt32 length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetDocumentation(TBHandle otbHandle, TCHAR** ppDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetDocumentation(TBHandle otbHandle, const TCHAR* pDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetDocumentationAttributes(TBHandle otbHandle, OTUInt32 *pAttributeNamesCount, TCHAR*** pAttributeNames, OTUInt32 *pAttributeValuesCount, TCHAR*** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetDocumentationAttributes(TBHandle otbHandle, OTUInt32 attributeNamesCount, const TCHAR** pAttributeNames, OTUInt32 attributeValuesCount, const TCHAR** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetCustomAttributes(TBHandle otbHandle, OTUInt32 *pAttributeNamesCount, TCHAR*** pAttributeNames, OTUInt32 *pAttributeValuesCount, TCHAR*** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetCustomAttributes(TBHandle otbHandle, OTUInt32 attributeNamesCount, const TCHAR** pAttributeNames, OTUInt32 attributeValuesCount, const TCHAR** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetTypeName(TBHandle otbHandle, TCHAR** ppTypeName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetType(TBHandle otbHandle, const NodeIdStruct* pNodeId);


	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class EnumeratedValueDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTEnumeratedValueDescription_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionGetName(TBHandle otbHandle, TCHAR** ppName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionSetName(TBHandle otbHandle, const TCHAR* pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionGetValue(TBHandle otbHandle, OTInt32* pEnumValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionSetValue(TBHandle otbHandle, OTInt32 enumValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionGetDocumentation(TBHandle otbHandle, TCHAR** ppDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionSetDocumentation(TBHandle otbHandle, const TCHAR* pDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionGetDocumentationAttributes(TBHandle otbHandle, OTUInt32 *pAttributeNamesCount, TCHAR*** pAttributeNames, OTUInt32 *pAttributeValuesCount, TCHAR*** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionSetDocumentationAttributes(TBHandle otbHandle, OTUInt32 attributeNamesCount, const TCHAR** pAttributeNames, OTUInt32 attributeValuesCount, const TCHAR** pAttributeValues);

	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class Dictionary
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTDictionary_Construct(TBHandle apiHandle, bool addRef);

#ifdef COMPILE_FOR_UNITTESTS
		// UnitTest helper functions to access sync objects
		TBCORE_IF void* OTAPI_CALL OTBGetTypeDependencyMapSyncHandle();
		TBCORE_IF void* OTAPI_CALL OTBGetStructAccessSyncHandle();
		TBCORE_IF void* OTAPI_CALL OTBGetLocalizedTextManagerSyncHandle();
		TBCORE_IF void* OTAPI_CALL OTBGetLifeTimeSemaphoreSyncHandle();
		TBCORE_IF void* OTAPI_CALL OTBGetClientMonitoredItemLockSyncHandle();
		TBCORE_IF void* OTAPI_CALL OTBGetDataTypeLockSyncHandle();
		TBCORE_IF void* OTAPI_CALL OTBGetAppInfoSyncHandle();
		TBCORE_IF void* OTAPI_CALL OTBGetDiagnosticsLockSyncHandle();

		// UnitTest helper functions to precreate singletons
		TBCORE_IF void OTAPI_CALL OTBPrecreateScheduler();
#endif

#ifdef __cplusplus
}
#endif

#endif // _C_API_H_
