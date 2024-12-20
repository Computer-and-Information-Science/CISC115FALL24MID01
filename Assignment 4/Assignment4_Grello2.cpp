#include <iostream>
using namespace std;                               // Allows shorthand for standard library names
int main() {
    int rows = 5;                                  // Number of rows for pyramid

                                                   // Outer loop to handle number of rows
    for (int i = 1; i <= rows; i++) {
                                                   // Inner loop for printing leading spaces
        for (int j = i; j < rows; j++) {
            cout << "  ";                          // Two spaces for alignment
        }
                                                   // Inner loop for printing numbers
        for (int j = 1; j <= i; j++) {
            cout << i << "   ";                    // Prints row number with spacing
        }
        cout << endl;                              // Moves to next line after each row
    }
    return 0;                                      // Success
}