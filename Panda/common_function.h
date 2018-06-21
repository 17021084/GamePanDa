#pragma once

#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL_image.h>
#include <ctime>
#include <sstream>
#include <vector>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <fstream>




static std::string WINDOW_TITLE = "Panda";
static const int SCREEN_WIDTH = 1200;
static const int SCREEN_HEIGHT = 600;

static const int NUM_THREATS_UP = 5;
static const int NUM_THREATS_DOWN = 5;
static const int NUM_THREATS = NUM_THREATS_UP + NUM_THREATS_DOWN;
static int Snail_Loc[6] = {233, 272, 562, 600, 884, 921};

static int Panda_Loc[6] = {204, 269, 533, 597, 855, 918};
static double SPEED = 2;

static int score_val = 0;
static std::string score_str = "Score: 0";
static int HighScore;



static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *background;
static SDL_Event event;

static TTF_Font * smallText;
static TTF_Font * mediumText;
static TTF_Font * bigText;

static Mix_Chunk* test;
static Mix_Chunk* bg;

void logSDLError(std::ostream& os, const std::string &msg, bool fatal);
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
int randomBamboo(int i);
std::string creatLinkImage(int n, int type);
bool Collision(const SDL_Rect& panda, const SDL_Rect& snail);
void readHighScore(int &HighScore, std::string str);
std::ofstream writeHighScore(int HighScore, int score, std::string str);

