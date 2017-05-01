#include "SnakeWindow.h"

#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/fl_draw.H>

#include "Defines.h"
#include "Game.h"

const int WINDOW_SIZE = 800;

//According to documentation, repeat_timeout has a fair degree of accuracy up to 60 fps. Let's run at 30fps.
const double FRAME_DURATION_SECONDS = 1.0/60.0;

void OnTimeCB(void*);
double totalTime = 0;

SnakeWindow::SnakeWindow() : Fl_Window(WINDOW_SIZE, WINDOW_SIZE)
{
    Fl::add_timeout(FRAME_DURATION_SECONDS, OnTimeCB, this);
}

int SnakeWindow::handle(int event)
{
    switch(event)
    {
        case FL_KEYDOWN:
            ProcessKeyDown(Fl::event_key());
            return 1;
        default:
            return Fl_Widget::handle(event);
    }
}

void SnakeWindow::ProcessKeyDown(int key)
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
        default:
            std::cout << "Received unknown key:" << key << std::endl;
    }
}

void SnakeWindow::draw()
{
    //std::cout << "SnakeWindow::draw()" << std::endl;
    fl_rectf(0, 0, WINDOW_SIZE, WINDOW_SIZE, FL_GREEN);
    game.Draw(*this);
}

void SnakeWindow::DrawTileAt(Vector2i pos) const
{
    DrawTileAt(pos, FL_BLACK);
}

void SnakeWindow::DrawTileAt(Vector2i pos, Fl_Color color) const
{
    static int tileSize = WINDOW_SIZE / game.GetGridSize().x;
    fl_rectf(pos.x * tileSize, pos.y * tileSize, tileSize, tileSize, color);
}

void SnakeWindow::OnTime(double totalTime)
{
    //std::cout << "OnTime " << totalTime << std::endl;
    game.OnTime(totalTime, FRAME_DURATION_SECONDS);
    flush();
}

void OnTimeCB(void* data)
{
    totalTime += FRAME_DURATION_SECONDS;
    SnakeWindow* window = (SnakeWindow*)data;
    window->OnTime(totalTime);
    Fl::repeat_timeout(FRAME_DURATION_SECONDS, OnTimeCB, data);
}
