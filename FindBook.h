/*
FindBook is a derived class from BookInfo class that will 
contain a function to find a book in the array of books by 
ISBN codes.
*/
#ifndef FINDBOOK_H
#define FINDBOOK_H
#include "BookArray.h"
#include <iostream>
#include <string>

//class FindBook is derived from BookArray class
class FindBook : public BookInfo
{
protected:
	bool found;

public:
	FindBook()//default/empty constructor
	{

	}

	int findISBN(string, BookInfo *, int);

};

#endif