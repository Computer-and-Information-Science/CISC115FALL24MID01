#include <iostream>
using namespace std;

int main() {
    int rows = 5;

    for (int i = 1; i <= rows; i++) { // Print the numbers of row until it less than equal to 5
        // create spaces to get a pyramid shape
        for (int j = 1; j <= rows - i; j++) {
            cout << "  ";  // Two spaces
        }
        
        for (int k = 1; k <= i; k++) { // // Print numbers from 1 until it equals to i
            cout << i << "    "; // Four spaces
        }

        cout << endl; // Move to the next row
    }

    return 0;
}
