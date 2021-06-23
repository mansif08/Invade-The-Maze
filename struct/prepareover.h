#ifndef PREPAREOVER_H
#define PREPAREOVER_H

#include "object.h"

void prepareover(SDL_Renderer* grend,object overbg,object playag,object quit,object overscore,object& mainmenu,object& gamecompleted)
{
	SDL_RenderClear(grend);
	SDL_RenderCopy(grend, overbg.tex, NULL, &overbg.dest);
	SDL_RenderCopy(grend, playag.tex, NULL, &playag.dest);
    SDL_RenderCopy(grend, quit.tex, NULL, &quit.dest);
    SDL_RenderCopy(grend, overscore.tex, NULL, &overscore.dest);
    SDL_RenderCopy(grend, mainmenu.tex, NULL, &mainmenu.dest);
    

}
#endif