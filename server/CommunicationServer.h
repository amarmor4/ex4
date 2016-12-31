//
// Created by yarden95c on 25/12/16.
//

#ifndef SERVER_COMMUNICATION_H
#define SERVER_COMMUNICATION_H

#include <fstream>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include "../both/Driver.h"
//#include "GameFlow.h"

class CommunicationServer {
private:
    int portNo;
public:
    CommunicationServer();

    Driver *startCommunicate();

    void error(const char *msg);

    ~CommunicationServer();
};


#endif //SERVER_COMMUNICATION_H
