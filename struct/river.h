#ifndef RIVER_H
#define RIVER_H

#include "object.h"

void setRiver(object& river)
{
	river.dest.w = 450;
	river.dest.h = 340;
	river.dest.x = WINDOW_WIDTH-500;
	river.dest.y = 120;
}
#endif