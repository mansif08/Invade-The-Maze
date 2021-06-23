#ifndef SHOWINSTRUCT_H
#define SHOWINSTRUCT_H

#include "object.h"
#include "checkgoback.h"

void showinstruct(SDL_Renderer* grend, object& goback,int& quit,int& watchinstruct)
{
	SDL_Texture* instruct;
	int show=1;

	while(watchinstruct)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				quit = 1;
				watchinstruct=0;


				break;

			}
		}

		

		if(show==1)
		{
			show=0;

			SDL_Surface* surfaceinstruct =IMG_Load("../Images/INSTRUCTIONS.png"); 
			instruct = SDL_CreateTextureFromSurface(grend, surfaceinstruct);
			SDL_FreeSurface( surfaceinstruct );

			SDL_RenderCopy(grend, instruct, NULL, NULL);

			SDL_RenderCopy(grend, goback.tex, NULL, &goback.dest);
	

			SDL_RenderPresent(grend);
		}

		checkgoback3(goback,watchinstruct);



	}

	instruct=NULL;
	
	
	
}

#endif