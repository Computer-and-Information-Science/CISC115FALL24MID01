#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function Prototypes
void displayMenu();
double fahrenheitToCelsius(double fahrenheit);
double celsiusToFahrenheit(double celsius);
void calculateRectangle(double length, double width, double &area, double &perimeter);
void incrementCounter();
double calculateArea(double radius); // Overloaded function for circle
double calculateArea(double length, double width); // Overloaded function for rectangle
double calculateArea(double base, double height, bool isTriangle); // Overloaded function for triangle
void greetUser(string name, string title = "Mr./Ms.");

int main() {
    int choice;
    double num1, num2, result;
    double length, width, area, perimeter;
    string name, title;

    // Basic Calculator using Predefined Functions
    displayMenu();
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "Enter a number to find the square root: ";
            cin >> num1;
            result = sqrt(num1);
            cout << "Square root: " << result << endl;
            break;
        case 2:
            cout << "Enter base and exponent: ";
            cin >> num1 >> num2;
            result = pow(num1, num2);
            cout << "Power: " << result << endl;
            break;
        case 3:
            cout << "Enter a number to find the absolute value: ";
            cin >> num1;
            result = abs(num1);
            cout << "Absolute value: " << result << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    // Custom Functions for Temperature Conversion
    cout << "Enter temperature in Fahrenheit to convert to Celsius: ";
    cin >> num1;
    cout << num1 << " Fahrenheit is " << fahrenheitToCelsius(num1) << " Celsius." << endl;

    cout << "Enter temperature in Celsius to convert to Fahrenheit: ";
    cin >> num2;
    cout << num2 << " Celsius is " << celsiusToFahrenheit(num2) << " Fahrenheit." << endl;

    // Area and Perimeter Calculations with Reference Parameters
    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;
    calculateRectangle(length, width, area, perimeter);
    cout << "Rectangle Area: " << area << ", Perimeter: " << perimeter << endl;

    // Scope and Static Variables in Counter Function
    incrementCounter();
    incrementCounter();
    incrementCounter();

    // Function Overloading for Shape Area Calculation
    int shapeChoice;
    cout << "Choose a shape (1: Circle, 2: Rectangle, 3: Triangle): ";
    cin >> shapeChoice;

    if (shapeChoice == 1) {
        cout << "Enter the radius of the circle: ";
        cin >> num1;
        cout << "Area of Circle: " << calculateArea(num1) << endl;
    } else if (shapeChoice == 2) {
        cout << "Enter length and width of the rectangle: ";
        cin >> num1 >> num2;
        cout << "Area of Rectangle: " << calculateArea(num1, num2) << endl;
    } else if (shapeChoice == 3) {
        cout << "Enter base and height of the triangle: ";
        cin >> num1 >> num2;
        cout << "Area of Triangle: " << calculateArea(num1, num2, true) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    // Default Parameters in Greeting Function
    cout << "Enter your name: ";
    cin >> name;
    greetUser(name);  // Calling with default title
    cout << "Enter your title: ";
    cin >> title;
    greetUser(name, title);  // Calling with custom title

    return 0;
}

// Function Definitions

// Menu function
void displayMenu() {
    cout << "Choose an operation:\n";
    cout << "1. Square Root\n";
    cout << "2. Power\n";
    cout << "3. Absolute Value\n";
    cout << "Enter your choice: ";
}

// Temperature Conversion Functions
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Area and Perimeter Calculation with Reference Parameters
void calculateRectangle(double length, double width, double &area, double &perimeter) {
    area = length * width;
    perimeter = 2 * (length + width);
}

// Static Variable Counter Function
void incrementCounter() {
    static int count = 0;
    count++;
    cout << "Current count: " << count << endl;
}

// Function Overloading for Shape Area Calculation
double calculateArea(double radius) {
    return M_PI * radius * radius;  // Area of Circle: π * r^2
}

double calculateArea(double length, double width) {
    return length * width;  // Area of Rectangle: length * width
}

double calculateArea(double base, double height, bool isTriangle) {
    if (isTriangle) {
        return 0.5 * base * height;  // Area of Triangle: 1/2 * base * height
    }
    return 0;
}

// Default Parameters in Greeting Function
void greetUser(string name, string title) {
    cout << "Hello, " << title << " " << name << "!\n";
}