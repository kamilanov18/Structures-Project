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

//Function that check wether a user has any reservations. Returns true if yes and no otehrwise.
bool checkForExistingReservaitons(RESERVATION* reservations, int count, string username)
{
	//Loop trough every element of the reservations array
	for (int i = 0; i < count; i++)
	{
		//Check if the username in the argument of the function
		//matches any of the usernames in the reservation array
		if (reservations[i].username == username) 
			return true;
	}
	return false;
}

//This function is used to check wether a certain reservation exists and that if it exists
//and to see wether this specific reservation belongs to the user who wants to edit / delete it
bool checkReservationID(RESERVATION* reservations, int count, int id, string username)
{
	//Loop trough every element of the reservations array
	for (int i = 0; i < count; i++)
	{
		//Check if the username in the argument of the function
		//matches any of the usernames in the reservation array
		//and if the reservaitons exists using its ID
		if (id == reservations[i].reservedId && username == reservations[i].username)
		{
			return true;
		}
	}
	return false;
}

//Check to see if a Train timetable exists, based on its ID | returns true if yes, return false if no
bool checkTrainID(TRAIN* trains, int count, int id)
{
	//Loop trough every element of the trains array
	for (int i = 0; i < count; i++)
	{
		//And check wether the ID in the argument
		//of the function matches any of the ones in the trains array
		if (id == trains[i].id)
		{
			return true;
		}
	}
	return false;
}

//A special function that replaces cin>>, because it detects input
//and if it is string the user is sent back until the input is int
//We use "s" as an argument to add a specific message prompting the user for specific input
int readInt2(string s)
{
	int a;
	// Constantly make the user enter new input if the result is of type string
	while (!(cin >> a))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Incorrect value, try again!" << endl;
		// The argument "s" as the specific message, example: "Day: ", "Month: " 
		cout << s; 
	}
	return a;
}

//This function is identical to readInt2, but it has no specific "s" argument,
//because it is used in Menu choices, so the "s" is replaced with "Your choice: "
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

//Function that gets the length of a char array
int len(char a[100])
{
	int i = 0;
	//While the current element is not empty
	while (a[i] != NULL)
	{
		i++; //Add to the element count
	}
	return i; //return the element count
}

//Function that replaces the administrator password with the second argument.
void createNewPass(string& pass, string newPass)
{
	pass = newPass; //pass is a pseudonym, so the original variable's value is replaced
}

//Function that generates a new ID when called. It needs the previous maxId
int generateId(int& maxId)
{
	maxId++;
	return maxId; //We return an incremented value, also the original value of maxId is incremented too
}

//This function is used to find an element of the trains array's index, using it's ID
int findElementByIdTRAIN(TRAIN* trains, int count, int searchID)
{
	//Loop trough all of the elements in the array
	for (int i = 0; i < count; i++)
	{
		//If the id in the arguments of the function matches that of any in the list
		if (searchID == trains[i].id)
		{
			return i; //We return it's index
		}
	}
}

//This function is used to find an element of the reservations array's index, using it's ID
int findElementByIdRESERVATION(RESERVATION* reservations, int count, int searchID)
{
	//Loop trough all of the elements in the array
	for (int i = 0; i < count; i++)
	{
		//If the id in the arguments of the function matches that of any in the list
		if (searchID == reservations[i].reservedId)
		{
			return i;//We return it's index
		}
	}
}

//The menu function for the createNewPass() function
void createNewPassMenu(string& pass)
{
	string newPass;
	cout << "Please enter the new password: "; cin >> newPass; //Prompt the administrator for the new password
	 //Replace the old password with the new, using the pass argument, which is a pseudonym, and it's original value is updated.
	createNewPass(pass, newPass);
}

//Function, which checks if the password entered by the user is correct or not
bool checkPassword(string realPass)
{
	system("CLS"); //Use system("CLS") to make the screen more clear
	cout << "/================================================================\\" << endl;
	cout << "You need to enter a password to access the administration mode!" << endl;
	cout << ("Note: Password characters won't be displayed, only their count: (0)") << endl;
	cout << "\\================================================================/" << endl;

	char input[100]; //array of the user's inputed charachters
	int p = 0; //The count of the input array's elements

	//Each time the input charachter is not equal to enter we loop this cycle
	do {
		input[p] = _getch(); //Use _getch() to hide the input of the user, it is a password afterall

		//If the currently entered element is not equal to backspace ot enter
		if (input[p] != '\r' && input[p] != '\b')
			p++; // increment the count of the array of chars

		//if the current input char is equal to backspace
		if (input[p] == '\b')
		{
			//This if() is used to check if we are on the 0th element of the input array
			//if it is, do nothing, because if we were to do so we would go into -1, -2 and memmory will leak.
			//Otherwise just delete the charachter
			if (p > 0)
			{
				input[p] = NULL; //Reset the current element in the char array to NULL
				p--; //Decrease the count of elements in the input array
			}
		}

		//Clear the system's screen and display the amount of charachters entered, This adds the illusion of smooth animation
		system("CLS");
		cout << "/================================================================\\" << endl;
		cout << "You need to enter a password to access the administration mode!" << endl;
		cout << "Note: Password characters won't be displayed, only their count: (" << p << ")" << endl;
		cout << "\\================================================================/" << endl;
	} while (input[p] != '\r'); 

	input[p] = '\0'; //set the last element of the input array to '\0'

	if (realPass == input) //Check to see if the real password matches the user's input
	{
		cout << "Correct, you may proceed!" << endl;
		return true; //if so return true
	}
	else
	{
		cout << "Incorrect password, try again!" << endl;
		return false; //otherwise return false
	}
}

//This function is used in writing the HTML, it adds an extra '0' to elements, which are lower than 10
string earlyTimeCorrectionCheck(int time)
{
	string text = "0";
	//check to see if the function's argument is lower than 10
	if (time < 10)
	{
		text += to_string(time); //if so add an extra '0'
		return text;
	}
	else
		return to_string(time); //Otherwise just return the value
}

//Funciton that converts a string to an Int type
int toInt(string a)
{
	int sum = 0;
	int dig[100];
	//Loop trough every char in the string
	for (int i = 0; i < a.size(); i++)
	{
		dig[i] = (int)a[i] - 48; //Store it's valuei n the dig array
	}
	for (int i = 0; i < a.size(); i++)
	{
		sum += dig[a.size() - 1 - i] * pow(10, i); //use the sum to add all of the values, multiplied by 10 empowered the currently position of i
	}
	return sum; // return the number
}

//This function count the elements in the data.txt file for the trains array
void countTrainElements(int& count)
{
	//Open the data.txt file
	ifstream file;
	file.open("data.txt");
	string counterText;
	//Loop trough each line of the file
	while (getline(file, counterText))
	{
		//If the line has ':::' we increment the count, as we use ':::' as a divider between the individual elements
		if (counterText == ":::")
			count++; //count is a pseudonym, so its original value is impacted
	}
	file.close();
}

//This function count the elements in the data.txt file for the reservations array
void countReservationElements(int& count)
{
	//Open the reservationData.txt file
	ifstream file;
	file.open("reservationData.txt");
	string counterText;
	//Loop trough all of it's lines
	while (getline(file, counterText))
	{
		//If the line has ':::' we increment the count, as we use ':::' as a divider between the individual elements
		if (counterText == ":::")
			count++; //count is a pseudonym, so its original value is impacted
	}
	file.close();
}

//This function gets the maxId of the elements in the trains array
void getTrainMaxId(TRAIN* trains, int& maxId, int count)
{
	//We use count to see wether there are no elements in the array
	if (count == 0)
		maxId = 50; //If so we set the maxId to 50
	else
		maxId = trains[count - 1].id; //Otherwise we use the next to last element's id as the max Id
}

//This function gets the maxId of the elements in the trains array
void getReservationMaxId(RESERVATION* reservations, int& maxId, int count)
{
	//We use count to see wether there are no elements in the array
	if (count == 0)
		maxId = 0; //If so we set the maxId to 0
	else
		maxId = reservations[count - 1].reservedId; //Otherwise we use the next to last element's id as the max Id
}