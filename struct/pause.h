#ifndef PAUSE_H
#define PAUSE_H

#include "object.h"
void setPause(object& pause)
{
    pause.dest.w = 600;
	pause.dest.h = 320;
	pause.dest.x = (WINDOW_WIDTH-pause.dest.w)/2;
	pause.dest.y = (WINDOW_HEIGHT-pause.dest.h)/2-180;


}
#endif