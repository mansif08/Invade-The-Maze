#ifndef MOUSEEVENTOVER_H
#define MOUSEEVENTOVER_H

#include "object.h"

void mouseeventover(object& hero,object& ghost,object& ghost2,object& target,object& playag,object& quit,int& gameovr,int& count,int& ovr,int& level,int& heartcount,object& bonus,int& verifyname,int& quit2)
{
	//interaction using mouse
	int mousex, mousey;
	int click = SDL_GetMouseState(&mousex, &mousey);

	if(click & SDL_BUTTON(SDL_BUTTON_LEFT))
	{

		if(mousex>=playag.dest.x && mousex<=(playag.dest.x+playag.dest.w) && mousey>=playag.dest.y && mousey<=(playag.dest.y+playag.dest.h))
		{
			//reinitialing
			gameovr=0;
			hero.dest.x=300;
			hero.dest.y=300;
			hero.x_pos=300;
			hero.y_pos=300;
			ghost.x_pos=500;
			ghost.y_pos=0;
			ghost2.x_pos=WINDOW_HEIGHT;
			ghost2.y_pos=550;
			count=0;
			level=1;
			heartcount=3;
			bonus.flag=0;
			bonus.vis5=0;
			bonus.vis15=0;
			bonus.vis25=0;
			bonus.vis35=0;
			bonus.vis45=0;
			bonus.vis55=0;
			bonus.vis65=0;
			bonus.vis75=0;
			bonus.vis85=0;
			verifyname=0;
			
			target.dest.y =(rand()%(WINDOW_HEIGHT-(50+50+70+40)))+50+70;

			if(target.dest.y>=120 &&  target.dest.y<=460)
			{
				target.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+450+40)))+50;
			}

			else if(target.dest.y>460 &&  target.dest.y<510)
			{
				target.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+215+40)))+50;

			}

			else if(target.dest.y>=510 &&  target.dest.y<=550)
			{
				target.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+215+40)))+50+90;

			}

			else if(target.dest.y>550 &&  target.dest.y<=640)
			{
				target.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+90+40)))+50+90;

			}

			else if(target.dest.y>640 &&  target.dest.y<=840)
			{
				target.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+150+40)))+50+150;

			}

			else
			{
				target.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+40)))+50;

			}

			target.px1=target.dest.x-40,target.px2=target.dest.x+40,target.py1=target.dest.y-40,target.py2=target.dest.y+40;
			target.x_pos=target.dest.x;
			target.y_pos=target.dest.y;


		}

		else if(mousex>=quit.dest.x && mousex<=(quit.dest.x+quit.dest.w) && mousey>=quit.dest.y && mousey<=(quit.dest.y+quit.dest.h))
			{
				ovr=1;
				quit2=1;
			}


	}

}
#endif