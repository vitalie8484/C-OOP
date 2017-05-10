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

private:
	Game* game;
};

#endif /* defined(__PACMAN__HUD__) */
