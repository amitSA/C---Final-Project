#define _CRT_SECURE_NO_WARNINGS
#include "BookList.h"
#include <fstream>
#include <string>


using namespace std;


BookList::BookList(string s){ fileName = s; }


void BookList::add(Book &b)
{
	bookList.push_back(b);
}

Book& BookList::get(int index)
{
	return bookList.at(index);
}

void BookList::remove(int index)
{
	bookList.erase(bookList.begin() + index); //check this..
}

string BookList::listBooks(int info)
{
	string s;
	for (int i = 0; i < (int)bookList.size(); i++){
		s += bookList[i].toString(info);
		if (i != bookList.size() - 1)
			s += "\n\n";
	}
	return s;
}

double BookList::tally(int info)
{
	double d = 0;
	for (int i = 0; i < (int)bookList.size(); i++)
	{
		Book &b = bookList[i];
		if ((info & Book::RET) != 0)
			d += b.getRetailCost() * b.getQuantity();
		if ((info & Book::WCOST) != 0)
			d += b.getWholesaleCost() * b.getQuantity();
	}
	return d;
}

Book& BookList::operator[](int index)
{
	return get(index);
}


void BookList::writeToFile()
{
	std::remove(fileName.c_str());
	ofstream out;
	out.open(fileName, ios::out);
	for (int i = 0; i < (int)bookList.size(); i++)
	{
		out << bookList[i];
		if (i != bookList.size()-1)
			out << '\n';
	}
	out.close();
}


void BookList::readFromFile()
{
	bookList.clear();
	ifstream in;
	in.open(fileName, ios::in);
	
	while (!in.eof())
	{
		Book b;
		in >> b;
		bookList.push_back(b);
	}
	in.close();
}

int BookList::getSize() const
{
	return bookList.size();
}



void BookList::findBooks(int info, string s, vector<Book*>&tempV)
{
	tempV.clear();
	for (int i = 0; i < bookList.size(); i++)
	{
		if (bookList[i].getProperty(info) == s)
			tempV.push_back(&bookList[i]);
	}
}


void BookList::partialFindBooks(int info, string s, vector<Book*>&tempV)
{
	tempV.clear();
	for (int i = 0; i < bookList.size(); i++)
	{
		string bProp = bookList[i].getProperty(info);
		if (s.find(bProp.c_str(),0,s.size()) == 0)
			tempV.push_back(&bookList[i]);
	}
}
