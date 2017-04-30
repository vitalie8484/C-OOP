#ifndef __Tp2_Snake5__SnakeWindow__
#define __Tp2_Snake5__SnakeWindow__

#include <iostream>
#include <FL/Fl_Window.H>
#include "Game.h"
#include "Vector2i.h"

class SnakeWindow : public Fl_Window
{
public:
    SnakeWindow();
    
    void OnTime(double totalTime);
    void DrawTileAt(Vector2i pos) const;
    void DrawTileAt(Vector2i pos, Fl_Color color) const;
    
    //Overrides Fl_Window
    int handle(int event);
    void draw();
    
    
private:
    void ProcessKeyDown(int key);
    
private:
    Game game;
};

#endif /* defined(__Tp2_Snake5__SnakeWindow__) */
