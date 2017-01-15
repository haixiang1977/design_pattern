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

#ifndef DATATYPEDESCRIPTION_H
#define DATATYPEDESCRIPTION_H

#include "Base.h"
#include "NodeId.h"
#include "FieldDescription.h"

namespace SoftingOPCToolbox5
{
	/*! This is the base class of a user defined data type. */
	class TBC_EXPORT DataTypeDescription
		: public Base
	{
	protected:
		/*! Default constructor */
		DataTypeDescription();
	public:
		/*! Destructor */
		virtual ~DataTypeDescription();

		/*! Indicates the concrete subtype of this DataTypeDescription instance. */
		EnumDataTypeDescriptionType getDescriptionType() const;

		/*! Returns the Name of the DataTypeDescription */
		tstring getName() const;
		/*! Sets the Name of the DataTypeDescription
		* @note	The string must consist of valid UTF8 characters
		*		When the name is empty, then the name will be generated from the BrowseName of the DataType node
		*		during Server::DataType::setDataTypeDescription(). */
		EnumStatusCode setName(tstring name);

		/*! Returns the XML documentation of the field as text.
		* It contains the value of the "Documentation" XML node (plain text and any XML elements) */
		tstring getDocumentation() const;
		/*! Sets the XML documentation of the field as text.
		* It is the value of the "Documentation" XML node (plain text and any XML elements)
		* @note The string must consist of valid UTF8 characters */
		EnumStatusCode setDocumentation(tstring documentation);

		/*! Returns the Version of the DataTypeDescription */
		tstring getVersion() const;
		/*! Sets the Version of the DataTypeDescription
		* @note The string must consist of valid UTF8 characters */
		EnumStatusCode setVersion(tstring version);

		/*! Returns the possible documentation attributes.
		* It contains all attributes of the "Documentation" XML node. */
		EnumStatusCode getDocumentationAttributes(std::vector<std::pair<tstring, tstring> >* pDocumentationAttributes);
		/*! Sets the possible documentation attributes.
		* these are all attributes of the "Documentation" XML node.
		* @note The strings must consist of valid UTF8 characters */
		EnumStatusCode setDocumentationAttributes(std::vector<std::pair<tstring, tstring> >& documentationAttributes);

		/*! Returns the user defined Attributes */
		EnumStatusCode getCustomAttributes(std::vector<std::pair<tstring, tstring> >* pCustomAttributes);
		/*! Sets the user defined Attributes
		* @note The strings must consist of valid UTF8 characters */
		EnumStatusCode setCustomAttributes(std::vector<std::pair<tstring, tstring> >& customAttributes);

	private:
		/*! DataTypeDescription cannot be copied */
		DataTypeDescription(const DataTypeDescription&);
		/*! DataTypeDescription cannot be copied */
		DataTypeDescription& operator=(const DataTypeDescription&);
	};
	typedef ObjectPointer<DataTypeDescription> DataTypeDescriptionPtr;
	typedef ObjectPointer<const DataTypeDescription> DataTypeDescriptionConstPtr;
} // end namespace

#endif	// DATATYPEDESCRIPTION_H
