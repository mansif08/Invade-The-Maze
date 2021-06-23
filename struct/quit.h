#ifndef QUIT_H
#define QUIT_H

#include "object.h"

void setQuit(object& quit)
{
	quit.dest.w = 200;
    quit.dest.h = 70;
    quit.dest.x = WINDOW_WIDTH-170;
    quit.dest.y =0 ;


}
#endif