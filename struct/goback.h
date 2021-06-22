#ifndef GOBACK_H
#define GOBACK_H

#include "object.h"

void setgoBack(object& goback)
{
	goback.dest.w=200;
	goback.dest.h=50;
	goback.dest.x=(WINDOW_WIDTH/2)-100;
	goback.dest.y=28;

}
#endif