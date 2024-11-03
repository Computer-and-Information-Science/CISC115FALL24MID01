#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function prototypes
void basicCalculator();
double fahrenheitToCelsius(double fahrenheit);
double celsiusToFahrenheit(double celsius);
void calculateRectangle(double length, double width, double &area, double &perimeter);
void incrementCounter();
double calculateArea(double radius);
double calculateArea(double length, double width);
double calculateArea(double base, double height, bool isTriangle);
void greetUser(string name, string title = "Mr./Ms.");

int main() {
    int choice;
    
    do {
        cout << "Choose an operation:\n";
        cout << "1. Basic Calculator\n";
        cout << "2. Temperature Conversion\n";
        cout << "3. Rectangle Area and Perimeter\n";
        cout << "4. Counter Function\n";
        cout << "5. Shape Area Calculation\n";
        cout << "6. Greet User\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                basicCalculator();
                break;
            case 2:
                {
                    int tempChoice;
                    cout << "Temperature Conversion:\n1. Fahrenheit to Celsius\n2. Celsius to Fahrenheit\n";
                    cout << "Enter your choice: ";
                    cin >> tempChoice;

                    if (tempChoice == 1) {
                        double fahrenheit;
                        cout << "Enter temperature in Fahrenheit: ";
                        cin >> fahrenheit;
                        cout << "Celsius: " << fahrenheitToCelsius(fahrenheit) << endl;
                    } else if (tempChoice == 2) {
                        double celsius;
                        cout << "Enter temperature in Celsius: ";
                        cin >> celsius;
                        cout << "Fahrenheit: " << celsiusToFahrenheit(celsius) << endl;
                    }
                }
                break;
            case 3:
                {
                    double length, width, area, perimeter;
                    cout << "Enter length and width of the rectangle: ";
                    cin >> length >> width;
                    calculateRectangle(length, width, area, perimeter);
                    cout << "Area: " << area << ", Perimeter: " << perimeter << endl;
                }
                break;
            case 4:
                incrementCounter();
                incrementCounter();
                incrementCounter();
                break;
            case 5:
                {
                    int shapeChoice;
                    cout << "Shape Area Calculation:\n1. Circle\n2. Rectangle\n3. Triangle\n";
                    cout << "Enter your choice: ";
                    cin >> shapeChoice;

                    if (shapeChoice == 1) {
                        double radius;
                        cout << "Enter radius: ";
                        cin >> radius;
                        cout << "Circle Area: " << calculateArea(radius) << endl;
                    } else if (shapeChoice == 2) {
                        double length, width;
                        cout << "Enter length and width: ";
                        cin >> length >> width;
                        cout << "Rectangle Area: " << calculateArea(length, width) << endl;
                    } else if (shapeChoice == 3) {
                        double base, height;
                        cout << "Enter base and height: ";
                        cin >> base >> height;
                        cout << "Triangle Area: " << calculateArea(base, height, true) << endl;
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
                    getline(cin, title);
                    if (title.empty()) {
                        greetUser(name);
                    } else {
                        greetUser(name, title);
                    }
                }
                break;
            case 7:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

// Task 1: Basic Calculator
void basicCalculator() {
    int calcChoice;
    cout << "Basic Calculator:\n1. Square Root\n2. Power\n3. Absolute Value\n";
    cout << "Enter your choice: ";
    cin >> calcChoice;

    if (calcChoice == 1) {
        double num;
        cout << "Enter number: ";
        cin >> num;
        cout << "Square Root: " << sqrt(num) << endl;
    } else if (calcChoice == 2) {
        double base, exponent;
        cout << "Enter base and exponent: ";
        cin >> base >> exponent;
        cout << "Power: " << pow(base, exponent) << endl;
    } else if (calcChoice == 3) {
        int num;
        cout << "Enter number: ";
        cin >> num;
        cout << "Absolute Value: " << abs(num) << endl;
    } else {
        cout << "Invalid choice.\n";
    }
}

// Task 2: Temperature Conversion
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Task 3: Rectangle Area and Perimeter Calculation
void calculateRectangle(double length, double width, double &area, double &perimeter) {
    area = length * width;
    perimeter = 2 * (length + width);
}

// Task 4: Counter Function with Static Variable
void incrementCounter() {
    static int count = 0;
    count++;
    cout << "Current Count: " << count << endl;
}

// Task 5: Shape Area Calculation Overloading
double calculateArea(double radius) {
    return M_PI * radius * radius;
}

double calculateArea(double length, double width) {
    return length * width;
}

double calculateArea(double base, double height, bool isTriangle) {
    if (isTriangle) {
        return 0.5 * base * height;
    }
    return base * height;
}

// Task 6: Greeting Function with Default Parameters
void greetUser(string name, string title) {
    cout << "Hello, " << title << " " << name << "!" << endl;
}
