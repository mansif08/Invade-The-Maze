#ifndef SCORE_H
#define SCORE_H

#include "object.h"

void setScore(object& score)
{

	score.dest.w = 120;
	score.dest.h = 50;
	score.dest.x = WINDOW_WIDTH-300;
	score.dest.y = 0;

}
#endif