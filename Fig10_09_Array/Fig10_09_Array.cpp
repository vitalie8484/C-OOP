#include <iostream>
#include <stdexcept>
#include "Array.h"
using namespace std;

int main()
{
	Array integers1(7);
	Array integers2;

	cout << "Size of Array integers1 is " << integers1.getSize() << endl;
	cout << integers1 << endl;
	cout << "Size of Array integers2 is " << integers2.getSize() << endl;
	cout << integers2 << endl;

	cout << "Enter 17 integers:" << endl;
	cin >> integers1 >> integers2;

	cout << "\nAfter input, the Arrays contains:\n"
		<< "integers1:\n"
		<< integers1
		<< "integers2:\n"
		<< integers2;

	cout << "\nEvaluating: integers1 != integers2" << endl;
	if (integers1 != integers2)
	{
		cout << "integers1 and integers2 are not equal" << endl;
	}

	Array integers3(integers1);
	cout << "\nSize of Array integers3 is " << integers3.getSize() << endl;
	cout << "Array after initialization:\n" << integers3 << endl;

	cout << "Assigning integers2 to integers1:" << endl;
	integers1 = integers2;

	cout << "integers1\n" << integers1
		<< "integers2\n" << integers2;

	cout << "Evaluating: integers1 == integers2" << endl;
	if (integers1 == integers2)
	{
		cout << "integers1 and integers2 are equal" << endl;
	}

	cout << "\nintegers1[5] is " << integers1[5];

	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1[5] = 1000;
	cout << "integers1:\n" << integers1;

	try
	{
		cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
		integers1[15] = 1000;
	}
	catch (out_of_range &ex)
	{
		cout << "An exception occured: " << ex.what() << endl;
	}

    return 0;
}

 