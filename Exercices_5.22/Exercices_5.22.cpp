#include <iostream>

using namespace std;

int main()
{
	unsigned int x = 4, y = 1;
	unsigned int a = 1, b = 1, g = 5;
	unsigned int i = 8, j = 6;
	cout << "a) " << (!(x < 5) && !(y >= 7)) << " = " << !((x < 5) || (y >= 7)) << endl;
	cout << "b) " << (!(a == b) || !(g != 5)) << " = " << !((a == b) && (g != 5)) << endl;
	cout << "c) " << !((x <= 8) && (y > 4)) << " = " << (!(x <= 8) || !(y > 4)) << endl;
	cout << "d) " << !((i > 4) || (j <= 6)) << " = " << (!(i > 4) && !(j <= 6)) << endl;

    return 0;
}

