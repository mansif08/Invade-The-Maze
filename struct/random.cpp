    #include <iostream>
    using namespace std;
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_timer.h>
    #include <stdlib.h>
    #include<time.h>
    #include <stdio.h>

    #include "initialization.cpp"
     
    #define WINDOW_WIDTH (1280)
    #define WINDOW_HEIGHT (960)
     #define MAZE_WIDTH (1230)
    #define MAZE_HEIGHT (910)
    #define SCROLL_SPEED (850)
    #define RECT_SPEED (5.0)
    #define GHOST_SPEED (100)
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

    void free(SDL_Texture* tex)
    {
    //Free texture if it exists
        if( tex!= NULL )
       {
           SDL_DestroyTexture( tex);
            tex = NULL;
       }
    }

/*
void initialize(void )
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)!=0)
        {
            printf("%s\n",SDL_GetError());
        }

        if(!(IMG_Init(IMG_INIT_PNG)))
        {
            printf("%s\n",SDL_GetError());
        }



}
*/



    int main()
    {


        //printf("initialization complete\n");
        initialize();

        SDL_Window* win= SDL_CreateWindow("invade the maze",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,0);

        if(!win)
        {
            printf("%s",SDL_GetError());
            SDL_Quit();
            return 1;
        }


        Uint32 render_flags= SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC;
        SDL_Renderer* rend=SDL_CreateRenderer(win,-1,render_flags);

        if(!rend)
        {
            printf("%s\n",SDL_GetError());
            SDL_DestroyWindow(win);
            SDL_Quit();
            return 1;

        }
      
        
        SDL_Surface* surface=IMG_Load("PROJECT INSTRUCTIONS2.png");

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
        {

            surface = IMG_Load("char.png");
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

            dest.w = 40;
            dest.h = 40;
            float x_pos=50;
            float y_pos=50;



            surface = IMG_Load("bc3.jpg");
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


             
            

            surface = IMG_Load("wall.jpeg");
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

            surface = IMG_Load("wall.jpeg");
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

            surface = IMG_Load("wall.jpeg");
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


            surface = IMG_Load("wall.jpeg");
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




            surface = IMG_Load("paused1.png");
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
            paused_rect.h = 450;
            paused_rect.x = (WINDOW_WIDTH-paused_rect.w)/2;
            paused_rect.y = (WINDOW_HEIGHT-paused_rect.h)/2-250;



            surface = IMG_Load("playagain1.png");
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
            playag_rect.h = 450;
            playag_rect.x = (WINDOW_WIDTH-playag_rect.w)/2;
            playag_rect.y = (WINDOW_HEIGHT-playag_rect.h)/2+150;
            
            surface = IMG_Load("quit1.png");
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
            quit_rect.w = 150;
            quit_rect.h = 75;
            quit_rect.x = WINDOW_WIDTH-150;
            quit_rect.y =0 ;

             
        
            surface = IMG_Load("ghost5.png");
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
            ghost1_rect.y = 300;
            float ghost1_pos=50;
            int pdirection=1;


            surface = IMG_Load("ghost5.png");
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
            float ghost2_pos=WINDOW_WIDTH-170;
            int qdirection=1;


            surface = IMG_Load("ghost5.png");
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

            ghost3_rect.w = 75;
            ghost3_rect.h = 100;
            ghost3_rect.x = 250;
            ghost3_rect.y = WINDOW_HEIGHT-400;
            float ghost3_pos=250;
            int rdirection=1;
            surface = IMG_Load("ghost5.png");
            if (!surface){
                printf("ghost4 Error: %s\n",IMG_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }


            SDL_Texture* ghost4_tex = SDL_CreateTextureFromSurface(rend, surface);
            SDL_FreeSurface(surface);
            if(!tex){
                printf("ghost4 Texture %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 1;
            }

            SDL_Rect ghost4_rect;

            ghost4_rect.w = 68;
            ghost4_rect.h = 55;
            ghost4_rect.x = WINDOW_WIDTH-120;
            ghost4_rect.y = 60;
            float ghost4_pos=WINDOW_WIDTH-120;
            int sdirection=1;




            surface = IMG_Load("gameover1.png");
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
            gameover_rect.h = 350;
            gameover_rect.x = (WINDOW_WIDTH-paused_rect.w)/2+50;
            gameover_rect.y = (WINDOW_HEIGHT-paused_rect.h)/2-250;



            srand(time(0));

            surface = IMG_Load("jewel2.png");
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

            target1_rect.w = 40;
            target1_rect.h = 40;
            target1_rect.x =(rand()%(WINDOW_WIDTH-140))+50;
            target1_rect.y =(rand()%(WINDOW_HEIGHT-140))+50;
            int px1=target1_rect.x-40,px2=target1_rect.x+40,py1=target1_rect.y-40,py2=target1_rect.y+40;
            



             

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




            SDL_Rect over_rect;

            over_rect.w = 100;
            over_rect.h = 100;
            over_rect.x = (WINDOW_WIDTH-100)/2;
            over_rect.y = 840;

            SDL_Rect over_rect2;

            over_rect2.w = 100;
            over_rect2.h = 100;
            over_rect2.x = ((WINDOW_WIDTH-100)/2)-100;
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


            SDL_Texture* digit_tex[10];



            surface = IMG_Load("0.jpg");
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

            surface = IMG_Load("3.jpg");
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



            surface = IMG_Load("4.jpg");
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


            surface = IMG_Load("5.jpg");
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



            surface = IMG_Load("6.jpg");
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


            surface = IMG_Load("7.jpg");
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

            surface = IMG_Load("9.jpg");
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
            int over=0;
            int close = 0;
            int pause = 0;
            int count=0,count2,d,c;

            

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
                            x_pos = max(50,x_pos-(SCROLL_SPEED/60));
                            break;
                            case SDL_SCANCODE_RIGHT:
                            x_pos = min(MAZE_WIDTH-dest.w,x_pos+(SCROLL_SPEED/60));
                            break;
                            case  SDL_SCANCODE_UP:
                            y_pos= max(50,y_pos-(SCROLL_SPEED/60));
                            break;
                            case  SDL_SCANCODE_DOWN:
                            y_pos= min(MAZE_HEIGHT-dest.h,y_pos+(SCROLL_SPEED/60));
                            break;
                            case SDL_SCANCODE_ESCAPE:
                            pause=1;
                            break;

                        }
                    }
                }

                if(over==1)
                {
                    close=1;
                    break;
                }

                if(pause==0 && gameover==0)
                {

                     if( (x_pos>=px1 && x_pos<=px2) && (y_pos>=py1 && y_pos<=py2) )
                     {
                         count++;
                         target1_rect.x =(rand()%(WINDOW_WIDTH-140))+50;
                         target1_rect.y =(rand()%(WINDOW_HEIGHT-140))+50;
                         px1=target1_rect.x-40,px2=target1_rect.x+40,py1=target1_rect.y-40,py2=target1_rect.y+40;
                     }

                     if(count==100)
                     {
                          gameover=1;
                          break;
                     }

                     SDL_RenderClear(rend);
                     SDL_RenderCopy(rend, bc_tex, NULL, &bc_rect);
                     SDL_RenderCopy(rend, wall_tex, NULL, &wall_rect);
                     SDL_RenderCopy(rend, wall2_tex, NULL, &wall2_rect);
                     SDL_RenderCopy(rend, wall3_tex, NULL, &wall3_rect);
                     SDL_RenderCopy(rend, wall4_tex, NULL, &wall4_rect);
                     SDL_RenderCopy(rend, tex, NULL, &dest);
                     SDL_RenderCopy(rend, ghost1_tex, NULL, &ghost1_rect);
                     SDL_RenderCopy(rend, ghost2_tex, NULL, &ghost2_rect);
                     SDL_RenderCopy(rend, ghost3_tex, NULL, &ghost3_rect);
                     SDL_RenderCopy(rend, ghost4_tex, NULL, &ghost4_rect);
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

                    ghost1_rect.x=ghost1_pos;
                    ghost2_rect.x=ghost2_pos;
                    ghost3_rect.x=ghost3_pos;
                    ghost4_rect.x=ghost4_pos;

                    dest.x = (int)x_pos;
                    dest.y =(int)y_pos;



                    SDL_RenderPresent(rend);


                   ghost1_pos += (float) pdirection*(GHOST_SPEED/60);
                   if(ghost1_pos>=550 || ghost1_pos<=50)
                   {
                        pdirection =pdirection*(-1);
                        if(ghost1_pos>=550)ghost1_pos=550;
                        else ghost1_pos=50;
 
                   }


                   ghost2_pos -= (float) qdirection*(GHOST_SPEED/60);
                   if(ghost2_pos<=WINDOW_WIDTH-450 || ghost2_pos>=WINDOW_WIDTH-170)
                   {
                        qdirection =qdirection*(-1);
                        if(ghost2_pos<=WINDOW_WIDTH-450)  ghost2_pos=WINDOW_WIDTH-450;
                        else ghost2_pos=WINDOW_WIDTH-170;
                   }


                   ghost3_pos += (float) rdirection*(GHOST_SPEED/60);
                   if(ghost3_pos>=550 || ghost3_pos<=250)
                   {
                       rdirection =rdirection*(-1);
                       if(ghost3_pos>=550)ghost3_pos=550;
                       else ghost3_pos=250;
                   }

                   ghost4_pos -= (float) sdirection*(GHOST_SPEED/60);
                   if(ghost4_pos>=WINDOW_WIDTH-120 || ghost4_pos<=WINDOW_WIDTH-380)
                   {
                       sdirection =sdirection*(-1);

                       if(ghost4_pos>=WINDOW_WIDTH-120) ghost4_pos=WINDOW_WIDTH-120;
                       else  ghost4_pos=WINDOW_WIDTH-380;

                    }

                   if(  ( (dest.x+dest.w>=ghost1_rect.x  &&  dest.x+dest.w<=ghost1_rect.x+ghost1_rect.w  ) || (dest.x>=ghost1_rect.x && dest.x<=ghost1_rect.x+ghost1_rect.w ))  && 
                         ( (dest.y>=ghost1_rect.y  &&  dest.y<=ghost1_rect.y+ ghost1_rect.h)    ||    (dest.y+dest.h>=ghost1_rect.y  &&  dest.y+dest.h<=ghost1_rect.y+ ghost1_rect.h) ) )
                       {
                           gameover=1;
                       }

                  else if(  ( (dest.x+dest.w>=ghost2_rect.x  &&  dest.x+dest.w<=ghost2_rect.x+ghost2_rect.w  ) || (dest.x>=ghost2_rect.x && dest.x<=ghost2_rect.x+ghost2_rect.w ))  && 
                          ( (dest.y>=ghost2_rect.y  &&  dest.y<=ghost2_rect.y+ ghost2_rect.h)    ||    (dest.y+dest.h>=ghost2_rect.y  &&  dest.y+dest.h<=ghost2_rect.y+ ghost2_rect.h) ) )
                       {
                           gameover=1;
                       }

                  else if(  ( (dest.x+dest.w>=ghost3_rect.x  &&  dest.x+dest.w<=ghost3_rect.x+ghost3_rect.w  ) || (dest.x>=ghost3_rect.x && dest.x<=ghost3_rect.x+ghost3_rect.w ))  && 
                          ( (dest.y>=ghost3_rect.y  &&  dest.y<=ghost3_rect.y+ ghost3_rect.h)    ||    (dest.y+dest.h>=ghost3_rect.y  &&  dest.y+dest.h<=ghost3_rect.y+ ghost3_rect.h) ) )
                       {
                           gameover=1;
                       }

                  else if (  ( (dest.x+dest.w>=ghost4_rect.x  &&  dest.x+dest.w<=ghost4_rect.x+ghost4_rect.w  ) || (dest.x>=ghost4_rect.x && dest.x<=ghost4_rect.x+ghost4_rect.w ))  && 
                        ( (dest.y>=ghost4_rect.y  &&  dest.y<=ghost4_rect.y+ ghost4_rect.h)    ||    (dest.y+dest.h>=ghost4_rect.y  &&  dest.y+dest.h<=ghost4_rect.y+ ghost4_rect.h) ) )
                      {
                          gameover=1;
                      }


                   SDL_Delay(1000/60);
 
                }



                else if (gameover==1)
               {
                     SDL_RenderClear(rend);


                     SDL_RenderCopy(rend, overbg_tex, NULL, &overbg_rect);

                     if(count!=100)
                     SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
                     
                     else
                     {
                        SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
                     }


                    SDL_RenderCopy(rend, playag_tex, NULL, &playag_rect);
                    SDL_RenderCopy(rend, quit_tex, NULL, &quit_rect);


               


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
                           x_pos=50;
                           y_pos=50;
                           count=0;
                        }

                        else if(mousex>=quit_rect.x && mousex<=(quit_rect.x+quit_rect.w) && mousey>=quit_rect.y && mousey<=(quit_rect.y+quit_rect.h))
                           over=1;


                    } 


                }



                else if(pause==1)
                {
                     SDL_RenderClear(rend);
                     SDL_RenderCopy(rend, overbg1_tex, NULL, &overbg1_rect);

                     SDL_RenderCopy(rend, paused_tex, NULL, &paused_rect);
                     SDL_RenderCopy(rend, playag_tex, NULL, &playag_rect);
                     SDL_RenderCopy(rend, quit_tex, NULL, &quit_rect);
                     SDL_RenderPresent(rend);
                     int mousex, mousey;
                     int positions = SDL_GetMouseState(&mousex, &mousey);

                     if(positions & SDL_BUTTON(SDL_BUTTON_LEFT))
                     {
                        if(mousex>=playag_rect.x && mousex<=(playag_rect.x+playag_rect.w) && mousey>=playag_rect.y && mousey<=(playag_rect.y+playag_rect.h))
                        {
                           pause = 0;

                        }
                        else if(mousex>=quit_rect.x && mousex<=(quit_rect.x+quit_rect.w) && mousey>=quit_rect.y && mousey<=(quit_rect.y+quit_rect.h))
                           over=1;
                        
                    }
                }

        }

        free(tex96);
        free(tex);
        free(bc_tex);
        free(wall_tex);
        free(wall2_tex);
        free(wall3_tex);
        free(wall4_tex);
        free(paused_tex);
        free(playag_tex);
        free(quit_tex);
        free(ghost1_tex);
        free(ghost2_tex);
        free(ghost3_tex);
        free(ghost4_tex);
        free(gameover_tex);
        free(target1_tex);
        free(overbg_tex);
        free(overbg1_tex);

        for(int i=0;i<=9;i=i+1)
        {
            free(digit_tex[i]);
        }
        SDL_Delay(200);
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        rend=NULL;
        win=NULL;



    }


        
    
        SDL_Quit();
        return 0;
}
