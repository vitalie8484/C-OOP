#ifndef __EXAMEN__Game__
#define __EXAMEN__Game__

#include <iostream>

#include "Defines.h"
#include "Maze.h"
#include "Pacman.h"

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
    
private:
    void CheckGameOverConditions();

private:
    Pacman pacman;
    Maze maze;
    bool gameOver;
};

#endif /* defined(__EXAMEN__Game__) */
