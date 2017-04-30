#include <iostream>
#include <array>
#include <stdexcept>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y)
{
	if (m > 0 && m <= monthPerYear)
	{
		month = m;
	}
	else
	{
		throw invalid_argument("month must be 1-12");
	}

	year = y;
	day = checkDay(d);

	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

void Date::print() const
{
	cout << month << '/' << day << '/' << year;
}

Date::~Date()
{
	cout << "Date object destructor for date ";
	print();
	cout << endl;
}

unsigned int Date::checkDay(int testDay) const
{
	static const array<int, monthPerYear + 1> daysPerMonth =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (testDay > 0 && testDay <= daysPerMonth[month])
	{
		return testDay;
	}
	
	if (month == 2 && testDay == 29 && 
		(year % 4 == 0 || year % 400 == 0 && year % 100 != 0))
	{
		return testDay;
	}

	throw invalid_argument("Invalid day for current month and year");
}