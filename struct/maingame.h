#ifndef MAINGAME_H
#define MAINGAME_H

#include "object.h"
#include "gameControl.h"
#include "points.h"
#include "heroposition.h"
#include "ghostposition.h"
#include "collision.h"
#include "showcount.h"
#include "prepare.h"
#include "show.h"
#include "prepareover.h"
#include "showcountover.h"
#include "mouseeventover.h"
#include "preparepaused.h"
#include "mouseeventpaused.h"
#include "checklevel.h"
#include "showbonus.h"
#include "bonustime.h"
#include "checkhighscore.h"
#include "checkgoback.h"





void maingame(char name[],int& playgame,int& quit2,highscore hscore[],SDL_Renderer* grend,object& hero,object& bc,object& wall,object& wall2,object& wall3,object& wall4,object& pause,object& resume,object& playag,object& quit,object& ghost,object& ghost2,object& gameover,object& target,object& overbg,object digit[10],object& forest,object& river,object& oranget,object& greent,object& olivet,object& stone,object& treesin,object& score,object& overscore,object& title,object& levelcompleted,object& heart1,object& heart2,object& heart3,object& bonus,object& goback,object& mainmenu,object& gamecompleted)
{


    playgame=1;
	int gameovr=0;
    int ovr=0;
    int close =0;
    int paused = 0;
    int count=0,count2,d,c;
    int level=1;
    int heartcount=3;// user have 3 lifes


    int verify=0;
    int verifyname=0;


    while(!close)
    {
     
        

        //control the hero
    	gameControl(hero,paused,close,quit2);



    	if(ovr==1 || playgame==0)
        {
            close=1;
            break;
        }

        if(paused==0 && gameovr==0 && heartcount>0)
        {
            verify=1;
        	points(hero,ghost2,count,target,bonus,level);//verify achieving points and bonus. Increase the count. 
            checklevel(grend,hero,ghost,ghost2,count,level,levelcompleted);//checking the level
            showbonus(count,bonus);//checking if the bonus will appear
            bonustime(bonus);//checking the bonus time

        	if(count==100)
        	{
        		gameovr=1;
        		
        	}

        	heroposition(hero);//setting up hero position
        	ghostposition(hero,ghost,ghost2,target,bonus,level);//setting up ghost position
        	prepare(grend,bc,hero,wall,wall2,wall3,wall4,ghost,ghost2,target,forest,river,oranget,greent,olivet,stone,treesin,score,title,heart1,heart2,heart3,heartcount,bonus,level);
        	showcount(count,grend,digit);//showing the count
        	collision(gameovr,hero,ghost,ghost2,forest,river,oranget,greent,olivet,stone,treesin,heart1,heart2,heart3,heartcount);//determining collision
        	show(grend);

        }

        else if(gameovr==1 || heartcount==0)
        {
        	prepareover(grend,overbg,playag,quit,overscore,mainmenu,gamecompleted);
        	showcountover(count,grend,digit,gameover,gamecompleted);//showing count on the gameover screeen 
        	show(grend);
        	mouseeventover(hero,ghost,ghost2,target,playag,quit,gameovr,count,ovr,level,heartcount,bonus,verifyname,quit2);//interaction with mouse when gameover
            checkgoback4(mainmenu,playgame,hero,ghost,ghost2,target,playag,quit,gameovr,count,ovr,level,heartcount,bonus,verifyname,quit2);//checking if the user wants to go to main menu when game over

            if(verify==1)//checking if we checked it previously
            {
               checkhighscore(name,count,hscore);//checking if its one of the highest score
               verify=0;
            }

        }

        else if(paused==1)
        {
        	preparepaused(grend,overbg,pause,resume,playag,quit,mainmenu);
        	show(grend);
        	mouseeventpaused(playag,quit,paused,ovr,quit2);//interaction with mouse when paused 
            checkgoback4(mainmenu,playgame,hero,ghost,ghost2,target,playag,quit,gameovr,count,ovr,level,heartcount,bonus,verifyname,quit2);//checking if the user wants to go to main menu when gamepaused


        }
               

    }



    if(quit2==1)
    playgame=0;
    

    




}
#endif