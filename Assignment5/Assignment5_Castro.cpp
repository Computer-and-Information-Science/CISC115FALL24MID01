//**********************************************************************
// Author: Raymond Castro
// Date: 17 Nov 2024
//
// Computer Science I Coding Assignment 5 - Raymond Castro
//
// This C++ program utilizes user-defined functions to break down tasks,
// including a basic calculator using pre-defined functions, custom
// functions for temperature conversion, area and perimeter calculations
// with reference parameters, scope and static variables in a counter
// function, function overloading for shape area calculation, and
// default paramters in a greeting function.
//**********************************************************************

// Header files
#include <iostream>
#include <cmath> // Header file used for mathematical functions
#include <string>

using namespace std;

#ifndef M_PI // Manually defines M_PI
#define M_PI 3.14159265358979323846
#endif

void basicCalculator();
double fahrenheitToCelsius(double fahrenheit);
double celsiusToFahrenheit(double celsius);
void calculateRectangle(double length, double width, double &area, double &perimeter);
void incrementCounter();
double calculateArea(double radius);
double calculateArea(double length, double width);
double calculateTriangleArea(double base, double height);
void greetUser(string name, string title = "Mr./Ms."); /* Creates function prototypes
for the preceding user-defined functions */

bool getValidInput(int &input) /* Defines a user-defined function to get 
valid inputs for integers */
{
    if (cin >> input) // Checks for valid input in inputs of the int data type
    {
        return true; // Returns true to the calling function
    }
    else
    {
        cin.clear(); // Clears the input stream
        cin.ignore(100, '\n'); /* Ignores the invalid input and
        clears the buffer */ 
        return false;
    }
}

bool getValidDoubleInput(double &input) /* Defines a user-defined function to get 
valid inputs for decimals */
{
    if (cin >> input) // Checks for valid input in inputs of the double data type
    {
        return true;
    }
    else
    {
        cin.clear();
        cin.ignore(100, '\n');
        return false;
    }
}

int main()
{
    int choice; // Declares the variable choice in the int data type
    
    cout << "Computer Science I Coding Assignment 5 - Raymond "
         << "Castro" << endl << endl; // Outputs the title of the program
    cout << "Utilizing pre-defined functions, types of parameters, and "
         << "function overloading, this C++ program uses various user-defined "
         << "functions, such as functions for a basic calculator,\ntemperature "
         << "conversion, area and perimeter calculations, scope and static "
         << "variables, shape area calculation, and greetings."
         << endl << endl; // Displays an explanation of the program

    do
    {
        cout << "Choose an operation:" << endl
             << "1. Basic Calculator" << endl
             << "2. Temperature Conversion" << endl
             << "3. Rectangle Area and Perimeter" << endl
             << "4. Counter Function" << endl
             << "5. Shape Area Calculation" << endl
             << "6. Greet User" << endl
             << "7. Exit" << endl;
            // Displays a list of the possible operations

        cout << "Enter your choice: ";
        while (!getValidInput(choice) || (choice < 1) || (choice > 7))
        // Loops until the input for choice is valid
        {
            cout << "Invalid input. Please enter a number between 1 and 7." << endl; 
            // Outputs a statement for the user to try again
            cout << "Enter your choice: ";
        }

        switch (choice) /* Executes a function based on what value of
        choice the user inputted */
        {
            case 1:
                basicCalculator(); // Calls the user-defined function basicCalculator
                break; // Breaks the while loop if the input is valid
            case 2:
                {
                    int tempChoice; // Declares the variable tempChoice in the int data type
                    cout << "Temperature Conversion:" << endl
                         << "1. Fahrenheit to Celsius" << endl
                         << "2. Celsius to Fahrenheit" << endl;
                    // Displays a list of the possible temperature conversions
                    cout << "Enter your choice: ";
                    while (!getValidInput(tempChoice) || ((tempChoice != 1) && (tempChoice != 2)))
                    // Loops until the input for tempChoice is valid
                    {
                        cout << "Invalid choice. Please enter 1 or 2." << endl;
                        cout << "Enter your choice: ";
                    }

                    if (tempChoice == 1)
                    {
                        double fahrenheit;
                        cout << "Enter temperature in Fahrenheit: ";
                        while (!getValidDoubleInput(fahrenheit))
                        // Loops until the input for fahrenheit is valid
                        {
                            cout << "Invalid input. Please enter a valid temperature: ";
                        }
                        cout << "Celsius: " << fahrenheitToCelsius(fahrenheit) << endl << endl;
                        // Calls the user-defined function fahrenheitToCelsius
                    }
                    else
                    {
                        double celsius;
                        cout << "Enter temperature in Celsius: ";
                        while (!getValidDoubleInput(celsius))
                        // Loops until the input for celsius is valid
                        {
                            cout << "Invalid input. Please enter a valid temperature: ";
                        }
                        cout << "Fahrenheit: " << celsiusToFahrenheit(celsius) << endl << endl;
                        // Calls the user-defined function celsiusToFahrenheit
                    }
                }
                break;
            case 3:
                {
                    double length, width, area, perimeter;
                    cout << "Enter length and width of the rectangle: ";
                    while (!getValidDoubleInput(length) || (length <= 0))
                    // Loops until the input for length is valid
                    {
                        cout << "Invalid input. Length must be positive. Please enter length: ";
                    }
                    while (!getValidDoubleInput(width) || (width <= 0))
                    // Loops until the input for width is valid
                    {
                        cout << "Invalid input. Width must be positive. Please enter width: ";
                    }
                    calculateRectangle(length, width, area, perimeter);
                    // Calls the user-defined function calculateRectangle
                    cout << "Area: " << area << ", Perimeter: " << perimeter << endl << endl;
                }
                break;
            case 4:
                incrementCounter(); // Calls the user-defined function incrementCounter
                incrementCounter();
                incrementCounter();
                break;
            case 5:
               {
                    int shapeChoice; // Declares the variable shapeChoice in the int data type
                    cout << "Shape Area Calculation:" << endl
                         << "1. Circle" << endl
                         << "2. Rectangle" << endl
                         << "3. Triangle" << endl;
                        // Displays a list of the possible shape area calcuations
                    cout << "Enter your choice: ";
                    while (!getValidInput(shapeChoice) || (shapeChoice < 1) || (shapeChoice > 3))
                    // Loops until the input for shapeChoice is valid
                    {
                        cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
                        cout << "Enter your choice: ";
                    }

                    if (shapeChoice == 1)
                    {
                        double radius;
                        cout << "Enter radius: ";
                        while (!getValidDoubleInput(radius) || (radius <= 0))
                        // Loops until the input for radius is valid
                        {
                            cout << "Invalid input. Radius must be positive. Please enter radius: ";
                        }
                        cout << "Circle Area: " << calculateArea(radius) << endl << endl;
                    }
                    else if (shapeChoice == 2)
                    {
                        double length, width;
                        cout << "Enter length and width: ";
                        while (!getValidDoubleInput(length) || (length <= 0))
                        // Loops until the input for length is valid
                        {
                            cout << "Invalid input. Length must be positive. Please enter length: ";
                        }
                        while (!getValidDoubleInput(width) || (width <= 0))
                        // Loops until the input for width is valid
                        {
                            cout << "Invalid input. Width must be positive. Please enter width: ";
                        }
                        cout << "Rectangle Area: " << calculateArea(length, width) << endl << endl;
                    }
                    else if (shapeChoice == 3)
                    {
                        double base, height;
                        cout << "Enter base and height: ";
                        while (!getValidDoubleInput(base) || (base <= 0))
                        // Loops until the input for base is valid
                        {
                            cout << "Invalid input. Base must be positive. Please enter base: ";
                        }
                        while (!getValidDoubleInput(height) || (height <= 0))
                        // Loops until the input for height is valid
                        {
                            cout << "Invalid input. Height must be positive. Please enter height: ";
                        }
                        cout << "Triangle Area: " << calculateTriangleArea(base, height) << endl << endl;
                    }
                }
                break;
            case 6:
                {
                    string name, title;
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter title (or leave blank for default): ";
                    cin.ignore();
                    getline(cin, title); /* Reads the inputted string, including
                    whitespaces, then stores it in title */
                    if (title.empty()) /* Checks for a blank based on what
                    value of title the user inputted */
                    {
                        greetUser(name); // Calls the user-defined function greetUser
                    }
                    else
                    {
                        greetUser(name, title);
                    }
                }
                break;
            case 7:
                cout << "Exiting the program. Goodbye!" << endl;
                // Presents a farewell message to the user after they exit the program
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    while (choice != 7); /* Loops until the user chooses to exit the program, executing
    at least once */

    return 0; // Terminates the program
}

void basicCalculator() // Defines the user-defined function basicCalculator
{
    int calcChoice; // Declares the variable calcChoice in the int data type
    cout << "Basic Calculator:" << endl
        << "1. Square Root" << endl
        << "2. Power" << endl
        << "3. Absolute Value" << endl;
        // Displays a list of the possible calculator options
    cout << "Enter your choice: ";
    while (!getValidInput(calcChoice) || (calcChoice < 1) || (calcChoice > 3))
    // Loops until the input for calcChoice is valid
    {
        cout << "Invalid choice. Please enter a valid option." << endl;
        cout << "Enter your choice: ";
    }

    if (calcChoice == 1)
    {
        double num;
        cout << "Enter number: ";
        while (!getValidDoubleInput(num) || (num < 0))
        // Loops until the input for num is valid in the double data type
        {
            cout << "Invalid input. Please enter a valid positive number: ";
        }
        cout << "Square Root: " << sqrt(num) << endl << endl; /* Executes the square root
        function provided by the header file cmath */
    }
    else if (calcChoice == 2)
    {
        double base, exponent;
        cout << "Enter base and exponent: ";
        while (!getValidDoubleInput(base) || !getValidDoubleInput(exponent))
        // Loops until the inputs for base and exponent are valid
        {
            cout << "Invalid input. Please enter valid numbers for base and exponent: ";
        }
            cout << "Power: " << pow(base, exponent) << endl << endl; /* Executes the power
        function provided by the header file cmath */
    }
    else if (calcChoice == 3)
    {
        int num; // Declares the variable num in the int data type
        cout << "Enter number: ";
        while (!getValidInput(num))
        // Loops until the input for num is valid in the int data type
        {
            cout << "Invalid input. Please enter a valid integer: ";
        }
        cout << "Absolute Value: " << abs(num) << endl << endl; /* Executes the absolute value
        function provided by the header file cmath */
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}

double fahrenheitToCelsius(double fahrenheit) // Defines the user-defined function fahrenheitToCelsius
{
    return (fahrenheit - 32) * 5 / 9;
}

double celsiusToFahrenheit(double celsius) // Defines the user-defined function celsiusToFahrenheit
{
    return (celsius * 9 / 5) + 32;
}

void calculateRectangle(double length, double width, double &area, double &perimeter)
// Defines the user-defined function calculateRectangle
{
    area = length * width;
    perimeter = 2 * (length + width);
}

void incrementCounter() // Defines the user-defined function incrementCounter
{
    static int count = 0; // Declares the variable count as a static integer
    count++; // Increments the value of count after it's used in the function
    cout << "Current Count: " << count << endl << endl;
}

double calculateArea(double radius) // Defines the user-defined function calculateArea
{
    return M_PI * radius * radius;
}

double calculateArea(double length, double width)
// Defines the user-defined function calculateArea again, but with different parameters
{
    return length * width;
}

double calculateTriangleArea(double base, double height)
// Defines the user-defined function calculateTriangleArea
{
    return 0.5 * base * height;
}

void greetUser(string name, string title)
// Defines the user-defined function greetUser
{
    cout << "Hello, " << title << " " << name << "!" << endl << endl;
    // Presents a greeting message to the user
}