#ifndef REPORT_MODULE
#define REPORT_MODULE

#include "Module.h"
#include "Book.h"
#include <vector>

class ReportModule : public Module
{

	

public:        
	ReportModule(BookList*);
	void act();
	string displayInventory();           //BUT THESE ARE ALL HELPER METHODS TOO???, make them private
	string displayWholeSaleValue();
	string displayByRetailValue();
	string listByQuantity();
	string listByCost();
	string listByDate();


private:           // these variables are only meant to be used in this class, there purpose is to choose how the elements in bookList are to be sorted 
	const static int dInv = 1,
				     dWSVal = 2,
					 dRVal = 3,
					 lQT = 4,
					 lWSVAL = 5,
					 lDT = 6;
	
	void sort(int st);														// helper method(only to be used in this class)

};

#endif