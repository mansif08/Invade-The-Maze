#ifndef GHOSTPOSITION_H
#define GHOSTPOSITION_H

#include "object.h"

void ghostposition(object& hero,object& ghost,object& ghost2,object& target,object& bonus,int& level)
{
	ghost.dest.x=ghost.x_pos;
    ghost.dest.y=ghost.y_pos;
    ghost2.dest.x=ghost2.x_pos;
    ghost2.dest.y=ghost2.y_pos;  


	if( ! ( (hero.dest.x+hero.dest.w>=ghost.dest.x  &&  hero.dest.x+hero.dest.w<=ghost.dest.x+ghost.dest.w  ) || (hero.dest.x>=ghost.dest.x && hero.dest.x<=ghost.dest.x+ghost.dest.w )))
	{  

		if(ghost.x_pos<hero.dest.x)
		{
			ghost.x_pos += (GHOST_SPEED/60);
		}
		else if(ghost.x_pos>hero.dest.x)
		{
			ghost.x_pos -=  (GHOST_SPEED/60);

		}
	}

	if(!( (hero.dest.y>=ghost.dest.y  &&  hero.dest.y<=ghost.dest.y+ ghost.dest.h)    ||    (hero.dest.y+hero.dest.h>=ghost.dest.y  &&  hero.dest.y+hero.dest.h<=ghost.dest.y+ ghost.dest.h) ))
	{

		if(ghost.y_pos<hero.dest.y)
		{

			ghost.y_pos += (GHOST_SPEED/60);

		}
		else if(ghost.y_pos>hero.dest.y)
		{

			ghost.y_pos -= (GHOST_SPEED/60);

		}


	}
	

	if(level==2)
	{

		if(bonus.flag==1)
		{

				if(ghost2.x_pos<bonus.x_pos)
				{
					ghost2.x_pos += (GHOST_SPEED2/60);
				}
				else if(ghost2.x_pos>bonus.x_pos)
				{
					ghost2.x_pos -=  (GHOST_SPEED2/60);

				}

				if(ghost2.y_pos<bonus.y_pos)
				{

					ghost2.y_pos += (GHOST_SPEED2/60);

				}
				else if(ghost2.y_pos>bonus.y_pos)
				{

					ghost2.y_pos -= (GHOST_SPEED2/60);

				}


		}

		else
		{


				if(ghost2.x_pos<target.x_pos)
				{
					ghost2.x_pos += (GHOST_SPEED2/60);
				}
				else if(ghost2.x_pos>target.x_pos)
				{
					ghost2.x_pos -=  (GHOST_SPEED2/60);

				}

				if(ghost2.y_pos<target.y_pos)
				{

					ghost2.y_pos += (GHOST_SPEED2/60);

				}
				else if(ghost2.y_pos>target.y_pos)
				{

					ghost2.y_pos -= (GHOST_SPEED2/60);

				}






		}
		
	/*
	if(level==2)
	{

		if(bonus.flag==1)
		{
			if( ! ( (bonus.dest.x+bonus.dest.w>=ghost2.dest.x  &&  bonus.dest.x+bonus.dest.w<=ghost2.dest.x+ghost2.dest.w  ) || (bonus.dest.x>=ghost2.dest.x && bonus.dest.x<=ghost2.dest.x+ghost2.dest.w )))
			{  

				if(ghost2.x_pos<bonus.dest.x)
				{
					ghost2.x_pos += (GHOST_SPEED/60);
				}
				else if(ghost2.x_pos>bonus.dest.x)
				{
					ghost2.x_pos -=  (GHOST_SPEED/60);

				}
			}

			if(!( (bonus.dest.y>=ghost2.dest.y  &&  bonus.dest.y<=ghost2.dest.y+ ghost2.dest.h)    ||    (bonus.dest.y+bonus.dest.h>=ghost2.dest.y  &&  bonus.dest.y+bonus.dest.h<=ghost2.dest.y+ ghost2.dest.h) ))
			{

				if(ghost2.y_pos<bonus.dest.y)
				{

					ghost2.y_pos += (GHOST_SPEED/60);

				}
				else if(ghost2.y_pos>bonus.dest.y)
				{

					ghost2.y_pos -= (GHOST_SPEED/60);

				}


			}




		}

		else
		{
			if( ! ( (target.dest.x+target.dest.w>=ghost2.dest.x  &&  target.dest.x+target.dest.w<=ghost2.dest.x+ghost2.dest.w  ) || (target.dest.x>=ghost2.dest.x && target.dest.x<=ghost2.dest.x+ghost2.dest.w )))
			{  

				if(ghost2.x_pos<target.dest.x)
				{
					ghost2.x_pos += (GHOST_SPEED/60);
				}
				else if(ghost2.x_pos>target.dest.x)
				{
					ghost2.x_pos -=  (GHOST_SPEED/60);

				}
			}

			if(!( (target.dest.y>=ghost2.dest.y  &&  target.dest.y<=ghost2.dest.y+ ghost2.dest.h)    ||    (target.dest.y+target.dest.h>=ghost2.dest.y  &&  target.dest.y+target.dest.h<=ghost2.dest.y+ ghost2.dest.h) ))
			{

				if(ghost2.y_pos<target.dest.y)
				{

					ghost2.y_pos += (GHOST_SPEED/60);

				}
				else if(ghost2.y_pos>target.dest.y)
				{

					ghost2.y_pos -= (GHOST_SPEED/60);

				}


			}









		}

		*/




	}



}

#endif