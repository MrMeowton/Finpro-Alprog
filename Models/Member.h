#pragma once

#include <iostream>
#include "User.h"

using namespace std;

class Member : public User {
public:
    // Default Constructor
    Member() : User() {}

    // Parameterized Constructor
    Member(string username, string password)
        : User(username, password, "member") {}

    // Override Menu
    void showMenu() override {
        cout << endl;
        cout << "========== MEMBER MENU ==========" << endl;
        cout << "1. View Books" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Borrow Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Logout" << endl;
        cout << "=================================" << endl;
    }
};