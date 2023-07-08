#include "core.hpp"

#include <iostream>

Core *core = nullptr;

int main(int argc, char *argv[]) {

	core = new Core();
	core->init("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720);

	Uint64 time_now = SDL_GetPerformanceCounter();
	Uint64 time_last = 0;
	double delta_time = 0;

	while (core->running()) {

		time_last = time_now;
		time_now = SDL_GetPerformanceCounter();
		delta_time = (double)((time_now - time_last) * 1000 / (double)SDL_GetPerformanceFrequency());
		
		core->event();
		core->beginUpdate();
		core->update(delta_time);
		core->endUpdate();
		core->draw();
	}

	core->clean();

	return 0;
}