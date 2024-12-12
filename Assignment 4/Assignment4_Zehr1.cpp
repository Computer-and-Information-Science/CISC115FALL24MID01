//
//  Assignment4_Zehr1.cpp
//  Homework Week 4 Program 1
//
//  Created by Isaac Zehr
//

#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;
    char choice;

    do {
        cout << "Welcome to the Menu Driven Calculator!" << endl;
        cout << "Available operators: +  -  *  /" << endl;
        cout << "Enter your first number: ";
        cin >> num1;

        cout << "Enter your second number: ";
        cin >> num2;

        cout << "Enter the operator (+, -, *, /): ";
        cin >> op;

        // Handle the arithmetic based on operator
        switch (op) {
            case '+':
                result = num1 + num2;
                cout << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                // Check for division by zero
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    result = num1 / num2;
                    cout << num1 << " / " << num2 << " = " << result << endl;
                }
                break;
            default:
                cout << "Invalid operator entered." << endl;
                break;
        }

        // Ask the user if they want to perform another operation
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
}
