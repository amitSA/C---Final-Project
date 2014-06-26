#define _CRT_SECURE_NO_WARNINGS
#include "CashierModule.h"

//dont have to include the nampespace again, becuase I have included it from CashierModule


CashierModule::CashierModule(BookList *b) :Module(b)
{
}


void CashierModule::act()
{  
	bookList->readFromFile();
	vector<Book> bookCart;
	cout << "Welcome to the CashierModule" << endl << endl;
	cout << "Here you can add books to your cart by typing all the characters of a books property or only the first couple characters of a books property.";
	cout << "And when your done adding books to your cart, you can proceed to checkout and remove the books you selected from the inventory" << endl;
	cout << endl;
	char cInput;
	do{
		cout << "Type '1' to add items to your cart" << endl;
		cout << "Type '2' to proceed to checkout(and exit the module)" << endl;
		cout << "Type here-----------> ";
		while (!readChar(cInput) || cInput < '1' || cInput > '2')  // this works because all chars are asci values(which are ints) and '1' is lesser than '2' in the asci table
			cout << "Please type in a valid number: ";
		if (cInput == '1')
			addItemToCart(bookCart);
		else // cInput == '2'
			proceedToCheckout(bookCart);
	} while (cInput != '2');
	bookList->writeToFile();
}

void CashierModule::addItemToCart(vector<Book>&bookCart)
{
	char cInput;
	Book copyBook;
	Book *bPtr = NULL;
	cout << endl << endl << "Type '1' To select a book by ISBN" << endl;
	cout << "Type '2' To select a book by Book Title" << endl;
	cout << "Type here-----------> ";
	while (!readChar(cInput) || (cInput < '1') || (cInput > '2')) {
		cout << "Please enter a number between 1 and 2: ";
	}
	cout << endl;
	int info;
	string findS;
	if (cInput == '1')
	{
		info = Book::ISB;
		cout << "Type in the ISBN of the book you want to look up: ";
		readString(findS);
	}
	else //cInput has to be == '2'
	{
		info = Book::BKTTLE;
		cout << "Type in the title of the book you want to look up: ";
		readString(findS);
	}
	cout << endl;
	vector<Book*> tempV;
	bookList->partialFindBooks(info, findS, tempV);
	if (tempV.size() == 1){
		bPtr = tempV[0];
	}
	else if (tempV.size() > 1)
	{
		cout << "Multiple Books were found with those credentials, please choose one of them" << endl << endl;
		for (int i = 0; i < tempV.size(); i++)
			cout << (i + 1) << ") " << tempV[i]->toString(Book::ISB | Book::BKTTLE) << endl << endl;
		cout << "Type in the number which corresponds to the book you want: ";
		int answ;
		while (!readInt(answ) || (answ < 1) || (answ >tempV.size())) {
			cout << "\nPlease enter a number between " << 1 << " and " << tempV.size() << ": ";
		}
		bPtr = tempV[answ - 1];
	}
	else
		cout << "Sorry, no books were found with those credentials" << endl;
	if (bPtr != NULL)
	{
		if (bPtr->getQuantity() == 0){
			cout << "The book you selected has a quantity of 0, exiting back to CashierModule menu..." << endl;
			return;
		}
		int quant;
		cout << "Type in the quantity of the book you want to buy: ";
		while (!readInt(quant) || quant < 1 || quant > bPtr->getQuantity())
			cout << "Invalid Input: Please type a number between 1 and " << bPtr->getQuantity() << ": ";
		bPtr->setQuantity(bPtr->getQuantity() - quant);
		copyBook = *bPtr;
		copyBook.setQuantity(quant);
		bool flag = false;
		for (int i = 0; i < bookCart.size(); i++)
		{
			if (bookCart[i].getISBN() == copyBook.getISBN()){
				bookCart[i].setQuantity(bookCart[i].getQuantity() + copyBook.getQuantity());
				flag = true;
			}
		}
		if (!flag)
			bookCart.push_back(copyBook);
	}
}


void CashierModule::proceedToCheckout(vector<Book>&bC)
{
	double subTotal = 0;
	double total = 0;
	const double TAX_RATE = 0.09;
	cout << "    Checking out Books..." << endl << endl;
	cout << "    Qty      ISBN               Title                   Price       Total    " << endl;
	for (int i = 0; i < bC.size(); i++)
	{
		subTotal += bC[i].getWholesaleCost()*bC[i].getQuantity();
		string num = to_string(i+1) + ")";
		cout << left << setw(4) << num << setw(9) << bC[i].getQuantity()  << setw(19) << bC[i].getISBN() << setw(24) << bC[i].getBookTitle() << setw(12) << "$"+to_string(bC[i].getWholesaleCost()) << "$"+to_string(subTotal) <<endl;
	}
	total = subTotal * (TAX_RATE+1);
	cout << endl << "Subtotal: " << subTotal << endl; 
	cout << "Tax: " << total - subTotal << endl;
	cout << "Total: " << total;
	cout << endl << "Thank you for shopping with Serendipity!" << endl;
}
/*
void CashierModule::act()
{
	char cInput;                                                   //DO THE PARTIAL FIND IDEA
	cout << endl << "You can select a book by typing all the characters of a books property or only the first couple characters of a books property" << endl;
	
	
	cout << endl << "Type '1' To select a book by ISBN" << endl;
	cout << "Type '2' To select a book by Book Title" << endl;
	cout << "Type here-----------> ";
	while (!readChar(cInput) || (cInput < '1') || (cInput > '2')) {
		cout << "Please enter a number between 1 and 2: ";
	}
	cout << endl;
	int info;
	string findS;
	if (cInput == '1')
	{
		info = Book::ISB;
		cout << "Type in the ISBN of the book you want to look up: ";
		readString(findS);
	}
	else //cInput has to be == '2'
	{
		info = Book::BKTTLE;
		cout << "Type in the title of the book you want to look up: ";
		readString(findS);
	}
	cout << endl;
	vector<Book*> tempV;
	bookList->partialFindBooks(info, findS, tempV);
	if (tempV.size() == 1){
		//cout << "Book Found, Listing Book Details..." << endl;
		//cout << tempV[0]->toString(Book::EVERYTHING) << endl;
	}
	else if (tempV.size() > 1)
	{
		cout << "Multiple Books were found with those credentials, please choose one of them" << endl << endl;
		for (int i = 0; i < tempV.size(); i++)
			cout << (i + 1) << ") " << tempV[i]->toString(Book::ISB | Book::BKTTLE) << endl << endl;
		cout << "Type in the number which corresponds to the book you want: ";
		int answ;
		while (!readInt(answ) || (answ < 1) || (answ >tempV.size())) {
			cout << "\nPlease enter a number between " << 1 << " and " << tempV.size() << ": ";
		}
		//cout << endl << "Listing Book Details..." << endl;
		//cout << tempV[answ - 1]->toString(Book::EVERYTHING);
	}
	else
		cout << "Sorry, no books were found with those credentials" << endl;
}
}*/


/*
//	for (int i = 0; i < bookCart.size(); i++)
//	{
string num = to_string(1) + ")";
cout << left << setw(4) << num << setw(9) << "QTT" << setw(21) << "123456" << setw(24) <<"Amit Saxena" << setw(12) << "$4.55" << "$6.54" <<endl;
//	}

*/