#pragma once

#include"Sprite.h"

class Swan{
	public:
		Swan(Sprite sprite) : sprite(sprite), texture(sprite.texture){
			SDL_Surface* surface = IMG_Load(sprite.fil);
			
			if(surface) renderQuad = {0, 0, surface->w, surface->h};
			SDL_FreeSurface(surface);
		};

		bool update(){};
		bool draw(SDL_Renderer*){};
	private:
		int iXPos=0, iYPos=0, iXVel=1, iYVel=1;
	protected:
		Sprite sprite = NULL;
		SDL_Texture* texture = NULL;
		SDL_Rect renderQuad;
}

bool Swan::update(){
	if(iXPos<0){
		iXPos += iXVel; iXPos = 0;
	}else if(iXPos>renderQuad->w){
		iXPos -= iXVel; iXPos = 0;
	}else{
		iXPos += iXVel;
	};

	if(iYPos<0){
		iYPos += iYVel; iYPos = 0;
	}else if(iYPos>renderQuad->h){
		iYPos -= iYVel; iYPos = 0;
	}else{
		iYPos += iYVel;
	};
};

bool Swan::render(SDL_Renderer* renderer){
	if(SDL_RenderCopyEx(renderer, *texture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE) != 0)

	printf("%s\n", SDL_GetError());
};
