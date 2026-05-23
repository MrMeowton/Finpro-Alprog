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
    // Constructor
    UserManager() {
        admin = Admin("admin", "123");
        member = Member("member", "123");
    }

    // Validate Login
    User* login(string username, string password) {

        if (admin.login(username, password)) {
            return &admin;
        }

        if (member.login(username, password)) {
            return &member;
        }

        return nullptr;
    }
};