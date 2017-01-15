/*
 * opcclient_factory.h
 *
 *  Created on: Jan 15, 2017
 *      Author: liu
 */

#ifndef OPCCLIENT_FACTORY_H_
#define OPCCLIENT_FACTORY_H_

#include "opcclient.h"

class OpcClientFactory {
public:
	enum OPC_CLIENT_VENDOR {
		SOFTING
	};

	virtual ~OpcClientFactory() {};
	static OpcClient* get_opc_client(OPC_CLIENT_VENDOR vendor);
};

#endif /* OPCCLIENT_FACTORY_H_ */
