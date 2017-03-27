#include <iostream>
#include <random>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> randInt(1, 6);

	for (unsigned int i = 1; i <= 20; i++)
	{
		cout << setw(10) << randInt(engine);
		if (i % 5 == 0)
		{
			cout << endl;
		}
	}

    return 0;
}

