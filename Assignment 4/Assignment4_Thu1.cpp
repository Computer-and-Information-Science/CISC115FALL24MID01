#include <iostream>
using namespace std;

int main() {
    double firstNo, secNo, answer; // Declare variables
    char operation, choice;

    cout << "***Menu-Driven Calculator***\n" << endl; // Program Title

    do {
        cout << "Enter First Number: ";
        cin >> firstNo;
        
        cout << "Enter Second Number: ";
        cin >> secNo;

        cout << "Please choose an operator to calculate the numbers (+, -, *, /): ";
        cin >> operation;

        // In case user enters second no. is 0 and division, to ask to change the second number 
        if (operation == '/' && secNo == 0) {
            while (secNo == 0) {
                cout << "***Error: Division by zero is not allowed. Please enter a non-zero second number: ";
                cin >> secNo;
            }
        }
        
        // operation
        switch (operation) {
            case '+':
                answer = firstNo + secNo;
                cout << "Answer: " << answer << endl;
                break;
            case '-':
                answer = firstNo - secNo;
                cout << "Answer: " << answer << endl;
                break;
            case '*':
                answer = firstNo * secNo;
                cout << "Answer: " << answer << endl;
                break;
            case '/':
                answer = firstNo / secNo;
                cout << "Answer: " << answer << endl;
               
        }

        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y'); // to continue program if user choose y or Y

    cout << "\n------- Program ended. Thank you! -------" << endl;

    return 0;
}
