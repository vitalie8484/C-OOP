#include <iostream>
#include <iomanip>
using namespace std;

unsigned long factorial(unsigned long);

int main()
{
	for (unsigned int counter = 0; counter <= 10; counter++)
	{
		cout << setw(2) << counter << "! = " << factorial(counter) << endl;
	}

    return 0;
}

unsigned long factorial(unsigned long number)
{
	unsigned long result = 1;
	for (unsigned int counter= 1; counter <= number; counter++)
	{
		result *= counter;
	}
	return result;
}