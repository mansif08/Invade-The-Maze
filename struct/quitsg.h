#ifndef SGQUIT_H
#define SGQUIT_H

#include "object.h"

void setSGQuit(object& sgquit)
{
	sgquit.dest.w=300;
	sgquit.dest.h=100;
	sgquit.dest.x=WINDOW_WIDTH-900;
	sgquit.dest.y=WINDOW_HEIGHT-370;

	

}
#endif