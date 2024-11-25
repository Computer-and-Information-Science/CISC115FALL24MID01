#include <iostream>
#include <string>

namespace theater_booking {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
}

// Define enumeration types
enum MovieGenre { ACTION = 1, COMEDY, DRAMA, SCI_FI, HORROR };
enum TicketType { REGULAR = 1, VIP, STUDENT };

// Typedef for aliasing
typedef std::string String;

// Function to get the name of the genre
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
double calculateTicketPrice(TicketType ticket) {
    switch (ticket) {
        case REGULAR: return 10.00;
        case VIP: return 20.00;
        case STUDENT: return 8.00;
        default: return 0.0;
    }
}

// Function to verify username and password
bool verifyCredentials(const String& userName, const String& password) {
    String enteredUserName, enteredPassword;
    theater_booking::cout << "Enter your username: ";
    theater_booking::cin >> enteredUserName;
    theater_booking::cout << "Enter your password: ";
    theater_booking::cin >> enteredPassword;

    if (userName == enteredUserName && password == enteredPassword) {
        theater_booking::cout << "Login successful!\n";
        return true;
    } else {
        theater_booking::cout << "Error: Invalid username or password.\n";
        return false;
    }
}

int main() {
    using namespace theater_booking;

    String userName, password;

    // Set up username and password
    cout << "Set your username: ";
    cin >> userName;
    cout << "Set your password: ";
    cin >> password;

    char choice;
    do {
        // Verify credentials
        if (!verifyCredentials(userName, password)) {
            cout << "Exiting program due to failed authentication.\n";
            return 1;
        }

        // Prompt for movie genre
        cout << "\nSelect a movie genre:\n"
             << "1. Action\n2. Comedy\n3. Drama\n4. Sci-Fi\n5. Horror\n";
        int genreInput;
        cin >> genreInput;
        MovieGenre genre = static_cast<MovieGenre>(genreInput);

        // Prompt for ticket type
        cout << "\nSelect a ticket type:\n"
             << "1. Regular\n2. VIP\n3. Student\n";
        int ticketInput;
        cin >> ticketInput;
        TicketType ticket = static_cast<TicketType>(ticketInput);

        // Calculate and display ticket details
        cout << "\nMovie Genre: " << getGenreName(genre) << "\n";
        cout << "Ticket Type: " << (ticket == REGULAR ? "Regular" : ticket == VIP ? "VIP" : "Student") << "\n";
        cout << "Ticket Price: $" << calculateTicketPrice(ticket) << "\n";

        // Ask if the user wants to book another ticket
        cout << "\nWould you like to book another ticket? (y/n): ";
        cin >> choice;

        // Re-authenticate if the user wants to book another ticket
        if (choice == 'y' || choice == 'Y') {
            if (!verifyCredentials(userName, password)) {
                cout << "Exiting program due to failed authentication.\n";
                return 1;
            }
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the Movie Ticket Booking System. Goodbye!\n";

    return 0;
}
