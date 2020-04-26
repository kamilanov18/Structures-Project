#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "structures.h"

using namespace std;

void checkMinutes(int minutes);
int toInt(string a);
void countTrainElements(int& count);
void countReservationElements(int& count);
void getMaxId(TRAIN* trains, int& maxId, int count);
void saveTrainData(TRAIN* trains, int count);
void loadTrainData(TRAIN* trains, int count);
void saveReservationData(RESERVATION* reservations, int count);
void loadReservationData(RESERVATION* reservations, int count);
void WriteHTML(TRAIN* trains, int count);