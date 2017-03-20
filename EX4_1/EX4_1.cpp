#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <math.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1252);

	const double pi = 3.14159265358979323846;

	cout << "Rentrer le rayon du cercle:" << endl;
	double rayon = 0;
	cin >> rayon;

	cout << fixed << setprecision(4);

	double diameter = rayon * 2;
	cout << "1) Le diamètre du cercle est: " << diameter << endl;

	double circonference = diameter * pi;
	cout << "2) La circonférence du cercle est: " << circonference << endl;

	double surface = (pi * pow(diameter, 2)) / 4;
	cout << "3) La surface du cercle est: " << surface << endl;

    return 0;
}

