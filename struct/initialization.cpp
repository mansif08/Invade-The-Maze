
 
/*
bool initialize(SDL_Window* win,SDL_Renderer* rend)
{
	bool success=true;

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)!=0)
        {
            printf("%s\n",SDL_GetError());
            success=false;
            return success;

        }

    else
    {

        if(!(IMG_Init(IMG_INIT_PNG)))
        {
            printf("%s\n",SDL_GetError());
            success=false;
            return success;
        }

        else 
        {

        	win= SDL_CreateWindow("invade the maze",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,0);

            if(!win)
            {
                printf("%s",SDL_GetError());
                success=false;
                return success;
                
            }

            else
            {

            	Uint32 render_flags= SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC;
            	rend=SDL_CreateRenderer(win,-1,render_flags);

            	if(!rend)
            	{

            		printf("%s\n",SDL_GetError());
            		success=false;
                    return success;
            		
            	}


            }




            return success;
        }

    



}
*/