//
// Created by yarden95c on 25/12/16.
//

#include "CommunicationServer.h"

using namespace std;


CommunicationServer::CommunicationServer() {
    //portNo = portNo1;
}

Driver *CommunicationServer::startCommunicate() {


    const int server_port = 5555;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;

    memset(&sin, 0, sizeof(sin));

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding to socket");
    }

    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);


    char buffer[4096];
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading from socket");
    }

    cout << "The client sent: " <<
                                buffer << endl;

    int sent_bytes = sendto(sock, buffer, bytes, 0, (struct sockaddr *) &from, sizeof(from));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }

    close(sock);





/**
 *
 * insert a new driver to the list of driversInfo in the taxiCenter
 */

    int id, age, experience, cabId;
    Status status;
    char c, statusLetter;

    cin >> id >> c >> age >> c >> statusLetter >> c >>
        experience >> c >> cabId;
    status = Status(statusLetter);
    return new Driver(id, age, status, experience, cabId);
    // set the pointer to point on null so when
    // the object will delete this pointer will no longer point on it




}


void CommunicationServer::error(const char *msg) {
    perror(msg);
    exit(0);
}

CommunicationServer::~CommunicationServer() {

}