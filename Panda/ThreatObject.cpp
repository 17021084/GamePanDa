#include "ThreatObject.h"

ThreatObject::ThreatObject() {
	rect_.x = -100;
	rect_.w = THREAT_WIDTH;
	rect_.h = THREAT_HEIGHT;

	x_val_ = 0;
	y_val_ = 0;
}

ThreatObject::~ThreatObject() {

}

void ThreatObject::HandMove(const int& x_border, const int& y_border) {
	if (typeMove_ == Up) {
		rect_.y -= y_val_;
	}
	else {
		rect_.y += y_val_;
	}
	
}

void ThreatObject::Remove(SDL_Texture * text, int i) {
	int x = randomBamboo(i);
	if (typeMove_ == Up) {
		SetRect(Snail_Loc[x], SCREEN_HEIGHT + i * 100);
	}
	else {
		SetRect(Snail_Loc[x], i * -100);
	}
	
}