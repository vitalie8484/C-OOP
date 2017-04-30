#ifndef __TP2_SNAKE__Snake__
#define __TP2_SNAKE__Snake__

#include <iostream>
#include <deque>

#include "Vector2d.h"
#include "Defines.h"

class SnakeWindow;

class Snake
{
public:
    Snake(Vector2d position);
    void Move(double deltaTime);
	void MoveBy(double deltaPosition);
    void SetDirection(DIRECTION value);
    void IncreaseLengthBy1();
    void Draw(const SnakeWindow& windowRef) const;
    Vector2d GetPosition() const;
    bool IsRollOver() const;
    bool IsOnSnake(Vector2i pos) const;
private:
    //TODO add your private functions prototypes here
	void MoveOneStep();
    
private:
    //TODO add your private members here
	Vector2d head;
	DIRECTION direction;
	std::deque<Vector2d> sections;
};

#endif /* defined(__TP2_SNAKE__Snake__) */
