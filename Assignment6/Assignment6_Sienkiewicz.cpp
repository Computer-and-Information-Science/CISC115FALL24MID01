#include <iostream>  // For cin and cout
#include <string>    // For std::string
#include <cstdlib>   // For exit() function

using namespace std;

// Enumeration Types
enum MovieGenre { ACTION = 1, COMEDY, DRAMA, SCI_FI, HORROR };  
enum TicketType { REGULAR = 1, VIP, STUDENT };  

typedef string String;  

// Namespace for theater booking
namespace theater_booking {
    // Function to get the name of the movie genre
    string getGenreName(MovieGenre genre) {
        switch (genre) {
            case ACTION: return "Action";
            case COMEDY: return "Comedy";
            case DRAMA: return "Drama";
            case SCI_FI: return "Science Fiction";
            case HORROR: return "Horror";
            default: return "Unknown Genre";
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

    // Function to handle user login
    bool userLogin(String &userName, String &password) {
        cout << "Please enter your username: ";
        cin >> userName;
        cout << "Please enter your password: ";
        cin >> password;

        // Validate login
        if (userName == "Norbert" && password == "Sienkiewicz") {
            cout << "Login successful!" << endl; 
            return true;
        } else {
            cout << "Login failed. Exiting program." << endl;
            exit(1);  // Exit the program if login fails
        }
    }
}

int main() {
    // Declare variables
    MovieGenre selectedGenre;
    TicketType selectedTicket;
    String userName, password;
    int genreChoice, ticketChoice;
    char repeatChoice;

    // Prompt for login before booking
    theater_booking::userLogin(userName, password);

    do {
        // Ask the user to select a movie genre
        cout << "Select a Movie Genre:" << endl;
        cout << "1. ACTION\n2. COMEDY\n3. DRAMA\n4. SCI_FI\n5. HORROR" << endl;
        cout << "Enter choice (1-5): ";
        cin >> genreChoice;

        // Validate the genre choice
        if (genreChoice < 1 || genreChoice > 5) {
            cout << "Invalid choice. Please select a valid genre." << endl;
            continue;
        }

        selectedGenre = static_cast<MovieGenre>(genreChoice);

        //  Ask the user to select a ticket type
        cout << "Select Ticket Type:" << endl;
        cout << "1. REGULAR\n2. VIP\n3. STUDENT" << endl;
        cout << "Enter choice (1-3): ";
        cin >> ticketChoice;

        // Validate the ticket choice
        if (ticketChoice < 1 || ticketChoice > 3) {
            cout << "Invalid choice. Please select a valid ticket type." << endl;
            continue;
        }

        selectedTicket = static_cast<TicketType>(ticketChoice);

        // Output the selected genre and ticket details
        cout << "You selected: " << theater_booking::getGenreName(selectedGenre) << endl;
        cout << "Ticket Type: ";

        switch (selectedTicket) {
            case REGULAR: cout << "Regular"; break;
            case VIP: cout << "VIP"; break;
            case STUDENT: cout << "Student"; break;
        }

        // Display the calculated ticket price
        double ticketPrice = theater_booking::calculateTicketPrice(selectedTicket);
        cout << "\nTicket Price: $" << ticketPrice << endl;

        // Ask if the user wants to book another ticket
        cout << "\nDo you want to book another ticket? (Y/N): ";
        cin >> repeatChoice;

        // If yes, ask for the username and password again before proceeding
        if (repeatChoice == 'Y' || repeatChoice == 'y') {
            cout << "\nPlease log in again to book another ticket.\n";
            theater_booking::userLogin(userName, password); // Prompt for login again
        }

    } while (repeatChoice == 'Y' || repeatChoice == 'y');

    return 0;
}

