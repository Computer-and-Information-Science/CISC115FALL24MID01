#include <iostream>
using namespace std;

int main() {
    int age;
    char movieType;
    int showTime; // 1 for morning, 2 for afternoon, 3 for evening

    // Base ticket prices
    double basePrice = 10.0; // Base price for 2D
    double price = basePrice;

    // Input age
    cout << "Enter your age: ";
    cin >> age;

    // Input movie type
    cout << "Enter movie type (2 for 2D, 3 for 3D): ";
    cin >> movieType;

    // Input show time
    cout << "Enter show time (1 for morning, 2 for afternoon, 3 for evening): ";
    cin >> showTime;

    // Adjust price based on age
    if (age < 12) {
        price *= 0.5; // 50% discount for children
    } else if (age >= 60) {
        price *= 0.7; // 30% discount for seniors
    }

    // Adjust price based on movie type
    switch (movieType) {
        case '2':
            // No additional charge for 2D
            break;
        case '3':
            price *= 1.5; // 50% extra for 3D
            break;
        default:
            cout << "Invalid movie type!" << endl;
            return 1; // Exit if invalid input
    }

    // Adjust price based on show time
    switch (showTime) {
        case 1:
            price *= 0.8; // 20% discount for morning shows
            break;
        case 2:
            // No additional charge for afternoon
            break;
        case 3:
            price *= 1.2; // 20% extra for evening shows
            break;
        default:
            cout << "Invalid show time!" << endl;
            return 1; // Exit if invalid input
    }

    // Output the final ticket price
    cout << "The final ticket price is: $" << price << endl;

    return 0;
}
