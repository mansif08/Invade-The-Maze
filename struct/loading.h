
#ifndef LOADING_H
#define LOADING_H
    SDL_Texture* loadFromFile( SDL_Renderer* grend,std::string path) 
    {
        
        SDL_Texture* newTexture = NULL;
        SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
        if( loadedSurface == NULL )
        {
           printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
       }
       else
       {
           newTexture =SDL_CreateTextureFromSurface(grend,loadedSurface);
           
           SDL_FreeSurface( loadedSurface );
       }

       return newTexture;
   }
   
#endif