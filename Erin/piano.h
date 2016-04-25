#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

class Key {
 public:
  Key();
  void drawOneKey(int, int, SDL_Renderer*);
  void drawOneSharp(int, int, SDL_Renderer*);
  void drawKeys(SDL_Renderer *);
  void drawSharps(SDL_Renderer *);
  void drawWholePiano(SDL_Renderer *);
  void colorKey(int xpos, int ypos, SDL_Renderer *);
  void colorSharp(int xpos, int ypos, SDL_Renderer *);
  void handleKeyPress(SDL_Renderer *, SDL_Event e);
 private:
  const int keyWid = 60;
  const int keyLen = 450;
  const int sharpWid = 30;
  const int sharpLen = 281;
};

Key::Key(){

}

void Key::drawOneKey(int xpos, int ypos, SDL_Renderer* gRenderer){
  SDL_Rect pianoKey = {xpos, ypos, keyWid, keyLen};
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 100, 100);
  SDL_RenderDrawRect(gRenderer, &pianoKey);
}

void Key::drawOneSharp(int xpos, int ypos, SDL_Renderer* gRenderer){
  SDL_Rect sharpKey = {xpos, ypos, sharpWid, sharpLen};
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 100, 100);
  SDL_RenderFillRect(gRenderer, &sharpKey);
}

void Key::drawKeys(SDL_Renderer* gRenderer){
  drawOneKey(30, 30, gRenderer);
  drawOneKey(150, 30, gRenderer);
  drawOneKey(270, 30, gRenderer);
  drawOneKey(390, 30, gRenderer);
  drawOneKey(510, 30, gRenderer);
}

void Key::drawKeys(SDL_Renderer* gRenderer){
  drawOneKey(30, 30, gRenderer);
  drawOneKey(150, 30, gRenderer);
  drawOneKey(270, 30, gRenderer);
  drawOneKey(390, 30, gRenderer);
  drawOneKey(510, 30, gRenderer);
}

void Key::drawSharps(SDL_Renderer* gRenderer){
  drawOneSharp(75, 30, gRenderer);
  drawOneSharp(135, 30, gRenderer);
  drawOneSharp(255, 30, gRenderer);
  drawOneSharp(315, 30, gRenderer);
  drawOneSharp(375, 30, gRenderer);
  drawOneSharp(495, 30, gRenderer);
  drawOneSharp(555, 30, gRenderer);
}

void Key::drawWholePiano(SDL_Renderer* gRenderer){
  SDL_Rect screenRect = {0, 0, 700, 500};
  SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
  SDL_RenderFillRect(gRenderer, &screenRect);
  SDL_Rect outlineRect = {30, 30, 600, 450};
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 100, 100);
  SDL_RenderDrawRect(gRenderer, &outlineRect);
  drawKeys(gRenderer);
  drawSharps(gRenderer);
}

void Key::colorKey(int xpos, int ypos, SDL_Renderer* gRenderer){
  SDL_Rect color = {xpos, ypos, keyWid, keyLen};
  SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(gRenderer, &color);
}
void Key::colorSharp(int xpos, int ypos, SDL_Renderer* gRenderer){
  SDL_Rect color = {xpos, ypos, sharpWid, sharpLen};
  SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(gRenderer, &color);
}

void Key::handleKeyPress(SDL_Renderer* gRenderer, SDL_Event e){
  int value=0;
  switch(e.key.keysym.sym){
  case 'a':
    colorKey(30, 30, gRenderer);
    drawSharps(gRenderer); //might need to call this in color function?              
    break;
  case 's':
    colorKey(90, 30, gRenderer);
    drawSharps(gRenderer);
    break;
  case 'd':
    colorKey(150, 30, gRenderer);
    drawSharps(gRenderer);
    break;
  case 'f':
    colorKey(210, 30, gRenderer);
    drawSharps(gRenderer);
    break;
  case 'g':
    colorKey(270, 30, gRenderer);
    drawSharps(gRenderer);
    break;
  case 'h':
    colorKey(330, 30, gRenderer);
    drawSharps(gRenderer);
    break;
  case 'j':
    colorKey(390, 30, gRenderer);
    drawSharps(gRenderer);
    break;
  case 'k':
    colorKey(450, 30, gRenderer);
    drawSharps(gRenderer);
    break;
  case 'l':
    colorKey(510, 30, gRenderer);
    drawSharps(gRenderer);
    break;
  case ';':
    colorKey(570, 30, gRenderer);
    drawSharps(gRenderer);
    break;
  case 'w':
    drawKeys(gRenderer);
    colorSharp(75, 30, gRenderer);
    break;
  case 'e':
    drawKeys(gRenderer);
    colorSharp(135, 30, gRenderer);
    break;
  case 't':
    drawKeys(gRenderer);
    colorSharp(255, 30, gRenderer);
    break;
  case 'y':
    drawKeys(gRenderer);
    colorSharp(315, 30, gRenderer);
    break;
  case 'u':
    drawKeys(gRenderer);
    colorSharp(375, 30, gRenderer);
    break;
  case 'o':
    drawKeys(gRenderer);
    colorSharp(495, 30, gRenderer);
    break;
  case 'p':
    drawKeys(gRenderer);
    colorSharp(555, 30, gRenderer);
    break;
 }
  SDL_RenderPresent(gRenderer);
  SDL_Delay(500);
}
