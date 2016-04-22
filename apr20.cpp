/* The piano that lights up when keys are pressed
the white keys are the keys 'a'-';' on the keyboard and the black keys are 'w','e', 't','y','u','o',and 'p'

 */
/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
  and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Screen dimension constants
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 500;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

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
      //Set texture filtering to linear
      if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	{
	  printf( "Warning: Linear texture filtering not enabled!" );
	}

      //Create window
      gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
      if( gWindow == NULL )
	{
	  printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
	  success = false;
	}
      else
	{
	  //Create renderer for window
	  gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
	  if( gRenderer == NULL )
	    {
	      printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
	      success = false;
	    }
	  else
	    {
	      //Initialize renderer color
	      SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

	      //Initialize PNG loading
	      int imgFlags = IMG_INIT_PNG;
	      if( !( IMG_Init( imgFlags ) & imgFlags ) )
		{
		  printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		  success = false;
		}
	    }
	}
    }

  return success;
}

bool loadMedia()
{
  //Loading success flag
  bool success = true;

  //Nothing to load
  return success;
}

void close()
{
  //Destroy window
  SDL_DestroyRenderer( gRenderer );
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  gRenderer = NULL;

  //Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

SDL_Texture* loadTexture( std::string path ){
  //The final texture
  SDL_Texture* newTexture = NULL;
  //Load image at specified path
  SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
  if( loadedSurface == NULL ){
    printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
  }
  else{
    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
    if( newTexture == NULL )
      {
	printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
      }

    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );
  }

  return newTexture;
}
void drawSharps(){
	  SDL_Rect sharp1= { 75,30, 30, 281};                                                                                              
  SDL_Rect sharp2= { 135, 30, 30, 281};                                                                                            
  SDL_Rect sharp3= { 255, 30, 30, 281};                                                                                            
  SDL_Rect sharp4 = { 315, 30, 30, 281};                                                                                           
  SDL_Rect sharp5 = { 375, 30, 30, 281};                                                                                           
  SDL_Rect sharp6 = { 495, 30, 30, 281};
  SDL_Rect sharp7 = { 555, 30, 30, 281};                                                                                           
  SDL_SetRenderDrawColor( gRenderer, 0, 0, 100, 100);                                                                              
  SDL_RenderFillRect (gRenderer, &sharp1);                                                                                         
  SDL_RenderFillRect (gRenderer, &sharp2);                                                                                         
  SDL_RenderFillRect (gRenderer, &sharp3);                                                                                         
  SDL_RenderFillRect (gRenderer, &sharp4);                                                                                         
  SDL_RenderFillRect (gRenderer, &sharp5);
  SDL_RenderFillRect (gRenderer, &sharp6);
  SDL_RenderFillRect (gRenderer, &sharp7);
}
void drawKeys(){
	 SDL_Rect rect1 = { 30, 30, 60, 450};                                                                                             
  SDL_Rect rect2 = { 150, 30, 60, 450};                                                                                            
  SDL_Rect rect3 = { 270, 30, 60, 450};                                                                                            
  SDL_Rect rect4 = { 390, 30, 60, 450};                                                                                            
  SDL_Rect rect5 = { 510, 30, 60, 450};                                                                                            
  SDL_SetRenderDrawColor( gRenderer, 0, 0, 100, 100 );                                                                             
                                                                                                                                                                                                                                                 
  SDL_RenderDrawRect( gRenderer, &rect1 );                                                                                         
  SDL_RenderDrawRect( gRenderer, &rect2 );                                                                                         
  SDL_RenderDrawRect( gRenderer, &rect3 );                                                                                         
  SDL_RenderDrawRect( gRenderer, &rect4 );                                                                                         
  SDL_RenderDrawRect( gRenderer, &rect5 );       
}
void drawPiano(){
	SDL_Rect screenRect = {0,0,700,500};
	SDL_SetRenderDrawColor ( gRenderer,255,255,255,255);
	SDL_RenderFillRect ( gRenderer, &screenRect);
	
  SDL_Rect outlineRect = { 30, 30, 600, 450 }; //left x coord, left y coord, width, height        
	SDL_SetRenderDrawColor( gRenderer, 0, 0, 100, 100 );                                                                             
                                                                                                                                                                 
  SDL_RenderDrawRect( gRenderer, &outlineRect );                                
 drawKeys();                                                                                  
                                                                                                                                                                 
 drawSharps();
}


//doesn't work
void highlightPiano(int letter){
  if(letter == 1){
    SDL_Rect colorA = { 30, 30, 60, 450 };
    SDL_SetRenderDrawColor (gRenderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect (gRenderer, &colorA);

	drawSharps();
  /*  SDL_Rect sharp1 = {75, 30, 30, 281};
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 100, 100);
    SDL_RenderFillRect (gRenderer, &sharp1);*/
  }
  else if (letter == 2){
	SDL_Rect colorS = {90,30,60,450};
	SDL_SetRenderDrawColor (gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer, &colorS);
	drawSharps();
}
	else if (letter==3){
	SDL_Rect colorD = {150,30,60,450};
	SDL_SetRenderDrawColor (gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer, &colorD);
	drawSharps();
	}
	else if (letter==4){
	SDL_Rect colorF = {210,30,60,450};
	SDL_SetRenderDrawColor (gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer, &colorF);
	drawSharps();
	}
	else if (letter==5){
	SDL_Rect colorG = {270,30,60,450};
	SDL_SetRenderDrawColor (gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer, &colorG);
	drawSharps();
	}
	else if (letter==6){
	SDL_Rect colorH = {330,30,60,450};
	SDL_SetRenderDrawColor (gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer, &colorH);
	drawSharps();
	}
	else if (letter==7){
	SDL_Rect colorJ = {390,30,60,450};
	SDL_SetRenderDrawColor (gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer, &colorJ);
	drawSharps();
	}
	else if (letter==8){
	SDL_Rect colorK = {450,30,60,450};
	SDL_SetRenderDrawColor (gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer, &colorK);
	drawSharps();
	}
	else if (letter==9){
	SDL_Rect colorL = {510,30,60,450};
	SDL_SetRenderDrawColor (gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer, &colorL);
	drawSharps();
	}
	else if (letter==10){
	SDL_Rect colorM = {570,30,60,450};
	SDL_SetRenderDrawColor (gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer, &colorM);
	drawSharps();
	}
	else if (letter==11){
	drawKeys();
	SDL_Rect colorW = {75,30,30,281};
	SDL_SetRenderDrawColor(gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer,&colorW);
	}
	else if (letter==12){
	drawKeys();
	SDL_Rect colorE = {135,30,30,281};
	SDL_SetRenderDrawColor(gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer,&colorE);
	}
	else if (letter==13){
	drawKeys();
	SDL_Rect colorT = {255,30,30,281};
	SDL_SetRenderDrawColor(gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer,&colorT);
	}
	else if (letter==14){
	drawKeys();
	SDL_Rect colorY = {315,30,30,281};
	SDL_SetRenderDrawColor(gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer,&colorY);
	}
	else if (letter==15){
	drawKeys();
	SDL_Rect colorU = {375,30,30,281};
	SDL_SetRenderDrawColor(gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer,&colorU);
	}
	else if (letter==16){
	drawKeys();
	SDL_Rect colorO = {495,30,30,281};
	SDL_SetRenderDrawColor(gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer,&colorO);
	}
	else if (letter==17){
	drawKeys();
	SDL_Rect colorP = {555,30,30,281};
	SDL_SetRenderDrawColor(gRenderer,0xFF,0x00,0x00,0xFF);
	SDL_RenderFillRect(gRenderer,&colorP);
	}

	
}

int main( int argc, char* args[] ){
  //Start up SDL and create window
  if( !init() ){
    printf( "Failed to initialize!\n" );
  }
  else{
    //Load media
    if( !loadMedia() ){
      printf( "Failed to load media!\n" );
    }
    else{
      //Main loop flag
      bool quit = false;

      //Event handler
      SDL_Event e;

      int whichKey;

      //While application is running
      while( !quit )
	{
	  //Handle events on queue
	  if( SDL_PollEvent( &e )){
	    //User requests quit
	    if( e.type == SDL_QUIT || (e.key.keysym.sym==SDLK_q)){
	      quit = true;
	    }
	  }
	  //Clear screen
	  
	  SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 255);
	  SDL_RenderClear( gRenderer );
	  
	  drawPiano();
		int value=0;
	//int val=e.key.keysym.sym;
	//  switch(e.key.keysym.sym){
	if (e.type == SDL_KEYDOWN)
	//	SDLKEY keyPressed = e.key.keysym.sym;

		switch(e.key.keysym.sym){
	  		case 'a':
				value=1;
				break;
	  		case 's':
				value=2;
				break;
			case 'd':
				value=3;
				break;
			case 'f':
				value=4;
				break;
			case 'g':
				value=5;
				break;
			case 'h':
				value=6;
				break;
			case 'j':
				value=7;
				break;
			case 'k':
				value=8;
				break;
			case 'l':
				value=9;
				break;
			case ';':
				value=10;
				break;
			case 'w':
				value=11;
				break;
			case 'e':
				value=12;
				break;
			case 't':
				value=13;
				break;
			case 'y':
				value=14;
				break;
			case 'u':
				value=15;
				break;
			case 'o':
				value=16;
				break;
			case 'p':
				value=17;
				break;
	  }
		if(value != 0){
			highlightPiano(value);
			SDL_RenderPresent(gRenderer);
			SDL_Delay(500);
		}
	  SDL_RenderPresent(gRenderer);
	  drawPiano();
	}
    }
  }

  //Free resources and close SDL
  close();

  return 0;
}

