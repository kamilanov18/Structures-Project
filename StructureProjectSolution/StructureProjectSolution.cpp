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