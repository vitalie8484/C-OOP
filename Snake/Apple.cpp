#include "Apple.h"
#include "SnakeWindow.h"

void Apple::Draw(const SnakeWindow& windowRef) const
{
    windowRef.DrawTileAt(position, FL_RED);
}