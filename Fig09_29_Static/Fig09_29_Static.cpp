#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
	cout << "Numberof employees vefore instantiation of any objects is " <<
		Employee::getCount() << endl;

	{
		Employee e1("Susan", "Baker");
		Employee e2("Robert", "Jones");

		cout << "Number of employees after objects are instantiated is " <<
			Employee::getCount() << endl << endl;

		cout << "Employee 1: " << e1.getFirstName() << ' ' <<
			e1.getLastName() << endl;
		cout << "Employee 2: " << e2.getFirstName() << ' ' <<
			e2.getLastName() << endl;
	}

	cout << "\nNumber of employees after objects are deleted is " <<
		Employee::getCount() << endl;

    return 0;
}

