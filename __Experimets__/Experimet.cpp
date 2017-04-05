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
	ClassExample example1;
	ClassExample example2;
	ClassExample example3;

	example1.localMethodIncrementAndShow();

	example2.localMethodIncrementAndShow();
	example2.localMethodIncrementAndShow();

	example3.localMethodIncrementAndShow();
	example3.localMethodIncrementAndShow();
	example3.localMethodIncrementAndShow();

	return 0;
}
