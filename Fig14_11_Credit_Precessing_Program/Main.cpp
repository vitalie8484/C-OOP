#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "ClientData.h"
using namespace std;

void outputLine(ostream &, const ClientData &);

int main()
{
	cout << "*** Credit Processing Program ***\n\n"
		<< "  * Select one action:\n"
		<< "1 - Initialize the database, new instantiating (all current data a deleted)\n"
		<< "2 - Insert into database\n"
		<< "3 - Read from database\n"
		<< "0 - Exit" << endl;
	int action = 0;

	cin >> action;

	while (action > 0 && action <=3)
	{
		if (action == 1)
		{
			//*********************** Instantiate data ******************************
			ofstream outCredit("credit.dat", ios::out | ios::binary);

			if (!outCredit)
			{
				cerr << "File could not be opened." << endl;
				exit(EXIT_FAILURE);
			}

			ClientData clientData;

			for (size_t i = 0; i < 100; i++)
			{
				outCredit.write(reinterpret_cast<const char *>(&clientData), sizeof(ClientData));
			}

			cout << endl << endl << endl;
			outCredit.close();
		} 
		else if (action == 2)
		{
			//*********************** Insert data ******************************
			int accountNumber;
			string lastName;
			string firstName;
			double balance;

			fstream outCredit("credit.dat", ios::in | ios::out | ios::binary);

			if (!outCredit)
			{
				cerr << "File could not be opened." << endl;
				exit(EXIT_FAILURE);
			}

			cout << "Enter account number (1 to 100, 0 to end input)\n";

			ClientData client;
			cin >> accountNumber;

			while (accountNumber > 0 && accountNumber <= 100)
			{
				cout << "Enter lastname, firstname, balance\n?";
				cin >> lastName;
				cin >> firstName;
				cin >> balance;

				client.setAccountNumber(accountNumber);
				client.setLastName(lastName);
				client.setFirstName(firstName);
				client.setBalance(balance);

				outCredit.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));

				outCredit.write(reinterpret_cast<const char *>(&client), sizeof(ClientData));

				cout << "Enter account number\n?";
				cin >> accountNumber;
			}

			cout << endl << endl << endl;
			outCredit.close();
		}
		else if (action == 3)
		{
			//*********************** Read data ******************************
			ifstream inCredit("credit.dat", ios::in | ios::binary);

			if (!inCredit)
			{
				cerr << "File could not be opened." << endl;
				exit(EXIT_FAILURE);
			}

			cout << left << setw(10) << "Account" << setw(16)
				<< "Last Name" << setw(11) << "First Name" << left
				<< setw(10) << right << "Balance" << endl;

			ClientData client;

			inCredit.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

			while (inCredit && !inCredit.eof())
			{
				if (client.getAccountNumber() !=0)
				{
					outputLine(cout, client);
				}

				inCredit.read(reinterpret_cast<char *>(&client), sizeof(ClientData));
			}

			cout << endl << endl << endl;
			inCredit.close();
		}
		else if (action == 0)
		{
			cout << "Exiting the application..." << endl;
			exit(EXIT_SUCCESS);
		}

		// Reselect an action
		cout << "  * Select one action:\n"
			<< "1 - Initialize the database, new instanciating (all current data a deleted)\n"
			<< "2 - Insert into database\n"
			<< "3 - Read from database\n"
			<< "0 - Exit" << endl;

		cin >> action;
	}
	
    return 0;
}

void outputLine(ostream& output, const ClientData& record)
{
	output << left << setw(10) << record.getAccountNumber() 
		<< setw(16)	<< record.getLastName() 
		<< setw(11) << record.getFirstName() 
		<< setw(10) << setprecision(2) << right << fixed 
		<< showpoint << record.getBalance() << endl;
}

