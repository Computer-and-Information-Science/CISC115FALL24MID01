#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2;
    char choice;

    do {
                                                                             // Main menu
        cout << "Super Duper Advanced Calculator Menu:" << endl;
        cout << "Enter + for Addition" << endl;
        cout << "Enter - for Subtraction" << endl;
        cout << "Enter * for Multiplication" << endl;
        cout << "Enter / for Division" << endl;
        cout << "Enter your operator: ";
        cin >> operation;

                                                                             // Input two numbers
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

                                                                             // Switch case for operations
        switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            }
            else {
                cout << "Error! Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operator." << endl;
        }

                                                                             // Ask user to continue/ exit
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');                                // Loop

    cout << "Goodbye!" << endl;
    return 0;
}