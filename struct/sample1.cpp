    #include <iostream>
    using namespace std;
    
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_timer.h>
    #include <stdlib.h>
    #include<time.h>
    #include <stdio.h>

    #include "initialization.cpp"
    #include "loading.cpp"

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

    bool init();
    SDL_Window* win=NULL;
    SDL_Renderer* grend=NULL;

    bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
       
       win= SDL_CreateWindow("invade the maze",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,0);
        if( win == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            grend = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( grend == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            
        }
    }

    return success;
}


int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }


}


