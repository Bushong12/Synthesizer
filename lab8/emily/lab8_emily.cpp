//Emily Park CSE20212 lab8 lab.cpp
//deliverable for lab8
//image will change upon pressing different buttons and when left click is pressed
//image goes back to default image when buton is released or when left click is released
//window will close when you press esc key
//(might be slow though)

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
using namespace std;

enum KeyPress{
	keyDEFAULT,
	keyUP,
	keyDOWN,
	keyLEFT,
	keyRIGHT,
	keyTOTAL,
	mouseDOWN
};

//screen dimensions
int width=800;
int height=800;

bool init();			//start SDL
bool loadMedia();		//load images
void close();			//close window
SDL_Surface* loadSurface(string path);		//load image
SDL_Window* gWindow=NULL;			//window we render to
SDL_Surface* gScreenSurface=NULL;		//surface contained by window
SDL_Surface* gKeyPressSurfaces[keyTOTAL];	//image corresponding to arrow press
SDL_Surface* gCurrentSurface=NULL;		//currently displayed image

bool init(){
	bool success=true;

	if( SDL_Init(SDL_INIT_VIDEO) < 0 ){
		cout << "SDL could not initialize; Error: " << SDL_GetError() << endl;
		success=false;
	}
	else{
		gWindow = SDL_CreateWindow( "lab", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if(gWindow==NULL){
			cout << "Window could not be created; Error: " << SDL_GetError() << endl;
			success=false;
		}
		else{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia(){
	bool success=true;

	//default picture
	gKeyPressSurfaces[keyDEFAULT] = loadSurface("default.png");
	if(gKeyPressSurfaces == NULL){
		cout << "Failed to load default image" << endl;
		success=false;
	}

	//image depending on arrow press
	gKeyPressSurfaces[keyUP] = loadSurface("up.png");
	if(gKeyPressSurfaces == NULL){
		cout << "Failed to load up image" << endl;
		success=false;
	}

	gKeyPressSurfaces[keyDOWN] = loadSurface("down.png");
	if(gKeyPressSurfaces[keyDOWN] == NULL){
		cout << "Failed to load down image" << endl;
		success=false;
	}

	gKeyPressSurfaces[keyLEFT] = loadSurface("left.png");
	if(gKeyPressSurfaces[keyLEFT] == NULL){
		cout << "Failed to load left image" << endl;
		success=false;
	}

	gKeyPressSurfaces[keyRIGHT] = loadSurface("right.png");
	if(gKeyPressSurfaces[keyRIGHT] == NULL){
		cout << "Failed to load right image" << endl;
		success=false;
	}

	gKeyPressSurfaces[mouseDOWN] = loadSurface("click.png");
	if(gKeyPressSurfaces[mouseDOWN] == NULL){
		cout << "Failed to load click image" << endl;
		success=false;
	}

	return success;
}

void close(){
	for(int i=0; i<keyTOTAL; ++i){
		SDL_FreeSurface(gKeyPressSurfaces[i]);
		gKeyPressSurfaces[i] = NULL;
	}

	//get rid of window
	SDL_DestroyWindow(gWindow);
	gWindow=NULL;

	SDL_Quit();
}

SDL_Surface* loadSurface( string path ){
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if(loadedSurface==NULL){
		cout << "Unable to load image " << path << "! Error: " << SDL_GetError() << endl;
	}

	return loadedSurface;
}

//main//
int main( int argc, char* args[] ){
	if( !init() ){
		cout << "Failed to initialize" << endl;
	}
	else{
		if( !loadMedia() ){
			cout << "Failed to load media" << endl;
		}
		else{
			bool quit = false;
			SDL_Event e;
			gCurrentSurface = gKeyPressSurfaces[keyDEFAULT];

			while(!quit){
				while(SDL_PollEvent(&e)!=0){
					if(e.type==SDL_KEYDOWN || e.type==SDL_MOUSEBUTTONUP){
						switch ( e.key.keysym.sym ){
							case SDLK_ESCAPE:
								quit=true;
								break;
							case SDLK_w:
								gCurrentSurface=gKeyPressSurfaces[keyUP];
								break;
							case SDLK_s:
								gCurrentSurface=gKeyPressSurfaces[keyDOWN];
								break;
							case SDLK_a:
								gCurrentSurface=gKeyPressSurfaces[keyLEFT];
								break;
							case SDLK_d:
								gCurrentSurface=gKeyPressSurfaces[keyRIGHT];
								break;
							default:
								gCurrentSurface=gKeyPressSurfaces[keyDEFAULT];
								break;
						}	//end case
					}		//end if(e.type==SDL_KEYDOWN)
					else if(e.type==SDL_KEYUP){
						gCurrentSurface=gKeyPressSurfaces[keyDEFAULT];
					}
					else if(e.type==SDL_MOUSEBUTTONDOWN){
						gCurrentSurface=gKeyPressSurfaces[mouseDOWN];
					}
				}			//end inner while

				SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
				SDL_UpdateWindowSurface(gWindow);
			}
		}	//end else(loadMedia())
	}		//end else(init())
}			//end main
