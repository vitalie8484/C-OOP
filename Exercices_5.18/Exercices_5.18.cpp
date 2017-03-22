#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int main()
{
	cout << setw(12) << "Decimal"
		<< setw(12) << "Binary"
		<< setw(12) << "Octal"
		<< setw(12) << "Hexadecimal" << endl;
	for (unsigned short i = 1; i <= 256; i++)
	{
		if (i == 256)
		{
			cout << setw(12) << dec << i
				<< setw(12) << bitset<9>(i)
				<< setw(12) << oct << i
				<< setw(12) << hex << i << endl;
		}
		else
		{
			cout << setw(12) << dec << i
				<< setw(12) << bitset<8>(i)
				<< setw(12) << oct << i
				<< setw(12) << hex << i << endl;
		}
		
	}

    return 0;
}

