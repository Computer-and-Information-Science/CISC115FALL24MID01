#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation, choice;

    do {
        // Display menu
        cout << "Welcome to the Menu-Driven Calculator\n";
        cout << "-----------------------\n";
        // Input two numbers
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        // Select the operation
        cout << "-----------------------\n";
        cout << "Select an operation:\n";
        cout << "+ : Addition\n";
        cout << "- : Subtraction\n";
        cout << "* : Multiplication\n";
        cout << "/ : Division\n";
        // Input operator
        cout << "Enter an operator (+, -, *, /): ";
        cin >> operation;

        // Perform calculation based on operator
        switch (operation) {
            case '+':
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid operator. Please try again." << endl;
                break;
        }

        // Ask if the user wants to perform another calculation
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
}