#ifndef __PACMAN__Ghost__
#define __PACMAN__Ghost__

#include <iostream>

#include "Defines.h"
#include "MovingGameObject.h"

class Maze;
class Wall;

class Ghost : public MovingGameObject
{
public:
    Ghost(Maze* maze);

private:
    void OnCollisionWithWall(const Wall* wall);
};

#endif /* defined(__PACMAN__Ghost__) */
