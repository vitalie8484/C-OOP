#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <time.h>

#include "GameWindow.h"

//argc - numarul de arg
int main(int argc, char **argv)
{
	// seed random
    srand((unsigned int)time(0));

    GameWindow w;
    w.show(argc, argv);

	// run() - static function
    return Fl::run();
}