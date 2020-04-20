#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include<cmath>
#include "structures.h"
#include "dataFunctions.h"

using namespace std;

int toInt(string a)
{
    int sum = 0;
    int dig[100];
    for (int i = 0; i < a.size(); i++)
    {
        dig[i] = (int)a[i] - 48;
    }
    for (int i = 0; i < a.size(); i++)
    {
        sum += dig[a.size() - 1 - i] * pow(10, i);
    }
    return sum;
}

void countElements(int& count)
{

    ifstream file;
    file.open("data.txt");
    string counterText;
    while (getline(file, counterText))
    {
        if (counterText == ":::")
            count++;
    }
    file.close();
}

void loadData(TRAIN* trains, int count)
{
    ifstream data;
    data.open("data.txt");
    string text;

    for (int i = 0; i < count; i++)
    {
        data >> trains[i].departTime.day;
        data >> trains[i].departTime.month;
        data >> trains[i].departTime.year;
        data >> trains[i].departTime.time.hours;
        data >> trains[i].departTime.time.minutes;

        data >> trains[i].arriveTime.day;
        data >> trains[i].arriveTime.month;
        data >> trains[i].arriveTime.year;
        data >> trains[i].arriveTime.time.hours;
        data >> trains[i].arriveTime.time.minutes;

        data >> trains[i].id;
        data >> trains[i].departFrom;
        data >> trains[i].arriveTo;
        data >> trains[i].seats;
        data >> trains[i].trainClass;
        data >> text;
    }
    data.close();
}

void saveData(TRAIN* trains, int count)
{

    ofstream data;
    data.open("data.txt");

    for (int i = 0; i < count; i++)
    {
        data << trains[i].departTime.day << endl;
        data << trains[i].departTime.month << endl;
        data << trains[i].departTime.year << endl;
        data << trains[i].departTime.time.hours << endl;
        data << trains[i].departTime.time.minutes << endl;
      
        data << trains[i].arriveTime.day << endl;
        data << trains[i].arriveTime.month << endl;
        data << trains[i].arriveTime.year << endl;
        data << trains[i].arriveTime.time.hours << endl;
        data << trains[i].arriveTime.time.minutes << endl;

        data << trains[i].id << endl;
        data << trains[i].departFrom << endl;
        data << trains[i].arriveTo << endl;
        data << trains[i].seats << endl;
        data << trains[i].trainClass << endl;
        data << ":::" << endl;

    }
    data.close();
}
