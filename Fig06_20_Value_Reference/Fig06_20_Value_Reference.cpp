#include <iostream>
using namespace std;

int squareByValue(int);
void squareByReference(int &);

int main()
{
	int x = 2;
	int y = 4;

	cout << "x = " << x << " before squareByValue\n";
	cout << "Value returned by squareByValue: " << squareByValue(x) << endl;

	cout << "y = " << y << " before squareByReference" << endl;
	squareByReference(y);
	cout << "y = " << y << " after squareByReference" << endl;

    return 0;
}

int squareByValue(int number)
{
	return number *= number;
}

void squareByReference(int &numberRef)
{
	numberRef *= numberRef;
}