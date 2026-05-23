#pragma once

#include <iostream>
#include <vector>

#include "../models/Book.h"

using namespace std;

class Searching {
public:

    // =========================
    // LINEAR SEARCH BY TITLE
    // =========================

    static Book* linearSearchByTitle(
        vector<Book>& books,
        string keyword
    ) {

        for (Book& book : books) {

            if (book.getTitle() == keyword) {
                return &book;
            }
        }

        return nullptr;
    }

    // =========================
    // LINEAR SEARCH BY AUTHOR
    // =========================

    static Book* linearSearchByAuthor(
        vector<Book>& books,
        string keyword
    ) {

        for (Book& book : books) {

            if (book.getAuthor() == keyword) {
                return &book;
            }
        }

        return nullptr;
    }

    // =========================
    // BINARY SEARCH BY ID
    // =========================

    static Book* binarySearchById(
        vector<Book>& books,
        int targetId
    ) {

        int left = 0;
        int right = books.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (books[mid].getId() == targetId) {
                return &books[mid];
            }

            if (books[mid].getId() < targetId) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return nullptr;
    }
};