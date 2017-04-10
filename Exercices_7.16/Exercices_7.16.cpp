#include <iostream>
#include <array>
#include <iomanip>
#include <random>
#include <ctime>
using namespace std;

default_random_engine engine(static_cast<int>(time(0)));
uniform_int_distribution<int> randInt(1, 6);

int rollDice();
int sumTwoDices();

int main()
{
	array<int, 11> arr = {};
	unsigned int counter = 1;
	unsigned int n = 0;

	while (counter <= 36000)
	{
		n = sumTwoDices();
		++arr[n - 2];
		++counter;
	}

	cout << setw(5) << "sum" << setw(15) << "frequency" << endl;

	for (unsigned int i = 0; i < 11; ++i)
	{
		cout << setw(5) << (i + 2) << setw(15) << arr[i] << endl;
	}

    return 0;
}

int rollDice()
{
	return randInt(engine);
}

int sumTwoDices()
{
	return rollDice() + rollDice();
}
