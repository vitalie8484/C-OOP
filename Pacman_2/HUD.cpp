#include "HUD.h"

#include <FL/fl_draw.H>

void DrawTextAt(const char* text, int x, int y, Fl_Color color, int fontSize);

void HUD::Draw(const GameWindow& windowRef) const
{
    DrawTextAt("SCORE: XXX HIGH SCORE: XXX LIFE: XXX", 0, 22, FL_BLACK, 28);
}

void DrawTextAt(const char* text, int x, int y, Fl_Color color, int fontSize)
{
    fl_color(color);
    fl_font(0, fontSize);
    fl_draw(text, x, y);
}
