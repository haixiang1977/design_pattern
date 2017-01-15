/*
 * opcclient_factory.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: liu
 */

#include <iostream>
#include <opcclient_factory.h>
#include <softing_opcclient.h>

OpcClient* OpcClientFactory::get_opc_client(OPC_CLIENT_VENDOR vendor)
{
	OpcClient* client = NULL;

	std::cout << "OpcClientFactory get_opc_client" << std::endl;
	switch (vendor)
	{
	case SOFTING:
		client = new SoftingOpcClient();
		break;
	default:
		break;
	}

	return client;
}
