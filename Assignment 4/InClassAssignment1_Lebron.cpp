#include <iostream>
using namespace std;

const int SENTINEL = -1; // Declares  the variable SENTINEL as a constant integer 

int main() {
    int number, total_sum = 0; // Declares the variable sum and number in the int data type 

    // Sentinel-controlled while loop
    while (true) {
        cout << "Enter a number (-1 to stop): ";
        cin >> number;

        if (number == 0)  // Sentinel condition
            break;
        
        total_sum += number;  // Add number to total sum
    }

    cout << "The sum of the entered numbers is: " << total_sum << endl;

    
    return 0;
}