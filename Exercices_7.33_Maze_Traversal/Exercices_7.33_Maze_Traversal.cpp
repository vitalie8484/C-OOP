#include <iostream>
#include <array>
using namespace std;

const size_t arraySize = 12;

const int DOWN = 0;
const int RIGHT = 1;
const int UP = 2;
const int LEFT = 3;
const int X_START = 0;
const int Y_START = 2;
int move = 0;

array<array<char, arraySize>, arraySize> maze = {
				'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
				'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
				'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
				'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',
				'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.',
				'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#',
				'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
				'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
				'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
				'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
				'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',
				'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
			};

void mazeTravers(array<array<char, arraySize>, arraySize> &, int, int, int);
void printMaze();
bool mazeExited(int, int);
bool validMove(int, int);

int main()
{
	mazeTravers(maze, Y_START,X_START, RIGHT);

    return 0;
}

void mazeTravers(array<array<char, arraySize>, arraySize>& maze2, int y, int x, int direction)
{
	maze2[y][x] = 'X';
	++::move;
	printMaze();

	if ((x == X_START) && (y == Y_START) && (::move > 1))
	{
		cout << "Returned to starting location!" << endl;
		return;
	}
	else if (mazeExited(y, x) && (::move > 1)) 
	{
		cout << "Maze successfully exited!" << endl;
		return;
	}
	else
	{
		for (int move = direction, count = 0; count < 4; ++count, ++move, move %= 4)
		{
			switch (move)
			{
			case DOWN:
				if (validMove(y + 1, x))
				{
					mazeTravers(maze2, y + 1, x, LEFT);
					return;
				}
				break;
			case RIGHT:
				if (validMove(y, x + 1))
				{
					mazeTravers(maze2, y, x + 1, DOWN);
					return;
				}
				break;
			case UP:
				if (validMove(y - 1, x))
				{
					mazeTravers(maze2, y - 1, x, RIGHT);
					return;
				}
				break;
			case LEFT:
				if (validMove(y, x - 1))
				{
					mazeTravers(maze2, y, x - 1, UP);
					return;
				}
				break;
			}
		}
	}
}

bool validMove(int row, int column)
{
	return (row >= 0 && row <= 11 && 
		column >= 0 && column <= 11 && maze[row][column] != '#');
}

bool mazeExited(int row, int column)
{
	return (row == 0 || row == 11 || column == 0 || column == 11);
}

void printMaze()
{
	for (auto const &rows : maze)
	{
		for (auto const &val : rows)
		{
			cout << val << " ";
		}
		cout << endl;
	}
	cout << "*****************************************************" << endl;
}

