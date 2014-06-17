#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "BookArray.h"

using namespace std;

BookInfo::BookInfo()
{

	//set all variables to a 'default' value
	ISBN = "";
	bookTitle = "";
	authorName = "";
	publisher = "";

	month = "";
	day = "";
	year = "";

	quantity = "";
	cost = "";
	retail = "";

}

void BookInfo::setISBN(string number)
{
	ISBN = number;
}

void BookInfo::setBookTitle(string title)
{
	bookTitle = title;
}

void BookInfo::setAuthorName(string Aname)
{
	authorName = Aname;
}

void BookInfo::setPublisher(string pub)
{
	publisher = pub;
}

void BookInfo::setMonth(string mon)
{
	month = mon;
}

void BookInfo::setDay(string d)
{
	day = d;
}

void BookInfo::setYear(string yr)
{
	year = yr;
}

void BookInfo::setDate()
{
	//Putting the month, day and year into the date array.
		date = new string**[month.length()]; //creating the size of the month name for the 3D array

		for(int i = 0; i < month.length(); i++)
		{

		date[i] = new string*[day.length()]; //same for day

		for(int j = 0; j < day.length(); j++)
		{

			date[i][j] = new string[year.length()]; //and year
		}

		}

		//Now accessing the 3D array to input the value of month, date and year
		for(int i = 0; i < month.length(); i++)
		{
			for(int j = 0; j < day.length(); j++)
			{
				for(int k = 0; k < year.length(); k++)
				{
					date[i][j][k] = month + day + year; //In order of a written date
				}
			}
		}
}

void BookInfo::setQuantity(string number)
{
	quantity = number;
}

void BookInfo::setCost(string price)
{
	cost = price;
}

void BookInfo::setRetail(string sellBack)
{
	retail = sellBack;
}
