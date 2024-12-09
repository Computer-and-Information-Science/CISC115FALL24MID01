#include <iostream>
#include <iomanip>
#include <string>

int main(){
    bankingSystem bankSystem;
    int decision;

    while (true) {
        cout << "  Bank System Menu  "
            << "1. Add Account 2. Perform Transaction 3. Display All Accounts 4. Exit"
            << "Enter your choice: ";
        cin >> decision;

        if (decision == 1)
            bankSystem.addAccount();
        else if (decision == 2)
            bankSystem.bankTransaction();
        else if (decision == 3)
            bankSystem.displayAllAccounts();
        else if (decision == 4)
            break;
        else 
            cout << "Invalid input.";
    }
    return 0;
}

class bankAccount {
    int accountNumber;
    string accountName;
    double balance;

    public:
        bankAccount() : accountNumber(0), accountName(""), balance(0.0) {}

        bankAccount(int num, string name, double accBalance)
            : accountNumber (num), accountName(name), balance(accBalance) {}

        int getAccountNumber() const {return accountNumber;} 

        void deposit(double total) {balance += (total > 0) ? total : 0;}

        void withdraw(double total) {
            if (total > 0 && total <= balance)
                balance -= total;
            else 
                cout << "Insufficient funds " <<endl;
            }

            void display() const {
            cout << "Account Number: " << accountNumber
                << " Account Name: " << accountName
                << " Account Balance: $" << balance <<endl;
            }
}

class bankingSystem {

    bankAccount accounts [100];
    int accountCount = 0;

    public:
        void addAccount(){
            int num;
            string name;
            double accBalance;

            cout << "Enter Account Number: ";
            cin >> num;
            cin.ignore();
            cout << "Enter Account Name: ";
            getline (cin, name);
            cout << "Enter starting balane: $";
            cin >> accBalance;

            if (accBalance >= 0 && accountCount < 100) {
                accounts[accountCount++] = bankAccount(num, name, accBalance);
                cout << "Account Creation Successful.";
            } else {
                cout << "Account Creation Failed.";
            }

        }

        void bankTransaction(){
            int num;
            char type;
            double amount;

            cout << "Please enter account number: ";
            cin >> num;

            for (int i = 0; i < accountCount; i++){
                if (accounts[i].getAccountNumber() == num) {
                    cout << "Enter type of transaction, Deposit or Withdraw (D/W): ";
                    cin >> type;
                    cout << "Enter amount: $";
                    cin >> amount; 

                    (type == 'D' || type == 'd') ? accounts[i].deposit(amount) : accounts[i].withdraw(amount);
                    return;
                }
            }
            cout << "Unable to find account." <<endl;
        }

        void displayAllAccounts() const {
            if (accountCount == 0){
                cout << "No accounts found.";
            } else {
                for (int i = 0; i < accountCount; i++)
                    accounts[i].display();
            }

        }
}