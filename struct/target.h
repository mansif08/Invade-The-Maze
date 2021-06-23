#ifndef TARGET_H
#define TARGET_H

#include "object.h"

void setTarget(object& target)
{
	  srand(time(0));
	  target.dest.w = 40;
      target.dest.h = 40;
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
#endif