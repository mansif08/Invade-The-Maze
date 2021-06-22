#ifndef MAINMENU_H
#define MAINMENU_H

#include "object.h"

void setMainmenu(object& mainmenu)
{
	mainmenu.dest.w=200;
	mainmenu.dest.h=50;
	mainmenu.dest.x=(WINDOW_WIDTH/2)-100;
	mainmenu.dest.y=28;

}
#endif