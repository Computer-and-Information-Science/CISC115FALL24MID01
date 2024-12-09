#include <iostream>
#include <iomanip>
using namespace std;
class bankAccount//this class controls the contents of the bank account
{
public://these functions allow for the object to change or get properties it has
    bankAccount();
    bankAccount(int, string, double);
    void displayAccount() const;
    void depositMoney(double amount);
    void withdrawMoney(double amount);
    int getAccountNumber() const {return accountNumber;}//inline function that returns the account number of the class object when called
private://these variables make up the properties of the bank account class objects
    int accountNumber;
    string accountHolder;
    double balance;
};
class bankingSystem//this class creates bank accounts and keeps track of each account
{
public://these functions allow for the object to change or get properties it has
    int addNewAccount();
    void accountTransactions();
    void allAccountDetails() const;
private://these variables make up the properties of the banking system class objects
    bankAccount accounts[100];
    int counter = 0;
};
int error(int& input);
double error(double& input);
int main()
{
    int choice = 0;
    bankingSystem bank;
    while (choice != 4){
        cout<<"\n=== Banking System Menu ==="<<endl;
        cout<<"1. Add Account\n2. Perform Transaction\n3. Display All Accounts\n4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        error(choice);
        if (choice == 1){
            bank.addNewAccount();
        }else if (choice == 2){
            bank.accountTransactions();
        }else if (choice == 3){
            bank.allAccountDetails();
        }else if ((choice < 1)||(choice > 4)){
            cout<<"Enter a valid choice!"<<endl;
        }
    }  
    cout<<"Logged Out. Thanks for using our banking system."<<endl;
}
bankAccount::bankAccount(int num, string name, double iniBalance){//constructor function for the bankAccount class with parameters
    accountNumber = num;
    accountHolder = name;
    balance = iniBalance;
}
bankAccount::bankAccount(){//constructor function for the bankAccount class
    accountNumber = 0;
    accountHolder = "";
    balance = 0.00;
}
int bankingSystem::addNewAccount(){//creates a new account with a different account id
    int number;
    string holder;
    double amount;
    cout<<"Enter Account Number: ";
    cin>>number;
    error(number);
    for (int x = 0; x < counter; x++){
        if (accounts[x].getAccountNumber() == number){
            cout<<"ERROR!\nError: That account number is already in use. Try again."<<endl;
            return 0;
        }
    }
    cout<<"Enter Account Holder Name: ";
    cin>>holder;
    cout<<"Enter Initial Balance: ";
    cin>>amount;
    error(amount);
    bankAccount account(number, holder, amount);
    accounts[counter] = account;
    counter ++;
    cout<<"Account created successfully."<<endl;
    return 0;
}
void bankingSystem::allAccountDetails() const{//loops through the list of avalible accounts to display each one
    int x;
    if (counter != 0){
        for (x = 0; x < counter; x++){
            accounts[x].displayAccount();
        }
    }else{
        cout<<"ERROR!\nError: No accounts in the system."<<endl;
    }
}
void bankAccount::displayAccount() const{//displays contents of the bank account
    cout<<"Account Number: "<<accountNumber<<", Holder: "<<accountHolder<<", Balance: $"<<fixed<<showpoint<<setprecision(2)<<balance<<endl;
}
void bankAccount::depositMoney(double amount){//adds non-negative money to the bank accout
    if (amount > 0){
        balance = balance + amount;
        cout<<"Deposited $"<<fixed<<showpoint<<setprecision(2)<<amount<<" to account "<<accountNumber<<endl;
    }else{
        cout<<"ERROR!\nError: The amount entered was not big enough for a deposit."<<endl;
    }
}
void bankAccount::withdrawMoney(double amount){//withdraws money only if it's lower than or equal to the current amount
    if (balance >= amount){
        balance = balance - amount;
        cout<<"withdrew $"<<fixed<<showpoint<<setprecision(2)<<amount<<" from account "<<accountNumber<<endl;      
    }else{
        cout<<"ERROR!\nError: The amount entered exceeded the current balance"<<endl;
    }
}
void bankingSystem::accountTransactions(){//figures out which transaction the user is trying to use and executes it
    double amount;
    int verification;
    string transaction = "";
    cout<<"Enter Account Number: ";
    cin>>verification;
    error(verification);
    for (int x = 0; x < counter; x++){
        if (accounts[x].getAccountNumber() == verification){
            cout<<"Enter Transaction Type (deposit/withdraw): ";
            cin>>transaction;
            while ((transaction != "deposit")&&(transaction != "withdraw")){
                cout<<"Try Again. Enter deposit or withdraw: ";
                cin>>transaction;
            }
            if (transaction == "deposit"){
                cout<<"Enter Amount: $";
                cin>>amount;
                error(amount);
                accounts[x].depositMoney(amount);
            }else if(transaction == "withdraw"){
                cout<<"Enter Amount: $";
                cin>>amount;
                error(amount);
                accounts[x].withdrawMoney(amount);
            }
            break;
        }
    }
    if (transaction == "")
        cout<<"ERROR!\nError: Account not found."<<endl;    
}
int error(int& input){//corrects any input errors for int inputs when called
    while (cin.fail()){
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"Invalid input. Please enter the correct data type: ";
      cin>>input;
   }
    return input;
}
double error(double& input){//corrects any input errors for double inputs when called
    while (cin.fail()){
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"Invalid input. Please enter the correct data type: ";
      cin>>input;
   }
    return input;
}
