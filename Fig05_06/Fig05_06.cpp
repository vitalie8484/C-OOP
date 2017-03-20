// Fig05_06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double amount;
	double principal = 1000.0;
	double rate = .05;

	double expression = 1.0 + rate;

	cout << "Year" << setw(21) << "Amount on deposit" << endl;

	cout << fixed << setprecision(2);

	for (unsigned int year  = 1; year <= 10; ++year)
	{
		// amount = principal * pow(1.0 + rate, year);
		amount = principal * pow(expression, year);

		cout << setw(4) << year << setw(21) << amount << endl;
	}

    return 0;
}

