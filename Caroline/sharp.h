#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

class Sharp {
 public:
  Sharp();
  void drawOneSharp(SDL_Renderer*);
  void colorSharp(SDL_Renderer *);
  void setVals(int,int);
 private:
  const int sharpWid = 30;
  const int sharpLen = 281;
  int xpos;
  int ypos;
};

Sharp::Sharp(){
}

void Sharp::setVals(int xval, int yval){
	xpos=xval;
	ypos=yval;
}

void Sharp::drawOneSharp(SDL_Renderer* gRenderer){
  SDL_Rect sharpKey = {xpos, ypos, sharpWid, sharpLen};
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 100, 100);
  SDL_RenderFillRect(gRenderer, &sharpKey);
}

void Sharp::colorSharp(SDL_Renderer* gRenderer){
  SDL_Rect color = {xpos, ypos, sharpWid, sharpLen};
  SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(gRenderer, &color);
}
