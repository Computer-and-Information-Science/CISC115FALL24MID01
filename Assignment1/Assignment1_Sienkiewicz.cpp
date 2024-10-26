#include <iostream>
#include <string> 

using namespace std;

int main() {
    // Step 1: Declare Variables
    int age; 
    double height; 
    char grade; 
    string fullName; 

    // Step 2: Assign Values
    age = 20; 
    height = 5.11; 
    grade = 'C'; 
    fullName = "Norbert Sienkiewicz"; 

    // Output initial values
    cout << "This is my first program in C++:" << endl;
    cout << "Name: " << fullName << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << " feet" << endl;
    cout << "Grade: " << grade << endl;

    // Step 3: Perform Basic Operations
    age = age + 5; 
    height = height + 0.5; 

    // Output updated values
    cout << "\nAfter updating values:" << endl;
    cout << "New Age: " << age << endl;
    cout << "New Height: " << height << " feet" << endl;

    // Step 4: Type Conversion (Casting)
    // Implicit type conversion
    float ageInFloat = age; 
    cout << "\nAge as float (implicit conversion): " << ageInFloat << endl;

    // Explicit type casting
    int heightInInt = (int)height; 
    cout << "Height as int (explicit conversion): " << heightInInt << " feet" << endl;

    // Using static_cast for explicit conversion
    float heightAsFloat = static_cast<float>(heightInInt); 
    cout << "Height back as float (using static_cast): " << heightAsFloat << " feet" << endl;

    // Final output
    cout << "\nFinal output:" << endl;
    cout << "Name: " << fullName << endl;
    cout << "Final Age: " << age << " (as float: " << ageInFloat << ")" << endl;
    cout << "Final Height: " << height << " (as int: " << heightInInt << ", as float: " << heightAsFloat << ")" << endl;
    cout << "Grade: " << grade << endl;

    return 0; 
}
