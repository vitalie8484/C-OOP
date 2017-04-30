#ifndef __TP2_SNAKE__Vector2d__
#define __TP2_SNAKE__Vector2d__

#include <iostream>
#include "Vector2i.h"

class Vector2d
{
public:
    Vector2d();
    Vector2d(double x, double y);
    Vector2i ToVector2i()const;
    double x;
    double y;
};

#endif /* defined(__TP2_SNAKE__Vector2d__) */
