#ifndef SHOWBONUS_H
#define SHOWBONUS_H

#include "object.h"


void showbonus(int& count,object& bonus)
{
      if(count%5==0 && count%10!=0)//bonus will appear on 5 ,15, 25...till 85
      {
            if(count==5 && bonus.vis5==0)
            {
                  bonus.flag=1;
                  bonus.vis5=1;
                  bonus.time=320;

                  bonus.dest.y =(rand()%(WINDOW_HEIGHT-(50+50+70+40)))+50+70;

                  if(bonus.dest.y>=120 &&  bonus.dest.y<=460)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+450+40)))+50;
                  }

                  else if(bonus.dest.y>460 &&  bonus.dest.y<510)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+215+40)))+50;

                  }

                  else if(bonus.dest.y>=510 &&  bonus.dest.y<=550)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+215+40)))+50+90;

                  }

                  else if(bonus.dest.y>550 &&  bonus.dest.y<=640)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+90+40)))+50+90;

                  }

                  else if(bonus.dest.y>640 &&  bonus.dest.y<=840)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+150+40)))+50+150;

                  }

                  else
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+40)))+50;

                  }

                  bonus.px1=bonus.dest.x-40,bonus.px2=bonus.dest.x+40,bonus.py1=bonus.dest.y-40,bonus.py2=bonus.dest.y+40;

                  bonus.x_pos=bonus.dest.x;
                  bonus.y_pos=bonus.dest.y;


            }


            else if(count==15 && bonus.vis15==0)
            {
                  bonus.flag=1;
                  bonus.vis15=1;
                  bonus.time=320;

                  bonus.dest.y =(rand()%(WINDOW_HEIGHT-(50+50+70+40)))+50+70;

                  if(bonus.dest.y>=120 &&  bonus.dest.y<=460)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+450+40)))+50;
                  }

                  else if(bonus.dest.y>460 &&  bonus.dest.y<510)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+215+40)))+50;

                  }

                  else if(bonus.dest.y>=510 &&  bonus.dest.y<=550)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+215+40)))+50+90;

                  }

                  else if(bonus.dest.y>550 &&  bonus.dest.y<=640)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+90+40)))+50+90;

                  }

                  else if(bonus.dest.y>640 &&  bonus.dest.y<=840)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+150+40)))+50+150;

                  }

                  else
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+40)))+50;

                  }

                  bonus.px1=bonus.dest.x-40,bonus.px2=bonus.dest.x+40,bonus.py1=bonus.dest.y-40,bonus.py2=bonus.dest.y+40;

                  bonus.x_pos=bonus.dest.x;
                  bonus.y_pos=bonus.dest.y;


            }

            else if(count==25 && bonus.vis25==0)
            {
                  bonus.flag=1;
                  bonus.vis25=1;
                  bonus.time=320;

                  bonus.dest.y =(rand()%(WINDOW_HEIGHT-(50+50+70+40)))+50+70;

                  if(bonus.dest.y>=120 &&  bonus.dest.y<=460)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+450+40)))+50;
                  }

                  else if(bonus.dest.y>460 &&  bonus.dest.y<510)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+215+40)))+50;

                  }

                  else if(bonus.dest.y>=510 &&  bonus.dest.y<=550)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+215+40)))+50+90;

                  }

                  else if(bonus.dest.y>550 &&  bonus.dest.y<=640)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+90+40)))+50+90;

                  }

                  else if(bonus.dest.y>640 &&  bonus.dest.y<=840)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+150+40)))+50+150;

                  }

                  else
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+40)))+50;

                  }

                  bonus.px1=bonus.dest.x-40,bonus.px2=bonus.dest.x+40,bonus.py1=bonus.dest.y-40,bonus.py2=bonus.dest.y+40;

                  bonus.x_pos=bonus.dest.x;
                  bonus.y_pos=bonus.dest.y;


            }

            else if(count==35 && bonus.vis35==0)
            {
                  bonus.flag=1;
                  bonus.vis35=1;
                  bonus.time=320;

                  bonus.dest.y =(rand()%(WINDOW_HEIGHT-(50+50+70+40)))+50+70;

                  if(bonus.dest.y>=120 &&  bonus.dest.y<=460)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+450+40)))+50;
                  }

                  else if(bonus.dest.y>460 &&  bonus.dest.y<510)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+215+40)))+50;

                  }

                  else if(bonus.dest.y>=510 &&  bonus.dest.y<=550)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+215+40)))+50+90;

                  }

                  else if(bonus.dest.y>550 &&  bonus.dest.y<=640)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+90+40)))+50+90;

                  }

                  else if(bonus.dest.y>640 &&  bonus.dest.y<=840)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+150+40)))+50+150;

                  }

                  else
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+40)))+50;

                  }

                  bonus.px1=bonus.dest.x-40,bonus.px2=bonus.dest.x+40,bonus.py1=bonus.dest.y-40,bonus.py2=bonus.dest.y+40;

                  bonus.x_pos=bonus.dest.x;
                  bonus.y_pos=bonus.dest.y;


            }

            else if(count==45 && bonus.vis45==0)
            {
                  bonus.flag=1;
                  bonus.vis45=1;
                  bonus.time=320;

                  bonus.dest.y =(rand()%(WINDOW_HEIGHT-(50+50+70+40)))+50+70;

                  if(bonus.dest.y>=120 &&  bonus.dest.y<=460)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+450+40)))+50;
                  }

                  else if(bonus.dest.y>460 &&  bonus.dest.y<510)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+215+40)))+50;

                  }

                  else if(bonus.dest.y>=510 &&  bonus.dest.y<=550)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+215+40)))+50+90;

                  }

                  else if(bonus.dest.y>550 &&  bonus.dest.y<=640)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+90+40)))+50+90;

                  }

                  else if(bonus.dest.y>640 &&  bonus.dest.y<=840)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+150+40)))+50+150;

                  }

                  else
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+40)))+50;

                  }

                  bonus.px1=bonus.dest.x-40,bonus.px2=bonus.dest.x+40,bonus.py1=bonus.dest.y-40,bonus.py2=bonus.dest.y+40;

                  bonus.x_pos=bonus.dest.x;
                  bonus.y_pos=bonus.dest.y;


            }

            else if(count==55 && bonus.vis55==0)
            {
                  bonus.flag=1;
                  bonus.vis55=1;
                  bonus.time=320;

                  bonus.dest.y =(rand()%(WINDOW_HEIGHT-(50+50+70+40)))+50+70;

                  if(bonus.dest.y>=120 &&  bonus.dest.y<=460)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+450+40)))+50;
                  }

                  else if(bonus.dest.y>460 &&  bonus.dest.y<510)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+215+40)))+50;

                  }

                  else if(bonus.dest.y>=510 &&  bonus.dest.y<=550)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+215+40)))+50+90;

                  }

                  else if(bonus.dest.y>550 &&  bonus.dest.y<=640)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+90+40)))+50+90;

                  }

                  else if(bonus.dest.y>640 &&  bonus.dest.y<=840)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+150+40)))+50+150;

                  }

                  else
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+40)))+50;

                  }

                  bonus.px1=bonus.dest.x-40,bonus.px2=bonus.dest.x+40,bonus.py1=bonus.dest.y-40,bonus.py2=bonus.dest.y+40;

                  bonus.x_pos=bonus.dest.x;
                  bonus.y_pos=bonus.dest.y;


            }

            else if(count==65 && bonus.vis65==0)
            {
                  bonus.flag=1;
                  bonus.vis65=1;
                  bonus.time=320;

                  bonus.dest.y =(rand()%(WINDOW_HEIGHT-(50+50+70+40)))+50+70;

                  if(bonus.dest.y>=120 &&  bonus.dest.y<=460)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+450+40)))+50;
                  }

                  else if(bonus.dest.y>460 &&  bonus.dest.y<510)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+215+40)))+50;

                  }

                  else if(bonus.dest.y>=510 &&  bonus.dest.y<=550)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+215+40)))+50+90;

                  }

                  else if(bonus.dest.y>550 &&  bonus.dest.y<=640)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+90+40)))+50+90;

                  }

                  else if(bonus.dest.y>640 &&  bonus.dest.y<=840)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+150+40)))+50+150;

                  }

                  else
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+40)))+50;

                  }

                  bonus.px1=bonus.dest.x-40,bonus.px2=bonus.dest.x+40,bonus.py1=bonus.dest.y-40,bonus.py2=bonus.dest.y+40;

                  bonus.x_pos=bonus.dest.x;
                  bonus.y_pos=bonus.dest.y;


            }

            else if(count==75 && bonus.vis75==0)
            {
                  bonus.flag=1;
                  bonus.vis75=1;
                  bonus.time=320;

                  bonus.dest.y =(rand()%(WINDOW_HEIGHT-(50+50+70+40)))+50+70;

                  if(bonus.dest.y>=120 &&  bonus.dest.y<=460)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+450+40)))+50;
                  }

                  else if(bonus.dest.y>460 &&  bonus.dest.y<510)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+215+40)))+50;

                  }

                  else if(bonus.dest.y>=510 &&  bonus.dest.y<=550)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+215+40)))+50+90;

                  }

                  else if(bonus.dest.y>550 &&  bonus.dest.y<=640)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+90+40)))+50+90;

                  }

                  else if(bonus.dest.y>640 &&  bonus.dest.y<=840)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+150+40)))+50+150;

                  }

                  else
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+40)))+50;

                  }

                  bonus.px1=bonus.dest.x-40,bonus.px2=bonus.dest.x+40,bonus.py1=bonus.dest.y-40,bonus.py2=bonus.dest.y+40;

                  bonus.x_pos=bonus.dest.x;
                  bonus.y_pos=bonus.dest.y;


            }

            else if(count==85 && bonus.vis85==0)
            {
                  bonus.flag=1;
                  bonus.vis85=1;
                  bonus.time=320;

                  bonus.dest.y =(rand()%(WINDOW_HEIGHT-(50+50+70+40)))+50+70;

                  if(bonus.dest.y>=120 &&  bonus.dest.y<=460)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+450+40)))+50;
                  }

                  else if(bonus.dest.y>460 &&  bonus.dest.y<510)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+215+40)))+50;

                  }

                  else if(bonus.dest.y>=510 &&  bonus.dest.y<=550)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+215+40)))+50+90;

                  }

                  else if(bonus.dest.y>550 &&  bonus.dest.y<=640)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+90+90+40)))+50+90;

                  }

                  else if(bonus.dest.y>640 &&  bonus.dest.y<=840)
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+150+40)))+50+150;

                  }

                  else
                  {
                        bonus.dest.x =(rand()%(WINDOW_HEIGHT-(50+50+40)))+50;

                  }

                  bonus.px1=bonus.dest.x-40,bonus.px2=bonus.dest.x+40,bonus.py1=bonus.dest.y-40,bonus.py2=bonus.dest.y+40;

                  bonus.x_pos=bonus.dest.x;
                  bonus.y_pos=bonus.dest.y;


            }



      }


}
#endif