#include "keyboardinput.hpp"

//define variables
bool Keyboard::kmod_ctrl, Keyboard::kmod_shift, Keyboard::kmod_alt, Keyboard::kmod_caps;
std::map<SDL_Keycode, keyState> Keyboard::key_map;

int Keyboard::keys_pressed = 0;
int Keyboard::keys_released = 0;
SDL_Keycode Keyboard::pressed_key_array[max_rollover];
SDL_Keycode Keyboard::released_key_array[max_rollover];

void Keyboard::init() {
	key_map[SDLK_0] = {0, 0, 0, "0", ")"};
	key_map[SDLK_1] = {0, 0, 0, "1", "!"};
	key_map[SDLK_2] = {0, 0, 0, "2", "@"};
	key_map[SDLK_3] = {0, 0, 0, "3", "#"};
	key_map[SDLK_4] = {0, 0, 0, "4", "$"};
	key_map[SDLK_5] = {0, 0, 0, "5", "%"};
	key_map[SDLK_6] = {0, 0, 0, "6", "^"};
	key_map[SDLK_7] = {0, 0, 0, "7", "&"};
	key_map[SDLK_8] = {0, 0, 0, "8", "*"};
	key_map[SDLK_9] = {0, 0, 0, "9", "("};

	key_map[SDLK_a] = {0, 0, 0, "a", "A"};
	key_map[SDLK_b] = {0, 0, 0, "b", "B"};
	key_map[SDLK_c] = {0, 0, 0, "c", "C"};
	key_map[SDLK_d] = {0, 0, 0, "d", "D"};
	key_map[SDLK_e] = {0, 0, 0, "e", "E"};
	key_map[SDLK_f] = {0, 0, 0, "f", "F"};
	key_map[SDLK_g] = {0, 0, 0, "g", "G"};
	key_map[SDLK_h] = {0, 0, 0, "h", "H"};
	key_map[SDLK_i] = {0, 0, 0, "i", "I"};
	key_map[SDLK_j] = {0, 0, 0, "j", "J"};
	key_map[SDLK_k] = {0, 0, 0, "k", "K"};
	key_map[SDLK_l] = {0, 0, 0, "l", "L"};
	key_map[SDLK_m] = {0, 0, 0, "m", "M"};
	key_map[SDLK_n] = {0, 0, 0, "n", "N"};
	key_map[SDLK_o] = {0, 0, 0, "o", "O"};
	key_map[SDLK_p] = {0, 0, 0, "p", "P"};
	key_map[SDLK_q] = {0, 0, 0, "q", "Q"};
	key_map[SDLK_r] = {0, 0, 0, "r", "R"};
	key_map[SDLK_s] = {0, 0, 0, "s", "S"};
	key_map[SDLK_t] = {0, 0, 0, "t", "T"};
	key_map[SDLK_u] = {0, 0, 0, "u", "U"};
	key_map[SDLK_v] = {0, 0, 0, "v", "V"};
	key_map[SDLK_w] = {0, 0, 0, "w", "W"};
	key_map[SDLK_x] = {0, 0, 0, "x", "X"};
	key_map[SDLK_y] = {0, 0, 0, "y", "Y"};
	key_map[SDLK_z] = {0, 0, 0, "z", "Z"};

	key_map[SDLK_QUOTE] = {0, 0, 0, "'", "\""};
	key_map[SDLK_BACKSLASH] = {0, 0, 0, "\\", "|"};
	key_map[SDLK_COMMA] = {0, 0, 0, ",", "<"};
	key_map[SDLK_EQUALS] = {0, 0, 0, "=", "+"};
	key_map[SDLK_BACKQUOTE] = {0, 0, 0, "`", "~"};
	key_map[SDLK_MINUS] = {0, 0, 0, "-", "_"};
	key_map[SDLK_PERIOD] = {0, 0, 0, ".", ">"};
	key_map[SDLK_SEMICOLON] = {0, 0, 0, ";", ":"};
	key_map[SDLK_SLASH] = {0, 0, 0, "/", "?"};
	key_map[SDLK_RIGHTBRACKET] = {0, 0, 0, "]", "}"};
	key_map[SDLK_LEFTBRACKET] = {0, 0, 0, "[", "{"};
	
	key_map[SDLK_F1] = {0, 0, 0, "", ""};
	key_map[SDLK_F2] = {0, 0, 0, "", ""};
	key_map[SDLK_F3] = {0, 0, 0, "", ""};
	key_map[SDLK_F4] = {0, 0, 0, "", ""};
	key_map[SDLK_F5] = {0, 0, 0, "", ""};
	key_map[SDLK_F6] = {0, 0, 0, "", ""};
	key_map[SDLK_F7] = {0, 0, 0, "", ""};
	key_map[SDLK_F8] = {0, 0, 0, "", ""};
	key_map[SDLK_F9] = {0, 0, 0, "", ""};
	key_map[SDLK_F10] = {0, 0, 0, "", ""};
	key_map[SDLK_F11] = {0, 0, 0, "", ""};
	key_map[SDLK_F12] = {0, 0, 0, "", ""};	

	key_map[SDLK_PRINTSCREEN] = {0, 0, 0, "", ""};
	key_map[SDLK_SCROLLLOCK] = {0, 0, 0, "", ""};
	key_map[SDLK_PAUSE] = {0, 0, 0, "", ""};
	key_map[SDLK_INSERT] = {0, 0, 0, "", ""};
	key_map[SDLK_HOME] = {0, 0, 0, "", ""};
	key_map[SDLK_PAGEUP] = {0, 0, 0, "", ""};
	key_map[SDLK_DELETE] = {0, 0, 0, "", ""};
	key_map[SDLK_END] = {0, 0, 0, "", ""};
	key_map[SDLK_PAGEDOWN] = {0, 0, 0, "", ""};
	
	key_map[SDLK_SPACE] = {0, 0, 0, " ", " "};
	key_map[SDLK_TAB] = {0, 0, 0, "    ", "    "};
	key_map[SDLK_ESCAPE] = {0, 0, 0, "", ""};
	key_map[SDLK_BACKSPACE] = {0, 0, 0, "", ""};
	key_map[SDLK_CAPSLOCK] = {0, 0, 0, "", ""};
	key_map[SDLK_RETURN] = {0, 0, 0, "", ""};
	key_map[SDLK_APPLICATION] = {0, 0, 0, "", ""};

	key_map[SDLK_UP] = {0, 0, 0, "", ""};
	key_map[SDLK_DOWN] = {0, 0, 0, "", ""};
	key_map[SDLK_LEFT] = {0, 0, 0, "", ""};
	key_map[SDLK_RIGHT] = {0, 0, 0, "", ""};
	
	key_map[SDLK_KP_0] = {0, 0, 0, "0", ""};
	key_map[SDLK_KP_1] = {0, 0, 0, "1", ""};
	key_map[SDLK_KP_2] = {0, 0, 0, "2", ""};
	key_map[SDLK_KP_3] = {0, 0, 0, "3", ""};
	key_map[SDLK_KP_4] = {0, 0, 0, "4", ""};
	key_map[SDLK_KP_5] = {0, 0, 0, "5", ""};
	key_map[SDLK_KP_6] = {0, 0, 0, "6", ""};
	key_map[SDLK_KP_7] = {0, 0, 0, "7", ""};
	key_map[SDLK_KP_8] = {0, 0, 0, "8", ""};
	key_map[SDLK_KP_9] = {0, 0, 0, "9", ""};

	key_map[SDLK_NUMLOCKCLEAR] = {0, 0, 0, "", ""};
	key_map[SDLK_KP_DIVIDE] = {0, 0, 0, "/", "/"};
	key_map[SDLK_KP_ENTER] = {0, 0, 0, "", ""};
	key_map[SDLK_KP_MINUS] = {0, 0, 0, "-", "-"};
	key_map[SDLK_KP_MULTIPLY] = {0, 0, 0, "*", "*"};
	key_map[SDLK_KP_PERIOD] = {0, 0, 0, ".", "."};
	key_map[SDLK_KP_PLUS] = {0, 0, 0, "+", "+"};
	
	key_map[SDLK_POWER] = {0, 0, 0, "", ""};
	key_map[SDLK_UNKNOWN] = {0, 0, 0, "", ""};
	
	kmod_ctrl = false;
	kmod_shift = false;
	kmod_alt = false;
	kmod_caps = false;
}

void Keyboard::update(double delta) {
	//debug
	std::string disp = Keyboard::getCharString();
	if (disp.length() > 0) {
		std::cout << disp << std::endl;
	}
}

void Keyboard::endUpdate() {
	SDL_Keycode keycode;

	for (int i = 0; i < keys_pressed; i++) {
		keycode = pressed_key_array[i];
		key_map[keycode].pressed = false;
		keys_pressed = 0;
	}

	for (int i = 0; i < keys_released; i++) {
		keycode = released_key_array[i];
		key_map[keycode].released = false;
		keys_released = 0;
	}
}

bool Keyboard::isKeyPressed(SDL_Keycode keycode) {
	return key_map[keycode].pressed;
}

bool Keyboard::isKeyHeld(SDL_Keycode keycode) {
	return key_map[keycode].held;
}

bool Keyboard::isKeyReleased(SDL_Keycode keycode) {
	return key_map[keycode].released;
}

std::string Keyboard::getCharString()
{
	SDL_Keycode keycode;
	keyState keystate;
	std::string str_out = "";

	for (int i = 0; i < keys_pressed; i++) {
		keycode = pressed_key_array[i];
		keystate = key_map[keycode];

		if ((0x60 < keycode) && (keycode < 0x7B)) {
			str_out += (kmod_shift ^ kmod_caps) ? keystate.shift_key_val : keystate.key_val;
		} else {
			str_out += (kmod_shift) ? keystate.shift_key_val : keystate.key_val;
		}
	}
	return str_out;
}

void Keyboard::handleKeys(SDL_KeyboardEvent *key_event)
{
	bool pressed;
	int keycode = key_event->keysym.sym;
	

	if (keycode < 0x40000068) { 
		pressed = (key_event->state == SDL_PRESSED);

		key_map[keycode].pressed = (key_map[keycode].pressed) || (pressed);
		key_map[keycode].released = !pressed;
		key_map[keycode].held = !(key_map[keycode].held && !pressed) || pressed;

		if (pressed) {
			if (keys_pressed < max_rollover) {
				pressed_key_array[keys_pressed++] = keycode;
			} else {
				std::cout << "Warning: Rollover limit reached" << std::endl;
			}
		} else {
			if (keys_released < max_rollover) {
				released_key_array[keys_released++] = keycode;
			} else {
				std::cout << "Warning: Rollover limit reached" << std::endl;
			}
		}
	}

	kmod_ctrl = (key_event->keysym.mod & KMOD_CTRL);
	kmod_shift = (key_event->keysym.mod & KMOD_SHIFT);
	kmod_alt = (key_event->keysym.mod & KMOD_ALT);
	kmod_caps = (key_event->keysym.mod & KMOD_CAPS);
}