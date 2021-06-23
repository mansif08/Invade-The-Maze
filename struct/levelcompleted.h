#ifndef LEVELCOMPLETED_H
#define LEVELCOMPLETED_H

#include "object.h"

void setLevelcompleted(object& levelcompleted)
{
	  levelcompleted.dest.w=WINDOW_WIDTH;
        levelcompleted.dest.h=WINDOW_HEIGHT;
        levelcompleted.dest.x=0;
        levelcompleted.dest.y=0;


}
#endif