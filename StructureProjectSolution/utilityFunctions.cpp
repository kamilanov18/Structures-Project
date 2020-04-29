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

bool checkForExistingReservaitons(RESERVATION* reservations, int count, string username)
{
	for (int i = 0; i < count; i++)
	{
		if (reservations[i].username == username)
			return true;
	}
	return false;
}

bool checkReservationID(RESERVATION* reservations, int count, int id, string username)
{
	for (int i = 0; i < count; i++)
	{
		if (id == reservations[i].reservedId && username == reservations[i].username)
		{
			return true;
		}
	}
	return false;
}

bool checkTrainID(TRAIN* trains, int count, int id)
{
	for (int i = 0; i < count; i++)
	{
		if (id == trains[i].id)
		{
			return true;
		}
	}
	return false;
}

int readInt2(string s)
{
	int a;
	while (!(cin >> a))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Incorrect value, try again!" << endl;
		cout << s;
	}
	return a;
}

int readInt()
{
	int a;
	while (!(cin >> a))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Incorrect value, try again!" << endl;
		cout << "Your choice: ";
	}
	return a;
}

int len(char a[100])
{
	int i = 0;
	while (a[i] != NULL)
	{
		i++;
	}
	return i;
}

void createNewPass(string& pass, string newPass)
{
	pass = newPass;
}

int generateId(int& maxId)
{
	maxId++;
	return maxId;
}

int findElementByIdTRAIN(TRAIN* trains, int count, int searchID)
{
	for (int i = 0; i < count; i++)
	{
		if (searchID == trains[i].id)
		{
			return i;
		}
	}
}

int findElementByIdRESERVATION(RESERVATION* reservations, int count, int searchID)
{
	for (int i = 0; i < count; i++)
	{
		if (searchID == reservations[i].reservedId)
		{
			return i;
		}
	}
}

void createNewPassMenu(string& pass)
{
	string newPass;
	cout << "Please enter the new password: "; cin >> newPass;
	createNewPass(pass, newPass);
}

bool checkPassword(string realPass)
{
	system("CLS");
	cout << "/================================================================\\" << endl;
	cout << "You need to enter a password to access the administration mode!" << endl;
	cout << ("Note: Password characters won't be displayed, only their count (0)") << endl;
	cout << "\\================================================================/" << endl;

	char input[100];
	int p = 0;
	do {
		input[p] = _getch();
		if (input[p] != '\r' && input[p] != '\b')
			p++;
		if (input[p] == '\b')
		{
			if (p > 0)
			{
				input[p] = NULL;
				p--;
			}
		}
		system("CLS");
		cout << "/================================================================\\" << endl;
		cout << "You need to enter a password to access the administration mode!" << endl;
		cout << "Note: Password characters won't be displayed, only their count: (" << p << ")" << endl;
		cout << "\\================================================================/" << endl;
	} while (input[p] != '\r');
	input[p] = '\0';

	if (realPass == input)
	{
		cout << "Correct, you may proceed!" << endl;
		return true;
	}
	else
	{
		cout << "Incorrect password, try again!" << endl;
		return false;
	}
}

string earlyTimeCorrectionCheck(int time)
{
	string text = "0";
	if (time < 10)
	{
		text += to_string(time);
		return text;
	}
	else
		return to_string(time);
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

void countTrainElements(int& count)
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

void countReservationElements(int& count)
{

	ifstream file;
	file.open("reservationData.txt");
	string counterText;
	while (getline(file, counterText))
	{
		if (counterText == ":::")
			count++;
	}
	file.close();
}

void getTrainMaxId(TRAIN* trains, int& maxId, int count)
{
	if (count == 0)
		maxId = 50;
	else
		maxId = trains[count - 1].id;
}

void getReservationMaxId(RESERVATION* reservations, int& maxId, int count)
{
	if (count == 0)
		maxId = 0;
	else
		maxId = reservations[count - 1].reservedId;
}