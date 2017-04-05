#include <iostream>
using namespace std;

class ClassExample
{
public:
	static int staticGlobalInt;
	int globalInt = 10;

	ClassExample();
	void localMethodIncrementAndShow();
};