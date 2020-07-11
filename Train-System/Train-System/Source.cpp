#include <iostream>
#include<iomanip>
#include <stdlib.h>
using namespace std;
int error(int choice, int start, int end)//recursive function to check if the number is valid or not
{
	if (choice >= start && choice <= end){ return choice; }       //Check if the number is in the border or not
	else { cout << "\n\n\t  ERROR .... You Entered A Wrong Number\n";   cout << "\n     *Please Enter The New Correct Number : "; }    //if the number is wrong print .... ,and Requests new number
	cin >> choice;              //enter his choice
	return error(choice, start, end);
}
void start(char name[], int& choice, bool m) //function for start the program
{
	static int e = 0;
	if (m == 0)   //If the first use for the user
	{
		if (e != 0)
		{
			system("pause");
			system("cls");  //clean
		}
		e++;
		cout << "\n Please Enter Your Name : ";     //Requests from the user enter his name
		cin >> name;                                //store his name in (name)
		cout << "\n\n\n\t\t Hello, " << name << " Welcome To CAIRO Station (^_^) \n\n\n"; //print welcome message
	}
	cout << " -  Please Enter Number 1 If You Want TO Reserve a Ticket \n\n\n";   //Requests from user enter 1 for reserve
	cout << " -  Please Enter Number 2 If You Want TO Cancel Reservation \n\n\n";   //Requests from user enter 2 for cancel
	cout << " -  Please Enter Number 3 If You Want To inquire \n\n\n";        //Requests from user enter 3 for inquire
	cout << " -  Please Enter Number 0 If You Want To End This\n\n\n";          //Requests from user enter 0 for end the program
	cout << " -  Your Choice Is : ";
	cin >> choice;
	choice = error(choice, 0, 3); //check if the number that user are enterd is valid or not
}
void Reserve(int train[10][30], int& car, int& seat) //function for reserve
{
	int choice;
	cout << "\n\n -  Do You Want Normal or Special Ticket ? \n";    //Show him the types of tickets
	cout << "\n -  Please Enter Number 1 For Special Ticket Or Number 2 For Normal Ticket : "; //Requests from user enter 1 For Special Ticket Or Number 2 For Normal Ticket
	cin >> choice;
	choice = error(choice, 1, 2); //check if the number that user are enterd is valid or not
	if (choice == 1)    //if enter 1 for special ticket
	{
		cout << "\n\n\n - The Number Of The Car You Want Is 1 Or 2 : ";   //Show him car's numbers
		cin >> car;
		car = error(car, 1, 2); //check if the number that user are enterd is valid or not
		cout << "\n - Please Enter The Number Of The Seat from 1 To 30 : ";  //Requests from the user enter seat's number 1~30
		bool state1 = 0;
		while (state1 != 1)             //this loop for if the user enter seat and the seat is Reserved
		{
			cin >> seat;
			seat = error(seat, 1, 30);
			if (train[car - 1][seat - 1] == 0) //if the seat isn't reserved
			{
				train[car - 1][seat - 1] = 1;       //makes the seat reserved
				cout << "\n\n   * The Operation Was Performed * \n\n";  // print The Operation Was Performed
				state1 = 1;   //to out from loop (state)
			}
			else   //f the seat is reserved
			{
				cout << "\n\n\n   * The Seat Which You Enter Is booked up *\n\n";  //print that The Seat Which You Enter Is booked up
				cout << " - please Enter The Number Of The New Seat : ";   //Requests new seat
			}
		}
	}
	if (choice == 2)  //if enter 2 for normal ticket
	{
		cout << "\n\n    Available Cars Are From 3 To 10 : ";  //Show him car's numbers
		cin >> car;
		car = error(car, 3, 10);
		cout << "\n\n - Please Enter The Number Of The Seat from 1 To 30 : ";   //Requests from the user enter seat's number 1~30
		bool state = 0;
		while (state != 1)          //this loop for if the user enter seat and the seat is Reserved
		{
			cin >> seat;
			seat = error(seat, 1, 30);
			seat = error(seat, 1, 30);
			if (train[car - 1][seat - 1] == 0)  // if the seat isn't reserve
			{
				train[car - 1][seat - 1] = 1;      //makes the seat reserved
				cout << "\n\n  * The Operation Was Performed *\n\n";  // print that The Operation Was Performed
				state = 1;      //If the number between the border  makes q equal to 1 and out from loop (state)
			}
			else    //if the seat is reserved
			{
				cout << "\n\n   * The Seat You Enter Is Booked up *\n";     //print that the seat is reserved
				cout << " - please Enter The Number Of The New Seat : ";    // request from the user enter new seat
			}
		}
	}
}
bool cancel(int train[10][30])  //function for cancel reserve
{
	int car, seat;
	cout << "\n\n -  Please Enter The Number Of The Car : ";    //request from the user enter car's number
	cin >> car;
	car = error(car, 1, 10);
	cout << "\n -  Please Enter The ID Of The Seat : ";     //request from the user enter seat's number
	cin >> seat;
	seat = error(seat, 1, 30);
	if (train[car - 1][seat - 1] == 0)
	{
		cout << "\n\n * The Seat You Enterd Is Not Reserved *";    // if the seat isn't reserved print that The Seat Is Not Reserved
		return 0;//if seat isn't Reserved return 0 ... In order not to reduce the counter
	}
	else  // if the seat is reserve
	{
		train[car - 1][seat - 1] = 0;   //makes the seat not Reserved
		cout << "\n\n  * The Operation Was Performed And Reservation Canceled *\n";  //print  The Operation Was Performed
		return 1;   //if seat is Reserved return  ... To reduce the counter
	}
}
bool check(int train[10][30])   //function for check on seat if reserve or not  .... and return 0 or 1
{
	int car, seat;
	cout << "\n\n -  Please Enter The Number Of The Car : ";    //request from the user enter car's number
	cin >> car;
	car = error(car, 1, 10);
	cout << "\n -  Please Enter The ID Of The Seat : ";     //request from the user enter seat's number
	cin >> seat;
	seat = error(seat, 1, 30);
	if (train[car - 1][seat - 1] == 0){ return 0; }     //if the seat isn't reserve return 0
	else { return 1; }      //if the seat is reserve return 1
}
char a[14] = { 'S', 'p', 'e', 'c', 'i', 'a', 'l', ' ', 'T', 'i', 'c', 'k', 'e', 't' };
char b[13] = { 'N', 'o', 'r', 'm', 'a', 'l', ' ', 'T', 'i', 'c', 'k', 'e', 't' };
void ticket(char name[], int car, int seat)     // function for print ticket
{
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, car1 = car, seat1 = seat;
	while (name[c1] != '\0')     //this loop counter number of characters
	{
		c1++;               //number of characters
	}
	while (car1)            //this loop counter number of dig.
	{
		car1 /= 10;
		c2++;               //number of dig.
	}
	while (seat1)           //this loop counter number of dig.
	{
		seat1 /= 10;
		c3++;       //number of dig.
	}
	if (car <= 2){ c4 = 14; }
	else { c4 = 13; }

	cout << "\n\n    Here Are Your Ticket  We Wish You Have A Happy Trip \n\n";
	cout << "    ___________________________________________________\n";
	cout << "   |                                                   | \n";
	cout << "   |                  CAIRO STATION                    |\n";
	cout << "   |                                                   | \n";
	cout << "   |  Name : " << name << setw(40 - c1 - c4);
	if (car <= 2){ cout << "    " << a << "  |" << endl; }
	else { cout << "    " << b << "  |" << endl; }
	cout << "   |				                       |\n";
	cout << "   |		Form : Cairo     To : Assiut           |\n";
	cout << "   |                                                   |\n";
	cout << "   |	Car : " << car << setw(43 - c2) << "|\n";
	cout << "   |   Seat : " << seat << setw(43 - c3) << "|\n";
	cout << "   |                 C'lock : 6:30 PM                  |\n";
	cout << "   |                                                   |\n";
	cout << "   |___________________________________________________|\n";
}
void inqure(int train[10][30], int num, int car)
{
	if (num == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			int c = 0;
			for (int j = 0; j < 30; j++)
			{
				if (train[i][j] == 0)
					c++;
			}
			if ((i + 1) == 10)
				cout << " - The Seats Are Available In The Car Number ( " << i + 1 << " ) is " << c << endl << endl;
			else
				cout << " - The Seats Are Available In The Car Number ( " << i + 1 << " )  is " << c << endl << endl;
		}
	}
	else
	{

		int c = 0;
		cout << "\n\n - The Avalibal Seats In Car " << car << " Is : \n\n    ";
		for (int j = 0; j < 30; j++)
		{
			if (train[car - 1][j] == 0)
			{
				cout << j + 1 << " , ";
				if (j == 14)
					cout << "\n\n  ";
				c++;
			}
		}
		if (c == 0)
			cout << "Ther Is Non Avalibal Seats In This Car ";
		cout << endl;

	}
}

void End(bool& m)  //function if the user want to end the program
{
	cout << "\n\n\tGOOD BYE Let Us See You Soon\n\n\t\t Created BY :  Kareem  &  Shehab \n\n\n";
	m = 0;  // the user enter 0
}
int main()
{
	char name[30];  //variable for name
	int choice, car, seat, train[10][30] = { 0 }, how_many;
	int counter = 0;
	bool m = 0;
	while (counter<300)
	{
		if (m == 0)
			start(name, choice, m);   // call the function (start) .... counter = 0 ... the first use for the user
		m = 1;
		switch (choice)
		{
		case 0:     //if choice = 0 .... the user want to end
			End(m);      // call the function (end)
			break;

		case 1:     // if choice = 1 .... the user want to reserve ticket
			cout << "\n\n -  How Many Tickets You Want To Book ? \n\n";     //request from the user enter number of tickets
			cout << "    Number : ";
			cin >> how_many;
			how_many = error(how_many, 1, 300);
			int b;
			if (how_many == 1)  //if the user want one ticket
			{
				Reserve(train, car, seat);  //call function (reserve)
				counter++;
				ticket(name, car, seat);    // call function (ticket)
			}
			else if (how_many > 1)  //if the user want more than one ticket
			{
				cout << "\n\n    If You Want All Tickets To Be Named BY : ( " << name << " ) Please Enter Number 0\n\n";    //ask the user are you want all tickets by one name if yes enter 0
				cout << "    If You Want Each Ticket To Be In A Different Name Please Enter Number 1\n\n";      //if he want the tickets by different names enter 1
				cout << "\n -  Your Choice Is : ";
				cin >> b;
				b = error(b, 0, 1);
				if (!b)     //if he want the tickets by the same name
				{
					while (how_many--)  //this loop continue until how_many become 0
					{
						Reserve(train, car, seat);  //call function (reserve)
						counter++;
						ticket(name, car, seat);    //call function (ticket)
					}
				}
				else    //if he want the tickets by different names
				{
					int i = 1;
					while (how_many--)  //this loop continue until how_many become 0
					{
						cout << "\n    Please Enter The Name Of The Ticket Number " << i << " : "; //request from user enter the first ticket name... sec.....etc
						cin >> name;
						i++;
						Reserve(train, car, seat);  //call function (reserve)
						counter++;
						ticket(name, car, seat);    //call function (ticket)
					}
				}
			}
			cout << "\n\n -  If You Want To Continue Please Enter Number 1 Else Enter Number 0 \n\n";   //ask the user if he want to continue enter 1 and if he end enter 0
			cout << " -  Your Choice Is : ";
			int b1;
			cin >> b1;
			b1 = error(b1, 0, 1);
			if (b1) //if b1 == true
			{
				cout << "\n\n";
				start(name, choice, m);    //call function (start)
			}
			else    //if b1 == false
			{
				End(m);  //call function (end)
			}
			break;

		case 2:     //if the user want to Cancel booking
			cout << "\n\n -  How Many Tickets You Want To Cancel? \n\n";    //ask the user How Many Tickets You Want To Cancel
			cout << "    Number : ";
			cin >> how_many;
			for (int i = 0; i<how_many; i++)
			{
				bool s = cancel(train);  //call function (cancel)
				if (s == 1){ counter--; }    //if s=1 ... show that the seat was booked ... Reservations are canceled
			}
			cout << "\n\n -  If You Want To Continue Please Enter Number 1 Else Enter Number 0 \n\n";   //ask the user if he want to continue enter 1 and if he end enter 0
			cout << " -  Your Choice Is : ";
			int b2;
			cin >> b2;
			b2 = error(b2, 0, 1);
			if (b2)     //if b2 == ture
			{
				cout << "\n\n";
				start(name, choice, m);     //call function (start) ... counter =1 .... it isn't first use for the user
			}
			else       //if b2 == false
			{
				End(m);  //call function (end)
			}
			break;

		case 3:     //if the user want to inquare about thing
			cout << "\n\n  - If You Want To Know A Status Of Specific Seat Please Enter Number 1\n\n";
			cout << "  - If You Want To Know How Many Seats Are Avalibal In The Cars Please Enter Number 2\n\n";
			cout << "  - If You Want To Know How Many Seats Are Avalibal In A Specific Car Please Enter Number 3\n\n";
			cout << "  - To Know The Time Of The Next Trip Please Enter Number 4\n\n";
			cout << "  - Your Choice Is : ";
			int ch;
			cin >> ch;
			cout << endl << endl;
			ch = error(ch, 1, 3);
			if (ch == 1)
			{
				bool fun = check(train);    //call function (check) ... this function is bool ... return 0 or 1
				if (fun == 0){ cout << "\n    The Seat Is Available\n\n\n"; }   //if the function return 0 ... The Seat Is Available
				else { cout << "\n    The Seat Is Reserved\n\n\n"; }        // if the function return 1 ... The Seat Isn't Available
			}
			else if (ch == 2)
			{
				inqure(train, 1, 0);
			}
			else if (ch == 3)
			{
				int car;
				cout << " - Please Enter The Number Of The Car : ";
				cin >> car;
				inqure(train, 2, car);
			}
			else
			{
				cout << "  ** The Next Trip Is At 6:30 PM **\n\n";
			}
			cout << "\n\n -  If You Want To Continue Please Enter Number 1 Else Enter Number 0 \n\n";    //ask the user if he want to continue enter else enter 0
			cout << " -  Your Choice Is : ";
			int b3;
			cin >> b3;
			b3 = error(b3, 0, 1);
			if (b3)     //if b3 == true
			{
				cout << "\n\n";
				start(name, choice, m);     //call (start) ... counter =1 ... it isn't first use from the user
			}
			else    //if b3 == false
			{
				End(m);      //call function (end)
			}
			break;
		}
	}
}