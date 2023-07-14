#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "core.hpp"

class Sprite {
	public:
		/**
		 * @brief Construct a new Sprite object
		 * 
		 * @param texture_file 
		 * @param _x 
		 * @param _y 
		 * @param _xscale 
		 * @param _yscale 
		 * @param _orientation 
		 * @param _xpart 
		 * @param _ypart 
		 * @param _wpart 
		 * @param _hpart 
		 */
		Sprite(const char* texture_file, int _x = 0, int _y = 0, double _xscale = 1, double _yscale = 1,
			double _orientation = 0, int _xpart = 0, int _ypart = 0, int _wpart = -1, int _hpart = -1);
		~Sprite();

		void draw();

		int getXPos() { return dest_rect.x; }
		int getYPos() { return dest_rect.y; }

		void setPart(int x, int y, int w, int h);
		void setPosition(int x, int y);
		void setScale(double _xscale, double _yscale);

	private:
		double xscale, yscale, orientation;
		int xpart, ypart, wpart, hpart;
		
		SDL_Point sprite_texture_size;
		SDL_Point centre;
		SDL_Texture* sprite_texture;
		SDL_Rect src_rect, dest_rect;
		SDL_RendererFlip flip;
};


#endif