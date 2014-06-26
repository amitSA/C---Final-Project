#ifndef CASHIER_MODULE
#define CASHIER_MODULE

#include "Module.h"
#include <iomanip>

class CashierModule : public Module
{
public:
	CashierModule(BookList*);
	void act();                  // overriding the virtual method from Module class
	
	void addItemToCart(vector<Book>&);

	void proceedToCheckout(vector<Book>&);
};










#endif