#pragma once

#include <iostream>
#include <string>

using namespace std;

class User {
protected:
    string username;
    string password;
    string role;

public:
    // Default Constructor
    User() {
        username = "";
        password = "";
        role = "";
    }

    // Parameterized Constructor
    User(string username, string password, string role) {
        this->username = username;
        this->password = password;
        this->role = role;
    }

    // Virtual Destructor
    virtual ~User() {}

    // Login Validation
    bool login(string inputUsername, string inputPassword) {
        return (username == inputUsername &&
                password == inputPassword);
    }

    // Getter
    string getUsername() const {
        return username;
    }

    string getRole() const {
        return role;
    }

    // Pure Virtual Function
    virtual void showMenu() = 0;
};