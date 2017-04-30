#include <iostream>
#include <iomanip>
#include <array>
#include <ctime>
using namespace std;

const size_t arraySize = 8;
int lookAhead(int const &nextRow, int const & nextColumn);
array<array<int, arraySize>, arraySize> board = {};
array<array<int, arraySize>, arraySize> accessibility = {
	2, 3, 4, 4, 4, 4, 3, 2,
	3, 4, 6, 6, 6, 6, 4, 3,
	4, 6, 8, 8, 8, 8, 6, 4,
	4, 6, 8, 8, 8, 8, 6, 4,
	4, 6, 8, 8, 8, 8, 6, 4,
	4, 6, 8, 8, 8, 8, 6, 4,
	3, 4, 6, 6, 6, 6, 4, 3,
	2, 3, 4, 4, 4, 4, 3, 2
};

array<int, arraySize> horizontal = { 2, 1, -1, -2, -2, -1, 1, 2 };
array<int, arraySize> vertical = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main()
{
	int currentRow = 0;
	int currentColumn = 0;

	for (int i = 0; i <= 7; ++i)
	{
		for (int j = 0; j <= 7; ++j)
		{
			board = {};
			currentRow = i;
			currentColumn = j;
			int counter = 1;
			bool gameOver = false;

			while ((counter < 64) && !gameOver)
			{
				board[currentRow][currentColumn] = counter;

				bool foundMove = false;
				unsigned int moveNumber = 0;
				unsigned int accessible = 8;
				while (moveNumber <= 7)
				{
					int currR = currentRow;
					int currC = currentColumn;
					int currRow = currR + vertical[moveNumber];
					int currColumn = currC + horizontal[moveNumber];

					if ((currRow >= 0) && (currRow <= 7) && (currColumn >= 0) && (currColumn <= 7))
					{
						if ((board[currRow][currColumn] == 0) && (accessibility[currRow][currColumn] <= accessible))
						{
							if (currR != currentRow)
							{
								if (lookAhead(currRow, currColumn) < lookAhead(currentRow, currentColumn))
								{
									currentRow = currRow;
									currentColumn = currColumn;
									accessible = accessibility[currRow][currColumn];
									foundMove = true;
								}
							}
							else
							{
								currentRow = currRow;
								currentColumn = currColumn;
								accessible = accessibility[currRow][currColumn];
								foundMove = true;
							}
						}
					}

					if ((moveNumber == 7) && !foundMove)
					{
						gameOver = true;
						cout << counter << endl;
					}

					++moveNumber;
				}

				++counter;
			}
		}
	}



	/*for (auto const &row : board)
	{
	for (auto const &val : row)
	{
	cout << setw(3) << val << " ";
	}
	cout << endl << endl;
	}*/

	return 0;
}

int lookAhead(int const &nextRow, int const & nextColumn)
{
	unsigned int moveNumber = 0;
	unsigned int accessible = 8;
	while (moveNumber <= 7)
	{
		int currR = nextRow;
		int currC = nextColumn;
		int currRow = currR + vertical[moveNumber];
		int currColumn = currC + horizontal[moveNumber];

		if ((currRow >= 0) && (currRow <= 7) && (currColumn >= 0) && (currColumn <= 7))
		{
			if ((board[currRow][currColumn] == 0) && (accessibility[currRow][currColumn] < accessible))
			{

				accessible = accessibility[currRow][currColumn];
			}
		}

		++moveNumber;
	}

	return accessible;
}