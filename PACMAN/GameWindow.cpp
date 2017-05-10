#include "GameWindow.h"

#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>

#include "Defines.h"

using namespace std;

const int WINDOW_SIZE = 810;//Make sure it fits game's size.

void OnTimeCB(void*);
double totalTime = 0;

GameWindow::GameWindow() : 
	Fl_Window(WINDOW_SIZE, WINDOW_SIZE),
	hud(&game)
{
	// in x seconds call OnTimeCB at infinit
    Fl::add_timeout(FRAME_DURATION_SECONDS, OnTimeCB, this);
}

GameWindow::~GameWindow()
{
    cout << "GameWindow DTOR" << endl;
}

int GameWindow::handle(int event)
{
	Fl_Window::handle(event);
    switch(event)
    {
        case FL_KEYDOWN:
            ProcessKeyDown(Fl::event_key());
            return 1;
        default:
            return Fl_Widget::handle(event);
    }
}

void GameWindow::ProcessKeyDown(int key)
{
    switch(key)
    {
        case 65361://Left arrow
            //std::cout << "Left" << std::endl;
            game.OnGameEvent(SET_DIRECTION_WEST);
            break;
        case 65362://Up arrow
            //std::cout << "Up" << std::endl;
            game.OnGameEvent(SET_DIRECTION_NORTH);
            break;
        case 65363://Right arrow
            //std::cout << "Right" << std::endl;
            game.OnGameEvent(SET_DIRECTION_EAST);
            break;
        case 65364://Down arrow
            //std::cout << "Down" << std::endl;
            game.OnGameEvent(SET_DIRECTION_SOUTH);
            break;
        case 97://A
            game.OnGameEvent(DEBUG_MOVE_BY);
            break;
        case 113://Q
            hide();
            break;
        default:
            std::cout << "Received unknown key:" << key << std::endl;;
    }
}

void GameWindow::draw()
{
    fl_rectf(0, 0, WINDOW_SIZE, WINDOW_SIZE, FL_BLACK);
    game.Draw(*this);
    hud.Draw(*this);
}

void GameWindow::DrawTileAt(Vector2i pos) const
{
    DrawTileAt(pos, FL_BLACK);
}

void GameWindow::DrawTileAt(Vector2i pos, Fl_Color color) const
{
    DrawInnerTileAt(pos, 1, color);
}

void GameWindow::DrawInnerTileAt(Vector2i pos, double pct, Fl_Color color) const
{
    if(WINDOW_SIZE % game.GetGridSize().x != 0)
    {
        cerr << "Watch out. The grid does not fit the window size!" << endl;
    }
    static int tileSize = WINDOW_SIZE / game.GetGridSize().x;
    int offset = (1.0 - pct) * tileSize / 2;
    int side = tileSize * pct;
    fl_rectf(pos.x * tileSize + offset, pos.y * tileSize + offset, side, side, color);
}

void GameWindow::OnTime(double totalTime)
{
    game.OnTime(totalTime, FRAME_DURATION_SECONDS);
    flush();
}

void OnTimeCB(void* data)
{
    totalTime += FRAME_DURATION_SECONDS;
    GameWindow* window = (GameWindow*)data;
    window->OnTime(totalTime);
    Fl::repeat_timeout(FRAME_DURATION_SECONDS, OnTimeCB, data);
}
