//*********************************************************************
// Author: Raymond Castro
// Date: 6 Oct 2024
//
// Computer Science I Coding Assignment 1 - Raymond Castro
//
// This C++ Program displays my name, age, height in feet and inches,
// desired grade in the CISC115_MID_01_FA24 course, and a new age
// and rounded height based on implicit & explicit type conversions
// to the user.
//*********************************************************************

// Header files included
#include <iostream>
#include <string>

using namespace std;

int main()
{
     // Variable declarations
     string name = "Raymond Castro"; /* Stores the string "Raymond
     Castro" into name */
     int age = 18; // Stores the integer 18 into age
     float height = 5.9; // Stores the decimal 5.9 into height
     char grade = 'A'; // Stores the character 'A' into grade

     // Variable initializations
     float newAge = age; /* Assigns what is stored in age to newAge;
     implicitly converts age into the float data type */
     int roundedHeight = static_cast<int>(height); /* Explicitly casts
     height as an integer; assigns what is stored in height to
     roundedHeight */

    // Output statements
     cout << "Computer Science I Coding Assignment 1 - Raymond Castro"
          << endl << endl; // Outputs the title of the program
     cout << "Being my first basic C++ program in the "
          << "CISC115_MID_01_FA24 course, this C++ program outputs to "
          << "the user my age, height in feet and inches,\ndesired "
          << "grade, and a new age and rounded height based on "
          << "implicit and explicit type conversion."
          << endl << endl; // Displays an explanation of the program

     cout << "Name: " << name << endl
          << "Age: " << age << " years old" << endl
          << "Height: " << height << " inches" << endl
          << "My Desired Grade in CISC115_MID_01_FA24: " << grade
          << endl << endl; /* Inserts what is stored in the variables
          into the output */

     cout << "New Age (float): " << newAge << " years old" << endl
          << "Rounded Height (int): " << roundedHeight << " inches"
          << endl << endl; /* Inserts what is stored in the updated
          variables into the output */

    cout << "Nice to meet you all! Best of luck with the Fall 2024 "
         << "semester! I look forward to working with all of you!"
         << endl; /* Exhibits a greeting message from me to the other
         students in the CISC115_MID_01_FA24 course */
  
    return 0; // Terminates the program
}