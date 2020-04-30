#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "structures.h"
#include "dataFunctions.h"
#include "administratorFunctions.h"
#include "guestFunctions.h"
#include "utilityFunctions.h"

using namespace std;
//|||==============================LOGIC LAYER==============================|||//
void createTimetable(TRAIN* trains, int& count, int& maxId, TRAIN newData)
{
	newData.id = generateId(maxId);
	trains[count] = newData;
	count++;
	saveTrainData(trains, count);
	WriteHTML(trains, count);
}
void updateTimetable(TRAIN* trains, int index, TRAIN newData, int count)
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
bool AdministratorLogin(TRAIN* trains, int& count, int& maxId, RESERVATION* reservations, bool CheckSystem, string& pass, int reservationCount)
{


	if (checkPassword(pass))
	{
		bool checkSystem2;
		CheckSystem = true;
		do
		{
			checkSystem2 = AdministratorMenu(trains, count, maxId, reservations, pass, reservationCount);
		} while (checkSystem2);
	}
	else
	{
		CheckSystem = false;
		return false;
	}
	return true;

}
//|||==============================LOGIC LAYER==============================|||//

//|||==============================PRESENTATION LAYER==============================|||//
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

retry:
	cout << "Enter the ID of the train you want to delete: "; searchID = readInt2("Enter the ID of the train you want to delete: ");
	if (checkTrainID(trains, count, searchID) == true)
	{
		deleteTimetable(trains, count, searchID);
		cout << endl;
		cout << "/===================\\" << endl;
		cout << "Successfully deleted!" << endl;
		cout << "\\===================/" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "/==================\\" << endl;
		cout << "Invalid Train Id" << endl;
		cout << "\\==================/" << endl;
		cout << endl;
		goto retry;
	}
}
void updateTimetableMenu(TRAIN* trains, int& count) // Change Retry (function) with Bool Variable !!!!
{
	TRAIN newData;

	int searchID;
	int field, field2;

Retry:
	cout << "Enter the ID of the train: "; searchID = readInt2("Enter the ID of the train: ");

	if (checkTrainID(trains, count, searchID) == true)
	{
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
		cout << "Your choice: "; field = readInt();

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

			cout << "Your choice: "; field2 = readInt();
			switch (field2)
			{
			case 1:
			retryDDay:
				cout << "Enter the new day: "; newData.departTime.day = readInt2("Enter the new day: ");
				if (newData.departTime.day > 31 or newData.departTime.day < 0)
				{
					cout << "Incorrect Input, please enter a legal value!" << endl;
					goto retryDDay;
				}
				break;

			case 2:
			retryDMonth:
				cout << "Enter the new month: "; newData.departTime.month = readInt2("Enter the new month: ");
				if (newData.departTime.month > 12 or newData.departTime.month < 0)
				{
					cout << "Incorrect Input, please enter a legal value!" << endl;
					goto retryDMonth;
				}
				break;

			case 3:
			retryDYear:
				cout << "Enter the new year: "; newData.departTime.year = readInt2("Enter the new year: ");
				if (newData.departTime.year < 2020)
				{
					cout << "Incorrect Input, please enter a legal value!" << endl;
					goto retryDYear;
				}
				break;

			case 4:
			retryDHours:
				cout << "Enter the new hours: "; newData.departTime.time.hours = readInt2("Enter the new hours: ");
				if (newData.departTime.time.hours > 24 or newData.departTime.time.hours < 0)
				{
					cout << "Incorrect Input, please enter a legal value!" << endl;
					goto retryDHours;
				}
				break;

			case 5:
			retryDMinutes:
				cout << "Enter the new minutes: "; newData.departTime.time.minutes = readInt2("Enter the new minutes: ");
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

			cout << "Your choice: "; field2 = readInt();
			switch (field2)
			{
			case 1:
			retryADay:
				cout << "Enter the new day: "; newData.arriveTime.day = readInt2("Enter the new day: ");
				if (newData.arriveTime.day > 31 or newData.arriveTime.day < 0)
				{
					cout << "Incorrect Input, please enter a legal value!" << endl;
					goto retryADay;
				}
				break;

			case 2:
			retryAMonth:
				cout << "Enter the new month: "; newData.arriveTime.month = readInt2("Enter the new month: ");
				if (newData.arriveTime.month > 12 or newData.arriveTime.month < 0)
				{
					cout << "Incorrect Input, please enter a legal value!" << endl;
					goto retryAMonth;
				}
				break;

			case 3:
			retryAYear:
				cout << "Enter the new year: "; newData.arriveTime.year = readInt2("Enter the new year: ");
				if (newData.arriveTime.year < 2020)
				{
					cout << "Incorrect Input, please enter a legal value!" << endl;
					goto retryAYear;
				}
				break;

			case 4:
			retryAHours:
				cout << "Enter the new hours: "; newData.arriveTime.time.hours = readInt2("Enter the new hours: ");
				if (newData.arriveTime.time.hours > 24 or newData.arriveTime.time.hours < 0)
				{
					cout << "Incorrect Input, please enter a legal value!" << endl;
					goto retryAHours;
				}
				break;

			case 5:
			retryAMinutes:
				cout << "Enter the new minutes: "; newData.arriveTime.time.minutes = readInt2("Enter the new minutes: ");
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

			cout << "Your choice: "; field2 = readInt();
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
				cout << "Enter the newnumber of seats: "; newData.seats = readInt2("Enter the newnumber of seats: ");
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
			break;

		default:
			cout << "Incorrect Input, Please Try Again!";
			goto Retry1;
			break;
		}

		updateTimetable(trains, index, newData, count);
	}
	else
	{
		cout << endl;
		cout << "/==================\\" << endl;
		cout << "Invalid Train Id" << endl;
		cout << "\\==================/" << endl;
		cout << endl;
		goto Retry;
	}

}
void createTimetableMenu(TRAIN* trains, int& count, int& maxId)
{
	TRAIN newData;

	//Depart time 
	cout << endl;
	cout << "/==============================\\" << endl;
	cout << "Please enter the departure date." << endl;

retryDDay:
	cout << "Day: ";  newData.departTime.day = readInt2("Day: ");
	if (newData.departTime.day > 31 or newData.departTime.day < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryDDay;
	}

retryDMonth:
	cout << "Month: "; newData.departTime.month = readInt2("Month: ");
	if (newData.departTime.month > 12 or newData.departTime.month < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryDMonth;
	}

retryDYear:
	cout << "Year: "; newData.departTime.year = readInt2("Year: ");
	if (newData.departTime.year < 2020)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryDYear;
	}
	cout << endl;

	cout << "Enter departure time." << endl;
retryDHours:
	cout << "Hours: "; newData.departTime.time.hours = readInt2("Hours: ");
	if (newData.departTime.time.hours > 24 or newData.departTime.time.hours < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryDHours;
	}

retryDMinutes:
	cout << "Minutes: "; newData.departTime.time.minutes = readInt2("Minutes: ");
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
	cout << "Day: "; newData.arriveTime.day = readInt2("Day: ");
	if (newData.arriveTime.day > 31 or newData.arriveTime.day < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryADay;
	}

retryAMonth:
	cout << "Month: "; newData.arriveTime.month = readInt2("Month: ");
	if (newData.arriveTime.month > 12 or newData.arriveTime.month < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryAMonth;
	}

retryAYear:
	cout << "Year: "; newData.arriveTime.year = readInt2("Year: ");
	if (newData.arriveTime.year < 2020)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryAYear;
	}
	cout << endl;


	cout << "Enter arrival time." << endl;
retryAHours:
	cout << "Hours: "; newData.arriveTime.time.hours = readInt2("Hours: ");
	if (newData.arriveTime.time.hours > 24 or newData.arriveTime.time.hours < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retryAHours;
	}

retryAMinutes:
	cout << "Minutes: "; newData.arriveTime.time.minutes = readInt2("Minutes: ");
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
	cout << "Enter number of seats: "; newData.seats = readInt2("Enter number of seats: ");
	if (newData.seats < 0)
	{
		cout << "Incorrect Input, please enter a legal value!" << endl;
		goto retrySeats;
	}
	cout << "\\=================================/" << endl;
	cout << endl;

	createTimetable(trains, count, maxId, newData);
}
bool AdministratorMenu(TRAIN* trains, int& count, int& maxId, RESERVATION* reservations, string& pass, int reservationCount)
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
	cout << "6. Update Administrator Password." << endl;
	cout << "7. Exit." << endl;
	cout << "\\=============================/" << endl;

	int option2;
	cout << "Your choice: "; option2 = readInt();

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
		displayReservations(reservations, reservationCount, true, "");
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
bool MainMenu(TRAIN* trains, int count, int& trainMaxId, int& reservationMaxId, RESERVATION* reservations, int& reservationCount, bool CheckSystem, string& pass)
{
	//
retry:
	cout << endl;
	cout << "/=======================\\" << endl;
	cout << "Welcome to Trainvago!" << endl;
	cout << "Please select your role:" << endl;
	cout << "1. Administrator" << endl;
	cout << "2. Guest" << endl;
	cout << "3. Exit" << endl;
	cout << "\\=======================/" << endl;
	//

	int option = 0;
	cout << "Your choice: "; option = readInt();

	switch (option)
	{
	case 1:
		AdministratorLogin(trains, count, trainMaxId, reservations, CheckSystem, pass, reservationCount);
		break;

	case 2:
		GuestLogin(reservations, reservationCount, reservationMaxId, CheckSystem, trains, count);
		break;

	case 3:
		cout << "Good Bye!" << endl;
		return false;
		break;

	default:
		cout << "Please press a valid key!" << endl;
		cout << endl;
		goto retry;

	}
	return true;
}
//|||==============================PRESENTATION LAYER==============================|||//