#ifndef PLAYAGAIN_H
#define PLAYAGAIN_H

#include "object.h"
void setPlayag(object& playag)
{
	playag.dest.w = 600;
	playag.dest.h = 120;
	playag.dest.x = (WINDOW_WIDTH-playag.dest.w)/2;
	playag.dest.y = (WINDOW_HEIGHT-playag.dest.h)/2+150;        
}
#endif
