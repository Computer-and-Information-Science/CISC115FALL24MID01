#include <iostream>
using namespace std;

int main() {
    int rows;

    // Ask user for the number of rows
    cout << "Enter the number of rows for the pyramid: ";
    cin >> rows;

    // Outer loop for each row
    for (int i = 1; i <= rows; ++i) {
        
        // Inner loop for leading spaces
        for (int j = 1; j <= rows - i; ++j) {
            cout << " ";
        }

        // Inner loop for printing numbers
        for (int k = 1; k <= i; ++k) {
            cout << k << " ";
        }

        // Move to the next line after each row
        cout << endl;
    }

    return 0;
}
