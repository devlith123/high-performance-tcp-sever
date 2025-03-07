#include "tcpserver.h"

constexpr int PORT = 8080;
constexpr int BUFFER_SIZE = 1024;

TCPServer::TCPServer() {
#ifdef _WIN32
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cerr << "WSAStartup failed!\n";
		exit(EXIT_FAILURE);
	}
#endif

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_fd == -1) {
		perror("Failed to create Socket");
		exit(EXIT_FAILURE);
	}

	const int opt = 1;
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	sockaddr_in address{};

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(socket_fd, (sockaddr*)&address, sizeof(address)) < 0) {
		perror("Error in binding the socket address");
		exit(EXIT_FAILURE);
	}

	if (listen(socket_fd, 5) < 0) {
		perror("Listen Failed");
		exit(EXIT_FAILURE);
	}

	std::cout << "Listening on the port: " << PORT << std::endl;
}

void TCPServer::run() {
	while (true) {
		sockaddr_in client_address{};
		socklen_t client_len = sizeof(client_address);
		int client_socket = accept(socket_fd, (sockaddr*)&client_address, &client_len);

		if (client_socket < 0) {
			perror("Accept failed");
			continue;
		}

		std::cout << "Client connected!\n";
		std::thread(&TCPServer::handle_client, this, client_socket).detach();
	}
}

void TCPServer::handle_client(int clientSocket) {
	std::array<char, BUFFER_SIZE> buffer{};
	ssize_t bytesReceived = read(clientSocket, buffer.data(), buffer.size());

	if (bytesReceived > 0) {
		std::cout << "Client: " << std::string_view(buffer.data(), bytesReceived) << std::endl;

		const std::string& response = "Hello from C++20 TCP Server";
		send(clientSocket, response.data(), response.size(), 0);
	}

#ifdef _WIN32
	closesocket(clientSocket);
#else
	close(clientSocket);
#endif
}