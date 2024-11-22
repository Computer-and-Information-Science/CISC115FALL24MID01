#include <iostream>
#include <string>

namespace theater_booking { 
    // define std functions
    using std::cin;
    using std::cout;
    using std::string;
    using std::endl;

    // enum definitions
    enum MovieGenre {ACTION, COMEDY, DRAMA, SCI_FI, HORROR};    // define enum type 'MovieGenre'
    enum TicketType {REGULAR, VIP, STUDENT};                    // define enum type 'TicketType'
    enum {A, B, C, D, E} seatRow;                               // define anonymous enum for 'SeatRow'
    typedef std::string String;                                 // create an alias for std::string using typedef

    // function prototypes
    void validateUserAccount();
    void handleUserInput();
    MovieGenre promptUserGenre();
    TicketType promptUserTicket();
    String getGenreName(MovieGenre);
    double calculateTicketPrice(TicketType);
    void displayBookingDetails(MovieGenre, TicketType, double);
}

int main() {
    using namespace theater_booking;     // use the user-defined namespace
    theater_booking::validateUserAccount();
    theater_booking::handleUserInput();
    return 0;
}

void theater_booking::validateUserAccount() {
    String userName, password;  // define string variables 'userName' and 'password' using 'String' alias

    cout << "Enter username: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;

    if (userName == "Cheryl" && password == "Merng") {
        cout << "Login successful!" << endl;
    }
    else {
        cout << "Invalid username or password. Exiting program.";
        exit(0);    // terminate program
    }
}

void theater_booking::handleUserInput() {
    char continueBooking = 'n';
    
    do {        
        MovieGenre selectedGenre = promptUserGenre();                           // call promptuser functions to declare enum types variables
        TicketType selectedTicket = promptUserTicket();
        double ticketPrice = calculateTicketPrice(selectedTicket);              // call calculateTicketPrice()
        displayBookingDetails(selectedGenre, selectedTicket, ticketPrice);      // call displayBookingDetails() to output the selected details

        cout << "\nWould you like to book another ticket? (y/n): ";             // ask the user if they want to continue using the system
        cin >> continueBooking;
        validateUserAccount();                                                  // ask the user to login again to ensure the same or new user will make a new booking
    }
    while (continueBooking == 'y' || continueBooking == 'Y');   // exit program

    cout << "\nThank you for using the theater booking system!\n";
}

theater_booking::MovieGenre theater_booking::promptUserGenre() {
    int choice;
    MovieGenre selectedGenre;   // declare variables for enum type

    while (true) {
        cout << "\nSelect Movie Genre:\n1. Action\n2. Comedy\n3. Drama\n4. Sci-Fi\n5. Horror" << endl;
        cout << "Enter choice (1-5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            selectedGenre = static_cast<MovieGenre>(choice - 1);
            // cout << "In MovieGenre promptUserGenre(): " << selectedGenre << endl;      // testing purpose - output index no
            break;
        }
        else
            cout << "Invalid choice. Please enter 1 to 5 only!\n";        
    }
    return selectedGenre;
}

theater_booking::TicketType theater_booking::promptUserTicket() {
    int choice;
    TicketType selectedTicket;  // declare variables for enum type

    // prompt the user to select a ticket type
    while (true) {
        cout << "\nSelect Ticket Type:\n1. Regular\n2. VIP\n3. Student" << endl;
        cout << "Enter choice (1-3): ";
        cin >> choice;

        if (choice >=1 && choice <=3) {
            selectedTicket = static_cast<TicketType>(choice - 1);
            // cout << "TicketType promptUserTicket(): " << selectedTicket << endl;    // testing purpose - output index no
            break;
        }
        else
            cout << "Invalid choice. Please enter 1 to 3 only!\n"; 
        }
    return selectedTicket;
}

theater_booking::String theater_booking::getGenreName(theater_booking::MovieGenre genre) {
    switch (genre) {
        case ACTION: return "Action";   // no need to break b/c of return
        case COMEDY: return "Comedy";
        case DRAMA: return "Drama";
        case SCI_FI: return "Sci-Fi";
        case HORROR: return "Horror";
        default: return "Unknown";
    }
}

double theater_booking::calculateTicketPrice(theater_booking::TicketType type) {
    switch (type) {
        case REGULAR: return 10.00;
        case VIP: return 20.00;
        case STUDENT: return 8.00;
        default: return 0.00;
    }
}

void theater_booking::displayBookingDetails(theater_booking::MovieGenre genre, theater_booking::TicketType type, double price) {
    cout << "\nYou selected: " << getGenreName(genre) << endl;
    cout << "Ticket Type: ";

    switch (type) {
        case REGULAR: cout << "Regular"; break;
        case VIP: cout << "VIP"; break;
        case STUDENT: cout << "Student"; break;
        default: cout << "Unknown"; break;
    }

    cout << "\nTicket Price: $" << price << endl;
}