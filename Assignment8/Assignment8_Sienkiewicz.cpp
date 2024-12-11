#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// BankAccount Class
class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Default Constructor
    BankAccount() {
        accountNumber = 0;
        accountHolderName = "Unknown";
        balance = 0.0;
    }

    // Parameterized Constructor
    BankAccount(int accNum, string holderName, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = holderName;
        balance = initialBalance;
    }

    // Accessor Functions 
    int getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    // Mutator Functions 
    void setAccountNumber(int accNum) {
        accountNumber = accNum;
    }

    void setAccountHolderName(string holderName) {
        accountHolderName = holderName;
    }

    void setBalance(double amount) {
        balance = amount;
    }

    // Function to Deposit Money into Account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Function to Withdraw Money from Account
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
        }
    }

    // Function to Display Account Details
    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

// BankingSystem Class
class BankingSystem {
private:
    BankAccount accounts[100];
    int accountCount; 
public:
    BankingSystem() {
        accountCount = 0;
    }

    // Function to Add a new account
    void addAccount() {
        if (accountCount < 100) {
            int accNum;
            string holderName;
            double initialBalance;

            cout << "Enter account number: ";
            cin >> accNum;
            cin.ignore(); 
            cout << "Enter account holder name: ";
            getline(cin, holderName);
            cout << "Enter initial balance: $";
            cin >> initialBalance;

            // Create a new account and store it in the array
            accounts[accountCount] = BankAccount(accNum, holderName, initialBalance);
            accountCount++;

            cout << "Account created successfully.\n";
        } else {
            cout << "Account limit reached (100 accounts).\n";
        }
    }

    // Function to Perform a transaction (Deposit or Withdraw)
    void performTransaction() {
        int accNum;
        double amount;
        char choice;

        cout << "Enter account number: ";
        cin >> accNum;

        // Find the account by account number
        int index = -1;
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].getAccountNumber() == accNum) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Account not found.\n";
            return;
        }

        cout << "Enter transaction type (D for Deposit, W for Withdraw): ";
        cin >> choice;
        cout << "Enter amount: $";
        cin >> amount;

        if (choice == 'D' || choice == 'd') {
            accounts[index].deposit(amount);
        } else if (choice == 'W' || choice == 'w') {
            accounts[index].withdraw(amount);
        } else {
            cout << "Invalid transaction type.\n";
        }
    }

    // Display details of all accounts
    void displayAllAccounts() const {
        if (accountCount == 0) {
            cout << "No accounts available.\n";
            return;
        }

        for (int i = 0; i < accountCount; i++) {
            cout << "\nAccount " << (i + 1) << ":\n";
            accounts[i].displayAccountDetails();
        }
    }
};

// Main function for Menu-Driven Interface
int main() {
    BankingSystem bankSystem;
    int choice;

    do {
        // Display Menu
        cout << "\nBanking System Menu:\n";
        cout << "1. Add Account\n";
        cout << "2. Perform Transaction\n";
        cout << "3. Display All Accounts\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
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
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}