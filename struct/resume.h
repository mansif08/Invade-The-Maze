#ifndef RESUME_H
#define RESUME_H

#include "object.h"

void setResume(object& resume)
{
	resume.dest.w = 600;
    resume.dest.h = 120;
    resume.dest.x = (WINDOW_WIDTH-resume.dest.w)/2;
    resume.dest.y = (WINDOW_HEIGHT-resume.dest.h)/2+150;
            
}
#endif