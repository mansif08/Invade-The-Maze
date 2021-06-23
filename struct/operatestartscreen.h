#ifndef OPERATESTARTSCREEN_H
#define OPERATESTARTSCREEN_H

#include "object.h"
#include "preparestartscreen.h"
#include "showstartscreen.h"
#include "showhighscore.h"
#include "startscreencheck.h"
#include "showcredit.h"
#include "showinstruct.h"
#include "givename.h"


void operateStartscreen(SDL_Renderer* grend,object& startscreen,object& newgame,object& sgquit,object& sgscore,object& credit,object& sginstruct,object& stand,object& goback,highscore hscore[5],TTF_Font *gFont,object& hero,object& bc,object& wall,object& wall2,object& wall3,object& wall4,object& pause,object& resume,object& playag,object& quit,object& ghost,object& ghost2,object& gameover,object& target,object& overbg,object digit[10],object& forest,object& river,object& oranget,object& greent,object& olivet,object& stone,object& treesin,object& score,object& overscore,object& title,object& levelcompleted,object& heart1,object& heart2,object& heart3,object& bonus,object& entername,object& mainmenu,object& gamecompleted)
{
       int playgame=0;
       int quit2=0;
       int watchscore=0;
       int watchcredit=0;
       int watchinstruct=0;

       int show=1;
       


       SDL_Event event;


       while(!quit2)
       {
       	  


              //checking if user is pressed any button in startscreen

       	   startscreencheck(playgame,quit2,watchscore,watchcredit,watchinstruct,newgame,sgquit, sgscore,credit,goback,sginstruct);

       	   if(playgame==1)
       	   {
                  //take name and start game
       	   	 givename(grend,entername,gFont, playgame,quit2, hscore,hero,bc,wall, wall2,wall3,wall4,pause,resume,playag,quit,ghost,ghost2,gameover,target,overbg,digit,forest,river,oranget,greent,olivet,stone,treesin,score,overscore,title,levelcompleted,heart1,heart2,heart3,bonus,goback,mainmenu,gamecompleted);
                   show=1;

       	   	 

       	   }


       	   else if(watchscore==1)
               {
                  //show highscore chart

       		 showhighscore(grend,goback,quit2,watchscore,hscore,gFont);
                   show=1;

       	   }

       	   else if(watchcredit==1)
       	   {
                  //show credit screen
       	   	 showcredit(grend,goback,quit2,watchcredit);
                   show=1;


       	   }
      	   else if(watchinstruct==1)
       	   {
                  //show instruction screen

       	   	 showinstruct(grend,goback,quit2,watchinstruct);
                   show=1;


       	   }
       	   
       	   else if(show==1)
       	   {

       		  preparestartscreen(grend,startscreen,newgame,sgquit,sgscore,credit,stand,goback,sginstruct);
       		  showstartscreen(grend);
                    show=0;
       	   }

       }
        


}

#endif