#include <iostream>
#include <string>
using namespace std;

void isPerfect(int);

int main()
{
	for (unsigned int i = 2; i < 10000; i++)
	{
		isPerfect(i);
	}

	isPerfect(33550336);

    return 0;
}

void isPerfect(int number)
{
	int sum = 0;
	string divisors = "";

	for (unsigned int i = 1; i < number; i++)
	{
		if ((number % i) == 0)
		{
			sum += i;
			divisors = divisors + to_string(i) + " ";
		}
	}

	if (sum == number)
	{
		cout << number << " divisors: " << divisors << endl;
	}
}

