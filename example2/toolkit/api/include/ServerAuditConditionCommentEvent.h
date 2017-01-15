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

#ifndef SERVERAUDITCONDITIONCOMMENTEVENT_H
#define SERVERAUDITCONDITIONCOMMENTEVENT_H
#if TB5_ALARMS
#include "ServerAuditUpdateMethodEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event shall be generated if a comment was added to a condition.
		*
		* Beside mandatory properties of the base class additionally the following mandatory properties shall be set:
		* @li EventId:	This property shall contain the id of the event for which the comment was added.
		* @li Comment:	Contains the actual comment that was added. */
		class TBC_EXPORT AuditConditionCommentEvent
			: public AuditUpdateMethodEvent
		{
		public:
			/*! Constructs a new AuditConditionCommentEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Method/ConditionComment"
			* @li Message:			"Comment added" / "en".
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditConditionCommentEvent> create();

			/*! @deprecated		Please use AuditConditionCommentEvent::create() to construct an instance of this type.
			*					This constructor will be made 'protected' in future versions of this product.
			*
			* Constructs a new audit event for the given audit event type.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Method/ConditionComment"
			* @li Message:			"Comment added" / "en".
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			DEPRECATED(AuditConditionCommentEvent());
		protected:
			/*! @overload */
			AuditConditionCommentEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditConditionCommentEvent();

		private:
			/*! Forbid use assignment operator */
			AuditConditionCommentEvent& operator=(const AuditConditionCommentEvent&);
			/*! Forbid use of copy constructor */
			AuditConditionCommentEvent(const AuditConditionCommentEvent&);
		};
		typedef ObjectPointer<AuditConditionCommentEvent> AuditConditionCommentEventPtr;
		typedef ObjectPointer<const AuditConditionCommentEvent> AuditConditionCommentEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCONDITIONCOMMENTEVENT_H
