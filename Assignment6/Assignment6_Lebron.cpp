#include <iostream>
#include <string>

namespace theater_booking {

    // Enumeration for Movie Genre
    enum MovieGenre {
        ACTION = 1,
        COMEDY,
        DRAMA,
        SCI_FI,
        HORROR
    };

    // Enumeration for Ticket Type
    enum TicketType {
        REGULAR = 1,
        VIP,
        STUDENT
    };

    // Typedef for string alias
    typedef std::string String;

    // Anonymous enumeration for Seat Row
    enum { A = 1, B, C, D, E };

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

    // Function to calculate ticket price based on ticket type
    double calculateTicketPrice(TicketType type) {
        switch (type) {
            case REGULAR: return 10.00;
            case VIP: return 20.00;
            case STUDENT: return 8.00;
            default: return 0.00;
        }
    }

}  // namespace theater_booking

int main() {
    using namespace theater_booking;

    String userName, password;
    bool continueBooking = true;

    // Ask for login credentials
    std::cout << "Enter username: ";
    std::getline(std::cin, userName);

    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    // Login validation
    if (userName == "Cristian" && password == "Lebron") {
        std::cout << "Login Successful!" << std::endl;
    } else {
        std::cout << "Invalid username or password." << std::endl;
        return 0;  // Exit the program if login fails
    }

    // Start the ticket booking loop
    while (continueBooking) {
        int genreChoice, ticketChoice;

        // Movie Genre Selection
        std::cout << "\nSelect Movie Genre:" << std::endl;
        std::cout << "1. Action" << std::endl;
        std::cout << "2. Comedy" << std::endl;
        std::cout << "3. Drama" << std::endl;
        std::cout << "4. Sci-Fi" << std::endl;
        std::cout << "5. Horror" << std::endl;
        std::cout << "Enter choice (1-5): ";
        std::cin >> genreChoice;

        // Validate genre choice
        if (genreChoice < 1 || genreChoice > 5) {
            std::cout << "Invalid choice!" << std::endl;
            continue;  // Skip this loop iteration
        }

        MovieGenre selectedGenre = static_cast<MovieGenre>(genreChoice);
        std::cout << "You selected: " << getGenreName(selectedGenre) << std::endl;

        // Ticket Type Selection
        std::cout << "\nSelect Ticket Type:" << std::endl;
        std::cout << "1. Regular" << std::endl;
        std::cout << "2. VIP" << std::endl;
        std::cout << "3. Student" << std::endl;
        std::cout << "Enter choice (1-3): ";
        std::cin >> ticketChoice;

        // Validate ticket choice
        if (ticketChoice < 1 || ticketChoice > 3) {
            std::cout << "Invalid choice!" << std::endl;
            continue;  // Skip this loop iteration
        }

        TicketType selectedTicket = static_cast<TicketType>(ticketChoice);
        double ticketPrice = calculateTicketPrice(selectedTicket);

        std::cout << "Ticket Type: " << (selectedTicket == REGULAR ? "Regular" :
                                           selectedTicket == VIP ? "VIP" : "Student") << std::endl;
        std::cout << "Ticket Price: $" << ticketPrice << std::endl;

        // Ask if the user wants to book another ticket
        char choice;
        std::cout << "\nWould you like to book another ticket? (y/n): ";
        std::cin >> choice;

        if (choice == 'n' || choice == 'N') {
            continueBooking = false;
        }
    }

    // Final message
    std::cout << "\nThank you for using the theater booking system!" << std::endl;

    return 0;
}