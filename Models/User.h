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

    // constructor default
    User() {

        username = "";
        password = "";
        role = "";
    }

    // constructor dengan parameter
    User(string username,
         string password,
         string role) {

        this->username = username;
        this->password = password;
        this->role = role;
    }

    // destructor
    virtual ~User() {}

    // validasi login
    bool login(string inputUsername,
               string inputPassword) {

        return (
            username == inputUsername &&
            password == inputPassword
        );
    }

    // getter
    string getUsername() const {
        return username;
    }

    string getRole() const {
        return role;
    }

    // menu virtual
    virtual void showMenu() = 0;
};