#pragma once

#include <iostream>
#include <fstream>

#include "../models/Transaction.h"
#include "../structures/LinkedList.h"
#include "../networking/json.hpp"

using json = nlohmann::json;
using namespace std;

class TransactionManager {
private:
    LinkedList<Transaction> transactions;

public:

    // tambah transaksi
    void addTransaction(Transaction transaction) {

        transactions.insert(transaction);

        cout << "\nTransaction saved!" << endl;

        saveTransactions();
    }

    // tampilkan transaksi
    void displayTransactions() {

        if (transactions.isEmpty()) {

            cout << "\nNo transactions available!" << endl;

            return;
        }

        Node<Transaction>* current = transactions.getHead();

        while (current != nullptr) {

            current->data.displayTransaction();

            cout << endl;

            current = current->next;
        }
    }

    // load transaksi dari json
    void loadTransactions() {

        ifstream file("data/transactions.json");

        if (!file.is_open()) {

            cout << "\nCannot open transactions.json!" << endl;

            return;
        }

        json data;

        file >> data;

        for (auto& item : data) {

            Transaction transaction(
                item["username"],
                item["book"],
                item["type"]
            );

            transactions.insert(transaction);
        }

        file.close();

        cout << "\nTransactions loaded successfully!" << endl;
    }

    // simpan transaksi ke json
    void saveTransactions() {

        json data = json::array();

        Node<Transaction>* current = transactions.getHead();

        while (current != nullptr) {

            json item;

            item["username"] =
                current->data.getUsername();

            item["book"] =
                current->data.getBookTitle();

            item["type"] =
                current->data.getType();

            data.push_back(item);

            current = current->next;
        }

        ofstream file("data/transactions.json");

        file << data.dump(4);

        file.close();
    }
};