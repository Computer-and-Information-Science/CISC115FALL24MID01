#include <iostream>
#include <string>
using namespace std;

// Class representing a bank account
class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Default constructor
    BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0) {}

    // Parameterized constructor
    BankAccount(int accNum, string holderName, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = holderName;
        balance = (initialBalance >= 0) ? initialBalance : 0.0;
    }

    // Getter and setter for account number
    int getAccountNumber() const { return accountNumber; }
    void setAccountNumber(int accNum) { accountNumber = accNum; }

    // Getter and setter for account holder name
    string getAccountHolderName() const { return accountHolderName; }
    void setAccountHolderName(string name) { accountHolderName = name; }

    // Getter and setter for balance
    double getBalance() const { return balance; }
    void setBalance(double bal) { balance = (bal >= 0) ? bal : 0.0; }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount. Must be greater than zero.\n";
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance. Withdrawal failed.\n";
        } else {
            cout << "Invalid withdrawal amount. Must be greater than zero.\n";
        }
    }

    // Function to display account details
    void displayDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// Class to manage multiple bank accounts
class BankSystem {
private:
    BankAccount accounts[100];
    int accountCounter;

public:
    // Default constructor
    BankSystem() : accountCounter(0) {}

    // Function to add a new account
    void addAccount() {
        if (accountCounter < 100) {
            int accNum;
            string holderName;
            double initialBalance;

            cout << "Enter Account Number: ";
            cin >> accNum;
            cin.ignore();
            cout << "Enter Account Holder Name: ";
            getline(cin, holderName);
            cout << "Enter Initial Balance: ";
            cin >> initialBalance;

            if (initialBalance >= 0) {
                accounts[accountCounter] = BankAccount(accNum, holderName, initialBalance);
                accountCounter++;
                cout << "Account added successfully.\n";
            } else {
                cout << "Initial balance cannot be negative. Account creation failed.\n";
            }
        } else {
            cout << "Account limit reached. Cannot add more accounts.\n";
        }
    }

    // Function to perform transactions
    void performTransaction() {
        int accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        // Search for the account
        for (int i = 0; i < accountCounter; i++) {
            if (accounts[i].getAccountNumber() == accNum) {
                char choice;
                double amount;
                cout << "Transaction Type (D for Deposit, W for Withdraw): ";
                cin >> choice;

                if (choice == 'D' || choice == 'd') {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[i].deposit(amount);
                } else if (choice == 'W' || choice == 'w') {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    accounts[i].withdraw(amount);
                } else {
                    cout << "Invalid transaction type.\n";
                }
                return;
            }
        }
        cout << "Account not found.\n";
    }

    // Function to display all account details
    void displayAllAccounts() const {
        if (accountCounter == 0) {
            cout << "No accounts available.\n";
        } else {
            for (int i = 0; i < accountCounter; i++) {
                cout << "Account " << (i + 1) << ":\n";
                accounts[i].displayDetails();
                cout << "-----------------------------\n";
            }
        }
    }
};

// Main function with menu-driven interface
int main() {
    BankSystem bankSystem;
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
                bankSystem.addAccount();
                break;
            case 2:
                bankSystem.performTransaction();
                break;
            case 3:
                bankSystem.displayAllAccounts();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
