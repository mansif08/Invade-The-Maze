#ifndef SHOW_H
#define SHOW_H

#include "object.h"

void show(SDL_Renderer* grend)
{
	SDL_RenderPresent(grend);
	SDL_Delay(1000/60);
}
#endif