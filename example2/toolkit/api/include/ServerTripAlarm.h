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

#ifndef SERVERTRIPALARM_H
#define SERVERTRIPALARM_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerOffNormalAlarm.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The TripAlarm is a specialization of the OffNormalAlarm intended to represent an equipment trip condition.
		*
		* The Alarm becomes active when the monitored piece of equipment experiences some abnormal fault such as
		* a motor shutting down due to an overload condition.
		*
		* @see OffNormalAlarm */
		class TBC_EXPORT TripAlarm
			: public OffNormalAlarm
		{
		public:
			/*! Constructs a new TripAlarm instance */
			static ObjectPointer<TripAlarm> create();

			/*! @deprecated		Please use TripAlarm::create() to construct an instance of this type.
			*					This constructor will be made 'protected' in future versions of this product.
			*
			Default constructor */
			TripAlarm();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			TripAlarm(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			TripAlarm(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~TripAlarm();

		private:
			/*! Forbid use assignment operator */
			TripAlarm& operator=(const TripAlarm&);
			/*! Forbid use of copy constructor */
			TripAlarm(const TripAlarm&);
		};
		typedef ObjectPointer<TripAlarm> TripAlarmPtr;
		typedef ObjectPointer<const TripAlarm> TripAlarmConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERTRIPALARM_H
