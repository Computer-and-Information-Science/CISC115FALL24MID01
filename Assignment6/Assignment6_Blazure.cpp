#include <iostream>
#include <string>
#include <iomanip>

namespace theater_booking { //Declaring the variables for the Movie Genre
    using namespace std;

    enum MovieType {Action = 1 , Drama, SciFi, Horror};
    enum TicketType {Regular = 1 , VIP, Student};

    typedef string String;

    String getMovieType (MovieType Mtype) { //Assigning values for movie genres
        switch (Mtype)
        {
        case Action:
            return "Action";
        case Drama:
            return "Drama";
        case SciFi:
            return "SciFi";
        case Horror:
            return "Horror";    
        
        default:
            return "UNKNOWN";
        }
    }
    double TicketPrice(TicketType ticketType) { //Assigning values for the ticket prices
        switch (ticketType) {
            case Regular: 
                return 10.00;
            case VIP: 
                return 20.00;
            case Student: 
                return 8.00;

            default: 
                 return 0.00;
        }
    }
}

int main () {
  using namespace theater_booking; //Values in the namespace theater booking are put into effect for the main
   cout << fixed << showpoint << setprecision (2);
   string userName, Password;
   cout << "Enter Username:";
   cin >> userName;
   cout << "Enter Password:";
   cin >> Password;

   if (userName == "CBlazure" && Password == "Green")
   {
    cout << "Welcome " << userName << Password;
   } else
   {
    cout << "Invalid login."; //If the incorrect values are inserted
    return 1;
   }
   
   char MoreTickets;
   int MovieChoice;
   int TicketChoice;

  do
  {
  cout << "Please select a movie type: " << endl; //Selection for ehich movie genre to watch
  cout << "1. Action" << endl << "2. Drama" << endl << "3. SciFi" << endl << "4. Horror" << endl;
  cout << "Enter a choice (1-4): " << endl;
  cin >> MovieChoice;

        MovieType genre = static_cast<MovieType>(MovieChoice);
        String genreName = getMovieType(genre);

cout << "Please Select a ticket type: " << endl; //Values for the ticket type selected
cout << "1. Regular" << endl << "2. VIP" << endl << "3. Student" << endl;
cout << "Select ticket choice (1-3): ";
cin >> TicketChoice;

         TicketType ticketType = static_cast<TicketType>(TicketChoice);
        String ticketTypeName = (ticketType == Regular) ? "Regular" :(ticketType == VIP) ? "VIP" : "Student";
        double price = TicketPrice(ticketType);

cout << "Order overview: " << endl //Summary and total for all the values added
<< "Movie type: " << genreName << endl
<< "Ticket type selection: " << ticketTypeName << endl
<< "Price: " << "$" << price << endl;

cout << "Would you like to try again? Enter Y or N: ";
cin >> MoreTickets;
  } while (MoreTickets == 'y' || MoreTickets == 'Y');
  
   cout << "Thank you. Enjoy the show." << endl;

   return 0;

}