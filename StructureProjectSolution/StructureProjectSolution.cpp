#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "structures.h"
#include "dataFunctions.h"

using namespace std;

bool CheckSystem; // Declaring a variable of bool type(For checking | true / false)

int generateId(int& maxId)
{
	return maxId++;
}

int findElementByIdTRAIN(TRAIN* trains, int count, int searchID)
{
	for (int i = 0; i < count; i++)
	{
		if (searchID == trains[i].id)
		{
			return i;
		}
	}
}

int findElementByIdRESERVATION(RESERVATION* reservations, int count, int searchID)
{
	for (int i = 0; i < count; i++)
	{
		if (searchID == reservations[i].reservedId)
		{
			return i;
		}
	}
}

//|||=========================LOGIC LAYER=========================|||\\

void createTimetable(TRAIN* trains, int& count, int& maxId, TRAIN newData)
{
	newData.id = generateId(maxId);
	trains[count] = newData;
	count++;
}

void updateTimetable(TRAIN* trains, int index, TRAIN newData)
{
	trains[index] = newData;
}

void deleteTimetable(TRAIN* trains, int& count, int searchID)
{
	for (int i = findElementByIdTRAIN(trains, count, searchID); i < count - 1; i++)
	{
		trains[i] = trains[i + 1];
	}
	count--;
}

void makeReservation(RESERVATION* reservations, LOGIN* login, int count, int maxId, RESERVATION newData)
{
	newData.reservedId = generateId(maxId);
	reservations[count] = newData;
	count++;
}

void deleteReservation(RESERVATION* reservations, int& count, int searchID)
{
	for (int i = findElementByIdRESERVATION(reservations, count, searchID); i < count - 1; i++)
	{
		reservations[i] = reservations[i + 1];
	}
	count--;
}

void updateReservation(RESERVATION* reservations, int& index, RESERVATION NewData)
{
	reservations[index] = NewData;
}

//|||=========================LOGIC LAYER=========================|||\\

//|||=========================PRESENTATION LAYER=========================|||\\

void createTimetableMenu(TRAIN* trains, int& count, int& maxId)
{
	TRAIN newData;

	//Depart time 
	cout << endl;
	cout << "/==============================\\" << endl;
	cout << "Please enter the departure date." << endl;
	cout << "Day: ";  cin >> newData.departTime.day;
	cout << "month: "; cin >> newData.departTime.month;
	cout << "year: "; cin >> newData.departTime.year;
	cout << endl;

	cout << "Enter departure time." << endl;
	cout << "Hours: "; cin >> newData.departTime.time.hours;
	cout << "Minutes: "; cin >> newData.departTime.time.minutes;
	cout << "\\===============================/" << endl;
	cout << endl;

	//Arrive time
	cout << "/============================\\" << endl;
	cout << "Please enter the arrival date." << endl;
	cout << "Day: ";  cin >> newData.arriveTime.day;
	cout << "month: "; cin >> newData.arriveTime.month;
	cout << "year: "; cin >> newData.arriveTime.year;
	cout << endl;

	cout << "Enter arrival time." << endl;
	cout << "Hours: "; cin >> newData.arriveTime.time.hours;
	cout << "Minutes: "; cin >> newData.arriveTime.time.minutes;
	cout << "\\============================/" << endl;
	cout << endl;

	//Location data
	cout << "/=================================\\" << endl;
	cout << "Enter departure location: "; cin >> newData.departFrom;
	cout << "Enter arrival location: "; cin >> newData.arriveTo;
	cout << endl;

	cout << "Enter Train class: "; cin >> newData.trainClass;
	cout << "Enter number of seats: "; cin >> newData.seats;
	cout << "\\=================================/" << endl;

	createTimetable(trains, count, maxId, newData);
}

void displayTimetable(TRAIN* trains, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << endl;
		cout << "|||=============!!!=============|||" << endl;
		//Departure Time
		cout << "/========================\\" << endl;
		cout << "Departure date: " << trains[i].departTime.day << "." << trains[i].departTime.month << "." << trains[i].departTime.year << endl;
		cout << "Departure time: " << trains[i].departTime.time.hours << ":" << trains[i].departTime.time.minutes << endl;
		cout << "\\========================/" << endl;
		cout << endl;


		//Arrive Time
		cout << "/======================\\" << endl;
		cout << "Arrival date: " << trains[i].arriveTime.day << "." << trains[i].arriveTime.month << "." << trains[i].arriveTime.year << endl;
		cout << "Arrival time: " << trains[i].arriveTime.time.hours << ":" << trains[i].arriveTime.time.minutes << endl;
		cout << "\\======================/" << endl;
		cout << endl;


		//Location data
		cout << "/============================\\" << endl;
		cout << "Departure location: "; cout << trains[i].departFrom << endl;
		cout << "Arrival location: "; cout << trains[i].arriveTo << endl;
		cout << "Train class: "; cout << trains[i].trainClass << endl;
		cout << "Number of seats: "; cout << trains[i].seats << endl;
		cout << "\\============================/" << endl;
		cout << endl;


		//Train ID
		cout << "/==================\\" << endl;
		cout << "Train ID: "; cout << trains[i].id << endl;
		cout << "\\==================/" << endl;
		cout << "|||=============!!!=============|||" << endl;
		cout << endl;
	}
}

void deleteTimetableMenu(TRAIN* trains, int& count)
{
	int searchID;
	cout << "Enter the ID of the train you want to delete: ";  cin >> searchID;
	deleteTimetable(trains, count, searchID);
}

void updateTimetableMenu(TRAIN* trains, int& count) // Change Retry (function) with Bool Variable !!!!
{
	TRAIN newData;

	int searchID;
	int field,field2;

	cout << "Enter the ID of the train: "; cin >> searchID;
	
	int index = findElementByIdTRAIN(trains, count, searchID);
	newData = trains[index];

Retry1:
	cout << "/====== Train Update Timetable ======\\" << endl;
	cout << "Choose what you want to update: " << endl;
	cout << "1. Departure Time." << endl;
	cout << "2. Arrival Time." << endl;
	cout << "3. Location Data" << endl;
	cout << "4. Exit" << endl;
	cout << "\\====================================/" << endl;
	cin >> field;
	
	switch (field)
	{
		case 1:
			Retry2:
			cout << "Choose what you want to update: " << endl;
			cout << "1. Day" << endl;
			cout << "2. Month" << endl;
			cout << "3. Year" << endl;
			cout << "4. Hours" << endl;
			cout << "5. Minutes" << endl;
			cout << "6. Exit" << endl;
			cin >> field2;
			switch (field2)
			{
				case 1:
					cout << "Enter the new day: "; cin >> newData.departTime.day;
					break;

				case 2:
					cout << "Enter the new month: "; cin >> newData.departTime.month;
					break;

				case 3:
					cout << "Enter the new year: "; cin >> newData.departTime.year;
					break;

				case 4:
					cout << "Enter the new hours: "; cin >> newData.departTime.time.hours;
					break;

				case 5:
					cout << "Enter the new minutes: "; cin >> newData.departTime.time.minutes;
					break;

				case 6:
					cout << "Good Bye!" << endl;

				default:
					cout << "Incorrect Input, Please Try Again!";
					goto Retry2;
					break;
			}
			break;

		case 2:
			Retry3:
			cout << "Choose what you want to update: " << endl;
			cout << "1. Day" << endl;
			cout << "2. Month" << endl;
			cout << "3. Year" << endl;
			cout << "4. Hours" << endl;
			cout << "5. Minutes" << endl;
			cout << "6. Exit" << endl;
			cin >> field2;
			switch (field2)
			{
				case 1:
					cout << "Enter the new day: "; cin >> newData.arriveTime.day;
					break;

				case 2:
					cout << "Enter the new month: "; cin >> newData.arriveTime.month;
					break;

				case 3:
					cout << "Enter the new year: "; cin >> newData.arriveTime.year;
					break;

				case 4:
					cout << "Enter the new hours: "; cin >> newData.arriveTime.time.hours;
					break;

				case 5:
					cout << "Enter the new minutes: "; cin >> newData.arriveTime.time.minutes;
					break;

				case 6:
					cout << "Good Bye!" << endl;

				default:
					cout << "Incorrect Input, Please Try Again!";
					goto Retry3;
					break;
			}
			break;

		case 3:
			Retry4:
			cout << "Choose what you want to update: " << endl;
			cout << "1. Departure Location." << endl;
			cout << "2. Arrival Location" << endl;
			cout << "3. Number of seats" << endl;
			cout << "4.Exit" << endl;
			cin >> field2;
			switch (field2)
			{
				case 1:
					cout << "Enter the new departure location: "; cin >> newData.departFrom;
					break;

				case 2:
					cout << "Enter the new arrival location: "; cin >> newData.arriveTo;
					break;

				case 3:
					cout << "Enter the newnumber of seats: "; cin >> newData.seats;

				case 4:
					cout << "Good Bye!" << endl;

				default:
					cout << "Incorrect Input, Please Try Again!";
					goto Retry4;
					break;
			}
			break;
	
		case 4:
			cout << "Good Bye!" << endl;
	
		default:
			cout << "Incorrect Input, Please Try Again!";
			goto Retry1;
			break;
	}
	
	updateTimetable(trains, index, newData);

}

void makeReservationMenu(RESERVATION* reservations, LOGIN* login, int count, int maxId)
{
	RESERVATION newData;

	cout << "/====== RESERVATION DEPARTMENT ======\\" << endl;
	cout << "Hello "; cout << login[count].username << "!" << endl;
	cout << "Enter the Train ID: "; cin >> newData.reservedTrainID;
	cout << "Enter the number of seats: "; cin >> newData.reservedSeats;
	cout << "\\====================================/" << endl;
	cout << endl;

	makeReservation(reservations, login, count, maxId, newData);
}

void deleteReservationMenu(RESERVATION* reservations, int& count)
{
	int searchID;
	cout << "Enter the ID of the reservation you want to delete: "; cin >> searchID;
	deleteReservation(reservations, count, searchID);
}

void updateReservationMenu(RESERVATION* reservations, int& count)
{
	RESERVATION NewData;

	int searchID;
	cout << "Enter the ID of the train you want to update: "; cin >> searchID;

	int index = findElementByIdRESERVATION(reservations, count, searchID);
	NewData = reservations[index];

	cout << "/===========================\\" << endl;
	cout << "Choose what you want to fix: " << endl;
	cout << "1. Train ID." << endl;
	cout << "2. Number of seats." << endl;
	cout << "3. Exit." << endl;
	cout << "\\===========================/" << endl;
Retry1:
	int option4;
	cin >> option4;

	switch (option4)
	{
	case 1:
		cout << "Train ID: "; cin >> NewData.reservedTrainID;
		break;

	case 2:
		cout << "Number of seats: "; cin >> NewData.reservedSeats;
		break;

	case 3:
		cout << "Good Bye!" << endl;

	default:
	{
		cout << "Please press a valid key!" << endl;
		goto Retry1;
		break;
	}
	}

	updateReservation(reservations, index, NewData);
}

//|||=========================PRESENTATION LAYER=========================|||\\

void deleteOrFixReservation(RESERVATION* reservations, int& count)
{

	int searchID;
	cout << "/=====================================\\" << endl;
	cout << "Enter the ID of your reservation: " << endl; cin >> searchID;
	cout << "1. Delete my reservation." << endl;
	cout << "2. Fix my reservation." << endl;
	cout << "3. Exit." << endl;
	cout << "\\=====================================/" << endl;

	int option3;
	cin >> option3;
	Retry:
	switch (option3)
	{
	case 1:
		deleteReservationMenu(reservations, count);
		break;

	case 2:
		updateReservationMenu(reservations, count);
		break;

	case 3:
		cout << "Good Bye!" << endl;

	default:
		{
			cout << "Please press a valid key!" << endl;
			goto Retry;
			break;
		}
	}

}

void GuestLogin(LOGIN* login, RESERVATION* reservations, int& count, int& maxId) // Guest make reservation registration !!!!!!!!!!!
{
	cout << endl;
	cout << "/=========================\\" << endl;
	cout << "Make an account!" << endl;
	cout << "Username: "; getline(cin, login[count].username);
	cout << "Password: "; getline(cin, login[count].password);
	cout << "\\=========================/" << endl;
	count++;


	//if (login->username._Equal == NULL && login->password._Equal == NULL) // Strange !!!!!!!!!!!!!!!!!!
	//{
	//	cout << "Try again!" << endl;
	//	CheckSystem = false;
	//}
	//else
	//	makingReservation(reservations, count, maxId); // Argument list !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//CheckSystem = true;
}

void displayReservations(RESERVATION* reservations, LOGIN* login, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "/=========================\\" << endl;
		cout << "Reservator Name: "; cout << login[i].username << endl;
		cout << "Train ID: "; cout << reservations[i].reservedTrainID << endl;
		cout << "Train Seats: "; cout << reservations[i].reservedSeats << endl;
		cout << "|-----------------------------|" << endl;
		cout << "Reservator Password: "; cout << login[i].password << endl;
		cout << "|-----------------------------|" << endl;
		cout << "\\=========================/" << endl;
	}
}

bool AdministratorMenu(TRAIN* trains, int& count, int& maxId, RESERVATION* reservations, LOGIN* login)
{
	cout << endl;
	cout << "/=========================\\" << endl;
	cout << "Welcome!" << endl;
	cout << "Choose option: " << endl;
	cout << "1. Create Train Timetable." << endl;
	cout << "2. View Timetable." << endl;
	cout << "3. Delete Timetable." << endl;
	cout << "4. Update Timetable." << endl; // In progress
	cout << "5. Guest Reservations." << endl;
	cout << "6. Exit." << endl;
	cout << "\\=========================/" << endl;

	int option2;
	cin >> option2;

	switch (option2)
	{
	case 1:
		createTimetableMenu(trains, count, maxId);
		break; 

	case 2:
		displayTimetable(trains, count);
		break;

	case 3:
		deleteTimetableMenu(trains, count);
		break;

	case 4:
		updateTimetableMenu(trains, count);
		break;

	case 5:
		displayReservations(reservations, login, count);
		break;

	case 6: 
		cout << "Good Bye!" << endl; 
		return false; 

	default:
		cout << "Please press a valid key!" << endl; 
	}
	return true;
}

void AdministratorLogin(LOGIN* login, TRAIN* trains, int& count, int& maxId, RESERVATION* reservations)
{
	cout << endl;
	cout << "/=============================================================\\" << endl;
	cout << "You need to enter a password to access the administration mode!" << endl;

	string realPass = "parola";

	cout << ("Password: ");
	int p = 0;
	do {
		login->password[p] = _getch();
		if (login->password[p] != '\r') 
		{
			cout << ("*");
		}
		p++;
	} while (login->password[p - 1] != '\r');
	login->password[p - 1] = '\0';
	cout << "\\==============================================================/" << endl;
	if (realPass == login->password)
	{
		AdministratorMenu(trains, count, maxId, reservations,login);
		CheckSystem = true;
	}
	else
		cout << "Try again!" << endl;
	CheckSystem = false;

}

bool GuestMenu(TRAIN * trains, int& count, RESERVATION* reservations, LOGIN* login, int& maxId)
{
	cout << endl;
	cout << "/====================\\" << endl;
	cout << "Welcome!" << endl;
	cout << "Choose option: " << endl;
	cout << "1. View Timetable." << endl; //Building
	cout << "2. Make Reservation." << endl;
	cout << "3. Update/Delete Reservation." << endl;
	cout << "4. Exit." << endl; // Ready
	cout << "\\=====================/" << endl;

	int option3;
	cin >> option3;

	switch (option3)
	{
	case 1:
		displayTimetable(trains, count);
		break;

	case 2:
		makeReservationMenu(reservations, login, count, maxId);
		break;

	case 3:
		deleteOrFixReservation(reservations, count);
		break;

	case 4: 
		cout << "Good Bye!" << endl; 
		return false;

	default:
		cout << "Please press a valid key!" << endl; 
	}
	return true;
}

bool MainMenu(LOGIN* login, TRAIN* trains, int count, int maxId,RESERVATION* reservations) 
{
	//
	cout << "/====================\\" << endl;
	cout << "Welcome!" << endl;
	cout << "Choose who you are?" << endl;
	cout << "1. Administrator" << endl;
	cout << "2. Guest" << endl;
	cout << "3. Exit" << endl;
	cout << "\\====================/" << endl;
	//

	int option = 0; 
	cin >> option; 

	switch (option)
	{
	case 1:
		AdministratorLogin(login, trains, count, maxId, reservations);
		break; 

	case 2: 
		GuestLogin(login,reservations,count,maxId);
		break; 

	case 3: 
		cout << "Good Bye!" << endl; 
		return false; 

	default:
		cout << "Please press a valid key!" << endl; 
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

	RESERVATION reservations[10];

	bool Cycler; // Declaring variable of bool type (for the while cycle)

	countElements(count);

	loadData(trains, count);

	createTimetableMenu(trains, count, maxId);

	saveData(trains, count);

	displayTimetable(trains, count);

	AdministratorMenu(trains, count, maxId,reservations,administratorlogin); 

	/*do
	{
		Cycler = MainMenu(Promenliva structure);     // Variable (Cycler) take MainMenu valuee
	} while (Cycler == true);
	*/
}