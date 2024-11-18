//**********************************************************************
// Author: Raymond Castro
// Date: 28 Oct 2024
//
// Computer Science I Coding Assignment 3 - Raymond Castro
//
// Using if-else conditions and switch-case statements, this C++ program
// calculates the price of a movie ticket based on age, showtime, seat
// type, and loyalty card status.
//**********************************************************************

// Header files
#include <iostream>
#include <iomanip> // Header file used for input and output manipulators

using namespace std;

int main()
{
    // Variable declarations
    int age, showtime, seatType, loyaltyCardStatus; /* Declares the 
    preceding variables in the int data type */
    double ticketPrice; /* Declares the variable ticketPrice in the double
    data type */

    cout << fixed << showpoint << setprecision(2); /* Formats the
    numbers typed by the user to two decimal points, which is made
    visible to the user in the output */

    cout << "Computer Science I Coding Assignment 3 - Raymond Castro"
         << endl << endl; // Outputs the title of the program
    cout << "This C++ program acts as a movie ticket price calculator and, "
         << "using if-else conditions and switch-case statements, computes "
         << "a movie's ticket price based on the user's input for\nage, "
         << "showtime, seat type, and loyalty card status." << endl << endl;
         // Displays an explanation of the program
        
    while (true) /* Loops the input prompt for age until the user
    inputs it correctly */
    {
        cout << "Children (12 and under): $8.00" << endl; /* Displays prices
        based on age */
        cout << "Adults (13 to 59): $12.00" << endl;
        cout << "Seniors (60 and above): $10.00" << endl << endl;

        cout << "Enter your age: ";
        cin >> age;

        if ((cin.fail()) || (age < 0)) /* Checks whether the input for
        age is valid */
        {
            cin.clear(); // Clears the input stream
            cin.ignore(100, '\n'); /* Ignores the invalid input and clears
            the buffer */
            cout << "Invalid input. Please enter a valid age." << endl << endl;
            // Outputs a statement to the user to input their age again
        }
        else /* Checks for the base ticket price based on
            what value of age the user inputted */
        {
            if (age <= 12)
                ticketPrice = 8.00;
            else if ((age >= 13) && (age <= 59))
                ticketPrice = 12.00;
            else // age >= 60
                ticketPrice = 10.00;
            break; // Breaks the while loop if the input is valid
        }
    }

    while (true) /* Loops the input prompt for showtime until the user
    inputs it correctly */
    {
        cout << "Morning Show (from 9 AM - 5 PM): 10% discount"
             << endl << endl; /* Displays a price based on showtime */
        
        cout << "Enter the showtime [24-hour format between "
             << "9 AM - 5 PM (e.g., 14 for 2 PM)]: ";
        cin >> showtime;
        
        if ((cin.fail()) || (showtime < 0) || (showtime > 23)) /* Checks
        whether the input for showtime is valid */
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Invalid input. Please enter a valid time." << endl << endl;
            // Outputs a statement to the user to input showtime again
        }
        else
        {
            if ((showtime >= 9) && (showtime <= 17)) /* Checks for a
            discount based on what value of showtime the user inputted */
            ticketPrice *= 0.9;
            break;
        }
    }
    
    while (true) /* Loops the input prompt for seatType until the user
    inputs it correctly */
    {
        cout << "1 for (Standard: No extra charge)" << endl; /* Displays
        prices and options based on seatType */
        cout << "2 for (Premium: $5.00)" << endl;
        cout << "3 for (Combo: $7.00)" << endl;
        cout << "4 for (Upgrade for Gold Member: $10.00)" << endl << endl;
    
        cout << "What is your preferred seat type? ";
        cin >> seatType;

    if ((cin.fail()) || (seatType < 1) || (seatType > 4)) /* Checks
        whether the input for seatType is valid */
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Invalid input. Please enter a valid seat type." << endl << endl;
            /* Outputs a statement to the user to input their preferred
            seat type again */
            continue; // Transitions with the next iteration of the while loop
        }
        switch (seatType) /* Adds additional costs to the base ticket price
        based on what value of seatType the user inputted */
        {
            case 1:
                break; // No extra charge
            case 2:
                ticketPrice += 5.00;
                break;
            case 3:
                ticketPrice += 7.00;
                break;
            case 4:
                ticketPrice += 10.00;
                break;
        }
        break;
    }

    while (true) /* Loops the input prompt for loyaltyCardStatus until the
    user inputs it correctly */
    {
        cout << "1 for (Yes: 15% discount)" << endl; /* Displays a price
        and options based on loyaltyCardStatus */
        cout << "0 for No" << endl << endl;

        cout << "Do you have a loyalty card? ";
        cin >> loyaltyCardStatus;

        if ((cin.fail()) || (loyaltyCardStatus < 0) || (loyaltyCardStatus > 1))
        // Checks whether the input for loyaltyCardStatus is valid
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Invalid input. Please enter a valid answer." << endl << endl;
            /* Outputs a statement to the user to input their loyalty
            card status again */
            continue;
        }
        
        if (loyaltyCardStatus == 1) /* Checks for a discount based on what
            value of loyaltyCardStatus the user inputted */
            {
                ticketPrice *= 0.85;
            }
            break;
    }

    cout << "Final ticket price: $" << ticketPrice << endl; /* Outputs the
    final ticket price */

    return 0; // Terminates the program
}