//**********************************************************************
// Author: Raymond Castro
// Date: 8 Dec 2024
//
// Computer Science Coding Assignment 8 - Raymond Castro
//
// This C++ program acts as a banking system, with classes for bank
// accounts and a banking system. Using object-oriented programming
// (OOP) concepts, classes, and abstract data types (ADTs), this program
// allows the user to add accounts, perform transcations, display all
// accounts, and exit the program through a menu-driven interface.
//**********************************************************************

// Header files
#include <iostream>
#include <string>
#include <cctype> /* Header file used for functions which classify and
transform individual characters, such as isalpha */

using namespace std;

class BankAccount /* Declares BankAccount as a class to represent a bank
account */
{
public:
    BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0) {}
    // Declares a default constructor in the BankAccount class

    BankAccount(int accNum, string name, double initialBalance) 
        : accountNumber(accNum), accountHolderName(name), balance(initialBalance) {}
    // Declares a parameterized constructor in the BankAccount class

    int getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }
    /* Declares the preceding getter (accessor) functions to provide
    controlled access to private data members of BankAccount */

    void setAccountNumber(int accNum) { accountNumber = accNum; }
    void setAccountHolderName(string name) { accountHolderName = name; }
    void setBalance(double amount) { balance = amount; }
    /* Declares the preceding setter (mutator) functions to modify values
    of private data members of BankAccount */

    void deposit(double amount) /* Creates a function to deposit money
    into a bank account */
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited $" << amount << " in account " << accountNumber << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) /* Creates a function to withdraw money
    from a bank account */
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew $" << amount << " from account " << accountNumber << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    void displayAccountDetails() const /* Creates a function to display
    account details */
    {
        cout << "Account Number: " << accountNumber
             << ", Holder: " << accountHolderName
             << ", Balance: $" << balance << endl;
    }

private:
    int accountNumber; // Declares accountNumber in the int data type
    string accountHolderName;
    double balance;
};

class BankSystem // Declares BankSystem as a class to manage a banking system
{
public:
    BankSystem() : accountCounter(0) {}
    // Declares a default constructor for BankSystem

    bool isValidName(const string& name) /* Creates a function to validate a
    name input */
    {
        for (char c : name) // Iterates through each character in a name
        {
            if (!isalpha(c) && c != ' ') /* Checkes if a character in a name is
            not a letter or space */
            {
                return false; /* Returns false to the calling
                function if any invalid character is found */
            }
        }
        return !name.empty(); /* Returns true to the calling function if the name
        non-empty and valid */
    }

    void addAccount() // Creates a function to add a new account
    {
        if (accountCounter >= 100)
        {
            cout << "Maximum account limit reached." << endl;
            return;
        }

        int accNum;
        string name;
        double initialBalance;

        while (true) /* Loops the input prompt for accNum until the user
        inputs it correctly */
        {
            cout << "Enter Account Number: ";
            cin >> accNum;

            if (cin.fail() || (accNum < 0)) /* Checks whether the input for accNum
            is valid */
            {
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear(); // Clears the input stream
                cin.ignore(100, '\n'); /* Ignores the invalid input and clears
                the buffer */
            }
            else if (!isAccountNumberUnique(accNum)) /* Uses the user-defined function
            isAccountNumberUnique to check for unique account numbers */
            {
                cout << "Account number already exists. Please try again." << endl;
            }
            else
            {
                break; // Breaks the while loop if the input is valid
            }
        }

        cin.ignore(100, '\n');
        while (true) /* Loops the input prompt for name until the user
        inputs it correctly */
        {
            cout << "Enter Account Holder Name: ";
            getline(cin, name); /* Reads the inputted string, including
            whitespaces, then stores it in name */

            if (!isValidName(name)) /* Uses the user=defined function isValidName
            to validate name inputs */
            {
                cout << "Invalid input. Please enter a valid name." << endl;
            }
            else
            {
                break;
            }
        }
        
        while (true) /* Loops the input prompt for initialBalance until the user
        inputs it correctly */
        {
            cout << "Enter Initial Balance: ";
            cin >> initialBalance;

            if (cin.fail() || (initialBalance < 0)) /* Checks whether the input for
            initialBalance is valid */
            {
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                break;
            }
        }

        accounts[accountCounter] = BankAccount(accNum, name, initialBalance);
        // Creates a new BankAccount object using the parameterized constructor
        accountCounter++;
        cout << "Account created successfully." << endl;
    }

    void performTransaction() // Creates a function to perform a transaction
    {
        int accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        int index = findAccountIndex(accNum); /* Uses the user-defined function
        findAccountIndex to search for an account and return its index in the array
        if found */
        if (index == -1) /* Checks for whether an account number inputted by the
        user exists */
        {
            cout << "ERROR!" << endl << "Error: Account not found." << endl;
            return; // Exits the function early
        }

        cout << "Choose Transaction Type (1: Deposit, 2: Withdraw): ";
        int choice;
        cin >> choice;

        double amount;
        cout << "Enter Amount: ";
        cin >> amount;

        if (cin.fail() || amount <= 0) /* Checks whether the input for
        amount is valid */
        {
            cout << "Invalid amount. Transaction canceled." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            return;
        }

        if (choice == 1) /* Checks for which type of transaction to perform
        based on what the user inputted for choice */
        {
            accounts[index].deposit(amount); /* Performs the deposit operation
            on the account located at the index in the accounts array */
        }
        else if (choice == 2)
        {
            accounts[index].withdraw(amount); /* Performs the withdraw operation
            on the account located at the index in the accounts array */
        }
        else
        {
            cout << "Invalid transaction type." << endl;
        }
    }

    void displayAllAccounts() const /* Creates a function to display all
    accounts */
    {
        if (accountCounter == 0) // Checks for accounts created by the user
        {
            cout << "No accounts in the system." << endl;
            return;
        }

        for (int i = 0; i < accountCounter; ++i) /* Iterates through all
        accounts */
        {
            accounts[i].displayAccountDetails(); /* Uses the user-defined function
            displayAccountDetails to display account details */
        }
    }

private:
    BankAccount accounts[100];
    int accountCounter;
    int findAccountIndex(int accNum) const /* Locates an index of an account in the
    accounts array based on accNum */
    {
        for (int i = 0; i < accountCounter; ++i)
        {
            if (accounts[i].getAccountNumber() == accNum)
            {
                return i;
            }
        }
        return -1;
    }

    bool isAccountNumberUnique(int accNum) const
    // Creates a function to check for unique account numbers
    {
        return findAccountIndex(accNum) == -1;
    }
};

int main()
{
    BankSystem bank;
    int choice;

    cout << "Computer Science I Coding Assignment 8 - Raymond Castro"
         << endl << endl; // Outputs the title of the program
    cout << "Using object-oriented programming (OOP), classes, and abstract data "
         << "types (ADTS), this C++ program uses concepts such as constructors, accessor "
         << "and mutator functions, and data\nabstraction to run a banking system. Using classes "
         << "for bank accounts and a banking system, the user can choose from a menu-driven interface "
         << "to add accounts, perform transactions,\ndisplay all accounts, or exit the program." << endl;
         // Displays an explanation of the program

    do /* Loops the menu and available operations until the user chooses
    to exit the program */
    {
        cout << endl << "=== Banking System Menu ===" << endl
             << "1. Add Account" << endl
             << "2. Perform Transaction" << endl
             << "3. Display All Accounts" << endl
             << "4. Exit" << endl
             // Displays a list of what operations the user can choose
             << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) /* Checks whether the input for choice is
        valid */
        {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue; // Transitions with the next iteration of the do while loop
        }

        switch (choice) /* Utilizes a specific operation based on what
        value of choice the user inputted */
        {
            case 1:
                bank.addAccount();
                // Performs the user-defined function addAccount()
                break;
            case 2:
                bank.performTransaction();
                // Performs the user-defined function performTransaction()
                break;
            case 3:
                bank.displayAllAccounts();
                // Performs the user-defined function displayAllAccounts()
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    while (choice != 4);

    return 0; // Terminates the program
}