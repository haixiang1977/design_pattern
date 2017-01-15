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

#ifndef SERVERAUDITCERTIFICATEUNTRUSTEDEVENT_H
#define SERVERAUDITCERTIFICATEUNTRUSTEDEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditCertificateEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event is generated if the certificate is not trusted.
		*
		* This class does not define additional properties. */
		class TBC_EXPORT AuditCertificateUntrustedEvent
			: public AuditCertificateEvent
		{
		public:
			/*! Constructs a new AuditCertificateUntrustedEvent instance
			*
			* The newly created object has already the following properties initially set:
			* @li Message:			"Certificate is not trusted" / "en"
			* @li SourceName:		"Security/Certificate"
			* @li SourceNode:		The server object
			* @li ClientUserId:		"System/OpenSecureChannel"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditCertificateUntrustedEvent> create();

			/*! @deprecated		Please use AuditCertificateUntrustedEvent::create() to construct an instance of this type.
			*					This constructor will be made 'protected' in future versions of this product for derived classes.
			*
			* Constructs a new audit event for the given audit event type.
			*
			* The newly created object has already the following properties initially set:
			* @li Message:			"Certificate is not trusted" / "en"
			* @li SourceName:		"Security/Certificate"
			* @li SourceNode:		The server object
			* @li ClientUserId:		"System/OpenSecureChannel"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			DEPRECATED(AuditCertificateUntrustedEvent());
		protected:
			/*! @overload */
			AuditCertificateUntrustedEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditCertificateUntrustedEvent();

		private:
			/*! Forbid use assignment operator */
			AuditCertificateUntrustedEvent& operator=(const AuditCertificateUntrustedEvent&);
			/*! Forbid use of copy constructor */
			AuditCertificateUntrustedEvent(const AuditCertificateUntrustedEvent&);
		};
		typedef ObjectPointer<AuditCertificateUntrustedEvent> AuditCertificateUntrustedEventPtr;
		typedef ObjectPointer<const AuditCertificateUntrustedEvent> AuditCertificateUntrustedEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCERTIFICATEUNTRUSTEDEVENT_H
