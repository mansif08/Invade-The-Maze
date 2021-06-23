
#ifndef WALL_H
#define WALL_H

#include "object.h"

void setWall(object& wall)
{

	
    	wall.dest.w = WINDOW_WIDTH;
        wall.dest.h = 50;
        wall.dest.x = 0;
        wall.dest.y = 0;
    

}

void setWall2(object& wall2)
{

    	wall2.dest.w = 50;
        wall2.dest.h = WINDOW_HEIGHT;
        wall2.dest.x = 0;
        wall2.dest.y = 0;



}
void setWall3(object& wall3)
{

	

    	wall3.dest.w = WINDOW_WIDTH;
        wall3.dest.h = 50;
        wall3.dest.x = 0;
        wall3.dest.y = WINDOW_HEIGHT-50;

}

void setWall4(object& wall4)
{

	   wall4.dest.w = 50;
       wall4.dest.h = WINDOW_HEIGHT;
       wall4.dest.x = WINDOW_WIDTH-50;
       wall4.dest.y = 0;
  
}
#endif