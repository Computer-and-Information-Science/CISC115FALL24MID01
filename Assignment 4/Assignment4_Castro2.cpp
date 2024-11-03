//**********************************************************************
// Author: Raymond Castro
// Date: 3 Nov 2024
//
// Computer Science I Coding Assignment 4 Program 2 - Raymond Castro
//
// Using nested for loops, this C++ program prints a pattern in the
// shape of a pyramid, with loops for row iteration, leading spaces that
// decrease with each row, and number printing corresponding to the row
// number, with a new line for each row.
//**********************************************************************

// Header file
#include <iostream>

using namespace std;

int main()
{
    int rows = 5; // Stores the integer 5 into rows

    cout << "Computer Science I Coding Assignment 4 Program 2 - Raymond "
         << "Castro" << endl << endl; // Outputs the title of the program
    cout << "This C++ program outputs a pyramid-like pattern to the user by "
         << "utilizing nested for loops. The outer loop iterates through "
         << "each row, the first inner loop is for leading spaces,\nwith 4 "
         << "spaces for indentation, and the second inner loop prints the "
         << "current row number multiple times, each followed by 7 spaces. "
         << "A new line is also printed with each row." << endl << endl;
         // Displays an explanation of the program

    for (int l = 1; l <= rows; l++) /* Prints rows until l is less than or
    equal to what is stored in rows */
    {
        for (int m = l; m < rows; m++) /* Prints 4 leading spaces for
        consistent spacing until m is less than rows */
        {
            cout << "    ";
        }

        for (int n = 1; n <= l; n++) /* Prints l repeatedly in each row,
        with 7 spaces for proper alignment, until n is less than or equal
        to rows */
        {
            cout << l << "       ";
        }

        cout << endl; /* Advances to the next row with each iteration of the
        nested for loops */
    }

    return 0; // Terminates the program
}