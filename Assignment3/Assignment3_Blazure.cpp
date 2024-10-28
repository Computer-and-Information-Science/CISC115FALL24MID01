#include <iostream>
#include <iomanip>
using namespace std;

int main () {
//Assign the functions of the variables
    int age;
    int seating;
    int time;
    bool loyalty;
    double price = 0.00;

    cout<<"Please enter your age";
    cin>>age;
    //Age assignments which will determine the final price
    if (age <= 12 && age >= 0)
        price = price + 10.00;
    else if (age >= 13 && age <= 17)
        price = price + 12.00;
    else if (age >= 18 && age <= 59)
        price = price + 15.00;
    else if  (age >= 60)
        price = price + 10.00;
    else
    {
        cout<<"Enter a valid age"<<endl;
        return 0;
    }
    //The times that are available
    cout<<"Enter time (Between 9 and 23 in military time): ";
    cin>>time;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Invalid input. Please input a correct showtime."<<endl;
        return 0;
    }
    //Assignments for the pricing depending on the time
    if ((time < 12 && time >= 9))
        price = price - ((price * 10)/100);
    else if ((time < 9) || (time > 11))
    {
        cout<<"Invalid time. Please input a correct time"<<endl;
        return 0;
    }
    cout<<"Choose set type: \n"<<"1 for standard \n"<<"2 for premium\n"<<"3 for combo"<<"4 for upgrade to gold\n"<<"Seat type";
    cin>>seating;

    if (cin.fail())
    {
        cin.clear ();
        cin.ignore(1000,'\n');
        cout<<"Invalid input. Please enter a correct choice."<<endl;
        return 0;
    }
    switch (seating) //Prices for the theater seating, can be selected
    {
        case 1:
            break;
        case 2:
            price = price + 3.00;
            break;
        case 3:
            price = price + 5.00;
            break;
        case 4:
            price = price + 10.00;
            break;
        default:
            cout<<"Please select an option from the list";
            return 0;
    }
    cout<<"Do you have a loyalty card? (1 for yes, 2 for no)"<<endl;
    cin>>loyalty;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Invalid input. Please enter the correct input."<<endl;
        return 0;
    }
    //If there is a loyalty card yes or no
    if (loyalty =1)
        price = price - ((price *25)/100);
    cout<<"Final price: $"<<fixed<<showpoint<<setprecision<<price<<endl;

    return 0;
}