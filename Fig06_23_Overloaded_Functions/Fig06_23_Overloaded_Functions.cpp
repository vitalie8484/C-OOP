#include <iostream>
using namespace std;

int square(int i)
{
	cout << "square of integer " << i << " is ";
	return i * i;
}

double square(double i)
{
	cout << "square of double " << i << " is ";
	return i * i;
}


int main()
{
	cout << square(7) << endl;
	cout << square(7.5) << endl;

    return 0;
}

