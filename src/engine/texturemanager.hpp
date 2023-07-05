#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class TextureManager {
	public:
		static SDL_Texture* loadTexture(const char* file_name);
};

#endif