#include "BaseObject.h"
#include "common_function.h"

BaseObject::BaseObject() {
	rect_.x = 0;
	rect_.y = 0;
	object_ = NULL;
}

BaseObject::~BaseObject() {
	if (object_ != NULL) {
		SDL_DestroyTexture(object_);
	}
}

void BaseObject::LoadImg(const std::string &file_name, SDL_Renderer *ren) {
	object_ = loadTexture(file_name, ren);

}

void BaseObject::render(SDL_Renderer *ren) {
	if (object_ != NULL) {
		renderTexture(object_, ren, rect_.x, rect_.y, rect_.w, rect_.h);
	}
}