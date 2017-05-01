#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(const string& firstName,
				   const string& lastName, 
				   const string& ssn)

	: firstName(firstName), lastName(lastName), socialSecurityNumber(ssn)
{ }

void Employee::setFirstName(const string& firstName)
{
	this->firstName = firstName;
}

string Employee::getFirstName() const
{
	return this->firstName;
}

void Employee::setLastName(const string& lastName)
{
	this->lastName = lastName;
}

string Employee::getLastName() const
{
	return this->lastName;
}

void Employee::setSocialSecurityNumber(const string& ssn)
{
	this->socialSecurityNumber = ssn;
}

string Employee::getSocialSecurityNumber() const
{
	return this->socialSecurityNumber;
}

void Employee::print() const
{
	cout << getFirstName() << " " << getLastName()
		<< "\nsocial security number: " << getSocialSecurityNumber();
}