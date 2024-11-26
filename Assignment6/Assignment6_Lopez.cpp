#include <iostream>
#include <string>

namespace theater_booking {

    // Enumeration for Movie Genre
    enum MovieGenre { ACTION = 1, COMEDY, DRAMA, SCI_FI, HORROR };

    // Enumeration for Ticket Type
    enum TicketType { REGULAR = 1, VIP, STUDENT };

    // Typedef for string alias
    typedef std::string String;

    // Anonymous enumeration for SeatRow
    enum { A, B, C, D, E } SeatRow;

    // Function to get the genre name as a string
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
    double calculateTicketPrice(TicketType type) {
        switch (type) {
            case REGULAR: return 10.00;
            case VIP: return 20.00;
            case STUDENT: return 8.00;
            default: return 0.00;
        }
    }
} // namespace theater_booking

using namespace theater_booking;

int main() {
    String userName, password;

    // Prompt for username and password
    std::cout << "Enter your username: ";
    std::getline(std::cin, userName);
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    // Validate username and password
    if (userName == "Austin" && password == "Lopez") {
        std::cout << "Login successful. Welcome, " << userName << "!\n";
    } else {
        std::cout << "Error: Invalid username or password.\n";
        return 0;
    }

    bool bookAnotherTicket = true;

    while (bookAnotherTicket) {
        // Prompt user to select a MovieGenre
        std::cout << "\nSelect a Movie Genre:\n";
        std::cout << "1. Action\n2. Comedy\n3. Drama\n4. Sci-Fi\n5. Horror\n";
        int genreChoice;
        std::cout << "Enter the number of your choice: ";
        std::cin >> genreChoice;

        if (genreChoice < 1 || genreChoice > 5) {
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        MovieGenre selectedGenre = static_cast<MovieGenre>(genreChoice);

        // Prompt user to select a TicketType
        std::cout << "\nSelect a Ticket Type:\n";
        std::cout << "1. Regular ($10.00)\n2. VIP ($20.00)\n3. Student ($8.00)\n";
        int ticketChoice;
        std::cout << "Enter the number of your choice: ";
        std::cin >> ticketChoice;

        if (ticketChoice < 1 || ticketChoice > 3) {
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        TicketType selectedTicket = static_cast<TicketType>(ticketChoice);

        // Calculate ticket price
        double ticketPrice = calculateTicketPrice(selectedTicket);

        // Output selected MovieGenre, TicketType, and ticket price
        std::cout << "\nYour Selection:\n";
        std::cout << "Movie Genre: " << getGenreName(selectedGenre) << "\n";

        std::cout << "Ticket Type: ";
        switch (selectedTicket) {
            case REGULAR: std::cout << "Regular"; break;
            case VIP: std::cout << "VIP"; break;
            case STUDENT: std::cout << "Student"; break;
        }
        std::cout << "\n";

        std::cout << "Ticket Price: $" << ticketPrice << "\n";

        // Ask if the user wants to book another ticket
        std::cout << "\nDo you want to book another ticket? (1 for Yes, 0 for No): ";
        int response;
        std::cin >> response;

        if (response != 1) {
            bookAnotherTicket = false;
            std::cout << "Thank you for using the Ticket Booking System!\n";
        }
    }

    return 0;
}
