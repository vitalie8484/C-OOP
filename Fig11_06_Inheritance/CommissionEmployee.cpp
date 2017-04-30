#include <iostream>
#include <stdexcept>
#include <string>

#include "CommissionEmployee.h"
using namespace std;

CommissionEmployee::CommissionEmployee(const string& firstName,
	const string& lastName,	const string& ssn,
	double grossSales, double commissionRate)

	: firstName(firstName),	lastName(lastName), socialSecurityNumber(ssn)
{
	/*
	this->firstName = firstName;
	this->lastName = lastName;
	this->socialSecurityNumber = ssn;
	this->setGrossSales(grossSales);
	this->setCommissionRate(commissionRate);
	*/
	setGrossSales(grossSales);
	setCommissionRate(commissionRate);
}

void CommissionEmployee::setFirstName(const string& firstName)
{
	this->firstName = firstName;
}

string CommissionEmployee::getFirstName() const
{
	return this->firstName;
}

void CommissionEmployee::setLastName(const string& lastName)
{
	this->lastName = lastName;
}

string CommissionEmployee::getLastName() const
{
	return this->lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const string& ssn)
{
	this->socialSecurityNumber = ssn;
}

string CommissionEmployee::getSocialSecurityNumber() const
{
	return this->socialSecurityNumber;
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
	//return commissionRate * grossSales;
	return getCommissionRate() * getGrossSales();
}

void CommissionEmployee::print() const
{
	/*
	cout << "commission employee: " << firstName << " " << lastName
		<< "\nsocial security number: " << socialSecurityNumber
		<< "\ngross sales: " << grossSales
		<< "\ncommission rate: " << commissionRate;
	*/

	cout << "commission employee: " << getFirstName() << " " << getLastName()
		<< "\nsocial security number: " << getSocialSecurityNumber()
		<< "\ngross sales: " << getGrossSales()
		<< "\ncommission rate: " << getCommissionRate();
}