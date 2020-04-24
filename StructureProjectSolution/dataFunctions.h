#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "structures.h"

using namespace std;

int toInt(string a);
void countElements(int& count);
void getMaxId(TRAIN* trains, int& maxId, int count);
void saveData(TRAIN* trains, int count);
void loadData(TRAIN* trains, int count);