#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

class Key {
 public:
  Key();
  void drawOneKey(SDL_Renderer*);
  void colorKey(SDL_Renderer *);
  void setVals(int,int);
 private:
  const int keyWid = 60;
  const int keyLen = 450;
  int xpos;
  int ypos;
};

Key::Key(){
}

void Key::setVals(int xval, int yval){
	xpos=xval;
	ypos=yval;
}

void Key::drawOneKey(SDL_Renderer* gRenderer){
  SDL_Rect pianoKey = {xpos, ypos, keyWid, keyLen};
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 100, 100);
  SDL_RenderDrawRect(gRenderer, &pianoKey);
}

void Key::colorKey(SDL_Renderer* gRenderer){
  SDL_Rect color = {xpos, ypos, keyWid, keyLen};
  SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(gRenderer, &color);
}
