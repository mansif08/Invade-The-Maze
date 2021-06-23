#include "object.h"

void showcountover(int count,SDL_Renderer* grend,object digit[10],object& gameover,object& gamecompleted)
{
	if(count!=100)
	SDL_RenderCopy(grend, gameover.tex, NULL, &gameover.dest);

	else
	{
		SDL_RenderCopy(grend, gamecompleted.tex, NULL, &gamecompleted.dest);
	}


	if(count<100)
	{

		int c=0,d;
		int count2=count;
		if(count2==0)
		{

			SDL_RenderCopy(grend, digit[0].tex, NULL, &digit[0].over_rect);
		}

		else
		{

			while(count2>0)
			{

				d=count2%10;
				count2=count2/10;
				if(c==0)
					SDL_RenderCopy(grend, digit[d].tex, NULL, &digit[d].over_rect);
				else if(c==1)
					SDL_RenderCopy(grend, digit[d].tex, NULL, &digit[d].over_rect2);
				c++;

			}
		}
	}

	else
	{

		SDL_Rect over_rect,over_rect2,over_rect3;
		over_rect.x=digit[1].over_rect.x-100;
		over_rect.y=digit[1].over_rect.y;
		over_rect.w=digit[1].over_rect.w;
		over_rect.h=digit[1].over_rect.h;

		over_rect2.x=digit[0].over_rect.x;
		over_rect2.y=digit[0].over_rect.y;
		over_rect2.w=digit[0].over_rect.w;
		over_rect2.h=digit[0].over_rect.h;

		over_rect3.x=digit[0].over_rect.x+100;
		over_rect3.y=digit[0].over_rect.y;
		over_rect3.w=digit[0].over_rect.w;
		over_rect3.h=digit[0].over_rect.h;
		
		SDL_RenderCopy(grend, digit[0].tex, NULL, &over_rect3);
		SDL_RenderCopy(grend, digit[0].tex, NULL, &over_rect2);
		SDL_RenderCopy(grend, digit[1].tex, NULL, &over_rect);


	}

}