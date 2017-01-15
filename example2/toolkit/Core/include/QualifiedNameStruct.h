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

#ifndef __QUALIFIEDNAMESTRUCT_H_
#define __QUALIFIEDNAMESTRUCT_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


/*! A name with an additional namespace index. This type of name is used for specifying BrowseNames (that
* must contain the namespace). */
//lint -sem(QualifiedNameStruct::clear, cleanup)
//lint -sem(QualifiedNameStruct::clear, initializer)
typedef struct QualifiedNameStruct
{
	/*! String containing the name without namespaceindex. */
	TCHAR* pName;

	/*! The namespaceindex to use building a BrowsePath. */
	unsigned short namespaceIndex;


#ifdef OT_COMPILATION
	QualifiedNameStruct();
	EnumStatusCode setName(const TCHAR* pValue);

	EnumStatusCode set(const QualifiedNameStruct&);
	EnumStatusCode get(QualifiedNameStruct&) const;
	EnumStatusCode set(const OpcUa_QualifiedName&);
	EnumStatusCode get(OpcUa_QualifiedName&) const;
	QualifiedNameStruct(const TCHAR* name, unsigned short namespecIndex);
	void setNameAndIndex_API(LPCTSTR name, unsigned short index);
	tstring toString(void) const;
	static EnumStatusCode parse(const tstring& reader,
			bool isReferenceName,
			QualifiedNameStruct& name,
			size_t &sizeConsumed);
	QualifiedNameStruct(const QualifiedNameStruct& cp);

	const QualifiedNameStruct& operator=(const QualifiedNameStruct& cp);
	bool operator==(const QualifiedNameStruct& toCompare) const;
	bool operator!=(const QualifiedNameStruct& toCompare) const;
	bool operator<(const QualifiedNameStruct& toCompare) const;
	bool operator>(const QualifiedNameStruct& toCompare) const;

	int compare(const QualifiedNameStruct* pTarget) const;

	void clear(void);
	~QualifiedNameStruct(void);

#endif
}QualifiedNameStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
