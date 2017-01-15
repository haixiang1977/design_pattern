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

#ifndef INNERBROWSERESULT_H
#define INNERBROWSERESULT_H

#include "IBrowseResult.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerBrowseResult
	class TBC_EXPORT InnerBrowseResult
		: public IBrowseResult
	{
	public:
		/*! Destructor */
		virtual ~InnerBrowseResult();


		// init from otb handle
		void initInner(BrowseResultStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IBrowseResult* other) const;
		/*! @overload */
		virtual int compare(const IBrowseResult& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowseResult& other);
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowseResult& other);

		// set from interface
		EnumStatusCode set(const IBrowseResult* pSrc);
		EnumStatusCode set(const IBrowseResult& pSrc);

		// protected:
		// the handle to the related core object
		BrowseResultStruct* m_pBrowseResult_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
	};
}
#endif	// INNERBROWSERESULT_H
