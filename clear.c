#include "shell.h"

void clear()
{
    system(CLEAR_SCREEN);
}

void clearLine()
{
    system(CLEAR_LINE);
}

void clearScreenLine()
{
    system(CLEAR_SCREEN_LINE);
}

void clearLineScreen()
{
    system(CLEAR_LINE_SCREEN);
}
