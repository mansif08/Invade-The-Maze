#ifndef HERO_H
#define HERO_H

#include "object.h"

void setHero(object& hero)
{
       SDL_QueryTexture(hero.tex, NULL, NULL, &hero.dest.w, &hero.dest.h);
	   hero.dest.w = 40;
       hero.dest.h = 40;
       hero.dest.x = 300;
       hero.dest.y = 300;
       hero.x_pos=300;
       hero.y_pos=300;
   
}

#endif
