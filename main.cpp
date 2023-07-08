#include "core.hpp"
#include <iostream>

int main(int argc, char *argv[]) {

	//intitialise the engine core
	Core *core = new Core();
	core->init("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720);

	//initialise the delta time
	Uint64 time_now = SDL_GetPerformanceCounter();
	Uint64 time_last = 0;
	double delta_time = 0;

	//fps cap for debugging/testing
	double fps_cap = 1;
	double frametime_cap = 1000/fps_cap;
	double delta_sum = 0;
	bool limit_fps = false;

	while (core->running()) {

		//calculate the delta time for the current cycle
		time_last = time_now;
		time_now = SDL_GetPerformanceCounter();
		delta_time = (double)((time_now - time_last) * 1000 / (double)SDL_GetPerformanceFrequency());
		
		if (limit_fps) {
			delta_sum += delta_time;
			if (delta_sum >= frametime_cap) {

				core->event();
				core->beginUpdate();
				core->update(delta_time);
				core->endUpdate();
				core->draw();

				delta_sum = delta_time;
			}
		} else {
			core->event();
			core->beginUpdate();
			core->update(delta_time);
			core->endUpdate();
			core->draw();
		}
	}

	//if the program has been exited, call the core clean function to close the program nicely
	core->clean();

	return 0;
}