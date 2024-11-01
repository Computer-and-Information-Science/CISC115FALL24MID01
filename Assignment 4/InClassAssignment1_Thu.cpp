#include <iostream>
using namespace std;

const int SENTINEL = -1; // Declare sentinel is constant

int main() {
    int number;
    int sum = 0;
    
    cout<<"*This program will sum all the input numbers until the user enters -1 to stop it.*\n"<<endl; // Output user instruction
    
    
    while (true)
    {
        cout<<"Enter numbers (enter -1 to stop): ";
        cin>>number;

        if (number == SENTINEL){
            break; // Stop the loop when user enters sentinel value
        }
        sum += number;
    }
    
    cout<<"Total Sum is: "<< sum <<endl;
    return 0;
}
