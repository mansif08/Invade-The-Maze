#ifndef PREPARESTARTSCREEN_H
#define PREPARESTARTSCREEN_H

#include "object.h"


void preparestartscreen(SDL_Renderer* grend,object& startscreen,object& newgame,object& sgquit,object& sgscore,object& credit,object& stand,object& goback,object& sginstruct)
{
	SDL_RenderClear(grend);

	SDL_RenderCopy(grend, startscreen.tex, NULL, &startscreen.dest); 
	SDL_RenderCopy(grend, stand.tex, NULL, &stand.dest);
    SDL_RenderCopy(grend, newgame.tex, NULL, &newgame.dest);
    SDL_RenderCopy(grend, sgquit.tex, NULL, &sgquit.dest);
	SDL_RenderCopy(grend, sgscore.tex, NULL, &sgscore.dest); 
    SDL_RenderCopy(grend, credit.tex, NULL, &credit.dest);
    SDL_RenderCopy(grend, sginstruct.tex, NULL, &sginstruct.dest);
     
    //SDL_RenderCopy(grend, goback.tex, NULL, &goback.dest);
    
    

}

#endif