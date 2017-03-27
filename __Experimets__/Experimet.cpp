#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	int n = 0;
	
	for (unsigned int i = 0; i < 1000; i++)
	{
		n = rand() % 15 - 3;
		cout << n << endl;
	}
}