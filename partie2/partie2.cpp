#include <iostream>
using namespace std;

unsigned int mouvements = 0;

void toursDeHanoi(unsigned int n, unsigned int moveFrom, unsigned int moveTo, unsigned int temporary)
{
	if (n > 0)
	{
		toursDeHanoi(n - 1, moveFrom, temporary, moveTo);
		cout << moveFrom << " --> " << moveTo << endl;
		toursDeHanoi(n - 1, temporary, moveTo, moveFrom);
		mouvements++;
	}
}

int main()
{
	unsigned int n = 0;
	cout << "Veuillez entrer le nombre de disques: ";
	cin >> n;
	toursDeHanoi(n, 1, 3, 2);
	cout << "Mouvements: " << mouvements << endl;
    return 0;
}



