// Program 2: Printing pyramid pattern using nested for loops
#include <iostream>     // for input & output
using namespace std;

int main() {
    
    int rows = 5;   // initialize number of rows    
    
    for (int i = 1; i <= rows; i++) {       // outer loop - control the number of rows
                                                // loop variable i represents the current row number

        for (int j = rows; j > i; j--) {    // inner loop 1 - print leading spaces (decreasing number of spaces as moving down the rows)
            cout << "    ";                     // 4 spaces for indentation
        }

        for (int k = 1; k <= i; k++) {      // inner loop 2 - print numbers in each row
            cout << i << "       ";             // print current row number i multiple times, with 7 spaces between numbers
        }

        cout << endl;   // print a new line to move to the next row

    }

    return 0;
}