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

#ifndef _BuildInfoStruct_H_
#define _BuildInfoStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "DateTimeStruct.h"

/*! Information that describes the build of the software. */
//lint -sem(BuildInfoStruct::clear, cleanup)
//lint -sem(BuildInfoStruct::clear, initializer)
typedef struct BuildInfoStruct
{
	/*! URI that identifies the software. */
	OTChar* pProductUri;

	/*! Name of the software manufacturer. */
	OTChar* pManufacturerName;

	/*! Name of the software. */
	OTChar* pProductName;

	/*! Software version. */
	OTChar* pSoftwareVersion;

	/*! Build number. */
	OTChar* pBuildNumber;

	/*! Date and time of the build. */
	DateTimeStruct buildDate;


#ifdef OT_COMPILATION
	BuildInfoStruct();
	BuildInfoStruct(const BuildInfoStruct&);

	EnumStatusCode setProductUri(const TCHAR* pValue);
	EnumStatusCode setManufacturerName(const TCHAR* pValue);
	EnumStatusCode setProductName(const TCHAR* pValue);
	EnumStatusCode setSoftwareVersion(const TCHAR* pValue);
	EnumStatusCode setBuildNumber(const TCHAR* pValue);
	EnumStatusCode setBuildDate(const DateTimeStruct& value);

	tstring getProductUri() const;
	tstring getManufacturerName() const;
	tstring getProductName() const;
	tstring getSoftwareVersion() const;
	tstring getBuildNumber() const;
	DateTimeStruct getBuildDate() const;

	EnumStatusCode set(const BuildInfoStruct&);
	EnumStatusCode get(BuildInfoStruct&) const;

	EnumStatusCode set(const OpcUa_BuildInfo&);
	EnumStatusCode get(OpcUa_BuildInfo&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;

	const BuildInfoStruct& operator=(const BuildInfoStruct& cp);
	bool operator==(const BuildInfoStruct& toCompare) const;
	bool operator!=(const BuildInfoStruct& toCompare) const;
	bool operator<(const BuildInfoStruct& toCompare) const;
	bool operator>(const BuildInfoStruct& toCompare) const;

	int compare(const BuildInfoStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~BuildInfoStruct(void);
#endif
} BuildInfoStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
