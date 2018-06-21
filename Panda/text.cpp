#include "text.h"


text::text() {
	text_color_ = { 243,156,18 };
}
text::~text() {

}
void text::CreateText(SDL_Renderer* ren, TTF_Font* font) {
	if (!font)
		std::cout << "Unable to load font: %s \n" << TTF_GetError() << std::endl;
	if (surface_ != NULL && object_ != NULL) {
		SDL_FreeSurface(surface_);
		SDL_DestroyTexture(object_);
		object_ = NULL;
		surface_ = NULL;
	}

	surface_ = TTF_RenderText_Solid(font, text_val_.c_str(), text_color_); 
	
	object_ = SDL_CreateTextureFromSurface(ren, surface_);
	SDL_QueryTexture(object_, NULL, NULL, &rect_.w, &rect_.h);
}


void text::setColor(text_color color) {
	if (color == ORANGE) {
		text_color_ = { 243,156,18 };
	}
	else if (color == GREEN) {
		text_color_ = { 72, 150, 32 };
	}
	else if (color == PINK) {
		text_color_ = { 241, 145, 235 };
	}
	else if (color == RED) {
		
		text_color_ = { 247, 191, 131 };
	}
}