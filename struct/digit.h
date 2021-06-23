
#ifndef DIGIT_H
#define DIGIT_H
#include "object.h"

void setDigit(object& digit)
{

	digit.over_rect.w = 100;
	digit.over_rect.h = 100;
	digit.over_rect.x = ((WINDOW_WIDTH)/2)+350;
	digit.over_rect.y = 800;

	

	digit.over_rect2.w = 100;
	digit.over_rect2.h = 100;
	digit.over_rect2.x = ((WINDOW_WIDTH)/2)+250;
	digit.over_rect2.y = 800;


	

	digit.show_rect.w = 50;
	digit.show_rect.h = 50;
	digit.show_rect.x = WINDOW_WIDTH-50;
	digit.show_rect.y = 0;

	
	digit.show_rect2.w = 50;
	digit.show_rect2.h = 50;
	digit.show_rect2.x = WINDOW_WIDTH-100;
	digit.show_rect2.y = 0;

}
#endif