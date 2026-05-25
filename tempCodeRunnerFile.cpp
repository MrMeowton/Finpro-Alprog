#include <iostream>
#include "models/Book.h"
#include "models/Admin.h"
#include "models/Member.h"
#include "models/Transaction.h"
#include "managers/LibraryManager.h"
#include "managers/UserManager.h"
#include "managers/TransactionManager.h"

using namespace std;

int main() {

    // =========================
    // USER LOGIN TEST
    // =========================

    UserManager userManager;

    string username;
    string password;

    cout << "========== LOGIN ==========" << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    User* currentUser = userManager.login(username, password);

    if (currentUser == nullptr) {
        cout << endl;
        cout << "[ERROR] Invalid login!" << endl;
        return 0;
    }

    cout << endl;
    cout << "[SUCCESS] Login successful!" << endl;

    currentUser->showMenu();

    // =========================
    // LIBRARY TEST
    // =========================

    LibraryManager library;

    library.addBook(
        Book(1, "Clean Code", "Robert Martin", "Programming", 3)
    );

    library.addBook(
        Book(2, "Design Patterns",  "Gang of Four", "Software Engineering", 2)
    );

    library.addBook(
        Book(3, "Algorithms", "CLRS", "Computer Science", 5)
    );

    cout << endl;
    cout << "========== BOOK LIST ==========" << endl;
    library.displayBooks();

    // =========================
    // BORROW TEST
    // =========================

    cout << endl;
    cout << "========== BORROW TEST ==========" << endl;
    library.borrowBook(1);

    // =========================
    // DISPLAY UPDATED STOCK
    // =========================

    cout << endl;
    cout << "========== UPDATED BOOK LIST ==========" << endl;
    library.displayBooks();

    // =========================
    // TRANSACTION TEST
    // =========================

    TransactionManager transactionManager;

    transactionManager.addTransaction(
        Transaction(username, "Clean Code", "2026-05-23")
    );

    cout << endl;
    cout << "========== TRANSACTION HISTORY ==========" << endl;
    transactionManager.displayTransactions();

    cout << endl;
    cout << "========== SEARCH TEST ==========" << endl;
    library.searchBookByTitle("Algorithms");

    cout << endl;
    cout << "========== SORT TITLE TEST ==========" << endl;
    library.sortBooksByTitle();

    cout << endl;
    cout << "========== SORT STOCK TEST ==========" << endl;
    library.sortBooksByStock();

    return 0;
}