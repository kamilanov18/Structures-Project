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

int main()
{
	//Define the arrays of structures
	TRAIN trains[50];
	RESERVATION reservations[50];

	//Define the arrays' count values
	int trainCount = 0;
	int reservationCount = 0;

	//Define the maximum possible ids for both of the arrays
	int trainMaxId = 0;
	int reservationMaxId = 0;

	//Count all of the elements in the data.txt and reservationData.txt files and assign that count in their respectable variables
	countTrainElements(trainCount);
	countReservationElements(reservationCount);

	//Get all of the data from the data.txt and reservationData.txt files and assign these elements to the trains and reservations arrays, with their count
	loadTrainData(trains, trainCount);
	loadReservationData(reservations, reservationCount);
	
	//Get the maximum possible ID's of teh trains and reservations arrays and assign them to trainMaxId and reservationMaxId
	getTrainMaxId(trains, trainMaxId, trainCount);
	getReservationMaxId(reservations, reservationMaxId, reservationCount);

	bool Cycler; // This variable serves as a way to break or continue the do while loop
	bool CheckSystem=false; // Declaring a variable of bool type(For checking | true / false)

	string pass = "adminadmin"; //Password used by the administartor

	do
	{
		//Call the MainMenu() as long as the user doesn't choose exit as an option with a do while loop
		Cycler = MainMenu(trains,trainCount, trainMaxId, reservationMaxId,reservations,reservationCount,CheckSystem,pass);
	} while (Cycler == true);
}