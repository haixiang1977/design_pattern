/*
 * main.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: liu
 */

/* example to use factory design pattern to implement opc client */

#include <unistd.h>
#include <iostream>
#include "opcclient.h"
#include "opcclient_factory.h"

int main(int argc, char *argv[])
{
    int ret = 0;
    OpcClient* client = NULL;

    std::cout << "Opc Client Hello world" << std::endl;
    client = OpcClientFactory::get_opc_client(OpcClientFactory::SOFTING);
    if (client == NULL) return -1;

    ret = client->open();
    if (ret != 0) return ret;

    ret = client->connect();
    if (ret != 0) return ret;

    ret = client->subscribe();
    if (ret != 0) return ret;

    ret = client->monitor();
    if (ret != 0) return ret;

    while (1)
    {
        sleep(1);
    }

    ret = client->unsubscribe();
    if (ret != 0) return ret;

    ret = client->disconnect();
    if (ret != 0) return ret;

    ret = client->close();
    if (ret != 0) return ret;

    return ret;
}
