#pragma once

#include"GameState.h"
#include"Swan.h"

class GameSaver: public GameState{
	public:
		GameSaver(Renderer& renderer) : GameState(renderer){
			Sprite sprite("resources\swan.png");

			Swan swan = new Swan(sprite);
		}
		~GameSaver(){
			sprite.destroySprite();
		}
		void update(SDL_Event&);
}

void GameSaver::update(SDL_Event& e){
	if(e.type==SDL_KEYDOWN){
		case SDLK_ENTER:
			break;
		case SDLK_ESCAPE:
			arg.type=SDL_QUIT;
			break;
	};

	swan.update();
	swan.render(renderer);
};
