#include "core.hpp"
#include "texturemanager.hpp"
#include "object2d.hpp"
#include "keyboardinput.hpp"

SDL_Renderer* Core::renderer = nullptr;
Object2D* square;

Core::Core() {
}

Core::~Core() {
}

void Core::init(const char* title, int xpos, int ypos, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL initialised correctly" << std::endl;
	} else {
		std::cout << "SDL failed to initialise" << std::endl;
		return;
	}

	window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_ALLOW_HIGHDPI);
	if (window == NULL) {
		std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
		return;
	} else {
		std::cout << "Window created successfully" << std::endl;
	}


	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) {
		std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
		return;
	} else {
		SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
		std::cout << "Renderer created successfully" << std::endl;
	}

	Keyboard::init();

	square = new Object2D("assets/spr_test_sprite.png", 50, 50);

	is_running = true;

}

void Core::event() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				is_running = false;
				break;

			case SDL_KEYDOWN:
			case SDL_KEYUP:
				Keyboard::handleKeys(&event.key);
				break;

			default:
				break;
		}
	}
}

void Core::beginUpdate() {

}

void Core::update(double delta) {
	//delta is the time in milliseconds
	square->update(delta);
	
}

void Core::endUpdate() {
	Keyboard::endUpdate();
}

void Core::draw() {
	SDL_RenderClear(Core::renderer);
	
	square->draw();

	SDL_RenderPresent(Core::renderer);
}

void Core::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Core::renderer);
	SDL_Quit();
}

bool Core::running() {
	return is_running;
}