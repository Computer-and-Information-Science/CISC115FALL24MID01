#include <iostream>
#include <string>
using namespace std;

// Class for Bank Accounts
class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Default constructor
    BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0) {}

    // Parameterized constructor
    BankAccount(int accNum, string holderName, double initialBalance)
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}

    // Accessor functions
    int getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    // Mutator functions
    void setAccountNumber(int accNum) { accountNumber = accNum; }
    void setAccountHolderName(string holderName) { accountHolderName = holderName; }
    void setBalance(double newBalance) { balance = newBalance; }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    // Display account details
    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Class for Banking System
class BankingSystem {
private:
    BankAccount accounts[100];
    int accountCount;

public:
    // Constructor
    BankingSystem() : accountCount(0) {}

    // Add a new account
    void addAccount() {
        if (accountCount >= 100) {
            cout << "Cannot add more accounts. Limit reached." << endl;
            return;
        }

        int accNum;
        string holderName;
        double initialBalance;

        cout << "Enter Account Number: ";
        cin >> accNum;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, holderName);
        cout << "Enter Initial Balance: ";
        cin >> initialBalance;

        if (initialBalance < 0) {
            cout << "Balance cannot be negative." << endl;
            return;
        }

        accounts[accountCount] = BankAccount(accNum, holderName, initialBalance);
        accountCount++;
        cout << "Account added successfully!" << endl;
    }

    // Perform a transaction
    void performTransaction() {
        int accNum;
        double amount;
        char transactionType;

        cout << "Enter Account Number: ";
        cin >> accNum;

        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getAccountNumber() == accNum) {
                cout << "Enter transaction type (D for Deposit, W for Withdrawal): ";
                cin >> transactionType;
                cout << "Enter amount: ";
                cin >> amount;

                if (transactionType == 'D' || transactionType == 'd') {
                    accounts[i].deposit(amount);
                } else if (transactionType == 'W' || transactionType == 'w') {
                    accounts[i].withdraw(amount);
                } else {
                    cout << "Invalid transaction type." << endl;
                }
                return;
            }
        }

        cout << "Account not found." << endl;
    }

    // Display all accounts
    void displayAllAccounts() const {
        if (accountCount == 0) {
            cout << "No accounts to display." << endl;
            return;
        }

        for (int i = 0; i < accountCount; i++) {
            accounts[i].displayAccountDetails();
            cout << "-------------------------" << endl;
        }
    }
};

int main() {
    BankingSystem bank;
    int choice;

    do {
        cout << "\nBanking System Menu:\n";
        cout << "1. Add Account\n";
        cout << "2. Perform Transaction\n";
        cout << "3. Display All Accounts\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bank.addAccount();
            break;
        case 2:
            bank.performTransaction();
            break;
        case 3:
            bank.displayAllAccounts();
            break;
        case 4:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
