#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Function declarations
void basicCalculator();
void temperatureConversion();
void rectangleAreaPerimeter();
void counterFunction();
void shapeAreaCalculation();
void greetUser();

int counter = 0; // Global counter for Task 4 (Beginner-friendly)

// Main program
int main() {
    int choice;

    do {
        // Main menu
        cout << "Choose an operation:" << endl;
        cout << "1. Basic Calculator" << endl;
        cout << "2. Temperature Conversion" << endl;
        cout << "3. Rectangle Area and Perimeter" << endl;
        cout << "4. Counter Function" << endl;
        cout << "5. Shape Area Calculation" << endl;
        cout << "6. Greet User" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle menu choices
        if (choice == 1) {
            basicCalculator();
        } else if (choice == 2) {
            temperatureConversion();
        } else if (choice == 3) {
            rectangleAreaPerimeter();
        } else if (choice == 4) {
            counterFunction();
        } else if (choice == 5) {
            shapeAreaCalculation();
        } else if (choice == 6) {
            greetUser();
        } else if (choice == 7) {
            cout << "Exiting the program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}

// Task 1: Basic Calculator
void basicCalculator() {
    int calcChoice;
    double num1, num2;

    cout << "Basic Calculator:" << endl;
    cout << "1. Square Root" << endl;
    cout << "2. Power" << endl;
    cout << "3. Absolute Value" << endl;
    cout << "Enter your choice: ";
    cin >> calcChoice;

    if (calcChoice == 1) {
        cout << "Enter number: ";
        cin >> num1;
        cout << "Square Root: " << sqrt(num1) << endl;
    } else if (calcChoice == 2) {
        cout << "Enter base and exponent: ";
        cin >> num1 >> num2;
        cout << "Result: " << pow(num1, num2) << endl;
    } else if (calcChoice == 3) {
        cout << "Enter number: ";
        cin >> num1;
        cout << "Absolute Value: " << abs(num1) << endl;
    } else {
        cout << "Invalid choice in Basic Calculator." << endl;
    }
}

// Task 2: Temperature Conversion
void temperatureConversion() {
    int tempChoice;
    double temp;

    cout << "Temperature Conversion:" << endl;
    cout << "1. Fahrenheit to Celsius" << endl;
    cout << "2. Celsius to Fahrenheit" << endl;
    cout << "Enter your choice: ";
    cin >> tempChoice;

    if (tempChoice == 1) {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temp;
        cout << "Celsius: " << (temp - 32) * 5 / 9 << endl;
    } else if (tempChoice == 2) {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
        cout << "Fahrenheit: " << (temp * 9 / 5) + 32 << endl;
    } else {
        cout << "Invalid choice in Temperature Conversion." << endl;
    }
}

// Task 3: Rectangle Area and Perimeter
void rectangleAreaPerimeter() {
    double length, width, area, perimeter;

    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;

    area = length * width;
    perimeter = 2 * (length + width);

    cout << "Area: " << area << ", Perimeter: " << perimeter << endl;
}

// Task 4: Counter Function
void counterFunction() {
    counter++;
    cout << "Counter: " << counter << endl;
}

// Task 5: Shape Area Calculation
void shapeAreaCalculation() {
    int shapeChoice;
    double radius, length, width, base, height;

    cout << "Shape Area Calculation:" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Triangle" << endl;
    cout << "Enter your choice: ";
    cin >> shapeChoice;

    if (shapeChoice == 1) {
        cout << "Enter radius: ";
        cin >> radius;
        cout << "Circle Area: " << 3.14159 * radius * radius << endl;
    } else if (shapeChoice == 2) {
        cout << "Enter length and width: ";
        cin >> length >> width;
        cout << "Rectangle Area: " << length * width << endl;
    } else if (shapeChoice == 3) {
        cout << "Enter base and height: ";
        cin >> base >> height;
        cout << "Triangle Area: " << 0.5 * base * height << endl;
    } else {
        cout << "Invalid choice in Shape Area Calculation." << endl;
    }
}

// Task 6: Greeting Function
void greetUser() {
    string name, title;

    cout << "Enter your name: ";
    cin.ignore(); // To clear any leftover newline character
    getline(cin, name);

    cout << "Enter title (or leave empty for default): ";
    getline(cin, title);

    if (title.empty()) {
        title = "Mr./Ms.";
    }

    cout << "Hello, " << title << " " << name << "!" << endl;
}
