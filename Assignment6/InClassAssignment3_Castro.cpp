//**********************************************************************
// Author: Raymond Castro
// Date: 19 Nov 2024
//
// Computer Science I In Class Assignment 3 - Raymond Castro
//
// This C++ program utilizes enum keywords and a for loop to count and
// iterate the days of a week, printing their values in the output.
//**********************************************************************

// Header files
#include <iostream>

using namespace std;

int main()
{
    cout << "Computer Science I In Class Assignment 3 - Raymond Castro"
         << endl << endl; // Outputs the title of the program
    cout << "Through enum keywords and a for loop, this C++ program iterates "
         << "through and prints the values of the days of the week (e.g., "
         << "Sunday, Monday, Tuesday, Wednesday, Thursday, Friday,\nand "
         << "Saturday), with week being an enum data type." << endl << endl;
         // Displays an explanation of the program

    enum week {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY} day;
    /* Declares week as an enum data type, the days of the week as enumerators,
    and the variable day in the week data type */ 
    
    for (day = SUNDAY; day <= SATURDAY; day = static_cast<week>(day + 1))
    /* Prints the assigned integer value of day, starting at 0 for SUNDAY,
    incrementing until day is less than SATURDAY, which is assigned 6 by default */
    {
        cout << day << endl;
    }
    
    cout << "There are " << day << " days in a week." << endl;
    // Outputs the final value assigned to day by the for loop, which is 7

    return 0; // Terminates the program
}