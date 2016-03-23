/* Caroline Braun, lab 8
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

// size of screen
const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 375;

// initializes SDL, creates window
bool init();

// closes SDL
void close();

// window we will render to
SDL_Window* gWindow = NULL;

// window renderer
SDL_Renderer* gRenderer = NULL;

// surface contained by the window
SDL_Surface* screenSurface = NULL;

bool init(){
	bool success = true;

	// initializes SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		// sets texture filtering
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}

		// creates the window
		gWindow = SDL_CreateWindow("Button Press", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL){
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success - false;
		}
		else {
			// creates renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				// initializes color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}
	return success;
}

void close()
{
	// close window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	// quit SDL
	SDL_Quit();
}

int main(int argc, char* args[]) {
	if (!init()) {
		printf("Failed to initilize!\n");
	}
	else {

		bool quit = false;
		SDL_Event e; //event handler

		while (!quit) {
			// handles events on queue
			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					quit = true;
				}
				printf("HERE");
				//mouse event
				if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP){
					printf("TRYING");
					// change color of screen
					SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 96, 96, 96));

					// updates surface
					SDL_UpdateWindowSurface(gWindow);
				}

			}

			//clears screen
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xff, 0xFF);
			SDL_RenderClear(gRenderer);

			// updates
			SDL_RenderPresent(gRenderer);
		}
	}
	// closes SDL
	close();
	return 0;
}
