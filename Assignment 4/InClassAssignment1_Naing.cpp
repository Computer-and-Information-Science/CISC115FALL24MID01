#include <iostream>
using namespace std;

int main() {
    const int SENTINEL = -1;  // Sentinel value to stop input
    int number, total_sum = 0;

    cout << "Enter numbers to sum (-1 to stop): ";
    while (true) {
        cin >> number;

        if (number == SENTINEL)  // Sentinel condition
            break;

        total_sum += number;  // Adding number to total sum
    }
    cout << "The sum of the entered numbers is: " << total_sum << endl;

    return 0;
}
