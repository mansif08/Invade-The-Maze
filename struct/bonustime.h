#ifndef BONUSTIME_H
#define BONUSTIME_H

#include "object.h"


void bonustime(object& bonus)
{
	if(bonus.flag==1)
	{
		bonus.time--;
		if(bonus.time==0)
		{
			bonus.flag=0;
		}
	}
 	
}
#endif
