#ifndef GAMECOMPLETED_H
#define GAMECOMPLETED_H

#include "object.h"

void setGamecompleted(object& gamecompleted)
{
	gamecompleted.dest.w = 500;
	gamecompleted.dest.h = 300;
	gamecompleted.dest.x = (WINDOW_WIDTH-600)/2+50;
	gamecompleted.dest.y = (WINDOW_HEIGHT-320)/2-200;


}
#endif