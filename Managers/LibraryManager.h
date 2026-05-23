#pragma once

#include <iostream>

#include "../models/Book.h"
#include "../structures/LinkedList.h"

using namespace std;

class LibraryManager {
private:
    LinkedList<Book> books;

public:
    // Add Book
    void addBook(Book book) {
        books.insert(book);

        cout << endl;
        cout << "[SUCCESS] Book added successfully!" << endl;
    }

    // Display All Books
    void displayBooks() {
        if (books.isEmpty()) {
            cout << endl;
            cout << "[INFO] No books available." << endl;
            return;
        }

        books.display();
    }

    // Search Book By ID
    Book* searchBookById(int id) {
        Node<Book>* current = books.getHead();

        while (current != nullptr) {
            if (current->data.getId() == id) {
                return &(current->data);
            }

            current = current->next;
        }

        return nullptr;
    }

    // Borrow Book
    bool borrowBook(int id) {
        Book* book = searchBookById(id);

        if (book == nullptr) {
            cout << endl;
            cout << "[ERROR] Book not found!" << endl;
            return false;
        }

        if (book->getStock() <= 0) {
            cout << endl;
            cout << "[ERROR] Book out of stock!" << endl;
            return false;
        }

        book->setStock(book->getStock() - 1);

        cout << endl;
        cout << "[SUCCESS] Book borrowed successfully!" << endl;

        return true;
    }

    // Return Book
    void returnBook(int id) {
        Book* book = searchBookById(id);

        if (book == nullptr) {
            cout << endl;
            cout << "[ERROR] Book not found!" << endl;
            return;
        }

        book->setStock(book->getStock() + 1);

        cout << endl;
        cout << "[SUCCESS] Book returned successfully!" << endl;
    }
};