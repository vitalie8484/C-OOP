#include <iostream>
#include "ClassExample.h"

ClassExample::ClassExample()
{
}

void ClassExample::localMethodIncrementAndShow()
{
	int localInt = 100;

	cout << "Before incrementation: " << endl;
	cout << "staticGlobalInt - " << staticGlobalInt << endl;
	cout << "globalInt - " << globalInt << endl;
	cout << "localInt - " << localInt << endl;

	cout << "After incrementation: " << endl;
	cout << "staticGlobalInt - " << ++staticGlobalInt << endl;
	cout << "globalInt - " << ++globalInt << endl;
	cout << "localInt - " << ++localInt << endl;
}