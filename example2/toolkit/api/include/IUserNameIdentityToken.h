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

#ifndef IUSERNAMEIDENTITYTOKEN_H
#define IUSERNAMEIDENTITYTOKEN_H

#include "UserNameIdentityTokenStruct.h"
#include "ByteString.h"
#include "IByteString.h"

namespace SoftingOPCToolbox5
{
	/*! The UserNameIdentityToken data type is used to pass username/password credentials to the server.
	*
	* UA defines various tokens for user identification. This one is using a user name
	* and a password for identification.
	*
	* The password is transported encrypted to avoid a "man in the middle" seeing the password. */
	class TBC_EXPORT IUserNameIdentityToken
	{
	public:
		/*! Destructor */
		virtual ~IUserNameIdentityToken(){};

		/*! Returns the identifier for the UserTokenPolicy that the token conforms to.
		*
		* @see setPolicyId() */
		virtual tstring getPolicyId() const = 0;
		/*! Sets the identifier for the UserTokenPolicy that the token conforms to.
		*
		* The PolicyId is an identifier, specified by the user identities returned from server
		* during GetEndpoints service call (see Application::getEndpointsFromServer()).
		* This value is only unique within the context of a single server. */
		virtual void setPolicyId(const tstring& value) = 0;

		/*! Returns a string that identifies the user. */
		virtual tstring getUserName() const = 0;
		/*! Sets the string that identifies the user. */
		virtual void setUserName(const tstring& value) = 0;

		/*! Returns the password for the user. */
		virtual const IByteString* getPassword() const = 0;
		/*! Sets the password for the user. The password can be an empty string.
		* The password is used to verify a specific user. */
		virtual EnumStatusCode setPassword(const IByteString* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setPassword(const ByteString& value) = 0;

		/*! Returns a URI that identifies the encryption algorithm used for encrypting
		* and decrypting the password.
		*
		* @see setEncryptionAlgorithm() */
		virtual tstring getEncryptionAlgorithm() const = 0;
		/*! @deprecated		This method will be removed in future versions of this product.
		*					The encryption algorithm is filled by the Toolkit and must not
		*					be defined by a client.
		*
		* Sets the URI of the encryption algorithm used for encrypting and decrypting the password.
		*
		* @param value The URI of the encryption algorithm
		*
		* @note		On the client side, when connecting to a server, this field should not be filled in as
		*			it is automatically filled by the Toolkit (depending on the security policy used),
		*			when this user token is actually sent to the server. */
		virtual void setEncryptionAlgorithm(const tstring& value) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IUserNameIdentityToken* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IUserNameIdentityToken& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IUserNameIdentityToken* other) const = 0;
		/*! @overload */
		virtual int compare(const IUserNameIdentityToken& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserNameIdentityToken& other) = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserNameIdentityToken& other) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IUserNameIdentityToken
} // end namespace

#endif	// IUSERNAMEIDENTITYTOKEN_H
