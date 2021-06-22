#ifndef OLIVET_H
#define OLIVET_H

#include "object.h"

void setOlivet(object& olivet)
{
	olivet.dest.w = 90;
	olivet.dest.h = 90;
	olivet.dest.x = WINDOW_WIDTH-140;
	olivet.dest.y = 550;


}
#endif
