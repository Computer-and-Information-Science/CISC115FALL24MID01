#include <iostream>
#include <string>

using namespace std;

// Create class for a bank account
class BankAccount
{
    // Initialize variables
    int number;
    string holderName;
    double balance;

    public:
        // Create default constructor
        BankAccount() : number(0), holderName(""), balance(0) {}

        // Create parameterized constructor
        BankAccount(int num, string name, double amount) : number(num), holderName(name), balance(amount) {}

        // Create accessors
        int getNum() { return number; }
        string getName() { return holderName; }
        double getBalance() { return balance; }


        // Create mutators (deposit and withdraw)
        void deposit(double amount)
        {
            if(amount > 0)
                balance += amount;
            else
                cout << "Error! Cannot deposit zero or negative amount!" << endl;
        }

        void withdraw(double amount)
        {
            if(amount <= balance && amount > 0)
                balance -= amount;
            else
                cout << "Error! Amount cannot be 0, negative, or larger than amount" << endl;
        }

        // Create function to display all values
        void displayDetails()
        {
            cout << "Account's number: " << number << endl;
            cout << "Account holder's name: " << holderName << endl;
            cout << "Account's balance: $" << balance << endl;
        }
};

// Create class for the banking system
class BankingSystem
{
    // Create array and counter
    BankAccount account[100];
    int count;

    public:
        // Create function to make new account
        void newAccount()
        {
            // Initialize variables
            int accountNum;
            string accHolderName;
            double accountBal;

            cout << "Enter account number: "; 
            cin >> accountNum;
            cin.ignore(); // Program skips entering of name without this
            cout << "Enter holder name: ";
            getline(cin, accHolderName); // Use getline instead because of spaces
            cout << "Enter balance: ";
            cin >> accountBal;

            // Ensure this new account does not exceed the account limit
            if (count < 100)
            {
                account[count++] = BankAccount(accountNum, accHolderName, accountBal);
                cout << "Your account was successfully created." << endl;
            }
            else
                cout << "Your account could not be created because it would exceed the account limit." << endl;
        }

        // Create function for transactions
        void transactions()
        {
            int num;
            int transType;
            double amnt;

            cout << "What is your account number?: ";
            cin >> num;

            // Find account by using account number
            for(int i = 0; i < count; i++)
            {
                if(account[i].getNum() == num)
                {
                    cout << "Enter 0 for Deposit or 1 for Withdraw: ";
                    cin >> transType;
                    cout << "How much would you like to deposit/withdraw?: ";
                    cin >> amnt;

                    if(transType == 0)
                        account[i].deposit(amnt);
                    if(transType == 1)
                        account[i].withdraw(amnt);
                    else
                        cout << "Invalid transaction type. Please enter 0 or 1." << endl;
                }
                else
                    cout << "Error! Invalid account number" << endl;
            }
        }

        // Create function to display all accounts' details
        void displayAll()
        {
            if(count == 0)
                cout << "No accounts yet." << endl;
            else
            {
                for(int i = 0; i < count; i++)
                    account[i].displayDetails();
            }
        }
};

int main()
{
    // Initialize variables
    BankingSystem system;
    int input;

    // Ensure program keeps running until user stops it
    while(true)
    {
        // Prompt user for choice
        cout << "Welcome to the Online Bank." << endl;
        cout << "Enter 1 to create an account, 2 to perform a transaction, 3 to display all accounts, 4 to exit: ";
        cin >> input;

        // Use if else, switch does not work
        if(input == 1)
            system.newAccount();
        else if(input == 2)
            system.transactions();
        else if(input == 3)
            system.displayAll();
        else if(input == 4)
            break;
        else
            cout << "Invalid selection." << endl;
    }
}