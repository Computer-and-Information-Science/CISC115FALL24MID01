#include <iostream>
#include <iomanip>
using namespace std;

// Function to get the base ticket price based on age
double getBasePrice(int age) {
    if (age <= 12) {
        return 8.00;
    } else if (age >= 13 && age <= 59) {
        return 12.00;
    } else if (age >= 60) {
        return 10.00;
    } else {
        return -1; // Invalid age
    }
}

// Function to get seat type price adjustment based on user input
double getSeatTypePrice(int seatTypeOption) {
    switch (seatTypeOption) {
        case 1: // Standard
            return 0.0;
        case 2: // Premium
            return 5.0;
        case 3: // Combo
            return 7.0;
        case 4: // Gold
            return 10.0;
        default:
            return -1; // Invalid option
    }
}

// Main function
int main() {
    int age, showtime, seatTypeOption;
    double basePrice;
    char loyaltyCard;
    bool validInput = false;

    // Get the age from the user
    while (!validInput) {
        cout << "Enter your age: ";
        cin >> age;
        if (age > 0) {
            validInput = true;
        } else {
            cout << "Invalid age. Please enter a positive number.\n";
        }
    }

    // Calculate the base price
    basePrice = getBasePrice(age);
    if (basePrice == -1) {
        cout << "Error calculating base price.\n";
        return 1;
    }

    // Get the showtime from the user
    validInput = false;
    while (!validInput) {
        cout << "Enter showtime (in 24-hour format, e.g., 14 for 2 PM): ";
        cin >> showtime;
        if (showtime >= 9 && showtime <= 23) {
            validInput = true;
        } else {
            cout << "Invalid showtime. Please enter a time between 9 and 23.\n";
        }
    }

    // Apply the showtime discount if applicable
    if (showtime >= 9 && showtime <= 17) {
        basePrice *= 0.90; // 10% discount
    }

    // Get the seat type from the user using numeric options
    validInput = false;
    while (!validInput) {
        cout << "Select seat type: \n";
        cout << "1. Standard\n";
        cout << "2. Premium\n";
        cout << "3. Combo\n";
        cout << "4. Upgrade to Gold Member\n";
        cout << "Enter the number corresponding to your choice: ";
        cin >> seatTypeOption;

        double seatPrice = getSeatTypePrice(seatTypeOption);
        if (seatPrice != -1) {
            basePrice += seatPrice;
            validInput = true;
        } else {
            cout << "Invalid option. Please enter a number between 1 and 4.\n";
        }
    }

    // Check if the user has a loyalty card
    validInput = false;
    while (!validInput) {
        cout << "Do you have a loyalty card? (Press 1 for Yes, 0 for No): ";
        cin >> loyaltyCard;
        if (loyaltyCard == '1' || loyaltyCard == '0') {
            validInput = true;
            if (loyaltyCard == '1') {
                basePrice *= 0.85; // Apply 15% discount
            }
        } else {
            cout << "Invalid input. Please enter '1' for yes or '0' for no.\n";
        }
    }

    // Display the final ticket price with two decimal precision
    cout << fixed << setprecision(2);
    cout << "The final ticket price is: $" << basePrice << endl;

    return 0;
}