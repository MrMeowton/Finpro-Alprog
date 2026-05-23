#include <iostream>

#include <winsock2.h>
#include <ws2tcpip.h>

#include "../networking/SocketHandler.h"
#include "../networking/JsonHandler.h"

using namespace std;

int main() {
    SocketHandler::initializeWinsock();
    SOCKET clientSocket = SocketHandler::createSocket();
    sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);

    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    connect( clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));

    cout << "==================================" << endl;
    cout << " SMART LIBRARY CLIENT" << endl;
    cout << "==================================" << endl;

    string keyword;

    cout << endl;
    cout << "Search Book Title : ";
    getline(cin, keyword);

    string request = JsonHandler::createSearchRequest(keyword);

    send(clientSocket, request.c_str(), request.size(), 0);

    char buffer[4096];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);

    string response(buffer, bytesReceived);

    cout << endl;
    cout << "[SERVER RESPONSE]" << endl;
    cout << response << endl;

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}