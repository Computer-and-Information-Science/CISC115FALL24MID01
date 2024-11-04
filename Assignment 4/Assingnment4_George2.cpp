#include<iostream>
using namespace std;
int main()
{
	int rows;
	int spaces;
	int display;
	int num1;
	int number;
	cout<<"Please enter the number of rows: ";
	cin>>number;
	num1=number;
	rows=1;
	
	//initiating my variables and asking for number of rows
	do
	{
		spaces=1;
		do
		{
			cout<<"    ";
			spaces++;
		}

		while(spaces<=num1);
		num1--;
		display=1;
		do
		{
			cout<<"       "<<rows;
			      
			display++
            //displaying the row numbers
;
		}

		while(display<=rows);
		cout<<endl;
		rows++;
		//starting new line
	}
	while(rows<=number);
}