#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "InventoryDatabaseModule.h"
#include "ReportModule.h"
#include "BookList.h"
#include "CashierModule.h"
#include <iomanip>


using namespace std;

/*Pseudo Code
-Initialize all the modules
-In a while loop, ask the user for which module they want to enter
  - if they choose 1, then go into Cashier Module
  - if they chooes 2, then go into InventoryDataBase Module
  - if they choose 3, then go inside Report Module
  - if they choose 4, then exit the program
*/

int main()
{
	BookList bookList{ "BookList.txt" };
	bookList.readFromFile();
	ReportModule repModule{ &bookList };
	InventoryDatabaseModule invModule{ &bookList };
	CashierModule cashModule{ &bookList };

	char cInput;
	do{
		cout << "|================================|\n";
		cout << "|    Serendipity Booksellers     |\n";
		cout << "|           Main Menu            |\n";
		cout << "|  1. Cashier Module             |\n";
		cout << "|  2. Inventory Database Module  |\n";
		cout << "|  3. Report Module              |\n";
		cout << "|  4. Exit Program               |\n";
		cout << "|                                |\n";
		cout << "|  Enter Your Choice: ";
		 while (!repModule.readChar(cInput) || (cInput < '1') || (cInput > '4'))   // just calling the readChar in report module, it returns true, if the user actually entered in a char
			 cout << "Invalid Input, Please enter a number between 1 and 4: ";      // error checkings
		 if (cInput == '1'){
			 cout << endl << endl;
			 cashModule.act();                               
		 }else if (cInput == '2'){
			 cout << endl << endl;
			 invModule.act();
		 }else if (cInput == '3'){
			 cout << endl << endl;
			 repModule.act();
		 }//else if (cInput = '4') then just exit the while loop and finish executing the program 
		 cout << endl << endl;
	} while (cInput != '4');

	return 0;
}



/*
int main()
{
	string s = "Hello People, \nmy name is Amit Saxena";
	cout << "1" << setw(5) << ")" <<s;

	cin.get();
}*/

/*
cout << bookList.listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME | Book::PUB  | Book::QUANT | Book::WCOST | Book::RET | Book::DATE) << endl;
*/