#ifndef COLLISION_H
#define COLLISION_H

#include "object.h"

void collision(int& gameovr,object& hero,object& ghost,object& ghost2,object& forest,object& river,object& oranget,object& greent ,object& olivet,object& stone,object& treesin,object& heart1,object& heart2,object& heart3,int& heartcount)
{

	//collision with the first ghost
	if(  ( (hero.dest.x+hero.dest.w>=ghost.dest.x  &&  hero.dest.x+hero.dest.w<=ghost.dest.x+ghost.dest.w  ) || (hero.dest.x>=ghost.dest.x && hero.dest.x<=ghost.dest.x+ghost.dest.w ))  && 
		( (hero.dest.y>=ghost.dest.y  &&  hero.dest.y<=ghost.dest.y+ ghost.dest.h)    ||    (hero.dest.y+hero.dest.h>=ghost.dest.y  &&  hero.dest.y+hero.dest.h<=ghost.dest.y+ ghost.dest.h) ) )
	{

        Mix_Chunk* spmusic=Mix_LoadWAV("../Audio/ghost.wav");
        Mix_PlayChannel(-1,spmusic,0);
		heartcount--;
		hero.x_pos=300;
		hero.y_pos=300;
		ghost.x_pos=500;
		ghost.y_pos=0;
		ghost2.x_pos=WINDOW_WIDTH-65;
		ghost2.y_pos=550;
			
			
	}

	//collision with the second ghost

	if(  ( (hero.dest.x+hero.dest.w>=ghost2.dest.x  &&  hero.dest.x+hero.dest.w<=ghost2.dest.x+ghost2.dest.w  ) || (hero.dest.x>=ghost2.dest.x && hero.dest.x<=ghost2.dest.x+ghost2.dest.w ))  && 
		( (hero.dest.y>=ghost2.dest.y  &&  hero.dest.y<=ghost2.dest.y+ ghost2.dest.h)    ||    (hero.dest.y+hero.dest.h>=ghost2.dest.y  &&  hero.dest.y+hero.dest.h<=ghost2.dest.y+ ghost2.dest.h) ) )
	{

        Mix_Chunk* spmusic=Mix_LoadWAV("../Audio/ghost.wav");
        Mix_PlayChannel(-1,spmusic,0);
		heartcount--;
		hero.x_pos=300;
		hero.y_pos=300;
		ghost.x_pos=500;
		ghost.y_pos=0;
		ghost2.x_pos=WINDOW_WIDTH-65;
		ghost2.y_pos=550;
			
			
	}

	//collision with forest


	if(  ( (hero.dest.x+hero.dest.w>=forest.dest.x  &&  hero.dest.x+hero.dest.w<=forest.dest.x+forest.dest.w  ) || (hero.dest.x>=forest.dest.x && hero.dest.x<=forest.dest.x+forest.dest.w ))  && 
		( (hero.dest.y>=forest.dest.y  &&  hero.dest.y<=forest.dest.y+ forest.dest.h)    ||    (hero.dest.y+hero.dest.h>=forest.dest.y  &&  hero.dest.y+hero.dest.h<=forest.dest.y+ forest.dest.h) ) )
	{
		Mix_Chunk* colmusic=Mix_LoadWAV("../Audio/enemym.wav");
        Mix_PlayChannel(-1,colmusic,0);

		heartcount--;
		hero.x_pos=300;
		hero.y_pos=300;
		ghost.x_pos=500;
		ghost.y_pos=0;
		ghost2.x_pos=WINDOW_WIDTH-65;
		ghost2.y_pos=550;
			
		
	}

	//collision with river

	if(  ( (hero.dest.x+hero.dest.w>=river.dest.x  &&  hero.dest.x+hero.dest.w<=river.dest.x+river.dest.w  ) || (hero.dest.x>=river.dest.x && hero.dest.x<=river.dest.x+river.dest.w ))  && 
		( (hero.dest.y>=river.dest.y  &&  hero.dest.y<=river.dest.y+ river.dest.h)    ||    (hero.dest.y+hero.dest.h>=river.dest.y  &&  hero.dest.y+hero.dest.h<=river.dest.y+ river.dest.h) ) )
	{

         Mix_Chunk* spmusic=Mix_LoadWAV("../Audio/splash.wav");
         Mix_PlayChannel(-1,spmusic,0);

		heartcount--;
		hero.x_pos=300;
		hero.y_pos=300;
		ghost.x_pos=500;
		ghost.y_pos=0;
		ghost2.x_pos=WINDOW_WIDTH-65;
		ghost2.y_pos=550;
		
		
	}

	//collision with oranget


	if(  ( (hero.dest.x+hero.dest.w>=oranget.dest.x  &&  hero.dest.x+hero.dest.w<=oranget.dest.x+oranget.dest.w  ) || (hero.dest.x>=oranget.dest.x && hero.dest.x<=oranget.dest.x+oranget.dest.w ))  && 
		( (hero.dest.y>=oranget.dest.y  &&  hero.dest.y<=oranget.dest.y+ oranget.dest.h)    ||    (hero.dest.y+hero.dest.h>=oranget.dest.y  &&  hero.dest.y+hero.dest.h<=oranget.dest.y+ oranget.dest.h) ) )
	{
		Mix_Chunk* colmusic=Mix_LoadWAV("../Audio/enemym.wav");
        Mix_PlayChannel(-1,colmusic,0);

		heartcount--;
		hero.x_pos=300;
		hero.y_pos=300;
		ghost.x_pos=500;
		ghost.y_pos=0;
		ghost2.x_pos=WINDOW_WIDTH-65;
		ghost2.y_pos=550;
		
		
	}

	//collision with greent

	if(  ( (hero.dest.x+hero.dest.w>=greent.dest.x  &&  hero.dest.x+hero.dest.w<=greent.dest.x+greent.dest.w  ) || (hero.dest.x>=greent.dest.x && hero.dest.x<=greent.dest.x+greent.dest.w ))  && 
		( (hero.dest.y>=greent.dest.y  &&  hero.dest.y<=greent.dest.y+ greent.dest.h)    ||    (hero.dest.y+hero.dest.h>=greent.dest.y  &&  hero.dest.y+hero.dest.h<=greent.dest.y+ greent.dest.h) ) )
	{
		Mix_Chunk* colmusic=Mix_LoadWAV("../Audio/enemym.wav");
        Mix_PlayChannel(-1,colmusic,0);

		heartcount--;
		hero.x_pos=300;
		hero.y_pos=300;
		ghost.x_pos=500;
		ghost.y_pos=0;
		ghost2.x_pos=WINDOW_WIDTH-65;
		ghost2.y_pos=550;
		
		
	}

	//collision with olivet

	if(  ( (hero.dest.x+hero.dest.w>=olivet.dest.x  &&  hero.dest.x+hero.dest.w<=olivet.dest.x+olivet.dest.w  ) || (hero.dest.x>=olivet.dest.x && hero.dest.x<=olivet.dest.x+olivet.dest.w ))  && 
		( (hero.dest.y>=olivet.dest.y  &&  hero.dest.y<=olivet.dest.y+ olivet.dest.h)    ||    (hero.dest.y+hero.dest.h>=olivet.dest.y  &&  hero.dest.y+hero.dest.h<=olivet.dest.y+ olivet.dest.h) ) )
	{
		Mix_Chunk* colmusic=Mix_LoadWAV("../Audio/enemym.wav");
        Mix_PlayChannel(-1,colmusic,0);

		heartcount--;
		hero.x_pos=300;
		hero.y_pos=300;
		ghost.x_pos=500;
		ghost.y_pos=0;
		ghost2.x_pos=WINDOW_WIDTH-65;
		ghost2.y_pos=550;
		
		
	}
    //collision with stone

	if(  ( (hero.dest.x+hero.dest.w>=stone.dest.x  &&  hero.dest.x+hero.dest.w<=stone.dest.x+stone.dest.w  ) || (hero.dest.x>=stone.dest.x && hero.dest.x<=stone.dest.x+stone.dest.w ))  && 
		( (hero.dest.y>=stone.dest.y  &&  hero.dest.y<=stone.dest.y+ stone.dest.h)    ||    (hero.dest.y+hero.dest.h>=stone.dest.y  &&  hero.dest.y+hero.dest.h<=stone.dest.y+ stone.dest.h) ) )
	{
		Mix_Chunk* colmusic=Mix_LoadWAV("../Audio/enemym.wav");
        Mix_PlayChannel(-1,colmusic,0);

		heartcount--;
		hero.x_pos=300;
		hero.y_pos=300;
		ghost.x_pos=500;
		ghost.y_pos=0;
		ghost2.x_pos=WINDOW_WIDTH-65;
		ghost2.y_pos=550;
		
	}

	//collision with treesin

	
	if(  ( (hero.dest.x+hero.dest.w>=treesin.dest.x  &&  hero.dest.x+hero.dest.w<=treesin.dest.x+treesin.dest.w  ) || (hero.dest.x>=treesin.dest.x && hero.dest.x<=treesin.dest.x+treesin.dest.w ))  && 
		( (hero.dest.y>=treesin.dest.y  &&  hero.dest.y<=treesin.dest.y+ treesin.dest.h)    ||    (hero.dest.y+hero.dest.h>=treesin.dest.y  &&  hero.dest.y+hero.dest.h<=treesin.dest.y+ treesin.dest.h) ) )
	{
		Mix_Chunk* colmusic=Mix_LoadWAV("../Audio/enemym.wav");
        Mix_PlayChannel(-1,colmusic,0);


		heartcount--;
		hero.x_pos=300;
		hero.y_pos=300;
		ghost.x_pos=500;
		ghost.y_pos=0;
		ghost2.x_pos=WINDOW_WIDTH-65;
		ghost2.y_pos=550;
		
		
	}


	


}
#endif