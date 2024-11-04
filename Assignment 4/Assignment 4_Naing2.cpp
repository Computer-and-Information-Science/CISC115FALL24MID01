#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows for the pyramid: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int j = i; j < rows; j++) {
            cout << " ";
        }
        // Print numbers with a single space between each
        for (int k = 1; k <= i; k++) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
