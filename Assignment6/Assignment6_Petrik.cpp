#include <iostream>
#include <iomanip>
#include <string>
enum movieGenre {ACTION, COMEDY, DRAMA, SCI_FI, HORROR};//creates the movieGenre data type that stores the different types of movies
enum ticketType {REG, VIP, STU};//creates the ticketType data type that stores the different types of tickets
enum {A, B, C, D, E} seatRow;//creates an anonymous data type that stores seat rows in the variable seatRow
namespace theater_booking//creates a namespace to store the input/output functions, string functions, and other functions of the program
{
    using namespace std;//allows input and output functions and the string data type to be used
    typedef string String;//creates an alias for the string type
    String username;
    String password;
    int error(int input)//corrects any input errors for int inputs
    {
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"Invalid input. Please enter the correct data type: ";
            cin>>input;
        }
        return input;
    }
    String getGenreName(movieGenre genre)//uses the movieGenre type as a parameter to find what movie has been selected
    {
        if (genre == ACTION){
            return "Action";
        }else if (genre == COMEDY){
            return "Comedy";
        }else if (genre == DRAMA){
            return "Drama";
        }else if (genre == SCI_FI){
            return "Sci-Fi";
        }else if (genre == HORROR){
            return "Horror";
        }
        return "what";
    }
    double calculateTicketPrice (ticketType ticket)//uses the ticketType as a parameter to determine a price for the ticket chosen
    {
        if (ticket == REG){
            return 10.00;
        }else if (ticket == VIP){
            return 20.00;
        }else if (ticket == STU){
            return 8.00;
        } 
        return 0.00;
    }
    char yesOrNo(char input)//checks to see if the user inputted the right letter to answer the question
    {
        while ((input != 'y')&&(input != 'n'))
        {
            cout<<"Enter an answer as y for yes and n for no: ";
            cin>>input;
        }
        return input;
    }
}
int main()
{
    using namespace theater_booking;//allows access to all properties of the namespace
    //variables need to run the program
    char iteration;
    int genreChoice;
    int ticketChoice;
    movieGenre movie;
    ticketType ticket;
    do{
    cout<<"Enter Username: ";
    cin>>username;
    cout<<"Enter Password: ";
    cin>>password;
    if ((username == "Steven")&&(password == "Petrik"))//check if the user inputted in the right username and password
    {
        cout<<"Login Successful!"<<endl;
        do{
            cout<<"\nSelect Movie Genre:\n1. Action\n2. Comedy\n3. Drama\n4. Sci-Fi\n5. Horror"<<endl;
            cout<<"Enter choice(1-5): ";
            cin>>genreChoice;
            genreChoice = error(genreChoice);
            cout<<"\nSelect Ticket Type:\n1. Regular\n2. VIP\n3. Student"<<endl;
            cout<<"Enter choice (1-3): ";
            cin>>ticketChoice;
            ticketChoice = error(ticketChoice);
            if (genreChoice == 1){
                cout<<"\nYou selected: "<<getGenreName(movie = ACTION)<<endl;
            }else if(genreChoice == 2){
                cout<<"\nYou selected: "<<getGenreName(movie = COMEDY)<<endl;
            }else if(genreChoice == 3){
                cout<<"\nYou selected: "<<getGenreName(movie = DRAMA)<<endl;
            }else if (genreChoice == 4){
                cout<<"\nYou selected: "<<getGenreName(movie = SCI_FI)<<endl;
            }else if (genreChoice == 5){
                cout<<"\nYou selected: "<<getGenreName(movie = HORROR)<<endl;
            }else{
                cout<<"\nError. Could not find movie genre. Exiting program."<<endl;
                return 0;
            }
            if (ticketChoice == 1){
                cout<<"Ticket Type: Regular"<<endl;
                cout<<"Ticket Price: $"<<calculateTicketPrice(ticket = REG)<<endl;
            }else if(ticketChoice == 2){
                cout<<"Ticket Type: VIP"<<endl;
                cout<<"Ticket Price: $"<<calculateTicketPrice(ticket = VIP)<<endl;
                
            }else if(ticketChoice == 3){
                cout<<"Ticket Type: Student"<<endl;
                cout<<"Ticket Price: $"<<calculateTicketPrice(ticket = STU)<<endl;
            }else{
                cout<<"\nError. Could not find ticket type. Exiting program."<<endl;
                return 0;
            }
            cout<<"\nWould you like to book another ticket? (y/n): ";
            cin>>iteration;
            iteration = yesOrNo(iteration);
        }while(iteration != 'n');
        iteration = 'y';
    }else{
        cout<<"\nInvalid username or password. Exiting the program."<<endl;
        return 0;
    }
    cout<<"Do you want to make a ticket on another account? (y/n): ";
    //I know this is extra and no other username/password is possible for the code, but it seemed appropriate for the user to be able to make mutiple ticket under their name
    cin>>iteration;
    iteration = yesOrNo(iteration);
    }while(iteration != 'n');
    cout<<"Thank you for using the theater booking system!"<<endl;
}
