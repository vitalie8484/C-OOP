#include <iostream>
#include <stdexcept>

#include "CommissionEmployee.h"
using namespace std;

CommissionEmployee::CommissionEmployee(const string& firstName,
	const string& lastName,	const string& ssn,
	double grossSales, double commissionRate)

	: Employee(firstName, lastName, ssn)
{
	setGrossSales(grossSales);
	setCommissionRate(commissionRate);
}

void CommissionEmployee::setGrossSales(double sales)
{
	if (sales >= 0.0)
	{
		this->grossSales = sales;
	}
	else
	{
		throw invalid_argument("Gross sales must be >= 0.0");
	}
}

double CommissionEmployee::getGrossSales() const
{
	return this->grossSales;
}

void CommissionEmployee::setCommissionRate(double rate)
{
	if (rate > 0.0 && rate < 1.0)
	{
		this->commissionRate = rate;
	}
	else
	{
		throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
	}
}

double CommissionEmployee::getCommissionRate() const
{
	return this->commissionRate;
}

double CommissionEmployee::earnings() const
{
	return getCommissionRate() * getGrossSales();
}

void CommissionEmployee::print() const
{
	cout << "commission employee: ";
	Employee::print();
	cout << "\ngross sales: " << getGrossSales()
		<< "\ncommission rate: " << getCommissionRate();
}