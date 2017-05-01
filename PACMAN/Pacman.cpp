#include "Pacman.h"

#include "Ghost.h"
#include "Vector2i.h"
#include "Wall.h"

using namespace std;

Pacman::Pacman(Maze* maze):
MovingGameObject(maze),
dead(false)
{
    SetColor(FL_BLUE);
    defaultSpeed = DEFAULT_PACMAN_SPEED;
    speed = 0;
}

void Pacman::OnCollisionWithWall(const Wall* wall)
{
    speed = 0;
    SetPosition(GetLastPosition());
}

void Pacman::OnCollisionWithGhost(const Ghost* ghost)
{
    dead = true;
}

