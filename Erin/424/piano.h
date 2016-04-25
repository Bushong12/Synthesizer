#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "key.h"
#include "sharp.h"

class Piano{
 public:
  Piano();
  void drawKeys(SDL_Renderer *);
  void drawSharps(SDL_Renderer *);
  void drawWholePiano(SDL_Renderer *);
  void handleKeyPress(SDL_Renderer *, SDL_Event e);
 private:
  Sharp mySharps;
  Key myKeys;
};
