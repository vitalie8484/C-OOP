#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <time.h>

#include "SnakeWindow.h"

int main(int argc, char **argv) {
    srand((unsigned int)time(0));
    Fl_Window *window = new SnakeWindow();
    window->show(argc, argv);
    return Fl::run();
}