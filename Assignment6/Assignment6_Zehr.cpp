//
//
//  Homework Week 6
//
//  Created by Isaac Zehr
//

#include <iostream>
#include <string>



//Creating a namespace
namespace theater_booking {
using namespace std;
//Defining enumerations for MovieGenre, and TickeType
enum MovieGenre { ACTION, COMEDY, DRAMA, SCI_FI, HORROR};
enum TicketType { REGULAR, VIP, STUDENT};

//Defining anonymous enum
enum {A, B, C, D, E} SeatRow;

//Creating an alias for std::string called String
typedef std::string String;

//Function to take enumeration value of MovieGenre and return it as a string
String getGenreName(MovieGenre genre) {
        switch (genre) {
            case ACTION: return "Action";
            case COMEDY: return "Comedy";
            case DRAMA: return "Drama";
            case SCI_FI: return "Sci-Fi";
            case HORROR: return "Horror";
            default: return "Unknown";
        }
    }
//Function to take TicketType enum value and retunr a double price
double calculateTicketPrice(TicketType type) {
        switch (type) {
            case REGULAR: return 10.00;
            case VIP: return 20.00;
            case STUDENT: return 8.00;
            default: return 0.00;
        }
    }
}

using namespace theater_booking;

int main (){
  
    using namespace theater_booking;
    
    String userName, password;
    bool continue_booking = true;
    
    //Ask for login
    
    cout << "Enter Username: " << endl;
    getline (cin, userName);
    cout << "Enter Password: " << endl;
    getline (cin, password);
    
    //Verify Login
    
    if (userName == "Isaac" && password == "Zehr"){
        cout << "Login Succesful!" << endl;
    }
    else {
        cout <<"Invalid Username or Password" << endl;
        return 0;
    }
    
    while (continue_booking){
        //Movie Genre selection
        int genreChoice, ticketChoice;
        cout << "Select Movie Genre: \n";
        cout << "1. Action\n";
        cout << "2. Comedy\n";
        cout << "3. Drama\n";
        cout << "4. Sci-fi\n";
        cout << "5. Horror\n";
        cout << "Enter Choice (1-5): \n";
        cin >> genreChoice;
        
        //Genre choice input validation
        
        if (genreChoice < 1 || genreChoice > 5){
            cout << "Invalid genre choice. Please try again." << endl;
            continue;
        }
        
        MovieGenre selectedGenre = static_cast<MovieGenre>(genreChoice-1);
       
        //Ticket Type selection
        cout << "Select Ticket Type: \n";
        cout << "1. Regular\n";
        cout << "2. VIP\n";
        cout << "3. Student\n";
        cout << "Enter Choice (1-3)\n";
        cin >> ticketChoice;
        
        //Ticket Choice input validation
        
        if (ticketChoice < 1 || ticketChoice > 3){
            cout << "Invalid ticket type. Please try again." << endl;
        }
        
        TicketType ticketselection = static_cast<TicketType>(ticketChoice-1);
        double ticketPrice = calculateTicketPrice(ticketselection);
        //Print user selections
        cout << "You Selected: " << getGenreName(selectedGenre) << endl;
        cout << "Ticket Type: ";
        switch (ticketChoice){
            case 1: cout << "Regular\n";
                break;
            case 2: cout << "VIP\n";
                break;
            case 3: cout << "Student\n";
                break;
        }
        cout << "Ticket Price: $";
        cout << ticketPrice << endl;
        
        //Ask user if they want to book another ticket
        cout << "Do you want to book another ticket? (y/n): " << endl;
        char response;
        cin >> response;
        //Based on user response either continue the loop or stop it and output a closure message
        if (response == 'n' || response == 'N') {
                continue_booking = false;
                        cout << "Thank you for using the Ticket Booking System!\n";
                    }
        }
    
    
    
    
    
    return 0;
}
