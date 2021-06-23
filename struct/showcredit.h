#ifndef SHOWCREDIT_H
#define SHOWCREDIT_H

#include "object.h"
#include "checkgoback.h"

void showcredit(SDL_Renderer* grend, object& goback,int& quit,int& watchcredit)
{
	SDL_Texture* credit;
	int show=1;
	    
	while(watchcredit)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				quit = 1;
     			watchcredit=0;


				break;

			}
		}

		if(show==1)
		{
			show=0;

			SDL_Surface* surfacecredit =IMG_Load("../Images/credit2.png"); 
			credit = SDL_CreateTextureFromSurface(grend, surfacecredit);
			SDL_FreeSurface( surfacecredit );

			SDL_RenderCopy(grend, credit, NULL, NULL);

			SDL_RenderCopy(grend, goback.tex, NULL, &goback.dest);

			

			SDL_RenderPresent(grend);
		}
		
		checkgoback2(goback,watchcredit);





	}

	credit=NULL;
	
	
	
}

#endif