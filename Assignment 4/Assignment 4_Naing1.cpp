#include <iostream>
using namespace std;

int main() {
    char operation;
    float num1, num2;
    char choice;

    cout << "Welcome to the Menu-Driven Calculator!" << endl;

    do {
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

        cout << "-----------------------------------------" << endl;
        cout << "Please choose the operation you'd like to perform:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "-----------------------------------------" << endl;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

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
                if (num2 != 0)
                    cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                else
                    cout << "ERROR! Error: Division by zero is not allowed!" << endl;
                break;
            default:
                cout << "Invalid operation." << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator. Goodbye!" << endl;
    return 0;
}
