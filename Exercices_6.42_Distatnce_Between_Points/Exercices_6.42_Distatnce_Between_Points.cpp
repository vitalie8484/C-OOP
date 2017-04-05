#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double x2, double y1, double y2);

int main()
{
	cout << distance(-1, -1, 2, 3) << endl;
    return 0;
}

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}

