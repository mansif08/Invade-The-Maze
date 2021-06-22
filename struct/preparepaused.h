#ifndef PREPAREPAUSED_H
#define PREPAREPAUSED_H

#include "object.h"

void preparepaused(SDL_Renderer* grend,object& overbg,object& pause,object& resume,object& playag,object& quit,object& mainmenu)
{
	SDL_RenderClear(grend);
    SDL_RenderCopy(grend, overbg.tex, NULL, &overbg.dest);
    SDL_RenderCopy(grend, pause.tex, NULL, &pause.dest);
    SDL_RenderCopy(grend, resume.tex, NULL, &resume.dest);
    SDL_RenderCopy(grend, quit.tex, NULL, &quit.dest);
    SDL_RenderCopy(grend, mainmenu.tex, NULL, &mainmenu.dest);
}

#endif