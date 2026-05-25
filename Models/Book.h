#pragma once

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    string category;
    int stock;

public:
    // Default Constructor
    Book() {
        id = 0;
        title = "";
        author = "";
        category = "";
        stock = 0;
    }

    // Parameterized Constructor
    Book(int id, string title, string author, string category, int stock) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->category = category;
        this->stock = stock;
    }

    // Getter
    int getId() const {
        return id;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getCategory() const {
        return category;
    }

    int getStock() const {
        return stock;
    }

    // Setter
    void setStock(int stock) {
        this->stock = stock;
    }

    // Display Book Information
    void displayBook() const {
        cout << "==========================" << endl;
        cout << "Book ID   : " << id << endl;
        cout << "Title     : " << title << endl;
        cout << "Author    : " << author << endl;
        cout << "Category  : " << category << endl;
        cout << "Stock     : " << stock << endl;
        cout << "==========================" << endl;
    }
};