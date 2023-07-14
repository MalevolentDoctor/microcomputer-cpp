#include "texturemanager.hpp"

SDL_Texture* TextureManager::loadTexture(const char* file_name) {
	SDL_Surface* temp_surface = IMG_Load(file_name);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Core::renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	return texture;
}

SDL_Point TextureManager::getTextureSize(SDL_Texture *texture) {
	SDL_Point texture_size;
	SDL_QueryTexture(texture, NULL, NULL, &(texture_size.x), &(texture_size.y));
	return texture_size;
}