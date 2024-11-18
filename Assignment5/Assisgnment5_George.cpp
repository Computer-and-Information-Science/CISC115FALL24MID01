#include <string>
#include <iostream>
using namespace std; 
#include <iomanip>
#include <cmath>
static int count = 0;
//prototyping my functions
void BasicCalculator();
void greetUser(string name, string title);
double fahrenheitToCelsius(double fahrenheit);
double celsiusToFahrenheit(double celsius);
double calculateRectangle(double length, double width);
int incrementCounter();
double calculateArea(double num1, double num2, double num3);



double calculateArea(double radius){

double area;
area = M_PI * pow(radius, 2);
return area;
}

double calculateArea(double length, double width){

double area;
area = length * width;
return area;
}

double calculateArea(double base, double height, bool isTriangle){

double area;
area = (base *height)/2;
return area; 
}

int main(){
//declaring variables 
double Num1;
double Num2;
string stringInput;
string title;
int userInput;
int control = 0;
//creating my loop
while (control == 0){

cout<< "What kind of Opperation would you like?" << '\n';
cout << "1: Basic Calculator" <<'\n';
cout<< "2: Temperature conversion" <<'\n';
cout << "3: Rectangle Area and Perimeter" << '\n';
cout << "4: Counter Function " << '\n';
cout << "5: Shape Area Claculation" << '\n';
cout << "6: Greet User" <<'\n';
cout << "7: Exit" << '\n';
cout<< "Please Enter your choice: " ;
cin >> userInput;
//switch statement for selections
switch(userInput){
        case 1:{
        BasicCalculator();
        break;
        }
        case 2:{
        cout<< "What type of conversion would you like to do?" << '\n';
        cout << "1: Fahrenheit to celsius" << '\n';
        cout << "2: Celsius to fahrenheit" << '\n';
        cout << "Please make your choice: ";
        cin >> userInput;

        if (userInput == 1){
        cout << "Please enter your number in degrees fahrenheit: " ;
        cin >> Num1;
        cout << fahrenheitToCelsius(Num1);
        
        
        }
        if(userInput == 2){
        cout << "Please enter your number in degrees celsius : " ;
        cin >> Num1;
        cout << celsiusToFahrenheit(Num1) << '\n';
        }
        break;
        }
        case 3:{
        cout << "please enter your length number: " ;
        cin >> Num1;
        cout << "Please enter your width number: ";
        cin >> Num2;
        cout << calculateRectangle(Num1, Num2) << '\n';
        break;
        }
        case 4:{
        //calling increment function a desired amount of times 
        cout << "How many times would you like to call this function: ";
        cin >> Num1;
        for (int x = 0; x < Num1; ++x){
            cout << incrementCounter() << '\n';
        }
        break;
        }
        case 5:{
        cout << "Please choice what shape you would like to calculate." << '\n';
        cout << "1: Circle" << '\n';
        cout << "2: Rectangle" << '\n';
        cout << "3: Triangle" << '\n';
        cout << "Please make a choice: ";
        cin >> userInput;

        if(userInput == 1){
        cout << "Please provide the radius of your circle: ";
        cin >> Num1;
        cout << calculateArea(Num1) << '\n';


        }
        if(userInput == 2){
        cout << "Please provide your rectangles length: ";
        cin >> Num1;
        cout << "Please provide your reclangles width: ";
        cin >> Num2;
        cout << calculateArea(Num1,Num2) << '\n';


        }
        if(userInput == 3){
        cout << "Please enter your triangle's base: ";
        cin >> Num1;
        cout << "Please enter your trinagle's height: ";
        cin >> Num2;
        cout << calculateArea(Num1,Num2, true) << '\n';
        }
        break;
        }

        case 6:{
        cout << "Please enter your name: ";
        getline(cin>> ws ,stringInput);
        
        cout << "Please enter a title (Or leave blank for the default): ";
    
        getline(cin,title);
        
        greetUser(stringInput, title);

        break;
        }
        case 7:{
        //program ending lines
        control = 1;
        cout << "Thank you for using this program, Ending program";
        break;
        }


}      

}
}

//all prototyped functions bodies 

void greetUser(string name, string title = "Mr./Ms."){

cout << "Hello, " << title << name << '\n';

}

int incrementCounter(){
    count = count + 1;
    return count;
}



void BasicCalculator(){
int userInput;
double num1;
double num2;

cout << "1: Square root" << '\n';
cout << "2: Power" << '\n';
cout << "3: Absoulute Vaule" << '\n';
cout << "Please make your choice: ";
cin >> userInput;

switch (userInput){
    case 1:{
        cout << "Please enter your number: ";
        cin >> num1;
        cout << "Your answer is " << sqrt(num1) << '\n';
        break;
    }
    case 2:{
        cout << "Please enter your base number: ";
        cin >> num1;
        cout << "Please enter your exponent: ";
        cin >> num2;
        cout << "your answer is " << pow(num1,num2) << '\n';
        break;
    }
    case 3:{
        cout << "Please enter your number :";
        cin >> num1;
        cout << "Your answer is " << abs(num1) << '\n';
        break;
    }
}

}
double fahrenheitToCelsius(double fahrenheit){
double celsius;
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}


double celsiusToFahrenheit(double celsius){
double fahrenheit;
    fahrenheit = celsius * 1.8 + 32;
    return fahrenheit;
}

double calculateRectangle(double length, double width){
double area; 
double perimeter;
int userInput;
area = length * width;
perimeter = 2 * (length * width);

cout << "Which vaule would you like?" <<'\n';
cout << "1: Area vaule" << '\n';
cout << "2: Perimeter Vaule" << '\n';
cout << "Which would you like: ";
cin >> userInput;
if(userInput == 1){
    return area;
}
if(userInput == 2){
    return perimeter;
}
return 0;
}
