#include <iostream>     // for input & output
#include <iomanip>      // for manipulators like setw, setprecision
#include <limits>       // for numeric_limits
using namespace std;

int main() {
    
    int age, showtime, seat_type, loyal_card;   // variables for age, showtime, seat type and loyalty card status
    float price = 0.0, discount = 0.0;                // initialize price and discount

    // prompt the user for their age
    cout << "Enter your age: ";
    cin >> age;

    // validate input for age
    if (cin.fail()) {
        cin.clear();        // clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore bad input
        cout << "Invalid input. Please enter a number only!\n";
        return 0;           // exit program due to invalid input
    }
    else if (age < 0) {     // check if age is negative
        cout << "Invalid age entered!\n";
        return 0;
    }
    
    // define base price on age
    if (age <= 12)
        price = 8;      // price for children
    else if (age >= 13 && age <= 59)
        price = 12;     // price for adults
    else
        price = 10;     // price for seniors

    //cout << price << " - price after age\n\n";

    // prompt the user for showtime
    cout << "Enter the showtime (in 24-hour format), e.g., 14 for 2 PM): ";
    cin >> showtime;
    
    // validate input for showtime
    if (cin.fail()) {
        cin.clear();        // clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore bad input
        cout << "Invalid input. Please enter a number only!\n";
        return 0;
    }
    else if (showtime < 9 || showtime > 23) {   // check valid time range 
        cout << "Invalid showtime entered! Please enter between 9 and 23!\n";  
        return 0;
    }

    // apply 10% discount if morning show from 9AM to 5PM
    if (showtime >= 9 && showtime <= 17) {
        discount = price * 0.10;
        price -= discount;
    }        

    //cout << price << " - price after show time\n\n";

    // prompt the user for seat type
    cout << "Choose seat type\n1 for Standard\n2 for Premium\n3 for Condo\n4 Upgrade to gold member: ";
    cin >> seat_type;

    // validate for invalid seat type
    if (cin.fail() || seat_type < 1 || seat_type > 4) {
        cin.clear();        // clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore bad input
        cout << "Invalid input. Please enter a number only!\n";
        return 0;
    }

    // determine additional charges on seat type
    switch (seat_type) {
        case 1:     // standard - no extra charge
            price = price;
            break;
        case 2:     // premium - add $5
            price += 5.0;
            break;
        case 3:     // combo - add $7
            price += 7.0;
            break;
        case 4:     // gold - add $10
            price += 10.0;  
            break;
        default:
            cout << "Invalid seat type entered!\n";
            return 0;
    }

    //cout << price << " - price after seat type\n\n";

    // prompt the user for loyalty card status
    cout << "Do you have a loyalty card? (1 for Yes, 0 for No): ";
    cin >> loyal_card;
    
    // validate input for loyalty card status
    if (cin.fail() || (loyal_card != 1 && loyal_card != 0)) {
        cin.clear();        // clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore bad input
        cout << "Invalid input. Please enter 1 for Yes or 0 for No!\n";
        return 0;
    }

    // apply 15% discount if user has a loyalty card
    if (loyal_card == 1) {
        discount = price * 0.15;    
        price -= discount;          
    }

    //cout << price << " - price after loyalty card\n\n";
    
    // output final ticket price with formatting to 2 decimal places
    cout << fixed << setprecision(2);   
    cout << "Final Ticket Price: $" << price << endl;

    return 0;
}