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

#ifndef __ENDPOINTDESCRIPTIONSTRUCT_H_
#define __ENDPOINTDESCRIPTIONSTRUCT_H_

#include "ApplicationDescriptionStruct.h"
#include "UserTokenPolicyStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Stores information related to an endpoint. This is usually used, when calling the "GetEndpoints" or "FindServer"
* on the Application object. */
//lint -sem(EndpointDescriptionStruct::clear, cleanup)
//lint -sem(EndpointDescriptionStruct::clear, initializer)
typedef struct EndpointDescriptionStruct
{
	/*! The URL of this Endpoint. Clients that want to connect to this Endpoint have to use this URL. */
	TCHAR* pEndpointUrl;

	/*! The application description of the hosting server. */
	ApplicationDescriptionStruct server;

	/*! The application instance Certificate issued to the Server. A Server shall prove possession by using the
	* private key to sign the Nonce provided by the Client in the request.
	* The Client shall verify that this Certificate is the same as the one used to create the SecureChannel. */
	ByteStringStruct serverCertificate;

	/*! The messageSecurityMode is an enumeration that specifies what security should be applied to messages exchanges
	* during a Session.
	* See enumeration type for possible values. */
	EnumMessageSecurityMode messageSecurityMode;

	/*! The URI for SecurityPolicy to use when securing messages. */
	TCHAR* pSecurityPolicy;

	/*! The user identity tokens that the Server will accept. One of these have to be used for configuring a Client::Session. */
	unsigned userIdentityTokens_count;
	UserTokenPolicyStruct* userIdentityTokens;

	/*! The URI of the Transport Profile supported by the Endpoint. */
	TCHAR* pTransportProfile;

	/*! A numeric value that indicates how secure the EndpointDescription is compared to other EndpointDescriptions
	* for the same Server. A value of 0 indicates that the EndpointDescription is not recommended and is only
	* supported for backward compatibility. */
	unsigned char securityLevel;


#ifdef OT_COMPILATION
	EndpointDescriptionStruct();
	EnumStatusCode setEndpointUrl(const TCHAR* pValue);
	EnumStatusCode setServerCertificate(unsigned length, const unsigned char* pValue);
	EnumStatusCode getServerCertificate(unsigned* pLength, unsigned char** pValue);
	EnumStatusCode setSecurityPolicy(const TCHAR* pValue);
	EnumStatusCode setUserIdentityTokens(unsigned UserIdentityTokensCount, const UserTokenPolicyStruct* UserIdentityTokens);
	EnumStatusCode addUserIdentityToken(const UserTokenPolicyStruct* pUserTokenPolicy);
	EnumStatusCode setTransportProfile(const TCHAR* pValue);

	EnumStatusCode set(const EndpointDescriptionStruct&);
	EnumStatusCode get(EndpointDescriptionStruct&) const;
	EnumStatusCode set(const OpcUa_EndpointDescription&);
	EnumStatusCode get(OpcUa_EndpointDescription&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;


	const EndpointDescriptionStruct& operator=(const EndpointDescriptionStruct& cp);
	bool operator==(const EndpointDescriptionStruct& toCompare) const;
	bool operator!=(const EndpointDescriptionStruct& toCompare) const;
	bool operator<(const EndpointDescriptionStruct& toCompare) const;
	bool operator>(const EndpointDescriptionStruct& toCompare) const;

	int compare(const EndpointDescriptionStruct* pTarget) const;

	void clear(void);
	~EndpointDescriptionStruct(void);

#endif
}EndpointDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
