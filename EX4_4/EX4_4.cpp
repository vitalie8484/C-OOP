#include <iostream>

using namespace std;

int main()
{
	const double pi = 3.14159265358979323846;
	cout << "Rentrer un angle en degre: ";
	double degre = 0;
	cin >> degre;
	cout << degre << " degre = " << (degre * (pi / 180)) << " rad" << endl;

    return 0;
}

