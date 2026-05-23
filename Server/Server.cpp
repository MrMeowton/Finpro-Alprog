#include <iostream>
#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "../networking/SocketHandler.h"
#include "../networking/JsonHandler.h"
#include "../managers/LibraryManager.h"
#include "../managers/UserManager.h"
#include "../networking/json.hpp"
#include <mutex>

mutex libraryMutex;
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
    json request;
    try {
        request = json::parse(requestString);
    }
    catch (...) {
        string errorResponse = JsonHandler::createResponse("failed", "Invalid JSON format");

        send(clientSocket, errorResponse.c_str(), errorResponse.size(), 0);
        closesocket(clientSocket);

        return;
    }

    string action = request["action"];

    cout << endl;
    cout << "[CLIENT REQUEST] " << requestString << endl;

    // SEARCH REQUEST
    if (action == "search") {
    string keyword = request["keyword"];
    vector<Book> books;
    {
        lock_guard<mutex> lock(libraryMutex);
        books = library->convertToVector();
    }

    sort(books.begin(), books.end(), [](Book a, Book b) {return a.getTitle() < b.getTitle();});
    Book* result = Searching::binarySearchByTitle( books, keyword);
    json response;

    if (result == nullptr) {
        response["status"] = "failed";
        response["message"] = "Book not found";
    }else {
        response["status"] = "success";
        response["message"] = "Book found";
        response["book"]["id"] = result->getId();
        response["book"]["title"] = result->getTitle();
        response["book"]["author"] = result->getAuthor();
        response["book"]["stock"] = result->getStock();
    }

    string responseString = response.dump();
    send(clientSocket, responseString.c_str(), responseString.size(), 0);
    }

    // VIEW REQUEST
    if (action == "view") {
    vector<Book> books;
    {
        lock_guard<mutex> lock(libraryMutex);
        books = library->convertToVector();
    }
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

    // BORROW REQUEST
    if (action == "borrow") {
    int bookId = request["book_id"];
    bool success;
    {
        lock_guard<mutex> lock(libraryMutex);
        success = library->borrowBook(bookId);
    }

    string response;

    if (success) {
        response = JsonHandler::createResponse("success", "Borrow successful");
    } else {
        response = JsonHandler::createResponse("failed", "Borrow failed");
    }

    send(clientSocket, response.c_str(), response.size(), 0);
    }

    if (action == "login") {

        string username = request["username"];
        string password = request["password"];

        UserManager userManager;

        User* user =
            userManager.login(
                username,
                password
            );

        json response;

        if (user == nullptr) {

            response["status"] = "failed";
            response["message"] = "Invalid login";
        }
        else {

            response["status"] = "success";
            response["message"] = "Login success";
        }

        string responseString = response.dump();

        send(clientSocket,
            responseString.c_str(),
            responseString.size(),
            0);
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