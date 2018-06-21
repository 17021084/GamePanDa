#pragma once
#include "common_function.h"
class BaseObject {
public:
	BaseObject();
	~BaseObject();
	void render(SDL_Renderer *ren);
	void LoadImg(const std::string &file_name, SDL_Renderer *ren);
	void SetRect(const int &x, const int &y) {
		rect_.x = x;
		rect_.y = y;
	}
	SDL_Rect GetRect() {
		return rect_;
	}
	int GetRect_y() {
		return rect_.y;
	}
	SDL_Texture *GetObject() {
		return object_;
	}
	

	void setObject(SDL_Texture* image) { 
		object_ = image; 
	
	}
	SDL_Surface *getSurface() {
		return surface_;
	}
protected:
	SDL_Rect rect_;
	SDL_Texture *object_;
	SDL_Surface *surface_;
};
