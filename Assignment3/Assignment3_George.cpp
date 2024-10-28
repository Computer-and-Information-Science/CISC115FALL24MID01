# include <string>
#include <iostream>
using namespace std; 
#include <iostream>
#include <iomanip>

int main() {
    int age;
    int Showtime; 
    int seat_type;
    int loyaltyMember;
    double TicketPrice = 0;
    double Discount;
    //declaring my vaules
    cout<< "Please input your age: ";
    cin>>(age);
    if(age <= 0){
        while (age < 1){
        cout<< "invalid age, please input a valid age: ";
        cin>> (age);}
        
        
    }
    //asking age and checking if it is a valid vaule, if not then asking until one is input

    if(age > 0 && age <= 12){
        TicketPrice = TicketPrice + 8;
    }
    if(age >= 13 && age <= 59){
    TicketPrice = TicketPrice + 12;
    }
    if(age >= 60){
    TicketPrice = TicketPrice + 10;
    }
    
    //setting price based on age 


    cout<< "Showing times are in between 9Am to 11Pm using a 24 hour format(Military time)" << '\n';
    cout<< "Please input your prefered showing time: ";
    cin>> (Showtime);

    if(Showtime < 9 || Showtime > 23){
        while(Showtime <9 || Showtime > 23){
            cout <<"Invalid Showtime entered, please make sure your showtime is valid and enter again: ";
            cin >> (Showtime);
        }}

    //Making sure that the entered time vaule is valid 
    if(Showtime >=9 && Showtime <= 17){
        Discount = TicketPrice * 0.10;
        TicketPrice = TicketPrice - Discount;
        Discount = 0;
    }
    //Giving the discount if the showtime is in between 9am and 5pm
    


    cout<< "Please chose a seat type." << '\n';
    cout<< "1 for a standard seat, 2 for a premium seat for an additional 5 dollars, 3 for the combo seat for an additional 7 dollars , and 4 in order to upgrade into a gold member for a additional 10 dollars: " ;
    cin>> (seat_type);
    //taking seat type 
if(seat_type > 4){
        while(seat_type > 4){
            cout <<"Invalid seat type entered, please make sure your seat type number is between 1 to 4 : ";
            cin >> (seat_type);
        }}else{

    switch(seat_type){
        case 1:{
            cout << "You have chosen the standard seat type." << '\n';
            break;
        }
        case 2:{
            cout<< "You have chosen the premium seat type" << '\n';
            TicketPrice = TicketPrice + 5;
            break;
        }
        case 3:{
            cout<< "You have chosen the combo option seat type." << '\n';
            TicketPrice = TicketPrice + 7;
            break;
        }
        case 4:{
            cout<< "You have chosen to upgrade to a gold member." << '\n';
            TicketPrice = TicketPrice + 10;
            break;
        }
    }
}

    //adding the charge for premium seat type or not




    cout << "Are you a loyaty card member? 1 for yes, 0 for no:";
    cin >> (loyaltyMember);
if(loyaltyMember > 1 || loyaltyMember < 0){
    while(loyaltyMember > 1 || loyaltyMember < 0){                                                      //Making sure that the enter vaule stays between 1 or 0
            cout <<"Invalid vaule entered, please make sure your entered vaule is between 1 or 0: ";
            cin >> (loyaltyMember);
}}else{
    if(loyaltyMember == 1){
        cout << "Thank you for being a loyalty member, we have applided your 15 precent discount."<< '\n';
        Discount = TicketPrice * 0.15;
        TicketPrice = TicketPrice - Discount;
        Discount =0;
    }}

    //adding loyalty member discount 


    cout<< "You final ticket price comes out to $";
    cout << setprecision(5) << TicketPrice << '\n';
    cout<< "Thank you for booking with us, we can't wait to see you.";

    //outputing final price 
    
    
    
}
