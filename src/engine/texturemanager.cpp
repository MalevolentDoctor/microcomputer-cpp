#include "texturemanager.hpp"
#include "core.hpp"

SDL_Texture* TextureManager::loadTexture(const char* file_name) {
	SDL_Surface* temp_surface = IMG_Load(file_name);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Core::renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	return texture;
}