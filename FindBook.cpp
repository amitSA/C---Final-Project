/*
Instructions for functions in the FindBook class
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include "BookArray.h"
#include "FindBook.h"


using namespace std;

/***************************************************
Constructor FindBook: 
*/

/***************************************************
Function find: Integer function that will take a string
arguement (the ISBN code of a book), BookInfo array, and
and an integer (position) and compare the string to the 
ISBNs of the BookArray by the use of a for-loop.
If an ISBN matches the arguement, bool 'found' will be set 
to true and if not, will stay false. The function will 
return the position it was found.
*/
int FindBook::findISBN(string bookCode, BookInfo *book, int position)
{
	for(int i = 0; i < 100; i++) //goes through all 100 books
	{
		if(bookCode.compare(book[i].getISBN(book, i)) == 0) //If there's a ISBN match
		{
			found = true;
			position = i;
			break;
		}
		else //if there's no match
		{
			position = -1;
		}
	}

	return position;
}