#ifndef MODULE
#define MODULE

#include "BookList.h"
#include <vector>

using namespace std;

class Module
{
protected:                           //this is defined as protected so that inheriting classes can have acces to it
	BookList *bookList;
public:
	Module(BookList *bookList);           //the constructor
	virtual void act() = 0;          //the pure virtual function, the act() method basically contains the menu for all classes which choose to inherit of this class
									 // also when this method returns, then the option "Return to Main Menu" has probably been called
	
									/*All modules will have these methods which they call call whenever they want to take in user input.
	                                  All the methods return a boolean, if the boolean is true, that means it succesfully read a double,string,int etc.
									  Although if a method returns false, then the user input was invalid, and the method did not succesfully read user input
									  For example, if readDouble(&doubTemp) returns false, then the user had probably inputed a word when they were
									  only supposed to input letters*/
	bool readString(string&);   
	bool readDouble(double&);
	bool readInt(int&);
	bool readChar(char&);

private:
	bool isStringDouble(char*);
};




#endif