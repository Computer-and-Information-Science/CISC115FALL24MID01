// Header files for our program.
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Class will be used to identify the Bank Account.
class BankAccount {
    int AccountNum;
    string AccountHolderName;
    double AccountBalance;

public:

BankAccount() : AccountNum(0), AccountHolderName(""), AccountBalance(0.0) {}

BankAccount (int number, string name, double balance)
: AccountNum(number), AccountHolderName(name), AccountBalance(balance) {}

int GetAccountNumber() const {return AccountNum;}

void deposit (double amount) {
    AccountBalance += (amount > 0 ) ? amount : 0;
}

void withdraw (double amount){
    if (amount > 0 && amount <= AccountBalance)
    {
        AccountBalance -= amount;
    }else
    {
        cout << "Amount entered invalid or funds are not availble. Try again....";
    }
    
}

void display() const{
    cout << "Account number: " <<  AccountNum << endl
    << "Holders name on account: " << AccountHolderName << endl
    <<"Balacne: $" << AccountBalance << endl;
} 
};


class BankSys {
    BankAccount accounts[100];
    int NumberOfAccounts = 0;

public:

void AccountAdd() {
    int AccountNumber;
    string AccountHolder;
    double InitialBalance;

    cout << "Enter Account number: ";
    cin >> AccountNumber;
    cin.ignore();

    cout << "Enter holder name for account: ";
    getline(cin,AccountHolder);
    
    cout << "Enter Intial Balance: ";
    cin >> InitialBalance;
    cin.ignore();


if (InitialBalance >= 0 && NumberOfAccounts < 100)
{
    accounts[NumberOfAccounts++] = BankAccount (AccountNumber, AccountHolder, InitialBalance);
    cout << "Creating account...." << endl << "Account created successfully";

}else
{
     cout << "Creating account...." << endl << "Failed to create account.";
}

}

void Transaction() {
    int AccountNumber;
    char action;
    double amount;

    cout << "Enter a(n) account numbeer: ";
    cin >> AccountNumber;

    for (int i = 0; i < NumberOfAccounts; i++)
    {
        if (accounts [i].GetAccountNumber() == AccountNumber)
        {
            cout << "Would you like to deposit or withdraw today? Type (D/W): ";
            cin >> action;

            cout << "Enter a amount for this transaction: ";
            cin >> amount;

          (action == 'D' || action == 'd') ? accounts[i].deposit(amount) : accounts[i].withdraw(amount);
          return;
        }
        
    }
    
    cout << "Processing....." << endl << "Account could not be found." << endl;
}

void DisplayAllAccounts() const {
    if (NumberOfAccounts == 0)
    {
        cout << "No accounts could be found in our system...." << endl;

    }else
    {
        for (int i = 0; i < NumberOfAccounts; i++)
        {
            accounts[i].display();
        }
        
    }   
}

};



int main () {

BankSys banksystem;
int x;
while (true) {
cout << endl << "=== Banking system menu ===" << endl
<< "1. Add account" << endl << "2. Perform Transaction" << endl
<< "3. Display all accounts" << endl << "4. Exit" << endl;

cout << "Please type a valid option:"; 

cin >> x;
cin.ignore();

if (x == 1)
{
    banksystem.AccountAdd();
}else if (x == 2)
{
    banksystem.Transaction();
}else if (x == 3)
{
    banksystem.DisplayAllAccounts();
}else if (x == 4)
{
    break;
}else
{
    cout << "Please selcct valid option.";
}

}



return 0;

}