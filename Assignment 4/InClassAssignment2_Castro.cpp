//**********************************************************************
// Author: Raymond Castro
// Date: 29 Oct 2024
//
// Computer Science I In Class Assignment 1 - Raymond Castro
//
// This C++ program outputs the first 10 even positive integers in
// descending order, primarily using a for loop.
//**********************************************************************

// Header file
#include <iostream>

using namespace std;

int main()
{
    cout << "Computer Science I In Class Assignment 2 - Raymond Castro"
         << endl << endl; // Outputs the title of the program
    cout << "Utilizing a for loop, this C++ program displays the first "
         << "10 even positive integers in descending order."
         << endl << endl; // Displays an explanation of the program

    for (int i = 20; i >= 2; i -= 2) /* Loops until the variable i is
    less than 2 */
    {
        cout << i << " "; /* Repeatedly outputs i and updates the initial
        statement until the for loop evaluates to false and terminates */
    }
    
    cout << endl;
    return 0; // Terminates the program
}