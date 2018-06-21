
#include "MainObject.h"


MainObject::MainObject() {
	rect_.x = Panda_Loc[1];
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	x_val_ = 0;
	y_val_ = 0;
	loc_ = 1;
	type_ = Right;
	is_attack = false;
}

MainObject::~MainObject() {

}

void MainObject::HandleInputAction(SDL_Event event, SDL_Renderer *ren) {
	std::cout << x_val_ << " " << y_val_ << std::endl;
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			y_val_ -= HEIGHT_MAIN_OBJECT / 8;
			break;
		case SDLK_s:
			y_val_ += HEIGHT_MAIN_OBJECT / 8;
			is_attack = true;
			break;
		case SDLK_a:
			loc_ -= 1;
			break;
		case SDLK_d:
			loc_ += 1;
			break;
		default:
			break;
		}
	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			y_val_ = 0;
			break;
		case SDLK_s:
			y_val_ = 0;
			is_attack = false;
			break;
		case SDLK_a:
			break;
		case SDLK_d:
			break;
		default:
			break;
		}
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN) {
		y_val_ += HEIGHT_MAIN_OBJECT / 4;
		is_attack = true;
//		std::cout << event.motion.x << " " << event.motion.y << std::endl;
	}
	else if (event.type == SDL_MOUSEBUTTONUP) {
		y_val_ = 0;
		is_attack = false;
	}
	else {

	}
}

void MainObject::HandMove() {
	if (loc_ > 5) {
		loc_ = 5;
	}
	else if (loc_ < 0) {
		loc_ = 0;
	}
	
	if (loc_ % 2 == 0) {// loc_ chan thi vi chi mang chan been trai
		type_ = Left;
	}
	else {
		type_ = Right;
	}
	rect_.x = Panda_Loc[loc_];
	
	//.....
	rect_.y += y_val_;
	if (rect_.y < 0) {
		rect_.y = 0;
	}
	else if (rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT) {
		rect_.y = SCREEN_HEIGHT - HEIGHT_MAIN_OBJECT;
	}
}

void MainObject::removePanda(SDL_Texture* text, SDL_Renderer* ren, SDL_Texture* bg) {
	
	setObject(text);
	if (loc_ % 2 == 0) {
		rect_.x -= 100;
	}
	else {
		rect_.x += 100;
	}
	
	while (rect_.y < SCREEN_HEIGHT)
	{
		rect_.y += 10;
		render(ren);
		SDL_RenderPresent(ren);
		renderTexture(bg, ren, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	}
}