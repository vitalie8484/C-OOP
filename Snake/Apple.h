#ifndef __TP2_SNAKE__Apple__
#define __TP2_SNAKE__Apple__

#include <iostream>

#include "Vector2i.h"

class SnakeWindow;

class Apple
{
public:
    Apple() {}
    
    inline Vector2i GetPosition() const { return position; }
    inline void SetPosition(Vector2i value) { position = value; }
    
    void Draw(const SnakeWindow& windowRef) const;
    
private:
    Vector2i position;
};

#endif /* defined(__TP2_SNAKE__Apple__) */
