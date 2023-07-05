#ifndef OBJECT2D_HPP
#define OBJECT2D_HPP

#include "core.hpp"

class Object2D {
	public:
		Object2D(const char* texture_file, int x_init, int y_init);
		~Object2D();

		void update(double delta);
		void draw();

	private:
		int x;
		int y;

		SDL_Texture* obj2d_texture;
		SDL_Rect src_rect, dest_rect;
};


#endif