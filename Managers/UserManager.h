#pragma once

#include <iostream>

#include "../models/Admin.h"
#include "../models/Member.h"

using namespace std;

class UserManager {
private:
    Admin admin;
    Member member;

public:

    // constructor
    UserManager() {

        admin = Admin("admin", "123");

        member = Member("member", "123");
    }

    // login user
    User* login(string username, string password) {

        if (admin.login(username, password)) {
            return &admin;
        }

        if (member.login(username, password)) {
            return &member;
        }

        cout << "\nUsername or password is wrong!" << endl;

        return nullptr;
    }
};