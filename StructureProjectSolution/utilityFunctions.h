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

bool checkForExistingReservaitons(RESERVATION* reservations, int count, string username);
bool checkReservationID(RESERVATION* reservations, int count, int id, string username);
bool checkTrainID(TRAIN* trains, int count, int id);
int readInt2(string s);
int readInt();
int len(char a[100]);
void createNewPass(string& pass, string newPass);
int generateId(int& maxId);
int findElementByIdTRAIN(TRAIN* trains, int count, int searchID);
int findElementByIdRESERVATION(RESERVATION* reservations, int count, int searchID);
void createNewPassMenu(string& pass);
bool checkPassword(string realPass);
string earlyTimeCorrectionCheck(int time);
int toInt(string a);
void countTrainElements(int& count);
void countReservationElements(int& count);
void getTrainMaxId(TRAIN* trains, int& maxId, int count);
void getReservationMaxId(RESERVATION* reservations, int& maxId, int count);