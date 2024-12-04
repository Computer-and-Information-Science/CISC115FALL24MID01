#include <iostream>
#include <string>
using namespace std;

// Class to represent a bank account
class BankAccount {
    int accountNumber;          // Unique account number
    string accountHolderName;   // Name of the account holder
    double balance;             // Account balance

public:
    // Default Constructor
    BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0) {}

    // Parameterized Constructor
    BankAccount(int accNum, string accHolder, double initBalance)
        : accountNumber(accNum), accountHolderName(accHolder), balance(initBalance) {}

    // Getter for account number
    int getAccountNumber() const { return accountNumber; }

    // Deposit money into the account (amount must be positive)
    void deposit(double amount) { 
        balance += (amount > 0) ? amount : 0; 
    }

    // Withdraw money from the account (ensure sufficient balance)
    void withdraw(double amount) { 
        if (amount > 0 && amount <= balance) 
            balance -= amount; 
        else 
            cout << "Invalid or insufficient funds.\n"; 
    }

    // Display account details
    void display() const { 
        cout << "Account Number: " << accountNumber 
             << ", Holder: " << accountHolderName 
             << ", Balance $" << balance << endl; 
    }
};

// Class to manage the banking system
class BankSystem {
    BankAccount accounts[100];  // Array to store up to 100 accounts
    int accountCount = 0;       // Counter for the number of accounts

public:
    // Add a new account to the system
    void addAccount() {
        int accNum;
        string accHolder;
        double initBalance;

        cout << "Enter Account Number: ";
        cin >> accNum;
        cin.ignore();  // Clear input buffer
        cout << "Enter Account Holder Name: ";
        getline(cin, accHolder);
        cout << "Enter Initial Balance: ";
        cin >> initBalance;

        // Validate initial balance and ensure account limit is not exceeded
        if (initBalance >= 0 && accountCount < 100) {
            accounts[accountCount++] = BankAccount(accNum, accHolder, initBalance);
            cout << "Account created successfully.\n";
        } else {
            cout << "Failed to create account.\n";
        }
    }

    // Perform a deposit or withdrawal transaction on an account
    void performTransaction() {
        int accNum;
        char type;
        double amount;

        cout << "Enter Account Number: ";
        cin >> accNum;

        // Search for the account by account number
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getAccountNumber() == accNum) {
                cout << "Enter Transaction Type (D/W): ";
                cin >> type;
                cout << "Enter Amount: ";
                cin >> amount;

                // Perform deposit or withdrawal based on the transaction type
                (type == 'D' || type == 'd') ? accounts[i].deposit(amount) : accounts[i].withdraw(amount);
                return;
            }
        }
        cout << "Account not found.\n";  // Display error if account is not found
    }

    // Display details of all accounts in the system
    void displayAllAccounts() const {
        if (accountCount == 0) 
            cout << "No accounts in the system.\n";
        else 
            for (int i = 0; i < accountCount; i++) 
                accounts[i].display();
    }
};

// Main function to provide a menu-driven interface
int main() {
    BankSystem bankSystem;
    int choice;

    while (true) {
        // Display menu options
        cout << "\n=== Banking System menu ===\n"
             << "1. Add Account\n2. Perform Transaction\n3. Display All Accounts\n4. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        // Perform action based on user choice
        if (choice == 1) 
            bankSystem.addAccount();
        else if (choice == 2) 
            bankSystem.performTransaction();
        else if (choice == 3) 
            bankSystem.displayAllAccounts();
        else if (choice == 4) 
            break;  // Exit the loop
        else 
            cout << "Invalid choice.\n";
    }

    return 0;
}
