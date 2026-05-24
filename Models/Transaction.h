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

    // constructor default
    Transaction() {

        username = "";
        bookTitle = "";
        borrowDate = "";
        returnDate = "-";
    }

    // constructor dengan parameter
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

    // getter
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

    // setter return date
    void setReturnDate(string returnDate) {

        this->returnDate = returnDate;
    }

    // tampilkan transaksi
    void displayTransaction() const {

        cout << "==============================" << endl;
        cout << "Username    : " << username << endl;
        cout << "Book Title  : " << bookTitle << endl;
        cout << "Borrow Date : " << borrowDate << endl;
        cout << "Return Date : " << returnDate << endl;
        cout << "==============================" << endl;
    }
};