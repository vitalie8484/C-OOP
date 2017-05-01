#ifndef EXAMEN_Defines_h
#define EXAMEN_Defines_h

//According to documentation, repeat_timeout has a fair degree of accuracy up to 60 fps. Let's run at 30fps.
const double FRAME_DURATION_SECONDS = 1.0/30.0;

#define INITIAL_DIRECTION WEST
#define DEFAULT_GHOST_SPEED 7
#define DEFAULT_PACMAN_SPEED 8

enum GAME_EVENT
{
    SET_DIRECTION_WEST,
    SET_DIRECTION_EAST,
    SET_DIRECTION_NORTH,
    SET_DIRECTION_SOUTH,
    DEBUG_MOVE_BY,
};

enum DIRECTION
{
    NORTH = 1,
    SOUTH,
    EAST,
    WEST,
    FIRST = NORTH,
    LAST = WEST
};

#endif
