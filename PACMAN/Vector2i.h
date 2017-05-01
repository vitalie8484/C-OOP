#ifndef __EXAMEN__Vector2i__
#define __EXAMEN__Vector2i__

#include <iostream>

class Vector2i
{
public:
    Vector2i();
    Vector2i(int x, int y);
    bool Equals(const Vector2i&)const;
    std::string ToString() const;
    int x;
    int y;
};

#endif /* defined(__EXAMEN__Vector2i__) */
