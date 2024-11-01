#include <iostream>

using namespace std;

const int SENTINEL = -1;

int main () {

// First we declare the variables.
int number;
int sum = 0;

// Introduction of the program.
cout << "CompSci In-Class Assignment 1 - Kameron M" << endl << endl;
cout <<  "Shwoing how a Sentinel controlled while loop is used." << endl << endl;

//Introducing the while function for our "SENTINEL while loop."
while (true)
{
    //Asking for user input.
    cout << "Enter any number to continue the loop, enter -1 to end the loop: " << endl << endl;
    cin >> number;

    // Include if function in the while function so we can have a way to exit this loop by using the SENTINEL value.
    if (number == SENTINEL)
    {
        break; // Add a break so it can exit this loop.
    }
    
    sum += number; // This will take all usr inputs from cin and add them with the use of the addition operator, giving us our sum.
}

 cout << endl << "Total sum of entered values is: " << sum << endl << endl; 
 //Completed the program and all inputs should add up to a sum, for example "1+1=2" if you entered 1 followed by another 1 and then terminated the program.



return 0;

}