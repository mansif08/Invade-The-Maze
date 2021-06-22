#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "object.h"



void gameControl(object& hero,int& paused,int& close,int& quit2)
{
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
			quit2=1;
			close = 1;
			break;
			case SDL_KEYDOWN:
			switch(event.key.keysym.scancode){

				case SDL_SCANCODE_LEFT:
				hero.x_pos = max(50,hero.x_pos-(SCROLL_SPEED/60));
				break;
				case SDL_SCANCODE_RIGHT:
				hero.x_pos = min(MAZE_WIDTH-hero.dest.w,hero.x_pos+(SCROLL_SPEED/60));
				break;
				case  SDL_SCANCODE_UP:
				hero.y_pos= max(50,hero.y_pos-(SCROLL_SPEED/60));
				break;
				case  SDL_SCANCODE_DOWN:
				hero.y_pos= min(MAZE_HEIGHT-hero.dest.h,hero.y_pos+(SCROLL_SPEED/60));
				break;
				case SDL_SCANCODE_ESCAPE:
				paused=1;
				break;

			}
		}
	}


}
#endif