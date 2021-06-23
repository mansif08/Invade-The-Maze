#ifndef GIVENAME_H
#define GIVENAME_H
#include "object.h"
#include "rendertext.h"
#include "loading.h"
#include "continue.h"



void  givename(SDL_Renderer* grend,object& entername,TTF_Font *gFont,int& playgame,int& quit2,highscore hscore[],object& hero,object& bc,object& wall,object& wall2,object& wall3,object& wall4,object& pause,object& resume,object& playag,object& quit,object& ghost,object& ghost2,object& gameover,object& target,object& overbg,object digit[10],object& forest,object& river,object& oranget,object& greent,object& olivet,object& stone,object& treesin,object& score,object& overscore,object& title,object& levelcompleted,object& heart1,object& heart2,object& heart3,object& bonus,object& goback,object& mainmenu,object& gamecompleted)
{


            char  inputText[100] = "";
            //Main loop flag
            bool quitx = false;

            //Event handler
            SDL_Event e;

            //Set text color as brown
            SDL_Color textColor = {  133, 94, 66 };

            //The current input text.
            
            SDL_Texture* gInputTextTexture;
            gInputTextTexture=loadFromRenderedText( grend,inputText, textColor,gFont );

            //Enable text input
            SDL_StartTextInput();

            int i=0;

            

            //While application is running
            while( !quitx )
            {
                //The rerender text flag
                bool renderText = false;

                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quitx = true;
                        quit2=1;
                    }
                   
                    
                    //Special key input
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Handle backspace
                        if( e.key.keysym.sym == SDLK_BACKSPACE && i > 0 )
                        {
                            //lop off character
                            i--;
                            inputText[i]='\0';
                            renderText = true;
                        }
                        else if ( e.key.keysym.sym == SDLK_RETURN  )
                        {
                            //lop off character
                            quitx=1;
                        }
                        
                    }
                    //Special text input event
                    else if( e.type == SDL_TEXTINPUT && i<10 )
                    {

                         
                           strcat(inputText,e.text.text);
                           i++;
                           inputText[i] = '\0';
                           renderText = true;
                        

                     }
                    
                }

               // cout<<inputText<<endl;

                //Rerender text if needed
                if( renderText )
                {
                    //Text is not empty
                    if( i!=0 )
                    {
                        //Render new text
                        gInputTextTexture=loadFromRenderedText( grend,inputText, textColor,gFont );
                    }
                    //Text is empty
                    else
                    {
                        //Render space texture
                        gInputTextTexture=loadFromRenderedText(grend, " ", textColor,gFont );
                    }
                }

                //Clear screen
                SDL_SetRenderDrawColor( grend, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( grend );
                SDL_RenderCopy(grend, entername.tex, NULL, NULL);
 

                //Render text textures


                SDL_Rect Message_rect; //create a rect
                Message_rect.x = 500;  //controls the rect's x coordinate 
                Message_rect.y = 600; // controls the rect's y coordinte
                Message_rect.w = i*30; // controls the width of the rect
                Message_rect.h = 100; // controls the height of the rect
                SDL_RenderCopy(grend,gInputTextTexture, NULL, &Message_rect);


            /*    object cont;
                cont.tex=loadFromFile(grend,"continue3.png");
                setCont(cont);
                SDL_RenderCopy(grend,cont.tex, NULL, &cont.dest);

                checkcontinue(cont,quitx);

                //Update screen
                SDL_RenderPresent( grend );
                */
                SDL_RenderPresent( grend );


                if(quitx)
                {
                     inputText[i] = '\n';
                     i++;
                     inputText[i] = '\0';


                }
            }

            
            //Disable text input
             SDL_StopTextInput();

            
             if(quit2==0)//start main game 
             maingame( inputText,playgame,quit2, hscore, grend, hero, bc, wall,wall2, wall3, wall4, pause, resume, playag, quit, ghost, ghost2, gameover, target, overbg, digit, forest, river, oranget, greent,olivet, stone, treesin, score, overscore, title,levelcompleted, heart1,heart2, heart3, bonus,goback,mainmenu,gamecompleted);
     



    


}
#endif