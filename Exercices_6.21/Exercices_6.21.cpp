#include <iostream>
#include <cstdlib>
using namespace std;

bool isEven(int);

int main()
{
	int x = 0;
	do
	{
		cout << "Entrer un mombre entier positif: (negatif nombre pour sortir)" << endl;
		cin >> x;
		if (x < 0)
		{
			break;
		}
		if (isEven(x))
		{
			cout << "Le nombre " << x << " est pair" << endl;
		}
		else
		{
			cout << "Le nombre " << x << " est impair" << endl;
		}
	} while (true);

    return 0;
}

bool isEven(int a)
{
	if (a % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

