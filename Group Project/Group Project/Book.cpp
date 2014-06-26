#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

using namespace std;

Book::Book()
{

	//set all variables to a 'default' value
	ISBN = "";
	bookTitle = "";
	authorName = "";
	publisher = "";

	date;

	quantity = 0;
	wholesaleCost = 0;
	retailCost = 0;

}
Book::Book(string ISBN, string b, string a, string p, int day,int month,int year, int q, double c, double r) : 
ISBN(ISBN), bookTitle(b), authorName(a), publisher(p), date(day, month, year), quantity(q), wholesaleCost(c), retailCost(r)
{}



//SHOULD WE ADD A NEW LINE IN FRONT OF ISBN?
string Book::toString(int info)
{
	string s;
	bool flag = 0;
	int inc = 0;
	if ((info & Book::ISB) != 0)  // 1
		s += help(flag) + "ISNB: " + ISBN;
	if ((info & Book::BKTTLE) != 0)  // 2
		s += help(flag) + "Title: " + bookTitle;
	if ((info & Book::AUTHNAME) != 0)  // 4
		s += help(flag) + "Author: " + authorName;
	if ((info & Book::PUB) != 0)   // 8
		s += help(flag) + "Publisher: " + publisher;
	if ((info & Book::DATE) != 0)   // 16
		s += help(flag) + "Date Added: " + date.toString();
	if ((info & Book::QUANT) != 0)   // 32
		s += help(flag) + "Quantity-On-Hand: " + to_string(quantity);
	if ((info & Book::WCOST) != 0)   // 64
		s += help(flag) + "Wholesale Cost: " + to_string(wholesaleCost);
	if ((info & Book::RET) != 0)   // 128
		s += help(flag) + "Retail Price: " + to_string(retailCost);
	return s;
}

string Book::help(bool &b)
{
	if (!b){
		b = 1;
		return "";
	}
	return "\n";
	
}

void Book::setISBN(string number)
{
	ISBN = number;
}

void Book::setBookTitle(string title)
{
	bookTitle = title;
}

void Book::setAuthorName(string Aname)
{
	authorName = Aname;
}

void Book::setPublisher(string pub)
{
	publisher = pub;
}
void Book::setQuantity(int number)
{
	quantity = number;
}

void Book::setWholesaleCost(double price)
{
	wholesaleCost = price;
}

void Book::setRetailCost(double sellBack)
{
	retailCost = sellBack;
}

void Book::setDay(int d)
{
	date.setDay(d);
}

void Book::setMonth(int m)
{
	date.setMonth(m);
}

void Book::setYear(int y)
{
	date.setYear(y);
}

string Book::getISBN() const
{
	return ISBN;
}
string Book :: getBookTitle() const
{
	return bookTitle;
}
string Book :: getAuthorName() const
{
	return authorName;
}
string Book :: getPublisher() const
{
	return publisher;
}
int Book::getMonth() const
{
	return date.getMonth();
}
int Book::getDay() const
{
	return date.getDay();
}
int Book::getYear() const
{
	return date.getYear();
}
Date Book::getDate() const
{
	return date;
}
int Book :: getQuantity() const
{
	return quantity;
}
double Book::getWholesaleCost() const
{
	return wholesaleCost;
}
double Book::getRetailCost() const
{
	return retailCost;
}

//template<typename T>
string Book::getProperty(int info)
{
	if ((info & Book::ISB) != 0)  // 1
		return this->ISBN;
	else if ((info & Book::BKTTLE) != 0)  // 2
		return bookTitle;
	else if ((info & Book::AUTHNAME) != 0)  // 4
		return authorName;
	else if ((info & Book::PUB) != 0)   // 8
		return publisher;

	//right now, the code can only handle geters of properties that are strings
	//the code really shouldnt reach here
	return "";
}


ofstream& operator<<(ofstream& out, Book& b)
{
	//PUT ENDLINE INSTEAD?
	const char endL = '\n';
	out << b.ISBN << endL;
	out << b.bookTitle << endL;
	out << b.authorName << endL;
	out << b.publisher << endL;
	out << b.date.getMonth() << ' ' << b.date.getDay() << ' ' <<b.date.getYear() << endL;   //ONCE THE PROGRAM IS WORKING, MAKE A << OPERATOR FOR DATE
	out << b.quantity << endL;
	out << b.wholesaleCost << endL;
	out << b.retailCost;
	return out;
}

ifstream& operator>>(ifstream& in, Book&b)
{
	const char endL = '\n';
	char c[500];
	in.getline(c, 500, endL);
	b.ISBN = c;
	in.getline(c, 500, endL);
	b.bookTitle = c;
	in.getline(c, 500, endL);
	b.authorName = c;
	in.getline(c, 500, endL);
	b.publisher = c;
	in.getline(c, 500, endL);
	string sTemp(c);                //ONCE THE PROGRAM IS WORKING, MAKE A >> OPERATOR FOR DATE
	b.date = sTemp;
	in.getline(c, 500, endL);
	b.quantity = atoi(c);
	in.getline(c, 500, endL);
	b.wholesaleCost = atof(c);
	in.getline(c, 500, endL);
	b.retailCost = atof(c);
	return in;
}

