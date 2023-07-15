#ifndef OBJECT2D_HPP
#define OBJECT2D_HPP

#include "core.hpp"
#include "sprite.hpp"

class Object2D {
	public:
		Object2D(Sprite *_sprite);
		~Object2D();

		void update(double delta);
		void draw();

	private:
		Sprite *spr_sprite;
};


#endif