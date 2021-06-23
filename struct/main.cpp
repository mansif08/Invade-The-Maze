    #include <iostream>
    using namespace std;
    #include <stdlib.h>
    #include<time.h>
    #include <stdio.h>


    //all header files divided from the main file
    
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_timer.h>
    #include <SDL2/SDL_mixer.h>
    #include<SDL2/SDL_ttf.h>


    #include "object.h"//all preprocessors and structures  defined here
    #include "loadMedia.h"//load all images
    #include "setObject.h"//set all objects


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
    
     
    //Globally used font
    TTF_Font *gFont = NULL;


    bool init();
    SDL_Texture* loadFromFile(SDL_Renderer* grend,std::string path);
    bool loadMedia();
    void close();

    
    highscore hscore[5];

    

    SDL_Window* win=NULL;
    SDL_Renderer* grend=NULL;

      //declating all the objects
    object inmaze;
    object instruct;
    object hero;
    object bc;
    object wall;
    object wall2;
    object wall3;
    object wall4;
    object pause;
    object playag;
    object quit;
    object ghost;
    object ghost2;
    object gameover;
    object target;
    object overbg;
    object digit[10];
    object resume;
    object forest;
    object river;
    object oranget;
    object greent;
    object olivet;
    object stone;
    object treesin;
    object score;
    object overscore;
    object title;
    object levelcompleted;
    object heart1;
    object heart2;
    object heart3;
    object bonus;
    object startscreen;
    object sgscore;
    object newgame;
    object sgquit;
    object credit;
    object sginstruct;
    object goback;
    object entername;
    object stand;
    object mainmenu;
    object gamecompleted;



    
    bool init()//initializing primary things
    {
        fileini();

        assignscore(hscore);
        

        bool success=true;

        if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO)!=0)
        {
            printf("%s\n",SDL_GetError());
            success=false;
        }

        else
        {
            //SDL_SetVideoMode (320, 200, 8, 0);
            if(!(IMG_Init(IMG_INIT_PNG)))
            {
                printf("%s\n",SDL_GetError());
                success=false;
            }

            else
            {
               win= SDL_CreateWindow("invade the maze",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,0);

               if(!win)
               {
                  printf("%s",SDL_GetError());
                  success=false;
               }

               else
               {
                    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
                    printf("Error in bgmusic: %s\n",Mix_GetError());

                    Uint32 render_flags= SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
                    grend=SDL_CreateRenderer(win,-1,render_flags);

                    if(!grend)
                    {
                        printf("%s\n",SDL_GetError());
                        success=false;

                    }

                    if( TTF_Init() == -1 )
                    {
                        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                        success = false;
                    }
                    else
                    {
                        gFont = TTF_OpenFont( "Raleway-Black.ttf", 100 );

                        if( gFont == NULL )
                         {
                           return false;
            
                          }

                    }



               }



            }


        }

        return success;

    }

    


    void close()
    {
        SDL_Delay(200);
         //Free loaded images
        free(inmaze.tex);
        free(instruct.tex);
        free(hero.tex);
        free(bc.tex);
        free(wall.tex);
        free(wall2.tex);
        free(wall3.tex);
        free(wall4.tex);
        free(pause.tex);
        free(playag.tex);
        free(quit.tex);
        free(ghost.tex);
        free(ghost2.tex);
        free(gameover.tex);
        free(target.tex);
        free(overbg.tex);
        free(digit[0].tex);
        free(digit[1].tex);
        free(digit[2].tex);
        free(digit[3].tex);
        free(digit[4].tex);
        free(digit[5].tex);
        free(digit[6].tex);
        free(digit[7].tex);
        free(digit[8].tex);
        free(digit[9].tex);
        free(resume.tex);
        free(forest.tex);
        free(river.tex);
        free(oranget.tex);
        free(greent.tex);
        free(olivet.tex);
        free(stone.tex);
        free(treesin.tex);
        free(score.tex);
        free(overscore.tex);
        free(title.tex);
        free(levelcompleted.tex);
        free(heart1.tex);
        free(heart2.tex);
        free(heart3.tex);
        free(bonus.tex);
        free(startscreen.tex);
        free(sgscore.tex);
        free(newgame.tex);
        free(sgquit.tex);
        free(credit.tex);
        free(stand.tex);
        free(goback.tex);
        free(sginstruct.tex);
        free(entername.tex);
        free(stand.tex);
        free(mainmenu.tex);
        free(gamecompleted.tex);


        TTF_CloseFont( gFont );
        gFont = NULL;
        //Destroy window    
        SDL_DestroyRenderer( grend );
        SDL_DestroyWindow( win );
        win = NULL;
        grend = NULL;
        //Quit SDL subsystems
        IMG_Quit();
        SDL_Quit();
        TTF_Quit();
    }
    

    int main(int argc, char *argv[])
    {
        if(!(init()))
        {
            printf("failed to initialize\n");

        }

        else
        {

            if(!loadMedia(grend,inmaze,instruct,hero,bc,wall,wall2,wall3,wall4,pause,resume,playag,quit,ghost,ghost2,gameover,target,overbg,digit,forest,river,oranget,greent,olivet
    ,stone ,treesin,score,overscore,title,levelcompleted,heart1,heart2,heart3,bonus,startscreen,sgscore,newgame,sgquit,credit,goback,sginstruct,entername,stand,mainmenu,gamecompleted))
            {
                printf( "Failed to load media!\n" );
            }

            else
            {

                setObject(hero,bc,wall,wall2,wall3,wall4,pause,resume,playag,quit,ghost,ghost2,gameover,
        target,overbg,digit,forest,river,oranget,greent,olivet,stone,treesin,score,overscore,title,levelcompleted,heart1,heart2,heart3,bonus,startscreen,sgscore,newgame,
        sgquit,credit,stand,goback,sginstruct,mainmenu,gamecompleted);

                int close=0;

                invademaze(grend,inmaze,close);


                if(close==0)
                operateStartscreen(grend,startscreen,newgame,sgquit,sgscore,credit,sginstruct,stand,goback, hscore, gFont, hero, bc, wall, wall2, wall3, wall4, pause, resume, playag, quit, ghost, ghost2, gameover, target, overbg,digit, forest, river, oranget, greent, olivet, stone, treesin, score,overscore,title,levelcompleted,heart1,heart2, heart3, bonus,entername,mainmenu,gamecompleted);


     
            }             

        }
        
        close();
        return 0;
    }
