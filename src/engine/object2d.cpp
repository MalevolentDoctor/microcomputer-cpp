#include "object2d.hpp"
#include "texturemanager.hpp"

Object2D::Object2D(const char* texture_file, int x_init, int y_init) {
	obj2d_texture = TextureManager::loadTexture(texture_file);
	x = x_init;
	y = y_init;
}

void Object2D::update(double delta) {
	src_rect.w = 64;
	src_rect.h = 64;
	src_rect.x = 0;
	src_rect.y = 0;

	dest_rect.x = x;
	dest_rect.y = y;
	dest_rect.w = 64;
	dest_rect.h = 64;
}

void Object2D::draw() {
	SDL_RenderCopy(Core::renderer, obj2d_texture, &src_rect, &dest_rect);
}