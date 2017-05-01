#include "Ghost.h"

#include "Wall.h"
#include "Maze.h"

using namespace std;

Ghost::Ghost(Maze* maze):
MovingGameObject(maze)
{
    SetColor(FL_RED);
    defaultSpeed = DEFAULT_GHOST_SPEED;
    speed = defaultSpeed;
}

void Ghost::OnCollisionWithWall(const Wall* wall)
{
    SetPosition(GetLastPosition());
    currentDirection = static_cast<DIRECTION>(FIRST + rand() % LAST);
    nextDirection = static_cast<DIRECTION>(FIRST + rand() % LAST);
}

