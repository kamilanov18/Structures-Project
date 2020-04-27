#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "structures.h"
#include "dataFunctions.h"


using namespace std;

//|||=========================LOGIC LAYER=========================|||\\

int len(char a[100])
{
	int i = 0;
	while (a[i] != NULL)
	{
		i++;
	}
	return i;
}

void createNewPass(string& pass,string newPass)
{
	pass = newPass;
}

int generateId(int& maxId)
{
	maxId++;
	return maxId;
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

void createTimetable(TRAIN* trains, int& count, int& maxId, TRAIN newData)
{
	newData.id = generateId(maxId);
	trains[count] = newData;
	count++;
	saveTrainData(trains, count);
	WriteHTML(trains, count);
}

void updateTimetable(TRAIN* trains, int index, TRAIN newData,int count)
{
	trains[index] = newData;
	saveTrainData(trains, count);
	WriteHTML(trains, count);
}

void deleteTimetable(TRAIN* trains, int& count, int searchID)
{
	for (int i = findElementByIdTRAIN(trains, count, searchID); i < count - 1; i++)
	{
		trains[i] = trains[i + 1];
	}
	count--;
	saveTrainData(trains, count);
	WriteHTML(trains, count);
}

void deleteReservation(RESERVATION* reservations, int& count, int searchID)
{
	for (int i = findElementByIdRESERVATION(reservations, count, searchID); i < count - 1; i++)
	{
		reservations[i] = reservations[i + 1];
	}
	count--;
	saveReservationData(reservations, count);
}

void updateReservation(RESERVATION* reservations, int& index, RESERVATION NewData, int count)
{
	reservations[index] = NewData;
	saveReservationData(reservations, count);
}

void checkSystemFunction(bool CheckSystem)
{
	if (CheckSystem == false)
	{
		cout << endl;
		cout << "/===============================\\" << endl;
		cout << "Incorrect Input " << endl; 
		cout << "Go back and enter numbers again! " << endl; 
		cout << "\\===============================/" << endl;
		cout << endl;
		return; 
	}
}

//|||=========================TrainTimetable=========================|||\\

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
	system("web.html");
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
	int field, field2;

	cout << "Enter the ID of the train: "; cin >> searchID;

	int index = findElementByIdTRAIN(trains, count, searchID);
	newData = trains[index];

Retry1:
	cout << endl;
	cout << "/====== Train Update Timetable ======\\" << endl;
	cout << "Choose what you want to update: " << endl;
	cout << "1. Departure Time." << endl;
	cout << "2. Arrival Time." << endl;
	cout << "3. Location Data" << endl;
	cout << "4. Exit" << endl;
	cout << "\\====================================/" << endl;
	cout << "Your choice: "; cin >> field;

	switch (field)
	{
	case 1:
	Retry2:
		cout << endl;
		cout << "Choose what you want to update: " << endl;
		cout << "1. Day" << endl;
		cout << "2. Month" << endl;
		cout << "3. Year" << endl;
		cout << "4. Hours" << endl;
		cout << "5. Minutes" << endl;
		cout << "6. Exit" << endl;

		cout << "Your choice: "; cin >> field2;
		switch (field2)
		{
		case 1:
		retryDDay:
			cout << "Enter the new day: "; cin >> newData.departTime.day;
			if (newData.departTime.day > 31 or newData.departTime.day < 0)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retryDDay;
			}
			break;

		case 2:
		retryDMonth:
			cout << "Enter the new month: "; cin >> newData.departTime.month;
			if (newData.departTime.month > 12 or newData.departTime.month < 0)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retryDMonth;
			}
			break;

		case 3:
		retryDYear:
			cout << "Enter the new year: "; cin >> newData.departTime.year;
			if (newData.departTime.year < 2020)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retryDYear;
			}
			break;

		case 4:
		retryDHours:
			cout << "Enter the new hours: "; cin >> newData.departTime.time.hours;
			if (newData.departTime.time.hours > 24 or newData.departTime.time.hours < 0)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retryDHours;
			}
			break;

		case 5:
		retryDMinutes:
			cout << "Enter the new minutes: "; cin >> newData.departTime.time.minutes;
			if (newData.departTime.time.minutes > 60 or newData.departTime.time.minutes < 0)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retryDMinutes;
			}
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
		cout << endl;
		cout << "Choose what you want to update: " << endl;
		cout << "1. Day" << endl;
		cout << "2. Month" << endl;
		cout << "3. Year" << endl;
		cout << "4. Hours" << endl;
		cout << "5. Minutes" << endl;
		cout << "6. Exit" << endl;

		cout << "Your choice: "; cin >> field2;
		switch (field2)
		{
		case 1:
		retryADay:
			cout << "Enter the new day: "; cin >> newData.arriveTime.day;
			if (newData.arriveTime.day > 31 or newData.arriveTime.day < 0)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retryADay;
			}
			break;

		case 2:
		retryAMonth:
			cout << "Enter the new month: "; cin >> newData.arriveTime.month;
			if (newData.arriveTime.month > 12 or newData.arriveTime.month < 0)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retryAMonth;
			}
			break;

		case 3:
		retryAYear:
			cout << "Enter the new year: "; cin >> newData.arriveTime.year;
			if (newData.arriveTime.year < 2020)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retryAYear;
			}
			break;

		case 4:
		retryAHours:
			cout << "Enter the new hours: "; cin >> newData.arriveTime.time.hours;
			if (newData.arriveTime.time.hours > 24 or newData.arriveTime.time.hours < 0)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retryAHours;
			}
			break;

		case 5:
		retryAMinutes:
			cout << "Enter the new minutes: "; cin >> newData.arriveTime.time.minutes;
			if (newData.arriveTime.time.minutes > 60 or newData.arriveTime.time.minutes < 0)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retryAMinutes;
			}
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
		cout << endl;
		cout << "Choose what you want to update: " << endl;
		cout << "1. Departure Location." << endl;
		cout << "2. Arrival Location" << endl;
		cout << "3. Number of seats" << endl;
		cout << "4.Exit" << endl;

		cout << "Your choice: "; cin >> field2;
		switch (field2)
		{
		case 1:
			cout << "Enter the new departure location: "; cin >> newData.departFrom;
			break;

		case 2:
			cout << "Enter the new arrival location: "; cin >> newData.arriveTo;
			break;

		case 3:
		retrySeats:
			cout << "Enter the newnumber of seats: "; cin >> newData.seats;
			if (newData.seats < 0)
			{
				cout << "Incorrect Input, please enter a legal value!" << endl;
				goto retrySeats;
			}

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

	updateTimetable(trains, index, newData,count);

}

void createTimetableMenu(TRAIN* trains, int& count, int& maxId)
{
	TRAIN newData;

	//Depart time 
	cout << endl;
	cout << "/==============================\\" << endl;
	cout << "Please enter the departure date." << endl;

	retryDDay: 
	cout << "Day: ";  cin >> newData.departTime.day; 
	if (newData.departTime.day > 31 or newData.departTime.day < 0) 
	{
		cout << "Incorrect Input, please enter a legal value!" << endl; 
		goto retryDDay;
	}

	retryDMonth: 
	cout << "month: "; cin >> newData.departTime.month; 
	if (newData.departTime.month > 12 or newData.departTime.month < 0) 
	{ 
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryDMonth; 
	}

	retryDYear:
	cout << "year: "; cin >> newData.departTime.year;
	if (newData.departTime.year<2020)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryDYear;
	}
	cout << endl;

	cout << "Enter departure time." << endl;
	retryDHours:
	cout << "Hours: "; cin >> newData.departTime.time.hours;
	if (newData.departTime.time.hours > 24 or newData.departTime.time.hours < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryDHours;
	}

	retryDMinutes:
	cout << "Minutes: "; cin >> newData.departTime.time.minutes;
	if (newData.departTime.time.minutes > 60 or newData.departTime.time.minutes < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryDMinutes;
	}
	cout << "\\===============================/" << endl;
	cout << endl;

	//Arrive time
	cout << "/============================\\" << endl;
	cout << "Please enter the arrival date." << endl;
	retryADay:
	cout << "Day: ";  cin >> newData.arriveTime.day;
	if (newData.arriveTime.day > 31 or newData.arriveTime.day < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryADay;
	}

	retryAMonth:
	cout << "month: "; cin >> newData.arriveTime.month;
	if (newData.arriveTime.month > 12 or newData.arriveTime.month < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryAMonth;
	}

	retryAYear:
	cout << "year: "; cin >> newData.arriveTime.year;
	if (newData.arriveTime.year < 2020)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryAYear;
	}
	cout << endl;

	
	cout << "Enter arrival time." << endl;
	retryAHours:
	cout << "Hours: "; cin >> newData.arriveTime.time.hours;
	if (newData.arriveTime.time.hours > 24 or newData.arriveTime.time.hours < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryAHours;
	}

	retryAMinutes:
	cout << "Minutes: "; cin >> newData.arriveTime.time.minutes;
	if (newData.arriveTime.time.minutes > 60 or newData.arriveTime.time.minutes < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryAMinutes;
	}
	cout << "\\============================/" << endl;
	cout << endl;

	//Location data
	cout << "/=================================\\" << endl;
	retryDepart:
	cout << "Enter departure location: "; cin >> newData.departFrom;
	cout << "Enter arrival location: "; cin >> newData.arriveTo;
	retrySeats:
	cout << "Enter number of seats: "; cin >> newData.seats;
	if (newData.seats < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retrySeats;
	}
	cout << "\\=================================/" << endl;
	cout << endl;

	createTimetable(trains, count, maxId, newData);
}

//|||=========================RESERVATION=========================|||\\

void displayReservations(RESERVATION* reservations, int count,bool isAdmin,string username)
{
	bool hasReservations=false;
	if (isAdmin)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "/=========================\\" << endl;
			cout << "Reservator Name: "; cout << reservations[i].username << endl;
			cout << "Train ID: "; cout << reservations[i].reservedTrainID << endl;
			cout << "Train Seats: "; cout << reservations[i].reservedSeats << endl;
			cout << "Reservation ID: "; cout << reservations[i].reservedId << endl;
			cout << "\\=========================/" << endl;
		}
	}
	else
	{
		cout << endl;
		cout << "/=========YOUR RESERVATIONS=========\\" << endl;
		cout << endl;
		for (int i = 0; i < count; i++)
		{
			if (username == reservations[i].username)
			{
				cout << "/=========================\\" << endl;
				cout << "Reservator Name: "; cout << reservations[i].username << endl;
				cout << "Train ID: "; cout << reservations[i].reservedTrainID << endl;
				cout << "Train Seats: "; cout << reservations[i].reservedSeats << endl;
				cout << "Reservation ID: "; cout << reservations[i].reservedId << endl;
				cout << "\\=========================/" << endl;
				cout << endl;
				hasReservations=true;
			}
		}
		if (hasReservations == false)
			cout << "There are no reservations unser this username!" << endl;
		cout << endl;
		cout << "\\===================================/" << endl;
		cout << endl;
	}
}

void updateReservationMenu(RESERVATION* reservations, int& count, int searchID)
{
	RESERVATION NewData;

	int index = findElementByIdRESERVATION(reservations, count, searchID);
	NewData = reservations[index];

	cout << endl;
	cout << "/===========================\\" << endl;
	cout << "Choose what you want to fix: " << endl;
	cout << "1. Train ID." << endl;
	cout << "2. Number of seats." << endl;
	cout << "3. Exit." << endl;
	cout << "\\===========================/" << endl;

	int option4;
	cout << "Your choice: "; cin >> option4;

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
		break;
	}

	}

	updateReservation(reservations, index, NewData,count); //==LOGIC LAYER==
}

void deleteReservationMenu(RESERVATION* reservations, int& count, int searchID)
{
	deleteReservation(reservations, count, searchID);

}

void deleteOrFixReservation(RESERVATION* reservations, int& count, string username)
{

	int searchID;

	cout << endl;
	cout << "/=====================================\\" << endl;
	cout << "Hello, "; cout << username << "!" << endl;
	cout << "Enter the ID of your reservation: "; cin >> searchID;
	cout << "1. Delete my reservation." << endl;
	cout << "2. Fix my reservation." << endl;
	cout << "3. Exit." << endl;
	cout << "\\=====================================/" << endl;


	int option3;
	cout << "Your choice: ";  cin >> option3;

	switch (option3)
	{
	case 1:
		deleteReservationMenu(reservations, count, searchID);
		break;

	case 2:
		updateReservationMenu(reservations, count, searchID);
		break;

	case 3:
		cout << "Good Bye!" << endl;

	default:
	{
		cout << "Please press a valid key!" << endl;
		break;
	}
	}

}

void makeReservation(RESERVATION* reservations, int& count, int& maxId, RESERVATION newData,string username)
{
	newData.username = username;
	newData.reservedId = generateId(maxId);
	reservations[count] = newData;
	count++;
	saveReservationData(reservations, count);
	
}

void makeReservationMenu(RESERVATION* reservations, int& count, int& maxId, string username)
{
	RESERVATION newData;
	cout << endl;
	cout << "/================= RESERVATION DEPARTMENT =================\\" << endl;
	cout << "Hello, "; cout << username << "! Please enter the ID of the train" << endl; 
	cout << "and the number of seats you want to reserve!" << endl;
	cout << "Enter the Train ID: "; cin >> newData.reservedTrainID;
	cout << "Enter the number of seats: "; cin >> newData.reservedSeats;
	cout << "\\==========================================================/" << endl;
	cout << endl;
	makeReservation(reservations, count, maxId, newData,username);
}

//|||=========================GUEST=========================|||\\

bool GuestMenu(TRAIN* trains, int& count, RESERVATION* reservations, int& maxId,string username) //Guest 2
{
	cout << endl;
	cout << "/==========================\\" << endl;
	cout << "Welcome, "<<username<< "!" << endl;
	cout << "Choose option: " << endl;
	cout << "1. View Timetable." << endl; 
	cout << "2. Make Reservation." << endl;
	cout << "3. Update/Delete Reservation." << endl;
	cout << "4. View Your Reservations."<<endl;
	cout << "5. Exit." << endl;
	cout << "\\==========================/" << endl;

	int option3;
	retry:
	cout << "Your choice: ";  cin >> option3;

	switch (option3)
	{
	case 1:
		displayTimetable(trains, count);
		break;

	case 2:
		makeReservationMenu(reservations, count, maxId, username);
		break;

	case 3:
		displayReservations(reservations, count, false, username);
		deleteOrFixReservation(reservations, count, username);
		break;
	case 4:
		displayReservations(reservations, count, false, username);
		break;
	case 5:
		cout << "Good Bye!" << endl;
		return false;
		break;

	default:
		cout << "Please press a valid key!" << endl;
		goto retry;
		break;
	}
	return true;
}

bool GuestLogin(RESERVATION* reservations, int& count, int& maxId, bool CheckSystem, TRAIN* trains) // Guest 1
{
	string username;

	system("CLS");
	cout << "/==============================================================\\" << endl;
	cout << "Please enter your full name, this is how the system recognises"<<endl;
	cout << "you and gives you the ability to make or edit reservations!" << endl;
	cout << "Example: Georgi_Petkov" << endl;
	cout << "Username: "; cin >> username;
	cout << "\\==============================================================/" << endl;

	if (username != " ")
	{
		bool checkSystem3;
		CheckSystem = true;
		do
		{
			checkSystem3 = GuestMenu(trains, count, reservations, maxId, username);
		} while (checkSystem3);
			
	}
	else 
	{
		CheckSystem = false;
		return false;
	}
		
	return true;
}

//|||=========================Administrator=========================|||\\

void createNewPassMenu(string& pass)
{
	string newPass;
	cout << "Please enter the new password: "; cin >> newPass;
	createNewPass(pass, newPass);
}

bool AdministratorMenu(TRAIN* trains, int& count, int& maxId, RESERVATION* reservations,string& pass, int reservationCount)
{
	cout << endl;
	cout << "/=============================\\" << endl;
	cout << "Welcome, Administrator!" << endl;
	cout << "Choose option: " << endl;
	cout << "1. Create Train Timetable." << endl;
	cout << "2. View Timetable." << endl;
	cout << "3. Delete Timetable." << endl;
	cout << "4. Update Timetable." << endl;
	cout << "5. Guest Reservations." << endl;
	cout << "6. Update Administrator Password."<<endl;
	cout << "7. Exit." << endl;
	cout << "\\=============================/" << endl;

	int option2;
	cout << "Your choice: ";  cin >> option2;

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
		displayReservations(reservations, reservationCount,true,"");
		break;

	case 6: 
		createNewPassMenu(pass);
		break;
	case 7:
		cout << "Good Bye!" << endl;
		return false;
		break;
	default:
		cout << "Please press a valid key!" << endl; 
		break;
	}
	return true;
}

bool checkPassword(string realPass)
{
	system("CLS");
	cout << "/================================================================\\" << endl;
	cout << "You need to enter a password to access the administration mode!" << endl;
	cout << ("Note: Password characters won't be displayed, only their count (0)") << endl;
	cout << "\\================================================================/" << endl;

	char input[100];
	int p = 0;
	do {
		input[p] = _getch();
		if (input[p] != '\r' && input[p] != '\b')
			p++;
		if (input[p] == '\b')
		{
			if (p > 0)
			{
				input[p] = NULL;
				p--;
			}
		}
		system("CLS");
		cout << "/================================================================\\" << endl;
		cout << "You need to enter a password to access the administration mode!" << endl;
		cout << "Note: Password characters won't be displayed, only their count: (" << p << ")" << endl;
		cout << "\\================================================================/" << endl;
	} while (input[p] != '\r');
	input[p] = '\0';

	if (realPass == input)
	{
		cout << "Correct, you may proceed!" << endl;
		return true;
	}
	else
	{
		cout << "Incorrect password, try again!" << endl;
		return false;
	}
}

bool AdministratorLogin(TRAIN* trains, int& count, int& maxId, RESERVATION* reservations, bool CheckSystem,string& pass, int reservationCount)
{
	
	
	if (checkPassword(pass))
	{
		bool checkSystem2;
		CheckSystem = true;
		do
		{
			checkSystem2 = AdministratorMenu(trains, count, maxId, reservations,pass, reservationCount);
		} while (checkSystem2);
	}
	else
	{
		CheckSystem = false;
		return false;
	}
	return true;

}

bool MainMenu(TRAIN* trains, int count, int& trainMaxId,int& reservationMaxId,RESERVATION* reservations,int& reservationCount, bool CheckSystem,string& pass)
{
	//
	retry:
	cout << "/=======================\\" << endl;
	cout << "Welcome to Trainvago!" << endl;
	cout << "Please select your role:" << endl;
	cout << "1. Administrator" << endl;
	cout << "2. Guest" << endl;
	cout << "3. Exit" << endl;
	cout << "\\=======================/" << endl;
	//

	int option = 0; 
	cout << "Your choice: ";  cin >> option;

	switch (option)
	{
	case 1:
		AdministratorLogin(trains, count, trainMaxId, reservations, CheckSystem,pass, reservationCount);
		break; 

	case 2: 
		GuestLogin(reservations, reservationCount, reservationMaxId, CheckSystem, trains);
		break; 

	case 3: 
		cout << "Good Bye!" << endl; 
		return false; 

	default:
		cout << "Please press a valid key!" << endl;
		cout << endl;
		goto retry;
		
	}
	return true;
}

int main()
{
	TRAIN trains[50];
	RESERVATION reservations[50];

	int trainCount = 0;
	int reservationCount = 0;

	int trainMaxId = 0;
	int reservationMaxId = 0;

	countTrainElements(trainCount);
	countReservationElements(reservationCount);
	loadTrainData(trains, trainCount);
	loadReservationData(reservations, reservationCount);
	
	getTrainMaxId(trains, trainMaxId, trainCount);
	getReservationMaxId(reservations, reservationMaxId, reservationCount);

	bool Cycler; // Declaring variable of bool type (for the while cycle)
	bool CheckSystem=false; // Declaring a variable of bool type(For checking | true / false)

	string pass = "adminadmin";

	do
	{
		Cycler = MainMenu(trains,trainCount, trainMaxId, reservationMaxId,reservations,reservationCount,CheckSystem,pass);
	} while (Cycler == true);
}