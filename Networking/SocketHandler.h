#pragma once

#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

class SocketHandler {
public:
    // INITIALIZE WINSOCK
    static void initializeWinsock() {
        WSADATA wsadata;

        int result = WSAStartup(MAKEWORD(2, 2), &wsadata);

        if (result != 0) {
            cout << "[ERROR] WSAStartup failed!" << endl;
            exit(1);
        }
    }

    // CREATE SOCKET
    static SOCKET createSocket() {
        SOCKET serverSocket =
            socket(AF_INET, SOCK_STREAM, 0);

        if (serverSocket == INVALID_SOCKET) {
            cout << "[ERROR] Socket creation failed!" << endl;
            exit(1);
        }
        return serverSocket;
    }
};