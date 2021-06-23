#ifndef STARTSCREENCHECK_H
#define STARTSCREENCHECK_H

#include "object.h"

void startscreencheck(int& playgame,int& quit,int& watchscore,int& watchcredit,int& watchinstruct,object& newgame,object& sgquit,object&  sgscore,object& credit,object& goback,object& sginstruct)
{
	int mousex, mousey;


	SDL_Event event;
	

	while(SDL_PollEvent(&event))
       	  {
       		  switch(event.type)
       		  {
       			case SDL_QUIT:
       			quit = 1;
       			

       			break;

       		   }
       	   }

      SDL_PumpEvents();

	



	if(SDL_GetMouseState(&mousex, &mousey) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		

		if(mousex>=newgame.dest.x && mousex<=(newgame.dest.x+newgame.dest.w) && mousey>=newgame.dest.y && mousey<=(newgame.dest.y+newgame.dest.h))
		{
			playgame = 1;

		}

		else if(mousex>=sgquit.dest.x && mousex<=(sgquit.dest.x+sgquit.dest.w) && mousey>=sgquit.dest.y && mousey<=(sgquit.dest.y+sgquit.dest.h))
		{
			quit= 1;

		}

		else if(mousex>=sgscore.dest.x && mousex<=(sgscore.dest.x+sgscore.dest.w) && mousey>=sgscore.dest.y && mousey<=(sgscore.dest.y+sgscore.dest.h))
		{
			watchscore= 1;

		}

		else if(mousex>=credit.dest.x && mousex<=(credit.dest.x+credit.dest.w) && mousey>=credit.dest.y && mousey<=(credit.dest.y+credit.dest.h))
		{
			watchcredit= 1;

		}

		else if(mousex>=sginstruct.dest.x && mousex<=(sginstruct.dest.x+sginstruct.dest.w) && mousey>=sginstruct.dest.y && mousey<=(sginstruct.dest.y+sginstruct.dest.h))
		{
			watchinstruct= 1;

		}


	}
	
	
}

#endif