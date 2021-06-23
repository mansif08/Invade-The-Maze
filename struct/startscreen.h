#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "object.h"

void setStartscreen(object& startscreen)
{
	startscreen.dest.w=WINDOW_WIDTH;
	startscreen.dest.h=WINDOW_HEIGHT;
	startscreen.dest.x=0;
	startscreen.dest.y=0;

}
#endif