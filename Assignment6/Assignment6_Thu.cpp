#include <iostream>
#include <string>

namespace theater_booking {
    using namespace std;
    
    // Declare enumeration data type
    enum MovieGenre { ACTION = 1, COMEDY, DRAMA, SCI_FI, HORROR }; 
    enum TicketType { REGULAR = 1, VIP, STUDENT };
    
    // To create an alias 
    typedef string String;
    
    // Function to translate enumeration values into readable strings
    String getGenreName(MovieGenre genre) {
        switch (genre) {
            case ACTION: 
                return "Action";
            case COMEDY: 
                return "Comedy";
            case DRAMA: 
                return "Drama";
            case SCI_FI: 
                return "Sci-Fi";
            case HORROR: 
                return "Horror";
            default: 
                return "Error selecting genre!";
        }
    }
    
    double calculateTicketPrice(TicketType ticketType) {
        switch (ticketType) {
            case REGULAR:
                return 10.00;
            case VIP:
                return 20.00;
            case STUDENT:
                return 8.00;
            default:
                return 0.00; 
        }
    }
}

//movie ticket operation
int main() {
    using namespace theater_booking;

    cout << ".....Movie Ticket Booking System.....\n" << endl; // output the title of program

    // Prompts for user to login correctly 
    String userName, password;
    while (true) {
        cout << "Enter Username: ";
        cin >> userName;
        cout << "Enter Password: ";
        cin >> password;

        if (userName == "kaungmyat" && password == "Thu") {
            cout << "Successful login!\n " << endl;
            break; // To stop the login loop when login is successful
        } else {
            cout << "Invalid username or password. Please try again.\n";
        }
    }

    char bookAnotherTicket;
    do { //loop to perform multiple tickets
        
        int genreSelection;
        cout << "Select Movie Genre:\n";
        cout << "1. Action\n2. Comedy\n3. Drama\n4. Sci-Fi\n5. Horror\n";
        cout << "Enter your choice (1-5): ";
        cin >> genreSelection;

        // To convert input into appropriate enum type
        MovieGenre genre = static_cast<MovieGenre>(genreSelection);
        String genreName = getGenreName(genre);

        int ticketSelection;
        cout << "\nSelect Ticket Type:\n";
        cout << "1. Regular\n2. VIP\n3. Student\n";
        cout << "Enter your choice (1-3): ";
        cin >> ticketSelection;

        TicketType ticketType = static_cast<TicketType>(ticketSelection);
        String ticketTypeName = (ticketType == REGULAR) ? "Regular" :
                                (ticketType == VIP) ? "VIP" : "Student";
        double price = calculateTicketPrice(ticketType);

        // Output final ticket review
        cout << "\nYou selected: " << genreName << endl;
        cout << "Ticket Type: " << ticketTypeName << endl;
        cout << "Your Ticket Price is: $" << price << "\n" << endl;
        
        // Asking user to continue program or not
        cout << "Would you like to book another ticket? (y/n): ";
        cin >> bookAnotherTicket; 

    } while (bookAnotherTicket == 'y');

    cout << "Thank you for using the theater booking system!" << endl;

    return 0;
}
