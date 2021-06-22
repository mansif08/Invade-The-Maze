#ifndef CREDIT_H
#define CREDIT_H

#include "object.h"

void setCredit(object& credit)
{
	credit.dest.w=300;
	credit.dest.h=100;
	credit.dest.x=WINDOW_WIDTH-900;
	credit.dest.y=WINDOW_HEIGHT-610;



}
#endif