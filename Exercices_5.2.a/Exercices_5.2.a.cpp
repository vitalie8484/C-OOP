#include <iostream>

using namespace std;

int main()
{
	unsigned int sum = 0;
	for (unsigned int count = 1; count < 100; count +=2)
	{
		sum += count;
	}
	cout << "The sum of odd integers between 1 and 99 is: " << sum << endl;

    return 0;
}

