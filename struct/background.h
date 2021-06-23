#ifndef BC_H
#define BC_H

#include "object.h"

void setBc(object& bc)
{

	    Mix_Music* bgmusic=Mix_LoadMUS("../Audio/bgmusic.mp3");
        if(!Mix_PlayingMusic())
        Mix_PlayMusic(bgmusic,-1);

    	SDL_QueryTexture(bc.tex, NULL, NULL, &bc.dest.w, &bc.dest.h);
	    bc.dest.w =WINDOW_WIDTH;
        bc.dest.h =WINDOW_HEIGHT;
        bc.dest.x=0;
        bc.dest.y=0;
	



}

#endif
