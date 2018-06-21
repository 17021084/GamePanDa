#pragma once

#include "common_function.h"
#include "text.h"

static const int NUM_ITEMS = 2;
bool checkMouse(SDL_Rect rect, SDL_Event event);
bool createMenu(SDL_Renderer* ren, TTF_Font* font, SDL_Event event);
void createGameOver(SDL_Renderer * ren, TTF_Font * font, std::string str, int HighScore);
