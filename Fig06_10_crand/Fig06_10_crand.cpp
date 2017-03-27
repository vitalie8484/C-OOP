#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
	unsigned int seed = 0;
	cout << "Enter seed:" << endl;
	srand(static_cast<unsigned int>(time(0)));

	for (unsigned int i = 1; i <= 10; i++)
	{
		cout << setw(10) << (1 + rand() % 6);

		if (i % 5 == 0)
		{
			cout << endl;
		}
	}

    return 0;
}

