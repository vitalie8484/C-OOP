#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	unsigned int frequency1 = 0;
	unsigned int frequency2 = 0;
	unsigned int frequency3 = 0;
	unsigned int frequency4 = 0;
	unsigned int frequency5 = 0;
	unsigned int frequency6 = 0;

	for (unsigned int roll = 1; roll <= 6000000; ++roll)
	{
		unsigned int face = 1 + rand() % 6;

		switch (face)
		{
		case 1:
			++frequency1;
			break;
		case 2:
			++frequency2;
			break;
		case 3:
			++frequency3;
			break;
		case 4:
			++frequency4;
			break;
		case 5:
			++frequency5;
			break;
		case 6:
			++frequency6;
			break;
		default:
			cout << "Program should never get here!" << endl;
			break;
		}
	}

	cout << "Face" << setw(10) << "Frequency" << endl;
	cout << "   1" << setw(10) << frequency1
		<< "\n   2" << setw(10) << frequency2
		<< "\n   3" << setw(10) << frequency3
		<< "\n   4" << setw(10) << frequency4
		<< "\n   5" << setw(10) << frequency5
		<< "\n   6" << setw(10) << frequency6 << endl;
    return 0;
}