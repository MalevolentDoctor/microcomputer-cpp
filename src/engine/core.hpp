#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


class Core {

	public:
		Core();
		~Core();

		void init(const char* title, int xpos, int ypos, int width, int height);

		void event();
		void update(double delta);
		void draw();
		void clean();

		bool running();

		static SDL_Renderer *renderer;

	private:
		bool is_running;

		SDL_Window *window;
};


#endif