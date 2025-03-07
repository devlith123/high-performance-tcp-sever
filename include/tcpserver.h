#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <iostream>
#include <array>
#include <thread>
#include <vector>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")  // Link Winsock library

#else
#include <unistd.h>
#include <arpa/inet.h>
#endif

class TCPServer {

private:
	int socket_fd;
	void handle_client(int client_socket);

public:
	TCPServer();
	void run();


	~TCPServer() {
      #ifdef _WIN32
		closesocket(socket_fd);
		WSACleanup();
     #else
		close(socket_fd);
     #endif
	}
};

#endif
