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

#ifndef ENDPOINTDESCRIPTION_H
#define ENDPOINTDESCRIPTION_H

#include "IEndpointDescription.h"
#include "InnerApplicationDescription.h"
#include "ApplicationDescription.h"
#include "InnerUserTokenPolicy.h"
#include "UserTokenPolicy.h"
#include "InnerByteString.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The EndpointDescription data type describes the endpoint for a server
	* and is returned by the GetEndpoints service (see Application::getEndpointsFromServer()).
	*
	* An EndpointDescription contains all information a client needs to establish
	* a session with the server. */
	class TBC_EXPORT EndpointDescription
		: public IEndpointDescription
	{
	public:
		/*! Default constructor */
		EndpointDescription();
		/*! Constructs a copy of the given instance */
		EndpointDescription(const IEndpointDescription*);
		/*! @overload */
		EndpointDescription(const IEndpointDescription&);
		/*! @overload */
		EndpointDescription(const EndpointDescription&);

		/*! Destructor */
		virtual ~EndpointDescription();

		/*! Assigns the contents of @p cp to this instance */
		EndpointDescription& operator=(const IEndpointDescription* cp);
		/*! @overload */
		EndpointDescription& operator=(const IEndpointDescription& cp);
		/*! @overload */
		EndpointDescription& operator=(const EndpointDescription& cp);

		/* see IEndpointDescription::set */
		virtual EnumStatusCode set(const IEndpointDescription* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IEndpointDescription& pSrc);

		/* see IEndpointDescription::compare */
		virtual int compare(const IEndpointDescription*) const;
		/*! @overload */
		virtual int compare(const IEndpointDescription&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEndpointDescription& other);
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEndpointDescription& other);

		/* see IEndpointDescription::getEndpointUrl */
		virtual tstring getEndpointUrl() const;
		/*! see IEndpointDescription::setEndpointUrl */
		DEPRECATED(virtual void setEndpointUrl(const tstring& value));

		/* see IEndpointDescription::getServer */
		virtual const IApplicationDescription* getServer() const;
		/*! @overload */
		virtual IApplicationDescription* getServer();
		/* see IEndpointDescription::setServer */
		DEPRECATED(virtual void setServer(const IApplicationDescription* value));
		/*! @overload */
		DEPRECATED(virtual void setServer(const ApplicationDescription& value));

		/* see IEndpointDescription::getServerCertificate */
		virtual ByteString getServerCertificate() const;
		/* see IEndpointDescription::setServerCertificate */
		DEPRECATED(virtual void setServerCertificate(const ByteString& value));

		/* see IEndpointDescription::getMessageSecurityMode */
		virtual EnumMessageSecurityMode getMessageSecurityMode() const;
		/* see IEndpointDescription::setMessageSecurityMode */
		DEPRECATED(virtual void setMessageSecurityMode(EnumMessageSecurityMode value));

		/* see IEndpointDescription::getSecurityPolicy */
		virtual tstring getSecurityPolicy() const;
		/* see IEndpointDescription::setSecurityPolicy */
		DEPRECATED(virtual void setSecurityPolicy(const tstring& value));

		/* see IEndpointDescription::getUserIdentityTokenCount */
		virtual unsigned getUserIdentityTokenCount() const;
		/* see IEndpointDescription::getUserIdentityToken */
		virtual const IUserTokenPolicy* getUserIdentityToken(unsigned index) const;
		/* see IEndpointDescription::getUserIdentityTokens */
		virtual std::vector<UserTokenPolicy> getUserIdentityTokens() const;
		/* see IEndpointDescription::addUserIdentityToken */
		DEPRECATED(virtual EnumStatusCode addUserIdentityToken(const IUserTokenPolicy* value));

		/* see IEndpointDescription::getTransportProfile */
		virtual tstring getTransportProfile() const;
		/* see IEndpointDescription::setTransportProfile */
		DEPRECATED(virtual void setTransportProfile(const tstring& value));

		/* see IEndpointDescription::getSecurityLevel */
		virtual unsigned char getSecurityLevel() const;
		/* see IEndpointDescription::setSecurityLevel */
		DEPRECATED(virtual void setSecurityLevel(unsigned char value));

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerApplicationDescription m_Server;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerUserTokenPolicy> m_UserIdentityTokens)
		InnerByteString m_serverCertificate;
		EndpointDescriptionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// ENDPOINTDESCRIPTION_H
