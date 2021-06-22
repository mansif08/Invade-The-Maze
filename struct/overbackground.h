#ifndef OVERBG_H
#define OVERBG_H

#include "object.h"

void setOverbg(object& overbg)
{
	overbg.dest.w = WINDOW_WIDTH;
    overbg.dest.h = WINDOW_HEIGHT;
    overbg.dest.x = 0;
    overbg.dest.y = 0;

}
#endif