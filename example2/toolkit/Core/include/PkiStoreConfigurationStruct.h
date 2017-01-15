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

#ifndef _PkiStoreConfigurationStruct_H_
#define _PkiStoreConfigurationStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(PkiStoreConfigurationStruct::clear, cleanup)
//lint -sem(PkiStoreConfigurationStruct::clear, initializer)
typedef struct PkiStoreConfigurationStruct
{
	/*! The path to the folder containing trusted client instance certificates
	 * (or the certificate of an issuer in the certificate chain) */
	TCHAR* pCertificateTrustListLocation;

	/*! The path to the folder containing certificates needed for validating a
	 * certificate chain to the root certificate. The certificates (and other certificates
	 * issued by those) are not automatically trusted. This parameter can be an empty string
	 * if addUntrustedCertificatesToChainValidation is set to false. */
	TCHAR* pCertificateUntrustedListLocation;

	/*! The path to the certificate revocation list. The path can be either a specific file
	 * with suffix .crl or a folder containing those files. This parameter can be an empty
	 * string if no CRL checks are specified. */
	TCHAR* pCertificateRevocationListLocation;

	/*! The path to the folder where rejected client certificates will be stored
	 * This parameter can be an empty string (e.g. in case of read-only file systems).
	 * Rejected certificates are not stored in this case. */
	TCHAR* pRejectedCertificateLocation;

	/*! Bit field for validation errors that shall be ignored. */
	EnumCertificateCheck ignoredCertificateChecks;

	/*! The definition how revocation checks shall be done. */
	EnumCrlCheckOption revocationCheckOption;

	/*! A proxy certificate is a certificate which is not a CA but was used to issue other certificates.
	 * This is an usual way to issue certificates, but sometimes necessary in the case that a global root
	 * CA refuses issuing other CA certificates. With this flag set to false the certificate chain
	 * validation will fail if such a proxy certificate is within the chain. Allowing proxy certificates
	 * on the other hand might downgrade security. */
	bool allowProxyCertificates;

	/*! Indicates whether the signature of self-signed certificates shall be verified. */
	bool checkSelfSignedSignature;

	/*! Check whether URI in certificate matches UR in application description. */
	bool checkUrlMatch;

#ifdef OT_COMPILATION
	PkiStoreConfigurationStruct();
	PkiStoreConfigurationStruct(const PkiStoreConfigurationStruct&);

	void initialize_API();

	EnumStatusCode set(const PkiStoreConfigurationStruct&);
	EnumStatusCode get(PkiStoreConfigurationStruct&) const;

	const PkiStoreConfigurationStruct& operator=(const PkiStoreConfigurationStruct& cp);
	bool operator==(const PkiStoreConfigurationStruct& toCompare) const;
	bool operator!=(const PkiStoreConfigurationStruct& toCompare) const;
	bool operator<(const PkiStoreConfigurationStruct& toCompare) const;
	bool operator>(const PkiStoreConfigurationStruct& toCompare) const;

	int compare(const PkiStoreConfigurationStruct* pTarget) const;

	void clear(void);
	~PkiStoreConfigurationStruct(void);
#endif
} PkiStoreConfigurationStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
