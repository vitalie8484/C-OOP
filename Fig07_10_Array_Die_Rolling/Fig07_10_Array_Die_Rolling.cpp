#include <iostream>
#include <iomanip>
#include <array>
#include <ctime>
#include <random>
using namespace std;

int main()
{
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> randomInt(1, 6);

	const size_t arraySize = 6;
	array<unsigned int, arraySize> frequency = {};

	for (unsigned int roll = 1; roll < 6000000; ++roll)
	{
		++frequency[randomInt(engine) - 1];
	}

	cout << "Face" << setw(15) << "Frequency" << endl;

	for (size_t i = 0; i < frequency.size(); i++)
	{
		cout << setw(4) << i + 1 << setw(15) << frequency[i] << endl;
	}

    return 0;
}
