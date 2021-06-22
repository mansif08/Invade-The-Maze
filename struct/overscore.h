#ifndef OVERSCORE_H
#define OVERSCORE_H

#include "object.h"

void setOverscore(object& overscore)
{

	overscore.dest.w = 400;
	overscore.dest.h = 100;
	overscore.dest.x = (WINDOW_WIDTH/2)-200;
	overscore.dest.y = 800;

}
#endif