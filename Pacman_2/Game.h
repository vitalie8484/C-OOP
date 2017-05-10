#ifndef __EXAMEN__Game__
#define __EXAMEN__Game__

#include <iostream>

#include "Defines.h"
#include "Maze.h"
#include "Pacman.h"

class GameWindow;
class HUD;

class Game
{
public:
    Game(HUD* hud);
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
    void CheckGameOverConditions();

	void Load();
	void CheckHighScore();

private:
    Pacman pacman;
    Maze maze;
    bool gameOver;

	int score;
	int highScore;
	int life;
	HUD* hud;
};

#endif /* defined(__EXAMEN__Game__) */
