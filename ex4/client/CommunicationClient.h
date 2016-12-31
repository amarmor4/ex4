//
// Created by yarden95c on 25/12/16.
//

#ifndef CLIENT_COMMUNICATION_H
#define CLIENT_COMMUNICATION_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "../both/Driver.h"


class CommunicationClient {
private:
//    int portNo;
//    struct sockaddr_in serv_addr;
//    struct hostent *hp;
//    Driver* driver;

public:
    CommunicationClient();
    ~CommunicationClient();
    void startCommunicate();

};


#endif //CLIENT_COMMUNICATION_H
