#ifndef GHOST_H
#define GHOST_H

#include "object.h"

void setGhost(object& ghost)
{

       ghost.dest.w = 65;
       ghost.dest.h = 70;
       ghost.dest.x = 500;
       ghost.dest.y = 0;
       ghost.x_pos=500;
       ghost.y_pos=0;
       
}
#endif