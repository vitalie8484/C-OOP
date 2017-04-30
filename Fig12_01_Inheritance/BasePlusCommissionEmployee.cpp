#include <iostream>
#include <stdexcept>

#include "BasePlusCommissionEmployee.h"
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	const string& firstName,
	const string& lastName,
	const string& ssn,
	double sales,
	double rate,
	double salary)
	: CommissionEmployee(firstName, lastName, ssn, sales, rate)
{
	setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary >= 0.0)
	{
		this->baseSalary = salary;
	}
	else
	{
		throw invalid_argument("Salary must be >= 0.0");
	}
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
	return this->baseSalary;
}

double BasePlusCommissionEmployee::earnings() const
{
	//return baseSalary + (getCommissionRate() * getGrossSales());
	return baseSalary + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const
{
/*
	cout << "base-salaried commission employee: " << getFirstName() << ' ' << getLastName()
		<< "\nsocial security number: " << getSocialSecurityNumber()
		<< "\ngross sales: " << getGrossSales()
		<< "\ncommission rate: " << getCommissionRate()
		<< "\nbase dalary: " << baseSalary;
*/

/*
	cout << "base-salaried commission employee: " << firstName << ' ' << lastName
		<< "\nsocial security number: " << socialSecurityNumber
		<< "\ngross sales: " << grossSales
		<< "\ncommission rate: " << commissionRate
		<< "\nbase dalary: " << baseSalary;
*/

	cout << "based-salaried ";
	CommissionEmployee::print();

	cout << "\nbase salary: " << getBaseSalary();
}