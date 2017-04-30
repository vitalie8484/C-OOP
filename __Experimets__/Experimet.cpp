#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <string>
#include "Header1.h"
#include "ClassExample.h"

using namespace std;

int ClassExample::staticGlobalInt = 1;

int main()
{	
	//ClassExample example1;
	//ClassExample example2;
	//ClassExample example3;

	//example1.localMethodIncrementAndShow();

	//example2.localMethodIncrementAndShow();
	//example2.localMethodIncrementAndShow();

	//example3.localMethodIncrementAndShow();
	//example3.localMethodIncrementAndShow();
	//example3.localMethodIncrementAndShow();

	int i = 70;
	int* ptr1 = &i;
	int* ptr2;
	ptr2 = ptr1;

	cout << ptr1 << endl;
	cout << ptr2 << endl;
	cout << &i << endl;

	return 0;
}
