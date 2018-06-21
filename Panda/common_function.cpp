

#include "common_function.h"

void logSDLError(std::ostream& os, const std::string &msg, bool fatal)
{
	os << msg << " Error: " << SDL_GetError() << std::endl;
	if (fatal) {
		SDL_Quit();
		exit(1);
	}
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		logSDLError(std::cout, "SDL_Init", true);

	TTF_Init();
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		std::cout << "Failed to init audio" << std::endl;
	}

	window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren)
{
	SDL_Texture *texture = nullptr;

	SDL_Surface *loadedImage = IMG_Load(file.c_str());

	// Xóa màu của nền
	if (loadedImage != NULL)
	{
		Uint32 color_key = SDL_MapRGB(loadedImage->format, 230, 254, 240);
		SDL_SetColorKey(loadedImage, SDL_TRUE, color_key);
	}


	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);

		if (texture == nullptr) {
			logSDLError(std::cout, "CreateTextureFromSurface", true);
		}
	}
	else {
		logSDLError(std::cout, "LoadBMP", true);
	}

	return texture;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;

	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int randomBamboo(int i) {
	int x;
	if (i % 2 == 0) {
		srand(time(0));
		x = rand() % 6;
		if (x % 2 != 0) x -= 1;
	}
	else {
		srand(time(0));
		x = rand() % 6;
		if (x % 2 == 0) x += 1;
	}
	return x;
}


std::string creatLinkImage(int n, int type) {
	if (type == 0) {
		return  "snailUp/" + std::to_string(n) + ".png";
	}
	return  "snailDown/" + std::to_string(n) + ".png";
	
}

bool Collision(const SDL_Rect& panda, const SDL_Rect&  snail) {
	int left_a = panda.x;
	int right_a = panda.x + panda.w;
	int top_a = panda.y;
	int bottom_a = panda.y + panda.h;

	int left_b = snail.x;
	int right_b = snail.x + snail.w;
	int top_b = snail.y;
	int bottom_b = snail.y + snail.h;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 2 < size object 1
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}

void readHighScore(int &HighScore, std::string str) {
	std::ifstream file;
	file.open(str.c_str());
	file >> HighScore;
	std::cout << HighScore;
	file.close();
}

std::ofstream writeHighScore(int HighScore, int score, std::string str) {
	std::ofstream file;
	if (score >= HighScore) {
		file.open(str.c_str());
		file << score;
	}
	return file;
}