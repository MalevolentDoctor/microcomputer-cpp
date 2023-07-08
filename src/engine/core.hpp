#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


class Core {

	public:

		/**
		 * @brief Construct a new Core object
		 */
		Core();

		/**
		 * @brief Destroy the Core object
		 */
		~Core();

		/**
		 * @brief Initialises the engine core, initialising SDL, creating a window and renderer and 
		 * initialising the input devices.
		 * 
		 * @param title title of the window.
		 * @param xpos x-position of the top-left of the window.
		 * @param ypos y-position of the top-right of the window.
		 * @param width width of the window.
		 * @param height height of the window.
		 */
		void init(const char* title, int xpos, int ypos, int width, int height);

		/**
		 * @brief Handles all events in the event queue at the start of each cycle.
		 */
		void event();

		/**
		 * @brief The initial update step in the cycle, used for things that must be done prior to 
		 * the rest of the program's logic.
		 */
		void beginUpdate();

		/**
		 * @brief The main update step, the majority of the update logic, that is not sequence 
		 * dependent should go here. It takes a delta time parameter which can be used 
		 * to normalise the speed of events regardless of actual program performance.
		 * 
		 * @param delta time in milliseconds since the last frame.
		 */
		void update(double delta);

		/**
		 * @brief The final update step of the program, shoudl be used to clean up any
		 * leftovers from the current cycle that are no longer necessary or need to be
		 * reset.
		 */
		void endUpdate();

		/**
		 * @brief This function is called after all update functions and is responsible
		 * all rendering operations.
		 */
		void draw();

		/**
		 * @brief This function is called on program exit and should be used to free up
		 * all memory occupied by the program.
		 */
		void clean();

		/**
		 * @brief Used to determine whether or not the program should keep running
		 * 
		 * @return the current value of the is_running variable
		 */
		bool running();

		static SDL_Renderer *renderer;

	private:
		bool is_running;
		SDL_Window *window;
};


#endif