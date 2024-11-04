// Program 1: Menu-Driven Calculator Using Loops
#include <iostream>
#include <limits>       // for numeric_limits
using namespace std;

// function to get valid number input
float getValidNumberInput(const string &prompt) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
            cout << "Invalid input. Please enter a valid number." << endl;
        } else {
            break;
        }
    }
    return value;
}

int main() {
    float num1, num2;
    char operation, option;

    cout << "--------------------------------------" << endl;
    cout << "Welcome to the Menu-Driven Calculator!" << endl;

    do {
        // show menu
        cout << "--------------------------------------" << endl;
        cout << "Please choose the operation you'd like to perform:" << endl;
        cout << "1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)" << endl;
        cout << "--------------------------------------" << endl;

        // get user inputs
        num1 = getValidNumberInput("Enter the first number: ");
        num2 = getValidNumberInput("Enter the second number: ");
        
        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        // perform calculation in switch
        switch (operation) {
        case '+':
            cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {    // display result only if there's no error
                cout << "ERROR!\nError: Division by zero is not allowed!" << endl;   // display error message
            }
            break;
        default:
            cout << "Invalid operation selected." << endl;
        }

        // ask if user wants another calculation
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> option;
        cout << endl;

    } while (option == 'y' || option == 'Y');   // exit condition

    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
}