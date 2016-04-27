/*
header file containing the class definition and functions for the key class
*/

#ifndef key_H
#define key_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

class Key { //key class
 public:
  Key(); //default constructor
  void drawOneKey(SDL_Renderer*); //function draws one key
  void colorKey(SDL_Renderer *); //function colors one key
  void setVals(int,int); //function sets x position and y position of key
 private:
  const int keyWid = 60; //variable storing width of one key
  const int keyLen = 450; //variable storing length of one key
  int xpos; //variable storing x position of key
  int ypos; //variable storing y position of key
};

//default constructor
Key::Key(){
}

//function sets x position and y position of key
void Key::setVals(int xval, int yval){
	xpos=xval;
	ypos=yval;
}

//function draws one key
void Key::drawOneKey(SDL_Renderer* gRenderer){
  SDL_Rect pianoKey = {xpos, ypos, keyWid, keyLen}; //creates rectangle in SDL
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 100, 100); //changes color of rectangle
  SDL_RenderDrawRect(gRenderer, &pianoKey); //renders rectangle to screen
}

//function colors one key
void Key::colorKey(SDL_Renderer* gRenderer){
  SDL_Rect color = {xpos, ypos, keyWid, keyLen}; //creates rectangle in SDL
  SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF); //changes color of rectangle
  SDL_RenderFillRect(gRenderer, &color); //renders rectangle to screen
}
#endif
