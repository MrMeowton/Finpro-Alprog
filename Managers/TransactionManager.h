#pragma once

#include <iostream>
#include "../models/Transaction.h"
#include "../structures/LinkedList.h"

using namespace std;

class TransactionManager {
private:
    LinkedList<Transaction> transactions;

public:
    // Menambah transaksi
    void addTransaction(Transaction transaction) {
        transactions.insert(transaction);

        cout << endl;
        cout << "[SUCCESS] Transaksi disimpan!" << endl;
    }

    // Menampilkan transaksi
    void displayTransactions() {

        if (transactions.isEmpty()) {
            cout << endl;
            cout << "[INFO] Tidak ada transaksi." << endl;
            return;
        }

        Node<Transaction>* current = transactions.getHead();

        while (current != nullptr) {
            current->data.displayTransaction();
            current = current->next;
        }
    }
};