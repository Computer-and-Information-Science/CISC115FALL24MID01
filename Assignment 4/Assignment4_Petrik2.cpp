#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //variables needed to make the number pyramid
    int x;
    int y;
    int z = 21;
    //these two for loops loop through each other to create the number pyramid
    for (x = 1; x <= 5; x++)
    {
        cout<<setw(z)<<setfill(' ');//uses an external loop control variable to set the distance from the left side of the terminal
        for (y = 0; y < x; y++)
        {
	    //uses the x variable of the external loop to set the current number displayed on the pyramid and displays each number 10 spaces apart from another
            cout<<(x)<<setw(10)<<setfill(' ');
        }
        z = z-5;//modifies the external loop control variable to have a smaller value by 5
        cout<<endl;//moves the line to the next one
    }
}
