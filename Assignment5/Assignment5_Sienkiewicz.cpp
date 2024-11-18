#include <iostream>
#include <cmath>   // For predefined functions sqrt, pow, abs
#include <string>  // For string handling

using namespace std;

// Function Prototypes
double fahrenheitToCelsius(double fahrenheit);
double celsiusToFahrenheit(double celsius);
void calculateRectangle(double length, double width, double &area, double &perimeter);
void incrementCounter();
double calculateArea(double radius);
double calculateArea(double length, double width);
double calculateArea(double base, double height, bool isTriangle);
void greetUser(string name, string title = "Mr./Ms.");

// Global counter variable for Task 4
static int counter = 0;

int main() {
    int choice;
    
    do {
        // Display menu
        cout << "Select a task to perform:\n";
        cout << "1. Basic Calculator\n";
        cout << "2. Temperature Conversion\n";
        cout << "3. Area and Perimeter Calculations\n";
        cout << "4. Counter Function\n";
        cout << "5. Shape Area Calculation\n";
        cout << "6. Greeting\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Task 1: Basic Calculator
                int calcChoice;
                double num1, num2, result;

                cout << "\nTask 1: Basic Calculator\n";
                cout << "Select an operation:\n";
                cout << "1. Square root\n";
                cout << "2. Power\n";
                cout << "3. Absolute value\n";
                cout << "Enter your choice: ";
                cin >> calcChoice;

                switch (calcChoice) {
                    case 1:
                        cout << "Enter a number: ";
                        cin >> num1;
                        result = sqrt(num1);
                        cout << "Square root of " << num1 << " is: " << result << endl;
                        break;
                    case 2:
                        cout << "Enter base number: ";
                        cin >> num1;
                        cout << "Enter exponent: ";
                        cin >> num2;
                        result = pow(num1, num2);
                        cout << num1 << " raised to the power of " << num2 << " is: " << result << endl;
                        break;
                    case 3:
                        cout << "Enter a number: ";
                        cin >> num1;
                        result = abs(num1);
                        cout << "Absolute value of " << num1 << " is: " << result << endl;
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                }
                break;
            }

            case 2: {
                // Task 2: Temperature Conversion
                double fahrenheit, celsiusTemp;
                cout << "\nTask 2: Temperature Conversion\n";
                cout << "Enter temperature in Fahrenheit: ";
                cin >> fahrenheit;
                celsiusTemp = fahrenheitToCelsius(fahrenheit);
                cout << fahrenheit << "°F is " << celsiusTemp << "°C." << endl;

                cout << "Enter temperature in Celsius: ";
                cin >> celsiusTemp;
                fahrenheit = celsiusToFahrenheit(celsiusTemp);
                cout << celsiusTemp << "°C is " << fahrenheit << "°F." << endl;
                break;
            }

            case 3: {
                // Task 3: Area and Perimeter Calculations
                double length, width, area, perimeter;
                cout << "\nTask 3: Area and Perimeter Calculation\n";
                cout << "Enter rectangle length: ";
                cin >> length;
                cout << "Enter rectangle width: ";
                cin >> width;
                calculateRectangle(length, width, area, perimeter);
                cout << "Rectangle area: " << area << ", Perimeter: " << perimeter << endl;
                break;
            }

            case 4: {
                // Task 4: Counter Function
                cout << "\nTask 4: Static Counter Function\n";
                incrementCounter();
                incrementCounter();
                incrementCounter();
                break;
            }

            case 5: {
                // Task 5: Shape Area Calculation
                int shapeChoice;
                double num1, num2;
                cout << "\nTask 5: Shape Area Calculation\n";
                cout << "Choose a shape to calculate the area:\n";
                cout << "1. Circle\n";
                cout << "2. Rectangle\n";
                cout << "3. Triangle\n";
                cout << "Enter your choice: ";
                cin >> shapeChoice;

                switch (shapeChoice) {
                    case 1:
                        cout << "Enter radius of the circle: ";
                        cin >> num1;
                        cout << "Area of circle: " << calculateArea(num1) << endl;
                        break;
                    case 2:
                        cout << "Enter length of rectangle: ";
                        cin >> num1;
                        cout << "Enter width of rectangle: ";
                        cin >> num2;
                        cout << "Area of rectangle: " << calculateArea(num1, num2) << endl;
                        break;
                    case 3:
                        cout << "Enter base of triangle: ";
                        cin >> num1;
                        cout << "Enter height of triangle: ";
                        cin >> num2;
                        cout << "Area of triangle: " << calculateArea(num1, num2, true) << endl;
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                }
                break;
            }

            case 6: {
                // Task 6: Greeting Function
                string name;
                cout << "\nTask 6: Greeting Function\n";
                cout << "Enter your name: ";
                cin >> name;
                greetUser(name);             
                break;
            }

            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please select between 1 and 7.\n";
        }

    } while (choice != 7);  

    return 0;
}

// Task 2: Temperature Conversion
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Task 3: Area and Perimeter Calculations
void calculateRectangle(double length, double width, double &area, double &perimeter) {
    area = length * width;
    perimeter = 2 * (length + width);
}

// Task 4: Counter Function
void incrementCounter() {
    counter++; 
    cout << "Current count: " << counter << endl;
}

// Task 5: Shape Area Calculation
double calculateArea(double radius) {
    return M_PI * radius * radius;  // Area of circle
}

double calculateArea(double length, double width) {
    return length * width;          // Area of rectangle
}
double calculateArea(double base, double height, bool isTriangle) {
    if (isTriangle) {
        return 0.5 * base * height;  // Area of triangle
    }
    return 0;  
}
// Task 6: Greeting Function
void greetUser(string name, string title) {
    cout << "Hello, " << title << " " << name << "!" << endl;
}