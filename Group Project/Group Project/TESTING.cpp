// FinalProject.cpp : Defines the entry point for the console application.
//this is the main which nicholette made


#include <iostream>
#include <string>
#include <fstream>
#include "BookArray.h"

using namespace std; //////////////////////Find a way to return a 3d array! 6/4/14


/*
int main()
{
	fstream file; //Stream object; used to open BookList file
	int numOfBooks = 2; //Number of book listed

	BookInfo *book;
	book = new BookInfo[numOfBooks];


	string fileInfo; //Used to hold the file's input

	file.open("BookList.txt", ios::in); //open file

	if(file) //if file openned
	{
		//Placing the data from the file to the correct array 'book'
		for(int j = 0; j < numOfBooks; j++)
		{
			for(int i = 0; i < 10; i++)
		{
			if(i == 0) //To set ISBN
			{
				 getline(file, fileInfo); //get a line from the file
				 book[j].setISBN(fileInfo);
			}
			if(i == 1) //To set Title
			{
				 getline(file, fileInfo); //get a line from the file
				 book[j].setBookTitle(fileInfo);
			}
			if(i == 2)//To set Author
			{
				 getline(file, fileInfo); //get a line from the file
				 book[j].setAuthorName(fileInfo);
			}
			if(i == 3)//To set Publisher
			{
				 getline(file, fileInfo); //get a line from the file
				 book[j].setPublisher(fileInfo);
			}
			if(i == 4)//To set month
			{
				 getline(file, fileInfo); //get a line from the file
				 book[j].setMonth(fileInfo);
			}
			if(i == 5)//To set day
			{
				 getline(file, fileInfo); //get a line from the file
				 book[j].setDay(fileInfo);
			}
			if(i == 6)//To set year
			{
				 getline(file, fileInfo); //get a line from the file
				 book[j].setYear(fileInfo);
			}
			if(i == 7)//To set Quantity
			{
				 getline(file, fileInfo); //get a line from the file
				 book[j].setQuantity(fileInfo);
			}
			if(i == 8)//To set Cost
			{
				 getline(file, fileInfo); //get a line from the file
				 book[j].setCost(fileInfo);

			}
			if(i == 9)//To set Retail
			{
				 getline(file, fileInfo); //get a line from the file
				 book[j].setRetail(fileInfo);

			}

		}
			book[j].setDate(); //get date
			
		}
	}

	else //if the file failed to open
	{
		cout << "The program has failed. Please contact IT support." << endl;
	}

	//to display the books or a book
	for(int i = 0; i < numOfBooks; i++)
	{
		cout << book[i].getISBN() << endl;
		cout << book[i].getBookTitle() << endl;
		cout << book[i].getAuthorName() << endl;
		cout << book[i].getPublisher() << endl;
		cout << book[i].getDate() << endl;
		cout << book[i].getQuantity() << endl;
		cout << book[i].getCost() << endl;
		cout << book[i].getRetail() << endl;
	}

	

	return 0;
}



///Book array of 100 books


/*

/*cout << book.ISBN << endl;
cout << book.bookTitle << endl;
cout << book.authorName << endl;
cout << book.publisher << endl;

for(int i = 0; i < 1; i++)
{
for(int j = 0; j < 1; j++)
{
for(int k = 0; k < 1; k++)
{
cout << book.date[i][j][k] << endl;
}
}
}

//	cout << book.date << endl;

cout << book.quantity << endl;
cout << book.cost << endl;
cout << book.retail << endl;*/