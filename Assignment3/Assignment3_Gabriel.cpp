#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// The Variables used in the program.
int main()
{
    int age;
    int time;
    double price;
    double discount;
    int seat;
    int card;

//User will input age that will later be used to determine ticket price.
    cout << "To purchase your ticket, please provide the following information." <<endl;
    cout << "Please enter your age: ";
    while(!(cin>>age))
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid: Please only enter the number for your age.";
    }
    cout <<endl;

// User will enter a showtime that will later affect the final ticket price.
    cout << "Enter a showtime between 9AM-11PM (24 Hour format, e.g. 14 for 2PM): " <<endl;
    while(!(cin>>time))
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid: Please only enter the number for time.";
    }
    cout <<endl;

//User will choose a seat that will add more to ticket price depending on choice.
    cout << "Please choose your prefered seat from the selection below" <<endl;
    cout << "Standard (No additonal charge)= 1" <<endl;
    cout << "Premium (+$5.00) = 2" <<endl;
    cout << "Combo (+$8.00) = 3" <<endl;
    cout << "Upgrade to Gold Member (+$10.00) = 4" <<endl;
    while(!(cin>>seat))
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid: Please only enter a number between 1-4.";
    }
    cout <<endl;

//User will answer if they are a Loyalty member or not for a discount on final ticket price.
    cout << "Are you a Loyalty Member? Yes=1 No=2" <<endl;
    cin >> card;

//Age is used to determine the base ticket price.
    if (age <= 12)
        price = 8;
    else if ((age >=13) && (age<=59))
        price = 12;
    else price = 10;

//Time will decide if the ticket price recieves a discount.
    if ((time >= 9) && (time <= 17))
    {
        discount = price * 0.10;
        price -= discount;
    }

//Switch case is used to further determine ticket price.
    switch (seat)
    {
        case 1:
            break;
        case 2: 
            price += 5.00;
            break;
        case 3:
            price += 8.00;
            break;
        case 4:
            price += 10.00;
            break;
}

//The final discount is applied to the ticket price.
    if (card == 1){
        discount = price * 0.15;
        price -= discount;
    }

//The final ticket price is calculated with a decimal place of two to show answer in currency.
    cout << "Final ticket price: $" << setprecision(2) << fixed << price <<endl;

    return 0;
}