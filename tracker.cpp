#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Transaction {
    string description;
    double amount;
};

//void newTransaction(vector(Transaction)& transactions) {
    
//}

int main() {
    vector<Transaction> transactions;
    cout << "\033[31mWelcome to Personal Budget Tracker!\033[0m" << endl;
    cout << "\033[32mEnter the amount needs to be like this: -123 means expenditure 123 means income\033[0m" << endl;
    while (true) {
        cout << "\033[31m--- Menu ---\033[0m" << endl;
        cout << "\033[31m1. Add transaction\033[0m" << endl;
        cout << "\033[31m2. Exit\033[0m" << endl;
        cout << "\033[35mEnter your choice (1-2): \033[0m";
        int choice;
        if (!(cin >> choice)) {
            cout << "\033[33mInvalid input! Enter a number.\033[0m" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');
        if (choice == 1) {
            cout << "\033[34mFunction in proccessing\033[0m" << endl;
            break;
        } else if (choice == 2) {
            cout << "\033[34mThanks for using Personal Budget Tracker!\033[0m" << endl;
            break;
        }
    }
    return 0;
}