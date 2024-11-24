#include <iostream>
#include <iomanip>
#include <string>


namespace movie_booking {
    using namespace std;

    enum movieGenre {ACTION = 1, COMEDY, DRAMA, SCI_FI, HORROR};
    enum ticketType {Standard = 1, VIP, Student};

    typedef string String;

    String getmovieType (movieGenre genre) {
        switch (genre) {
            case ACTION: return "Action";
            case COMEDY: return "Comedy";
            case DRAMA: return "Drama";
            case SCI_FI: return "Sci_Fi";
            case HORROR: return "Horror";
            default: return "Invalid";
        }
    }

    double ticketPrice (ticketType ticket) {
        switch (ticket) {
            case Standard: return 10.00;
            case VIP: return 20.00;
            case Student: return 8.00;
            default: return 0.00;
        }
    }
}

int main() {
    using namespace movie_booking;
    cout << fixed << showpoint << setprecision(2);
    string userName, password;
    cout << "Enter username and password" <<endl;
    cin >> userName;
    cin >> password;

    if (userName == "EvanI" && password == "Gabriel") {
        cout << "Welcome Mr. Gabriel." <<endl;
    }
    else {
        cout << "Invalid Credentials" <<endl;
        return 1;
    }

    char moreTickets;
    int movieChoice;
    int ticketChoice;

    do 
    {
        cout << "Please select your movie genre (1-5):" <<endl;
        cout << "1. ACTION" <<endl;
        cout << "2. COMEDY" <<endl;
        cout << "3. DRAMA" <<endl;
        cout << "4.SCI_FI" <<endl;
        cout << "5. HORROR" <<endl;
        cin >> movieChoice;
            movieGenre genre = static_cast<movieGenre>(movieChoice);
            String genreType = getmovieType (genre);
        
        cout << "Please select your seat type (1-3):" <<endl;
        cout << "1. Standard" <<endl;
        cout << "2. VIP" <<endl;
        cout << "3. Student" <<endl;
        cin >> ticketChoice;
            ticketType ticket = static_cast<ticketType>(ticketChoice);
            String seatTicket = (ticket == Standard) ? "Standard" : (ticket == VIP) ? "VIP": "Student";
            double price = ticketPrice (ticket);

        cout << "Order Summary:" <<endl;
        cout << "Movie:" << genreType <<endl;
        cout << "Ticket:" << seatTicket <<endl;
        cout << "Price: $" << price <<endl;

        cout << "Would you like to order another ticket? (Y/N)" <<endl;
        cin >> moreTickets;
    } while (moreTickets == 'Y' || moreTickets == 'y');

        cout << "Thank you. Please enjoy your show!" <<endl;

    return 0;
}