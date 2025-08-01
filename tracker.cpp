#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <ctime>


using namespace std;

struct Transaction {
    string description;
    double amount;
    string date;
};

string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    ostringstream oss;
    oss << put_time(ltm, "%Y-%m-%d");
    return oss.str();
}

void newTransactions(vector<Transaction>& transactions) {
    string transactionDescription, amountInput;
    double transactionAmount;

    cout << "\033[1;33m📝 Enter transaction description: \033[0m";
    getline(cin, transactionDescription);
    if (transactionDescription.empty()) {
        cout << "\033[1;31m⚠️ Description cannot be empty!\033[0m" << endl;
        return;
    }

    cout << "\033[1;33m💵 Enter transaction amount (use - for expenses): \033[0m";
    getline(cin, amountInput);
    try {
        transactionAmount = stod(amountInput);
    } catch (...) {
        cout << "\033[1;31m❌ Invalid amount!\033[0m" << endl;
        return;
    }

    Transaction newTransaction;
    newTransaction.description = transactionDescription;
    newTransaction.amount = transactionAmount;
    newTransaction.date = getCurrentDate();
    transactions.push_back(newTransaction);

    cout << "\033[1;32m✅ Transaction added: " << transactionDescription 
         << " | Amount: " << transactionAmount << "$ | Date: " << newTransaction.date << "\033[0m" << endl;
}

void viewTransactions(const vector<Transaction>& transactions) {
    if (transactions.empty()) {
        cout << "\033[1;33m📂 No transactions to display.\033[0m" << endl;
        return;
    }

    cout << "\033[1;36m--- 📄 Transaction History ---\033[0m" << endl;
    for (size_t i = 0; i < transactions.size(); i++) {
        cout << i + 1 << ". " << transactions[i].description << " — " << transactions[i].amount << "$" << " on \033[1;36m" << transactions[i].date << "\033[0m" << endl;
    }
}

void calculateBalance(const vector<Transaction>& transactions) {
    double currentBalance = 0;

    if (transactions.empty()) {
        cout << "\033[1;33m⚠️ No transactions available.\033[0m" << endl;
        return;
    }

    for (size_t i = 0; i < transactions.size(); i++) {
        currentBalance += transactions[i].amount;
    }

    cout << "\033[1;36m💰 Your current balance: \033[1;32m" 
         << currentBalance << "$\033[0m" << endl;
}

int main() {
    vector<Transaction> transactions;

    cout << "\033[1;36m👋 Welcome to Personal Budget Tracker!\033[0m" << endl;
    cout << "\033[1;33mTip: Use negative values for expenses and positive for income.\033[0m\n" << endl;

    while (true) {
        cout << "\n\033[1;36m============================\033[0m" << endl;
        cout << "\033[1;36m      📊 Main Menu           \033[0m" << endl;
        cout << "\033[1;36m============================\033[0m" << endl;
        cout << "\033[1;33m👉 (1) Add a new transaction\033[0m" << endl;
        cout << "\033[1;33m📄 (2) Show my transactions\033[0m" << endl;
        cout << "\033[1;33m💵 (3) Show current balance\033[0m" << endl;
        cout << "\033[1;33m🚪 (4) Exit the tracker\033[0m" << endl;
        cout << "\033[1;36m----------------------------\033[0m" << endl;
        cout << "\033[1;36mYour choice: \033[0m";

        int choice;
        if (!(cin >> choice)) {
            cout << "\033[1;31m❌ Invalid input! Please enter a number.\033[0m" << endl;
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
            cout << "\033[1;36m👋 Thanks for using Personal Budget Tracker. Stay financially smart!\033[0m" << endl;
            break;
        } else {
            cout << "\033[1;31m❌ Invalid choice! Select 1-4.\033[0m" << endl;
        }
    }

    return 0;
}
