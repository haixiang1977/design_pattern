/*
 * softing_opcclient.h
 *
 *  Created on: Jan 15, 2017
 *      Author: liu
 */

#ifndef SOFTING_OPCCLIENT_H_
#define SOFTING_OPCCLIENT_H_

#include "opcclient.h"

class SoftingOpcClient : public OpcClient {
public:
	SoftingOpcClient() {};
	~SoftingOpcClient() {};

	int open();
	int close();
	int connect();
	int disconnect();
	int subscribe();
	int unsubscribe();
	int monitor();
private:
	// FIX ME !!!
};

#endif /* SOFTING_OPCCLIENT_H_ */
