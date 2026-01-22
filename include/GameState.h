#pragma once

#include<iostream>

class GameState{
	public:
		GameState(Renderer& renderer) : renderer(renderer) {};
		
		virtual void update(SDL_Event&);
	protected:
		Renderer& renderer;
}
