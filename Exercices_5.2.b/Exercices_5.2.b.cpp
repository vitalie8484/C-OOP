#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double number = 333.546372;
	cout << fixed << left << setprecision(1) << setw(15) << number 
		                  << setprecision(2) << setw(15) << number 
		                  << setprecision(3) << setw(15) << number << endl;


    return 0;
}

