#include <iostream>
using namespace std;
int main()
{
 std::string fullname = "Matthew Lewis";

std::cout << "My name is: " << fullname<< "\n";

std::string intro = "This is my first basic program in C++";

std::cout << intro << std::endl;

int age = 19;

std::cout << "age: " << age <<std::endl;

double height = 5.9;

std::cout << "height: " << height << std::endl;

char grade = 'A';

std::cout <<"The grade I want in CISC: "<< grade << std::endl; //declaring

float New_age = age;

std::cout << "New age: " << New_age <<std::endl;

int Rounded_Height = static_cast<int>(height);

std::cout <<"Rounded Height: " << Rounded_Height << std::endl;

} 
