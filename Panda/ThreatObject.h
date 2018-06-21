#pragma once

#include "common_function.h"
#include "BaseObject.h"

#define THREAT_WIDTH 36
#define THREAT_HEIGHT 44


class ThreatObject : public BaseObject
{
public:
	
	enum TypeSnail {
		Right,
		Left
	};
	enum TypeMove {
		Up,
		Down
	};
	ThreatObject();
	~ThreatObject();

	void HandMove(const int& x_border, const int& y_border);
	void HandInputAction(SDL_Event event);
	void setSpeed(const int y_val) {
		y_val_ = y_val;

	}
	void SetTypeSnail(int type) {
		typeSnail_ = type;
	}
	int GetTypeSnail() {
		return typeSnail_;
	 }
	void SetTypeMove(int type) {
		typeMove_ = type;
	}
	int GetTypeMove() {
		return typeMove_;
	}
	void setLoc(int x) {
		loc_ = x;
	}
	int getLoc() {
		return loc_;
	}
	void Remove(SDL_Texture * text, int i);
private:
	int x_val_;
	int y_val_;
	int typeSnail_;
	int typeMove_;
	int loc_;
};


