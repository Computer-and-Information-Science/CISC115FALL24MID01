#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows for the pyramid: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++) {
        for (int j = i; j < rows; j++) {
            cout << "    "; // 4 spaces for indentation
        }
        // Print numbers in the current row
        for (int k = 1; k <= i; k++) {
            cout << i << "       "; // 7 spaces between numbers
        }
        cout << endl; // Newline after each row
    }

    return 0;
}
