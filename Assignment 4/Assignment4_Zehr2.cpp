//
//  Assignment4_Zehr2.cpp
//  Homework Week 4 Program 2
//
//  Created by Isaac Zehr
//
#include <iostream>
using namespace std;

int main() {
    int rows = 5; //sets up 5 rows

    for (int i = 1; i <= rows; i++) {
        // Print leading spaces:
        // For each row i, print (rows - i) groups of 4 spaces:
        for (int s = 1; s <= (rows - i); s++) {
            cout << "    "; // 4 spaces
        }

        // Print the row number i, i times, with 7 spaces between them:
        for (int j = 1; j <= i; j++) {
            cout << i;
            if (j < i) {
                cout << "       "; // 7 spaces between numbers
            }
        }

        cout << endl; // Move to the next line after each row
    }

    return 0;
}