#pragma once

#include <iostream>

using namespace std;

class Transaction {
private:
    string username;
    string bookTitle;
    string type;

public:

    Transaction() {

        username = "";
        bookTitle = "";
        type = "";
    }

    Transaction(string username,
                string bookTitle,
                string type) {

        this->username = username;
        this->bookTitle = bookTitle;
        this->type = type;
    }

    string getUsername() {
        return username;
    }

    string getBookTitle() {
        return bookTitle;
    }

    string getType() {
        return type;
    }

    void displayTransaction() {

        cout << "Username : " << username << endl;
        cout << "Book     : " << bookTitle << endl;
        cout << "Type     : " << type << endl;
    }
};