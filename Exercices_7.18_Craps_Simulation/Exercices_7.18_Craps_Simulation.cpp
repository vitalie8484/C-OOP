#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
using namespace std;

default_random_engine engine(static_cast<int>(time(0)));
uniform_int_distribution<int> randInt(1, 6);

int rollDice();
int sumTwoDices();

int main()
{
	enum Status { CONTINUE, WIN, LOST };
	array<int, 22> wonGames = {};
	array<int, 22> lostGames = {};

	unsigned int myPoint;
	Status gameStatus;
	unsigned int sumOfDice;

	unsigned int gamesCounter = 1;

	while (gamesCounter <= 1000)
	{
		myPoint = 0;
		gameStatus = CONTINUE;
		sumOfDice = sumTwoDices();

		switch (sumOfDice)
		{
		case 7:
		case 11:
			gameStatus = WIN;
			++wonGames[1];
			break;
		case 2:
		case 3:
		case 12:
			gameStatus = LOST;
			++lostGames[1];
			break;
		default:
			gameStatus = CONTINUE;
			myPoint = sumOfDice;
			break;
		}

		unsigned int counter = 0;
		while (gameStatus == CONTINUE)
		{
			++counter;
			sumOfDice = sumTwoDices();

			if (sumOfDice == 7)
			{
				gameStatus = LOST;
				if (counter > 20)
				{
					++lostGames[21];
				}
				else
				{
					++lostGames[counter];
				}
			}
			else if (sumOfDice == myPoint)
			{
				gameStatus = WIN;
				if (counter > 20)
				{
					++wonGames[21];
				}
				else
				{
					++wonGames[counter];
				}
			}
		}
		++gamesCounter;
	}

	unsigned int wonTotal = 0;
	unsigned int lostTotal = 0;
	for (unsigned int i : wonGames)
	{
		wonTotal += i;
	}
	for (unsigned int i : lostGames)
	{
		lostTotal += i;
	}

	cout << right << setw(10) << "Roll Nr." << 
		setw(10) << "Wons" <<
		setw(10) << "Losts" << 
		setw(10) << "Total" << 
		setw(20) << "Chances of winning" << endl;

	unsigned int chancesWon = 0;
	unsigned int chancesLost = 0;
	for (size_t i = 1; i < 21; i++)
	{
		chancesWon = 0;
		chancesLost = 0;
		for (size_t j = 1; j <= i; j++)
		{
			chancesWon += wonGames[j];
			chancesLost += lostGames[j];
		}

		cout << setw(7) << "Roll " << setw(3) << i << 
			setw(10) << wonGames[i] << 
			setw(10) << lostGames[i] << 
			setw(10) << wonGames[i] + lostGames[i] << 
			setw(15) << (((chancesWon + chancesLost) == 0) ? 0 : ((chancesWon * 100) / (chancesWon + chancesLost))) << "%" << endl;
	}

	chancesWon = 0;
	chancesLost = 0;
	for (size_t j = 1; j <= 21; j++)
	{
		chancesWon += wonGames[j];
		chancesLost += lostGames[j];
	}
	cout << setw(10) << "Roll > 21" << 
		setw(10) << wonGames[21] << 
		setw(10) << lostGames[21] << 
		setw(10) << wonGames[21] + lostGames[21] <<
		setw(15) << (((chancesWon + chancesLost) == 0) ? 0 : ((chancesWon * 100) / (chancesWon + chancesLost))) << "%" << endl;

	cout << setw(10) << "Total" << 
		setw(10) << wonTotal << 
		setw(10) << lostTotal << 
		setw(10) << wonTotal + lostTotal << 
		setw(15) << ((wonTotal * 100) / (wonTotal + lostTotal)) << "%" << endl;

	unsigned int averageSum = 0;
	unsigned int averageLength = 0;
	for (size_t i = 1; i <= 20; i++)
	{
		averageSum += i * (wonGames[i] + lostGames[i]);
		averageLength += i;
	}

	cout << "Average length of a game is " << averageSum / averageLength << endl;

	return 0;
}

int rollDice()
{
	return randInt(engine);
}

int sumTwoDices()
{
	return rollDice() + rollDice();
}