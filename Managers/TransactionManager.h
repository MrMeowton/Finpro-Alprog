#pragma once

#include <iostream>

#include "../models/Transaction.h"
#include "../structures/LinkedList.h"

using namespace std;

class TransactionManager {
private:
    LinkedList<Transaction> transactions;

public:
    // Add Transaction
    void addTransaction(Transaction transaction) {
        transactions.insert(transaction);

        cout << endl;
        cout << "[SUCCESS] Transaction saved!" << endl;
    }

    // Display Transactions
    void displayTransactions() {

        if (transactions.isEmpty()) {
            cout << endl;
            cout << "[INFO] No transactions available." << endl;
            return;
        }

        Node<Transaction>* current = transactions.getHead();

        while (current != nullptr) {
            current->data.displayTransaction();
            current = current->next;
        }
    }
};