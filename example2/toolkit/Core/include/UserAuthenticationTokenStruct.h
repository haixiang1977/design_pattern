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

#ifndef _OT_USER_AUTHENTICATION_STRUCT_H_
#define _OT_USER_AUTHENTICATION_STRUCT_H_

#include "UserNameIdentityTokenStruct.h"
#include "X509IdentityTokenStruct.h"
#include "IssuedIdentityTokenStruct.h"

//lint -sem(UserAuthenticationTokenStruct::clear,cleanup)
struct UserAuthenticationTokenStruct
{
	EnumUserTokenType	type;
	OTChar*				pPolicyId;
	OTChar*				pSecurityPolicyUri;
	OTChar*				pIssuedTokenType;	// Not supported yet
	OTChar*				pIssuerEndpointUrl;	// Not supported yet

	EnumUserTokenType getType_API()
	{
		return type;
	}
	union
	{
		UserNameIdentityTokenStruct*  username;
		X509IdentityTokenStruct*      x509;
		IssuedIdentityTokenStruct*    issued;
	} data;

#ifdef OT_COMPILATION

	UserAuthenticationTokenStruct();
	~UserAuthenticationTokenStruct();

	void clear();
	void clearData();

	EnumStatusCode setPolicyId(const tstring& pPolicyId);
	EnumStatusCode setPolicyId(const OpcUa_String& pPolId);
	tstring getSecurityPolicyUri() const;
	EnumStatusCode setSecurityPolicyUri(const tstring& securityPolicyId);
	EnumStatusCode setIssuedTokenType(const tstring& value);
	EnumStatusCode setIssuerEndpointUrl(const tstring& value);


	EnumStatusCode set(const UserAuthenticationTokenStruct& pValue);

	int compare(const UserAuthenticationTokenStruct* pTarget) const
	{
		_UNUSED(pTarget);
		_REPORT_ASSERTION(_T("NotImplemented"));
		return 0;
	}

	EnumStatusCode setAnonymousToken_API();
	EnumStatusCode setUsernameToken_API(const UserNameIdentityTokenStruct* pUsernameToken);
	EnumStatusCode getUsernameToken_API(UserNameIdentityTokenStruct* ret) const;
	EnumStatusCode setIssuedToken_API(const IssuedIdentityTokenStruct* pIssuedToken);
	EnumStatusCode getIssuedToken_API(IssuedIdentityTokenStruct* ret) const;
	EnumStatusCode setX509Token_API(const X509IdentityTokenStruct* pX509Token);
	EnumStatusCode getX509Token_API(X509IdentityTokenStruct* ret) const;

#endif
};

#endif

