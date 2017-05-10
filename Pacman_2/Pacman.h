#ifndef __PACMAN__Pacman__
#define __PACMAN__Pacman__

#include <iostream>

#include "Defines.h"
#include "MovingGameObject.h"
#include "Vector2i.h"

class Ghost;
class Wall;
class Maze;

class Pacman : public MovingGameObject
{
public:
    Pacman(Maze* maze);
    inline bool IsDead() const { return dead; };

private:
    void OnCollisionWithWall(const Wall* wall);
    void OnCollisionWithGhost(const Ghost* ghost);
    
private:
    bool dead;
};

#endif /* defined(__PACMAN__Pacman__) */
