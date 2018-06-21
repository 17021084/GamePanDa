#pragma once

#include "common_function.h"
#include "BaseObject.h"

#define WIDTH_MAIN_OBJECT 66
#define HEIGHT_MAIN_OBJECT 82

class MainObject : public BaseObject
{
public:
	
	enum typePanda {
		Right,
		Left
	};
	MainObject();
	~MainObject();
	void HandleInputAction(SDL_Event event, SDL_Renderer *ren);
	void HandMove();
	int GetType() {
		return type_;
	}
	bool GetIs_attack() {
		return is_attack;
	}

	void removePanda(SDL_Texture* text, SDL_Renderer* ren, SDL_Texture* bg);
private:
	int x_val_;
	int y_val_;
	int loc_;
	int type_;
	bool is_attack;
};
