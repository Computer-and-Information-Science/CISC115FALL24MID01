#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    char choice;

    cout << "Welcome to the Menu-Driven Calculator!" << endl;

    do {
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        cout << "Please choose the operation you'd like to perform:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        switch (operation) {
            case '+':
                cout << "Result: " << (num1 + num2) << endl;
                break;
            case '-':
                cout << "Result: " << (num1 - num2) << endl;
                break;
            case '*':
                cout << "Result: " << (num1 * num2) << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << (num1 / num2) << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid operation!" << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using my calculator. Goodbye!" << endl;
    return 0;
}