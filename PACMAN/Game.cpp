#include <fstream>
#include "Game.h"
#include "GameWindow.h"

using namespace std;

Game::Game() :
	pacman(&maze),
	maze(&pacman, this),
	gameOver(false),
	score(0),
	highScore(0),
	life(0)
{
	Load();
}

Game::~Game()
{
    cout << "Game DTOR" << endl;
    maze.Unload();
}

void Game::Load()
{
	ifstream dataFile("data.dat", ios::in);
	if (!dataFile)
	{
		cerr << "Cannot load data." << endl;
		return;
	}

	dataFile >> highScore >> life;

	dataFile.close();
}

void Game::OnTime(double time, double deltaTime)
{
    if(!gameOver)
    {
        maze.PhysicStep(time, deltaTime);
        CheckGameOverConditions();
    }
}

void Game::OnGameEvent(GAME_EVENT event)
{
    switch(event)
    {
        case SET_DIRECTION_EAST:
            pacman.SetDirection(EAST);
            break;
        case SET_DIRECTION_WEST:
            pacman.SetDirection(WEST);
            break;
        case SET_DIRECTION_NORTH:
            pacman.SetDirection(NORTH);
            break;
        case SET_DIRECTION_SOUTH:
            pacman.SetDirection(SOUTH);
            break;
        case DEBUG_MOVE_BY:
            pacman.MoveBy(1.0);
            break;
        default:
            std::cerr << "Invalid event=" << event << std::endl;
    }
}

void Game::Draw(const GameWindow& windowRef) const
{
    maze.Draw(windowRef);
    pacman.Draw(windowRef);
}

void Game::CheckGameOverConditions()
{
	gameOver = maze.GetNbRemainingDots() == 0;

	if (gameOver)
	{
		CheckHighScore();
		cout << "GAME OVER - YOU WIN!" << endl;
		return;
	}

	gameOver = pacman.IsDead();

	if (gameOver)
	{
		CheckHighScore();
		cout << "GAME OVER - YOU LOOSE!" << endl;
		return;
	}
//    else
//    {
//        cout << "Still " << maze.GetNbRemainingDots() << " dots to collect." << endl;
//    }
}

void Game::CheckHighScore()
{
	int localHighScore;
	int localLife;
	fstream dataFile;

	dataFile.open("data.dat", ios::in);
	if (!dataFile)
	{
		cerr << "Cannot load data." << endl;
		return;
	}

	dataFile >> localHighScore >> localLife;

	dataFile.close();

	if (score > localHighScore)
	{
		dataFile.open("data.dat", ios::out);

		if (!dataFile)
		{
			cerr << "Cannot load data." << endl;
			return;
		}

		dataFile << score << ' ' << localLife << endl;

		dataFile.close();
	}

	dataFile.close();
}