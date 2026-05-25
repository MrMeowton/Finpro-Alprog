#pragma once

#include <vector>
#include <string>
#include "../models/Book.h"

using namespace std;

class Sorting {
public:

    // menyortir berdasarkan judul buku menggunakan algoritma quick sort
    static int partitionByTitle(
        vector<Book>& books,
        int low,
        int high
    ) {

        string pivot = books[high].getTitle();

        int i = low - 1;

        for (int j = low; j < high; j++) {

            if (books[j].getTitle() < pivot) {

                i++;

                swap(books[i], books[j]);
            }
        }

        swap(books[i + 1], books[high]);

        return i + 1;
    }

    static void quickSortByTitle(
        vector<Book>& books,
        int low,
        int high
    ) {

        if (low < high) {

            int pivotIndex =
                partitionByTitle(
                    books,
                    low,
                    high
                );

            quickSortByTitle(
                books,
                low,
                pivotIndex - 1
            );

            quickSortByTitle(
                books,
                pivotIndex + 1,
                high
            );
        }
    }


    // menyortir berdasarkan ID buku menggunakan algoritma quick sort

    static int partitionById(
        vector<Book>& books,
        int low,
        int high
    ) {

        int pivot = books[high].getId();

        int i = low - 1;

        for (int j = low; j < high; j++) {

            if (books[j].getId() < pivot) {

                i++;

                swap(books[i], books[j]);
            }
        }

        swap(books[i + 1], books[high]);

        return i + 1;
    }

    static void quickSortById(
        vector<Book>& books,
        int low,
        int high
    ) {

        if (low < high) {

            int pivotIndex =
                partitionById(
                    books,
                    low,
                    high
                );

            quickSortById(
                books,
                low,
                pivotIndex - 1
            );

            quickSortById(
                books,
                pivotIndex + 1,
                high
            );
        }
    }

    // menyortir berdasarkan stok buku menggunakan algoritma merge sort

    static void merge(
        vector<Book>& books,
        int left,
        int mid,
        int right
    ) {

        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<Book> leftArray(n1);
        vector<Book> rightArray(n2);

        for (int i = 0; i < n1; i++) {
            leftArray[i] = books[left + i];
        }

        for (int j = 0; j < n2; j++) {
            rightArray[j] = books[mid + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {

            if (
                leftArray[i].getStock()
                <=
                rightArray[j].getStock()
            ) {

                books[k] = leftArray[i];
                i++;
            }
            else {

                books[k] = rightArray[j];
                j++;
            }

            k++;
        }

        while (i < n1) {

            books[k] = leftArray[i];

            i++;
            k++;
        }

        while (j < n2) {

            books[k] = rightArray[j];

            j++;
            k++;
        }
    }

    static void mergeSortByStock(
        vector<Book>& books,
        int left,
        int right
    ) {

        if (left < right) {

            int mid =
                left + (right - left) / 2;

            mergeSortByStock(
                books,
                left,
                mid
            );

            mergeSortByStock(
                books,
                mid + 1,
                right
            );

            merge(
                books,
                left,
                mid,
                right
            );
        }
    }
};