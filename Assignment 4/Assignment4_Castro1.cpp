//**********************************************************************
// Author: Raymond Castro
// Date: 3 Nov 2024
//
// Computer Science I Coding Assignment 4 Program 1 - Raymond Castro
//
// Using loops, this C++ program allows the user to repeatedly perform
// calculations through two numbers and arithmetic operations
// (addition, subtraction, multiplication, division) until the user
// exits.
//**********************************************************************

// Header files
#include <iostream>
#include <iomanip> // Header file used for input and output manipulators

using namespace std;

int main()
{
    double num1, num2, result; /* Declares the preceding variables in the
    double data type */
    char operatorSymbol, choice = 'Y'; /* Declares the preceding variables in
    the char data type */

    cout << "Computer Science I Coding Assignment 4 Program 1 - Raymond "
         << "Castro" << endl << endl; // Outputs the title of the program
    cout << "Utilizing loops, this C++ program acts as a menu-driven "
         << "calculator, where the user can repeatedly perform "
         << "calculations with two numbers and arithmetic operations until "
         << "they\nchoose to exit." << endl << endl;
         // Displays an explanation of the program

    cout << "Welcome to the Menu-Driven Calculator!" << endl << endl;

    while ((choice == 'Y') || (choice == 'y')) /* Loops until the user inputs
    'N' or 'n' into choice */
    {
        while (true) /* Loops the input prompt for num1 until the user
        inputs it correctly */
        {
            cout << "Enter the first number: ";
            cin >> num1;
          
            if (cin.fail()) // Checks whether the input for num1 is valid
            {
                cin.clear(); // Clears the input stream
                cin.ignore(100,'\n'); /* Ignores the invalid input and
                clears the buffer */ 
                cout << "Invalid input. Please try again." << endl << endl;
                // Outputs a statement for the user to input num1 again
            }
            else
            {
                break; // Breaks the while loop if the input is valid
            }
        }

        while (true) /* Loops the input prompt for num2 until the user
        inputs it correctly */
        {
            cout << "Enter the second number: ";
            cin >> num2;
          
            if (cin.fail()) // Checks whether the input for num2 is valid
            {
                cin.clear();
                cin.ignore(100,'\n');
                cout << "Invalid input. Please try again." << endl << endl;
                // Outputs a statement for the user to input num2 again
            }
            else
            {
                break;
            }
        }

        cout << setw(40) << setfill('_') << "" << endl << endl;
        // Prints a line of underscores

        cout << "Please choose the operation you'd like to perform: " << endl;
        cout << "1. Addition (+)" << endl
             << "2. Subtraction (-)" << endl
             << "3. Multiplication (*)" << endl
             << "4. Division (/)" << endl; /* Displays a menu of the
             arithmetic operations to the user */

        cout << setw(40) << setfill('_') << "" << endl << endl;

        while (true) // Checks whether the input for operatorSymbol is valid
        {
            cout << "Choose an operation (+, -, *, /): ";
            cin >> operatorSymbol;
            cout << endl;

            if ((operatorSymbol == '+') || (operatorSymbol == '-') ||
                (operatorSymbol == '*') || (operatorSymbol == '/'))
            {
                break;
            }
            else
            {
                cout << "Invalid operator. Please try again." << endl;
            }
        }

        switch (operatorSymbol) /* Utilizes a specific arithmetic operation
        based on what value of operatorSymbol the user inputted */
        {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) // Checks for the error of division by zero
                {
                    result = num1 / num2;
                }
                else
                {
                    cout << "Error! Division by zero is not allowed. Try again."
                    << endl; /* Outputs a statement for the user to restart the
                    menu-driven calculator */
                    continue; /* Transitions with the next iteration of the
                    while loop */
                }
                break;
        }
        
        cout << "Result: " << num1 << " " << operatorSymbol << " "
             << num2 << " = " << result << endl;
             // Outputs the result to the user

        do /* Loops the input prompt for choice until the user
        inputs it correctly */
        {
            cout << "Do you want to perform another calculation? (Y/N): ";
            cin >> choice;
            cout << endl;

            if ((choice != 'Y' && choice != 'y') && (choice != 'N' && choice != 'n'))
            // Checks whether the input for choice is valid
            {
                cout << "Invalid input. Please enter 'Y', 'y', 'N', or 'n'." << endl;
                cout << setw(40) << setfill('_') << "" << endl << endl;
            }
        }
        while ((choice != 'Y' && choice != 'y') && (choice != 'N' && choice != 'n'));

        if (choice == 'N' || choice == 'n') 
        {
            cout << "Thank you for using the calculator. Goodbye!" << endl;
            // Presents a farewell message to the user after they exit the program
            break;
        }
    }

    return 0; // Terminates the program
}