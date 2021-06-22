#ifndef PREPARE_H
#define PREPARE_H

#include "object.h"


void prepare(SDL_Renderer* grend,object& bc,object& hero,object& wall,object& wall2,object& wall3,object& wall4,object& ghost,object& ghost2,object& target,object& forest,object& river,object& oranget,object& greent,object& olivet,object& stone,object& treesin,object& score,object& title,object& heart1,object& heart2,object& heart3,int& heartcount,object& bonus,int& level)
{
	SDL_RenderClear(grend);
	SDL_RenderCopy(grend, bc.tex, NULL, &bc.dest); 
    SDL_RenderCopy(grend, hero.tex, NULL, &hero.dest);
    SDL_RenderCopy(grend, wall.tex, NULL, &wall.dest);
    SDL_RenderCopy(grend, wall2.tex, NULL, &wall2.dest);
    SDL_RenderCopy(grend, wall3.tex, NULL, &wall3.dest);
    SDL_RenderCopy(grend, wall4.tex, NULL, &wall4.dest);
    SDL_RenderCopy(grend, ghost.tex, NULL, &ghost.dest);
    SDL_RenderCopy(grend, target.tex, NULL, &target.dest);    
    SDL_RenderCopy(grend, forest.tex, NULL, &forest.dest);
    SDL_RenderCopy(grend, river.tex, NULL, &river.dest);
    SDL_RenderCopy(grend, oranget.tex, NULL, &oranget.dest);
    SDL_RenderCopy(grend, greent.tex, NULL, &greent.dest);
    SDL_RenderCopy(grend, olivet.tex, NULL, &olivet.dest);
    SDL_RenderCopy(grend, stone.tex, NULL, &stone.dest);
    SDL_RenderCopy(grend, treesin.tex, NULL, &treesin.dest);    
    SDL_RenderCopy(grend, score.tex, NULL, &score.dest);
    SDL_RenderCopy(grend, title.tex, NULL, &title.dest);

    if(heartcount>=3)
    SDL_RenderCopy(grend, heart3.tex, NULL, &heart3.dest);
    

    if(heartcount>=2)
    SDL_RenderCopy(grend, heart2.tex, NULL, &heart2.dest);


    if(heartcount>=1)
    SDL_RenderCopy(grend, heart1.tex, NULL, &heart1.dest);


    if(bonus.flag==1)
    SDL_RenderCopy(grend, bonus.tex, NULL, &bonus.dest);

    
    if(level==2)
    SDL_RenderCopy(grend, ghost2.tex, NULL, &ghost2.dest);










}
#endif