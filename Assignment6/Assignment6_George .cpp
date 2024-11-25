#include <string>
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h> 
using namespace std;
typedef std::string String;
String getGenreName();
//creating my enum values 
enum TicketType {REGULAR, VIP, STUDENT};
enum MovieGenre {ACTION, COMEDY, DRAMA, SCI_FI, HORROR};
double calculateTicketPrice(TicketType x);

int main(){
//creating anonymus enum 
enum{A,B,C,D,E};
String userName;
String password;
String userInput;
int numInput;
String movieGenre;
double ticketPrice;
int movieNumVal;
String ticketType;

int control = 0;
// function loop
while(control == 0){
cout << "Please enter your username: ";
cin >> userName;
cout << "Please enter your password: ";
cin >> password;

if(userName == "Kalonji" && password == "George"){
    //calling function to get genre
    movieGenre = getGenreName();

if(movieGenre == "Action"){
        MovieGenre movie = ACTION;
         movieNumVal = movie;
        
    }
    if(movieGenre == "Comedy"){
        MovieGenre movie = COMEDY;
         movieNumVal = movie;
    
    }if(movieGenre == "Drama"){
        MovieGenre movie = DRAMA;
         movieNumVal = movie;
    
    }if(movieGenre == "Sci Fi"){
        MovieGenre movie = SCI_FI;
         movieNumVal = movie;
    
    }if(movieGenre == "Horror"){
        MovieGenre movie = HORROR;
         movieNumVal = movie;
    
    }
    
    cout << "Please pick your ticket price." << '\n';
    cout << "1: Regular -> $10.00" << '\n';
    cout << "2: VIP -> $20.00" << '\n';
    cout << "3: Student -> $8.00" << '\n';
    cout << "Enter Choice: ";
    cin >> numInput;
    //sending ticket type value to function
    switch(numInput){
        case 1:{
           TicketType userTicket = REGULAR; 
           ticketPrice = calculateTicketPrice(userTicket); 
           ticketType = "Regular";
           break;

        }
        case 2:{
           TicketType userTicket = VIP; 
           ticketPrice = calculateTicketPrice(userTicket); 
           ticketType = "VIP";
           break;

        }
        case 3:{
           TicketType userTicket = STUDENT; 
           ticketPrice = calculateTicketPrice(userTicket); 
           ticketType = "Student";
           break;
        }
    }

   
            cout << "You Selected: " << movieGenre << '\n';
            cout << "Ticket Type: " << ticketType << '\n';
            cout << "Ticket Price: $" << ticketPrice << '\n';

            
            cout << "Would you like to book another ticket (Y/N): ";
            cin >> userInput;
            //looping main function if chosen
            if(userInput == "Y" || userInput == "y"){
                control = 0;
                numInput = 0;
            }
            if(userInput == "N" || userInput == "n"){
                control = 1;
                cout<< "Thank you for booking with us.";
            }
        
    
    
}



else{
    cout << "Your username and password don't match, Ending program.";
    control = 1;
}



}




}
//function for getting and returning genre name
String getGenreName(){
int userInput;
String returnValue;

cout << "Please select a Movie Genre." << '\n';
cout << "1: ACTION" << '\n';
cout << "2: COMEDY" << '\n';
cout << "3: DRAMA" << '\n';
cout << "4: SCI FI" << '\n';
cout << "5: HORROR" << '\n';
cout << "Please enter your selection: ";
cin >> userInput;

switch(userInput){
    case 1:{
        returnValue = "Action";
        return returnValue;
    }
    case 2:{
        returnValue = "Comedy";
        return returnValue;
    }
    case 3:{
        returnValue = "Drama";
        return returnValue;

    }
    case 4:{
        returnValue = "Sci Fi";
        return returnValue;

    }
    case 5:{
        returnValue = "Horror";
        return returnValue;

    }

}

}
//function for getting ticket prices
double calculateTicketPrice(TicketType x){
double ticketPrice;


if(x == REGULAR){
ticketPrice = 10;
return ticketPrice;
}
if(x == VIP){
ticketPrice = 20;
return ticketPrice;
}
if(x == STUDENT){
ticketPrice = 8;
return ticketPrice;
}

}
