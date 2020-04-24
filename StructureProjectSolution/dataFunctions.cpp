#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include<cmath>
#include "structures.h"
#include "dataFunctions.h"

using namespace std;

void checkMinutes(int minutes)
{
    if (minutes < 10)
    {
        cout << "0" << minutes;
    }
    else
        cout << minutes;
}

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

void getMaxId(TRAIN* trains,int& maxId,int count)
{
    maxId = trains[count].id;
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

void WriteHTML(TRAIN* trains,int count)
{
    ofstream web;
    web.open("web.html");
    web << "<!DOCTYPE html><html><head>    <link href='https://fonts.googleapis.com/css2?family=Manrope&display=swap' rel='stylesheet'>    <link rel='stylesheet' type='text/css' href='style.css'>    <title>Timetable</title></head><body>    <div class='container'>        <img src='img/train.jpg' alt='train'>        <div class='Title'>TRAINVAGO</div>        <div class='UnderTitle'>Railway Administration System</div>        <hr class='hr'>        <div class='container2'>            <section id='section' class='Button'>                <a href='#a'><span></span>Scroll</a>            </section>        </div>    </div>    <div class='MainDiv'>        <div class='Timetable' id='a'>            <center>Timetable</center>        </div>";
    for (int i = 0; i < count; i++)
    {
        web << "<div class='SubDiv'>            <div class='SubDiv1'>                <p id='inline'><b>"<<trains[count].departFrom<<" - "<< trains[count].arriveTo<<"</b>                    <p class='ID' id='inline'>ID: <span class='IDNumber'>"<< trains[count].id<<"</span></p>                </p>            </div>            <div calss='SubDiv2'>                <p class='Departure' id='inline'><b>Departure: </b>                    <p class='DepartDate' id='inline'>"<< trains[count].departTime.day<<"."<< trains[count].departTime.month<<"."<< trains[count].departTime.year<<" | "<< trains[count].departTime.time.hours<<":"<<trains[count].departTime.time.minutes<<"                       <p class='Seats' id='inline'>Seats: "<< trains[count].seats<<"</p>                    </p>                </p>                <p class='Arrival' id='inline'><b>Arrival: </b>                    <p class='ArriveDate' id='inline'>"<< trains[count].arriveTime.day<<"." << trains[count].arriveTime.month<<"." << trains[count].arriveTime.year<<" | "<<trains[count].arriveTime.time.hours<<":" << trains[count].arriveTime.time.minutes<<"</p>                </p>            </div>        </div>";
    }
    web << "</div></body></html>";
    web.close();
}
