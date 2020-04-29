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

void makeReservation(RESERVATION* reservations, int& count, int& maxId, RESERVATION newData, string username)
{
	newData.username = username;
	newData.reservedId = generateId(maxId);
	reservations[count] = newData;
	count++;
	saveReservationData(reservations, count);

}

bool GuestLogin(RESERVATION* reservations, int& count, int& maxId, bool CheckSystem, TRAIN* trains, int trainCount) // Guest 1
{
	string username;

	system("CLS");
	cout << "/==============================================================\\" << endl;
	cout << "Please enter your full name, this is how the system recognises" << endl;
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
			checkSystem3 = GuestMenu(trains, count, reservations, maxId, username, trainCount);
		} while (checkSystem3);

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
void displayReservations(RESERVATION* reservations, int count, bool isAdmin, string username)
{
	bool hasReservations = false;
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

				hasReservations = true;
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
	cout << "Your choice: "; option4 = readInt();

	switch (option4)
	{
	case 1:
		cout << "Train ID: "; NewData.reservedTrainID = readInt2("Train ID: ");
		break;

	case 2:
		cout << "Number of seats: "; NewData.reservedSeats = readInt2("Number of seats: ");
		break;

	case 3:
		cout << "Good Bye!" << endl;
		break;

	default:
	{
		cout << "Please press a valid key!" << endl;
		break;
	}

	}

	updateReservation(reservations, index, NewData, count); //==LOGIC LAYER==
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

Retry:
	cout << "Enter the ID of your reservation: "; searchID = readInt2("Enter the ID of your reservation: ");
	if (checkReservationID(reservations, count, searchID, username))
	{
		cout << endl;
		cout << "|=====================================|" << endl;
		cout << "1. Delete my reservation." << endl;
		cout << "2. Fix my reservation." << endl;
		cout << "3. Exit." << endl;
		cout << "\\=====================================/" << endl;


		int option3;
		cout << "Your choice: "; option3 = readInt();

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
			break;

		default:
		{
			cout << "Please press a valid key!" << endl;
			break;
		}
		}
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

void makeReservationMenu(RESERVATION* reservations, int& count, int& maxId, string username)
{
	RESERVATION newData;

	cout << endl;
	cout << "/================= RESERVATION DEPARTMENT =================\\" << endl;
	cout << "Hello, "; cout << username << "! Please enter the ID of the train" << endl;
	cout << "and the number of seats you want to reserve!" << endl;
	cout << "Enter the Train ID: "; newData.reservedTrainID = readInt2("Enter the Train ID: ");
	cout << "Enter the number of seats: "; newData.reservedSeats = readInt2("Enter the number of seats: ");
	cout << "\\==========================================================/" << endl;
	cout << endl;

	makeReservation(reservations, count, maxId, newData, username);
}

bool GuestMenu(TRAIN* trains, int& count, RESERVATION* reservations, int& maxId, string username, int trainCount) //Guest 2
{
	cout << endl;
	cout << "/==========================\\" << endl;
	cout << "Welcome, " << username << "!" << endl;
	cout << "Choose option: " << endl;
	cout << "1. View Timetable." << endl;
	cout << "2. Make Reservation." << endl;
	cout << "3. View Your Reservations" << endl;
	cout << "4. Update/Delete Reservation." << endl;
	cout << "5. Exit." << endl;
	cout << "\\==========================/" << endl;

	int option3;
retry:
	cout << "Your choice: "; option3 = readInt();

	switch (option3)
	{
	case 1:
		displayTimetable(trains, trainCount);
		break;

	case 2:
		makeReservationMenu(reservations, count, maxId, username);
		break;

	case 3:
		displayReservations(reservations, count, false, username);
		break;

	case 4:
		if (checkForExistingReservaitons(reservations, count, username))
		{
			displayReservations(reservations, count, false, username);
			deleteOrFixReservation(reservations, count, username);
		}
		else
		{
			cout << "There are no reservaitons under this username!";
		}
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
//|||==============================PRESENTATION LAYER==============================|||//

