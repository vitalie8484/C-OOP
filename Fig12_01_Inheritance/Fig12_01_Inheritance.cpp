#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main()
{
	CommissionEmployee commissionEmployee(
		"Sue", "Jones", "222-22-222", 10000, .06);

	CommissionEmployee* commissionEmployeePtr = nullptr;

	BasePlusCommissionEmployee basePlusCommissionEmployee(
	"Bob", "Lewis", "333-33-3333", 5000, .04, 300);

	BasePlusCommissionEmployee* basePlusCommissionEmployeePtr = nullptr;

	cout << fixed << setprecision(2);

	cout << "Print base-class and derives-class objects:\n\n";
	commissionEmployee.print();
	cout << "\n\n";
	basePlusCommissionEmployee.print();

	commissionEmployeePtr = &commissionEmployee;
	cout << "\n\n\nCalling print with base-class pointer to "
		<< "\nbase-class object invokes base-class print function:\n\n";
	commissionEmployeePtr->print();

	basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;
	cout << "\n\nCalling print with derived-class pointer to "
		<< "\nderived-class pbject incokes derived-class print funcrion:\n\n";
	basePlusCommissionEmployeePtr->print();

	commissionEmployeePtr = &basePlusCommissionEmployee;
	cout << "\n\n\nCalling print with base-class pointer to "
		<< "\nderived-class objest invokes derived-class objest: (virtual is used)\n\n";
	commissionEmployeePtr->print();
	
	cout << endl;
}

