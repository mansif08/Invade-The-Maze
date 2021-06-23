#ifndef SGSCORE_H
#define SGSCORE_H

#include "object.h"

void setSgscore(object& sgscore)
{
	sgscore.dest.w=300;
	sgscore.dest.h=100;
	sgscore.dest.x=WINDOW_WIDTH-900;
	sgscore.dest.y=WINDOW_HEIGHT-730;



}
#endif