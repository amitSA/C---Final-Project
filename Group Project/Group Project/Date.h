#ifndef DATE_CLASS
#define DATE_CLASS
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



class Date
{
private:
int day, month, year;

public:
Date();
Date(int, int, int);

void setDay(int);
void setMonth(int);
void setYear(int);

int getDay() const;
int getMonth() const;
int getYear() const;

std::string toString() const;
bool operator<(const Date&);

friend std::ofstream& operator<<(std::ofstream& out, const Date&d);


void operator=(std::string);

}; 

#endif