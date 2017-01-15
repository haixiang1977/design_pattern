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

#ifndef __APPLICATIONDESCRIPTIONSTRUCT_H_
#define __APPLICATIONDESCRIPTIONSTRUCT_H_

#include "LocalizedTextStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure with members characterizing an application. The application type is defined by the application's
* initialization. */
//lint -sem(ApplicationDescriptionStruct::clear, cleanup)
//lint -sem(ApplicationDescriptionStruct::clear, initializer)
typedef struct ApplicationDescriptionStruct
{
	/*! The global unique identifier for the application instance. */
	TCHAR* pApplicationUri;

	/*! The global unique identifier for the product. */
	TCHAR* pProductUri;

	/*! A localized descriptive name for the application. */
	LocalizedTextStruct applicationName;

	/*! The type of the application (whether Client, Server or Both). */
	EnumApplicationType applicationType;

	/*! If a server can be accessed via a Gateway Server the value shall specify that. */
	TCHAR* pGatewayServerUri;

	/*! A URI that identifies the discovery profile supported by the URLs provided.
	* The field is not used in case of client only applications.
	* If the value is not specified then the Endpoints shall support the standard DiscoveryServices. */
	TCHAR* pDiscoveryProfileUri;

	/*! These URLs belong to the Gateway Server.
	* Some Discovery Servers may return multiple records for the same Server if that Server can be accessed
	* via multiple paths. */
	OTUInt32 discoveryUrls_count;
	TCHAR** discoveryUrls;


#ifdef OT_COMPILATION
	ApplicationDescriptionStruct();
	ApplicationDescriptionStruct(const ApplicationDescriptionStruct& cp);
	EnumStatusCode setApplicationUri(const TCHAR* pValue);
	EnumStatusCode setProductUri(const TCHAR* pValue);
	EnumStatusCode setGatewayServerUri(const TCHAR* pValue);
	EnumStatusCode setDiscoveryProfileUri(const TCHAR* pValue);
	EnumStatusCode setDiscoveryUrls(unsigned DiscoveryUrlsCount, const TCHAR** DiscoveryUrls);
	EnumStatusCode getDiscoveryUrls(unsigned* pDiscoveryUrlsCount, TCHAR*** DiscoveryUrls);

	EnumStatusCode set(const ApplicationDescriptionStruct&);
	EnumStatusCode get(ApplicationDescriptionStruct&) const;
	EnumStatusCode set(const OpcUa_ApplicationDescription&);
	EnumStatusCode get(OpcUa_ApplicationDescription&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;


	const ApplicationDescriptionStruct& operator=(const ApplicationDescriptionStruct& cp);
	bool operator==(const ApplicationDescriptionStruct& toCompare) const;
	bool operator!=(const ApplicationDescriptionStruct& toCompare) const;
	bool operator<(const ApplicationDescriptionStruct& toCompare) const;
	bool operator>(const ApplicationDescriptionStruct& toCompare) const;

	int compare(const ApplicationDescriptionStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~ApplicationDescriptionStruct(void);

#endif
}ApplicationDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
