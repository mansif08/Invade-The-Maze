#ifndef MOUSEEVENTPAUSED_H
#define MOUSEEVENTPAUSED_H

#include "object.h"

void mouseeventpaused(object& playag,object&quit,int& paused,int& ovr,int& quit2)
{
	//interaction using mouse 
	int mousex, mousey;
	
	int click = SDL_GetMouseState(&mousex, &mousey);


	if(click & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if(mousex>=playag.dest.x && mousex<=(playag.dest.x+playag.dest.w) && mousey>=playag.dest.y && mousey<=(playag.dest.y+playag.dest.h))
		{
			paused = 0;

		}
		else if(mousex>=quit.dest.x && mousex<=(quit.dest.x+quit.dest.w) && mousey>=quit.dest.y && mousey<=(quit.dest.y+quit.dest.h))
			{
				quit2=1;
				ovr=1;
			}
		}
}

#endif