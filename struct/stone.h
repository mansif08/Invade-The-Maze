#ifndef STONE_H
#define STONE_H

#include "object.h"

void setStone(object& stone)
{
	stone.dest.w = 150;
	stone.dest.h = 150;
	stone.dest.x = 50;
	stone.dest.y =WINDOW_HEIGHT-270;



}

#endif
