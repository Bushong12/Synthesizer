/*
header file containing the class definition for the sharp class
*/
#ifndef sharp_H
#define sharp_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

class Sharp {//sharp class
 public:
  Sharp(); //default constructor
  void drawOneSharp(SDL_Renderer*); //function draws one sharp
  void colorSharp(SDL_Renderer *); //function colors one sharp
  void setVals(int,int); //function sets x position and y position
 private:
  const int sharpWid = 30; //variable stores sharp width
  const int sharpLen = 281; //variable stores sharp length
  int xpos; //variable stores x position of sharp
  int ypos; //variable stores y position of sharp
};

//default constructor
Sharp::Sharp(){
}

//function sets x position and y position
void Sharp::setVals(int xval, int yval){
	xpos=xval;
	ypos=yval;
}

//function draws one sharp
void Sharp::drawOneSharp(SDL_Renderer* gRenderer){
  SDL_Rect sharpKey = {xpos, ypos, sharpWid, sharpLen}; //creates SDL rectangle
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 100, 100); //changes SDL draw color
  SDL_RenderFillRect(gRenderer, &sharpKey); //renders rectangle to screen
}

//function colors one sharp
void Sharp::colorSharp(SDL_Renderer* gRenderer){
  SDL_Rect color = {xpos, ypos, sharpWid, sharpLen}; //creates SDL rectangle
  SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF); //changes SDL draw color
  SDL_RenderFillRect(gRenderer, &color); //renders rectangle to screen
}

#endif
