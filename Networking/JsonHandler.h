#pragma once

#include <iostream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class JsonHandler {
public:
    // CREATE LOGIN REQUEST
    static string createLoginRequest(string username, string password) {
        json request;

        request["action"] = "login";
        request["username"] = username;
        request["password"] = password;

        return request.dump();
    }

    // CREATE SEARCH REQUEST
    static string createSearchRequest(string keyword) {
        json request;

        request["action"] = "search";
        request["keyword"] = keyword;

        return request.dump();
    }

    // CREATE BORROW REQUEST
    static string createBorrowRequest(int bookId) {
        json request;

        request["action"] = "borrow";
        request["book_id"] = bookId;

        return request.dump();
    }

    // CREATE RESPONSE
    static string createResponse(string status, string message) {
        json response;

        response["status"] = status;
        response["message"] = message;

        return response.dump();
    }

    static string createViewBooksRequest() {

    json request;

    request["action"] = "view";

    return request.dump();
    }
};