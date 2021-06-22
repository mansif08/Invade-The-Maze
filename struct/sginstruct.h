#ifndef SGINSTRUCT_H
#define SGINSTRUCT_H

#include "object.h"

void setSGinstruct(object& sginstruct)
{
	sginstruct.dest.w=300;
	sginstruct.dest.h=100;
	sginstruct.dest.x=WINDOW_WIDTH-900;
	sginstruct.dest.y=WINDOW_HEIGHT-490;

}
#endif