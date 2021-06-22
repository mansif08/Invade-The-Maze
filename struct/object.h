#ifndef MYSTRUCT_H
#define MYSTRUCT_H


//preprocessor directives

 #define WINDOW_WIDTH (1280)
 #define WINDOW_HEIGHT (960)
 #define MAZE_WIDTH (1230)
 #define MAZE_HEIGHT (910)
 #define SCROLL_SPEED (850)
 #define RECT_SPEED (5.0)
 #define GHOST_SPEED (120)
 #define GHOST_SPEED2 (60) 
 #define TARGET_SPEED (400)


//new datatype object and highscore
struct object
{
    SDL_Texture* tex;
    SDL_Rect dest;
    float x_pos=50;
    float y_pos=50;
    int direction=1;
    int px1,px2,py1,py2;
    SDL_Rect over_rect;
    SDL_Rect over_rect2;
    SDL_Rect show_rect;
    SDL_Rect show_rect2;

    int time;
    bool flag=0;
    bool vis5=0,vis15=0,vis25=0,vis35=0,vis45=0,vis55=0,vis65=0,vis75=0,vis85=0;


    
};

struct highscore
{
    char name[50];
    int score;


};


    void free(SDL_Texture* tex)
    {
    //Free texture if it exists
        if( tex!= NULL )
       {
           SDL_DestroyTexture( tex);
            tex = NULL;
       }
    }


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


#endif
