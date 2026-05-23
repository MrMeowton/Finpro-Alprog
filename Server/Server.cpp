#include <iostream>
#include <thread>

#include <winsock2.h>
#include <ws2tcpip.h>

#include "../networking/SocketHandler.h"
#include "../networking/JsonHandler.h"

#include "../managers/LibraryManager.h"

#include "../networking/json.hpp"

using json = nlohmann::json;
using namespace std;

void handleClient(SOCKET clientSocket, LibraryManager* library) {
    char buffer[4096];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);

    if (bytesReceived <= 0) {
        closesocket(clientSocket);
        return;
    }

    string requestString(buffer, bytesReceived);
    json request = json::parse(requestString);
    string action = request["action"];

    cout << endl;
    cout << "[CLIENT REQUEST] " << requestString << endl;

    // SEARCH REQUEST

    if (action == "search") {
        string keyword = request["keyword"];
        vector<Book> books = library->convertToVector();
        Book* result = Searching::linearSearchByTitle(books, keyword);
        string response;

        if (result == nullptr) {
            response = JsonHandler::createResponse("failed", "Book not found");
        } else {
            response = JsonHandler::createResponse("success", "Book found");
        }

        send(clientSocket, response.c_str(), response.size(), 0);
    }

    if (action == "view") {
    vector<Book> books = library->convertToVector();
    json response;
    response["status"] = "success";
    response["books"] = json::array();

    for (Book& book : books) {
        json item;

        item["id"] = book.getId();
        item["title"] = book.getTitle();
        item["author"] = book.getAuthor();
        item["stock"] = book.getStock();
        response["books"].push_back(item);
    }

    string responseString = response.dump();

    send(clientSocket, responseString.c_str(), responseString.size(), 0);
    }

    if (action == "borrow") {
    int bookId = request["book_id"];
    bool success = library->borrowBook(bookId);
    string response;

    if (success) {
        response = JsonHandler::createResponse("success", "Borrow successful");
    } else {
        response = JsonHandler::createResponse("failed", "Borrow failed");
    }

    send(clientSocket, response.c_str(), response.size(), 0);
    }

    closesocket(clientSocket);
}

int main() {
    SocketHandler::initializeWinsock();
    SOCKET serverSocket = SocketHandler::createSocket();
    sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));
    listen(serverSocket, SOMAXCONN);

    cout << "==================================" << endl;
    cout << " SMART LIBRARY SERVER RUNNING" << endl;
    cout << " PORT : 8080" << endl;
    cout << "==================================" << endl;
    
    // LOCAL DATA
    LibraryManager library;

    library.loadBooksFromFile();
   
    // ACCEPT CLIENT LOOP
    while (true) {
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);

        cout << endl;
        cout << "[NEW CLIENT CONNECTED]" << endl;

        thread clientThread(handleClient, clientSocket, &library );

        clientThread.detach();
    }

    closesocket(serverSocket);
    WSACleanup();

    return 0;
}