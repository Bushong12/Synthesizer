#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Starts SDL and creates window
bool init();

// Shuts down SDl
void close();

// Window we'll render to
SDL_Window* gWindow = NULL;

// Window Renderer
SDL_Renderer* gRenderer = NULL;

// The surface contained by the window
SDL_Surface* screenSurface = NULL;

bool init(){
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		// Set texture filtering to linear
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("Button Press", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL){
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success - false;
		}
		else {
			// Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				// Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}
	return success;
}

void close()
{
	// Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	// Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[]) {

	// Start up SDL and create window
	if (!init()) {
		printf("Failed to initilize!\n");
	}
	else {

		// Main loop flag
		bool quit = false;

		// Event handler
		SDL_Event e;
		// While application is running
		while (!quit) {
			// Handle events on queue
			while (SDL_PollEvent(&e) != 0) {
				// User requests quit
				if (e.type == SDL_QUIT) {
					quit = true;
				}
				printf("HERE");
				// If mouse event happens
				if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP){
					printf("TRYING");
					// change color of screen
					SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 96, 96, 96));

					// Update the surface
					SDL_UpdateWindowSurface(gWindow);
				}

			}

			// Clear screen
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xff, 0xFF);
			SDL_RenderClear(gRenderer);

			// Update screen
			SDL_RenderPresent(gRenderer);
		}
	}
	// Free resources and close SDL
	close();
	return 0;
}
