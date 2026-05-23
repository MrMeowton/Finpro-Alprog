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
    // Default Constructor
    Transaction() {
        username = "";
        bookTitle = "";
        borrowDate = "";
        returnDate = "";
    }

    // Parameterized Constructor
    Transaction(
        string username,
        string bookTitle,
        string borrowDate,
        string returnDate = "-"
    ) {
        this->username = username;
        this->bookTitle = bookTitle;
        this->borrowDate = borrowDate;
        this->returnDate = returnDate;
    }

    // Getter
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

    // Setter
    void setReturnDate(string returnDate) {
        this->returnDate = returnDate;
    }

    // Display Transaction
    void displayTransaction() const {
        cout << "==============================" << endl;
        cout << "Username     : " << username << endl;
        cout << "Book Title   : " << bookTitle << endl;
        cout << "Borrow Date  : " << borrowDate << endl;
        cout << "Return Date  : " << returnDate << endl;
        cout << "==============================" << endl;
    }
};