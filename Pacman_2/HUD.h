#ifndef __PACMAN__HUD__
#define __PACMAN__HUD__

#include <iostream>
#include "Game.h"

class GameWindow;

class HUD
{
public:
	HUD(Game* game);
    void Draw(const GameWindow& windowRef) const;

	void setGameOver(bool b) { gameOver = b; }
	void setNewHighScore(bool b) { newHighScore = b; }

private:
	Game* game;
	bool gameOver;
	bool newHighScore;
};

#endif /* defined(__PACMAN__HUD__) */
