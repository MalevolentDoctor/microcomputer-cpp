#ifndef KEYBOARDINPUT_HPP
#define KEYBOARDINPUT_HPP

#include <map>
#include <string>

#include "core.hpp"

struct keyState {
	bool pressed, held, released;
	const char *key_val, *shift_key_val;
	//typable
};

class Keyboard {
	public:

		/**
		 * @brief Initialises the keyboard object, populating the key_map map
		 */
		static void init();

		/**
		 * @brief The update function called by Core::update
		 * 
		 * @param delta time in milliseconds since the last cycle
		 */
		static void update(double delta);

		/**
		 * @brief The endUpdate function called by Core::endUpdate
		 */
		static void endUpdate();

		/**
		 * @brief Used to determine if a specific key has been pressed
		 * 
		 * @param keycode the SDL_Keycode of the key to check
		 * @return true if the key is pressed or false if it is not pressed
		 */
		static bool isKeyPressed(SDL_Keycode keycode);

		/**
		 * @brief Used to determine if a specific key is being held
		 * 
		 * @param keycode the SDL_Keycode of the key to check
		 * @return true if the key is being held or false if it is not being held
		 */
		static bool isKeyHeld(SDL_Keycode keycode);

		/**
		 * @brief Used to determine if a specific key has been released
		 * 
		 * @param keycode the SDL_Keycode of the key to check
		 * @return true if the key is released or false if it is not released
		 */
		static bool isKeyReleased(SDL_Keycode keycode);

		/**
		 * @brief Used to check if either alt key is down
		 * 
		 * @return true if alt is down or false if alt is up
		 */
		static bool isKeyAlt() { return kmod_alt; }

		/**
		 * @brief Used to check if either shift key is down
		 * 
		 * @return true if shift is down or shift if alt is up
		 */
		static bool isKeyShift() { return kmod_shift; }

		/**
		 * @brief Used to check if either control key is down
		 * 
		 * @return true if control is down or false if control is up
		 */
		static bool isKeyCtrl() { return kmod_ctrl; }

		/**
		 * @brief Used to check if caps lock is toggled
		 * 
		 * @return true if caps lock is on or false if caps lock is off
		 */
		static bool isKeyCaps() { return kmod_caps; }

		/**
		 * @brief used to get the string of printable characters that were entered in the
		 * current cycle, respecting the state of the caps lock and shift keys.
		 * 
		 * @return string of printable characters
		 */
		static std::string getCharString();

		/**
		 * @brief Is called by the Core::event function when the event read is 
		 * SDL_KEYDOWN or SDL_KEYUP to handle the key presses
		 * 
		 * @param key_event the keyboard event
		 */
		static void handleKeys(SDL_KeyboardEvent *key_event);

	private:
		static std::map<SDL_Keycode, keyState> key_map;

		//number of keys pressed/released in the current cycle
		static int keys_pressed, keys_released;

		//maximum number of keys that can be pressed/released in one cycle
		static const int max_rollover = 20;

		//arrays containing the kets pressed/released on the current cycle
		static SDL_Keycode pressed_key_array[max_rollover];
		static SDL_Keycode released_key_array[max_rollover];

		//modifier keys
		static bool kmod_ctrl, kmod_shift, kmod_alt, kmod_caps;

};

#endif