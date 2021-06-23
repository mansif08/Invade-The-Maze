#ifndef INVADEMAZE_H
#define INVADEMAZE_H

#include "object.h"


void invademaze(SDL_Renderer* grend,object& inmaze,int& close)
{

    int esc=0;

    while(!esc && !close)
    {
    	
    	SDL_Event event;

        //keyboard interaction with user
    	while(SDL_PollEvent(&event)){
    		switch(event.type){
    			case SDL_QUIT:
    			close = 1;
    			break;
    			case SDL_KEYDOWN:
    			switch(event.key.keysym.scancode){

    				case SDL_SCANCODE_ESCAPE:
    				esc=1;
    				break;

    			}
    		}
    	}


    	SDL_RenderClear(grend);
    	SDL_RenderCopy(grend, inmaze.tex, NULL,NULL);  
    	SDL_RenderPresent(grend);
    }
	
	

}

#endif