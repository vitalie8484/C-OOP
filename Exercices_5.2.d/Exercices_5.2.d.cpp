#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	unsigned int x = 1;
	while (x <= 20)
	{
		if (x % 5 == 0)
		{
			cout << setw(3) << x << endl;
		}
		else
		{
			cout << setw(3) << x;
		}
		++x;
	}

	for (unsigned int x = 1; x <= 20; x++)
	{
		if (x % 5 == 0)
		{
			cout << setw(3) << x << endl;
		}
		else
		{
			cout << setw(3) << x;
		}
	}
    return 0;
}

