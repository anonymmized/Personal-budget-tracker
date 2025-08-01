#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Transaction {
    string description;
    double amount;
};

void newTransactions(vector<Transaction>& transactions) {
    string transactionDescription, amountInput;
    double transactionAmount;
    cout << "\033[32mEnter transaction description: \033[0m";
    getline(cin, transactionDescription);
    if (transactionDescription.empty()) {
        cout << "\033[32mTransaction description cannot be empty!\033[0m" << endl;
        return;
    }

    cout << "\033[32mEnter transaction amount: \033[0m";
    getline(cin, amountInput);
    try {
        transactionAmount = stod(amountInput);
    } catch(...) {
        cout << "\033[32mInvalid amount!\033[0m" << endl;
        return;
    }
    
    Transaction newTransaction;
    newTransaction.description = transactionDescription;
    newTransaction.amount = transactionAmount;
    transactions.push_back(newTransaction);
    cout << "\033[32mTransaction added: " << transactionDescription <<  " - Amount: " << transactionAmount << "$\033[0m" << endl;

}

void viewTransactions(const vector<Transaction>& transactions) {
    if (transactions.empty()) {
        cout << "\033[32mNo transactions!\033[0m" << endl;
        return;
    }

    cout << "\033[32m--- Transactions list ---\033[0m" << endl;
    for (size_t i = 0; i < transactions.size(); i++) {
        cout << i + 1 << "\033[32m. " << transactions[i].description << " - " << transactions[i].amount << "$\033[0m" << endl;
    }
}

void calculateBalance(const vector<Transaction>& transactions) {
    double currentBalance;

    if (transactions.empty()) {
        cout << "\033[32mNo transactions!\033[0m" << endl;
        return;
    }

    
    for (size_t i = 0; i < transactions.size(); i++){ 
        currentBalance = currentBalance + transactions[i].amount;
    }
    cout << "\033[32mCurrent Balance: " << currentBalance << "\033[0m" << endl;

}

int main() {
    vector<Transaction> transactions;
    cout << "\033[31mWelcome to Personal Budget Tracker!\033[0m" << endl;
    cout << "\033[32mEnter the amount needs to be like this: -123 means expenditure 123 means income\033[0m" << endl;
    while (true) {
        cout << "\033[31m--- Menu ---\033[0m" << endl;
        cout << "\033[31m1. Add transaction\033[0m" << endl;
        cout << "\033[31m2. View transactions\033[0m" << endl;
        cout << "\033[31m3. View current balance\033[0m" << endl;
        cout << "\033[31m4. Exit\033[0m" << endl;
        cout << "\033[35mEnter your choice (1-3): \033[0m";
        int choice;
        if (!(cin >> choice)) {
            cout << "\033[33mInvalid input! Enter a number.\033[0m" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');
        if (choice == 1) {
            newTransactions(transactions);
        } else if (choice == 2) {
            viewTransactions(transactions);
        } else if (choice == 3) {
            calculateBalance(transactions);
        } else if (choice == 4) {
            cout << "\033[34mThanks for using Personal Budget Tracker!\033[0m" << endl;
            break;
        }
    }
    return 0;
}