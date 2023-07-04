#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include "SDL2/SDL.h"


class Core {

	public:
		Core();
		~Core();

		void init(const char* title, int xpos, int ypos, int width, int height);

		void event();
		void update();
		void draw();
		void clean();

		bool running();

	private:
		bool is_running;

		SDL_Window *window;
		SDL_Renderer *renderer;
};


#endif