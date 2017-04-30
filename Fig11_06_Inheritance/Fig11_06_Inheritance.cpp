#include <iostream>
#include <iomanip>
#include <string>

#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main()
{
	CommissionEmployee employee1(
		"Sue",
		"Jones",
		"222-22-2222",
		10000,
		.06
	);

	cout << fixed << setprecision(2);

	cout << "Employee_1 information obtained by get functions: \n"
		<< "\nFirst name is " << employee1.getFirstName()
		<< "\nLast name is " << employee1.getLastName()
		<< "\nSocial security number is " << employee1.getSocialSecurityNumber()
		<< "\nGross sales is " << employee1.getGrossSales()
		<< "\nCommission rate is " << employee1.getCommissionRate() << endl;

	employee1.setGrossSales(8000);
	employee1.setCommissionRate(.1);

	cout << "\nUpdated employee_1 information output by print function: \n" << endl;
	employee1.print();

	cout << "\n\nEmployee_1's earnings: $" << employee1.earnings() << endl;

	cout << "\n\n=====================================================================\n\n";

	BasePlusCommissionEmployee employee2(
		"Bob",
		"Lewis",
		"333-33-3333",
		5000,
		.04,
		300
	);

	cout << "Employee_2 information obtained by get functions: \n"
		<< "\nFirst name is " << employee2.getFirstName()
		<< "\nLast name is " << employee2.getLastName()
		<< "\nSocial security number is " << employee2.getSocialSecurityNumber()
		<< "\nGross sales is " << employee2.getGrossSales()
		<< "\nCommission rate is " << employee2.getCommissionRate()
		<< "\nBase salary is " << employee2.getBaseSalary() << endl;

	employee2.setBaseSalary(1000);

	cout << "\nUpdated employee_2 information output by print function: \n" << endl;
	employee2.print();

	cout << "\n\nEmployee_2's earnings: $" << employee2.earnings() << endl;
}