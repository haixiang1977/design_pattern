/*
 * softing_opcclient.h
 *
 *  Created on: Jan 15, 2017
 *      Author: liu
 */

#ifndef SOFTING_OPCCLIENT_H_
#define SOFTING_OPCCLIENT_H_

#include "opcclient.h"

#include "Toolbox.h"
#include "Application.h"
#include "ClientSession.h"
#include "Constants.h"
#include "UserIdentityToken.h"

#include "ClientSubscription.h"
#include "ClientMonitoredItem.h"

using namespace SoftingOPCToolbox5;

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
	void initApplicationDescription(ApplicationDescription&);
	ApplicationPtr m_app;
	Client::SessionPtr m_session;
	SoftingOPCToolbox5::Client::SubscriptionPtr m_subscription; // one subscription for one or multiple items
	SoftingOPCToolbox5::Client::MonitoredItemPtr m_monitoritem; // one moinitor item for one node, later to be vector
};

#endif /* SOFTING_OPCCLIENT_H_ */
