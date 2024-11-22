#include <iostream>
#include <string>

namespace theater_booking {
    using namespace std;

    // Define enumeration types
    enum MovieGenre { ACTION = 1, COMEDY, DRAMA, SCI_FI, HORROR };
    enum TicketType { REGULAR = 1, VIP, STUDENT };

    // Typedef for string alias
    typedef string String;

    // Function to get the name of the movie genre
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

    // Function to calculate ticket price
    double calculateTicketPrice(TicketType ticketType) {
        switch (ticketType) {
            case REGULAR: return 10.00;
            case VIP: return 20.00;
            case STUDENT: return 8.00;
            default: return 0.00;
        }
    }
}

int main() {
    using namespace theater_booking;

    // User login
    String userName, password;
    cout << "Enter username: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;

    if (userName == "Myoset" && password == "Naing") {
        cout << "Login successful!\n";
    } else {
        cout << "Invalid username or password. Exiting program.\n";
        return 1;
    }

    // Ticket booking loop
    char anotherTicket;
    do {
        // Select Movie Genre
        cout << "\nSelect Movie Genre:\n";
        cout << "1. Action\n2. Comedy\n3. Drama\n4. Sci-Fi\n5. Horror\n";
        int genreChoice;
        cout << "Enter choice (1-5): ";
        cin >> genreChoice;

        MovieGenre genre = static_cast<MovieGenre>(genreChoice);
        String genreName = getGenreName(genre);

        // Select Ticket Type
        cout << "Select Ticket Type:\n";
        cout << "1. Regular\n2. VIP\n3. Student\n";
        int ticketChoice;
        cout << "Enter choice (1-3): ";
        cin >> ticketChoice;

        TicketType ticketType = static_cast<TicketType>(ticketChoice);
        String ticketTypeName = (ticketType == REGULAR) ? "Regular" :
                                (ticketType == VIP) ? "VIP" : "Student";
        double price = calculateTicketPrice(ticketType);

        // Output the selection
        cout << "You selected: " << genreName << "\n";
        cout << "Ticket Type: " << ticketTypeName << "\n";
        cout << "Ticket Price: $" << price << "\n";

        // Ask if the user wants another ticket
        cout << "Would you like to book another ticket? (y/n): ";
        cin >> anotherTicket;

    } while (anotherTicket == 'y' || anotherTicket == 'Y');

    cout << "Thank you for using the theater booking system!\n";

    return 0;
}

