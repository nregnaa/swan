#pragma once

#include<iostream>

using std::string;

struct Sprite{
	Sprite(string path){
		fil = path;

		if(SDL_Surface* surf=IMG_Load(); surf){
			tex=SDL_CreateTextureFromSurface(renderer, surf);
			if(tex==NULL){
				printf("%s\n", SDL_GetError());
			};
			SDL_FreeSurface(surf);
		};
	};

	void destroySprite(struct Sprite *sprite){
		if(sprite == NULL) return;

		SDL_DestroyTexture(texture);
		texture = NULL;

		free(sprite->name);
		sprite->name = NULL;
	};

	const char* fil;
	SDL_Texture texture;
};

