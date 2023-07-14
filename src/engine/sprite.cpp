#include "sprite.hpp"
#include "texturemanager.hpp"

Sprite::Sprite(const char* texture_file, int _x, int _y, double _xscale, double _yscale,
	double _orientation, int _xpart, int _ypart, int _wpart, int _hpart) {
	
	sprite_texture = TextureManager::loadTexture(texture_file);
	sprite_texture_size = TextureManager::getTextureSize(sprite_texture);

	//set x/y part to be the texture w/h if none is specified
	if (_xpart == -1) { _xpart = sprite_texture_size.x; }
	if (_ypart == -1) { _ypart = sprite_texture_size.y; }

	setPosition(_x, _y);

	//need to check what the float is doing here
	dest_rect.w = _wpart * _xscale;
	dest_rect.h = _hpart * _yscale;

	orientation = _orientation;

	centre.x = _wpart/2;
	centre.y = _hpart/2;

	setPart(_xpart, _ypart, _wpart, _hpart);
}

void Sprite::draw() {
	SDL_RenderCopyEx(Core::renderer, sprite_texture, &src_rect, &dest_rect, orientation, &centre, flip);
}

void Sprite::setPart(int x, int y, int w, int h) {
	src_rect.x = x;
	src_rect.y = y;
	src_rect.w = w;
	src_rect.h = h;
}

void Sprite::setPosition(int x, int y) {
	dest_rect.x = x;
	dest_rect.y = y;
}

void Sprite::setScale(double _xscale, double _yscale) {
	flip = (SDL_RendererFlip)(((_xscale < 0) * SDL_FLIP_HORIZONTAL) | ((_yscale < 0) * SDL_FLIP_VERTICAL));
	xscale = abs(_xscale);
	yscale = abs(_yscale);
}


