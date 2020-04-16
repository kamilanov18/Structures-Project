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

void createTimetable(TRAIN* trains, int& count, int& maxId)
{
	//Depart time 
	cout << endl;
	cout << "/==============================\\" << endl;
	cout << "Please enter the departure date." << endl;
	cout << "Day: ";  cin >> trains[count].departTime.day;
	cout << "month: "; cin >> trains[count].departTime.month;
	cout << "year: "; cin >> trains[count].departTime.year;
	cout << endl;

	cout << "Enter departure time." << endl;
	cout << "Hours: "; cin >> trains[count].departTime.time.hours;
	cout << "Minutes: "; cin >> trains[count].departTime.time.minutes;
	cout << "\\===============================/" << endl;
	cout << endl;

	//Arrive time
	cout << "/============================\\" << endl;
	cout << "Please enter the arrival date." << endl;
	cout << "Day: ";  cin >> trains[count].arriveTime.day;
	cout << "month: "; cin >> trains[count].arriveTime.month;
	cout << "year: "; cin >> trains[count].arriveTime.year;
	cout << endl;

	cout << "Enter arrival time." << endl;
	cout << "Hours: "; cin >> trains[count].arriveTime.time.hours;
	cout << "Minutes: "; cin >> trains[count].arriveTime.time.minutes;
	cout << "\\============================/" << endl;
	cout << endl;

	//Location data
	cout << "/=================================\\" << endl;
	cout << "Enter departure location: "; cin >> trains[count].departFrom;
	cout << "Enter arrival location: "; cin >> trains[count].arriveTo;
	cout << "Enter number of seats: "; cin >> trains[count].seats;
	cout << "\\=================================/" << endl;

	trains[count].id = generateId(maxId);
	count++;
}

void displayTimetable(TRAIN* trains, int count) // Mislq che q napisah pravilno taka che da izbroi vsichki napisani i dobaveni -> count !
{
	for (int i = 0; i < count; i++)
	{
		//Departure Time
		cout << "/==================\\" << endl;
		cout << "Departure date." << endl;
		cout << "Day: ";  cout << trains[i].departTime.day;
		cout << "month: "; cout << trains[i].departTime.month;
		cout << "year: "; cout << trains[i].departTime.year;
		cout << endl;

		cout << "Departure time." << endl;
		cout << "Hours: "; cout << trains[i].departTime.time.hours;
		cout << "Minutes: "; cout << trains[i].departTime.time.minutes;
		cout << "\\==================/" << endl;
		cout << endl;


		//Arrive Time
		cout << "/==================\\" << endl;
		cout << "Arrival date." << endl;
		cout << "Day: ";  cin >> trains[i].arriveTime.day;
		cout << "month: "; cin >> trains[i].arriveTime.month;
		cout << "year: "; cin >> trains[i].arriveTime.year;
		cout << endl;

		cout << "Arrival time." << endl;
		cout << "Hours: "; cin >> trains[i].arriveTime.time.hours;
		cout << "Minutes: "; cin >> trains[i].arriveTime.time.minutes;
		cout << "\\==================/" << endl;
		cout << endl;


		//Location data
		cout << "/=================================\\" << endl;
		cout << "Enter departure location: "; cin >> trains[i].departFrom;
		cout << "Enter arrival location: "; cin >> trains[i].arriveTo;
		cout << "Enter number of seats: "; cin >> trains[i].seats;
		cout << "\\=================================/" << endl;

	}
}

int findElementById(TRAIN* trains, int count, int searchID)
{
	for (int i = 0; i < count; i++)
	{
		if (searchID == trains[i].id)
		{
			return i;
		}
	}
}

void deleteTimetable(TRAIN* trains, int& count)
{
	int searchID;
	cout << "Enter the ID of the train - You want to delete." << endl;
	cout << "ID: "; cin >> searchID;

	for (int i = findElementById(trains, count, searchID); i < count - 1; i++)
	{
		trains[i] = trains[i + 1];
	}
	count--;
}


bool AdministratorDisplay(TRAIN* trains)
{
	cout << endl;
	cout << "/=========================\\" << endl;
	cout << "Welcome!" << endl;
	cout << "Choose option: " << endl;
	cout << "1. Create Train Timetable." << endl;
	cout << "2. View Timetable." << endl;
	cout << "3. Delete Timetable." << endl;
	cout << "4. Update Timetable." << endl;
	cout << "5. Guest Reservations." << endl;
	cout << "6. Exit." << endl;
	cout << "\\=========================/" << endl;

	int option2;
	cin >> option2;

	switch (option2)
	{
	case 1: // Option 1
		/////
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
		cout << "Please press a valid key!" << endl; // Print "Error"
	}
	return true;
}

void AdministratorLogin(LOGIN* login, TRAIN* trains)
{
	cout << endl;
	cout << "/=============================================================\\" << endl;
	cout << "You need to enter a password to access the administration mode!" << endl;

	string realPass = "parola";

	cout << ("Password: ");
	int p = 0;
	do {
		login->password[p] = _getch();
		if (login->password[p] != '\r') {
			cout << ("*");
		}
		p++;
	} while (login->password[p - 1] != '\r');
	login->password[p - 1] = '\0';
	cout << "\\==============================================================/" << endl;
	if (realPass == login->password)
	{
		AdministratorDisplay(trains); // Argument list !!!!
		CheckSystem = true;
	}
	else
		cout << "Try again!" << endl;
	CheckSystem = false;

}

void MakingReservation()
{
	//Tomorrow
}

void GuestLogin(LOGIN* login) // Guest make reservation registration !!!!!!!!!!!
{
	cout << endl;
	cout << "/==========================================\\" << endl;
	cout << "You should enter your email to use the wifi" << endl;
	cout << "Username: "; getline(cin, login->username);
	cout << "Password: "; getline(cin, login->password);
	cout << "\\==========================================/" << endl;

	if (login->username._Equal == NULL && login->password._Equal == NULL) // Strange !!!!!!!!!!!!!!!!!!
	{
		cout << "Try again!" << endl;
		CheckSystem = false;
	}
	else
		CheckSystem = true;
	MakingReservation(); // Argument list !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

bool GuestDisplay()
{
	cout << endl;
	cout << "/====================\\" << endl;
	cout << "Welcome!" << endl;
	cout << "Choose option: " << endl;
	cout << "1. View Timetable." << endl; //Building
	cout << "2. Make Reservation." << endl;
	cout << "3. Delete Reservation." << endl;
	cout << "4. Exit." << endl; // Ready
	cout << "\\=====================/" << endl;

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
		cout << "Please press a valid key!" << endl; // Print "Error"
	}
	return true;
}

bool MainMenu(LOGIN* login, TRAIN* trains) // Creating our Mainmenu
{
	//
	cout << "/====================\\" << endl;
	cout << "Welcome!" << endl;
	cout << "Choose who are you ?" << endl;
	cout << "1. Administrator" << endl;
	cout << "2. Guest" << endl;
	cout << "3. Exit" << endl;
	cout << "\\====================/" << endl;
	//

	int option = 0; // Declaring variable (option) for our "switch"
	cin >> option; // Entering our option

	switch (option)
	{
	case 1: // Option 1
		AdministratorLogin(login, trains);// Calling our function (AdministratorLogin)
		break; // Stop option 1

	case 2: // Option 2
		GuestLogin(login); // Calling our function (GuestLogin)
		break; // Stop option 2

	case 3: // Option 3
		cout << "Good Bye!" << endl; // Print "Good Bye"
		return false; // Back to menu

	default:
		cout << "Please press a valid key!" << endl; // Print "Error"
	}
	return true;
}


int main()
{
	TRAIN trains[55];

	int count = 0;

	int br = 0;

	int maxId = 0;

	LOGIN administratorlogin[5];
	LOGIN guestlogin[5];

	bool Cycler; // Declaring variable of bool type (for the while cycle)


	do
	{
		Cycler = MainMenu(Promenliva structure);     // Variable (Cycler) take MainMenu value
	} while (Cycler == true);

}