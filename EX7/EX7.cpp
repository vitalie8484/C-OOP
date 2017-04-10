#include <iostream>
#include <array>
using namespace std;

void transformArray(array<int, 9> &);

int main()
{
	array<int, 9> arr = { -1, 3, 4, 0, 5, -2, 0, 6, 0 };

	cout << "Le tableau avant la transformation:" << endl;
	for (int i : arr)
	{
		cout << i << " ";
	}
	cout << endl;

	transformArray(arr);
	cout << "Le tableau apres la transformation:" << endl;
	for (int i : arr)
	{
		cout << i << " ";
	}
	cout << endl;

    return 0;
}

void transformArray(array<int, 9>& a)
{
	for (unsigned int count = 0; count < a.size(); ++count)
	{
		for (size_t i = 0; i < a.size() - 1; ++i)
		{
			if ((a[i] == 0) && (a[i + 1] != 0))
			{
				a[i] = a[i + 1];
				a[i + 1] = 0;
			}
		}
	}
}
