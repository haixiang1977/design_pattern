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

#ifndef IUSERAUTHENTICATIONTOKEN_H
#define IUSERAUTHENTICATIONTOKEN_H

#include "UserAuthenticationTokenStruct.h"
#include "InnerAnonymousIdentityToken.h"
#include "AnonymousIdentityToken.h"
#include "InnerUserNameIdentityToken.h"
#include "UserNameIdentityToken.h"
#include "InnerIssuedIdentityToken.h"
#include "IssuedIdentityToken.h"
#include "InnerX509IdentityToken.h"
#include "X509IdentityToken.h"

namespace SoftingOPCToolbox5
{
	/*! @deprecated This class will be removed in future versions of this product.
	*
	* The UserAuthenticationToken data type is used to configure user credentials for a session.
	*
	* @note This data type is not defined by the OPC UA specifications. */
	class TBC_EXPORT IUserAuthenticationToken
	{
	public:
		/*! Destructor */
		virtual ~IUserAuthenticationToken(){};

		//////////////////////////////////////////////////////////////////////////
		// Information related to the UserIdentityToken
		//////////////////////////////////////////////////////////////////////////

		/*! @see IUserIdentityToken::getType() */
		virtual EnumUserTokenType getType() const = 0;

		/*! @see IUserIdentityToken::setAnonymousIdentityToken() */
		virtual EnumStatusCode setAnonymousToken() = 0;

		/*! @see IUserIdentity::getUserNameIdentityToken() */
		virtual UserNameIdentityToken getUsernameToken() const = 0;
		/*! @see IUserIdentity::setUserNameIdentityToken() */
		virtual EnumStatusCode setUsernameToken(const IUserNameIdentityToken* usernameToken) = 0;

		/*! @see IUserIdentity::getX509IdentityToken() */
		virtual X509IdentityToken getX509Token() const = 0;
		/*! @see IUserIdentity::setX509IdentityToken() */
		virtual EnumStatusCode setX509Token(const IX509IdentityToken* x509Token) = 0;

		/*! @see IUserIdentity::getIssuedIdentityToken() */
		virtual IssuedIdentityToken getIssuedToken() const = 0;
		/*! @see IUserIdentity::setIssuedIdentityToken() */
		virtual EnumStatusCode setIssuedToken(const IIssuedIdentityToken* issuedToken) = 0;

		//////////////////////////////////////////////////////////////////////////
		// Information related to the server's UserTokenPolicy
		//////////////////////////////////////////////////////////////////////////

		/*! @see IUserTokenPolicy::getPolicyId() */
		virtual tstring getPolicyId() const = 0;
		/*! @see IUserTokenPolicy::setPolicyId() */
		virtual void setPolicyId(const tstring& value) = 0;

		/*! @see IUserTokenPolicy::getIssuedTokenType() */
		virtual tstring getIssuedTokenType() const = 0;
		/*! @see IUserTokenPolicy::setIssuedTokenType() */
		virtual void setIssuedTokenType(const tstring& value) = 0;

		/*! @see IUserTokenPolicy::getIssuerEndpointUrl() */
		virtual tstring getIssuerEndpointUrl() const = 0;
		/*! @see IUserTokenPolicy::setIssuerEndpointUrl() */
		virtual void setIssuerEndpointUrl(const tstring& value) = 0;

		/*! @see IUserTokenPolicy::getSecurityPolicyUri() */
		virtual tstring getSecurityPolicyUri() const = 0;
		/*! @see IUserTokenPolicy::setSecurityPolicyUri() */
		virtual void setSecurityPolicyUri(const tstring& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IUserAuthenticationToken*) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IUserAuthenticationToken&) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IUserAuthenticationToken* other) const = 0;
		/*! @overload */
		virtual int compare(const IUserAuthenticationToken& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserAuthenticationToken& other) = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserAuthenticationToken& other) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IUserAuthenticationToken
} // end namespace
#endif	// IUSERAUTHENTICATIONTOKEN_H
