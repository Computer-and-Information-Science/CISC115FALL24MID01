#include <iostream>
#include <string>  // For handling strings like book title and author name

using namespace std;

int main() {
    // Variables to store book information
    string bookTitle;
    string authorName;
    double price;

    // Asking user to enter the book title (including spaces)
    cout << "Enter the title of the book: ";
    getline(cin, bookTitle);  // This allows spaces in the input

    // Asking user to enter the author's name (including spaces)
    cout << "Enter the author's name: ";
    getline(cin, authorName);  // This also allows spaces in the input

    // Asking user to enter the price of the book with simple error checking
    cout << "Enter the price of the book: $";
    cin >> price;

    // If the input for price fails (e.g., if the user enters letters), clear and ask again
    while (cin.fail()) {
        cin.clear();  // Clears the error flag on cin
        cin.ignore(1000, '\n');  // Ignores the invalid input
        cout << "Invalid input. Please enter a valid price: $";
        cin >> price;
    }

    // Display the book information
    cout << "\n--- Book Information ---\n";
    cout << "Title: " << bookTitle << endl;
    cout << "Author: " << authorName << endl;
    cout << "Price: $" << price << endl;

    return 0;
}
