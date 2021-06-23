#ifndef TITLE_H
#define TITLE_H

#include "object.h"

void setTitle(object& title)
{

	title.dest.w = 300;
	title.dest.h = 60;
	title.dest.x = (WINDOW_WIDTH/2)-150;
	title.dest.y = 0;

}
#endif