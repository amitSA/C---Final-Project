//ADD THE STATEMENTS WHICH PROTECTS AGAINST C-FUNCTION COMPILER ERRORS

#include "Module.h"
#include <iostream>
#include <string>
#include "Book.h"
#include <vector>

using namespace std;

Module::Module(BookList *b)
{
	this->bookList = b;
}

bool Module::readString(string& strP)        // this method will be always called if a module wants to take in any type of string formatted user input
{
	char cArray[500];
	cin.getline(cArray, 500, '\n\r');
	cin.clear();
	strP = cArray;
	return true;

}

bool Module::readInt(int &intP)         // this method will be always called if a module wants to take in any type of double formatted user input
{
	bool returnVal;
	char cArray[500];
	cin.getline(cArray, 500, '\n\r');


	double d = atof(cArray);
	returnVal = isStringDouble(cArray) & fabs(fmod(d,1))<0.001;  // if the double is divisible by 1, then the double is an integer
	intP = d;

	return returnVal;
}

bool Module::readDouble(double &doubP)
{
	bool returnVal;
	char cArray[500];
	cin.getline(cArray, 500, '\n\r');

	doubP = atof(cArray);
	return isStringDouble(cArray);
}

bool Module::readChar(char &c)
{
	bool returnVal;
	char cArray[500];
	cin.getline(cArray, 500, '\n\r');
	if (*(cArray + 1) != '\0')
		returnVal = false;
	else
		returnVal = true;
	c = *cArray;
	return returnVal;

}

bool Module::isStringDouble(char *cArray)
{
	bool decFlag = true;                                   // a flag indicating 1 decimal point was reached(a number cannot have 2 decimal points)
	for (int i = 0; *(cArray + i) != '\0'; i++)             // cycles through the cstring passed in
	{
		char let = *(cArray + i);
		if (!(isdigit(let) || (decFlag && let == '.')))            // checks if the current character is not a digit or a '.'
			return false;
		if (let == '.')
			decFlag = false;                                       // toggles the flag that 1 decimal point has been reached
	}
	return true;
}