#pragma once

#include <iostream>
#include <string>

using namespace std;

class Transaction {
private:
    string username;
    string bookTitle;
    string borrowDate;
    string returnDate;

public:
    Transaction() {
        username = "";
        bookTitle = "";
        borrowDate = "";
        returnDate = "";
    }

    Transaction(string username, string bookTitle, string borrowDate, string returnDate = "-") {
        this->username = username;
        this->bookTitle = bookTitle;
        this->borrowDate = borrowDate;
        this->returnDate = returnDate;
    }

    string getUsername() const {
        return username;
    }

    string getBookTitle() const {
        return bookTitle;
    }

    string getBorrowDate() const {
        return borrowDate;
    }

    string getReturnDate() const {
        return returnDate;
    }

    void setReturnDate(string returnDate) {
        this->returnDate = returnDate;
    }

    void displayTransaction() const {
        cout << "==============================" << endl;
        cout << "Username     : " << username << endl;
        cout << "Book Title   : " << bookTitle << endl;
        cout << "Borrow Date  : " << borrowDate << endl;
        cout << "Return Date  : " << returnDate << endl;
        cout << "==============================" << endl;
    }
};