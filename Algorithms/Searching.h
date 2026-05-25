#pragma once

#include <iostream>
#include <vector>
#include "../models/Book.h"
#include <string>

using namespace std;

class Searching {
public:

    // mencari berdasarkan judul dengan linear search

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

    // mencari berdasarkan author dengan linear search

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

    // mengecek apakah data sudah terurut berdasarkan ID

    static bool isSortedById(
        vector<Book>& books
    ) {

        for (int i = 0; i < books.size() - 1; i++) {

            if (books[i].getId() > books[i + 1].getId()) {
                return false;
            }
        }

        return true;
    }

    // mengecek apakah data sudah terurut berdasarkan title

    static bool isSortedByTitle(
        vector<Book>& books
    ) {

        for (int i = 0; i < books.size() - 1; i++) {

            if (books[i].getTitle() > books[i + 1].getTitle()) {
                return false;
            }
        }

        return true;
    }

    // mencari berdasarkan ID dengan binary search

    static Book* binarySearchById(
        vector<Book>& books,
        int targetId
    ) {

        // cek apakah data sudah sorted
        if (!isSortedById(books)) {
            return nullptr;
        }

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

    // mencari berdasarkan title dengan binary search

    static Book* binarySearchByTitle(
        vector<Book>& books,
        string target
    ) {

        // cek apakah data sudah sorted
        if (!isSortedByTitle(books)) {
            return nullptr;
        }

        int left = 0;
        int right = books.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (books[mid].getTitle() == target) {
                return &books[mid];
            }

            if (books[mid].getTitle() < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return nullptr;
    }
};