#include <iostream>
using namespace std;

int main() 
{
    int rows;
    cout << 5;
    cin >> rows;

    for (int i = 1; i <= rows; i++) 
    {
        //Prints leading spaces
        for (int j = i; j < rows; j++) 
        {
            cout << " ";
        }
        //Prints numbers with a single space between each
        for (int k = 1; k <= i; k++) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}