#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <time.h>

#include "GameWindow.h"

int main(int argc, char **argv)
{
    srand((unsigned int)time(0));
    GameWindow w;
    w.show(argc, argv);
    return Fl::run();
}