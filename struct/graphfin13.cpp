    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_timer.h>
    #include <SDL2/SDL_mixer.h>

    //#include <SDL2/SDL_ttf.h>

    #include <stdlib.h>
    #include<time.h>
    #include <stdio.h>

    #define WINDOW_WIDTH (1280)
    #define WINDOW_HEIGHT (960)
    #define MAZE_WIDTH (1230)
    #define MAZE_HEIGHT (910)

    #define SCROLL_SPEED (850)
    #define RECT_SPEED (5.0)
    #define GHOST_SPEED (65)
    #define GHOST2_SPEED (110)

    #define TARGET_SPEED (400)


    float min(float x, float y){
        if(x<y)
            return x;
        return y;
    }
    float max(float x, float y){
        if(x>y)
            return x;
        return y;
    }



    int main()
    {
     if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO)!=0)

        {
            printf("%s\n",SDL_GetError());
        }

        if(!(IMG_Init(IMG_INIT_PNG)))
        {
            printf("%s\n",SDL_GetError());
        }


        //printf("initialization complete\n");

        SDL_Window* win= SDL_CreateWindow("invade the maze",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,0);

        if(!win)
        {
            printf("%s",SDL_GetError());
            SDL_Quit();
            return 1;
        }
        if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
        printf("Error in bgmusic: %s\n",Mix_GetError());

        Mix_Music* bgmusic=Mix_LoadMUS("bgmusic.mp3");
        if(!Mix_PlayingMusic())
            Mix_PlayMusic(bgmusic,-1);


        Uint32 render_flags= SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC;
        SDL_Renderer* rend=SDL_CreateRenderer(win,-1,render_flags);

        if(!rend)
        {
            printf("%s\n",SDL_GetError());
            SDL_DestroyWindow(win);
            SDL_Quit();
            return 1;

        }

        SDL_Surface* surface=IMG_Load("quitbg.png");

        if(!surface)
        {
            printf("%s\n",SDL_GetError() );
            SDL_DestroyRenderer(rend);
            SDL_DestroyWindow(win);
            SDL_Quit();
            return 1;
        }

        SDL_Texture* tex96=SDL_CreateTextureFromSurface(rend,surface);
        SDL_FreeSurface(surface);

        if(!tex96)
        {
            printf("%s\n",SDL_GetError());
            SDL_DestroyRenderer(rend);
            SDL_DestroyWindow(win);
            SDL_Quit();
            return 1;
        }


        int enter=0,close5=0;

        while(!enter && !close5)
        {

            SDL_Event event;

            while(SDL_PollEvent(&event))
            {

                switch(event.type)
                {
                    case SDL_QUIT:
                    close5=1;
                    break;

                    case SDL_KEYDOWN:
                    switch(event.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_ESCAPE:
                        enter=1;
                        break;

                    }

                }


            }

            SDL_RenderClear(rend);
            SDL_RenderCopy(rend,tex96,NULL,NULL);
            SDL_RenderPresent(rend);
        }


        if(close5==0)
        {            //background music 

             Mix_Music* bgmusic=Mix_LoadMUS("bgmusic.mp3");
            if(!Mix_PlayingMusic())
            Mix_PlayMusic(bgmusic,-1);

            surface = IMG_Load("charhum2.png");
            if (!surface){
                printf("char Surface Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("char Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Rect dest;
            SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

            dest.w = 55;
            dest.h = 55;
            float x_pos=300;//CHANGED THE CHARACTER POSITION AS THERE WILL BE AN OBSTACLE ON THE PREVIOUS POSITION

            float y_pos=300;



             surface = IMG_Load("finalbg2.png");
            if (!surface){
                printf("background Surface Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* bc_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("bc Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect bc_rect;
            bc_rect.w =WINDOW_WIDTH;
            bc_rect.h =WINDOW_HEIGHT;
            bc_rect.x=0;
            bc_rect.y=0;


             surface = IMG_Load("finalbg2.png");
            if (!surface){
                printf("background2 Surface Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* bc2_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("bc2 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect bc2_rect;
            bc2_rect.w =WINDOW_WIDTH;
            bc2_rect.h =WINDOW_HEIGHT;
            bc2_rect.x=0;
            bc2_rect.y=0;
            

            surface = IMG_Load("BT.png");//CHANGED THE WALL IMAGES
            if (!surface){
                printf("wall Surface Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* wall_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("wall Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Rect wall_rect;
            wall_rect.w = WINDOW_WIDTH;
            wall_rect.h = 50;
            wall_rect.x = 0;
            wall_rect.y = 0;

            surface = IMG_Load("BL.png");
            if (!surface){
                printf("wall2 Surface Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Texture* wall2_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("wall2 Texture  %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Rect wall2_rect;
            wall2_rect.w = 50;
            wall2_rect.h = WINDOW_HEIGHT;
            wall2_rect.x = 0;
            wall2_rect.y = 0;

            surface = IMG_Load("BW.png");
            if (!surface){
                printf("wall3 Surface Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Texture* wall3_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("wall3 Texture  %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Rect wall3_rect;
            wall3_rect.w = WINDOW_WIDTH;
            wall3_rect.h = 50;
            wall3_rect.x = 0;
            wall3_rect.y = WINDOW_HEIGHT-50;


            surface = IMG_Load("BR.png");
            if (!surface){
                printf("wall4 Surface Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Texture* wall4_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("wall4 Texture  %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Rect wall4_rect;
            wall4_rect.w = 50;
            wall4_rect.h = WINDOW_HEIGHT;
            wall4_rect.x = WINDOW_WIDTH-50;
            wall4_rect.y = 0;





            surface = IMG_Load("gamepausedfin.png");
            if (!surface){
                printf("Paused Image Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }
            SDL_Texture* paused_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("Paused Texture Error %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect paused_rect;
            paused_rect.w = 600;
            paused_rect.h = 320;
            paused_rect.x = (WINDOW_WIDTH-paused_rect.w)/2;
            paused_rect.y = (WINDOW_HEIGHT-paused_rect.h)/2-180;



            surface = IMG_Load("finplayag.png");
            if (!surface){
                printf("replay Surface Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }
            SDL_Texture* playag_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("Play again Texture Error %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect playag_rect;
            playag_rect.w = 600;
            playag_rect.h = 120;
            playag_rect.x = (WINDOW_WIDTH-playag_rect.w)/2;
            playag_rect.y = (WINDOW_HEIGHT-playag_rect.h)/2+150;


                        //RESUME INSTEAD OF PLAY AGAIN FOR PAUSE SCREEN

                    surface = IMG_Load("finresume.png");
            if (!surface){
                printf("resume Surface Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }
            SDL_Texture* resume_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("resume Texture Error %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect resume_rect;
            resume_rect.w = 600;
            resume_rect.h = 120;
            resume_rect.x = (WINDOW_WIDTH-playag_rect.w)/2;
            resume_rect.y = (WINDOW_HEIGHT-playag_rect.h)/2+150;
            surface = IMG_Load("finquit.png");
            if (!surface){
                printf("quit Surface Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }
            SDL_Texture* quit_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("quit Texture Error %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect quit_rect;
            quit_rect.w = 200;
            quit_rect.h = 70;
            quit_rect.x = WINDOW_WIDTH-170;
            quit_rect.y =0 ;

            


            surface = IMG_Load("finghost.png");
            if (!surface){
                printf("ghost1 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* ghost1_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("ghost1 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect ghost1_rect;

            ghost1_rect.w = 65;
            ghost1_rect.h = 70;
            ghost1_rect.x = 50;
            ghost1_rect.y = 400;
            float ghost1_posx=50;
            float ghost1_posy=400;
            int pdirectionx=1;
            int pdirectiony=1;




            surface = IMG_Load("finghost.png");
            if (!surface){
                printf("ghost2 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* ghost2_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("ghost2 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect ghost2_rect;

            ghost2_rect.w = 60;
            ghost2_rect.h = 70;
            ghost2_rect.x = WINDOW_WIDTH-170;
            ghost2_rect.y = WINDOW_HEIGHT-200;
            float ghost2_posx=WINDOW_WIDTH-170;
            float ghost2_posy=WINDOW_HEIGHT-200;

            int qdirectionx=1;
            int qdirectiony=1;


            surface = IMG_Load("finghost.png");
            if (!surface){
                printf("ghost3 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* ghost3_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("ghost3 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect ghost3_rect;

            ghost3_rect.w = 60;
            ghost3_rect.h = 70;
            ghost3_rect.x = WINDOW_WIDTH-300;
            ghost3_rect.y = 300;
            float ghost3_posx=WINDOW_WIDTH-300;
            float ghost3_posy=300;
            int rdirectionx=1;
            int rdirectiony=1;

     




            surface = IMG_Load("gameoverfin.png");
            if (!surface){
                printf("gameover Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("gameover Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect gameover_rect;

            gameover_rect.w = 500;
            gameover_rect.h = 300;
            gameover_rect.x = (WINDOW_WIDTH-600)/2+50;
            gameover_rect.y = (WINDOW_HEIGHT-320)/2-200;



            srand(time(0));

            surface = IMG_Load("fintarget.png");
            if (!surface){
                printf("target1 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* target1_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("target1 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Rect target1_rect;

            target1_rect.w = 70;
            target1_rect.h = 70;
            target1_rect.x =(rand()%(WINDOW_WIDTH-110))+60;
             target1_rect.y =(rand()%(WINDOW_HEIGHT-110))+60;
                 //FIRST RANDOMLY GENERATED TARGET POSITION CHECK AND PUTTING IT INTO RIGHT PLACE(LEVEL-1)


                      if(target1_rect.y>= 50 && target1_rect.y<=120)
                      {target1_rect.x=WINDOW_WIDTH-305;
                        target1_rect.y=640;}
                     if(target1_rect.y>=120 && target1_rect.y<=640)

                       {    if(target1_rect.x>=305 && target1_rect.x<=WINDOW_WIDTH-305)
                        {
                            target1_rect.x=target1_rect.x;
                            target1_rect.y=target1_rect.y;

                        }
                        else{

                        target1_rect.x=WINDOW_WIDTH-350;
                        target1_rect.y=600;}
                       }
                     if((target1_rect.y>=120 && target1_rect.y<=460) && (target1_rect.x>=WINDOW_WIDTH-540 && target1_rect.x<=WINDOW_WIDTH))
                      {target1_rect.x=WINDOW_WIDTH-325;
                        target1_rect.y=670;}



            int px1=target1_rect.x-55,px2=target1_rect.x+55,py1=target1_rect.y-55,py2=target1_rect.y+55;


              surface = IMG_Load("fintarget.png");
            if (!surface){
                printf("target2 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* target2_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("target2 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Rect target2_rect;

            target2_rect.w = 70;
            target2_rect.h = 70;
            target2_rect.x =(rand()%(WINDOW_WIDTH-110))+60;
             target2_rect.y =(rand()%(WINDOW_HEIGHT-110))+60;
                 //FIRST RANDOMLY GENERATED TARGET POSITION CHECK AND PUTTING IT INTO RIGHT PLACE(LEVEL-2)

              if(target2_rect.y>= 50 && target2_rect.y<=120)
                      {target2_rect.x=WINDOW_WIDTH-305;
                        target2_rect.y=640;}
                     if(target2_rect.y>=120 && target2_rect.y<=640)

                       {    if(target2_rect.x>=305 && target2_rect.x<=WINDOW_WIDTH-305)
                        {
                            target2_rect.x=target2_rect.x;
                            target2_rect.y=target2_rect.y;

                        }
                        else{

                        target2_rect.x=WINDOW_WIDTH-350;
                        target2_rect.y=600;}
                       }
                     if((target2_rect.y>=390 && target2_rect.y<=590) && (target2_rect.x>=300 && target2_rect.x<=530))
                      {target2_rect.x=450;
                        target2_rect.y=WINDOW_HEIGHT-100;}
                     if((target2_rect.y>=WINDOW_HEIGHT-210 && target2_rect.y<=WINDOW_HEIGHT-130) && (target2_rect.x>=170 && target2_rect.x<=260))
                      {target2_rect.x=220;
                        target2_rect.y=130;}
                     if((target2_rect.y>=WINDOW_HEIGHT-420 && target2_rect.y<=WINDOW_HEIGHT-310) && (target2_rect.x>=150 && target2_rect.x<=240))
                      {target2_rect.x=WINDOW_WIDTH-105;
                        target2_rect.y=WINDOW_HEIGHT-100;}



            int wx1=target2_rect.x-55,wx2=target2_rect.x+55,wy1=target2_rect.y-55,wy2=target2_rect.y+55;
            //INVADE THE MAZE NAME ON TOP OF SCREEN 



                    surface = IMG_Load("in2.png");
            if (!surface){
                printf("level1 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* level1_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("level1 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect level1_rect;

            level1_rect.w = 300;
            level1_rect.h = 60;
            level1_rect.x = (WINDOW_WIDTH/2)-150;
            level1_rect.y = 0;




            surface = IMG_Load("S1.png");
            if (!surface){
                printf("score Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* score_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("score Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect score_rect;

            score_rect.w = 400;
            score_rect.h = 100;
            score_rect.x = (WINDOW_WIDTH/2)-200;
            score_rect.y = 800;
            
            


        //GAME OVER BACKGROUND



            surface = IMG_Load("overbg.png");
            if (!surface){
                printf("overbg Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* overbg_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("overbg Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect overbg_rect;

            overbg_rect.w = WINDOW_WIDTH;
            overbg_rect.h = WINDOW_HEIGHT;
            overbg_rect.x = 0;
            overbg_rect.y = 0;

            surface = IMG_Load("overbg.png");
            if (!surface){
                printf("overbg1 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* overbg1_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("overbg1 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect overbg1_rect;

            overbg1_rect.w = WINDOW_WIDTH;
            overbg1_rect.h = WINDOW_HEIGHT;
            overbg1_rect.x = 0;
            overbg1_rect.y = 0;
        //LEVEL COMPLETED IMAGE


            surface = IMG_Load("lecompleted.jpg");
            if (!surface){
                printf("lecompleted Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            surface = IMG_Load("bonus3.png");
            if (!surface){
                printf("bonus Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }
        //BONUS 


            SDL_Texture* bonus_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("bonus Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect bonus_rect;

            bonus_rect.w = 40;
            bonus_rect.h = 40;
            bonus_rect.x =(rand()%(WINDOW_WIDTH-140))+50;
            bonus_rect.y =(rand()%(WINDOW_HEIGHT-140))+50;

                 //FIRST RANDOMLY GENERATED BONUS POSITION CHECK AND PUTTING IT INTO RIGHT PLACE(BOTH LEVEL)

                              if(bonus_rect.y>= 50 && bonus_rect.y<=120)
                      {bonus_rect.x=WINDOW_WIDTH-315;
                      bonus_rect.y=680;}
                     if(bonus_rect.y>=120 && bonus_rect.y<=640)

                       {    if(bonus_rect.x>=305 && bonus_rect.x<=WINDOW_WIDTH-305)
                        {
                            bonus_rect.x=bonus_rect.x;
                            bonus_rect.y=bonus_rect.y;

                        }
                        else{

                        bonus_rect.x=WINDOW_WIDTH-325;
                        bonus_rect.y=595;}
                       }
                     if((bonus_rect.y>=120 && bonus_rect.y<=460) && (bonus_rect.x>=WINDOW_WIDTH-540 && bonus_rect.y<=WINDOW_WIDTH))
                      {bonus_rect.x=WINDOW_WIDTH-325;
                        bonus_rect.y=670;}
                     if((bonus_rect.y>=390 && bonus_rect.y<=590) && (bonus_rect.x>=300 && bonus_rect.x<=530))
                      {bonus_rect.x=450;
                        bonus_rect.y=WINDOW_HEIGHT-100;}
                     if((bonus_rect.y>=WINDOW_HEIGHT-210 && bonus_rect.y<=WINDOW_HEIGHT-130) && (bonus_rect.x>=170 && bonus_rect.x<=260))
                      {bonus_rect.x=220;
                        bonus_rect.y=130;}
                     if((bonus_rect.y>=WINDOW_HEIGHT-420 && bonus_rect.y<=WINDOW_HEIGHT-310) && (bonus_rect.x>=150 && bonus_rect.x<=240))
                      {bonus_rect.x=WINDOW_WIDTH-105;
                        bonus_rect.y=WINDOW_HEIGHT-100;}


            int zx1=bonus_rect.x-40,zx2=bonus_rect.x+40,zy1=bonus_rect.y-40,zy2=bonus_rect.y+40;

        //FOREST ON TOP OF THE SCREEN IS OBSTACLE 1

            surface = IMG_Load("forest.png");
            if (!surface){
                printf("obstacle1 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* obstacle1_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("obstacle1 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect obstacle1_rect;

            obstacle1_rect.w = WINDOW_WIDTH-100;
            obstacle1_rect.h = 70;
            obstacle1_rect.x = 0;
            obstacle1_rect.y = 50;

        //THE RIVER PAST THE FOREST IS OBSTACLE 2


            surface = IMG_Load("river.png");
            if (!surface){
                printf("obstacle2 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* obstacle2_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("obstacle2 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect obstacle2_rect;

            obstacle2_rect.w = 450;
            obstacle2_rect.h = 340;
            obstacle2_rect.x = WINDOW_WIDTH-500;
            obstacle2_rect.y = 120;

            surface = IMG_Load("oranget.png");
            if (!surface){
                printf("obstacle3 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }
        //THE ORANGE TREE PAST THE RIVER  IS OBSTACLE 3


            SDL_Texture* obstacle3_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("obstacle3 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect obstacle3_rect;

            obstacle3_rect.w = 90;
            obstacle3_rect.h = 90;
            obstacle3_rect.x = WINDOW_WIDTH-140;
            obstacle3_rect.y = 460;

             surface = IMG_Load("greent.png");
            if (!surface){
                printf("obstacle3 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* obstacle4_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("obstacle4 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }
    //THE GREEN  TREE BESIDE THE ORANGE TREE IS OBSTACLE 4


            SDL_Rect obstacle4_rect;

            obstacle4_rect.w = 90;
            obstacle4_rect.h = 90;
            obstacle4_rect.x = WINDOW_WIDTH-265;
            obstacle4_rect.y = 460;
      //THE OLIVE TREE UNDER THE ORANGE TREE IS OBSTACLE 5


             surface = IMG_Load("olivet.png");
            if (!surface){
                printf("obstacle5 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* obstacle5_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("obstacle5 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect obstacle5_rect;

            obstacle5_rect.w = 90;
            obstacle5_rect.h = 90;
            obstacle5_rect.x = WINDOW_WIDTH-140;
            obstacle5_rect.y = 550;
                //THE STONE ON THE LEFT OF THE SCREEN IS  OBSTACLE 6


             surface = IMG_Load("stone.png");
            if (!surface){
                printf("obstacle6 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* obstacle6_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("obstacle6 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect obstacle6_rect;

            obstacle6_rect.w = 150;
            obstacle6_rect.h = 150;
            obstacle6_rect.x = 50;
            obstacle6_rect.y =WINDOW_HEIGHT-280;
            //THE TREE ON TOP  OF THE STONE IS  OBSTACLE 7

             surface = IMG_Load("treesin.png");
            if (!surface){
                printf("obstacle7 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* obstacle7_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("obstacle7 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect obstacle7_rect;

            obstacle7_rect.w = 100;
            obstacle7_rect.h = 120;
            obstacle7_rect.x = 50;
            obstacle7_rect.y =WINDOW_HEIGHT-430;
                //THE SMALL RIVER IS  OBSTACLE 8[FOR LEVEL 2 ONLY]


             surface = IMG_Load("river.png");
            if (!surface){
                printf("obstacle7 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* obstacle8_tex = SDL_CreateTextureFromSurface(rend, surface);
                   SDL_FreeSurface(surface);
            if(!tex){
                printf("obstacle7 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect obstacle8_rect;

            obstacle8_rect.w = 230;
            obstacle8_rect.h = 200;
            obstacle8_rect.x = 300;
            obstacle8_rect.y =390;

            //THE SMALL STONE BESIDE THE ACTUAL STONE IS  OBSTACLE 9[FOR LEVEL 2 ONLY]


             surface = IMG_Load("stone.png");
            if (!surface){
                printf("obstacle6 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* obstacle9_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("obstacle9 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect obstacle9_rect;

            obstacle9_rect.w = 90;
            obstacle9_rect.h = 80;
            obstacle9_rect.x = 170;
            obstacle9_rect.y =WINDOW_HEIGHT-210;

            //THE SMALL TREE IS OBSTACLE 10[FOR LEVEL 2 ONLY]

      surface = IMG_Load("treesin.png");
            if (!surface){
                printf("obstacle10 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* obstacle10_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("obstacle10 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect obstacle10_rect;

            obstacle10_rect.w = 90;
            obstacle10_rect.h = 110;
            obstacle10_rect.x = 150;
            obstacle10_rect.y =WINDOW_HEIGHT-420;


        //3 LIFE IMAGES LOAD




             surface = IMG_Load("heart2.png");
            if (!surface){
                printf("heart1 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* heart1_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("heart1 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect heart1_rect;

            heart1_rect.w = 40;
            heart1_rect.h = 50;
            heart1_rect.x = 0;
            heart1_rect.y = 0;


             surface = IMG_Load("heart2.png");
            if (!surface){
                printf("heart2 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* heart2_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("heart2 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect heart2_rect;

            heart2_rect.w = 40;
            heart2_rect.h = 50;
            heart2_rect.x = 50;
            heart2_rect.y = 0;

             surface = IMG_Load("heart2.png");
            if (!surface){
                printf("heart3 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* heart3_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("heart3 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect heart3_rect;

            heart3_rect.w = 40;
            heart3_rect.h = 50;
            heart3_rect.x = 100;
            heart3_rect.y = 0;


             surface = IMG_Load("S1.png");
            if (!surface){
                printf("scoresc Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* scoresc_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("scoresc Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect scoresc_rect;

            scoresc_rect.w = 120;
            scoresc_rect.h = 50;
            scoresc_rect.x = WINDOW_WIDTH-250;
            scoresc_rect.y = 0;


         
                 //LEVEL COMPLETED IMAGE LOAD 

         

            surface = IMG_Load("lecompleted.png");
            if (!surface){
                printf("lecompleted Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* lecompleted_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("lecompleted Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect lecompleted_rect;

            lecompleted_rect.w = WINDOW_WIDTH;
            lecompleted_rect.h = WINDOW_HEIGHT;
            lecompleted_rect.x = 0;
            lecompleted_rect.y = 0;

             SDL_Rect over_rect;

             over_rect.w = 100;
             over_rect.h = 100;
             over_rect.x = 950;
             over_rect.y = 800;

             SDL_Rect over_rect2;

            over_rect2.w = 100;
             over_rect2.h = 100;
             over_rect2.x = 850;
             over_rect2.y = 840;


             SDL_Rect show_rect;

             show_rect.w = 50;
             show_rect.h = 50;
             show_rect.x = WINDOW_WIDTH-50;
             show_rect.y = 0;

            SDL_Rect show_rect2;
             show_rect2.w = 50;
             show_rect2.h = 50;
             show_rect2.x = WINDOW_WIDTH-100;
             show_rect2.y = 0;

      
      int l2flag=1;;

         

       

            SDL_Texture* digit_tex[10];



             surface = IMG_Load("0.png");
            if (!surface){
                printf("0 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            digit_tex[0] = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!digit_tex[0]){
                printf("0 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }





            surface = IMG_Load("1.png");
            if (!surface){
                printf("1 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            digit_tex[1] = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!digit_tex[1]){
                printf("1 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            


            surface = IMG_Load("2.png");
            if (!surface){
                printf("2 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            digit_tex[2] = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!digit_tex[2]){
                printf("2 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

             surface = IMG_Load("3.png");
            if (!surface){
                printf("3 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            digit_tex[3] = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!digit_tex[3]){
                printf("3 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }



                    surface = IMG_Load("4.png");
            if (!surface){
                printf("4 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            digit_tex[4] = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!digit_tex[4]){
                printf("4 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

       
             surface = IMG_Load("5.png");
            if (!surface){
                printf("5 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            digit_tex[5] = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!digit_tex[5]){
                printf("5 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }



            surface = IMG_Load("6.png");
            if (!surface){
                printf("6 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            digit_tex[6] = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!digit_tex[6]){
                printf("6 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


             surface = IMG_Load("7.png");
            if (!surface){
                printf("7 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            digit_tex[7] = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!digit_tex[7]){
                printf("7 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            surface = IMG_Load("8.png");
            if (!surface){
                printf("8 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            digit_tex[8] = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!digit_tex[8]){
                printf("8 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

             surface = IMG_Load("9.png");
            if (!surface){
                printf("9 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            digit_tex[9] = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!digit_tex[9]){
                printf("9 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }






            int gameover=0;
            int cont=0;
            int over=0;
            int close = 0;
            int pause = 0;
            int count=0,count2,d,c;
            int b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0,b10=0,b11=0;
            int heart=3;

            int pflag=0,rflag=0;
            long long int cf=0;



            while(!close){
                SDL_Event event;
                while(SDL_PollEvent(&event)){
                    switch(event.type){
                        case SDL_QUIT:
                        close = 1;
                        break;
                        case SDL_KEYDOWN:
                        switch(event.key.keysym.scancode){

                            case SDL_SCANCODE_LEFT:
                           { x_pos = max(50,x_pos-(SCROLL_SPEED/60));
                            break;
                           }
                            case SDL_SCANCODE_RIGHT:
                           {x_pos = min(MAZE_WIDTH-dest.w,x_pos+(SCROLL_SPEED/60));
                         
                            break;
                        } 
                            case  SDL_SCANCODE_UP:
                           { y_pos= max(50,y_pos-(SCROLL_SPEED/60));
                          
                            break;}
                            case  SDL_SCANCODE_DOWN:
                           { y_pos= min(MAZE_HEIGHT-dest.h,y_pos+(SCROLL_SPEED/60));
                       ;
                            break;}
                            case SDL_SCANCODE_ESCAPE:
                            pause=1;
                            break;

                        }
                     

                    }
                }
                cf++;


                if(over==1)
                {
                    SDL_DestroyRenderer(rend);
                    SDL_DestroyWindow(win);
                    SDL_Quit();
                    return 0;
                }
                int bonusflag=0;


                if(pause==0 && gameover==0 && heart!=0 && pflag==0 && rflag==0)
                {
                


                     SDL_RenderClear(rend);
                     SDL_RenderCopy(rend, bc_tex, NULL, &bc_rect);
     //SEVERAL BONUS APPEARS IF WE SET UP NO FLAG.SO b1,b2,b3,b4 checks whether the bonus to be loaded in a particular frame is already loaded and gained.
                         //if once loaded and gained already,the flags will change into 1 and no more bonus will be loaded
                  
              
                     if(cf>=500 && cf<=580)
                     {
                        if(b1==0)

                      {bonusflag=1;//bonusflag=1 if a bonus will appear on screen
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                        }


                     }
                     else if(cf>=1200 && cf<=1280)

                      {
                        if(b2==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                        }


                     }
                      else if(cf>=1800 && cf<=1880)

                      {
                        if(b3==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);

                        }

                     } 
                      else if(cf>=2400 && cf<=2480)

                      {

                        if(b4==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                      }
                        


                     }
                      else if(cf>=3000 && cf<=3080)

                      {

                        if(b5==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                      }
                        


                     }
                      else if(cf>=3600 && cf<=3680)

                      {

                        if(b6==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                      }
                        


                     }
                      else if(cf>=4200 && cf<=4280)

                      {

                        if(b7==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                      }
                        


                     }

                      else if(cf>=4800 && cf<=4880)

                      {

                        if(b8==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                      }
                        


                     }
                      else if(cf>=5500 && cf<=5580)

                      {

                        if(b9==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                      }
                        


                     }
                      else if(cf>=6100 && cf<=6180)

                      {

                        if(b10==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                      }
                        


                     }
                          else if(cf>=6800 && cf<=6880)

                      {

                        if(b11==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                      }
                        


                     }
                      else if(cf>=2400 && cf<=2480)

                      {

                        if(b4==0)

                      {bonusflag=1;
                       SDL_RenderCopy(rend, bonus_tex, NULL, &bonus_rect);
                      }
                        


                     }
                  


                       if((x_pos>=px1 && x_pos<=px2) && (y_pos>=py1 && y_pos<=py2) )
                     {

                     //PLAYING A CHUNK IF TARGET IS GAINED 

                     Mix_Chunk* tmusic=Mix_LoadWAV("treasurem.wav");
                    Mix_PlayChannel(-1,tmusic,0);
                      count++;
                      target1_rect.x =(rand()%(WINDOW_WIDTH-140))+50;
                      target1_rect.y =(rand()%(WINDOW_HEIGHT-140))+50;

        //CHECKING THE RANDOMLY GENERATED POSITION OF TARGET AND CORRECTING IT

                      if(target1_rect.y>= 50 && target1_rect.y<=120)
                      {target1_rect.x=105;
                        target1_rect.y=WINDOW_HEIGHT-100;}

                     if(target1_rect.y>=120 && target1_rect.y<=640)

                       {    if(target1_rect.x>=305 && target1_rect.x<=WINDOW_WIDTH-305)
                        {
                            target1_rect.x=target1_rect.x;
                            target1_rect.y=target1_rect.y;

                        }
                        else{

                        target1_rect.x=WINDOW_WIDTH-305;
                        target1_rect.y=470;}
                       }
                     if((target1_rect.y>=120 && target1_rect.y<=460) && (target1_rect.x>=WINDOW_WIDTH-540 && target1_rect.x<=WINDOW_WIDTH))
                      {target1_rect.x=WINDOW_WIDTH-325;
                        target1_rect.y=670;}


                    

                      px1=target1_rect.x-55,px2=target1_rect.x+55,py1=target1_rect.y-55,py2=target1_rect.y+55;
                     }


                     if(bonusflag==1) //IF ANY BONUS HAS APPEARED
                     {                   

                    if((x_pos>=zx1 && x_pos<=zx2) && (y_pos>=zy1 && y_pos<=zy2) )  //checking if the player gets any bonus
                     {
                     Mix_Chunk* tmusic=Mix_LoadWAV("treasurem.wav");    //playing a chunk if bonus is gained
                    Mix_PlayChannel(-1,tmusic,0);
                      count=count+3;
                      if(cf>=500 && cf<=580)
                      b1=1;
                   else if(cf>=1200 && cf<=1280)
                      b2=1;
                    else if(cf>=1800 && cf<=1880)
                      b3=1;

                  else if(cf>=2400 && cf<=2480)
                      b4=1;             
                      bonus_rect.x =(rand()%(WINDOW_WIDTH-140))+50;
                      bonus_rect.y =(rand()%(WINDOW_HEIGHT-140))+50;

        //CHECKING THE RANDOMLY GENERATED POSITION OF TARGET AND CORRECTING IT


                      if(bonus_rect.y>= 50 && bonus_rect.y<=120)
                      {bonus_rect.x=WINDOW_WIDTH-315;
                      bonus_rect.y=680;}
                     if(bonus_rect.y>=120 && bonus_rect.y<=640)

                       {    if(bonus_rect.x>=305 && bonus_rect.x<=WINDOW_WIDTH-305)
                        {
                            bonus_rect.x=bonus_rect.x;
                            bonus_rect.y=bonus_rect.y;

                        }
                        else{

                        bonus_rect.x=WINDOW_WIDTH-305;
                        bonus_rect.y=470;}
                       }
                     if((bonus_rect.y>=120 && bonus_rect.y<=460) && (bonus_rect.x>=WINDOW_WIDTH-540 && bonus_rect.y<=WINDOW_WIDTH))
                      {bonus_rect.x=WINDOW_WIDTH-325;
                        bonus_rect.y=670;}

                    
                      zx1=bonus_rect.x-55,zx2=bonus_rect.x+55,zy1=bonus_rect.y-55,zy2=bonus_rect.y+55;
                      bonusflag=0;
                     }
                 }
     

                   /*  if(count==100)
                      {
                         gameover=1;
                         break;
                         }*/
     




            

                     
                    SDL_RenderCopy(rend, wall_tex, NULL, &wall_rect);
                    SDL_RenderCopy(rend, wall2_tex, NULL, &wall2_rect);
                    SDL_RenderCopy(rend, wall3_tex, NULL, &wall3_rect);
                    SDL_RenderCopy(rend, wall4_tex, NULL, &wall4_rect);
                    SDL_RenderCopy(rend, scoresc_tex, NULL, &scoresc_rect);

                    SDL_RenderCopy(rend, level1_tex, NULL, &level1_rect);
                        //life will appear on screen depending on their number remained

                    if(heart==3)
                     {
                     SDL_RenderCopy(rend,heart1_tex, NULL, &heart1_rect);
                     SDL_RenderCopy(rend,heart2_tex, NULL, &heart2_rect);
                     SDL_RenderCopy(rend,heart3_tex, NULL, &heart3_rect);

                     }
                     if(heart==2)
                     {
                     SDL_RenderCopy(rend,heart1_tex, NULL, &heart1_rect);
                     SDL_RenderCopy(rend,heart2_tex, NULL, &heart2_rect);
                     }
                     if(heart==1)
                     {
                     SDL_RenderCopy(rend,heart1_tex, NULL, &heart1_rect);
                     }


                    SDL_RenderCopy(rend, tex, NULL, &dest);
                    SDL_RenderCopy(rend, ghost1_tex, NULL, &ghost1_rect);
                    SDL_RenderCopy(rend, obstacle1_tex, NULL, &obstacle1_rect);
                    SDL_RenderCopy(rend, obstacle2_tex, NULL, &obstacle2_rect);
                    SDL_RenderCopy(rend, obstacle3_tex, NULL, &obstacle3_rect);
                    SDL_RenderCopy(rend, obstacle4_tex, NULL, &obstacle4_rect);
                    SDL_RenderCopy(rend, obstacle5_tex, NULL, &obstacle5_rect);
                    SDL_RenderCopy(rend, obstacle6_tex, NULL, &obstacle6_rect);
                    SDL_RenderCopy(rend, obstacle7_tex, NULL, &obstacle7_rect);











                    
                     SDL_RenderCopy(rend, target1_tex, NULL, &target1_rect);


                    c=0;
                    count2=count;

                    if(count2==0)
                         {
                    
                            SDL_RenderCopy(rend, digit_tex[0], NULL, &show_rect);
                         }

                        else
                        {

                            while(count2>0)
                            {

                                d=count2%10;
                                count2=count2/10;
                                if(c==0)
                                    SDL_RenderCopy(rend, digit_tex[d], NULL, &show_rect);
                                else if(c==1)
                                    SDL_RenderCopy(rend, digit_tex[d], NULL, &show_rect2);
                                c++;

                            }
                        }






                    ghost1_rect.x=ghost1_posx;
                    ghost1_rect.y=ghost1_posy; 

                    

                    dest.x = (int) x_pos;
                    dest.y =(int)y_pos;






                   
                    SDL_RenderPresent(rend);

                     if(ghost1_posx<=dest.x){
                    ghost1_posx += (float) pdirectionx*(GHOST_SPEED/60);
               }
                     else if(ghost1_posx>=dest.x){
                    ghost1_posx -= (float) pdirectionx*(GHOST_SPEED/60);
      

                }
           if(ghost1_posy<=dest.y){

               ghost1_posy += (float) pdirectiony*(GHOST_SPEED/60);

                }
                           if(ghost1_posy>=dest.y){

               ghost1_posy -= (float) pdirectiony*(GHOST_SPEED/60);
     
                }


        
            
                if(abs(ghost1_posx-dest.x)!=0)
                {
                  if(ghost1_posx<=dest.x)
                    ghost1_posx += (float) pdirectionx*(GHOST_SPEED/60);
                   
                     else if(ghost1_posx>=dest.x)
                    ghost1_posx -= (float) pdirectionx*(GHOST_SPEED/60);  
                }
                 if(abs(ghost1_posy-dest.y)!=0)
                {
                  if(ghost1_posy<=dest.y)
                    ghost1_posy += (float) pdirectiony*(GHOST_SPEED/60);
                   
                 else if(ghost1_posy>=dest.y)
                    ghost1_posy -= (float) pdirectiony*(GHOST_SPEED/60);  
                }
            









                  if (  ( (dest.x+dest.w>=ghost1_rect.x  &&  dest.x+dest.w<=ghost1_rect.x+ghost1_rect.w  ) || (dest.x>=ghost1_rect.x && dest.x<=ghost1_rect.x+ghost1_rect.w ))  && 
                    ( (dest.y>=ghost1_rect.y  &&  dest.y<=ghost1_rect.y+ ghost1_rect.h)    ||    (dest.y+dest.h>=ghost1_rect.y  &&  dest.y+dest.h<=ghost1_rect.y+ ghost1_rect.h) ) )
                  {
                    heart=heart-1;
                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");//playing a chunk if caught by an enemy
                    Mix_PlayChannel(-1,colmusic,0);
                      x_pos=300;
                       y_pos=300;

                  }

                  else if (  ( (dest.x+dest.w>=obstacle1_rect.x  &&  dest.x+dest.w<=obstacle1_rect.x+obstacle1_rect.w  ) || (dest.x>=obstacle1_rect.x && dest.x<=obstacle1_rect.x+obstacle1_rect.w ))  && 
                    ( (dest.y>=obstacle1_rect.y  &&  dest.y<=obstacle1_rect.y+ obstacle1_rect.h)    ||    (dest.y+dest.h>=obstacle1_rect.y  &&  dest.y+dest.h<=obstacle1_rect.y+ obstacle1_rect.h) ) )
                  {

                      heart=heart-1;


                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;


    ;

                  }
                  else if (  ( (dest.x+dest.w>=obstacle2_rect.x  &&  dest.x+dest.w<=obstacle2_rect.x+obstacle2_rect.w  ) || (dest.x>=obstacle2_rect.x && dest.x<=obstacle2_rect.x+obstacle2_rect.w ))  && 
                    ( (dest.y>=obstacle2_rect.y  &&  dest.y<=obstacle2_rect.y+ obstacle2_rect.h)    ||    (dest.y+dest.h>=obstacle2_rect.y  &&  dest.y+dest.h<=obstacle2_rect.y+ obstacle2_rect.h) ) )
                  {

                      heart=heart-1;
                  Mix_Chunk* spmusic=Mix_LoadWAV("splash.wav");  //playing a different chunk if the player gets into the river
                    Mix_PlayChannel(-1,spmusic,0);
                   x_pos=300;
                    y_pos=300;


                    
                  }
                  else if (  ( (dest.x+dest.w>=obstacle3_rect.x  &&  dest.x+dest.w<=obstacle3_rect.x+obstacle3_rect.w  ) || (dest.x>=obstacle3_rect.x && dest.x<=obstacle3_rect.x+obstacle3_rect.w ))  && 
                    ( (dest.y>=obstacle3_rect.y  &&  dest.y<=obstacle3_rect.y+ obstacle3_rect.h)    ||    (dest.y+dest.h>=obstacle3_rect.y  &&  dest.y+dest.h<=obstacle3_rect.y+ obstacle3_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }




                  else if (  ( (dest.x+dest.w>=obstacle4_rect.x  &&  dest.x+dest.w<=obstacle4_rect.x+obstacle4_rect.w  ) || (dest.x>=obstacle4_rect.x && dest.x<=obstacle4_rect.x+obstacle4_rect.w ))  && 
                    ( (dest.y>=obstacle4_rect.y  &&  dest.y<=obstacle4_rect.y+ obstacle4_rect.h)    ||    (dest.y+dest.h>=obstacle4_rect.y  &&  dest.y+dest.h<=obstacle4_rect.y+ obstacle4_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }
                      else if (  ( (dest.x+dest.w>=obstacle5_rect.x  &&  dest.x+dest.w<=obstacle5_rect.x+obstacle5_rect.w  ) || (dest.x>=obstacle5_rect.x && dest.x<=obstacle5_rect.x+obstacle5_rect.w ))  && 
                    ( (dest.y>=obstacle5_rect.y  &&  dest.y<=obstacle5_rect.y+ obstacle5_rect.h)    ||    (dest.y+dest.h>=obstacle5_rect.y  &&  dest.y+dest.h<=obstacle5_rect.y+ obstacle5_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }
                      else if (  ( (dest.x+dest.w>=obstacle6_rect.x  &&  dest.x+dest.w<=obstacle6_rect.x+obstacle6_rect.w  ) || (dest.x>=obstacle6_rect.x && dest.x<=obstacle6_rect.x+obstacle6_rect.w ))  && 
                    ( (dest.y>=obstacle6_rect.y  &&  dest.y<=obstacle6_rect.y+ obstacle6_rect.h)    ||    (dest.y+dest.h>=obstacle6_rect.y  &&  dest.y+dest.h<=obstacle6_rect.y+ obstacle6_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }
                      else if (  ( (dest.x+dest.w>=obstacle7_rect.x  &&  dest.x+dest.w<=obstacle7_rect.x+obstacle7_rect.w  ) || (dest.x>=obstacle7_rect.x && dest.x<=obstacle7_rect.x+obstacle7_rect.w ))  && 
                    ( (dest.y>=obstacle7_rect.y  &&  dest.y<=obstacle7_rect.y+ obstacle7_rect.h)    ||    (dest.y+dest.h>=obstacle7_rect.y  &&  dest.y+dest.h<=obstacle7_rect.y+ obstacle7_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }


                  /*else if (  ( (dest.x+dest.w>=ghost3_rect.x  &&  dest.x+dest.w<=ghost3_rect.x+ghost3_rect.w  ) || (dest.x>=ghost3_rect.x && dest.x<=ghost3_rect.x+ghost3_rect.w ))  && 
                    ( (dest.y>=ghost3_rect.y  &&  dest.y<=ghost3_rect.y+ ghost3_rect.h)    ||    (dest.y+dest.h>=ghost3_rect.y  &&  dest.y+dest.h<=ghost3_rect.y+ ghost3_rect.h) ) )
                  {
                    gameover=1;
                  }

                  else if (  ( (dest.x+dest.w>=ghost4_rect.x  &&  dest.x+dest.w<=ghost4_rect.x+ghost4_rect.w  ) || (dest.x>=ghost4_rect.x && dest.x<=ghost4_rect.x+ghost4_rect.w ))  && 
                    ( (dest.y>=ghost4_rect.y  &&  dest.y<=ghost4_rect.y+ ghost4_rect.h)    ||    (dest.y+dest.h>=ghost4_rect.y  &&  dest.y+dest.h<=ghost4_rect.y+ ghost4_rect.h) ) )
                  {
                    gameover=1;
                  }*/


    if(count>=3)//IF THE PLAYER GETS MORE THAN OR EQUAL TO 3 POINTS,LEVEL TO WILL GET IMPLEMENTED
        {pflag=1;//IF PFLAG==1,LEVEL2 WILL GET IMPLEMENTED

        rflag=1;

        }




                  SDL_Delay(1000/60);

              }

    count=count;


          if(pflag==1 && gameover==0 && pause==0 && heart!=0)
          {



            

             SDL_RenderClear(rend);

             if(l2flag==1) //THE LEVEL COMPLETED IMAGE WILL APPEAR ONLY ONCE FOR l2flag=1[initial value].the flag will be changed into 0 once it is implementd 
             {

              SDL_RenderClear(rend);

            SDL_RenderCopy(rend,lecompleted_tex, NULL, &lecompleted_rect);


           SDL_RenderPresent(rend);
           SDL_Delay(2000);



         Mix_Chunk* wmusic=Mix_LoadWAV("tada.wav");
          Mix_PlayChannel(-1,wmusic,0);
          l2flag=0;



             }
        

          SDL_RenderClear(rend);

            SDL_RenderCopy(rend, bc2_tex, NULL, &bc2_rect);


                   


                       if((x_pos>=wx1 && x_pos<=wx2) && (y_pos>=wy1 && y_pos<=wy2) )
                     {
                     Mix_Chunk* tmusic=Mix_LoadWAV("treasurem.wav");
                    Mix_PlayChannel(-1,tmusic,0);
                      count++;
                      target2_rect.x =(rand()%(WINDOW_WIDTH-140))+50;
                      target2_rect.y =(rand()%(WINDOW_HEIGHT-140))+50;


                      if(target2_rect.y>= 50 && target2_rect.y<=120)
                      {target2_rect.x=WINDOW_WIDTH-305;
                        target2_rect.y=640;}
                     if(target2_rect.y>=120 && target2_rect.y<=640)

                       {    if(target2_rect.x>=305 && target2_rect.x<=WINDOW_WIDTH-305)
                        {
                            target2_rect.x=target2_rect.x;
                            target2_rect.y=target2_rect.y;

                        }
                        else{

                        target2_rect.x=WINDOW_WIDTH-305;
                        target2_rect.y=470;}
                       }
                     if((target2_rect.y>=390 && target2_rect.y<=590) && (target2_rect.x>=300 && target2_rect.x<=530))
                      {target2_rect.x=450;
                        target2_rect.y=WINDOW_HEIGHT-100;}
                     if((target2_rect.y>=WINDOW_HEIGHT-210 && target2_rect.y<=WINDOW_HEIGHT-130) && (target2_rect.x>=170 && target2_rect.x<=260))
                      {target2_rect.x=220;
                        target2_rect.y=130;}
                     if((target2_rect.y>=WINDOW_HEIGHT-420 && target2_rect.y<=WINDOW_HEIGHT-310) && (target2_rect.x>=150 && target2_rect.x<=240))
                      {target2_rect.x=WINDOW_WIDTH-105;
                        target2_rect.y=WINDOW_HEIGHT-100;}




                        wx1=target2_rect.x-40,wx2=target2_rect.x+40,wy1=target2_rect.y-40,wy2=target2_rect.y+40;


                     }

                     if(bonusflag==1)
                     {                   

                    if((x_pos>=zx1 && x_pos<=zx2) && (y_pos>=zy1 && y_pos<=zy2) )
                     {
                     Mix_Chunk* tmusic=Mix_LoadWAV("treasurem.wav");
                    Mix_PlayChannel(-1,tmusic,0);
                      count=count+3;
                      if(cf>=3000 && cf<=3080)
                      b5=1;
                   else if(cf>=3600 && cf<=3680)
                      b6=1;
                    else if(cf>=4200 && cf<=4280)
                      b7=1;

                  else if(cf>=4800 && cf<=4880)
                      b8=1;
                  else if(cf>=5500 && cf<=5580)
                      b9=1;    
                  else if(cf>=6100 && cf<=6180)
                      b10=1;    
                  else if(cf>=6800 && cf<=6880)
                      b11=1;                 
                      bonus_rect.x =(rand()%(WINDOW_WIDTH-140))+50;
                      bonus_rect.y =(rand()%(WINDOW_HEIGHT-140))+50;
            //same logic as level 1 [for 7 bonuses]


                      if(bonus_rect.y>= 50 && bonus_rect.y<=120)
                      {bonus_rect.x=WINDOW_WIDTH-305;
                        bonus_rect.y=640;}
                     if(bonus_rect.y>=120 && bonus_rect.y<=640)

                       {    if(bonus_rect.x>=305 && bonus_rect.x<=WINDOW_WIDTH-305)
                        {
                            bonus_rect.x=bonus_rect.x;
                            bonus_rect.y=bonus_rect.y;

                        }
                        else{

                        bonus_rect.x=WINDOW_WIDTH-305;
                        bonus_rect.y=460;}
                       }
                     if((bonus_rect.y>=390 && bonus_rect.y<=590) && (bonus_rect.x>=300 && bonus_rect.x<=530))
                      {bonus_rect.x=450;
                        bonus_rect.y=WINDOW_HEIGHT-100;}
                     if((bonus_rect.y>=WINDOW_HEIGHT-210 && bonus_rect.y<=WINDOW_HEIGHT-130) && (bonus_rect.x>=170 && bonus_rect.x<=260))
                      {bonus_rect.x=220;
                        bonus_rect.y=130;}
                     if((bonus_rect.y>=WINDOW_HEIGHT-420 && bonus_rect.y<=WINDOW_HEIGHT-310) && (bonus_rect.x>=150 && bonus_rect.x<=240))
                      {bonus_rect.x=WINDOW_WIDTH-105;
                        bonus_rect.y=WINDOW_HEIGHT-100;}



                    
                      zx1=bonus_rect.x-40,zx2=bonus_rect.x+40,zy1=bonus_rect.y-40,zy2=bonus_rect.y+40;
                      bonusflag=0;
                     }
                 }

                  

                    SDL_RenderCopy(rend, wall_tex, NULL, &wall_rect);
                    SDL_RenderCopy(rend, wall2_tex, NULL, &wall2_rect);
                    SDL_RenderCopy(rend, wall3_tex, NULL, &wall3_rect);
                    SDL_RenderCopy(rend, wall4_tex, NULL, &wall4_rect);
                    SDL_RenderCopy(rend, level1_tex, NULL, &level1_rect);


                    SDL_RenderCopy(rend, tex, NULL, &dest);
                    SDL_RenderCopy(rend, ghost2_tex, NULL, &ghost2_rect);
                    SDL_RenderCopy(rend, ghost3_tex, NULL, &ghost3_rect);
                  if(heart==3)
                     {
                     SDL_RenderCopy(rend,heart1_tex, NULL, &heart1_rect);
                     SDL_RenderCopy(rend,heart2_tex, NULL, &heart2_rect);
                     SDL_RenderCopy(rend,heart3_tex, NULL, &heart3_rect);

                     }
                     if(heart==2)
                     {
                     SDL_RenderCopy(rend,heart1_tex, NULL, &heart1_rect);
                     SDL_RenderCopy(rend,heart2_tex, NULL, &heart2_rect);
                     }
                     if(heart==1)
                     {
                     SDL_RenderCopy(rend,heart1_tex, NULL, &heart1_rect);
                     }


                    SDL_RenderCopy(rend, obstacle1_tex, NULL, &obstacle1_rect);
                    SDL_RenderCopy(rend, obstacle2_tex, NULL, &obstacle2_rect);
                    SDL_RenderCopy(rend, obstacle3_tex, NULL, &obstacle3_rect);
                    SDL_RenderCopy(rend, obstacle4_tex, NULL, &obstacle4_rect);
                    SDL_RenderCopy(rend, obstacle5_tex, NULL, &obstacle5_rect);
                    SDL_RenderCopy(rend, obstacle6_tex, NULL, &obstacle6_rect);
                    SDL_RenderCopy(rend, obstacle7_tex, NULL, &obstacle7_rect);
                    SDL_RenderCopy(rend, obstacle8_tex, NULL, &obstacle8_rect);
                    SDL_RenderCopy(rend, obstacle9_tex, NULL, &obstacle9_rect);
                    SDL_RenderCopy(rend, obstacle10_tex, NULL, &obstacle10_rect);




                    
                     SDL_RenderCopy(rend, target2_tex, NULL, &target2_rect);

                     c=0;
                    count2=count;

                    if(count2==0)
                     {
                    
                    SDL_RenderCopy(rend, digit_tex[0], NULL, &show_rect);
                     }

                     else
                    {

                     while(count2>0)
                        {

                                d=count2%10;
                                count2=count2/10;
                                if(c==0)
                                    SDL_RenderCopy(rend, digit_tex[d], NULL, &show_rect);
                                else if(c==1)
                                    SDL_RenderCopy(rend, digit_tex[d], NULL, &show_rect2);
                                c++;

                            }
                        }
                    ghost2_rect.x=ghost2_posx;
                    ghost2_rect.y=ghost2_posy;


                    ghost3_rect.x=ghost3_posx;
                    ghost3_rect.y=ghost3_posy;






                    

                    dest.x = (int) x_pos;
                    dest.y =(int)y_pos;






                    SDL_RenderPresent(rend);



                 if(ghost2_posx<=dest.x){

                    ghost2_posx += (float) qdirectionx*(GHOST_SPEED/60);
             }
                     else if(ghost2_posx>=dest.x){
                    ghost2_posx -= (float) qdirectionx*(GHOST_SPEED/60);


                }
           if(ghost2_posy<=dest.y){

               ghost2_posy += (float) qdirectiony*(GHOST_SPEED/60);
                 }
                           if(ghost2_posy>=dest.y){

               ghost2_posy -= (float) qdirectiony*(GHOST_SPEED/60);

                }


        
            
                if(abs(ghost2_posx-dest.x)!=0)
                {
                  if(ghost2_posx<=dest.x)
                    ghost2_posx += (float) qdirectionx*(GHOST_SPEED/60);
                   
                     else if(ghost2_posx>=dest.x)
                    ghost2_posx -= (float) qdirectionx*(GHOST_SPEED/60);  
                }
                 if(abs(ghost2_posy-dest.y)!=0)
                {
                  if(ghost2_posy<=dest.y)
                    ghost2_posy += (float) qdirectiony*(GHOST_SPEED/60);
                   
                 else if(ghost2_posy>=dest.y)
                    ghost2_posy -= (float) qdirectiony*(GHOST_SPEED/60);  
                }
            

                     if(ghost3_posx<=dest.x){
                    ghost3_posx += (float) rdirectionx*(GHOST2_SPEED/60);
                   /* if(ghost1_posx>=dest.x-10 || ghost1_posx<=50)
                    {
                      pdirectionx=pdirectionx*(-1);

                      if(ghost1_posx>=dest.x-10)ghost1_posx=dest.x-10;
                      else ghost1_posx=50;

                    }*/}
                     else if(ghost3_posx>=dest.x){
                    ghost3_posx -= (float) rdirectionx*(GHOST2_SPEED/60);
                   /* if(ghost1_posx<=dest.x-10 || ghost1_posx>=50)
                    {
                      pdirectionx =pdirectionx*(-1);

                      if(ghost1_posx<=dest.x-10)ghost1_posx=dest.x-10;
                      else ghost1_posx=50;

                    }}*/

                }
           if(ghost3_posy<=dest.y){

               ghost3_posy += (float) rdirectiony*(GHOST2_SPEED/60);
                   /* if(ghost1_posy>=dest.y-10 || ghost1_posy<=300)
                    {
                      pdirectiony =pdirectiony*(-1);

                      if(ghost1_posy>=dest.y-10)ghost1_posy=dest.y-10;
                      else ghost1_posy=300;

                    }*/
                }
                           if(ghost3_posy>=dest.y){

               ghost3_posy -= (float) rdirectiony*(GHOST2_SPEED/60);
                    /*if(ghost1_posy<=dest.y-10 || ghost1_posy>=300)
                    {
                      pdirectiony=pdirectiony*(-1);

                      if(ghost1_posy<=dest.y-10)ghost1_posy=dest.y-10;
                      else
                        ghost1_posy=300;


                    }*/
                }


        
                if(abs(ghost3_posx-dest.x)!=0)
                {
                  if(ghost3_posx<=dest.x)
                    ghost3_posx += (float) rdirectionx*(GHOST2_SPEED/60);
                   
                     else if(ghost1_posx>=dest.x)
                    ghost3_posx -= (float) rdirectionx*(GHOST2_SPEED/60);  
                }
                 if(abs(ghost3_posy-dest.y)!=0)
                {
                  if(ghost3_posy<=dest.y)
                    ghost3_posy += (float) rdirectiony*(GHOST2_SPEED/60);
                   
                 else if(ghost3_posy>=dest.y)
                    ghost3_posy -= (float) pdirectiony*(GHOST2_SPEED/60);  
                }
            

     

                if (  ( (dest.x+dest.w>=ghost2_rect.x  &&  dest.x+dest.w<=ghost2_rect.x+ghost2_rect.w  ) || (dest.x>=ghost2_rect.x && dest.x<=ghost2_rect.x+ghost2_rect.w ))  && 
                    ( (dest.y>=ghost2_rect.y  &&  dest.y<=ghost2_rect.y+ ghost2_rect.h)    ||    (dest.y+dest.h>=ghost2_rect.y  &&  dest.y+dest.h<=ghost2_rect.y+ ghost2_rect.h) ) )
                  {
                         heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
               
                   x_pos=300;
                    y_pos=300;}



                  if (  ( (dest.x+dest.w>=ghost3_rect.x  &&  dest.x+dest.w<=ghost3_rect.x+ghost3_rect.w  ) || (dest.x>=ghost3_rect.x && dest.x<=ghost3_rect.x+ghost3_rect.w ))  && 
                    ( (dest.y>=ghost3_rect.y  &&  dest.y<=ghost3_rect.y+ ghost3_rect.h)    ||    (dest.y+dest.h>=ghost3_rect.y  &&  dest.y+dest.h<=ghost3_rect.y+ ghost3_rect.h) ) )
                  {
                    heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
           
                   x_pos=300;
                    y_pos=300;
                  }
                  if(heart==0)
                  {
                     pflag=0;
                    rflag=0;
                  }
                  else if (  ( (dest.x+dest.w>=obstacle1_rect.x  &&  dest.x+dest.w<=obstacle1_rect.x+obstacle1_rect.w  ) || (dest.x>=obstacle1_rect.x && dest.x<=obstacle1_rect.x+obstacle1_rect.w ))  && 
                    ( (dest.y>=obstacle1_rect.y  &&  dest.y<=obstacle1_rect.y+ obstacle1_rect.h)    ||    (dest.y+dest.h>=obstacle1_rect.y  &&  dest.y+dest.h<=obstacle1_rect.y+ obstacle1_rect.h) ) )
                  {

                      heart=heart-1;


                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;

                  }
                  else if (  ( (dest.x+dest.w>=obstacle2_rect.x  &&  dest.x+dest.w<=obstacle2_rect.x+obstacle2_rect.w  ) || (dest.x>=obstacle2_rect.x && dest.x<=obstacle2_rect.x+obstacle2_rect.w ))  && 
                    ( (dest.y>=obstacle2_rect.y  &&  dest.y<=obstacle2_rect.y+ obstacle2_rect.h)    ||    (dest.y+dest.h>=obstacle2_rect.y  &&  dest.y+dest.h<=obstacle2_rect.y+ obstacle2_rect.h) ) )
                  {

                      heart=heart-1;
                      heart=heart-1;
                  Mix_Chunk* spmusic=Mix_LoadWAV("splash.wav");
                    Mix_PlayChannel(-1,spmusic,0);
                   x_pos=300;
                    y_pos=300;

                    
                  }
                  else if (  ( (dest.x+dest.w>=obstacle3_rect.x  &&  dest.x+dest.w<=obstacle3_rect.x+obstacle3_rect.w  ) || (dest.x>=obstacle3_rect.x && dest.x<=obstacle3_rect.x+obstacle3_rect.w ))  && 
                    ( (dest.y>=obstacle3_rect.y  &&  dest.y<=obstacle3_rect.y+ obstacle3_rect.h)    ||    (dest.y+dest.h>=obstacle3_rect.y  &&  dest.y+dest.h<=obstacle3_rect.y+ obstacle3_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }


                  else if (  ( (dest.x+dest.w>=obstacle3_rect.x  &&  dest.x+dest.w<=obstacle3_rect.x+obstacle3_rect.w  ) || (dest.x>=obstacle3_rect.x && dest.x<=obstacle3_rect.x+obstacle3_rect.w ))  && 
                    ( (dest.y>=obstacle3_rect.y  &&  dest.y<=obstacle3_rect.y+ obstacle3_rect.h)    ||    (dest.y+dest.h>=obstacle3_rect.y  &&  dest.y+dest.h<=obstacle3_rect.y+ obstacle3_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }

                  else if (  ( (dest.x+dest.w>=obstacle4_rect.x  &&  dest.x+dest.w<=obstacle4_rect.x+obstacle4_rect.w  ) || (dest.x>=obstacle4_rect.x && dest.x<=obstacle4_rect.x+obstacle4_rect.w ))  && 
                    ( (dest.y>=obstacle4_rect.y  &&  dest.y<=obstacle4_rect.y+ obstacle4_rect.h)    ||    (dest.y+dest.h>=obstacle4_rect.y  &&  dest.y+dest.h<=obstacle4_rect.y+ obstacle4_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }
                      else if (  ( (dest.x+dest.w>=obstacle5_rect.x  &&  dest.x+dest.w<=obstacle5_rect.x+obstacle5_rect.w  ) || (dest.x>=obstacle5_rect.x && dest.x<=obstacle5_rect.x+obstacle5_rect.w ))  && 
                    ( (dest.y>=obstacle5_rect.y  &&  dest.y<=obstacle5_rect.y+ obstacle5_rect.h)    ||    (dest.y+dest.h>=obstacle5_rect.y  &&  dest.y+dest.h<=obstacle5_rect.y+ obstacle5_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }
                      else if (  ( (dest.x+dest.w>=obstacle6_rect.x  &&  dest.x+dest.w<=obstacle6_rect.x+obstacle6_rect.w  ) || (dest.x>=obstacle6_rect.x && dest.x<=obstacle6_rect.x+obstacle6_rect.w ))  && 
                    ( (dest.y>=obstacle6_rect.y  &&  dest.y<=obstacle6_rect.y+ obstacle6_rect.h)    ||    (dest.y+dest.h>=obstacle6_rect.y  &&  dest.y+dest.h<=obstacle6_rect.y+ obstacle6_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }
                      else if (  ( (dest.x+dest.w>=obstacle7_rect.x  &&  dest.x+dest.w<=obstacle7_rect.x+obstacle7_rect.w  ) || (dest.x>=obstacle7_rect.x && dest.x<=obstacle7_rect.x+obstacle7_rect.w ))  && 
                    ( (dest.y>=obstacle7_rect.y  &&  dest.y<=obstacle7_rect.y+ obstacle7_rect.h)    ||    (dest.y+dest.h>=obstacle7_rect.y  &&  dest.y+dest.h<=obstacle7_rect.y+ obstacle7_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }
                      else if (  ( (dest.x+dest.w>=obstacle8_rect.x  &&  dest.x+dest.w<=obstacle8_rect.x+obstacle8_rect.w  ) || (dest.x>=obstacle8_rect.x && dest.x<=obstacle8_rect.x+obstacle8_rect.w ))  && 
                    ( (dest.y>=obstacle8_rect.y  &&  dest.y<=obstacle8_rect.y+ obstacle8_rect.h)    ||    (dest.y+dest.h>=obstacle8_rect.y  &&  dest.y+dest.h<=obstacle8_rect.y+ obstacle8_rect.h) ) )
                  {
                      heart=heart-1;
                  Mix_Chunk* spmusic=Mix_LoadWAV("splash.wav");
                    Mix_PlayChannel(-1,spmusic,0);
                   x_pos=300;
                    y_pos=300;



                  }
                      else if (  ( (dest.x+dest.w>=obstacle9_rect.x  &&  dest.x+dest.w<=obstacle9_rect.x+obstacle9_rect.w  ) || (dest.x>=obstacle9_rect.x && dest.x<=obstacle9_rect.x+obstacle9_rect.w ))  && 
                    ( (dest.y>=obstacle9_rect.y  &&  dest.y<=obstacle9_rect.y+ obstacle9_rect.h)    ||    (dest.y+dest.h>=obstacle9_rect.y  &&  dest.y+dest.h<=obstacle9_rect.y+ obstacle9_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }

                          else if (  ( (dest.x+dest.w>=obstacle10_rect.x  &&  dest.x+dest.w<=obstacle10_rect.x+obstacle10_rect.w  ) || (dest.x>=obstacle10_rect.x && dest.x<=obstacle10_rect.x+obstacle10_rect.w ))  && 
                    ( (dest.y>=obstacle10_rect.y  &&  dest.y<=obstacle10_rect.y+ obstacle10_rect.h)    ||    (dest.y+dest.h>=obstacle10_rect.y  &&  dest.y+dest.h<=obstacle10_rect.y+ obstacle10_rect.h) ) )
                  {
                      heart=heart-1;

                     Mix_Chunk* colmusic=Mix_LoadWAV("enemym.wav");
                    Mix_PlayChannel(-1,colmusic,0);
                   x_pos=300;
                    y_pos=300;
                  }


           





                  SDL_Delay(1000/60);



          }


              
              else if(gameover==1||heart==0)
              {
                 SDL_RenderClear(rend);


                 SDL_RenderCopy(rend, overbg_tex, NULL, &overbg_rect);
                 SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
                 SDL_RenderCopy(rend, playag_tex, NULL, &playag_rect);
                 SDL_RenderCopy(rend, quit_tex, NULL, &quit_rect);
                SDL_RenderCopy(rend, score_tex, NULL, &score_rect);

                        c=0;
                        count2=count;
                        if(count==0)
                        SDL_RenderCopy(rend, digit_tex[0], NULL, &over_rect);
                        while(count2>0)
                        {

                            d=count2%10;
                            count2=count2/10;
                            if(c==0)
                            SDL_RenderCopy(rend, digit_tex[d], NULL, &over_rect);
                            else if(c==1)
                            SDL_RenderCopy(rend, digit_tex[d], NULL, &over_rect2);
                            c++;
                        }
                




                 SDL_RenderPresent(rend);
                 int mousex, mousey;
                 int directions = SDL_GetMouseState(&mousex, &mousey);

                 if(directions & SDL_BUTTON(SDL_BUTTON_LEFT))
                 {
                    if(mousex>=playag_rect.x && mousex<=(playag_rect.x+playag_rect.w) && mousey>=playag_rect.y && mousey<=(playag_rect.y+playag_rect.h))
                    {
                        gameover=0;
                        x_pos=300;
                        y_pos=300;
                        count=0;
                        l2flag=1;
                        heart=3;
     ghost1_posx=50;
     ghost1_posy=600;
     ghost2_posx=WINDOW_WIDTH-170;
     ghost2_posy=WINDOW_HEIGHT-200;
     ghost3_posx=WINDOW_WIDTH-300;
     ghost3_posy=300;
            


                    }

                    else if(mousex>=quit_rect.x && mousex<=(quit_rect.x+quit_rect.w) && mousey>=quit_rect.y && mousey<=(quit_rect.y+quit_rect.h))
                        over=1;


                 } 

     ghost1_posx=50;
     ghost1_posy=600;
     ghost2_posx=WINDOW_WIDTH-170;
     ghost2_posy=WINDOW_HEIGHT-200;
     ghost3_posx=WINDOW_WIDTH-300;
     ghost3_posy=300;



                 


            }
            
            
            
            


            else if(pause==1)

            {
                SDL_RenderClear(rend);

                
                SDL_RenderCopy(rend, overbg1_tex, NULL, &overbg1_rect);

                SDL_RenderCopy(rend, paused_tex, NULL, &paused_rect);
                SDL_RenderCopy(rend, resume_tex, NULL, &resume_rect);
                SDL_RenderCopy(rend, quit_tex, NULL, &quit_rect);



                SDL_RenderPresent(rend);

                int mousex, mousey;
                int positions = SDL_GetMouseState(&mousex, &mousey);

                if(positions & SDL_BUTTON(SDL_BUTTON_LEFT))
                {
                    if(mousex>=resume_rect.x && mousex<=(resume_rect.x+resume_rect.w) && mousey>=resume_rect.y && mousey<=(resume_rect.y+resume_rect.h))
                    {
                        pause = 0;
                        
                    }
                    else if(mousex>=quit_rect.x && mousex<=(quit_rect.x+quit_rect.w) && mousey>=quit_rect.y && mousey<=(quit_rect.y+quit_rect.h))
                     over=1;



             }
         }

     }

    }


    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
    }