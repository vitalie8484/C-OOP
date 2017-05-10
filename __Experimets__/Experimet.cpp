#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{	
	int a, b, c, d , resul;

	a = 5;
	b = 11;
	c = 36;
	d = -6;
	resul = d % a * c + a %b + a;
	

	cout << resul;
	return 0;
}
