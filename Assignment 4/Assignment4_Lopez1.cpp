#include <iostream>
using namespace std;

void showMenu() {
    cout << "\nChoose an operation:\n";
    cout << "+ for Addition\n";
    cout << "- for Subtraction\n";
    cout << "* for Multiplication\n";
    cout << "/ for Division\n";
    cout << "q to Quit\n";
    cout << "Enter your choice: ";
}

int main() {
    char operation;
    double num1, num2;

    while (true) {
        cout << "\nEnter two numbers: ";
        cin >> num1 >> num2;

        showMenu();
        cin >> operation;

        if (operation == 'q') {
            cout << "Exiting the program.\n";
            break;
        }

        switch (operation) {
            case '+':
                cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
                break;
            case '-':
                cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
                break;
            case '*':
                cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                }
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}
