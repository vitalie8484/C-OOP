#include <iostream>
#include "maximum.h"
using namespace std;

int main()
{
	int int1, int2, int3;

	cout << "Input three integer values: ";
	cin >> int1 >> int2 >> int3;
	cout << "The maximum integer values is: " << maximum(int1, int2, int3);

	double d1, d2, d3;
	cout << "\n\nInput three double value is: ";
	cin >> d1 >> d2 >> d3;
	cout << "The maximum double values is:" << maximum(d1, d2, d3);

	char c1, c2, c3;
	cout << "\n\nInput three characters: ";
	cin >> c1 >> c2 >> c3;
	cout << "The maximum character value is: " << maximum(c1, c2, c3) << endl;

    return 0;
}

