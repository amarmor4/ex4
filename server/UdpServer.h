/************************************************************
* File description: UDP header file. the class inherit from	*
* socket. methods of udp socket type						*
************************************************************/

#ifndef UDP_H_
#define UDP_H_

#include "../both/Socket.h"


class UdpServer: public Socket {
public:
	/***********************************************************************
	* function name: Udp												   *
	* The Input: Boolean, true - if server, false if client and port number*
	* The output: none										               *
	* The Function operation: creating new Udp						       *
	***********************************************************************/
	UdpServer(bool isServers, int port_num);
	/***********************************************************************
	* function name: ~Udp												   *
	* The Input: none													   *
	* The output: none										               *
	* The Function operation: default destructor					       *
	***********************************************************************/
	virtual ~UdpServer();
	/***********************************************************************
	* function name: initialize											   *
	* The Input: none              										   *
	* The output: int number representing the return status		           *
	* The Function operation: initialize the Socket object and getting a   *
	* socket descriptor.												   *
	***********************************************************************/
	int initialize();
	/***********************************************************************
	* function name: sendData											   *
	* The Input: string representing the data to send		               *
	* The output: int number representing the return status		           *
	* The Function operation: sending the input data to the socket         *
	* who connect to this socket.										   *
	***********************************************************************/
	int sendData(string data);
	/***********************************************************************
	* function name: recive	`											   *
	* The Input: none										               *
	* The output: int number representing the return status	               *
	* The Function operation: getting data from the other socket and print *
	* the data															   *
	***********************************************************************/
	int reciveData(char* buffer, int size);
};

#endif /* UDP_H_ */
