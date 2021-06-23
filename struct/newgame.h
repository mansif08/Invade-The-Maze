#ifndef NEWGAME_H
#define NEWGAME_H

#include "object.h"

void setNewgame(object& newgame)
{

	newgame.dest.w=300;
	newgame.dest.h=100;
	newgame.dest.x=WINDOW_WIDTH-900;
	newgame.dest.y=WINDOW_HEIGHT-850;

}
#endif