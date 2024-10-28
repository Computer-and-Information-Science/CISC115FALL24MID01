#include <iostream>
#include <iomanip> // for setting precision
using namespace std;

int main() {
    // Variables
    int age, showtime, seatType;
    char loyaltyCard;
    double basePrice = 0.0, finalPrice = 0.0, discount = 0.0;

    // Step 1: Ask for and validate age
    do {
        cout << "Enter your age (positive number): ";
        cin >> age;
        if (age <= 0) {
            cout << "Invalid input. Age must be a positive number. Please try again.\n";
        }
    } while (age <= 0);

    // Determine base price based on age
    if (age <= 12) {
        basePrice = 8.00;
    } else if (age <= 59) {
        basePrice = 12.00;
    } else {
        basePrice = 10.00;
    }

    // Step 2: Ask for and validate showtime
    do {
        cout << "Enter the showtime (in 24-hour format, between 9 and 23): ";
        cin >> showtime;
        if (showtime < 9 || showtime > 23) {
            cout << "Invalid input. Showtime must be between 9 and 23. Please try again.\n";
        }
    } while (showtime < 9 || showtime > 23);

    // Apply 10% discount for morning shows (9 AM to 5 PM)
    if (showtime >= 9 && showtime <= 17) {
        discount = basePrice * 0.10;
        basePrice -= discount;
    }

    // Step 3: Ask for and validate seat type using switch-case
    do {
        cout << "Choose seat type:\n";
        cout << "1 - Standard (No extra charge)\n";
        cout << "2 - Premium (Add $5.00)\n";
        cout << "3 - Combo (Add $7.00)\n";
        cout << "4 - Gold Member (Add $10.00)\n";
        cout << "Enter your choice (1-4): ";
        cin >> seatType;
        if (seatType < 1 || seatType > 4) {
            cout << "Invalid input. Please choose a seat type between 1 and 4.\n";
        }
    } while (seatType < 1 || seatType > 4);

    // Apply seat type charges using switch-case
    switch (seatType) {
        case 1:
            // Standard: no extra charge
            break;
        case 2:
            basePrice += 5.00; // Premium: add $5.00
            break;
        case 3:
            basePrice += 7.00; // Combo: add $7.00
            break;
        case 4:
            basePrice += 10.00; // Gold Member: add $10.00
            break;
    }

    // Step 4: Ask for and validate loyalty card status
    do {
        cout << "Do you have a loyalty card? (Y/N): ";
        cin >> loyaltyCard;
        if (loyaltyCard != 'Y' && loyaltyCard != 'y' && loyaltyCard != 'N' && loyaltyCard != 'n') {
            cout << "Invalid input. Please enter 'Y' for yes or 'N' for no.\n";
        }
    } while (loyaltyCard != 'Y' && loyaltyCard != 'y' && loyaltyCard != 'N' && loyaltyCard != 'n');

    // Apply 15% loyalty card discount if applicable
    if (loyaltyCard == 'Y' || loyaltyCard == 'y') {
        discount = basePrice * 0.15;
        basePrice -= discount;
    }

    // Step 5: Display the final ticket price with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "The final ticket price is: $" << basePrice << endl;

    return 0;
}
