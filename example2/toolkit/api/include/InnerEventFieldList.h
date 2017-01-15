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

#ifndef INNEREVENTFIELDLIST_H
#define INNEREVENTFIELDLIST_H
#if TB5_FILTER

#include "IEventFieldList.h"
#include "InnerValue.h"
#include "Value.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerEventFieldList
	class TBC_EXPORT InnerEventFieldList
		: public IEventFieldList
	{
	public:
		/*! Destructor */
		virtual ~InnerEventFieldList();

		virtual unsigned getEventFieldCount() const;
		virtual const IValue* getEventField(unsigned index) const;
		virtual std::vector<Value> getEventFields() const;
		virtual EnumStatusCode addEventField(const IValue* value);


		// init from otb handle
		void initInner(EventFieldListStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IEventFieldList* other) const;
		/*! @overload */
		virtual int compare(const IEventFieldList& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEventFieldList& other);
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEventFieldList& other);

		// set from interface
		EnumStatusCode set(const IEventFieldList* pSrc);
		EnumStatusCode set(const IEventFieldList& pSrc);

	private:
		// the handle to the related core object
		EventFieldListStruct* m_pEventFieldList_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerValue> m_EventFields)
	};
}
#endif
#endif	// INNEREVENTFIELDLIST_H
