#include <iostream>
using namespace std;

unsigned int reversedOf(unsigned int);

int main()
{
	cout << reversedOf(7631) << endl;
    return 0;
}

unsigned int reversedOf(unsigned int number)
{
	unsigned int reverseNumber = 0;

	while (number > 0)
	{
		reverseNumber = (reverseNumber * 10) + (number % 10);
		number /= 10;
	}

	return reverseNumber;
}

