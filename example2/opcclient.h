/*
 * opcclient.h
 *
 *  Created on: Jan 15, 2017
 *      Author: liu
 */

#ifndef OPCCLIENT_H_
#define OPCCLIENT_H_

/* Interface of OPC Client */
class OpcClient {
public:
	OpcClient() {};
	virtual ~OpcClient() {};

	// called to open and run the client
	virtual int open() = 0;

	// call to shut down the client
	virtual int close() = 0;

	// call to connect to the server
	virtual int connect() = 0;

	// call to disconnect to the server
	virtual int disconnect() = 0;

	// call to subscribe
	virtual int subscribe() = 0;

	// call to unsubscribe
	virtual int unsubscribe() = 0;

	// call to monitor the server items
	virtual int monitor() = 0;
};


#endif /* OPCCLIENT_H_ */
