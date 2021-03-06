#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "piano.h"

using namespace stk;
//Screen dimension constants                                                        \
                                                                                     
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 500;

//Starts up SDL and creates window                                                  \
                                                                                     
bool init();

//Loads media                                                                       \
                                                                                     
bool loadMedia();

//Frees media and shuts down SDL                                                    \
                                                                                     
void close();

//Loads individual image as texture                                                 \
                                                                                     
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to                                                  \
                                                                                     
SDL_Window* gWindow = NULL;

//The window renderer                                                               \
                                                                                     
SDL_Renderer* gRenderer = NULL;

bool init(){
  //Initialization flag                                                             \
                                                                                     
  bool success = true;

  //Initialize SDL                                                                  \
                                                                                     
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
    printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    success = false;
  }
  else{
    //Set texture filtering to linear     
                                                                                        
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
      printf( "Warning: Linear texture filtering not enabled!" );
    }
    //Create window                                                                 \
                                                                                     
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWP\
OS_UNDEFINED\
                                , SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL ){
      printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
      success = false;
    }
    else{
      //Create renderer for window                                                  \
                                                                                     
      gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
      if( gRenderer == NULL ){
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        success = false;
      }
      else{
        //Initialize renderer color                                                 \
                                                                                     
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

        //Initialize PNG loading                                                    \
                                                                                     
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) ){
          printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetEr\
ror() \
                  );
          success = false;
        }
      }
    }
  }

  return success;
}

bool loadMedia(){
  //Loading success flag                                                            \
                                                                                     
  bool success = true;

  //Nothing to load     
  return success;
}

void close(){
  //Destroy window                                                                  \
                                                                                     
  SDL_DestroyRenderer( gRenderer );
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  gRenderer = NULL;

  //Quit SDL subsystems                                                             \
                                                                                     
  IMG_Quit();
  SDL_Quit();
}

SDL_Texture* loadTexture( std::string path ){
  //The final texture                                                               \
                                                                                     
  SDL_Texture* newTexture = NULL;
  //Load image at specified path                                                    \
                                                                                     
  SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
  if( loadedSurface == NULL ){
    printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetE\
rror() );
  }
  else{
    //Create texture from surface pixels                                            \
                                                                                     
    newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
    if( newTexture == NULL )
      {
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), S\
DL_GetError() \
                );
      }

    //Get rid of old loaded surface                                                 \
                                                                                     
    SDL_FreeSurface( loadedSurface );
  }

  return newTexture;
}

int main( int argc, char* args[] ){
  //Start up SDL and create window                                                  \
                                                                                     
  if( !init() ){
    printf( "Failed to initialize!\n" );
  }
  else{
    //Load media                                                                    \
                                                                                     
    if( !loadMedia() ){
      printf( "Failed to load media!\n" );
    }
    else{
      //Main loop flag                                                              \
                                                                                     
      bool quit = false;

      //Event handler                                                               \
                                                                                     
      SDL_Event e;

      int whichKey;
      Piano myPiano(gRenderer); //creates a piano object called myPiano

      //While application is running                                                \
                                                                                     
      int startTime = SDL_GetTicks();
      while( !quit )
        {
          //Handle events on queue                                                  \
                                                                                     
          if( SDL_PollEvent( &e )){
            //User requests quit                                                    \
                                                                                     
            if( e.type == SDL_QUIT || (e.key.keysym.sym==SDLK_q)){
              quit = true;
            }
          }
          //Clear screen                                                            \
                                                                                     

          SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 255);
          SDL_RenderClear( gRenderer );

          myPiano.drawWholePiano(gRenderer); //draws the entire Piano

          if(e.type == SDL_KEYDOWN){
            myPiano.handleKeyPress(gRenderer, e); //handles key press if a key is pressed down
          }
          int totalTime = SDL_GetTicks() - startTime;
          SDL_RenderPresent(gRenderer); //renders to screen
          myPiano.drawWholePiano(gRenderer); //draws the entire piano
        }
    }
  }
  close();
  return 0;
}
