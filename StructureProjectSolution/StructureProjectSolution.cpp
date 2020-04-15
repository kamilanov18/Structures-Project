#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

bool CheckSystem; // Declaring a variable of bool type(For checking | true / false)

struct TIME {
	int minutes;
	int hours;
};

struct DATE {
	int day;
	int month;
	int year;
	TIME time;
};

struct TRAIN {
	DATE departTime;
	DATE arriveTime;
	int id;
	string departFrom;
	string arriveTo;
	int seats;
};

struct LOGIN
{
	string username;
	string password;
};

int generateId(int& maxId)
{
	return maxId++;
}

void createTimetable(TRAIN* trains,int& count, int& maxId)
{
	//Depart time 
	cout << "/==============================\\" << endl;
	cout << "Please enter the departure date:"<<endl; 
	cout << "Day: ";  cin >> trains[count].departTime.day;
	cout << "month: "; cin >> trains[count].departTime.month;
	cout << "year: "; cin >> trains[count].departTime.year;
	cout << "Enter departure time:" << endl;
	cout << "Hours: "; cin >> trains[count].departTime.time.hours;
	cout << "Minutes: "; cin >> trains[count].departTime.time.minutes;
	cout << endl;

	//Arrive time
	cout << "Please enter the arrival date: "<<endl;
	cout << "Day: ";  cin >> trains[count].arriveTime.day;
	cout << "month: "; cin >> trains[count].arriveTime.month;
	cout << "year: "; cin >> trains[count].arriveTime.year;
	cout << "Enter arrival time:" << endl;
	cout << "Hours: "; cin >> trains[count].arriveTime.time.hours;
	cout << "Minutes: "; cin >> trains[count].arriveTime.time.minutes;
	cout << endl;

	//Location data
	cout << "Enter departure location: "; cin >> trains[count].departFrom;
	cout << "Enter arrival location: "; cin >> trains[count].arriveTo;
	cout << endl;

	cout << "Enter number of seats: "; cin >> trains[count].seats;
	cout << "\\================================/" << endl;
	trains[count].id = generateId(maxId);
	count++;
}

void displayTimetable(TRAIN* trains, int count)
{

}


bool AdministratorDisplay()
{
	cout << "Welcome!" << endl;
	cout << "Choose option: " << endl;
	cout << "1. Create Train Timetable." << endl;
	cout << "2. View Timetable." << endl;
	cout << "3. Delete Timetable." << endl;
	cout << "4. Update Timetable." << endl;
	cout << "5. Guest Reservations." << endl;
	cout << "6. Exit." << endl;

	int option2;
	cin >> option2;

	switch (option2)
	{
	case 1: // Option 1
		// Calling our function ()
		break; // Stop option 1

	case 2: 
		// Calling our function ()
		break;

	case 3:
		// Calling our function ()
		break;

	case 4:
		// Calling our function ()
		break;

	case 5:
		// Calling our function ()
		break;

	case 6: // Option 3
		cout << "Good Bye!" << endl; // Print "Good Bye"
		return false; // Back to menu

	default:
		cout << "Error" << endl; // Print "Error"
	}
	return true;
}

void AdministratorLogin(LOGIN *login)
{

	cout << "You need to enter a password to access the administration mode" << endl;

	string realPass = "parola";

	cout << ("password:\n");
	int p = 0;
	do {
		login->password[p] = _getch();
		if (login->password[p] != '\r') {
			cout << ("*");
		}
		p++;
	} while (login->password[p - 1] != '\r');
	login->password[p - 1] = '\0';
	if (realPass == login->password)
	{
		AdministratorDisplay;
	}
	else
		cout << "Try again" << endl;

}

bool GuestDisplay()
{
	cout << "Welcome!" << endl;
	cout << "Choose option: " << endl;
	cout << "1. View Timetable." << endl;
	cout << "2. Make Reservation." << endl;
	cout << "3. Delete Reservation." << endl;
	cout << "4. Exit." << endl;

	int option3;
	cin >> option3;

	switch (option3)
	{
	case 1: 
		// Calling our function ()
		break; 

	case 2:
		// Calling our function ()
		break;

	case 3:
		// Calling our function ()
		break;

	case 4: // Option 3
		cout << "Good Bye!" << endl; // Print "Good Bye"
		return false; 

	default:
		cout << "Error" << endl; // Print "Error"
	}
	return true;
}

void GuestLogin(LOGIN *login)
{
	cout << "You should enter your email to use the wifi" << endl;
	getline(cin, login->username);
	getline(cin, login->password);
}

bool MainMenu(LOGIN *login) // Creating our Mainmenu
{
	//
	cout << "====================" << endl;
	cout << "    Welcome!" << endl;
	cout << "Choose who are you ?" << endl;
	cout << "1. Administrator" << endl;
	cout << "2. Guest" << endl;
	cout << "3. Exit" << endl;
	cout << "====================" << endl;
	//

	int option = 0; // Declaring variable (option) for our "switch"
	cin >> option; // Entering our option

	switch (option)
	{
	case 1: // Option 1
		AdministratorLogin(login);// Calling our function (AdministratorLogin)
		break; // Stop option 1

	case 2: // Option 2
		GuestLogin(login); // Calling our function (GuestLogin)
		break; // Stop option 2

	case 3: // Option 3
		cout << "Good Bye!" << endl; // Print "Good Bye"
		return false; // Back to menu

	default:
		cout << "Error" << endl; // Print "Error"
	}
	return true;
}


int main()
{
	TRAIN trains[55];
	int count = 0;
	int maxId = 0;
	LOGIN administratorlogin[5];
	LOGIN guestlogin[5];
	
	bool Cycler; // Declaring variable of bool type (for the while cycle)

	//
	do
	{
		Cycler = MainMenu(Promenliva structure);     // Variable (Cycler) take MainMenu value
	} while (Cycler == true);
	//
	
	
}