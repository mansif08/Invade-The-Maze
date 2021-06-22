#ifndef RENDERTEXT_H
#define RENDERTEXT_H

SDL_Texture*  loadFromRenderedText(SDL_Renderer* grend,char* textureText, SDL_Color textColor,TTF_Font *gFont )
{
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText, textColor );
	if( textSurface != NULL )
	{
		//Create texture from surface pixels
        SDL_Texture* mTexture = SDL_CreateTextureFromSurface( grend, textSurface );

		//Get rid of old surface
		SDL_FreeSurface( textSurface );

	    return mTexture;

	
	
	   
	}



}





#endif