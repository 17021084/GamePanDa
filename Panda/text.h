#pragma once

#include "common_function.h"
#include "BaseObject.h"

class text : public BaseObject
{
public:
	enum text_color {
		ORANGE,
		GREEN,
		PINK,
		RED
	};
	text();
	~text();
	void setColor(text_color color);
	void SetText(std::string text) {
		text_val_ = text;
	}
	void CreateText(SDL_Renderer * ren, TTF_Font * font);
private:
	std::string text_val_;
	SDL_Color text_color_;
};

