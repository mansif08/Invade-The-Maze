#ifndef FOREST_H
#define FOREST_H

#include "object.h"

void setForest(object& forest)
{

	forest.dest.w = WINDOW_WIDTH-100;
	forest.dest.h = 70;
	forest.dest.x = 0;
	forest.dest.y = 50;
}
#endif
