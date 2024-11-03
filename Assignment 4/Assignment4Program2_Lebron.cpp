// Assignment4_Lastname2.cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 5;  // Number of rows in the pyramid

    for (int i = 1; i <= rows; i++) {              // Outer loop for rows
        // Print leading spaces
        for (int j = 1; j <= rows - i; j++) {
            cout << "    ";                        // 4 spaces for alignment
        }

        // Print numbers with spacing
        for (int k = 1; k <= i; k++) {
            cout << i << "       ";                // 7 spaces between numbers for alignment
        }

        cout << endl;                              // Move to next row after each row
    }

    return 0;
}