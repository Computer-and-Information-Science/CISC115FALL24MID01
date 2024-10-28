#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Initialize variables
    int age;
    int time;
    int discount;
    int seat;
    int card; 
    double price = 0;

    // Prompt user for info
    cout << "Before purchasing a ticket you must give some information." << endl;
    cout << "What is your age: ";
    while(!(cin >> age))
    {
        cin.clear();
        cin.ignore(999,'\n');
        cout << "Invalid age! Please be sure you are only entering a number: ";
    }
    cout << endl;

    cout << "What time is the movie (24 hour format): ";
    while(!(cin >> time))
    {
        cin.clear();
        cin.ignore(999,'\n');
        cout << "Invalid time. Please be sure you are entering a valid time (Ex. 9 for 9 AM, 14 for 2 PM): ";
    }
    cout << endl;

    cout << "What type of seat would you like? (1 = Standard, 2 = Premium, 3 = Combo, 4 = Gold Member Upgrade): ";
    while(!(cin >> seat))
    {
        cin.clear();
        cin.ignore(999,'\n');
        cout << "Invalid type. Please enter 1, 2, 3, or 4.";
    }
    cout << endl;

    cout << "Do you have a loyalty card? (1 = Yes, 2 = No): ";
    while(!(cin >> card))
    {
        cin.clear();
        cin.ignore(999,'\n');
    }
    cout << endl;

    // Calculate price based on age
    if (age <= 12)
        price = 8;
    else if ((age >= 13) && (age <= 59))
        price = 12;
    else
        price = 10;

    // Calculate discount if applicable
    if ((time >= 9) && (time <= 17))
    {
        discount = price * 0.10;
        price - discount;
    }

    // Calculate extra cost based on seat type
    switch (seat)
    {
        case 1:
            break; // Standard seat
        case 2:
            price += 5; // Premium seat
            break;
        case 3:
            price += 7; // Combo seat
            break;
        case 4:
            price += 10; // Gold member seat
            break;
    }

    // Calculate discount based on loyalty card
    if(discount == 1)
    {
        discount = price * 0.15;
        price - discount;
    }

    // Output final ticket price
    cout << "Final ticket price: $" << price << endl;

    return 0;
}