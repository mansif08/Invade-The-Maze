#ifndef STAND_H
#define STAND_H

#include "object.h"

void setStand(object& stand)
{

	stand.dest.w=350;
	stand.dest.h=630;
	stand.dest.x=WINDOW_WIDTH-920;
	stand.dest.y=WINDOW_HEIGHT-870;


}
#endif