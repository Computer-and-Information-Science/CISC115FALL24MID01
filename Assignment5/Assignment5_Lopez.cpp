#include <iostream>
#include <cmath> // For mathematical functions
#include <string> // For handling strings

using namespace std;

// Function Prototypes

// Task 1: Basic Calculator
void basicCalculator();

// Task 2: Temperature Conversion
double fahrenheitToCelsius(double fahrenheit);
double celsiusToFahrenheit(double celsius);
void temperatureConversion();

// Task 3: Rectangle Area and Perimeter
void calculateRectangle(double length, double width, double &area, double &perimeter);
void rectangleCalculations();

// Task 4: Counter with Static Variables
void incrementCounter();

// Task 5: Shape Area Calculation
double calculateArea(double radius);
double calculateArea(double length, double width);
double calculateArea(double base, double height, bool isTriangle);
void areaCalculator();

// Task 6: Greeting with Default Parameters
void greetUser(string name, string title = "Mr./Ms.");
void greetingDemo();

// Main Function
int main() {
    int taskChoice;

    while (true) {
        cout << "\n--- Select a Task ---\n";
        cout << "1. Basic Calculator\n";
        cout << "2. Temperature Conversion\n";
        cout << "3. Rectangle Area and Perimeter\n";
        cout << "4. Increment Counter (Static Variable)\n";
        cout << "5. Shape Area Calculation (Overloading)\n";
        cout << "6. Greeting Function (Default Parameters)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> taskChoice;

        switch (taskChoice) {
            case 1:
                basicCalculator();
                break;
            case 2:
                temperatureConversion();
                break;
            case 3:
                rectangleCalculations();
                break;
            case 4:
                cout << "Calling incrementCounter() multiple times...\n";
                incrementCounter();
                incrementCounter();
                incrementCounter();
                break;
            case 5:
                areaCalculator();
                break;
            case 6:
                greetingDemo();
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    }
    return 0;
}

// Task 1: Basic Calculator
void basicCalculator() {
    int choice;
    cout << "Choose an operation:\n";
    cout << "1. Square Root\n";
    cout << "2. Power\n";
    cout << "3. Absolute Value\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double number;
            cout << "Enter a number: ";
            cin >> number;
            cout << "Square Root of " << number << " is " << sqrt(number) << endl;
            break;
        }
        case 2: {
            double base, exponent;
            cout << "Enter base: ";
            cin >> base;
            cout << "Enter exponent: ";
            cin >> exponent;
            cout << base << "^" << exponent << " = " << pow(base, exponent) << endl;
            break;
        }
        case 3: {
            double number;
            cout << "Enter a number: ";
            cin >> number;
            cout << "Absolute Value of " << number << " is " << abs(number) << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please select 1, 2, or 3.\n";
    }
}

// Task 2: Temperature Conversion
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

void temperatureConversion() {
    int choice;
    cout << "Choose Conversion:\n";
    cout << "1. Fahrenheit to Celsius\n";
    cout << "2. Celsius to Fahrenheit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        double fahrenheit;
        cout << "Enter temperature in Fahrenheit: ";
        cin >> fahrenheit;
        cout << "Temperature in Celsius: " << fahrenheitToCelsius(fahrenheit) << endl;
    } else if (choice == 2) {
        double celsius;
        cout << "Enter temperature in Celsius: ";
        cin >> celsius;
        cout << "Temperature in Fahrenheit: " << celsiusToFahrenheit(celsius) << endl;
    } else {
        cout << "Invalid choice. Please select 1 or 2.\n";
    }
}

// Task 3: Rectangle Area and Perimeter
void calculateRectangle(double length, double width, double &area, double &perimeter) {
    area = length * width;
    perimeter = 2 * (length + width);
}

void rectangleCalculations() {
    double length, width, area, perimeter;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    calculateRectangle(length, width, area, perimeter);

    cout << "Area of the Rectangle: " << area << endl;
    cout << "Perimeter of the Rectangle: " << perimeter << endl;
}

// Task 4: Counter with Static Variables
void incrementCounter() {
    static int count = 0;
    count++;
    cout << "Current Count: " << count << endl;

    int temp = 0; // Automatic variable
    temp++;
    cout << "Temporary Count (automatic variable): " << temp << endl;
}

// Task 5: Shape Area Calculation
double calculateArea(double radius) {
    return M_PI * radius * radius; // Circle area
}

double calculateArea(double length, double width) {
    return length * width; // Rectangle area
}

double calculateArea(double base, double height, bool isTriangle) {
    if (isTriangle) {
        return 0.5 * base * height; // Triangle area
    }
    return base * height;
}

void areaCalculator() {
    int choice;
    cout << "Choose a shape:\n";
    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        double radius;
        cout << "Enter radius of the circle: ";
        cin >> radius;
        cout << "Area of Circle: " << calculateArea(radius) << endl;
    } else if (choice == 2) {
        double length, width;
        cout << "Enter length and width of the rectangle: ";
        cin >> length >> width;
        cout << "Area of Rectangle: " << calculateArea(length, width) << endl;
    } else if (choice == 3) {
        double base, height;
        cout << "Enter base and height of the triangle: ";
        cin >> base >> height;
        cout << "Area of Triangle: " << calculateArea(base, height, true) << endl;
    } else {
        cout << "Invalid choice. Please select 1, 2, or 3.\n";
    }
}

// Task 6: Greeting with Default Parameters
void greetUser(string name, string title) {
    cout << "Hello, " << title << " " << name << "!" << endl;
}

void greetingDemo() {
    greetUser("Alice"); // Default title
    greetUser("Bob", "Dr."); // Custom title
}
