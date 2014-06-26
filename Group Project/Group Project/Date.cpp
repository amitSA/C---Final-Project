#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"


using namespace std;



Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{}

Date::Date() : day(0), month(0), year(0)
{}

int Date::getDay() const { return day; }

int Date::getMonth() const { return month; }

int Date::getYear() const{ return year; }

void Date::setDay(int d) { day = d; }

void Date::setMonth(int m) { month = m; }

void Date::setYear(int y) { year = y; }

bool Date::operator<(const Date& dOther)
{
	return (year < dOther.year) || (year == dOther.year && month < dOther.month)
		|| (year == dOther.year && month == dOther.month && day < dOther.day);
}

string Date::toString() const
{
	return to_string(month) + "-" + to_string(day) + "-" + to_string(year);
	
}


ofstream& operator<<(ofstream& out, const Date& d) 
{
	string s = d.toString();
	out.write(s.c_str(), s.size());         
	return out;
}

void Date::operator=(string s)
{
	stringstream stream;
	stream << s;
	stream >> month;
	stream >> day;
	stream >> year;
}
