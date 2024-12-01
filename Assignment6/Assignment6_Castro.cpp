//**********************************************************************
// Author: Raymond Castro
// Date: 24 Nov 2024
//
// Computer Science I Coding Assignment 6 - Raymond Castro
//
// This C++ program acts as a simple ticket booking system for a
// theater, using enumeration types, 'typedef' statements, namespaces,
// string operations, and input/output operations to prompt the user.
//**********************************************************************

// Header files
#include <iostream>
#include <string>
#include <algorithm> /* Header file used for algorithms, such as remove_if
and isspace */

namespace theater_booking
// Defines the namespace theater_booking
{
    using namespace std;
    
    enum MovieGenre {ACTION = 1, COMEDY, DRAMA, SCI_FI, HORROR};
    /* Declares MovieGenre as an enum data type and the following values
    as enumerators */
    enum TicketType {REGULAR = 1, VIP, STUDENT};
    /* Declares TicketType as an enum data type and the following values
    as enumerators */

    typedef string String; /* Creates an alias, String, for the string
    data type */

    enum {A = 'A', B = 'B', C = 'C', D = 'D', E = 'E'}; /* Declares the
    preceding values with no type name */

    String getGenreName(MovieGenre genre)
    /* Creates a function which converts an enumeration value of
    MovieGenre into a readable string */
    {
        switch (genre) /* Returns a specific string based on the value
        of genre */
        {
            case ACTION:
                return "Action"; /* Returns "Action" to the calling
                function */
            case COMEDY:
                return "Comedy";
            case DRAMA:
                return "Drama";
            case SCI_FI:
                return "Sci-Fi";
            case HORROR:
                return "Horror";
            default:
                return "Unknown Genre";
        }
    }

    String getTicketTypeName(TicketType ticket)
    /* Creates a function which converts an enumeration value of
    TicketType into a readable string */
    {
        switch(ticket) /* Returns a specific string based on the value
        of ticket */
        {
            case REGULAR:
                return "Regular";
            case VIP:
                return "VIP";
            case STUDENT:
                return "Student";
            default:
                return "Unknown Genre";
        }
    }

    double calculateTicketPrice(TicketType ticket)
    /* Creates a function which converts an enumeration value of
    TicketType into a price */
    {
        switch (ticket) /* Returns a specific price based on the value
        of ticket */
        {
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

    bool checkCredentials(const String& userName, const String& password)
    /* Creates a function which checks whether the user's credentials
    matches the predefined set below */
    {
        return userName == "Raymond" && password == "Castro";
    }

    void trim(String& str)
    // Creates a function which removes whitespace characters from a string
    {
        str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    }

    MovieGenre selectMovieGenre()
    // Creates a function which prompts the user to select a movie genre
    {
        int movieChoice;
        cout << "Select Movie Genre:" << endl
             << "1. Action" << endl
             << "2. Comedy" << endl
             << "3. Drama" << endl
             << "4. Sci-Fi" << endl
             << "5. Horror" << endl;
            // Displays a list of what genres the user can choose
        cout << "Enter choice (1-5): ";
        cin >> movieChoice;
        cout << endl;

        if ((movieChoice < 1) || (movieChoice > 5))
        /* Checks for input failure in movieChoice, then prompts the user
        repeatedly until the input is valid */
        {
            cout << "Invalid selection. Please try again." << endl;
            return selectMovieGenre();
        }
        return static_cast<MovieGenre>(movieChoice); /* Explicitly casts
        movieChoice as an enum value of MovieGenre */
    }

    TicketType selectTicketType()
    // Creates a function which prompts the user to select a ticket type
    {
    int ticketChoice;
        cout << "Select Ticket Type:" << endl
             << "1. Regular" << endl
             << "2. VIP" << endl
             << "3. Student" << endl;
             // Displays a list of what ticket types the user can choose
        cout << "Enter choice (1-3): ";
        cin >> ticketChoice;
        cout << endl;

        if ((ticketChoice < 1) || (ticketChoice > 3))
        /* Checks for input failure in ticketChoice, then prompts the user
        repeatedly until the input is valid */
        {
            cout << "Invalid selection. Please try again." << endl;
            return selectTicketType();
        }
        return static_cast<TicketType>(ticketChoice); /* Explicitly casts
        ticketChoice as an enum value of TicketType */
    }
}

int main()
{
    using namespace theater_booking; /* Tells the compiler to directly
    access members in the theater_booking namespace */

    int movieChoice, ticketChoice; /* Declares the preceding variables
    in the int data type */
    String userName, password;
    bool booking = true;

    cout << "Computer Science I Coding Assignment 6 - Raymond Castro"
         << endl << endl; // Outputs the title of the program
    cout << "Through enumeration types, 'typedef' statements, namespaces, "
         << "string operations, and input/output operations, this C++ program "
         << "functions as a movie ticket booking system,\nprompting the user "
         << "for their credentials, a movie genre, a ticket type, and "
         << "whether they would like to book another ticket."
         << endl << endl; // Displays an explanation of the program

    while (booking) // Loops until the user inputs a username and password
    {
        cout << "Enter your username: ";
        getline(cin, userName); /* Reads the inputted string, including
        whitespaces, then stores it in userName */
        cout << "Enter your password: ";
        getline(cin, password);

        trim(userName); // Uses the user-defined function trim on userName
        trim(password);

        while (userName.empty() || password.empty())
        // Loops until the username and password are not left empty
        {
            cout << "Username and password cannot be empty. Please try again."
            << endl; /* Prompts the user to ensure that the username and password
            fields are not empty */
            cout << "Enter your username: ";
            getline(cin, userName);
            cout << "Enter your password: ";
            getline(cin, password);
            trim(userName);
            trim(password);
        }

        if (checkCredentials(userName, password)) /* Checks whether the inputs for
        userName and password match the predefined set in the program */
        {
            cout << "Login successful!" << endl << endl;
        }
        else
        {
            cout << "Invalid username or password. Exiting program." << endl << endl;
            return 0; // Terminates the program if userName or password are invalid
        }

        MovieGenre selectedGenre = selectMovieGenre(); /* Stores the result of the
        user-defined function selectMovieGenre into selectedGenre */
        TicketType selectedTicket = selectTicketType();
        
        cout << "You selected: " << getGenreName(selectedGenre) << endl;
        cout << "Ticket Type: " << getTicketTypeName(selectedTicket) << endl;

        double price = calculateTicketPrice(selectedTicket);
        cout << "Ticket Price: $" << price << endl << endl;

        char repeat;
        cout << "Would you like to book another ticket? (Y/N): ";
        cin >> repeat;

        cin.ignore(100, '\n'); // Manages leftover characters in the input buffer

        while ((repeat != 'Y') && (repeat != 'y') && (repeat != 'N') && (repeat != 'n'))
        // Loops until the input for repeat is valid
        {
            cout << "Invalid input. Please enter Y or N: ";
            cin >> repeat;

            cin.ignore(100, '\n');
        }

        if ((repeat == 'N' || repeat == 'n'))
        // Checks whether the user chose to not book another ticket
        {
            booking = false;
            cout << "Thank you for using the theater booking system!" << endl;
            // Presents a thank you message to the user after they choose not to book another ticket
        }
    }

    return 0; // Terminates the program
}