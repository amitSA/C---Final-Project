/* BookArray class is a class that will hold variables/information
on a certain book such as ISBN codes and book titles.
*/
#ifndef BOOKARRAY_H
#define BOOKARRAY_H
#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

class BookInfo //Class to outline the information of a book
{

public:
	string ISBN; //Int code
	string bookTitle; //Title of the book
	string authorName; //Author's name
	string publisher; //Book's Publisher

	//Aspects of the date that will be stored in date array
	string month;
	string day;
	string year;

	string ***date; //Date when the book was added
	string quantity; //How many copies of the book is there
	string cost; //Price of the book
	string retail; //Sellback price of the book

//public:
	BookInfo(); //Constructor
	int monthConvert(BookInfo *, int);//month conversion function that takes a BookInfo * object and an int

	//Mutators
	void setISBN(string);
	void setBookTitle(string);
	void setAuthorName(string);
	void setPublisher(string);

	void setMonth(string);
	void setDay(string);
	void setYear(string);

	void setDate();
	void setQuantity(string);
	void setCost(string);
	void setRetail(string);
	
	//Accessors
	string getISBN(BookInfo * book, int pos) const
	{

		return book[pos].ISBN;
	}
	string getBookTitle() const
	{
		return bookTitle;
	}
	string getAuthorName() const
	{
		return authorName;
	}
	string getPublisher() const
	{
		return publisher;
	}
	string getMonth() const
	{
		return month;
	}
	string getDay() const
	{
		return day;
	}
	string getYear() const
	{
		return year;
	}
	string ***getDate() const
	{
		return date;
	}
	string getQuantity() const
	{
		return quantity;
	}
	string getCost() const
	{
		return cost;
	}
	string getRetail() const
	{
		return retail;
	}

};

#endif