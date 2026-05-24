#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "../networking/SocketHandler.h"
#include "../networking/JsonHandler.h"
#include "../networking/json.hpp"

using json = nlohmann::json;
using namespace std;

int main() {
    while (true) {
        SocketHandler::initializeWinsock();

        SOCKET clientSocket =SocketHandler::createSocket();
        sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(8080);

        inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);
        connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));

        cout << endl;
        cout << "==================================" << endl;
        cout << " SMART LIBRARY CLIENT" << endl;
        cout << "==================================" << endl;
        cout << "1. View Books" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Borrow Book" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << endl;
        cout << "Choose : ";
        cin >> choice;
        cin.ignore();

        string request;
        // VIEW BOOKS
        if (choice == 1) {
            request = JsonHandler::createViewBooksRequest();
        }
        // SEARCH BOOK
        else if (choice == 2) {
            string keyword;

            cout << endl;
            cout << "Search Title : ";

            getline(cin, keyword);

            request = JsonHandler::createSearchRequest(keyword);
        }
        // BORROW BOOK
        else if (choice == 3) {
            int id;

            cout << endl;
            cout << "Book ID : ";
            cin >> id;

            request = JsonHandler::createBorrowRequest(id);
        }

        // EXIT

        else if (choice == 4) {
            closesocket(clientSocket);
            WSACleanup();
            break;
        }

        send(clientSocket, request.c_str(), request.size(), 0);

        char buffer[4096];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        string response(buffer, bytesReceived);

        cout << endl;
        cout << "[SERVER RESPONSE]" << endl;

        json responseJson = json::parse(response);

        // VIEW RESULT
        if (responseJson.contains("books")) {
            for (auto& book : responseJson["books"]) {

                cout << "==========================" << endl;
                cout << "Book ID   : " << book["id"] << endl;
                cout << "Title     : " << book["title"] << endl;
                cout << "Author    : " << book["author"] << endl;
                cout << "Stock     : " << book["stock"] << endl;
            }
        }

        // NORMAL RESPONSE
        else {
            cout << response << endl;
        }

        closesocket(clientSocket);
        WSACleanup();

        cout << endl;

        system("pause");
        system("cls");
    }
    return 0;
}