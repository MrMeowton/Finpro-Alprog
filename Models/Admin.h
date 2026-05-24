#pragma once

#include <iostream>
#include "User.h"

using namespace std;

class Admin : public User {
public:

    // constructor default
    Admin() : User() {}

    // constructor dengan parameter
    Admin(string username, string password)
        : User(username, password, "admin") {}

    // menu admin
    void showMenu() override {

        cout << endl;
        cout << "========== ADMIN MENU ==========" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Update Stock" << endl;
        cout << "4. View Transactions" << endl;
        cout << "5. Logout" << endl;
        cout << "================================" << endl;
    }
};