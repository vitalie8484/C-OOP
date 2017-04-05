#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

void initializeArrayByZero()
{
	array<int, 5> n;

	for (unsigned int i = 0; i < n.size(); i++)
	{
		n[i] = 0;
	}

	cout << "Element" << setw(13) << "Values" << endl;

	for (unsigned int i = 0; i < n.size(); i++)
	{
		cout << setw(7) << i << setw(13) << n[i] << endl;
	}
}

void initializeArrayInDeclaration()
{
	array<int, 5> n = { 32, 27, 64, 18};

	cout << "Element" << setw(13) << "Values" << endl;

	for (unsigned int i = 0; i < n.size(); i++)
	{
		cout << setw(7) << i << setw(13) << n[i] << endl;
	}
}

void arrayWithEvenIntegers()
{
	const size_t arraySize = 5;

	array<int, arraySize> n;

	for (unsigned int i = 1; i <= n.size(); i++)
	{
		n[i - 1] = i * 2;
	}

	cout << "Element" << setw(13) << "Values" << endl;

	for (unsigned int i = 0; i < n.size(); i++)
	{
		cout << setw(7) << i << setw(13) << n[i] << endl;
	}
}

int main()
{
	cout << "Initialize array with zero: " << endl;
	initializeArrayByZero();
	cout << endl;

	cout << "Initialize array in declaration: " << endl;
	initializeArrayInDeclaration();
	cout << endl;

	cout << "Array show even numbers: " << endl;
	arrayWithEvenIntegers();
	cout << endl;

    return 0;
}

