
#include "ReportModule.h"
#include <vector>
#include <iostream>
#include "Book.h"



ReportModule::ReportModule(BookList*b) : Module(b)
{
}


/*Psuedo Code
     - ask the user if the want to Display the inventory
	 - display and tally the Wholesale valaue
	 - display and tally the retail value
	 - list by quantity
	 - list by cost
	 - list by age
	 - or return to the main menu

	 the selection sort algorithim
	 - locate the i-th smallest element in the AccountInfo array
	 - move the i-th smallest element to the i-th position, and move the element which was previously at the i-th index into the now vacant indice
	 - call the recursive function again
	 - base case: if the int i is == size-1, then return out of method
 */
void ReportModule::act()
{
	bookList->readFromFile();
	char cInput;
	cout << "|         Report Module          |\n";
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
	
	while (!readChar(cInput) || ((cInput < '1') || (cInput > '7'))) {
		cout << "\nPlease enter a number between 1 and 7: ";
	}
	if (cInput == '1')
		cout << displayInventory();
	else if (cInput == '2')
		cout << displayWholeSaleValue();
	else if (cInput == '3')
		cout << displayByRetailValue();
	else if (cInput == '4')
		cout << listByQuantity();
	else if (cInput == '5')
		cout << listByCost();
	else if (cInput == '6')
		cout << listByDate();
	//else answer == 7, then just let the method end
}

string ReportModule::displayInventory()
{
	return bookList->listBooks(Book::EVERYTHING);
}

string ReportModule::displayWholeSaleValue()
{
	string s = bookList->listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME | Book::WCOST);
	s += "\n\nTotal Wholesale Value: " + to_string(bookList->tally(Book::WCOST));
	return s;
}
string ReportModule::displayByRetailValue()
{
	string s = bookList->listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME | Book::RET);
	s += "\n\nTotal Retail Value: " + to_string(bookList->tally(Book::RET));
	return s;
}
string ReportModule::listByQuantity()
{
	sort(lQT);
	return bookList->listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME | Book::QUANT);
	
}
string ReportModule::listByCost()
{
	sort(lWSVAL);
	return bookList->listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME|Book::WCOST);
}
string ReportModule::listByDate()
{
	sort(lDT);
	return bookList->listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME | Book::DATE);
}


void ReportModule::sort(int st)
{
	int i, j, first;
	Book temp; 
	int numLength = bookList->getSize();
	for (i = 0; i < numLength; i++) {
		first = i;                
		for (j = i; j < numLength; j++) {   

			if (st == lQT){
				if ((*bookList)[j].getQuantity() < (*bookList)[first].getQuantity())
					first = j;
			}
			else if (st == lWSVAL){
				if ((*bookList)[j].getWholesaleCost() <(*bookList)[first].getWholesaleCost())
					first = j;
			}
			else if (st == lDT){
				if ((*bookList)[j].getDate() < (*bookList)[first].getDate())
					first = j;
			}
		}
		temp = (*bookList)[first];   // Swap smallest found with element in position i.
		(*bookList)[first] = (*bookList)[i];
		(*bookList)[i] = temp;
	}
}


