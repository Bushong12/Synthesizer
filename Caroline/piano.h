#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "key.h"
#include "sharp.h"

class Piano {
 public:
  Piano(SDL_Renderer *);
  void drawKeys(SDL_Renderer *);
  void drawSharps(SDL_Renderer *);
  void drawWholePiano(SDL_Renderer *);
  void handleKeyPress(SDL_Renderer *, SDL_Event e);
 private:
	Key keyOne;
	Key keyTwo;
	Key keyThree;
	Key keyFour;
	Key keyFive;
	Key keySix;
	Key keySeven;
	Key keyEight;
	Key keyNine;
	Key keyTen;
	Sharp sharpOne;
	Sharp sharpTwo;
	Sharp sharpThree;
	Sharp sharpFour;
	Sharp sharpFive;
	Sharp sharpSix;
	Sharp sharpSeven;	
};

Piano::Piano(SDL_Renderer* gRenderer){
	keyOne.setVals(30,30);
	keyTwo.setVals(90,30);
	keyThree.setVals(150,30);
	keyFour.setVals(210,30);
	keyFive.setVals(270,30);
	keySix.setVals(330,30);
	keySeven.setVals(390,30);
	keyEight.setVals(450,30);
	keyNine.setVals(510,30);
	keyTen.setVals(570,30);
	sharpOne.setVals(75,30);
	sharpTwo.setVals(135,30);
	sharpThree.setVals(255,30);
	sharpFour.setVals(315,30);
	sharpFive.setVals(375,30);
	sharpSix.setVals(495,30);
	sharpSeven.setVals(555,30);
}


void Piano::drawKeys(SDL_Renderer* gRenderer){
	keyOne.drawOneKey(gRenderer);
	keyTwo.drawOneKey(gRenderer);
	keyThree.drawOneKey(gRenderer);
	keyFour.drawOneKey(gRenderer);
	keyFive.drawOneKey(gRenderer);
	keySix.drawOneKey(gRenderer);
	keySeven.drawOneKey(gRenderer);
	keyEight.drawOneKey(gRenderer);
	keyNine.drawOneKey(gRenderer);
	keyTen.drawOneKey(gRenderer);
}

void Piano::drawSharps(SDL_Renderer* gRenderer){
	sharpOne.drawOneSharp(gRenderer);
	sharpTwo.drawOneSharp(gRenderer);
	sharpThree.drawOneSharp(gRenderer);
	sharpFour.drawOneSharp(gRenderer);
	sharpFive.drawOneSharp(gRenderer);
	sharpSix.drawOneSharp(gRenderer);
	sharpSeven.drawOneSharp(gRenderer);
}

void Piano::drawWholePiano(SDL_Renderer* gRenderer){
  SDL_Rect screenRect = {0, 0, 700, 500};
  SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
  SDL_RenderFillRect(gRenderer, &screenRect);
  SDL_Rect outlineRect = {30, 30, 600, 450};
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 100, 100);
  SDL_RenderDrawRect(gRenderer, &outlineRect);
  drawKeys(gRenderer);
  drawSharps(gRenderer);
}

void Piano::handleKeyPress(SDL_Renderer* gRenderer, SDL_Event e){
  int value=0;
  switch(e.key.keysym.sym){
  case 'a':
    keyOne.colorKey(gRenderer);
    drawSharps(gRenderer); //might need to call this in color function?              
    break;
  case 's':
    keyTwo.colorKey(gRenderer);
    drawSharps(gRenderer);
    break;
  case 'd':
    keyThree.colorKey(gRenderer);
    drawSharps(gRenderer);
    break;
  case 'f':
    keyFour.colorKey(gRenderer);
    drawSharps(gRenderer);
    break;
  case 'g':
    keyFive.colorKey(gRenderer);
    drawSharps(gRenderer);
    break;
  case 'h':
    keySix.colorKey(gRenderer);
    drawSharps(gRenderer);
    break;
  case 'j':
    keySeven.colorKey(gRenderer);
    drawSharps(gRenderer);
    break;
  case 'k':
    keyEight.colorKey(gRenderer);
    drawSharps(gRenderer);
    break;
  case 'l':
    keyNine.colorKey(gRenderer);
    drawSharps(gRenderer);
    break;
  case ';':
    keyTen.colorKey(gRenderer);
    drawSharps(gRenderer);
    break;
  case 'w':
    drawKeys(gRenderer);
    sharpOne.colorSharp(gRenderer);
    break;
  case 'e':
    drawKeys(gRenderer);
    sharpTwo.colorSharp(gRenderer);
    break;
  case 't':
    drawKeys(gRenderer);
    sharpThree.colorSharp(gRenderer);
    break;
  case 'y':
    drawKeys(gRenderer);
    sharpFour.colorSharp(gRenderer);
    break;
  case 'u':
    drawKeys(gRenderer);
    sharpFive.colorSharp(gRenderer);
    break;
  case 'o':
    drawKeys(gRenderer);
    sharpSix.colorSharp(gRenderer);
    break;
  case 'p':
    drawKeys(gRenderer);
    sharpSeven.colorSharp(gRenderer);
    break;
 }
  SDL_RenderPresent(gRenderer);
  SDL_Delay(500);
}
