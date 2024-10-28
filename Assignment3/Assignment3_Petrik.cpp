#include <iostream>
#include <iomanip>
using namespace std;
int main() {
   //variables needed to run the program
   int age;
   int showTime;
   int seatType;
   bool loyal;
   double price = 0.00;
   //asks for an input of age
   cout<<"Enter your age: ";
   cin>>age;
   //cheak if input enters a failed state
   if (cin.fail())
   {
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"Invalid input. Please enter the correct data type."<<endl;
      return 0;
   }
   //assesses the cost of ticket based off of age
   if ((age <= 12) && (age >= 0))
      price = price + 8.00;
   else if ((age >= 13) && (age <= 59))
      price = price + 12.00;
   else if (age >= 60)
      price = price + 10.00;
   else
   {
      cout<<"Enter a real age!"<<endl;
      return 0;
   }
   //asks for the showtime in military time
   cout<<"Enter the showtime (24-hour format between 9AM - 5PM, e.g., 14 for 2PM): ";
   cin>>showTime;
   //cheak if input enters a failed state
   if (cin.fail())
   {
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"Invalid input. Please enter the correct data type."<<endl;
      return 0;
   }
   //assesses the ticket price base off of the time
   if ((showTime < 12) && (showTime >= 9))
      price = price - ((price * 10)/100);
   else if ((showTime < 9) || (showTime > 17))
   {
      cout<<"Invalid show time!"<<endl;
      return 0;
   }
   //gives a list of seat types for the user to buy
   cout<<"Choose seat type:\n"<<"1 for standard\n"<<"2 for premium\n"<<"3 for combo\n"<<"4 for upgrade to gold member\n"<<"Seat type: ";
   cin>>seatType;
   //cheak if input enters a failed state
   if (cin.fail())
   {
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"Invalid input. Please enter the correct data type."<<endl;
      return 0;
   }
   //assesses the price based off of the seat typed picked
   switch (seatType)
   {
   case 1:
      break;
   case 2:
      price = price + 5.00;
      break;
   case 3:
      price = price + 7.00;
      break;
   case 4:
      price = price + 10.00;
      break;
   default:
      cout<<"Input a choice from the list!";
      return 0;
   }
   //asks the user if they have a loyalty card
   cout<<"Do you have a loyalty card? (1 for Yes, 0 for No): ";
   cin>>loyal;
   //cheak if input enters a failed state
   if (cin.fail())
   {
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"Invalid input. Please enter the correct data type."<<endl;
      return 0;
   }
   //assesses the price based on whether they have a card or not
   if (loyal == 1)
      price = price - ((price * 15)/100);
   cout<<"Final Ticket Price: $"<<fixed<<showpoint<<setprecision(2)<<price<<endl;
   return 0;
}
