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

    // constructor default
    Book() {

        id = 0;
        title = "";
        author = "";
        category = "";
        stock = 0;
    }

    // constructor dengan parameter
    Book(int id,
         string title,
         string author,
         string category,
         int stock) {

        this->id = id;
        this->title = title;
        this->author = author;
        this->category = category;
        this->stock = stock;
    }

    // getter
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

    // setter stock
    void setStock(int stock) {
        this->stock = stock;
    }

    // tampilkan data buku
    void displayBook() const {

        cout << "==========================" << endl;
        cout << "ID       : " << id << endl;
        cout << "Title    : " << title << endl;
        cout << "Author   : " << author << endl;
        cout << "Category : " << category << endl;
        cout << "Stock    : " << stock << endl;
        cout << "==========================" << endl;
    }
};