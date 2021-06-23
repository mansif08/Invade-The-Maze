#ifndef setObject_H
#define setObject_H


#include "object.h"
#include "invademaze.h"//intro of the game
#include "loading.h"//load all images
#include "instruction.h"//setting the instruction screen

    #include "hero.h"//setting the hero
    #include "background.h"//setting the background
    #include "wall.h"//setting the wall
    #include "pause.h"//setting the pausescreen
    #include "resume.h"//setting the resume screen
    #include "playagain.h"//setting playagain screen
    #include "quit.h"//setting the quit button
    #include "ghost.h"//setting the ghost
    #include "ghost2.h"//setting the ghost2
    #include "gameover.h"//setting the gameover screen
    #include "target.h"//setting the target
    #include "overbackground.h"//setting the background screen after gameover
    #include "digit.h"//setting the digits
    #include "maingame.h"//operating maingame
    #include "river.h"//setting the river 
    #include "forest.h"//setting the forest 
    #include "oranget.h"//setting the oranget
    #include "greent.h"//setting the greent
    #include "olivet.h"//setting the olivet
    #include "stone.h"//setting the stone
    #include "treesin.h"//setting the treesin
    #include "score.h"//setting the score
    #include "overscore.h"//setting the overscore
    #include "title.h"//setting the title
    #include "levelcompleted.h"//setting the level complete screen
    #include "heart1.h"//setting heart1
    #include "heart2.h"//setting heart2
    #include "heart3.h"//setting heart3
    #include "bonus.h"//setting bonus
    #include "fileini.h"//initializing score and name of the highscores 
    #include "assignscore.h"//assigning the scores to the structure
    #include "startscreen.h"//setting the startscreen
    #include "sgscore.h"//setting the count of points in the game
    #include "newgame.h"//setting the newgame button
    #include "quitsg.h"//setting the quit button
    #include "sginstruct.h"//setting the instruction button
    #include "credit.h"//setting the credit button
    #include "stand.h"//setting the stand
    #include "goback.h"//setting the goback button
    #include "operatestartscreen.h"//operating the start screen
    #include "mainmenu.h"//setting mainmenu button
    #include "gamecompleted.h"//setting gamecompleted box



    void setObject(object& hero,object& bc,object& wall,object& wall2,object& wall3,object& wall4,object& pause,object& resume,object& playag,object& quit,object& ghost,object& ghost2,object& gameover,
    	object& target,object& overbg,object digit[10],object& forest,object& river,object& oranget,object& greent,object& olivet,object& stone,object& treesin,object& score,object& overscore,
    	object& title,object& levelcompleted,object& heart1,object& heart2,object& heart3,object& bonus,object& startscreen,object& sgscore,object& newgame,
    	object& sgquit,object& credit,object& stand,object& goback,object& sginstruct,object& mainmenu,object& gamecompleted)//set the destination rect and starting x y position of the object 
    {

    	setHero(hero);
    	setBc(bc);
    	setWall(wall);
    	setWall2(wall2);
    	setWall3(wall3);
    	setWall4(wall4);
    	setPause(pause);
    	setResume(resume);
    	setPlayag(playag);
    	setQuit(quit);
    	setGhost(ghost);
    	setGhost2(ghost2);
    	setGameover(gameover);
    	setTarget(target);
    	setOverbg(overbg);

    	for(int i=0;i<10;i=i+1)
    	{
    		setDigit(digit[i]);

    	}

    	setForest(forest);
    	setRiver(river);
    	setOranget(oranget);
    	setGreent(greent);
    	setOlivet(olivet);
    	setStone(stone);
    	setTreesin(treesin);
    	setScore(score);
    	setOverscore(overscore);
    	setTitle(title);
    	setLevelcompleted(levelcompleted);
    	setHeart1( heart1);
    	setHeart2( heart2);
    	setHeart3(heart3);
    	setBonus(bonus);
    	setStartscreen(startscreen);
    	setSgscore(sgscore);
    	setNewgame(newgame);
    	setSGQuit(sgquit);
    	setCredit(credit);
    	setStand(stand);
    	setgoBack(goback);
    	setSGinstruct(sginstruct);
    	setStand(stand);
    	setMainmenu(mainmenu);
        setGamecompleted(gamecompleted);






    }


#endif
