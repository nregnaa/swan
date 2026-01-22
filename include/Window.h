#pragma once

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

#include"renderer.h"
#include"GameSaver.h"

class Window{

	public:

		bool init(), update(SDL_Event&), close();
	
	private:

		SDL_Window* wind = NULL;
		Renderer renderer = NULL;
		GameState mode = NULL;
}

bool Window::init(){
	wind=SDL_CreateWindow("Ain't so", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
							391, 294, SDL_WINDOW_SHOWN);
	
	renderer = new Renderer();

	mode = new GameSaver(renderer);
}

bool Window::update(SDL_Event& arg){
	if(mode.update())
}

bool Window::close(){
	SDL_DestroyWindow(wind); wind = NULL;
	SDL_DestroyRenderer(renderer); renderer = NULL;
}
