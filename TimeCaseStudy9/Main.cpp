#include <iostream>
#include <stdexcept>
#include "Time.h"
#include "Date.h"
#include "Employee.h"
using namespace std;

int main()
{
	Time t1;
	Time t2(2);
	Time t3(21, 34);
	Time t4(12, 25, 42);

	cout << "Constructed with:" << endl;

	cout << "\nt1: all arguments defaulted" << endl;
	t1.printUniversal();
	cout << endl;
	t1.printStandard();

	cout << "\n\nt2: hour specified; minute and second defaulted" << endl;
	t2.printUniversal();
	cout << endl;
	t2.printStandard();

	cout << "\n\nt3: hour and minute specified; second defaulted" << endl;
	t3.printUniversal();
	cout << endl;
	t3.printStandard();

	cout << "\n\nt4: hour, minute and second specified" << endl;
	t4.printUniversal();
	cout << endl;
	t4.printStandard();

	try
	{
		Time t5(21, 99, 99);
	}
	catch (invalid_argument &e)
	{
		cout << "\n\nException while initializing t5: " << e.what() << endl;
	}

	//**************************** Fig09_12 ****************************
	cout << "\n\n//**************************** Fig09_12 ****************************" << endl;

	unsigned int& hourRef = t1.badSetHour(20);

	cout << "Valid hour before modification: " << hourRef;

	hourRef = 30;
	cout << "\nInvalid hour after modification: " << t1.getHour();

	t1.badSetHour(12) = 74;
	cout << "\n\n********************************************************\n"
		<< "POOR PROGRAMMING PRACTICE!!!!!!!\n"
		<< "t1.badSetHour(12) = 74; t1.getHour() = " << t1.getHour()
		<< "\n********************************************************" << endl;

	//**************************** Fig09_15 ****************************
	cout << "\n\n//**************************** Fig09_15 ****************************" << endl;

	Date date1(7, 4, 2004);
	Date date2;

	cout << "date1 = ";
	date1.print();
	cout << "date2 = ";
	date2.print();

	date2 = date1;

	cout << "\nAfter default memeberwise assignment, date2 = ";
	date2.print();
	cout << endl;

	//**************************** Fig09_21 ****************************
	cout << "\n\n//**************************** Fig09_21 ****************************" << endl;
	Date birth(7, 24, 1949);
	Date hire(3, 12, 1988);
	Employee manager("Bob", "Blue", birth, hire);

	cout << endl;
	manager.print();

	//**************************** Fig09_26 ****************************
	cout << "\n\n//**************************** Fig09_26 ****************************" << endl;
	Time t;
	t.setHour(8).setMinute(30).setSecond(22);

	cout << "Universal rime: ";
	t.printUniversal();

	cout << "\nStandard time: ";
	t.printStandard();

	cout << "\n\nNew standard time: ";
	t.setTime(20, 20, 20).printStandard();
	cout << endl << endl;
}