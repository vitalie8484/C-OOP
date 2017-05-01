#ifndef __PACMAN__GameObject__
#define __PACMAN__GameObject__

#include <iostream>

#include <FL/Fl_Window.H>

#include "Vector2i.h"

class GameWindow;

class GameObject
{
public:
    GameObject();
    virtual ~GameObject() {}
    
    inline Vector2i GetPosition() const { return position; }
    inline void SetPosition(Vector2i position) { this->position = position; }
    
    inline Fl_Color GetColor() const { return color; }
    inline void SetColor(Fl_Color color) { this->color = color; }
    
    inline bool IsVisible() const { return visible; }
    inline void SetVisible(bool visible) { this->visible = visible; }
    
    bool Collides(const GameObject* other) const;
    
    virtual void OnCollision(const GameObject* other) = 0;
    virtual void Draw(const GameWindow& windowRef) const;
    
private:
    Vector2i position;
    Fl_Color color;
    bool visible;
};

#endif /* defined(__PACMAN__GameObject__) */
