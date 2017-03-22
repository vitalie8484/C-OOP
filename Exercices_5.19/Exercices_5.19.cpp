#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	long double rez = 0;
	long double precedent = 0;

	cout << fixed << setprecision(51);

	for (int i = 1; i <= 1000; i++)
	{
		precedent = rez;
		if ((i % 2) != 0)
		{
			rez += static_cast<long double>(4) / ((i * 2) - 1);
		}
		else
		{
			rez -= static_cast<long double>(4) / ((i * 2) - 1);
		}

		cout << i << " step - " << rez << endl;
	}

	cout << "Avarage value - " << (precedent + rez) / 2 << endl;

    return 0;
}

