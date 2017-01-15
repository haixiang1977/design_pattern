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

#ifndef SERVEREVENTNOTIFICATION_H
#define SERVEREVENTNOTIFICATION_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "InnerValue.h"
#include "Value.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerBaseEvent.h"
#include "ServerBaseEventNotification.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class BaseNode;
	}

	namespace Server
	{
		/*! @deprecated Please do not use this class, use BaseEventNotification instead.
		*
		* Typically the usage of this class was like
		*
		* @code
		* BaseNodePtr sourceNode;
		* BaseEventPtr baseEvent = new BaseEvent();
		* ...
		* EventNotificationPtr eventNotification = new EventNotification();
		* eventNotification->init(baseEvent);
		* sourceNode->reportEvent(eventNotification);
		* @endcode
		*
		* If you have used such a code please adapt it to the following:
		*
		* @code
		* BaseNodePtr sourceNode;
		* BaseEventPtr baseEvent = BaseEvent::create();
		* ...
		* baseEvent->report(sourceNode->getNodeId());
		* @endcode */
		class TBC_EXPORT EventNotification
			: public Base
		{
		public:
			/*! Constructs a new EventNotification instance */
			static ObjectPointer<EventNotification> create();

			/*! @deprecated		Please use EventNotification::create() to construct an instance of this type.
			*					This constructor will be made 'protected' in future versions of this product.
			*
			* Default constructor */
			EventNotification();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			EventNotification(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			EventNotification(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~EventNotification();

			/////////////////////////////////////////////////////////////////////////
			// Methods of class EventNotification
			/////////////////////////////////////////////////////////////////////////

			/*! Initializes the EventNotification-instance with the given event type or event-instance node.
			* If the node is of a wrong type the function call will return an error.
			* If the notification is not initialized it cannot be reported. */
			EnumStatusCode init(Server::BaseNode* instanceOrType);

			/*! Returns a property of the notification (i. e. a node of the event). */
			EnumStatusCode getEventFieldValue(const IQualifiedName* propertyName, IValue* value) const;
			/*! Sets the value of an event property. If a previous value exists for a field with the given name, it will
			* be replaced.
			*
			* @param propertyName	Qualified name of the property
			* @param value			The value of the property */
			EnumStatusCode setEventFieldValue(const IQualifiedName* propertyName, const IValue* value);

			/*! Removes a child property with the specified BrowseName. */
			EnumStatusCode removeEventField(const IQualifiedName* propertyName);

			/*! Initializes the EventNotification-instance with the event type identified by the NodeId.
			* The NodeId must be a valid ID of an event type.
			*
			* If the node is invalid and the target cannot be found in the address space, this function will return an
			* error. */
			EnumStatusCode initFromTypeId(const INodeId* eventType);

		private:
			/*! For internal use only */
			void initMembers();

			/*! Required to support legacy notification mechanism in BaseNode::reportEvent() */
			friend class BaseNode;

			/*! For internal use only */
			PRIVATE_EXPORTED_STL_CONTAINER(BaseEventPtr m_event)
			/*! For internal use only */
			PRIVATE_EXPORTED_STL_CONTAINER(BaseEventNotificationPtr m_eventNotification)

			/*! Forbid use assignment operator */
			EventNotification& operator=(const EventNotification&);
			/*! Forbid use of copy constructor */
			EventNotification(const EventNotification&);
		};
		typedef ObjectPointer<EventNotification> EventNotificationPtr;
		typedef ObjectPointer<const EventNotification> EventNotificationConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVEREVENTNOTIFICATION_H
