#include <iostream>
#include <string>
using namespace std;

// class to manage BankAccount
class BankAccount {
    int accountNumber;
    string accountHolderName;
    double accountBalance;
    
public:
    // Default Constructor
    BankAccount() : accountNumber(0), accountHolderName(""), accountBalance(0.0) {}
    
    // Parameterized Constructor
    BankAccount(int accNum, string name, double balance) 
        : accountNumber(accNum), accountHolderName(name), accountBalance(balance) {}
    
    // Getter    
    int getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getAccountBalance() const { return accountBalance; }
    
    // Deposit
    void deposit (double amount) {
    accountBalance += (amount > 0 ) ? amount : 0;
    cout << "Deposited " << amount << " to account " << accountNumber << " successfully. " <<endl;
    }
    
    // Withdraw
    void withdraw(double amount) {
        if (amount > 0 && amount <= accountBalance) {
            accountBalance -= amount;
       cout << "Withdrew" << amount << " from account " << accountNumber << " successfully. " << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
    // Display account details
    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber 
             << ", Holder: " << accountHolderName 
             << ", Balance: $" << accountBalance << endl;
    }
};

// class to manage BankSystem
class BankSystem {
    BankAccount accounts[100];  
    int accountCount = 0; 
    
public:
    void addAccount() {
        int accNumber;
        string accHolder;
        double initialBalance;

        cout << "Enter Account Number: ";
        cin >> accNumber;
        cin.ignore();  
        cout << "Enter Account Holder Name: ";
        getline(cin, accHolder);
        cout << "Enter Initial Balance: ";
        cin >> initialBalance;

        if (initialBalance >= 0 && accountCount < 100) {
            accounts[accountCount++] = BankAccount(accNumber, accHolder, initialBalance);
            cout << "Account created successfully.\n";
        } else {
            cout << "Error! Account creation failed.\n";
        }
    }
    
    void performTransaction() {
        int accNumber;
        cout << "Enter account number: ";
        cin >> accNumber;

        for (int i = 0; i < accountCount; ++i) {
            if (accounts[i].getAccountNumber() == accNumber) {
                char transactionType;
                double amount;

                cout << "Enter transaction type (deposit/withdrawal): ";
                cin >> transactionType;
                cout << "Enter amount: ";
                cin >> amount;

                if (transactionType == 'D' || transactionType == 'd') {
                    accounts[i].deposit(amount);
                } else if (transactionType == 'W' || transactionType == 'w') {
                    accounts[i].withdraw(amount);
                }
                return;
            }
        }
        cout << "Error: Account not found." << endl;
    }
    void displayAllAccounts() const {
        if (accountCount == 0) {
            cout << "No accounts in the system." << endl;
            return;
        }
        for (int i = 0; i < accountCount; ++i) {
            accounts[i].displayAccountDetails();
        }
    }
};

int main() {
    BankSystem bankSystem;
    int choice;

    while (true) {
        // Displaying bank system menu 
        cout << "\n=== Banking System menu ===\n"
             << "1. Add Account\n2. Perform Transaction\n3. Display All Accounts\n4. Exit\n"
             << "Enter your choice: ";
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
                cout << "\nExiting the program... Thank you!\n";
                return 0;
            
            default:
                cout << "Invalid input. Please select a valid option (1-4).\n" << endl;
        }
    }

    return 0;
}