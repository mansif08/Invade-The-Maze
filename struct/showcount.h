#ifndef SHOWCOUNT_H
#define SHOWCOUNT_H

#include "object.h"

void showcount(int count,SDL_Renderer* grend,object digit[10])
{


	int c=0,d;
	int count2=count;

	if(count2==0)
	{

		SDL_RenderCopy(grend, digit[0].tex, NULL, &digit[0].show_rect);
	}

	else
	{

		while(count2>0)
		{

			d=count2%10;
			count2=count2/10;
			if(c==0)
			SDL_RenderCopy(grend, digit[d].tex, NULL, &digit[d].show_rect);
			else if(c==1)
			SDL_RenderCopy(grend, digit[d].tex, NULL, &digit[d].show_rect2);
			c++;

		}
	}

}
#endif