// CIS 22B
//Lab 5: Create a trvia game asking 10 questions
//       for 2 players implementing a class.
//Name: Jeffrey Shin

#define CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

///////////////////////////////
#include "BookArray.h"
#include "FindBook.h"
///////////////////////////////

int Main_Menu_Screen();
void Cashier_Screen(/*int*/ BookInfo *book/*[]*/);
void Inventory_Menu_Screen(/*int*/ BookInfo *book/*[]*/); 
void Reports_Menu_Screen(/*int*/ BookInfo *book/*[]*/);
void Loop_Up_Book(/*int*/ BookInfo *books/*[]*/);
void Add_Book(/*int*/ BookInfo *books/*[]*/);
void Edit_Book(/*int*/ BookInfo *books/*[]*/);
void Delete_Book(/*int*/ BookInfo *books/*[]*/);
void Inventory_Listing(/*int*/ BookInfo *books/*[]*/);
void Inventory_Wholesale_Value(/*int*/ BookInfo *books/*[]*/);
void Inventory_Retail_Value(/*int*/ BookInfo *books/*[]*/);
void Sort_By_Quantity(/*int*/ BookInfo *books/*[]*/);
void Sort_By_Cost(/*int*/ BookInfo *books/*[]*/);
//void Sort_By_Age(/*int*/ BookInfo *books/*[]*/); //commented this out because I don't understand what is going on
void Print_Books(/*int*/ BookInfo *books/*[]*/);

struct Inventory {
	string ISBN;
	string Title;
	string Author;
	string Publisher;
	string Date_Added;
	int Quantity_On_Hand;
	double Wholesale_Cost;
	double Retail_Price;
};

int main(int argc, char *argv[]) {

	/* //////////////////////////////////////////////////////////////
	*/

	fstream file; //Stream object; used to open BookList file
	int numOfBooks = 2; //Number of books listed

	BookInfo *book;
	book = new BookInfo[numOfBooks]; //array of objects


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
	/* ///////////////////////////////////////////////////////////////////////
	*/

	//Inventory books[100];	//10 instances of Question class
	/*Inventory * ptr = new Inventory[100];
	int books[6] = { 500, 1000, 2, 3, 17, 50};
	//int n = sizeof(books) / sizeof(books[0]);*/
	int answer;

	do {
		answer = Main_Menu_Screen();
		if (answer == 1) {
			Cashier_Screen(book);
		}
		else if (answer == 2) {
			Inventory_Menu_Screen(book);
		}
		else if (answer == 3) {
			Reports_Menu_Screen(book);
		}
	} while(answer != 4);   //keep looping while answer is not 4, so stops when 4	

	delete [] /*ptr*/book;
	return 0;
}

int Main_Menu_Screen() {
	int answer;

	cout << "|================================|\n";
	//<< setprecision(2) << fixed << right << setw(7) 
	cout << "|    Serendipity Booksellers     |\n";
	cout << "|           Main Menu            |\n";
	cout << "|  1. Cashier Module             |\n";
	cout << "|  2. Inventory Database Module  |\n";
	cout << "|  3. Report Module              |\n";
	cout << "|  4. Exit                       |\n";
	cout << "|                                |\n";
	cout << "|  Enter Your Choice: ";	
	while ( !(cin >> answer) || ((answer < 1) || (answer > 4)) ) {
		cout << "\nPlease enter a number between 1 and 4: ";
		cin.clear();
		cin.ignore(80, '\n');
	}	
	cout << "|================================|\n\n";

	return answer;
}

void Cashier_Screen(/*int*/BookInfo *book/*[]*/) {
	cout << "|=========================================================================|\n";
	cout << "|    Serendipity Book Sellers                                             |\n";
	cout << "|                                                                         |\n";
	cout << "|    Date:                                                                |\n";
	cout << "|                                                                         |\n";
	cout << "|  Qty  ISBN\t\tTitle\t\t\t\tPrice\tTotal     |\n";
	cout << "|  ____________________________________________________________________   |\n";
	cout << "|  1    1234567890                                                        |\n";
	cout << "|                                                                         |\n";
	cout << "|  Subtotal:                                                              |\n";
	cout << "|  Tax:                                                                   |\n";
	cout << "|  Total:                                                                 |\n";
	cout << "|                                                                         |\n";
	cout << "|  Thank You for Shopping at Serendipity!                                 |\n";
	cout << "|                                                                         |\n";
	cout << "|=========================================================================|\n\n";
}

void Inventory_Menu_Screen(/*int*/BookInfo *book/*[]*/) {
	int answer;

	cout << "|===============================|\n";
	cout << "|    Serendipity Booksellers    |\n";
	cout << "|      Inventory Database       |\n";
	cout << "|  1. Look Up a Book            |\n";
	cout << "|  2. Add a Book                |\n";
	cout << "|  3. Edit a Book's Record      |\n";
	cout << "|  4. Delete a Book             |\n";
	cout << "|  5. Return to the Main Menu   |\n";
	cout << "|                               |\n";
	cout << "|  Enter Your Choice: ";	
	while ( !(cin >> answer) || ((answer < 1) || (answer > 5)) ) {
		cout << "\nPlease enter a number between 1 and 5: ";
		cin.clear();
		cin.ignore(80, '\n');
	}	
	cout << "|===============================|\n\n";

	if (answer == 1) {
		Loop_Up_Book(book);
	}
	else if (answer == 2) {
		Add_Book(book);
	}
	else if (answer == 3) {
		Edit_Book(book);
	}
	else if (answer == 4) {
		Delete_Book(book);
	}
	else {
		Main_Menu_Screen();
	}
}

void Loop_Up_Book(/*int*/BookInfo *book/*[]*/) {
	//////////////////////////////////////////
	FindBook f; //FindBook object

	int position = -1; //for the found position of the book

	string bookCode; //user defined variable
	cout << "Please enter the unique ISBN code of the book: " << endl;
	cin >> bookCode;

	position = f.findISBN(bookCode, book, position); //Call to function in FindBook class

	if(position != -1) //If the book was found (-1 means the book wasn't found)
	{
		//output the results
		cout << "Found result:" << endl;

	cout << "|===========================================|\n";
	cout << "|        Look Up Book                       |\n";	
	cout << "|===========================================|\n";
	cout << "|    Serendipity Booksellers                |\n";
	cout << "|        Book Information                   |\n";
	cout << "|                                           |\n";
	cout << "|  ISBN: " << book[position].getISBN(book, position) << "                                   |\n";
	cout << "|  Title: "  << book[position].getBookTitle() <<  "                              |\n";
	cout << "|  Author: " << book[position].getAuthorName() << "                                 |\n";
	cout << "|  Publisher: " << book[position].getPublisher() << "                              |\n";
	cout << "|  Date Added: " << book[position].getDate() << "                             |\n";
	cout << "|  Quantity-On-Hand: " << book[position].getQuantity() << "                       |\n";
	cout << "|  Wholesale Cost: " << book[position].getCost() << "                         |\n";
	cout << "|  Retail Price: " << book[position].getRetail() << "                           |\n";
	cout << "|===========================================|\n\n";
	}
	else //if book was not found
	{
		cout << "Book was not found." << endl;
	}
	/////////////////////////////////////////////////////////////////////////////////////////
}
void Add_Book(/*int*/BookInfo *book/*[]*/) {
	/*Same logic as delete book but opposite:
	Add 1 to numOfBooks, write the new book info to
	a new file along with the already existing books
	Replace the old text file with this new one
	*/

	cout << "|===========================================|\n";
	cout << "|        Add Book                           |\n";	
	cout << "|===========================================|\n";
	cout << "|    Serendipity Booksellers                |\n";
	cout << "|        Book Information                   |\n";
	cout << "|                                           |\n";
	cout << "|  ISBN:                                    |\n";
	cout << "|  Title:                                   |\n";
	cout << "|  Author:                                  |\n";
	cout << "|  Publisher:                               |\n";
	cout << "|  Date Added:                              |\n";
	cout << "|  Quantity-On-Hand:                        |\n";
	cout << "|  Wholesale Cost:                          |\n";
	cout << "|  Retail Price:                            |\n";
	cout << "|===========================================|\n\n";
}
void Edit_Book(/*int*/BookInfo *book/*[]*/) {
	///////////////////////////////////////////////////////////////////////////////////////////////////Are we also changing the info in the text file?
	FindBook f; //FindBook object

	int position = -1; //for the found position of the book

	int change; //user defined variable to state what they want to edit
	char choice; //user defined char that goes with the do-while loop

	string bookCode; //user defined variable
	//Need to find if the book exists first before you can edit it.
	cout << "Please enter the unique ISBN code of the book you wish to edit: " << endl;
	cin >> bookCode;

	position = f.findISBN(bookCode, book, position); //Call to function in FindBook class

	if(position != -1) //If the book was found (-1 means the book wasn't found)
	{
		do //do-while loop to allow the user to keep editting the book info to their heart's content
		{
		//Ask the user what they want to change
		cout << "What would you like to edit? " << endl;
		cout << "1. ISBN\n";
		cout << "2. Title:\n";
		cout << "3. Author\n";
		cout << "4. Publisher\n";
		cout << "5. Date Added\n";
		cout << "6. Quantity-On-Hand\n";
		cout << "7. Wholesale Cost\n";
		cout << "8. Retail Price\n";
		cout << "Please enter the corresponding number: " << endl;
		cin >> change;

		//Input check
		while(cin.fail() || change > 8 || change < 1)
		{
			cout << "That was not a valid input." << endl;
			cout << "Please try again" << endl;
			cin >> change;
		}

		string newChange; //user defined variable to change the data of a book

		//Depending on what the user chose...
		//They can edit the field of the corresponding number
		if(change == 1)
		{
			//Get variable newChange
			cout << "What do you want to change the ISBN to?" << endl;
			cin >> newChange;

			book[position].ISBN = newChange; //change the info from the book to newChange value
		}
		if(change == 2)
		{
			//Get variable newChange
			cout << "What do you want to change the Title to?" << endl;
			cin >> newChange;

			book[position].bookTitle = newChange; //change the info from the book to newChange value
		}
		if(change == 3)
		{
			//Get variable newChange
			cout << "What do you want to change the author to?" << endl;
			cin >> newChange;

			book[position].authorName = newChange; //change the info from the book to newChange value
		}
		if(change == 4)
		{
			//Get variable newChange
			cout << "What do you want to change the publisher to?" << endl;
			cin >> newChange;

			book[position].publisher = newChange; //change the info from the book to newChange value
		}
		if(change == 5)
		{
			//date has 3 parts therefore, there must be three different input values
			string newChange1; //month
			string newChange2; //day
			string newChange3; //year

			//Get variable newChange
			cout << "What do you want to change the date to?" << endl;
			cout << "Month: ";
			cin >> newChange1;
			cout << "Day: ";
			cin >> newChange2;
			cout << "Year: ";
			cin >> newChange3;

			book[position].month = newChange1; //change the info from the book to newChange value
			book[position].day = newChange2;
			book[position].year = newChange3;
		}
		if(change == 6)
		{
			//Get variable newChange
			cout << "What do you want to change the quantity to?" << endl;
			cin >> newChange;

			book[position].quantity = newChange; //change the info from the book to newChange value
		}
		if(change == 7)
		{
			//Get variable newChange
			cout << "What do you want to change the cost to?" << endl;
			cin >> newChange;

			book[position].cost = newChange; //change the info from the book to newChange value
		}
		if(change == 8)
		{
			//Get variable newChange
			cout << "What do you want to change the resale value to?" << endl;
			cin >> newChange;

			book[position].retail = newChange; //change the info from the book to newChange value
		}

	
		cout << "Is there anything else you wish to edit from this book?" << endl;
		cin >> choice;

		//Input check
		while(choice != 'n' && choice != 'N'&& choice != 'y' && choice != 'Y')
		{
			cout << "That was not a valid input." << endl;
			cout << "Please try again" << endl;
			cin >> choice;
		}

		}
		while(choice != 'n' && choice != 'N');

		//Display the editted and non-editted book information
	cout << "New book information: " << endl;

	cout << "|===========================================|\n";
	cout << "|        Edit Book                          |\n";	
	cout << "|===========================================|\n";
	cout << "|    Serendipity Booksellers                |\n";
	cout << "|        Book Information                   |\n";
	cout << "|                                           |\n";
	cout << "|  ISBN: " << book[position].getISBN(book, position) << "                                   |\n";
	cout << "|  Title: "  << book[position].getBookTitle() <<  "                              |\n";
	cout << "|  Author: " << book[position].getAuthorName() << "                                 |\n";
	cout << "|  Publisher: " << book[position].getPublisher() << "                              |\n";
	cout << "|  Date Added: " << book[position].getDate() << "                             |\n";
	cout << "|  Quantity-On-Hand: " << book[position].getQuantity() << "                       |\n";
	cout << "|  Wholesale Cost: " << book[position].getCost() << "                         |\n";
	cout << "|  Retail Price: " << book[position].getRetail() << "                           |\n";
	cout << "|===========================================|\n\n";
		}
	else //if book was not found
	{
		cout << "Book was not found." << endl;
	}
	/////////////////////////////////////////////////////////////////////////////////////////
}
void Delete_Book(/*int*/BookInfo *book/*[]*/) {
	//////////////////////////////////////////
	FindBook f; //FindBook object

	char answer; //user defined variable to confirm the book deletion

	int position = -1; //for the found position of the book

	string bookCode; //user defined variable

	//Need to find if the book exists first before you can delete it.
	cout << "Please enter the unique ISBN code of the book: " << endl;
	cin >> bookCode;
	
	position = f.findISBN(bookCode, book, position); //Call to function in FindBook class

	if(position != -1) //If the book was found (-1 means the book wasn't found)
	{

	cout << "|===========================================|\n";
	cout << "|        Delete Book                        |\n";	
	cout << "|===========================================|\n";
	cout << "|    Serendipity Booksellers                |\n";
	cout << "|        Book Information                   |\n";
	cout << "|                                           |\n";
	cout << "|  ISBN: " << book[position].getISBN(book, position) << "                                   |\n";
	cout << "|  Title: "  << book[position].getBookTitle() <<  "                              |\n";
	cout << "|  Author: " << book[position].getAuthorName() << "                                 |\n";
	cout << "|  Publisher: " << book[position].getPublisher() << "                              |\n";
	cout << "|  Date Added: " << book[position].getDate() << "                             |\n";
	cout << "|  Quantity-On-Hand: " << book[position].getQuantity() << "                       |\n";
	cout << "|  Wholesale Cost: " << book[position].getCost() << "                         |\n";
	cout << "|  Retail Price: " << book[position].getRetail() << "                           |\n";
	cout << "|===========================================|\n\n";

		//Ask the user if they really want to delete this book from the array
		cout << "Is this the book you wish to delete?" << endl;
		cout << "Y/N" << endl;
		cin >> answer;

		//Input check 
		while(cin.fail() || answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
		{
			cout << "That was not a valid input." << endl;
			cout << "Please try again" << endl;
			cin >> answer;
		}

		//If the book is confirmed for deletion
		if(answer == 'y' || answer == 'Y')
		{
			/*Depending if we want to deal with the text file and the array of just the array:
			Erase the book info from the text file, minus 1 from numOfBooks, and 
			resumbit the "new" text file (the file without the deleted book) into
			the book array*/

			cout << "The book was deleted." << endl;
		}
		else
		{
			cout << "The book was not deleted. " << endl;
		}

	}
	else //if book was not found
	{
		cout << "Book was not found." << endl;
	}
	/////////////////////////////////////////////////////////////////////////////////////////
}

void Reports_Menu_Screen(/*int*/BookInfo *book/*[]*/) {
	int answer;

	cout << "|================================|\n";
	cout << "|    Serendipity Booksellers     |\n";
	cout << "|            Reports             |\n";
	cout << "|                                |\n";
	cout << "|  1. Inventory Listing          |\n";
	cout << "|  2. Inventory Wholesale Value  |\n";
	cout << "|  3. Inventory Retail Value     |\n";
	cout << "|  4. Listing by Quantity        |\n";
	cout << "|  5. Listing by Cost            |\n";
	cout << "|  6. Listing by Age             |\n";
	cout << "|  7. Return to the Main Menu    |\n";
	cout << "|                                |\n";
	cout << "|  Enter Your Choice: ";	
	while ( !(cin >> answer) || ((answer < 1) || (answer > 7)) ) {
		cout << "\nPlease enter a number between 1 and 5: ";
		cin.clear();
		cin.ignore(80, '\n');
	}	
	cout << "|================================|\n\n";

	if (answer == 1) {
		Inventory_Listing(book);
	}
	else if (answer == 2) {
		Inventory_Wholesale_Value(book);
	}
	else if (answer == 3) {
		Inventory_Retail_Value(book);
	}
	else if (answer == 4) {
		Sort_By_Quantity(book);
	}
	else if (answer == 5) {
		Sort_By_Cost(book);
	}
	else if (answer == 6) {
		//Sort_By_Age(book); //commented this out because I don't understand what is going on
	}
	else {
		Main_Menu_Screen();
	}
}

void Inventory_Listing(/*int*/BookInfo *book/*[]*/) {
	cout << "|===============================|\n";
	cout << "|       Inventory Listing       |\n";
	Print_Books(book);
}
void Inventory_Wholesale_Value(/*int*/BookInfo *book/*[]*/) {
	cout << "|===============================|\n";
	cout << "|   Inventory Wholesale Value   |\n";
	Print_Books(book);
}
void Inventory_Retail_Value(/*int*/BookInfo *book/*[]*/) {
	cout << "|===============================|\n";
	cout << "|     Inventory Retail Value    |\n";
	Print_Books(book);
}
void Sort_By_Quantity(/*int*/BookInfo *book/*[]*/) {
	int i, j, first, temp;
	int numLength = 6;
	for (i = numLength - 1; i > 0; i--) {
		first = 0;                 // initialize to subscript of first element
		for (j=1; j<=i; j++) {    // locate smallest between positions 1 and i.
			if (book[j].getQuantity() < book[first].getQuantity())
			first = j;
		}//convert string to int
		temp = atoi(book[first].getQuantity().c_str());   // Swap smallest found with element in position i.
		book[first].getQuantity() = book[i].getQuantity();
		book[i].getQuantity() = temp;
	}
	cout << "|===============================|\n";
	cout << "|        List by Quantity       |\n";
	Print_Books(book);
	return;
}
void Sort_By_Cost(/*int*/BookInfo *book/*[]*/) {
	int i, j, first, temp;
	int numLength = 6;
	for (i = numLength - 1; i > 0; i--) {
		first = 0;                 // initialize to subscript of first element
		for (j=1; j<=i; j++) {    // locate smallest between positions 1 and i.
			if (book[j].getCost() < book[first].getCost())
			first = j;
		} //convert string to int
		temp = atoi(book[first].getCost().c_str());   // Swap smallest found with element in position i.
		book[first].getCost() = book[i].getCost();
		book[i].getCost() = temp;
	}
	cout << "|===============================|\n";
	cout << "|          List by Cost         |\n";
	Print_Books(book);
	return;
} //commented this out because I don't understand what is going on
/*void Sort_By_Age(/*int BookInfo *book/*[]) { /////////////////////////////////////////////////////////////////////////////////////Date?
	int i, j, first, temp;
	int numLength = 6;
	for (i = numLength - 1; i > 0; i--) {
		first = 0;                 // initialize to subscript of first element
		for (j=1; j<=i; j++) {    // locate smallest between positions 1 and i.
			if (book[j] < book[first])
			first = j;																///////////////////////////////////////////////////Date needs to be sorted by year, month and date because it is a 3D array.
																																		
		}
		temp = book[first];   // Swap smallest found with element in position i.
		book[first] = book[i];
		book[i] = temp;
	}
	cout << "|===============================|\n";
	cout << "|           List by Age         |\n";
	Print_Books(book);
	return;
}*/

void Print_Books(/*int*/BookInfo *book/*[]*/) {
	int numLength = 6;
	for (int i = 0; i < numLength; i ++) {
		cout << "|  "<< book[i].getISBN(book, i) << "                |\n";
		cout << "|  "<< book[i].getBookTitle() << "                |\n";
		cout << "|  "<< book[i].getAuthorName() << "                |\n";
		cout << "|  "<< book[i].getPublisher() << "                |\n";
		cout << "|  "<< book[i].getDate() << "                |\n";
		cout << "|  "<< book[i].getQuantity() << "                |\n";
		cout << "|  "<< book[i].getCost() << "                |\n";
		cout << "|  "<< book[i].getRetail() << "                |\n";
	}
	cout << "|===============================|\n\n";	
	return;
}