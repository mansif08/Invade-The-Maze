#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "object.h"


int instruction(SDL_Renderer* grend,object instruct)
{
	int enter=0,close=0;

	while(!enter && !close)
	{

		SDL_Event event;

		while(SDL_PollEvent(&event))
		{

			switch(event.type)
			{
				case SDL_QUIT:
				close=1;
				break;

				case SDL_KEYDOWN:
				switch(event.key.keysym.scancode)
				{
					case SDL_SCANCODE_ESCAPE:
					enter=1;
					break;

				}

			}


		}

		SDL_RenderClear(grend);
		SDL_RenderCopy(grend,instruct.tex,NULL,NULL);
		SDL_RenderPresent(grend);
	}

	if(enter==1)
	{
		return 1;

	}

	if(close==1)
	{
		return 0;

	}

}
#endif