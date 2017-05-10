#ifndef __PACMAN__HUD__
#define __PACMAN__HUD__

#include <iostream>

class GameWindow;

class HUD
{
public:
    void Draw(const GameWindow& windowRef) const;
};

#endif /* defined(__PACMAN__HUD__) */
