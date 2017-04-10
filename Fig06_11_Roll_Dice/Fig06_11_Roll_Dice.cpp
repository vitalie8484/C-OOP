#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned int rollDice();

int main()
{
	enum Status {CONTINUE, WIN, LOST};

	srand(static_cast<unsigned int>(time(0)));

	unsigned int myPoint = 0;
	Status gameStatus = CONTINUE;
	unsigned int sumOfDice = rollDice();

	switch (sumOfDice)
	{
	case 7:
	case 11:
		gameStatus = WIN;
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = LOST;
		break;
	default:
		gameStatus = CONTINUE;
		myPoint = sumOfDice;
		cout << "Point is " << myPoint << endl;
		break;
	}

	while (gameStatus == CONTINUE)
	{
		sumOfDice = rollDice();

		if (sumOfDice == 7)
		{
			gameStatus = LOST;
		}
		else if (sumOfDice == myPoint)
		{
			gameStatus = WIN;
		}
	}

	if (LOST == gameStatus)
	{
		cout << "Player loses" << endl;
	}
	else
	{
		cout << "Player wins" << endl;
	}

    return 0;
}

unsigned int rollDice() 
{
	unsigned int die1 = 1 + rand() % 6;
	unsigned int die2 = 1 + rand() % 6;

	unsigned int sum = die1 + die2;

	cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;
	return sum;
}