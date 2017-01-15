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

#ifndef _UserIdentityTokenStruct_H_
#define _UserIdentityTokenStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "AnonymousIdentityTokenStruct.h"
#include "UserNameIdentityTokenStruct.h"
#include "X509IdentityTokenStruct.h"
#include "IssuedIdentityTokenStruct.h"

//lint -sem(UserIdentityTokenStruct::clear, cleanup)
//lint -sem(UserIdentityTokenStruct::clear, initializer)
typedef struct UserIdentityTokenStruct
{
	EnumUserTokenType type;
	union
	{
		AnonymousIdentityTokenStruct* anonymousIdentityToken;
		UserNameIdentityTokenStruct* userNameIdentityToken;
		X509IdentityTokenStruct* x509IdentityToken;
		IssuedIdentityTokenStruct* issuedIdentityToken;
	}
	value;

#ifdef OT_COMPILATION
	UserIdentityTokenStruct();
	UserIdentityTokenStruct(const UserIdentityTokenStruct& cp);

	EnumStatusCode set(const UserIdentityTokenStruct&);
	EnumStatusCode get(UserIdentityTokenStruct&) const;

	EnumStatusCode set(const OpcUa_ExtensionObject& src);
	EnumStatusCode get(OpcUa_ExtensionObject& target) const;

	const UserIdentityTokenStruct& operator=(const UserIdentityTokenStruct& cp);
	bool operator==(const UserIdentityTokenStruct& toCompare) const;
	bool operator!=(const UserIdentityTokenStruct& toCompare) const;
	bool operator<(const UserIdentityTokenStruct& toCompare) const;
	bool operator>(const UserIdentityTokenStruct& toCompare) const;

	int compare(const UserIdentityTokenStruct* pTarget) const;

	EnumStatusCode setAnonymousIdentityToken(const AnonymousIdentityTokenStruct & token);
	EnumStatusCode getAnonymousIdentityToken(AnonymousIdentityTokenStruct & token) const;
	EnumStatusCode setUserNameIdentityToken(const UserNameIdentityTokenStruct & token);
	EnumStatusCode getUserNameIdentityToken(UserNameIdentityTokenStruct & token) const;
	EnumStatusCode setX509IdentityToken(const X509IdentityTokenStruct & token);
	EnumStatusCode getX509IdentityToken(X509IdentityTokenStruct & token) const;
	EnumStatusCode setIssuedIdentityToken(const IssuedIdentityTokenStruct & token);
	EnumStatusCode getIssuedIdentityToken(IssuedIdentityTokenStruct & token) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;

	tstring getTokenPolicyId() const;

	tstring toString() const;

	void clear(void);
	~UserIdentityTokenStruct(void);
	void* operator new(size_t s) { return OTAllocateMemory(s); }
	void operator delete(void* p) { return OTFreeMemory(p); }
#endif
} UserIdentityTokenStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
