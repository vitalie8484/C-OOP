#include "ClientData.h"
using namespace std;

ClientData::ClientData(int accountNumberValue, const string& lastName,
	const string& firstName, double balanceValue)
	: accountNumber(accountNumberValue), balance(balanceValue)
{
	setLastName(lastName);
	setFirstName(firstName);
}

int ClientData::getAccountNumber() const
{
	return this->accountNumber;
}

void ClientData::setAccountNumber(int accountNumberValue)
{
	this->accountNumber = accountNumberValue;
}

string ClientData::getLastName() const
{
	return this->lastName;
}

void ClientData::setLastName(const string& lastName)
{
	int length = lastName.size();
	length = (length < 15 ? length : 14);
	lastName.copy(this->lastName, length);
	this->lastName[length] = '\0';
}

string ClientData::getFirstName() const
{
	return this->firstName;
}

void ClientData::setFirstName(const string& firstName)
{
	int length = firstName.size();
	length = (length < 10 ? length : 9);
	firstName.copy(this->firstName, length);
	this->firstName[length] = '\0';
}

double ClientData::getBalance() const
{
	return this->balance;
}

void ClientData::setBalance(double balance)
{
	this->balance = balance;
}
