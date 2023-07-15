#include "object2d.hpp"

Object2D::Object2D(Sprite *sprite) {
	spr_sprite = sprite;
}

void Object2D::update(double delta) {
}

void Object2D::draw() {
	spr_sprite->draw();
}