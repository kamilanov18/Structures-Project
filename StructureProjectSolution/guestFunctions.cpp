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
//This function deletes reservations
void deleteReservation(RESERVATION* reservations, int& count, int searchID)
{
	//Count from the position we want to delete, finding it by using the findElementByIdRESERVATION function
	for (int i = findElementByIdRESERVATION(reservations, count, searchID); i < count - 1; i++)
	{
		reservations[i] = reservations[i + 1]; //shift every element to the right
	}
	count--; //decrease the count, because of the deleted element 
	//save the new data to the reservationData.txt file
	saveReservationData(reservations, count);
}

//This function updates reservations
void updateReservation(RESERVATION* reservations, int& index, RESERVATION NewData, int count)
{
	//pass NewData in the index position of the old data, thus replacing it
	reservations[index] = NewData;
	//save the new data to the reservationData.txt file
	saveReservationData(reservations, count);
}

//This function creates reservations
void makeReservation(RESERVATION* reservations, int& count, int& maxId, RESERVATION newData, string username)
{
	//set newData's username to the one used in the argument
	newData.username = username;
	//Call generateId to create a new unique ID for this specific reservation
	newData.reservedId = generateId(maxId);
	//Add the new reservation to the array
	reservations[count] = newData;
	//Increase the count, because of the new data
	count++;
	//save the new data to the reservationData.txt file
	saveReservationData(reservations, count);

}

//This function lets the user login their account or make a new one
bool GuestLogin(RESERVATION* reservations, int& count, int& maxId, bool CheckSystem, TRAIN* trains, int trainCount) // Guest 1
{
	string username;

	//Clear the screen
	system("CLS");
	cout << "/==============================================================\\" << endl;
	cout << "Please enter your full name, this is how the system recognises" << endl;
	cout << "you and gives you the ability to make or edit reservations!" << endl;
	cout << "Example: Georgi_Petkov" << endl;
	cout << "Username: "; cin >> username; //The user enters their name
	cout << "\\==============================================================/" << endl;

	if (username != " ") //If it is not empty Call GuestMenu() and let the user use the program
	{
		//Call the guest menu until the user chooses exit as an option
		bool checkSystem3;
		CheckSystem = true;
		do
		{
			checkSystem3 = GuestMenu(trains, count, reservations, maxId, username, trainCount); 
		} while (checkSystem3);

	}
	else //Otherwise don't let the user in the guest menu and make them go back to the main menu
	{
		CheckSystem = false;
		return false;
	}

	return true;
}
//|||==============================LOGIC LAYER==============================|||//

//|||==============================PRESENTATION LAYER==============================|||//
//This function displays reservations
void displayReservations(RESERVATION* reservations, int count, bool isAdmin, string username)
{
	bool hasReservations = false;
	if (isAdmin) //If this function is used in admin mode, then display all reservations onscreen
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
		//if the function is in user mode, check if  there are any reservations under the user's name
		//if there are reservations loop trough the array of reservations and check each element to see if they match the user's name
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
		if (hasReservations == false) //If there are no reservations, let the user know!
			cout << "There are no reservations unser this username!" << endl;
		cout << endl;
		cout << "\\===================================/" << endl;
		cout << endl;
	}
}

//This function displays the menu for updating reservations
void updateReservationMenu(RESERVATION* reservations, int& count, int searchID)
{
	RESERVATION NewData;

	//Find the index of the element we want to update by using the findElementByIdRESERVATION and the searchID
	int index = findElementByIdRESERVATION(reservations, count, searchID); 
	NewData = reservations[index]; //Copy the data we want to update in the NewData variable

	//Display the menu:
	cout << endl;
	cout << "/===========================\\" << endl;
	cout << "Choose what you want to fix: " << endl;
	cout << "1. Train ID." << endl;
	cout << "2. Number of seats." << endl;
	cout << "3. Exit." << endl;
	cout << "\\===========================/" << endl;

	//Read input
	int option4;
	cout << "Your choice: "; option4 = readInt();

	switch (option4)
	{
	case 1:
		cout << "Train ID: "; NewData.reservedTrainID = readInt2("Train ID: "); // Set the new data to the user's choice
		break;

	case 2:
		cout << "Number of seats: "; NewData.reservedSeats = readInt2("Number of seats: "); // Set the new data to the user's choice
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
	//Update the reservations by calling the updateReservation function
	updateReservation(reservations, index, NewData, count); 
}

//This function calls the deleteReservation function
void deleteReservationMenu(RESERVATION* reservations, int& count, int searchID)
{
	deleteReservation(reservations, count, searchID);

}

//This function makes the user choose between deleting and updating a function
void deleteOrFixReservation(RESERVATION* reservations, int& count, string username)
{

	int searchID;

	cout << endl;
	cout << "/=====================================\\" << endl;
	cout << "Hello, "; cout << username << "!" << endl;

	//Prompt the user for input
Retry:
	cout << "Enter the ID of your reservation: "; searchID = readInt2("Enter the ID of your reservation: "); 
	//If the reservation exists and if the user, who wanto to do this operation is the creator of the reservation
	if (checkReservationID(reservations, count, searchID, username))
	{
		//display menu
		cout << endl;
		cout << "|=====================================|" << endl;
		cout << "1. Delete my reservation." << endl;
		cout << "2. Fix my reservation." << endl;
		cout << "3. Exit." << endl;
		cout << "\\=====================================/" << endl;


		int option3;
		cout << "Your choice: "; option3 = readInt(); //prompt the user for input

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
	else //Otherwise make sure that the user know that there are no such reservations
	{
		cout << endl;
		cout << "/=====================\\" << endl;
		cout << "Invalid Reservation Id" << endl;
		cout << "\\=====================/" << endl;
		cout << endl;
		goto Retry;
	}
}

//This functions displays the menu of the makeReservation function
void makeReservationMenu(RESERVATION* reservations, int& count, int& maxId, string username)
{
	RESERVATION newData;

	//Display the menu and prompt the user for all of the data below
	cout << endl;
	cout << "/================= RESERVATION DEPARTMENT =================\\" << endl;
	cout << "Hello, "; cout << username << "! Please enter the ID of the train" << endl;
	cout << "and the number of seats you want to reserve!" << endl;
	cout << "Enter the Train ID: "; newData.reservedTrainID = readInt2("Enter the Train ID: ");
	cout << "Enter the number of seats: "; newData.reservedSeats = readInt2("Enter the number of seats: ");
	cout << "\\==========================================================/" << endl;
	cout << endl;

	//Register the new information by calling the makeReservation function
	makeReservation(reservations, count, maxId, newData, username);
}

//This function displays the guest menu
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
	//prompt the user for input
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
		//Check to see if this user has any reservations, if not these operations are impossible
		if (checkForExistingReservaitons(reservations, count, username)) 
		{
			displayReservations(reservations, count, false, username);
			deleteOrFixReservation(reservations, count, username);
		}
		else
		{
			//let the user know!
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

