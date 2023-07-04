#include "core.hpp"

#include <iostream>

Core *core = nullptr;

int main(int argc, char *argv[]) {

	std::cout << "Hello there" << std::endl;

	core = new Core();
	core->init("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720);

	while (core->running()) {
		
		core->event();
		core->update();
		core->draw();
	}

	core->clean();

	return 0;
}