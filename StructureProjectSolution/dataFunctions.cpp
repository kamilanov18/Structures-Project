#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include<cmath>
#include "structures.h"
#include "dataFunctions.h"
#include "utilityFunctions.h"
using namespace std;


//|||==============================DATA LAYER==============================|||//
void loadTrainData(TRAIN* trains, int count)
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
        data >> text;
    }
    data.close();
}

void saveTrainData(TRAIN* trains, int count)
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
        data << ":::" << endl;

    }
    data.close();
}

void saveReservationData(RESERVATION* reservations, int count)
{
    ofstream rData;
    rData.open("reservationData.txt");
    for (int i = 0; i < count; i++)
    {
        rData << reservations[i].username << endl;
        rData << reservations[i].reservedSeats << endl;
        rData << reservations[i].reservedTrainID<< endl;
        rData << reservations[i].reservedId << endl;
        rData << ":::" << endl;
    }
    rData.close();
}

void loadReservationData(RESERVATION* reservations, int count)
{
    ifstream rData;
    rData.open("reservationData.txt");
    string text;

    for (int i = 0; i < count; i++)
    {
        rData >> reservations[i].username;
        rData >> reservations[i].reservedSeats;
        rData >> reservations[i].reservedTrainID;
        rData >> reservations[i].reservedId;
        rData >> text;
    }
    rData.close();
}

void WriteHTML(TRAIN* trains,int count)
{
    ofstream web;
    web.open("web.html");
    web << "<!DOCTYPE html><html><head>    <link href='https://fonts.googleapis.com/css2?family=Manrope&display=swap' rel='stylesheet'>    <link rel='stylesheet' type='text/css' href='style.css'>    <title>Timetable</title></head><body>    <div class='container'>        <img src='img/train.jpg' alt='train'>        <div class='Title'>TRAINVAGO</div>        <div class='UnderTitle'>Railway Administration System</div>        <hr class='hr'>        <div class='container2'>            <section id='section' class='Button'>                <a href='#a'><span></span>Scroll</a>            </section>        </div>    </div>    <div class='MainDiv'>        <div class='Timetable' id='a'>            <center>Timetable</center>        </div>";
    for (int i = 0; i < count; i++)
    {
        web << "<div class='SubDiv'>            <div class='SubDiv1'>                <p id='inline'><b>"<<trains[i].departFrom<<" - "<< trains[i].arriveTo<<"</b>                    <p class='ID' id='inline'>ID: <span class='IDNumber'>"<< trains[i].id<<"</span></p>                </p>            </div>            <div calss='SubDiv2'>                <p class='Departure' id='inline'><b>Departure: </b>                    <p class='DepartDate' id='inline'>"<< earlyTimeCorrectionCheck(trains[i].departTime.day)<<"."<< earlyTimeCorrectionCheck(trains[i].departTime.month)<<"."<< trains[i].departTime.year<<" | "<< earlyTimeCorrectionCheck(trains[i].departTime.time.hours)<<":"<< earlyTimeCorrectionCheck(trains[i].departTime.time.minutes)/*trains[i].departTime.time.minutes*/<<"                       <p class='Seats' id='inline'>Seats: "<< trains[i].seats<<"</p>                    </p>                </p>                <p class='Arrival' id='inline'><b>Arrival: </b>                    <p class='ArriveDate' id='inline'>"<< earlyTimeCorrectionCheck(trains[i].arriveTime.day)<<"." << earlyTimeCorrectionCheck(trains[i].arriveTime.month)<<"." << trains[i].arriveTime.year<<" | "<< earlyTimeCorrectionCheck(trains[i].arriveTime.time.hours)<<":" << earlyTimeCorrectionCheck(trains[i].arriveTime.time.minutes)<<"</p>                </p>            </div>        </div>";
    }
    web << "</div></body></html>";
    web.close();
}
//|||==============================DATA LAYER==============================|||//
