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
    User() {
        username = "";
        password = "";
        role = "";
    }

    User(string username, string password, string role) {
        this->username = username;
        this->password = password;
        this->role = role;
    }

    virtual ~User() {}

    bool login(string inputUsername, string inputPassword) {
        return (username == inputUsername && password == inputPassword);
    }

    string getUsername() const {
        return username;
    }

    string getRole() const {
        return role;
    }

    virtual void showMenu() = 0;
};