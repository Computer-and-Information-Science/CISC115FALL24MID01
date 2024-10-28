//***********************************************************************
// Author: Raymond Castro
// Date: 13 Oct 2024
//
// Computer Science I Coding Assignment 2 - Raymond Castro
//
// This C++ Program collects and displays book information. Utilizing
// predefined functions, manipulators, and debugging techniques, the
// user will input their book's title, author, and price, which the
// program will output in a neat format. The program will also ask the
// user to reenter the price if they enter an invalid input.
//**********************************************************************

// Header files
#include <iostream>
#include <iomanip> // Header file used for input and output manipulators
#include <string>

using namespace std;

int main()
{
     // Variable declarations
     string bookTitle; /* Declares the variable bookTitle in the string
     data type */
     string authorName; /* Declares the variable authorName in the string
     data type */
     double bookPrice; /* Declares the variable bookPrice in the double
     data type */

     cout << "Computer Science I Coding Assignment 2 - Raymond Castro"
          << endl << endl; // Outputs the title of the program
     cout << "This C++ program collects and displays details for a book "
          << "chosen by the user. Using predefined functions, manipulators, "
          << "and debugging techniques, the program takes in the user's\n"
          << "input of a book's title, author, and price, then neatly "
          << "outputs the data. It also prompts the user to input the "
          << "price again if it was an invalid input." << endl << endl;
          // Displays an explanation of the program

     cout << "Enter the book's title: ";
     getline(cin, bookTitle); /* Reads the inputted string, including
     whitespaces, then stores it in bookTitle */

     cout << "Enter the author's name: ";
     getline(cin, authorName); /* Reads the inputted string, including
     whitespaces, then stores it in authorName */

     cout << fixed << showpoint << setprecision(2); /* Formats the
     number typed by the user for bookPrice to two decimal points,
     which is made visible to the user in the output */
     while (true) /* Loops the input prompt for bookPrice until the user
     inputs it correctly */
     {
          cout << "Enter the book's price: $";
          cin >> bookPrice;
          cout << endl;
          if (cin.fail()) // Checks whether the input for bookPrice is valid
          {
               cin.clear(); // Clears the input stream
               cin.ignore(100,'\n'); /* Ignores the invalid input and clears
               the buffer */ 
               cout << "Invalid input. Please enter a valid price." << endl << endl;
               // Outputs a statement to the user to input the price again
          }
          else
          {
               break; // Breaks the while loop if the input is valid
          }
     }
    
     cout << "----- Book Details -----" << endl; /* Outputs the inputted
     user data in a neat manner, with whitespace between the titles and
     data */
     cout << "Title: " << setw(4) << bookTitle << endl;
     cout << "Author: " << setw(3) << authorName << endl;
     cout << "Price: $" << setw(2) << bookPrice << endl << endl;
    
     return 0; // Terminates the program
}