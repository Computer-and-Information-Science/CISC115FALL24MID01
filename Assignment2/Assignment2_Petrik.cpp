#include <iostream>
#include <iomanip>
using namespace std;
int main () { 
    //Variables needed to form Library receipt
    string bookTitle;
    string author;
    double price = 0;
    char check;
    cout<<"Enter book title: ";
    //Gets the first letter of the title
    cin.get(check);
    //puts back the first letter of the title
    cin.putback(check);
    //Checks to see if the first letter of the title is there
    cin.peek();
    //removes the first letter
    cin.ignore(1, '\n');
    //stores the title in bookTitle
    getline(cin,bookTitle);
    cout<<"Enter author's name: ";
    //stores the name in author
    getline(cin,author);
    cout<<"Enter book price: $";
    //stores the price of the book in price
    cin>>price;
    //checks to see if the price was inputted properly and asks user to fix the price if necessary
    if (price <= 0)
        cin.clear();
    if (price <= 0)
        cin.ignore(100,'\n');
    if (price <= 0)
        cout<<"Invalid input. Please enter the correct data type.";
    if (price <= 0)
        cin>>price;
    //creates the heading of the receipt
    cout<<'\n'<<setw(19)<<setfill('-')<<" Book Details "<<setw(5)<<setfill('-')<<""<<endl;
    //fills in the information that the user provided about the book
    cout<<"Title:         "<<bookTitle<<endl;
    cout<<"Author:        "<<author<<endl;
    cout<<"Price:         $"<<fixed<<showpoint<<setprecision(2)<<price<<endl;
    return 0;
}
