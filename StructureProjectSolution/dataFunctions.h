#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "structures.h"
#include "administratorFunctions.h"
#include "guestFunctions.h"
#include "utilityFunctions.h"

using namespace std;

//
void saveTrainData(TRAIN* trains, int count);
void loadTrainData(TRAIN* trains, int count);
void saveReservationData(RESERVATION* reservations, int count);
void loadReservationData(RESERVATION* reservations, int count);
void WriteHTML(TRAIN* trains, int count);