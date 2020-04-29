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

using namespace std;

void deleteReservation(RESERVATION* reservations, int& count, int searchID);
void updateReservation(RESERVATION* reservations, int& index, RESERVATION NewData, int count);
void displayReservations(RESERVATION* reservations, int count, bool isAdmin, string username);
void updateReservationMenu(RESERVATION* reservations, int& count, int searchID);
void deleteReservationMenu(RESERVATION* reservations, int& count, int searchID);
void deleteOrFixReservation(RESERVATION* reservations, int& count, string username);
void makeReservation(RESERVATION* reservations, int& count, int& maxId, RESERVATION newData, string username);
void makeReservationMenu(RESERVATION* reservations, int& count, int& maxId, string username);
bool GuestMenu(TRAIN* trains, int& count, RESERVATION* reservations, int& maxId, string username, int trainCount);
bool GuestLogin(RESERVATION* reservations, int& count, int& maxId, bool CheckSystem, TRAIN* trains, int trainCount);