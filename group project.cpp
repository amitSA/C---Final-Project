// CIS 22B
//Lab 5: Create a trvia game asking 10 questions
//       for 2 players implementing a class.
//Name: Jeffrey Shin

#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

int Main_Menu_Screen();
void Cashier_Screen(int books[]);
void Inventory_Menu_Screen(int books[]); 
void Reports_Menu_Screen(int books[]);
void Loop_Up_Book(int books[]);
void Add_Book(int books[]);
void Edit_Book(int books[]);
void Delete_Book(int books[]);
void Inventory_Listing(int books[]);
void Inventory_Wholesale_Value(int books[]);
void Inventory_Retail_Value(int books[]);
void Sort_By_Quantity(int books[]);
void Sort_By_Cost(int books[]);
void Sort_By_Age(int books[]);
void Print_Books(int books[]);

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
	//Inventory books[100];	//10 instances of Question class
	Inventory * ptr = new Inventory[100];
	int books[6] = { 500, 1000, 2, 3, 17, 50};
	//int n = sizeof(books) / sizeof(books[0]);
	int answer;

	do {
		answer = Main_Menu_Screen();
		if (answer == 1) {
			Cashier_Screen(books);
		}
		else if (answer == 2) {
			Inventory_Menu_Screen(books);
		}
		else if (answer == 3) {
			Reports_Menu_Screen(books);
		}
	} while(answer != 4);   //keep looping while answer is not 4, so stops when 4	

	delete [] ptr;
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

void Cashier_Screen(int books[]) {
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

void Inventory_Menu_Screen(int books[]) {
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
		Loop_Up_Book(books);
	}
	else if (answer == 2) {
		Add_Book(books);
	}
	else if (answer == 3) {
		Edit_Book(books);
	}
	else if (answer == 4) {
		Delete_Book(books);
	}
	else {
		Main_Menu_Screen();
	}
}

void Loop_Up_Book(int books[]) {
	cout << "|===========================================|\n";
	cout << "|        Loop Up Book                       |\n";	
	cout << "|===========================================|\n";
	cout << "|    Serendipity Booksellers                |\n";
	cout << "|        Book Information                   |\n";
	cout << "|                                           |\n";
	cout << "|  ISBN:                                    |\n";
	cout << "|  Title:                                   |\n";
	cout << "|  Autheor:                                 |\n";
	cout << "|  Publisher:                               |\n";
	cout << "|  Date Added:                              |\n";
	cout << "|  Quantity-On-Hand:                        |\n";
	cout << "|  Wholesale Cost:                          |\n";
	cout << "|  Retail Price:                            |\n";
	cout << "|===========================================|\n\n";
}
void Add_Book(int books[]) {
	cout << "|===========================================|\n";
	cout << "|        Add Book                           |\n";	
	cout << "|===========================================|\n";
	cout << "|    Serendipity Booksellers                |\n";
	cout << "|        Book Information                   |\n";
	cout << "|                                           |\n";
	cout << "|  ISBN:                                    |\n";
	cout << "|  Title:                                   |\n";
	cout << "|  Autheor:                                 |\n";
	cout << "|  Publisher:                               |\n";
	cout << "|  Date Added:                              |\n";
	cout << "|  Quantity-On-Hand:                        |\n";
	cout << "|  Wholesale Cost:                          |\n";
	cout << "|  Retail Price:                            |\n";
	cout << "|===========================================|\n\n";
}
void Edit_Book(int books[]) {
	cout << "|===========================================|\n";
	cout << "|        Edit Book                          |\n";	
	cout << "|===========================================|\n";
	cout << "|    Serendipity Booksellers                |\n";
	cout << "|        Book Information                   |\n";
	cout << "|                                           |\n";
	cout << "|  ISBN:                                    |\n";
	cout << "|  Title:                                   |\n";
	cout << "|  Autheor:                                 |\n";
	cout << "|  Publisher:                               |\n";
	cout << "|  Date Added:                              |\n";
	cout << "|  Quantity-On-Hand:                        |\n";
	cout << "|  Wholesale Cost:                          |\n";
	cout << "|  Retail Price:                            |\n";
	cout << "|===========================================|\n\n";
}
void Delete_Book(int books[]) {
	cout << "|===========================================|\n";
	cout << "|        Delete Book                        |\n";	
	cout << "|===========================================|\n";
	cout << "|    Serendipity Booksellers                |\n";
	cout << "|        Book Information                   |\n";
	cout << "|                                           |\n";
	cout << "|  ISBN:                                    |\n";
	cout << "|  Title:                                   |\n";
	cout << "|  Autheor:                                 |\n";
	cout << "|  Publisher:                               |\n";
	cout << "|  Date Added:                              |\n";
	cout << "|  Quantity-On-Hand:                        |\n";
	cout << "|  Wholesale Cost:                          |\n";
	cout << "|  Retail Price:                            |\n";
	cout << "|===========================================|\n\n";
}

void Reports_Menu_Screen(int books[]) {
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
		Inventory_Listing(books);
	}
	else if (answer == 2) {
		Inventory_Wholesale_Value(books);
	}
	else if (answer == 3) {
		Inventory_Retail_Value(books);
	}
	else if (answer == 4) {
		Sort_By_Quantity(books);
	}
	else if (answer == 5) {
		Sort_By_Cost(books);
	}
	else if (answer == 6) {
		Sort_By_Age(books);
	}
	else {
		Main_Menu_Screen();
	}
}

void Inventory_Listing(int books[]) {
	cout << "|===============================|\n";
	cout << "|       Inventory Listing       |\n";
	Print_Books(books);
}
void Inventory_Wholesale_Value(int books[]) {
	cout << "|===============================|\n";
	cout << "|   Inventory Wholesale Value   |\n";
	Print_Books(books);
}
void Inventory_Retail_Value(int books[]) {
	cout << "|===============================|\n";
	cout << "|     Inventory Retail Value    |\n";
	Print_Books(books);
}
void Sort_By_Quantity(int books[]) {
	int i, j, first, temp;
	int numLength = 6;
	for (i = numLength - 1; i > 0; i--) {
		first = 0;                 // initialize to subscript of first element
		for (j=1; j<=i; j++) {    // locate smallest between positions 1 and i.
			if (books[j] < books[first])
			first = j;
		}
		temp = books[first];   // Swap smallest found with element in position i.
		books[first] = books[i];
		books[i] = temp;
	}
	cout << "|===============================|\n";
	cout << "|        List by Quantity       |\n";
	Print_Books(books);
	return;
}
void Sort_By_Cost(int books[]) {
	int i, j, first, temp;
	int numLength = 6;
	for (i = numLength - 1; i > 0; i--) {
		first = 0;                 // initialize to subscript of first element
		for (j=1; j<=i; j++) {    // locate smallest between positions 1 and i.
			if (books[j] < books[first])
			first = j;
		}
		temp = books[first];   // Swap smallest found with element in position i.
		books[first] = books[i];
		books[i] = temp;
	}
	cout << "|===============================|\n";
	cout << "|          List by Cost         |\n";
	Print_Books(books);
	return;
}
void Sort_By_Age(int books[]) {
	int i, j, first, temp;
	int numLength = 6;
	for (i = numLength - 1; i > 0; i--) {
		first = 0;                 // initialize to subscript of first element
		for (j=1; j<=i; j++) {    // locate smallest between positions 1 and i.
			if (books[j] < books[first])
			first = j;
		}
		temp = books[first];   // Swap smallest found with element in position i.
		books[first] = books[i];
		books[i] = temp;
	}
	cout << "|===============================|\n";
	cout << "|           List by Age         |\n";
	Print_Books(books);
	return;
}

void Print_Books(int books[]) {
	int numLength = 6;
	for (int i = 0; i < numLength; i ++) {
		cout << "|  "<< books[i] << "                |\n";
	}
	cout << "|===============================|\n\n";	
	return;
}