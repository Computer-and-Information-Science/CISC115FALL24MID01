#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
 string name;
 string title;
 char again;
 cout << "Welcome to my Ultimate Mathing Program!" << '\n';

 cout << " Please Select an option: " << endl << "1. Basic Calculator " << endl 
<< "2. Temperature Conversion " << endl << "3. Rectangle area and perimeter " << endl 
<< "4. Counter Function " << endl << "5. Shape Area Calculator " << endl 
<< "6. Greet User " << endl << "7. Exit" << endl;

char ch;

cout << "Select an option: ";
cin >> ch;
cout << endl;

switch (ch)
{
case '1': // Basic Calculator switch starts here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   cout << "Basic Calculator! Please select a mode:" << endl << "1. Square root" << endl << "2. Power" 
   << endl << "3. Absolute value" << endl;

   char op;

cout << "Select an option: ";
cin >> op;
cout << endl;

switch (op)
{
case '1':
    int x;
    cout << "Square root! Please input a number!" << endl;
    cout << "Enter a whole number: ";
    cin >> x;
    cout << "The square root of " << x << " is " << sqrt(x);

    break;
case '2':
    int y;
    cout << "Power! Please end a number to square!" << endl;
    cout << "Enter a whole number:";
    cin >> y;
    cout << "Result: " << pow(y,2) << endl;
    break;
case '3':
    int z;
    cout << "Absolute value! Please input a whole number!" << endl;
    cout << "Enter a whole number or negative integer:";
    cin >> z;
    cout << "The absolute value of " << z << " is " << abs(z) << endl;
    break;    
default:
    break;
}
    break;
    // Basic Calculator switch ends here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

case '2': // Temperature conversion starts here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     cout << "Temperature conversion! Please select a mode:" << endl << "1. Fahrenheit to Celsius" << endl << "2. Celsius to Fahrenheit" << endl;

     char tp;

     cout << "Select a option: ";
     cin >> tp;
     cout << endl;

     switch (tp)
     {
     case '1':
        double TempA;
        cout << " Fahrenheit to Celsius! Please input your temperature!" << endl;
        cout << "Tempature:";
        cin >> TempA;
        cout << "Converts to: " <<  (TempA - 32.0) * 5.0 / 9.0 << " C" << endl;
        break;
     case '2':
        double TempB;
        cout << "Celsius to Fahrenheit! Please input your temperature!" << endl;
        cout << "Temperature:";
        cin >> TempB;
        cout << "Converts to: " << (TempB * 9.0 / 5.0  ) + 32 << " F" << endl;

        break;
     default:
        break;
     }
     
     break;
     // Tempature conversion switch ends here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

     case '3': // Rectangle area and perimeter calculator starts here!!!!!!!!!!!!!!!!!!!!!!!!!!!

     int length;
     int withd;

         cout << " Rectangle area and perimeter! Please enter values!" << endl << "Enter length: ";
         cin >> length;
         cout << "Enter withd: ";
         cin >> withd;
         cout << "The perimeter is: " << 2 * length + withd << endl;
         cout << "The area is: " << length * withd << endl;
        break;
       // Rectangle area and perimeter calculator ends here!!!!!!!!!!!!!!!!!!!!!!!!!!!

case '4':  // Start of count function
    int count;
    
         cout <<"Here we will show the count function" << endl << "Enter a value:";
         cin >> count; 
         count++;
         cout << "Value after incrementing by 1 is " << count << endl;
         count--;
         count--;
         cout << "followed by decrement by 2 is " << count << endl;
         break;
         // Counting function ends here !!!!!!!!!!!!
case '5': // Shape area starts here!!!!!!!!!!!!!
    char sh;

cout << " Shape area calculator! Please select a shape: " << endl << "1. Circle" << endl << "2. Rectangle" << endl << "3. Triangle" << endl
<< "Select an option: ";
cin >> sh;
cout << endl;

switch (sh)
{
case '1':
    double Radius;
    cout << "Cirle! Please enter your Radius:";
    cin >> Radius;
    cout << "Area of this circle is " << M_PI * pow(Radius,2) << endl;
    
    break;
case '2':
    int L;
    int W;
    cout << "Rectangle! Please input a lenght and withd!" << endl;
    cout << "Length: ";
    cin >> L;
    cout << endl;
    cout << "Withd: ";
    cin >> W;

    cout << "Area of a rectangle is " << L * W << endl;
    break;

case '3':
   double base;
   double hieght;
    cout << "Triangle! Please enter in a base value and height value!" << endl;
    cout << "Base: ";
    cin >> base;
    cout << "Hieght: ";
    cin >> hieght;

    cout << "Area of a triangle is " <<  base * hieght / 2;
    break;
default:
    break;
}
break;
/// Shape area function ends here!!!!!!!!!!!!!!!!!
case '6':

 cout << "Please enter your title (Mr. or Mrs.): " << endl;
 cin >> title;
 cout << "Input last name: ";
 cin >> name;
 if (title == "Mr.", "mr." || title == "Mrs.", "mrs.")
 {
    cout << "Hello " << title << name << endl; 
 }
 else
 {
    cout << "Hello user!";
 }
 
// Couldn't get this function to work with string data type.
break;

case '7':
cout << "Program ending, Goodbye!" << endl; 
    // Program ends if case 7 is selected!!!!!!!!!!!!!!
default:
break;
}




    return 0;
}