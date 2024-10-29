#include <iostream>
using namespace std;
const int SENTINEL = -1; //Declares the variable SENTINEL as the constant integer

int main(){
    cout<<"Assignment 1-Blazure"<<endl;//Introduction for Assignment 1 program
    cout<<"Looping with a while function and SENTINEL"<<endl;//Describing what the function in the assignment is

    int number; //Assigning the number to the program
    int sum = 0;

    while (true)
    {
        cout<<"Enter number (enter -1 to end)"<<endl;
        cin>>number;

        if (number == SENTINEL){
            break;
        }
        sum += number;
    }
    cout<<"Total Sum"<<sum<<endl;
    return 0;
}