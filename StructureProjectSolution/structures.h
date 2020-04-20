#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

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
	char trainClass;
};

struct LOGIN
{
	string username;
	string password;
};

struct RESERVATION
{
	int reservedTrainID;
	int reservedSeats;
	int reservedId;
};

