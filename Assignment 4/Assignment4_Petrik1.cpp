#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //variables needed to run the program
    double number1;  
    double number2; 
    char operation;
    char decision;
    do
    {
        //introduces the program to the user
        cout<<"Welcome to the Menu-Driven Calaculator!"<<endl;
        cout<<"Enter the first number: ";
        //takes the first input from the user
        cin>>number1;
        //checks to see if the user inputted a number
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"Invalid input. Please enter a number."<<endl;
            return 0;
        }
        cout<<"Enter the second number: ";
        //takes the second input from the user
        cin>>number2;
        //checks to see if the user inputted a number
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"Invalid input. Please enter a number."<<endl;
            return 0;
        }
        //describes what operations are available for use
        cout<<setw(40)<<setfill('-')<<"\n";
        cout<<"Please choose the operation you'd like to perform:\n1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)\n";
        cout<<setw(40)<<setfill('-')<<"\n";
        cout<<"Choose an operation (+, -, *, /): ";
        //takes the operation given by the user
        cin>>operation;
        //checks and prints the results of using the chosen operation with the inputted numbers
        if (operation == '+'){
            cout<<"Result: "<<number1<<" + "<<number2<<" = "<<(number1 + number2)<<endl;
        } else if (operation == '-'){
            cout<<"Result: "<<number1<<" - "<<number2<<" = "<<(number1 - number2)<<endl;
        } else if (operation == '*'){
            cout<<"Result: "<<number1<<" * "<<number2<<" = "<<(number1 * number2)<<endl;
        } else if (operation == '/'){
            //checks if the second number is equal to zero
            if (number2 != 0){
                cout<<"Result: "<<number1<<" / "<<number2<<" = "<<(number1 / number2)<<endl;
            } else {
                cout<<"ERROR!"<<endl;
                cout<<"Error: Division by zero is not allowed!"<<endl;
            }
        } else {
            //checks if the user didn't put a valid operation
            cout<<"Invalid input. Enter a mathmatical operator."<<endl;
        }
        //asks the user to input y or n to continue or terminate the program
        cout<<"Do you want to perform another calculation? (y/n): ";
        cin>>decision;
        //checks to see if the user actually inputted y or n
        while ((decision != 'y') && (decision != 'n'))
        {
            cout<<"Invalid input. Please enter y (yes) or n (no):"<<endl;
            cin>>decision;
        }
    }
    while (decision != 'n');//makes the decision to continue the loop according to the response from the user
    //closing statment that tells the user that the program has ended
    cout<<"Thank you for using the calcualtor. Goodbye!"<<endl;
}
