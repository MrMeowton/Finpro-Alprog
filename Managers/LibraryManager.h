#pragma once

#include <iostream>
#include <vector>
#include "../models/Book.h"
#include "../structures/LinkedList.h"
#include "../algorithms/Searching.h"
#include "../algorithms/Sorting.h"
#include <fstream>
#include "../networking/json.hpp"

using json = nlohmann::json;
using namespace std;

class LibraryManager {
private:
    LinkedList<Book> books;

public:
    // Menambah buku
    void addBook(Book book) {
        books.insert(book);

        cout << endl;
        cout << "[SUCCESS] Buku berhasil ditambahkan!" << endl;

        saveBooksToFile();
    }

    // Menampilkan semua buku
    void displayBooks() {

    if (books.isEmpty()) {

        cout << endl;
        cout << "[INFO] Tidak ada buku yang tersedia." << endl;

        return;
    }

    Node<Book>* current = books.getHead();

    while (current != nullptr) {

        current->data.displayBook();

        current = current->next;
    }
    }

    // Mencari buku melalui ID
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

    // Meminjam buku
    bool borrowBook(int id) {
        Book* book = searchBookById(id);

        if (book == nullptr) {
            cout << endl;
            cout << "[ERROR] Buku tidak ditemukan!" << endl;
            return false;
        }

        if (book->getStock() <= 0) {
            cout << endl;
            cout << "[ERROR] Tidak ada stok buku!" << endl;
            return false;
        }

        book->setStock(book->getStock() - 1);

        cout << endl;
        cout << "[SUCCESS] Buku berhasil dipinjam!" << endl;

        saveBooksToFile();
        return true;
    }

    // Mengembalikan buku
    void returnBook(int id) {
        Book* book = searchBookById(id);

        if (book == nullptr) {
            cout << endl;
            cout << "[ERROR] Buku tidak ditemukan!" << endl;
            return;
        }

        book->setStock(book->getStock() + 1);

        cout << endl;
        cout << "[SUCCESS] Buku berhasil dikembalikan!" << endl;
    }

    // TAMBAHAN PHASE 3
    // Convert LinkedList → Vector
    vector<Book> convertToVector() {

    vector<Book> tempBooks;

    Node<Book>* current = books.getHead();

    while (current != nullptr) {

        tempBooks.push_back(current->data);

        current = current->next;
    }

    return tempBooks;
    }

    //MENCARI JUDUL
    void searchBookByTitle(string title) {
    vector<Book> tempBooks =
        convertToVector();

    Book* result =
        Searching::linearSearchByTitle(
            tempBooks,
            title
        );

    if (result == nullptr) {

        cout << endl;
        cout << "[INFO] Buku tidak ditemukan!" << endl;

        return;
    }

    cout << endl;
    cout << "===== HASIL PENCARIAN =====" << endl;

    result->displayBook();
    }

    //MENGURUTKAN BERDASARKAN JUDUL
    void sortBooksByTitle() {

    vector<Book> tempBooks =
        convertToVector();

    Sorting::quickSortByTitle(
        tempBooks,
        0,
        tempBooks.size() - 1
    );

    cout << endl;
    cout << "===== URUT BERDASARKAN JUDUL =====" << endl;

    for (Book& book : tempBooks) {
        book.displayBook();
    }
    }

    // MENGURUTKAN BERDASARKAN STOK
    void sortBooksByStock() {
    vector<Book> tempBooks =
        convertToVector();

    Sorting::mergeSortByStock(
        tempBooks,
        0,
        tempBooks.size() - 1
    );

    cout << endl;
    cout << "===== URUT BERDASARKAN STOK =====" << endl;

    for (Book& book : tempBooks) {
        book.displayBook();
    }
    }

    void loadBooksFromFile() {

    ifstream file("data/books.json");

    if (!file.is_open()) {

        cout << "[ERROR] Cannot open books.json!" << endl;

        return;
    }

    json data;

    file >> data;

    for (auto& item : data) {

        Book book(
            item["id"],
            item["title"],
            item["author"],
            item["category"],
            item["stock"]
        );

        books.insert(book);
    }

    file.close();

    cout << endl;
    cout << "[SUCCESS] Books loaded from JSON!" << endl;
    }

    void saveBooksToFile() {

    json data = json::array();

    Node<Book>* current = books.getHead();

    while (current != nullptr) {

        json item;

        item["id"] = current->data.getId();
        item["title"] = current->data.getTitle();
        item["author"] = current->data.getAuthor();
        item["category"] = current->data.getCategory();
        item["stock"] = current->data.getStock();

        data.push_back(item);

        current = current->next;
    }

    ofstream file("data/books.json");

    file << data.dump(4);

    file.close();

    cout << endl;
    cout << "[SUCCESS] Books saved to JSON!" << endl;
    }
};