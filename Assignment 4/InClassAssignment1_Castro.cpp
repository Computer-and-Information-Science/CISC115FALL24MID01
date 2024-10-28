//**********************************************************************
// Author: Raymond Castro
// Date: 29 Oct 2024
//
// Computer Science I In Class Assignment 1 - Raymond Castro
//
// This C++ program uses a sentinel-controlled while loop to collect
// input from the user, and utilizes it to find the sum of a variable.
//**********************************************************************

// Header file
#include <iostream>

using namespace std;

const int SENTINEL = -1; /* Declares and initializes the variable SENTINEL
as a constant integer */

int main()
{
    int number; // Declares the variable number in the int data type
    int sum = 0; // Declares the variable sum in the int data type 

    cout << "Computer Science I In Class Assignment 1 - Raymond Castro"
         << endl << endl; // Outputs the title of the program
    cout << "Utilizing a sentinel-controlled while loop, this C++ program "
         << "takes input from the user to find the sum of a variable."
         << endl << endl; // Displays an explanation of the program

    while (true) // Loops until the user inputs the SENTINEL value
    {
        cout << "Enter a number (enter -1 to end): ";
        cin >> number;

        if (number == SENTINEL) // Checks for the SENTINEL value
        {
            break; /* Breaks the while loop if the user entered the
            SENTINEL value */ 
        }
        
        sum += number; // Adds the user's entered number to the sum
    }

    cout << endl;
    cout << "Total sum: " << sum << endl; /* Outputs the total sum
    once the user enters the SENTINEL value to exit the while loop */

    return 0; // Terminates the program
}