#ifndef INVENTORY_DATABASE_MODULE
#define INVENTORY_DATABASE_MODULE

#include "Module.h"
#include "Book.h"
#include <vector>
#include <iostream>


using namespace std;

class InventoryDatabaseModule : public Module
{
public:
	InventoryDatabaseModule(BookList*);
	void act();                  // overriding the virtual method from Module class
	
	void lookUpBook();            // these are methods that the act() method will call
	void addBook();
	void editBook();
	void deleteBook();

	
};




#endif 