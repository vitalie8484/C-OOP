#include "HUD.h"

#include <string>

#include <FL/fl_draw.H>

void DrawTextAt(const char* text, int x, int y, Fl_Color color, int fontSize);

HUD::HUD(Game* game) :
	game(game)
{
}

void HUD::Draw(const GameWindow& windowRef) const
{
	// "SCORE: XXX HIGH SCORE: XXX LIFE: XXX"
	std::string s = "SCORE: ";
	s += std::to_string(game->getScore());
	s += " HIGH SCORE : ";
	s += std::to_string(game->getHighScore());
	s += " LIFE : ";
	s += std::to_string(game->getLife());

    DrawTextAt(s.c_str(), 0, 22, FL_BLACK, 28);
}

void DrawTextAt(const char* text, int x, int y, Fl_Color color, int fontSize)
{
    fl_color(color);
    fl_font(0, fontSize);
    fl_draw(text, x, y);
}
