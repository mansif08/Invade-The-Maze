#ifndef GHOST2_H
#define GHOST2_H

#include "object.h"

void setGhost2(object& ghost2)
{

       ghost2.dest.w = 65;
       ghost2.dest.h = 70;
       ghost2.dest.x = WINDOW_WIDTH-65;
       ghost2.dest.y = 550;
       ghost2.x_pos=WINDOW_WIDTH-65;
       ghost2.y_pos=550;
       
}
#endif