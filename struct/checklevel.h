
#ifndef CHECKLEVEL_H
#define CHECKLEVEL_H

#include "object.h"


void checklevel(SDL_Renderer* grend,object& hero,object& ghost,object& ghost2,int& count,int& level,object& levelcompleted)
{

	if(level==1 && count>=10)//level gets over if count is greater than 10
	{

        Mix_Chunk* wmusic=Mix_LoadWAV("../Audio/tada.wav");
        Mix_PlayChannel(-1,wmusic,0);
		level=2;	
		SDL_RenderClear(grend);
		SDL_RenderCopy(grend, levelcompleted.tex, NULL, &levelcompleted.dest);
		SDL_RenderPresent(grend);
	    SDL_Delay(2000);


		hero.x_pos=300;
		hero.y_pos=300;
		ghost.x_pos=500;
		ghost.y_pos=0;
		ghost2.x_pos=WINDOW_WIDTH;
		ghost2.y_pos=550;

	}
	

}
#endif