#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int main()
{
	const size_t arraySize = 11;
	array<unsigned int, arraySize> n = { 1, 2, 4, 2, 1, 4, 2, 4, 7, 6, 10 };
	
	cout << "Grade distribution:" << endl;

	for (size_t i = 0; i < n.size(); ++i)
	{
		if (i == 10)
		{
			cout << "  100:";
		}
		else if(i == 0)
		{
			cout << "  0-9:";
		}
		else
		{
			cout << (i * 10) << "-" << (i * 10 + 9) << ":";
		}

		for (unsigned int stars= 0; stars < n[i]; ++stars)
		{
			cout << "*";
		}
		cout << endl;
	}
	
    return 0;
}