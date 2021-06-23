#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "object.h"

void setGameover(object& gameover)
{
	gameover.dest.w = 500;
	gameover.dest.h = 300;
	gameover.dest.x = (WINDOW_WIDTH-600)/2+50;
	gameover.dest.y = (WINDOW_HEIGHT-320)/2-200;


}
#endif