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

#ifndef INNERUSERAUTHENTICATIONTOKEN_H
#define INNERUSERAUTHENTICATIONTOKEN_H

#include "IUserAuthenticationToken.h"
#include "InnerUserNameIdentityToken.h"
#include "UserNameIdentityToken.h"
#include "InnerIssuedIdentityToken.h"
#include "IssuedIdentityToken.h"
#include "InnerX509IdentityToken.h"
#include "X509IdentityToken.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerUserAuthenticationToken
	class TBC_EXPORT InnerUserAuthenticationToken
		: public IUserAuthenticationToken
	{
	public:
		/*! Destructor */
		virtual ~InnerUserAuthenticationToken();

		/* see IUserAuthenticationToken::getUsernameToken */
		virtual UserNameIdentityToken getUsernameToken() const;
		/* see IUserAuthenticationToken::setUsernameToken */
		virtual EnumStatusCode setUsernameToken(const IUserNameIdentityToken* usernameToken);

		/* see IUserAuthenticationToken::getIssuedToken */
		virtual IssuedIdentityToken getIssuedToken() const;
		/* see IUserAuthenticationToken::setIssuedToken */
		virtual EnumStatusCode setIssuedToken(const IIssuedIdentityToken* issuedToken);

		/* see IUserAuthenticationToken::getX509Token */
		virtual X509IdentityToken getX509Token() const;
		/* see IUserAuthenticationToken::setX509Token */
		virtual EnumStatusCode setX509Token(const IX509IdentityToken* x509Token);

		/* see IUserAuthenticationToken::setAnonymousToken */
		virtual EnumStatusCode setAnonymousToken();

		/*! An identifier for the UserTokenPolicy that the token conforms to.
		*
		* The Client specifies this value when it constructs a UserIdentityToken that
		* conforms to the policy.
		* This value is only unique within the context of a single Server. */
		virtual tstring getPolicyId() const;
		virtual void setPolicyId(const tstring& value);

		/*! The security policy to be used for this user identity. If empty the security policy which has been set
		* for the session (channel) will be used.
		*
		* @note This security policy determines the encryption algorithm to be used for the username identity, when encrypting
		* the password. */
		virtual tstring getSecurityPolicyUri() const;
		virtual void setSecurityPolicyUri(const tstring& value);

		/*! Defines the type of the token. */
		virtual EnumUserTokenType getType() const;

		/*! Identifies the issued token type. This is only used for issued tokens. */
		virtual tstring getIssuedTokenType() const;
		virtual void setIssuedTokenType(const tstring& value);

		/*! Identifies the issuer endpoint URL. This is only used for issued tokens. */
		virtual tstring getIssuerEndpointUrl() const;
		virtual void setIssuerEndpointUrl(const tstring& value);


		// init from otb handle
		void initInner(UserAuthenticationTokenStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IUserAuthenticationToken* other) const;
		/*! @overload */
		virtual int compare(const IUserAuthenticationToken& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserAuthenticationToken& other);
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserAuthenticationToken& other);

		// set from interface
		EnumStatusCode set(const IUserAuthenticationToken* pSrc);
		EnumStatusCode set(const IUserAuthenticationToken& pSrc);

		// protected:
		// the handle to the related core object
		UserAuthenticationTokenStruct* m_pUserAuthenticationToken_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
	};
}
#endif	// INNERUSERAUTHENTICATIONTOKEN_H
