#include <iostream>
#include <iomanip>
using namespace std;

double determineBasePrice(int age) {
    if (age <= 12) {
        return 8.00;
    } else if (age >= 13 && age <= 59) {
        return 12.00;
    } else if (age >= 60) {
        return 10.00;
    } else {
        return -1; // for invalid input
    }
}

double determineSeatTypePrice(int seatType) {
    switch (seatType) {
        case 1: // Standard
            return 0.0;
        case 2: // Premium
            return 5.0;
        case 3: // Combo
            return 7.0;
        case 4: // Gold
            return 10.0;
        default:
            return -1; // for invalid input
    }
}

int main() {
    int age, showtime, seatType;
    char loyaltyCard;
    double ticketPrice = 0.0;
    bool validInput = false;

    // Get user's age
    while (!validInput) {
        cout << "Enter your age: ";
        cin >> age;
        if (age > 0) {
            validInput = true;
        } else {
            cout << "Error: Please enter a valid age." << endl;
        }
    }

    // Determine base ticket price based on age
    ticketPrice += determineBasePrice(age);

    validInput = false;
    // Get showtime
    while (!validInput) {
        cout << "Enter the showtime (24-hour format): ";
        cin >> showtime;
        if (showtime >= 9 && showtime <= 23) {
            validInput = true;
        } else {
            cout << "Error: Please enter a valid showtime between 9 to 23." << endl;
        }
    }

    // 10% discount
    if (showtime >= 9 && showtime < 17) {
        ticketPrice *= 0.90; 
    }

    validInput = false;
    // Get seat type
    while (!validInput) {
        cout << "Select seat type: \n";
        cout << "1. Standard\n";
        cout << "2. Premium\n";
        cout << "3. Combo\n";
        cout << "4. Upgrade to Gold Member\n";
        cout << "Please select your choice in number: ";
        cin >> seatType;

        double seatPrice = determineSeatTypePrice(seatType);
        if (seatPrice != -1) {
            ticketPrice += seatPrice; // Add the seat type price
            validInput = true;
        } else {
            cout << "Error: Please enter a valid seat type number." << endl;
        }
    }

    // Check for loyalty card
    cout << "Do you have a loyalty card? (y for Yes, n for No): ";
    cin >> loyaltyCard;

    if (loyaltyCard == 'y') {
        ticketPrice *= 0.85; 
    }

    // Output the total ticket price
    cout << fixed << setprecision(2);
    cout << "Total ticket price is: $" << ticketPrice << endl;

    return 0;
}
