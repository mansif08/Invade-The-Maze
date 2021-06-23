#ifndef POINTS_H
#define POINTS_H

#include "object.h"


void points(object& hero,object ghost2,int& count,object& target,object& bonus,int& level)
{
	if( (hero.x_pos>=target.px1 && hero.x_pos<=target.px2) && (hero.y_pos>=target.py1 && hero.y_pos<=target.py2) )//achieving targets
	{

	  Mix_Chunk* tmusic=Mix_LoadWAV("../Audio/treasurem.wav");
	  
      Mix_PlayChannel(-1,tmusic,0);
	  

	  count++;
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

	if( bonus.flag==1 && (hero.x_pos>=bonus.px1 && hero.x_pos<=bonus.px2) && (hero.y_pos>=bonus.py1 && hero.y_pos<=bonus.py2) )//achieving points
	{
		 Mix_Chunk* tmusic=Mix_LoadWAV("../Audio/treasurem.wav");
	  
         Mix_PlayChannel(-1,tmusic,0);
	 
		count=count+4;
		bonus.flag=0;

	}


	if(level==2)//white ghost taking away the points
	{
		if( bonus.flag==1 && (ghost2.x_pos>=bonus.px1 && ghost2.x_pos<=bonus.px2) && (ghost2.y_pos>=bonus.py1 && ghost2.y_pos<=bonus.py2) )
		{
			bonus.flag=0;

		}

		else if((ghost2.x_pos>=target.px1 && ghost2.x_pos<=target.px2) && (ghost2.y_pos>=target.py1 && ghost2.y_pos<=target.py2))
		{
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
			


	}



}
#endif