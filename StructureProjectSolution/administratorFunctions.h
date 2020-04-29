#pragma once
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



void createTimetable(TRAIN* trains, int& count, int& maxId, TRAIN newData);
void updateTimetable(TRAIN* trains, int index, TRAIN newData, int count);
void deleteTimetable(TRAIN* trains, int& count, int searchID);
void displayTimetable(TRAIN* trains, int count);
void deleteTimetableMenu(TRAIN* trains, int& count);
void updateTimetableMenu(TRAIN* trains, int& count);
void createTimetableMenu(TRAIN* trains, int& count, int& maxId);
bool AdministratorMenu(TRAIN* trains, int& count, int& maxId, RESERVATION* reservations, string& pass, int reservationCount);
bool AdministratorLogin(TRAIN* trains, int& count, int& maxId, RESERVATION* reservations, bool CheckSystem, string& pass, int reservationCount);
bool MainMenu(TRAIN* trains, int count, int& trainMaxId, int& reservationMaxId, RESERVATION* reservations, int& reservationCount, bool CheckSystem, string& pass);