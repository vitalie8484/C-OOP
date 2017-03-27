#include <iostream>
using namespace std;

unsigned long fibonacci(unsigned long);

int main()
{
	for (unsigned int count = 0; count <= 10; count++)
	{
		cout << "fibonacci(" << count << ") = " << fibonacci(count) << endl;
	}

	cout << endl;

	cout << "fibonacci(20) = " << fibonacci(20) << endl;
	cout << "fibonacci(30) = " << fibonacci(30) << endl;
	cout << "fibonacci(35) = " << fibonacci(35) << endl;

    return 0;
}

unsigned long fibonacci(unsigned long number)
{
	if ((0 == number) || (1 == number))
	{
		return number;
	}
	else
	{
		return fibonacci(number - 1) + fibonacci(number - 2);
	}
}

