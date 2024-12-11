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
    // Default Constructor
    BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0) {}

    // Parameterized Constructor
    BankAccount(int accNum, string name, double bal) 
        : accountNumber(accNum), accountHolderName(name), balance(bal) {}

    // Accessor for Account Number
    int getAccountNumber() { return accountNumber; }

    // Function to Deposit Money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " to account " << accountNumber << " successfully.\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    // Function to Withdraw Money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from account " << accountNumber << " successfully.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            cout << "Invalid withdrawal amount!\n";
        }
    }

    // Function to Display Account Details
    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber
             << ", Holder: " << accountHolderName
             << ", Balance: $" << balance << "\n";
    }
};

// Class for the Banking System
class BankingSystem {
private:
    BankAccount accounts[100];
    int accountCount;

public:
    // Constructor
    BankingSystem() : accountCount(0) {}

    // Function to Add a New Account
    void addAccount() {
        if (accountCount < 100) {
            int accNum;
            string name;
            double bal;

            cout << "Enter Account Number: ";
            cin >> accNum;
            cin.ignore(); // Clear input buffer
            cout << "Enter Account Holder Name: ";
            getline(cin, name);
            cout << "Enter Initial Balance: ";
            cin >> bal;

            if (bal < 0) {
                cout << "Initial balance cannot be negative!\n";
                return;
            }

            accounts[accountCount] = BankAccount(accNum, name, bal);
            accountCount++;
            cout << "Account created successfully.\n";
        } else {
            cout << "Account limit reached! Cannot add more accounts.\n";
        }
    }

    // Function to Perform Transaction
    void performTransaction() {
        int accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getAccountNumber() == accNum) {
                string type;
                double amount;

                cout << "Enter Transaction Type (deposit/withdraw): ";
                cin >> type;
                cout << "Enter Amount: ";
                cin >> amount;

                if (type == "deposit") {
                    accounts[i].deposit(amount);
                } else if (type == "withdraw") {
                    accounts[i].withdraw(amount);
                } else {
                    cout << "Invalid transaction type!\n";
                }
                return;
            }
        }
        cout << "ERROR: Account not found.\n";
    }

    // Function to Display All Accounts
    void displayAllAccounts() {
        if (accountCount == 0) {
            cout << "No accounts in the system.\n";
        } else {
            for (int i = 0; i < accountCount; i++) {
                accounts[i].displayAccountDetails();
            }
        }
    }
};

// Main Function
int main() {
    BankingSystem bank;
    int choice;

    do {
        cout << "\n=== Banking System Menu ===\n";
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
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
