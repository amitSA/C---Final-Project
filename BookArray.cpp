/* File that holds information of the functions from 
the BookArray class
*/
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
//Mutators
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
/***************************************************
Setting up the date the hard way
*/
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
/***************************************************
Function used to convert the name of a month to a 
numberically value to easily sort by date
*/
int BookInfo::monthConvert(BookInfo *book, int position)
{
	//Strings for all of the months to compare to the book's info
	string m1 = "January";
	string m2 = "February";
	string m3 = "March";
	string m4 = "April";
	string m5 = "May";
	string m6 = "June";
	string m7 = "July";
	string m8 = "August";
	string m9 = "September";
	string m10 = "October";
	string m11 = "November";
	string m12 = "December";

	int convert; //variable that will act as the converted month and will be return

	//If the book's month matches one of the strings,
	//convert will equal the numberical value of that month
	if(m1.compare(book[position].month) == 0)
	{
		convert = 1;
	}
	if(m2.compare(book[position].month) == 0)
	{
		convert = 2;
	}
	if(m3.compare(book[position].month) == 0)
	{
		convert = 3;
	}
	if(m4.compare(book[position].month) == 0)
	{
		convert = 4;
	}
	if(m5.compare(book[position].month) == 0)
	{
		convert = 5;
	}
	if(m6.compare(book[position].month) == 0)
	{
		convert = 6;
	}
	if(m7.compare(book[position].month) == 0)
	{
		convert = 7;
	}
	if(m8.compare(book[position].month) == 0)
	{
		convert = 8;
	}
	if(m9.compare(book[position].month) == 0)
	{
		convert = 9;
	}
	if(m10.compare(book[position].month) == 0)
	{
		convert = 10;
	}
	if(m11.compare(book[position].month) == 0)
	{
		convert = 11;
	}
	if(m12.compare(book[position].month) == 0)
	{
		convert = 12;
	}

	return convert;
}

//More mutators...yay
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
