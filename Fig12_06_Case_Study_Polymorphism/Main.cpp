#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <typeinfo>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

void virtualViaPointer(const Employee * const);
void virtualViaReference(const Employee &);

int main()
{
	cout << fixed << setprecision(2);

	SalariedEmployee salariedEmployee(
		"John", "Smith", "111-11-1111", 800
	);
	CommissionEmployee commissionEmployee(
		"Sue", "Jones", "333-33-333", 10000, .06
	);
	BasePlusCommissionEmployee basePlusCommissionEmployee(
		"Bob", "Lewis", "444-44-4444", 5000, .04, 300
	);

	cout << "Employees processed individually using static binding:\n\n";
	salariedEmployee.print();
	cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
	commissionEmployee.print();
	cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
	basePlusCommissionEmployee.print();
	cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";


	vector<Employee *> employees(3);
	employees[0] = &salariedEmployee;
	employees[1] = &commissionEmployee;
	employees[2] = &basePlusCommissionEmployee;

	cout << "Employees processed polymorphically via dynamic binding:\n\n";

	cout << "Virtual function calls made off base-class pointers:\n\n";
	for (Employee*  employeePtr : employees)
	{
		virtualViaPointer(employeePtr);
	}

	cout << "Virtual function calls made off base-class references:\n\n";
	for (Employee* employeePtr: employees)
	{
		virtualViaReference(*employeePtr);
	}

	cout << "/*********************************** Fig. 12.19 **************************************/" << endl;

	employees[0] = new SalariedEmployee("John", "Smith", "111-11-1111", 800);
	employees[1] = new CommissionEmployee("Sue", "Jones", "333-33-333", 10000, .06);
	employees[2] = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);

	for (Employee* employeePtr : employees)
	{
		employeePtr->print();
		cout << endl;

		BasePlusCommissionEmployee* derivedPtr = dynamic_cast<BasePlusCommissionEmployee *>(employeePtr);

		if (derivedPtr != nullptr)
		{
			double oldBaseSalary = derivedPtr->getBaseSalary();
			cout << "old base salary: $" << oldBaseSalary << endl;
			derivedPtr->setBaseSalary(1.10 * oldBaseSalary);
			cout << "new base salary with 10% increase is: $" << derivedPtr->getBaseSalary() << endl;
		}

		cout << "earned $" << employeePtr->earnings() << "\n\n";
	}

	for (const Employee* employeePtr : employees)
	{
		cout << "deleting object of " << typeid(*employeePtr).name() << endl;
		delete employeePtr;
	}
}

void virtualViaPointer(const Employee * const baseCassPtr)
{
	baseCassPtr->print();
	cout << "\nearned $" << baseCassPtr->earnings() << "\n\n";
}

void virtualViaReference(const Employee& baseCassRef)
{
	baseCassRef.print();
	cout << "\nearned $" << baseCassRef.earnings() << "\n\n";
}