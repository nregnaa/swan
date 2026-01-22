#pragma once

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

class Renderer{
	public:
		Renderer(){
			ren = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED); 

			SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
		};
		~Renderer(){
			SDL_DestroyRenderer(ren); ren = NULL;
		};

	private:

		SDL_Renderer* ren=NULL;
}
