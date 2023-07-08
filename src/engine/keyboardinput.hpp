#ifndef KEYBOARDINPUT_HPP
#define KEYBOARDINPUT_HPP

#include <map>

#include "core.hpp"

struct keyState {
	bool pressed, held, released;
	const char *key_val, *shift_key_val;
	//typable
};

class Keyboard {
	public:

		static void init();
		static void endUpdate();
		static bool isKeyPressed(SDL_Keycode keycode);
		static bool isKeyHeld(SDL_Keycode keycode);
		static bool isKeyReleased(SDL_Keycode keycode);

		static bool isKeyAlt() { return kmod_alt; }
		static bool isKeyShift() { return kmod_shift; }
		static bool isKeyCtrl() { return kmod_ctrl; }
		static bool isKeyCaps() { return kmod_caps; }

		static void handleKeys(SDL_KeyboardEvent *key_event);

	private:
		static std::map<SDL_Keycode, keyState> key_map;

		//modifier keys
		static bool kmod_ctrl, kmod_shift, kmod_alt, kmod_caps;

};

#endif