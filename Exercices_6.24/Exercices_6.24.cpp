#include <iostream>
using namespace std;

void printInteger();

int main()
{
	printInteger();

    return 0;
}

void printInteger()
{
	int x = 0;
	cout << "Entrer un nombre dans l'intervalle de 1 a 32767:" << endl;
	cin >> x;
	if ((x < 1) || (x > 32768))
	{
		cout << "Le nombre et moin 1 ou plus que 32767!";
		return;
	}
	while (x > 0)
	{
		cout << x % 10 << "  ";
		x = x / 10;
 	}
}

