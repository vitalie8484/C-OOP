#ifndef __EXAMEN__GameWindow__
#define __EXAMEN__GameWindow__

#include <iostream>

#include <FL/Fl_Window.H>

#include "Game.h"
#include "HUD.h"
#include "Vector2i.h"

class GameWindow : public Fl_Window
{
public:
    GameWindow();
    ~GameWindow();
    
    void OnTime(double totalTime);
    void DrawTileAt(Vector2i pos) const;
    void DrawTileAt(Vector2i pos, Fl_Color color) const;
    void DrawInnerTileAt(Vector2i pos, double pct, Fl_Color color) const;
    
    //Overrides Fl_Window
    int handle(int event);
    void draw();
    
private:
    void ProcessKeyDown(int key);
    
private:
    Game game;
    HUD hud;
};

#endif /* defined(__EXAMEN__GameWindow__) */
