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

#ifndef USERAUTHENTICATIONTOKEN_H
#define USERAUTHENTICATIONTOKEN_H

#include "IUserAuthenticationToken.h"
#include "InnerUserNameIdentityToken.h"
#include "UserNameIdentityToken.h"
#include "InnerIssuedIdentityToken.h"
#include "IssuedIdentityToken.h"
#include "InnerX509IdentityToken.h"
#include "X509IdentityToken.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! @deprecated This class will be removed in future versions of this product.
	*
	* The UserAuthenticationToken data type is used to configure user credentials for a session.
	*
	* @note This data type is not defined by the OPC UA specifications. */
	class TBC_EXPORT UserAuthenticationToken
		: public IUserAuthenticationToken
	{
	public:
		/*! Default constructor */
		UserAuthenticationToken();
		/*! Constructs a copy of the given instance */
		UserAuthenticationToken(const IUserAuthenticationToken*);
		/*! @overload */
		UserAuthenticationToken(const IUserAuthenticationToken&);
		/*! @overload */
		UserAuthenticationToken(const UserAuthenticationToken&);

		/*! Destructor */
		virtual ~UserAuthenticationToken();

		/*! Assigns the contents of @p cp to this instance */
		UserAuthenticationToken& operator=(const IUserAuthenticationToken*);
		/*! @overload */
		UserAuthenticationToken& operator=(const IUserAuthenticationToken&);
		/*! @overload */
		UserAuthenticationToken& operator=(const UserAuthenticationToken&);

		/* see IUserAuthenticationToken::compare */
		virtual int compare(const IUserAuthenticationToken*) const;
		/*! @overload */
		virtual int compare(const IUserAuthenticationToken&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserAuthenticationToken& other);
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserAuthenticationToken& other);

		/* see IUserAuthenticationToken::set */
		virtual EnumStatusCode set(const IUserAuthenticationToken* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IUserAuthenticationToken& pSrc);

		//////////////////////////////////////////////////////////////////////////
		// Information related to the UserIdentityToken
		//////////////////////////////////////////////////////////////////////////

		/* see IUserAuthenticationToken::getType */
		virtual EnumUserTokenType getType() const;

		/* see IUserAuthenticationToken::setAnonymousToken */
		virtual EnumStatusCode setAnonymousToken();

		/* see IUserAuthenticationToken::getUsernameToken */
		virtual UserNameIdentityToken getUsernameToken() const;
		/* see IUserAuthenticationToken::setUsernameToken */
		virtual EnumStatusCode setUsernameToken(const IUserNameIdentityToken* usernameToken);

		/* see IUserAuthenticationToken::getX509Token */
		virtual X509IdentityToken getX509Token() const;
		/* see IUserAuthenticationToken::setX509Token */
		virtual EnumStatusCode setX509Token(const IX509IdentityToken* x509Token);

		/* see IUserAuthenticationToken::getIssuedToken */
		virtual IssuedIdentityToken getIssuedToken() const;
		/* see IUserAuthenticationToken::setIssuedToken */
		virtual EnumStatusCode setIssuedToken(const IIssuedIdentityToken* issuedToken);

		//////////////////////////////////////////////////////////////////////////
		// Information related to the server's UserTokenPolicy
		//////////////////////////////////////////////////////////////////////////

		/* see IUserAuthenticationToken::getPolicyId */
		virtual tstring getPolicyId() const;
		/* see IUserAuthenticationToken::setPolicyId */
		virtual void setPolicyId(const tstring& value);

		/* see IUserAuthenticationToken::getIssuedTokenType */
		virtual tstring getIssuedTokenType() const;
		/* see IUserAuthenticationToken::setIssuedTokenType */
		virtual void setIssuedTokenType(const tstring& value);

		/* see IUserAuthenticationToken::getIssuerEndpointUrl */
		virtual tstring getIssuerEndpointUrl() const;
		/* see IUserAuthenticationToken::setIssuerEndpointUrl */
		virtual void setIssuerEndpointUrl(const tstring& value);

		/* see IUserAuthenticationToken::getSecurityPolicyUri */
		virtual tstring getSecurityPolicyUri() const;
		/* see IUserAuthenticationToken::setSecurityPolicyUri */
		virtual void setSecurityPolicyUri(const tstring& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		UserAuthenticationTokenStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// USERAUTHENTICATIONTOKEN_H
