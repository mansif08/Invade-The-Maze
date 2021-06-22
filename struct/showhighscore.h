#ifndef SHOWHIGHSCORE_H
#define SHOWHIGHSCORE_H


#include "object.h"
#include "checkgoback.h"


void showhighscore(SDL_Renderer* grend,object& goback,int& quit,int& watchscore,highscore hscore[5],TTF_Font *gFont)
{

    SDL_Texture* Message;
    SDL_Texture* newTexture;

    int enter=0;

    //printf("%d\n",hscore[4].score);




    //checking if the user goes back
	while(watchscore)
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
       	  {
       		  switch(event.type)
       		  {
       			case SDL_QUIT:
       			quit = 1;
       			
                watchscore=0;
               

       			break;

       		   }
       	   }

       if(enter==0)
       {
            enter++;

		SDL_RenderClear(grend);

		newTexture = NULL;
		SDL_Surface* loadedSurface = IMG_Load("../Images/highscores3.png");
		newTexture =SDL_CreateTextureFromSurface(grend,loadedSurface);
		SDL_RenderCopy(grend, newTexture, NULL, NULL);
		SDL_FreeSurface( loadedSurface );


		
        //storing the names of the chart

        char first[100];
        int flength=0;
		char second[100];
        int slength=0;
		char third[100];
        int tlength=0;
        char four[100];
        int fourlength=0;
        char five[100];
        int fivelength=0;
        
        


        int i;


		for(i=0;hscore[0].name[i]!='\n';i++)
		{
			first[i]=hscore[0].name[i];
            flength++;

		}

		first[i]='\0';


		for(i=0;hscore[1].name[i]!='\n';i++)
		{
			second[i]=hscore[1].name[i];
            slength++;

		}
        
		second[i]='\0';


		for(i=0;hscore[2].name[i]!='\n';i++)
		{
			third[i]=hscore[2].name[i];
            tlength++;

		}

		third[i]='\0';

        for(i=0;hscore[3].name[i]!='\n';i++)
        {
            four[i]=hscore[3].name[i];
            fourlength++;

        }

        four[i]='\0';

        for(i=0;hscore[4].name[i]!='\n';i++)
        {
            five[i]=hscore[4].name[i];
            fivelength++;

        }
        
        five[i]='\0';


        //displaying the name



		SDL_Color White = { 133, 94, 66};
		SDL_Surface* surfaceMessage =TTF_RenderUTF8_Blended(gFont,first, White); 
		Message = SDL_CreateTextureFromSurface(grend, surfaceMessage);
		SDL_FreeSurface( surfaceMessage );
        SDL_Rect Message_rect; //create a rect
        Message_rect.x = 400;  //controls the rect's x coordinate 
        Message_rect.y = 300; // controls the rect's y coordinte
        Message_rect.w = flength*30; // controls the width of the rect
        Message_rect.h = 90; // controls the height of the rect
        SDL_RenderCopy(grend, Message, NULL, &Message_rect);




        surfaceMessage =TTF_RenderUTF8_Blended(gFont,second, White); 
        Message = SDL_CreateTextureFromSurface(grend, surfaceMessage);
        SDL_FreeSurface( surfaceMessage );
        Message_rect.x = 400;  //controls the rect's x coordinate 
        Message_rect.y = 420; // controls the rect's y coordinte
        Message_rect.w = slength*30; // controls the width of the rect
        Message_rect.h = 90; // controls the height of the rect
        SDL_RenderCopy(grend, Message, NULL, &Message_rect);





        surfaceMessage =	TTF_RenderUTF8_Blended(gFont,third, White); 
        Message = SDL_CreateTextureFromSurface(grend, surfaceMessage);
        SDL_FreeSurface( surfaceMessage );
        Message_rect.x = 400;  //controls the rect's x coordinate 
        Message_rect.y = 540; // controls the rect's y coordinte
        Message_rect.w = tlength*30; // controls the width of the rect
        Message_rect.h = 90; // controls the height of the rect
        SDL_RenderCopy(grend, Message, NULL, &Message_rect);

        


        surfaceMessage =    TTF_RenderUTF8_Blended(gFont,four, White); 
        Message = SDL_CreateTextureFromSurface(grend, surfaceMessage);
        SDL_FreeSurface( surfaceMessage );
        Message_rect.x = 400;  //controls the rect's x coordinate 
        Message_rect.y = 660; // controls the rect's y coordinte
        Message_rect.w = fourlength*30; // controls the width of the rect
        Message_rect.h = 90; // controls the height of the rect
        SDL_RenderCopy(grend, Message, NULL, &Message_rect);


        

        surfaceMessage =    TTF_RenderUTF8_Blended(gFont,five, White); 
        Message = SDL_CreateTextureFromSurface(grend, surfaceMessage);
        SDL_FreeSurface( surfaceMessage );
        Message_rect.x = 400;  //controls the rect's x coordinate 
        Message_rect.y = 780; // controls the rect's y coordinte
        Message_rect.w = fivelength*30; // controls the width of the rect
        Message_rect.h = 90; // controls the height of the rect
        SDL_RenderCopy(grend, Message, NULL, &Message_rect);







        int lnum1;
        int lnum2;
        int lnum3;
        int lnum4;
        int lnum5;

        if(hscore[0].score<10)
        {
            lnum1=1;

        }
        else
        {
            lnum1=2;

        }

        if(hscore[1].score<10)
        {
            lnum2=1;

        }
        else
        {
            lnum2=2;

        }

        if(hscore[2].score<10)
        {
            lnum3=1;

        }
        else
        {
            lnum3=2;

        }

        if(hscore[3].score<10)
        {
            lnum4=1;

        }
        else
        {
            lnum4=2;

        }
        if(hscore[4].score<10)
        {
            lnum5=1;

        }
        else
        {
            lnum5=2;

        }

     
        char snum1[5];
        char snum2[5];
        char snum3[5];
        char snum4[5];
        char snum5[5];
        
        

        //displaying the name
        sprintf(snum1, "%d", hscore[0].score);
        sprintf(snum2, "%d", hscore[1].score);
        sprintf(snum3, "%d", hscore[2].score);
        sprintf(snum4, "%d", hscore[3].score);
        sprintf(snum5, "%d", hscore[4].score);


        surfaceMessage =	TTF_RenderUTF8_Blended(gFont,snum1, White); 
        Message = SDL_CreateTextureFromSurface(grend, surfaceMessage);
        SDL_FreeSurface( surfaceMessage );
    
        Message_rect.x = 800;  //controls the rect's x coordinate 
        Message_rect.y = 300; // controls the rect's y coordinte
        Message_rect.w = lnum1*45; // controls the width of the rect
        Message_rect.h = 90; // controls the height of the rect
        SDL_RenderCopy(grend, Message, NULL, &Message_rect);

        surfaceMessage =	TTF_RenderUTF8_Blended(gFont,snum2, White); 
        Message = SDL_CreateTextureFromSurface(grend, surfaceMessage);
        SDL_FreeSurface( surfaceMessage );
    
        Message_rect.x = 800;  //controls the rect's x coordinate 
        Message_rect.y = 420; // controls the rect's y coordinte
        Message_rect.w = lnum2*45; // controls the width of the rect
        Message_rect.h = 90; // controls the height of the rect
        SDL_RenderCopy(grend, Message, NULL, &Message_rect);

        surfaceMessage =	TTF_RenderUTF8_Blended(gFont,snum3, White); 
        Message = SDL_CreateTextureFromSurface(grend, surfaceMessage);
        SDL_FreeSurface( surfaceMessage );
    
        Message_rect.x = 800;  //controls the rect's x coordinate 
        Message_rect.y = 540; // controls the rect's y coordinte
        Message_rect.w = lnum3*45; // controls the width of the rect
        Message_rect.h = 90; // controls the height of the rect
        SDL_RenderCopy(grend, Message, NULL, &Message_rect);

        surfaceMessage =    TTF_RenderUTF8_Blended(gFont,snum4, White); 
        Message = SDL_CreateTextureFromSurface(grend, surfaceMessage);
        SDL_FreeSurface( surfaceMessage );
    
        Message_rect.x = 800;  //controls the rect's x coordinate 
        Message_rect.y = 660; // controls the rect's y coordinte
        Message_rect.w = lnum4*45; // controls the width of the rect
        Message_rect.h = 90; // controls the height of the rect
        SDL_RenderCopy(grend, Message, NULL, &Message_rect);

        surfaceMessage =    TTF_RenderUTF8_Blended(gFont,snum5, White); 
        Message = SDL_CreateTextureFromSurface(grend, surfaceMessage);
        SDL_FreeSurface( surfaceMessage );
    
        Message_rect.x = 800;  //controls the rect's x coordinate 
        Message_rect.y = 780; // controls the rect's y coordinte
        Message_rect.w = lnum5*45; // controls the width of the rect
        Message_rect.h = 90; // controls the height of the rect
        SDL_RenderCopy(grend, Message, NULL, &Message_rect);




        SDL_RenderCopy(grend, goback.tex, NULL, &goback.dest);

        


        SDL_RenderPresent(grend);
     }


     checkgoback( goback, watchscore);


   }


     newTexture=NULL;
     Message=NULL;



}
#endif