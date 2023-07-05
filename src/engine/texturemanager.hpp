#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "core.hpp"

class TextureManager {
	public:
		static SDL_Texture* loadTexture(const char* file_name);
};

#endif