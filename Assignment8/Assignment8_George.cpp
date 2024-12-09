#include <string>
#include <iostream>
using namespace std; 
#include <iomanip>

//makeing constructor and getter class
class BankAccounts { 

    private: 
        int accountNumber; 
        string accountHolderName;
        double accountBalance;

    public: 
            //defualt constructor
         BankAccounts(): accountNumber(0), accountHolderName(""), accountBalance(0) {}
        
            //constructor
         BankAccounts(int accNumber, string accountHN, double balance):
           accountNumber(accNumber),
           accountHolderName(accountHN),
           accountBalance(balance)
        {}

// methods
        void withdrawMoney(double withdraw){
            accountBalance = accountBalance - withdraw;
            cout << withdraw << " Has been take out of your account." << '\n';
            cout << "New Account Balance: " << accountBalance << '\n';
            
        }

        void depositMoney(double deposit){
            accountBalance = accountBalance + deposit;
            cout << deposit << " Has been put into your account." << '\n';
            cout << "New Account Balance: " << accountBalance << '\n';
        }

        void displayAccountDetaliis(){
            cout << "Account Holder: " << accountHolderName;
            cout << " ,Account Number: " << accountNumber;
            cout << " ,Account Balance: " << accountBalance << '\n';

        }
//return methods
        void displayAccountNumber(){
            cout << accountNumber << '\n';
        }

        int getAccountNum(){
            return accountNumber;
        }

        double getAccountBalance(){
            return accountBalance;
        }

        string getAccountHoldername(){
            return accountHolderName;
        }

};


//creating class to hold 

class BankingSystem{
//accounts array with 100 limit
BankAccounts accounts[100];
int numberOfAccounts = 0;
//account counter

public:


// account adding method
void addNewAccount(){
double balance;
int accountNumber;
string accountHolderName;

cout << "Enter account number: ";
cin >> accountNumber;
cin.ignore();

cout << "Enter account holder name: ";
getline(cin,accountHolderName);

cout << "Enter inital balance: ";
cin >> balance;

if(balance >= 0){


if(numberOfAccounts < 100){

accounts[numberOfAccounts] = BankAccounts(accountNumber, accountHolderName, balance);
++numberOfAccounts;
cout << "Account created succsefuly" << '\n';
}
else{
cout << "Cannot Create account, account limit reached." << '\n';
}

}
else{
cout << "Invalid balance entered" << '\n';
}




}

//despoits and withdraws methods
void deposit(int AccountNumber){
double amount;
int accountNum = AccountNumber;


for(int x = 0; x < numberOfAccounts; ++x){

    if(accounts[x].getAccountNum() == accountNum){
        cout << "How much would you like to deposit: ";
        cin >> amount;

        accounts[x].depositMoney(amount);
        break;

    }
   
}


}

void withdraw(int AccountNumber){
double amount;
int accountNum = AccountNumber;



for(int x = 0; x < numberOfAccounts; ++x){

    if(accounts[x].getAccountNum() == accountNum){
        cout << "How much would you like to withdraw: ";
        cin >> amount;

        accounts[x].withdrawMoney(amount);
    }
    else{
        cout << "Invalid account number entered.";
    }
}

}
//displaying method
void displatAllAccounts(){

    if(numberOfAccounts == 0){
        cout << "No accounts present" << '\n';

    }else{
        for(int y = 0; y < numberOfAccounts; ++ y){
            accounts[y].displayAccountDetaliis();
        }
    }




}





};


//main function
int main(){
int userChoice;
string transactionChoice;
int accountNum;
bool control = true;


BankingSystem system;
while(control == true){
//selection
cout << "=== Banking System Menu ===" << '\n';
cout << "1. Add Account" << '\n';
cout << "2. Preform Transaction" << '\n';
cout << "3. Display All Accounts" << '\n';
cout << "4. Exit" << '\n';
cout << "Enter Your choice: " << '\n';
cin >> userChoice;
//option calls
if(userChoice == 1){
    system.addNewAccount();

}

if(userChoice == 2){
    cout << "Please enter your account number: ";
    cin >> accountNum;
    cin.ignore();

    cout << "What kind of transaction would you like to make(Withdraw/Deposit): ";
    getline(cin,transactionChoice);


    if(transactionChoice == "withdraw" || transactionChoice == "Withdraw"){
        system.withdraw(accountNum);
    }

    if(transactionChoice == "deposit" || transactionChoice == "Deposit"){
        system.deposit(accountNum);
    }
}
else if(userChoice == 3){
        system.displatAllAccounts();
    }
else if(userChoice == 4){
        control = false;
        cout << "Thank you for banking with us.";
    }//exit 
}
}
