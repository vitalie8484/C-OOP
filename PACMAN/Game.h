#ifndef __EXAMEN__Game__
#define __EXAMEN__Game__

#include <iostream>

#include "Defines.h"
#include "Maze.h"
#include "Pacman.h"

// forward class declaration
// in loc de:
// #include "GameWindow.h"
// imposibil #include in doua directii
class GameWindow;

class Game
{
public:
    Game();
    ~Game();
    void OnTime(double time, double deltaTime);
    void OnGameEvent(GAME_EVENT event);
    void Draw(const GameWindow&) const;
    inline Vector2i GetGridSize() const { return maze.GetSize(); };

	void setScore(int i) { score = i; };
	int getScore() const { return score; };
	void setHighScore(int i) { highScore = i; };
	int getHighScore() const { return highScore; };
	void setLife(int i) { life = i; };
	int getLife() const { return life; };

private:
	void Load();
    void CheckGameOverConditions();
	void CheckHighScore();

private:
    Pacman pacman;
    Maze maze;
    bool gameOver;

	int score;
	int highScore;
	int life;
};

#endif /* defined(__EXAMEN__Game__) */
