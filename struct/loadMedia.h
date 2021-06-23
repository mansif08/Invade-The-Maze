#ifndef loadMedia_H
#define loadMedia_H
#include "loading.h"//load all images


#include "object.h"



    bool loadMedia(SDL_Renderer* grend,object& inmaze,object& instruct,object&  hero,object& bc,object& wall,object& wall2,object& wall3,object& wall4,object& pause,object& resume,object& playag,object& quit,object& ghost,object& ghost2,
    	object& gameover,object& target,object& overbg,object digit[10],object& forest,object& river,object& oranget,object& greent,object& olivet,object& stone ,object& treesin,object& score,
    	object& overscore,object& title,object& levelcompleted,object& heart1,object& heart2,object& heart3,object& bonus,object& startscreen,object& sgscore,object& newgame,object& sgquit,
    	object& credit,object& goback,object& sginstruct,object& entername,object& stand,object& mainmenu,object& gamecompleted)//load the textures with images
    {
        
        
        inmaze.tex=loadFromFile(grend,"../Images/invademaze.png");
        if(inmaze.tex==NULL)
        {
            return false;
        }

        instruct.tex=loadFromFile(grend,"../Images/INSTRUCTIONS.png");
        if(instruct.tex==NULL)
        {
            return false;
        }

        hero.tex=loadFromFile(grend,"../Images/charhum2.png");
        if(hero.tex==NULL)
        {
            return false;
        }

        bc.tex=loadFromFile(grend,"../Images/finalbg2.png");

        if(bc.tex==NULL)
        {
            return false;
        }

        wall.tex=loadFromFile(grend,"../Images/BT.png");
        if(wall.tex==NULL)
        {
            return false;
        }

        wall2.tex=loadFromFile(grend,"../Images/BL.png");
        if(wall2.tex==NULL)
        {
            return false;
        }

        wall3.tex=loadFromFile(grend,"../Images/BW.png");
        if(wall3.tex==NULL)
        {
            return false;
        }

        wall4.tex=loadFromFile(grend,"../Images/BR.png");
        if(wall4.tex==NULL)
        {
            return false;
        }

        pause.tex=loadFromFile(grend,"../Images/gamepausedfin.png");
        if(pause.tex==NULL)
        {
            return false;
        }


        resume.tex=loadFromFile(grend,"../Images/finresume.png");
        if(resume.tex==NULL)
        {
            return false;
        }


        playag.tex=loadFromFile(grend,"../Images/finplayag.png");
        if(playag.tex==NULL)
        {
            return false;
        }

        quit.tex=loadFromFile(grend,"../Images/finquit.png");
        if(quit.tex==NULL)
        {
            return false;
        }

        ghost.tex=loadFromFile(grend,"../Images/finghost copy.png");
        if(ghost.tex==NULL)
        {
            return false;
        }

        ghost2.tex=loadFromFile(grend,"../Images/finghost.png");
        if(ghost2.tex==NULL)
        {
            return false;
        }

        gameover.tex=loadFromFile(grend,"../Images/gameoverfin.png");
        if(gameover.tex==NULL)
        {
            return false;
        }

        target.tex=loadFromFile(grend,"../Images/fintarget.png");
        if(target.tex==NULL)
        {
            return false;
        }
        overbg.tex=loadFromFile(grend,"../Images/bg2.png");
        if(overbg.tex==NULL)
        {
            return false;
        }

        digit[0].tex=loadFromFile(grend,"../Images/0.png");
        if(digit[0].tex==NULL)
        {
            return false;
        }

        digit[1].tex=loadFromFile(grend,"../Images/1.png");
        if(digit[1].tex==NULL)
        {
            return false;
        }

        digit[2].tex=loadFromFile(grend,"../Images/2.png");
        if(digit[2].tex==NULL)
        {
            return false;
        }
        digit[3].tex=loadFromFile(grend,"../Images/3.png");
        if(digit[3].tex==NULL)
        {
            return false;
        }

        digit[4].tex=loadFromFile(grend,"../Images/4.png");
        if(digit[4].tex==NULL)
        {
            return false;
        }
        digit[5].tex=loadFromFile(grend,"../Images/5.png");
        if(digit[5].tex==NULL)
        {
            return false;
        }
        digit[6].tex=loadFromFile(grend,"../Images/6.png");
        if(digit[6].tex==NULL)
        {
            return false;
        }
        digit[7].tex=loadFromFile(grend,"../Images/7.png");
        if(digit[7].tex==NULL)
        {
            return false;
        }
        digit[8].tex=loadFromFile(grend,"../Images/8.png");
        if(digit[8].tex==NULL)
        {
            return false;
        }
        digit[9].tex=loadFromFile(grend,"../Images/9.png");
        if(digit[9].tex==NULL)
        {
            return false;
        }
        forest.tex=loadFromFile(grend,"../Images/forest.png");
        if(forest.tex==NULL)
        {
            return false;
        }
        river.tex=loadFromFile(grend,"../Images/river copy.png");
        if(river.tex==NULL)
        {
            return false;
        }
        oranget.tex=loadFromFile(grend,"../Images/oranget.png");
        if(oranget.tex==NULL)
        {
            return false;
        }
        greent.tex=loadFromFile(grend,"../Images/greent.png");
        if(greent.tex==NULL)
        {
            return false;
        }
        olivet.tex=loadFromFile(grend,"../Images/olivet.png");
        if(olivet.tex==NULL)
        {
            return false;
        }

        stone.tex=loadFromFile(grend,"../Images/stone.png");
        if(stone.tex==NULL)
        {
            return false;
        }
        treesin.tex=loadFromFile(grend,"../Images/treesin.png");
        if(treesin.tex==NULL)
        {
            return false;
        }

        score.tex=loadFromFile(grend,"../Images/S1.png");
        if(score.tex==NULL)
        {
            return false;
        }
        overscore.tex=loadFromFile(grend,"../Images/S1.png");
        if(overscore.tex==NULL)
        {
            return false;
        }


        title.tex=loadFromFile(grend,"../Images/in2.png");
        if(title.tex==NULL)
        {
            return false;
        }

        levelcompleted.tex=loadFromFile(grend,"../Images/lecompleted.png");

        if(levelcompleted.tex==NULL)
        {
            return false;
        }

        heart1.tex=loadFromFile(grend,"../Images/heart2.png");
        if(heart1.tex==NULL)
        {
            return false;
        }

        heart2.tex=loadFromFile(grend,"../Images/heart2.png");
        if(heart2.tex==NULL)
        {
            return false;
        }

        heart3.tex=loadFromFile(grend,"../Images/heart2.png");
        if(heart3.tex==NULL)
        {
            return false;
        }

        bonus.tex=loadFromFile(grend,"../Images/bonus3.png");
        if(bonus.tex==NULL)
        {
            return false;
        }

        startscreen.tex=loadFromFile(grend,"../Images/sgbg.png");
        if(startscreen.tex==NULL)
        {
            return false;
        }
        sgscore.tex=loadFromFile(grend,"../Images/sgscore.png");
        if(sgscore.tex==NULL)
        {
            return false;
        }

        newgame.tex=loadFromFile(grend,"../Images/newgame.png");
        if(newgame.tex==NULL)
        {
            return false;
        }

        sgquit.tex=loadFromFile(grend,"../Images/quitsg.png");
        if(quit.tex==NULL)
        {
            return false;
        }
        credit.tex=loadFromFile(grend,"../Images/credit.png");
        if(credit.tex==NULL)
        {
            return false;
        }


        goback.tex=loadFromFile(grend,"../Images/goback3.png");
        if(goback.tex==NULL)
        {
            return false;
        }
        

        sginstruct.tex=loadFromFile(grend,"../Images/sginstruct.png");
        if(sginstruct.tex==NULL)
        {
            return false;
        }

        entername.tex=loadFromFile(grend,"../Images/finentername.png");
        if(entername.tex==NULL)
        {
            return false;
        }

        stand.tex=loadFromFile(grend,"../Images/finstand.png");
        if(stand.tex==NULL)
        {
            return false;
        }

        mainmenu.tex=loadFromFile(grend,"../Images/mainmenu.png");
        if(mainmenu.tex==NULL)
        {
            return false;
        }

        gamecompleted.tex=loadFromFile(grend,"../Images/gamecompleted.png");
        if(gamecompleted.tex==NULL)
        {
            return false;
        }


      




        return true;

    }
   

#endif