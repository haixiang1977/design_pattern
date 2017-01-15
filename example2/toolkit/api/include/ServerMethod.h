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

#ifndef SERVERMETHOD_H
#define SERVERMETHOD_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerBaseNode.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class MethodCallTransaction;
		class MethodCallRequest;
	}

	namespace Server
	{
		/*! The Method class is used to define a Method node in the address space of a server.
		* A method can be called by a client using the 'Call' service and will be executed
		* on the server (see handleExecuteRequest()).
		*
		* A method is part of an object in the address space. An object that owns a method needs to
		* reference the method by a 'HasComponent' reference. */
		class TBC_EXPORT Method
			: public BaseNode
		{
		public:
			/*! Constructs a new Method instance */
			static ObjectPointer<Method> create();

			/*! @deprecated		Please use Method::create() to construct an instance of this type.
			*					This constructor will be made 'protected' in future versions of this product.
			*
			* Default constructor */
			Method();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			Method(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			Method(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~Method();

			/*! Defines the input arguments of the method. Clients are able to identify the input arguments
			* of a method by reading the 'InputArgument' property of the method.
			*
			* The input arguments cannot be modified once they have been defined.
			*
			* @param pNodeId		The NodeId that is assigned to the InputArgument property
			* @param arguments		A vector of Arguments, defining the number and properties for the InputArguments
			*
			* @note	This method creates the InputArgument property that holds the input arguments of the method.
			*
			* @see Argument */
			EnumStatusCode setInputArguments(const INodeId* pNodeId, const std::vector<Argument>& arguments);

			/*! Defines the output arguments of the method. Clients are able to identify the output arguments
			* of a method by reading the 'OutputArgument' property of the method.
			*
			* The output arguments cannot be modified once they have been defined.
			*
			* @param pNodeId		The NodeId that is assigned to the OutputArgument property
			* @param arguments		A vector of Arguments, defining the number and properties for the OutputArguments
			*
			* @note	This method creates the OutputArgument property that holds the output arguments of the method.
			*
			* @see Argument */
			EnumStatusCode setOutputArguments(const INodeId* pNodeId, const std::vector<Argument>& arguments);

			/*! Returns whether a client is (currently) allowed to execute this method. */
			bool getExecutable() const;
			/*! Sets whether a client is allowed to execute this method. */
			virtual EnumStatusCode setExecutable(bool executable);

			/*! Returns the 'UserExecutable' attribute value of the method that indicates whether the
			* method can be executed by a user belonging to the given user group.
			*
			* @param userGroupIndex	The 0-based index into the user group
			*
			* @see getExecutable() */
			bool getUserExecutable(OTUInt32 userGroupIndex) const;

			/*! Returns the key of an AccessPattern which defines the access rights for different user groups.
			*
			* @see AccessPattern and Application::getAccessPatterns() */
			OTUInt32 getAccessPatternKey() const;
			/*! @deprecated Please use getAccessPatternKey() instead. */
			DEPRECATED(OTUInt32 getAccessGroupKey() const);
			/*! Assigns the method a previously defined AccessPattern. An AccessPattern defines
			* the users' rights to execute the method.
			*
			* @note	This method returns an error if the key is unknown to the server.
			*		Keys are limited to values from 0...0xFFFF.
			*
			* @see IAccessPattern Application::setAccessPattern() */
			EnumStatusCode setAccessPatternKey(OTUInt32 accessPatternKey);
			/*! @deprecated Please use setAccessPatternKey() instead. */
			DEPRECATED(EnumStatusCode setAccessGroupKey(OTUInt32 accessGroupKey));

			/*! Callback method that is triggered when the method is executed by a client.
			* This method should be overridden by server applications.
			*
			* @param transaction	The transaction which contains the single request
			* @param request		The single request which shall be handled
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleExecuteRequest(Server::MethodCallTransaction* transaction, Server::MethodCallRequest* request);

			/*! Callback method for a single read request to a value.
			*
			* This method handles requests for the 'Executable' and 'UserExecutable' attribute of methods.
			*
			* @param transaction	The whole transaction which contains the single ReadRequest
			* @param request		The single ReadRequest which shall be handled
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			EnumStatusCode handleReadRequest(Server::ReadTransaction* transaction, Server::ReadRequest* request);

		protected:
			/*! The implementation of the method in the Toolkit core.
			*
			* @param transaction	The whole transaction which contains the single request
			* @param request		The single request which shall be executed */
			EnumStatusCode executeRequest(Server::MethodCallTransaction* transaction, Server::MethodCallRequest* request);

		private:
			/*! Forbid use assignment operator */
			Method& operator=(const Method&);
			/*! Forbid use of copy constructor */
			Method(const Method&);
		};
		typedef ObjectPointer<Method> MethodPtr;
		typedef ObjectPointer<const Method> MethodConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERMETHOD_H
