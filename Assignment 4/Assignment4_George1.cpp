# include <string>
#include <iostream>
using namespace std; 
#include <iostream>
#include <iomanip>

int main(){
    double num1;
    double num2;
    char opperation;
    int control = 0;
    int EndProgram = 1;
    double sum;
    int loopAmount = 0;

    while (control < 1){


     if (loopAmount > 0){
     cout<< "would you like to end the program or continue, if so please enter a '0', if you want to continue enter a 1: ";
            cin>> EndProgram;
            if(EndProgram == 0){
                        cout << '\n' << "Ending Program.";
                        control = 2;
                //Checking if the user wants to end the program after one loop
                }}if(EndProgram == 1){
                
    
        cout<< "Please enter you two chosen numbers seperated by a space: ";
        cin >> num1 >>num2;
        cout<< "Addition '+' " << '\n';
        cout<< "Subtraction '-' " << '\n';
        cout<< "Multiplication '*' " << '\n';
        cout<< "Division '/' " << '\n';
        cout << "Please enter your desireded opporation: ";
        cin >> opperation;
//asking for the numbers that want to be used and what opporator the user wants to use
        switch(opperation){
                case('+'):{
                    cout<< num1 << " + " << num2 <<" = " << num1+num2 << '\n';
                    ++loopAmount;
                    break;
                    //using addition and increasing the loop amount
                }
                case('-'):{
                    cout<< num1 << " - " << num2 <<" = " << num1-num2 << '\n';
                    ++loopAmount;
                    //using subtraction and increasing the loop amount
                    break;


                }

                case('*'):{
                    cout<< num1 << " * " << num2 <<" = " << num1*num2 << '\n';
                    ++loopAmount;
                    //using multiplicatioon and increasing the loop amount
                    break;


                }
                case('/'):{
                while (num2 == 0){
                    if(num2 == 0){
                        cout << "Your second number can't be a zero to prevent a divide by zero error, please enter a diffrent num2 : ";
                        cin>> num2;
                        //preventing a divide by 0 error
                    }}
                    sum = num1/num2;
                    cout<< num1 << " / " << num2 <<" = " << fixed <<  sum << '\n';
                    ++loopAmount;
                    break;
                    //using division and increasing the loop amount

                }
               
        }
     }
        



    
    
    
    }







}
