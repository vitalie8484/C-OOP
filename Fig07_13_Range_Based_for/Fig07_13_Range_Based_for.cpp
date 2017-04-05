#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<int, 5> items = { 1, 2, 3, 4, 5 };

	cout << "Array's elements before modification:" << endl;

	for (int item : items)
	{
		cout << item << " ";
	}

	for (int& refItem : items)
	{
		refItem *= 2;
	}

	cout << "\nArray's elemtents after modification:" << endl;

	for (int item : items)
	{
		cout << item << " ";
	}

    return 0;
}

