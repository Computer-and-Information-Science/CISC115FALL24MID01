#include <iostream>
#include <string>

using namespace std;

class bankAccount 
{
    private:
        int accountNumber;
        string accountHolderName;
        double balance;

    public:
        bankAccount(): accountNumber(0), accountHolderName(""), balance(0) {}
        bankAccount(int accNo, string name, double bal) :
            accountNumber(accNo), accountHolderName(name), balance(bal) {}

        int getAccountNumber() {
            return accountNumber;
        }

        void setAccountHolderName(string name) {
            accountHolderName = name;
        }

        string getAccountHolderName() {   
            return accountHolderName;
        }

        double getBalance() {
            return balance;
        }

        void deposit(double amt) {
            if (amt >= 0) 
                balance += amt;
            else
                cout << "Negative number is provided for deposit\n";
        }

        void withdraw(double amt) {
            if (amt < 0) {
                cout << "Negative number is provided for withdraw\n";
                return;
            }

            if (amt > balance) {
                cout << "Amount provided is greater than the balance\n";
                return;
            }

            balance -= amt;
        }

        void displayAccDetails() {
            cout << "Account Number: " << accountNumber
                << ", Holder: " << accountHolderName
                << ", Balance: $" << balance << "\n";
        }
};

class bankingSystem 
{
    private:
        bankAccount bankAccounts[100];
        int counter;

    public:
        bankingSystem() : counter(0) {}  // initialize counter

        void addNewAccount() {
            if (counter >= 100) {
                cout << "Cannot add more accounts. Maximum limit reached.\n";
                return;
            }

            int accNo;
            string name;
            double bal;

            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> bal;

            bankAccount acc (accNo, name, bal);    // create a bankAccount onject (direct object assignment)
            bankAccounts[counter] = acc;           // add to array
            counter++;

            cout << "Account created successfully.\n";
        }

        void performTransactions() {
            int accNo;
            string type;
            double amt;

            cout << "Enter Account Number: ";
            cin >> accNo;
            
            for (int i = 0; i < counter; i++) {
                if (bankAccounts[i].getAccountNumber() != accNo) {  // search for the account by its account number
                    cout << "ERROR!\nError: Account not found.\n";
                }
                else {
                    cout << "Enter Transaction Type (deposit/ withdraw): ";
                    cin >> type;
                    cout << "Enter Amount: ";
                    cin >> amt;

                    if (type == "deposit") {
                        bankAccounts[i].deposit(amt);
                        if (amt >= 0)
                            cout << "Deposited $" << amt << " to account " << accNo << endl;
                    }    
                    else if (type == "withdraw") {
                        bankAccounts[i].withdraw(amt);
                        if (amt < 0 && amt > bankAccounts[i].getBalance())
                            cout << "Withdrew $" << amt << " from account " << accNo << endl;
                    }
                    else
                        cout << "Invalid account transaction!\n";
                }           
            }
        }

        void displayAllAccDetails() {
            if (counter == 0) {
                cout << "No bank accounts in the system.\n";
                return;
            }

            for (int i = 0; i < counter; i++)
                bankAccounts[i].displayAccDetails();
        }
};

int main() 
{
    bankingSystem bank;
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
                bank.addNewAccount();
                break;
            case 2:
                bank.performTransactions();
                break;
            case 3:
                bank.displayAllAccDetails();
                break;
            case 4:
                cout << "Exiting banking system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}