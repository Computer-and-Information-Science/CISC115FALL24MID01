//
//  Assignment8_Zehr.cpp
//  Homework Week 8
//
//  Created by Isaac Zehr
//
#include <iostream>
#include <string>
using namespace std;

// BankAccount Class
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
    void setAccountHolderName(string name) { accountHolderName = name; }
    void setBalance(double newBalance) { balance = newBalance; }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Deposit amount must be positive.\n";
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds.\n";
        } else {
            cout << "Withdrawal amount must be positive.\n";
        }
    }

    // Display account details
    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// BankSystem Class
class BankSystem {
private:
    BankAccount accounts[100];
    int accountCount;

public:
    // Constructor
    BankSystem() : accountCount(0) {}

    // Add a new account
    void addAccount() {
        if (accountCount >= 100) {
            cout << "Cannot add more accounts. Maximum limit reached.\n";
            return;
        }

        int accNum;
        string holderName;
        double initialBalance;

        cout << "Enter account number: ";
        cin >> accNum;
        cout << "Enter account holder's name: ";
        cin.ignore();
        getline(cin, holderName);
        cout << "Enter initial balance: ";
        cin >> initialBalance;

        if (initialBalance < 0) {
            cout << "Initial balance cannot be negative.\n";
            return;
        }

        accounts[accountCount] = BankAccount(accNum, holderName, initialBalance);
        accountCount++;
        cout << "Account added successfully!\n";
    }

    // Perform a transaction
    void performTransaction() {
        int accNum;
        cout << "Enter account number: ";
        cin >> accNum;

        // Find account
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getAccountNumber() == accNum) {
                char choice;
                double amount;

                cout << "Transaction type (D for Deposit, W for Withdrawal): ";
                cin >> choice;
                cout << "Enter amount: ";
                cin >> amount;

                if (choice == 'D' || choice == 'd') {
                    accounts[i].deposit(amount);
                } else if (choice == 'W' || choice == 'w') {
                    accounts[i].withdraw(amount);
                } else {
                    cout << "Invalid transaction type.\n";
                }
                return;
            }
        }
        cout << "Account not found.\n";
    }

    // Display all accounts
    void displayAllAccounts() const {
        if (accountCount == 0) {
            cout << "No accounts to display.\n";
            return;
        }

        for (int i = 0; i < accountCount; i++) {
            accounts[i].displayAccountDetails();
            cout << "-----------------------------\n";
        }
    }
};

// Main Function
int main() {
    BankSystem bank;
    int choice;

    do {
        cout << "\n--- Banking System Menu ---\n";
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
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
