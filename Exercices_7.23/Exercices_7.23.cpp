#include <iostream>
#include <iomanip>
#include <random>
#include <array>
#include <ctime>
using namespace std;

default_random_engine engine(static_cast<int>(time(0)));
uniform_int_distribution<int> randInt(0, 7);

const size_t arraySize = 8;
array<array<int, arraySize>, arraySize> board = {};

array<int, arraySize> horizontal = { 2, 1, -1, -2, -2, -1, 1, 2 };
array<int, arraySize> vertical = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main()
{
	bool foundComplete = false;
	int countTours = 1;
	while(!foundComplete)
	{
		board = {};
		int currentRow = randInt(engine);
		int currentColumn = randInt(engine);

		int counter = 0;
		bool gameOver = false;

		while (!gameOver)
		{
			++counter;
			board[currentRow][currentColumn] = counter;

			bool foundMove = false;
			int randTry = 1;
			while (!foundMove && (randTry < 10))
			{
				unsigned int moveNumber = randInt(engine);

				int currR = currentRow;
				int currC = currentColumn;
				int currRow = currR + vertical[moveNumber];
				int currColumn = currC + horizontal[moveNumber];

				if ((currRow >= 0) && (currRow <= 7) && (currColumn >= 0) && (currColumn <= 7))
				{
					if (board[currRow][currColumn] == 0)
					{
						currentRow = currRow;
						currentColumn = currColumn;
						foundMove = true;
					}
				}
				++randTry;
			}
			if (!foundMove)
			{
				gameOver = true;
			}
		}
		cout << counter << endl;
		if (counter == 64)
		{
			foundComplete = true;
		}
		else
		{
			++countTours;
		}
		
	}

	cout << "Number of tours : " << countTours << endl;

	for (auto const &row : board)
	{
		for (auto const &val : row)
		{
			cout << setw(3) << val << " ";
		}
		cout << endl << endl;
	}

	return 0;
}